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
                 tolerance: int = 10,
                 confidence: float = 0.3,
                 rotate='right',
                 verbose: bool = False,
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
            rotate=rotate,
        )

        self.centering_submachine = CenteringWithAvoidSub(
            PureStateMachine.construct_name('CenteringOnMoveFlare', name),
            auv,
            camera,
            target,
            confirmation,
            tolerance,
            confidence,
            verbose=verbose,
            wait=3,
            speed=0.3,
            is_big_h=0.5,
            is_big_method='height',
        )

        super().__init__(name, auv, camera, '', verbose=verbose)

    def setup_states(self):
        return ('move_march', 'custom_search_yellow_flare', 'custom_centering_yellow_flare', 'custom_stop')

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, self.machine.state_init,'custom_search_yellow_flare'],

            ['go_search_yellow', 'custom_search_yellow_flare', 'custom_centering_yellow_flare'],

            ['go_centering_flare', 'custom_centering_yellow_flare', 'move_march'],

            ['go_yellow', 'move_march', 'custom_stop'],

            [self.machine.transition_end, 'custom_stop', self.machine.state_end],
        ]
        return transitions

    def prerun(self):
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 800,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.0,
            'lag': 0.0,
            'yaw': -90,
            'wait': 2,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.6,
            'lag': 0.0,
            'yaw': 0,
            'wait': 2,
        })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
            'custom_search_yellow_flare': {
                'subFSM': True,
                'custom': self.search_submachine,
                'args': ()
            },
            'custom_centering_yellow_flare': {
                'subFSM': True,
                'custom': self.centering_submachine,
                'args': ()
            },
            'move_march': {
                'march': 0.6,
                'lag': 0.0,
                'yaw': 0,
                'wait': 5,
            },
            'custom_stop': {
                'custom': self.machine.auv.execute_stop_goal,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass
