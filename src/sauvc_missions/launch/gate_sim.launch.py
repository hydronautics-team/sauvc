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
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(mission_launch),
            launch_arguments={
                'control_data_topic': '/control/data',
            }.items()),
        Node(
            package='sauvc_missions',
            executable='sim_gate_detector',
            condition=IfCondition(LaunchConfiguration('synthetic_detections')),
            parameters=[{'use_sim_time': True}],
            output='screen'),
    ])
