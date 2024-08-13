import scipy.optimize as sp
import ast
import numpy as np

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

        for var in comp.set_var():
            if var[0] not in self.var_name:
                self.var_name.append(var[0])
                self.var_init.append(var[1])
                self.var_min.append(var[2])
                self.var_max.append(var[3])
                self.var_unit.append(var[4])


    def add_bc(self, bc):
        self.eq_unsorted.append([bc])


    def sort_eq(self):
        self.eq_unsorted = sum(self.eq_unsorted, [])


    def sort_var(self):
        self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit = [list(a) for a in zip(*sorted(zip(self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit)))]
    

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
    

    def convert_eq(self):
        for eq in self.eq_unsorted:
            start, end = eq.split("=")
            self.eq_sorted.append("(" + start + ") - (" + end + ")")
    

    def calculate_res(self, variables):
        for i in range(len(self.var_name)):
            globals()[self.var_name[i]] = variables[i]
        
        self.eq_sorted_eval = []

        for eq in self.eq_sorted:
            self.eq_sorted_eval.append(eval(eq))

        return self.eq_sorted_eval
    

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
        
        self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit, self.var_res = [list(a) for a in zip(*sorted(zip(self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit, self.var_res)))]


    def evaluate(self):
        self.sort_eq()

        self.sort_var()

        if len(self.eq_unsorted) < len(self.var_name):
            print("ERROR! Equation system is underdetermined. Set additional boundary conditions.")
            exit()
        elif len(self.eq_unsorted) > len(self.var_name):
            print("WARNING! Equation system may be overdetermined.")

        self.reduce_var()

        self.convert_eq()

        self.solution = sp.least_squares(self.calculate_res, np.array(self.var_init), max_nfev=100000, gtol=1e-10, bounds=(np.array(self.var_min), np.array(self.var_max)))

        if self.solution.success == False:
            print("ERROR! No convergence could be achieved.")
            print(self.solution)
        else:
            for i in range(len(self.var_name)):
                self.var_res.append(self.solution.x[i])

            self.extend_var()
            
            print(self.solution.message)
            
            for j in range(len(self.var_name)):
                print("%20s = %12.3f %s"%(self.var_name[j], self.var_res[j], self.var_unit[j]))


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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, 1.0, 0.0, np.inf, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7]


class Throttle:
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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7]


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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        self.var8 = [self.Qdot, 10000.0, 0.0, np.inf, "W"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8]


class Heatsink:
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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        self.var8 = [self.Qdot, - 10000.0, - np.inf, 0.0, "W"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8]


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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out_1, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out_1, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out_1, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out_2, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out_2, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out_2, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.nsplit_1, 0.5, 0.0, 1.0, "-"]
        self.var11 = [self.nsplit_2, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11]


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
    

    def set_var(self):
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out_1, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out_1, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out_1, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out_2, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out_2, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out_2, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.nsplit_1, 0.5, 0.0, 1.0, "-"]
        self.var11 = [self.nsplit_2, 0.5, 0.0, 1.0, "-"]
        self.var12 = [self.delta_p_1, - 1.0, - np.inf, 0.0, "bar"]
        self.var13 = [self.delta_p_2, - 1.0, - np.inf, 0.0, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13]


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
    

    def set_var(self):
        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var11 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11]


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
    

    def set_var(self):
        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var11 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        self.var12 = [self.delta_p_1, - 1.0, - np.inf, 0.0, "bar"]
        self.var13 = [self.delta_p_2, - 1.0, - np.inf, 0.0, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13]