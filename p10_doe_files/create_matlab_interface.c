#include "mex.h"
/*
Parameter	Description
nlhs	Number of output (left-side) arguments, or the size of the plhs array.
plhs	Array of output arguments.
nrhs	Number of input (right-side) arguments, or the size of the prhs array.
prhs	Array of input arguments.
*/

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
#include "vendor_provision\temp_coolant_in_out_diff.c"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    //double *inMatrix;  /* 1xN input matrix */
    size_t ncols;      /* size of matrix */
    double *outMatrix; /* output matrix */
    double factors[12]; 
    //int return_value;

    if(nrhs == 0) 
    {
        mexPrintf("\n\tInput parameters are the following: \n");
        mexPrintf("\tcurrent, \n");
        mexPrintf("\th2_concentration, \n");
        mexPrintf("\tanode_stoich, \n");
        mexPrintf("\ttemp_anode_dewpoint, \n");    
        mexPrintf("\ttemp_anode_inlet, \n");       
        mexPrintf("\tpressure_anode_inlet, \n");   
        mexPrintf("\tcathode_stoich, \n");         
        mexPrintf("\ttemp_cathode_dewpoint, \n");  
        mexPrintf("\ttemp_cathode_inlet, \n");     
        mexPrintf("\tpressure_cathode_inlet, \n"); 
        mexPrintf("\tflow_coolant, \n");      
        mexPrintf("\ttemp_coolant_inlet\n\n");
    }
    else 
    {
        if (nrhs == 12)
        {
            factors[0] = mxGetScalar(prhs[0]);
            factors[1] = mxGetScalar(prhs[1]);
            factors[2] = mxGetScalar(prhs[2]);
            factors[3] = mxGetScalar(prhs[3]);
            factors[4] = mxGetScalar(prhs[4]);
            factors[5] = mxGetScalar(prhs[5]);
            factors[6] = mxGetScalar(prhs[6]);
            factors[7] = mxGetScalar(prhs[7]);
            factors[8] = mxGetScalar(prhs[8]);
            factors[9] = mxGetScalar(prhs[9]);
            factors[10] = mxGetScalar(prhs[10]);
            factors[11] = mxGetScalar(prhs[11]);
        }


        /* create output variable */
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);

        outMatrix = mxGetPr(plhs[0]);

        get_response(factors, outMatrix);
    }
}