import CoolProp.CoolProp as CP
from parameters import Physical_Parameters
from basic_physics import icao_atmosphere

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

    def calculate_weight(self)->float:
        # TODO: Do weight estimation here.
        # Placeholder implementation, update with actual logic
        return None
    
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

# %% Example Usage:

# Step 1: Import necessary modules
# import CoolProp.CoolProp as CP
# from parameters import Physical_Parameters
# from basic_physics import icao_atmosphere

# Step 2: Instantiate the Stack object with default parameters
# stack = Stack()

# # Step 3: Modify parameters if necessary (e.g., current_A, coolant flow, etc.)
# stack.current_A = 400

# # Step 4: Test calculate_pressure_drop_anode method
# try:
#     stack_pressure_drop_anode_Pa = stack.calculate_pressure_drop_anode()
#     print(f"Pressure drop across the anode: {stack_pressure_drop_anode_Pa*1e-5:.2f} bar")
# except Exception as e:
#     print(f"Error in calculate_pressure_drop_anode: {e}")

# # Step 5: Test calculate_pressure_drop_cooling method
# try:
#     stack.coolant_flow_m3_s = 0.002  # Example coolant flow rate
#     stack_pressure_drop_cooling_Pa = stack.calculate_pressure_drop_cooling()
#     print(f"Pressure drop across the cooling channels: {stack_pressure_drop_cooling_Pa*1e-5:.2f} bar")
# except Exception as e:
#     print(f"Error in calculate_pressure_drop_cooling: {e}")

# # Step 6: Test calculate_heat_flux method
# try:
#     heat_flux_W = stack.calculate_heat_flux()
#     print(f"Heat flux generated in the stack: {heat_flux_W:.2f} W")
# except Exception as e:
#     print(f"Error in calculate_heat_flux: {e}")

# # Step 7: Test calculate_coolant_flow method
# try:
#     coolant_flow_m3_s = stack.calculate_coolant_flow(flight_level_100ft=50)
#     print(f"Coolant flow rate: {coolant_flow_m3_s:.6f} m^3/s")
# except Exception as e:
#     print(f"Error in calculate_coolant_flow: {e}")