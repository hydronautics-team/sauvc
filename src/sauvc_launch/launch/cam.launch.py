from pathlib import Path

from ament_index_python import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition
from launch.actions import IncludeLaunchDescription


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("enable_front_camera",
                              default_value="true",
                              description="Включить (true) или отключить (false) ноду нижней камеры"),
        DeclareLaunchArgument('front_camera_topic',
                              default_value='/stingray/topics/camera/front',
                              description='Топик с изображениями для первой камеры'),
        DeclareLaunchArgument("front_camera_info_topic",
                              default_value='/stingray/topics/camera/front/camera_info'),
        DeclareLaunchArgument("front_camera_path",
                              default_value='/dev/video0'),
        DeclareLaunchArgument("front_camera_calibration_path",
                              default_value="package://sauvc_cam/configs/front_camera.yaml"),
        DeclareLaunchArgument('front_camera_output_width',
                              default_value='640',
                              description='Ширина видео'),
        DeclareLaunchArgument('front_camera_output_height',
                              default_value='480',
                              description='Высота видео'),
        # bottom camera
        DeclareLaunchArgument("enable_bottom_camera",
                              default_value="true",
                              description="Включить (true) или отключить (false) ноду нижней камеры"),
        DeclareLaunchArgument('bottom_camera_topic',
                              default_value='/stingray/topics/camera/bottom',
                              description='Топик с изображениями для второй камеры'),
        DeclareLaunchArgument("bottom_camera_info_topic",
                              default_value='/stingray/topics/camera/bottom/camera_info'),
        DeclareLaunchArgument("bottom_camera_path",
                              default_value='/dev/video2'),
        DeclareLaunchArgument("bottom_camera_calibration_path",
                              default_value="package://sauvc_cam/configs/bottom_camera.yaml"),
        DeclareLaunchArgument('bottom_camera_output_width',
                              default_value='640',
                              description='Ширина видео'),
        DeclareLaunchArgument('bottom_camera_output_height',
                              default_value='480',
                              description='Высота видео'),
        # recorder
        DeclareLaunchArgument("enable_recording_front_camera",
                              default_value="true",
                              description="Включить (true) или отключить (false) ноду нижней камеры"),
        DeclareLaunchArgument("enable_recording_bottom_camera",
                                default_value="true",
                                description="Включить(true) или отключить(false) ноду нижней камеры"),
        DeclareLaunchArgument('output_fps',
                              default_value='15',
                              description='Частота кадров видео'),
        DeclareLaunchArgument('output_format',
                              default_value='h264',
                              description='Формат видео (FourCC)'),
        DeclareLaunchArgument('record_dir',
                              default_value='./records/',
                              description='Путь к папке для сохранения записей'),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'zbar.launch.py'))),
            launch_arguments={
                'zbar_camera_topic': LaunchConfiguration("front_camera_topic"),
            }.items(),
        ),

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
                {'image_width': LaunchConfiguration(
                    "front_camera_output_width")},
                {'image_height': LaunchConfiguration(
                    "front_camera_output_height")},
            ],
            respawn=True,
            respawn_delay=1,
            condition=IfCondition(LaunchConfiguration('enable_front_camera'))
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
                {'image_width': LaunchConfiguration(
                    "bottom_camera_output_width")},
                {'image_height': LaunchConfiguration(
                    "bottom_camera_output_width")},
            ],
            respawn=True,
            respawn_delay=1,
            condition=IfCondition(LaunchConfiguration('enable_bottom_camera'))
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'recorder.launch.py'))),
            launch_arguments={
                'source_topic': LaunchConfiguration('front_camera_topic'),
                'output_width': LaunchConfiguration('front_camera_output_width'),
                'output_height': LaunchConfiguration('front_camera_output_height'),
                'output_fps': LaunchConfiguration('output_fps'),
                'output_format': LaunchConfiguration('output_format'),
                'record_dir': LaunchConfiguration('record_dir'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('enable_recording_front_camera'))
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(Path(
                get_package_share_directory('stingray_launch'), 'recorder.launch.py'))),
            launch_arguments={
                'source_topic': LaunchConfiguration('bottom_camera_topic'),
                'output_width': LaunchConfiguration('bottom_camera_output_width'),
                'output_height': LaunchConfiguration('bottom_camera_output_height'),
                'output_fps': LaunchConfiguration('output_fps'),
                'output_format': LaunchConfiguration('output_format'),
                'record_dir': LaunchConfiguration('record_dir'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('enable_recording_bottom_camera'))
        ),
    ])
