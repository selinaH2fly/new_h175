''' This script contains the basic physics functions used in the optimization problem. '''

from parameters import Physical_Parameters

def icao_atmosphere(flight_level_100ft):
    """
    Calculate the temperature and pressure at a given altitude using the ICAO atmosphere model.
    """

    # Load the physical parameters
    params_physics = Physical_Parameters()

    # Calculate the altitude in meters
    altitude_m = flight_level_100ft * 100 * 0.3048

    # Calculate the temperature and pressure at the given altitude
    temperature_K = params_physics.sea_level_ambient_temperature_K - params_physics.temperature_lapse_rate * altitude_m
    pressure_Pa = params_physics.sea_level_ambient_pressure_bar*1e5 * \
        (1 - params_physics.temperature_lapse_rate * altitude_m / params_physics.sea_level_ambient_temperature_K) ** \
            (params_physics.gravity / (params_physics.specific_gas_constant * params_physics.temperature_lapse_rate))

    return temperature_K, pressure_Pa
    
def compute_air_mass_flow(stoichiometry, current_A, cellcount=275):
    """
    Compute the air mass flow rate in kg/s.
    """

    # Load the physical parameters
    params_physics = Physical_Parameters()

    # Calculate the air mass flow rate
    air_mass_flow_kg_s = current_A * cellcount * stoichiometry * params_physics.air_molar_mass / \
        (4 * params_physics.faraday * params_physics.oxygen_mol_fraction)

    return air_mass_flow_kg_s