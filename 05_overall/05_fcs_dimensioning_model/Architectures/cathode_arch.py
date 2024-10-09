import CoolProp.CoolProp as CP
# Import custom classes and functions
#TODO: change parameters to cathode_model_run
import parameters
from cathode_model_run import PressureParameters
from Components.compressor import Compressor
from Components.heat_exchanger import Intercooler
from Components.moist_exchanger import Humidifier
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow, convert, icao_atmosphere

# Function to simulate the components in series
def simulate_cathode_architecture(flight_level_100ft, compressor_map=None, stoich_cathode=1.8,current_A = 600, cellcount=455):
    print(f"Starting simulation for flight level: {flight_level_100ft}")

    # Instantiate Physical Parameters
    _params_physics = parameters.Physical_Parameters()
    _params_compressor = parameters.Compressor_Parameters()
    _params_intercooler = parameters.Intercooler_Parameters()
    _params_humidifier = parameters.Humidifier_Parameters()
    _params_turbine = parameters.Turbine_Parameters()  # Ensure this is instantiated
    _mass_estimator = parameters.Mass_Parameters()

    # Instantiate Pressure Parameters
    pressures = PressureParameters()

    # Evaluate ambient conditions
    temperature_ambient_K, pressure_ambient_Pa = icao_atmosphere(flight_level_100ft)
    print(f"Ambient temperature: {temperature_ambient_K} K, pressure: {pressure_ambient_Pa} Pa")

    # Instantiate the compressor
    compressor = Compressor(
        mass_estimator=_mass_estimator,
        isentropic_efficiency=_params_compressor.isentropic_efficiency,
        electric_efficiency=_params_compressor.electric_efficiency,
        temperature_in_K=temperature_ambient_K,
        pressure_in_Pa=pressure_ambient_Pa,
        nominal_BoP_pressure_drop_Pa=_params_compressor.nominal_BoP_pressure_drop_Pa,
        compressor_map=compressor_map,
        nominal_air_flow_kg_s=_params_compressor.nominal_air_flow_kg_s,
        reference_ambient_conditions=(
            _params_compressor.reference_pressure_Pa,
            _params_compressor.reference_temperature_K
        )
    )

    # Calculate air mass flow using the compute_air_mass_flow function
    compressor.air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=stoich_cathode, current_A=current_A, cellcount=cellcount)
    compressor.pressure_out_Pa = pressures.PTC211_p_Pa

    # Calculate outlet temperature and power
    compressor.temperature_out_K = compressor.calculate_T_out()
    compressor_power_W = compressor.calculate_power()

    # Print compressor results
    print(f"Stage 1 outlet temperature: {compressor.temperature_out_K:.2f} K")
    print(f"Compressor power for stage 1: {compressor_power_W / 1000:.2f} kW")  # Convert W to kW
    print(f"Air mass flow rate: {compressor.air_mass_flow_kg_s:.4f} kg/s")

 #    # Instantiate the intercooler using compressor outputs
 #    intercooler = Intercooler(
 #        primary_p_in_Pa=convert(pressures.PTC301_p_bara, 'Pa'),  # Pressure after air-air intercooler, warm side
 #        primary_t_in_K=compressor.temperature_out_K,
 #        primary_mass_flow_kg_s=compressor.air_mass_flow_kg_s
 #    )
 #
 #
 #    #TODO: IC Tout and Power??
 #    # Calculate intercooler outlet temperature and other properties as necessary
 #    # intercooler.temperature_out_K =
 #    # intercooler_power_W = intercooler.calculate_power()
 #    intercooler_heat_flux_W = intercooler.calculate_heat_flux("primary")
 #
 #
 # # Print values for debugging
 #    print(f"Compressor outlet pressure (from cathode_model_run): {convert(pressures.PTC301_p_bara, 'Pa')} Pa")
 #    print(f"Intercooler primary inlet temperature: {intercooler.primary_t_in_K} K")
 #    print(f"Compressor power: {compressor.power_out_W / 1000:.2f} kW")  # Convert to kW
 #    print(f"Air mass flow rate: {compressor.air_mass_flow_kg_s:.4f} kg/s")

# Uncomment the following to run the simulation when the script is executed
if __name__ == "__main__":
    # Call the function with a valid flight level (e.g., 30 for 3000 feet)
    simulate_cathode_architecture(flight_level_100ft=100)

