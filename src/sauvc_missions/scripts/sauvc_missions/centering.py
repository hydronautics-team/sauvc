#! /usr/bin/env python3

from stingray_tfsm.ros_transitions import AUVStateMachine
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectOnRight, ObjectOnLeft

import rospy

TARGET = 'gate'
CONFIRMATION = 2
TOLERANCE = 14
HARDCODE = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
HARDCODE1 = '/front_camera/image_raw/yolo_detector/objects'

gate_detected = ObjectDetectionEvent(HARDCODE, TARGET, CONFIRMATION)
gate_lefter = ObjectOnLeft(HARDCODE, TARGET, CONFIRMATION, tolerance=TOLERANCE * 0.01)
gate_righter = ObjectOnRight(HARDCODE, TARGET, CONFIRMATION, tolerance=TOLERANCE * 0.01)


class Centering:
    EXHAUSTION = 0

    def lefter(self, *args, **kwargs):
        gate_lefter.start_listening()
        rospy.sleep(0.8)
        if gate_lefter.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is more than {TOLERANCE}% lefter")
            Centering.EXHAUSTION += 1
            gate_lefter.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is less {TOLERANCE}% lefter from center")
            gate_lefter.stop_listening()
            return 0


    def righter(self, *args, **kwargs):
        gate_righter.start_listening()
        rospy.sleep(0.8)
        if gate_righter.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is more than {TOLERANCE}% righter")
            Centering.EXHAUSTION += 1
            gate_righter.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is less {TOLERANCE}% righter from center")
            gate_righter.stop_listening()
            return 0


    def visible(self, *args, **kwargs):
        gate_detected.start_listening()
        rospy.sleep(0.8)
        if gate_detected.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is visible")
            gate_detected.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is not visible")
            gate_detected.stop_listening()
            return 0

    def exhausted(self, *args, **kwargs):
        return Centering.EXHAUSTION >= 15


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

STATES_ARGS = {
    'init': {
        'time': 0.1
    },
    'condition_detected': {
        'condition': Centering.visible,
        'args': None
    },
    'condition_righter': {
        'condition': Centering.righter,
        'args': None
    },
    'condition_lefter': {
            'condition': Centering.lefter,
            'args': None
        },
    'rotate_anti': {
        'angle': -10
    },
    'rotate_clock': {
        'angle': 10
    },
    'done': {},
    'aborted': {}
}

centering_sub = AUVStateMachine(STATES, TRANSITIONS, STATES_ARGS)


