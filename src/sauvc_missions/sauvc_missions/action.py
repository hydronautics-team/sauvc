import asyncio
import math
import time
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rclpy.logging import get_logger
from rclpy.node import Node
from stingray_utils.acyncio import AsyncActionClient
from stingray_interfaces.action import TwistAction
from stingray_interfaces.action import BboxCenteringTwistAction
from stingray_interfaces.action import BboxSearchTwistAction
from stingray_interfaces.msg import BboxArray
from sauvc_interfaces.action import HydroacousticCenteringTwistAction
from stingray_missions.action import StateActionBase, load_stingray_actions


def _yaw_degrees(orientation) -> float:
    return math.degrees(math.atan2(
        2.0 * (orientation.w * orientation.z +
               orientation.x * orientation.y),
        1.0 - 2.0 * (orientation.y ** 2 + orientation.z ** 2)))


def _normalize_degrees(angle: float) -> float:
    return (angle + 180.0) % 360.0 - 180.0


class RelativeControlStateAction(StateActionBase):
    """Publish relative XYZ offsets while preserving an absolute yaw setpoint."""

    def __init__(self, node: Node):
        super().__init__(node=node)
        topic = self.node.get_parameter(
            'control_data_topic').get_parameter_value().string_value
        odometry_topic = self.node.get_parameter(
            'odometry_topic').get_parameter_value().string_value
        self.command_pub = self.node.create_publisher(Twist, topic, 10)
        self.current_yaw = None
        self.current_position = None
        self.hold_yaw = None
        self.odometry_sub = self.node.create_subscription(
            Odometry, odometry_topic, self._odometry_callback, 10)

    def _odometry_callback(self, msg: Odometry):
        self.current_yaw = _yaw_degrees(msg.pose.pose.orientation)
        self.current_position = (
            msg.pose.pose.position.x, msg.pose.pose.position.y)

    def _command(self, forward: float = 0.0, lateral: float = 0.0,
                 yaw: float = None) -> Twist:
        command = Twist()
        command.linear.x = float(forward)
        command.linear.y = float(lateral)
        if yaw is None:
            yaw = self.hold_yaw
        if yaw is None:
            yaw = self.current_yaw
        command.angular.z = _normalize_degrees(yaw or 0.0)
        return command

    def _publish_hold(self):
        self.command_pub.publish(self._command())

    def stop(self):
        get_logger("action").info(f"Stopping {self.type} action")
        self._publish_hold()
        return super().stop()


