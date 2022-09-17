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
        return 'custom_lower', 'custom_lift', 'custom_drop'

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, [self.machine.state_init, ], 'custom_lower'],
            ['grab', 'custom_lower', 'custom_lift'],
            ['drop', 'custom_lift', 'custom_drop'],
        ]
        return transitions

    def lift(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
            }
        )

    def drop(self):
        self.machine.auv.execute_dropper_goal()

    def lower(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
                "wait": 2
            }
        )

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'wait': 1
            },
            'custom_lift': {
                'custom': self.lift,
                'args': ()

            },
            'custom_drop': {
                'custom': self.drop,
                'args': ()
            },
            'custom_lower': {
                'custom': self.lower,
                'args': ()
            },

        }
        return scene

    def setup_events(self):
        pass


