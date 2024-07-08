/*
 * thermal_closed_loop_model_data.cpp
 *
 * Code generation for model "thermal_closed_loop_model".
 *
 * Model version              : 2.76
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Fri Jun 28 15:46:30 2024
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "thermal_closed_loop_model.h"

/* Block parameters (default storage) */
P_thermal_closed_loop_model_T thermal_closed_loop_model_P = {
  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S181>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S181>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S181>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S181>/Saturation'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S182>/Saturation'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S35>/Saturation'
   */
  0.0,

  /* Start of '<S3>/controlBontazTCV' */
  {
    /* Expression: antiwindupUpperLimit
     * Referenced by: '<S114>/Integrator'
     */
    0.0,

    /* Expression: antiwindupLowerLimit
     * Referenced by: '<S114>/Integrator'
     */
    0.0,

    /* Expression: windupUpperLimit
     * Referenced by: '<S114>/Saturation'
     */
    0.0,

    /* Expression: windupLowerLimit
     * Referenced by: '<S114>/Saturation'
     */
    0.0
  }
  /* End of '<S3>/controlBontazTCV' */
};
