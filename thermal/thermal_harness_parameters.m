%% Definition of Parameters for HT-Cooling Harness (i.e., stack, heat exchanger, potentially controller)

%% Fuel cell stack

% Basic stack parameters
stack.area = 300; % [cm^2] Cell area
stack.thermal_mass = 30; % [kg] Stack thermal mass
stack.specific_heat = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly

% Stack coolant system
stack.coolant_w_channels = 1; % [cm] Coolant channel width/height
stack.coolant_num_passes = 20; % [-] Number of coolant channel passes per layer
stack.coolant_num_layers = 15; % [-] Number of coolant layers in stack

%% Radiator parameters
% These are only relevant when engaging the physical radiator model (cf.
% *variant_config.m).

% Basic radator parameters
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

% Heat transfer surface area
radiator_area_primary = 2 * radiator_tube_length * radiator_width * (radiator_fin_rows)...
    - 2 * radiator_fin_thickness * radiator_width * radiator_n_fins...
    + 2 * radiator_fin_height * radiator_width * radiator_fin_rows...
    + 2 * radiator_tube_height * radiator_n_tubes * radiator_tube_length;
radiator_area_fins = radiator_n_fins * (radiator_fin_height-radiator_fin_thickness) * radiator_width * 2;
radiator_area_air = radiator_n_fins * radiator_fin_height * radiator_fin_width; % Cross-sectional area [m^2]

% Air parameters (for air-coolant heat exchange)
air_rho = 1.2; % Density [kg/m^3]
air_cp = 1004; % Specific heat [J/kg/K]
air_vel_nom = 1; % Nominal velocity [m/s]
air_HC_nom = 100; % Nominal heat transfer coefficient [W/(K*m^2)]
air_HC_min = 10; % Minimum heat transfer coefficient [W/(K*m^2)]