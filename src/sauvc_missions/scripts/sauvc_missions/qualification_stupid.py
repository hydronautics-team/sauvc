from stingray_tfsm.submachines.centering_on_move import CenteringOnMoveSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
import rospy


class QualificationStupidMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 camera: str,
                 ):

        self.camera = camera

        super().__init__(name, camera, '')

    def setup_states(self):
        return ()

    def setup_transitions(self):
        return []


    def run_qual(self):
        self.machine.auv.execute_dive_goal({
                    'depth': 1000,
                })
        self.machine.auv.execute_move_goal({
                    'march': 1.0,
                    'lag': 0.0,
                    'yaw': 0,
                    'wait': 15,
                })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.run_qual,
                "args": (),
            }
        }
        return scene

    def setup_events(self):
        pass

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
