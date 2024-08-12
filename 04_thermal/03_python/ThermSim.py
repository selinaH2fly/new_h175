import scipy.optimize as sp
import ast
import numpy as np

# Definition of classes and functions

class Circuit:
    def __init__(self):
        self.eq_unsorted = []
        self.eq_sorted = []
        self.var_name = []
        self.var_init = []
        self.var_min = []
        self.var_max = []
        self.var_unit = []
        self.var_removal = []
        self.var_replacement = []
        self.var_res = []
    

    def add_comp(self, comp):
        self.eq_unsorted.append(comp.set_eq())


    def add_bc(self, bc):
        self.eq_unsorted.append([bc])
    

    def get_var(self):
        self.eq_unsorted = sum(self.eq_unsorted, [])
        
        for eq in self.eq_unsorted:
            start, end = eq.split("=")            
            eq_parsed = ast.parse("(%s) - (%s)"%(start, end))
            
            for var in ast.walk(eq_parsed):
                if isinstance(var, ast.Name):
                    self.var_name.append(var.id)
        
        self.var_name = sorted(set(self.var_name))

        for var in self.var_name:
            if var.startswith("p_"):
                self.var_init.append(1.0)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit.append("bar")
            elif var.startswith("T_"):
                self.var_init.append(273.15)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit.append("K")
            elif var.startswith("Vdot"):
                self.var_init.append(1.0)
                self.var_min.append(0.0)
                self.var_max.append(np.inf)
                self.var_unit.append("l/s")
            elif var.startswith("delta_p"):
                self.var_init.append(1.0)
                self.var_min.append(- np.inf)
                self.var_max.append(np.inf)
                self.var_unit.append("bar")
            elif var.startswith("Qdot"):
                self.var_init.append(10000.0)
                self.var_min.append(- np.inf)
                self.var_max.append(np.inf)
                self.var_unit.append("W")
            elif var.startswith("nsplit"):
                self.var_init.append(0.5)
                self.var_min.append(0.0)
                self.var_max.append(1.0)
                self.var_unit.append("")
            elif var.startswith("nmix"):
                self.var_init.append(0.5)
                self.var_min.append(0.0)
                self.var_max.append(1.0)
                self.var_unit.append("")
            else:
                print("ERROR! Missing definition of initialization for variable.")
    

    def reduce_var(self):
        restart = True

        while restart == True:
            restart = False

            for i in range(len(self.eq_unsorted)):
                start, end = self.eq_unsorted[i].split("=")
                start = start.strip()
                end = end.strip()

                if start in self.var_name and end in self.var_name:
                    var1 = start
                    var2 = end
                    self.eq_unsorted.pop(i)
                    self.var_removal.append(var1)
                    self.var_replacement.append(var2)

                    for j in range(len(self.eq_unsorted)):
                        start, end = self.eq_unsorted[j].split("=")
                        start = start.strip()
                        end = end.strip()
                        start = ast.unparse(NodeRenamer(var1, var2).visit(ast.parse(start)))
                        end = ast.unparse(NodeRenamer(var1, var2).visit(ast.parse(end)))
                        self.eq_unsorted[j] = "%s = %s"%(start, end)
                    
                    for k in range(len(self.var_name)):
                        if self.var_name[k] == var1:
                            self.var_name.pop(k)
                            self.var_init.pop(k)
                            self.var_min.pop(k)
                            self.var_max.pop(k)
                            self.var_unit.pop(k)
                            break

                    for l in range(len(self.var_replacement)):
                        if self.var_replacement[l] == var1:
                            self.var_replacement[l] = var2

                    restart = True
                    break
    

    def sort_eq(self):
        for eq in self.eq_unsorted:
            start, end = eq.split("=")
            self.eq_sorted.append("(" + start + ") - (" + end + ")")
    

    def calculate_res(self, variables):
        for i in range(len(self.var_name)):
            globals()[self.var_name[i]] = variables[i]
        
        self.eq_unsorted_eval = []

        for eq in self.eq_sorted:
            self.eq_unsorted_eval.append(eval(eq))

        return self.eq_unsorted_eval
    

    def extend_var(self):
        for i in range(len(self.var_removal)):
            for j in range(len(self.var_name)):
                if self.var_name[j] == self.var_replacement[i]:
                    self.var_name.append(self.var_removal[i])
                    self.var_init.append(self.var_init[j])
                    self.var_min.append(self.var_min[j])
                    self.var_max.append(self.var_max[j])
                    self.var_unit.append(self.var_unit[j])
                    self.var_res.append(self.var_res[j])
        
        self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit, self.var_res = zip(*sorted(zip(self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit, self.var_res)))


