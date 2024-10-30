import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    Provide input on architecture

        .----> throttle1 --> bop1 ------.                      .--------> bop2 ----------.
        | 2               3           4 |                      | 11                   12 |
        |                               v                      |                         v
    splitter1 --> tcv1 --> stack1 --> mixer1 --> pump1 --> splitter2 --> throttle2 --> mixer2
        ^      5   ^    6          7          9        10      |     13            14    |
        |          |                                           |                         |
        |          '-------------------------------------------'                         |
        |                               8                                                |
        | 1                                                                           15 |
        '------------------------- radiator1 <-------------------------------------------'
    """

    circ = ThermSim.Circuit()
    splitter1 = ThermSim.ConnectorPassive1to2(1, 2, 5, "splitter1")
    circ.add_comp(splitter1)
    throttle1 = ThermSim.Throttle(2, 3, "throttle1")
    
    circ.add_comp(throttle1)
    bop1 = ThermSim.Heatsink(3, 4, "bop1")
    circ.add_comp(bop1)
    mixer1 = ThermSim.ConnectorPassive2to1(4, 7, 9, "mixer1")
    circ.add_comp(mixer1)
    tcv1 = ThermSim.ConnectorActive2to1(5, 8, 6, "tcv1")
    circ.add_comp(tcv1)
    stack1 = ThermSim.Heatsource(6, 7, "stack1")
    circ.add_comp(stack1)
    pump1 = ThermSim.Pump(9, 10, "pump1")
    circ.add_comp(pump1)
    splitter2 = ThermSim.ConnectorPassive1to3(10, 11, 13, 8, "splitter2")
    circ.add_comp(splitter2)
    bop2 = ThermSim.Heatsource(11, 12, "bop2")
    circ.add_comp(bop2)
    throttle2 = ThermSim.Throttle(13, 14, "throttle2")
    circ.add_comp(throttle2)
    mixer2 = ThermSim.ConnectorPassive2to1(12, 14, 15, "mixer2")
    circ.add_comp(mixer2)
    radiator1 = ThermSim.Heatsink(15, 1, "radiator1")
    circ.add_comp(radiator1)


    """
    Provide input on boundary conditions
    """
    circ.add_bc("0.0 = %s * %s"%(tcv1.delta_p_1, tcv1.delta_p_2))
    #circ.add_bc("0.0 = %s"%(tcv1.delta_p_1))
    # circ.add_bc("0.0 = %s * %s"%(tcv1.delta_p_1, tcv1.delta_p_2))
    # pressure drop for bop1 for all bop components including intercooler, must be adapted to without intercooler!
    # pressure drop bop2 is equal to intercooler pressure drop, already adapted
    circ.add_bc("%s = - (%f * %s ** 2 + %f * %s)"%(bop1.delta_p, bc_dict["bop_delta_p"][0], bop1.Vdot_in, bc_dict["bop_delta_p"][1], bop1.Vdot_in)) 
    circ.add_bc("delta_p_bop2 = - (4.4760 * 10 ** (-4) * %s ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * %s * 60)"%(bop2.Vdot_in, bop2.Vdot_in)) # intercooler
    #circ.add_bc("delta_p_bop2 = -0.6")
    circ.add_bc("Qdot_bop1 = -2000")
    circ.add_bc("Qdot_bop2 = 5000")

    circ.add_bc("%s = %f" %(bop1.Vdot_in, bc_dict["bop_vdot"]))
    #circ.add_bc("%s = -0.0"%(throttle1.delta_p))
    #circ.add_bc("%s = 0.0" %(splitter2.nsplit_2))
    circ.add_bc("%s = 0.1" %(bop2.Vdot_in))    # problem with architecture
    # boundary conditions, user input:
    circ.add_bc("%s = %f" %(pump1.p_in, bc_dict["pump_p_in"]))
    circ.add_bc("%s = %f" %(stack1.T_in, bc_dict["stack_t_in"]))
    circ.add_bc("%s = %f" %(stack1.T_out, bc_dict["stack_t_out"]))
    circ.add_bc("%s = %f" %(radiator1.T_out, bc_dict["sys_t_in"]))
    circ.add_bc("%s = %f" %(stack1.Qdot, bc_dict["stack_q"]))


    # fixed boundary conditiones:
    # circ.add_bc("%s = - (0.000425124 * 60 ** 2 * %s ** 2 + 0.003355931 * %s)"%(bop1.delta_p, bop1.Vdot_in, bop1.Vdot_in))
    circ.add_bc("%s = - (5.6629  * 10 ** (-6) * 60 ** 2 * %s ** 2 + 6.3347 * 10 ** (-4) * 60 * %s)"%(stack1.delta_p, stack1.Vdot_in, stack1.Vdot_in))
    circ.add_bc("%s = - (8.2958 * 10 ** (-6) * 60 ** 2 * %s + 1.6622 * 10 ** (-3) * 60 * %s)"%(radiator1.delta_p, radiator1.Vdot_in, radiator1.Vdot_in))


    """
    Evaluate and generate output
    """

    for name in result_dict:
        if name == "pump_vdot":
            result_dict[name][0] = pump1.Vdot_in
        elif name == "pump_delta_p":
            result_dict[name][0] = pump1.delta_p
        elif name == "radiator_vdot":
            result_dict[name][0] = radiator1.Vdot_in
        elif name == "perc_recirc":
            result_dict[name][0] = tcv1.nmix_2
        elif name == "radiator_t_in":
            result_dict[name][0] = radiator1.T_in
        elif name == "stack_delta_p":
            result_dict[name][0] = stack1.delta_p
        elif name == "radiator_q":
            result_dict[name][0] = radiator1.Qdot
        elif name == "radiator_cp_in":
            result_dict[name][0] = radiator1.c_p_in
        elif name == "radiator_cp_out":
            result_dict[name][0] = radiator1.c_p_out
        elif name == "radiator_t_in":
            result_dict[name][0] = radiator1.T_in
        elif name == "radiator_t_out":
            result_dict[name][0] = radiator1.T_out
    if "pump2_vdot" in result_dict.keys():
        del result_dict["pump2_vdot"]
    if "pump2_delta_p" in result_dict.keys():
        del result_dict["pump2_delta_p"]   
    
    if input_dict is not None: 
        for name in input_dict:
            if name == "stack_t_in":
                input_dict[name][0] = stack1.T_in             
            elif name == "stack_t_out":
                input_dict[name][0] = stack1.T_out              
            elif name == "sys_t_in":
                input_dict[name][0] = radiator1.T_out            #
            elif name == "bop_q":
                input_dict[name][0] = bop1.Qdot
            elif name == "stack_q":
                input_dict[name][0] = stack1.Qdot
            elif name == "bop_vdot":
                input_dict[name][0] = bop1.Vdot_in         
            elif name == "bop_dp":
                input_dict[name][0] = bop1.delta_p

    return circ, input_dict, result_dict
