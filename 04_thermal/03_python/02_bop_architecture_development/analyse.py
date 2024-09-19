from architectures import bop10, bop21, bop22

arch_list = ["bop10"]      # which architecture should be analysed?, also possible to evaluate multiple architectures

# input_list[0] = variable which should be adapted
# input_list[1] = Values for adjusting boundary condition
# input_list[2] = Description for axis for plotting
#, 273.15 + 70 + 12, 273.15 + 70 + 14, 273.15 + 70 + 16
input_dict = {"Vdot_in" : ["", [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60], "BoP Eingangsvolumenstrom l/s"]}
#input_dict = {"p_in": ["p_1", [1.25, 1.3, 1.35, 1.4, 1.45, 1.5], "Input Pressure [bar]"]}
#input_dict = {"throttle_delta_p" : ["", [0.1, 0.15, 0.2, 0.25, 0.3], "Thottle pressure drop [bar]"]}

# input
critical_operation = True
if critical_operation is True:
    bc_dict = {"T_in" : 273.15 + 60.0,
                "Vdot_in" : 0.5,
                "p_end" : 1,
                "Qdot_hpdu" : 1000,
                "Qdot_lvdcdc" : 300,
                "Qdot_hvdcdc" : 1600,
                "Qdot_inverter" : 1250,
                "Qdot_intercooler" : 21000,
                "Qdot_compressor" : 1000,
                "Qdot_evap" : -13500}
else: 
    bc_dict = {"T_in" : 273.15 + 50.0,
               "Vdot_in" : 0.5,
                "p_end" : 1,
                "Qdot_hpdu" : 500,
                "Qdot_lvdcdc" : 150,
                "Qdot_hvdcdc" : 800,
                "Qdot_inverter" : 625,
                "Qdot_intercooler" : 21000,
                "Qdot_compressor" : 500,
                "Qdot_evap" : -13500}
    
result_dict = {"Vdot_in" :              ['', [], ''], 
                "Vdot_1" :              ['', [], ''], 
                "Vdot_2" :              ['', [],''],
#                "Vdot_3" :              ['', [],''],
 #               "Vdot_4" :              ['', [],''],
                "t_in_lvdcdc":          ["", [],'LV DCDC T_in'],
                "t_in_hvdcdc" :         ["", [], 'HV DCDC T_in'],
                "t_in_inverter" :       ["", [], 'Inverter T_in'],
                "t_in_hpdu" :           ["", [], 'HPDU T_in'],
                "t_in_compressor" :     ["", [], 'Compressor T_in'],
                "t_in_intercooler" :    ["", [], "Intercooler T_in"],
                "t_out_intercooler" :   ["", [], "Intercooler T_out"],
                "t_out_Bop" :           ["", [],'BoP T_out'],
                "p_in" :               ["", [], 'bop pressure drop in [bar]']}

#calculation
for y in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(y, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    circ.analyse_vdot_temp_pr(input_dict, result_dict)
