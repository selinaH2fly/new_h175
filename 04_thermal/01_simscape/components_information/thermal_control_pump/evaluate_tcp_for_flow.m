function flow_prediction_lpm = evaluate_tcp_for_flow(pressure_in_bar, ...
    pressure_out_bar, shaft_speed_rpm, make_plot)

    % This function evaluates the EMP TCP datasheet values for creating a
    % 2D lookup-table for coolant volumetric flow vs. pressure rise and
    % pump shaft speed. This lookup-table is then evaluated for the
    % specific arguments passed to the function.
    %
    % Notes:
    %   1. Presumably, the datasheet refers to water as a coolant. For
    %   Glysant, the viscosity differs quit a bit. However, changes in
    %   viscosity are expected to not have a huge impact on flow
    %   prediction.
    %
    %   2. The EMP datasheet only covers a pump shaft speed in the range of
    %   [2000, 4200] rpm. As of Apr. 16, 2024, the flow prediction is not
    %   capable of extrapolating beyond this range.

    %% Initial Variable Assignment

    % instantiate return value
    flow_prediction_lpm = -99;

    % assign optional arguments
    switch nargin
        case 3
            make_plot = false;
        case 4
            % do nothing
        otherwise
            disp('Invalid number of arguments passed to the function.')
            return
    end

    % as of Apr. 16, 2024, only for 60°C to keep it simple
    eval_temp_degC = 60;

    % evaluate eval_temp argument (passed to function, for future versions)
    % TODO: evaluate for all temperatures in the datasheet and do a 3d
    % interpolation
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


    %% Datasheet Values to 2D Lookup-Table

    % [pump_info_datasheet, pump_info_ann_prediction] = get_pump_data();
    [pump_info_datasheet, ~] = get_pump_data();

    % define discretization and instantiate lookup-table
    head_vector_kPa = 20:10:180;
    shaft_speed_vector_rpm = [2000, 2500, 3000, 3500, 4000, 4200];
    % temp_vector_degC = [20, 60, 85];
    flow_table_lpm = nan(length(head_vector_kPa), length(shaft_speed_vector_rpm));

    % interpolation of datasheet values and assignment to lookup-table
    % TODO: get rid of ugly for-loop(s)
    for shaft_speed_index = 1:size(flow_table_lpm, 2)
        % evaluate data picked from datasheet
        head_samples_kPa = squeeze(pump_info_datasheet(temp_index,shaft_speed_index,:,2));
        head_samples_kPa = head_samples_kPa(~isnan(head_samples_kPa));
        flow_samples_lpm = squeeze(pump_info_datasheet(temp_index,shaft_speed_index,:,1));
        flow_samples_lpm = flow_samples_lpm(~isnan(flow_samples_lpm));
    
        % assign 2D lookup-table
        flow_table_lpm(:, shaft_speed_index) = interp1(head_samples_kPa, ...
            flow_samples_lpm, head_vector_kPa);
    end

    %% Flow Prediction

    % compute pressure rise
    head_kPa = (pressure_out_bar - pressure_in_bar)*100;

    % evaluate lookup-table
    [head_grid_kPa, shaft_speed_grid_rpm] = meshgrid(head_vector_kPa, shaft_speed_vector_rpm);
    flow_prediction_lpm = interp2(head_grid_kPa, shaft_speed_grid_rpm, ...
        flow_table_lpm', head_kPa, shaft_speed_rpm);

    if isnan(flow_prediction_lpm)
        % flow_prediction_lpm = interp2(head_grid_kPa, shaft_speed_grid_rpm, ...
        % flow_table_lpm', head_kPa, shaft_speed_rpm, 'spline');
        % TODO: Make extrapolation work.
        disp('Vendor pump characteristics not covering domain passed to the function.')
    end

    %% Plotting

    if make_plot == true
            figure
            hold on
            plot_pump_characteristics(eval_temp_degC)
            legend('AutoUpdate','off')
            plot(flow_table_lpm, head_vector_kPa, 'x')
            plot(flow_prediction_lpm, head_kPa, 'o', 'MarkerSize', 5, ...
                'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'black')
    end

end