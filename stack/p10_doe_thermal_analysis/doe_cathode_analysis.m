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
cathode_pressure_drop_mbar = cell2mat({doe_raw_data_struct.dp_Cathode}');
cathode_pressure_inlet_bar = cell2mat({doe_raw_data_struct.pressure_cathode_inlet}');


%% separate data by stack current
index_current_100   = find(stack_current_A > 050 & stack_current_A <= 150);
index_current_200   = find(stack_current_A > 150 & stack_current_A <= 250);
index_current_300   = find(stack_current_A > 250 & stack_current_A <= 350);
index_current_400   = find(stack_current_A > 350 & stack_current_A <= 450);
index_current_500   = find(stack_current_A > 450 & stack_current_A <= 550);
index_current_600   = find(stack_current_A > 550 & stack_current_A <= 650);

%% separate data by cathode inlet pressure
index_pressure_050  = find(cathode_pressure_inlet_bar <= 0.5);
index_pressure_075  = find(cathode_pressure_inlet_bar > 0.5 & cathode_pressure_inlet_bar <= 1.0);
index_pressure_100  = find(cathode_pressure_inlet_bar > 1.0 & cathode_pressure_inlet_bar <= 1.5);
index_pressure_150  = find(cathode_pressure_inlet_bar > 1.5);

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

%% make 2D plot: dT vs. flow (current clustered)
fig_dp_vs_I = figure;
hold on
grid on

plot(stack_current_A(index_pressure_050), cathode_pressure_drop_mbar(index_pressure_050), 'o')
plot(stack_current_A(index_pressure_075), cathode_pressure_drop_mbar(index_pressure_075), 'o')
plot(stack_current_A(index_pressure_100), cathode_pressure_drop_mbar(index_pressure_100), 'o')
plot(stack_current_A(index_pressure_150), cathode_pressure_drop_mbar(index_pressure_150), 'o')


xlabel('Stack Current (A)')
ylabel('Cathode Pressure Drop (mbar)')
xlim([0,600])
ylim([0,0.5])

lgd = legend('DoE Raw Data (p_{in} \leq 0.5 barg)', ...
        'DoE Raw Data (0.5 barg < p_{in} \leq 1.0 barg)', ...
        'DoE Raw Data (1.0 barg < p_{in} \leq 1.5 barg)', ...
        'DoE Raw Data (p_{in} > 1.5 barg)');

% lgd.Location = 'northwest';

%% make 2D plot: current vs. flow (dT clustered)
% fig_flow_vs_current = figure;
% hold on
% grid on
% 
% plot(stack_current_A(index_temp_05), coolant_flow_lpm(index_temp_05), 'o')
% plot(stack_current_A(index_temp_06), coolant_flow_lpm(index_temp_06), 'o')
% plot(stack_current_A(index_temp_07), coolant_flow_lpm(index_temp_07), 'o')
% plot(stack_current_A(index_temp_08), coolant_flow_lpm(index_temp_08), 'o')
% plot(stack_current_A(index_temp_09), coolant_flow_lpm(index_temp_09), 'o')
% plot(stack_current_A(index_temp_10), coolant_flow_lpm(index_temp_10), 'o')
% plot(stack_current_A(index_temp_11), coolant_flow_lpm(index_temp_11), 'o')
% plot(stack_current_A(index_temp_12), coolant_flow_lpm(index_temp_12), 'o')
% 
% xlabel('Stack Current (A)')
% ylabel('Coolant Flow (l/min)')
% ylim([100,300])
% xlim([0, 600])
% 
% lgd = legend('DoE Raw Data (4.5°C < T_{CLSti} \leq 5.5°C )', ...
%         'DoE Raw Data (5.5°C < T_{CLSti} \leq 6.5°C)', ...
%         'DoE Raw Data (6.5°C < T_{CLSti} \leq 7.5°C', ...
%         'DoE Raw Data (7.5°C < T_{CLSti} \leq 8.5°C)', ...
%         'DoE Raw Data (8.5°C < T_{CLSti} \leq 9.5°C)', ...
%         'DoE Raw Data (9.5°C < T_{CLSti} \leq 10.5°C)', ...
%         'DoE Raw Data (10.5°C < T_{CLSti} \leq 11.5°C)', ...
%         'DoE Raw Data (11.5°C < T_{CLSti} \leq 12.5°C)');
% 
% lgd.Location = 'northwest';
% 
% %% make 3D plot: current & dT vs. flow
% fig_3D_scatter = figure;
% hold on
% grid on
% 
% scatter3(stack_current_A, coolant_delta_temp_degC, coolant_flow_lpm, 'o')
% 
% xlabel('Stack Current (A)')
% ylabel('Coolant \Delta-Temp. (°C)')
% zlabel('Coolant Flow (l/min)')
% xlim([0, 600])
% ylim([0,20])
% zlim([100,300])
% 
% view(130,35)

%% save plots
saveas(fig_dp_vs_I, fullfile('results','cathode_pressure_drop_vs_current_inlet_pressure_clustered.fig'))
saveas(fig_dp_vs_I, fullfile('results','cathode_pressure_drop_vs_current_inlet_pressure_clustered.png'))
