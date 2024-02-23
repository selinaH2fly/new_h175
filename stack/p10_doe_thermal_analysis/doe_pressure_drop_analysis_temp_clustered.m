clear
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_mat.mat')

%% separate data by coolant inlet temperature
index_40    = find(doe_raw_data_mat(:,69) > 39 & doe_raw_data_mat(:,69) <= 41);
index_45    = find(doe_raw_data_mat(:,69) > 44 & doe_raw_data_mat(:,69) <= 46);
index_50    = find(doe_raw_data_mat(:,69) > 49 & doe_raw_data_mat(:,69) <= 51);
index_55    = find(doe_raw_data_mat(:,69) > 54 & doe_raw_data_mat(:,69) <= 56);
index_60    = find(doe_raw_data_mat(:,69) > 59 & doe_raw_data_mat(:,69) <= 61);
index_65    = find(doe_raw_data_mat(:,69) > 64 & doe_raw_data_mat(:,69) <= 66);
index_70    = find(doe_raw_data_mat(:,69) > 69 & doe_raw_data_mat(:,69) <= 71);
index_75    = find(doe_raw_data_mat(:,69) > 74 & doe_raw_data_mat(:,69) <= 76);
index_80    = find(doe_raw_data_mat(:,69) > 79 & doe_raw_data_mat(:,69) <= 81);
index_85    = find(doe_raw_data_mat(:,69) > 84 & doe_raw_data_mat(:,69) <= 86);

%% compute pressure drops in mbar
drop_40     = 1000*(doe_raw_data_mat(index_40,47) - doe_raw_data_mat(index_40,48));
drop_45     = 1000*(doe_raw_data_mat(index_45,47) - doe_raw_data_mat(index_45,48));
drop_50     = 1000*(doe_raw_data_mat(index_50,47) - doe_raw_data_mat(index_50,48));
drop_55     = 1000*(doe_raw_data_mat(index_55,47) - doe_raw_data_mat(index_55,48));
drop_60     = 1000*(doe_raw_data_mat(index_60,47) - doe_raw_data_mat(index_60,48));
drop_65     = 1000*(doe_raw_data_mat(index_65,47) - doe_raw_data_mat(index_65,48));
drop_70     = 1000*(doe_raw_data_mat(index_70,47) - doe_raw_data_mat(index_70,48));
drop_75     = 1000*(doe_raw_data_mat(index_75,47) - doe_raw_data_mat(index_75,48));
drop_80     = 1000*(doe_raw_data_mat(index_80,47) - doe_raw_data_mat(index_80,48));
drop_85     = 1000*(doe_raw_data_mat(index_85,47) - doe_raw_data_mat(index_85,48));

%% compute means
mean_40 = mean(drop_40);
mean_45 = mean(drop_45);
mean_50 = mean(drop_50);
mean_55 = mean(drop_55);
mean_60 = mean(drop_60);
mean_65 = mean(drop_65);
mean_70 = mean(drop_70);
mean_75 = mean(drop_75);
mean_80 = mean(drop_80);
mean_85 = mean(drop_85);

%% make plot
fig = figure;
hold on
grid on

plot(doe_raw_data_mat(index_40,32), drop_40, 'o')
plot(doe_raw_data_mat(index_45,32), drop_45, 'o')
plot(doe_raw_data_mat(index_50,32), drop_50, 'o')
plot(doe_raw_data_mat(index_55,32), drop_55, 'o')
plot(doe_raw_data_mat(index_60,32), drop_60, 'o')
plot(doe_raw_data_mat(index_65,32), drop_65, 'o')
plot(doe_raw_data_mat(index_70,32), drop_70, 'o')
plot(doe_raw_data_mat(index_75,32), drop_75, 'o')
plot(doe_raw_data_mat(index_80,32), drop_80, 'o')
plot(doe_raw_data_mat(index_85,32), drop_85, 'o')

xlabel('Coolant Flow (l/min)')
ylabel('Pressure Drop (mbar)')
xlim([0,350])
ylim([0, 1000])

lgd = legend('DoE Raw Data (T_{CLSti} \approx 40°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 45°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 50°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 55°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 60°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 65°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 70°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 75°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 80°C)', ...
        'DoE Raw Data (T_{CLSti} \approx 85°C)');

lgd.Location = 'northwest';

%% save plot
saveas(fig,'coolant_pressure_drop_estimation_temp_clustered.fig')
saveas(fig,'coolant_pressure_drop_estimation_temp_clustered.png')