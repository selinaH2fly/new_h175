from architectures import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08
import pandas as pd
import matplotlib.pyplot as plt

# Do you want to vary one boundary condition? If not no plots will be made, but results will be safed in excel.
vary_bc = False

# How do you want to plot?
# Do you want to compare results of different architectures in one plot (only has effect if vary_bc is set True)
compare_res = False

# Which Architectures do you want to evaluate? ["Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08"]
arch_list = ["Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08"]      # which architecture should be analysed?, also possible to evaluate multiple architectures

if vary_bc is True: # Adjust Input_dict only if you want to vary a boundary condition
    # input_dict = {"Variable_Name": ["Variable_Name in Architecture", [List of Values], "Text for plotting"]}

    input_dict = {"stack_t_out" : ["", [273.15 + 70 + 8, 273.15 + 70 + 10], 'Stackausgangstemperatur [K]']}
    input_dict = {"stack_t_in" : ["", [273.15 + 60 + 8, 273.15 + 60 + 10, 273.15 + 60 + 12], 'Stackeingangstemperatur [K]']} #, 273.15 + 60 + 14, 273.15 + 60 + 16
    #input_dict = {"sys_t_in" : ["", [273.15 + 50 + 8, 273.15 + 50 + 10, 273.15 + 50 + 12, 273.15 + 50 + 14, 273.15 + 50 + 16], 'Systemeingangstemperatur [K]']}
    #input_dict = {"bop_q" : ["",[5000, 7000, 9000, 11000, 13000], 'Wärmeeintrag BoP Komponenten [W]']}
    #input_dict = {"stack_q" : ["", [140000, 160000, 180000, 200000, 220000], 'Wärmeeintrag Stack [W]']}
    #input_dict = {"bop_vdot" : ["", [20/60, 30/60, 40/60, 50/60, 60/60], 'Volumenstrom über BoP Komponenten [l/s]']}
    #input_dict = {"bop_dp" : ["", [0.1, 0.2, 0.3, 0.4, 0.5], 'Druckverlust über die BoP Komponenten [bar]']}
else: 
    input_dict = None


# What boundary conditions do you want to set? 
bc_dict = {"pump_p_in" : 1,                     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 68.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 80.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 60.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 13000,                     # bop heat 
           "stack_q" : 158000,                  # stack heat
           "bop_vdot" : 0.5                     # flow over bop components (whole block) 30L/min
}

# Which variables should be safed in excel and be plotted
result_dict = {"pump_vdot" : ["", [], 'flow over pump1 in [l/S]'],
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],
                "radiator_vdot" : ["", [], 'flow over radiator in [l/S]'],
                "perc_recirc": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]'],
                "pump2_vdot" : ["", [], "flow over pump2 in [l/s]"],
                "pump2_delta_p" : ["", [], "pump2 pressure difference [bar]"]
}

############################################################ calculation ############################################################
excel_dict = {}
all_result_dict = {}
result_dict_new = {}
if input_dict is not None:
    for name in input_dict:
            excel_dict[input_dict[name][2]] = input_dict[name][1]

for arch in arch_list:      # each architecture is evaluated
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict_new = eval(key_init)
    result_dict_new = circ.analyse_arch(input_dict, result_dict_new)

    for name in result_dict_new:    # rewrite results in one dictionary
        all_result_dict["%s_%s"%(arch,name)] = [result_dict_new[name][0], result_dict_new[name][1], result_dict_new[name][2]]
        excel_dict["%s_%s"%(arch,name)] = result_dict_new[name][1]

data = pd.DataFrame(excel_dict)
datatoexcel = pd.ExcelWriter('results.xlsx')
data.to_excel(datatoexcel)
datatoexcel.close()

if vary_bc is True and compare_res is False:
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