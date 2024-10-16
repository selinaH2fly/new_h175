"""
    Simulates the behavior of a cathode air supply system for a fuel cell at a given flight level.
    The function models the performance of components like compressors, intercoolers, humidifiers,
    and turbines, calculating key outputs such as temperature, pressure, humidity, and power.
    """

# Import custom classes and functions
import cathode_model_run
from Components.compressor import Compressor
from Components.heat_exchanger import Intercooler
from Components.moist_exchanger import Humidifier
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow, convert, icao_atmosphere

# Function to simulate the architecture
def simulate_cathode_architecture(flight_level_100ft, compressor_map=None, stoich_cathode=1.8, current_A=600, cellcount=455):
    """
    Arguments:
    - flight_level_100ft (int): Altitude in flight levels.
      This is used to compute ambient conditions (temperature and pressure) for the simulation.

    - compressor_map: A performance map for the compressor. If provided,
      it supplies specific efficiency curves or other characteristics for the compressor. If not
      provided, default values will be used.

    - stoich_cathode : Stoichiometry of the cathode.

    - current_A: The electrical current in amperes drawn by the fuel cell stack.

    - cellcount: The number of individual cells in the fuel cell stack.
    """
    # Print heading
    print("=" * 50)  # Creates a line of equal signs for emphasis
    print(f"Starting simulation for flight level: {flight_level_100ft}")  # Simulated flight level message
    print("=" * 50)  # Creates another line of equal signs for emphasis

    # Instantiate parameters
    _params_physics = cathode_model_run.PhysicalParameters()
    _params_compressor = cathode_model_run.CompressorParameters()
    _params_intercooler = cathode_model_run.IntercoolerParameters()
    _params_humidifier = cathode_model_run.HumidifierParameters()
    _params_turbine = cathode_model_run.TurbineParameters()
    _mass_estimator = cathode_model_run.Mass_Parameters()

    # Instantiate input pressures and temperatures
    inputs = cathode_model_run.Input()  # Using the new Input class

    # Evaluate ambient conditions
    temperature_ambient_K, pressure_ambient_Pa = icao_atmosphere(flight_level_100ft)
    print(f"Ambient temperature: {temperature_ambient_K:.2f} K, pressure: {pressure_ambient_Pa:.2f} Pa")

    # Instantiate the compressor
    compressor = Compressor(
        mass_estimator=_mass_estimator,
        isentropic_efficiency=_params_compressor.isentropic_efficiency,
        electric_efficiency=_params_compressor.electric_efficiency,
        air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=stoich_cathode, current_A=current_A,
                                                   cellcount=cellcount),
        temperature_in_K=temperature_ambient_K,
        pressure_in_Pa=pressure_ambient_Pa,
        pressure_out_Pa=inputs.pressures_Pa["PTC211"],
        compressor_map=compressor_map,

    )

    # Calculate outlet temperature and power
    compressor.temperature_out_K = compressor.calculate_T_out()
    compressor.power_W = compressor.calculate_power()

    # Add a header for the compressor results
    print("-" * 20)  # Creates a line of equal signs for emphasis
    print("Compressor Results:")
    print("-" * 20)  # Creates another line of equal signs for emphasis

    # Print compressor results
    print(f"Compressor outlet temperature: {compressor.temperature_out_K:.2f} K")
    print(f"Compressor power : {compressor.power_W / 1000:.2f} kW")  # Convert W to kW
    #print(f"Air mass flow rate: {compressor.air_mass_flow_kg_s:.4f} kg/s")

    # Instantiate the intercooler_air_air using compressor outputs
    intercooler_air_air = Intercooler(
        efficiency=0.41, primary_fluid="Air", coolant_fluid="Air",
        primary_p_in_Pa=compressor.pressure_out_Pa,
        primary_T_in_K=compressor.temperature_out_K,
        primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
        coolant_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
        coolant_T_in_K=inputs.temperatures_K["TTC601"]
    )
    # Calculate outlet temperature and heat flux
    intercooler_air_air.primary_temperature_out_K = intercooler_air_air.calculate_primary_T_out()
    intercooler_air_air.coolant_temperature_out_K = intercooler_air_air.calculate_coolant_T_out()
    intercooler_air_air.pressure_out_Pa = inputs.pressures_Pa["PTC301"]
    intercooler_air_air.heat_flux_W = intercooler_air_air.calculate_heat_flux("primary")

    # Add a header for the compressor results
    print("-" * 20)  # Creates a line of equal signs for emphasis
    print("Intercooler Air-Air Results:")
    print("-" * 20)  # Creates another line of equal signs for emphasis

    # Print intercooler_air_air results
    print(f"Intercooler air-air primary outlet temperature: {intercooler_air_air.primary_temperature_out_K:.2f} K")
    print(f"Intercooler air-air coolant outlet temperature: {intercooler_air_air.coolant_temperature_out_K:.2f} K")
    print(f"Intercooler air-air outlet pressure: {intercooler_air_air.pressure_out_Pa :.2f} Pa")
    print(f"Intercooler air-air heat flux: {intercooler_air_air.heat_flux_W / 1000:.4f} kW")

    # Instantiate the intercooler_air_liquid
    intercooler_air_liquid = Intercooler(
        efficiency=0.61, primary_fluid="Air", coolant_fluid="Water",
        primary_p_in_Pa=intercooler_air_air.pressure_out_Pa,
        primary_T_in_K=intercooler_air_air.primary_temperature_out_K,
        primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
        coolant_mdot_in_kg_s=0.5, coolant_T_in_K=323
    )
    # Calculate outlet temperature and heat flux
    intercooler_air_liquid.primary_temperature_out_K = intercooler_air_liquid.calculate_primary_T_out()
    intercooler_air_liquid.coolant_temperature_out_K = intercooler_air_liquid.calculate_coolant_T_out()
    intercooler_air_liquid.pressure_out_Pa = inputs.pressures_Pa["PTC311"]
    intercooler_air_liquid.heat_flux_W = intercooler_air_liquid.calculate_heat_flux("primary")

    print("-" * 20)  # Creates a line of equal signs for emphasis
    print("Intercooler Air-Liquid Results:")
    print("-" * 20)  # Creates another line of equal signs for emphasis

    # Print intercooler_air_liquid results
    print(f"Intercooler air_liquid primary outlet temperature: {intercooler_air_liquid.primary_temperature_out_K:.2f} K")
    print(f"Intercooler air_liquid coolant outlet temperature: {intercooler_air_liquid.coolant_temperature_out_K:.2f} K")
    print(f"Intercooler air_liquid heat flux: {intercooler_air_air.heat_flux_W / 1000:.4f} kW")

    # Instantiate the humidifier with intercooler_air_liquid output as input for dry air inlet
    humidifier = Humidifier(
        dry_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        dry_air_temperature_in_K=intercooler_air_liquid.primary_temperature_out_K,
        dry_air_pressure_in_Pa=intercooler_air_liquid.primary_p_in_Pa,
        dry_air_rh_in=_params_humidifier.dry_air_rh_in,
        dry_air_temperature_out_K=_params_humidifier.dry_air_temperature_out_K,
        dry_air_pressure_out_Pa=_params_humidifier.dry_air_pressure_out_Pa,
        dry_air_rh_out=_params_humidifier.dry_air_rh_out,
        wet_air_mass_flow_kg_s=_params_humidifier.wet_air_mass_flow_kg_s,
        wet_air_temperature_in_K=_params_humidifier.wet_air_temperature_in_K,
        wet_air_pressure_in_Pa=_params_humidifier.wet_air_pressure_in_Pa,
        wet_air_rh_in=_params_humidifier.wet_air_rh_in,
        wet_air_pressure_out_Pa =_params_humidifier.wet_air_pressure_out_Pa
    )

    # Calculate partial pressures
    p_vap_dry_in = humidifier.calculate_partial_pressure(humidifier.dry_air_temperature_in_K, humidifier.dry_air_rh_in)
    p_vap_dry_out = humidifier.calculate_partial_pressure(humidifier.dry_air_temperature_out_K,
                                                          humidifier.dry_air_rh_out)
    p_vap_wet_in = humidifier.calculate_partial_pressure(humidifier.wet_air_temperature_in_K, humidifier.wet_air_rh_in)

    # Calculate dew point temperature
    dry_air_DPT_in_K = humidifier.calculate_dewpoint(humidifier.dry_air_temperature_in_K,humidifier.dry_air_pressure_in_Pa,humidifier.dry_air_rh_in)
    dry_air_DPT_out_K = humidifier.calculate_dewpoint(humidifier.dry_air_temperature_out_K,humidifier.dry_air_pressure_out_Pa,humidifier.dry_air_rh_out)
    wet_air_DPT_in_K = humidifier.calculate_dewpoint(humidifier.wet_air_temperature_in_K,humidifier.wet_air_pressure_in_Pa,humidifier.wet_air_rh_in)

    # calculate water transfer
    m_dot_water_trans, eta_water_trans = humidifier.calculate_water_transfer()


    print("-" * 20)  # Creates a line of equal signs for emphasis
    print("Humidifier Results:")
    print("-" * 20)  # Creates another line of equal signs for emphasis

    # Print humidifier results
    print(f"Dry in, dew point temperature: {dry_air_DPT_in_K:.2f} K")
    print(f"Dry out, dew point temperature: {dry_air_DPT_out_K:.2f} K")
    print(f"Wet in, dew point temperature: {wet_air_DPT_in_K:.2f} K")
    print(f"Efficiency of water transfer: {eta_water_trans*100:.2f} %")

    # Instantiate the turbine using humidifier output and Pressure from cathode_model_run
    turbine = Turbine(
        mass_estimator=_mass_estimator,
        isentropic_efficiency=_params_turbine.isentropic_efficiency,
        temperature_in_K=intercooler_air_air.coolant_temperature_out_K,
        pressure_in_Pa=inputs.pressures_Pa["p_8"],
        pressure_out_Pa=pressure_ambient_Pa,
        air_mass_flow_kg_s=humidifier.wet_air_mass_flow_kg_s
    )

    # Calculate turbine outlet temperature and power
    turbine.temperature_out_K = turbine.calculate_T_out()
    turbine.power_W =  turbine.calculate_power() /turbine.isentropic_efficiency

    print("-" * 20)  # Creates a line of equal signs for emphasis
    print("Turbine Results:")
    print("-" * 20)  # Creates another line of equal signs for emphasis

    # Print turbine results
    print(f"Turbine Inlet temperature: {turbine.temperature_in_K:.2f} K")
    print(f"Turbine outlet temperature: {turbine.temperature_out_K:.2f} K")
    print(f"Turbine power: {turbine.power_W / 1000:.2f} kW")  # Convert W to kW

# Uncomment the following to run the simulation when the script is executed
if __name__ == "__main__":
    # Call the function with a valid flight level (e.g., 100 for 10000 feet)
    simulate_cathode_architecture(flight_level_100ft=100)
