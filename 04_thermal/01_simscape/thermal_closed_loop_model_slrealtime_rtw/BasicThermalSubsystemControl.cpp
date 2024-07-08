/*
 * Code generation for system system '<Root>/BasicThermalSubsystemControl'
 *
 * Model                      : thermal_closed_loop_model
 * Model version              : 2.76
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C++ source code generated on : Fri Jun 28 15:46:30 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "rtwtypes.h"
#include "BasicThermalSubsystemControl.h"
#include "controlBontazTCV.h"
#include "thermal_closed_loop_model.h"
#include "thermal_closed_loop_model_cal.h"
#include "calculateDeltaTemperatureSetpoint.h"
#include "calculateTemperatureSetpoint.h"
#include "thermal_closed_loop_model_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <cmath>
#include "zero_crossing_types.h"

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* System initialize for atomic system: '<Root>/BasicThermalSubsystemControl' */
void BasicThermalSubsystemC_Init(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;

  /* SystemInitialize for Atomic SubSystem: '<S3>/controlBontazTCV' */
  therm_controlBontazTCV_Init(&thermal_closed_loop_model_B.controlBontazTCV,
    &thermal_closed_loop_model_DW.controlBontazTCV,
    &thermal_closed_loop_model_cal->thermal_cl_controlBontazTCV_cal);

  /* End of SystemInitialize for SubSystem: '<S3>/controlBontazTCV' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/controlEMPHVTCP' */
  /* Start for Probe: '<S175>/Probe' */
  thermal_closed_loop_model_B.Probe[0] = 0.05;
  thermal_closed_loop_model_B.Probe[1] = 0.0;

  /* Start for Probe: '<S182>/Probe' */
  thermal_closed_loop_model_B.Probe_f[0] = 0.05;
  thermal_closed_loop_model_B.Probe_f[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Integrator' */
  thermal_closed_loop_model_DW.Integrator_PrevResetState = 0;
  thermal_closed_loop_model_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for UnitDelay: '<S120>/Unit Delay' */
  thermal_closed_loop_model_DW.UnitDelay_DSTATE_h =
    thermal_closed_loop_model_cal->UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
  thermal_closed_loop_model_DW.DiscreteTimeIntegrator_DSTATE =
    thermal_closed_loop_model_cal->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S182>/Unit Delay' */
  thermal_closed_loop_model_DW.UnitDelay_DSTATE_b =
    thermal_closed_loop_model_cal->UnitDelay_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S182>/Unit Delay1' */
  thermal_closed_loop_model_DW.UnitDelay1_DSTATE_b =
    thermal_closed_loop_model_cal->MovingAverageVariableFrequenc_d;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Integrator' */
  thermal_closed_loop_model_DW.Integrator_PrevResetState_o = 2;
  thermal_closed_loop_model_DW.Integrator_IC_LOADING_m = 1U;

  /* InitializeConditions for Delay: '<S150>/UD' */
  thermal_closed_loop_model_DW.icLoad = true;

  /* SystemInitialize for Iterator SubSystem: '<S182>/For Each Subsystem' */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* SystemInitialize for Delay: '<S183>/Variable Integer Delay' */
    thermal_closed_loop_model_B.CoreSubsys[ForEach_itr].VariableIntegerDelay =
      0.0;

    /* InitializeConditions for Delay: '<S183>/Variable Integer Delay' */
    for (i = 0; i < 4096; i++) {
      thermal_closed_loop_model_DW.CoreSubsys[ForEach_itr].
        VariableIntegerDelay_DSTATE[i] =
        thermal_closed_loop_model_cal->thermal_closed_l_CoreSubsys_cal.VariableIntegerDelay_InitialCon;
    }

    /* End of InitializeConditions for Delay: '<S183>/Variable Integer Delay' */
  }

  /* End of SystemInitialize for SubSystem: '<S182>/For Each Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S120>/Triggered Subsystem' */
  /* SystemInitialize for Switch: '<S185>/Switch' incorporates:
   *  Outport: '<S185>/Out1'
   */
  thermal_closed_loop_model_B.Switch_d = thermal_closed_loop_model_cal->Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S120>/Triggered Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S3>/controlEMPHVTCP' */
}

/* Enable for atomic system: '<Root>/BasicThermalSubsystemControl' */
void BasicThermalSubsyste_Enable(void)
{
  /* Enable for Atomic SubSystem: '<S3>/controlEMPHVTCP' */
  /* Enable for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
  thermal_closed_loop_model_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for SubSystem: '<S3>/controlEMPHVTCP' */
}

