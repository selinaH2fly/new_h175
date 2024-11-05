''' This script contains the basic physics functions used in the optimization problem. '''

from parameters import Physical_Parameters
import CoolProp.CoolProp as CP
from scipy.constants import physical_constants
import inspect # for unit conversion

def icao_atmosphere(flight_level_100ft):
    """
    Calculate the temperature and pressure at a given altitude using the ICAO atmosphere model.
    """

    # Load the physical parameters
    params_physics = Physical_Parameters()

    # Calculate the altitude in meters
    altitude_m = flight_level_100ft * 100 * 0.3048

    # Calculate the temperature and pressure at the given altitude
    temperature_K = params_physics.sea_level_ambient_temperature_K - params_physics.temperature_lapse_rate_K_m * altitude_m
    pressure_Pa = params_physics.sea_level_ambient_pressure_bar*1e5 * \
        (1 - params_physics.temperature_lapse_rate_K_m * altitude_m / params_physics.sea_level_ambient_temperature_K) ** \
            ((physical_constants['standard acceleration of gravity'][0]) / ((physical_constants['molar gas constant'][0]/CP.PropsSI('M', 'Air')) * params_physics.temperature_lapse_rate_K_m))  #calculation of specific gas constant by R/molar_mass(air)

    return temperature_K, pressure_Pa
    
def compute_air_mass_flow(stoichiometry, current_A, cellcount=275):
    """
    Compute the air mass flow rate in kg/s.
    """

    # Load the physical parameters
    params_physics = Physical_Parameters()

    # Calculate the air flow rates
    air_flow_mol_s = current_A * cellcount * stoichiometry / (4 * physical_constants['Faraday constant'][0] * params_physics.oxygen_mol_fraction)
    air_flow_kg_s = air_flow_mol_s * CP.PropsSI('M','Air')

    return air_flow_kg_s

def compute_reacted_o2_mass_flow(current_A, cellcount):
    """
    Calculate the reacted O2 mass flow rate in a fuel cell stack.

    Parameters:
    current_A, cellcount=275: Current per cell in amperes (A).
    cellcount: Number of cells in the stack.

    Returns:
    float: Reacted O2 mass flow rate in kg/s.
    """
    #TODO transfer to basic physics?
    #TODO grab constants from coolprop

    M_O2 = 0.032  # Molar mass of O2 in kg/mol
    F = 96485  # Faraday's constant in C/mol
    efficiency_factor = 0.23  # Efficiency factor

    # Calculate reacted O2 mass flow rate
    o2_mass_flow_rate = (current_A * cellcount * M_O2) / (4 * F * efficiency_factor)

    return o2_mass_flow_rate

# %% Unit conversion function:

# Dictionary to store allowed conversion functions
CONVERSION_FACTORS = {
    'temperature': {
        ('degC', 'K'): lambda c: c + 273.15,    # Celsius to Kelvin
        ('K', 'degC'): lambda k: k - 273.15,    # Kelvin to Celsius
    },
    'pressure': {
        ('Pa', 'bara'): lambda p: p / 1e5,      # Pascals to bar
        ('Pa', 'bar'):  lambda p: p / 1e5,      # Pascals to bar
        ('bara', 'Pa'): lambda b: b * 1e5,      # Bar to Pascals
        ('bar', 'Pa'):  lambda b: b * 1e5,      # Bar to Pascals
        
        
    }
}

def get_variable_type(variable_name):
    """
    Determines the variable type (temperature or pressure) and extracts the unit from the variable name.
    
    Parameters:
    - variable_name: The variable name containing the unit suffix (e.g., "*_degC", "*_Pa").
    
    Returns:
    - A tuple of (variable_type, unit), where variable_type is either 'temperature' or 'pressure',
      and unit is the detected unit (e.g., 'degC', 'K', 'Pa', 'bar').
    """
    
    if "_" not in variable_name:
        raise ValueError(f"Invalid variable name format: {variable_name}")
    
    # Extract the unit after the last underscore
    unit = variable_name.split('_')[-1]

    # Determine the variable type based on the unit
    if unit in ["degC", "K"]:
        return 'temperature', unit
    elif unit in ["Pa", "bara", "bar"]:
        return 'pressure', unit
    else:
        raise ValueError(f"Unrecognized unit in variable: {variable_name}")

def convert(value, target_unit):
    """
    Converts a given value from its detected unit (from the variable name) to the target unit.
    
    Parameters:
    - value: The numerical value to convert.
    - target_unit: The target unit as a string (e.g., "degC", "K", "Pa", "bara").
    
    Returns:
    - Converted value in the target unit.
    """
    
    if not isinstance(value, (int, float)):
        raise ValueError("Value must be a numerical type, not a string.")
    
    # Extract the varaible name from the function call
    caller_locals = inspect.currentframe().f_back.f_locals
    variable_name = next(name for name, var in caller_locals.items() if var is value)

    # Get the variable type and the current unit
    variable_type, unit = get_variable_type(variable_name)
    
    # Check if there is a direct conversion between the unit and target unit
    conversion_key = (unit, target_unit)
    
    # Fetch the conversion function from the dictionary
    conversion_function = CONVERSION_FACTORS[variable_type].get(conversion_key)
    
    if conversion_function is None:
        raise ValueError(f"Unsupported conversion from {unit} to {target_unit}")
    
    # Perform the conversion using the fetched function
    return conversion_function(value)

#Basic example:
# Pressure conversion: Pascals to bar
#Inlet_Pressure_Pa = 101325  # Inlet pressure in Pascals
#outlet_Pressure_bar = convert(Inlet_Pressure_Pa, "bar")

# Pressure conversion: bar to Pascals
#Inlet_Pressure_bar = 1.01325  # Inlet pressure in bar
#outlet_Pressure_Pa = convert(Inlet_Pressure_bar, "Pa")