import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim
"""
bop Architecture 2.2
            
                
                                                                                       8                9           
----> evap --> LV DCDC --> HPDU --> Inverter --> HV DCDC --> Compressor --> splitter1 -->  Intercooler --> Mixer1 ---->
 1          2           3         4            5           6              7     |                            |     12
                                                                                '------> Throttle1  ---------'
                                                                                10                          11
"""

circ = ThermSim.Circuit()
evap = ThermSim.Heatsink(1, 2, "evap")
circ.add_comp(evap)

lvdcdc = ThermSim.Heatsource(2, 3, "lvdcdc")
circ.add_comp(lvdcdc)
hpdu = ThermSim.Heatsource(3, 4, "hpdu")
circ.add_comp(hpdu)
inverter = ThermSim.Heatsource(4, 5, "inverter")
circ.add_comp(inverter)
hvdcdc = ThermSim.Heatsource(5, 6, "hvdcdc")
circ.add_comp(hvdcdc)
compressor = ThermSim.Heatsource(6, 7, "compressor")
circ.add_comp(compressor)

splitter1 = ThermSim.ConnectorPassive1to2(7, 8, 10, "splitter1")
circ.add_comp(splitter1)
intercooler = ThermSim.Heatsource(8, 9, "intercooler")
circ.add_comp(intercooler)
mixer1 = ThermSim.ConnectorPassive2to1(9, 11, 12, "mixer1")
circ.add_comp(mixer1)

throttle1 = ThermSim.Throttle(10, 11, "throttle1")
circ.add_comp(throttle1)

"""
Provide input on boundary conditions
"""
circ.add_bc("Vdot_1 = 0")
circ.add_bc("Vdot_10 = 0.00001")
circ.add_bc("p_1 = 1.0")
circ.add_bc("T_1 = 273.15 + 50.0")

circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_3 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_3 * 60)")
circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_2 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_2 * 60)")
circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_5 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_5 * 60)")
circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_4 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_4 *  60)")
circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_8 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_8 * 60)")
circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_6 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_6 * 60)")
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

result_vdot_dict = {'Vdot_10' : ['Vdot Throttle in [l/s]', []], 
                    'Vdot_8' : ['Vdot Intercooler in [l/s]', []],
}
result_temp_dict = {lvdcdc.T_in : ['LV DCDC T_in', []],
                    hvdcdc.T_in : ['HV DCDC T_in', []],
                    inverter.T_in : ['Inverter T_in', []],
                    hpdu.T_in : ['HPDU T_in', []],
                    compressor.T_in : ['Compressor T_in', []],
                    intercooler.T_in : ['Intercooler T_in', []],
                    mixer1.T_out : ['BoP T_out', []],
}
result_pr_dict = {mixer1.p_out : ['bop pressure drop in [bar]', []]
}

vdot1 = [3/60, 4/60, 5/60, 6/60, 7/60, 8/60, 10/60]
circ.analyse_vdot1(vdot1, result_vdot_dict, result_temp_dict, result_pr_dict)