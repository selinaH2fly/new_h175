import sys
import os

sys.path.insert(1, os.path.join(sys.path[0], '..'))

import ThermSim

# Input on architecture

circ = ThermSim.Circuit()
pump1 = ThermSim.Pump("p_1", "T_1", "Vdot_1", "p_2", "T_2", "Vdot_2", "delta_p_pump1")
circ.add_comp(pump1)
splitter1 = ThermSim.ConnectorPassive1to2("p_2", "T_2", "Vdot_2", "p_3", "T_3", "Vdot_3", "p_6", "T_6", "Vdot_6", "nsplit_1_splitter1", "nsplit_2_splitter1")
circ.add_comp(splitter1)
throttle1 = ThermSim.Throttle("p_3", "T_3", "Vdot_3", "p_4", "T_4", "Vdot_4", "delta_p_throttle1")
circ.add_comp(throttle1)
bop1 = ThermSim.Heatsource("p_4", "T_4", "Vdot_4", "p_5", "T_5", "Vdot_5", "delta_p_bop1", "Qdot_bop1", "c_p_in_bop1", "c_p_out_bop1")
circ.add_comp(bop1)
mixer2 = ThermSim.ConnectorPassive2to1("p_5", "T_5", "Vdot_5", "p_9", "T_9", "Vdot_9", "p_12", "T_12", "Vdot_12", "c_p_in_1_mixer2", "c_p_in_2_mixer2", "c_p_out_mixer2", "nmix_1_mixer2", "nmix_2_mixer2")
circ.add_comp(mixer2)
mixer1 = ThermSim.ConnectorPassive2to1("p_6", "T_6", "Vdot_6", "p_11", "T_11", "Vdot_11", "p_7", "T_7", "Vdot_7", "c_p_in_1_mixer1", "c_p_in_2_mixer1", "c_p_out_mixer1", "nmix_1_mixer1", "nmix_2_mixer1")
circ.add_comp(mixer1)
stack1 = ThermSim.Heatsource("p_7", "T_7", "Vdot_7", "p_8", "T_8", "Vdot_8", "delta_p_stack1", "Qdot_stack1", "c_p_in_stack1", "c_p_out_stack1")
circ.add_comp(stack1)
splitter2 = ThermSim.ConnectorPassive1to2("p_8", "T_8", "Vdot_8", "p_9", "T_9", "Vdot_9", "p_10", "T_10", "Vdot_10", "nsplit_1_splitter2", "nsplit_2_splitter2")
circ.add_comp(splitter2)
pump2 = ThermSim.Pump("p_10", "T_10", "Vdot_10", "p_11", "T_11", "Vdot_11", "delta_p_pump2")
circ.add_comp(pump2)
radiator1 = ThermSim.Heatsink("p_12", "T_12", "Vdot_12", "p_1", "T_1", "Vdot_1", "delta_p_radiator1", "Qdot_radiator1", "c_p_in_radiator1", "c_p_out_radiator1")
circ.add_comp(radiator1)


# Input on boundary conditions

circ.add_bc("p_1 = 1.0")
# circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023 - 0.0028 + 0.0052 + 0.0022 + 0.0013 + 0.001) * 60.0 * Vdot_3 - (0.0001 + 0.0004 + 0.0035 + 0.0028 + 0.001 + 0.0003 + 0.001) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_bop1 = - (0.0014 + 0.0023) * 60.0 * Vdot_3 - (0.0001 + 0.0004) * 60.0 ** 2 * Vdot_3 **2")
circ.add_bc("delta_p_stack1 = - 0.6")
circ.add_bc("delta_p_radiator1 = - 0.4")

circ.add_bc("T_7 = 273.15 + 70.0")
circ.add_bc("T_8 = 273.15 + 85.0")
circ.add_bc("T_4 = 273.15 + 50.0")

circ.add_bc("Qdot_bop1 = 10000.0")
circ.add_bc("Qdot_stack1 = 180000.0")

circ.add_bc("Vdot_4 = 0.1")


# Evaluation and output

circ.evaluate()