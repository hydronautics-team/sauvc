from stingray_tfsm.submachines.centering_on_move import CenteringWithAvoidSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
from stingray_tfsm.auv_control import AUVControl
import rospy


class QualificationMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 camera: str,
                 target: str = 'gate',
                 confirmation: int = 2,
                 tolerance: int = 3,
                 confidence: float = 0.3,
                 verbose: bool = False,
                 ):

        self.camera = camera
        self.target = target
        self.tolerance = tolerance
        self.confirmation = confirmation
        self.confidence = confidence

        self.centering_submachine = CenteringWithAvoidSub(
            PureStateMachine.construct_name('CenteringOnMove', name),
            auv,
            camera,
            target,
            confirmation,
            tolerance,
            confidence,
            verbose,
        )

        super().__init__(name, auv, camera, '')

    def setup_states(self):
        return ('move_march', 'custom_centering_gate')

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, self.machine.state_init, 'custom_centering_gate'],

            ['pass_through', 'custom_centering_gate', 'move_march'],

            [self.machine.transition_end, 'move_march', self.machine.state_end],
        ]
        return transitions

    def prerun(self):
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 1200,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.6,
            'lag': 0.0,
            'yaw': 0,
            'wait': 5,
        })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
            'custom_centering_gate': {
                'subFSM': True,
                'custom': self.centering_submachine,
                'args': ()
            },
            'move_march': {
                'march': 1.0,
                'lag': 0.0,
                'yaw': 0,
                'wait': 5,
            },
        }
        return scene

    def setup_events(self):
        pass
