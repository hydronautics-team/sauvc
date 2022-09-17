from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 camera: str,
                 *args,
                 **kwargs
                 ):

        self.camera = camera
        super().__init__(name, camera, '')

    def setup_states(self):
        return 'move_march',

    def setup_transitions(self):
        transitions = [
              [self.machine.transition_start, [self.machine.state_init, ], 'move_march'],
        ] + self.machine.default_transitions
        return transitions

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },
            'move_march': {
                'direction': 3,
                'velocity': 0.5,
                'duration': 1000
            },
        }
        return scene

    def setup_events(self):
        pass

    
