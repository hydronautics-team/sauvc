from pathlib import Path

from ament_index_python import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.actions import GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import TextSubstitution
from launch_ros.actions import Node
from launch_ros.actions import PushRosNamespace


def generate_launch_description():

    # load ros config
    return LaunchDescription([
        Node(
            package='sauvc_pinger_finder',
            executable='uart_driver_node',
            name='uart_driver_node'
            # parameters=[

            # ],
            # respawn=True,
            # respawn_delay=0.5,
        )
    ])