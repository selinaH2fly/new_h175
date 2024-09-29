import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    Provide input on architecture

        .----> throttle1 --> bop1 ------.
        | 2               3           4 |
        |                               v
    splitter1 --> mixer2 --> stack1 --> mixer1 --> pump1 --> tcv1 --.
        ^      5    ^     6          7          9        10   |     |
        |           |                                         |     |
        |           '-----------------------------------------'     |
        |                               8                           |
        | 1                                                      11 |
        '------------------------ radiator1 <-----------------------'
    """

    circ = ThermSim.Circuit()
    splitter1 = ThermSim.ConnectorPassive1to2(1, 2, 5, "splitter1")
    circ.add_comp(splitter1)
    throttle1 = ThermSim.Throttle(2, 3, "throttle1")
    circ.add_comp(throttle1)
    bop1 = ThermSim.Heatsource(3, 4, "bop1")
    circ.add_comp(bop1)
    mixer1 = ThermSim.ConnectorPassive2to1(4, 7, 9, "mixer1")
    circ.add_comp(mixer1)
    mixer2 = ThermSim.ConnectorPassive2to1(5, 8, 6, "mixer2")
    circ.add_comp(mixer2)
    stack1 = ThermSim.Heatsource(6, 7, "stack1")
    circ.add_comp(stack1)
    pump1 = ThermSim.Pump(9, 10, "pump1")
    circ.add_comp(pump1)
    tcv1 = ThermSim.ConnectorActive1to2(10, 11, 8, "tcv1")
    circ.add_comp(tcv1)
    radiator1 = ThermSim.Heatsink(11, 1, "radiator1")
    circ.add_comp(radiator1)


    """
    Provide input on boundary conditions
    """
    circ.add_bc("delta_p_1_tcv1 = 0.0")

    # boundary conditions, user input:
    circ.add_bc("%s = %f" %(pump1.p_in, bc_dict["pump_p_in"]))
    circ.add_bc("%s = %f" %(stack1.T_in, bc_dict["stack_t_in"]))
    circ.add_bc("%s = %f" %(stack1.T_out, bc_dict["stack_t_out"]))
    circ.add_bc("%s = %f" %(radiator1.T_out, bc_dict["sys_t_in"]))
    circ.add_bc("%s = %f" %(bop1.Qdot, bc_dict["bop_q"]))
    circ.add_bc("%s = %f" %(stack1.Qdot, bc_dict["stack_q"]))
    circ.add_bc("%s = %f" %(bop1.Vdot_in,bc_dict["bop_vdot"]))

    # fixed boundary conditiones:
    circ.add_bc("%s = - (0.000425124 * 60 ** 2 * %s ** 2 + 0.003355931 * %s)"%(bop1.delta_p, bop1.Vdot_in, bop1.Vdot_in))
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
            result_dict[name][0] = mixer2.nmix_2
        elif name == "radiator_t_in":
            result_dict[name][0] = radiator1.T_in
        elif name == "stack_delta_p":
            result_dict[name][0] = stack1.delta_p
    if "pump2_vdot" in result_dict.keys():
        del result_dict["pump2_vdot"]
    if "pump2_delta_p" in result_dict.keys():
        del result_dict["pump2_delta_p"]    
    
    if input_dict is not None: 
        for name in input_dict:
            if name == "stack_t_in":
                input_dict[name][0] = stack1.T_in              #
            elif name == "stack_t_out":
                input_dict[name][0] = stack1.T_out              #
            elif name == "sys_t_in":
                input_dict[name][0] = radiator1.T_out            #
            elif name == "bop_q":
                input_dict[name][0] = bop1.Qdot
            elif name == "stack_q":
                input_dict[name][0] = stack1.Qdot
            elif name == "bop_vdot":
                input_dict[name][0] = bop1.Vdot_in          #
            elif name == "bop_dp":
                input_dict[name][0] = bop1.delta_p

    return circ, input_dict, result_dict

