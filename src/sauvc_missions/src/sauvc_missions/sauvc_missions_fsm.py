import rospy
import smach
from stingray_missions_lib.fsm.missions_fsm import Mission, MissionsFSMFactory
from stingray_missions_lib.control.controller import AUVController
import actionlib
import stingray_movement_msgs.msg
from stingray_object_detection_msgs.msg import Object
from stingray_movement_msgs.msg import AlignValue


class RedFlareMission(Mission):
    def __init__(self):
        Mission.__init__(self, "RED_FLARE")
        self.pub_ = None

    def sub_callback(self, msg):
        value = AlignValue()
        if msg.is_exist:
            value.hasValue = True
            value.difference = 320.0 - msg.x_center
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
        steerer = AUVController()

        self.pub_ = rospy.Publisher("/sauvc/topic/align/flare", AlignValue, queue_size=10)

        rospy.loginfo("Diving...")
        steerer.dive(70)
        rospy.loginfo("Dived!")

        rospy.loginfo("Starting lag movement")
        lag_goal = steerer.lag(600000, 0.2)
        goal_handle = linear_client.send_goal(lag_goal, active_cb=None, feedback_cb=None, done_cb=None)

        has_gate_count = 0
        while has_gate_count < 10:
            msg = rospy.wait_for_message("/object_detector/red_flare", Object)
            if msg.is_exist:
                rospy.loginfo("Flare!")
                has_gate_count += 1
            else:
                rospy.loginfo("No flare!")
                has_gate_count = 0

        rospy.loginfo("Stopping lag movement...")
        steerer.stop()
        linear_client.cancel_all_goals()
        rospy.loginfo("Lag movement stopped")

        rospy.loginfo("Starting alignment")
        sub = rospy.Subscriber("/object_detector/red_flare", Object,
                               lambda msg: self.sub_callback(msg))
        align_goal = stingray_movement_msgs.msg.AlignGoal(topicName="/sauvc/topic/align/flare", delta=10.0)
        align_client.send_goal(align_goal)
        align_client.wait_for_result()
        sub.unregister()

        rospy.loginfo("Passing flare...")
        steerer.lag(4000, 0.4)
        steerer.march(4000, 0.4)
        steerer.lag(4000, -0.4)

        return self.outcome_ok


class GatesMission(Mission):
    def __init__(self):
        Mission.__init__(self, "GATES")
        self.pub_ = None

    def sub_callback(self, msg):
        value = AlignValue()
        if msg.is_exist:
            value.hasValue = True
            value.difference = 320.0 - msg.x_center
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
        steerer = AUVController()

        self.pub_ = rospy.Publisher("/sauvc/topic/align/gate", AlignValue, queue_size=10)

        rospy.loginfo("Diving...")
        steerer.dive(70)
        rospy.loginfo("Dived!")

        rospy.loginfo("Starting lag movement")
        lag_goal = steerer.lag(600000, 0.2)
        goal_handle = linear_client.send_goal(lag_goal, active_cb=None, feedback_cb=None, done_cb=None)

        has_gate_count = 0
        while has_gate_count < 2:
            msg = rospy.wait_for_message("/object_detector/gate", Object)
            if msg.is_exist:
                rospy.loginfo("Gates!")
                has_gate_count += 1
            else:
                rospy.loginfo("No gates!")
                has_gate_count = 0

        rospy.loginfo("Stopping lag movement...")
        steerer.stop()
        linear_client.cancel_all_goals()
        rospy.loginfo("Lag movement stopped")

        rospy.loginfo("Starting alignment")
        sub = rospy.Subscriber("/object_detector/gate", Object,
                               lambda msg: self.sub_callback(msg))
        align_goal = stingray_movement_msgs.msg.AlignGoal(topicName="/sauvc/topic/align/gate", delta=10.0)
        align_client.send_goal(align_goal)
        align_client.wait_for_result()
        sub.unregister()

        return self.outcome_ok


class SauvcMissions(MissionsFSMFactory):
    def __init__(self):
        MissionsFSMFactory.__init__(self)

    def create_fsm(self):
        sm = smach.StateMachine(outcomes=[self.outcome_ok, self.outcome_failed])
        with sm:
            # smach.StateMachine.add("RED_FLARE", RedFlareMission(), transitions={"RED_FLARE_OK": "GATES",
            #                                                                     "RED_FLARE_FAILED": self.outcome_failed})
            smach.StateMachine.add("GATES", GatesMission(), transitions={"GATES_OK": self.outcome_ok,
                                                                         "GATES_FAILED": self.outcome_failed})
        return sm
