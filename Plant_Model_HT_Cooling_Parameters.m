%% Definition of Parameters for HT-Cooling Plant Model

% Coolant initial conditions
coolant_initial_pressure = 0.111325; % [MPa] Pressure
coolant_initial_temperature = 293.15; % [K] Temperature

% Fuel cell stack
stack_area = 280; % [cm^2] Cell area
stack_thermal_mass = 30; % [kg] Stack thermal mass
stack_specific_heat = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly

% Stack coolant system
coolant_w_channels = 1; % [cm] Coolant channel width/height
coolant_num_passes = 20; % [-] Number of coolant channel passes per layer
coolant_num_layers = 15; % [-] Number of coolant layers in stack
coolant_tube_D = 0.05; % [m] Coolant tube diameter

% Radiator parameters
radiator_n_tubes = 20; % Number of tubes [-]
radiator_width = 0.025; % Radiator width [m]
radiator_tube_height = 0.0015; % Tube height [m]
radiator_tube_length = 0.45; % Tube length [m]
radiator_fin_thickness = 1e-4; % Fin thickness [m]
radiator_fin_width = 0.002; % Fin width [m]
radiator_fin_height = 0.012; % Fin height [m]

% Radiator fins
radiator_fin_rows = radiator_n_tubes - 1; % Number of fin rows [-]
radiator_n_fins = radiator_fin_rows  * (radiator_tube_length / radiator_fin_width); % Total number of fins [-]


% Air parameters (for air-coolant heat exchange)
air_rho = 1.2; % Density [kg/m^3]
air_cp = 1004; % Specific heat [J/kg/K]
air_vel_nom = 1; % Nominal velocity [m/s]
air_HC_nom = 100; % Nominal heat transfer coefficient [W/(K*m^2)]
air_HC_min = 10; % Minimum heat transfer coefficient [W/(K*m^2)]

% Heat transfer surface area
radiator_area_primary = 2 * radiator_tube_length * radiator_width * (radiator_fin_rows)...
    - 2 * radiator_fin_thickness * radiator_width * radiator_n_fins...
    + 2 * radiator_fin_height * radiator_width * radiator_fin_rows...
    + 2 * radiator_tube_height * radiator_n_tubes * radiator_tube_length;
radiator_area_fins = radiator_n_fins * (radiator_fin_height-radiator_fin_thickness) * radiator_width * 2;
radiator_area_air = radiator_n_fins * radiator_fin_height * radiator_fin_width; % Cross-sectional area [m^2]


% TCV parameters
tcv_orifice_diameter = 0.045; % [m] TCV max. orifice diameter (note: the valve model (3-way linear valve) does not meed the design of the actual TCV)
tcv_rate_limit = 45; % [1/s] percentage opening per second
tcv_time_constant = .2; % [s] time constant for PT1 dynamics
tcv_leakage_area = 4e-5; % [m2] leakage area

% TCP parameters
tcp_rate_limit = 1000; % [rpm/s] rpm rate limit per second
tcp_time_constant = 2; % [s] time constant for PT1 dynamics