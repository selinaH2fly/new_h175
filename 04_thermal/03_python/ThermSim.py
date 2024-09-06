"""
This script contains the classes and working functions used for thermal simulations.
"""


import scipy.optimize as sp
import ast
import numpy as np
import CoolProp.CoolProp as cp
import matplotlib.pyplot as plt
import pandas as pd



class Circuit:
    """
    Set up a closed circuit to evaluate thermal properties across multiple connected components.
    """

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

        self.eq_unsorted_start = []
        self.eq_sorted_start = []
        self.var_name_start = []
        self.var_init_start = []
        self.var_min_start = []
        self.var_max_start = []
        self.var_unit_start = []
        self.var_removal_start = []
        self.var_replacement_start = []
        self.var_res_start = []
    

    def add_comp(self, comp):
        """
        Add component to circuit.
        
        Args:
        - comp: A previsouly defined component to be added to the circuit.
        """
        
        self.eq_unsorted.append(comp.set_eq())

        for var in comp.set_var():
            if var[0] not in self.var_name:
                self.var_name.append(var[0])
                self.var_init.append(var[1])
                self.var_min.append(var[2])
                self.var_max.append(var[3])
                self.var_unit.append(var[4])


    def add_bc(self, bc):
        """
        Add boundary condition to definition of circuit.

        Args:
        - bc: A string describing a boundary condition in the form of an equation describing a correlation of circuit components' variables.
        """
        
        self.eq_unsorted.append([bc])


    def sort_eq(self):
        """
        Sort all equations defined for the circuit.
        """
        
        self.eq_unsorted = sum(self.eq_unsorted, [])


    def sort_var(self):
        """
        Sort all variables defined for the circuit.
        """
        
        self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit = [list(a) for a in zip(*sorted(zip(self.var_name, self.var_init, self.var_min, self.var_max, self.var_unit)))]
    

    def reduce_var(self):
        """
        Reduce variables defined for the circuit by removing and replacing variables that are kept constant over components or in boundary conditions, leading to a decrease in number of variables and equations for improved convergence.
        """
        
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
        """
        Convert all equations defined for the circuit to the format required for the numeric solver.
        """
        
        for eq in self.eq_unsorted:
            start, end = eq.split("=")
            self.eq_sorted.append("(" + start + ") - (" + end + ")")
    

    def calculate_res(self, variables):
        """
        Set up the equation system required for the numeric solver by setting up the variables and evaluating the equation strings.

        Args:
        - variables: List of (unknown) variables for equation system.

        Returns::
        - eq_sorted_eval: Equation system to be solved with dependency from variables.
        """
        
        for i in range(len(self.var_name)):
            globals()[self.var_name[i]] = variables[i]
        
        self.eq_sorted_eval = []

        for eq in self.eq_sorted:
            self.eq_sorted_eval.append(eval(eq))

        return self.eq_sorted_eval
    

    def extend_var(self):
        """
        Extend variables defined for the circuit by re-integrating previously removed and replaced variables that are kept constant over components or in boundary conditions.
        """
        
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
        """
        Evaluate thermal properties across the circuit by organizing equations and variables, numerically solving equation system and providing output on result.
        """
        self.save_startcond()

        self.sort_eq()

        self.sort_var()

        self.reduce_var()

        self.convert_eq()

        if len(self.eq_sorted) < len(self.var_name):
            print("ERROR! Equation system is underdetermined (%i equations for %s variables). Set additional boundary conditions."%(len(self.eq_sorted), len(self.var_name)))
            exit()
        elif len(self.eq_sorted) > len(self.var_name):
            print("WARNING! Equation system may be overdetermined (%i equations for %s variables)."%(len(self.eq_sorted), len(self.var_name)))

        self.solution = sp.least_squares(self.calculate_res, np.array(self.var_init), max_nfev=100000, gtol=1e-10, xtol=1e-12, bounds=(np.array(self.var_min), np.array(self.var_max)))

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

    def reset_to_startcond(self):
        self.eq_unsorted = self.eq_unsorted_start
        self.eq_sorted = []
        self.var_name = self.var_name_start
        self.var_init = self.var_init_start
        self.var_min = self.var_min_start
        self.var_max = self.var_max_start
        self.var_unit = self.var_unit_start 
        self.var_removal = [] #self.var_removal_start
        self.var_replacement = [] # self.var_replacement_start
        self.var_res = []
        self.eq_sorted_eval = []
    

    def save_startcond(self):
        self.eq_unsorted_start = self.eq_unsorted
        self.eq_sorted_start = self.eq_sorted
        self.var_name_start = self.var_name
        self.var_init_start = self.var_init
        self.var_min_start = self.var_min
        self.var_max_start = self.var_max
        self.var_unit_start = self.var_unit 
        self.var_removal_start = self.var_removal
        self.var_replacement_start = self.var_replacement
        self.var_res_start = self.var_res

    
    def analyse_vdot_temp_pr(self, input_list, result_vdot_dict, result_temp_dict, result_pr_dict):
        for i in range(len(self.eq_unsorted)):
            if '%s = ' %(input_list[0]) in self.eq_unsorted[i][0]:
                k = i
        
        for y in input_list[1]:
            self.eq_unsorted[k] = ['%s = %f' %(input_list[0], y)]
            self.evaluate()

            for j in range(len(self.var_name)):
                for vdot_name in result_vdot_dict:
                    if self.var_name[j] == vdot_name:
                        result_vdot_dict[vdot_name][1].append(self.var_res[j])
                for temp_name in result_temp_dict:
                    if self.var_name[j] == temp_name:
                        result_temp_dict[temp_name][1].append(self.var_res[j])
                for pr_name in result_pr_dict:
                    if self.var_name[j] == pr_name and 'delta_p' not in self.var_name[j]:
                        result_pr_dict[pr_name][1].append(1 - self.var_res[j])          # absolute pressure converts to pressure drop
                    elif self.var_name[j] == pr_name:
                        result_pr_dict[pr_name][1].append( - self.var_res[j])
                
            self.reset_to_startcond()

        for vdot_name in result_vdot_dict:
            plt.plot(input_list[1], result_vdot_dict[vdot_name][1], label=result_vdot_dict[vdot_name][0])
        plt.ylabel('Flow in Branches in [l/s]')
        plt.xlabel(input_list[2])
        plt.legend()
        plt.grid()
        plt.show()
        for temp_name in result_temp_dict:
            plt.plot(input_list[1], result_temp_dict[temp_name][1], label=result_temp_dict[temp_name][0])
        plt.ylabel('Temperature in [K]')
        plt.xlabel(input_list[2])
        plt.legend(loc = 'lower right')
        plt.grid()
        plt.show()
        for pr_name in result_pr_dict:
            plt.plot(input_list[1], result_pr_dict[pr_name][1], label=result_pr_dict[pr_name][0])
        plt.ylabel('BoP Pressuredrop in [bar]')
        plt.xlabel(input_list[2])
        plt.legend()
        plt.grid()
        plt.show()

        data_dict = {}
        data_dict[input_list[0]] = input_list[1]
        for vdot_name in result_vdot_dict:
            data_dict[result_vdot_dict[vdot_name][0]] = result_vdot_dict[vdot_name][1]
        for temp_name in result_temp_dict:
            data_dict[result_temp_dict[temp_name][0]] = result_temp_dict[temp_name][1]
        for pr_name in result_pr_dict:
            data_dict[result_pr_dict[pr_name][0]] = result_pr_dict[pr_name][1]
        data = pd.DataFrame(data_dict)
        datatoexcel = pd.ExcelWriter('results.xlsx')
        data.to_excel(datatoexcel)
        datatoexcel.close()


    def eveluate_big_arch(self, result_dict):
        self.evaluate()

        for j in range(len(self.var_name)):
                for result_name in result_dict:
                    if self.var_name[j] == result_name:
                        result_dict[result_name][1].append(self.var_res[j])

        data_dict = {}
        for result_name in result_dict:
            data_dict[result_dict[result_name][0]] = result_dict[result_name][1]
        data = pd.DataFrame(data_dict)
        datatoexcel = pd.ExcelWriter('results.xlsx')
        data.to_excel(datatoexcel)
        datatoexcel.close()


    def analyse_big_arch(self, input_list, result_dict):
        for i in range(len(self.eq_unsorted)):
            if '%s = ' %(input_list[0]) in self.eq_unsorted[i][0]:
                k = i
        
        for y in input_list[1]:
            self.eq_unsorted[k] = ['%s = %f' %(input_list[0], y)]
            self.evaluate()

            for j in range(len(self.var_name)):
                for result_name in result_dict:
                    if self.var_name[j] == result_name:
                        result_dict[result_name][1].append(self.var_res[j])

            self.reset_to_startcond()

        for result_name in result_dict:
            plt.plot(input_list[1], result_dict[result_name][1], label=result_dict[result_name][0])
            plt.ylabel(result_dict[result_name][0])
            plt.xlabel(input_list[2])
            plt.legend()
            plt.grid()
            plt.show()

        data_dict = {}
        data_dict[input_list[0]] = input_list[1]
        for result_name in result_dict:
            data_dict[result_dict[result_name][0]] = result_dict[result_name][1]
        data = pd.DataFrame(data_dict)
        datatoexcel = pd.ExcelWriter('results.xlsx')
        data.to_excel(datatoexcel)
        datatoexcel.close()
        
        

