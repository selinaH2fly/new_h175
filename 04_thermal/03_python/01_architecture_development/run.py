import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08
arch_list = ["Arch01"]      # which architecture should be eveluated?, also possible to evaluate multiple architectures
input_dict = {}             # input_dict is not needed


result_dict = {"pump_vdot" : ["", [], 'flow over pump1 in [l/S]'],              # these variable will be saved in excel file result.xlsx
                "pump_delta_p" : ["", [],'pump pressure difference [bar]'],     # to save an additional variable, there have to be made changes to arch...py files
                "radiator_vdot" : ["", [], 'flow over radiator in [l/S]'],
                "perc_rec": ["", [], 'Percentage recirculated'],
                "radiator_t_in" : ["", [],'System Output Temperature [K]']
}


# input
bc_dict = {"pump_p_in" : 1,     # pressure before pump, lowest pressure level
           "stack_t_in" : 273.15 + 70.0,        # temperature at stack inlet
           "stack_t_out" : 273.15 + 85.0,       # temperature at stack outlet
           "sys_t_in" : 273.15 + 65.0,          # System entry temperature, temperature after external radiatior
           "bop_q" : 10600,             # bop heat 
           "stack_q" : 158000,          # stack heat
           "bop_vdot" : 0.4             # flow over bop components (whole block)
}


#calculation
for y in arch_list:
    key_init = "%s.initialize(%s, %s, %s)" %(y, input_dict, result_dict, bc_dict)
    circ, input_variable, result_dict = eval(key_init)
    circ.evaluate_big_arch(result_dict)



