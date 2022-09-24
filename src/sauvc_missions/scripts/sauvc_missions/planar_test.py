from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.planar_submachine import CenteringPlanarSub


class TestMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_cam: str = None,
                 camera: str = None,
                 simulation=True,
                 *args,
                 **kwargs
                 ):
        self.camera = camera  # bottom

        self.planar_submachine = CenteringPlanarSub(
            'planar',
            camera,  # bottom needed
            'blue_bowl',
            simulation=simulation
            )

        super().__init__(name, front_cam, camera)

    def setup_states(self):
        return 'custom_centering',

    def setup_transitions(self):
        transitions = [
                          [self.machine.transition_start, [self.machine.state_init, ], 'custom_centering'],
                      ] + self.machine.default_transitions
        return transitions

    def preparations(self, *args, **kwargs):
        self.enable_object_detection(self.camera, True)
        self.machine.auv.execute_dive_goal({
            'depth': 4  # 4 for sim, 500 for hard
        })
        pass

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'preps': self.preparations,
                "args": (),
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
