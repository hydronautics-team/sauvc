import os
from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.actions import GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import TextSubstitution
from launch_ros.actions import Node
from launch_ros.actions import PushRosNamespace


def generate_launch_description():
    # topic names
    driver_request_topic_arg = DeclareLaunchArgument(
        "driver_request_topic", default_value='/stingray/topics/driver_hydroacoustic_request'
    )
   
    driver_response_topic_arg = DeclareLaunchArgument(
        "driver_response_topic", default_value='/stingray/topics/driver_response'
    )
    device_arg = DeclareLaunchArgument(
        "device", default_value="/dev/ttyUSB0"
    )
    baudrate_arg = DeclareLaunchArgument(
        "baudrate", default_value="115200"
    )
    data_bits_arg = DeclareLaunchArgument(
        "data_bits", default_value="8"
    )
    stop_bits_arg = DeclareLaunchArgument(
        "stop_bits", default_value="1"
    )
    parity_arg = DeclareLaunchArgument(
        "parity", default_value="none"
    )
    serial_timeout_arg = DeclareLaunchArgument(
        "serial_timeout", default_value="1000"
    )

    angle_hydroacoustic_topic_arg = DeclareLaunchArgument(
        "angle_hydroacoustic_topic", default_value='/stingray/topics/angle_hydroacoustic_topic'
    )

    driver_hydroacoustic_request_topic_arg = DeclareLaunchArgument(
        "driver_hydroacoustic_request_topic", default_value='/stingray/topics/driver_hydroacoustic_request'
    )
   
    driver_hydroacoustic_response_topic_arg = DeclareLaunchArgument(
        "driver_hydroacoustic_response_topic", default_value='/stingray/topics/driver_hydroacoustic_response'
    )

    return LaunchDescription([
        driver_request_topic_arg,
        driver_response_topic_arg,
        device_arg,
        baudrate_arg,
        data_bits_arg,
        stop_bits_arg,
        parity_arg,
        serial_timeout_arg,
        angle_hydroacoustic_topic_arg,
        driver_hydroacoustic_request_topic_arg,
        driver_hydroacoustic_response_topic_arg,
       
        Node(
            package='sauvc_pinger_finder',
            executable='uart_driver_node',
            name='uart_driver_node',
            parameters=[
                {'driver_request_topic': LaunchConfiguration("driver_request_topic")},
                {'driver_response_topic': LaunchConfiguration("driver_response_topic")},
                {'device': LaunchConfiguration("device")},
                {'baudrate': LaunchConfiguration("baudrate")},
                {'data_bits': LaunchConfiguration("data_bits")},
                {'stop_bits': LaunchConfiguration("stop_bits")},
                {'parity': LaunchConfiguration("parity")},
                {'serial_timeout': LaunchConfiguration("serial_timeout")},
            ],
            respawn=True,
            respawn_delay=0.5,
        ),
        Node(
            package='sauvc_pinger_finder',
            executable='hydroacoustic_bridge_node',
            name='hydroacoustic_bridge_node',
            parameters=[
                {'angle_hydroacoustic_topic': LaunchConfiguration("angle_hydroacoustic_topic")},
                {'driver_hydroacoustic_request_topic': LaunchConfiguration("driver_hydroacoustic_request_topic")},
                {'driver_hydroacoustic_response_topic': LaunchConfiguration("driver_hydroacoustic_response_topic")},
            ],
            # respawn=True,
            # respawn_delay=0.5,
        ),
    ])
