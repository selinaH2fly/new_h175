/*
 *  rtmodel.cpp:
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

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void thermal_closed_loop_model_step(int_T tid)
{
  switch (tid) {
   case 0 :
    thermal_closed_loop_model_step0();
    break;

   case 1 :
    thermal_closed_loop_model_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}
