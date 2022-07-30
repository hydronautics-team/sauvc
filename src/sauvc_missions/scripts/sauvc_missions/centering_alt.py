#! /usr/bin/env python3

from stingray_tfsm.ros_transitions import AUVStateMachine
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectOnRight, ObjectOnLeft

import rospy

TARGET = 'gate'
CONFIRMATION = 2
TOLERANCE = 14
SIM_CAMERA = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
HRD_CAMERA = '/front_camera/image_raw/yolo_detector/objects'


class Centering:
    EXHAUSTION = 0
    gate_detected = None
    gate_lefter = None
    gate_righter = None

    @staticmethod
    def set_camera(yolo_topic=SIM_CAMERA):
        Centering.gate_detected = ObjectDetectionEvent(yolo_topic, TARGET, CONFIRMATION)
        Centering.gate_lefter = ObjectOnLeft(yolo_topic, TARGET, CONFIRMATION, tolerance=TOLERANCE * 0.01)
        Centering.gate_righter = ObjectOnRight(yolo_topic, TARGET, CONFIRMATION, tolerance=TOLERANCE * 0.01)

    def lefter(self, *args, **kwargs):
        Centering.gate_lefter.start_listening()
        rospy.sleep(0.8)
        if Centering.gate_lefter.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is more than {TOLERANCE}% lefter")
            Centering.EXHAUSTION += 1
            Centering.gate_lefter.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is less {TOLERANCE}% lefter from center")
            Centering.gate_lefter.stop_listening()
            return 0

    def righter(self, *args, **kwargs):
        Centering.gate_righter.start_listening()
        rospy.sleep(0.8)
        if Centering.gate_righter.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is more than {TOLERANCE}% righter")
            Centering.EXHAUSTION += 1
            Centering.gate_righter.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is less {TOLERANCE}% righter from center")
            Centering.gate_righter.stop_listening()
            return 0

    def visible(self, *args, **kwargs):
        Centering.gate_detected.start_listening()
        rospy.sleep(0.8)
        if Centering.gate_detected.is_triggered():
            rospy.loginfo(f"DEBUG: Gate is visible")
            Centering.gate_detected.stop_listening()
            return 1
        else:
            rospy.loginfo(f"DEBUG: Gate is not visible")
            Centering.gate_detected.stop_listening()
            return 0

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