class GateSearchStateAction(RelativeControlStateAction):
    """Search for a gate with an expanding absolute-yaw sweep."""

    type = "GateSearch"
    found_yaw = None

    def __init__(self, node: Node):
        super().__init__(node=node)
        self.bbox_sub = None
        self.detection_hits = 0
        self.last_detection_at = None

    def _bbox_callback(self, msg: BboxArray):
        detected = any(
            bbox.name == self.target_name and
            bbox.confidence >= self.min_confidence
            for bbox in msg.bboxes)
        self.detection_hits = self.detection_hits + 1 if detected else 0
        if detected:
            self.last_detection_at = time.monotonic()

    async def execute(self,
                      bbox_name: str = "gate",
                      bbox_topic: str = "",
                      min_confidence: float = 0.5,
                      confirmation_count: int = 3,
                      initial_wait: float = 2.0,
                      yaw_step: float = 30.0,
                      max_yaw_offset: float = 120.0,
                      dwell_time: float = 3.0,
                      timeout: float = 35.0,
                      control_rate: float = 5.0,
                      **kwargs) -> bool:
        kwargs.pop("type", None)
        if not bbox_topic:
            get_logger("action").error(f"{self.type}: bbox_topic is empty")
            return False
        if self.current_yaw is None:
            get_logger("action").error(
                f"{self.type}: no odometry; cannot create absolute yaw targets")
            return False

        self.target_name = bbox_name
        self.min_confidence = float(min_confidence)
        self.detection_hits = 0
        self.last_detection_at = None
        self.hold_yaw = self.current_yaw
        start_yaw = self.current_yaw
        type(self).found_yaw = None
        self.bbox_sub = self.node.create_subscription(
            BboxArray, bbox_topic, self._bbox_callback, 10)

        period = 1.0 / max(0.1, float(control_rate))
        started_at = time.monotonic()
        offsets = [0.0]
        offset = abs(float(yaw_step))
        while offset <= abs(float(max_yaw_offset)) + 1e-6:
            offsets.extend((offset, -offset))
            offset += abs(float(yaw_step))

        try:
            for index, yaw_offset in enumerate(offsets):
                target_yaw = _normalize_degrees(start_yaw + yaw_offset)
                self.hold_yaw = target_yaw
                stage_time = float(initial_wait) if index == 0 else float(dwell_time)
                stage_deadline = time.monotonic() + max(0.0, stage_time)
                get_logger("action").info(
                    f"{self.type}: observing at yaw={target_yaw:.1f} deg")

                while time.monotonic() < stage_deadline:
                    if self.stopped:
                        return False
                    if time.monotonic() - started_at >= float(timeout):
                        get_logger("action").error(f"{self.type}: timeout")
                        return False
                    if self.detection_hits >= max(1, int(confirmation_count)):
                        type(self).found_yaw = (
                            self.current_yaw if self.current_yaw is not None
                            else target_yaw)
                        self.hold_yaw = type(self).found_yaw
                        self._publish_hold()
                        get_logger("action").info(
                            f"{self.type}: gate found at yaw="
                            f"{type(self).found_yaw:.1f} deg")
                        return await super().execute(**kwargs)
                    self.command_pub.publish(
                        self._command(yaw=target_yaw))
                    await asyncio.sleep(period)

            get_logger("action").error(
                f"{self.type}: gate not found in search sector")
            return False
        finally:
            self._publish_hold()
            if self.bbox_sub is not None:
                self.node.destroy_subscription(self.bbox_sub)
                self.bbox_sub = None


