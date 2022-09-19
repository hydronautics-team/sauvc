from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.centering_planar import CenteringPlanarSub


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_cam,
                 camera: str,
                 *args,
                 **kwargs
                 ):
        self.camera = camera  # bottom

        self.planar_submachine = CenteringPlanarSub(
            'planar',
            camera,  # bottom needed
            'red_bowl',
            )

        super().__init__(name, front_cam, camera)

    def setup_states(self):
        return 'custom_centering',

    def setup_transitions(self):
        transitions = [
                          [self.machine.transition_start, [self.machine.state_init, ], 'custom_centering'],
                      ] + self.machine.default_transitions
        return transitions

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.camera, True),
            },
            'custom_centering': {
                'subFSM': True,
                'custom': self.planar_submachine,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass
