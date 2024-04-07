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
    # object detection
    bbox_array_topic_arg = DeclareLaunchArgument(
        "bbox_array_topic", default_value='/stingray/topics/front_camera/bbox_array'
    )

    # missions
    mission_package_names_arg = DeclareLaunchArgument(
        "mission_package_names", default_value='[sauvc_missions, stingray_missions]'
    )

    # core
    uv_state_topic_arg = DeclareLaunchArgument(
        "uv_state_topic", default_value='/stingray/topics/uv_state'
    )
    device_state_array_topic_arg = DeclareLaunchArgument(
        "device_state_array_topic", default_value='/stingray/topics/device_state_array'
    )
    set_twist_srv_arg = DeclareLaunchArgument(
        "set_twist_srv", default_value='/stingray/services/set_twist'
    )
    set_stabilization_srv_arg = DeclareLaunchArgument(
        "set_stabilization_srv", default_value='/stingray/services/set_stabilization'
    )
    reset_imu_srv_arg = DeclareLaunchArgument(
        "reset_imu_srv", default_value='/stingray/services/reset_imu'
    )
    enable_thrusters_srv_arg = DeclareLaunchArgument(
        "enable_thrusters_srv", default_value='/stingray/services/enable_thrusters'
    )
    set_device_srv_arg = DeclareLaunchArgument(
        "set_device_srv", default_value='/stingray/services/set_device'
    )

    # load ros config
    return LaunchDescription([
        bbox_array_topic_arg,
        mission_package_names_arg,
        uv_state_topic_arg,
        set_twist_srv_arg,
        device_state_array_topic_arg,
        reset_imu_srv_arg,
        set_stabilization_srv_arg,
        enable_thrusters_srv_arg,
        set_device_srv_arg,

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'control.launch.py'))),
            launch_arguments={
                'bbox_array_topic': LaunchConfiguration("bbox_array_topic"),
                'mission_package_names': LaunchConfiguration("mission_package_names"),
                'uv_state_topic': LaunchConfiguration("uv_state_topic"),
                'device_state_array_topic': LaunchConfiguration("device_state_array_topic"),
                'set_twist_srv': LaunchConfiguration("set_twist_srv"),
                'set_stabilization_srv': LaunchConfiguration("set_stabilization_srv"),
                'reset_imu_srv': LaunchConfiguration("reset_imu_srv"),
                'enable_thrusters_srv': LaunchConfiguration("enable_thrusters_srv"),
                'set_device_srv': LaunchConfiguration("set_device_srv"),
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('sauvc_launch'), 'pinger.launch.py')))
        ),
        
    ])
