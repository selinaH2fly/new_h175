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

%=============================
% Reference Values
%=============================
% p_atm = 1.01325;                    % atmospheric pressure [bar]
% p_reference = 1.01325;              % reference pressure [bar] (used for SLMP to LMP conversion among others)
% p_comp_reference = 1.0;             % reference pressure [bar] (for Fisher compressor)
% 
% T_abs_zero = -273.15;               % absolute zero temperature [°C]
% T_reference = 273.15;               % reference temperature [K] (for Fisher compressor)
% T_comp_reference = 298;
% 
% H_0 = 0;                            % reference altitude for ISA standard atmosphere
% p_0 = 1.01325;                      % reference pressure [bar] for ISA standard atmosphere
% rho_0 = 1.225;                      % reference densty [kg/m^3] for ISA standard atmosphere
% T_0 = 288.15;                       % reference temperature [K] for ISA standard atmosphere
% 
% n_atm = 1.235;                      % polytropic index [-] for ISA standard atmosphere

