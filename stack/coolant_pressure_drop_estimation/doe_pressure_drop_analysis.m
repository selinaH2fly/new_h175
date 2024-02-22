clear
clc

%% load data
addpath('vendor_provision')
load('doe_raw_data_mat.mat')

%% separate data by coolant inlet temperature

index_fourty_null   = find(doe_raw_data_mat(:,69) > 39 & doe_raw_data_mat(:,69) <= 41);
index_fourty_five   = find(doe_raw_data_mat(:,69) > 44 & doe_raw_data_mat(:,69) <= 46);
index_fivety_null   = find(doe_raw_data_mat(:,69) > 49 & doe_raw_data_mat(:,69) <= 51);
index_fivety_five   = find(doe_raw_data_mat(:,69) > 54 & doe_raw_data_mat(:,69) <= 56);
index_sixty_null    = find(doe_raw_data_mat(:,69) > 59 & doe_raw_data_mat(:,69) <= 61);
index_sixty_five    = find(doe_raw_data_mat(:,69) > 64 & doe_raw_data_mat(:,69) <= 66);
index_seventy_null  = find(doe_raw_data_mat(:,69) > 69 & doe_raw_data_mat(:,69) <= 71);
index_seventy_five  = find(doe_raw_data_mat(:,69) > 74 & doe_raw_data_mat(:,69) <= 76);
index_eighty_null   = find(doe_raw_data_mat(:,69) > 79 & doe_raw_data_mat(:,69) <= 81);
index_eighty_five   = find(doe_raw_data_mat(:,69) > 84 & doe_raw_data_mat(:,69) <= 86);

%% make plot
figure
hold on
grid on

plot(doe_raw_data_mat(index_fourty_null,32), 1000*(doe_raw_data_mat(index_fourty_null,47) - doe_raw_data_mat(index_fourty_null,48)), 'o')
plot(doe_raw_data_mat(index_fourty_five,32), 1000*(doe_raw_data_mat(index_fourty_five,47) - doe_raw_data_mat(index_fourty_five,48)), 'o')
plot(doe_raw_data_mat(index_fivety_null,32), 1000*(doe_raw_data_mat(index_fivety_null,47) - doe_raw_data_mat(index_fivety_null,48)), 'o')
plot(doe_raw_data_mat(index_fivety_five,32), 1000*(doe_raw_data_mat(index_fivety_five,47) - doe_raw_data_mat(index_fivety_five,48)), 'o')
plot(doe_raw_data_mat(index_sixty_null,32), 1000*(doe_raw_data_mat(index_sixty_null,47) - doe_raw_data_mat(index_sixty_null,48)), 'o')
plot(doe_raw_data_mat(index_sixty_five,32), 1000*(doe_raw_data_mat(index_sixty_five,47) - doe_raw_data_mat(index_sixty_five,48)), 'o')
plot(doe_raw_data_mat(index_seventy_null,32), 1000*(doe_raw_data_mat(index_seventy_null,47) - doe_raw_data_mat(index_seventy_null,48)), 'o')
plot(doe_raw_data_mat(index_seventy_five,32), 1000*(doe_raw_data_mat(index_seventy_five,47) - doe_raw_data_mat(index_seventy_five,48)), 'o')
plot(doe_raw_data_mat(index_eighty_null,32), 1000*(doe_raw_data_mat(index_eighty_null,47) - doe_raw_data_mat(index_eighty_null,48)), 'o')
plot(doe_raw_data_mat(index_eighty_five,32), 1000*(doe_raw_data_mat(index_eighty_five,47) - doe_raw_data_mat(index_eighty_five,48)), 'o')

xlabel('Coolant Flow (l/min)')
ylabel('Pressure Drop (mbar)')
xlim([0,350])
ylim([0, 1000])

legend('DoE Raw Data (T_{CLSti} \approx 40°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 45°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 50°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 55°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 60°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 65°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 70°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 75°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 80°C)', ...
    'DoE Raw Data (T_{CLSti} \approx 85°C)')