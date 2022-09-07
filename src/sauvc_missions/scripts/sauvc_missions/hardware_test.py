from stingray_tfsm.auv_fsm import AUVStateMachine

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

test = AUVStateMachine('HARDWARE_TEST', STATES, TRANSITIONS, SCENE)


def next_mission(self, mission):
    self.add_mission(mission)
    if self.last_mission is None:
        self.add_mission_transitions([
            [self.machine.transition_start, self.machine.state_init, mission.name],
        ])
        print(f'added{[self.machine.transition_start, self.machine.state_init, mission.name]}')
        self.last_mission = mission.name
    else:
        self.add_mission_transitions([
            [f"FROM_{self.last_mission}_TO_{mission.name}",
             self.last_mission, mission.name],
        ])
        print('added ' + f"[FROM_{self.last_mission}_TO_{mission.name}", self.last_mission, mission.name, ']')
    self.last_mission = mission.name
    print(f'added {self.last_mission}')


def arrange_finish(self):
    if self.last_mission is None:
        self.add_mission_transitions([
            ['skip', self.machine.state_init, self.machine.state_end],
        ])
        print('no mission set')
    else:
        self.add_mission_transitions([
            [self.machine.transition_end, self.last_mission, self.machine.state_end],
        ])
        print(f'{[self.machine.transition_end, self.last_mission, self.machine.state_end]}')
    rospy.loginfo("Missions setup done")


def setup_missions(self):
    if self.test:
        from sauvc_missions.hardware_test import test
        test_mission = test
        self.next_mission(test_mission)

    if self.gate:
        from sauvc_missions.gate import GateMission
        gate_mission = GateMission(
            GateMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='left',
            lag='left',
        )
        self.next_mission(gate_mission)

    if self.yellow_flare:
        from sauvc_missions.yellow import FlareMission
        flare_mission = FlareMission(
            FlareMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='right',
            lag='right',
        )
        self.next_mission(flare_mission)

    if self.drums:
        from sauvc_missions.drums import DrumsMission
        drums_mission = DrumsMission(
            DrumsMission.__name__,
            self.front_camera,
            self.bottom_camera
        )
        self.next_mission(drums_mission)

    self.arrange_finish()

###

def setup_missions(self):
    if self.gate and not self.yellow_flare:
        from sauvc_missions.gate import GateMission

        self.gate_mission = GateMission(
            GateMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='left',
            lag='left',
        )
        self.add_mission(self.gate_mission)
        self.add_mission_transitions([
            [self.machine.transition_start, self.machine.state_init, self.gate_mission.name],
            [self.machine.transition_end, self.gate_mission.name, self.machine.state_end]
        ])

    if self.yellow_flare and not self.gate:
        from sauvc_missions.yellow import FlareMission

        self.flare_mission = FlareMission(
            FlareMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='left',
            lag='left',
        )
        self.add_mission(self.flare_mission)
        self.add_mission_transitions([
            [self.machine.transition_start, self.machine.state_init, self.flare_mission.name],
            [self.machine.transition_end, self.flare_mission.name, self.machine.state_end]
        ])
    if self.yellow_flare and self.gate:
        from sauvc_missions.gate import GateMission
        from sauvc_missions.yellow import FlareMission

        self.gate_mission = GateMission(
            GateMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='left',
            lag='left',
        )

        self.flare_mission = FlareMission(
            FlareMission.__name__,
            self.front_camera,
            self.bottom_camera,
            rotate='right',
            lag='left',
        )
        self.add_mission(self.gate_mission, [
            [self.machine.transition_start, self.machine.state_init, self.gate_mission.name]])
        self.add_mission(self.flare_mission, [
            ['gate_to_flare', self.gate_mission.name, self.flare_mission.name]
        ])
        self.add_mission_transitions([
            ['gate_to_flare', self.gate_mission.name, self.flare_mission.name],
            [self.machine.transition_end, self.flare_mission.name, self.machine.state_end],
        ])


    elif self.drums:
        self.drums_mission = DrumsMission("drums_mission",
                                          self.front_camera, self.bottom_camera)
        self.add_mission(self.drums_mission)
        self.add_mission_transitions([
            [self.machine.transition_start, self.machine.state_init, self.gate_mission.name],
            ['finish_gate', self.gate_mission.name, self.drums_mission.name],
            [self.machine.transition_end, self.drums_mission.name, self.machine.state_end],
        ])

    self.add_mission_transitions([
        ['skip', self.machine.state_init, self.machine.state_end],
    ])

    rospy.loginfo("Missions setup done")


