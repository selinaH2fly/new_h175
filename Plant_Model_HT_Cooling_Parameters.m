%% Definition of Parameters for HT-Cooling Plant Model

% Environment conditions
env_p = 0.101325; % [MPa] Pressure
env_T = 293.15; % [K] Temperature
% env_RH = 0.5; % [-] Relative humidity
% env_yO2 = 0.21; % [-] Oxygen mole fraction

% Fuel cell stack
stack_num_cells = 455; % [-] Number cells
stack_area = 280; % [cm^2] Cell area
stack_t_membrane = 125; % [um] Membrane thickness
stack_t_gdl = 250; % [um] Gas diffusion layer thickness
stack_mea_rho = 1800; % [kg/s] Overall density of membrane electrode assembly
stack_mea_cp = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly


% Hydrogen fuel
% tank_p = 70; % [MPa] Fuel tank pressure
% tank_yH2 = 1 - 3e-4; % [-] Hydrogen mole fraction
% tank_V = 120; % [l] Fuel tank volume

% Stack coolant system
coolant_w_channels = 1; % [cm] Coolant channel width/height
coolant_num_passes = 20; % [-] Number of coolant channel passes per layer
coolant_num_layers = 20; % [-] Number of coolant layers in stack
coolant_tube_D = 0.05; % [m] Coolant tube diameter

% anode_tube_D = 0.01; % [m] Hydrogen tube diameter
% cathode_tube_D = 0.05; % [m] Air tube diameter

% Radiator dimensions
radiator_L = 1; % [m] Overall radiator length
radiator_W = 0.025; % [m] Overall radiator width
radiator_H = 0.5; % [m] Overal radiator height
radiator_N_tubes = 25; % [-] Number of coolant tubes
radiator_tube_H = 0.0015; % [m] Height of each coolant tube
radiator_fin_spacing = 0.002; % [-] Fin spacing
radiator_eta_fin = 0.7; % [-] Fin efficiency
radiator_t_wall = 1e-4; % [m] Material thickness
radiator_rho = 2700; % [kg/s] Radiator material density
radiator_cp = 910; % [J/(kg*K)] Radiator material specific heat

radiator_gap_H = (radiator_H - radiator_N_tubes*radiator_tube_H) / (radiator_N_tubes - 1); % [m] Height between coolant tubes
radiator_air_area_primary = 2 * (radiator_N_tubes - 1) * radiator_W * (radiator_L + radiator_gap_H); % [m^2] Primary air heat transfer surface area
radiator_N_fins = (radiator_N_tubes - 1) * radiator_L / radiator_fin_spacing; % [-] Total number of fins
radiator_air_area_fins = 2 * radiator_N_fins * radiator_W * radiator_gap_H; % [m^2] Total fin surface area
radiator_tube_Leq = 2*(radiator_H + 20*radiator_tube_H*radiator_N_tubes); % [m] Additional equivalent tube length for losses due to manifold and splits

% TCV parameters
tcv_orifice_diameter = 0.045; % [m] TCV max. orifice diameter (note: the valve model (3-way linear valve) does not meed the design of the actual TCV)
tcv_rate_limit = 45; % [1/s] percentage opening per second
tcv_time_constant = .2; % [s] time constant for PT1 dynamics

% TCP parameters
tcp_rate_limit = 1000; % [rpm/s] rpm rate limit per second
tcp_time_constant = 2; % [s] time constant for PT1 dynamics