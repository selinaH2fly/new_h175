import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim


"""
Provide input on architecture

                  .--------------------------> bop1 ----------------------------.
                  | 3                                                         4 |
                  |                                                             v
.-> pump1 --> splitter1 --> tcv1 --> mixer1 --> pump2 --> stack1 --> tcv2 --> mixer2 --.
|          2             5   |    6    ^     8         9         10   |   12    ^      |
|                            |         |                              |         |      |
|                            |         '------------------------------'         |      |
|                            |                        11                        |      |
|                            |                                                  |      |
|                            '--------------------------------------------------'      |
|                                                     7                                |
| 1                                                                                 13 |
'------------------------------------- radiator1 <-------------------------------------'
"""

circ = ThermSim.Circuit()
pump1 = ThermSim.Pump(1, 2, "pump1")
circ.add_comp(pump1)
splitter1 = ThermSim.ConnectorPassive1to2(2, 3, 5, "splitter1")
circ.add_comp(splitter1)
bop1 = ThermSim.Heatsource(3, 4, "bop1")
circ.add_comp(bop1)
tcv1 = ThermSim.ConnectorActive1to2(5, 6, 7, "tcv1")
circ.add_comp(tcv1)
mixer1 = ThermSim.ConnectorPassive2to1(6, 11, 8, "mixer1")
circ.add_comp(mixer1)
pump2 = ThermSim.Pump(8, 9, "pump2")
circ.add_comp(pump2)
stack1 = ThermSim.Heatsource(9, 10, "stack1")
circ.add_comp(stack1)
tcv2 = ThermSim.ConnectorActive1to2(10, 12, 11, "tcv2")
circ.add_comp(tcv2)
mixer2 = ThermSim.ConnectorPassive3to1(4, 12, 7, 13, "mixer2")
circ.add_comp(mixer2)
radiator1 = ThermSim.Heatsink(13, 1, "radiator1")
circ.add_comp(radiator1)


"""
Provide input on boundary conditions
"""

circ.add_bc("p_1 = 1.0")
# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023) * 60.0 * Vdot_3 - (0.0001 + 0.0004) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_stack1 = - (5.6629  * 10 ** (-6) * 60 ** 2 * Vdot_9 ** 2 + 6.3347 * 10 ** (-4) * 60 * Vdot_9)")
circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * Vdot_1 + 1.6622 * 10 ** (-3) * 60 * Vdot_1)")
circ.add_bc("delta_p_1_tcv2 = - 0.0")   #CAUTION: Weird behaviour of architecture
circ.add_bc("delta_p_2_tcv2 = - 0.0")   #CAUTION: Weird behaviour of architecture

circ.add_bc("T_9 = 273.15 + 70.0")
circ.add_bc("T_10 = 273.15 + 85.0")
circ.add_bc("T_3 = 273.15 + 50.0")

circ.add_bc("Qdot_bop1 = 10000.0")
circ.add_bc("Qdot_stack1 = %.1f"%(np.interp(600, [20, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600], [2.6, 9.7, 20.8, 33.1, 46.7, 60.5, 75.0, 90.2, 106.4, 123.6, 142.5, 162.0, 178.5], left=np.nan, right=np.nan) * 1000.0))

circ.add_bc("Vdot_3 = 0.1")
circ.add_bc("Vdot_13 = 1.15")            # alternative: Vdot_7  #CAUTION: Weird behaviour of architecture


"""
Evaluate and generate output
"""

circ.evaluate()