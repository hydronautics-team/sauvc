from sauvc_missions.sauvc_mission import SAUVCMission


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 ):
        super().__init__(name, front_camera, bottom_camera)

    def setup_states(self):
        return ('move_1', 'rotate_1',
                'move_2', 'rotate_2',
                'move_3', 'rotate_3',
                'move_4', 'rotate_4',) + self.machine.default_states

    def setup_transitions(self):
        return [

                   [self.machine.transition_start, self.machine.state_init, 'move_1'],
                   ['step_11', 'move_1', 'rotate_1'],

                   ['step_21', 'rotate_1', 'move_2'],
                   ['step_22', 'move_2', 'rotate_2'],

                   ['step_31', 'rotate_2', 'move_3'],
                   ['step_32', 'move_3', 'rotate_3'],

                   ['step_41', 'rotate_3', 'move_4'],
                   ['step_42', 'move_4', 'rotate_4'],

               ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'time': 7
            },
            'move_1': {
                'direction': 3,
                'velocity': 0.65,
                'duration': 2500
            },
            'rotate_1': {
                'angle': 90
            },
            'move_2': {
                'direction': 3,
                'velocity': 0.65,
                'duration': 2500
            },
            'rotate_2': {
                'angle': 90
            },
            'move_3': {
                'direction': 3,
                'velocity': 0.65,
                'duration': 2500
            },
            'rotate_3': {
                'angle': 90
            },
            'move_4': {
                'direction': 3,
                'velocity': 0.65,
                'duration': 2500
            },
            'rotate_4': {
                'angle': 90
            },
        }

    def setup_events(self):
        pass
