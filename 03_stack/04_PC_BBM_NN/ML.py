# -*- coding: utf-8 -*-
"""
Created on Tue Jul 16 06:47:00 2024

@author: wenzel.gassner
"""
def load_data(path=r"", datatype="dict", filter_steady_state = False):    
    """
    This function ...
    -loads data from csv into pandas dataframes, depending on user input into a list or dict.
    -Cleans out all Nan columns of the data (error cases)
    -Option to filter for steady state cases.
    Order of the csv/data: Inputs, Outputs, Parameters
    

    Parameters
    ----------
    path : TYPE, optional
        path to the csv files. The default is r"".
    datatype : TYPE, optional
        list or dict depending on user preferences. The default is "list".

    Returns
    -------
    li (list or dict with pandas Dataframes)
    
    Created on Mon Jul 15 08:23:29 2024

    @author: wenzel.gassner
    """
    #TODO: filter_steady_state=True filter out all non steady state via: Outputs["Steady_State"] == 1
    #TODO: Adjust path later to be relative inside the directory?
    
    #% Imports:    
    import pandas as pd
    import glob
    import os

    datatype = str(datatype)
    all_files = glob.glob(os.path.join(path, "*.csv"))
    
    #Import data as dict:
    if datatype == "dict":
        li = {}
        for filename in all_files:
            name_short = filename.removeprefix("MC_1stdraft_").removesuffix(".csv")
            df = pd.read_csv(filename, index_col=None, header=0)
            li[name_short] = df
        #remove Nan columns (not converged cases) from all 3 data sets, use the steady state column of Outputs
        idx = li.get("Outputs")["Steady_State"].notnull()
        # Apply these indices to filter all DataFrames in the dictionary
        for key in li.keys():
            li[key] = li[key][idx].reset_index(drop=True)
        
    #Import data as list:
    if datatype == "list":
        li = []
        for filename in all_files:
            df = pd.read_csv(filename, index_col=None, header=0)
            li.append(df)
        #remove Nan columns (not converged cases) from all 3 data sets, use the steady state column of Outputs
        idx = li[1]["Steady_State"].notnull()
        for i in range(3):
            li[i] = li[i][idx]
    return li  

import torch
from torch.utils.data import DataLoader, TensorDataset, random_split
import torch.nn as nn
import matplotlib.pyplot as plt   
from sklearn.preprocessing import MinMaxScaler
import numpy as np

data = load_data()

y = data["Outputs"].iloc[1:,2:].astype(float)
y_units = data["Outputs"].iloc[0,2:]
x = data["Parameters"].iloc[1:,2:].astype(float)
x_units = data["Outputs"].iloc[0,2:]

# Convert pandas DataFrames to PyTorch tensors
X_tensor = torch.tensor(x.values, dtype=torch.float32)
y_tensor = torch.tensor(y.values, dtype=torch.float32)

# Create a dataset and dataloader
dataset = TensorDataset(X_tensor, y_tensor)

# Split dataset into training and testing sets (80% train, 20% test)
train_size = int(0.8 * len(dataset))
test_size = len(dataset) - train_size
train_dataset, test_dataset = random_split(dataset, [train_size, test_size])

train_loader = DataLoader(train_dataset, batch_size=32, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=32, shuffle=False)

class ANN(nn.Module):
    def __init__(self):
        super(ANN, self).__init__()
        self.fc1 = nn.Linear(13, 128)  # Input layer to first hidden layer
        self.fc2 = nn.Linear(128, 128)  # First hidden layer to second hidden layer
        self.fc3 = nn.Linear(128, 36)  # Second hidden layer to output layer

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        x = self.fc3(x)
        return x

# Instantiate the model
model = ANN()

criterion = nn.MSELoss()  # Assuming regression task
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

num_epochs = 10000
losses = []

for epoch in range(num_epochs):
    epoch_loss = 0
    for inputs, targets in train_loader:
        optimizer.zero_grad()  # Clear the gradients
        outputs = model(inputs)  # Forward pass
        loss = criterion(outputs, targets)  # Compute loss
        loss.backward()  # Backward pass
        optimizer.step()  # Update weights
        epoch_loss += loss.item()
    
    avg_epoch_loss = epoch_loss / len(train_loader)
    losses.append(avg_epoch_loss)
    if epoch % 100 == 0:
        print(f'Epoch {epoch+1}/{num_epochs}, Loss: {avg_epoch_loss:.4f}')

# Plot the training loss over epochs
plt.plot(losses)
plt.yscale("log")
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.title('Training Loss over Epochs')
#plt.ylim([0,5])

plt.show()

# Evaluate the model on the test set
with torch.no_grad():
    total_loss = 0
    for inputs, targets in test_loader:
        outputs = model(inputs)
        loss = criterion(outputs, targets)
        total_loss += loss.item()
    
    avg_test_loss = total_loss / len(test_loader)
    print(f'Average Test Loss: {avg_test_loss:.4f}')