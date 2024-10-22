import gpytorch

# This is the basic default model with RBF kernel we have been using throughout
class ExactGPModel_RBF(gpytorch.models.ExactGP):
    def __init__(self, train_x, train_y, likelihood):
        super(ExactGPModel_RBF, self).__init__(train_x, train_y, likelihood=likelihood)
        self.mean_module = gpytorch.means.ConstantMean()
        self.covar_module = gpytorch.kernels.ScaleKernel(gpytorch.kernels.RBFKernel())

    def forward(self, x):
        mean_x = self.mean_module(x)
        covar_x = self.covar_module(x)
        return gpytorch.distributions.MultivariateNormal(mean_x, covar_x)



# More complex model with linear combination of 3 RBF kernels, initialized at 3 different lengthscales 0.1, 1, 10
class ExactGPModel_RBF_MultiLenscale(gpytorch.models.ExactGP):
    def __init__(self, train_x, train_y, likelihood):
        super(ExactGPModel_RBF_MultiLenscale, self).__init__(train_x, train_y, likelihood=likelihood)
        self.mean_module = gpytorch.means.ConstantMean()

       # Create three RBF kernels and set different initial length scales
        rbf_kernels = [gpytorch.kernels.ScaleKernel(gpytorch.kernels.RBFKernel()) for _ in range(3)]
        
        # Set different initial length scales using the `.initialize` method
        initial_lengthscales = [0.1, 1.0, 10.0]
        for i, kernel in enumerate(rbf_kernels):
            kernel.base_kernel.initialize(lengthscale=initial_lengthscales[i])

        # Combine the kernels using AdditiveKernel
        self.covar_module = gpytorch.kernels.AdditiveKernel(*rbf_kernels)

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