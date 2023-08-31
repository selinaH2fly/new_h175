#include "DOE-data_TV500873_ModelInput_Default_Voltage_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_temp_coolant_in_out_diff_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_temp_cathode_in_out_diff_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_temp_anode_in_out_diff_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_Stack_Voltage_Loss_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_dp_Coolant_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_dp_Cathode_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_dp_Anode_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_CellSense_std_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_CellSense_Min_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_CellSense_Max_Kriging_Case1_standalone.c"
//#include "DOE-data_TV500873_ModelInput_Default_CellSense_Avg_Kriging_Case1_standalone.c"


#include <stdio.h>
#include <stdlib.h>

double response;

/* Input order in factors vector 
{"current", "H2-concentration", "anode_stoich", "temp_anode_dewpoint", "temp_anode_inlet", 
"pressure_anode_inlet", "cathode_stoich", "temp_cathode_dewpoint", "temp_cathode_inlet", "pressure_cathode_inlet", 
"flow_coolant", "temp_coolant_inlet"}
*/
double factors[12] = {450, 0.7, 1.5, 50, 61, 1, 2, 50, 70, 1.4, 250, 70};

int main()
{
   FILE *fptr;
   fptr = fopen("response","w");
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

	get_response(factors, &response);
	fprintf(fptr,"%f\n",response);	
		
	fclose(fptr); 
}
