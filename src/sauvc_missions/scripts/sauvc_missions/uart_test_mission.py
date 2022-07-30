#! /usr/bin/env python3


from stingray_tfsm.ros_transitions import AUVStateMachine

STATES = ('init', 'move_first',
          'rotate_clock', 'move_second',
          'done', 'aborted')

TRANSITIONS = [
    ['start', 'init', 'move_first'],

    ['step_1', 'move_first', 'rotate_clock'],

    ['step_2', 'rotate_clock', 'move_second'],

    ['end', '*', 'done']
]

SCENE = {
    'init': {
        'time': 5
    },
    'move_first': {
        'direction': 3,
        'velocity': 0.41,
        'duration': 1500
    },
    'move_second': {
        'direction': 1,
        'velocity': 0.39,
        'duration': 1500
    },
    'rotate_clock': {
        'angle': 10
    },
    'done': {},
    'aborted': {}
}

test = AUVStateMachine(STATES, TRANSITIONS, SCENE)

