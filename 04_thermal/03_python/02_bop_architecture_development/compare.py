from architectures import bop10, bop21, bop22, bop23, bop24, bop25, bop26, bop27, bop31, bop32, bop33, bop41, bop42

import pandas as pd
import matplotlib.pyplot as plt
#, "Arch03b", "Arch04", "Arch06", "Arch08"
arch_list = ["bop10", "bop21", "bop31", "bop42"]      # which architecture should be analysed?, also possible to evaluate multiple architectures

# input_dict = {"Vdot_in" : ["", [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60], "BoP Eingangsvolumenstrom l/s"]}
input_dict = {"p_in": ["p_1", [1.3, 1.35, 1.4, 1.45, 1.5, 1.55, 1.6], "Input Pressure [bar]"]}
#input_dict = {"throttle_delta_p" : ["", [0.1, 0.15, 0.2, 0.25, 0.3], "Thottle pressure drop [bar]"]}

# input
critical_operation = True
if critical_operation is True:
    bc_dict = {"T_in" : 273.15 + 60.0,
                #"Vdot_in" : 0.5,
                "p_in" : 0.5,
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
                "p_in" :               ["", [], 'bop pressure drop in [bar]']}



#calculation
excel_dict = {}
for arch in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    result_dict = circ.compare_big_arch(input_dict, result_dict)

    for name in result_dict:    # rewrite results in one dictionary
        excel_dict["%s_%s"%(arch,name)] = result_dict[name][1]
        result_dict[name][1] = []   # delete values


#max_len = 0    # fills gap in excel_dict with 0, important for architectures without second pump
#for name in excel_dict:
 #   list_len = len(excel_dict[name])
  #  if list_len > max_len:
   #     max_len = list_len
#for name in excel_dict:
 #   while len(excel_dict[name]) < max_len:
  #      excel_dict[name].append(0)

data = pd.DataFrame(excel_dict)
datatoexcel = pd.ExcelWriter('results.xlsx')
data.to_excel(datatoexcel)
datatoexcel.close()



for input_name in input_dict:
    for result_name in result_dict:
        y_begin, y_end = [], [] # y- position of data beginn and end
        for title in excel_dict:
            if result_name in title:
                plt.plot(input_dict[input_name][1], excel_dict[title], label=title[:title.index("_")]) # plots data

                adj_begin, adj_end = 0, 0           # 
                for y in y_begin:
                    if excel_dict[title][0] == 0:
                        if y == 0:
                            adj_begin += (input_dict[input_name][1][-1] - input_dict[input_name][1][0]) / 10
                    elif abs((y - excel_dict[title][0]) / excel_dict[title][0]) * 100 < 0.1:
                        adj_begin += (input_dict[input_name][1][-1] - input_dict[input_name][1][0]) / 10
                plt.text(input_dict[input_name][1][0] + adj_begin, excel_dict[title][0], title[:title.index("_")], fontsize=8)
                for y in y_end:
                    if excel_dict[title][-1] == 0:
                        if y == 0:
                            adj_end += (input_dict[input_name][1][-1] - input_dict[input_name][1][0]) / 10
                    elif abs((y - excel_dict[title][-1]) / excel_dict[title][-1]) * 100 < 0.1:
                        adj_end += (input_dict[input_name][1][-1] - input_dict[input_name][1][0]) / 10
                plt.text(input_dict[input_name][1][-1] - adj_end, excel_dict[title][-1] , title[:title.index("_")], fontsize=8)
                y_begin.append(excel_dict[title][0])
                y_end.append(excel_dict[title][-1])
                
        plt.ylabel(result_dict[result_name][2])
        plt.xlabel(input_dict[input_name][2])
        plt.legend()
        plt.grid()
        plt.show()
