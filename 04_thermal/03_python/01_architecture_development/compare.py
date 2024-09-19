from architectures import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08
import pandas as pd
import matplotlib.pyplot as plt
#, "Arch03b", "Arch04", "Arch06", "Arch08"
arch_list = ["Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08"]      # which architecture should be analysed?, also possible to evaluate multiple architectures

# input_list[0] = variable which should be adapted
# input_list[1] = Values for adjusting boundary condition
# input_list[2] = Description for axis for plotting
#273.15 + 70 + 8, 273.15 + 70 + 10, 273.15 + 70 + 12,
#, 273.15 + 70 + 12, 273.15 + 70 + 14, 273.15 + 70 + 16
input_dict = {"stack_t_out" : ["", [273.15 + 70 + 8, 273.15 + 70 + 10], 'Stackausgangstemperatur [K]']}
# input_list = ["stack_t_in" , [273.15 + 60 + 8, 273.15 + 60 + 10, 273.15 + 60 + 12, 273.15 + 60 + 14, 273.15 + 60 + 16], 'Stackeingangstemperatur [K]']
# input_list = ["sys_t_in" , [273.15 + 50 + 8, 273.15 + 50 + 10, 273.15 + 50 + 12, 273.15 + 50 + 14, 273.15 + 50 + 16], 'Systemeingangstemperatur [K]']
# input_list = ["bop_q" , [5000, 7000, 9000, 11000, 13000], 'Wärmeeintrag BoP Komponenten [W]']
# input_list = ["stack_q" , [], 'Wärmeeintrag Stack [W]']
# input_list = ["bop_vdot" , [20/60, 30/60, 40/60, 50/60, 60/60], 'Volumenstrom über BoP Komponenten [l/s]']
# input_list = ["bop_dp" , [0.1, 0.2, 0.3, 0.4, 0.5], 'Druckverlust über die BoP Komponenten [bar]']


result_dict = {"pump_vdot" : ["", [], 'flow over pump1 in [l/S]'],
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],
                "radiator_vdot" : ["", [], 'flow over radiator in [l/S]'],
                "perc_recirc": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]'],
                "pump2_vdot" : ["", [], 'flow over pump2 in [l/S]'],
                "pump2_delta_p" : ["", [],'pump2 pressure difference [bar]'],
    }

# input
bc_dict = {"pump_p_in" : 1,     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 70.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 85.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 60.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 10600,             # bop heat 
           "stack_q" : 158000,          # stack heat
           "bop_vdot" : 0.5             # flow over bop components (whole block)
}


#calculation
excel_dict = {}
for arch in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(arch, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    result_dict = circ.compare_big_arch(input_dict, result_dict)

    for name in result_dict:    # rewrite results in one dictionary
        excel_dict["%s_%s"%(arch,name)] = result_dict[name][1]
        result_dict[name][1] = []   # delete values


max_len = 0    # fills gap in excel_dict with 0, important for architectures without second pump
for name in excel_dict:
    list_len = len(excel_dict[name])
    if list_len > max_len:
        max_len = list_len
for name in excel_dict:
    while len(excel_dict[name]) < max_len:
        excel_dict[name].append(0)

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
