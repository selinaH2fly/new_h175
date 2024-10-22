import gpytorch

# Define a GP model
class ExactGPModel(gpytorch.models.ExactGP):
    def __init__(self, train_x, train_y, likelihood):
        super(ExactGPModel, self).__init__(train_x, train_y, likelihood=likelihood)
        self.mean_module = gpytorch.means.ConstantMean()
        self.covar_module = gpytorch.kernels.ScaleKernel(gpytorch.kernels.RBFKernel())

    def forward(self, x):
        mean_x = self.mean_module(x)
        covar_x = self.covar_module(x)
        return gpytorch.distributions.MultivariateNormal(mean_x, covar_x)
    
class GPRModelContainer:
    def __init__(self, model, likelihood, input_data_mean, input_data_std, target_data_mean, target_data_std, feature_names):
        self.model = model
        self.likelihood = likelihood
        self.input_data_mean = input_data_mean
        self.input_data_std = input_data_std
        self.target_data_mean = target_data_mean
        self.target_data_std = target_data_std
        self.feature_names = feature_names
