import scipy.optimize as sp
import ast
import numpy as np

# Definition of classes and functions

class Circuit:
    def __init__(self):
        self.eq_list = []
        self.eq_list_sorted = []
        self.var_list = []
        self.var_init = []
        self.var_min = []
        self.var_max = []
        self.var_unit_list = []
    

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

        for var in self.var_list:
            if var.startswith("p_"):
                self.var_init.append(1.0)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit_list.append("bar")
            elif var.startswith("T_"):
                self.var_init.append(273.15)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit_list.append("K")
            elif var.startswith("Vdot"):
                self.var_init.append(1.0)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit_list.append("l/s")
            elif var.startswith("delta_p"):
                self.var_init.append(1.0)
                self.var_min.append(- 1000.0)
                self.var_max.append(np.inf)
                self.var_unit_list.append("bar")
            elif var.startswith("Q"):
                self.var_init.append(10000.0)
                self.var_min.append(- 10000000)
                self.var_max.append(np.inf)
                self.var_unit_list.append("W")
            elif var.startswith("nsplit"):
                self.var_init.append(0.5)
                self.var_min.append(0.0)
                self.var_max.append(1.0)
                self.var_unit_list.append("")
            elif var.startswith("nmix"):
                self.var_init.append(0.5)
                self.var_min.append(0.0)
                self.var_max.append(1.0)
                self.var_unit_list.append("")
            else:
                print("ERROR! Missing definition of initialization for variable.")
    

    def calculate_res(self, variables):
        for i in range(len(self.var_list)):
            globals()[self.var_list[i]] = variables[i]
        self.eq_list_eval = []

        for eq in self.eq_list_sorted:
            self.eq_list_eval.append(eval(eq))

        return self.eq_list_eval


class Pump:
    def __init__(self, p_in, T_in, Vdot_in, p_out, T_out, Vdot_out, delta_p):
        self.p_in = p_in
        self.T_in = T_in
        self.Vdot_in = Vdot_in
        self.p_out = p_out
        self.T_out = T_out
        self.Vdot_out = Vdot_out
        self.delta_p = delta_p


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s"%(self.T_in, self.T_out)
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3]


class Heatsource:
    def __init__(self, p_in, T_in, Vdot_in, p_out, T_out, Vdot_out, delta_p, Q):
        self.p_in = p_in
        self.T_in = T_in
        self.Vdot_in = Vdot_in
        self.p_out = p_out
        self.T_out = T_out
        self.Vdot_out = Vdot_out
        self.delta_p = delta_p
        self.Q = Q


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s - %s / (%s * 4180.0)"%(self.T_in, self.T_out, self.Q, self.Vdot_in)               #TODO: implement Glysantin properties
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3]


class Splitter:
    def __init__(self, p_in, T_in, Vdot_in, p_out_1, T_out_1, Vdot_out_1, p_out_2, T_out_2, Vdot_out_2, nsplit_1, nsplit_2):
        self.p_in = p_in
        self.T_in = T_in
        self.Vdot_in = Vdot_in
        self.p_out_1 = p_out_1
        self.T_out_1 = T_out_1
        self.Vdot_out_1 = Vdot_out_1
        self.p_out_2 = p_out_2
        self.T_out_2 = T_out_2
        self.Vdot_out_2 = Vdot_out_2
        self.nsplit_1 = nsplit_1
        self.nsplit_2 = nsplit_2


    def set_eq(self):
        self.eq1 = "%s = %s"%(self.p_in, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in, self.p_out_2)
        #self.eq3 = "%s * %s = %s * %s + %s * %s"%(self.T_in, self.Vdot_in, self.T_out_1, self.Vdot_out_1, self.T_out_2, self.Vdot_out_2)
        self.eq3 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq5 = "%s = %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2)
        self.eq6 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq7 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7]


class Mixer:
    def __init__(self, p_in_1, T_in_1, Vdot_in_1, p_in_2, T_in_2, Vdot_in_2, p_out, T_out, Vdot_out, nmix_1, nmix_2):
        self.p_in_1 = p_in_1
        self.T_in_1 = T_in_1
        self.Vdot_in_1 = Vdot_in_1
        self.p_in_2 = p_in_2
        self.T_in_2 = T_in_2
        self.Vdot_in_2 = Vdot_in_2
        self.p_out = p_out
        self.T_out = T_out
        self.Vdot_out = Vdot_out
        self.nmix_1 = nmix_1
        self.nmix_2 = nmix_2


    def set_eq(self):
        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out)
        self.eq3 = "%s * %s + %s * %s = %s * %s"%(self.T_in_1, self.Vdot_in_1, self.T_in_2, self.Vdot_in_2, self.T_out, self.Vdot_out)
        self.eq4 = "%s + %s = %s"%(self.Vdot_in_1, self.Vdot_in_2, self.Vdot_out)
        self.eq5 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq6 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6]


# Input on architecture

circ = Circuit()
pump1 = Pump("p_7", "T_7", "Vdot_7", "p_1", "T_1", "Vdot_1", "delta_p_pump1")
circ.add_comp(pump1)
splitter1 = Splitter("p_1", "T_1", "Vdot_1", "p_2", "T_2", "Vdot_2", "p_4", "T_4", "Vdot_4", "nsplit_1_splitter1", "nsplit_2_splitter1")
circ.add_comp(splitter1)
stack1 = Heatsource("p_2", "T_2", "Vdot_2", "p_3", "T_3", "Vdot_3", "delta_p_stack1", "Q_stack1")
circ.add_comp(stack1)
comp1 = Heatsource("p_4", "T_4", "Vdot_4", "p_5", "T_5", "Vdot_5", "delta_p_comp1", "Q_comp1")
circ.add_comp(comp1)
mixer1 = Mixer("p_3", "T_3", "Vdot_3", "p_5", "T_5", "Vdot_5", "p_6", "T_6", "Vdot_6", "nmix_1_mixer1", "nmix_2_mixer1")
circ.add_comp(mixer1)
rad1 = Heatsource("p_6", "T_6", "Vdot_6", "p_7", "T_7", "Vdot_7", "delta_p_rad1", "Q_rad1")
circ.add_comp(rad1)


# Input on boundary conditions

circ.add_bc("p_7 = 1.0")
circ.add_bc("T_2 = 273.15 + 60.0")
circ.add_bc("T_3 = 273.15 + 75.0")
circ.add_bc("delta_p_stack1 = - 2.0")
circ.add_bc("delta_p_rad1 = - 1.0")
circ.add_bc("Q_stack1 = 100000.0")
circ.add_bc("Q_comp1 = 5000.0")


# Evaluation

circ.sort_eq()

circ.get_var()

solution = sp.least_squares(circ.calculate_res, np.array(circ.var_init), max_nfev=100000, gtol=1e-10, bounds=(np.array(circ.var_min), np.array(circ.var_max)))

if solution.success == False:
    print("ERROR! No convergence could be achieved.")
    print(solution)
else:
    print(solution.message)
    for i in range(len(circ.var_list)):
        print("%20s = %12.3f %s"%(circ.var_list[i], solution.x[i], circ.var_unit_list[i]))