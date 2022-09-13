from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.reach_submachine import ReachSub


class FlareMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 target='yellow_flare',
                 avoid=['red_flare', 'gate'],
                 rotate='left',
                 lag='left',
                 ):

        self.reach_sub = ReachSub(name + "_reach_flare", front_camera, target, avoid, rotate, lag)
        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):
        return ('custom_reach_flare', 'move_march')

    def setup_transitions(self):
        return [
                   [self.machine.transition_start, [self.machine.state_init, ], 'custom_reach_flare'],

                   ['pass_through', 'custom_reach_flare', 'move_march'],

               ]

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': print,
                "args": (),
            },
            'custom_reach_flare': {
                'subFSM': True,
                'custom': self.reach_sub,
                'args': ()
            },
            'move_march': {
                'direction': 3,
                'velocity': 0.41,
                'duration': 2200
            },
        }

    def setup_events(self):
        pass

    def gate_event_handler(self):
        pass