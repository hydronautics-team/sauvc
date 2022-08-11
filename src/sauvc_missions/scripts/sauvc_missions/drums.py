#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.vision_events import ObjectDetectionEvent
import rospy


class DrumsMission(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 gate="gate",
                 red_flare="red_flare",
                 yellow_flare="yellow_flare",
                 mat="mat",
                 blue_bowl="blue_bowl",
                 red_bowl="red_bowl"):
        super().__init__(name, front_camera, bottom_camera, gate,
                         red_flare, yellow_flare, mat, blue_bowl, red_bowl)

    def setup_states(self):
        return ('condition_drums', 'custom_setup',
                'rotate_clockwise', 'rotate_anticlockwise', 'move_march') + self.machine.default_states

    def setup_transitions(self):
        return [     # Vision exhaustion loop
            [self.machine.transition_start, [self.machine.state_init, 'rotate_clockwise',
                                     'move_march'], 'condition_drums'],
            ['condition_f', 'condition_drums', 'rotate_clockwise'],
            ['condition_s', 'condition_drums', 'move_march'],
        ]  + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },
            'condition_drums': {
                'condition': self.drums_event_handler,
                'args': None
            },
            'rotate_clockwise': {
                'angle': 10
            },
            'rotate_anticlockwise': {
                'angle': -10
            },
            'move_march': {
                'direction': 3,
                'velocity': 0.4,
                'duration': 1000
            },
            'done': {},
            'aborted': {}
        }

    def setup_events(self):
        self.drums_detection_event = ObjectDetectionEvent(
            self.front_camera, self.mat, self.confirmation)

    def drums_event_handler(self):
        self.drums_detection_event.start_listening()
        rospy.sleep(2)
        if self.drums_detection_event.is_triggered():
            rospy.loginfo("DEBUG: drums detected by event")
            self.EXHAUSTION = 0
            self.drums_detection_event.stop_listening()
            return 1
        else:
            self.EXHAUSTION += 1
            rospy.loginfo("DEBUG: no drums detected")
            self.drums_detection_event.stop_listening()
            if self.EXHAUSTION >= self.exhaust_max:
                rospy.loginfo("it's time to stop, but i'll implement it later")
            return 0


if __name__ == '__main__':
    rospy.init_node("drums_centering_fsm")
    front_camera_topic = rospy.get_param('~front_camera_topic')
    bottom_camera_topic = rospy.get_param('~front_camera_topic')

    drums_mission = DrumsMission(front_camera_topic, bottom_camera_topic)
    drums_mission.run()
