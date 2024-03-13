clear
close all
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_struct.mat')

%% set falg for plotting
% TODO: Make a function out of this script and pass the falg as an
% argument.

make_plot = true;

%% create results folder (if it does not exist, already)
if ~isfolder('results')
    mkdir('results')
end

%% extract variables of interest and write to vector
stack_current_A = cell2mat({doe_raw_data_struct.current}');
cathode_pressure_drop_mbar = 1000.*cell2mat({doe_raw_data_struct.dp_Cathode}');
cathode_pressure_inlet_bar = cell2mat({doe_raw_data_struct.pressure_cathode_inlet}');
cathode_stoich = cell2mat({doe_raw_data_struct.cathode_stoich}');

%% separate data by stack current
index_current_050   = find(stack_current_A > 025 & stack_current_A <= 075);
index_current_100   = find(stack_current_A > 075 & stack_current_A <= 125);
index_current_150   = find(stack_current_A > 125 & stack_current_A <= 175);
index_current_200   = find(stack_current_A > 175 & stack_current_A <= 225);
index_current_250   = find(stack_current_A > 225 & stack_current_A <= 275);
index_current_300   = find(stack_current_A > 275 & stack_current_A <= 325);
index_current_350   = find(stack_current_A > 325 & stack_current_A <= 375);
index_current_400   = find(stack_current_A > 375 & stack_current_A <= 425);
index_current_450   = find(stack_current_A > 425 & stack_current_A <= 475);
index_current_500   = find(stack_current_A > 475 & stack_current_A <= 525);
index_current_550   = find(stack_current_A > 525 & stack_current_A <= 575);

%% separate data by cathode inlet pressure
index_pressure_050  = find(cathode_pressure_inlet_bar <= 0.5);
index_pressure_075  = find(cathode_pressure_inlet_bar > 0.5 & cathode_pressure_inlet_bar <= 1.0);
index_pressure_100  = find(cathode_pressure_inlet_bar > 1.0 & cathode_pressure_inlet_bar <= 1.5);
index_pressure_150  = find(cathode_pressure_inlet_bar > 1.5);

%% separate data by cathode stoichiometry
index_stoich_15     = find(cathode_stoich <= 1.5);
index_stoich_20     = find(cathode_stoich > 1.5 & cathode_stoich <= 2.0);
index_stoich_25     = find(cathode_stoich > 2.0 & cathode_stoich <= 2.5);
index_stoich_30     = find(cathode_stoich > 2.5 & cathode_stoich <= 3.0);
index_stoich_35     = find(cathode_stoich > 3.0);

index_stoich_18     = find(cathode_stoich > 1.6 & cathode_stoich <= 2.0);
index_stoich_21     = find(cathode_stoich > 1.9 & cathode_stoich <= 2.3);
index_stoich_32     = find(cathode_stoich > 3.0 & cathode_stoich <= 3.4);
index_stoich_53     = find(cathode_stoich > 5.1 & cathode_stoich <= 5.5);

%% find correlated data (according to "P10 Power Layout")
index_at_50     = intersect(index_current_050, index_stoich_53);
index_at_100    = intersect(index_current_100, index_stoich_32);
index_at_150    = intersect(index_current_150, index_stoich_21);
index_at_200    = intersect(index_current_200, index_stoich_18);
index_at_250    = intersect(index_current_250, index_stoich_18);
index_at_300    = intersect(index_current_300, index_stoich_18);
index_at_350    = intersect(index_current_350, index_stoich_18);
index_at_400    = intersect(index_current_400, index_stoich_18);
index_at_450    = intersect(index_current_450, index_stoich_18);
index_at_500    = intersect(index_current_500, index_stoich_18);
index_at_550    = intersect(index_current_550, index_stoich_18);

%% compute pressure drops (for "P10 Power Layout")
% TODO: Make this less ugly :-(

dp_mean = zeros(11, 1);
currents = linspace(50,550,11);

for current = currents
    index = eval(strcat('index_at_', string(current)));
    if ~isempty(index)
        dp_mean(current/50) = mean(cathode_pressure_drop_mbar(index));
        % disp('Avg. flow at ' + string(current) + ' A for specified dT: ' + string(flow_mean(current/100)))
    % else
         % disp('No data at ' + string(current) + ' A for specified dT')
    end
end

%% polynomial fit
% Regression done in Excel, for the moment.

coefficents = [3e-4, 0.20, 28.6];
current_reg = linspace(0,600,100);
dp_mean_reg = coefficents*[current_reg.^2; current_reg; ones(1, length(current_reg))];

%% make 2D plot: dp vs. current (stoichiometry clustered)
if make_plot
    fig_dp_vs_I_stoich = figure;
    hold on
    grid on
    
    plot(stack_current_A(index_stoich_15), cathode_pressure_drop_mbar(index_stoich_15), 'o')
    plot(stack_current_A(index_stoich_20), cathode_pressure_drop_mbar(index_stoich_20), 'o')
    plot(stack_current_A(index_stoich_25), cathode_pressure_drop_mbar(index_stoich_25), 'o')
    plot(stack_current_A(index_stoich_30), cathode_pressure_drop_mbar(index_stoich_30), 'o')
    plot(stack_current_A(index_stoich_35), cathode_pressure_drop_mbar(index_stoich_35), 'o')

    plot(currents, dp_mean, 'k-x')
    plot(current_reg, dp_mean_reg, 'b-', 'LineWidth', 2)
    
    xlabel('Stack Current (A)')
    ylabel('Cathode Pressure Drop (mbar)')
    xlim([0,600])
    ylim([0,500])
    
    lgd = legend('DoE Raw Data (\lambda \leq 1.5)', ...
            'DoE Raw Data (1.5 < \lambda \leq 2.0)', ...
            'DoE Raw Data (2.0 < \lambda \leq 2.5)', ...
            'DoE Raw Data (2.5 < \lambda \leq 3.0)', ...
            'DoE Raw Data (\lambda > 3.0)', ...
            'Avg. Values for specified \lambda',...
            strcat('2nd Order Regression:', ...
            string(newline), 'a_2 = ', string(coefficents(1)), ', a_1 = ', string(coefficents(2)), ', a_0 = ', string(coefficents(3))));
    % lgd.Location = 'northwest';

    saveas(fig_dp_vs_I_stoich, fullfile('results','cathode_pressure_drop_vs_current_stoich_clustered.fig'))
    saveas(fig_dp_vs_I_stoich, fullfile('results','cathode_pressure_drop_vs_current_stoich_clustered.png'))
end

%% save plots
% saveas(fig_dp_vs_I_pin, fullfile('results','cathode_pressure_drop_vs_current_inlet_pressure_clustered.fig'))
% saveas(fig_dp_vs_I_pin, fullfile('results','cathode_pressure_drop_vs_current_inlet_pressure_clustered.png'))


