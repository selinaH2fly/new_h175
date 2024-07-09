import argparse
import numpy as np
import torch
import gpytorch
from scipy.optimize import minimize

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
        return -prediction  # We negate because we want to maximize

    # If no initial guess is provided, use the mean of bounds provided
    if initial_guess is None:
        if bounds is not None:
            initial_guess = np.mean(bounds, axis=1)
        else:
            raise ValueError("If no initial guess is provided, bounds must be specified.")
            

    # Perform the optimization
    result = minimize(objective_function, initial_guess, bounds=bounds, method='L-BFGS-B')

    # Get the optimal (normalized) input variables
    optimal_input_scaled = result.x

    return optimal_input_scaled

# Script entry point
# if __name__ == "__main__":

#     # Create an ArgumentParser object
#     parser = argparse.ArgumentParser(description="Train a Gaussian process regression model on Powercell DoE data")
#     parser.add_argument("-t", "--target", type=str, help="Target variable for Gaussia process regression", default="voltage")
#     parser.add_argument("-c", "--cutoff", type=float, help="Datapoints below cutoff current are removed from training data", default=0.0)
#     parser.add_argument("-p", "--plot", type=bool, help="Plot the input/output data", default=True)
#     parser.add_argument("-m", "--model", type=str, help="Load a pretrained GPR model", default=None)

#     args = parser.parse_args()

#     # Call the main function                        
#     train_gpr_model_on_doe_data(args.target, args.cutoff, args.plot, args.model)

#     # Assume you have your feature names, data, and trained model
#     feature_names = ["current", "relative_humidity", "stoichiometry", "pressure", "coolant_temperature"]
#     X = np.random.rand(100, len(feature_names))  # Example data, replace with your actual data
#     model = your_trained_gpytorch_model  # Replace with your actual trained model

#     # Create and fit a scaler based on your training data
#     scaler = StandardScaler()
#     X_scaled = scaler.fit_transform(X)

#     # Define the bounds for each feature
#     bounds = [(X[:, i].min(), X[:, i].max()) for i in range(X.shape[1])]

#     # Call the optimization function
#     optimal_input = optimize_for_inputs(model, scaler, bounds=bounds)

#     print("Optimal input variables:", optimal_input)
