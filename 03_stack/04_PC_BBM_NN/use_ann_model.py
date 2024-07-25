# -*- coding: utf-8 -*-
"""
Created on Tue Jul 23 13:47:45 2024

@author: wenzel.gassner
"""

import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler

# Define a neural network class
class ANN_Stack_Model(nn.Module):

    # Define the layers of the network
    def __init__(self, num_inputs=13, num_outputs=32, hidden_layer_sizes=[128, 128], dropout_prob=0.3):
        super(ANN_Stack_Model, self).__init__()
        self.fc1 = nn.Linear(num_inputs, hidden_layer_sizes[0])
        self.drop1 = nn.Dropout(p=dropout_prob)
        self.fc2 = nn.Linear(hidden_layer_sizes[0], hidden_layer_sizes[1])
        self.drop2 = nn.Dropout(p=dropout_prob)
        self.fc3 = nn.Linear(hidden_layer_sizes[1], num_outputs)

    # Define the forward pass using relu activation functions
    def forward(self, x):
        x = self.fc1(x)
        x = F.relu(x)
        x = self.drop1(x)
        x = self.fc2(x)
        x = F.relu(x)
        x = self.drop2(x)
        x = self.fc3(x)
        return x

# Load the saved model parameters (ensure the hidden_layer_sizes and dropout_prob match those used in training)
model = ANN_Stack_Model(num_inputs=len(model_in_dict), num_outputs=len(model_out_dict),
                        hidden_layer_sizes=[_params_model.hidden_layer_size_1, _params_model.hidden_layer_size_2],
                        dropout_prob=_params_training.dropout_prob)

model.load_state_dict(torch.load('ann_doe_model_final.pt'))
model.eval()

# Function to normalize the input data (must match the normalization used during training)
def normalize(data, min_val, max_val):
    return ((data - min_val) / (max_val - min_val)) * 2 - 1

# Example input data (replace this with your actual input data)
input_data = pd.read_csv('path_to_input_data.csv')
input_tensor = torch.tensor(input_data.values).float()

# Normalize the input data (you may need to load min and max values used during training)
min_val = input_tensor.min(axis=0)[0]
max_val = input_tensor.max(axis=0)[0]
input_tensor_normalized = normalize(input_tensor, min_val, max_val)

# Make predictions
with torch.no_grad():
    predictions = model(input_tensor_normalized)

# If you need to denormalize the output, use the inverse of the normalization applied during training
def denormalize(data, min_val, max_val):
    return ((data + 1) / 2) * (max_val - min_val) + min_val

# Example to denormalize predictions
min_out_val = MIN_OUTPUT_VAL  # replace with the min value of the output data used during training
max_out_val = MAX_OUTPUT_VAL  # replace with the max value of the output data used during training
predictions_denormalized = denormalize(predictions, min_out_val, max_out_val)

# Convert predictions to numpy array and save or process further
predictions_numpy = predictions_denormalized.numpy()
np.savetxt('predictions.csv', predictions_numpy, delimiter=',')
