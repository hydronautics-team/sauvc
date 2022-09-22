#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from stingray_tfsm.auv_control import AUVControl
import rospy


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl = None,
                 ):
        super().__init__(name, auv)

    def setup_states(self):
        return ('dive', 'move_march', 'move_lag')

    def setup_transitions(self):
        return [
            [self.machine.transition_start, self.machine.state_init, 'move_march'],
            ['step_0', 'dive', 'move_march'],
            ['step_11', 'move_march', 'move_lag'],
        ]

    def setup_scene(self):
        return {
            'dive': {
                'depth': 600,
                # 'check_depth': True
            },
            'move_march': {
                'march': 0.4,
                'lag': 0.0,
                'yaw': 0,
                'wait': 2,
            },
            'move_lag': {
                'march': 0.0,
                'lag': 0.4,
                'yaw': 0,
                'wait': 1,
            }
        }

    def setup_events(self):
        pass
