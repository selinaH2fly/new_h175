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
coolant_delta_temp_degC = cell2mat({doe_raw_data_struct.temp_coolant_outlet}') ...
    - cell2mat({doe_raw_data_struct.temp_coolant_inlet}');
coolant_flow_lpm = cell2mat({doe_raw_data_struct.flow_coolant}');

%% separate data by stack current
index_current_100   = find(stack_current_A > 050 & stack_current_A <= 150);
index_current_200   = find(stack_current_A > 150 & stack_current_A <= 250);
index_current_300   = find(stack_current_A > 250 & stack_current_A <= 350);
index_current_400   = find(stack_current_A > 350 & stack_current_A <= 450);
index_current_500   = find(stack_current_A > 450 & stack_current_A <= 550);
index_current_600   = find(stack_current_A > 550 & stack_current_A <= 650);

%% separate data by stack current
index_temp_05       = find(coolant_delta_temp_degC > 04.5 & coolant_delta_temp_degC <= 05.5);
index_temp_06       = find(coolant_delta_temp_degC > 05.5 & coolant_delta_temp_degC <= 06.5);
index_temp_07       = find(coolant_delta_temp_degC > 06.5 & coolant_delta_temp_degC <= 07.5);
index_temp_08       = find(coolant_delta_temp_degC > 07.5 & coolant_delta_temp_degC <= 08.5);
index_temp_09       = find(coolant_delta_temp_degC > 08.5 & coolant_delta_temp_degC <= 09.5);
index_temp_10       = find(coolant_delta_temp_degC > 09.5 & coolant_delta_temp_degC <= 10.5);
index_temp_11       = find(coolant_delta_temp_degC > 10.5 & coolant_delta_temp_degC <= 11.5);
index_temp_12       = find(coolant_delta_temp_degC > 11.5 & coolant_delta_temp_degC <= 12.5);

%% compute means
% mean_40 = mean(drop_40);
% mean_45 = mean(drop_45);
% mean_50 = mean(drop_50);
% mean_55 = mean(drop_55);
% mean_60 = mean(drop_60);
% mean_65 = mean(drop_65);
% mean_70 = mean(drop_70);
% mean_75 = mean(drop_75);
% mean_80 = mean(drop_80);
% mean_85 = mean(drop_85);

%% make 2D plot: dT vs. flow (current clustered)
fig_flow_vs_dT = figure;
hold on
grid on

plot(coolant_delta_temp_degC(index_current_100), coolant_flow_lpm(index_current_100), 'o')
plot(coolant_delta_temp_degC(index_current_200), coolant_flow_lpm(index_current_200), 'o')
plot(coolant_delta_temp_degC(index_current_300), coolant_flow_lpm(index_current_300), 'o')
plot(coolant_delta_temp_degC(index_current_400), coolant_flow_lpm(index_current_400), 'o')
plot(coolant_delta_temp_degC(index_current_500), coolant_flow_lpm(index_current_500), 'o')
plot(coolant_delta_temp_degC(index_current_600), coolant_flow_lpm(index_current_600), 'o')

xlabel('Coolant \Delta-Temp. (°C)')
ylabel('Coolant Flow (l/min)')
xlim([0,20])
ylim([100,300])

lgd = legend('DoE Raw Data (50 A < I \leq 250 A)', ...
        'DoE Raw Data (150 A < I \leq 250 A)', ...
        'DoE Raw Data (250 A < I \leq 350 A)', ...
        'DoE Raw Data (350 A < I \leq 450 A)', ...
        'DoE Raw Data (450 A < I \leq 550 A)', ...
        'DoE Raw Data (550 A < I \leq 650 A)');

% lgd.Location = 'northwest';

%% make 2D plot: current vs. flow (dT clustered)
fig_flow_vs_current = figure;
hold on
grid on

plot(stack_current_A(index_temp_05), coolant_flow_lpm(index_temp_05), 'o')
plot(stack_current_A(index_temp_06), coolant_flow_lpm(index_temp_06), 'o')
plot(stack_current_A(index_temp_07), coolant_flow_lpm(index_temp_07), 'o')
plot(stack_current_A(index_temp_08), coolant_flow_lpm(index_temp_08), 'o')
plot(stack_current_A(index_temp_09), coolant_flow_lpm(index_temp_09), 'o')
plot(stack_current_A(index_temp_10), coolant_flow_lpm(index_temp_10), 'o')
plot(stack_current_A(index_temp_11), coolant_flow_lpm(index_temp_11), 'o')
plot(stack_current_A(index_temp_12), coolant_flow_lpm(index_temp_12), 'o')

xlabel('Stack Current (A)')
ylabel('Coolant Flow (l/min)')
ylim([100,300])
xlim([0, 600])

lgd = legend('DoE Raw Data (4.5°C < T_{CLSti} \leq 5.5°C )', ...
        'DoE Raw Data (5.5°C < T_{CLSti} \leq 6.5°C)', ...
        'DoE Raw Data (6.5°C < T_{CLSti} \leq 7.5°C', ...
        'DoE Raw Data (7.5°C < T_{CLSti} \leq 8.5°C)', ...
        'DoE Raw Data (8.5°C < T_{CLSti} \leq 9.5°C)', ...
        'DoE Raw Data (9.5°C < T_{CLSti} \leq 10.5°C)', ...
        'DoE Raw Data (10.5°C < T_{CLSti} \leq 11.5°C)', ...
        'DoE Raw Data (11.5°C < T_{CLSti} \leq 12.5°C)');

lgd.Location = 'northwest';

%% make 3D plot: current & dT vs. flow
fig_3D_scatter = figure;
hold on
grid on

scatter3(stack_current_A, coolant_delta_temp_degC, coolant_flow_lpm, 'o')


xlabel('Stack Current (A)')
ylabel('Coolant \Delta-Temp. (°C)')
zlabel('Coolant Flow (l/min)')
xlim([0, 600])
ylim([0,20])
zlim([100,300])

view(130,35)

%% save plots
saveas(fig_flow_vs_dT,fullfile('results','coolant_deltaT_vs_flow_current_clustered.fig'))
saveas(fig_flow_vs_dT,fullfile('results','coolant_deltaT_vs_flow_current_clustered.png'))

saveas(fig_flow_vs_current,fullfile('results','coolant_current_vs_flow_current_clustered.fig'))
saveas(fig_flow_vs_current,fullfile('results','coolant_current_vs_flow_current_clustered.png'))

saveas(fig_3D_scatter,fullfile('results','coolant_deltaT_and_current_vs_flow_3d.fig'))
saveas(fig_3D_scatter,fullfile('results','coolant_deltaT_and_current_vs_flow_3d.png'))