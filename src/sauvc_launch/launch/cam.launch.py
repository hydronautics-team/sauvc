from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition


def generate_launch_description():
    # Аргументы для фронтальной камеры
    front_camera_topic_arg = DeclareLaunchArgument(
        "front_camera_topic", default_value='/stingray/topics/camera/front'
    )
    front_camera_info_topic_arg = DeclareLaunchArgument(
        "front_camera_info_topic", default_value='/stingray/topics/camera/front/camera_info'
    )
    front_camera_path_arg = DeclareLaunchArgument(
        "front_camera_path", default_value='/dev/video0'
    )
    front_camera_calibration_path_arg = DeclareLaunchArgument(
        "front_camera_calibration_path", default_value="package://welt_cam/configs/front_camera.yaml"
    )
    # Аргументы для нижней камеры
    bottom_camera_topic_arg = DeclareLaunchArgument(
        "bottom_camera_topic", default_value='/stingray/topics/camera/bottom'
    )
    bottom_camera_info_topic_arg = DeclareLaunchArgument(
        "bottom_camera_info_topic", default_value='/stingray/topics/camera/bottom/camera_info'
    )
    bottom_camera_path_arg = DeclareLaunchArgument(
        "bottom_camera_path", default_value='/dev/video4'
    )
    bottom_camera_calibration_path_arg = DeclareLaunchArgument(
        "bottom_camera_calibration_path", default_value="package://welt_cam/configs/bottom_camera.yaml"
    )
    enable_bottom_camera_arg = DeclareLaunchArgument(
        "enable_bottom_camera", default_value="true",
        description="Включить (true) или отключить (false) ноду нижней камеры"
    )

    return LaunchDescription([
        front_camera_topic_arg,
        front_camera_info_topic_arg,
        front_camera_path_arg,
        front_camera_calibration_path_arg,
        bottom_camera_topic_arg,
        bottom_camera_info_topic_arg,
        bottom_camera_path_arg,
        bottom_camera_calibration_path_arg,
        enable_bottom_camera_arg,

        # Нода фронтальной камеры
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='front_camera_node',
            remappings=[
                ('/image_raw', LaunchConfiguration("front_camera_topic")),
                ('/camera_info', LaunchConfiguration("front_camera_info_topic")),
            ],
            parameters=[
                {'video_device': LaunchConfiguration("front_camera_path")},
                {'camera_info_url': LaunchConfiguration(
                    "front_camera_calibration_path")},
                {'camera_name': 'front_camera'},
                {'image_width': 640},
                {'image_height': 480},
            ],
            respawn=True,
            respawn_delay=1,
        ),
        # Нода нижней камеры (запускается при enable_bottom_camera==true)
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='bottom_camera_node',
            remappings=[
                ('/image_raw', LaunchConfiguration("bottom_camera_topic")),
                ('/camera_info', LaunchConfiguration("bottom_camera_info_topic")),
            ],
            parameters=[
                {'video_device': LaunchConfiguration("bottom_camera_path")},
                {'camera_info_url': LaunchConfiguration(
                    "bottom_camera_calibration_path")},
                {'camera_name': 'bottom_camera'},
                {'image_width': 640},
                {'image_height': 480},
            ],
            respawn=True,
            respawn_delay=1,
            condition=IfCondition(LaunchConfiguration('enable_bottom_camera'))
        ),
    ])
