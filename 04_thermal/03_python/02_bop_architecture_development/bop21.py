import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim
"""
bop Architecture 2.1
                 6             7        8            9           10              11
                 .--> LV DCDC --> HPDU --> Inverter --> HV DCDC --> Compressor --.
                 |                                                               |
----> evap --> splitter1                                                       Mixer1 ---->
 1          2    |                                                               |     12
                 '------> Throttle1  -----> Intercooler -------------------------'
                 3                      4                            5                 
"""

circ = ThermSim.Circuit()
evap = ThermSim.Heatsink(1, 2, "evap")
circ.add_comp(evap)
splitter1 = ThermSim.ConnectorPassive1to2(2, 6, 3, "splitter1")
circ.add_comp(splitter1)
throttle1 = ThermSim.Throttle(3, 4, "throttle1")
circ.add_comp(throttle1)
intercooler = ThermSim.Heatsource(4, 5, "intercooler")
circ.add_comp(intercooler)
mixer1 = ThermSim.ConnectorPassive2to1(11, 5, 12, "mixer1")
circ.add_comp(mixer1)
lvdcdc = ThermSim.Heatsource(6, 7, "lvdcdc")
circ.add_comp(lvdcdc)
hpdu = ThermSim.Heatsource(7, 8, "hpdu")
circ.add_comp(hpdu)
inverter = ThermSim.Heatsource(8, 9, "inverter")
circ.add_comp(inverter)
hvdcdc = ThermSim.Heatsource(9, 10, "hvdcdc")
circ.add_comp(hvdcdc)
compressor = ThermSim.Heatsource(10, 11, "compressor")
circ.add_comp(compressor)


"""
Provide input on boundary conditions
"""
circ.add_bc("Vdot_1 = 0.2")
circ.add_bc("delta_p_throttle1 = - 0.0")
circ.add_bc("p_1 = 1.0")
circ.add_bc("T_1 = 273.15 + 50.0")

# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_7 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_7 * 60)")
circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_6 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_6 * 60)")
circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_9 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_9 * 60)")
circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_8 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_8 *  60)")
circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_4 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_4 * 60)")
circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_10 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_10 * 60)")
circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * Vdot_1 ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * Vdot_1 * 60)")

circ.add_bc("Qdot_hpdu = 500")
circ.add_bc("Qdot_lvdcdc = 150")
circ.add_bc("Qdot_hvdcdc = 800")
circ.add_bc("Qdot_inverter = 625")
circ.add_bc("Qdot_intercooler = 13000")
circ.add_bc("Qdot_compressor = 500")
circ.add_bc("Qdot_evap = - 13500")


"""
Evaluate and generate output
"""

circ.evaluate()