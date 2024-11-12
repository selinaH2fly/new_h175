import CoolProp.CoolProp as CP
from scipy.interpolate import interp1d
import cathode_model_run as cmr

class HeatExchanger:
    """
    A class to model the basic physics of a heat exchanger. 
    This class will later be used as a superclass for multiple heat exchanger types.
    """
    
    def __init__(self, efficiency = 1.0, effectiveness = 0.85,
                 primary_fluid = "Air", primary_mdot_in_kg_s = 0, primary_T_in_K = 293.15, primary_T_out_K = 293.15, primary_p_in_Pa = 101325,
                 coolant_fluid = "Water", coolant_mdot_in_kg_s = 0, coolant_T_in_K = 0, coolant_T_out_K = 0, coolant_p_in_Pa = 101325,
                 ALLOWED_FLUIDS = ['Water', 'Air', 'MEG', 'H2','INCOMP::MEG-50%']):
        
        self.efficiency = efficiency #TODO use it or kill it
        self.effectiveness= effectiveness #TODO use it or kill it

        # primary fluid or working fluid
        self.primary_fluid = primary_fluid
        self.primary_mdot_in_kg_s = primary_mdot_in_kg_s
        self.primary_T_in_K = primary_T_in_K
        self.primary_T_out_K = primary_T_out_K
        self.primary_p_in_Pa = primary_p_in_Pa  
        self.primary_p_out_Pa = None  
        
        # coolant fluid
        self.coolant_fluid  = coolant_fluid 
        self.coolant_mdot_in_kg_s = coolant_mdot_in_kg_s
        self.coolant_T_in_K = coolant_T_in_K
        self.coolant_T_out_K = None
        self.coolant_p_in_Pa = coolant_p_in_Pa
        self.coolant_p_out_Pa = None  
        self.ALLOWED_FLUIDS = ALLOWED_FLUIDS

        # Check the entered *_fluid strings to match the predefined Fluids for Heat Exchangers
        for fluid in [primary_fluid, coolant_fluid]:
            if fluid not in ALLOWED_FLUIDS:
                raise ValueError(f"Fluid '{fluid}' is not allowed. Choose from: {', '.join(ALLOWED_FLUIDS)}.")
    
    def calculate_specific_heat(self, T_in_K, p_in_Pa, fluid) -> float:
        """
        Calculate the specific heat capacity of a fluid at a given temperature using CoolProp.
        
        Args:
            T_in_K: float of Temperature in Kelvin.
            p_in_Pa: float of Pressure in Pascals.
            fluid: String of a CP fluid type.
            
        Returns:
            Specific heat capacity (J/kg.K)
        """
        return CP.PropsSI('C', 'T', T_in_K, 'P', p_in_Pa, fluid)

    def calculate_heat_flux(self, fluid_type="primary") -> float:
        """
        Calculate the heat flux (Qdot) for the specified fluid (primary or coolant).
        
        Args:
            fluid_type: Either "primary" or "coolant" to specify which fluid to calculate for.
            
        Returns:
            Qdot in W.
        """
        if fluid_type == "primary":
            c_p = self.calculate_specific_heat(self.primary_T_in_K, self.primary_p_in_Pa, self.primary_fluid)
            Qdot_W = c_p * self.primary_mdot_in_kg_s * (self.primary_T_in_K - self.primary_T_out_K)
        elif fluid_type == "coolant":
            c_p = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
            Qdot_W = c_p * self.coolant_mdot_in_kg_s * (self.coolant_T_out_K - self.coolant_T_in_K)
        else:
            raise ValueError("Invalid fluid_type. Choose either 'primary' or 'coolant'.")
        
        return Qdot_W

    def calculate_coolant_T_in(self):
        """
        Calculate the coolant temperature (Tcool) based on the inlet temperature (Tin),
        outlet temperature (Tout), and heat exchanger effectiveness.

        Returns:
            float: Calculated coolant temperature (Tcool) in K.
        """
        coolant_T_in_K = self.primary_T_in_K - (self.primary_T_in_K - self.primary_T_out_K) / self.effectiveness
        return coolant_T_in_K

    def calculate_primary_T_out(self) -> float:
        """
        Calculate the increase in primary fuid temperature depending on the primary/coolant input temperatures.
        This equation was provided by Chris Burger.
        """
        
        primary_T_out_K = self.primary_T_in_K - self.efficiency * (self.primary_T_in_K - self.coolant_T_in_K)
        self.primary_T_out_K = primary_T_out_K
        return primary_T_out_K
        
    def calculate_coolant_T_out(self) -> float:
        """
        Calculate the increase in coolant temperature depending on the heat flux from the primary fluid.
        This is only valid if we assume that all of the heat is transferred perfectly into the coolant.
        """
        c_p_coolant = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
        Q_dot_primary = self.calculate_heat_flux("primary")
        coolant_T_out_K = self.coolant_T_in_K + (Q_dot_primary / (c_p_coolant * self.coolant_mdot_in_kg_s))
        
        return coolant_T_out_K


