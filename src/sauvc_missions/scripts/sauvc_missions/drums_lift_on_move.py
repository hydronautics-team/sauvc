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


class DrumsLiftMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 verbose: bool = False,
                 ):
        super().__init__(name, auv, '', '', verbose=verbose)

    def setup_states(self):
        return ()

    def setup_transitions(self):
        return []

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
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_move_goal({
            'march': 0.2,
            'lag': 0.0,
            'yaw': 0,
            'wait': 5,
        })
        self.machine.auv.execute_stop_goal()
        self.lower()
        self.machine.auv.execute_dive_goal({
            'depth': 800,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.0,
            'lag': 0.0,
            'yaw': 720,
            'wait': 10,
        })
        self.lift()
        self.machine.auv.execute_stop_goal()

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
        }
        return scene

    def setup_events(self):
        pass
