# Simple script to make a plot from the average loss readings

import matplotlib.pyplot as plt
import pandas as pd
import argparse
import os

# Main function
def make_avg_loss_plot(experiment_folder, test=True):

    # Change the current working directory to the experiment folder
    os.chdir(experiment_folder)

    # Make the plot with log scale on the y-axis
    plt.figure()
    return_to_plot = pd.read_csv('average_loss_final.dat')
    return_to_plot.plot(x='epoch', y='avg_loss')
    plt.title("Training Progress")
    plt.xlabel("Training Epochs (-)")
    plt.ylabel("Training Loss (-)")
    plt.yscale('log')
    plt.ylim([1e-2, 2e-1])
    plt.yticks([2e-1, 1e-1, 9e-2, 8e-2, 7e-2, 6e-2, 5e-2, 4e-2, 3e-2, 2e-2, 1e-2, 1e-1])
    plt.grid(True)

    # add legend
    plt.legend(["Average MSE"], loc="upper right")
    
    plt.savefig("average_loss_plot.png")
    plt.close()

    return None

# Entry point of the script
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Make a plot from the avg. loss readings")
    parser.add_argument("-d", "--dir", type=str, help="Experiment subfolder containing avg. loss readings")

    args = parser.parse_args()

    # Call the main function                        
    make_avg_loss_plot(args.dir)
