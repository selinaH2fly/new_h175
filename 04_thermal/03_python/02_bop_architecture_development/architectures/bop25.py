import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    bop Architecture 2.5
                    7                 8                  9                       13                    14
                    .------> HPDU -------> Inverter -----------.               .---->   Throttle1 -------------.
                    |                                          |               |                               |
    ----> evap --> splitter1                                  Mixer1 ----> Splitter2 ----> Intercooler -----> Mixer2 ----->
    1          2    |                                          |     10                11                  12          15
                    '--> LV DCDC --> HV DCDC - -> Compressor --'
                    3             4           5              6               
    """

    circ = ThermSim.Circuit()
    evap = ThermSim.Heatsink(1, 2, "evap")
    circ.add_comp(evap)
    splitter1 = ThermSim.ConnectorPassive1to2(2, 7, 3, "splitter1")
    circ.add_comp(splitter1)


    lvdcdc = ThermSim.Heatsource(3, 4, "lvdcdc")
    circ.add_comp(lvdcdc)
    hvdcdc = ThermSim.Heatsource(4, 5, "hvdcdc")
    circ.add_comp(hvdcdc)
    compressor = ThermSim.Heatsource(5, 6, "compressor")
    circ.add_comp(compressor)

    hpdu = ThermSim.Heatsource(7, 8, "hpdu")
    circ.add_comp(hpdu)
    inverter = ThermSim.Heatsource(8, 9, "inverter")
    circ.add_comp(inverter)



    mixer1 = ThermSim.ConnectorPassive2to1(9, 6, 10, "mixer1")
    circ.add_comp(mixer1)
    splitter2 = ThermSim.ConnectorPassive1to2(10, 11, 13, "splitter2")
    circ.add_comp(splitter2)
    intercooler = ThermSim.Heatsource(11, 12, "intercooler")
    circ.add_comp(intercooler)
    mixer2 = ThermSim.ConnectorPassive2to1(12, 14, 15, "mixer2")
    circ.add_comp(mixer2)

    throttle1 = ThermSim.Throttle(13, 14, "throttle1")
    circ.add_comp(throttle1)

    """
    Provide input on boundary conditions
    """
    for name in bc_dict:
        if "Vdot_in" == name:
            circ.add_bc("Vdot_1 = %f" %bc_dict["Vdot_in"])
        elif "p_in" == name:
            circ.add_bc("p_1 = %f" %bc_dict["p_in"])

    circ.add_bc("p_11 = %f" %bc_dict["p_end"])
    circ.add_bc("T_1 = %f" %bc_dict["T_in"])
    circ.add_bc("Qdot_hpdu = %f" %bc_dict["Qdot_hpdu"])
    circ.add_bc("Qdot_lvdcdc = %f" %bc_dict["Qddot_lvdcdc"])
    circ.add_bc("Qdot_hvdcdc = %f" %bc_dict["Qdot_hvdcdc"])
    circ.add_bc("Qdot_inverter = %f" %bc_dict["Qdot_inverter"])
    circ.add_bc("Qdot_intercooler = %f" %bc_dict["Qdot_intercooler"])
    circ.add_bc("Qdot_compressor = %f" %bc_dict["Qdot_compressor"])
    circ.add_bc("Qdot_evap = %f" %bc_dict["Qdot_evap"])

    #circ.add_bc("delta_p_throttle1 = - 0.0")
    circ.add_bc("Vdot_13 = 0.00001")

    circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_7 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_7 * 60)")
    circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_3 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_3 * 60)")
    circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_4 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_4 * 60)")
    circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_8 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_8 *  60)")
    circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_11 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_11 * 60)")
    circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_5 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_5 * 60)")
    circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * Vdot_1 ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * Vdot_1 * 60)")



    """
    Evaluate and generate output
    """

    result_vdot_dict = {'Vdot_7' : ['Vdot el. Comp. in [l/s]', []], 
                        'Vdot_3' : ['Vdot Intercooler in [l/s]', []],
    }
    result_temp_dict = {lvdcdc.T_in : ['LV DCDC T_in', []],
                        hvdcdc.T_in : ['HV DCDC T_in', []],
                        inverter.T_in : ['Inverter T_in', []],
                        hpdu.T_in : ['HPDU T_in', []],
                        compressor.T_in : ['Compressor T_in', []],
                        intercooler.T_in : ['Intercooler T_in', []],
                        mixer2.T_out : ['BoP T_out', []],
    }
    result_pr_dict = {mixer2.p_out : ['bop pressure drop in [bar]', []]
    }

    return circ, input_dict, result_dict