class NodeRenamer(ast.NodeTransformer):
    """
    Rename node in AST to replace variable.

    Args:
    - var1: String of variable name to be replaced.
    - var2: String of variable name to replace.
    """
    
    def __init__(self, var1, var2):
        ast.NodeTransformer.__init__(self)
        self.var1 = var1
        self.var2 = var2


    def visit_Name(self, node):
        """
        Rename node in AST to replace variable.

        Returns:
        - node: Renamed node in AST.
        """

        if node.id == self.var1:
            node.id = self.var2

        return node


class Pump:
    """
    Set up a component with pump characteristics:
    - pressure increase
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """
    
    def __init__(self, i_in, i_out, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.delta_p = "delta_p_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics.
        - eq2: Equation for thermal energy flux characteristics.
        - eq3: Equation for mass flow characteristics.
        """
        
        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s"%(self.T_in, self.T_out)
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for pressure change over component.
        """
        
        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, 1.0, 0.0, np.inf, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7]


class Throttle:
    """
    Set up a component with throttle characteristics:
    - pressure decrease
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.delta_p = "delta_p_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics.
        - eq2: Equation for thermal energy flux characteristics.
        - eq3: Equation for mass flow characteristics.
        """

        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s"%(self.T_in, self.T_out)
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for pressure change over component.
        """

        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7]


class Heatsource:
    """
    Set up a component with heatsource characteristics:
    - pressure decrease
    - thermal energy flux increase
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.delta_p = "delta_p_%s"%(comp_name)
        self.Qdot = "Qdot_%s"%(comp_name)
        self.c_p_in = "c_p_in_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics.
        - eq2: Equation for thermal energy flux characteristics.
        - eq3: Equation for mass flow characteristics.
        - eq4: Equation for specific heat capacity of coolant at input.
        - eq5: Equation for specific heat capacity of coolant at output.
        """

        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s * %s / %s - %s / (%s * %s)"%(self.T_in, self.T_out, self.c_p_out, self.c_p_in, self.Qdot, self.Vdot_in, self.c_p_in)
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        self.eq4 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in, self.T_in, self.p_in)
        self.eq5 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for pressure change over component.
        - var8: Name string, initialization value, minimum, maximum and unit string for thermal energy flux change over component.
        - var9: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input.
        - var10: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        """

        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        self.var8 = [self.Qdot, 10000.0, 0.0, np.inf, "W"]
        self.var9 = [self.c_p_in, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var10 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10]


