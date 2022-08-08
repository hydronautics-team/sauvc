#! /usr/bin/env python3

from stingray_tfsm.ros_transitions import AUVStateMachine
from stingray_tfsm.vision_events import ObjectDetectionEvent
from stingray_object_detection_msgs.srv import SetEnableObjectDetection
from stingray_object_detection_msgs.msg import ObjectsArray
from stingray_tfsm.load_config import load_config
import rospy

HARDCODE = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
HARDCODE1 = '/front_camera/image_raw/yolo_detector/objects'
EXHAUST_MAX = 40
CONFIRMATION = 10
TARGET = 'blue_bowl'

ROS_CONFIG = load_config()


STATES = ('init', 'condition_drums', 'custom_setup',
          'rotate_clockwise', 'rotate_anticlockwise', 'move_march', 'done', 'aborted')
TRANSITIONS = [     # Vision exhaustion loop
    ['start', ['init', 'rotate_clockwise', 'move_march'], 'condition_drums'],
    ['condition_f', 'condition_drums', 'rotate_clockwise'],
    ['condition_s', 'condition_drums', 'move_march'],
    ['end', '*', 'done']
]

drums_detection_event = ObjectDetectionEvent(HARDCODE, TARGET, CONFIRMATION)
EXHAUSTION = 0


def drums_condition(*args, **kwargs):
    global EXHAUSTION
    drums_detection_event.start_listening()
    rospy.sleep(2)
    if drums_detection_event.is_triggered():
        rospy.loginfo("DEBUG: drums detected by event")
        EXHAUSTION = 0
        drums_detection_event.stop_listening()
        return 1
    else:
        EXHAUSTION += 1
        rospy.loginfo("DEBUG: no drums detected")
        drums_detection_event.stop_listening()
        if EXHAUSTION >= EXHAUST_MAX:
            rospy.loginfo("it's time to stop, but i'll implement it later")
        return 0


def set_camera_online(args):
    print(f"trying to set object detection on camera {args[0]} to {args[1]}")
    srv_name = ROS_CONFIG["services"]["set_enable_object_detection"]
    rospy.wait_for_service(srv_name)
    set_camera = rospy.ServiceProxy(srv_name, SetEnableObjectDetection)
    print(set_camera(args[0], args[1]))
    rospy.wait_for_message(HARDCODE, ObjectsArray)


def rotation_overflow_condition(*args, **kwargs):
    return 1


STATES_ARGS = {
    'init': {
        'preps': set_camera_online,
        "args": (0, 1),
    },
    'condition_drums': {
        'condition': drums_condition,
        'args': None
    },
    'rotate_clockwise': {
        'angle': 10
    },
    'rotate_anticlockwise': {
            'angle': -10
        },
    'move_march': {
        'direction': 3,
        'velocity': 0.4,
        'duration': 1000
    },
    'done': {},
    'aborted': {}
}

drums_mission = AUVStateMachine(STATES, TRANSITIONS, STATES_ARGS)

if __name__ == '__main__':
    rospy.init_node("control_fsm")
    drums_mission.run()