class Intercooler(HeatExchanger):
    def __init__(self, intercooler_type="air_liquid", **kwargs):
        super().__init__(**kwargs)

        # Load the intercooler pressure drop map based on the type
        intercooler_params = cmr.IntercoolerParameters()

        if intercooler_type == "air_liquid":
            self.pressure_drop_map = intercooler_params.pressure_drop_map_air_liquid
        elif intercooler_type == "air_air":
            self.pressure_drop_map_hot = intercooler_params.pressure_drop_map_air_air_hot
            self.pressure_drop_map_cold = intercooler_params.pressure_drop_map_air_air_cold
        else:
            raise ValueError("Invalid intercooler type. Choose 'air_liquid' or 'air_air'.")

        self.intercooler_type = intercooler_type

    def calculate_density(self, temperature_K, pressure_Pa):
        """
        Calculate the density of air based on the ideal gas law.
        Args:
            temperature_K (float): Temperature in Kelvin
            pressure_Pa (float): Pressure in Pascal
        Returns:
            float: Density in kg/m³
        """
        R_specific_air = 287.06  # Specific gas constant for dry air in J/(kg·K)
        density = pressure_Pa / (R_specific_air * temperature_K)
        return density

    def get_interpolated_pressure_drop(self, temperature_K, pressure_Pa, side="hot"):
        """
        Interpolate the pressure drop based on primary mass flow rate (kg/s) using the pressure drop map.
        Converts the interpolated pressure drop from bar to Pa.

        Args:
            temperature_K (float): Temperature in Kelvin
            pressure_Pa (float): Pressure in Pascal
            side (str): "hot" or "cold" for air-air intercooler; ignored for air-liquid intercooler.

        Returns:
            float: Interpolated pressure drop in Pa
        """
        # Calculate density using temperature and pressure
        density = self.calculate_density(temperature_K, pressure_Pa)

        # Convert mass flow rate (kg/s) to volume flow rate (m³/s)
        primary_volume_flow_m3_s = self.primary_mdot_in_kg_s / density

        # Initialize volume flows and pressure drops
        volume_flows = []
        pressure_drops_bar = []

        # Determine the appropriate pressure drop map
        if self.intercooler_type == "air_liquid":
            volume_flows = list(self.pressure_drop_map.keys())
            pressure_drops_bar = list(self.pressure_drop_map.values())
        elif self.intercooler_type == "air_air":
            if side == "hot":
                volume_flows = list(self.pressure_drop_map_hot.keys())
                pressure_drops_bar = list(self.pressure_drop_map_hot.values())
            elif side == "cold":
                volume_flows = list(self.pressure_drop_map_cold.keys())
                pressure_drops_bar = list(self.pressure_drop_map_cold.values())
            else:
                raise ValueError("For air-air intercooler, specify 'side' as 'hot' or 'cold'.")

        # Create an interpolation function for volume flow rate (m³/s) to pressure drop (bar)
        interpolator = interp1d(volume_flows, pressure_drops_bar, fill_value="extrapolate")

        # Calculate the interpolated pressure drop in bar
        pressure_drop_bar = interpolator(primary_volume_flow_m3_s)

        # Convert pressure drop from bar to Pa
        pressure_drop_pa = pressure_drop_bar * 100000  # 1 bar = 100,000 Pa

        return pressure_drop_pa


