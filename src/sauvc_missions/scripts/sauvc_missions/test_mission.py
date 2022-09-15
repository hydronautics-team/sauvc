#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
import rospy


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 gate="gate",
                 red_flare="red_flare",
                 yellow_flare="yellow_flare",
                 mat="mat",
                 blue_bowl="blue_bowl",
                 red_bowl="red_bowl"):
        super().__init__(name, front_camera, bottom_camera, gate,
                         red_flare, yellow_flare, mat, blue_bowl, red_bowl)

    def setup_states(self):
        return ('dive_0', 'move_march_1', 'move_yaw_1',
                'move_march_2', 'move_yaw_2',
                'move_march_3', 'move_yaw_3',
                'move_march_4', 'move_yaw_4',)

    def setup_transitions(self):
        return [
            [self.machine.transition_start, self.machine.state_init, 'dive_0'],
            ['step_0', 'dive_0', 'move_march_1'],
            ['step_11', 'move_march_1', 'move_yaw_1'],

            ['step_21', 'move_yaw_1', 'move_march_2'],
            ['step_22', 'move_march_2', 'move_yaw_2'],

            ['step_31', 'move_yaw_2', 'move_march_3'],
            ['step_32', 'move_march_3', 'move_yaw_3'],

            ['step_41', 'move_yaw_3', 'move_march_4'],
            ['step_42', 'move_march_4', 'move_yaw_4'],

            ['step_42', 'move_yaw_4', 'move_march_1'],

        ]

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'time': 2,
            },
            'dive_0': {
                'depth': 600,
                'check_depth': True
                
            },
            'move_march_1': {
                'march': 0.7,
                'lag': 0.0,
                'yaw': 0,
                'wait': 4,
            },
            'move_yaw_1': {
                'march': 0.0,
                'lag': 0.0,
                'yaw': 90,
                'wait': 4,
                # 'check_yaw': True
            },
            'move_march_2': {
                'march': 0.7,
                'lag': 0.0,
                'yaw': 0,
                'wait': 4,
            },
            'move_yaw_2': {
                'march': 0.0,
                'lag': 0.0,
                'yaw': 90,
                'wait': 4,
                # 'check_yaw': True
            },
            'move_march_3': {
                'march': 0.7,
                'lag': 0.0,
                'yaw': 0,
                'wait': 4,
            },
            'move_yaw_3': {
                'march': 0.0,
                'lag': 0.0,
                'yaw': 90,
                'wait': 4,
                # 'check_yaw': True
            },
            'move_march_4': {
                'march': 0.7,
                'lag': 0.0,
                'yaw': 0,
                'wait': 4,
            },
            'move_yaw_4': {
                'march': 0.0,
                'lag': 0.0,
                'yaw': 90,
                'wait': 4,
                # 'check_yaw': True
            },
        }

    def setup_events(self):
        pass