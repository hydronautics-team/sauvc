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
        return ('move_1', 'rotate_1',
                'move_2', 'rotate_2',
                'move_3', 'rotate_3',
                'move_4', 'rotate_4',) + self.machine.default_states

    def setup_transitions(self):
        return [
            [self.machine.transition_start, self.machine.state_init, 'move_1'],
            ['step_11', 'move_1', 'rotate_1'],

            ['step_21', 'rotate_1', 'move_2'],
            ['step_22', 'move_2', 'rotate_2'],

            ['step_31', 'rotate_2', 'move_3'],
            ['step_32', 'move_3', 'rotate_3'],

            ['step_41', 'rotate_3', 'move_4'],
            ['step_42', 'move_4', 'rotate_4'],

            ['step_42', 'rotate_4', 'move_1'],

        ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                # 'time': 7,
                'preps': self.suka,
                "args": (),
            },
            'move_1': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'rotate_1': {
                'angle': 90
            },
            'move_2': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'rotate_2': {
                'angle': 90
            },
            'move_3': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'rotate_3': {
                'angle': 90
            },
            'move_4': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'rotate_4': {
                'angle': 90
            },
        }

    def suka(self):
        self.machine.auv.execute_move_goal({
            'direction': 1,
            'velocity': 0.0,
            'duration': 1000
        })
        self.enable_stabilization(False, True, False)

    def setup_events(self):
        self.gate_detection_event = ObjectDetectionEvent(
            get_objects_topic(self.front_camera), self.gate, self.confirmation)
