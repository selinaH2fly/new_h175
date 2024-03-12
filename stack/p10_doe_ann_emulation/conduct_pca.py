"""This project shall do a principal component analysis on a dataset of Powercell DoE data.

Author: Stefan Notter
Date: March 2024"""

# import the necessary libraries
import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
# import seaborn as sns
# from sklearn.decomposition import PCA
# from sklearn.preprocessing import StandardScaler
# from sklearn.model_selection import train_test_split


# load the dataset from the load_data() function in the train_ann_model.py file
from train_ann_model import load_data
from train_ann_model import plot_doe_data

# Main function
def conduct_pca_on_doe_data(target='None'):
    
    # Load and assign the data
    (model_in_dict, model_out_dict) = load_data()

    plot_doe_data(model_in_dict, model_out_dict)

# Entry point
if __name__ == '__main__':

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(description="Conduct a Principal Component Analysis on Powercell DoE data")
    parser.add_argument("-t", "--target", type=str, help="Target (i.e., output variable) for PCA", default=False)
    args = parser.parse_args()

    # Call the main function                        
    conduct_pca_on_doe_data(args.target)

