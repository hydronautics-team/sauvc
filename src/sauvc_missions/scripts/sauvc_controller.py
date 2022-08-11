import rospy
from sauvc_missions.drums import DrumsMission
from sauvc_missions.gate_centering import GateMission
from stingray_tfsm.auv_controller import AUVController

NODE_NAME = "sauvc_controller"


def setup(*args, **kwargs):
    """here arguments from launches/ros should be retrieved and applied to where they belong"""
    # TODO machine which just checks that all required topics and nodes are online
    pass


class SAUVCController(AUVController):
    def __init__(self,
                 gate_vision: bool,
                 gate_brute: bool,
                 gate_centering: bool,
                 drums: bool,
                 verbose: bool,
                 centering_test: bool,
                 front_camera: str,
                 bottom_camera: str
                 ):
        super().__init__()
        self.gate_vision = gate_vision
        self.gate_brute = gate_brute
        self.gate_centering = gate_centering
        self.drums = drums
        self.verbose = verbose
        self.centering_test = centering_test
        self.front_camera = front_camera
        self.bottom_camera = bottom_camera

    def setup_missions(self):
        if self.drums:
            self.gate_mission = GateMission("gate_mission", 
                self.front_camera, self.bottom_camera)
            self.add_mission(self.gate_mission)
            self.drums_mission = DrumsMission("drums_mission", 
                self.front_camera, self.bottom_camera)
            self.add_mission(self.drums_mission)
            self.add_mission_transitions([
                [self.machine.transition_start, self.machine.state_init, 'gate'],
                ['finish_gate', 'gate', 'drums'],
            ])


if __name__ == '__main__':
    rospy.init_node(NODE_NAME)

    gate_vision = rospy.get_param("~gate_vision")
    gate_brute = rospy.get_param("~gate_brute", False)
    gate_centering = rospy.get_param("~gate_centering")
    drums = rospy.get_param("~drums")
    verbose = rospy.get_param("~verbose", True)
    centering_test = rospy.get_param("~test")
    front_camera = rospy.get_param("~front_camera")
    bottom_camera = rospy.get_param("~bottom_camera")

    controller = SAUVCController(
        gate_vision,
        gate_brute,
        gate_centering,
        drums,
        verbose,
        centering_test,
        front_camera,
        bottom_camera
    )
    controller.run()
