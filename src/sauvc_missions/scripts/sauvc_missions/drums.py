#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent
from stingray_tfsm.reach_submachine import ReachSub
from stingray_tfsm.centering_planar import PlanarCenteringSub

import rospy


class DrumsMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 avoid=['red_flare', 'gate', 'yellow_flare'],
                 acoustics=False,
                 ):

        self.reach_sub = ReachSub(
            name + "_reach_mat", front_camera, 'mat', avoid, 'left', 'right')
        self.centering_red = PlanarCenteringSub(
            name + "_center_red_drum", bottom_camera, 'red_drum', offset=(0, 0), bottom=True)
        self.centering_red = PlanarCenteringSub(
            name + "_center_red_drum", bottom_camera, 'red_drum', offset=(0, 0), bottom=True)

        self.memory = {
            'blue_drum_0': {
                'visited': False
            },
            'red_drum_1': {
                'visited': False,
                'has_pinger': False,
                'has_ball': False,
            },
            'red_drum_2': {
                'visited': False,
                'has_pinger': False,
                'has_ball': False,
            },
            'red_drum_3': {
                'visited': False,
                'has_pinger': False,
                'has_ball': False,
            },
        }  # is it necessary?

        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):
        return ('condition_drums', 'custom_reach_mat',
                'condition_planar', 'rotate_anticlockwise', 'move_march') + self.machine.default_states

    def setup_transitions(self):
        return [
                   [self.machine.transition_start, [self.machine.state_init, 'rotate_clockwise',
                                                    'move_march'], 'condition_drums'],
                   ['condition_f', 'condition_drums', 'rotate_clockwise'],
                   ['condition_s', 'condition_drums', 'move_march'],
               ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },

            '': {},

            'done': {},
            'aborted': {}
        }

    def setup_events(self):
        pass


