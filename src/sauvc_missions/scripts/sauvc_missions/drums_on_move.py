from stingray_tfsm.submachines.centering_on_move import CenteringWithAvoidSub
from stingray_tfsm.submachines.search_submachine import SearchSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
from stingray_tfsm.auv_control import AUVControl
from stingray_tfsm.submachines.planar_submachine import CenteringPlanarSub
import rospy


class DrumsMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 camera: str,
                 bottom_camera: str,
                 target: str = 'blue_bowl',
                 confirmation: int = 2,
                 tolerance: int = 5,
                 confidence: float = 0.3,
                 rotate='left',
                 verbose: bool = False,
                 ):

        self.camera = camera
        self.bottom_camera = bottom_camera
        self.target = target
        self.tolerance = tolerance
        self.confirmation = confirmation
        self.confidence = confidence

        self.search_submachine = SearchSub(
            PureStateMachine.construct_name('SearchMat', name),
            auv,
            camera,
            "blue_bowl",
            tolerance=self.tolerance,
            confirmation=self.confirmation,
            confidence=self.confidence,
            rotate=rotate,
            )

        self.centering_submachine = CenteringWithAvoidSub(
            PureStateMachine.construct_name('CenteringOnMove', name),
            auv,
            camera,
            target,
            confirmation,
            tolerance,
            confidence,
            verbose=verbose,
            wait=4,
            speed=0.2,
            is_big_w=0.2,
            )

        self.centering_bottom_submachine = CenteringPlanarSub(
            'planar',
            bottom_camera,  # bottom needed
            'blue_bowl',
            auv=auv,
            )

        super().__init__(name, auv, camera, '', verbose=verbose)

    def setup_states(self):
        return ('move_march', 'condition_search_drums', 'condition_centering_drums', 'custom_stop', 'custom_centering', 'custom_drop')

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, self.machine.state_init, 'condition_search_drums'],

            ['condition_f', 'condition_search_drums', self.machine.state_aborted],
            ['condition_s', 'condition_search_drums', 'condition_centering_drums'],

            ['condition_f', 'condition_centering_drums', 'condition_centering_drums'],
            ['condition_s', 'condition_centering_drums', 'move_march'],

            ['go_centering', 'move_march', 'custom_drop'],

            [self.machine.transition_end, 'custom_drop', self.machine.state_end],
        ]
        return transitions
    
    def drop(self):
        self.machine.auv.execute_dropper_goal()

    def dropper_close(self):
        self.machine.auv.execute_dropper_goal(velocity=0)
    
    def lift(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
            }
        )
    
    def lower(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
                "wait": 2
            }
        )

    def prerun(self):
        self.lower()
        rospy.sleep(5)
        self.lift()
        rospy.sleep(5)

        self.drop()
        rospy.sleep(5)
        self.dropper_close()
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 600,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.0,
            'lag': 0.0,
            'yaw': -70,
            'wait': 2,
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
            'condition_search_drums': {
                'subFSM': True,
                'condition': self.search_submachine,
                'args': ()
            },
            'condition_centering_drums': {
                'subFSM': True,
                'condition': self.centering_submachine,
                'args': ()
            },
            'move_march': {
                'march': 0.2,
                'lag': 0.0,
                'yaw': 0,
                'wait': 5,
            },
            'custom_stop': {
                'custom': self.machine.auv.execute_stop_goal,
                'args': ()
            },
            'custom_drop': {
                'custom': self.drop,
                'args': ()
            },
            'custom_centering': {
                'subFSM': True,
                'custom': self.centering_bottom_submachine,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass
