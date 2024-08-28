import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim
"""
bop Architecture 2.1
                 7               8        9             10              11
                 .----> LV DCDC ---> HPDU ---> Inverter ---> Compressor --.
                 |                                                        |
----> evap --> splitter1                                               Mixer1 ---->
 1          2    |                                                        |     12
                 '------> Throttle1 ------> HV DCDC -----> Intercooler ---'
                 3                      4               5                  6
"""

circ = ThermSim.Circuit()
evap = ThermSim.Heatsource(1, 2, "evap")
circ.add_comp(evap)
splitter1 = ThermSim.ConnectorPassive1to2(2, 7, 3, "splitter1")
circ.add_comp(splitter1)
throttle1 = ThermSim.Throttle(3, 4, "throttle1")
circ.add_comp(throttle1)
hvdcdc = ThermSim.Heatsource(4, 5, "hvdcdc")
circ.add_comp(hvdcdc)
intercooler = ThermSim.Heatsource(3, 4, "intercooler")
circ.add_comp(intercooler)
mixer1 = ThermSim.ConnectorPassive2to1(11, 6, 12, "mixer1")
circ.add_comp(mixer1)
lvdcdc = ThermSim.Heatsource(7, 8, "lvdcdc")
circ.add_comp(lvdcdc)
hpdu = ThermSim.Heatsource(8, 9, "hpdu")
circ.add_comp(hpdu)
inverter = ThermSim.Heatsource(9, 10, "inverter")
circ.add_comp(inverter)
compressor = ThermSim.Heatsource(10, 11, "compressor")
circ.add_comp(compressor)


"""
Provide input on boundary conditions
"""
circ.add_bc("Vdot_1 = 0.1")
circ.add_bc("p_1 = 1.0")
circ.add_bc("T_6 = 273.15 + 70.0")

# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_hpdu = ")
circ.add_bc("delta_p_lvdcdc = ")
circ.add_bc("delta_p_hvdcdc = ")
circ.add_bc("delta_p_inverter = ")
circ.add_bc("delta_p_intercooler = ")
circ.add_bc("delta_p_compressor = ")
circ.add_bc("delta_p_evap = ")
circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * Vdot_1 + 1.6622 * 10 ** (-3) * 60 * Vdot_1)")

circ.add_bc("Qdot_hpdu = ")
circ.add_bc("Qdot_lvdcdc = ")
circ.add_bc("Qdot_hvdcdc = ")
circ.add_bc("Qdot_inverter = ")
circ.add_bc("Qdot_intercooler = ")
circ.add_bc("Qdot_compressor = ")
circ.add_bc("Qdot_evap = ")


"""
Evaluate and generate output
"""

circ.evaluate()