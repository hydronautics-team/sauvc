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
        
        return ('move_first', 'move_clock', 'move_second') + self.machine.default_states

    def setup_transitions(self):
        return [

            [self.machine.transition_start, self.machine.state_init, 'move_first'],

            ['step_1', 'move_first', 'move_clock'],

            ['step_2', 'move_clock', 'move_second'],

        ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'time': 5
            },
            'move_first': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'move_second': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
            'move_clock': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 5000
            },
        }

    def setup_events(self):
        self.gate_detection_event = ObjectDetectionEvent(
            get_objects_topic(self.front_camera), self.gate, self.confirmation)