class GateVisualControlStateAction(RelativeControlStateAction):
    """Approach and center on a gate using the new /control/data contract."""

    type = "GateVisualControl"

    def __init__(self, node: Node):
        super().__init__(node=node)
        self.bbox_sub = None
        self.target = None
        self.target_received_at = None
        self.motion_start = None
        self.motion_distance = 0.0

    def _bbox_callback(self, msg: BboxArray):
        candidates = [bbox for bbox in msg.bboxes
                      if bbox.name == self.target_name]
        if not candidates:
            return
        self.target = max(candidates, key=lambda bbox: bbox.confidence)
        self.target_received_at = time.monotonic()

    async def execute(self,
                      bbox_name: str = "gate",
                      bbox_topic: str = "",
                      min_confidence: float = 0.5,
                      stop_distance: float = 2.0,
                      horizontal_tolerance: float = 0.15,
                      lateral_gain: float = 1.0,
                      max_forward_offset: float = 0.75,
                      max_lateral_offset: float = 0.3,
                      lost_timeout: float = 2.0,
                      initial_detection_timeout: float = 10.0,
                      timeout: float = 20.0,
                      control_rate: float = 2.0,
                      confirmation_count: int = 3,
                      **kwargs) -> bool:
        kwargs.pop("type", None)
        if not bbox_topic:
            get_logger("action").error(f"{self.type}: bbox_topic is empty")
            return False

        self.target_name = bbox_name
        self.hold_yaw = (
            GateSearchStateAction.found_yaw
            if GateSearchStateAction.found_yaw is not None
            else self.current_yaw)
        self.target = None
        self.target_received_at = None
        self.bbox_sub = self.node.create_subscription(
            BboxArray, bbox_topic, self._bbox_callback, 10)

        started_at = time.monotonic()
        confirmed = 0
        period = 1.0 / max(0.1, float(control_rate))
        get_logger("action").info(
            f"{self.type}: waiting for '{bbox_name}' on {bbox_topic}")

        try:
            while time.monotonic() - started_at < float(timeout):
                if self.stopped:
                    self._publish_hold()
                    return False

                now = time.monotonic()
                if self.target is None:
                    if now - started_at > float(initial_detection_timeout):
                        get_logger("action").error(
                            f"{self.type}: gate was not detected")
                        self._publish_hold()
                        return False
                    await asyncio.sleep(period)
                    continue

                if now - self.target_received_at > float(lost_timeout):
                    get_logger("action").error(
                        f"{self.type}: gate detections became stale")
                    self._publish_hold()
                    return False

                target = self.target
                if not all(math.isfinite(value) for value in
                           (target.pos_x, target.pos_z)):
                    get_logger("action").warning(
                        f"{self.type}: ignoring non-finite gate position")
                    await asyncio.sleep(period)
                    continue
                if target.confidence < float(min_confidence):
                    get_logger("action").warning(
                        f"{self.type}: gate confidence {target.confidence:.2f} "
                        f"is below {float(min_confidence):.2f}")
                    await asyncio.sleep(period)
                    continue

                # /control/data contains a relative position target. The new
                # stingray_core deliberately ignores an identical repeated
                # value, so a saturated offset must finish before we send a
                # hold and issue the next relative step.
                if self.motion_start is not None and \
                        self.current_position is not None:
                    travelled = math.hypot(
                        self.current_position[0] - self.motion_start[0],
                        self.current_position[1] - self.motion_start[1])
                    required = max(0.05, 0.8 * self.motion_distance)
                    if travelled < required:
                        await asyncio.sleep(period)
                        continue
                    self._publish_hold()
                    self.motion_start = None
                    self.motion_distance = 0.0
                    await asyncio.sleep(period)
                    continue

                distance_error = max(0.0, target.pos_z - stop_distance)
                forward = min(
                    distance_error,
                    max(0.0, float(max_forward_offset)))
                centered = abs(target.pos_x) <= horizontal_tolerance
                close_enough = distance_error <= 0.0
                confirmed = confirmed + 1 if centered and close_enough else 0

                if centered and close_enough:
                    # Do not issue another lateral correction while confirming
                    # the final pose. Even a small command can move the vehicle
                    # back outside the tolerance before the next detection.
                    self._publish_hold()
                    if confirmed < max(1, int(confirmation_count)):
                        await asyncio.sleep(period)
                        continue
                    get_logger("action").info(
                        f"{self.type}: gate centered at {target.pos_z:.2f} m")
                    return await super().execute(**kwargs)

                lateral = max(
                    -abs(float(max_lateral_offset)),
                    min(abs(float(max_lateral_offset)),
                        float(lateral_gain) * target.pos_x))
                command = self._command(forward, lateral)
                self.command_pub.publish(command)
                if self.current_position is not None:
                    self.motion_start = self.current_position
                    self.motion_distance = math.hypot(forward, lateral)
                get_logger("action").info(
                    f"{self.type}: z={target.pos_z:.2f}, x={target.pos_x:.2f}, "
                    f"forward={command.linear.x:.2f}, lateral={command.linear.y:.2f}")
                await asyncio.sleep(period)

            get_logger("action").error(f"{self.type}: timeout")
            self._publish_hold()
            return False
        finally:
            if self.bbox_sub is not None:
                self.node.destroy_subscription(self.bbox_sub)
                self.bbox_sub = None


class ControlOffsetStateAction(RelativeControlStateAction):
    """Send one bounded relative-position target to the new control input."""

    type = "ControlOffset"

    def __init__(self, node: Node):
        super().__init__(node=node)

    async def execute(self,
                      forward: float = 0.0,
                      lateral: float = 0.0,
                      settle_time: float = 3.0,
                      max_offset: float = 1.0,
                      **kwargs) -> bool:
        kwargs.pop("type", None)
        self.hold_yaw = (
            GateSearchStateAction.found_yaw
            if GateSearchStateAction.found_yaw is not None
            else self.current_yaw)
        limit = abs(float(max_offset))
        command = self._command(
            max(-limit, min(limit, float(forward))),
            max(-limit, min(limit, float(lateral))))
        self.command_pub.publish(command)
        get_logger("action").info(
            f"{self.type}: forward={command.linear.x:.2f}, "
            f"lateral={command.linear.y:.2f}")

        deadline = time.monotonic() + max(0.0, float(settle_time))
        while time.monotonic() < deadline:
            if self.stopped:
                self._publish_hold()
                return False
            await asyncio.sleep(0.1)

        self._publish_hold()
        return await super().execute(**kwargs)