/* Output and update for atomic system: '<Root>/BasicThermalSubsystemControl' */
void BasicThermalSubsystemContro(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_In1_at_o;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_ImpSel_InsertedFor_In2_at_o;
  real_T u0;
  real_T u1;
  real_T u2;
  int32_T delayLen;
  boolean_T zcEvent;

  /* Outputs for Atomic SubSystem: '<S48>/calculateDeltaTemperatureSetpoint' */
  calculateDeltaTemperatureSe();

  /* End of Outputs for SubSystem: '<S48>/calculateDeltaTemperatureSetpoint' */

  /* Outputs for Atomic SubSystem: '<S48>/calculateTemperatureSetpoint' */
  calculateTemperatureSetpoin();

  /* End of Outputs for SubSystem: '<S48>/calculateTemperatureSetpoint' */

  /* Outputs for Atomic SubSystem: '<S3>/controlBontazTCV' */
  thermal_cl_controlBontazTCV(thermal_closed_loop_model_B.uDLookupTable1,
    thermal_closed_loop_model_B.Sum_p[1],
    &thermal_closed_loop_model_B.controlBontazTCV,
    &thermal_closed_loop_model_DW.controlBontazTCV,
    &thermal_closed_loop_model_P.controlBontazTCV,
    &thermal_closed_loop_model_cal->thermal_cl_controlBontazTCV_cal);

  /* End of Outputs for SubSystem: '<S3>/controlBontazTCV' */

  /* Outputs for Atomic SubSystem: '<S3>/controlEMPHVTCP' */
  /* Sum: '<S175>/Sum1' incorporates:
   *  Constant: '<S175>/Time constant'
   */
  thermal_closed_loop_model_B.Sum1 =
    thermal_closed_loop_model_cal->LowPassFilterDiscreteorContin_b -
    thermal_closed_loop_model_B.Probe[0];

  /* RelationalOperator: '<S179>/Compare' incorporates:
   *  Constant: '<S179>/Constant'
   */
  thermal_closed_loop_model_B.Compare = (thermal_closed_loop_model_B.Sum1 <=
    thermal_closed_loop_model_cal->Constant_Value);

  /* RelationalOperator: '<S178>/Compare' incorporates:
   *  Constant: '<S175>/Constant'
   *  Constant: '<S178>/Constant'
   */
  thermal_closed_loop_model_B.Compare_p =
    (thermal_closed_loop_model_cal->LowPassFilterDiscreteorContin_f <
     thermal_closed_loop_model_cal->CompareToConstant_const);

  /* Logic: '<S175>/Logical Operator' */
  thermal_closed_loop_model_B.LogicalOperator =
    (thermal_closed_loop_model_B.Compare &&
     thermal_closed_loop_model_B.Compare_p);

  /* Sum: '<S50>/Sum' */
  thermal_closed_loop_model_B.delta_T_degC = thermal_closed_loop_model_B.Sum_p[2]
    - thermal_closed_loop_model_B.Sum_p[1];

  /* Gain: '<S117>/K' */
  thermal_closed_loop_model_B.K =
    thermal_closed_loop_model_cal->LowPassFilterDiscreteorContinuo *
    thermal_closed_loop_model_B.delta_T_degC;

  /* DiscreteIntegrator: '<S181>/Integrator' */
  if (thermal_closed_loop_model_DW.Integrator_IC_LOADING != 0) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_B.K;
    if (thermal_closed_loop_model_DW.Integrator_DSTATE >=
        thermal_closed_loop_model_P.Integrator_UpperSat) {
      thermal_closed_loop_model_DW.Integrator_DSTATE =
        thermal_closed_loop_model_P.Integrator_UpperSat;
    } else if (thermal_closed_loop_model_DW.Integrator_DSTATE <=
               thermal_closed_loop_model_P.Integrator_LowerSat) {
      thermal_closed_loop_model_DW.Integrator_DSTATE =
        thermal_closed_loop_model_P.Integrator_LowerSat;
    }
  }

  if (thermal_closed_loop_model_B.LogicalOperator ||
      (thermal_closed_loop_model_DW.Integrator_PrevResetState != 0)) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_B.K;
    if (thermal_closed_loop_model_DW.Integrator_DSTATE >=
        thermal_closed_loop_model_P.Integrator_UpperSat) {
      thermal_closed_loop_model_DW.Integrator_DSTATE =
        thermal_closed_loop_model_P.Integrator_UpperSat;
    } else if (thermal_closed_loop_model_DW.Integrator_DSTATE <=
               thermal_closed_loop_model_P.Integrator_LowerSat) {
      thermal_closed_loop_model_DW.Integrator_DSTATE =
        thermal_closed_loop_model_P.Integrator_LowerSat;
    }
  }

  if (thermal_closed_loop_model_DW.Integrator_DSTATE >=
      thermal_closed_loop_model_P.Integrator_UpperSat) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_P.Integrator_UpperSat;
  } else if (thermal_closed_loop_model_DW.Integrator_DSTATE <=
             thermal_closed_loop_model_P.Integrator_LowerSat) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_P.Integrator_LowerSat;
  }

  /* DiscreteIntegrator: '<S181>/Integrator' */
  thermal_closed_loop_model_B.Integrator =
    thermal_closed_loop_model_DW.Integrator_DSTATE;

  /* Saturate: '<S181>/Saturation' */
  u0 = thermal_closed_loop_model_B.Integrator;
  u1 = thermal_closed_loop_model_P.Saturation_LowerSat;
  u2 = thermal_closed_loop_model_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S181>/Saturation' */
    thermal_closed_loop_model_B.Saturation_g = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S181>/Saturation' */
    thermal_closed_loop_model_B.Saturation_g = u1;
  } else {
    /* Saturate: '<S181>/Saturation' */
    thermal_closed_loop_model_B.Saturation_g = u0;
  }

  /* End of Saturate: '<S181>/Saturation' */

  /* Sum: '<S50>/Sum1' */
  thermal_closed_loop_model_B.Sum1_l = thermal_closed_loop_model_B.Saturation_g
    - thermal_closed_loop_model_B.uDLookupTable1_p;

  /* Gain: '<S162>/Proportional Gain' */
  thermal_closed_loop_model_B.ProportionalGain =
    thermal_closed_loop_model_cal->DiscretePIDController_P *
    thermal_closed_loop_model_B.Sum1_l;

  /* UnitDelay: '<S120>/Unit Delay' */
  thermal_closed_loop_model_B.UnitDelay =
    thermal_closed_loop_model_DW.UnitDelay_DSTATE_h;

  /* Product: '<S50>/Reciprocal' incorporates:
   *  Constant: '<S50>/p_Emp_STCL_FFWD_Filter_PER_s'
   */
  thermal_closed_loop_model_B.Reciprocal = 1.0 /
    thermal_closed_loop_model_cal->p_Emp_STCL_FFWD_Filter_PER_s_Va;

  /* Saturate: '<S182>/Saturation' */
  u0 = thermal_closed_loop_model_B.Reciprocal;
  u1 = thermal_closed_loop_model_cal->Saturation_LowerSat_j;
  u2 = thermal_closed_loop_model_P.Saturation_UpperSat_g;
  if (u0 > u2) {
    /* Saturate: '<S182>/Saturation' */
    thermal_closed_loop_model_B.Saturation_b = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S182>/Saturation' */
    thermal_closed_loop_model_B.Saturation_b = u1;
  } else {
    /* Saturate: '<S182>/Saturation' */
    thermal_closed_loop_model_B.Saturation_b = u0;
  }

  /* End of Saturate: '<S182>/Saturation' */

  /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
  if (thermal_closed_loop_model_DW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
    /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
    thermal_closed_loop_model_B.DiscreteTimeIntegrator =
      thermal_closed_loop_model_DW.DiscreteTimeIntegrator_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
    thermal_closed_loop_model_B.DiscreteTimeIntegrator =
      thermal_closed_loop_model_cal->DiscreteTimeIntegrator_gainval *
      thermal_closed_loop_model_B.Sum_p[0] +
      thermal_closed_loop_model_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */

  /* Gain: '<S182>/Gain' */
  thermal_closed_loop_model_B.Gain_b = thermal_closed_loop_model_cal->Gain_Gain *
    thermal_closed_loop_model_B.Sum_p[0];

  /* Product: '<S182>/Product2' */
  thermal_closed_loop_model_B.Product2_c = thermal_closed_loop_model_B.Probe_f[0]
    * thermal_closed_loop_model_B.Saturation_b;

  /* Math: '<S182>/Math Function1'
   *
   * About '<S182>/Math Function1':
   *  Operator: reciprocal
   */
  u1 = thermal_closed_loop_model_B.Product2_c;

  /* Math: '<S182>/Math Function1'
   *
   * About '<S182>/Math Function1':
   *  Operator: reciprocal
   */
  thermal_closed_loop_model_B.MathFunction1 = 1.0 / u1;

  /* Rounding: '<S182>/Rounding Function1' */
  thermal_closed_loop_model_B.RoundingFunction1 = rt_roundd_snf
    (thermal_closed_loop_model_B.MathFunction1);

  /* Sum: '<S182>/Sum4' */
  thermal_closed_loop_model_B.Sum4 = thermal_closed_loop_model_B.Gain_b +
    thermal_closed_loop_model_B.RoundingFunction1;

  /* Outputs for Iterator SubSystem: '<S182>/For Each Subsystem' incorporates:
   *  ForEach: '<S183>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S183>/In1' */
    rtb_ImpSel_InsertedFor_In1_at_o =
      thermal_closed_loop_model_B.DiscreteTimeIntegrator;

    /* ForEachSliceSelector generated from: '<S183>/In2' */
    rtb_ImpSel_InsertedFor_In2_at_o = thermal_closed_loop_model_B.Sum4;

    /* Delay: '<S183>/Variable Integer Delay' */
    if ((rtb_ImpSel_InsertedFor_In2_at_o < 1.0) || rtIsNaN
        (rtb_ImpSel_InsertedFor_In2_at_o)) {
      /* Delay: '<S183>/Variable Integer Delay' */
      thermal_closed_loop_model_B.CoreSubsys[ForEach_itr].VariableIntegerDelay =
        rtb_ImpSel_InsertedFor_In1_at_o;
    } else {
      if (rtb_ImpSel_InsertedFor_In2_at_o > 4096.0) {
        delayLen = 4096;
      } else {
        u0 = rtb_ImpSel_InsertedFor_In2_at_o;
        u0 = std::floor(u0);
        delayLen = static_cast<int32_T>(u0);
      }

      delayLen = static_cast<int32_T>(4096U - static_cast<uint32_T>(delayLen));

      /* Delay: '<S183>/Variable Integer Delay' */
      thermal_closed_loop_model_B.CoreSubsys[ForEach_itr].VariableIntegerDelay =
        thermal_closed_loop_model_DW.CoreSubsys[ForEach_itr].
        VariableIntegerDelay_DSTATE[static_cast<uint32_T>(delayLen)];
    }

    /* End of Delay: '<S183>/Variable Integer Delay' */

    /* Update for Delay: '<S183>/Variable Integer Delay' */
    for (delayLen = 0; delayLen < 4095; delayLen++) {
      thermal_closed_loop_model_DW.CoreSubsys[ForEach_itr].
        VariableIntegerDelay_DSTATE[delayLen] =
        thermal_closed_loop_model_DW.CoreSubsys[ForEach_itr].
        VariableIntegerDelay_DSTATE[delayLen + 1];
    }

    thermal_closed_loop_model_DW.CoreSubsys[ForEach_itr].
      VariableIntegerDelay_DSTATE[4095] = rtb_ImpSel_InsertedFor_In1_at_o;

    /* End of Update for Delay: '<S183>/Variable Integer Delay' */

    /* ForEachSliceAssignment generated from: '<S183>/Out1' */
    thermal_closed_loop_model_B.ImpAsg_InsertedFor_Out1_at_inpo =
      thermal_closed_loop_model_B.CoreSubsys[ForEach_itr].VariableIntegerDelay;
  }

  /* End of Outputs for SubSystem: '<S182>/For Each Subsystem' */

  /* UnitDelay: '<S182>/Unit Delay' */
  thermal_closed_loop_model_B.UnitDelay_b =
    thermal_closed_loop_model_DW.UnitDelay_DSTATE_b;

  /* Sum: '<S182>/Sum3' incorporates:
   *  Constant: '<S182>/Constant2'
   */
  thermal_closed_loop_model_B.Sum3 = thermal_closed_loop_model_B.UnitDelay_b +
    thermal_closed_loop_model_cal->Constant2_Value;

  /* Gain: '<S182>/Gain1' */
  thermal_closed_loop_model_B.Gain1 =
    thermal_closed_loop_model_cal->MovingAverageVariableFrequency_ *
    thermal_closed_loop_model_B.Probe_f[0];

  /* Math: '<S182>/Math Function2'
   *
   * About '<S182>/Math Function2':
   *  Operator: reciprocal
   */
  u1 = thermal_closed_loop_model_B.Gain1;

  /* Math: '<S182>/Math Function2'
   *
   * About '<S182>/Math Function2':
   *  Operator: reciprocal
   */
  thermal_closed_loop_model_B.MathFunction2 = 1.0 / u1;

  /* Rounding: '<S182>/Rounding Function2' */
  thermal_closed_loop_model_B.RoundingFunction2 = rt_roundd_snf
    (thermal_closed_loop_model_B.MathFunction2);

  /* RelationalOperator: '<S182>/Relational Operator' */
  thermal_closed_loop_model_B.RelationalOperator =
    (thermal_closed_loop_model_B.Sum3 >=
     thermal_closed_loop_model_B.RoundingFunction2);

  /* UnitDelay: '<S182>/Unit Delay1' */
  thermal_closed_loop_model_B.UnitDelay1 =
    thermal_closed_loop_model_DW.UnitDelay1_DSTATE_b;

  /* Switch: '<S182>/Switch' */
  if (thermal_closed_loop_model_B.RelationalOperator) {
    /* Sum: '<S182>/Sum2' */
    thermal_closed_loop_model_B.Sum2_p =
      thermal_closed_loop_model_B.MathFunction1 -
      thermal_closed_loop_model_B.RoundingFunction1;

    /* Product: '<S182>/Product1' */
    thermal_closed_loop_model_B.Product1 = thermal_closed_loop_model_B.Sum2_p *
      thermal_closed_loop_model_B.Sum_p[0] /
      thermal_closed_loop_model_B.MathFunction1;

    /* Sum: '<S182>/Sum1' */
    thermal_closed_loop_model_B.Sum1_lt =
      thermal_closed_loop_model_B.DiscreteTimeIntegrator -
      thermal_closed_loop_model_B.ImpAsg_InsertedFor_Out1_at_inpo;

    /* Product: '<S182>/Product' */
    thermal_closed_loop_model_B.Product_a =
      thermal_closed_loop_model_B.Saturation_b *
      thermal_closed_loop_model_B.Sum1_lt;

    /* Sum: '<S182>/Sum' */
    thermal_closed_loop_model_B.Sum_i = thermal_closed_loop_model_B.Product_a +
      thermal_closed_loop_model_B.Product1;

    /* Switch: '<S182>/Switch' */
    thermal_closed_loop_model_B.Switch = thermal_closed_loop_model_B.Sum_i;
  } else {
    /* Switch: '<S182>/Switch' */
    thermal_closed_loop_model_B.Switch = thermal_closed_loop_model_B.UnitDelay1;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Lookup_n-D: '<S50>/LUT_FFWD_TCP' incorporates:
   *  Switch: '<S182>/Switch'
   */
  thermal_closed_loop_model_B.LUT_FFWD_TCP = look1_binlcapw
    (thermal_closed_loop_model_B.Switch,
     thermal_closed_loop_model_cal->LUT_FFWD_TCP_bp01Data,
     thermal_closed_loop_model_cal->LUT_FFWD_TCP_tableData, 13U);

  /* RelationalOperator: '<S119>/LowerRelop1' incorporates:
   *  Constant: '<S50>/p_Emp_TCP_max_rpm'
   */
  thermal_closed_loop_model_B.LowerRelop1 =
    (thermal_closed_loop_model_B.LUT_FFWD_TCP >
     thermal_closed_loop_model_cal->p_Emp_TCP_max_rpm_Value);

  /* RelationalOperator: '<S119>/UpperRelop' incorporates:
   *  Constant: '<S50>/p_Emp_TCP_min_rpm'
   */
  thermal_closed_loop_model_B.UpperRelop =
    (thermal_closed_loop_model_B.LUT_FFWD_TCP <
     thermal_closed_loop_model_cal->p_Emp_TCP_min_rpm_Value);

  /* Switch: '<S119>/Switch' */
  if (thermal_closed_loop_model_B.UpperRelop) {
    /* Switch: '<S119>/Switch' incorporates:
     *  Constant: '<S50>/p_Emp_TCP_min_rpm'
     */
    thermal_closed_loop_model_B.Switch_l =
      thermal_closed_loop_model_cal->p_Emp_TCP_min_rpm_Value;
  } else {
    /* Switch: '<S119>/Switch' */
    thermal_closed_loop_model_B.Switch_l =
      thermal_closed_loop_model_B.LUT_FFWD_TCP;
  }

  /* End of Switch: '<S119>/Switch' */

  /* Switch: '<S119>/Switch2' */
  if (thermal_closed_loop_model_B.LowerRelop1) {
    /* Switch: '<S119>/Switch2' incorporates:
     *  Constant: '<S50>/p_Emp_TCP_max_rpm'
     */
    thermal_closed_loop_model_B.Switch2 =
      thermal_closed_loop_model_cal->p_Emp_TCP_max_rpm_Value;
  } else {
    /* Switch: '<S119>/Switch2' */
    thermal_closed_loop_model_B.Switch2 = thermal_closed_loop_model_B.Switch_l;
  }

  /* End of Switch: '<S119>/Switch2' */

  /* Sum: '<S50>/Sum2' incorporates:
   *  Constant: '<S50>/p_Emp_TCP_min_rpm'
   */
  thermal_closed_loop_model_B.Sum2 =
    thermal_closed_loop_model_cal->p_Emp_TCP_min_rpm_Value -
    thermal_closed_loop_model_B.Switch2;

  /* DiscreteIntegrator: '<S157>/Integrator' */
  if (thermal_closed_loop_model_DW.Integrator_IC_LOADING_m != 0) {
    thermal_closed_loop_model_DW.Integrator_DSTATE_o =
      thermal_closed_loop_model_B.Sum2;
  }

  if ((thermal_closed_loop_model_B.UnitDelay > 0.0) &&
      (thermal_closed_loop_model_DW.Integrator_PrevResetState_o <= 0)) {
    thermal_closed_loop_model_DW.Integrator_DSTATE_o =
      thermal_closed_loop_model_B.Sum2;
  }

  /* DiscreteIntegrator: '<S157>/Integrator' */
  thermal_closed_loop_model_B.Integrator_k =
    thermal_closed_loop_model_DW.Integrator_DSTATE_o;

  /* Gain: '<S149>/Derivative Gain' */
  thermal_closed_loop_model_B.DerivativeGain =
    thermal_closed_loop_model_cal->DiscretePIDController_D *
    thermal_closed_loop_model_B.Sum1_l;

  /* SampleTimeMath: '<S152>/Tsamp'
   *
   * About '<S152>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  thermal_closed_loop_model_B.Tsamp = thermal_closed_loop_model_B.DerivativeGain
    * thermal_closed_loop_model_cal->Tsamp_WtEt;

  /* Delay: '<S150>/UD' incorporates:
   *  Constant: '<S50>/Constant'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &thermal_closed_loop_mod_PrevZCX.UD_Reset_ZCE,
               (thermal_closed_loop_model_B.UnitDelay)) != NO_ZCEVENT) {
    thermal_closed_loop_model_DW.icLoad = true;
  }

  if (thermal_closed_loop_model_DW.icLoad) {
    thermal_closed_loop_model_DW.UD_DSTATE =
      thermal_closed_loop_model_cal->Constant_Value_a4;
  }

  /* Delay: '<S150>/UD' */
  thermal_closed_loop_model_B.UD = thermal_closed_loop_model_DW.UD_DSTATE;

  /* Sum: '<S150>/Diff' */
  thermal_closed_loop_model_B.Diff = thermal_closed_loop_model_B.Tsamp -
    thermal_closed_loop_model_B.UD;

  /* Sum: '<S167>/Sum' */
  thermal_closed_loop_model_B.Sum_j =
    (thermal_closed_loop_model_B.ProportionalGain +
     thermal_closed_loop_model_B.Integrator_k) +
    thermal_closed_loop_model_B.Diff;

  /* Sum: '<S50>/Sum3' incorporates:
   *  Constant: '<S50>/p_Emp_TCP_max_rpm'
   */
  thermal_closed_loop_model_B.Sum3_o =
    thermal_closed_loop_model_cal->p_Emp_TCP_max_rpm_Value -
    thermal_closed_loop_model_B.Switch2;

  /* RelationalOperator: '<S148>/u_GTE_up' */
  thermal_closed_loop_model_B.u_GTE_up = (thermal_closed_loop_model_B.Sum_j >=
    thermal_closed_loop_model_B.Sum3_o);

  /* Switch: '<S148>/Switch' */
  if (thermal_closed_loop_model_B.u_GTE_up) {
    /* Switch: '<S148>/Switch' */
    thermal_closed_loop_model_B.Switch_p = thermal_closed_loop_model_B.Sum3_o;
  } else {
    /* RelationalOperator: '<S148>/u_GT_lo' */
    thermal_closed_loop_model_B.u_GT_lo = (thermal_closed_loop_model_B.Sum_j >
      thermal_closed_loop_model_B.Sum2);

    /* Switch: '<S148>/Switch1' */
    if (thermal_closed_loop_model_B.u_GT_lo) {
      /* Switch: '<S148>/Switch1' */
      thermal_closed_loop_model_B.Switch1 = thermal_closed_loop_model_B.Sum_j;
    } else {
      /* Switch: '<S148>/Switch1' */
      thermal_closed_loop_model_B.Switch1 = thermal_closed_loop_model_B.Sum2;
    }

    /* End of Switch: '<S148>/Switch1' */

    /* Switch: '<S148>/Switch' */
    thermal_closed_loop_model_B.Switch_p = thermal_closed_loop_model_B.Switch1;
  }

  /* End of Switch: '<S148>/Switch' */

  /* Sum: '<S148>/Diff' */
  thermal_closed_loop_model_B.Diff_e = thermal_closed_loop_model_B.Sum_j -
    thermal_closed_loop_model_B.Switch_p;

  /* RelationalOperator: '<S145>/Relational Operator' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   */
  thermal_closed_loop_model_B.RelationalOperator_c =
    (thermal_closed_loop_model_cal->Clamping_zero_Value !=
     thermal_closed_loop_model_B.Diff_e);

  /* RelationalOperator: '<S145>/fix for DT propagation issue' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   */
  thermal_closed_loop_model_B.fixforDTpropagationissue =
    (thermal_closed_loop_model_B.Diff_e >
     thermal_closed_loop_model_cal->Clamping_zero_Value);

  /* Switch: '<S145>/Switch1' */
  if (thermal_closed_loop_model_B.fixforDTpropagationissue) {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/Constant'
     */
    thermal_closed_loop_model_B.Switch1_l =
      thermal_closed_loop_model_cal->Constant_Value_i;
  } else {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/Constant2'
     */
    thermal_closed_loop_model_B.Switch1_l =
      thermal_closed_loop_model_cal->Constant2_Value_f;
  }

  /* End of Switch: '<S145>/Switch1' */

  /* Gain: '<S154>/Integral Gain' */
  thermal_closed_loop_model_B.IntegralGain =
    thermal_closed_loop_model_cal->DiscretePIDController_I *
    thermal_closed_loop_model_B.Sum1_l;

  /* RelationalOperator: '<S145>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   */
  thermal_closed_loop_model_B.fixforDTpropagationissue1 =
    (thermal_closed_loop_model_B.IntegralGain >
     thermal_closed_loop_model_cal->Clamping_zero_Value);

  /* Switch: '<S145>/Switch2' */
  if (thermal_closed_loop_model_B.fixforDTpropagationissue1) {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/Constant3'
     */
    thermal_closed_loop_model_B.Switch2_c =
      thermal_closed_loop_model_cal->Constant3_Value_h;
  } else {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S145>/Constant4'
     */
    thermal_closed_loop_model_B.Switch2_c =
      thermal_closed_loop_model_cal->Constant4_Value;
  }

  /* End of Switch: '<S145>/Switch2' */

  /* RelationalOperator: '<S145>/Equal1' */
  thermal_closed_loop_model_B.Equal1 = (thermal_closed_loop_model_B.Switch1_l ==
    thermal_closed_loop_model_B.Switch2_c);

  /* Logic: '<S145>/AND3' */
  thermal_closed_loop_model_B.AND3 =
    (thermal_closed_loop_model_B.RelationalOperator_c &&
     thermal_closed_loop_model_B.Equal1);

  /* Switch: '<S145>/Switch' */
  if (thermal_closed_loop_model_B.AND3) {
    /* Switch: '<S145>/Switch' incorporates:
     *  Constant: '<S145>/Constant1'
     */
    thermal_closed_loop_model_B.Switch_m =
      thermal_closed_loop_model_cal->Constant1_Value;
  } else {
    /* Switch: '<S145>/Switch' */
    thermal_closed_loop_model_B.Switch_m =
      thermal_closed_loop_model_B.IntegralGain;
  }

  /* End of Switch: '<S145>/Switch' */

  /* RelationalOperator: '<S165>/LowerRelop1' */
  thermal_closed_loop_model_B.LowerRelop1_c = (thermal_closed_loop_model_B.Sum_j
    > thermal_closed_loop_model_B.Sum3_o);

  /* RelationalOperator: '<S165>/UpperRelop' */
  thermal_closed_loop_model_B.UpperRelop_p = (thermal_closed_loop_model_B.Sum_j <
    thermal_closed_loop_model_B.Sum2);

  /* Switch: '<S165>/Switch' */
  if (thermal_closed_loop_model_B.UpperRelop_p) {
    /* Switch: '<S165>/Switch' */
    thermal_closed_loop_model_B.Switch_f = thermal_closed_loop_model_B.Sum2;
  } else {
    /* Switch: '<S165>/Switch' */
    thermal_closed_loop_model_B.Switch_f = thermal_closed_loop_model_B.Sum_j;
  }

  /* End of Switch: '<S165>/Switch' */

  /* Switch: '<S165>/Switch2' */
  if (thermal_closed_loop_model_B.LowerRelop1_c) {
    /* Switch: '<S165>/Switch2' */
    thermal_closed_loop_model_B.Switch2_m = thermal_closed_loop_model_B.Sum3_o;
  } else {
    /* Switch: '<S165>/Switch2' */
    thermal_closed_loop_model_B.Switch2_m = thermal_closed_loop_model_B.Switch_f;
  }

  /* End of Switch: '<S165>/Switch2' */

  /* MinMax: '<S175>/Max' incorporates:
   *  Constant: '<S175>/Time constant'
   */
  u0 = thermal_closed_loop_model_B.Probe[0];
  u1 = thermal_closed_loop_model_cal->LowPassFilterDiscreteorContin_b;
  if ((u0 >= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  /* MinMax: '<S175>/Max' */
  thermal_closed_loop_model_B.Max = u1;

  /* Fcn: '<S175>/Avoid Divide by Zero' */
  thermal_closed_loop_model_B.AvoidDividebyZero = static_cast<real_T>
    (thermal_closed_loop_model_B.Max == 0.0) * 2.2204460492503131e-16 +
    thermal_closed_loop_model_B.Max;

  /* Sum: '<S117>/Sum1' */
  thermal_closed_loop_model_B.Sum1_j = thermal_closed_loop_model_B.K -
    thermal_closed_loop_model_B.Saturation_g;

  /* Product: '<S117>/1//T' */
  thermal_closed_loop_model_B.uT = 1.0 /
    thermal_closed_loop_model_B.AvoidDividebyZero *
    thermal_closed_loop_model_B.Sum1_j;

  /* Sum: '<S50>/Sum4' */
  thermal_closed_loop_model_B.Sum4_o = thermal_closed_loop_model_B.Switch2_m +
    thermal_closed_loop_model_B.Switch2;

  /* RelationalOperator: '<S184>/Compare' incorporates:
   *  Constant: '<S184>/Constant'
   */
  thermal_closed_loop_model_B.Compare_h = (thermal_closed_loop_model_B.Sum1_l >
    thermal_closed_loop_model_cal->Constant_Value_a);

  /* Outputs for Triggered SubSystem: '<S120>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S185>/Trigger'
   */
  zcEvent = (thermal_closed_loop_model_B.Compare_h &&
             (thermal_closed_loop_mod_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
              POS_ZCSIG));
  if (zcEvent) {
    /* Switch: '<S185>/Switch' */
    if (thermal_closed_loop_model_B.UnitDelay >
        thermal_closed_loop_model_cal->Switch_Threshold) {
      /* Switch: '<S185>/Switch' */
      thermal_closed_loop_model_B.Switch_d =
        thermal_closed_loop_model_B.UnitDelay;
    } else {
      /* Switch: '<S185>/Switch' incorporates:
       *  Constant: '<S185>/Constant'
       */
      thermal_closed_loop_model_B.Switch_d =
        thermal_closed_loop_model_cal->Constant_Value_g;
    }

    /* End of Switch: '<S185>/Switch' */
    thermal_closed_loop_model_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  thermal_closed_loop_mod_PrevZCX.TriggeredSubsystem_Trig_ZCE =
    thermal_closed_loop_model_B.Compare_h;

  /* End of Outputs for SubSystem: '<S120>/Triggered Subsystem' */

  /* Update for DiscreteIntegrator: '<S181>/Integrator' */
  thermal_closed_loop_model_DW.Integrator_IC_LOADING = 0U;
  thermal_closed_loop_model_DW.Integrator_DSTATE +=
    thermal_closed_loop_model_cal->Integrator_gainval *
    thermal_closed_loop_model_B.uT;
  if (thermal_closed_loop_model_DW.Integrator_DSTATE >=
      thermal_closed_loop_model_P.Integrator_UpperSat) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_P.Integrator_UpperSat;
  } else if (thermal_closed_loop_model_DW.Integrator_DSTATE <=
             thermal_closed_loop_model_P.Integrator_LowerSat) {
    thermal_closed_loop_model_DW.Integrator_DSTATE =
      thermal_closed_loop_model_P.Integrator_LowerSat;
  }

  thermal_closed_loop_model_DW.Integrator_PrevResetState = static_cast<int8_T>
    (thermal_closed_loop_model_B.LogicalOperator);

  /* End of Update for DiscreteIntegrator: '<S181>/Integrator' */

  /* Update for UnitDelay: '<S120>/Unit Delay' */
  thermal_closed_loop_model_DW.UnitDelay_DSTATE_h =
    thermal_closed_loop_model_B.Switch_d;

  /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
  thermal_closed_loop_model_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  thermal_closed_loop_model_DW.DiscreteTimeIntegrator_DSTATE =
    thermal_closed_loop_model_cal->DiscreteTimeIntegrator_gainval *
    thermal_closed_loop_model_B.Sum_p[0] +
    thermal_closed_loop_model_B.DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S182>/Unit Delay' */
  thermal_closed_loop_model_DW.UnitDelay_DSTATE_b =
    thermal_closed_loop_model_B.Sum3;

  /* Update for UnitDelay: '<S182>/Unit Delay1' */
  thermal_closed_loop_model_DW.UnitDelay1_DSTATE_b =
    thermal_closed_loop_model_B.Switch;

  /* Update for DiscreteIntegrator: '<S157>/Integrator' */
  thermal_closed_loop_model_DW.Integrator_IC_LOADING_m = 0U;
  thermal_closed_loop_model_DW.Integrator_DSTATE_o +=
    thermal_closed_loop_model_cal->Integrator_gainval_k *
    thermal_closed_loop_model_B.Switch_m;
  if (thermal_closed_loop_model_B.UnitDelay > 0.0) {
    thermal_closed_loop_model_DW.Integrator_PrevResetState_o = 1;
  } else if (thermal_closed_loop_model_B.UnitDelay < 0.0) {
    thermal_closed_loop_model_DW.Integrator_PrevResetState_o = -1;
  } else if (thermal_closed_loop_model_B.UnitDelay == 0.0) {
    thermal_closed_loop_model_DW.Integrator_PrevResetState_o = 0;
  } else {
    thermal_closed_loop_model_DW.Integrator_PrevResetState_o = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S157>/Integrator' */

  /* Update for Delay: '<S150>/UD' */
  thermal_closed_loop_model_DW.icLoad = false;
  thermal_closed_loop_model_DW.UD_DSTATE = thermal_closed_loop_model_B.Tsamp;

  /* End of Outputs for SubSystem: '<S3>/controlEMPHVTCP' */
}
