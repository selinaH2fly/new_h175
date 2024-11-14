"""
Simulates the behavior of a cathode air supply system for a fuel cell at a given flight level.
The function models the performance of components like compressors, intercoolers, humidifiers,
and turbines, calculating key outputs such as temperature, pressure, humidity, and power.
"""

# System Architecture

# Import custom classes and functions
import cathode_model_run
import pandas as pd
from Components.compressor import Compressor
from Components.heat_exchanger import Intercooler
from Components.filter import FuelCellAirFilter
from Components.moist_exchanger import Humidifier
from Components.valve import Valve
from Components.water_separator import WaterSeparator
from Components.turbine import Turbine
from basic_physics import compute_air_mass_flow, compute_reacted_o2_mass_flow_kg_s, icao_atmosphere

# Function to simulate the architecture
def simulate_cathode_architecture(flight_level, compressor_map=None, stoich_cathode=1.6, current_A=600, cellcount=455):
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
    print(dry_air_mass_flow_kg_s)
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

    # Initial guess for intercooler outlet pressure
    intercooler_air_liquid_primary_p_out_Pa = inputs.pressures_Pa["PTC4"]
    air_filter_pressure_out_Pa = inputs.pressures_Pa["PTC4"]

    while not converged and iteration < max_iterations:
        iteration += 1

        # Step 1: Calculate compressor outlet temperature based on current outlet pressure
        compressor.temperature_out_K = compressor.calculate_T_out()

        # Step 2: Instantiate and update the intercooler with the compressor's outlet conditions
        intercooler_air_liquid = Intercooler(
            efficiency=_params_intercooler.efficiency,
            effectiveness=_params_intercooler.effectiveness,
            primary_fluid="Air",
            coolant_fluid="INCOMP::MEG-50%",
            primary_p_in_Pa=compressor.pressure_out_Pa,
            primary_T_in_K=compressor.temperature_out_K,
            primary_T_out_K=inputs.temperatures_K["TTC4"],
            primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,
            coolant_mdot_in_kg_s=_params_intercooler.coolant_mdot_in_kg_s,
            coolant_T_in_K=inputs.temperatures_K["T_cool"]
        )

        # Use the current estimate of pout to calculate mean pressure and temperature
        intercooler_air_liquid.primary_p_out_Pa = intercooler_air_liquid_primary_p_out_Pa
        intercooler_air_liquid.mean_p_in_Pa = (
                                                      intercooler_air_liquid.primary_p_in_Pa + intercooler_air_liquid.primary_p_out_Pa) / 2
        intercooler_air_liquid.mean_T_in_K = (
                                                     intercooler_air_liquid.primary_T_in_K + intercooler_air_liquid.primary_T_out_K) / 2

        # Calculate intercooler pressure drop
        intercooler_air_liquid.pressure_drop = intercooler_air_liquid.get_interpolated_pressure_drop(
            intercooler_air_liquid.mean_T_in_K, intercooler_air_liquid.mean_p_in_Pa
        )

        # Step 3: Set up the air filter with the latest calculated pressure out
        air_filter = FuelCellAirFilter(
            air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
            temperature_in_K=intercooler_air_liquid.primary_T_out_K,
            pressure_in_Pa=intercooler_air_liquid_primary_p_out_Pa,  # Set inlet pressure here
            temperature_out_K=intercooler_air_liquid.primary_T_out_K,
            relative_humidity=_params_humidifier.dry_air_rh_in,
            pressure_out_Pa=air_filter_pressure_out_Pa  # Initialize with current value
        )

        # Calculate and update the air filter pressure drop
        air_filter.pressure_drop = air_filter.get_pressure_drop()
        air_filter_pressure_out_Pa = air_filter.pressure_in_Pa - air_filter.pressure_drop

        # Step 4: Instantiate and calculate humidifier properties
        humidifier = Humidifier(
            dry_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
            o2_mass_flow_rate=depleted_o2,
            dry_air_temperature_in_K=intercooler_air_liquid.primary_T_out_K,
            dry_air_rh_in=_params_humidifier.dry_air_rh_in,
            dry_air_temperature_out_K=intercooler_air_liquid.primary_T_out_K + 3,
            dry_air_pressure_out_Pa=inputs.pressures_Pa["PTC7"],
            wet_air_temperature_in_K=inputs.temperatures_K["TTC9"],
            wet_air_pressure_in_Pa=inputs.pressures_Pa["PTC9"],
            wet_air_rh_in=_params_humidifier.dry_air_rh_in,
            wet_air_temperature_out_K=inputs.temperatures_K["TTC10"]
        )

        humidifier.dry_mass_flow_slpm = humidifier.convert_kg_s_to_slpm(humidifier.dry_air_mass_flow_kg_s)
        humidifier.wet_air_pressure_out_Pa = humidifier.wet_air_pressure_in_Pa - humidifier.interpolate_wet_pressure_drop()
        humidifier.dry_air_pressure_in_Pa = humidifier.dry_air_pressure_out_Pa + humidifier.interpolate_dry_pressure_drop()
        humidifier.efficiency = humidifier.get_efficiency()

        # Step 5: Calculate new compressor outlet pressure based on humidifier's dry air inlet pressure
        new_compressor_pressure_out_Pa = (
                humidifier.dry_air_pressure_out_Pa +
                humidifier.interpolate_dry_pressure_drop() +
                air_filter.pressure_drop +
                intercooler_air_liquid.pressure_drop
        )

        # Update intercooler outlet pressure and air filter outlet pressure
        intercooler_air_liquid_primary_p_out_Pa = humidifier.dry_air_pressure_in_Pa + air_filter.pressure_drop
        air_filter_pressure_out_Pa = humidifier.dry_air_pressure_in_Pa

        # Step 6: Check convergence
        if abs(compressor.pressure_out_Pa - new_compressor_pressure_out_Pa) < tolerance:
            converged = True
        else:
            compressor.pressure_out_Pa = new_compressor_pressure_out_Pa  # Update for next iteration

    if not converged:
        print("Warning: Solution did not converge within the maximum number of iterations")

    # Proceed with calculations using final conditions
    compressor.power_W = compressor.calculate_power()

    # Re-instantiate components with final conditions for accuracy in outputs
    intercooler_air_liquid = Intercooler(
        efficiency=_params_intercooler.efficiency,
        effectiveness=_params_intercooler.effectiveness,
        primary_fluid="Air", coolant_fluid="INCOMP::MEG-50%",
        primary_p_in_Pa=compressor.pressure_out_Pa,
        primary_T_in_K=compressor.temperature_out_K,
        primary_T_out_K=inputs.temperatures_K["TTC4"],
        primary_mdot_in_kg_s=compressor.air_mass_flow_kg_s,

    )

    # Use the final stored outlet pressure from the iteration
    intercooler_air_liquid.primary_p_out_Pa = intercooler_air_liquid_primary_p_out_Pa
    intercooler_air_liquid.mean_p_in_Pa = (intercooler_air_liquid.primary_p_in_Pa + intercooler_air_liquid.primary_p_out_Pa) / 2
    intercooler_air_liquid.mean_T_in_K = (intercooler_air_liquid.primary_T_in_K + intercooler_air_liquid.primary_T_out_K) / 2

    # Calculate the pressure drop
    intercooler_air_liquid.pressure_drop = intercooler_air_liquid.get_interpolated_pressure_drop(intercooler_air_liquid.mean_T_in_K,
                                            intercooler_air_liquid.mean_p_in_Pa)

    intercooler_air_liquid.deltaT = intercooler_air_liquid.primary_T_in_K - intercooler_air_liquid.primary_T_out_K

    intercooler_air_liquid.coolant_temperature_in_K = intercooler_air_liquid.calculate_coolant_T_in()

    intercooler_air_liquid.primary_Qdot_W = intercooler_air_liquid.calculate_heat_flux()
    # Instantiate the air filter with an initial guess for pressure_out_Pa
    air_filter = FuelCellAirFilter(
        air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        temperature_in_K=intercooler_air_liquid.primary_T_out_K,
        temperature_out_K=intercooler_air_liquid.primary_T_out_K,
        pressure_in_Pa=intercooler_air_liquid.primary_p_out_Pa,
        pressure_out_Pa=inputs.pressures_Pa["PTC4"] , # Provide an initial value for pressure_out_Pa
        relative_humidity=_params_humidifier.dry_air_rh_in
    )

    # Calculate pressure drop based on initial or updated conditions
    air_filter.pressure_drop = air_filter.get_pressure_drop()

    humidifier = Humidifier(
        dry_air_mass_flow_kg_s=intercooler_air_liquid.primary_mdot_in_kg_s,
        o2_mass_flow_rate=depleted_o2,
        dry_air_temperature_in_K=intercooler_air_liquid.primary_T_out_K,
        dry_air_rh_in=_params_humidifier.dry_air_rh_in,
        dry_air_temperature_out_K=intercooler_air_liquid.primary_T_out_K + 3,
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

    humidifier.initial_efficiency  = humidifier.get_efficiency()
    humidifier.target_RH =inputs.target_RH
    ##TODO change target rh to a variable
    # Calculate target vapor transfer to achieve desired RH at Point 8
    target_vapor_transfer_kg_s = humidifier.calculate_target_vapor_transfer(inputs.temperatures_K["TTC8"],humidifier.target_RH)

    def iterate_for_mixed_RH():
        current_efficiency = 0.35  # Initial efficiency
        tolerance = 0.01  # Convergence tolerance for RH
        max_iterations = 50  # Limit to avoid infinite loops

        RH_mix = 0  # Default value for RH_mix
        efficiency_from_map = 0  # Default value for efficiency_from_map
        m_dot_vap_dry_out = 0  # Default value for vapor dry out
        updated_vapor_dry_out_kg_s = 0  # Default updated vapor dry out mass flow
        RH_vapor_dry_out = 0  # Default RH for vapor dry out
        Valve_vapor_out_kg_s = 0  # Default valve vapor mass flow
        Valve_air_flow_kg_s = 0  # Default valve air flow mass flow
        Valve_total_flow_kg_s = 0  # Default valve total flow mass flow

        for iteration in range(max_iterations):
            # Step 1: Calculate vapor dry out based on current efficiency
            m_dot_vap_dry_out = current_efficiency * humidifier.wetmassin[
                'm_dot_vap_wet_in']  # Efficiency = vapor dry out / vapor wet in

            target_vapor_kg_s = target_vapor_transfer_kg_s

            # Step 2: Calculate Valve vapor mass flow using mass balance
            Valve_vapor_out_kg_s = max(0, target_vapor_kg_s - m_dot_vap_dry_out)  # Prevent negative valve vapor flow

            # Step 3: Calculate Valve air mass flow (using RH, T, P, vapor mass flow)
            Valve_partial_pressure_vapor_Pa = humidifier.calculate_partial_pressure(
                humidifier.dry_air_temperature_out_K, humidifier.dry_air_rh_in)
            Valve_Y_out = (0.622 * Valve_partial_pressure_vapor_Pa) / (
                    humidifier.dry_air_pressure_out_Pa - Valve_partial_pressure_vapor_Pa)  # Specific humidity for Flow 2
            Valve_air_flow_kg_s = Valve_vapor_out_kg_s / Valve_Y_out  # Air mass flow for Flow 2

            # Step 4: Calculate total flow for Flow 2 (air + vapor)
            Valve_total_flow_kg_s = Valve_air_flow_kg_s + Valve_vapor_out_kg_s

            # Step 5: Update dry air mass flow for Dry In (given total mass flow for Dry In)
            humidifier.dry_air_mass_flow_kg_s = intercooler_air_liquid.primary_mdot_in_kg_s - Valve_total_flow_kg_s

            dryin_partial_pressure_vapor_Pa = humidifier.calculate_partial_pressure(
                humidifier.dry_air_temperature_in_K, humidifier.dry_air_rh_in)
            dryin_Y_out = (0.622 * dryin_partial_pressure_vapor_Pa) / (
                    humidifier.dry_air_pressure_in_Pa - dryin_partial_pressure_vapor_Pa)

            m_dot_vapor_dry_in = dryin_Y_out * humidifier.dry_air_mass_flow_kg_s

            m_dot_air_dry_in = humidifier.dry_air_mass_flow_kg_s - m_dot_vapor_dry_in

            # Step 7: Get updated efficiency from the map based on air flow
            efficiency_from_map = humidifier.get_efficiency() / 100  # Efficiency based on air flow
            updated_vapor_dry_out_kg_s = efficiency_from_map * humidifier.wetmassin['m_dot_vap_wet_in']

            # Step 8: Calculate RH for vapor dry out
            Y_vapor_dry_out = updated_vapor_dry_out_kg_s / m_dot_air_dry_in  # Specific humidity

            # Step 9: Calculate partial vapor pressure (P_vapor) for vapor dry out
            P_vapor_dry_out = (Y_vapor_dry_out * humidifier.dry_air_pressure_out_Pa) / (
                    0.622 + Y_vapor_dry_out)  # in Pa

            # Step 10: Calculate RH for vapor dry out
            P_sat = humidifier.calculate_saturation_pressure(humidifier.dry_air_temperature_out_K)
            RH_vapor_dry_out = (P_vapor_dry_out / P_sat) * 100  # RH for vapor dry out

            # Step 11: Update RH for the mix (mass balance of vapor and air)
            total_vapor_kg_s = m_dot_vap_dry_out + Valve_vapor_out_kg_s
            total_air_kg_s = m_dot_air_dry_in + Valve_air_flow_kg_s
            Y_mix = total_vapor_kg_s / total_air_kg_s
            P_vapor_mix = (Y_mix * humidifier.dry_air_pressure_out_Pa) / (0.622 + Y_mix)
            RH_mix = (P_vapor_mix / P_sat) * 100  # RH for the mix

            # Check if the mix RH is close enough to the target (convergence condition)
            if abs(RH_mix - humidifier.target_RH) < tolerance:
                print(f"Converged to target RH {humidifier.target_RH}% after {iteration + 1} iterations.")
                break

            # Update the efficiency for the next iteration
            current_efficiency = 0.5 * current_efficiency + 0.5 * efficiency_from_map

        # Return the calculated values, including updated humidifier parameters
        return RH_mix, efficiency_from_map, Valve_total_flow_kg_s, humidifier.dry_air_mass_flow_kg_s, RH_vapor_dry_out

    # Call the iterate_for_mixed_RH function to get the updated humidifier parameters and RH
    RH_mix, efficiency_from_map, Valve_vapor_out_kg_s, humidifier.dry_air_mass_flow_kg_s, RH_vapor_dry_out = iterate_for_mixed_RH()
    humidifier.efficiency = efficiency_from_map
    humidifier.dry_air_mass_flow_kg_s = humidifier.dry_air_mass_flow_kg_s  # Use updated dry air mass flow
    humidifier.m_dot_water_trans = humidifier.calculate_water_transfer_rate(humidifier.efficiency)
    humidifier.wetmassout = humidifier.calculate_wet_outlet_mass_flows(humidifier.efficiency)

    # Calculate bypass flow
    bypass_mass_flow_kg_s = intercooler_air_liquid.primary_mdot_in_kg_s - humidifier.dry_air_mass_flow_kg_s

    humidifier.total_mass_flow_wet_out_kg_s = humidifier.wetmassout["total_mass_flow_wet_out"]

    valve = Valve(
        total_air_mass_flow_kg_s=bypass_mass_flow_kg_s,
        pressure_input_pa=humidifier.dry_air_pressure_in_Pa,
        pressure_output_pa=inputs.pressures_Pa["PTC8"]
    )

    # Find the valve opening percentage for the desired bypass flow
    valve_position = valve.get_valve_opening_from_map()

    # Instantiate the water separator with the humidifier's wet outlet conditions
    # Instantiate the water separator
    water_separator = WaterSeparator(
        air_mass_flow_kg_s=humidifier.total_mass_flow_wet_out_kg_s,
        temperature_in_K=humidifier.wet_air_temperature_out_K,
        pressure_in_Pa=humidifier.wet_air_pressure_out_Pa,
        relative_humidity=humidifier.calculate_relative_humidity_outlet_wet(humidifier.efficiency)
    )
    water_separator.pressure_drop = water_separator.get_pressure_drop()
    water_separator.pressure_out = water_separator.pressure_in_Pa - water_separator.pressure_drop

    # Instantiate the turbine with parameters based on humidifier output and input
    turbine = Turbine(
        mass_estimator=_mass_estimator,
        isentropic_efficiency=_params_turbine.isentropic_efficiency,
        temperature_in_K=inputs.temperatures_K["TTC10"],
        pressure_in_Pa=water_separator.pressure_out,
        pressure_out_Pa=inputs.pressures_Pa["PTC14"],
        air_mass_flow_kg_s=humidifier.wetmassout["total_mass_flow_wet_out"],
        turbine_map=None)

    # Calculate turbine output temperature, efficiency, and power
    turbine.temperature_out_K = turbine.calculate_T_out()
    turbine.power_W = turbine.calculate_power()


    # Dictionary to store the results with converted units
    results = {
        "Compressor Inlet Temperature": f"{compressor.temperature_in_K - 273.15:.2f} °C",
        "Compressor Outlet Temperature": f"{compressor.temperature_out_K - 273.15:.2f} °C",
        "Compressor Inlet Pressure": f"{compressor.pressure_in_Pa/ 1e5:.2f} bara",
        "Compressor Outlet Pressure": f"{compressor.pressure_out_Pa / 1e5:.2f} bara",
        "Compressor Power": f"{compressor.power_W / 1000:.2f} kW",
        "Compressor Air Mass Flow Rate": f"{compressor.air_mass_flow_kg_s * 1000:.2f} g/s",


        "Intercooler Air-Liquid Primary(Warm) Temperature Difference": f"{intercooler_air_liquid.deltaT:.2f} K",
        "Intercooler Air-Liquid Primary(Warm) Pressure Drop": f"{intercooler_air_liquid.pressure_drop / 1e5:.4f} bara",
        "Intercooler Air-Liquid Primary(Warm) Outlet Pressure": f"{intercooler_air_liquid.primary_p_out_Pa / 1e5:.2f} bara",
        "Intercooler Air-Liquid Primary(Warm) Heat Transfer": f"{intercooler_air_liquid.primary_Qdot_W/ 1000:.2f} kW",
        "Intercooler Air-Liquid Secondary(Cold) Inlet Temperature": f"{intercooler_air_liquid.coolant_temperature_in_K - 273.15:.2f} °C",

        "Air Filter Pressure Drop": f"{air_filter.pressure_drop / 1e5:.4f} bara",

        "Humidifier Dry Air Inlet Pressure": f"{humidifier.dry_air_pressure_in_Pa / 1e5:.2f} bara",
        "Humidifier Wet Air Outlet Pressure": f"{humidifier.wet_air_pressure_out_Pa / 1e5:.2f} bara",
        "Humidifier Total Dry Outlet Mass Flow": f"{humidifier.dry_air_mass_flow_kg_s * 1000:.2f} g/s",
        "Humidifier Water Transfer": f"{humidifier.m_dot_water_trans * 1000:.2f} g/s",
        "Humidifier Efficiency": f"{humidifier.efficiency*100:.2f} %",
        "Humidifier Total Wet Outlet Mass Flow": f"{humidifier.wetmassout['total_mass_flow_wet_out'] * 1000:.2f} g/s",
        "Valve Bypass Flow": f"{bypass_mass_flow_kg_s * 1000:.2f} g/s",
        "Valve Position": f"{valve_position:.2f} %",

        "Water Separator Pressure Drop": f"{water_separator.pressure_drop / 1e5:.4f} bara",
        "Water Separator Outlet Pressure": f"{water_separator.pressure_out / 1e5:.2f} bara",

        "Turbine Inlet Temperature": f"{turbine.temperature_in_K - 273.15:.2f} °C",
        "Turbine Outlet Temperature": f"{turbine.temperature_out_K - 273.15:.2f} °C",
        "Turbine Efficiency": f"{turbine.isentropic_efficiency * 100:.2f} %",
        "Turbine Power": f"{turbine.power_W / 1000:.2f} kW",
        "Net Power": f"{(compressor.power_W - turbine.power_W) / 1000:.2f} kW",
    }

    # Return the results dictionary
    return results


# Code to run the simulation and save results to Excel in column format
if __name__ == "__main__":
    # Run the simulation
    results = simulate_cathode_architecture(flight_level=120)

    # Convert results to a DataFrame with two columns (one for labels and one for values with units)
    df = pd.DataFrame(list(results.items()), columns=["Parameter", "Value"])
    df.to_excel("simulation_results_oneIC.xlsx", index=False)
    print("Simulation results have been saved to 'simulation_results.xlsx'")