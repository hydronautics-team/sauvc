from stingray_tfsm.auv_controller import AUVController
import rospy

NODE_NAME = "sauvc_controller"


def setup(*args, **kwargs):
    """here arguments from launches/ros should be retrieved and applied to where they belong"""
    # TODO machine which just checks that all required topics and nodes are online
    pass


class SAUVCController(AUVController):
    def __init__(self,
                 gate: bool,
                 flare: bool,
                 drums: bool,
                 test: bool,
                 verbose: bool,
                 front_camera: str,
                 bottom_camera: str
                 ):
        self.test = test
        self.gate = gate
        self.yellow_flare = flare
        self.drums = drums
        self.test = test
        self.verbose = verbose

        self.front_camera = front_camera
        self.bottom_camera = bottom_camera

        self.gate_mission = None
        self.flare_mission = None
        self.drums_mission = None
        self.last_mission = None

        super().__init__()

    def next_mission(self, mission):
        self.add_mission(mission)
        if self.last_mission is None:
            self.add_mission_transitions([
                [self.machine.transition_start, self.machine.state_init, mission.name],
            ])
            print(f'added{[self.machine.transition_start, self.machine.state_init, mission.name]}')
            self.last_mission = mission.name
        else:
            self.add_mission_transitions([
                [f"FROM_{self.last_mission}_TO_{mission.name}",
                 self.last_mission, mission.name],
            ])
            print('added ' + f"[FROM_{self.last_mission}_TO_{mission.name}", self.last_mission, mission.name, ']')
        self.last_mission = mission.name
        print(f'added {self.last_mission}')


    def arrange_finish(self):
        if self.last_mission is None:
            self.add_mission_transitions([
                ['skip', self.machine.state_init, self.machine.state_end],
            ])
            print('no mission set')
        else:
            self.add_mission_transitions([
                [self.machine.transition_end, self.last_mission, self.machine.state_end],
            ])
            print(f'{[self.machine.transition_end, self.last_mission, self.machine.state_end]}')


    def setup_missions(self):
        if self.gate:
            from sauvc_missions.gate import GateMission
            gate_mission = GateMission(
                GateMission.__name__,
                self.front_camera,
                self.bottom_camera,
                rotate='left',
                lag='left',
            )
            self.next_mission(gate_mission)

        if self.yellow_flare:
            from sauvc_missions.yellow import FlareMission
            flare_mission = FlareMission(
                FlareMission.__name__,
                self.front_camera,
                self.bottom_camera,
                rotate='right',
                lag='right',
            )
            self.next_mission(flare_mission)

        if self.drums:
            from sauvc_missions.drums import DrumsMission
            drums_mission = DrumsMission(
                DrumsMission.__name__,
                self.front_camera,
                self.bottom_camera
            )
            self.next_mission(drums_mission)

        if self.test:
            from sauvc_missions.uart_test_mission import TestMission
            self.test_mission = TestMission("test_mission",
                                              self.front_camera, self.bottom_camera)
            self.add_mission(self.test_mission)
            self.add_mission_transitions([
                [self.machine.transition_start, self.machine.state_init, self.test_mission.name],
                [self.machine.transition_end, self.test_mission.name, self.machine.state_end]
            ])

        self.arrange_finish()



if __name__ == '__main__':
    rospy.init_node(NODE_NAME)

    gate = rospy.get_param("~gate")
    flare = rospy.get_param("~flare", False)
    drums = rospy.get_param("~drums")
    verbose = rospy.get_param("~verbose", True)
    test = rospy.get_param("~test")
    front_camera = rospy.get_param("~front_camera")
    bottom_camera = rospy.get_param("~bottom_camera")

    controller = SAUVCController(
        gate,
        flare,
        drums,
        test,
        verbose,
        front_camera,
        bottom_camera
    )
    controller.run()
