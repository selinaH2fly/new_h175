from architectures import bop10, bop21, bop22, bop23, bop24, bop25, bop26, bop27, bop31, bop32, bop33, bop41, bop42
import pandas as pd
import matplotlib.pyplot as plt

# Do you wan't to vary one boundary condition?
vary_bc = True

# Do you wan't to compare results of different architectures in one file?
compare_res = True

# Which Architectures do you wan't to evaluate?
arch_list = ["bop42"]

if vary_bc is True: # Adjust Input_dict only if you wan't to vary a boundary condition
    # input_dict = {"Variable_Name": ["Variable_Name in Architecture", [List of Values], "Text for plotting"]}

    #input_dict = {"Vdot_in" : ["", [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60], "BoP Eingangsvolumenstrom l/s"]}
    input_dict = {"p_in": ["p_1", [1.25, 1.3, 1.35, 1.4, 1.45, 1.5], "Input Pressure [bar]"]}
    #input_dict = {"throttle_delta_p" : ["", [0.1, 0.15, 0.2, 0.25, 0.3], "Thottle pressure drop [bar]"]}
else:
    input_dict = None

# input
critical_operation = True
if critical_operation is True:
    bc_dict = {"T_in" : 273.15 + 60.0,
                #"Vdot_in" : 0.5,
                "p_in" : 1.5,
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
               #"Vdot_in" : 0.5,
                "p_in" : 0.5,
                "p_end" : 1,
                "Qdot_hpdu" : 500,
                "Qdot_lvdcdc" : 150,
                "Qdot_hvdcdc" : 800,
                "Qdot_inverter" : 625,
                "Qdot_intercooler" : 21000,
                "Qdot_compressor" : 500,
                "Qdot_evap" : -13500}
    
result_dict = {"Vdot_in" :              ['', [], 'BoP Input flow in [l/s]'], 
                "Vdot_1" :              ['', [], ''], 
                "Vdot_2" :              ['', [],''],
                "Vdot_3" :              ['', [],''],
                "Vdot_4" :              ['', [],''],
                "t_in_lvdcdc":          ["", [],'LV DCDC T_in'],
                "t_in_hvdcdc" :         ["", [], 'HV DCDC T_in'],
                "t_in_inverter" :       ["", [], 'Inverter T_in'],
                "t_in_hpdu" :           ["", [], 'HPDU T_in'],
                "t_in_compressor" :     ["", [], 'Compressor T_in'],
                "t_in_intercooler" :    ["", [], "Intercooler T_in"],
                "t_out_intercooler" :   ["", [], "Intercooler T_out"],
                "t_out_Bop" :           ["", [],'BoP T_out'],
                "p_in" :                ["", [], 'bop pressure drop in [bar]']}

##########   calculation ###########################################################################################
excel_dict = {}
for arch in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    circ.analyse_vdot_temp_pr(input_dict, result_dict)

    for name in result_dict:    # rewrite results in one dictionary
        excel_dict["%s_%s"%(arch,name)] = result_dict[name][1]
        result_dict[name][1] = []   # delete values


if input_dict is not None:
    for name in input_dict:
            excel_dict[input_dict[name][2]] = input_dict[name][1]
data = pd.DataFrame(excel_dict)
datatoexcel = pd.ExcelWriter('results.xlsx')
data.to_excel(datatoexcel)
datatoexcel.close()
