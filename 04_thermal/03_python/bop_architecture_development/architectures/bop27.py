import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    bop Architecture 27
                                7              8                9                    13                    
                                .---> LV DCDC ---> Compressor ---.               .-------------------------------.
                                |                                |               |                               |
    ----> evap --> HV DCDC --> splitter1                       Mixer1 --------> TCV1 ---> Intercooler ----> Mixer2 ----->
    1          2          3    |                                |     10              11               12            14
                                '---> HPDU ----> Inverter -------'
                                4           5                 6            
    """

    circ = ThermSim.Circuit()
    evap = ThermSim.Heatsink(1, 2, "evap")
    circ.add_comp(evap)
    hvdcdc = ThermSim.Heatsource(2, 3, "hvdcdc")
    circ.add_comp(hvdcdc)

    splitter1 = ThermSim.ConnectorPassive1to2(3, 7, 4, "splitter1")
    circ.add_comp(splitter1)

    hpdu = ThermSim.Heatsource(4, 5, "hpdu")
    circ.add_comp(hpdu)
    inverter = ThermSim.Heatsource(5, 6, "inverter")
    circ.add_comp(inverter)

    lvdcdc = ThermSim.Heatsource(7, 8, "lvdcdc")
    circ.add_comp(lvdcdc)
    compressor = ThermSim.Heatsource(8, 9, "compressor")
    circ.add_comp(compressor)

    mixer1 = ThermSim.ConnectorPassive2to1(9, 6, 10, "mixer1")
    circ.add_comp(mixer1)
    tcv1 = ThermSim.ConnectorActive1to2(10, 11, 13, "tcv1")
    circ.add_comp(tcv1)
    intercooler = ThermSim.Heatsource(11, 12, "intercooler")
    circ.add_comp(intercooler)
    mixer2 = ThermSim.ConnectorPassive2to1(12, 13, 15, "mixer2")
    circ.add_comp(mixer2)


    """
    Provide input on boundary conditions
    """
    circ.add_bc("%s = 0.0" %tcv1.nsplit_2)
    circ.add_bc("%s = 0.0"%tcv1.delta_p_1)

    circ.add_bc("%s = %f" %(mixer2.p_out, bc_dict["p_end"]))    # depends on architecture


    for name in bc_dict:
        if "Vdot_in" == name:
            circ.add_bc("Vdot_1 = %f" %bc_dict["Vdot_in"])
        elif "p_in" == name:
            circ.add_bc("%s = %f" %(evap.p_in, bc_dict["p_in"]))

    circ.add_bc("T_1 = %f" %bc_dict["T_in"])
    circ.add_bc("Qdot_hpdu = %f" %bc_dict["Qdot_hpdu"])
    circ.add_bc("Qdot_lvdcdc = %f" %bc_dict["Qdot_lvdcdc"])
    circ.add_bc("Qdot_hvdcdc = %f" %bc_dict["Qdot_hvdcdc"])
    circ.add_bc("Qdot_inverter = %f" %bc_dict["Qdot_inverter"])
    circ.add_bc("Qdot_intercooler = %f" %bc_dict["Qdot_intercooler"])
    circ.add_bc("Qdot_compressor = %f" %bc_dict["Qdot_compressor"])
    circ.add_bc("Qdot_evap = %f" %bc_dict["Qdot_evap"]) 

    circ.add_bc("delta_p_hpdu = - (1.0423 * 10 ** (-3) * %s ** 2 * 60 ** 2 + 2.2465 * 10 ** (-3) * %s * 60)"%(hpdu.Vdot_in,hpdu.Vdot_in))
    circ.add_bc("delta_p_lvdcdc = - (5.3884 * 10 ** (-4) * %s ** 2 * 60 ** 2  + 2.8112 * 10 ** (-3) * %s * 60)"%(lvdcdc.Vdot_in,lvdcdc.Vdot_in))
    circ.add_bc("delta_p_hvdcdc  = - (2.9586 * 10 ** (-4) * %s ** 2 * 60 ** 2 + 1.3238 * 10 ** (-3) * %s * 60)"%(hvdcdc.Vdot_in,hvdcdc.Vdot_in))
    circ.add_bc("delta_p_inverter = - (2.7820 * 10 ** (-3) * %s ** 2 * 60 ** 2 + 5.2494 * 10 ** (-3) * %s *  60)"%(inverter.Vdot_in, inverter.Vdot_in))
    circ.add_bc("delta_p_intercooler = - (4.4760 * 10 ** (-4) * %s ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * %s * 60)"%(intercooler.Vdot_in, intercooler.Vdot_in))
    circ.add_bc("delta_p_compressor = - (2.9956 * 10 ** (-3) * %s ** 2 * 60 ** 2 + 4.1023 * 10 ** (-4) * %s * 60)"%(compressor.Vdot_in, compressor.Vdot_in))
    circ.add_bc("delta_p_evap = - (1.3479 * 10 ** (-4) * %s ** 2 * 60 ** 2 + 1.4225 * 10 ** (-3) * %s * 60)"%(evap.Vdot_in, evap.Vdot_in))

    """
    Relate the variable name in the circuit to the variable in result_dict and input_dict
    """
    if input_dict is not None: 
        for name in input_dict:
            if name == "Vdot_in":
                input_dict[name][0] = evap.Vdot_in
            if name == "throttle_delta_p":
                input_dict[name][0] = "ha"        # depends on architecture
            if name == "p_in":
                input_dict[name][0] = evap.p_in

    for name in result_dict:
        if name == "t_in_lvdcdc":
            result_dict[name][0] = lvdcdc.T_in
        elif name == "t_in_hvdcdc":
            result_dict[name][0] = hvdcdc.T_in
        elif name == "t_in_inverter":
            result_dict[name][0] = inverter.T_in
        elif name == "t_in_hpdu":
            result_dict[name][0] = hpdu.T_in
        elif name == "t_in_compressor":
            result_dict[name][0] = compressor.T_in
        elif name == "t_in_intercooler":
            result_dict[name][0] = intercooler.T_in
        elif name == "t_out_intercooler":
            result_dict[name][0] = intercooler.T_out
        elif name == "t_out_Bop":
            result_dict[name][0] = mixer2.T_out     # depends on architecture!
        elif name == "p_in":
            result_dict[name][0] = evap.p_in     # depends on architecture!
        elif name == "Vdot_in":
            result_dict[name][0] = evap.Vdot_in     # = "Vdot_1"

    if "Vdot_1" in result_dict.keys():
        result_dict["Vdot_1"][0] = intercooler.Vdot_in          # depends on architecture!
        result_dict["Vdot_1"][2] = "Flow over Intercooler in [l/s]"
        result_dict["vdot_intercooler"] = result_dict["Vdot_1"]
        del result_dict["Vdot_1"]
    if "Vdot_2" in result_dict.keys():
        result_dict["Vdot_2"][0] = mixer1.Vdot_in_2        # depends on architecture!
        result_dict["Vdot_2"][2] = "Flow over Bypass in [l/s]"
        result_dict["vdot_bypass"] = result_dict["Vdot_2"]
        del result_dict["Vdot_2"]
    if "Vdot_3" in result_dict.keys():      # depends on architecture
        del result_dict["Vdot_3"]
    if "Vdot_4" in result_dict.keys():      # depends on architecture
        del result_dict["Vdot_4"]


    return circ, input_dict, result_dict