import os
import shutil

import torch
import gpytorch
from Trained_Models.gpr_model import ExactGPModel, GPRModelContainer

# Create and browse to folder for storing experiment results
def create_experiment_folder(_params_model=None, _params_training=None, _params_logging=None, _params_optimization=None, type='training'):
    """ Creates new folder to store training and/or optimization results and writes parameters to file. """

    # create folder to store data for the experiment running
    experimentID = 1

    if type == 'training':
        dirName = "{}_gpr_doe_model_training_experiment".format(experimentID)
    elif type == 'optimization':
        dirName = "{}_gpr_doe_model_optimization_experiment".format(experimentID)
    else:
        raise ValueError("Invalid experiment type. Choose 'training' or 'optimization'.")

    # TODO: Check only for the ID, not the whole name    
    while os.path.exists(dirName):
        experimentID += 1
        dirName = "{}_".format(experimentID) + dirName.split('_', 1)[1]
    
    #try to create a dir with the name above and be save that FileExistsError is covered for parallel batch run
    try:
        # Attempt to create the directory
        os.mkdir(dirName)

    except FileExistsError:
        # If directory already exists, increment the ID and try again
        experimentID += 1
        dirName = "{}_".format(experimentID) + dirName.split('_', 1)[1]
        os.mkdir(dirName)
        
    shutil.copytree(os.getcwd(), os.path.join(dirName, "Sources_unzipped"),
                    ignore=shutil.ignore_patterns('*experiment*', '*consolidated*', 'archive', '.git*', 
                                                  '*model*', '../.idea', '__pycache__', 'README*','test_data'))

    os.chdir(dirName)
    shutil.make_archive("Sources", 'zip', "Sources_unzipped")
    shutil.rmtree("Sources_unzipped")
    print(f"\nDirectory for running {type} experiment no. {experimentID} created\n")

    # write paramters to file if they are not None
    parameterFile = open("parameterFile.txt", "w")
    if _params_model is not None:
        parameterFile.write(format(vars(_params_model)) + "\n")
    if _params_training is not None:
        parameterFile.write(format(vars(_params_training)) + "\n")
    if _params_logging is not None:
        parameterFile.write(format(vars(_params_logging)))
    if _params_optimization is not None:
        parameterFile.write(format(vars(_params_optimization)))
    parameterFile.close()

    return None

def load_gpr_model(file_path):
    # Load the saved dictionary
    save_dict = torch.load(file_path)
    
    # Extract components
    model_state_dict = save_dict['model_state_dict']
    likelihood_state_dict = save_dict['likelihood_state_dict']
    input_data_mean = save_dict['input_data_mean']
    input_data_std = save_dict['input_data_std']
    target_data_mean = save_dict['target_data_mean']
    target_data_std = save_dict['target_data_std']
    feature_names = save_dict['feature_names']
    train_input_tensor = save_dict['train_input_tensor']
    train_target_tensor = save_dict['train_target_tensor']

    # Initialize the model and likelihood
    likelihood = gpytorch.likelihoods.GaussianLikelihood()
    model = ExactGPModel(train_input_tensor, train_target_tensor, likelihood)
    
    # Load the state dictionaries into the model and likelihood
    model.load_state_dict(model_state_dict)
    likelihood.load_state_dict(likelihood_state_dict)

    # Set the model and likelihood in evaluation mode
    model.eval()
    likelihood.eval()

    # Return a single encapsulated object
    return GPRModelContainer(model, likelihood, input_data_mean, input_data_std, target_data_mean, target_data_std, feature_names)