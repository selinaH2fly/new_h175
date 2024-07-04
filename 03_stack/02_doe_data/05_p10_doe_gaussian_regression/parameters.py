import numpy as np

class Training_Parameters:

    def __init__(self):
        self.iterations = 10e3
        # self.batch_size = 4
        self.learning_rate = 0.01
        # self.split_ratio = 0.8
        # self.momentum = 0.9
        # self.dropout_prob = 0.1
        self.seed = 42

# class Model_Parameters:

#     def __init__(self):
#         self.hidden_layer_size_1 = 64
#         self.hidden_layer_size_2 = 64

class Logging_Parameters:

    def __init__(self):
        self.log_interval = 1000
        # self.save_interval = 50000