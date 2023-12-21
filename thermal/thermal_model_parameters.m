%% Definition of Parameters for HT-Cooling Plant Model

% Coolant initial conditions
coolant_initial_pressure = 0.111325; % [MPa] Pressure
coolant_initial_temperature = 293.15; % [K] Temperature
coolant_tube_D = 0.05; % [m] Coolant tube diameter

% TCV parameters
tcv_orifice_diameter = 0.045; % [m] TCV max. orifice diameter (note: the valve model (3-way linear valve) does not meed the design of the actual TCV)
tcv_rate_limit = 45; % [1/s] percentage opening per second
tcv_time_constant = .2; % [s] time constant for PT1 dynamics
tcv_leakage_area = 4e-5; % [m2] leakage area

% TCP parameters
tcp_rate_limit = 1000; % [rpm/s] rpm rate limit per second
tcp_time_constant = 2; % [s] time constant for PT1 dynamics
