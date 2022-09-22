from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.centering_on_move import CenteringWithAvoidSub
from stingray_tfsm.core.pure_fsm import PureStateMachine
from stingray_tfsm.auv_control import AUVControl


class GateMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl,
                 camera: str,
                 target: str = 'gate',
                 confirmation: int = 2,
                 tolerance: int = 20,
                 confidence: float = 0.5,
                 avoid: str = 'red_flare',
                 avoid_confirmation: int = 2,
                 avoid_tolerance: int = 20,
                 avoid_confidence: float = 0.3,
                 verbose: bool = False,
                 ):
        self.camera = camera

        self.centering_gate_sub = CenteringWithAvoidSub(
            PureStateMachine.construct_name('CenteringAvoid', name),
            auv,
            camera,
            target,
            confirmation,
            tolerance,
            confidence,
            avoid,
            avoid_confirmation,
            avoid_tolerance,
            avoid_confidence,
            verbose,
            speed=0.5
        )
        super().__init__(name, auv, camera, '')

    def setup_states(self):
        return ['custom_centering_gate', 'move_march']

    def setup_transitions(self):
        return [
            [self.machine.transition_start, self.machine.state_init, 'custom_centering_gate'],

            ['pass_through', 'custom_centering_gate', 'move_march'],

            [self.machine.transition_end, 'move_march', self.machine.state_end]
        ]

    def prerun(self):
        self.enable_object_detection(self.camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 800,
        })
        self.machine.auv.execute_move_goal({
            'march': 0.6,
            'lag': 0.0,
            'yaw': 0,
            'wait': 5
        })

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
            'custom_centering_gate': {
                'subFSM': True,
                'custom': self.centering_gate_sub,
                'args': ()
            },
            'move_march': {
                'march': 0.7,
                'lag': 0.0,
                'yaw': 0,
                'wait': 10
            },
        }

    def setup_events(self):
        pass

    def gate_event_handler(self):
        pass
