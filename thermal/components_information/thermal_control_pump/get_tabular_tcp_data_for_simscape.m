function [capacity_vector_lpm, shaft_speed_vector_rpm, head_table_m] = ...
    get_tabular_tcp_data_for_simscape(reference_density, make_plot)

    run('pump_data_picked_from_datasheet.m')
    
    capacity_vector_lpm = [50, 100, 150, 200, 250, 300, 350, 400];
    shaft_speed_vector_rpm = [2000, 2500, 3000, 3500, 4000, 4200];
    
    head_table_kPa = nan(length(capacity_vector_lpm), ...
        length(shaft_speed_vector_rpm));
    
    if make_plot == true
        run('plot_pump_characteristics.m')
        figure = gcf;
        hold on
        legend('AutoUpdate','off')
    end

    for shaft_speed = 1:6
        head_samples = squeeze(Pump_info(1,shaft_speed,:,2));
        head_samples = head_samples(~isnan(head_samples));
        capacity_samples = squeeze(Pump_info(1,shaft_speed,:,1));
        capacity_samples = capacity_samples(~isnan(capacity_samples));
    
        head_table_kPa(:, shaft_speed) = interp1(capacity_samples, ...
            head_samples, capacity_vector_lpm);

        if make_plot == true    
            plot(capacity_vector_lpm, head_table_kPa(:, shaft_speed), 'x')
        end
    
    end
    
    head_table_m = head_table_kPa*100/(reference_density*9.81);
end