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
        
        return ('move_1', 'rotate_1', 'move_stop_1', 'move_2','rotate_2', 'move_stop_2', 'move_stop', 'rotate_reset') + self.machine.default_states

    def setup_transitions(self):
        return [

            [self.machine.transition_start, self.machine.state_init, 'move_1'],

            ['step_0', 'move_1', 'rotate_1'],

            ['step_1', 'rotate_1', 'move_stop_1'],
            
            ['step_2', 'move_stop_1', 'move_2'],

            ['step_3', 'move_2', 'rotate_2'],
            
            ['step_4', 'rotate_2', 'move_stop_2'],

        ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.enable_stabilization,
                "args": (False, True, False),
            },
            'rotate_reset_0': {
                'angle': 0
            },
            'move_1': {
                'direction': 1,
                'velocity': 0.7,
                'duration': 5000
            },
            'rotate_1': {
                'angle': 200,
            },
            'move_stop_1': {
                'direction': 1,
                'velocity': 0.0,
                'duration': 5000
            },
            'move_2': {
                'direction': 1,
                'velocity': 0.7,
                'duration': 5000
            },
            'rotate_2': {
                'angle': 200
            },
            'move_stop_2': {
                'direction': 1,
                'velocity': 0.0,
                'duration': 5000
            },
            'rotate_reset': {
                'angle': 0
            },
        }

    def setup_events(self):
        self.gate_detection_event = ObjectDetectionEvent(
            get_objects_topic(self.front_camera), self.gate, self.confirmation)