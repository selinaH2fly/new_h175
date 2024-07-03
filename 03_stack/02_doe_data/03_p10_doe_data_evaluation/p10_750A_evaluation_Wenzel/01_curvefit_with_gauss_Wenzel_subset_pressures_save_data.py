import os
import pandas as pd
import numpy as np
import torch
import gpytorch
import matplotlib.pyplot as plt
import pickle

# Number of cells considered
n_cells_wished_for = 275
n_cells = 1 / 275 * n_cells_wished_for  # DEO dataset was performed by a stack with 275 cells

def load_high_amp_doe_data():
    # Get path to data file
    my_dir = r"F:\gauss"
    filename = "FC-P10-275C-H0C-SN0014 - H2Fly DOE averaged.xlsx"
    path = os.path.join(my_dir, filename)

    # Load data file
    xls = pd.ExcelFile(path)

    # Get the name of the second sheet
    second_sheet_name = xls.sheet_names[1]

    # Load the second sheet into a DataFrame, skipping the first row
    df = pd.read_excel(path, sheet_name=second_sheet_name)

    # Extract the units row and set it as the DataFrame column names
    units = df.iloc[0]
    df.columns = df.iloc[1]
    df = df.drop([0, 1]).reset_index(drop=True)
    df = df.drop(0)
    df = df[df['Point successfully run'] == 1]
    df = df.loc[:, ~df.columns.duplicated()]

    return df, units

def subdivide_data(data, column_name="pressure_cathode_inlet", n_groups=6):
    """
    Subdivides the data into N groups based on the specified column.

    Parameters:
    data (pd.DataFrame): The input data.
    column (str): The column name to base the subdivision on.
    n_groups (int): The number of groups to divide the data into.

    Returns:
    list: A list of DataFrames, each containing one of the subdivided groups.
    """
    # Ensure the column exists in the data
    if column_name not in data.columns:
        raise ValueError(f"Column '{column_name}' not found in the data.")
    
    # Sort data by the specified column
    data_sorted = data.sort_values(by=column_name)
        
    # Determine the size of each group
    group_size = len(data_sorted) // n_groups
    subdivided_data = []
    
    for i in range(n_groups):
        start_index = i * group_size
        # Ensure the last group gets any remaining rows
        if i == n_groups - 1:
            end_index = len(data_sorted)
        else:
            end_index = (i + 1) * group_size
            
        subset = data_sorted.iloc[start_index:end_index]
        subdivided_data.append(subset)
    
    return subdivided_data

# Load data using the provided function
data, units = load_high_amp_doe_data()
data['pressure_cathode_inlet'] = data['pressure_cathode_inlet'] + 1  # Change from relative pressures to absolute pressures
units['pressure_cathode_inlet'] = "bara"

n_groups = 3
subdivided_data = subdivide_data(data, 'pressure_cathode_inlet', n_groups)

# Use a dictionary to store fitted data and subdivided datasets
fitted_data_dict = {}

