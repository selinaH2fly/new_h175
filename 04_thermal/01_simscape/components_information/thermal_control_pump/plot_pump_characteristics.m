function plot_pump_characteristics(eval_temp_degC)

close all

[pump_info_datasheet, ~, pump_info_test] = get_pump_data();

figure
hold on
grid on

switch eval_temp_degC
    case 20
        temp_index = 1;
    case 60
        temp_index = 2;
    case 85
        temp_index = 3;
    otherwise
        disp('Please pass a temperature value {20, 60, 85} °C.')
        return
end 

plot(squeeze(pump_info_test(1,:,2)), squeeze(pump_info_test(1,:,1)))
plot(squeeze(pump_info_test(2,:,2)), squeeze(pump_info_test(2,:,1)))
plot(squeeze(pump_info_test(3,:,2)), squeeze(pump_info_test(3,:,1)))

for rpm = 1:6
    plot(squeeze(pump_info_datasheet(temp_index,rpm,:,1)), squeeze(pump_info_datasheet(temp_index,rpm,:,2)))
end

xlim([0 450])
ylim([0 200])

title("Pump Characteristics at " + eval_temp_degC + "°C")
xlabel('Volumetric Flow Rate (l/min.)')
ylabel('Normalized Static Pressure Rise (kPa)')

legend('500 rpm', '1000 rpm', '1500 rpm', '2000 rpm', '2500 rpm', '3000 rpm', '3500 rpm', '4000 rpm', '4200 rpm')