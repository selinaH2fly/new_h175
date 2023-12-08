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

% Fuel cell stack
stack.area = 280; % [cm^2] Cell area
stack.thermal_mass = 30; % [kg] Stack thermal mass
stack.specific_heat = 870; % [J/(kg*K)] Overall specific heat of membrane electrode assembly

% Stack coolant system
stack.coolant_w_channels = 1; % [cm] Coolant channel width/height
stack.coolant_num_passes = 20; % [-] Number of coolant channel passes per layer
stack.coolant_num_layers = 15; % [-] Number of coolant layers in stack

%% Definition of physical parameters
% Parameter definition adopted from Marlene Euchenhofer.

%=============================
% General & Electrochemical Constants
%=============================
constants.faraday_constant = 96485.33;          % Faraday constant [C/mol]
constants.universal_gas_constant = 8.3145;      % universal gas constant [J/(kg*K)]
constants.open_cell_voltage = 1.23;             % open circuit voltage aka reversible voltage [V] (specific to chemical reaction)
constants.gravity = 9.81;

%=============================
% Air Properties
%=============================
air.specific_heat = 1005;                       % isobaric specific heat air [J/(kg*K)]
air.isentropic_coefficient = 1.41;              % isentropic coefficient gamma (kappa) air [-]
air.molar_mass = 28.964*10^(-3);                % molar mass air [mol/kg]
air.specific_gas_constant = ...
    constants.universal_gas_constant/ ...
    air.molar_mass;                             % specific gas constant air [J/(kg*K)]

% vapor saturation pressure
% load and organize vapor satuaration pressure map
% vapor_saturation_pressure_data = readmatrix('data\constants\saturation_pressure_lookup.csv');
% vapor_saturation_pressure_temperature_K = vapor_saturation_pressure_data(2:length(vapor_saturation_pressure_data(:,2)),2)';
% vapor_saturation_pressure_bar = vapor_saturation_pressure_data(2:length(vapor_saturation_pressure_data(:,2)),4)';

%=============================
% Hydrogen Properties
%=============================
hydrogen.specific_heat = 14050;                 % isobaric specific heat hydrogen [J/(kg*K)]
hydrogen.isentropic_coefficientn = 1.41;        % isentropic coefficient gamma (kappa) [-]                  
hydrogen.molar_mass = 2.016*10^(-3);            % molar mass hydrogen [mol/kg]
hydrogen.specific_gas_constant = ...
    constants.universal_gas_constant/ ...
    hydrogen.molar_mass;                        % specific gas constant hydrogen [J/(kg*K)]
hydrogen.density = 0.0899;                      % density hydrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)
hydrogen.n_electrons = 2;                       % number of electrons per mol H2

% SG_Hydrogen = 0.0696;                         % specific gravity hydrogen [-]

%=============================
% Nitrogen Properties
%=============================
nitrogen.specific_heat = 296.103;               % isobaric specific heat nitrogen [J/(kg*K)]
nitrogen.isentropic_coefficientn = 1.41;        % isentropic coefficient gamma (kappa) [-]
nitrogen.molar_mass = 28.013*10^(-3);           % molar mass nitrogen [mol/kg]
nitrogen.specific_gas_constant = ...
    constants.universal_gas_constant/ ...
    nitrogen.molar_mass;                        % specific gas constant nitrogen [J/(kg*K)]
nitrogen.density = 1.2506;                      % density nitrogen [kg/(m^3)] at normal conditions (p = 1.013 bar and T = 0 °C)

%=============================
% Water Vapor Properties
%=============================
% cp_Vapor = 1920;                              % isobaric specific heat water vapor [J/(kg*K)]
% M_Oxygen = 18.0153*10^(-3);                   % molar mass water [mol/kg]
% R_Water = R/M_Oxygen;                         % specific gas constant water [J/(kg*K)]

%=============================
% Oxygen Properties
%=============================
oxygen.specific_heat = 909;                     % isobaric specific heat oxygen [J/(kg*K)]
oxygen.molar_mass = 31.999*10^(-3);             % molar mass oxygen [mol/kg]
oxygen.specific_gas_constant = ...
    constants.universal_gas_constant/...
    oxygen.molar_mass;                          % specific gas constant oxygen [J/(kg*K)]
oxygen.n_electrons = 4;                         % number of electrons per mol O2


