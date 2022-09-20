from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.reach_submachine import ReachSub
from stingray_tfsm.core.pure_fsm import PureStateMachine


class GateMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 target='gate',
                 avoid=['red_flare', ],
                 rotate='left',
                 lag='left',
                 ):
        self.reach_sub = ReachSub(PureStateMachine.construct_name('ReachGate', name), front_camera, target, avoid, rotate, lag)
        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):
        return 'custom_reach_gate', 'custom_stub', 'move_march', 'move_stop', 

    def setup_transitions(self):
        return [
            [self.machine.transition_start, [self.machine.state_init, ], 'custom_reach_gate'],

            ['pass_through', 'custom_reach_gate', 'move_march'],

            [self.machine.transition_end, 'move_march', self.machine.state_end]
        ]
    
    def prerun(self):
        self.enable_object_detection(self.front_camera, True)
        self.machine.auv.execute_dive_goal({
                    'depth': 1700,
                })
        self.machine.auv.execute_move_goal({
                    'march': 0.7,
                    'lag': 0.0,
                    'yaw': 0,
                    'wait': 0.2
                })

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.prerun,
                "args": (),
            },
            'custom_reach_gate': {
                'subFSM': True,
                'custom': self.reach_sub,
                'args': ()
            },
            'move_march': {
                'march': 1,
                'lag': 0.0,
                'yaw': 0,
                'wait': 0.5
            },
        }

    def setup_events(self):
        pass

    def gate_event_handler(self):
        pass