class SequencePunchBboxTwistStateAction(StateActionBase):
    type = "SequencePunchBboxTwist"
    sequence: list[str] = None

    def __init__(self, node: Node):
        super().__init__(node=node)

        self.bbox_centering_twist_action_client = AsyncActionClient(
            self.node,
            BboxCenteringTwistAction,
            self.node.get_parameter(
                'bbox_centering_twist_action').get_parameter_value().string_value
        )
        self.bbox_search_twist_action_client = AsyncActionClient(
            self.node,
            BboxSearchTwistAction,
            self.node.get_parameter(
                'bbox_search_twist_action').get_parameter_value().string_value
        )
        self.twist_action_client = AsyncActionClient(
            self.node,
            TwistAction,
            self.node.get_parameter(
                'twist_action').get_parameter_value().string_value
        )

    def stop(self):
        # Отправляем отмену экшенам, если нужно
        self.bbox_centering_twist_action_client.cancel()
        self.bbox_search_twist_action_client.cancel()
        self.twist_action_client.cancel()
        return super().stop()

    def get_bbox_name(self, flare_id: str):
        if flare_id == "R":
            return "red_flare"
        elif flare_id == "B":
            return "blue_flare"
        elif flare_id == "Y":
            return "yellow_flare"
        else:
            # Если пришёл неизвестный flare_id, можно вернуть что-то дефолтное
            return "yellow_flare"

    def get_avoid_bbox_array(self, flare_id: str):
        # Возвращаем список объектов, которые хотим избегать
        if flare_id == "R":
            return ["blue_flare", "yellow_flare"]
        elif flare_id == "B":
            return ["red_flare", "yellow_flare"]
        elif flare_id == "Y":
            return ["red_flare", "blue_flare"]
        else:
            return []

    async def execute(self,
                      bbox_topic: str = "",
                      distance_threshold: float = 0.0,
                      avoid_distance_threshold: float = 0.0,
                      avoid_horizontal_threshold: float = 0.0,
                      lost_threshold: int = 0,
                      first_clockwise: bool = True,
                      found_threshold: int = 0,
                      max_yaw: float = 0.0,
                      yaw_step: float = 0.0,
                      surge: float = 0.0,
                      avoid_sway: float = 0.0,
                      depth: float = 0.0,
                      roll: float = 0.0,
                      pitch: float = 0.0,
                      search_rate: float = 0.0,
                      centering_duration: float = 0.0,
                      punch_duration: float = 0.0,
                      centering_rate: float = 0.0,
                      **kwargs) -> bool:
        get_logger("action").info(f"Executing {self.type} state action")

        # Если sequence не передана, используем дефолт
        if not self.sequence:
            # Можно сделать так: sequence = ["R","B","Y"]
            self.sequence = ["Y", "R", "B"]
            get_logger("action").warn(
                "No sequence provided, using default [R,B,Y]")

        self.bbox_topic = bbox_topic

        # Сохраняем остальные параметры локально
        self.distance_threshold = float(distance_threshold)
        self.avoid_distance_threshold = float(avoid_distance_threshold)
        self.avoid_horizontal_threshold = float(avoid_horizontal_threshold)
        self.lost_threshold = int(lost_threshold)
        self.first_clockwise = first_clockwise
        self.found_threshold = int(found_threshold)
        self.max_yaw = float(max_yaw)
        self.yaw_step = float(yaw_step)
        self.surge = float(surge)
        self.avoid_sway = float(avoid_sway)
        self.depth = float(depth)
        self.roll = float(roll)
        self.pitch = float(pitch)
        self.search_rate = float(search_rate)
        self.centering_duration = float(centering_duration)
        self.punch_duration = float(punch_duration)
        self.centering_rate = float(centering_rate)

        # Проверка доступности серверов
        if not self.bbox_search_twist_action_client.wait_for_server(timeout_sec=2.0):
            get_logger("action").error(
                f"Timeout while waiting for {self.bbox_search_twist_action_client._action_name} action server")
            return False

        if not self.bbox_centering_twist_action_client.wait_for_server(timeout_sec=2.0):
            get_logger("action").error(
                f"Timeout while waiting for {self.bbox_centering_twist_action_client._action_name} action server")
            return False

        if not self.twist_action_client.wait_for_server(timeout_sec=2.0):
            get_logger("action").error(
                f"Timeout while waiting for {self.twist_action_client._action_name} action server")
            return False

        get_logger('action').info(f"Flares sequence: {self.sequence}")

        # Счётчик успешно сбитых фларов
        punched_flares_count = 0

        # Для каждого flare в последовательности
        for flare in self.sequence:
            flare_name = self.get_bbox_name(flare)

            # === 1) Поиск flare ===
            search_goal = BboxSearchTwistAction.Goal()
            search_goal.bbox_name = flare_name
            search_goal.bbox_topic = self.bbox_topic
            search_goal.first_clockwise = self.first_clockwise
            search_goal.found_threshold = self.found_threshold
            search_goal.max_yaw = self.max_yaw
            search_goal.yaw_step = self.yaw_step
            search_goal.depth = self.depth
            search_goal.roll = self.roll
            search_goal.pitch = self.pitch
            search_goal.search_rate = self.search_rate
            # Допустим, время поиска (duration) = 0 => без таймлимита.
            # Или хотим ограничить 30 секунд, например:
            # search_goal.duration = 30.0

            get_logger('action').info(f"Searching flare: {flare_name}")
            search_result = await self.bbox_search_twist_action_client.send_goal_async(search_goal)

            if not search_result.result.success:
                get_logger('action').error(
                    f"Search action for flare {flare_name} failed (success=False). Stopping.")
                continue
                # return False

            if not search_result.result.finded:
                get_logger('action').warn(
                    f"Flare {flare_name} was NOT found (finded=False). Skipping or continue next.")
                # Если строго нужно сбить все, возвращаем False
                # return False
                # ИЛИ можно «пропустить» этот flare, идём к следующему:
                continue

            get_logger('action').info(
                f"Flare {flare_name} found => now center on it")

            # === 2) Центрирование ===
            centering_goal = BboxCenteringTwistAction.Goal()
            centering_goal.bbox_name = flare_name
            centering_goal.bbox_topic = self.bbox_topic
            centering_goal.distance_threshold = self.distance_threshold
            centering_goal.lost_threshold = self.lost_threshold
            centering_goal.avoid_bbox_name_array = self.get_avoid_bbox_array(
                flare)
            centering_goal.avoid_distance_threshold = self.avoid_distance_threshold
            centering_goal.avoid_horizontal_threshold = self.avoid_horizontal_threshold
            centering_goal.surge = self.surge
            centering_goal.sway = self.avoid_sway
            centering_goal.depth = self.depth
            centering_goal.roll = self.roll
            centering_goal.pitch = self.pitch
            centering_goal.duration = self.centering_duration
            centering_goal.centering_rate = self.centering_rate

            center_result = await self.bbox_centering_twist_action_client.send_goal_async(centering_goal)
            if not center_result.result.success:
                get_logger('action').error(
                    f"Centering action for flare {flare_name} failed (success=False). Stopping.")
                continue
                # return False

            get_logger('action').info(
                f"Flare {flare_name} centered => now punch")

            # === 3) Сбитие (подача surge) ===
            punch_goal = TwistAction.Goal()
            punch_goal.surge = 70.0
            punch_goal.sway = 0.0
            punch_goal.depth = self.depth
            punch_goal.roll = self.roll
            punch_goal.pitch = self.pitch
            punch_goal.yaw = 0.0
            punch_goal.duration = self.punch_duration

            punch_result = await self.twist_action_client.send_goal_async(punch_goal)
            # Допустим, у нас есть punch_result.result.success
            # Проверим:
            if not punch_result.result.success:
                get_logger('action').error(
                    f"Punch action for flare {flare_name} failed. Stopping.")
                continue
                # return False

            get_logger('action').info(f"Flare {flare_name} has been punched.")
            punched_flares_count += 1

        # После цикла проверяем, сбили ли мы хотя бы один flare
        if punched_flares_count == 0:
            get_logger('action').error(
                "No flares were successfully punched. Mission failed.")
            return False
        else:
            get_logger('action').info(
                f"Mission complete. Total flares punched: {punched_flares_count}")
            return True


