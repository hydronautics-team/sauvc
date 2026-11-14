from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    control_data_topic = LaunchConfiguration('control_data_topic')
    odometry_topic = LaunchConfiguration('odometry_topic')

    return LaunchDescription([
        DeclareLaunchArgument(
            'control_data_topic', default_value='/control/data_test'),
        DeclareLaunchArgument(
            'odometry_topic', default_value='/core/state/odometry'),
        Node(
            package='sauvc_missions',
            executable='fsm_node',
            name='visible_flare_test_fsm',
            output='screen',
            parameters=[{
                'mission_package_names': ['sauvc_missions'],
                'control_data_topic': control_data_topic,
                'odometry_topic': odometry_topic,
            }],
        ),
    ])
