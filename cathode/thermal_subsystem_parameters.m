%% Definition of Parameters for HT-Cooling Plant Model

% Coolant initial conditions
coolant_initial_pressure = 0.111325; % [MPa] Pressure
coolant_initial_temperature = 293.15; % [K] Temperature
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

%% coolant supply
% TODO: Don't these bus definition refer to the stack model!?

coolant_supply = Simulink.Bus;
coolant_supply.Description = '';
coolant_supply.DataScope = 'Auto';
coolant_supply.HeaderFile = '';
coolant_supply.Alignment = -1;
coolant_supply.PreserveElementDimensions = false;
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'inlet_flow_lpmin';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = '';
saveVarsTmp{1}.Description = '';
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'inlet_temperature_degC';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = '';
saveVarsTmp{1}(2, 1).Description = '';
coolant_supply.Elements = saveVarsTmp{1};
clear saveVarsTmp;

coolant_supply_elements = Simulink.BusElement;
coolant_supply_elements.Name = 'inlet_flow_lpmin';
coolant_supply_elements.Complexity = 'real';
coolant_supply_elements.Dimensions = 1;
coolant_supply_elements.DataType = 'double';
coolant_supply_elements.Min = [];
coolant_supply_elements.Max = [];
coolant_supply_elements.DimensionsMode = 'Fixed';
coolant_supply_elements.SamplingMode = 'Sample based';
coolant_supply_elements.DocUnits = '';
coolant_supply_elements.Description = '';
coolant_supply_elements(2) = Simulink.BusElement;
coolant_supply_elements(2).Name = 'inlet_temperature_degC';
coolant_supply_elements(2).Complexity = 'real';
coolant_supply_elements(2).Dimensions = 1;
coolant_supply_elements(2).DataType = 'double';
coolant_supply_elements(2).Min = [];
coolant_supply_elements(2).Max = [];
coolant_supply_elements(2).DimensionsMode = 'Fixed';
coolant_supply_elements(2).SamplingMode = 'Sample based';
coolant_supply_elements(2).DocUnits = '';
coolant_supply_elements(2).Description = '';