from stingray_tfsm.ros_transitions import AUVStateMachine
#from sauvc_missions.centering import centering_sub
from sauvc_missions.centering_experimental import CenteringSub
from stingray_tfsm.vision_events import ObjectDetectionEvent
from stingray_object_detection_msgs.srv import SetEnableObjectDetection
from stingray_object_detection_msgs.msg import ObjectsArray
from stingray_tfsm.load_config import load_config
import rospy

HARDCODE = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
HARDCODE1 = '/front_camera/image_raw/yolo_detector/objects'
EXHAUST_MAX = 40
CONFIRMATION = 2
TARGET = 'gate'
ROS_CONFIG = load_config()

STATES = ('init', 'condition_gate',
          'rotate_clockwise', 'condition_centering',
          'move_march_0', 'condition_in_front', 'move_march_1',
          'done', 'aborted')

TRANSITIONS = [
    ['start', ['init', 'rotate_clockwise'], 'condition_gate'],

    ['condition_f', 'condition_gate', 'rotate_clockwise'],
    ['condition_s', 'condition_gate', 'condition_centering'],

    ['condition_f', 'condition_centering', 'condition_gate'],
    ['condition_s', 'condition_centering', 'move_march_0'],

    ['next', 'move_march_0', 'condition_in_front'],

    ['condition_f', 'condition_in_front', 'condition_centering'],
    ['condition_s', 'condition_in_front', 'move_march_1'],

    ['end', '*', 'done']
]

gate_detection_event = ObjectDetectionEvent(HARDCODE, TARGET, CONFIRMATION)
EXHAUSTION = 0
centering_sub = CenteringSub()


def gates_condition(*args, **kwargs):
    global EXHAUSTION
    gate_detection_event.start_listening()
    rospy.sleep(0.5)
    if gate_detection_event.is_triggered():
        rospy.loginfo("DEBUG: gate detected by event")
        EXHAUSTION = 0
        gate_detection_event.stop_listening()
        return 1
    else:
        EXHAUSTION += 1
        rospy.loginfo("DEBUG: no gate detected")
        gate_detection_event.stop_listening()
        if EXHAUSTION >= EXHAUST_MAX:
            rospy.loginfo("it's time to stop, but i'll implement it later")
        return 0


def not_gates(*args, **kwargs):
    rospy.sleep(1)
    return not gates_condition(*args, **kwargs)


def set_camera_online(args):
    print(f"trying to set object detection on camera {args[0]} to {args[1]}")
    srv_name = ROS_CONFIG["services"]["set_enable_object_detection"]
    rospy.wait_for_service(srv_name)
    set_camera = rospy.ServiceProxy(srv_name, SetEnableObjectDetection)
    print(set_camera(args[0], args[1]))
    rospy.wait_for_message(HARDCODE, ObjectsArray)


STATES_ARGS = {
    'init': {
        'preps': set_camera_online,
        "args": (0, 1),
    },
    'condition_gate': {
        'condition': gates_condition,
        'args': None
    },
    'condition_in_front': {
        'condition': not_gates,
        'args': None
    },
    'rotate_clockwise': {
        'angle': 5
    },
    'condition_centering': {
        'subFSM': True,
        'condition': centering_sub,
        'args': None
    },
    'move_march_0': {
        'direction': 3,
        'velocity': 0.4,
        'duration': 1500
    },
    'move_march_1': {
        'direction': 3,
        'velocity': 0.41,
        'duration': 2000
    },
    'done': {},
    'aborted': {}
}

gate_mission = AUVStateMachine(STATES, TRANSITIONS, STATES_ARGS)

if __name__ == '__main__':
    rospy.init_node("control_fsm")
    gate_mission.run()
