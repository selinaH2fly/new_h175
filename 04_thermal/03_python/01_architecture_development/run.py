import Arch01, Arch03a, Arch03b, Arch04, Arch05, Arch06, Arch08
arch_list = ["Arch01", "Arch03a", "Arch03b", "Arch04", "Arch05", "Arch06", "Arch08",]      # which architecture should be eveluated?, also possible to evaluate multiple architectures

# input
pump_p_in = 1       # pressure before pump, lowest pressure level

stack_t_in = 273.15 + 70.0              # temperature at stack inlet
stack_t_out = 273.15 + 85.0             # temperature at stack outlet
sys_t_in = 273.15 + 65.0                # System entry temperature, temperature after external radiatior

bop_q = 10600               # bop heat 
stack_q = 158000            # stack heat

bop_vdot = 0.4          # flow over bop components (whole block)

#calculation
for y in arch_list:
    key_init = "%s.initialize(%f, %f, %f, %f, %f, %f, %f)" %(y, pump_p_in, stack_t_in, stack_t_out, sys_t_in, bop_q, stack_q, bop_vdot)
    circ, result_dict = eval(key_init)
    circ.evaluate_big_arch(result_dict)