class Heatsink:
    """
    Set up a component with heatsink characteristics:
    - pressure decrease
    - thermal energy flux decrease
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.delta_p = "delta_p_%s"%(comp_name)
        self.Qdot = "Qdot_%s"%(comp_name)
        self.c_p_in = "c_p_in_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics.
        - eq2: Equation for thermal energy flux characteristics.
        - eq3: Equation for mass flow characteristics.
        - eq4: Equation for specific heat capacity of coolant at input.
        - eq5: Equation for specific heat capacity of coolant at output.
        """

        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out, self.delta_p)
        self.eq2 = "%s = %s * %s / %s - %s / (%s * %s)"%(self.T_in, self.T_out, self.c_p_out, self.c_p_in, self.Qdot, self.Vdot_in, self.c_p_in)
        self.eq3 = "%s = %s"%(self.Vdot_in, self.Vdot_out)
        self.eq4 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in, self.T_in, self.p_in)
        self.eq5 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for pressure change over component.
        - var8: Name string, initialization value, minimum, maximum and unit string for thermal energy flux change over component.
        - var9: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input.
        - var10: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        """

        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.delta_p, - 1.0, - np.inf, 0.0, "bar"]
        self.var8 = [self.Qdot, - 10000.0, - np.inf, 0.0, "W"]
        self.var9 = [self.c_p_in, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var10 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10]


class ConnectorPassive1to2:
    """
    Set up a component with splitter characteristics for 1 input and 2 outputs without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out_1: Integer for identifier of output 1.
    - i_out_2: Integer for identifier of output 2.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out_1, i_out_2, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out_1 = "p_%i"%(i_out_1)
        self.T_out_1 = "T_%i"%(i_out_1)
        self.Vdot_out_1 = "Vdot_%i"%(i_out_1)
        self.p_out_2 = "p_%i"%(i_out_2)
        self.T_out_2 = "T_%i"%(i_out_2)
        self.Vdot_out_2 = "Vdot_%i"%(i_out_2)
        self.nsplit_1 = "nsplit_1_%s"%(comp_name)
        self.nsplit_2 = "nsplit_2_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input and output 1.
        - eq2: Equation for pressure characteristics between input and output 2.
        - eq3: Equation for thermal energy flux characteristics between input and output 1.
        - eq4: Equation for thermal energy flux characteristics between input and output 2.
        - eq5: Equation for mass flow characteristics.
        - eq6: Equation for splitting ration characteristics of output 1.
        - eq7: Equation for splitting ration characteristics of output 2.
        """

        self.eq1 = "%s = %s"%(self.p_in, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in, self.p_out_2)
        self.eq3 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq5 = "%s = %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2)
        self.eq6 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq7 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output 1 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output 1 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output 1 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output 2 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output 2 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output 2 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output 1 splitting ratio.
        - var11: Name string, initialization value, minimum, maximum and unit string for output 2 splitting ratio.
        """

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


class ConnectorActive1to2:
    """
    Set up a component with splitter characteristics for 1 input and 2 outputs with active control:
    - pressure decrease (individually for both outputs)
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out_1: Integer for identifier of output 1.
    - i_out_2: Integer for identifier of output 2.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out_1, i_out_2, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out_1 = "p_%i"%(i_out_1)
        self.T_out_1 = "T_%i"%(i_out_1)
        self.Vdot_out_1 = "Vdot_%i"%(i_out_1)
        self.p_out_2 = "p_%i"%(i_out_2)
        self.T_out_2 = "T_%i"%(i_out_2)
        self.Vdot_out_2 = "Vdot_%i"%(i_out_2)
        self.nsplit_1 = "nsplit_1_%s"%(comp_name)
        self.nsplit_2 = "nsplit_2_%s"%(comp_name)
        self.delta_p_1 = "delta_p_1_%s"%(comp_name)
        self.delta_p_2 = "delta_p_2_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input and output 1.
        - eq2: Equation for pressure characteristics between input and output 2.
        - eq3: Equation for thermal energy flux characteristics between input and output 1.
        - eq4: Equation for thermal energy flux characteristics between input and output 2.
        - eq5: Equation for mass flow characteristics.
        - eq6: Equation for splitting ration characteristics of output 1.
        - eq7: Equation for splitting ration characteristics of output 2.
        """

        self.eq1 = "%s = %s - %s"%(self.p_in, self.p_out_1, self.delta_p_1)
        self.eq2 = "%s = %s - %s"%(self.p_in, self.p_out_2, self.delta_p_2)
        self.eq3 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq5 = "%s = %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2)
        self.eq6 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq7 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output 1 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output 1 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output 1 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output 2 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output 2 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output 2 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output 1 splitting ratio.
        - var11: Name string, initialization value, minimum, maximum and unit string for output 2 splitting ratio.
        - var12: Name string, initialization value, minimum, maximum and unit string for pressure change over component of output 1.
        - var13: Name string, initialization value, minimum, maximum and unit string for pressure change over component of output 2.
        """

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


class ConnectorPassive2to1:
    """
    Set up a component with mixer characteristics for 2 inputs and 1 output without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in_1: Integer for identifier of input 1.
    - i_in_2: Integer for identifier of input 2.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in_1, i_in_2, i_out, comp_name):
        self.p_in_1 = "p_%i"%(i_in_1)
        self.T_in_1 = "T_%i"%(i_in_1)
        self.Vdot_in_1 = "Vdot_%i"%(i_in_1)
        self.p_in_2 = "p_%i"%(i_in_2)
        self.T_in_2 = "T_%i"%(i_in_2)
        self.Vdot_in_2 = "Vdot_%i"%(i_in_2)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.c_p_in_1 = "c_p_in_1_%s"%(comp_name)
        self.c_p_in_2 = "c_p_in_2_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)
        self.nmix_1 = "nmix_1_%s"%(comp_name)
        self.nmix_2 = "nmix_2_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input 1 and output.
        - eq2: Equation for pressure characteristics between input 2 and output.
        - eq3: Equation for thermal energy flux characteristics between input 1, input 2 and output.
        - eq4: Equation for mass flow characteristics.
        - eq5: Equation for specific heat capacity of coolant at input 1.
        - eq6: Equation for specific heat capacity of coolant at input 2.
        - eq7: Equation for specific heat capacity of coolant at output.
        - eq8: Equation for mixing ration characteristics of input 1.
        - eq9: Equation for mixing ration characteristics of input 2.
        """

        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out)
        self.eq3 = "%s = %s * %s * %s / %s + %s * %s * %s / %s"%(self.T_out, self.T_in_1, self.nmix_1, self.c_p_in_1, self.c_p_out, self.T_in_2, self.nmix_2, self.c_p_in_2, self.c_p_out)
        self.eq4 = "%s = %s + %s"%(self.Vdot_out, self.Vdot_in_1, self.Vdot_in_2)
        self.eq5 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_1, self.T_in_1, self.p_in_1)
        self.eq6 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_2, self.T_in_2, self.p_in_2)
        self.eq7 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        self.eq8 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq9 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input 1 pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input 1 temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input 1 volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for input 2 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for input 2 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for input 2 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 1.
        - var11: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 2.
        - var12: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        - var13: Name string, initialization value, minimum, maximum and unit string for input 1 mixing ratio.
        - var14: Name string, initialization value, minimum, maximum and unit string for input 2 mixing ratio.
        """

        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.c_p_in_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var11 = [self.c_p_in_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var12 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var13 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var14 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14]


