import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim


"""
Provide input on architecture

    .----> throttle1 --> bop1 ------.
    | 2               3           4 |
    |                               v
splitter1 --> mixer2 --> stack1 --> mixer1 --> pump1 --> tcv1 --.
    ^      5    ^     6          7          9        10   |     |
    |           |                                         |     |
    |           '-----------------------------------------'     |
    |                               8                           |
    | 1                                                      11 |
    '------------------------ radiator1 <-----------------------'
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
mixer2 = ThermSim.ConnectorPassive2to1(5, 8, 6, "mixer2")
circ.add_comp(mixer2)
stack1 = ThermSim.Heatsource(6, 7, "stack1")
circ.add_comp(stack1)
pump1 = ThermSim.Pump(9, 10, "pump1")
circ.add_comp(pump1)
tcv1 = ThermSim.ConnectorActive1to2(10, 11, 8, "tcv1")
circ.add_comp(tcv1)
radiator1 = ThermSim.Heatsink(11, 1, "radiator1")
circ.add_comp(radiator1)


"""
Provide input on boundary conditions
"""

circ.add_bc("p_9 = 1.0")
circ.add_bc("delta_p_bop1 = - (0.000425124 * 60 ** 2 * Vdot_3 ** 2 + 0.003355931 * Vdot_3)")
circ.add_bc("delta_p_stack1 = - (5.6629  * 10 ** (-6) * 60 ** 2 * Vdot_7 ** 2 + 6.3347 * 10 ** (-4) * 60 * Vdot_7)")
circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * Vdot_1 + 1.6622 * 10 ** (-3) * 60 * Vdot_1)")

circ.add_bc("delta_p_1_tcv1 = 0.0")

circ.add_bc("T_6 = 273.15 + 70.0")
circ.add_bc("T_7 = 273.15 + 85.0")
circ.add_bc("T_3 = 273.15 + 50.0")

circ.add_bc("Qdot_bop1 = 10650")
circ.add_bc("Qdot_stack1 = 158000")
# circ.add_bc("Qdot_stack1 = %.1f"%(np.interp(600, [20, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600], [2.6, 9.7, 20.8, 33.1, 46.7, 60.5, 75.0, 90.2, 106.4, 123.6, 142.5, 162.0, 178.5], left=np.nan, right=np.nan) * 1000.0))

circ.add_bc("Vdot_3 = 0.1")


"""
Evaluate and generate output
"""

result_dict = {pump1.Vdot_in : ['flow over pump1 in [l/S]', []],
               pump1.delta_p : ['pump pressure difference [bar]', []],
               radiator1.Vdot_in : ['flow over radiator in [l/S]', []],
               mixer2.nmix_2 : ['Percentage recirculated', []],
               radiator1.T_in : ['System Output Temperature [K]', []]
}

circ.eveluate_big_arch(result_dict)
