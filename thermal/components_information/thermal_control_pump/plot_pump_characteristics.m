close all

run('pump_data_picked_from_datasheet.m')

figure
hold on
grid on

for rpm = 1:6
    plot(squeeze(Pump_info(1,rpm,:,1)), squeeze(Pump_info(1,rpm,:,2)))
end

xlim([0 450])
ylim([0 200])

title('Pump Characteristics at 20°C')
xlabel('Volumetric Flow Rate (lpm)')
ylabel('Normalized Static Pressure Rise (kPa)')

legend('2000 rpm', '2500 rpm', '3000 rpm', '3500 rpm', '4000 rpm', '4200 rpm')