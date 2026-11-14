from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    mission_launch = os.path.join(
        get_package_share_directory('sauvc_missions'),
        'launch', 'gate_sauvc_2027.launch.py')
    return LaunchDescription([
        DeclareLaunchArgument(
            'synthetic_detections', default_value='true',
            description='Publish deterministic gate bboxes instead of YOLO'),
        DeclareLaunchArgument('gate_x', default_value='8.0'),
        DeclareLaunchArgument('gate_y', default_value='6.0'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(mission_launch),
            launch_arguments={
                'control_data_topic': '/control/data',
            }.items()),
        Node(
            package='sauvc_missions',
            executable='sim_gate_detector',
            condition=IfCondition(LaunchConfiguration('synthetic_detections')),
            parameters=[{
                'use_sim_time': True,
                'gate_x': LaunchConfiguration('gate_x'),
                'gate_y': LaunchConfiguration('gate_y'),
            }],
            output='screen'),
        Node(
            package='stingray_object_detection',
            executable='detection_distance_monitor',
            name='detection_distance_monitor',
            condition=IfCondition(LaunchConfiguration('synthetic_detections')),
            parameters=[{
                'bbox_topic': '/stingray/topics/camera/front/bbox_array',
                'log_interval': 1.0,
                'source': 'sim-ground-truth',
                'use_sim_time': True,
            }],
            output='screen'),
    ])
