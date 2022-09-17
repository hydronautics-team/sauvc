from stingray_tfsm.auv_missions_controller import AUVMissionsController
import rospy

NODE_NAME = "sauvc_controller"


def setup(*args, **kwargs):
    """here arguments from launches/ros should be retrieved and applied to where they belong"""
    # TODO machine which just checks that all required topics and nodes are online
    pass


class SAUVCController(AUVMissionsController):
    def __init__(self,
                 gate: bool,
                 flare: bool,
                 drums: bool,
                 test: bool,
                 qual: bool,
                 qual_stupid: bool,
                 verbose: bool,
                 front_camera: str,
                 bottom_camera: str,
                 depth_stabilization: bool,
                 pitch_stabilization: bool,
                 yaw_stabilization: bool,
                 lag_stabilization: bool,
                 reset_imu: bool,
                 ):
        self.test = test
        self.gate = gate
        self.yellow_flare = flare
        self.drums = drums
        self.qual = qual
        self.qual_stupid = qual_stupid
        self.test = test
        self.verbose = verbose

        self.front_camera = front_camera
        self.bottom_camera = bottom_camera
        self.depth_stabilization = depth_stabilization
        self.pitch_stabilization = pitch_stabilization
        self.yaw_stabilization = yaw_stabilization
        self.lag_stabilization = lag_stabilization
        self.reset_imu = reset_imu

        super().__init__(self.depth_stabilization, self.pitch_stabilization, self.yaw_stabilization,
                         self.lag_stabilization, self.reset_imu)

    def setup_missions(self):

        super().setup_missions()
        if self.test:
            from sauvc_missions.devices_test import TestMission
            test_mission = TestMission(
                TestMission.__name__,
                self.front_camera,
                self.bottom_camera
            )
            self.add_mission(test_mission)

        if self.qual:
            from sauvc_missions.qualification import QualificationMission
            qual_mission = QualificationMission(
                QualificationMission.__name__,
                self.front_camera
            )
            self.add_mission(qual_mission)

        if self.qual_stupid:
            from sauvc_missions.qualification_stupid import QualificationStupidMission
            qual_stupid_mission = QualificationStupidMission(
                QualificationStupidMission.__name__,
                self.front_camera
            )
            self.add_mission(qual_stupid_mission)

        if self.gate:
            from sauvc_missions.gate import GateMission
            gate_mission = GateMission(
                GateMission.__name__,
                self.front_camera,
                self.bottom_camera,
                rotate='left',
                lag='left',
            )
            self.add_mission(gate_mission)

        if self.yellow_flare:
            from sauvc_missions.yellow import FlareMission
            flare_mission = FlareMission(
                FlareMission.__name__,
                self.front_camera,
                self.bottom_camera,
                rotate='right',
                lag='right',
            )
            self.add_mission(flare_mission)

        if self.drums:
            from sauvc_missions.drums import DrumsMission
            drums_mission = DrumsMission(
                DrumsMission.__name__,
                self.front_camera,
                self.bottom_camera
            )
            self.add_mission(drums_mission)


if __name__ == '__main__':
    rospy.init_node(NODE_NAME)

    gate = rospy.get_param("~gate", False)
    qual = rospy.get_param("~qual", False)
    qual_stupid = rospy.get_param("~qual_stupid", False)
    flare = rospy.get_param("~flare", False)
    drums = rospy.get_param("~drums", False)
    verbose = rospy.get_param("~verbose", True)
    test = rospy.get_param("~test", False)
    front_camera = rospy.get_param("~front_camera")
    bottom_camera = rospy.get_param("~bottom_camera")
    depth_stabilization = rospy.get_param("~depth_stabilization", False)
    pitch_stabilization = rospy.get_param("~pitch_stabilization", False)
    yaw_stabilization = rospy.get_param("~yaw_stabilization", False)
    lag_stabilization = rospy.get_param("~lag_stabilization", False)
    reset_imu = rospy.get_param("~reset_imu", False)

    controller = SAUVCController(
        gate,
        flare,
        drums,
        test,
        qual,
        qual_stupid,
        verbose,
        front_camera,
        bottom_camera,
        depth_stabilization,
        pitch_stabilization,
        yaw_stabilization,
        lag_stabilization,
        reset_imu,
    )
    controller.run()