class ConnectorActive2to1:
    """
    Set up a component with mixer characteristics for 2 inputs and 1 output with active control:
    - pressure decrease (individually for both inputs)
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in_1: Integer for identifier of input 1.
    - i_in_2: Integer for identifier of input 2.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in_1, i_in_2, i_out, comp_name):
        self.p_in_1 = "p_%i"%(i_in_1)
        self.T_in_1 = "T_%i"%(i_in_1)
        self.Vdot_in_1 = "Vdot_%i"%(i_in_1)
        self.p_in_2 = "p_%i"%(i_in_2)
        self.T_in_2 = "T_%i"%(i_in_2)
        self.Vdot_in_2 = "Vdot_%i"%(i_in_2)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.c_p_in_1 = "c_p_in_1_%s"%(comp_name)
        self.c_p_in_2 = "c_p_in_2_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)
        self.nmix_1 = "nmix_1_%s"%(comp_name)
        self.nmix_2 = "nmix_2_%s"%(comp_name)
        self.delta_p_1 = "delta_p_1_%s"%(comp_name)
        self.delta_p_2 = "delta_p_2_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input 1 and output.
        - eq2: Equation for pressure characteristics between input 2 and output.
        - eq3: Equation for thermal energy flux characteristics between input 1, input 2 and output.
        - eq4: Equation for mass flow characteristics.
        - eq5: Equation for specific heat capacity of coolant at input 1.
        - eq6: Equation for specific heat capacity of coolant at input 2.
        - eq7: Equation for specific heat capacity of coolant at output.
        - eq8: Equation for mixing ration characteristics of input 1.
        - eq9: Equation for mixing ration characteristics of input 2.
        """

        self.eq1 = "%s = %s - %s"%(self.p_in_1, self.p_out, self.delta_p_1)
        self.eq2 = "%s = %s - %s"%(self.p_in_2, self.p_out, self.delta_p_2)
        self.eq3 = "%s = %s * %s * %s / %s + %s * %s * %s / %s"%(self.T_out, self.T_in_1, self.nmix_1, self.c_p_in_1, self.c_p_out, self.T_in_2, self.nmix_2, self.c_p_in_2, self.c_p_out)
        self.eq4 = "%s = %s + %s"%(self.Vdot_out, self.Vdot_in_1, self.Vdot_in_2)
        self.eq5 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_1, self.T_in_1, self.p_in_1)
        self.eq6 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_2, self.T_in_2, self.p_in_2)
        self.eq7 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        self.eq8 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq9 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input 1 pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input 1 temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input 1 volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for input 2 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for input 2 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for input 2 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 1.
        - var11: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 2.
        - var12: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        - var13: Name string, initialization value, minimum, maximum and unit string for input 1 mixing ratio.
        - var14: Name string, initialization value, minimum, maximum and unit string for input 2 mixing ratio.
        - var15: Name string, initialization value, minimum, maximum and unit string for pressure change over component of input 1.
        - var16: Name string, initialization value, minimum, maximum and unit string for pressure change over component of input 2.
        """

        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.c_p_in_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var11 = [self.c_p_in_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var12 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var13 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var14 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        self.var15 = [self.delta_p_1, - 1.0, - np.inf, 0.0, "bar"]
        self.var16 = [self.delta_p_2, - 1.0, - np.inf, 0.0, "bar"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15, self.var16]


class ConnectorPassive1to3:
    """
    Set up a component with splitter characteristics for 1 input and 3 outputs without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out_1: Integer for identifier of output 1.
    - i_out_2: Integer for identifier of output 2.
    - i_out_3: Integer for identifier of output 3.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out_1, i_out_2, i_out_3, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out_1 = "p_%i"%(i_out_1)
        self.T_out_1 = "T_%i"%(i_out_1)
        self.Vdot_out_1 = "Vdot_%i"%(i_out_1)
        self.p_out_2 = "p_%i"%(i_out_2)
        self.T_out_2 = "T_%i"%(i_out_2)
        self.Vdot_out_2 = "Vdot_%i"%(i_out_2)
        self.p_out_3 = "p_%i"%(i_out_3)
        self.T_out_3 = "T_%i"%(i_out_3)
        self.Vdot_out_3 = "Vdot_%i"%(i_out_3)
        self.nsplit_1 = "nsplit_1_%s"%(comp_name)
        self.nsplit_2 = "nsplit_2_%s"%(comp_name)
        self.nsplit_3 = "nsplit_3_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input and output 1.
        - eq2: Equation for pressure characteristics between input and output 2.
        - eq3: Equation for pressure characteristics between input and output 3.
        - eq4: Equation for thermal energy flux characteristics between input and output 1.
        - eq5: Equation for thermal energy flux characteristics between input and output 2.
        - eq6: Equation for thermal energy flux characteristics between input and output 3.
        - eq7: Equation for mass flow characteristics.
        - eq8: Equation for splitting ration characteristics of output 1.
        - eq9: Equation for splitting ration characteristics of output 2.
        - eq10: Equation for splitting ration characteristics of output 3.
        """

        self.eq1 = "%s = %s"%(self.p_in, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in, self.p_out_2)
        self.eq3 = "%s = %s"%(self.p_in, self.p_out_3)
        self.eq4 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq5 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq6 = "%s = %s"%(self.T_in, self.T_out_3)
        self.eq7 = "%s = %s + %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2, self.Vdot_out_3)
        self.eq8 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq9 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        self.eq10 = "%s = %s / %s"%(self.nsplit_3, self.Vdot_out_3, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9, self.eq10]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output 1 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output 1 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output 1 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output 2 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output 2 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output 2 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output 3 pressure.
        - var11: Name string, initialization value, minimum, maximum and unit string for output 3 temperature.
        - var12: Name string, initialization value, minimum, maximum and unit string for output 3 volume flow.
        - var13: Name string, initialization value, minimum, maximum and unit string for output 1 splitting ratio.
        - var14: Name string, initialization value, minimum, maximum and unit string for output 2 splitting ratio.
        - var15: Name string, initialization value, minimum, maximum and unit string for output 3 splitting ratio.
        """

        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out_1, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out_1, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out_1, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out_2, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out_2, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out_2, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.p_out_3, 1.0, 0.0, np.inf, "bar"]
        self.var11 = [self.T_out_3, 273.15, 0.0, np.inf, "K"]
        self.var12 = [self.Vdot_out_3, 1.0, 0.0, np.inf, "l/s"]
        self.var13 = [self.nsplit_1, 0.5, 0.0, 1.0, "-"]
        self.var14 = [self.nsplit_2, 0.5, 0.0, 1.0, "-"]
        self.var15 = [self.nsplit_3, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15]


