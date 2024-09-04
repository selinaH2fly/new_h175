import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim
"""
bop Architecture 2.1

                        12                   13                
                     .---------> Inverter ----------------.   
                     |                                    |
                     |                                    |
----> evap --> splitter1 --> LV DCDC --> Compressor --> Mixer1 ---->
 1          2        |    9           10             11   |        14
                     |                                    |       
                     |--> Throttle1 ------> Intercooler --|
                     |  6              7                8 |
                     |                                    |
                     '---> HPDU --------> HV DCDC --------'
                     3              4                 5
"""

circ = ThermSim.Circuit()
evap = ThermSim.Heatsink(1, 2, "evap")
circ.add_comp(evap)
splitter1 = ThermSim.ConnectorPassive1to4(2, 3, 6, 9, 12, "splitter1")
circ.add_comp(splitter1)

hpdu = ThermSim.Heatsource(3, 4, "hpdu")
circ.add_comp(hpdu)
hvdcdc = ThermSim.Heatsource(4, 5, "hvdcdc")
circ.add_comp(hvdcdc)

throttle1 = ThermSim.Throttle(6, 7, "throttle1")
circ.add_comp(throttle1)
intercooler = ThermSim.Heatsource(7, 8, "intercooler")
circ.add_comp(intercooler)

lvdcdc = ThermSim.Heatsource(9, 10, "lvdcdc")
circ.add_comp(lvdcdc)
compressor = ThermSim.Heatsource(10, 11, "compressor")
circ.add_comp(compressor)

inverter = ThermSim.Heatsource(12, 13, "inverter")
circ.add_comp(inverter)

mixer1 = ThermSim.ConnectorPassive4to1(5, 8, 11, 13, 14, "mixer1")
circ.add_comp(mixer1)

"""
Provide input on boundary conditions
"""
circ.add_bc("Vdot_1 = 0")
circ.add_bc("delta_p_throttle1 = - 0.0")
circ.add_bc("p_1 = 1.0")

circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_3 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_3 * 60)")
circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_9 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_9 * 60)")
circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_4 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_4 * 60)")
circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_12 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_12 *  60)")
circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_7 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_7 * 60)")
circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_10 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_10 * 60)")
circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * Vdot_1 ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * Vdot_1 * 60)")

critical_operation = True
if critical_operation is False:
    circ.add_bc("T_1 = 273.15 + 50.0")
    circ.add_bc("Qdot_hpdu = 500")
    circ.add_bc("Qdot_lvdcdc = 150")
    circ.add_bc("Qdot_hvdcdc = 800")
    circ.add_bc("Qdot_inverter = 625")
    circ.add_bc("Qdot_intercooler = 13000")
    circ.add_bc("Qdot_compressor = 500")
    circ.add_bc("Qdot_evap = - 13500")
elif critical_operation is True:
    circ.add_bc("T_1 = 273.15 + 60.0")
    circ.add_bc("Qdot_hpdu = 1000")
    circ.add_bc("Qdot_lvdcdc = 300")
    circ.add_bc("Qdot_hvdcdc = 1600")
    circ.add_bc("Qdot_inverter = 1250")
    circ.add_bc("Qdot_intercooler = 19000")
    circ.add_bc("Qdot_compressor = 1000")
    circ.add_bc("Qdot_evap = - 13500")

"""
Evaluate and generate output
"""

result_vdot_dict = {'Vdot_3' : ['Vdot HPDU in [l/s]', []], 
                    'Vdot_6' : ['Vdot Intercooler in [l/s]', []],
                    'Vdot_9' : ['Vdot LV DCDC in [l/s]', []], 
                    'Vdot_12' : ['Vdot Inverter in [l/s]', []],
}
result_temp_dict = {lvdcdc.T_in : ['LV DCDC T_in', []],
                    hvdcdc.T_in : ['HV DCDC T_in', []],
                    inverter.T_in : ['Inverter T_in', []],
                    hpdu.T_in : ['HPDU T_in', []],
                    compressor.T_in : ['Compressor T_in', []],
                    intercooler.T_in : ['Intercooler T_in', []],
                    intercooler.T_out : ['Intercooler T_out', []],
                    mixer1.T_out : ['BoP T_out', []],
}
result_pr_dict = {mixer1.p_out : ['bop pressure drop in [bar]', []]
}
#10/60, 12/60, 15/60,
vdot1 = [17/60, 20/60, 22/60, 25/60, 27/60, 30/60]
circ.analyse_vdot1(vdot1, result_vdot_dict, result_temp_dict, result_pr_dict)