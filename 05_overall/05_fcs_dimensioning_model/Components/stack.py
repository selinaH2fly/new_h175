import numpy as np
class Stack:
    """
    A class to model a fuel cell stack
    """

    def __init__(self, cellcount=455, current_A=400, coolant_flow_m3_s=0.0, anode_pressure_drop_coefficients=[0, 0, 0],
                 cooling_pressure_drop_coefficients=[0, 0, 0]):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param current_A: Current in Amperes (default is 400)
        """

        self.cellcount = cellcount
        self.current_A = current_A
        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.anode_pressure_drop_coefficients = anode_pressure_drop_coefficients
        self.cooling_pressure_drop_coefficients = cooling_pressure_drop_coefficients

    def calculate_pressure_drop_anode(self)->float:
        """
        Calculate the pressure drop across the anode for a given current.
        The "model" is a simple quadratic relationship between pressure drop and current.
        """

        pressure_drop_Pa = (self.anode_pressure_drop_coefficients[0]*self.current_A**2 + 
                            self.anode_pressure_drop_coefficients[1]*self.current_A + 
                            self.anode_pressure_drop_coefficients[2])*100

        return pressure_drop_Pa
    
    def calculate_pressure_drop_cooling(self)->float:
        """
        Calculate the pressure drop across the cooling channels for a given coolant flow.
        The "model" is a simple quadratic relationship between pressure drop and coolant flow.
        """

        coolant_flow_l_min = self.coolant_flow_m3_s * 1000 * 60

        pressure_drop_Pa = (self.cooling_pressure_drop_coefficients[0]*coolant_flow_l_min**2 + 
                            self.cooling_pressure_drop_coefficients[1]*coolant_flow_l_min + 
                            self.cooling_pressure_drop_coefficients[2])*100

        return pressure_drop_Pa

    def calculate_stack_mass(self) -> float:
        """
        Calculate the stack mass as a function of the number of cells.
        The relationship is linear with a base value.
        """
        stack_mass = 0.0766 * self.cellcount + 9.2813
        return stack_mass

    def calculate_coolant_mass(self) -> float:
        """
        Calculate the coolant mass based on the number of cells.
        The relationship is linear, with mass scaling based on the cell count.
        """
        coolant_mass = self.cellcount * 7 / 455
        return coolant_mass

    def calculate_mass(self)->float:
        """
        Estimate the total mass of the stack, including both stack mass and coolant mass.
        """
        stack_mass = self.calculate_stack_mass()
        coolant_mass = self.calculate_coolant_mass()

        total_mass = stack_mass + coolant_mass
        return total_mass


# %% Example Usage:

stack = Stack()

stack.current_A = 400
stack_pressure_drop_anode_Pa = stack.calculate_pressure_drop_anode()

# print(f"Pressure drop across the anode: {stack_pressure_drop_anode_Pa*1e-5:.2f} bar")

# %% Example Usage:

stack = Stack(cellcount=400)  # You can specify different cell counts if needed


# Calculate stack mass, coolant mass, and total weight
stack_mass = stack.calculate_stack_mass()
coolant_mass = stack.calculate_coolant_mass()
total_weight = stack.calculate_mass()

