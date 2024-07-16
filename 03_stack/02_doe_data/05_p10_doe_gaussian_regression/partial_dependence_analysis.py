import numpy as np
import torch
import gpytorch
import matplotlib.pyplot as plt

# Computation of partial dependence
def partial_dependence(model, X, feature_index, fixed_feature_index=None, fixed_value=None, grid_resolution=100):
    """
    Calculate partial dependence for a given feature with one feature fixed.
    
    Parameters:
    - model: The trained gpytorch model.
    - X: The input data as a numpy array or torch tensor.
    - feature_index: The index of the feature to vary.
    - fixed_feature_index: The index of the feature to fix.
    - fixed_value: The value to fix the specified feature at.
    - grid_resolution: The number of points to evaluate.

    Returns:
    - grid: The values of the feature.
    - pdp: The partial dependence values.
    """
      # Calculate the range of the feature
    feature_min, feature_max = X[:, feature_index].min(), X[:, feature_index].max()
    grid = np.linspace(feature_min, feature_max, grid_resolution)
    
    # Create a tiled array to hold the variations
    X_temp = np.tile(X, (grid_resolution, 1))

    # Replace the values of the feature with the grid values
    for i, value in enumerate(grid):
        X_temp[i * X.shape[0]:(i + 1) * X.shape[0], feature_index] = value

    # Fix the specific feature value if provided
    if fixed_feature_index is not None and fixed_value is not None:
        X_temp[:, fixed_feature_index] = fixed_value
    
    # Convert to torch tensor
    X_temp = torch.tensor(X_temp, dtype=torch.float)
    
    # Compute the predictions
    model.eval()
    with torch.no_grad(), gpytorch.settings.fast_pred_var():
        predictions = model(X_temp).mean.numpy()
    
    # Average the predictions across the samples for each grid value
    pdp = predictions.reshape(grid_resolution, X.shape[0]).mean(axis=1)
    
    return grid, pdp

# Partial dependence plots
def plot_partial_dependence(model, train_x_tensor, feature_names, target='voltage', input_normalization=(0, 1), target_normalization=(0, 1), fixed_feature=None, fixed_value=400):

    # Making predictions
    model.eval()

    # Get the index of the fixed feature
    if fixed_feature is not None:
        fixed_feature_index = feature_names.index(fixed_feature)
        fixed_value_norm = (fixed_value - input_normalization[0][fixed_feature_index]) / input_normalization[1][fixed_feature_index]

    else:
        fixed_feature_index = None
        fixed_value_norm = None

    # Convert the training data to a numpy array for easier manipulation
    train_x_np = train_x_tensor.numpy()

    # Number of features
    num_features = len(feature_names)

    # Create subplots with 2 columns
    fig, axes = plt.subplots(int(np.ceil(num_features / 2)), 2, figsize=(12, 12))

    # Adjust the layout
    fig.subplots_adjust(hspace=2)

    # Create figure title
    fig.suptitle('GPR DoE Model - Partial Dependence Plots')

    # Loop through each feature and plot its partial dependence TODO: Make agnostic to the number of features
    for i in range(num_features):
        if i != fixed_feature_index:  # Skip the fixed feature

            # Calculate the partial dependence
            grid, pdp = partial_dependence(model, train_x_np, i, fixed_feature_index=fixed_feature_index, fixed_value=fixed_value_norm)

            # Denormalize the grid and pdp values
            # Convert tensor to numpy array
            input


            grid = grid * np.array(input_normalization[1][i]) + np.array(input_normalization[0][i])
            pdp = pdp * np.array(target_normalization[1]) + np.array(target_normalization[0])

            # Plot the partial dependence
            ax = axes[i // 2, i % 2]
            ax.plot(grid, pdp)

            # ax.set_ylim([0, 300])
            # extract target unit and check for lower and upper case
            # if (target[0].lower() + target[1:]) in feature_units:
            #     ax.set_ylabel(f'{target} ({feature_units[target[0].lower() + target[1:]]})')
            # elif (target[0].upper() + target[1:]) in feature_units:
            #     ax.set_ylabel(f'{target} ({feature_units[target[0].upper() + target[1:]]})')
            # else:
            #     ax.set_ylabel(f'{target} (-)')

            # Set the axes labels
            ax.set_ylabel(f'{target}')
            ax.set_xlabel(f'{feature_names[i]}')

            ax.grid(True, zorder=1)
        else:
            # Write the fixed feature value in the subplot in bold
            ax = axes[i // 2, i % 2]
            ax.text(0.5, 0.5, f'{fixed_feature} fixed at {fixed_value}', horizontalalignment='center', verticalalignment='center', transform=ax.transAxes, fontsize=12, fontweight='bold')


    # Remove empty subplot (if any)
    if len(axes.flatten()) > num_features:
        fig.delaxes(axes.flatten()[-1])

    # Unify the y-axis limits to min and max values of the subplots (excluding the fixed feature subplot!)
    # y_min = np.floor((np.min([ax.get_ylim()[0] for ax in axes.flatten() if ax.get_ylim()[0] != 0]) * 0.9) * 10) / 10
    # y_max = np.ceil((np.min([ax.get_ylim()[1] for ax in axes.flatten() if ax.get_ylim()[1] != 1]) * 1.1) * 10) / 10
    y_min = 0.4
    y_max = 0.7
    for ax in axes.flatten():
        ax.set_ylim([y_min, y_max])

    # Finalize the layout
    plt.tight_layout()

    # Draw the canvas
    fig.canvas.draw()

    # Save the figure with title according to the fixed feature value to the partial dependence plots folder
    if fixed_feature is not None:
        plt.savefig(f'partial_dependence_plots/partial_dependence_plot_{fixed_feature}_{fixed_value}.png', bbox_inches='tight')    
    else:
        plt.savefig(f'partial_dependence_plots/partial_dependence_plot.png', bbox_inches='tight')

    # Close the figure
    plt.close()