for j, this_data in enumerate(subdivided_data):
    # Extract relevant columns for GP fitting (replace 'x_column' and 'y_column' with actual column names)
    x_column = 'current'  # Replace with actual column name for x values
    y_column = 'voltage'  # Replace with actual column name for y values
    
    # Convert columns to numeric, forcing errors to NaN and then dropping NaN values
    this_data[x_column] = pd.to_numeric(this_data[x_column], errors='coerce')
    this_data[y_column] = pd.to_numeric(this_data[y_column], errors='coerce') / n_cells
    this_data = this_data.dropna(subset=[x_column, y_column])
    
    x_data = this_data[x_column].values
    y_data = this_data[y_column].values
    
    # Convert to numpy arrays and then to torch tensors
    x_data = torch.from_numpy(x_data).float().unsqueeze(-1)
    y_data = torch.from_numpy(y_data).float()
    
    # Define the GP model
    class ExactGPModel(gpytorch.models.ExactGP):
        def __init__(self, train_x, train_y, likelihood):
            super(ExactGPModel, self).__init__(train_x, train_y, likelihood)
            self.mean_module = gpytorch.means.ConstantMean()
            self.covar_module = gpytorch.kernels.ScaleKernel(gpytorch.kernels.RBFKernel())
    
        def forward(self, x):
            mean_x = self.mean_module(x)
            covar_x = self.covar_module(x)
            return gpytorch.distributions.MultivariateNormal(mean_x, covar_x)
    
    # Initialize the likelihood and model
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(x_data, y_data, likelihood)
    
    # Find optimal model hyperparameters
    model.train()
    likelihood.train()
    
    # Use the Adam optimizer
    optimizer = torch.optim.Adam(model.parameters(), lr=0.1)
    
    # "Loss" for GPs - the marginal log likelihood
    mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)
    
    # Store the loss values for plotting
    loss_values = []
    
    training_iterations = int(25e3)
    for i in range(training_iterations):
        optimizer.zero_grad()
        output = model(x_data)
        loss = -mll(output, y_data)
        loss.backward()
        print(f'Iteration {i + 1}/{training_iterations} - Loss: {loss.item()}')
        optimizer.step()
        loss_values.append(loss.item())
    
    # Plot the loss values to verify convergence
    plt.figure(figsize=(10, 5))
    plt.semilogy(range(1, training_iterations + 1), loss_values, marker='o')
    plt.xlabel('Iteration')
    plt.ylabel('Loss')
    plt.title(f'Training Loss for p_{j}')
    plt.grid(True)
    plt.show()
    
    # Make predictions
    model.eval()
    likelihood.eval()
    
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        test_x = torch.linspace(x_data.min(), x_data.max(), 100)
        observed_pred = likelihood(model(test_x))
    
    # Get the mean and confidence intervals
    mean = observed_pred.mean.numpy()
    lower, upper = observed_pred.confidence_region()
    
    # Plot training data and prediction
    plt.figure(figsize=(12, 6))
    plt.plot(x_data.numpy(), y_data.numpy(), 'k*')
    plt.plot(test_x.numpy(), mean, 'b')
    plt.fill_between(test_x.numpy(), lower.numpy(), upper.numpy(), alpha=0.5)
    plt.xlabel(x_column)
    plt.ylabel(y_column)
    plt.legend(['Observed Data', 'Mean', 'Confidence'])
    plt.title(f'Gaussian Process Regression for p_{j}')
    plt.show()
    
    # Store the data in the dictionary
    fitted_data_dict[f'p_{j}'] = {
        'x_data': x_data.numpy(),
        'y_data': y_data.numpy(),
        'loss_values': loss_values,
        'test_x': test_x.numpy(),
        'mean': mean,
        'lower': lower.numpy(),
        'upper': upper.numpy(),
        'subdivided_data': this_data
    }

# Plot all fitted U vs I in one plot
plt.figure(figsize=(12, 6))
colors_used = ['tab:blue', 'tab:orange', 'tab:green', "tab:red", "tab:cyan", "tab:purple"]
for j in range(len(fitted_data_dict)):
    plt.plot(fitted_data_dict[f'p_{j}']['x_data'], fitted_data_dict[f'p_{j}']['y_data'], ".", color=colors_used[j], label = f"p{j}")
    plt.plot(fitted_data_dict[f'p_{j}']['test_x'], fitted_data_dict[f'p_{j}']['mean'], color=colors_used[j])
    plt.fill_between(fitted_data_dict[f'p_{j}']['test_x'], fitted_data_dict[f'p_{j}']['lower'], fitted_data_dict[f'p_{j}']['upper'], alpha=0.2, color=colors_used[j])
plt.xlabel("Current [A]")
plt.ylabel("Voltage [V]")
plt.title(f'Gaussian Process Regression for All pressure groups, Iterations = {int(training_iterations/1000)}k')
plt.legend()
plt.savefig("U_vs_I_Gaussfit.png")
plt.show()


# Save the fitted data dictionary to a file
output_file_path = r"F:\gauss\fitted_data_dict.pkl"
with open(output_file_path, 'wb') as f:
    pickle.dump(fitted_data_dict, f)

print(f"Data saved to {output_file_path}")
