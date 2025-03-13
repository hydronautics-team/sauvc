from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition


def generate_launch_description():
    # load ros config
    return LaunchDescription([
        # object detection
        DeclareLaunchArgument("image_topic_list",
                              default_value='[/stingray/topics/camera/front, /stingray/topics/camera/bottom]'),
        DeclareLaunchArgument("camera_info_topic_list",
                              default_value='[/stingray/topics/camera/front/camera_info, /stingray/topics/camera/bottom/camera_info]'),
        DeclareLaunchArgument("weights_pkg_name",
                              default_value='sauvc_object_detection'),
        DeclareLaunchArgument("bbox_attrs_pkg_name",
                              default_value='sauvc_object_detection'),
        DeclareLaunchArgument("debug",
                              default_value='True'),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'od.launch.py'))),
            launch_arguments={
                'weights_pkg_name': LaunchConfiguration("weights_pkg_name"),
                'bbox_attrs_pkg_name': LaunchConfiguration("bbox_attrs_pkg_name"),
                'image_topic_list': LaunchConfiguration("image_topic_list"),
                'camera_info_topic_list': LaunchConfiguration("camera_info_topic_list"),
                'debug': LaunchConfiguration("debug"),
            }.items(),
        ),

    ])
