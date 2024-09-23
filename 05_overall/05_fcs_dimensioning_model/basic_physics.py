''' This script contains the basic physics functions used in the optimization problem. '''

from parameters import Physical_Parameters
import CoolProp.CoolProp as CP
from scipy.constants import physical_constants


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

#%% Example usage

temperature_K, pressure_Pa = icao_atmosphere(flight_level_100ft=120)

print(f"Temperature at 12000 ft: {temperature_K:.2f} K")
print(f"Pressure at 12000 ft: {pressure_Pa:.2f} Pa")