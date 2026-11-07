import asyncio
import math
import time
from geometry_msgs.msg import Twist
from rclpy.logging import get_logger
from rclpy.node import Node
from stingray_utils.acyncio import AsyncActionClient
from stingray_interfaces.action import TwistAction
from stingray_interfaces.action import BboxCenteringTwistAction
from stingray_interfaces.action import BboxSearchTwistAction
from stingray_interfaces.msg import BboxArray
from sauvc_interfaces.action import HydroacousticCenteringTwistAction
from stingray_missions.action import StateActionBase, load_stingray_actions


class GateVisualControlStateAction(StateActionBase):
    """Approach and center on a gate using the new /control/data contract."""

    type = "GateVisualControl"

    def __init__(self, node: Node):
        super().__init__(node=node)
        topic = self.node.get_parameter(
            'control_data_topic').get_parameter_value().string_value
        self.command_pub = self.node.create_publisher(Twist, topic, 10)
        self.bbox_sub = None
        self.target = None
        self.target_received_at = None

    def _bbox_callback(self, msg: BboxArray):
        candidates = [bbox for bbox in msg.bboxes
                      if bbox.name == self.target_name]
        if not candidates:
            return
        self.target = max(candidates, key=lambda bbox: bbox.confidence)
        self.target_received_at = time.monotonic()

    def _publish_stop(self):
        self.command_pub.publish(Twist())

    def stop(self):
        get_logger("action").info(f"Stopping {self.type} action")
        self._publish_stop()
        return super().stop()

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
                    self._publish_stop()
                    return False

                now = time.monotonic()
                if self.target is None:
                    if now - started_at > float(initial_detection_timeout):
                        get_logger("action").error(
                            f"{self.type}: gate was not detected")
                        self._publish_stop()
                        return False
                    await asyncio.sleep(period)
                    continue

                if now - self.target_received_at > float(lost_timeout):
                    get_logger("action").error(
                        f"{self.type}: gate detections became stale")
                    self._publish_stop()
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

                distance_error = max(0.0, target.pos_z - stop_distance)
                if distance_error > max(0.0, float(max_forward_offset)):
                    get_logger("action").error(
                        f"{self.type}: gate at {target.pos_z:.2f} m is outside "
                        f"the safe approach envelope")
                    self._publish_stop()
                    return False
                centered = abs(target.pos_x) <= horizontal_tolerance
                close_enough = distance_error <= 0.0
                confirmed = confirmed + 1 if centered and close_enough else 0

                if confirmed >= max(1, int(confirmation_count)):
                    self._publish_stop()
                    get_logger("action").info(
                        f"{self.type}: gate centered at {target.pos_z:.2f} m")
                    return await super().execute(**kwargs)

                command = Twist()
                command.linear.x = distance_error
                command.linear.y = max(
                    -abs(float(max_lateral_offset)),
                    min(abs(float(max_lateral_offset)),
                        float(lateral_gain) * target.pos_x))
                self.command_pub.publish(command)
                get_logger("action").info(
                    f"{self.type}: z={target.pos_z:.2f}, x={target.pos_x:.2f}, "
                    f"forward={command.linear.x:.2f}, lateral={command.linear.y:.2f}")
                await asyncio.sleep(period)

            get_logger("action").error(f"{self.type}: timeout")
            self._publish_stop()
            return False
        finally:
            if self.bbox_sub is not None:
                self.node.destroy_subscription(self.bbox_sub)
                self.bbox_sub = None


class ControlOffsetStateAction(StateActionBase):
    """Send one bounded relative-position target to the new control input."""

    type = "ControlOffset"

    def __init__(self, node: Node):
        super().__init__(node=node)
        topic = self.node.get_parameter(
            'control_data_topic').get_parameter_value().string_value
        self.command_pub = self.node.create_publisher(Twist, topic, 10)

    def _publish_stop(self):
        self.command_pub.publish(Twist())

    def stop(self):
        get_logger("action").info(f"Stopping {self.type} action")
        self._publish_stop()
        return super().stop()

    async def execute(self,
                      forward: float = 0.0,
                      lateral: float = 0.0,
                      settle_time: float = 3.0,
                      max_offset: float = 1.0,
                      **kwargs) -> bool:
        kwargs.pop("type", None)
        limit = abs(float(max_offset))
        command = Twist()
        command.linear.x = max(-limit, min(limit, float(forward)))
        command.linear.y = max(-limit, min(limit, float(lateral)))
        self.command_pub.publish(command)
        get_logger("action").info(
            f"{self.type}: forward={command.linear.x:.2f}, "
            f"lateral={command.linear.y:.2f}")

        deadline = time.monotonic() + max(0.0, float(settle_time))
        while time.monotonic() < deadline:
            if self.stopped:
                self._publish_stop()
                return False
            await asyncio.sleep(0.1)

        self._publish_stop()
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
        GateVisualControlStateAction.type: GateVisualControlStateAction(node),
        ControlOffsetStateAction.type: ControlOffsetStateAction(node),
        SequencePunchBboxTwistStateAction.type: SequencePunchBboxTwistStateAction(node),
        HydroacousticCenteringTwistStateAction.type: HydroacousticCenteringTwistStateAction(
            node)
    }
    # get_logger("action").info(f'Loaded sauvc_actions: {sauvc_actions}')
    return {**stingray_actions, **sauvc_actions}
