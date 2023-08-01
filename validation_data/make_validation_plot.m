% This script makes a plot comparing real-world testbanch data and
% simulation results subject to the identical input values.

load('20-07-2023_CTS_Data_to_Validate_Sim.mat')
load('20-07-2023_CTS_Data_Simout.mat')

% close all
fig = tiledlayout(3,3,'TileSpacing','Compact');
title(fig,'HT-Cooling: Testbanch Data vs. Simulation Results')

%% input data

current = nexttile(1);
title(current,'(Real-World) Input Data')
hold on
plot(testdata_input.stack_current(:,1), testdata_input.stack_current(:,2))
grid on
xlim([0, 3000])
ylim([0, 350])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
ylabel('Stack Current (A)')

tcv = nexttile(4);
plot(testdata_input.tcv_target_pos(:,1), smoothdata(testdata_input.tcv_target_pos(:,2),'movmean',10))
grid on
xlim([0, 3000])
ylim([0, 100])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
ylabel('TCV Position (%)')

tcp = nexttile(7);
hold on
plot(testdata_input.tcp_target_speed(:,1), smoothdata(testdata_input.tcp_target_speed(:,2),'movmean',10))
plot(testdata_input.auxtcp_target_speed(:,1), smoothdata(testdata_input.auxtcp_target_speed(:,2),'movmean',10))
grid on
xlim([0, 3000])
ylim([0, 4000])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'Internal Pump', 'External Pump'},'Location','northwest')
ylabel('TCP Rot. Speeds (rpm)')
xlabel('Time (min.)')

%% Testbanch Results

temp_real = nexttile(2);
title(temp_real,'(Real-World) Testbanch Data')
hold on
rectangle('Position',[46*60, 20, 14*60, 80], 'FaceColor', '#D95319', 'EdgeColor', 'none')
plot(testdata_output.tcv_input_temp(:,1),testdata_output.tcv_input_temp(:,2),'Color',"#0072BD")
plot(testdata_output.stack_input_temp(:,1),testdata_output.stack_input_temp(:,2),'Color',"#EDB120")
plot(testdata_output.stack_outlet_temp(:,1),testdata_output.stack_outlet_temp(:,2),'Color',"#D95319")
grid on
xlim([0, 3000])
ylim([20, 100])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'TCV Inlet (T6801)', 'Stack Inlet (T6812)', 'Stack Outlet (T6820)'},'Location','northwest')
ylabel('Coolant Temperature (°C)')

press_real = nexttile(5);
hold on
rectangle('Position',[46*60, 0, 14*60, 3], 'FaceColor', '#D95319', 'EdgeColor', 'none')
plot(testdata_output.tcp_input_press(:,1),smoothdata(testdata_output.tcp_input_press(:,2),'movmean',100),'Color',"#7E2F8E")
plot(testdata_output.tcv_input_press(:,1),smoothdata(testdata_output.tcv_input_press(:,2),'movmean',100),'Color',"#0072BD")
plot(testdata_output.stack_input_press(:,1),smoothdata(testdata_output.stack_input_press(:,2),'movmean',100),'Color',"#EDB120")
grid on
xlim([0, 3000])
ylim([0, 3])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'TCP Inlet (p6811)', 'TCV Inlet (p6801)', 'Stack Inlet (p6812)'},'Location','northwest')
ylabel('Coolant Pressure (bara)')

massflow_real = nexttile(8);
[img, map, alphachannel] = imread('pngegg.png');
image(img, 'AlphaData', alphachannel);
ylim([0,2000])
yticklabels({'4','3','2','1','0'})
% set(gca,'YTick',[])
xlim([0, 2000])
xticks(0:400:2000)
xticklabels({'0','10','20','30','40','50'})
ylabel('Massflow Readings (kg/s)')
xlabel('Time (min.)')

%% Simulation Results

temp_sim = nexttile(3);
title(temp_sim,'Simulation Results')
hold on
rectangle('Position',[46*60, 20, 14*60, 80], 'FaceColor', '#D95319', 'EdgeColor', 'none')
plot(simout_13h45_010823.simout.TCV_Inlet_Temperature__TSens_TCVi_6801____C_,'Color',"#0072BD")
plot(simout_13h45_010823.simout.Stack_Inlet_Temperature__TSens_CLSti_6812____C_,'Color',"#EDB120")
plot(simout_13h45_010823.simout.Stack_Outlet_Temperature__TSens_CLSto_6820____C_,'Color',"#D95319")
grid on
xlim([0, 3000])
ylim([20, 100])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'TCV Inlet (T6801)', 'Stack Inlet (T6812)', 'Stack Outlet (T6820)'},'Location','northwest')
ylabel('Coolant Temperature (°C)')

press_sim = nexttile(6);
hold on
rectangle('Position',[46*60, 0, 14*60, 3], 'FaceColor', '#D95319', 'EdgeColor', 'none')
plot(simout_13h45_010823.simout.TCP_Inlet_Pressure__pSens_TCPi_6811__Bar_,'Color',"#7E2F8E")
plot(simout_13h45_010823.simout.TCV_Inlet_Pressure__pSens_TCVi_6801__Bar_,'Color',"#0072BD")
plot(simout_13h45_010823.simout.Stack_Inlet_Pressure__pSens_CLSti_6812__Bar_,'Color',"#EDB120")
grid on
xlim([0, 3000])
ylim([0, 3])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'TCP Inlet (p6811)', 'TCV Inlet (p6801)', 'Stack Inlet (p6812)'},'Location','northwest')
ylabel('Coolant Pressure (bara)')

massflow_sim = nexttile(9);
hold on
rectangle('Position',[46*60, 0, 14*60, 4], 'FaceColor', '#D95319', 'EdgeColor', 'none')
plot(simout_13h45_010823.simout.Cold_Circuit_Coolant_Massflow__kg_s_,'Color',"#0072BD")
plot(simout_13h45_010823.simout.Hot_Circuit_Coolant_Massflow__kg_s_,'Color',"#D95319")
plot(simout_13h45_010823.simout.Overall_Coolant_Massflow__kg_s_,'Color',"#EDB120")
grid on
xlim([0, 3000])
ylim([0, 4])
xticks(0:600:3000)
xticklabels({'0','10','20','30','40','50'})
legend({'Cold Circuit', 'Hot Circuit', 'Overall'},'Location','northwest')
ylabel('Massflow Readings (kg/s)')
xlabel('Time (min.)')

%% save figure
print('HT-Cooling_Testbanch_vs_Simulation_20-07-2023','-dpng','-r600')
exportgraphics(fig,'HT-Cooling_Testbanch_vs_Simulation_20-07-2023.pdf')

