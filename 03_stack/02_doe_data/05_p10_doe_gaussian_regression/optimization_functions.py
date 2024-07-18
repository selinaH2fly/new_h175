# import libraries
import torch
import gpytorch
import numpy as np
from scipy.optimize import differential_evolution

# Import custom classes and functions
import parameters
from compressor import Compressor

def compute_air_mass_flow(stoichiometry, current_A, params_physics, cellcount=275):
    """
    Compute the air mass flow rate in kg/s.
    """

    # Calculate the air mass flow rate
    air_mass_flow_kg_s = current_A * cellcount * stoichiometry * params_physics.air_molar_mass / \
        (4 * params_physics.faraday * params_physics.oxygen_mol_fraction)

    return air_mass_flow_kg_s


def optimize_inputs_evolutionary(model, input_data_mean, input_data_std, target_data_mean, target_data_std, flight_level_100ft, cellcount=275, bounds=None, power_constraint_kW=None, penalty_weight=0.1, params_physics=None):
    """
    Optimize the (cell) voltage predicted by the GPyTorch model with a (cell) power constraint using differential evolution.

    Parameters:
    - model: The trained GPyTorch model.
    - power_constraint_value: The power constraint value per cell (voltage_cell * current).
    - initial_guess: Initial guess for the optimizer. If None, the mean of the scaled data is used.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].
    - penalty_weight: Weight for the penalty term in the objective function.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - optimal_target: The maximized target (eta_lhv) subject to the power constraint.
    """

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            eta_lhv = model(x_tensor).mean.item()
        current = x[0]

        # Denormalize current and voltage
        current = current * input_data_std[0] + input_data_mean[0]
        eta_lhv = eta_lhv * target_data_std + target_data_mean

        if power_constraint_kW is None:
            penalty = 0
        else:
            power_constraint = eta_lhv * params_physics.hydrogen_lhv_voltage_equivalent * cellcount * current - power_constraint_kW * 1000
            penalty = penalty_weight * (power_constraint**2)  # Squared term to ensure positive penalty

        result = -eta_lhv + penalty  # Negate voltage to maximize and add penalty for constraint violation

        return result

    # Instantiate the compressor object
    _params_physics = parameters.Physical_Parameters()
    _params_compressor = parameters.Compressor_Parameters()
    compressor = Compressor(_params_physics, isentropic_efficiency=_params_compressor.isentropic_efficiency, \
                            electric_efficiency=_params_compressor.electric_efficiency)
    
    # Perform the optimization using differential evolution
    result = differential_evolution(objective_function, bounds)

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    # Denormalize the optimal input and target variables
    optimal_input = optimal_input_scaled * np.array(input_data_std) + np.array(input_data_mean)
    optimal_target = -result.fun * target_data_std + target_data_mean

    # Test the compressor power function
    air_mass_flow_kg_s = compute_air_mass_flow(stoichiometry=optimal_input[2], current_A=optimal_input[0], params_physics=_params_physics)
    compressor_power = compressor.compressor_power(air_mass_flow_kg_s, pressure_out_Pa=optimal_input[3]*1e5, flight_level_100ft=flight_level_100ft)

    # Evaluate the optimal target value
    # x_tensor = torch.tensor(optimal_input_scaled, dtype=torch.float).unsqueeze(0)
    # model.eval()
    # with torch.no_grad(), gpytorch.settings.fast_pred_var():
    #     optimal_target_scaled = model(x_tensor).mean.item()

    return optimal_input, optimal_target, compressor_power
