from stingray_tfsm.submachines.centering_on_move import CenteringOnMoveSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
import rospy


class QualificationMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 camera: str,
                 target: str = 'gate',
                 rotate='left',
                 confirmation: int = 2,
                 tolerance: int = 3,
                 ):

        self.camera = camera
        self.target = target
        self.tolerance = tolerance
        self.confirmation = confirmation

        self.centering_submachine = CenteringOnMoveSub(
            name + "_centering", camera, target, tolerance=self.tolerance, confirmation=self.confirmation)
        self.rotate_dir = 1 if rotate == "left" else -1
        self.target_detection_event = None

        super().__init__(name, camera, '')

    def setup_states(self):
        return ('condition_gate', 'move_march',
                'move_rotate_search', 'condition_centering_on_move',
                )

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, [self.machine.state_init,
                                             'move_rotate_search', ], 'condition_gate'],


            ['condition_f', 'condition_gate', 'move_rotate_search'],
            ['condition_s', 'condition_gate', 'condition_centering_on_move'],

            ['condition_f', 'condition_centering_on_move', 'condition_gate'],
            # ['condition_s', 'condition_centering_on_move', 'move_march'],


        ]
        return transitions

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },
            'condition_gate': {
                'condition': self.target_event_handler,
                'args': ()
            },
            'move_rotate_search': {
                'march': 0.0,
                'lag': 0.0,
                'yaw': 30,
                # 'check_yaw': True,
                'wait': 0.5,
            },
            'condition_centering_on_move': {
                'subFSM': True,
                'condition': self.centering_submachine,
                'args': ()
            },
            'move_march': {
                'march': 1.0,
                'lag': 0.0,
                'yaw': 0,
                'wait': 15,
            },
        }
        return scene

    def setup_events(self):
        self.target_detection_event = ObjectDetectionEvent(
            get_objects_topic(self.camera), self.target, self.confirmation)

    def target_event_handler(self):
        self.target_detection_event.start_listening()
        rospy.loginfo("DEBUG: started listening target detection")

        rospy.sleep(3.5)
        if self.target_detection_event.is_triggered():
            rospy.loginfo("DEBUG: target detected by event")
            self.target_detection_event.stop_listening()
            return 1
        else:
            rospy.loginfo("DEBUG: no target detected")
            self.target_detection_event.stop_listening()
            return 0

    def check_machine(self):
        if type(self.machine) is AUVStateMachine or \
                type(self.machine) is PureStateMachine:
            return 1
        else:
            raise TypeError("machine was not initialized")

    def set_init_state(self, ):
        if self.check_machine():
            self.machine.set_state(self.machine.state_init)

    def set_state(self, state):
        if self.check_machine():
            self.machine.set_state(state)

    def run(self):
        if self.check_machine():
            value = self.machine.run()
            return value

    def verbose(self, verbose):
        if self.check_machine():
            self.machine.verbose(verbose)
