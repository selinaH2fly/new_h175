"""This project analysis the importance of input features to a specific output feature on a dataset of Powercell DoE data.
To do so, a random forest model is trained and the feature importances are visualized using a bar plot.

Author: Stefan Notter
Date: March 2024"""

# import the necessary libraries
import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
# import threading
# from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
import pandas as pd


# import functions to load and visualize the doe dataset
from load_doe_data import load_doe_data
from load_doe_data import plot_doe_data

# Main function
def analyze_feature_importance(target='dp_anode_mbar'):
    
    # Load and assign the data
    (model_in_dict, model_out_dict) = load_doe_data()

    # Create a new thread and plot the data
    # plt = plot_doe_data(model_in_dict, model_out_dict)
    # plt.show()

   # Create a dataframe from the input data and the target data
    df_input = pd.DataFrame(model_in_dict)
    df_target = pd.DataFrame(model_out_dict[target])

    # Normalize the  data
    scaler = StandardScaler()
    input_scaled = scaler.fit_transform(df_input)
    target_scaled = scaler.fit_transform(df_target)

    # Split the data into training and test sets
    X_train, X_test, y_train, y_test = train_test_split(input_scaled, target_scaled, test_size=0.2, random_state=42)

   # Train a Random Forest model
    model = RandomForestRegressor(n_estimators=100, random_state=42)
    model.fit(X_train, y_train)

    # Print trained model accuracy
    print(f"RF train accuracy: {model.score(X_train, y_train):.3f}")
    print(f"RF test accuracy: {model.score(X_test, y_test):.3f}")

    # Get feature importances
    importances = model.feature_importances_

    # Get the indices of the most important features
    indices = np.argsort(importances)[::-1]

    # Make a bar plot of the input feature importance for each target
    plt.figure()
    plt.title("Normalized Feature Importances for Target: " + target)
    plt.bar(range(input_scaled.shape[1]), importances[indices], align="center")
    plt.xticks(range(input_scaled.shape[1]), df_input.columns[indices], rotation=90)
    plt.xlim([-1, input_scaled.shape[1]])
    plt.subplots_adjust(bottom=0.3)  # Adjust the bottom margin to fit the x-axis labels
    plt.tight_layout()
    plt.show()


# Entry point
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Analyse the Feature Importance of Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target (i.e., output variable) for PCA", default='dp_cathode_mbar')
    args = parser.parse_args()

    # Call the main function                        
    analyze_feature_importance(args.target)

