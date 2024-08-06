import scipy.optimize as sp
import ast
import numpy as np

# Definition of classes and functions

class Circuit:
    def __init__(self):
        self.eq_list = []
        self.eq_list_sorted = []
        self.var_list = []
    

    def add_comp(self, comp):
        self.eq_list.append(comp.set_eq())


    def add_bc(self, bc):
        self.eq_list.append([bc])
    

    def sort_eq(self):
        self.eq_list = sum(self.eq_list, [])
        
        for eq in self.eq_list:
            start, end = eq.split("=")
            self.eq_list_sorted.append("(" + start + ") - (" + end + ")")
    

    def get_var(self):
        for eq in self.eq_list_sorted:
            eq_parsed = ast.parse(eq)
            for var in ast.walk(eq_parsed):
                if isinstance(var, ast.Name):
                    self.var_list.append(var.id)
        
        self.var_list = sorted(set(self.var_list))
    

    def calculate_res(self, variables):
        for i in range(len(self.var_list)):
            globals()[self.var_list[i]] = variables[i]
        self.eq_list_eval = []

        for eq in self.eq_list_sorted:
            self.eq_list_eval.append(eval(eq))

        return self.eq_list_eval


class Pump:
    def __init__(self, p_in, p_out, delta_p):
        self.p_in = p_in
        self.p_out = p_out
        self.delta_p = delta_p


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        return[self.eq1]


class Heatsource:
    def __init__(self, p_in, p_out, delta_p):
        self.p_in = p_in
        self.p_out = p_out
        self.delta_p = delta_p


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        return[self.eq1]


class Splitter:
    def __init__(self, p_in, p_out_1, p_out_2):
        self.p_in = p_in
        self.p_out_1 = p_out_1
        self.p_out_2 = p_out_2


    def set_eq(self):
        self.eq1 = "%s = %s"%(self.p_in, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in, self.p_out_2)
        return[self.eq1, self.eq2]


class Mixer:
    def __init__(self, p_in_1, p_in_2, p_out):
        self.p_in_1 = p_in_1
        self.p_in_2 = p_in_2
        self.p_out = p_out


    def set_eq(self):
        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out)
        return[self.eq1, self.eq2]


# Input on architecture

circ = Circuit()
pump1 = Pump("p_6", "p_1", "delta_p_pump1")
circ.add_comp(pump1)
splitter1 = Splitter("p_1", "p_2", "p_4")
circ.add_comp(splitter1)
stack1 = Heatsource("p_2", "p_3", "delta_p_stack1")
circ.add_comp(stack1)
comp1 = Heatsource("p_4", "p_5", "delta_p_comp1")
circ.add_comp(comp1)
mixer1 = Mixer("p_3", "p_5", "p_6")
circ.add_comp(mixer1)


# Input on boundary conditions

circ.add_bc("p_6 = 1")
circ.add_bc("delta_p_stack1 = - 2")


# Evaluation

circ.sort_eq()

print(circ.eq_list_sorted)

circ.get_var()

print(circ.var_list)

solution = sp.fsolve(circ.calculate_res, np.ones(len(circ.var_list)), args=())

for i in range(len(circ.var_list)):
    print("%15s = %8.2f"%(circ.var_list[i], solution[i]))