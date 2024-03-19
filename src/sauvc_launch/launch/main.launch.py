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

    # front camera
    front_camera_topic_arg = DeclareLaunchArgument(
        "front_camera_topic", default_value='/stingray/topics/front_camera'
    )
    front_camera_path_arg = DeclareLaunchArgument(
        "front_camera_path", default_value='/dev/video0'
    )

    # object detection
    image_topic_list_arg = DeclareLaunchArgument(
        "image_topic_list", default_value='/stingray/topics/front_camera'
    )
    weights_pkg_name_arg = DeclareLaunchArgument(
        "weights_pkg_name", default_value='sauvc_object_detection'
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
        front_camera_topic_arg,
        front_camera_path_arg,
        image_topic_list_arg,
        weights_pkg_name_arg,
        uv_state_topic_arg,
        set_twist_srv_arg,
        device_state_array_topic_arg,
        reset_imu_srv_arg,
        set_stabilization_srv_arg,
        enable_thrusters_srv_arg,
        set_device_srv_arg,
        
        # front camera
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='camera_driver',
            remappings=[
                ('/image_raw', LaunchConfiguration("front_camera_topic")),
            ],
            parameters=[
                {'video_device': LaunchConfiguration("front_camera_path")},
            ],
            respawn=True,
            respawn_delay=1,
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'main.launch.py'))),
            launch_arguments={
                'uv_state_topic': LaunchConfiguration("uv_state_topic"),
                'device_state_array_topic': LaunchConfiguration("device_state_array_topic"),
                'set_twist_srv': LaunchConfiguration("set_twist_srv"),
                'set_stabilization_srv': LaunchConfiguration("set_stabilization_srv"),
                'reset_imu_srv': LaunchConfiguration("reset_imu_srv"),
                'enable_thrusters_srv': LaunchConfiguration("enable_thrusters_srv"),
                'set_device_srv': LaunchConfiguration("set_device_srv"),
            }.items(),
        ),
        
    ])