class HydroacousticCenteringTwistStateAction(StateActionBase):
    type = "HydroacousticCenteringTwist"

    def __init__(self, node: Node):
        super().__init__(node=node)

        self.hydroacoustic_centering_twist_action_client = AsyncActionClient(
            self.node, HydroacousticCenteringTwistAction, self.node.get_parameter('hydroacoustic_centering_twist_action').get_parameter_value().string_value)

    def stop(self):
        get_logger("action").info(
            f"Stopping {self.type} action")
        self.hydroacoustic_centering_twist_action_client.cancel()
        return super().stop()

    async def execute(self,
                      bbox_name: str = "",
                      bbox_topic: str = "",
                      hydroacoustic_topic: str = "",
                      angle_threshold: float = 0.0,
                      distance_threshold: float = 0.0,
                      lost_threshold: int = 0,
                      surge: float = 0.0,
                      sway: float = 0.0,
                      depth: float = 0.0,
                      roll: float = 0.0,
                      pitch: float = 0.0,
                      duration: float = 0.0,
                      centering_rate: float = 0.0,
                      **kwargs) -> bool:
        get_logger("action").info(f"Executing {self.type} state action")
        self.goal = HydroacousticCenteringTwistAction.Goal()
        self.goal.bbox_name = bbox_name
        self.goal.bbox_topic = bbox_topic
        self.goal.hydroacoustic_topic = hydroacoustic_topic
        self.goal.angle_threshold = float(angle_threshold)
        self.goal.distance_threshold = float(distance_threshold)
        self.goal.lost_threshold = int(lost_threshold)
        self.goal.surge = float(surge)
        self.goal.sway = float(sway)
        self.goal.depth = float(depth)
        self.goal.roll = float(roll)
        self.goal.pitch = float(pitch)
        self.goal.duration = float(duration)
        self.goal.centering_rate = float(centering_rate)

        if not self.hydroacoustic_centering_twist_action_client.wait_for_server(timeout_sec=1.0):
            get_logger("action").error(
                f"Timeout while waiting for {self.hydroacoustic_centering_twist_action_client._action_name} action server")
            return False

        result = await self.hydroacoustic_centering_twist_action_client.send_goal_async(self.goal)
        if not result.result.success:
            get_logger('action').error(
                f"Error while executing {self.node.get_parameter('hydroacoustic_centering_twist_action').get_parameter_value().string_value}")
            return False
        return await super().execute(**kwargs)


def load_sauvc_actions(node: Node) -> dict[str, StateActionBase]:
    """Load all actions"""
    stingray_actions = load_stingray_actions(node)
    # get_logger("action").info(f'Loaded stingray_actions: {stingray_actions}')

    sauvc_actions = {
        GateSearchStateAction.type: GateSearchStateAction(node),
        GateVisualControlStateAction.type: GateVisualControlStateAction(node),
        ControlOffsetStateAction.type: ControlOffsetStateAction(node),
        SequencePunchBboxTwistStateAction.type: SequencePunchBboxTwistStateAction(node),
        HydroacousticCenteringTwistStateAction.type: HydroacousticCenteringTwistStateAction(
            node)
    }
    # get_logger("action").info(f'Loaded sauvc_actions: {sauvc_actions}')
    return {**stingray_actions, **sauvc_actions}
