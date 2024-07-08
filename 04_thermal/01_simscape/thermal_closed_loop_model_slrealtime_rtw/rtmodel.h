/*
 *  rtmodel.h:
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

#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_
#include "thermal_closed_loop_model.h"
#define GRTINTERFACE                   0

/* Model wrapper function */
/* Use this function only if you need to maintain compatibility with an existing static main program. */
extern void thermal_closed_loop_model_step(int_T tid);

#endif                                 /* RTW_HEADER_rtmodel_h_ */
