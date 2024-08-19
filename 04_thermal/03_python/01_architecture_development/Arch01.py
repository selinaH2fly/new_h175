import sys
import os

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim


"""
Provide input on architecture

    .----> throttle1 --> bop1 ------.
    | 2               3           4 |
    |                               v
splitter1 --> tcv1 --> stack1 --> mixer1 --> pump1 --> splitter2 --.
    ^      5   ^    6          7          9        10      |       |
    |          |                                           |       |
    |          '-------------------------------------------'       |
    |                               8                              |
    | 1                                                         11 |
    '------------------------- radiator1 <-------------------------'
"""

circ = ThermSim.Circuit()
splitter1 = ThermSim.ConnectorPassive1to2(1, 2, 5, "splitter1")
circ.add_comp(splitter1)
throttle1 = ThermSim.Throttle(2, 3, "throttle1")
circ.add_comp(throttle1)
bop1 = ThermSim.Heatsource(3, 4, "bop1")
circ.add_comp(bop1)
mixer1 = ThermSim.ConnectorPassive2to1(4, 7, 9, "mixer1")
circ.add_comp(mixer1)
tcv1 = ThermSim.ConnectorActive2to1(5, 8, 6, "tcv1")
circ.add_comp(tcv1)
stack1 = ThermSim.Heatsource(6, 7, "stack1")
circ.add_comp(stack1)
pump1 = ThermSim.Pump(9, 10, "pump1")
circ.add_comp(pump1)
splitter2 = ThermSim.ConnectorPassive1to2(10, 11, 8, "splitter2")
circ.add_comp(splitter2)
radiator1 = ThermSim.Heatsink(11, 1, "radiator1")
circ.add_comp(radiator1)


"""
Provide input on boundary conditions
"""

circ.add_bc("p_9 = 1.0")
# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023) * 60.0 * Vdot_3 - (0.0001 + 0.0004) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_stack1 = - 0.6")
circ.add_bc("delta_p_radiator1 = - 0.4")

circ.add_bc("delta_p_1_tcv1 = 0.0")

circ.add_bc("T_6 = 273.15 + 70.0")
circ.add_bc("T_7 = 273.15 + 85.0")
circ.add_bc("T_3 = 273.15 + 50.0")

circ.add_bc("Qdot_bop1 = 10000.0")
circ.add_bc("Qdot_stack1 = 180000.0")

circ.add_bc("Vdot_3 = 0.1")


"""
Evaluate and generate output
"""

circ.evaluate()