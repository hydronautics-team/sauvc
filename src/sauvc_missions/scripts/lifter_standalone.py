from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.auv_control import AUVControl
import rospy

class LifterStandalone(SAUVCMission):
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

        super().__init__(name, self.auv, '', '')

    def setup_states(self):
        return ['custom_lifter_open', 'custom_lifter_close']

    def setup_transitions(self):
        transitions = [
            [self.machine.transition_start, [self.machine.state_init], 'custom_lifter_open'],
        ]
        return transitions

    def lift(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lift": True,
            }
        )
    
    def lower(self):
        self.machine.auv.execute_lifter_goal(
            {
                "lower": True,
            }
        )

    def lifter_open(self):
        self.lower()
        self.lift()

    def setup_scene(self):
        scene = {
            self.machine.state_init: {
                'wait': 1
            },
            'custom_lifter_open': {
                'custom': self.lifter_open,
                'args': ()
            },
        }
        return scene

    def setup_events(self):
        pass


if __name__ == "__main__":
    rospy.init_node('LIFT')
    mission = LifterStandalone('lift', AUVControl())
    mission.run()


