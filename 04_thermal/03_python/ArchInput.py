"""
This script contains a test case serving as a template to set up and conduct a thermal simulation.
The circuit of this test case consists of a pump, two parallel heatsources connected via passive splitter and mixer, and a heatsink, with adequately defined dummy boundary conditions.
"""


import ThermSim

# Provide input on architecture

circ = ThermSim.Circuit()
pump1 = ThermSim.Pump("p_7", "T_7", "Vdot_7", "p_1", "T_1", "Vdot_1", "delta_p_pump1")
circ.add_comp(pump1)
splitter1 = ThermSim.SplitterPassive1to2("p_1", "T_1", "Vdot_1", "p_2", "T_2", "Vdot_2", "p_4", "T_4", "Vdot_4", "nsplit_1_splitter1", "nsplit_2_splitter1")
circ.add_comp(splitter1)
stack1 = ThermSim.Heatsource("p_2", "T_2", "Vdot_2", "p_3", "T_3", "Vdot_3", "delta_p_stack1", "Qdot_stack1", "c_p_in_stack1", "c_p_out_stack1")
circ.add_comp(stack1)
comp1 = ThermSim.Heatsource("p_4", "T_4", "Vdot_4", "p_5", "T_5", "Vdot_5", "delta_p_comp1", "Qdot_comp1", "c_p_in_comp1", "c_p_out_comp1")
circ.add_comp(comp1)
mixer1 = ThermSim.MixerPassive2to1("p_3", "T_3", "Vdot_3", "p_5", "T_5", "Vdot_5", "p_6", "T_6", "Vdot_6", "c_p_in_1_mixer1", "c_p_in_2_mixer1", "c_p_out_mixer1", "nmix_1_mixer1", "nmix_2_mixer1")
circ.add_comp(mixer1)
rad1 = ThermSim.Heatsink("p_6", "T_6", "Vdot_6", "p_7", "T_7", "Vdot_7", "delta_p_rad1", "Qdot_rad1", "c_p_in_rad1", "c_p_out_rad1")
circ.add_comp(rad1)


# Provide input on boundary conditions

circ.add_bc("p_7 = 1.0")
circ.add_bc("T_2 = 273.15 + 60.0")
circ.add_bc("T_3 = 273.15 + 75.0")
circ.add_bc("delta_p_stack1 = - 2.0")
circ.add_bc("delta_p_rad1 = - 1.0")
circ.add_bc("delta_p_comp1 = - 100.0 * Vdot_4 ** 2")
circ.add_bc("Qdot_stack1 = 100000.0")
circ.add_bc("Qdot_comp1 = 5000.0")


# Evaluate and generate output

circ.evaluate()