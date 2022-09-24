from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_control import AUVControl
import rospy

class DropperStandalone(SAUVCMission):
    def __init__(self,
                 name: str,
                 auv: AUVControl = None,
                 *args,
                 **kwargs
                 ):

        if auv is None:
            self.auv = AUVControl(verbose=False)
        else:
            self.auv = auv

        super().__init__(name, '', '', auv=self.auv)

    def setup_states(self):
        return 'custom_dropper_open'

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, [self.machine.state_init], 'custom_dropper_close'],
        ]
        return transitions

    def lift(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
            }
        )

    def dropper_open(self):
        self.machine.auv.execute_dropper_goal(velocity=50)
        rospy.sleep(3)
        self.machine.auv.execute_dropper_goal(velocity=100)

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'wait': 1
            },
            'custom_dropper_open': {
                'custom': self.dropper_open,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass


if __name__ == "__main__":
    rospy.init_node('D_R_O_P')
    mission = DropperStandalone('D R O P', AUVControl())
    mission.run()


