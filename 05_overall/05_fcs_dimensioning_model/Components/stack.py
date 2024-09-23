import CoolProp.CoolProp as CP
from parameters import Physical_Parameters

class Stack:
    """
    A class to model a fuel cell stack
    """

    def __init__(self, cellcount=455, current_A=400, cell_voltage_V = 0.7, 
                 coolant_flow_m3_s=0.0, anode_pressure_drop_coefficients=[0, 0, 0],
                 cooling_pressure_drop_coefficients=[0, 0, 0], 
                 temp_coolant_in_K=338.15, temp_coolant_out_K= 343.15):
        """
        Initialize the radiator with a given pressure drop and coolant flow rate.

        :param current_A: Current in Amperes (default is 400)
        """

        self.cellcount = cellcount
        self.current_A = current_A
        self.cell_voltage_V = cell_voltage_V
        self.coolant_flow_m3_s = coolant_flow_m3_s
        self.anode_pressure_drop_coefficients = anode_pressure_drop_coefficients
        self.cooling_pressure_drop_coefficients = cooling_pressure_drop_coefficients
        #
        self.temp_coolant_in_K = temp_coolant_in_K
        self.temp_coolant_out_K = temp_coolant_out_K

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
    
    def calculate_heat_flux(self) -> float:
        """
        Calculates the heat flux created by the H2 reaction


        """
        # Load the physical parameters
        params_physics = Physical_Parameters()
        
        # Calculate the heat generated in the stack TODO: account for stack radiation
        heat_flux_W = self.current_A * self.cellcount * (params_physics.hydrogen_lhv_voltage_equivalent - self.cell_voltage_V)
        
        return heat_flux_W 
        
    def calculate_coolant_flow(self, pressure_ambient_Pa):
        """
        Compute the coolant flow rate in kg/s.
        
        
        """

        heat_generated_W = self.calculate_heat_flux()

        # Calculate the heat capacity of the coolant
        #TODO: maybe move this to a component coolant in the future and use it in all cooled components...?
        coolant = "INCOMP::MEG-50%" # 50% Ethylene Glycol (MEG) and 50% Water, i.e., Glysantin
        coolant_cp_J_kgK = CP.PropsSI('C', 'T', (self.temp_coolant_in_K + self.temp_coolant_out_K) / 2, 'P', pressure_ambient_Pa, coolant)

        # Calculate the coolant flow rate
        coolant_flow_kg_s = heat_generated_W / (coolant_cp_J_kgK * (self.temp_coolant_out_K - self.temp_coolant_in_K))
        coolant_flow_m3_s = coolant_flow_kg_s / CP.PropsSI('D', 'T', (self.temp_coolant_in_K + self.temp_coolant_out_K) / 2, 'P', pressure_ambient_Pa, coolant)

        return coolant_flow_m3_s