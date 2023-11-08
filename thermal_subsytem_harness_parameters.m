%% Definition of Parameters for HT-Cooling Harness (i.e., stack and potentially controller)

% Fuel cell stack
stack.area = 280; % [cm^2] Cell area
stack.thermal_mass = 30; % [kg] Stack thermal mass
stack.specific_heat = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly

% Stack coolant system
stack.coolant_w_channels = 1; % [cm] Coolant channel width/height
stack.coolant_num_passes = 20; % [-] Number of coolant channel passes per layer
stack.coolant_num_layers = 15; % [-] Number of coolant layers in stack