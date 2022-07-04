import rospy
from stingray_tfsm.pure_transitions import FSM_Simple

STATES = ('init', 'done', 'aborted')
TRANSITIONS = [['finish', 'aborted', 'done']]
control_fsm = FSM_Simple(STATES, [])
NODE_NAME = "control_fsm"


def no_mission_set(*args, **kwargs):
    rospy.loginfo("No mission")


if __name__ == '__main__':
    rospy.init_node(NODE_NAME)

    gate_vision = rospy.get_param('/' + NODE_NAME + "/gate_vision")
    gate_brute = rospy.get_param('/' + NODE_NAME + "/gate_brute")

    if gate_vision:
        from sauvc_missions.gate_vision import gate_mission
        control_fsm.add_state(('gate',), on_enter=gate_mission.run)
        control_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish', 'gate', 'done'],
        ])

    elif gate_brute:
        from sauvc_missions.gate_bruteforce import gate_mission
        control_fsm.add_state(('gate',), on_enter=gate_mission.run)
        control_fsm.add_transitions([
            ['start', 'init', 'gate'],
            ['finish', 'gate', 'done'],
        ])

    control_fsm.add_transitions((
        {'trigger': 'skip',
         'source': 'init',
         'dest': 'done',
         'prepare': no_mission_set},
    ))
    control_fsm.run()
