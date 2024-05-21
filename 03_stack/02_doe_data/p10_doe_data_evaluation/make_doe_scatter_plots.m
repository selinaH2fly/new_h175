function make_doe_scatter_plots()

%% load data
addpath('vendor_provision')
load('doe_raw_data_struct.mat')

%% create results folder (if it does not exist, already)
if ~isfolder('results')
    mkdir('results')
end

%% extract variables of interest and write to vector
stack_current_A = cell2mat({doe_raw_data_struct.current}');
variable_a = cell2mat({doe_raw_data_struct.flow_coolant}'); % exemplarily; either simply insert your variable's name (cf. .csv headings) or make it proper cool by passing it as an argument to the function 

% variable_b = ...
% You can easily subtract, add, whatever

%% make plot
fig = figure;
hold on
grid on

plot_a = plot(stack_current_A, variable_a, 'o', 'DisplayName', 'my legend entry');
% plot_b = ...

xlabel('Stack Current (A)')
ylabel('My Variable (-)')
xlim([0,550])
%ylim([0, 1000])

lgd = legend;
lgd.Location = 'northwest';
lgd.NumColumns = 1;

%% save plot
saveas(fig,fullfile('results','doe_eval_example.fig'))
saveas(fig,fullfile('results','doe_eval_example.png'))