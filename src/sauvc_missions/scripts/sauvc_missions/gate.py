from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.reach_submachine import ReachSub


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
        self.reach_sub = ReachSub(
            name + "_reach_gate", front_camera, target, avoid, rotate, lag)
        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):

        return ('custom_reach_gate', 'custom_stub', 'move_march')

    def setup_transitions(self):
        return [
                   [self.machine.transition_start, [self.machine.state_init, ], 'custom_reach_gate'],


                   ['pass_through', 'custom_reach_gate', 'move_march'],

               ]

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': print,
                "args": (),
            },
            'custom_reach_gate': {
                'subFSM': True,
                'custom': self.reach_sub,
                'args': ()
            },
            'move_march': {
                'direction': 3,
                'velocity': 0.42,
                'duration': 2200
            },
        }

    def setup_events(self):
        pass

    def gate_event_handler(self):
        pass
