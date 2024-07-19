# Import libraries
import torch
import gpytorch
import numpy as np
from scipy.optimize import differential_evolution

# Import custom classes and functions
import parameters
from compressor import Compressor

def optimize_inputs_evolutionary(model, input_data_mean, input_data_std, target_data_mean, target_data_std, flight_level_100ft, cellcount=275, bounds=None, power_constraint_kW=None, penalty_weight=0.1, params_physics=None):
    """
    Optimize the (cell) voltage predicted by the GPyTorch model with a (cell) power constraint using differential evolution.

    Parameters:
    - model: The trained GPyTorch model.
    - input_data_mean: Mean values for input data normalization.
    - input_data_std: Standard deviation values for input data normalization.
    - target_data_mean: Mean values for target data normalization.
    - target_data_std: Standard deviation values for target data normalization.
    - flight_level_100ft: Flight level in 100 feet units.
    - cellcount: Number of cells.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].
    - power_constraint_kW: Power constraint in kilowatts.
    - penalty_weight: Weight for the penalty term in the objective function.
    - params_physics: Physical parameters.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - optimal_target: The maximized target (eta_lhv) subject to the power constraint.
    - compressor_power: The power of the compressor.
    """

    # Instantiate the compressor object
    _params_physics = parameters.Physical_Parameters()
    _params_compressor = parameters.Compressor_Parameters()
    compressor = Compressor(_params_physics, isentropic_efficiency=_params_compressor.isentropic_efficiency, 
                            electric_efficiency=_params_compressor.electric_efficiency)

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            eta_lhv = model(x_tensor).mean.item()

        # Denormalize
        optimal_input = x * np.array(input_data_std) + np.array(input_data_mean)
        eta_lhv = eta_lhv * target_data_std + target_data_mean

        # Compute the compressor power
        air_mass_flow_kg_s = compressor.compute_air_mass_flow(stoichiometry=optimal_input[2], current_A=optimal_input[0], cellcount=cellcount)
        compressor_power = compressor.compressor_power(air_mass_flow_kg_s, pressure_out_Pa=optimal_input[3]*1e5, flight_level_100ft=flight_level_100ft)

        if power_constraint_kW is None:
            penalty = 0
        else:
            power_constraint = eta_lhv * params_physics.hydrogen_lhv_voltage_equivalent * cellcount * optimal_input[0] - compressor_power - \
                power_constraint_kW * 1000
            penalty = penalty_weight * (power_constraint**2)  # Squared term to ensure positive penalty

        result = -eta_lhv + penalty  # Negate eta_lhv to maximize and add penalty for constraint violation

        return result

    # Perform the optimization using differential evolution
    result = differential_evolution(objective_function, bounds, maxiter=1000, tol=1e-4, disp=True, seed=42)

    # Print the stopping criterion
    print(f'\n{result.message}')

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    # Denormalize the optimal input and target variables
    optimal_input = optimal_input_scaled * np.array(input_data_std) + np.array(input_data_mean)
    optimal_target = -result.fun * target_data_std + target_data_mean

    # Test the stack power s.t. the optimal input variables
    stack_power_kW = optimal_input[0] * optimal_target * cellcount * params_physics.hydrogen_lhv_voltage_equivalent / 1000

    # Test the compressor power function with the optimal input
    air_mass_flow_kg_s = compressor.compute_air_mass_flow(stoichiometry=optimal_input[2], current_A=optimal_input[0], cellcount=cellcount)
    compressor_power_kW = compressor.compressor_power(air_mass_flow_kg_s, pressure_out_Pa=optimal_input[3]*1e5, flight_level_100ft=flight_level_100ft) / 1000

    return optimal_input, optimal_target, stack_power_kW, compressor_power_kW
