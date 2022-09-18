from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.reach_submachine import ReachSub


class FlareOnMoveMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 target='yellow_flare',
                 avoid=['red_flare', 'gate'],
                 rotate='left',
                 lag='left',
                 speed: int = 800,
                 ):

        self.reach_sub = ReachSub(name + "_reach_flare", front_camera, target, avoid, rotate, lag, speed)
        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):
        return ('custom_reach_flare', 'move_march', 'move_stop')

    def setup_transitions(self):
        return [
            [self.machine.transition_start, [self.machine.state_init, ], 'custom_reach_flare'],

            ['pass_through', 'custom_reach_flare', 'move_march'],

            ['finish', 'move_march', 'move_stop']
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
                'march': 1,
                'lag': 0.0,
                'yaw': 0,
                'wait': 0.5
            },
            'move_stop': {
                'march': 0,
                'lag': 0.0,
                'yaw': 0,
                'wait': 1
            },
        }

    def setup_events(self):
        pass

    def gate_event_handler(self):
        pass
