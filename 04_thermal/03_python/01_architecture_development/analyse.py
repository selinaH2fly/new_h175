import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08

arch_list = ["Arch01"]      # which architecture should be analysed?, also possible to evaluate multiple architectures

# input_list[0] = variable which should be adapted
# input_list[1] = Values for adjusting boundary condition
# input_list[2] = Description for axis for plotting
input_dict = {"stack_t_out" : ["", [273.15 + 70 + 8, 273.15 + 70 + 10, 273.15 + 70 + 12, 273.15 + 70 + 14, 273.15 + 70 + 16], 'Stackausgangstemperatur [K]']}
# input_list = ["stack_t_in" , [273.15 + 60 + 8, 273.15 + 60 + 10, 273.15 + 60 + 12, 273.15 + 60 + 14, 273.15 + 60 + 16], 'Stackeingangstemperatur [K]']
# input_list = ["sys_t_in" , [273.15 + 50 + 8, 273.15 + 50 + 10, 273.15 + 50 + 12, 273.15 + 50 + 14, 273.15 + 50 + 16], 'Systemeingangstemperatur [K]']
# input_list = ["bop_q" , [5000, 7000, 9000, 11000, 13000], 'Wärmeeintrag BoP Komponenten [W]']
# input_list = ["stack_q" , [], 'Wärmeeintrag Stack [W]']
# input_list = ["bop_vdot" , [20/60, 30/60, 40/60, 50/60, 60/60], 'Volumenstrom über BoP Komponenten [l/s]']
# input_list = ["bop_dp" , [0.1, 0.2, 0.3, 0.4, 0.5], 'Druckverlust über die BoP Komponenten [bar]']


# input
bc_dict = {"pump_p_in" : 1,     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 70.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 85.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 65.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 10600,             # bop heat 
           "stack_q" : 158000,          # stack heat
           "bop_vdot" : 0.4             # flow over bop components (whole block)
}

result_dict = {"pump_vdot" : ["", [], 'flow over pump1 in [l/S]'],
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],
                "radiator_vdot" : ["", [], 'flow over radiator in [l/S]'],
                "perc_rec": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]']
}

#calculation
for y in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(y, input_dict, result_dict, bc_dict)
    circ, input_dict, result_dict = eval(key_init)
    circ.analyse_big_arch(input_dict, result_dict)

