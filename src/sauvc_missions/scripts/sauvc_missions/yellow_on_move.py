from stingray_tfsm.submachines.centering_on_move import CenteringWithAvoidSub
from stingray_tfsm.submachines.search_submachine import SearchSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
from stingray_tfsm.auv_control import AUVControl
import rospy


class FlareMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 camera: str,
                 target: str = 'yellow_flare',
                 confirmation: int = 2,
                 tolerance: int = 5,
                 confidence: float = 0.3,
                 verbose: bool = False,
                 rotate='left',
                 ):

        self.camera = camera
        self.target = target
        self.tolerance = tolerance
        self.confirmation = confirmation
        self.confidence = confidence

        self.search_submachine = SearchSub(
            PureStateMachine.construct_name('SearchFlare', name),
            auv,
            camera,
            target,
            tolerance=self.tolerance,
            confirmation=self.confirmation,
            confidence=self.confidence,
            rotate='right',
            )

        self.centering_submachine = CenteringWithAvoidSub(
            PureStateMachine.construct_name('CenteringOnMove', name),
            auv,
            camera,
            target,
            tolerance=self.tolerance,
            confirmation=self.confirmation,
            confidence=self.confidence,
            speed=0.5,
            wait=3,
            )

        super().__init__(name, auv, camera, '', verbose=verbose)

    def setup_states(self):
        return ('move_march', 'condition_search_yellow_flare', 'condition_centering_yellow_flare')

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, self.machine.state_init,
                'condition_search_yellow_flare'],

            ['condition_f', 'condition_search_yellow_flare',
                self.machine.state_aborted],
            ['condition_s', 'condition_search_yellow_flare',
                'condition_centering_yellow_flare'],

            ['condition_f', 'condition_centering_yellow_flare',
                'condition_centering_yellow_flare'],
            ['condition_s', 'condition_centering_yellow_flare', 'move_march'],

            [self.machine.transition_end, 'move_march', self.machine.state_end],
        ]
        return transitions

    def prerun(self):
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 800,
        })
        # self.machine.auv.execute_move_goal({
        #     'march': 0.6,
        #     'lag': 0.0,
        #     'yaw': 0,
        #     'wait': 15,
        # })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
            'condition_search_yellow_flare': {
                'subFSM': True,
                'condition': self.search_submachine,
                'args': ()
            },
            'condition_centering_yellow_flare': {
                'subFSM': True,
                'condition': self.centering_submachine,
                'args': ()
            },
            'move_march': {
                'march': 0.6,
                'lag': 0.0,
                'yaw': 0,
                'wait': 5,
            },
        }
        return scene

    def setup_events(self):
        pass
