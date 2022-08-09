#! /usr/bin/env python3

from stingray_tfsm.mission_transitions import MissionBase
from stingray_tfsm.ros_transitions import AUVStateMachine
from stingray_tfsm.pure_transitions import FSM_Simple
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectOnRight, ObjectOnLeft

import rospy


class CenteringSub(MissionBase):
    TARGET = 'gate'
    CONFIRMATION = 2
    TOLERANCE = 14
    SIM_CAMERA = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
    HRD_CAMERA = '/front_camera/image_raw/yolo_detector/objects'
    STATES = ('init', 'condition_detected',
              'condition_lefter', 'condition_righter',
              'rotate_clock', 'rotate_anti',
              'condition_exhausted', 'done', 'aborted')
    TRANSITIONS = [
        ['start', ['init', 'rotate_clock', 'rotate_anti'], 'condition_detected'],

        ['condition_f', 'condition_detected', 'aborted'],
        ['condition_s', 'condition_detected', 'condition_lefter'],

        ['condition_f', 'condition_lefter', 'condition_righter'],
        ['condition_s', 'condition_lefter', 'rotate_anti'],

        ['condition_f', 'condition_righter', 'done'],
        ['condition_s', 'condition_righter', 'rotate_clock'],
        # add exhaustion
        ['end', '*', 'done']
    ]

    def setup_events(self):
        self.gate_detected = ObjectDetectionEvent(self.camera, self.TARGET, self.CONFIRMATION)
        self.gate_lefter = ObjectOnLeft(self.camera, self.TARGET, self.CONFIRMATION, tolerance=self.TOLERANCE * 0.01)
        self.gate_righter = ObjectOnRight(self.camera, self.TARGET, self.CONFIRMATION, tolerance=self.TOLERANCE * 0.01)
        self.events = True
        return self.events

    def reset(self, camera=False):
        self.events = False
        self.camera = camera
        if self.camera:
            self.camera = self.SIM_CAMERA
        else:
            self.camera = self.HRD_CAMERA
        rospy.loginfo(f"CenteringSub yobject feed set to {self.camera}")

        self.setup_events()

        self.scene = {
            'init': {
                'time': 0.1
            },
            'condition_detected': {
                'condition': self.event_handler,
                'args': self.gate_detected
            },
            'condition_righter': {
                'condition': self.event_handler,
                'args': self.gate_righter
            },
            'condition_lefter': {
                'condition': self.event_handler,
                'args': self.gate_lefter
            },
            'rotate_anti': {
                'angle': -5
            },
            'rotate_clock': {
                'angle': 5
            },
            'done': {},
            'aborted': {}
        }

        if self.events:
            self.machine = AUVStateMachine(CenteringSub.STATES, CenteringSub.TRANSITIONS, self.scene, verbose=False)

    def __init__(self, target='gate'):
        self.confirmation = rospy.get_param('/control_fsm' + "/centering_confirmation", self.CONFIRMATION)
        self.tolerance = rospy.get_param('/control_fsm/centering_tolerance', self.TOLERANCE)

        self.events = False
        self.target = target

        self.gate_detected = None
        self.gate_lefter = None
        self.gate_righter = None

        self.scene = None
        self.machine = None

        self.camera = rospy.get_param('/control_fsm/simulation', False)
        self.reset(self.camera)

    def check_machine(self):
        if type(self.machine) is AUVStateMachine or \
                type(self.machine) is FSM_Simple:
            return 1
        else:
            raise TypeError("machine was not initialized")

    def set_state(self, state):
        if self.check_machine():
            self.machine.set_state(state)

    def run(self, *args, **kwargs):
        if self.check_machine():
            value = self.machine.run(*args, **kwargs)
            return value

    def verbose(self, verbose):
        if self.check_machine():
            self.machine.verbose(verbose)
