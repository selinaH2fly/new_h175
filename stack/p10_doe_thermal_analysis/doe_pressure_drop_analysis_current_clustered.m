clear
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_mat.mat')

%% separate data by stack current
index_sub_100  = find(doe_raw_data_mat(:,3) <= 100);
index_sub_200  = find(doe_raw_data_mat(:,3) > 100 & doe_raw_data_mat(:,3) <= 200);
index_sub_300  = find(doe_raw_data_mat(:,3) > 200 & doe_raw_data_mat(:,3) <= 300);
index_sub_400  = find(doe_raw_data_mat(:,3) > 300 & doe_raw_data_mat(:,3) <= 400);
index_sub_500  = find(doe_raw_data_mat(:,3) > 400 & doe_raw_data_mat(:,3) <= 500);
index_sub_600  = find(doe_raw_data_mat(:,3) > 500 & doe_raw_data_mat(:,3) <= 600);

%% compute pressure drops in mbar
drop_sub_100 = 1000*(doe_raw_data_mat(index_sub_100,47) - doe_raw_data_mat(index_sub_100,48));
drop_sub_200 = 1000*(doe_raw_data_mat(index_sub_200,47) - doe_raw_data_mat(index_sub_200,48));
drop_sub_300 = 1000*(doe_raw_data_mat(index_sub_300,47) - doe_raw_data_mat(index_sub_300,48));
drop_sub_400 = 1000*(doe_raw_data_mat(index_sub_400,47) - doe_raw_data_mat(index_sub_400,48));
drop_sub_500 = 1000*(doe_raw_data_mat(index_sub_500,47) - doe_raw_data_mat(index_sub_500,48));
drop_sub_600 = 1000*(doe_raw_data_mat(index_sub_600,47) - doe_raw_data_mat(index_sub_600,48));

%% compute means
mean_sub_100 = mean(drop_sub_100);
mean_sub_200 = mean(drop_sub_200);
mean_sub_300 = mean(drop_sub_300);
mean_sub_400 = mean(drop_sub_400);
mean_sub_500 = mean(drop_sub_500);
mean_sub_600 = mean(drop_sub_600);

%% make plot
fig = figure;
hold on
grid on

plot(doe_raw_data_mat(index_sub_100,32), drop_sub_100, 'o')
plot(doe_raw_data_mat(index_sub_200,32), drop_sub_200, 'o')
plot(doe_raw_data_mat(index_sub_300,32), drop_sub_300, 'o')
plot(doe_raw_data_mat(index_sub_400,32), drop_sub_400, 'o')
plot(doe_raw_data_mat(index_sub_500,32), drop_sub_500, 'o')
plot(doe_raw_data_mat(index_sub_600,32), drop_sub_600, 'o')

xlabel('Coolant Flow (l/min)')
ylabel('Pressure Drop (mbar)')
xlim([0,350])
ylim([0, 1000])

lgd = legend('DoE Raw Data (I \leq 100 A)', ...
        'DoE Raw Data (100 A < I \leq 200 A)', ...
        'DoE Raw Data (200 A < I \leq 300 A)', ...
        'DoE Raw Data (300 A < I \leq 400 A)', ...
        'DoE Raw Data (400 A < I \leq 500 A)', ...
        'DoE Raw Data (500 A < I \leq 600 A)');

lgd.Location = 'northwest';

%% save plot
saveas(fig,'coolant_pressure_drop_estimation_current_clustered.fig')
saveas(fig,'coolant_pressure_drop_estimation_current_clustered.png')