class Radiatior(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        #For the moment the Radiator is not needed as a component its Qdot will be calculated 
        
class Evaporator(HeatExchanger):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
    
    #OVERWRITE: due to mean cp value we need to overwrite this function
    def calculate_specific_heat(self, fluid: str, T1: float = None, T2: float = None, P: float = None, step: float = 0.1) -> float:
        """
        Calculates the mean specific heat capacity (Cp) of a fluid over a temperature range 
        using Euler's forward integration.

        Parameters:
        - fluid: str : Name of the fluid (e.g., 'H2')
        - T1: float : Starting temperature in Kelvin
        - T2: float : Ending temperature in Kelvin
        - P: float : Pressure in Pa
        - step: float : Temperature step size in Kelvin (default: 0.1 K)
        
        Returns:
        - mean_cp: float : Mean specific heat capacity in J/kg·K over the temperature range
        """
        
        # Use instance attributes if parameters are not provided
        if T1 is None:
            T1 = self.primary_T_in_K
        if T2 is None:
            T2 = self.primary_T_out_K
        if P is None:
            P = self.primary_p_in_Pa
    
        # Ensure T1 is less than T2
        if T1 >= T2:
            raise ValueError("calculate_cp_of_T_range(): Starting temperature T1 must be less than ending temperature T2.")
        
        # Initialize variables
        total_cp = 0.0
        temp = T1
        count = 0
        
        # Perform Euler's forward integration over the temperature range
        while temp + step < T2:
            # Calculate Cp at the current temperature and pressure using CoolProp
            cp = CP.PropsSI('C', 'T', temp, 'P', P, fluid)
            
            # Add current cp to the total sum
            total_cp += cp
            
            # Increment the temperature by the step size
            temp += step
            count += 1
        
        # Final step: ensure we reach exactly T2
        # Calculate Cp at T2
        cp = CP.PropsSI('C', 'T', T2, 'P', P, fluid)
        total_cp += cp
        count += 1
        
        # Calculate the mean Cp by dividing the total Cp by the number of steps
        mean_cp = total_cp / count
        
        return mean_cp

    #OVERWRITE: due to mean cp value we need to overwrite this function
    def calculate_heat_flux(self, fluid_type="primary", mean_cp_H2 = None, evaporation_enthalpy_J_kg=446000) -> float:
        """
        Calculate the heat flux (Qdot) for the specified fluid (primary or coolant).
        
        Args:
            fluid_type: Either "primary" or "coolant" to specify which fluid to calculate for.
            
        Returns:
            Qdot in W.
        """
        
        if fluid_type == "primary":
            c_p = mean_cp_H2
            #Due to Phase change from liquid to gass the Qdot has a additional term (Verdapfungsenthalpie)
            Qdot_W = c_p * self.primary_mdot_in_kg_s * (self.primary_T_in_K - self.primary_T_out_K) + self.primary_mdot_in_kg_s * evaporation_enthalpy_J_kg
        elif fluid_type == "coolant":
            c_p = self.calculate_specific_heat(self.coolant_T_in_K, self.coolant_p_in_Pa, self.coolant_fluid)
            Qdot_W = c_p * self.coolant_mdot_in_kg_s * (self.coolant_T_out_K - self.coolant_T_in_K)
        else:
            raise ValueError("Invalid fluid_type. Choose either 'primary' or 'coolant'.")
        
        return Qdot_W
    #We know: T_Tank, T_out, massflow , primary
#
# # Create an instance of Intercooler with a specific primary mass flow rate
# intercooler_air_air = Intercooler(
#     intercooler_type="air_air",     # Specify the intercooler type
#     efficiency=0.49,
#     primary_fluid="Air",
#     coolant_fluid="Air",           # Specify air as the coolant fluid for air-air intercooler
#     primary_mdot_in_kg_s=0.166,    # Example mass flow rate for primary fluid in kg/s
#     primary_T_in_K=225.28 + 273,   # Example primary fluid inlet temperature in K
#     primary_p_in_Pa=316000,        # Example primary fluid inlet pressure in Pa
#     coolant_mdot_in_kg_s=0.2,      # Example mass flow rate for secondary air in kg/s
#     coolant_T_in_K=293.15          # Example secondary air inlet temperature in K
# )
#
# # Calculate the interpolated pressure drop for the hot side of air-air intercooler
# pressure_drop_hot = intercooler_air_air.get_interpolated_pressure_drop(
#     intercooler_air_air.primary_T_in_K,
#     intercooler_air_air.primary_p_in_Pa,
#     side="hot"
# )
#
# # Calculate the interpolated pressure drop for the cold side of air-air intercooler
# pressure_drop_cold = intercooler_air_air.get_interpolated_pressure_drop(
#     intercooler_air_air.primary_T_in_K,
#     intercooler_air_air.primary_p_in_Pa,
#     side="cold"
# )
#
# # Print the results
# print(f"Interpolated Pressure Drop (Hot Side): {pressure_drop_hot:.2f} Pa")
# print(f"Interpolated Pressure Drop (Cold Side): {pressure_drop_cold:.2f} Pa")
# # Create an instance of Intercooler for air-liquid
# intercooler_air_liquid = Intercooler(
#     intercooler_type="air_liquid",  # Specify the intercooler type
#     efficiency=0.49,
#     primary_fluid="Air",
#     coolant_fluid="Water",
#     primary_mdot_in_kg_s=0.166,    # Example mass flow rate for primary fluid in kg/s
#     primary_T_in_K=225.28 + 273,   # Example primary fluid inlet temperature in K
#     primary_p_in_Pa=316000,        # Example primary fluid inlet pressure in Pa
#     coolant_mdot_in_kg_s=0.2,      # Example mass flow rate for coolant in kg/s
#     coolant_T_in_K=293.15          # Example coolant inlet temperature in K
# )
#
# # Calculate the interpolated pressure drop for the air-liquid intercooler
# pressure_drop_air_liquid = intercooler_air_liquid.get_interpolated_pressure_drop(
#     intercooler_air_liquid.primary_T_in_K,
#     intercooler_air_liquid.primary_p_in_Pa
# )
#
# # Print the result
# print(f"Interpolated Pressure Drop (Air-Liquid): {pressure_drop_air_liquid:.2f} Pa")
