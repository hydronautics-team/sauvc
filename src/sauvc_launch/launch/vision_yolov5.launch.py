from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    # front camera
    front_camera_topic_arg = DeclareLaunchArgument(
        "front_camera_topic", default_value='/stingray/topics/front_camera'
    )
    front_camera_path_arg = DeclareLaunchArgument(
        "front_camera_path", default_value='/dev/video0'
    )
    # bottom camera
    bottom_camera_topic_arg = DeclareLaunchArgument(
        "bottom_camera_topic", default_value='/stingray/topics/bottom_camera'
    )
    bottom_camera_path_arg = DeclareLaunchArgument(
        "bottom_camera_path", default_value='/dev/video2'
    )

    # object detection
    image_topic_list_arg = DeclareLaunchArgument(
        "image_topic_list", default_value='[/stingray/topics/front_camera, /stingray/topics/bottom_camera]'
    )
    weights_pkg_name_arg = DeclareLaunchArgument(
        "weights_pkg_name", default_value='sauvc_object_detection'
    )
    debug_arg = DeclareLaunchArgument(
        "debug", default_value='True'
    )


    # load ros config
    return LaunchDescription([
        front_camera_topic_arg,
        front_camera_path_arg,
        bottom_camera_topic_arg,
        bottom_camera_path_arg,
        image_topic_list_arg,
        weights_pkg_name_arg,
        debug_arg,

        # camera
        # Node(
        #     package='usb_cam',
        #     executable='usb_cam_node_exe',
        #     name='bottom_camera_node',
        #     remappings=[
        #         ('/image_raw', LaunchConfiguration("bottom_camera_topic")),
        #     ],
        #     parameters=[
        #         {'video_device': LaunchConfiguration("bottom_camera_path")},
        #     ],
        #     respawn=True,
        #     respawn_delay=1,
        # ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'vision_yolov5.launch.py'))),
            launch_arguments={
                'camera_topic': LaunchConfiguration("front_camera_topic"),
                'camera_path': LaunchConfiguration("front_camera_path"),
                'weights_pkg_name': LaunchConfiguration("weights_pkg_name"),
                'image_topic_list': LaunchConfiguration("image_topic_list"),
                'debug': LaunchConfiguration("debug"),
            }.items(),
        ),

    ])
