import CoolProp.CoolProp as CP
# Import custom classes and functions
import parameters
from cathode_model_run import PressureParameters
from Components.compressor import Compressor
from Components.heat_exchanger import Intercooler
from Components.moist_exchanger import Humidifier
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow, convert, icao_atmosphere

# Function to simulate the components in series
def simulate_cathode_architecture(flight_level_100ft, compressor_map=None, stoich_cathode=1.8, current_A=600, cellcount=455):
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
    print(f"Ambient temperature: {temperature_ambient_K:.2f} K, pressure: {pressure_ambient_Pa:.2f} Pa")

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
    compressor.power_W = compressor.calculate_power()

    # Print compressor results
    print(f"Stage 1 outlet temperature: {compressor.temperature_out_K:.2f} K")
    print(f"Compressor power for stage 1: {compressor.power_W / 1000:.2f} kW")  # Convert W to kW
    print(f"Air mass flow rate: {compressor.air_mass_flow_kg_s:.4f} kg/s")

    # Instantiate the intercooler using compressor outputs
    intercooler = Intercooler(
        efficiency=0.41, primary_fluid="Air", coolant_fluid="Air",
        primary_p_in_Pa=compressor.pressure_out_Pa,
        primary_T_in_K=compressor.temperature_out_K,
        primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
        coolant_mdot_in_kg_s=0.5, coolant_T_in_K=323
    )

    intercooler.temperature_out_K = intercooler.calculate_primary_T_out()
    intercooler.heat_flux_W = intercooler.calculate_heat_flux("primary")

    # Print intercooler results
    print(f"Intercooler primary outlet temperature: {intercooler.temperature_out_K:.2f} K")
    print(f"Intercooler heat flux: {intercooler.heat_flux_W / 1000:.4f} kW")  # Convert to kW

    # Instantiate the humidifier with intercooler output as input for dry air inlet
    humidifier = Humidifier()
    humidifier.dry_air_temperature_in_K = intercooler.temperature_out_K
    humidifier.dry_air_pressure_in_Pa = intercooler.primary_p_in_Pa
    humidifier.dry_air_mass_flow_kg_s = intercooler.primary_mdot_in_kg_s

    # Humidifier calculations (assuming some method to calculate outlet conditions)
    humidifier.dry_air_temperature_out_K = humidifier.dry_air_temperature_in_K - 5  # Hypothetical cooling
    humidifier.dry_air_pressure_out_Pa = humidifier.dry_air_pressure_in_Pa - 1000  # Hypothetical pressure drop

    # Print humidifier results
    print(f"Humidifier dry air inlet temperature: {humidifier.dry_air_temperature_in_K:.2f} K")
    print(f"Humidifier dry air outlet temperature: {humidifier.dry_air_temperature_out_K:.2f} K")
    print(f"Humidifier dry air outlet pressure: {humidifier.dry_air_pressure_out_Pa:.2f} Pa")

# Uncomment the following to run the simulation when the script is executed
if __name__ == "__main__":
    # Call the function with a valid flight level (e.g., 100 for 10000 feet)
    simulate_cathode_architecture(flight_level_100ft=100)
