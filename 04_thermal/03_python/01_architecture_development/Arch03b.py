import sys
import os

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim


"""
Provide input on architecture

                  .-----> throttle1 --> bop1 -------.
                  | 3                4            5 |
                  |                                 v
.-> pump1 --> splitter1 --> mixer1 --> stack1 --> mixer2 --> splitter2 --.
|          2             6    ^     7          8          9      |       |
|                             | 11                            10 |       |
|                             '------------- pump2 <-------------'       |
|                                                                        |
| 1                                                                   12 |
'------------------------------ radiator1 <------------------------------'
"""

circ = ThermSim.Circuit()
pump1 = ThermSim.Pump(1, 2, "pump1")
circ.add_comp(pump1)
splitter1 = ThermSim.ConnectorPassive1to2(2, 3, 6, "splitter1")
circ.add_comp(splitter1)
throttle1 = ThermSim.Throttle(3, 4, "throttle1")
circ.add_comp(throttle1)
bop1 = ThermSim.Heatsource(4, 5, "bop1")
circ.add_comp(bop1)
mixer2 = ThermSim.ConnectorPassive2to1(5, 8, 9, "mixer2")
circ.add_comp(mixer2)
mixer1 = ThermSim.ConnectorPassive2to1(6, 11, 7, "mixer1")
circ.add_comp(mixer1)
stack1 = ThermSim.Heatsource(7, 8, "stack1")
circ.add_comp(stack1)
splitter2 = ThermSim.ConnectorPassive1to2(9, 12, 10, "splitter2")
circ.add_comp(splitter2)
pump2 = ThermSim.Pump(10, 11, "pump2")
circ.add_comp(pump2)
radiator1 = ThermSim.Heatsink(12, 1, "radiator1")
circ.add_comp(radiator1)


"""
Provide input on boundary conditions
"""

circ.add_bc("p_1 = 1.0")
# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023) * 60.0 * Vdot_4 - (0.0001 + 0.0004) * 60.0 ** 2 * Vdot_4 **2")
circ.add_bc("delta_p_stack1 = - (5.6629  * 10 ** (-6) * 60 ** 2 * Vdot_7 ** 2 + 6.3347 * 10 ** (-4) * 60 * Vdot_7)")
circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * Vdot_1 + 1.6622 * 10 ** (-3) * 60 * Vdot_1)")

circ.add_bc("T_7 = 273.15 + 70.0")
circ.add_bc("T_8 = 273.15 + 85.0")
circ.add_bc("T_4 = 273.15 + 50.0")

circ.add_bc("Qdot_bop1 = 10000.0")
circ.add_bc("Qdot_stack1 = 180000.0")

circ.add_bc("Vdot_4 = 0.1")


"""
Evaluate and generate output
"""

circ.evaluate()