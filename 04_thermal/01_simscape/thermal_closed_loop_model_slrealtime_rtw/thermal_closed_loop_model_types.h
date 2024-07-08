/*
 * thermal_closed_loop_model_types.h
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

#ifndef RTW_HEADER_thermal_closed_loop_model_types_h_
#define RTW_HEADER_thermal_closed_loop_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_DHR5maIhZ9MJSHfGp1zUNC_
#define DEFINED_TYPEDEF_FOR_struct_DHR5maIhZ9MJSHfGp1zUNC_

struct struct_DHR5maIhZ9MJSHfGp1zUNC
{
  real_T area;
  real_T thermal_mass;
  real_T specific_heat;
  real_T coolant_w_channels;
  real_T coolant_num_passes;
  real_T coolant_num_layers;
};

#endif

/* Parameters for system: '<S3>/controlBontazTCV' */
typedef struct P_controlBontazTCV_thermal_cl_T_ P_controlBontazTCV_thermal_cl_T;

/* Parameters (default storage) */
typedef struct P_thermal_closed_loop_model_T_ P_thermal_closed_loop_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_thermal_closed_loop_m_T RT_MODEL_thermal_closed_loop__T;

#endif                       /* RTW_HEADER_thermal_closed_loop_model_types_h_ */
