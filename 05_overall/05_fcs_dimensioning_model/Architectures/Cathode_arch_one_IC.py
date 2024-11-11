"""
Simulates the behavior of a cathode air supply system for a fuel cell at a given flight level.
The function models the performance of components like compressors, intercoolers, humidifiers,
and turbines, calculating key outputs such as temperature, pressure, humidity, and power.
"""

# System Architecture

# Import custom classes and functions
import cathode_model_run
from Components.compressor import Compressor
from Components.heat_exchanger import Intercooler
from Components.filter import FuelCellAirFilter
from Components.moist_exchanger import Humidifier
from Components.valve import Valve
from Components.water_separator import WaterSeparator
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow, compute_reacted_o2_mass_flow_kg_s, icao_atmosphere

# Function to simulate the architecture
def simulate_cathode_architecture(flight_level, compressor_map=None, stoich_cathode=1.7, current_A=600, cellcount=455):
    """
    Arguments:
    - flight_level (int): Altitude in flight levels.
      This is used to compute ambient conditions (temperature and pressure) for the simulation.
    - compressor_map: A performance map for the compressor. If provided,
      it supplies specific efficiency curves or other characteristics for the compressor. If not
      provided, default values will be used.
    - stoich_cathode: Stoichiometry of the cathode.
    - current_A: The electrical current in amperes drawn by the fuel cell stack.
    - cellcount: The number of individual cells in the fuel cell stack.
    """

    # Instantiate parameters for each component in the model
    _params_physics = cathode_model_run.PhysicalParameters()
    _params_compressor = cathode_model_run.CompressorParameters()
    _params_intercooler = cathode_model_run.IntercoolerParameters()
    _params_air_filter = cathode_model_run.AirFilterParameters()
    _params_humidifier = cathode_model_run.HumidifierParameters()
    _params_valve = cathode_model_run.ValveParameters()
    _params_water_separator = cathode_model_run.WaterSeparatorParameters()
    _params_turbine = cathode_model_run.TurbineParameters()
    _mass_estimator = cathode_model_run.Mass_Parameters()

    # Load input pressures and temperatures
    inputs = cathode_model_run.Input()  # Class that encapsulates all input values

    # Calculate dry air mass flow based on input parameters
    dry_air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=stoich_cathode, current_A=current_A, cellcount=cellcount)

    # Calculate the oxygen mass flow rate consumed in the stack
    depleted_o2 = compute_reacted_o2_mass_flow_kg_s(current_A=current_A, cellcount=cellcount)

    # Instantiate the compressor with initial conditions and parameters
    compressor = Compressor(
        mass_estimator=_mass_estimator,
        isentropic_efficiency=_params_compressor.isentropic_efficiency,
        electric_efficiency=_params_compressor.electric_efficiency,
        air_mass_flow_kg_s=dry_air_mass_flow_kg_s,
        temperature_in_K=inputs.temperatures_K["TTC1"],
        pressure_in_Pa=inputs.pressures_Pa["PTC1"],
        pressure_out_Pa=inputs.pressures_Pa["PTC1"] + 10000,  # Initial guess for pressure rise
        compressor_map=compressor_map,
    )

    # Initialize iterative loop variables for convergence
    tolerance = 1e-3
    max_iterations = 50
    iteration = 0
    converged = False

    while not converged and iteration < max_iterations:
        iteration += 1

        # Calculate compressor outlet temperature based on current outlet pressure
        compressor.temperature_out_K = compressor.calculate_T_out()


        # Instantiate and update the intercooler with the compressor's outlet conditions
        intercooler_air_liquid = Intercooler(
            efficiency=_params_intercooler.efficiency,
            primary_fluid="Air", coolant_fluid="INCOMP::MEG-50%",
            primary_p_in_Pa=compressor.pressure_out_Pa,
            primary_T_in_K=compressor.temperature_out_K,
            primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
            coolant_mdot_in_kg_s=_params_intercooler.coolant_mdot_in_kg_s,
            coolant_T_in_K=inputs.temperatures_K["T_cool"]
        )

        # Calculate intercooler outlet temperature, heat flux, and pressure drop
        intercooler_air_liquid.primary_temperature_out_K = intercooler_air_liquid.calculate_primary_T_out()
        intercooler_air_liquid.coolant_temperature_out_K = intercooler_air_liquid.calculate_coolant_T_out()
        intercooler_air_liquid.heat_flux_W = intercooler_air_liquid.calculate_heat_flux("primary")
        intercooler_air_liquid.pressure_drop = intercooler_air_liquid.get_interpolated_pressure_drop()
        intercooler_air_liquid.primary_p_out_Pa = intercooler_air_liquid.primary_p_in_Pa - intercooler_air_liquid.get_interpolated_pressure_drop()


        # Instantiate the air filter
        air_filter = FuelCellAirFilter(
            air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
            temperature_in_K=intercooler_air_liquid.primary_temperature_out_K,
            pressure_in_Pa=intercooler_air_liquid.primary_p_out_Pa,
            relative_humidity=_params_humidifier.dry_air_rh_in
        )
        air_filter.pressure_drop = air_filter.get_pressure_drop()
        air_filter.pressure_out = air_filter.pressure_in_Pa - air_filter.pressure_drop

        # Instantiate the humidifier with the latest intercooler output as dry air inlet conditions
        humidifier = Humidifier(
            dry_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
            o2_mass_flow_rate=depleted_o2,
            dry_air_temperature_in_K=intercooler_air_liquid.primary_temperature_out_K,
            dry_air_rh_in=_params_humidifier.dry_air_rh_in,
            dry_air_temperature_out_K=intercooler_air_liquid.primary_temperature_out_K + 3,
            dry_air_pressure_out_Pa=inputs.pressures_Pa["PTC7"],
            wet_air_temperature_in_K=inputs.temperatures_K["TTC9"],
            wet_air_pressure_in_Pa=inputs.pressures_Pa["PTC9"],
            wet_air_rh_in=_params_humidifier.dry_air_rh_in,
            wet_air_temperature_out_K=inputs.temperatures_K["TTC10"]
        )

        # Calculate humidifier parameters
        humidifier.dry_mass_flow_slpm = humidifier.convert_kg_s_to_slpm(dry_air_mass_flow_kg_s)
        humidifier.wet_air_pressure_out_Pa = humidifier.wet_air_pressure_in_Pa - humidifier.interpolate_wet_pressure_drop()
        humidifier.dry_air_pressure_in_Pa = humidifier.dry_air_pressure_out_Pa + humidifier.interpolate_dry_pressure_drop()

        # Calculate efficiency of water transfer in the humidifier
        humidifier.efficiency = humidifier.get_efficiency()

        # Calculate new compressor outlet pressure based on humidifier’s dry air inlet pressure
        new_compressor_pressure_out_Pa = humidifier.dry_air_pressure_out_Pa + humidifier.interpolate_dry_pressure_drop() + air_filter.pressure_drop + intercooler_air_liquid.pressure_drop

        # Check if values have converged
        if abs(compressor.pressure_out_Pa - new_compressor_pressure_out_Pa) < tolerance:
            converged = True
        else:
            compressor.pressure_out_Pa = new_compressor_pressure_out_Pa  # Update for next iteration

    if not converged:
        print("Warning: Solution did not converge within the maximum number of iterations")

    #Start calculating with updated parameters after iteration
    compressor.power_W = compressor.calculate_power()
    # Re-instantiate the intercooler, air filter and humidifier with final compressor outlet conditions after convergence
    intercooler_air_liquid = Intercooler(
        efficiency=_params_intercooler.efficiency,
        primary_fluid="Air", coolant_fluid="INCOMP::MEG-50%",
        primary_p_in_Pa=compressor.pressure_out_Pa,
        primary_T_in_K=compressor.temperature_out_K,
        primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
        coolant_mdot_in_kg_s=_params_intercooler.coolant_mdot_in_kg_s,
        coolant_T_in_K=inputs.temperatures_K["T_cool"]
    )
    intercooler_air_liquid.primary_temperature_out_K = intercooler_air_liquid.calculate_primary_T_out()
    intercooler_air_liquid.deltaT = intercooler_air_liquid.primary_T_in_K - intercooler_air_liquid.primary_temperature_out_K
    intercooler_air_liquid.coolant_temperature_out_K = intercooler_air_liquid.calculate_coolant_T_out()
    intercooler_air_liquid.pressure_drop = intercooler_air_liquid.get_interpolated_pressure_drop()
    intercooler_air_liquid.primary_p_out_Pa = intercooler_air_liquid.primary_p_in_Pa  - intercooler_air_liquid.get_interpolated_pressure_drop()
    intercooler_air_liquid.primary_Qdot_W = intercooler_air_liquid.calculate_heat_flux()
    # Instantiate the air filter
    air_filter = FuelCellAirFilter(
        air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        temperature_in_K=intercooler_air_liquid.primary_temperature_out_K,
        pressure_in_Pa=intercooler_air_liquid.primary_p_out_Pa,
        relative_humidity=_params_humidifier.dry_air_rh_in
    )
    air_filter.pressure_drop = air_filter.get_pressure_drop()
    air_filter.pressure_out = air_filter.pressure_in_Pa - air_filter.pressure_drop

    humidifier = Humidifier(
        dry_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        o2_mass_flow_rate=depleted_o2,
        dry_air_temperature_in_K=intercooler_air_liquid.primary_temperature_out_K,
        dry_air_rh_in=_params_humidifier.dry_air_rh_in,
        dry_air_temperature_out_K=intercooler_air_liquid.primary_temperature_out_K + 3,
        dry_air_pressure_out_Pa=inputs.pressures_Pa["PTC7"],
        wet_air_temperature_in_K=inputs.temperatures_K["TTC9"],
        wet_air_pressure_in_Pa=inputs.pressures_Pa["PTC9"],
        wet_air_rh_in=_params_humidifier.dry_air_rh_in,
        wet_air_temperature_out_K=inputs.temperatures_K["TTC10"]
    )

    # Convert dry air mass flow rate from kg/s to standard liters per minute
    humidifier.dry_mass_flow_slpm = humidifier.convert_kg_s_to_slpm(dry_air_mass_flow_kg_s)
    humidifier.wet_air_pressure_out_Pa = humidifier.wet_air_pressure_in_Pa - humidifier.interpolate_wet_pressure_drop()
    humidifier.dry_air_pressure_in_Pa = humidifier.dry_air_pressure_out_Pa + humidifier.interpolate_dry_pressure_drop()

    # Calculate the humidifier's dry and wet inlet mass flows
    humidifier.drymassin = humidifier.calculate_dry_inlet_mass_flows()
    humidifier.wetmassin = humidifier.calculate_wet_inlet_mass_flows()

    # Calculate water transfer rate and outlet mass flows in the humidifier
    humidifier.m_dot_water_trans = humidifier.calculate_water_transfer_rate()
    humidifier.drymassout = humidifier.calculate_dry_outlet_mass_flows()
    humidifier.wetmassout = humidifier.calculate_wet_outlet_mass_flows()
    total_mass_flow_wet_out_kg_s = humidifier.wetmassout["total_mass_flow_wet_out"]

    ##TODO change target rh to a variable
    # Calculate target vapor transfer to achieve desired RH at Point 8
    target_vapor_transfer_kg_s = humidifier.calculate_target_vapor_transfer(inputs.temperatures_K["TTC8"],0.50)

    # Use the `calculate_vapor_transfer` method to determine the required dry air mass flow
    humidifier_mass_flow_kg_s, efficiency = humidifier.calculate_vapor_transfer(target_vapor_transfer_kg_s)

    # Calculate bypass flow
    bypass_mass_flow_kg_s = intercooler_air_liquid.primary_mdot_in_kg_s - humidifier_mass_flow_kg_s

    humidifier.RH_wet_out = 100 * humidifier.calculate_relative_humidity_outlet_wet()

    humidifier.total_mass_flow_wet_out_kg_s = humidifier.wetmassout["total_mass_flow_wet_out"]

    valve = Valve(
        total_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        pressure_input_pa=humidifier.dry_air_pressure_in_Pa,
        pressure_output_pa=inputs.pressures_Pa["PTC8"]
    )

    # Find the valve opening percentage for the desired bypass flow
    valve_position = valve.find_valve_position_for_target_flow(bypass_mass_flow_kg_s*1000)

    # Instantiate the water separator with the humidifier's wet outlet conditions
    # Instantiate the water separator
    water_separator = WaterSeparator(
        air_mass_flow_kg_s=humidifier.total_mass_flow_wet_out_kg_s,
        temperature_in_K=humidifier.wet_air_temperature_out_K,
        pressure_in_Pa=humidifier.wet_air_pressure_out_Pa,
        relative_humidity=humidifier.calculate_relative_humidity_outlet_wet()
    )
    water_separator.pressure_drop = water_separator.get_pressure_drop()
    water_separator.pressure_out = water_separator.pressure_in_Pa - water_separator.pressure_drop

    # Instantiate the turbine with parameters based on humidifier output and input
    turbine = Turbine(
        mass_estimator=_mass_estimator,
        temperature_in_K=inputs.temperatures_K["TTC13"],
        pressure_in_Pa=humidifier.wet_air_pressure_out_Pa,
        pressure_out_Pa=inputs.pressures_Pa["PTC1"],
        air_mass_flow_kg_s=humidifier.wetmassout["total_mass_flow_wet_out"],
        turbine_map=_params_turbine.turbine_map
    )

    # Calculate turbine output temperature, efficiency, and power
    turbine.temperature_out_K = turbine.calculate_T_out()
    turbine.isentropic_efficiency = turbine.get_efficiency()
    turbine.power_W = turbine.calculate_power()

    # Output results summary
    print("=" * 50)
    print(f"Simulation Results for Flight Level: {flight_level}")
    print("=" * 50)

    print("\nCompressor Results:")
    print("-" * 20)
    print(f"Outlet Temperature: {compressor.temperature_out_K:.2f} K ({compressor.temperature_out_K - 273:.2f} °C)")
    print(f"Outlet Pressure: {compressor.pressure_out_Pa / 1e5:.4f} bara")
    print(f"Power: {compressor.power_W/ 1000:.2f} kW")
    print(f"Air Mass Flow Rate: {compressor.air_mass_flow_kg_s:.4f} kg/s")

    print("\nIntercooler Results:")
    print("-" * 20)
    print(f"Primary Outlet Temperature: {intercooler_air_liquid.primary_temperature_out_K:.2f} K ({intercooler_air_liquid.primary_temperature_out_K -273:.2f} °C)")
    print(f"Temperature Difference Across In Intercooler: {intercooler_air_liquid.deltaT:.2f} K")
    print(f"Pressure Drop: {intercooler_air_liquid.pressure_drop:.2f} Pa")
    print(f"Primary side Heat Transfer: {intercooler_air_liquid.primary_Qdot_W/1000:.2f} kW")

    print("\nAir Filter Results:")
    print("-" * 20)
    print(f"Pressure Drop: {air_filter.pressure_drop:.2f} Pa")
    print(f"Outlet Pressure: {air_filter.pressure_out:.2f} Pa")

    print("\nHumidifier Results:")
    print("-" * 20)
    print(f"Dry Air Inlet Pressure: {humidifier.dry_air_pressure_in_Pa:.2f} Pa")
    print(f"Wet Air Outlet Pressure: {humidifier.wet_air_pressure_out_Pa:.2f} Pa")
    print(f"Target Vapor Transfer at Point 8: {target_vapor_transfer_kg_s:.6f} kg/s")
    print(f"Converged Humidifier Mass Flow (through humidifier): {humidifier_mass_flow_kg_s:.4f} kg/s")
    print(f"Bypass Mass Flow (through valve HBV-C-320): {bypass_mass_flow_kg_s:.4f} kg/s")
    print(f"Interpolated Efficiency: {efficiency:.2f}%")

    #print(f"Water Transfer Rate: {humidifier.m_dot_water_trans:.4f} kg/s")
    print(
        f"Total Wet Outlet Mass Flow: {humidifier.wetmassout['total_mass_flow_wet_out'] * 1000:.2f} g/s")  # Converted to g/s for clarity
    #print(f"Relative Humidity at Dry Outlet: {humidifier.RH_dry_out:.2f} %")
    print(f"Relative Humidity at Wet Outlet: {humidifier.RH_wet_out:.2f} %")

    print("\nBypass Valve 320 Results:")
    print("-" * 20)
    if valve_position is not None:
        print(f"Valve opening percentage to achieve {bypass_mass_flow_kg_s:.4f} g/s bypass flow: {valve_position}%")
    else:
        print("No suitable valve opening percentage found to achieve the target bypass flow.")

    print("\nWater Separator Results:")
    print("-" * 20)
    print(f"Pressure Drop: {water_separator.pressure_drop:.2f} Pa")
    print(f"Outlet Pressure: {water_separator.pressure_out:.2f} Pa")

    print("\nTurbine Results:")
    print("-" * 20)
    print(f"Outlet Temperature: {turbine.temperature_out_K:.2f} K ({turbine.temperature_out_K-273:.2f} °C)")
    print(f"Efficiency: {100*turbine.isentropic_efficiency:.2f} %")
    print(f"Power: {turbine.power_W / 1000:.2f} kW")

    # Define the file path where you want to save the output
    output_file_path = "simulation_results.txt"

    # Open the file in write mode
    with open(output_file_path, "w") as file:
        # Output results summary
        file.write("=" * 50 + "\n")
        file.write(f"Simulation Results for Flight Level: {flight_level}\n")
        file.write("=" * 50 + "\n\n")

        file.write("Compressor Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Outlet Temperature: {compressor.temperature_out_K:.2f} K\n")
        file.write(f"Outlet Pressure: {compressor.pressure_out_Pa / 1e5:.4f} bara\n")
        file.write(f"Power: {compressor.power_W / 1000:.2f} kW\n")
        file.write(f"Air Mass Flow Rate: {compressor.air_mass_flow_kg_s:.4f} kg/s\n\n")

        file.write("Intercooler Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Primary Outlet Temperature: {intercooler_air_liquid.primary_temperature_out_K:.2f} K\n")
        file.write(f"Temperature Difference Across Intercooler: {intercooler_air_liquid.deltaT:.2f} K\n")
        file.write(f"Pressure Drop: {intercooler_air_liquid.pressure_drop:.2f} Pa\n")
        file.write(f"Primary side Heat Transfer: {intercooler_air_liquid.primary_Qdot_W / 1000:.2f} kW\n\n")

        file.write("Air Filter Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Pressure Drop: {air_filter.pressure_drop:.2f} Pa\n")
        file.write(f"Outlet Pressure: {air_filter.pressure_out:.2f} Pa\n\n")

        file.write("Humidifier Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Dry Air Inlet Pressure: {humidifier.dry_air_pressure_in_Pa:.2f} Pa\n")
        file.write(f"Wet Air Outlet Pressure: {humidifier.wet_air_pressure_out_Pa:.2f} Pa\n")
        file.write(f"Target Vapor Transfer at Point 8: {target_vapor_transfer_kg_s:.6f} kg/s\n")
        file.write(f"Converged Humidifier Mass Flow (through humidifier): {humidifier_mass_flow_kg_s:.4f} kg/s\n")
        file.write(f"Interpolated Efficiency: {efficiency:.2f}%\n")
        file.write(f"Total Wet Outlet Mass Flow: {humidifier.wetmassout['total_mass_flow_wet_out'] * 1000:.2f} g/s\n")
        file.write(f"Relative Humidity at Wet Outlet: {humidifier.RH_wet_out:.2f} %\n\n")

        file.write("Bypass Valve 320 Results:\n")
        file.write("-" * 20 + "\n")
        if valve_position is not None:
            file.write(
                f"Valve opening percentage to achieve {bypass_mass_flow_kg_s:.4f} g/s bypass flow: {valve_position}%\n")
        else:
            file.write("No suitable valve opening percentage found to achieve the target bypass flow.\n\n")

        file.write("Water Separator Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Pressure Drop: {water_separator.pressure_drop:.2f} Pa\n")
        file.write(f"Outlet Pressure: {water_separator.pressure_out:.2f} Pa\n\n")

        file.write("Turbine Results:\n")
        file.write("-" * 20 + "\n")
        file.write(f"Efficiency: {100 * turbine.isentropic_efficiency:.2f} %\n")
        file.write(f"Power: {turbine.power_W / 1000:.2f} kW\n")

    print(f"Simulation results have been saved to {output_file_path}")


# Uncomment the following to run the simulation when the script is executed
if __name__ == "__main__":
    # Run simulation for a given flight level (e.g., 120 for 12,000 feet)
    simulate_cathode_architecture(flight_level=120)