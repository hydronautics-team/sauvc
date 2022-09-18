from stingray_tfsm.submachines.centering_on_move import CenteringOnMoveSub
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

        self.centering_submachine = CenteringOnMoveSub(
            PureStateMachine.construct_name('CenteringOnMove', name),
            auv,
            camera,
            target,
            tolerance=self.tolerance,
            confirmation=self.confirmation,
            confidence=self.confidence)

        super().__init__(name, auv, camera, '')

    def setup_states(self):
        return ('move_march', 'condition_centering_on_move')

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, self.machine.state_init,
                'condition_centering_on_move'],

            ['condition_f', 'condition_centering_on_move',
                'condition_centering_on_move'],
            ['condition_s', 'condition_centering_on_move', 'move_march'],

            [self.machine.transition_end, 'move_march', self.machine.state_end],
        ]
        return transitions

    def prerun(self):
        self.machine.auv.execute_dive_goal({
            'depth': 1500,
        })
        self.machine.auv.execute_move_goal({
            'march': 1.0,
            'lag': 0.0,
            'yaw': 0,
            'wait': 25,
        })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
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
                'wait': 5,
            },
        }
        return scene

    def setup_events(self):
        pass
