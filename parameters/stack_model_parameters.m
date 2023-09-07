%% Definition of parameters for stack model

% Fuel cell stack
stack_num_cells = 455; % [-] Number cells
stack_area = 300; % [cm^2] Cell area
stack_t_membrane = 125; % [um] Membrane thickness
stack_t_gdl = 250; % [um] Gas diffusion layer thickness
stack_w_channels = 1; % [cm] Gas channel width/height
stack_num_channels = 8; % [-] Number of gas channels per cell
stack_io = 1e-04; % [A/cm^2] Exchange current density
stack_iL = 1.4; % [A/cm^2] Limiting current density
stack_alpha = 0.7; % [-] Charge transfer coefficient
stack_D_gdl = 0.07; % [cm^2/s] Water diffusivity in GDL
stack_membrane_rho = 2000; % [kg/m^3] Density of dry membrane
stack_membrane_MW = 1.1; % [kg/mol] Equivalent weight of dry membrane
stack_mea_rho = 1800; % [kg/s] Overall density of membrane electrode assembly
stack_mea_cp = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly