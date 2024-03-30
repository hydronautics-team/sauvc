from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # zbar camera
    zbar_camera_topic_arg = DeclareLaunchArgument(
        "zbar_camera_topic", default_value='/stingray/topics/front_camera'
    )
    
    # object detection
    image_topic_list_arg = DeclareLaunchArgument(
        "image_topic_list", default_value='[/stingray/topics/front_camera, /stingray/topics/bottom_camera]'
    )
    weights_pkg_name_arg = DeclareLaunchArgument(
        "weights_pkg_name", default_value='sauvc_object_detection'
    )
    bbox_attrs_pkg_name_arg = DeclareLaunchArgument(
        "bbox_attrs_pkg_name", default_value='sauvc_object_detection'
    )
    debug_arg = DeclareLaunchArgument(
        "debug", default_value='True'
    )


    # load ros config
    return LaunchDescription([
        zbar_camera_topic_arg,
        image_topic_list_arg,
        weights_pkg_name_arg,
        bbox_attrs_pkg_name_arg,
        debug_arg,

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'vision_yolov8.launch.py'))),
            launch_arguments={
                'zbar_camera_topic': LaunchConfiguration("zbar_camera_topic"),
                'weights_pkg_name': LaunchConfiguration("weights_pkg_name"),
                'bbox_attrs_pkg_name': LaunchConfiguration("bbox_attrs_pkg_name"),
                'image_topic_list': LaunchConfiguration("image_topic_list"),
                'debug': LaunchConfiguration("debug"),
            }.items(),
        ),

    ])
