/*
 * Code generation for system system '<S48>/calculateDeltaTemperatureSetpoint'
 *
 * Model                      : thermal_closed_loop_model
 * Model version              : 2.76
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Fri Jun 28 15:46:30 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "calculateDeltaTemperatureSetpoint.h"
#include "thermal_closed_loop_model.h"
#include "thermal_closed_loop_model_cal.h"
#include "thermal_closed_loop_model_private.h"

/* Output and update for atomic system: '<S48>/calculateDeltaTemperatureSetpoint' */
void calculateDeltaTemperatureSe(void)
{
  /* Lookup_n-D: '<S51>/1-D Lookup Table1' */
  thermal_closed_loop_model_B.uDLookupTable1_p = look1_binlcpw
    (thermal_closed_loop_model_B.Sum_p[0],
     thermal_closed_loop_model_cal->uDLookupTable1_bp01Data,
     thermal_closed_loop_model_cal->uDLookupTable1_tableData, 12U);
}
