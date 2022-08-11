import rospy
from stingray_tfsm.core.pure_fsm import PureStateMachine

STATES = ('init', 'done', 'aborted')
TRANSITIONS = [['finish', 'aborted', 'done']]
master_fsm = PureStateMachine(STATES, [])
NODE_NAME = "control_fsm"


def no_mission_set(*args, **kwargs):
    rospy.loginfo("No mission")


def setup(*args, **kwargs):
    """here arguments from launches/ros should be retrieved and applied to where they belong"""
    # TODO machine which just checks that all required topics and nodes are online
    pass


if __name__ == '__main__':
    rospy.init_node(NODE_NAME)

    gate_vision = rospy.get_param('/' + NODE_NAME + "/gate_vision")
    gate_brute = rospy.get_param('/' + NODE_NAME + "/gate_brute", False)
    gate_centering = rospy.get_param('/' + NODE_NAME + "/gate_centering")
    drums = rospy.get_param("~drums")
    verbose = rospy.get_param('/' + NODE_NAME + "/verbose", True)
    centering_test = rospy.get_param('/' + NODE_NAME + "/test")
    simulation = rospy.get_param('/' + NODE_NAME + "/simulation")

    if centering_test:
        from sauvc_missions.uart_test_mission import test
        master_fsm.add_state('centering', on_enter=test.run)
        master_fsm.add_transitions([
            ['start', 'init', 'centering'],
            ['finish', 'centering', 'done'],
        ])

    elif gate_vision:
        from sauvc_missions.gate_vision import gate_mission
        gate_mission.set_verbose(verbose)
        master_fsm.add_state(('gate',), on_enter=gate_mission.run)
        master_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish', 'gate', 'done'],
        ])

    elif gate_brute:
        from sauvc_missions.gate_bruteforce import gate_mission
        gate_mission.set_verbose(verbose)
        master_fsm.add_state(('gate',), on_enter=gate_mission.run)
        master_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish', 'gate', 'done'],
        ])
    elif gate_centering:
        from sauvc_missions.gate_centering import gate_mission
        gate_mission.set_verbose(verbose)
        master_fsm.add_state(('gate',), on_enter=gate_mission.run)
        master_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish', 'gate', 'done'],
        ])
    elif drums:
        from sauvc_missions.gate_centering import gate_mission
        from sauvc_missions.drums import drums_mission
        gate_mission.set_verbose(verbose)
        master_fsm.add_state(('gate'), on_enter=gate_mission.run)
        drums_mission.set_verbose(verbose)
        master_fsm.add_state(('drums'), on_enter=drums_mission.run)
        master_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish_gate', 'gate', 'drums'],
            ['finish', 'drums', 'done'],
        ])

    master_fsm.add_transitions((
        {'trigger': 'skip',
         'source': 'init',
         'dest': 'done',
         'prepare': no_mission_set},
    ))
    master_fsm.run()
