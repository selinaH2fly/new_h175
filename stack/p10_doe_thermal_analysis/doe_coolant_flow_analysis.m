clear
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_struct.mat')

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

%% make plot
fig = figure;
hold on
grid on

plot(coolant_flow_lpm(index_current_100), coolant_delta_temp_degC(index_current_100), 'o')
plot(coolant_flow_lpm(index_current_200), coolant_delta_temp_degC(index_current_200), 'o')
plot(coolant_flow_lpm(index_current_300), coolant_delta_temp_degC(index_current_300), 'o')
plot(coolant_flow_lpm(index_current_400), coolant_delta_temp_degC(index_current_400), 'o')
plot(coolant_flow_lpm(index_current_500), coolant_delta_temp_degC(index_current_500), 'o')
plot(coolant_flow_lpm(index_current_600), coolant_delta_temp_degC(index_current_600), 'o')

xlabel('Coolant Flow (l/min)')
ylabel('Coolant \Delta-Temp. (°C)')
xlim([100,300])
ylim([0, 20])

lgd = legend('DoE Raw Data (050 A < I \leq 250 A)', ...
        'DoE Raw Data (150 A < I \leq 250 A)', ...
        'DoE Raw Data (250 A < I \leq 350 A)', ...
        'DoE Raw Data (350 A < I \leq 450 A)', ...
        'DoE Raw Data (450 A < I \leq 550 A)', ...
        'DoE Raw Data (550 A < I \leq 650 A)');

% lgd.Location = 'northwest';

%% save plot
saveas(fig,'coolant_deltaT_vs_flow_current_clustered.fig')
saveas(fig,'coolant_deltaT_vs_flow_current_clustered.png')