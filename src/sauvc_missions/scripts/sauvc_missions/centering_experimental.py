#! /usr/bin/env python3

from stingray_tfsm.auv_mission import AUVMission
from stingray_tfsm.auv_fsm import AUVStateMachine
from stingray_tfsm.core.pure_fsm import PureStateMachine
from stingray_tfsm.vision_events import ObjectDetectionEvent, ObjectOnRight, ObjectOnLeft


class CenteringMission(AUVMission):
    def __init__(self, camera: str, target: str, confirmation: int = 2, tolerance: int = 14):
        super().__init__()
        self.target = target
        self.confirmation = confirmation
        self.tolerance = tolerance
        self.camera = camera

        self.gate_detected = None
        self.gate_lefter = None
        self.gate_righter = None

    def setup_states(self):
        return ('condition_detected',
                'condition_lefter', 'condition_righter',
                'rotate_clock', 'rotate_anti',
                'condition_exhausted')

    def setup_transitions(self):
        return [
            [self.transition_start, [self.state_init, 'rotate_clock',
                                     'rotate_anti'], 'condition_detected'],

            ['condition_f', 'condition_detected', 'aborted'],
            ['condition_s', 'condition_detected', 'condition_lefter'],

            ['condition_f', 'condition_lefter', 'condition_righter'],
            ['condition_s', 'condition_lefter', 'rotate_anti'],

            ['condition_f', 'condition_righter', 'done'],
            ['condition_s', 'condition_righter', 'rotate_clock'],
        ]

    def setup_scene(self):
        return {
            self.state_init: {
                'time': 0.1
            },
            'condition_detected': {
                'condition': self.event_handler,
                'args': self.gate_detected
            },
            'condition_righter': {
                'condition': self.event_handler,
                'args': self.gate_righter
            },
            'condition_lefter': {
                'condition': self.event_handler,
                'args': self.gate_lefter
            },
            'rotate_anti': {
                'angle': -5
            },
            'rotate_clock': {
                'angle': 5
            }
        }

    def setup_events(self):
        self.gate_detected = ObjectDetectionEvent(
            self.camera, self.target, self.confirmation)
        self.gate_lefter = ObjectOnLeft(
            self.camera, self.target, self.confirmation, tolerance=self.TOLERANCE * 0.01)
        self.gate_righter = ObjectOnRight(
            self.camera, self.target, self.confirmation, tolerance=self.TOLERANCE * 0.01)

    def check_machine(self):
        if type(self.machine) is AUVStateMachine or \
                type(self.machine) is PureStateMachine:
            return 1
        else:
            raise TypeError("machine was not initialized")

    def set_state(self, state):
        if self.check_machine():
            self.machine.set_state(state)

    def run(self, *args, **kwargs):
        if self.check_machine():
            value = self.machine.run(*args, **kwargs)
            return value

    def verbose(self, verbose):
        if self.check_machine():
            self.machine.verbose(verbose)
