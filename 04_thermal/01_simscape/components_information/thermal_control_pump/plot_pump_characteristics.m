close all

[pump_info_datasheet, ~] = get_pump_data();

figure
hold on
grid on

for rpm = 1:6
    plot(squeeze(pump_info_datasheet(1,rpm,:,1)), squeeze(pump_info_datasheet(1,rpm,:,2)))
end

xlim([0 450])
ylim([0 200])

title('Pump Characteristics at 20°C')
xlabel('Volumetric Flow Rate (lpm)')
ylabel('Normalized Static Pressure Rise (kPa)')

legend('2000 rpm', '2500 rpm', '3000 rpm', '3500 rpm', '4000 rpm', '4200 rpm')