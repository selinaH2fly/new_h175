from architectures import bop10, bop21, bop22, bop23, bop24, bop25, bop26, bop27, bop31, bop32, bop33, bop41, bop42
import pandas as pd
import matplotlib.pyplot as plt

# Do you want to vary one boundary condition? If not no plots will be made, but results will be safed in excel.
vary_bc = True  

# How do you want to plot?
# Do you wan't to compare results of different architectures in one plot (has effect if vary_bc is set True)
compare_res = False 
# if you don't want to compare architectures in one plot: Do you wan't to compare all temperatures, all pressures and all flows in each one plot?
plot_temp_pr_vd = True

# Which Architectures do you wan't to evaluate? ["bop10", "bop21","bop22", "bop23", "bop24","bop25", "bop26", "bop27","bop31", "bop33", "bop41","bop42"]
arch_list = ["bop10", "bop21"]

if vary_bc is True: # Adjust Input_dict only if you wan't to vary a boundary condition
    # input_dict = {"Variable_Name": ["Variable_Name in Architecture", [List of Values], "Text for plotting"]}

    #input_dict = {"Vdot_in" : ["", [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60], "BoP Eingangsvolumenstrom l/s"]}
    input_dict = {"p_in": ["p_1", [1.3, 1.35, 1.4, 1.45, 1.5], "Input Pressure [bar]"]}
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
                "p_in" : 1.5,
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
all_result_dict = {}
for arch in arch_list:      # each architecture is evaluated
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    result_dict = circ.compare_big_arch(input_dict, result_dict)

    for name in result_dict:    # rewrite results in one dictionary
        all_result_dict["%s_%s"%(arch,name)] = [result_dict[name][0], result_dict[name][1], result_dict[name][2]]
        excel_dict["%s_%s"%(arch,name)] = result_dict[name][1]
        result_dict[name][1] = []   # delete values


if input_dict is not None:
    for name in input_dict:
            excel_dict[input_dict[name][2]] = input_dict[name][1]
data = pd.DataFrame(excel_dict)
datatoexcel = pd.ExcelWriter('results.xlsx')
data.to_excel(datatoexcel)
datatoexcel.close()

if vary_bc is True and compare_res is False and plot_temp_pr_vd is True:        # condition that all temp, vdot and pressure get plottet in one plot
     for input_name in input_dict:                  # just to get the key of input_dict, no loop!
        for arch in arch_list:                      # loops through all arch
            for result_name in all_result_dict:          # loops through all result
                if arch in result_name:             # if result matches current arch, it gets plotted
                    if ("vdot" in result_name) or ("Vdot" in result_name):
                        plt.plot(input_dict[input_name][1], all_result_dict[result_name][1], label=all_result_dict[result_name][2])
            plt.ylabel('Flow in Branches in [l/s]')
            plt.xlabel(input_dict[input_name][2])
            plt.legend()
            plt.grid()
            plt.title(arch)
            plt.show()
            for result_name in excel_dict:
                if arch in result_name:             # if result matches current arch, it gets plotted
                    if "dot_" not in result_name and (("t_in" in result_name) or ("t_out" in result_name) or ("T_" in result_name)):
                        plt.plot(input_dict[input_name][1], all_result_dict[result_name][1], label=all_result_dict[result_name][2])
            plt.ylabel('Temperature in [K]')
            plt.xlabel(input_dict[input_name][2])
            plt.legend(loc = 'lower right')
            plt.grid()
            plt.title(arch)
            plt.show()
            for result_name in excel_dict:
                if arch in result_name:
                    if "delta_p" in result_name:
                        plt.plot(input_dict[input_name][1], all_result_dict[result_name][1], label=all_result_dict[result_name][2])
                        
                    if "p_in" in result_name:
                        y = 0
                        while y < len(all_result_dict[result_name][1]):
                            all_result_dict[result_name][1][y] -= 1
                            y +=1
                        plt.plot(input_dict[input_name][1], all_result_dict[result_name][1], label=all_result_dict[result_name][2])
            plt.ylabel('BoP Pressuredrop in [bar]')
            plt.xlabel(input_dict[input_name][2])
            plt.legend()
            plt.grid()
            plt.title(arch)
            plt.show()

if vary_bc is True and compare_res is False and plot_temp_pr_vd is False:
    for input_name in input_dict:                  # just to get the key of input_dict, no loop!
        for result_name in all_result_dict:         # loops through all result
            plt.plot(input_dict[input_name][1], all_result_dict[result_name][1])
            plt.ylabel(all_result_dict[result_name][2])
            plt.xlabel(input_dict[input_name][2])
            plt.grid()
            plt.show()



if vary_bc is True and compare_res is True:
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
