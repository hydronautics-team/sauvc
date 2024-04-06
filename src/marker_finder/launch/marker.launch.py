from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    calibration_config_dir = Path(get_package_share_directory('welt_cam')) / "configs"
    camera_calibration_path = calibration_config_dir / "bottom_camera.yaml"

    # bottom camera
    camera_topic_arg = DeclareLaunchArgument(
        "camera_bottom_topic_name", default_value='/stingray/topics/camera_bottom'
    )
    camera_path_arg = DeclareLaunchArgument(
        "camera_bottom_path", default_value='/dev/video0'
    )
    camera_calibration_path_arg = DeclareLaunchArgument(
        "camera_bottom_calibration_path", default_value=str(camera_calibration_path)
    )
    box_topic_arg = DeclareLaunchArgument(
        "box_topic_name", default_value='/stingray/topics/marker_box'
    )
    debug_arg = DeclareLaunchArgument(
        "debug", default_value='True'
    )
    debug_topic_arg = DeclareLaunchArgument(
        "debug_image_name", default_value='/stingray/topics/marker_debug_image'
    )
    kernel_arg = DeclareLaunchArgument(
        "kernel", default_value='5'
    )
    sigma_arg = DeclareLaunchArgument(
        "sigma", default_value='3'
    )
    closure_arg = DeclareLaunchArgument(
        "closure", default_value='10'
    )
    light_arg = DeclareLaunchArgument(
        "light", default_value='0.6'
    )
    grayness_arg = DeclareLaunchArgument(
        "grayness", default_value='0.1'
    )
 
    # load ros config
    return LaunchDescription([
        camera_topic_arg,
        camera_path_arg,
        camera_calibration_path_arg,
        box_topic_arg,
        debug_arg,
        debug_topic_arg,
        kernel_arg,
        sigma_arg,
        closure_arg,
        light_arg,
        grayness_arg,
        # bottom camera
        Node(
            package='marker_finder',
            executable='marker_detector',
            name='marker_finder_node',
            remappings=[
                ('/image_raw', LaunchConfiguration("camera_bottom_topic")),
            ],
            parameters=[
                {'video_device': LaunchConfiguration("camera_bottom_path")},
                {'params-file': LaunchConfiguration("camera_bottom_calibration_path")},
                # {'image_width': 640},
                # {'image_height': 480},
                # {'camera_name': 'camera'},
            ],
            respawn=True,
            respawn_delay=1,
        ),
    ])
