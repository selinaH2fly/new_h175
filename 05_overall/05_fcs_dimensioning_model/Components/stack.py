class Stack:
    """
    A class to model a fuel cell stack
    """

    def __init__(self, cellcount=455, current_A=400):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param current_A: Current in Amperes (default is 400)
        """

        self.cellcount = cellcount
        self.current_A = current_A
        self.anode_pressure_drop_coefficients = [4*1e-4, 9.4*1e-3, 49.7] # cf. PowerLayout, DoE Evaluation

    def calculate_pressure_drop_anode(self)->float:
        """
        Calculate the pressure drop across the anode for a given current.
        The "model" is a simple quadratic relationship between pressure drop and current.
        """

        pressure_drop_Pa = (self.anode_pressure_drop_coefficients[0]*self.current_A**2 + 
                            self.anode_pressure_drop_coefficients[1]*self.current_A + 
                            self.anode_pressure_drop_coefficients[2])*100

        return pressure_drop_Pa

    def calculate_weight(self)->float:
        # TODO: Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None

# %% Example Usage:

stack = Stack()

stack.current_A = 400
stack_pressure_drop_anode_Pa = stack.calculate_pressure_drop_anode()

# print(f"Pressure drop across the anode: {stack_pressure_drop_anode_Pa*1e-5:.2f} bar")