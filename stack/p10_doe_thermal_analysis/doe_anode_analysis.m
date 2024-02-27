clear
close all
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_struct.mat')

%% create results folder (if it does not exist, already)
if ~isfolder('results')
    mkdir('results')
end

%% extract variables of interest and write to vector
stack_current_A = cell2mat({doe_raw_data_struct.current}');
anode_pressure_drop_mbar = 1000.*cell2mat({doe_raw_data_struct.dp_Anode}');
anode_pressure_inlet_bar = cell2mat({doe_raw_data_struct.pressure_anode_inlet}');
anode_stoich = cell2mat({doe_raw_data_struct.anode_stoich}');


%% separate data by stack current
index_current_100   = find(stack_current_A > 050 & stack_current_A <= 150);
index_current_200   = find(stack_current_A > 150 & stack_current_A <= 250);
index_current_300   = find(stack_current_A > 250 & stack_current_A <= 350);
index_current_400   = find(stack_current_A > 350 & stack_current_A <= 450);
index_current_500   = find(stack_current_A > 450 & stack_current_A <= 550);
index_current_600   = find(stack_current_A > 550 & stack_current_A <= 650);

%% separate data by anode inlet pressure
index_pressure_050  = find(anode_pressure_inlet_bar <= 0.5);
index_pressure_075  = find(anode_pressure_inlet_bar > 0.5 & anode_pressure_inlet_bar <= 1.0);
index_pressure_100  = find(anode_pressure_inlet_bar > 1.0 & anode_pressure_inlet_bar <= 1.5);
index_pressure_150  = find(anode_pressure_inlet_bar > 1.5);

%% separate data by anode stoichiometry
index_stoich_15     = find(anode_stoich <= 1.5);
index_stoich_20     = find(anode_stoich > 1.5 & anode_stoich <= 2.0);
index_stoich_25     = find(anode_stoich > 2.0 & anode_stoich <= 2.5);
index_stoich_30     = find(anode_stoich > 2.5 & anode_stoich <= 3.0);
index_stoich_35     = find(anode_stoich > 3.0);

%% find correlated data (according to "P10 Power Layout")
% index_at_100 = intersect(index_current_100, index_temp_06);
% index_at_200 = intersect(index_current_200, index_temp_08);
% index_at_300 = intersect(index_current_300, index_temp_10);
% index_at_400 = intersect(index_current_400, index_temp_10);
% index_at_500 = intersect(index_current_500, index_temp_11);
% index_at_600 = intersect(index_current_600, index_temp_12);

%% compute mean flows (for "P10 Power Layout")
% flow_mean = zeros(6, 1);
% for current = 100:100:600
%     index = eval(strcat('index_at_', string(current)));
%     if ~isempty(index)
%         flow_mean(current/100) = mean(coolant_flow_lpm(index));
%         % disp('Avg. flow at ' + string(current) + ' A for specified dT: ' + string(flow_mean(current/100)))
%     % else
%          % disp('No data at ' + string(current) + ' A for specified dT')
%     end
% end

%% find mean pressure drops for mean flows
% pressure_drop_mean = zeros(6, 1);
% for current = 100:100:600
%     index = eval(strcat('index_at_', string(current)));
%     if ~isempty(index)
%         index_flow = find(coolant_flow_lpm > (flow_mean(current/100) - 5) &  coolant_flow_lpm <= (flow_mean(current/100) + 5));
%         pressure_drop_mean(current/100) = mean(coolant_pressure_drop_mbar(index_flow));
%     end
% end

%% make 2D plot: dp vs. current (inlet pressure clustered)
fig_dp_vs_I_pin = figure;
hold on
grid on

plot(stack_current_A(index_pressure_050), anode_pressure_drop_mbar(index_pressure_050), 'o')
plot(stack_current_A(index_pressure_075), anode_pressure_drop_mbar(index_pressure_075), 'o')
plot(stack_current_A(index_pressure_100), anode_pressure_drop_mbar(index_pressure_100), 'o')
plot(stack_current_A(index_pressure_150), anode_pressure_drop_mbar(index_pressure_150), 'o')


xlabel('Stack Current (A)')
ylabel('Anode Pressure Drop (mbar)')
xlim([0,600])
ylim([0,500])

lgd = legend('DoE Raw Data (\lamba \leq 0.5 barg)', ...
        'DoE Raw Data (0.5 barg < p_{in} \leq 1.0 barg)', ...
        'DoE Raw Data (1.0 barg < p_{in} \leq 1.5 barg)', ...
        'DoE Raw Data (p_{in} > 1.5 barg)');

% lgd.Location = 'northwest';

%% make 2D plot: dp vs. current (stoichiometry clustered)
fig_dp_vs_I_stoich = figure;
hold on
grid on

plot(stack_current_A(index_stoich_15), anode_pressure_drop_mbar(index_stoich_15), 'o')
plot(stack_current_A(index_stoich_20), anode_pressure_drop_mbar(index_stoich_20), 'o')
plot(stack_current_A(index_stoich_25), anode_pressure_drop_mbar(index_stoich_25), 'o')
plot(stack_current_A(index_stoich_30), anode_pressure_drop_mbar(index_stoich_30), 'o')
plot(stack_current_A(index_stoich_35), anode_pressure_drop_mbar(index_stoich_35), 'o')


xlabel('Stack Current (A)')
ylabel('Anode Pressure Drop (mbar)')
xlim([0,600])
ylim([0,500])

lgd = legend('DoE Raw Data (\lambda \leq 1.5)', ...
        'DoE Raw Data (1.5 < \lambda \leq 2.0)', ...
        'DoE Raw Data (2.0 < \lambda \leq 2.5)', ...
        'DoE Raw Data (2.5 < \lambda \leq 3.0)', ...
        'DoE Raw Data (\lambda > 3.0)');

% lgd.Location = 'northwest';

%% save plots
saveas(fig_dp_vs_I_pin, fullfile('results','anode_pressure_drop_vs_current_inlet_pressure_clustered.fig'))
saveas(fig_dp_vs_I_pin, fullfile('results','anode_pressure_drop_vs_current_inlet_pressure_clustered.png'))

saveas(fig_dp_vs_I_stoich, fullfile('results','anode_pressure_drop_vs_current_stoich_clustered.fig'))
saveas(fig_dp_vs_I_stoich, fullfile('results','anode_pressure_drop_vs_current_stoich_clustered.png'))
