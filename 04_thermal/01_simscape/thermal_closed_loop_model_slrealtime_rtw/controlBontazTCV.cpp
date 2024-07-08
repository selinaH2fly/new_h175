/*
 * Code generation for system system '<S3>/controlBontazTCV'
 *
 * Model                      : thermal_closed_loop_model
 * Model version              : 2.76
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Fri Jun 28 15:46:30 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "controlBontazTCV.h"
#include "controlBontazTCV_cal.h"
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "thermal_closed_loop_model_private.h"

/* System initialize for atomic system: '<S3>/controlBontazTCV' */
void therm_controlBontazTCV_Init(B_controlBontazTCV_thermal_cl_T *localB,
  DW_controlBontazTCV_thermal_c_T *localDW, therm_controlBontazTCV_cal_type
  *thermal_close_PageSwitching_arg)
{
  /* Start for Probe: '<S108>/Probe' */
  localB->Probe[0] = 0.05;
  localB->Probe[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  localDW->Integrator_PrevResetState = 0;
  localDW->Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
  localDW->Integrator_DSTATE_j =
    thermal_close_PageSwitching_arg->DiscretePIDController_InitialCo;

  /* InitializeConditions for Delay: '<S84>/UD' */
  localDW->UD_DSTATE =
    thermal_close_PageSwitching_arg->DiscretePIDController_Different;
}

/* Output and update for atomic system: '<S3>/controlBontazTCV' */
void thermal_cl_controlBontazTCV(real_T rtu_log_STCL_T_SP_degC, real_T
  rtu_s_T_decC_CLSti_Get, B_controlBontazTCV_thermal_cl_T *localB,
  DW_controlBontazTCV_thermal_c_T *localDW, P_controlBontazTCV_thermal_cl_T
  *localP, therm_controlBontazTCV_cal_type *thermal_close_PageSwitching_arg)
{
  real_T u0;
  real_T u1;
  real_T u2;

  /* Sum: '<S108>/Sum1' incorporates:
   *  Constant: '<S108>/Time constant'
   */
  localB->Sum1 =
    thermal_close_PageSwitching_arg->LowPassFilterDiscreteorContin_a -
    localB->Probe[0];

  /* RelationalOperator: '<S112>/Compare' incorporates:
   *  Constant: '<S112>/Constant'
   */
  localB->Compare = (localB->Sum1 <=
                     thermal_close_PageSwitching_arg->Constant_Value);

  /* RelationalOperator: '<S111>/Compare' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S111>/Constant'
   */
  localB->Compare_i =
    (thermal_close_PageSwitching_arg->LowPassFilterDiscreteorContin_k <
     thermal_close_PageSwitching_arg->CompareToConstant_const);

  /* Logic: '<S108>/Logical Operator' */
  localB->LogicalOperator = (localB->Compare && localB->Compare_i);

  /* Sum: '<S49>/Sum' */
  localB->e_STCL_T_degC = rtu_s_T_decC_CLSti_Get - rtu_log_STCL_T_SP_degC;

  /* Gain: '<S54>/K' */
  localB->K = thermal_close_PageSwitching_arg->LowPassFilterDiscreteorContinuo *
    localB->e_STCL_T_degC;

  /* DiscreteIntegrator: '<S114>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = localB->K;
    if (localDW->Integrator_DSTATE >= localP->Integrator_UpperSat) {
      localDW->Integrator_DSTATE = localP->Integrator_UpperSat;
    } else if (localDW->Integrator_DSTATE <= localP->Integrator_LowerSat) {
      localDW->Integrator_DSTATE = localP->Integrator_LowerSat;
    }
  }

  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = localB->K;
    if (localDW->Integrator_DSTATE >= localP->Integrator_UpperSat) {
      localDW->Integrator_DSTATE = localP->Integrator_UpperSat;
    } else if (localDW->Integrator_DSTATE <= localP->Integrator_LowerSat) {
      localDW->Integrator_DSTATE = localP->Integrator_LowerSat;
    }
  }

  if (localDW->Integrator_DSTATE >= localP->Integrator_UpperSat) {
    localDW->Integrator_DSTATE = localP->Integrator_UpperSat;
  } else if (localDW->Integrator_DSTATE <= localP->Integrator_LowerSat) {
    localDW->Integrator_DSTATE = localP->Integrator_LowerSat;
  }

  /* DiscreteIntegrator: '<S114>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Saturate: '<S114>/Saturation' */
  u0 = localB->Integrator;
  u1 = localP->Saturation_LowerSat;
  u2 = localP->Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S114>/Saturation' */
    localB->Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S114>/Saturation' */
    localB->Saturation = u1;
  } else {
    /* Saturate: '<S114>/Saturation' */
    localB->Saturation = u0;
  }

  /* End of Saturate: '<S114>/Saturation' */

  /* Gain: '<S96>/Proportional Gain' */
  localB->ProportionalGain =
    thermal_close_PageSwitching_arg->DiscretePIDController_P *
    localB->Saturation;

  /* DiscreteIntegrator: '<S91>/Integrator' */
  localB->Integrator_f = localDW->Integrator_DSTATE_j;

  /* Gain: '<S83>/Derivative Gain' */
  localB->DerivativeGain =
    thermal_close_PageSwitching_arg->DiscretePIDController_D *
    localB->Saturation;

  /* SampleTimeMath: '<S86>/Tsamp'
   *
   * About '<S86>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  localB->Tsamp = localB->DerivativeGain *
    thermal_close_PageSwitching_arg->Tsamp_WtEt;

  /* Delay: '<S84>/UD' */
  localB->UD = localDW->UD_DSTATE;

  /* Sum: '<S84>/Diff' */
  localB->Diff = localB->Tsamp - localB->UD;

  /* Sum: '<S100>/Sum' */
  localB->Sum = (localB->ProportionalGain + localB->Integrator_f) + localB->Diff;

  /* DeadZone: '<S82>/DeadZone' */
  if (localB->Sum >
      thermal_close_PageSwitching_arg->DiscretePIDController_UpperSatu) {
    /* DeadZone: '<S82>/DeadZone' */
    localB->DeadZone = localB->Sum -
      thermal_close_PageSwitching_arg->DiscretePIDController_UpperSatu;
  } else if (localB->Sum >=
             thermal_close_PageSwitching_arg->DiscretePIDController_LowerSatu) {
    /* DeadZone: '<S82>/DeadZone' */
    localB->DeadZone = 0.0;
  } else {
    /* DeadZone: '<S82>/DeadZone' */
    localB->DeadZone = localB->Sum -
      thermal_close_PageSwitching_arg->DiscretePIDController_LowerSatu;
  }

  /* End of DeadZone: '<S82>/DeadZone' */

  /* RelationalOperator: '<S80>/Relational Operator' incorporates:
   *  Constant: '<S80>/Clamping_zero'
   */
  localB->RelationalOperator =
    (thermal_close_PageSwitching_arg->Clamping_zero_Value != localB->DeadZone);

  /* RelationalOperator: '<S80>/fix for DT propagation issue' incorporates:
   *  Constant: '<S80>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone >
    thermal_close_PageSwitching_arg->Clamping_zero_Value);

  /* Switch: '<S80>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S80>/Switch1' incorporates:
     *  Constant: '<S80>/Constant'
     */
    localB->Switch1 = thermal_close_PageSwitching_arg->Constant_Value_i;
  } else {
    /* Switch: '<S80>/Switch1' incorporates:
     *  Constant: '<S80>/Constant2'
     */
    localB->Switch1 = thermal_close_PageSwitching_arg->Constant2_Value;
  }

  /* End of Switch: '<S80>/Switch1' */

  /* Gain: '<S88>/Integral Gain' */
  localB->IntegralGain =
    thermal_close_PageSwitching_arg->DiscretePIDController_I *
    localB->Saturation;

  /* RelationalOperator: '<S80>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S80>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IntegralGain >
    thermal_close_PageSwitching_arg->Clamping_zero_Value);

  /* Switch: '<S80>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S80>/Switch2' incorporates:
     *  Constant: '<S80>/Constant3'
     */
    localB->Switch2 = thermal_close_PageSwitching_arg->Constant3_Value;
  } else {
    /* Switch: '<S80>/Switch2' incorporates:
     *  Constant: '<S80>/Constant4'
     */
    localB->Switch2 = thermal_close_PageSwitching_arg->Constant4_Value;
  }

  /* End of Switch: '<S80>/Switch2' */

  /* RelationalOperator: '<S80>/Equal1' */
  localB->Equal1 = (localB->Switch1 == localB->Switch2);

  /* Logic: '<S80>/AND3' */
  localB->AND3 = (localB->RelationalOperator && localB->Equal1);

  /* Switch: '<S80>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S80>/Constant1'
     */
    localB->Switch = thermal_close_PageSwitching_arg->Constant1_Value;
  } else {
    /* Switch: '<S80>/Switch' */
    localB->Switch = localB->IntegralGain;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Saturate: '<S98>/Saturation' */
  u0 = localB->Sum;
  u1 = thermal_close_PageSwitching_arg->DiscretePIDController_LowerSatu;
  u2 = thermal_close_PageSwitching_arg->DiscretePIDController_UpperSatu;
  if (u0 > u2) {
    /* Saturate: '<S98>/Saturation' */
    localB->Saturation_g = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S98>/Saturation' */
    localB->Saturation_g = u1;
  } else {
    /* Saturate: '<S98>/Saturation' */
    localB->Saturation_g = u0;
  }

  /* End of Saturate: '<S98>/Saturation' */

  /* MinMax: '<S108>/Max' incorporates:
   *  Constant: '<S108>/Time constant'
   */
  u0 = localB->Probe[0];
  u1 = thermal_close_PageSwitching_arg->LowPassFilterDiscreteorContin_a;
  if ((u0 >= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  /* MinMax: '<S108>/Max' */
  localB->Max = u1;

  /* Fcn: '<S108>/Avoid Divide by Zero' */
  localB->AvoidDividebyZero = static_cast<real_T>(localB->Max == 0.0) *
    2.2204460492503131e-16 + localB->Max;

  /* Sum: '<S54>/Sum1' */
  localB->Sum1_n = localB->K - localB->Saturation;

  /* Product: '<S54>/1//T' */
  localB->uT = 1.0 / localB->AvoidDividebyZero * localB->Sum1_n;

  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Constant: '<S115>/Constant'
   */
  localB->Compare_p = (localB->Saturation_g ==
                       thermal_close_PageSwitching_arg->CompareToConstant_const_c);

  /* Switch: '<S55>/Switch' */
  if (localB->Compare_p) {
    /* Switch: '<S55>/Switch' */
    localB->Switch_e = localB->Saturation_g;
  } else {
    /* Lookup_n-D: '<S55>/1-D Lookup Table' incorporates:
     *  Saturate: '<S98>/Saturation'
     */
    localB->uDLookupTable = look1_binlxpw(localB->Saturation_g,
      thermal_close_PageSwitching_arg->uDLookupTable_bp01Data,
      thermal_close_PageSwitching_arg->uDLookupTable_tableData, 5U);

    /* Switch: '<S55>/Switch' */
    localB->Switch_e = localB->uDLookupTable;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Update for DiscreteIntegrator: '<S114>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;
  localDW->Integrator_DSTATE +=
    thermal_close_PageSwitching_arg->Integrator_gainval * localB->uT;
  if (localDW->Integrator_DSTATE >= localP->Integrator_UpperSat) {
    localDW->Integrator_DSTATE = localP->Integrator_UpperSat;
  } else if (localDW->Integrator_DSTATE <= localP->Integrator_LowerSat) {
    localDW->Integrator_DSTATE = localP->Integrator_LowerSat;
  }

  localDW->Integrator_PrevResetState = static_cast<int8_T>
    (localB->LogicalOperator);

  /* End of Update for DiscreteIntegrator: '<S114>/Integrator' */

  /* Update for DiscreteIntegrator: '<S91>/Integrator' */
  localDW->Integrator_DSTATE_j +=
    thermal_close_PageSwitching_arg->Integrator_gainval_a * localB->Switch;

  /* Update for Delay: '<S84>/UD' */
  localDW->UD_DSTATE = localB->Tsamp;
}
