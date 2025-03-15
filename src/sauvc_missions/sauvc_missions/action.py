import asyncio
from rclpy.logging import get_logger
from rclpy.node import Node
from stingray_utils.acyncio import AsyncActionClient
from stingray_interfaces.action import TwistAction
from stingray_interfaces.action import BboxCenteringTwistAction
from stingray_interfaces.action import BboxBottomCenteringTwistAction
from stingray_interfaces.action import BboxSearchTwistAction
from sauvc_interfaces.action import HydroacousticCenteringTwistAction
from stingray_missions.action import StateActionBase, load_stingray_actions


class SequencePunchBboxTwistStateAction(StateActionBase):
    type = "SequencePunchBboxTwist"

    def __init__(self, node: Node):
        super().__init__(node=node)

        self.bbox_centering_twist_action_client = AsyncActionClient(
            self.node, BboxCenteringTwistAction, self.node.get_parameter('bbox_centering_twist_action').get_parameter_value().string_value)
        self.bbox_search_twist_action_client = AsyncActionClient(
            self.node, BboxSearchTwistAction, self.node.get_parameter('bbox_search_twist_action').get_parameter_value().string_value)
        self.twist_action_client = AsyncActionClient(
            self.node, TwistAction, self.node.get_parameter('twist_action').get_parameter_value().string_value)

    def stop(self):
        self.bbox_centering_twist_action_client.cancel()
        self.bbox_search_twist_action_client.cancel()
        return super().stop()

    def get_bbox_name(self, flare_id: str):
        if flare_id == "R":
            return "red_flare"
        elif flare_id == "B":
            return "blue_flare"
        elif flare_id == "Y":
            return "yellow_flare"
        else:
            return "yellow_flare"

    def get_avoid_bbox_array(self, flare_id: str):
        if flare_id == "R":
            return ["blue_flare", "yellow_flare"]
        elif flare_id == "B":
            return ["red_flare", "yellow_flare"]
        elif flare_id == "Y":
            return ["red_flare", "blue_flare"]
        else:
            return []

    async def execute(self,
                      sequence: list[str] = ["R", "B", "Y"],
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

        self.bbox_topic = bbox_topic
        self.sequence = sequence
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

        # Проверка доступности сервера экшена
        if not self.bbox_search_twist_action_client.wait_for_server(timeout_sec=1.0): 
            get_logger("action").error(
                f"Timeout while waiting for {self.bbox_search_twist_action_client._action_name} action server")
            return False
        
        if not self.bbox_centering_twist_action_client.wait_for_server(timeout_sec=1.0): 
            get_logger("action").error(
                f"Timeout while waiting for {self.bbox_centering_twist_action_client._action_name} action server")
            return False
        
        if not self.twist_action_client.wait_for_server(timeout_sec=1.0):
            get_logger("action").error(
                f"Timeout while waiting for {self.twist_action_client._action_name} action server")
            return False

        # ещё один костыль, но он нужен
        if len(self.sequence) != 3 : self.sequence = ["R", "B", "Y"]
        get_logger('action').info(
                f"sequence: {self.sequence}")
        
        #for flare in self.sequence:
        count = 0
        while self.sequence:
            count += 1
            flare = self.sequence.pop(0)

            search_goal = BboxSearchTwistAction.Goal()
            search_goal.bbox_name = self.get_bbox_name(flare_id=flare)
            get_logger('action').info(
                f"Target bbox flare: {search_goal.bbox_name}")
            search_goal.bbox_topic = self.bbox_topic
            search_goal.first_clockwise = self.first_clockwise
            search_goal.found_threshold = int(self.found_threshold)
            search_goal.max_yaw = float(self.max_yaw)
            search_goal.yaw_step = float(self.yaw_step)
            search_goal.depth = float(self.depth)
            search_goal.roll = float(self.roll)
            search_goal.pitch = float(self.pitch)
            search_goal.search_rate = float(self.search_rate)
            result = await self.bbox_search_twist_action_client.send_goal_async(search_goal)
            if not result.result.success:
                get_logger('action').error(
                    f"Error while executing {self.node.get_parameter('bbox_search_twist_action').get_parameter_value().string_value}")
                return False
            # if flare did't finded
            if not result.result.finded:
                if count < 3 : 
                    self.sequence.append(flare)
                    get_logger('action').error(
                    f"Flare not finded, go to the next")
                    continue
                else : 
                    get_logger('action').error(
                    f"Not all flares was killed, but action is complete")
                    return True

            centering_goal = BboxCenteringTwistAction.Goal()
            centering_goal.bbox_name = self.get_bbox_name(flare_id=flare)
            centering_goal.bbox_topic = self.bbox_topic
            centering_goal.distance_threshold = float(self.distance_threshold)
            centering_goal.lost_threshold = int(self.lost_threshold)
            centering_goal.avoid_bbox_name_array = self.get_avoid_bbox_array(
                flare_id=flare)
            centering_goal.avoid_distance_threshold = float(
                self.avoid_distance_threshold)
            centering_goal.avoid_horizontal_threshold = float(
                self.avoid_horizontal_threshold)
            centering_goal.surge = float(self.surge)
            centering_goal.sway = float(self.avoid_sway)
            centering_goal.depth = float(self.depth)
            centering_goal.roll = float(self.roll)
            centering_goal.pitch = float(self.pitch)
            centering_goal.duration = float(self.centering_duration)
            centering_goal.centering_rate = float(self.centering_rate)
            result = await self.bbox_centering_twist_action_client.send_goal_async(centering_goal)
            if not result.result.success:
                get_logger('action').error(
                    f"Error while executing {self.node.get_parameter('bbox_centering_twist_action').get_parameter_value().string_value}")
                return False

            punch_goal = TwistAction.Goal()
            punch_goal.surge = float(70.0)
            punch_goal.sway = float(0.0)
            punch_goal.depth = float(self.depth)
            punch_goal.roll = float(self.roll)
            punch_goal.pitch = float(self.pitch)
            punch_goal.yaw = float(0.0)
            punch_goal.duration = float(self.punch_duration)
            # result = await self.twist_action_client.send_goal_async(punch_goal)
        return await super().execute(**kwargs)


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
    
    sauvc_actions ={
        SequencePunchBboxTwistStateAction.type: SequencePunchBboxTwistStateAction(node),
        HydroacousticCenteringTwistStateAction.type: HydroacousticCenteringTwistStateAction(node)
    }
    # get_logger("action").info(f'Loaded sauvc_actions: {sauvc_actions}')
    return {**stingray_actions, **sauvc_actions}
