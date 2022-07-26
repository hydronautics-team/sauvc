from stingray_tfsm.ros_transitions import AUVStateMachine
from sauvc_missions.centering import centering_sub
from stingray_tfsm.vision_events import ObjectDetectionEvent
import rospy

HARDCODE = '/rov_model_urdf/camera_front/image_raw/yolo_detector/objects'
HARDCODE1 = '/front_camera/image_raw/yolo_detector/objects'

gate_detection_event = ObjectDetectionEvent(HARDCODE, 'gate', 2)
EXHAUSTION = 0


def gates_condition(*args, **kwargs):
    gate_detection_event.start_listening()
    rospy.sleep(0.8)
    if gate_detection_event.is_triggered():
        rospy.loginfo("DEBUG: gate detected by event")
        gate_detection_event.stop_listening()
        return 1
    else:
        rospy.loginfo("DEBUG: no gate detected")
        gate_detection_event.stop_listening()
        return 0


def not_gates(*args, **kwargs):
    return not gates_condition(*args, **kwargs)


STATES = ('init', 'condition_gate',
          'rotate_clockwise', 'condition_centering',
          'move_march_0', 'condition_in_front', 'move_march_1',
          'done', 'aborted')

TRANSITIONS = [
    ['start', ['init', 'rotate_clockwise', 'move_march_1'], 'condition_gate'],

    ['condition_f', 'condition_gate', 'rotate_clockwise'],
    ['condition_s', 'condition_gate', 'condition_centering'],

    ['condition_f', 'condition_centering', 'condition_gate'],
    ['condition_s', 'condition_centering', 'move_march_0'],

    ['next', 'move_march_0', 'condition_in_front'],

    ['condition_f', 'condition_in_front', 'condition_centering'],
    ['condition_s', 'condition_in_front', 'move_march_1'],

    ['end', '*', 'done']
]

STATES_ARGS = {
    'init': {
        'time': 10
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
        'angle': 10
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
        'velocity': 0.4,
        'duration': 1500
    },
    'done': {},
    'aborted': {}
}

gate_mission = AUVStateMachine(STATES, TRANSITIONS, STATES_ARGS)

if __name__ == '__main__':
    rospy.init_node("control_fsm")
    gate_mission.run()