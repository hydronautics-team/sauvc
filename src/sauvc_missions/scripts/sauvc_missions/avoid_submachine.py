#! /usr/bin/env python3

from sauvc_missions.sauvc_mission import SAUVCMission
from stingray_object_detection.utils import get_objects_topic
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectIsCloseEvent
import rospy


class AvoidSub(SAUVCMission):
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 avoid: list,
                 lag='left'):
        self.avoid = avoid
        self.lag = lag
        self.avoid_states = tuple(f'condition_avoid_{i}' for i in self.avoid)
        if not self.avoid_states:
            raise TypeError('empty avoidance list given')
        super().__init__(name, front_camera, bottom_camera)

    def setup_events(self):
        self.avoid_assessions = [
                ObjectIsCloseEvent(get_objects_topic(self.front_camera), i, self.confirmation)
                for i in self.avoid
        ]

    def avoid_event_handler(self, event, *args, **kwargs):
        event.start_listening()
        rospy.sleep(0.5)
        if event.is_triggered():
            rospy.loginfo("DEBUG: Threat detected")
            event.stop_listening()
            return 1
        else:
            rospy.loginfo("DEBUG: No risks of collision with one of threatening objects")
            event.stop_listening()
            return 0

    def setup_states(self):
        states = ('move_lag', ) + self.machine.default_states + self.avoid_states
        return states

    def setup_transitions(self):
        t1 = [
            ['condition_s', self.avoid_states[i], 'move_lag'] for i in range(1, len(self.avoid))
        ] if len(self.avoid) > 1 else []

        t2 = [
            ['condition_f', self.avoid_states[i - 1], self.avoid_states[i]] for i in range(1, len(self.avoid)-1)
        ] if len(self.avoid) > 1 else []
        t3 = [
            ['condition_f', self.avoid_states[-1], self.machine.state_end]
        ] if len(self.avoid) > 1 else []
        t1 = t1 + t2 + t3
        transitions = t1 + [
                   [self.machine.transition_start, [self.machine.state_init,
                                                    'move_lag'], self.avoid_states[0]],

                   ['condition_f', self.avoid_states[0], self.avoid_states[1]] if len(self.avoid) > 1 else
                   ['condition_f', self.avoid_states[0], self.machine.state_end],
                   ['condition_s', self.avoid_states[0], 'move_lag'],

               ] + self.machine.default_transitions
        return transitions

    def setup_scene(self):
        assession_scene = dict()
        for i in range(len(self.avoid)):
            assession_scene.update({
                f'{self.avoid_states[i]}': {
                    'condition': self.avoid_event_handler,
                    'args': (self.avoid_assessions[i],)
                },
            })
        scene = {
            self.machine.state_init: {
                'preps': self.enable_object_detection,
                "args": (self.front_camera, True),
            },
            'move_lag': {
                'direction': 1 if self.lag_dir == 'left' else 2,
                'velocity': 0.5,
                'duration': 1000
            },
        }
        scene.update(assession_scene)
        return scene
