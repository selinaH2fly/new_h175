import os
import shutil

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

    os.mkdir(dirName)
    shutil.copytree(os.getcwd(), os.path.join(dirName, "Sources_unzipped"),
                    ignore=shutil.ignore_patterns('*experiment*', '*consolidated*', 'archive', '.git*', 
                                                  '*model*', '../.idea', '__pycache__', 'README*'))

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