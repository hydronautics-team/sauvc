from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    control_data_topic = LaunchConfiguration('control_data_topic')

    return LaunchDescription([
        DeclareLaunchArgument(
            'control_data_topic', default_value='/control/data_test'),
        Node(
            package='sauvc_missions',
            executable='fsm_node',
            name='gate_usb_test_fsm',
            output='screen',
            parameters=[{
                'mission_package_names': ['sauvc_missions'],
                'control_data_topic': control_data_topic,
            }],
        ),
    ])
