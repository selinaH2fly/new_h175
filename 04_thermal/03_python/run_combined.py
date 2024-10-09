from bop_architecture_development.architectures import bop10, bop21, bop22, bop23, bop24, bop25, bop26, bop27, bop31, bop32, bop33, bop41, bop42
from architecture_development.architectures import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08

import pandas as pd
import matplotlib.pyplot as plt

# what combination do you want to test? Only choose one for each!
big_arch_list = []           # "Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08"
bop_arch_list = []           # "bop10", "bop21","bop22", "bop23", "bop24","bop25", "bop26", "bop27","bop31", "bop33", "bop41" & "bop42"

# Do you want to vary one boundary condition? If not no plots will be made, but results will be safed in excel.
vary_bc = True

# How do you want to plot?
# Do you want to compare results of different architectures in one plot (has effect if vary_bc is set True)

if vary_bc is True: # Adjust Input_dict only if you want to vary a boundary condition
    # input_dict = {"Variable_Name": ["Variable_Name in Architecture", [List of Values], "Text for plotting"]}

    #input_dict = {"Vdot_in" : ["", [10/60, 12/60, 15/60, 17/60, 20/60, 22/60, 25/60, 27/60, 30/60], "BoP Eingangsvolumenstrom l/s"]}
    input_dict = {"p_in": ["p_1", [1.35, 1.4, 1.45, 1.5, 1.55, 1.6], "Input Pressure [bar]"]} #1.3, 1.35,
    #input_dict = {"throttle_delta_p" : ["", [0.1, 0.15, 0.2, 0.25, 0.3], "Thottle pressure drop [bar]"]}
else:
    input_dict = None

# What boundary conditions do you want to set? 
big_bc_dict = {"pump_p_in" : 1,                     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 68.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 80.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 60.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 13000,                     # bop heat 
           "stack_q" : 200000,                  # stack heat
           "bop_vdot" : 0.5                     # flow over bop components (whole block) 30L/min
           }

critical_operation = True
if critical_operation is True:
    bop_bc_dict = {"T_in" : 273.15 + 60.0,
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
    bop_bc_dict = {"T_in" : 273.15 + 50.0,
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
    
# Which variables should be safed in excel and be plotted
big_result_dict = {"pump_vdot" : ["", [], 'flow over pump1 [l/S]'],
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],
                "radiator_vdot" : ["", [], 'flow over radiator [l/S]'],
                "perc_recirc": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]'],
                "pump2_vdot" : ["", [], "flow over pump2 [l/s]"],
                "pump2_delta_p" : ["", [], "pump2 pressure difference [bar]"],
                "stack_delta_p" : ["", [], "pressure loss over stack [bar]"],
                "pump_power" : ["", [], "optimal pump power [W]"],
}
    
bop_result_dict = {"Vdot_in" :              ['', [], 'BoP Input flow in [l/s]'], 
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
for arch in big_arch_list:      # each architecture is evaluated
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    print("Start to evaluate architecture %s"%arch)
    result_dict = circ.analyse_arch(input_dict, result_dict)

    for name in result_dict:    # rewrite results in one dictionary
        all_result_dict["%s_%s"%(arch,name)] = [result_dict[name][0], result_dict[name][1], result_dict[name][2]]
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
