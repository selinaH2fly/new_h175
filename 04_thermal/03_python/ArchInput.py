"""
This script contains a test case serving as a template to set up and conduct a thermal simulation.
The circuit of this test case consists of a pump, two parallel heatsources connected via passive splitter and mixer, and a heatsink, with adequately defined dummy boundary conditions.
"""


import ThermSim


"""
Provide input on architecture

                  .--------> stack1 ----------.
                  | 3                       4 |
                  |                           v
.-> pump1 --> splitter1 --> compressor1 --> mixer1 --.
|          2             5               6           |
| 1                                                7 |
'-------------------- radiator1 <--------------------'
"""

circ = ThermSim.Circuit()
pump1 = ThermSim.Pump(1, 2, "pump1")
circ.add_comp(pump1)
splitter1 = ThermSim.ConnectorPassive1to2(2, 3, 5, "splitter1")
circ.add_comp(splitter1)
stack1 = ThermSim.Heatsource(3, 4, "stack1")
circ.add_comp(stack1)
mixer1 = ThermSim.ConnectorPassive2to1(4, 6, 7, "mixer1")
circ.add_comp(mixer1)
compressor1 = ThermSim.Heatsource(5, 6, "compressor1")
circ.add_comp(compressor1)
radiator1 = ThermSim.Heatsink(7, 1, "radiator1")
circ.add_comp(radiator1)


"""
Provide input on boundary conditions
"""

circ.add_bc("p_1 = 1.0")
circ.add_bc("T_3 = 273.15 + 60.0")
circ.add_bc("T_4 = 273.15 + 75.0")
circ.add_bc("delta_p_stack1 = - 2.0")
circ.add_bc("delta_p_radiator1 = - 1.0")
circ.add_bc("delta_p_compressor1 = - 100.0 * Vdot_5 ** 2")
circ.add_bc("Qdot_stack1 = 100000.0")
circ.add_bc("Qdot_compressor1 = 5000.0")


"""
Evaluate and generate output
"""

circ.evaluate()