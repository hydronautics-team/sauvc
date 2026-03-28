import asyncio

import rclpy
from rclpy.node import Node
from rclpy.logging import get_logger

from stingray_missions.fsm import FSM
from stingray_missions.fsm_node import ros_loop, fsm_loop, state_action_loop, declare_parameters
from sauvc_missions.action import load_sauvc_actions, SequencePunchBboxTwistStateAction
from stingray_interfaces.msg import UVState


def uv_state_callback( uv_state: UVState):
    # get_logger("fsm").info(f"uv_state: {uv_state}")
    # get_logger("fsm").info(f"uv_state.flare_seq: {uv_state.flare_seq}, len: {len(uv_state.flare_seq)}")
    unpacked = [chr(i) for i in uv_state.flare_seq]
    # get_logger("fsm").info(f"unpacked: {unpacked}")
    if "R" in unpacked and "Y" in unpacked and "B" in unpacked:
        SequencePunchBboxTwistStateAction.sequence = unpacked
    # elif "H" in unpacked and "H" in unpacked and "H" in unpacked:
    #     self.add_pending_transition(Transition.fail)
    else:
        SequencePunchBboxTwistStateAction.sequence = ["Y", "R", "B"]
    # get_logger("fsm").info(
    #     f"flare_sequence: {SequencePunchBboxTwistStateAction.sequence}")


def main():
    rclpy.init()

    node = rclpy.create_node('stingray_missions')

    declare_parameters(node)
    node.declare_parameter(
        'hydroacoustic_centering_twist_action', '/stingray/actions/hydroacoustic_centering_twist')

    mission_package_names = node.get_parameter(
        'mission_package_names').get_parameter_value().string_array_value

    fsm = FSM(node=node,
              scenarios_packages=mission_package_names,
              actions=load_sauvc_actions(node))

    node.create_subscription(
        UVState,
        node.get_parameter(
            'uv_state_topic').get_parameter_value().string_value,
        uv_state_callback,
        1)

    event_loop = asyncio.get_event_loop()
    future = asyncio.wait(
        [ros_loop(node), fsm_loop(fsm), state_action_loop(fsm)], return_when=asyncio.FIRST_EXCEPTION
    )
    done, _pending = event_loop.run_until_complete(future)
    for task in done:
        task.result()

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
