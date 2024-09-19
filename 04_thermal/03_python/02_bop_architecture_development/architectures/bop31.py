import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    bop Architecture 2.1
                    9           10          11              12
                    .--> HPDU ---> HV DCDC --> Compressor --.
                    |                                       |
                    |    6               7             8    | 
                    |    .----> LV DCDC ---> Inverter --.   |
                    |    |                              |   |
    ----> evap --> splitter1                            Mixer1 ---->
    1          2    |                                  |       13
                    '---> Throttle1 --> Intercooler ---'
                    3                4                5                 
    """

    circ = ThermSim.Circuit()
    evap = ThermSim.Heatsink(1, 2, "evap")
    circ.add_comp(evap)
    splitter1 = ThermSim.ConnectorPassive1to3(2, 9, 6, 3, "splitter1")
    circ.add_comp(splitter1)

    throttle1 = ThermSim.Throttle(3, 4, "throttle1")
    circ.add_comp(throttle1)
    intercooler = ThermSim.Heatsource(4, 5, "intercooler")
    circ.add_comp(intercooler)

    lvdcdc = ThermSim.Heatsource(6, 7, "lvdcdc")
    circ.add_comp(lvdcdc)
    inverter = ThermSim.Heatsource(7, 8, "inverter")
    circ.add_comp(inverter)

    hpdu = ThermSim.Heatsource(9, 10, "hpdu")
    circ.add_comp(hpdu)
    hvdcdc = ThermSim.Heatsource(10, 11, "hvdcdc")
    circ.add_comp(hvdcdc)
    compressor = ThermSim.Heatsource(11, 12, "compressor")
    circ.add_comp(compressor)

    mixer1 = ThermSim.ConnectorPassive3to1(12, 8, 5, 13, "mixer1")
    circ.add_comp(mixer1)

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
    
    circ.add_bc("delta_p_throttle1 = - 0.0")

    # circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
    circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * Vdot_9 ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * Vdot_9 * 60)")
    circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * Vdot_6 ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * Vdot_6 * 60)")
    circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * Vdot_10 ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * Vdot_10 * 60)")
    circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * Vdot_7 ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * Vdot_7 *  60)")
    circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * Vdot_4 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_4 * 60)")
    circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * Vdot_11 ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * Vdot_11 * 60)")
    circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * Vdot_1 ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * Vdot_1 * 60)")

    """
    Evaluate and generate output
    """

    result_vdot_dict = {'Vdot_6' : ['Vdot LV DCDC in [l/s]', []], 
                        'Vdot_9' : ['Vdot HPDU in [l/s]', []],
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


    return circ, input_dict, result_dict
