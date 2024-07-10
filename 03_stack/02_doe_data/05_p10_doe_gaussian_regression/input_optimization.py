import torch
import gpytorch
import numpy as np
from scipy.optimize import minimize, differential_evolution

def optimize_for_inputs(model, initial_guess=None, bounds=None, grid_resolution=100):
    """
    Optimize the efficiency predicted by the GPyTorch model.

    Parameters:
    - model: The trained GPyTorch model.
    - initial_guess: Initial guess for the optimizer. If None, the mean of the scaled data is used.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].
    - grid_resolution: Number of points to evaluate for the optimization grid.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    """

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            prediction = model(x_tensor).mean.numpy()
        # print(f"Evaluating at {x}, prediction: {-prediction}")  # Debug statement
        return -prediction  # We negate because we want to maximize

    # If no initial guess is provided, use the mean of bounds provided
    if initial_guess is None:
        if bounds is not None:
            initial_guess = np.mean(bounds, axis=1)
        else:
            raise ValueError("If no initial guess is provided, bounds must be specified.")
    
    # print(f"Initial guess: {initial_guess}")  # Debug statement
    # print(f"Bounds: {bounds}")  # Debug statement

    # Perform the optimization
    # result = minimize(objective_function, initial_guess, bounds=bounds, method='L-BFGS-B') # gradient-based algorithm
    result = differential_evolution(objective_function, bounds) # evolutionary algorithm

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    # print(f"Optimization result: {result}")  # Debug statement

    # Return the optimized prediction subject to the optimmal input
    optimal_target_scaled = -result.fun

    return optimal_input_scaled, optimal_target_scaled

