import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    bop Architecture 2.3
                    8                9                  10                11
                    .---> HPDU ----------> Inverter -------> Compressor -----.
                    |                                                        |
    ----> evap --> splitter1                                               Mixer1 ---->
    1          2    |                                                        |     12
                    '--> Throttle1 --> LV DCDC --> HV DCDC --> Intercooler --'
                    3               4           5           6               7
    """

    circ = ThermSim.Circuit()
    evap = ThermSim.Heatsink(1, 2, "evap")
    circ.add_comp(evap)
    splitter1 = ThermSim.ConnectorPassive1to2(2, 8, 3, "splitter1")
    circ.add_comp(splitter1)
    throttle1 = ThermSim.Throttle(3, 4, "throttle1")
    circ.add_comp(throttle1)
    lvdcdc = ThermSim.Heatsource(4, 5, "lvdcdc")
    circ.add_comp(lvdcdc)
    hvdcdc = ThermSim.Heatsource(5, 6, "hvdcdc")
    circ.add_comp(hvdcdc)
    intercooler = ThermSim.Heatsource(6, 7, "intercooler")
    circ.add_comp(intercooler)
    mixer1 = ThermSim.ConnectorPassive2to1(11, 7, 12, "mixer1")
    circ.add_comp(mixer1)
    hpdu = ThermSim.Heatsource(8, 9, "hpdu")
    circ.add_comp(hpdu)
    inverter = ThermSim.Heatsource(9, 10, "inverter")
    circ.add_comp(inverter)
    compressor = ThermSim.Heatsource(10, 11, "compressor")
    circ.add_comp(compressor)


    """
    Provide input on boundary conditions
    """
    circ.add_bc("Vdot_1 = 0")
    circ.add_bc("delta_p_throttle1 = - 0.0")
    circ.add_bc("p_1 = 1.0")

    circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_8 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_8 * 60)")
    circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_4 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_4 * 60)")
    circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_5 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_5 * 60)")
    circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_9 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_9 *  60)")
    circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_6 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_6 * 60)")
    circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_10 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_10 * 60)")
    circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * Vdot_1 ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * Vdot_1 * 60)")

    critical_operation = False
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

    result_vdot_dict = {'Vdot_8' : ['Vdot el. Comp. in [l/s]', []], 
                        'Vdot_3' : ['Vdot Intercooler in [l/s]', []],
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

    vdot1 = [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60]
    input_list = ['Vdot_1', vdot1, 'BoP Entry Flow [l/s]']
    circ.analyse_vdot_temp_pr(input_list, result_vdot_dict, result_temp_dict, result_pr_dict)

    return circ, input_dict, result_dict
