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
coolant_inlet_temp_degC = cell2mat({doe_raw_data_struct.temp_coolant_inlet}');
coolant_delta_temp_degC = cell2mat({doe_raw_data_struct.temp_coolant_outlet}') ...
    - coolant_inlet_temp_degC;
coolant_flow_lpm = cell2mat({doe_raw_data_struct.flow_coolant}');
coolant_pressure_drop_mbar = 1000*(cell2mat({doe_raw_data_struct.pressure_coolant_inlet}') ...
    - cell2mat({doe_raw_data_struct.pressure_coolant_outlet}'));

%% separate data by coolant inlet temperature
index_temp_40   = find(coolant_inlet_temp_degC > 39 & coolant_inlet_temp_degC <= 41);
index_temp_45   = find(coolant_inlet_temp_degC > 44 & coolant_inlet_temp_degC <= 46);
index_temp_50   = find(coolant_inlet_temp_degC > 49 & coolant_inlet_temp_degC <= 51);
index_temp_55   = find(coolant_inlet_temp_degC > 54 & coolant_inlet_temp_degC <= 56);
index_temp_60   = find(coolant_inlet_temp_degC > 59 & coolant_inlet_temp_degC <= 61);
index_temp_65   = find(coolant_inlet_temp_degC > 64 & coolant_inlet_temp_degC <= 66);
index_temp_70   = find(coolant_inlet_temp_degC > 69 & coolant_inlet_temp_degC <= 71);
index_temp_75   = find(coolant_inlet_temp_degC > 74 & coolant_inlet_temp_degC <= 76);
index_temp_80   = find(coolant_inlet_temp_degC > 79 & coolant_inlet_temp_degC <= 81);
index_temp_85   = find(coolant_inlet_temp_degC > 84 & coolant_inlet_temp_degC <= 86);

%% separate data by coolant flow
% Necessary?

%% find corresponding pressure drops
drop_temp_40    = coolant_pressure_drop_mbar(index_temp_40);
drop_temp_45    = coolant_pressure_drop_mbar(index_temp_45);
drop_temp_50    = coolant_pressure_drop_mbar(index_temp_50);
drop_temp_55    = coolant_pressure_drop_mbar(index_temp_55);
drop_temp_60    = coolant_pressure_drop_mbar(index_temp_60);
drop_temp_65    = coolant_pressure_drop_mbar(index_temp_65);
drop_temp_70    = coolant_pressure_drop_mbar(index_temp_70);
drop_temp_75    = coolant_pressure_drop_mbar(index_temp_75);
drop_temp_80    = coolant_pressure_drop_mbar(index_temp_80);
drop_temp_85    = coolant_pressure_drop_mbar(index_temp_85);

%% find corresponding flows
flow_temp_40    = coolant_flow_lpm(index_temp_40);
flow_temp_45    = coolant_flow_lpm(index_temp_45);
flow_temp_50    = coolant_flow_lpm(index_temp_50);
flow_temp_55    = coolant_flow_lpm(index_temp_55);
flow_temp_60    = coolant_flow_lpm(index_temp_60);
flow_temp_65    = coolant_flow_lpm(index_temp_65);
flow_temp_70    = coolant_flow_lpm(index_temp_70);
flow_temp_75    = coolant_flow_lpm(index_temp_75);
flow_temp_80    = coolant_flow_lpm(index_temp_80);
flow_temp_85    = coolant_flow_lpm(index_temp_85);

%% make plot
fig = figure;
hold on
grid on

% plot(flow_temp_40, drop_temp_40, 'o')
% plot(flow_temp_45, drop_temp_45, 'o')
% plot(flow_temp_50, drop_temp_50, 'o')
% plot(flow_temp_55, drop_temp_55, 'o')
% plot(flow_temp_60, drop_temp_60, 'o')
% plot(flow_temp_65, drop_temp_65, 'o')
% plot(flow_temp_70, drop_temp_70, 'o')
% plot(flow_temp_75, drop_temp_75, 'o')
% plot(flow_temp_80, drop_temp_80, 'o')
% plot(flow_temp_85, drop_temp_85, 'o')

xlabel('Coolant Flow (l/min)')
ylabel('Pressure Drop (mbar)')
xlim([0,350])
ylim([0, 1000])

% lgd = legend('DoE Raw Data (T_{CLSti} \approx 40°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 45°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 50°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 55°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 60°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 65°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 70°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 75°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 80°C)', ...
%         'DoE Raw Data (T_{CLSti} \approx 85°C)', ...
%         'AutoUpdate', 'off');
% 
% lgd.Location = 'northwest';

%% polynomial fit (MATLAB)
% TODO: https://blogs.mathworks.com/pick/2015/12/11/polynomial-fit-passing-through-specified-points/

% fit_temp_40     = polyfit(flow_temp_40, drop_temp_40, 2);
% fit_temp_45     = polyfit(flow_temp_45, drop_temp_45, 2);
% fit_temp_50     = polyfit(flow_temp_50, drop_temp_50, 2);
% fit_temp_55     = polyfit(flow_temp_55, drop_temp_55, 2);
% fit_temp_60     = polyfit(flow_temp_60, drop_temp_60, 2);
% fit_temp_65     = polyfit(flow_temp_65, drop_temp_65, 2);
% fit_temp_70     = polyfit(flow_temp_70, drop_temp_70, 2);
% fit_temp_75     = polyfit(flow_temp_75, drop_temp_75, 2);
% fit_temp_80     = polyfit(flow_temp_80, drop_temp_80, 2);
% fit_temp_85     = polyfit(flow_temp_85, drop_temp_85, 2);
% 
% flow_vec = linspace(0, 350, 100);

% plot(flow_vec, polyval(fit_temp_40, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_45, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_50, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_55, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_60, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_65, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_70, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_75, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_80, flow_vec), 'b-', 'LineWidth', 1)
% plot(flow_vec, polyval(fit_temp_85, flow_vec), 'b-', 'LineWidth', 1)

%% polynomial fit (Excel)
% Excel allows for a polynomial fit + a equality constraint (without the
% need for an extra toolbox).

% write to Excel
if ~isfolder('generated_csv')
    mkdir('generated_csv')
end

temps = 40:5:85;

for temp = temps
    flows = eval(strcat('flow_temp_', string(temp)));
    drops = eval(strcat('drop_temp_', string(temp)));
    if ~isempty(flows)
        filename = fullfile('generated_csv', strcat('coolant_dp_vs_flow_temp_', string(temp), '.xls'));
        writematrix([flows drops], filename)
    end
end

% from Excel
flow_vec = linspace(0, 350, 100);

coeff_temp_40 = [8.3e-3, 0.207, 0];
dp_reg_40 = coeff_temp_40*[flow_vec.^2; flow_vec; ones(1, length(flow_vec))];

coeff_temp_50 = [7.3e-3, 0.380, 0];
dp_reg_50 = coeff_temp_50*[flow_vec.^2; flow_vec; ones(1, length(flow_vec))];

coeff_temp_60 = [6.7e-3, 0.448, 0];
dp_reg_60 = coeff_temp_60*[flow_vec.^2; flow_vec; ones(1, length(flow_vec))];

coeff_temp_70 = [6.7e-3, 0.395, 0];
dp_reg_70 = coeff_temp_70*[flow_vec.^2; flow_vec; ones(1, length(flow_vec))];

coeff_temp_80 = [7.5e-3, 0.181, 0];
dp_reg_80 = coeff_temp_80*[flow_vec.^2; flow_vec; ones(1, length(flow_vec))];

% plot
plot(flow_vec, dp_reg_40, '-', 'LineWidth', 1)
plot(flow_vec, dp_reg_50, '-', 'LineWidth', 1)
plot(flow_vec, dp_reg_60, '-', 'LineWidth', 1)
plot(flow_vec, dp_reg_70, '-', 'LineWidth', 1)
plot(flow_vec, dp_reg_80, '-', 'LineWidth', 1)

lgd2 = legend('2nd Order Reg. @ T_{CLSti} \approx 40°C (a_2 = 8.3e-3, a_1 = 0.207)', ...
        '2nd Order Reg. @ T_{CLSti} \approx 50°C (a_2 = 7.3e-3, a_1 = 0.380)', ...
        '2nd Order Reg. @ T_{CLSti} \approx 60°C (a_2 = 6.7e-3, a_1 = 0.448)', ...
        '2nd Order Reg. @ T_{CLSti} \approx 70°C (a_2 = 6.7e-3, a_1 = 0.395)', ...
        '2nd Order Reg. @ T_{CLSti} \approx 80°C (a_2 = 7.5e-3, a_1 = 0.181)');

lgd2.Location = 'northwest';


%% save plot
saveas(fig,fullfile('results','doe_coolant_pressure_drop_vs_flow.fig'))
saveas(fig,fullfile('results','doe_coolant_pressure_drop_vs_flow.png'))