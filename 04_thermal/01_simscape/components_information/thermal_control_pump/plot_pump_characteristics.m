function plot_pump_characteristics(eval_temp_degC)

close all

[pump_info_datasheet, ~] = get_pump_data();

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

for rpm = 1:6
    plot(squeeze(pump_info_datasheet(temp_index,rpm,:,1)), squeeze(pump_info_datasheet(temp_index,rpm,:,2)))
end

xlim([0 450])
ylim([0 200])

title("Pump Characteristics at " + eval_temp_degC + "°C")
xlabel('Volumetric Flow Rate (l/min.)')
ylabel('Normalized Static Pressure Rise (kPa)')

legend('2000 rpm', '2500 rpm', '3000 rpm', '3500 rpm', '4000 rpm', '4200 rpm')