class ConnectorPassive3to1:
    """
    Set up a component with mixer characteristics for 3 inputs and 1 output without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in_1: Integer for identifier of input 1.
    - i_in_2: Integer for identifier of input 2.
    - i_in_3: Integer for identifier of input 3.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in_1, i_in_2, i_in_3, i_out, comp_name):
        self.p_in_1 = "p_%i"%(i_in_1)
        self.T_in_1 = "T_%i"%(i_in_1)
        self.Vdot_in_1 = "Vdot_%i"%(i_in_1)
        self.p_in_2 = "p_%i"%(i_in_2)
        self.T_in_2 = "T_%i"%(i_in_2)
        self.Vdot_in_2 = "Vdot_%i"%(i_in_2)
        self.p_in_3 = "p_%i"%(i_in_3)
        self.T_in_3 = "T_%i"%(i_in_3)
        self.Vdot_in_3 = "Vdot_%i"%(i_in_3)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.c_p_in_1 = "c_p_in_1_%s"%(comp_name)
        self.c_p_in_2 = "c_p_in_2_%s"%(comp_name)
        self.c_p_in_3 = "c_p_in_3_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)
        self.nmix_1 = "nmix_1_%s"%(comp_name)
        self.nmix_2 = "nmix_2_%s"%(comp_name)
        self.nmix_3 = "nmix_3_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input 1 and output.
        - eq2: Equation for pressure characteristics between input 2 and output.
        - eq3: Equation for pressure characteristics between input 3 and output.
        - eq4: Equation for thermal energy flux characteristics between input 1, input 2, input 3, and output.
        - eq5: Equation for mass flow characteristics.
        - eq6: Equation for specific heat capacity of coolant at input 1.
        - eq7: Equation for specific heat capacity of coolant at input 2.
        - eq8: Equation for specific heat capacity of coolant at input 3.
        - eq9: Equation for specific heat capacity of coolant at output.
        - eq10: Equation for mixing ration characteristics of input 1.
        - eq11: Equation for mixing ration characteristics of input 2.
        - eq12: Equation for mixing ration characteristics of input 3.
        """

        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out)
        self.eq3 = "%s = %s"%(self.p_in_3, self.p_out)
        self.eq4 = "%s = %s * %s * %s / %s + %s * %s * %s / %s + %s * %s * %s / %s"%(self.T_out, self.T_in_1, self.nmix_1, self.c_p_in_1, self.c_p_out, self.T_in_2, self.nmix_2, self.c_p_in_2, self.c_p_out, self.T_in_3, self.nmix_3, self.c_p_in_3, self.c_p_out)
        self.eq5 = "%s = %s + %s + %s"%(self.Vdot_out, self.Vdot_in_1, self.Vdot_in_2, self.Vdot_in_3)
        self.eq6 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_1, self.T_in_1, self.p_in_1)
        self.eq7 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_2, self.T_in_2, self.p_in_2)
        self.eq8 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_3, self.T_in_3, self.p_in_3)
        self.eq9 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        self.eq10 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq11 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        self.eq12 = "%s = %s / %s"%(self.nmix_3, self.Vdot_in_3, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9, self.eq10, self.eq11, self.eq12]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input 1 pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input 1 temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input 1 volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for input 2 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for input 2 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for input 2 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for input 3 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for input 3 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for input 3 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var11: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var12: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var13: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 1.
        - var14: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 2.
        - var15: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 3.
        - var16: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        - var17: Name string, initialization value, minimum, maximum and unit string for input 1 mixing ratio.
        - var18: Name string, initialization value, minimum, maximum and unit string for input 2 mixing ratio.
        - var19: Name string, initialization value, minimum, maximum and unit string for input 3 mixing ratio.
        """

        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_in_3, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_in_3, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_in_3, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var11 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var12 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var13 = [self.c_p_in_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var14 = [self.c_p_in_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var15 = [self.c_p_in_3, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var16 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var17 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var18 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        self.var19 = [self.nmix_3, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15, self.var16, self.var17, self.var18, self.var19]


class ConnectorPassive2to2:
    """
    Set up a component with mixer/splitter characteristics for 2 inputs and 2 output without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in_1: Integer for identifier of input 1.
    - i_in_2: Integer for identifier of input 2.
    - i_out_1: Integer for identifier of output 1.
    - i_out_2: Integer for identifier of output 2.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in_1, i_in_2, i_out_1, i_out_2, comp_name):
        self.p_in_1 = "p_%i"%(i_in_1)
        self.T_in_1 = "T_%i"%(i_in_1)
        self.Vdot_in_1 = "Vdot_%i"%(i_in_1)
        self.p_in_2 = "p_%i"%(i_in_2)
        self.T_in_2 = "T_%i"%(i_in_2)
        self.Vdot_in_2 = "Vdot_%i"%(i_in_2)
        self.p_out_1 = "p_%i"%(i_out_1)
        self.T_out_1 = "T_%i"%(i_out_1)
        self.Vdot_out_1 = "Vdot_%i"%(i_out_1)
        self.p_out_2 = "p_%i"%(i_out_2)
        self.T_out_2 = "T_%i"%(i_out_2)
        self.Vdot_out_2 = "Vdot_%i"%(i_out_2)
        self.c_p_in_1 = "c_p_in_1_%s"%(comp_name)
        self.c_p_in_2 = "c_p_in_2_%s"%(comp_name)
        self.c_p_out_1 = "c_p_out_1_%s"%(comp_name)
        self.c_p_out_2 = "c_p_out_2_%s"%(comp_name)
        self.nmix_1 = "nmix_1_%s"%(comp_name)
        self.nmix_2 = "nmix_2_%s"%(comp_name)
        self.nsplit_1 = "nsplit_1_%s"%(comp_name)
        self.nsplit_2 = "nsplit_2_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input 1 and output 1.
        - eq2: Equation for pressure characteristics between input 2 and output 2.
        - eq3: Equation for pressure characteristics between output 1 and output 2.
        - eq4: Equation for thermal energy flux characteristics between input 1, input 2 and output 1.
        - eq5: Equation for thermal energy flux characteristics between output 1 and output 2.
        - eq6: Equation for mass flow characteristics.
        - eq7: Equation for specific heat capacity of coolant at input 1.
        - eq8: Equation for specific heat capacity of coolant at input 2.
        - eq9: Equation for specific heat capacity of coolant at output 1.
        - eq10: Equation for specific heat capacity of coolant at output 2.
        - eq11: Equation for mixing ration characteristics of input 1.
        - eq12: Equation for mixing ration characteristics of input 2.
        - eq13: Equation for splitting ration characteristics of output 1.
        - eq14: Equation for splitting ration characteristics of output 2.
        """

        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out_2)
        self.eq3 = "%s = %s"%(self.p_out_1, self.p_out_2)
        self.eq4 = "%s = %s * %s * %s / %s + %s * %s * %s / %s"%(self.T_out_1, self.T_in_1, self.nmix_1, self.c_p_in_1, self.c_p_out_1, self.T_in_2, self.nmix_2, self.c_p_in_2, self.c_p_out_1)
        self.eq5 = "%s = %s"%(self.T_out_2, self.T_out_1)
        self.eq6 = "%s = %s + %s - %s"%(self.Vdot_out_1, self.Vdot_in_1, self.Vdot_in_2, self.Vdot_out_2)
        self.eq7 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_1, self.T_in_1, self.p_in_1)
        self.eq8 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_2, self.T_in_2, self.p_in_2)
        self.eq9 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out_1, self.T_out_1, self.p_out_1)
        self.eq10 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out_2, self.T_out_2, self.p_out_2)
        self.eq11 = "%s = %s / (%s + %s)"%(self.nmix_1, self.Vdot_in_1, self.Vdot_in_1, self.Vdot_in_2)
        self.eq12 = "%s = %s / (%s + %s)"%(self.nmix_2, self.Vdot_in_2, self.Vdot_in_1, self.Vdot_in_2)
        self.eq13 = "%s = %s / (%s + %s)"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_out_1, self.Vdot_out_2)
        self.eq14 = "%s = %s / (%s + %s)"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_out_1, self.Vdot_out_2)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9, self.eq10, self.eq11, self.eq12, self.eq13, self.eq14]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input 1 pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input 1 temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input 1 volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for input 2 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for input 2 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for input 2 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output 1 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output 1 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output 1 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output 2 pressure.
        - var11: Name string, initialization value, minimum, maximum and unit string for output 2 temperature.
        - var12: Name string, initialization value, minimum, maximum and unit string for output 2 volume flow.
        - var13: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 1.
        - var14: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 2.
        - var15: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output 1.
        - var16: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output 2.
        - var17: Name string, initialization value, minimum, maximum and unit string for input 1 mixing ratio.
        - var18: Name string, initialization value, minimum, maximum and unit string for input 2 mixing ratio.
        - var19: Name string, initialization value, minimum, maximum and unit string for output 1 splitting ratio.
        - var20: Name string, initialization value, minimum, maximum and unit string for output 2 splitting ratio.
        """

        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out_1, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out_1, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out_1, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.p_out_2, 1.0, 0.0, np.inf, "bar"]
        self.var11 = [self.T_out_2, 273.15, 0.0, np.inf, "K"]
        self.var12 = [self.Vdot_out_2, 1.0, 0.0, np.inf, "l/s"]
        self.var13 = [self.c_p_in_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var14 = [self.c_p_in_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var15 = [self.c_p_out_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var16 = [self.c_p_out_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var17 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var18 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        self.var19 = [self.nsplit_1, 0.5, 0.0, 1.0, "-"]
        self.var20 = [self.nsplit_2, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15, self.var16, self.var17, self.var18, self.var19, self.var20]
    

class ConnectorPassive1to4:
    """
    Set up a component with splitter characteristics for 1 input and 4 outputs without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in: Integer for identifier of input.
    - i_out_1: Integer for identifier of output 1.
    - i_out_2: Integer for identifier of output 2.
    - i_out_3: Integer for identifier of output 3.
    - i_out_4: Integer for identifier of output 4.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in, i_out_1, i_out_2, i_out_3, i_out_4, comp_name):
        self.p_in = "p_%i"%(i_in)
        self.T_in = "T_%i"%(i_in)
        self.Vdot_in = "Vdot_%i"%(i_in)
        self.p_out_1 = "p_%i"%(i_out_1)
        self.T_out_1 = "T_%i"%(i_out_1)
        self.Vdot_out_1 = "Vdot_%i"%(i_out_1)
        self.p_out_2 = "p_%i"%(i_out_2)
        self.T_out_2 = "T_%i"%(i_out_2)
        self.Vdot_out_2 = "Vdot_%i"%(i_out_2)
        self.p_out_3 = "p_%i"%(i_out_3)
        self.T_out_3 = "T_%i"%(i_out_3)
        self.Vdot_out_3 = "Vdot_%i"%(i_out_3)
        self.p_out_4 = "p_%i"%(i_out_4)
        self.T_out_4 = "T_%i"%(i_out_4)
        self.Vdot_out_4 = "Vdot_%i"%(i_out_4)
        self.nsplit_1 = "nsplit_1_%s"%(comp_name)
        self.nsplit_2 = "nsplit_2_%s"%(comp_name)
        self.nsplit_3 = "nsplit_3_%s"%(comp_name)
        self.nsplit_4 = "nsplit_4_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input and output 1.
        - eq2: Equation for pressure characteristics between input and output 2.
        - eq3: Equation for pressure characteristics between input and output 3.
        - eq4: Equation for pressure characteristics between input and output 4.
        - eq5: Equation for thermal energy flux characteristics between input and output 1.
        - eq6: Equation for thermal energy flux characteristics between input and output 2.
        - eq7: Equation for thermal energy flux characteristics between input and output 3.
        - eq8: Equation for thermal energy flux characteristics between input and output 4.
        - eq9: Equation for mass flow characteristics.
        - eq10: Equation for splitting ration characteristics of output 1.
        - eq11: Equation for splitting ration characteristics of output 2.
        - eq12: Equation for splitting ration characteristics of output 3.
        - eq13: Equation for splitting ration characteristics of output 4.
        """

        self.eq1 = "%s = %s"%(self.p_in, self.p_out_1)
        self.eq2 = "%s = %s"%(self.p_in, self.p_out_2)
        self.eq3 = "%s = %s"%(self.p_in, self.p_out_3)
        self.eq4 = "%s = %s"%(self.p_in, self.p_out_4)
        self.eq5 = "%s = %s"%(self.T_in, self.T_out_1)
        self.eq6 = "%s = %s"%(self.T_in, self.T_out_2)
        self.eq7 = "%s = %s"%(self.T_in, self.T_out_3)
        self.eq8 = "%s = %s"%(self.T_in, self.T_out_4)
        self.eq9 = "%s = %s + %s + %s + %s"%(self.Vdot_in, self.Vdot_out_1, self.Vdot_out_2, self.Vdot_out_3, self.Vdot_out_4)
        self.eq10 = "%s = %s / %s"%(self.nsplit_1, self.Vdot_out_1, self.Vdot_in)
        self.eq11 = "%s = %s / %s"%(self.nsplit_2, self.Vdot_out_2, self.Vdot_in)
        self.eq12 = "%s = %s / %s"%(self.nsplit_3, self.Vdot_out_3, self.Vdot_in)
        self.eq13 = "%s = %s / %s"%(self.nsplit_4, self.Vdot_out_4, self.Vdot_in)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9, self.eq10, self.eq11, self.eq12, self.eq13]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for output 1 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for output 1 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for output 1 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for output 2 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for output 2 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for output 2 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for output 3 pressure.
        - var11: Name string, initialization value, minimum, maximum and unit string for output 3 temperature.
        - var12: Name string, initialization value, minimum, maximum and unit string for output 3 volume flow.
        - var13: Name string, initialization value, minimum, maximum and unit string for output 4 pressure.
        - var14: Name string, initialization value, minimum, maximum and unit string for output 4 temperature.
        - var15: Name string, initialization value, minimum, maximum and unit string for output 4 volume flow.
        - var16: Name string, initialization value, minimum, maximum and unit string for output 1 splitting ratio.
        - var17: Name string, initialization value, minimum, maximum and unit string for output 2 splitting ratio.
        - var18: Name string, initialization value, minimum, maximum and unit string for output 3 splitting ratio.
        - var19: Name string, initialization value, minimum, maximum and unit string for output 4 splitting ratio.
        """

        self.var1 = [self.p_in, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_out_1, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_out_1, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_out_1, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_out_2, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_out_2, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_out_2, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.p_out_3, 1.0, 0.0, np.inf, "bar"]
        self.var11 = [self.T_out_3, 273.15, 0.0, np.inf, "K"]
        self.var12 = [self.Vdot_out_3, 1.0, 0.0, np.inf, "l/s"]
        self.var13 = [self.p_out_4, 1.0, 0.0, np.inf, "bar"]
        self.var14 = [self.T_out_4, 273.15, 0.0, np.inf, "K"]
        self.var15 = [self.Vdot_out_4, 1.0, 0.0, np.inf, "l/s"]
        self.var16 = [self.nsplit_1, 0.5, 0.0, 1.0, "-"]
        self.var17 = [self.nsplit_2, 0.5, 0.0, 1.0, "-"]
        self.var18 = [self.nsplit_3, 0.5, 0.0, 1.0, "-"]
        self.var19 = [self.nsplit_4, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15, self.var16, self.var17, self.var18, self.var19]
    

class ConnectorPassive4to1:
    """
    Set up a component with mixer characteristics for 4 inputs and 1 output without active control:
    - pressure conservation
    - thermal energy flux conservation
    - mass flow conservation

    Args:
    - i_in_1: Integer for identifier of input 1.
    - i_in_2: Integer for identifier of input 2.
    - i_in_3: Integer for identifier of input 3.
    - i_in_4: Integer for identifier of input 4.
    - i_out: Integer for identifier of output.
    - comp_name: String for name of component.
    """

    def __init__(self, i_in_1, i_in_2, i_in_3, i_in_4, i_out, comp_name):
        self.p_in_1 = "p_%i"%(i_in_1)
        self.T_in_1 = "T_%i"%(i_in_1)
        self.Vdot_in_1 = "Vdot_%i"%(i_in_1)
        self.p_in_2 = "p_%i"%(i_in_2)
        self.T_in_2 = "T_%i"%(i_in_2)
        self.Vdot_in_2 = "Vdot_%i"%(i_in_2)
        self.p_in_3 = "p_%i"%(i_in_3)
        self.T_in_3 = "T_%i"%(i_in_3)
        self.Vdot_in_3 = "Vdot_%i"%(i_in_3)
        self.p_in_4 = "p_%i"%(i_in_4)
        self.T_in_4 = "T_%i"%(i_in_4)
        self.Vdot_in_4 = "Vdot_%i"%(i_in_4)
        self.p_out = "p_%i"%(i_out)
        self.T_out = "T_%i"%(i_out)
        self.Vdot_out = "Vdot_%i"%(i_out)
        self.c_p_in_1 = "c_p_in_1_%s"%(comp_name)
        self.c_p_in_2 = "c_p_in_2_%s"%(comp_name)
        self.c_p_in_3 = "c_p_in_3_%s"%(comp_name)
        self.c_p_in_4 = "c_p_in_4_%s"%(comp_name)
        self.c_p_out = "c_p_out_%s"%(comp_name)
        self.nmix_1 = "nmix_1_%s"%(comp_name)
        self.nmix_2 = "nmix_2_%s"%(comp_name)
        self.nmix_3 = "nmix_3_%s"%(comp_name)
        self.nmix_4 = "nmix_4_%s"%(comp_name)


    def set_eq(self):
        """
        Set up equations for component.

        Returns:
        - eq1: Equation for pressure characteristics between input 1 and output.
        - eq2: Equation for pressure characteristics between input 2 and output.
        - eq3: Equation for pressure characteristics between input 3 and output.
        - eq4: Equation for pressure characteristics between input 4 and output.
        - eq5: Equation for thermal energy flux characteristics between input 1, input 2, input 3, input4 and output.
        - eq6: Equation for mass flow characteristics.
        - eq7: Equation for specific heat capacity of coolant at input 1.
        - eq8: Equation for specific heat capacity of coolant at input 2.
        - eq9: Equation for specific heat capacity of coolant at input 3.
        - eq10: Equation for specific heat capacity of coolant at input 4.
        - eq11: Equation for specific heat capacity of coolant at output.
        - eq12: Equation for mixing ration characteristics of input 1.
        - eq13: Equation for mixing ration characteristics of input 2.
        - eq14: Equation for mixing ration characteristics of input 3.
        - eq15: Equation for mixing ration characteristics of input 4.
        """

        self.eq1 = "%s = %s"%(self.p_in_1, self.p_out)
        self.eq2 = "%s = %s"%(self.p_in_2, self.p_out)
        self.eq3 = "%s = %s"%(self.p_in_3, self.p_out)
        self.eq4 = "%s = %s"%(self.p_in_4, self.p_out)
        self.eq5 = "%s = %s * %s * %s / %s + %s * %s * %s / %s + %s * %s * %s / %s + %s * %s * %s / %s"%(self.T_out, self.T_in_1, self.nmix_1, self.c_p_in_1, self.c_p_out, self.T_in_2, self.nmix_2, self.c_p_in_2, self.c_p_out, self.T_in_3, self.nmix_3, self.c_p_in_3, self.c_p_out, self.T_in_4, self.nmix_4, self.c_p_in_4, self.c_p_out)
        self.eq6 = "%s = %s + %s + %s + %s"%(self.Vdot_out, self.Vdot_in_1, self.Vdot_in_2, self.Vdot_in_3, self.Vdot_in_4)
        self.eq7 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_1, self.T_in_1, self.p_in_1)
        self.eq8 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_2, self.T_in_2, self.p_in_2)
        self.eq9 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_3, self.T_in_3, self.p_in_3)
        self.eq10 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_in_4, self.T_in_4, self.p_in_4)
        self.eq11 = "%s = cp.PropsSI('C', 'T', %s, 'P', %s * 1.0E+05, 'INCOMP::MEG-50%%')"%(self.c_p_out, self.T_out, self.p_out)
        self.eq12 = "%s = %s / %s"%(self.nmix_1, self.Vdot_in_1, self.Vdot_out)
        self.eq13 = "%s = %s / %s"%(self.nmix_2, self.Vdot_in_2, self.Vdot_out)
        self.eq14 = "%s = %s / %s"%(self.nmix_3, self.Vdot_in_3, self.Vdot_out)
        self.eq15 = "%s = %s / %s"%(self.nmix_4, self.Vdot_in_4, self.Vdot_out)
        return[self.eq1, self.eq2, self.eq3, self.eq4, self.eq5, self.eq6, self.eq7, self.eq8, self.eq9, self.eq10, self.eq11, self.eq12, self.eq13, self.eq14, self.eq15]
    

    def set_var(self):
        """
        Set up variables for component.
        
        Returns:
        - var1: Name string, initialization value, minimum, maximum and unit string for input 1 pressure.
        - var2: Name string, initialization value, minimum, maximum and unit string for input 1 temperature.
        - var3: Name string, initialization value, minimum, maximum and unit string for input 1 volume flow.
        - var4: Name string, initialization value, minimum, maximum and unit string for input 2 pressure.
        - var5: Name string, initialization value, minimum, maximum and unit string for input 2 temperature.
        - var6: Name string, initialization value, minimum, maximum and unit string for input 2 volume flow.
        - var7: Name string, initialization value, minimum, maximum and unit string for input 3 pressure.
        - var8: Name string, initialization value, minimum, maximum and unit string for input 3 temperature.
        - var9: Name string, initialization value, minimum, maximum and unit string for input 3 volume flow.
        - var10: Name string, initialization value, minimum, maximum and unit string for input 4 pressure.
        - var11: Name string, initialization value, minimum, maximum and unit string for input 4 temperature.
        - var12: Name string, initialization value, minimum, maximum and unit string for input 4 volume flow.
        - var13: Name string, initialization value, minimum, maximum and unit string for output pressure.
        - var14: Name string, initialization value, minimum, maximum and unit string for output temperature.
        - var15: Name string, initialization value, minimum, maximum and unit string for output volume flow.
        - var16: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 1.
        - var17: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 2.
        - var18: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 3.
        - var19: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at input 4.
        - var20: Name string, initialization value, minimum, maximum and unit string for specific heat capacity of coolant at output.
        - var21: Name string, initialization value, minimum, maximum and unit string for input 1 mixing ratio.
        - var22: Name string, initialization value, minimum, maximum and unit string for input 2 mixing ratio.
        - var23: Name string, initialization value, minimum, maximum and unit string for input 3 mixing ratio.
        - var24: Name string, initialization value, minimum, maximum and unit string for input 4 mixing ratio.
        """

        self.var1 = [self.p_in_1, 1.0, 0.0, np.inf, "bar"]
        self.var2 = [self.T_in_1, 273.15, 0.0, np.inf, "K"]
        self.var3 = [self.Vdot_in_1, 1.0, 0.0, np.inf, "l/s"]
        self.var4 = [self.p_in_2, 1.0, 0.0, np.inf, "bar"]
        self.var5 = [self.T_in_2, 273.15, 0.0, np.inf, "K"]
        self.var6 = [self.Vdot_in_2, 1.0, 0.0, np.inf, "l/s"]
        self.var7 = [self.p_in_3, 1.0, 0.0, np.inf, "bar"]
        self.var8 = [self.T_in_3, 273.15, 0.0, np.inf, "K"]
        self.var9 = [self.Vdot_in_3, 1.0, 0.0, np.inf, "l/s"]
        self.var10 = [self.p_in_4, 1.0, 0.0, np.inf, "bar"]
        self.var11 = [self.T_in_4, 273.15, 0.0, np.inf, "K"]
        self.var12 = [self.Vdot_in_4, 1.0, 0.0, np.inf, "l/s"]
        self.var13 = [self.p_out, 1.0, 0.0, np.inf, "bar"]
        self.var14 = [self.T_out, 273.15, 0.0, np.inf, "K"]
        self.var15 = [self.Vdot_out, 1.0, 0.0, np.inf, "l/s"]
        self.var16 = [self.c_p_in_1, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var17 = [self.c_p_in_2, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var18 = [self.c_p_in_3, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var19 = [self.c_p_in_4, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var20 = [self.c_p_out, 3500.0, 2900.0, 3700.0, "J/(kg*K)"]
        self.var21 = [self.nmix_1, 0.5, 0.0, 1.0, "-"]
        self.var22 = [self.nmix_2, 0.5, 0.0, 1.0, "-"]
        self.var23 = [self.nmix_3, 0.5, 0.0, 1.0, "-"]
        self.var24 = [self.nmix_4, 0.5, 0.0, 1.0, "-"]
        return[self.var1, self.var2, self.var3, self.var4, self.var5, self.var6, self.var7, self.var8, self.var9, self.var10, self.var11, self.var12, self.var13, self.var14, self.var15, self.var16, self.var17, self.var18, self.var19, self.var20, self.var21, self.var22, self.var23, self.var24]