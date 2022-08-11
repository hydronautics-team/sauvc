import rospy
from sauvc_missions.drums import DrumsMission
from sauvc_missions.gate_centering import GateMission
from stingray_tfsm.auv_controller import AUVController

NODE_NAME = "sauvc_controller"


def no_mission_set(*args, **kwargs):
    rospy.loginfo("No mission")


def setup(*args, **kwargs):
    """here arguments from launches/ros should be retrieved and applied to where they belong"""
    # TODO machine which just checks that all required topics and nodes are online
    pass


class SAUVCController(AUVController):
    def __init__(self):
        super().__init__()
        self.add_mission_transitions((
            {'trigger': 'skip',
             'source': 'init',
             'dest': 'done',
             'prepare': no_mission_set},
        ))

    def setup_missions(self):
        if self.drums:
            self.gate_mission = GateMission(
                self.front_camera, self.bottom_camera)
            self.add_mission(self.gate_mission)
            self.drums_mission = DrumsMission(
                self.front_camera, self.bottom_camera)
            self.add_mission(self.drums_mission)
            self.add_mission_transitions([
                [self.transition_start, self.state_init, 'gate'],
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
    simulation = rospy.get_param("~simulation")

    controller = SAUVCController()
    controller.run()
