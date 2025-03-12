import asyncio

import rclpy
from rclpy.node import Node

from stingray_missions.fsm import FSM
from stingray_missions.fsm_node import ros_loop, fsm_loop, state_action_loop, declare_parameters
from sauvc_missions.action import load_sauvc_actions


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
