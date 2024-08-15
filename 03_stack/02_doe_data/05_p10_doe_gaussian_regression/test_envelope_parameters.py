

# %% 1: Plot parameters from DOE Dataset agains current.
#path to data:
import os
import pandas as pd
from pathlib import Path
import matplotlib.pyplot as plt
import numpy as np

# Load the high amp DoE data
def load_high_amp_doe_data():
    # Get path to data file
    my_dir = os.getcwd()
    filename = "FC-P10-275C-H0C-SN0014 - H2Fly DOE averaged.xlsx"
    path = os.path.join(Path(my_dir).parents[1],'02_doe_data', '01_p10_doe_basic_files', '02_TV500106_750A', filename)

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

# Preprocess the data
def preprocess_data(df,cutoff_current=0):
    # Drop rows with 'current' values below the cutoff
    df = df[df['current'] > cutoff_current]
    
    # Keep only the specified columns
    selected_columns = ["current", "cathode_stoich", "RH_Cathode_Outlet", "temp_coolant_inlet", "temp_coolant_outlet", "pressure_cathode_inlet"]
    df = df[selected_columns]
    return df

def plot_columns_against_first(df):
    # Extract the 0th column (usually the first column)
    x = df.iloc[:, 0]
    x_label = df.columns[0]
    
    # Loop through each column, starting from the 1st index (skipping the 0th column)
    for i in range(1, df.shape[1]):
        y = df.iloc[:, i]
        y_label = df.columns[i]
        
        # Create a new plot for each column
        plt.figure(figsize=(8, 6))
        plt.scatter(x, y, label=y_label, marker='o')
        
        # Label the plot
        plt.xlabel(x_label)
        plt.ylabel(y_label)
        plt.title(f'{y_label} vs {x_label}')
        plt.legend()
        plt.grid(True)
        
        # Show the plot
        plt.show()
    

df1, units = load_high_amp_doe_data()
df = preprocess_data(df1)
#plot_columns_against_first(df)

# %% 2: Built envelope functions for each parameter

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def fit_envelope_functions(df, degree=5, quantile=0.95, window_size=50):
    x = df.iloc[:, 0]
    x_label = df.columns[0]

    # Convert x to numeric, coerce errors to NaN, then drop NaN values
    x = pd.to_numeric(x, errors='coerce')

    # Dictionary to store the polynomial coefficients for each column
    envelope_fits = {}

    for i in range(1, df.shape[1]):
        y = df.iloc[:, i]

        # Convert y to numeric, coerce errors to NaN, then drop NaN values
        y = pd.to_numeric(y, errors='coerce')

        # Drop rows where x or y have NaN values
        valid_data = pd.DataFrame({'x': x, 'y': y}).dropna()

        if valid_data.empty:
            print(f"Skipping column {df.columns[i]} due to lack of valid data.")
            continue

        x_cleaned = valid_data['x']
        y_cleaned = valid_data['y']

        # Calculate rolling quantiles for upper and lower bounds
        upper_bound = y_cleaned.rolling(window=window_size, min_periods=1).quantile(quantile)
        lower_bound = y_cleaned.rolling(window=window_size, min_periods=1).quantile(1 - quantile)

        # Drop NaN values that may result from rolling operations
        valid_bounds = pd.DataFrame({'x': x_cleaned, 'upper_bound': upper_bound, 'lower_bound': lower_bound}).dropna()

        if valid_bounds.empty:
            print(f"Skipping column {df.columns[i]} due to lack of valid bounds.")
            continue

        x_valid = valid_bounds['x']
        upper_valid = valid_bounds['upper_bound']
        lower_valid = valid_bounds['lower_bound']

        # Fit polynomial curves to the upper and lower bounds
        upper_fit_coeff = np.polyfit(x_valid, upper_valid, degree)
        lower_fit_coeff = np.polyfit(x_valid, lower_valid, degree)

        # Store the coefficients in a dictionary
        envelope_fits[df.columns[i]] = {
            "upper_fit": list(upper_fit_coeff),
            "lower_fit": list(lower_fit_coeff)
        }

    return envelope_fits

def plot_with_envelopes(df, envelope_fits):
    x = pd.to_numeric(df.iloc[:, 0], errors='coerce')
    x_label = df.columns[0]

    for i in range(1, df.shape[1]):
        y = pd.to_numeric(df.iloc[:, i], errors='coerce')
        y_label = df.columns[i]

        # Drop rows where x or y have NaN values
        valid_data = pd.DataFrame({'x': x, 'y': y}).dropna()

        if valid_data.empty:
            print(f"Skipping column {y_label} due to lack of valid data.")
            continue

        x_cleaned = valid_data['x']
        y_cleaned = valid_data['y']

        # Extract the envelope coefficients from the dictionary
        upper_fit_coeff = envelope_fits[y_label]["upper_fit"]
        lower_fit_coeff = envelope_fits[y_label]["lower_fit"]

        # Plot the original data
        plt.figure(figsize=(8, 6))
        plt.scatter(x_cleaned, y_cleaned, label=y_label, marker='o', linestyle='-', alpha=0.7)

        # Plot the fitted envelopes using the coefficients
        plt.scatter(x_cleaned, np.polyval(upper_fit_coeff, x_cleaned), label='Upper Envelope', color='red', linestyle='--')
        plt.scatter(x_cleaned, np.polyval(lower_fit_coeff, x_cleaned), label='Lower Envelope', color='blue', linestyle='--')

        # Label the plot
        plt.xlabel(x_label)
        plt.ylabel(y_label)
        plt.title(f'{y_label} vs {x_label} with Envelopes')
        #plt.legend()
        plt.grid(True)
        
        # Show the plot
        plt.show()

        
envelope_fits = fit_envelope_functions(df)
plot_with_envelopes(df, envelope_fits)

# %% 3: Save Parameters to a dict

# %%: 4 Build Function LookupParameters(I) inside of parameters.py

# %% 5: Integrate function into main script