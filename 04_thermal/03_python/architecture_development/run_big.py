from architectures import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08, ArchShy4
import pandas as pd
import matplotlib.pyplot as plt

# Do you want to vary one boundary condition? If not no plots will be made, but results will be safed in excel.
vary_bc = True

# How do you want to plot?
# Do you want to compare results of different architectures in one plot (only has effect if vary_bc is set True)
compare_res = True

# Which Architectures do you want to evaluate? ["Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08", "ArchShy4"]
arch_list = ["ArchShy4"] #, "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08", "ArchShy4"] # ]    # which architecture should be analysed?, also possible to evaluate multiple architectures
if vary_bc is True: # Adjust Input_dict only if you want to vary a boundary condition
    # input_dict = {"Variable_Name": ["Variable_Name in Architecture", [List of Values], "Text for plotting"]}

#    input_dict = {"stack_t_out" : ["", [273.15 + 70 + 8, 273.15 + 70 + 10], 'Stackausgangstemperatur [K]']}
  #  input_dict = {"stack_t_in" : ["", [273.15 + 66, 273.15 + 68, 273.15 + 70, 273.15 + 72], 'Stackeingangstemperatur [K]']} #, 273.15 + 60 + 14, 273.15 + 60 + 16
    input_dict = {"sys_t_in" : ["", [273.15 + 50, 273.15 + 55, 273.15 + 60, 273.15 + 65], 'Systemeingangstemperatur [K]']}
    #input_dict = {"bop_q" : ["",[5000, 7000, 9000, 11000, 13000], 'Wärmeeintrag BoP Komponenten [W]']}
    # input_dict = {"stack_q" : ["", [180000, 190000, 200000, 210000, 220000], 'Wärmeeintrag Stack [W]']}    # circ.add_bc("Qdot_stack1 = %.1f"%(np.interp(600, [20, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600], [2.6, 9.7, 20.8, 33.1, 46.7, 60.5, 75.0, 90.2, 106.4, 123.6, 142.5, 162.0, 178.5], left=np.nan, right=np.nan) * 1000.0))
    #input_dict = {"bop_vdot" : ["", [20/60, 30/60, 40/60, 50/60, 60/60], 'Volumenstrom über BoP Komponenten [l/s]']}
    ###M#input_dict = {"bop_dp" : ["", [0.1, 0.2, 0.3, 0.4, 0.5], 'Druckverlust über die BoP Komponenten [bar]']}
else: 
    input_dict = None


# What boundary conditions do you want to set? 
bc_dict = {"pump_p_in" : 1,                     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 68.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 80.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 60.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 13000,                     # bop heat 
           "stack_q" : 200000,                  # stack heat
           "bop_vdot" : 0.5,                     # flow over bop components (whole block) 30L/min
           "bop_delta_p" : 1                    # choose the bop number: 10, 21,22,23,24,25,26,27,31,32,33,41 or42
}

# Which variables should be safed in excel and be plotted
result_dict = {"pump_vdot" : ["", [], 'flow over pump1 [l/S]'],
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],
                "radiator_vdot" : ["", [], 'flow over radiator [l/S]'],
                "perc_recirc": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]'],
                "pump2_vdot" : ["", [], "flow over pump2 [l/s]"],
                "pump2_delta_p" : ["", [], "pump2 pressure difference [bar]"],
                "stack_delta_p" : ["", [], "pressure loss over stack [bar]"],
                "pump_power" : ["", [], "optimal pump power [W]"],
}

############################################################ calculation ############################################################
excel_dict = {}
all_result_dict = {}
result_dict_new = {}
y = 0
if input_dict is not None:
    for name in input_dict:
            excel_dict[input_dict[name][2]] = input_dict[name][1]

for arch in arch_list:      # each architecture is evaluated
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict_new = eval(key_init)
    print("Start to evaluate architecture %s"%arch)
    result_dict_new = circ.analyse_arch(input_dict, result_dict_new)

    if "pump_vdot" in result_dict_new.keys() and "pump_delta_p" in result_dict_new.keys(): #calculates the entire pump power
        for y in range(len(result_dict_new["pump_vdot"][1])):
            result_dict_new["pump_power"][1].append(result_dict_new["pump_vdot"][1][y] * result_dict_new["pump_delta_p"][1][y] * 100)
        if "pump2_vdot" in result_dict_new.keys() and "pump2_delta_p" in result_dict_new.keys():
            for y in range(len(result_dict_new["pump2_vdot"][1])):
                result_dict_new["pump_power"][1][y] += (result_dict_new["pump2_vdot"][1][y] * result_dict_new["pump2_delta_p"][1][y] * 100)

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

def bop_delta_p(bop_arch):
    if bop_arch == 10:
        bop_delta_p = "= 2,9653E+01x2 + 9,4479E-01x"
    elif bop_arch == 21: 
        bop_delta_p = "3,5471E+00x2 + 3,2617E-01x"
    elif bop_arch == 22: 
        bop_delta_p = "2,0263E+00x2 + 2,4735E-01x"
    elif bop_arch == 23: 
        bop_delta_p = "2,7341E+00x2 + 3,1410E-01x"
    elif bop_arch == 24: 
        bop_delta_p = "4,8421E+00x2 + 4,2018E-01x"
    elif bop_arch == 25: 
        bop_delta_p = "5,5433E+00x2 + 4,0187E-01x"
    elif bop_arch == 26: 
        bop_delta_p = "6,4742E+00x2 + 4,5768E-01x"
    elif bop_arch == 27: 
        bop_delta_p = "6,4742E+00x2 + 4,5768E-01x"
    elif bop_arch == 31: 
        bop_delta_p = "= 1,0509E+00x2 + 1,6437E-01x"
    elif bop_arch == 32: 
        bop_delta_p = "= 1,0019E+00x2 + 1,6645E-01x"
    elif bop_arch == 33: 
        bop_delta_p = "1,2261E+00x2 + 1,8181E-01x"
    elif bop_arch == 41: 
        bop_delta_p = "7,8087E-01x2 + 1,3715E-01x"
    elif bop_arch == 42: 
        bop_delta_p = "7,9734E-01x2 + 1,3849E-01x"