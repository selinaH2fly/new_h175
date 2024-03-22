function [capacity_vector_lpm, shaft_speed_vector_rpm, head_table_m] = ...
    get_tabular_tcp_data_for_simscape(reference_density, make_plot)

    [pump_info_datasheet, pump_info_ann_prediction] = get_pump_data();
    
    capacity_vector_lpm = [10, 20, 30, 40, 50, 75, 100, 150, 200, 250, 300, 350, 400];
    shaft_speed_vector_rpm = [1400, 2000, 2500, 3000, 3500, 4000, 4200];
    
    head_table_kPa = nan(length(capacity_vector_lpm), ...
        length(shaft_speed_vector_rpm));
    
    if make_plot == true
        run('plot_pump_characteristics.m')
        hold on
        legend('AutoUpdate','off')
    end

    % interpolation of datasheet values and assignment to lookup table
    for shaft_speed = 1:6
        datasheet_head_samples = squeeze(pump_info_datasheet(1,shaft_speed,:,2));
        datasheet_head_samples = datasheet_head_samples(~isnan(datasheet_head_samples));
        datasheet_capacity_samples = squeeze(pump_info_datasheet(1,shaft_speed,:,1));
        datasheet_capacity_samples = datasheet_capacity_samples(~isnan(datasheet_capacity_samples));
    
        head_table_kPa(:, shaft_speed+1) = interp1(datasheet_capacity_samples, ...
            datasheet_head_samples, capacity_vector_lpm);

        if make_plot == true    
            plot(capacity_vector_lpm, head_table_kPa(:, shaft_speed+1), 'x')
        end
    
    end

    % interpolation of ann prediction values and assignment to lookup table
    ann_head_samples = pump_info_ann_prediction.rpm1400_degC60(:, 2);
    ann_capacity_samples = pump_info_ann_prediction.rpm1400_degC60(:, 1);
    head_table_kPa(:, 1) = interp1(ann_capacity_samples, ...
            ann_head_samples, capacity_vector_lpm);

    if make_plot == true    
            plot(capacity_vector_lpm, head_table_kPa(:, 1), 'x')
    end

    % conversion to head in terms of meters
    head_table_m = head_table_kPa*1000/(reference_density*9.81);
end