class NodeRenamer(ast.NodeTransformer):
    def __init__(self, var1, var2):
        ast.NodeTransformer.__init__(self)
        self.var1 = var1
        self.var2 = var2


    def visit_Name(self, node):
        if node.id == self.var1:
            node.id = self.var2

        return node


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
    def __init__(self, p_in, T_in, Vdot_in, p_out, T_out, Vdot_out, delta_p, Qdot):
        self.p_in = p_in
        self.T_in = T_in
        self.Vdot_in = Vdot_in
        self.p_out = p_out
        self.T_out = T_out
        self.Vdot_out = Vdot_out
        self.delta_p = delta_p
        self.Qdot = Qdot


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s - %s / (%s * 4180.0)"%(self.T_in, self.T_out, self.Qdot, self.Vdot_in)               #TODO: implement Glysantin properties
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3]


class SplitterPassive1to2:
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
        self.eq3 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq5 = "%s = %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2)
        self.eq6 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq7 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7]


class SplitterActive1to2:
    def __init__(self, p_in, T_in, Vdot_in, p_out_1, T_out_1, Vdot_out_1, p_out_2, T_out_2, Vdot_out_2, nsplit_1, nsplit_2, delta_p_1, delta_p_2):
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
        self.delta_p_1 = delta_p_1
        self.delta_p_2 = delta_p_2


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out_1, self.delta_p_1)
        self.eq2 = "%s = %s - %s"%(self.p_in, self.p_out_2, self.delta_p_2)
        self.eq3 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq5 = "%s = %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2)
        self.eq6 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq7 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7]


class MixerPassive2to1:
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


class MixerActive2to1:
    def __init__(self, p_in_1, T_in_1, Vdot_in_1, p_in_2, T_in_2, Vdot_in_2, p_out, T_out, Vdot_out, nmix_1, nmix_2, delta_p_1, delta_p_2):
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
        self.delta_p_1 = delta_p_1
        self.delta_p_2 = delta_p_2


    def set_eq(self):
        self.eq1 = "%s = %s - %s"%(self.p_in_1, self.p_out, self.delta_p_1)
        self.eq2 = "%s = %s - %s"%(self.p_in_2, self.p_out, self.delta_p_2)
        self.eq3 = "%s * %s + %s * %s = %s * %s"%(self.T_in_1, self.Vdot_in_1, self.T_in_2, self.Vdot_in_2, self.T_out, self.Vdot_out)
        self.eq4 = "%s + %s = %s"%(self.Vdot_in_1, self.Vdot_in_2, self.Vdot_out)
        self.eq5 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq6 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6]


# Input on architecture

circ = Circuit()
pump1 = Pump("p_7", "T_7", "Vdot_7", "p_1", "T_1", "Vdot_1", "delta_p_pump1")
circ.add_comp(pump1)
splitter1 = SplitterPassive1to2("p_1", "T_1", "Vdot_1", "p_2", "T_2", "Vdot_2", "p_4", "T_4", "Vdot_4", "nsplit_1_splitter1", "nsplit_2_splitter1")
circ.add_comp(splitter1)
stack1 = Heatsource("p_2", "T_2", "Vdot_2", "p_3", "T_3", "Vdot_3", "delta_p_stack1", "Qdot_stack1")
circ.add_comp(stack1)
comp1 = Heatsource("p_4", "T_4", "Vdot_4", "p_5", "T_5", "Vdot_5", "delta_p_comp1", "Qdot_comp1")
circ.add_comp(comp1)
mixer1 = MixerPassive2to1("p_3", "T_3", "Vdot_3", "p_5", "T_5", "Vdot_5", "p_6", "T_6", "Vdot_6", "nmix_1_mixer1", "nmix_2_mixer1")
circ.add_comp(mixer1)
rad1 = Heatsource("p_6", "T_6", "Vdot_6", "p_7", "T_7", "Vdot_7", "delta_p_rad1", "Qdot_rad1")
circ.add_comp(rad1)


# Input on boundary conditions

circ.add_bc("p_7 = 1.0")
circ.add_bc("T_2 = 273.15 + 60.0")
circ.add_bc("T_3 = 273.15 + 75.0")
circ.add_bc("delta_p_stack1 = - 2.0")
circ.add_bc("delta_p_rad1 = - 1.0")
circ.add_bc("Qdot_stack1 = 100000.0")
circ.add_bc("Qdot_comp1 = 5000.0")


# Evaluation

circ.get_var()

circ.reduce_var()

circ.sort_eq()

solution = sp.least_squares(circ.calculate_res, np.array(circ.var_init), max_nfev=100000, gtol=1e-10, bounds=(np.array(circ.var_min), np.array(circ.var_max)))


# Output

if solution.success == False:
    print("ERROR! No convergence could be achieved.")
    print(solution)
else:
    for i in range(len(circ.var_name)):
        circ.var_res.append(solution.x[i])

    circ.extend_var()
    
    print(solution.message)
    for j in range(len(circ.var_name)):
        print("%20s = %12.3f %s"%(circ.var_name[j], circ.var_res[j], circ.var_unit[j]))