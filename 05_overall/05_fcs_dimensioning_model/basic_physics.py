''' This script contains the basic physics functions used in the optimization problem. '''


from parameters import Physical_Parameters
import CoolProp.CoolProp as CP
import CoolProp.HumidAirProp as HAP
from scipy.constants import physical_constants
import psychrolib as lib



molar_mass = CP.PropsSI('M', 'Air')

#default density
density=1

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
    },
    'flow': {
        ('kg_s', 'm3_min'): lambda kg: (kg / density) * 60,
        ('kg_s', 'l_min'):  lambda kg: kg / density * 1000 * 60, 
        ('m3_min', 'kg_s'): lambda m3: (m3 * density) / 60 ,
        ('l_min', 'kg_s'):  lambda l: l * density / (1000 *60),
    }
}




def getDensity(temperature, pressure, fluid, humidity): 
    density = lib.humidDensity(lib.Temperature(temperature,'K'), relHumidity = humidity,pressure=lib.Pressure(pressure,'pa'))
    if not density: raise ValueError("Density is 0 or None.")
    return density if not density else density[0]


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
            ((physical_constants['standard acceleration of gravity'][0]) / ((physical_constants['molar gas constant'][0]/molar_mass) * params_physics.temperature_lapse_rate_K_m))  #calculation of specific gas constant by R/molar_mass(air)

    return temperature_K, pressure_Pa
    
def compute_air_mass_flow(stoichiometry, current_A, cellcount=275):
    """
    Compute the air mass flow rate in kg/s.
    """

    # Load the physical parameters
    params_physics = Physical_Parameters()

    # Calculate the air flow rates
    air_flow_mol_s = current_A * cellcount * stoichiometry / (4 * physical_constants['Faraday constant'][0] * params_physics.oxygen_mol_fraction)
    air_flow_kg_s = air_flow_mol_s * molar_mass

    return air_flow_kg_s




def get_variable_type(input_unit):
    """
    Determines the variable type (temperature, pressure or flow) and extracts the unit from the variable name.
    
    Parameters:
    - variable_name: The variable name containing the unit suffix (e.g., "*_degC", "*_Pa").
    
    Returns:
    - A tuple of (variable_type, unit), where variable_type is either 'temperature' or 'pressure',
      and unit is the detected unit (e.g., 'degC', 'K', 'Pa', 'bar').
    """
    # Get conversion pairs per variable type
    temperature_units = list(set([unit for pair in list(CONVERSION_FACTORS['temperature'].keys()) for unit in pair]))
    pressure_units = list(set([unit for pair in list(CONVERSION_FACTORS['pressure'].keys()) for unit in pair]))
    flow_units = list(set([unit for pair in list(CONVERSION_FACTORS['flow'].keys()) for unit in pair]))

    # Check Input unit
    if all(input_unit not in units for units in [temperature_units, pressure_units, flow_units]):
        raise ValueError(f"Invalid unit: {input_unit}")

    # Determine the variable type based on the unit
    if input_unit in temperature_units:
        return 'temperature'
    elif input_unit in pressure_units:
        return 'pressure'
    elif input_unit in flow_units:
        return 'flow'
    else:
        raise ValueError(f"Unrecognized unit in variable: {input_unit}")


def checkHumidity(relative_humidity):
    return relative_humidity * 100 if 0 <= relative_humidity <= 1 else relative_humidity


def convert(value, input_unit , target_unit, fluid="Air", temperature=20, pressure=1, relative_humidity=0.3):
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
    
    # multiply humidity by 100 if it is between 0 and 1
    relative_humidity= checkHumidity(relative_humidity)

    # Get the variable type
    variable_type = get_variable_type(input_unit)

    # calc density for flows
    if variable_type == 'flow': 
        global density  
        density = getDensity(temperature, pressure, fluid, relative_humidity)
        


    # Check if there is a direct conversion between the unit and target unit
    conversion_key = (input_unit, target_unit)
    
    # Fetch the conversion function from the dictionary
    conversion_function = CONVERSION_FACTORS[variable_type].get(conversion_key)
    
    if conversion_function is None:
        raise ValueError(f"Unsupported conversion from {input_unit} to {target_unit}")
    
    # Perform the conversion using the fetched function
    return conversion_function(value)

#Basic example:
# Pressure conversion: Pascals to bar
#Inlet_Pressure_Pa = 101325  # Inlet pressure in Pascals
#outlet_Pressure_bar = convert(Inlet_Pressure_Pa, "bar")

# Pressure conversion: bar to Pascals
#Inlet_Pressure_bar = 1.01325  # Inlet pressure in bar
#outlet_Pressure_Pa = convert(Inlet_Pressure_bar, "Pa")
