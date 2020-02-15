import rospy
import smach
from stingray_missions_lib.missions_fsm import Mission, MissionsFSMFactory
from stingray_missions_lib.steering import BasicSteerer
import actionlib
import stingray_movement_msgs.msg
from sauvc_common.msg import Gate
from stingray_movement_msgs.msg import AlignValue


class GatesMission(Mission):
    def __init__(self):
        Mission.__init__(self, "GATES")
        self.pub_ = None

    def sub_callback(self, msg):
        value = AlignValue()
        if msg.is_exist:
            value.hasValue = True
            value.difference = msg.x_center
        else:
            value.hasValue = False
        self.pub_.publish(value)

    def execute(self, userdata):
        linear_client = actionlib.SimpleActionClient('stingray_action_linear_movement',
                                                     stingray_movement_msgs.msg.LinearMoveAction)
        align_client = actionlib.SimpleActionClient('stingray_action_align',
                                                    stingray_movement_msgs.msg.AlignAction)
        linear_client.wait_for_server()
        align_client.wait_for_server()
        steerer = BasicSteerer()

        self.pub_ = rospy.Publisher("/sauvc/topic/align/gate", AlignValue, queue_size=10)

        rospy.loginfo("Diving...")
        steerer.dive(70)
        rospy.loginfo("Dived!")

        lagGoal = steerer.create_lag_goal(600000, 0.2)
        linear_client.send_goal(lagGoal, active_cb=None, feedback_cb=None, done_cb=None)

        hasGateCount = 0
        while hasGateCount < 2:
            msg = rospy.wait_for_message("/bottom_equipment/gate", Gate)
            if msg.is_exist:
                hasGateCount += 1
            else:
                hasGateCount = 0

        steerer.stop()
        linear_client.cancel_goal()

        sub = rospy.Subscriber("/bottom_equipment/gate", Gate,
                               lambda msg: self.sub_callback(msg))
        align_goal = stingray_movement_msgs.msg.AlignGoal(topicName="/sauvc/topic/align/gate", delta=10.0)
        align_client.send_goal(align_goal)
        align_client.wait_for_result()

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
