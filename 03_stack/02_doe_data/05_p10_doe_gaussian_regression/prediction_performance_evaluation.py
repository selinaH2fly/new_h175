import os
import torch
import numpy as np
import matplotlib.pyplot as plt
#import cv2
import warnings
from gpytorch.utils.warnings import GPInputWarning

# Evaluate the model performance
def eval_prediction_performance(model, likelihood, mll, input_tensor, target_tensor):

    model.eval()
    likelihood.eval()

    with torch.no_grad():
        val_output = model(input_tensor)
        val_loss = -mll(val_output, target_tensor)

    return val_loss

# Plot the model performance
def plot_prediction_performance(model, likelihood, input_tensor, target_tensor, iteration, target="voltage", target_normalization=(0, 1), test=True):

    # Evaluate the model on the training data
    model.eval()
    likelihood.eval()
    with torch.no_grad():
        with warnings.catch_warnings():
            warnings.simplefilter("ignore", GPInputWarning)
            predictions = likelihood(model(input_tensor)).mean.numpy()

    # Denormalize the target tensor and the predictions
    targets = target_tensor.numpy() * target_normalization[1].numpy() + target_normalization[0].numpy()
    predictions = predictions * target_normalization[1].numpy() + target_normalization[0].numpy()

    # Initialize plot
    f, ax = plt.subplots(1, 1)
    mgr = plt.get_current_fig_manager()
    mgr.resize(720, 720)

    # Set the title
    ax.set_title(f'Model Performance Snapshot Test Data - Iteration: {iteration}') if test else ax.set_title(f'Model Performance Snapshot Training Data - Iteration: {iteration}')

    # Set the labels
    ax.set_xlabel(f'{target} Targets')
    ax.set_ylabel(f'{target} Predictions')

    # Set axis limits to min and max values of the targets + 10% (rounded to nearest 0.1)
    y_min = np.floor((np.min(targets) * 0.9) * 10) / 10
    y_max = np.ceil((np.max(targets) * 1.1) * 10) / 10
    ax.set_xlim([y_min, y_max])
    ax.set_ylim([y_min, y_max])

    # Set the aspect ratio to be equal
    # ax.set_aspect('equal', adjustable='box')
    ax.grid(True, zorder=1)

    # Plot the diagonal line
    ax.plot([y_min, y_max], [y_min, y_max], 'k--', lw=2)

    # Plot target vs. predictions
    ax.plot(targets, predictions, 'o', label='Training Data', color='blue')

    # Compute the RMS error, R2 score, max error
    rms_error = np.sqrt(np.mean((targets - predictions) ** 2))
    r2_score = np.corrcoef(targets, predictions)[0, 1] ** 2
    max_error = np.max(np.abs(targets - predictions))

    # Add text to the plot
    ax.text(
        0.05, 0.95, 
        f'RMS Error: {rms_error:.4f}\nMax Error: {max_error:.4f}\nR2 Score: {r2_score:.4f}', 
        horizontalalignment='left', 
        verticalalignment='top', 
        transform=ax.transAxes, 
        fontsize=10,
        bbox=dict(facecolor='white', alpha=0.8, edgecolor='none', pad=3.0)  # Add background color
    )

    # Save the figure to the model performance snapshots folder
    path = 'model_performance_snapshots/test' if test else 'model_performance_snapshots/train'
    os.makedirs(path, exist_ok=True)
    plt.savefig(f'{path}/model_performance_snapshot_{iteration}.png', dpi=300, bbox_inches='tight')

    plt.close()

# def create_prediction_performance_video(test=True):

#     # Change the current working directory
#     path = 'model_performance_snapshots/test' if test else 'model_performance_snapshots/train'
#     os.chdir(path)

#     # Set the path to the folder containing your PNG frames and the output video file name
#     frame_folder = os.getcwd()

#     output_video = "model_performance_evolution_test.avi" if test else "model_performance_evolution_train.avi"

#     # Define the frame rate and frame size
#     frame_rate = 5  # Adjust as needed

#     # Get a list of the PNG files in the folder
#     frame_files = sorted([f for f in os.listdir(frame_folder) if f.startswith("model_performance_snapshot")], key=lambda x: int(''.join(filter(str.isdigit, os.path.splitext(x)[0]))))

#     # Extract frame size from first frame
#     frame_path = os.path.join(frame_folder, frame_files[0])
#     frame = cv2.imread(frame_path)
#     height, width, _ = frame.shape

#     # Initialize VideoWriter
#     fourcc = 0
#     out = cv2.VideoWriter(output_video, fourcc, frame_rate, (width, height))

#     # Loop through the PNG frames and add them to the video
#     for frame_file in frame_files:
#         frame_path = os.path.join(frame_folder, frame_file)
#         frame = cv2.imread(frame_path)
#         out.write(frame)

#     # Release the VideoWriter
#     out.release()

#     print("Video creation for test data complete.") if test else print("Video creation for training data complete.")

#     # Change the current working directory back to the experiment folder
#     os.chdir("../..")

#     return None