#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_tfsm.submachines.centering_angle import CenteringAngleSub
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
import rospy


class GateMission(SAUVCMission):
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
        self.centering_submission = CenteringAngleSub(
            "centering", front_camera, gate)
        super().__init__(name, front_camera, bottom_camera, gate,
                         red_flare, yellow_flare, mat, blue_bowl, red_bowl)

    def setup_states(self):
        
        return ('condition_gate',
                'rotate_clockwise', 'condition_centering',
                'condition_flare', 'move_lag_right',
                'move_march_0', 'condition_in_front', 'move_march_1') + self.machine.default_states

    def setup_transitions(self):
        return [
            [self.machine.transition_start, [self.machine.state_init,
                                             'rotate_clockwise', 'move_lag_right'], 'condition_gate'],

            ['condition_f', 'condition_flare', 'condition_gate'],
            ['condition_s', 'condition_flare', 'move_lag_right'],

            ['condition_f', 'condition_gate', 'rotate_clockwise'],
            ['condition_s', 'condition_gate', 'condition_centering'],

            ['condition_f', 'condition_centering', 'condition_gate'],
            ['condition_s', 'condition_centering', 'move_march_0'],

            ['next', 'move_march_0', 'condition_in_front'],

            ['condition_f', 'condition_in_front', 'condition_flare'],
            ['condition_s', 'condition_in_front', 'move_march_1'],
        ] + self.machine.default_transitions

    def setup_scene(self):
        return {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },
            'condition_gate': {
                'condition': self.gate_event_handler,
                'args': ()
            },
            'condition_in_front': {
                'condition': self.not_gates,
                'args': ()
            },
            'rotate_clockwise': {
                'angle': 5
            },
            'condition_centering': {
                'subFSM': True,
                'condition': self.centering_submission,
                'args': ()
            },
            'move_march_0': {
                'direction': 3,
                'velocity': 0.4,
                'duration': 1500
            },
            'move_march_1': {
                'direction': 3,
                'velocity': 0.41,
                'duration': 2000
            },
            'condition_flare': {
                'condition': self.flare_event_handler,
                'args': ()
            },
            'move_lag_right': {
                'direction': 1,
                'velocity': 0.5,
                'duration': 1000
            },
        }

    def setup_events(self):
        self.gate_detection_event = ObjectDetectionEvent(
            get_objects_topic(self.front_camera), self.gate, self.confirmation-1)
        self.flare_assession_event = ObjectIsCloseEvent(
            get_objects_topic(self.front_camera), self.red_flare, self.confirmation
        )
        self.gate_proximity_event = ObjectIsCloseEvent(
            get_objects_topic(self.front_camera), self.gate, self.confirmation
        )
        # self.gate_angle_event = ObjectOrtho(
        #     get_objects_topic(self.front_camera), self.gate, self.confirmation
        # )

    def gate_event_handler(self):
        self.gate_detection_event.start_listening()
        rospy.loginfo("DEBUG: start listnening gate detection")

        rospy.sleep(0.5)
        if self.gate_detection_event.is_triggered():
            rospy.loginfo("DEBUG: gate detected by event")
            self.gate_detection_event.stop_listening()
            return 1
        else:
            rospy.loginfo("DEBUG: no gate detected")
            self.gate_detection_event.stop_listening()
            return 0

    def flare_event_handler(self, *args, **kwargs):
        self.flare_assession_event.start_listening()
        rospy.sleep(0.5)
        if self.flare_assession_event.is_triggered():
            rospy.loginfo("DEBUG: flare is detected and is a threat")
            self.flare_assession_event.stop_listening()
            return 1
        else:
            rospy.loginfo("DEBUG: no risks of collision with red flare")
            self.flare_assession_event.stop_listening()
            return 0

    def not_gates(self):
        rospy.sleep(1)
        return not self.gate_event_handler()


if __name__ == '__main__':
    rospy.init_node("gate_centering_fsm")
    front_camera_topic = rospy.get_param('~front_camera_topic')
    bottom_camera_topic = rospy.get_param('~front_camera_topic')

    gate_mission = GateMission(front_camera_topic, bottom_camera_topic)
    gate_mission.run()
