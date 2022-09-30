from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.planar_submachine import CenteringPlanarSub
from stingray_resources.utils import load_config


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
        self.ros_con = load_config()
        self.marker_topic = self.ros_con['topics']['marker']

        self.red_drum_centering = CenteringPlanarSub(
            'red_drum',
            camera,  # bottom needed
            'red_bowl',
            simulation=simulation,
            drop=False
            )

        self.blue_drum_centering = CenteringPlanarSub(
            'blue_drum',
            camera,  # bottom needed
            'blue_bowl',
            simulation=simulation
        )

        self.marker_centering = CenteringPlanarSub(
            'marker',
            self.marker_topic,  # bottom needed
            'marker',
            simulation=simulation,
            drop=True
        )

        super().__init__(name, front_cam, camera)

    def setup_states(self):
        return 'custom_centering_drum', 'custom_centering_marker'

    def setup_transitions(self):
        transitions = [
                          [self.machine.transition_start, [self.machine.state_init, ], 'custom_centering_drum'],

                          ['susus', 'custom_centering_drum', 'custom_centering_marker'],

                      ] + self.machine.default_transitions
        return transitions

    def preparations(self, *args, **kwargs):
        self.enable_object_detection(self.camera, True)
        self.enable_marker_detection(self.camera, True)
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
            'custom_centering_drum': {
                'subFSM': True,
                'custom': self.red_drum_centering,
                'args': ()
            },
            'custom_centering_marker': {
                'subFSM': True,
                'custom': self.marker_centering,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass
