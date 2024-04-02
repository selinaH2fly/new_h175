# h175_model_stack
Model of the stack subsystem of H175

Creators: Waldimir Gerber, Stefan Notter
Date of Creation: 2023-01-26
Last Modification: 2023-08-31

## Description
The model has been provided by PowerCell.
Internal Link [Link](https://h2flygmbh.sharepoint.com/:f:/s/FuelCellGroup-PowercellKooperation-daily/EkKw2y5STbpEhbHtO1VY2GgBcUTxINZg_60opt7XYaZxig?e=V8hbui).

In vendor_provision all files are stored as provided by FC vendor.

Powercell has divided each algorithm into one single file, whereas all files use the same function interfaces. 
For the first shot, 12 binaries have been created. This could be optimizied in the future and merged to one file.

## Test Environment
As the code is not written by H2Fly. Therefore, no dedicated test cases have been implemented. Basically, we have to trust the export of PowerCell.

## Used test vector
(450, 0.7, 1.5, 50, 61, 1, 2, 50, 70, 1.4, 250, 70)

Input parameters:
	current, 
	h2_concentration, 
	anode_stoich, 
	temp_anode_dewpoint, 
	temp_anode_inlet, 
	pressure_anode_inlet, 
	cathode_stoich, 
	temp_cathode_dewpoint, 
	temp_cathode_inlet, 
	pressure_cathode_inlet, 
	flow_coolant, 
	temp_coolant_inlet

## How to create a Matlab Library out of C Code
A good description of how to create an interface between C code and a Matlab, is given [here](https://de.mathworks.com/help/matlab/matlab_external/standalone-example.html).
An interface between C functions and MATLAB is created in ```interface.c```.
In order to compile it, the respective algorithm has to be commented in:
```
    // #include "vendor_provision\Voltage.C"
    // #include "vendor_provision\CellSense_Avg.c"
    // #include "vendor_provision\CellSense_Max.c"
	// #include "vendor_provision\CellSense_Min.c"
	// #include "vendor_provision\CellSense_std.c"
	// #include "vendor_provision\dp_Anode.c"
	// #include "vendor_provision\dp_Cathode.c"
	// #include "vendor_provision\dp_Coolant.c"
	// #include "vendor_provision\Stack_Voltage_Loss.c"
	// #include "vendor_provision\temp_anode_in_out_diff.c"
	// #include "vendor_provision\temp_cathode_in_out_diff.c"
	// #include "vendor_provision\temp_coolant_in_out_diff.c"
```
Matlab provides a compiler, further information provided on Matlab website:

    mex interface.c

In case of a successful compliation, you will find a file called ```interface.mexw64```. 

Rename to the respective algorithm and it can be used, e.g.:

    Voltage(450, 0.7, 1.5, 50, 61, 1, 2, 50, 70, 1.4, 250, 70)