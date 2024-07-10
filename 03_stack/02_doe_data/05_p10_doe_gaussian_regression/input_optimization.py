import torch
import gpytorch
import numpy as np
from scipy.optimize import minimize, differential_evolution, NonlinearConstraint

def optimize_inputs_gradient_based(model, initial_guess=None, bounds=None, power_constraint_value=None):
    """
    Optimize the efficiency predicted by the GPyTorch model.

    Parameters:
    - model: The trained GPyTorch model.
    - initial_guess: Initial guess for the optimizer. If None, the mean of the scaled data is used.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].

    Returns:
    - optimal_input: The optimal input values in the original scale.
    """

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            prediction = model(x_tensor).mean.numpy()
        return -prediction  # We negate because we want to maximize
    
    # Define the constraint function
    if power_constraint_value is not None:
        def constraint_function(x):
            return power_constraint(x)
    else:
        constraint_function = None

    def power_constraint(x):
        voltage = model(torch.tensor(x, dtype=torch.float).unsqueeze(0)).mean.item()
        current = x[0]
        return voltage * current - power_constraint_value
    
    # Nonlinear constraint
    nonlinear_constraint = NonlinearConstraint(power_constraint, 0, 0)

    # If no initial guess is provided, use the mean of bounds provided
    if initial_guess is None:
        if bounds is not None:
            initial_guess = np.mean(bounds, axis=1)
        else:
            raise ValueError("If no initial guess is provided, bounds must be specified.")

    # Perform the optimization
    result = minimize(objective_function, initial_guess, bounds=bounds, constraints=[nonlinear_constraint], method='SLSQP')

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    # Return the optimized prediction subject to the optimmal input
    optimal_target_scaled = -result.fun

    return optimal_input_scaled, optimal_target_scaled

def optimize_inputs_evolutionary(model, initial_guess=None, bounds=None, power_constraint_value=None, penalty_weight=100):
    """
    Optimize the voltage predicted by the GPyTorch model with a power constraint using differential evolution.

    Parameters:
    - model: The trained GPyTorch model.
    - power_constraint_value: The power constraint value (voltage * current).
    - initial_guess: Initial guess for the optimizer. If None, the mean of the scaled data is used.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].
    - penalty_weight: Weight for the penalty term in the objective function.

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - optimal_target: The maximum voltage subject to the power constraint.
    """

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            voltage = model(x_tensor).mean.item()
        current = x[0]
        power_constraint = voltage * current - power_constraint_value
        penalty = penalty_weight * (power_constraint**2)  # Squared term to ensure positive penalty
        result = -voltage + penalty  # Negate voltage to maximize and add penalty for constraint violation

        # Debug messages
        print(f"Evaluating at {x}")
        print(f"  Voltage: {voltage}")
        print(f"  Current: {current}")
        print(f"  Power constraint: {power_constraint}")
        print(f"  Penalty: {penalty}")
        print(f"  Objective function result: {result}")

        return result

    # If no initial guess is provided, use the mean of bounds provided
    if initial_guess is None:
        if bounds is not None:
            initial_guess = np.mean(bounds, axis=1)
        else:
            raise ValueError("If no initial guess is provided, bounds must be specified.")
    
    # Perform the optimization using differential evolution
    result = differential_evolution(objective_function, bounds)

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x
    print(f"Optimal input (scaled): {optimal_input_scaled}")

    # Evaluate the optimal target value
    x_tensor = torch.tensor(optimal_input_scaled, dtype=torch.float).unsqueeze(0)
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        optimal_target_scaled = model(x_tensor).mean.item()

    print(f"Optimal target (scaled): {optimal_target_scaled}")

    return optimal_input_scaled, optimal_target_scaled

def optimize_inputs_evolutionary_constraint(model, bounds, power_constraint_value, initial_guess=None):
    """
    Optimize the voltage predicted by the GPyTorch model with a power constraint using differential evolution.

    Parameters:
    - model: The trained GPyTorch model.
    - power_constraint_value: The power constraint value (voltage * current).
    - initial_guess: Initial guess for the optimizer. If None, the mean of the scaled data is used.
    - bounds: Bounds for each feature as a list of tuples [(min1, max1), (min2, max2), ...].

    Returns:
    - optimal_input: The optimal input values in the original scale.
    - optimal_target: The maximum voltage subject to the power constraint.
    """

    # Define the objective function for optimization
    def objective_function(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            voltage = model(x_tensor).mean.item()
        return -voltage  # Negate voltage to maximize

    # Define the constraint function
    def power_constraint(x):
        x_tensor = torch.tensor(x, dtype=torch.float).unsqueeze(0)
        model.eval()
        with torch.no_grad(), gpytorch.settings.fast_pred_var():
            voltage = model(x_tensor).mean.item()
        current = x[0]
        return voltage * current - power_constraint_value

    # Define the constraint dictionary
    constraints = {'type': 'eq', 'fun': power_constraint}

    # If no initial guess is provided, use the mean of bounds provided
    if initial_guess is None:
        if bounds is not None:
            initial_guess = np.mean(bounds, axis=1)
        else:
            raise ValueError("If no initial guess is provided, bounds must be specified.")
    
    # Perform the optimization using differential evolution with constraints
    result = differential_evolution(objective_function, bounds, constraints=[constraints])

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    # Evaluate the optimal target value
    x_tensor = torch.tensor(optimal_input_scaled, dtype=torch.float).unsqueeze(0)
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        optimal_target = model(x_tensor).mean.item()

    return optimal_input_scaled, optimal_target
