import rospy
import smach
from stingray_missions_lib.missions_fsm import Mission, MissionsFSMFactory


class GatesMission(Mission):
    def __init__(self):
        Mission.__init__(self, "GATES")

    def execute(self, userdata):
        rospy.loginfo("OOOOOOOOOOOKKKKKKKKK")
        return self.outcome_ok_


class SauvcMissions(MissionsFSMFactory):
    def __init__(self):
        MissionsFSMFactory.__init__(self)

    def create_fsm(self):
        sm = smach.StateMachine(outcomes=[self.outcome_ok_, self.outcome_failed_])
        with sm:
            smach.StateMachine.add("GATES", GatesMission(), transitions={"GATES_OK": self.outcome_ok_,
                                                                         "GATES_FAILED": self.outcome_failed_})
        return sm

