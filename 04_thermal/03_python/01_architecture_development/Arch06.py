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
    bop1 = ThermSim.Heatsource(3, 4, "bop1")
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

    circ.add_bc("p_9 = %f" %bc_dict["pump_p_in"])

    # pressure drop for bop1 for all bop components including intercooler, must be adapted to without intercooler!
    # pressure drop bop2 is equal to intercooler pressure drop, already adapted!
    circ.add_bc("delta_p_bop1 = - (0.000425124 * 60 ** 2 * Vdot_3 ** 2 + 0.003355931 * Vdot_3)")
    circ.add_bc("delta_p_bop2 = - - (4.4760 * 10 ** (-4) * Vdot_11 ** 2 * 60 ** 2 + 2.2828 * 10 ** (-3) * Vdot_11 * 60)")


    circ.add_bc("delta_p_stack1 = - (5.6629  * 10 ** (-6) * 60 ** 2 * Vdot_7 ** 2 + 6.3347 * 10 ** (-4) * 60 * Vdot_7)")
    circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * Vdot_1 + 1.6622 * 10 ** (-3) * 60 * Vdot_1)")

    circ.add_bc("delta_p_1_tcv1 = 0.0")

    circ.add_bc("T_6 = %f" %bc_dict["stack_t_in"])
    circ.add_bc("T_7 = %f" %bc_dict["stack_t_out"])
    circ.add_bc("T_3 = %f" %bc_dict["sys_t_in"])

    circ.add_bc("Qdot_bop1 = 1650")
    circ.add_bc("Qdot_bop2 = 9000")
    circ.add_bc("Qdot_stack1 = %f" %bc_dict["stack_q"])
    #circ.add_bc("Qdot_stack1 = %.1f"%(np.interp(600, [20, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600], [2.6, 9.7, 20.8, 33.1, 46.7, 60.5, 75.0, 90.2, 106.4, 123.6, 142.5, 162.0, 178.5], left=np.nan, right=np.nan) * 1000.0))

    circ.add_bc("Vdot_3 = %f" %bc_dict["bop_vdot"])
    circ.add_bc("Vdot_11 = %f" %bc_dict["bop_vdot"])


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
