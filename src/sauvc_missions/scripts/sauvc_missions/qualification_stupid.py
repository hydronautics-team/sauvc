from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_control import AUVControl
import rospy


class QualificationStupidMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 camera: str,
                 ):

        self.camera = camera

        super().__init__(name, auv, camera, '')

    def setup_states(self):
        return ()

    def setup_transitions(self):
        return []

    def run_qual(self):
        self.machine.auv.execute_dive_goal({
            'depth': 800,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.5,
            'lag': 0.0,
            'yaw': 0,
            'wait': 35,
        })

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.run_qual,
                "args": (),
            },
            self.machine.state_end: {
                'preps': self.machine.auv.execute_stop_goal,
                "args": (),
            }
        }
        return scene

    def setup_events(self):
        pass
