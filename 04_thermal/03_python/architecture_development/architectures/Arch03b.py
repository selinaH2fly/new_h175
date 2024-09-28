import sys
import os
import numpy as np

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

def initialize(input_dict, result_dict, bc_dict):

    """
    Provide input on architecture

                    .-----> throttle1 --> bop1 -------.
                    | 3                4            5 |
                    |                                 v
    .-> pump1 --> splitter1 --> mixer1 --> stack1 --> mixer2 --> splitter2 --.
    |          2             6    ^     7          8          9      |       |
    |                             | 11                            10 |       |
    |                             '------------- pump2 <-------------'       |
    |                                                                        |
    | 1                                                                   12 |
    '------------------------------ radiator1 <------------------------------'
    """

    circ = ThermSim.Circuit()
    pump1 = ThermSim.Pump(1, 2, "pump1")
    circ.add_comp(pump1)
    splitter1 = ThermSim.ConnectorPassive1to2(2, 3, 6, "splitter1")
    circ.add_comp(splitter1)
    throttle1 = ThermSim.Throttle(3, 4, "throttle1")
    circ.add_comp(throttle1)
    bop1 = ThermSim.Heatsource(4, 5, "bop1")
    circ.add_comp(bop1)
    mixer2 = ThermSim.ConnectorPassive2to1(5, 8, 9, "mixer2")
    circ.add_comp(mixer2)
    mixer1 = ThermSim.ConnectorPassive2to1(6, 11, 7, "mixer1")
    circ.add_comp(mixer1)
    stack1 = ThermSim.Heatsource(7, 8, "stack1")
    circ.add_comp(stack1)
    splitter2 = ThermSim.ConnectorPassive1to2(9, 12, 10, "splitter2")
    circ.add_comp(splitter2)
    pump2 = ThermSim.Pump(10, 11, "pump2")
    circ.add_comp(pump2)
    radiator1 = ThermSim.Heatsink(12, 1, "radiator1")
    circ.add_comp(radiator1)


    """
    Provide input on boundary conditions
    """

    circ.add_bc("p_1 = %f" %bc_dict["pump_p_in"])
    circ.add_bc("delta_p_bop1 = - (0.000425124 * 60 ** 2 * %s ** 2 + 0.003355931 * %s)"%(bop1.Vdot_in, bop1.Vdot_in))
    circ.add_bc("delta_p_stack1 = - (5.6629  * 10 ** (-6) * 60 ** 2 * %s ** 2 + 6.3347 * 10 ** (-4) * 60 * %s)"%(stack1.Vdot_in, stack1.Vdot_in))
    circ.add_bc("delta_p_radiator1 = - (8.2958 * 10 ** (-6) * 60 ** 2 * %s + 1.6622 * 10 ** (-3) * 60 * %s)"%(radiator1.Vdot_in, radiator1.Vdot_in))

    circ.add_bc("T_7 = %f" %bc_dict["stack_t_in"])
    circ.add_bc("T_8 = %f" %bc_dict["stack_t_out"])
    circ.add_bc("T_4 = %f" %bc_dict["sys_t_in"])

    circ.add_bc("Qdot_bop1 = %f" %bc_dict["bop_q"])
    circ.add_bc("Qdot_stack1 = %f" %bc_dict["stack_q"])
    # circ.add_bc("Qdot_stack1 = %.1f"%(np.interp(600, [20, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600], [2.6, 9.7, 20.8, 33.1, 46.7, 60.5, 75.0, 90.2, 106.4, 123.6, 142.5, 162.0, 178.5], left=np.nan, right=np.nan) * 1000.0))

    circ.add_bc("Vdot_4 = %f" %bc_dict["bop_vdot"])


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
            result_dict[name][0] = mixer1.nmix_2
        elif name == "radiator_t_in":
            result_dict[name][0] = radiator1.T_in
        elif name == "pump2_vdot":
            result_dict[name][0] = pump2.Vdot_in
        elif name == "pump2_delta_p":
            result_dict[name][0] = pump2.delta_p

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
