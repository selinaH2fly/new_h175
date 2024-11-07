import os
import pandas as pd

# Define the directory containing CSV files
folder_path = 'C:\Users\tobias.goosmann\Documents\GIT\h175model\03_stack\02_doe_data\06_p10_doe_gpr_GTSuite\simulationresult_GTSuite'
csv_files = [file for file in os.listdir(folder_path) if file.endswith('.csv)')]

# Display available CSV files
print('available csv files')
for i, file in enumerate(csv_files, start=1):
    print("f{i}. {file}")

# select files to load
selected_files = input("Enter file numbers separated by commas or tpye'all' to select all: ")
if selected_files.lower() == 'all':
    selected_files = csv_files
else:
    selected_indices = [int(idx.strip()) - 1 for idx in selected_files.split(',')]
    selected_files = [csv_files[i] for i in selected_indices]

# load and combine seletcted csv files
data_frames = [pd.read_csv(os.path.join(folder_path, file)) for file in selected_files]
combined_data = [pd.concat(data_frames, ignore_index=True)]

# rename columns if necessary
rename_columns = {
    'old_column_name1': 'new_column_name1',
    'old_column_name2': 'new_column_name2'
}
combined_data.rename(columns=rename_columns, inplace= True)

# save combined data to a new CSV
output_path = 'C:\Users\tobias.goosmann\Documents\GIT\h175model\03_stack\02_doe_data\06_p10_doe_gpr_GTSuite\input_data'
combined_data.to_csv(output_path,index=False)
print(f"Combined data saved to {output_path}")