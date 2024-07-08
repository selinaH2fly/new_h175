/*
 * thermal_closed_loop_model.cpp
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
#include "rtwtypes.h"
#include "rte_thermal_closed_loop_model_parameters.h"
#include <cmath>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "thermal_closed_loop_model_private.h"
#include "BasicThermalSubsystemControl.h"
#include "thermal_closed_loop_model_cal.h"
#include <cstring>
#include <stddef.h>

/* Block signals (default storage) */
B_thermal_closed_loop_model_T thermal_closed_loop_model_B;

/* Continuous states */
X_thermal_closed_loop_model_T thermal_closed_loop_model_X;

/* Block states (default storage) */
DW_thermal_closed_loop_model_T thermal_closed_loop_model_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_thermal_closed_loop_m_T thermal_closed_loop_mod_PrevZCX;

/* Mass Matrices */
MassMatrix_thermal_closed_loo_T thermal_closed_loop__MassMatrix;

/* Real-time model */
RT_MODEL_thermal_closed_loop__T thermal_closed_loop_model_M_ =
  RT_MODEL_thermal_closed_loop__T();
RT_MODEL_thermal_closed_loop__T *const thermal_closed_loop_model_M =
  &thermal_closed_loop_model_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    real_T yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

/* ForcingFunction for root system: '<Root>' */
void thermal_closed_loop_model_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_thermal_closed_loop_mode_T *_rtXdot;
  char *msg;
  real_T tmp_0[32];
  real_T time;
  int_T tmp_1[9];
  int_T is;
  boolean_T tmp;
  _rtXdot = ((XDot_thermal_closed_loop_mode_T *)
             thermal_closed_loop_model_M->derivs);

  /* ForcingFunction for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->tcv_opening = 0.0;
  _rtXdot->tcv_opening += thermal_closed_loop_model_cal->TransferFcn1_A *
    thermal_closed_loop_model_X.tcv_opening;
  _rtXdot->tcv_opening += thermal_closed_loop_model_B.RateTransition1;

  /* ForcingFunction for TransferFcn: '<S7>/Transfer Fcn2' */
  _rtXdot->tcv_opening_o = 0.0;
  _rtXdot->tcv_opening_o += thermal_closed_loop_model_cal->TransferFcn2_A *
    thermal_closed_loop_model_X.tcv_opening_o;
  _rtXdot->tcv_opening_o += thermal_closed_loop_model_B.RateTransition2;

  /* ForcingFunction for TransferFcn: '<S7>/Transfer Fcn' */
  _rtXdot->tcv_opening_e = 0.0;
  _rtXdot->tcv_opening_e += thermal_closed_loop_model_cal->TransferFcn_A *
    thermal_closed_loop_model_X.tcv_opening_e;
  _rtXdot->tcv_opening_e += thermal_closed_loop_model_B.RateTransition;

  /* ForcingFunction for SimscapeExecutionBlock: '<S47>/STATE_1' */
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.STATE_1_SimData);
  time = thermal_closed_loop_model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 148;
  simulationData->mData->mContStates.mX =
    &thermal_closed_loop_model_X.thermal_closed_loop_modelBasic_[0];
  simulationData->mData->mDiscStates.mN = 115;
  simulationData->mData->mDiscStates.mX =
    &thermal_closed_loop_model_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 214;
  simulationData->mData->mModeVector.mX =
    &thermal_closed_loop_model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (thermal_closed_loop_model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&thermal_closed_loop_model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&thermal_closed_loop_model_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
  tmp_0[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
  tmp_0[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
  tmp_0[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
  tmp_0[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
  tmp_0[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
  tmp_0[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
  tmp_0[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
  tmp_0[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
  tmp_0[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
  tmp_0[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
  tmp_0[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
  tmp_0[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
  tmp_0[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
  tmp_0[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
  tmp_0[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
  tmp_0[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
  tmp_0[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
  tmp_0[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
  tmp_0[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
  tmp_0[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
  tmp_0[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
  tmp_0[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
  tmp_0[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
  tmp_0[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
  tmp_1[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 148;
  simulationData->mData->mDx.mX = &_rtXdot->thermal_closed_loop_modelBasic_[0];
  simulator = static_cast<NeslSimulator *>
    (thermal_closed_loop_model_DW.STATE_1_Simulator);
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  is = ne_simulator_method(simulator, NESL_SIM_FORCINGFUNCTION, simulationData,
    diagnosticManager);
  if (is != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S47>/STATE_1' */
}

/* MassMatrix for root system: '<Root>' */
void thermal_closed_loop_model_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[32];
  real_T time;
  real_T *tmp_2;
  real_T *tmp_3;
  int32_T tmp_4;
  int_T tmp_1[9];
  boolean_T tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S47>/STATE_1' */
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.STATE_1_SimData);
  time = thermal_closed_loop_model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 148;
  simulationData->mData->mContStates.mX =
    &thermal_closed_loop_model_X.thermal_closed_loop_modelBasic_[0];
  simulationData->mData->mDiscStates.mN = 115;
  simulationData->mData->mDiscStates.mX =
    &thermal_closed_loop_model_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 214;
  simulationData->mData->mModeVector.mX =
    &thermal_closed_loop_model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (thermal_closed_loop_model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&thermal_closed_loop_model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&thermal_closed_loop_model_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
  tmp_0[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
  tmp_0[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
  tmp_0[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
  tmp_0[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
  tmp_0[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
  tmp_0[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
  tmp_0[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
  tmp_0[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
  tmp_0[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
  tmp_0[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
  tmp_0[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
  tmp_0[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
  tmp_0[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
  tmp_0[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
  tmp_0[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
  tmp_0[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
  tmp_0[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
  tmp_0[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
  tmp_0[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
  tmp_0[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
  tmp_0[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
  tmp_0[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
  tmp_0[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
  tmp_0[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
  tmp_1[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  tmp_2 = thermal_closed_loop_model_M->massMatrixPr;
  tmp_3 = double_pointer_shift(tmp_2,
    thermal_closed_loop_model_DW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 31;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  simulator = static_cast<NeslSimulator *>
    (thermal_closed_loop_model_DW.STATE_1_Simulator);
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method(simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S47>/STATE_1' */
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  thermal_closed_loop_model_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) std::memcpy(Mdest, Msrc,
                       static_cast<uint_T>(nzmax)*sizeof(real_T));
  }
}

void local_evaluateFminusMv(RTWSolverInfo *si, const real_T *v, real_T *fminusMv
  )
{
  /* Refresh forcing function */
  rtsiSetdX(si,fminusMv);
  thermal_closed_loop_model_forcingfunction();

  /* Refresh global mass matrix */
  thermal_closed_loop_model_massmatrix();

  /* Form f - M*v */
  {
    real_T *elptr = rtsiGetSolverMassMatrixPr(si);
    int_T *iptr = rtsiGetSolverMassMatrixIr(si);
    int_T *jc = rtsiGetSolverMassMatrixJc(si);
    int_T nx = 151;
    int_T col,row;
    for (col = 0; col < nx; col++) {
      for (row = jc[col]; row < jc[col+1]; row++) {
        fminusMv[*iptr++] -= (*v) * (*elptr++);
      }

      v++;
    }
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *v, const real_T
                  *Fty, real_T *fac, real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = std::pow(EPS, 0.75);
  real_T BU = std::pow(EPS, 0.25);
  real_T FACMIN = std::pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 151;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) std::memcpy(x, y,
                       static_cast<uint_T>(nx)*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = std::abs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = std::abs(del);
    else
      del = -std::abs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    thermal_closed_loop_model_step0();
    local_evaluateFminusMv(si,v,p );
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = std::abs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = std::abs(FdelRowmax);
      if (fscale < std::abs(Fty[rowmax]))
        fscale = std::abs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = static_cast<ODE14X_IntgData *>(rtsiGetSolverData(si));
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  real_T *M1 = id->M1;
  real_T *xdot = id->xdot;
  real_T *Edot = id->Edot;
  real_T *fminusMxdot = id->fminusMxdot;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 151;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(x0, x1,
                     static_cast<uint_T>(nx)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  local_evaluateMassMatrix(si,M );
  rtsiSetdX(si, xdot);
  thermal_closed_loop_model_derivatives();

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  thermal_closed_loop_model_forcingfunction();

  /* Form fminusMxdot = f(x) - M(x)*xdot, d(fminusMxdot)/dx = df/dx - d(Mv)/dx */
  (void) std::memcpy(fminusMxdot, f0,
                     static_cast<uint_T>(nx)*sizeof(real_T));
  for (col = 0; col < nx; col++) {
    for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
      real_T m_row_col = M[rowidx];
      row = Mpattern_ir[rowidx];
      fminusMxdot[row] -= m_row_col*xdot[col];
    }
  }

  local_numjac(si,x0,xdot,fminusMxdot,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) std::memcpy(W, dfdx,
                       static_cast<uint_T>(nx)*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) std::memcpy(x1, x0,
                       static_cast<uint_T>(nx)*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      thermal_closed_loop_model_step0();
      thermal_closed_loop_model_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      /* rhs = rhs - (Mtmp - M)*ztmp*h */
      local_evaluateMassMatrix(si,M1 );
      for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
        M1[i] -= M[i];
      }

      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M1[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= hN*m_row_col*ztmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) std::memcpy(x1start, x1,
                         static_cast<uint_T>(nx)*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        thermal_closed_loop_model_step0();
        thermal_closed_loop_model_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        /* For state-dep.,  Mdel = M(ttmp,ytmp) - M */
        thermal_closed_loop_model_step0();
        local_evaluateMassMatrix(si,M1 );
        for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
          M1[i] -= M[i];
        }

        /* rhs = rhs - Mdel*ztmp*h */
        for (col = 0; col < nx; col++) {
          for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++)
          {
            real_T m_row_col = M1[rowidx];
            row = Mpattern_ir[rowidx];
            Delta[row] -= hN*m_row_col*ztmp[col];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) std::memcpy(&(E[nx*j]), x1,
                       static_cast<uint_T>(nx)*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = static_cast<real_T>(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) std::memcpy(&(E[nx*(k-1)]), x1,
                         static_cast<uint_T>(nx)*sizeof(real_T));
    }

    /* Extrapolate the derivative */
    for (i = 0; i < nx; i++) {
      xdot[i] = (x1[i] - x1start[i])/hN;
    }

    (void) std::memcpy(&(Edot[nx*j]), xdot,
                       static_cast<uint_T>(nx)*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = static_cast<real_T>(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        xdot[i] = Edot[nx*k+i] + coef*(Edot[nx*k+i] - Edot[nx*(k-1)+i]);
      }

      (void) std::memcpy(&(Edot[nx*(k-1)]), xdot,
                         nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) std::memcpy(x1, E,
                     static_cast<uint_T>(nx)*sizeof(real_T));

  /* Extrapolated xdot */
  (void) std::memcpy(xdot, Edot,
                     nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = std::sqrt(-2.0 * std::log(si) / si) * sr;
  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void thermal_closed_loop_model_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
    /* set solver stop time */
    if (!(thermal_closed_loop_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&thermal_closed_loop_model_M->solverInfo,
                            ((thermal_closed_loop_model_M->Timing.clockTickH0 +
        1) * thermal_closed_loop_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&thermal_closed_loop_model_M->solverInfo,
                            ((thermal_closed_loop_model_M->Timing.clockTick0 + 1)
        * thermal_closed_loop_model_M->Timing.stepSize0 +
        thermal_closed_loop_model_M->Timing.clockTickH0 *
        thermal_closed_loop_model_M->Timing.stepSize0 * 4294967296.0));
    }

    /* Update the flag to indicate when data transfers from
     *  Sample time: [0.05s, 0.0s] to Sample time: [0.1s, 0.0s]  */
    (thermal_closed_loop_model_M->Timing.RateInteraction.TID1_2)++;
    if ((thermal_closed_loop_model_M->Timing.RateInteraction.TID1_2) > 1) {
      thermal_closed_loop_model_M->Timing.RateInteraction.TID1_2 = 0;
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(thermal_closed_loop_model_M)) {
    thermal_closed_loop_model_M->Timing.t[0] = rtsiGetT
      (&thermal_closed_loop_model_M->solverInfo);
  }

  {
    NeParameterBundle expl_temp;
    NeslRtpManager *rtpManager;
    NeslSimulationData *simulationData;
    NeslSimulator *simulator;
    NeuDiagnosticManager *diag;
    NeuDiagnosticTree *diagTree;
    char *msg;
    real_T tmp_2[401];
    real_T tmp_4[401];
    real_T tmp_6[401];
    real_T tmp_8[401];
    real_T tmp_0[32];
    real_T deltaT;
    real_T riseValLimit;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T time_5;
    real_T time_6;
    real_T time_7;
    real_T time_8;
    real_T tmp;
    real_T tmp_a;
    real_T tmp_b;
    real_T u1;
    real_T *parameterBundle_mRealParameters;
    int_T tmp_3[10];
    int_T tmp_5[10];
    int_T tmp_7[10];
    int_T tmp_9[10];
    int_T tmp_1[9];
    int_T iy;
    boolean_T ok;

    /* Gain: '<S1>/Gain' */
    tmp_b = *get_coolant_tube_D();

    /* Reset subsysRan breadcrumbs */
    srClearBC(thermal_closed_loop_model_DW.TriggeredSubsystem_SubsysRanBC);
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* UnitDelay: '<S7>/Unit Delay16' */
      thermal_closed_loop_model_B.StackCurrentI_A_StNA =
        thermal_closed_loop_model_DW.UnitDelay16_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay6' */
      thermal_closed_loop_model_B.TCVOpeningCommand =
        thermal_closed_loop_model_DW.UnitDelay6_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay7' */
      thermal_closed_loop_model_B.TCVOpening =
        thermal_closed_loop_model_DW.UnitDelay7_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay8' */
      thermal_closed_loop_model_B.TCPRotationalSpeedCommandrpm =
        thermal_closed_loop_model_DW.UnitDelay8_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay9' */
      thermal_closed_loop_model_B.TCPRotationalSpeedrpm =
        thermal_closed_loop_model_DW.UnitDelay9_DSTATE;

      /* UnitDelay: '<S1>/Unit Delay10' */
      thermal_closed_loop_model_B.AuxTCPRotationalSpeedCommandrpm =
        thermal_closed_loop_model_DW.UnitDelay10_DSTATE;

      /* UnitDelay: '<S1>/Unit Delay11' */
      thermal_closed_loop_model_B.AuxTCPRotationalSpeedrpm =
        thermal_closed_loop_model_DW.UnitDelay11_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay2' */
      thermal_closed_loop_model_B.AuxTCPOutletTemperature6801K =
        thermal_closed_loop_model_DW.UnitDelay2_DSTATE;

      /* Sum: '<S190>/Sum' incorporates:
       *  Constant: '<S190>/Constant'
       */
      thermal_closed_loop_model_B.Sum =
        thermal_closed_loop_model_B.AuxTCPOutletTemperature6801K -
        thermal_closed_loop_model_cal->Constant_Value_m;

      /* UnitDelay: '<S7>/Unit Delay1' */
      thermal_closed_loop_model_B.StackOutletTemperature6820K =
        thermal_closed_loop_model_DW.UnitDelay1_DSTATE;

      /* Sum: '<S189>/Sum' incorporates:
       *  Constant: '<S189>/Constant'
       */
      thermal_closed_loop_model_B.Sum_k =
        thermal_closed_loop_model_B.StackOutletTemperature6820K -
        thermal_closed_loop_model_cal->Constant_Value_e;

      /* UnitDelay: '<S7>/Unit Delay' */
      thermal_closed_loop_model_B.StackInletTemperature6812K =
        thermal_closed_loop_model_DW.UnitDelay_DSTATE;

      /* Sum: '<S188>/Sum' incorporates:
       *  Constant: '<S188>/Constant'
       */
      thermal_closed_loop_model_B.Sum_m =
        thermal_closed_loop_model_B.StackInletTemperature6812K -
        thermal_closed_loop_model_cal->Constant_Value_e5;

      /* RateTransition generated from: '<S4>/Sum' */
      if (thermal_closed_loop_model_M->Timing.RateInteraction.TID1_2 == 1) {
        thermal_closed_loop_model_DW.TmpRTBAtSumInport1_RdBufIdx =
          static_cast<int8_T>
          (thermal_closed_loop_model_DW.TmpRTBAtSumInport1_RdBufIdx == 0);
      }

      iy = thermal_closed_loop_model_DW.TmpRTBAtSumInport1_RdBufIdx * 3;

      /* RateTransition generated from: '<S4>/Sum' */
      thermal_closed_loop_model_B.TmpRTBAtSumInport1[0] =
        thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[iy];
      thermal_closed_loop_model_B.TmpRTBAtSumInport1[1] =
        thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[iy + 1];
      thermal_closed_loop_model_B.TmpRTBAtSumInport1[2] =
        thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[iy + 2];

      /* Sum: '<S4>/Sum' */
      thermal_closed_loop_model_B.Sum_p[0] =
        thermal_closed_loop_model_B.TmpRTBAtSumInport1[0] +
        thermal_closed_loop_model_B.StackCurrentI_A_StNA;
      thermal_closed_loop_model_B.Sum_p[1] =
        thermal_closed_loop_model_B.TmpRTBAtSumInport1[1] +
        thermal_closed_loop_model_B.Sum_m;
      thermal_closed_loop_model_B.Sum_p[2] =
        thermal_closed_loop_model_B.TmpRTBAtSumInport1[2] +
        thermal_closed_loop_model_B.Sum_k;

      /* Outputs for Atomic SubSystem: '<Root>/BasicThermalSubsystemControl' */
      BasicThermalSubsystemContro();

      /* End of Outputs for SubSystem: '<Root>/BasicThermalSubsystemControl' */

      /* Sum: '<S6>/Add' */
      thermal_closed_loop_model_B.StackOutletTemperatureSetpointC =
        thermal_closed_loop_model_B.uDLookupTable1 +
        thermal_closed_loop_model_B.uDLookupTable1_p;

      /* UnitDelay: '<S7>/Unit Delay5' */
      thermal_closed_loop_model_B.AuxTCPOutletPressure6801Pa =
        thermal_closed_loop_model_DW.UnitDelay5_DSTATE;

      /* Gain: '<S212>/Pa to Bar(a)' */
      thermal_closed_loop_model_B.PatoBara =
        thermal_closed_loop_model_cal->PatoBara_Gain *
        thermal_closed_loop_model_B.AuxTCPOutletPressure6801Pa;

      /* UnitDelay: '<S7>/Unit Delay4' */
      thermal_closed_loop_model_B.TCPOutletPressure6812Pa =
        thermal_closed_loop_model_DW.UnitDelay4_DSTATE;

      /* Gain: '<S211>/Pa to Bar(a)' */
      thermal_closed_loop_model_B.PatoBara_i =
        thermal_closed_loop_model_cal->PatoBara_Gain_o *
        thermal_closed_loop_model_B.TCPOutletPressure6812Pa;

      /* UnitDelay: '<S7>/Unit Delay3' */
      thermal_closed_loop_model_B.TCPInletPressure6811Pa =
        thermal_closed_loop_model_DW.UnitDelay3_DSTATE;

      /* Gain: '<S210>/Pa to Bar(a)' */
      thermal_closed_loop_model_B.PatoBara_j =
        thermal_closed_loop_model_cal->PatoBara_Gain_f *
        thermal_closed_loop_model_B.TCPInletPressure6811Pa;

      /* UnitDelay: '<S7>/Unit Delay14' */
      thermal_closed_loop_model_B.StackCoolantFlowlmin =
        thermal_closed_loop_model_DW.UnitDelay14_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay12' */
      thermal_closed_loop_model_B.MixHotCoolantFlowInlmin =
        thermal_closed_loop_model_DW.UnitDelay12_DSTATE;

      /* UnitDelay: '<S7>/Unit Delay13' */
      thermal_closed_loop_model_B.MixColdCoolantFlowInlmin =
        thermal_closed_loop_model_DW.UnitDelay13_DSTATE;

      /* UnitDelay: '<S1>/Unit Delay5' */
      thermal_closed_loop_model_B.AuxTCPInletPressurePa =
        thermal_closed_loop_model_DW.UnitDelay5_DSTATE_p;

      /* Gain: '<S19>/Pa to Bar(a)' */
      thermal_closed_loop_model_B.PatoBara_g =
        thermal_closed_loop_model_cal->PatoBara_Gain_e *
        thermal_closed_loop_model_B.AuxTCPInletPressurePa;

      /* UnitDelay: '<S1>/Unit Delay2' */
      thermal_closed_loop_model_B.AuxTCPInletTemperatureK =
        thermal_closed_loop_model_DW.UnitDelay2_DSTATE_m;

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/Constant'
       */
      thermal_closed_loop_model_B.Sum_pg =
        thermal_closed_loop_model_B.AuxTCPInletTemperatureK -
        thermal_closed_loop_model_cal->Constant_Value_p;

      /* UnitDelay: '<S1>/Unit Delay1' */
      thermal_closed_loop_model_B.RadiatorCoolantFlowlmin =
        thermal_closed_loop_model_DW.UnitDelay1_DSTATE_i;

      /* UnitDelay: '<S1>/Unit Delay3' */
      thermal_closed_loop_model_B.BypassCoolantFlowlmin =
        thermal_closed_loop_model_DW.UnitDelay3_DSTATE_d;

      /* UnitDelay: '<S7>/Unit Delay10' */
      thermal_closed_loop_model_B.AuxTCPRotationalSpeedCommandr_m =
        thermal_closed_loop_model_DW.UnitDelay10_DSTATE_f;

      /* UnitDelay: '<S7>/Unit Delay11' */
      thermal_closed_loop_model_B.AuxTCPRotationalSpeedrpm_l =
        thermal_closed_loop_model_DW.UnitDelay11_DSTATE_p;

      /* UnitDelay: '<S7>/Unit Delay15' */
      thermal_closed_loop_model_B.StackOutletPressurePa =
        thermal_closed_loop_model_DW.UnitDelay15_DSTATE;

      /* Gain: '<S213>/Pa to Bar(a)' */
      thermal_closed_loop_model_B.PatoBara_k =
        thermal_closed_loop_model_cal->PatoBara_Gain_l *
        thermal_closed_loop_model_B.StackOutletPressurePa;
    }

    /* TransferFcn: '<S1>/Transfer Fcn1' */
    thermal_closed_loop_model_B.TransferFcn1 = 0.0;
    thermal_closed_loop_model_B.TransferFcn1 +=
      thermal_closed_loop_model_cal->TransferFcn1_C *
      thermal_closed_loop_model_X.tcv_opening;

    /* RateLimiter: '<S1>/Rate Limiter1' */
    if ((thermal_closed_loop_model_DW.LastMajorTimeA >=
         thermal_closed_loop_model_M->Timing.t[0]) &&
        (thermal_closed_loop_model_DW.LastMajorTimeB >=
         thermal_closed_loop_model_M->Timing.t[0])) {
      /* RateLimiter: '<S1>/Rate Limiter1' */
      thermal_closed_loop_model_B.RateLimiter1 =
        thermal_closed_loop_model_B.TransferFcn1;
    } else {
      if (((thermal_closed_loop_model_DW.LastMajorTimeA <
            thermal_closed_loop_model_DW.LastMajorTimeB) &&
           (thermal_closed_loop_model_DW.LastMajorTimeB <
            thermal_closed_loop_model_M->Timing.t[0])) ||
          ((thermal_closed_loop_model_DW.LastMajorTimeA >=
            thermal_closed_loop_model_DW.LastMajorTimeB) &&
           (thermal_closed_loop_model_DW.LastMajorTimeA >=
            thermal_closed_loop_model_M->Timing.t[0]))) {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeB;
        u1 = thermal_closed_loop_model_DW.PrevYB;
      } else {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeA;
        u1 = thermal_closed_loop_model_DW.PrevYA;
      }

      riseValLimit = deltaT *
        thermal_closed_loop_model_cal->RateLimiter1_RisingLim;
      tmp_a = thermal_closed_loop_model_B.TransferFcn1 - u1;
      if (tmp_a > riseValLimit) {
        /* RateLimiter: '<S1>/Rate Limiter1' */
        thermal_closed_loop_model_B.RateLimiter1 = u1 + riseValLimit;
      } else {
        deltaT *= thermal_closed_loop_model_cal->RateLimiter1_FallingLim;
        if (tmp_a < deltaT) {
          /* RateLimiter: '<S1>/Rate Limiter1' */
          thermal_closed_loop_model_B.RateLimiter1 = u1 + deltaT;
        } else {
          /* RateLimiter: '<S1>/Rate Limiter1' */
          thermal_closed_loop_model_B.RateLimiter1 =
            thermal_closed_loop_model_B.TransferFcn1;
        }
      }
    }

    /* End of RateLimiter: '<S1>/Rate Limiter1' */

    /* SimscapeInputBlock: '<S47>/INPUT_1_1_1' */
    thermal_closed_loop_model_B.INPUT_1_1_1[0] =
      thermal_closed_loop_model_B.RateLimiter1;
    thermal_closed_loop_model_B.INPUT_1_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_1_1_1[2] = 0.0;
    thermal_closed_loop_model_B.INPUT_1_1_1[3] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* Gain: '<S1>/Gain' incorporates:
       *  Constant: '<Root>/Bypass_Opening'
       */
      thermal_closed_loop_model_B.Gain = tmp_b *
        thermal_closed_loop_model_cal->Bypass_Opening_Value;

      /* Saturate: '<S1>/Saturation' */
      deltaT = thermal_closed_loop_model_B.Gain;
      u1 = thermal_closed_loop_model_cal->Saturation_LowerSat_j0;
      riseValLimit = tmp_b;
      if (deltaT > riseValLimit) {
        /* Saturate: '<S1>/Saturation' */
        thermal_closed_loop_model_B.Saturation = riseValLimit;
      } else if (deltaT < u1) {
        /* Saturate: '<S1>/Saturation' */
        thermal_closed_loop_model_B.Saturation = u1;
      } else {
        /* Saturate: '<S1>/Saturation' */
        thermal_closed_loop_model_B.Saturation = deltaT;
      }

      /* End of Saturate: '<S1>/Saturation' */
    }

    /* SimscapeInputBlock: '<S47>/INPUT_2_1_1' */
    thermal_closed_loop_model_B.INPUT_2_1_1[0] =
      thermal_closed_loop_model_B.Saturation;
    thermal_closed_loop_model_B.INPUT_2_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_2_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      thermal_closed_loop_model_DW.INPUT_2_1_1_Discrete[0] =
        !(thermal_closed_loop_model_B.INPUT_2_1_1[0] ==
          thermal_closed_loop_model_DW.INPUT_2_1_1_Discrete[1]);
      thermal_closed_loop_model_DW.INPUT_2_1_1_Discrete[1] =
        thermal_closed_loop_model_B.INPUT_2_1_1[0];
    }

    thermal_closed_loop_model_B.INPUT_2_1_1[0] =
      thermal_closed_loop_model_DW.INPUT_2_1_1_Discrete[1];
    thermal_closed_loop_model_B.INPUT_2_1_1[3] =
      thermal_closed_loop_model_DW.INPUT_2_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S47>/INPUT_2_1_1' */
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* Product: '<S35>/Product' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S35>/Constant4'
       */
      thermal_closed_loop_model_B.Product =
        thermal_closed_loop_model_cal->Constant_Value_n * *get_radiator_area_air
        ();

      /* Product: '<S35>/Product1' incorporates:
       *  Constant: '<S35>/Constant2'
       */
      thermal_closed_loop_model_B.mdot_air = thermal_closed_loop_model_B.Product
        * *get_air_rho();

      /* Product: '<S35>/C_air' incorporates:
       *  Constant: '<S35>/Constant1'
       */
      thermal_closed_loop_model_B.C_air = thermal_closed_loop_model_B.mdot_air *
        *get_air_cp();
    }

    /* SimscapeInputBlock: '<S47>/INPUT_3_1_1' */
    thermal_closed_loop_model_B.INPUT_3_1_1[0] =
      thermal_closed_loop_model_B.C_air;
    thermal_closed_loop_model_B.INPUT_3_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_3_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      thermal_closed_loop_model_DW.INPUT_3_1_1_Discrete[0] =
        !(thermal_closed_loop_model_B.INPUT_3_1_1[0] ==
          thermal_closed_loop_model_DW.INPUT_3_1_1_Discrete[1]);
      thermal_closed_loop_model_DW.INPUT_3_1_1_Discrete[1] =
        thermal_closed_loop_model_B.INPUT_3_1_1[0];
    }

    thermal_closed_loop_model_B.INPUT_3_1_1[0] =
      thermal_closed_loop_model_DW.INPUT_3_1_1_Discrete[1];
    thermal_closed_loop_model_B.INPUT_3_1_1[3] =
      thermal_closed_loop_model_DW.INPUT_3_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S47>/INPUT_3_1_1' */
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* Product: '<S35>/Divide' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S35>/Constant'
       */
      thermal_closed_loop_model_B.Divide =
        thermal_closed_loop_model_cal->Constant_Value_n / *get_air_vel_nom();

      /* Saturate: '<S35>/Saturation' */
      deltaT = thermal_closed_loop_model_B.Divide;
      u1 = thermal_closed_loop_model_cal->Saturation_LowerSat_i;
      riseValLimit = thermal_closed_loop_model_P.Saturation_UpperSat_d;
      if (deltaT > riseValLimit) {
        /* Saturate: '<S35>/Saturation' */
        thermal_closed_loop_model_B.Saturation_i = riseValLimit;
      } else if (deltaT < u1) {
        /* Saturate: '<S35>/Saturation' */
        thermal_closed_loop_model_B.Saturation_i = u1;
      } else {
        /* Saturate: '<S35>/Saturation' */
        thermal_closed_loop_model_B.Saturation_i = deltaT;
      }

      /* End of Saturate: '<S35>/Saturation' */

      /* Fcn: '<S35>/Fcn' */
      tmp_a = thermal_closed_loop_model_B.Saturation_i;
      if (tmp_a < 0.0) {
        u1 = -rt_powd_snf(-tmp_a, 0.8);
      } else {
        u1 = rt_powd_snf(tmp_a, 0.8);
      }

      /* Fcn: '<S35>/Fcn' */
      thermal_closed_loop_model_B.Fcn = u1;

      /* Product: '<S35>/Product2' incorporates:
       *  Constant: '<S35>/Constant3'
       */
      thermal_closed_loop_model_B.Product2 = thermal_closed_loop_model_B.Fcn *
        *get_air_HC_nom();

      /* MinMax: '<S35>/MinMax' incorporates:
       *  Constant: '<S35>/Constant5'
       */
      deltaT = thermal_closed_loop_model_B.Product2;
      u1 = *get_air_HC_min();
      if ((deltaT >= u1) || rtIsNaN(u1)) {
        u1 = deltaT;
      }

      /* MinMax: '<S35>/MinMax' */
      thermal_closed_loop_model_B.MinMax = u1;
    }

    /* SimscapeInputBlock: '<S47>/INPUT_4_1_1' */
    thermal_closed_loop_model_B.INPUT_4_1_1[0] =
      thermal_closed_loop_model_B.MinMax;
    thermal_closed_loop_model_B.INPUT_4_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_4_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      thermal_closed_loop_model_DW.INPUT_4_1_1_Discrete[0] =
        !(thermal_closed_loop_model_B.INPUT_4_1_1[0] ==
          thermal_closed_loop_model_DW.INPUT_4_1_1_Discrete[1]);
      thermal_closed_loop_model_DW.INPUT_4_1_1_Discrete[1] =
        thermal_closed_loop_model_B.INPUT_4_1_1[0];
    }

    thermal_closed_loop_model_B.INPUT_4_1_1[0] =
      thermal_closed_loop_model_DW.INPUT_4_1_1_Discrete[1];
    thermal_closed_loop_model_B.INPUT_4_1_1[3] =
      thermal_closed_loop_model_DW.INPUT_4_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S47>/INPUT_4_1_1' */

    /* SimscapeInputBlock: '<S47>/INPUT_5_1_1' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    thermal_closed_loop_model_B.INPUT_5_1_1[0] =
      thermal_closed_loop_model_cal->Constant1_Value_a;
    thermal_closed_loop_model_B.INPUT_5_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_5_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      thermal_closed_loop_model_DW.INPUT_5_1_1_Discrete[0] =
        !(thermal_closed_loop_model_B.INPUT_5_1_1[0] ==
          thermal_closed_loop_model_DW.INPUT_5_1_1_Discrete[1]);
      thermal_closed_loop_model_DW.INPUT_5_1_1_Discrete[1] =
        thermal_closed_loop_model_B.INPUT_5_1_1[0];
    }

    thermal_closed_loop_model_B.INPUT_5_1_1[0] =
      thermal_closed_loop_model_DW.INPUT_5_1_1_Discrete[1];
    thermal_closed_loop_model_B.INPUT_5_1_1[3] =
      thermal_closed_loop_model_DW.INPUT_5_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S47>/INPUT_5_1_1' */

    /* FromWorkspace: '<S187>/FromWs' */
    {
      real_T *pDataValues = (real_T *)
        thermal_closed_loop_model_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        thermal_closed_loop_model_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = thermal_closed_loop_model_DW.FromWs_IWORK.PrevIndex;
      real_T t = thermal_closed_loop_model_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[25]) {
        currTimeIndex = 24;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      thermal_closed_loop_model_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            thermal_closed_loop_model_B.FromWs = pDataValues[currTimeIndex];
          } else {
            thermal_closed_loop_model_B.FromWs = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          thermal_closed_loop_model_B.FromWs = (real_T) rtInterpolate(d1, d2, f1,
            f2);
          pDataValues += 26;
        }
      }
    }

    /* Lookup_n-D: '<S2>/Current to Heat (W)' incorporates:
     *  FromWorkspace: '<S187>/FromWs'
     */
    thermal_closed_loop_model_B.CurrenttoHeatW = look1_binlxpw
      (thermal_closed_loop_model_B.FromWs,
       thermal_closed_loop_model_cal->CurrenttoHeatW_bp01Data,
       thermal_closed_loop_model_cal->CurrenttoHeatW_tableData, 8U);

    /* SimscapeInputBlock: '<S47>/INPUT_6_1_1' */
    thermal_closed_loop_model_B.INPUT_6_1_1[0] =
      thermal_closed_loop_model_B.CurrenttoHeatW;
    thermal_closed_loop_model_B.INPUT_6_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_6_1_1[2] = 0.0;
    thermal_closed_loop_model_B.INPUT_6_1_1[3] = 0.0;

    /* TransferFcn: '<S7>/Transfer Fcn2' */
    thermal_closed_loop_model_B.TransferFcn2 = 0.0;
    thermal_closed_loop_model_B.TransferFcn2 +=
      thermal_closed_loop_model_cal->TransferFcn2_C *
      thermal_closed_loop_model_X.tcv_opening_o;

    /* RateLimiter: '<S7>/Rate Limiter2' */
    if ((thermal_closed_loop_model_DW.LastMajorTimeA_j >=
         thermal_closed_loop_model_M->Timing.t[0]) &&
        (thermal_closed_loop_model_DW.LastMajorTimeB_k >=
         thermal_closed_loop_model_M->Timing.t[0])) {
      /* RateLimiter: '<S7>/Rate Limiter2' */
      thermal_closed_loop_model_B.RateLimiter2 =
        thermal_closed_loop_model_B.TransferFcn2;
    } else {
      if (((thermal_closed_loop_model_DW.LastMajorTimeA_j <
            thermal_closed_loop_model_DW.LastMajorTimeB_k) &&
           (thermal_closed_loop_model_DW.LastMajorTimeB_k <
            thermal_closed_loop_model_M->Timing.t[0])) ||
          ((thermal_closed_loop_model_DW.LastMajorTimeA_j >=
            thermal_closed_loop_model_DW.LastMajorTimeB_k) &&
           (thermal_closed_loop_model_DW.LastMajorTimeA_j >=
            thermal_closed_loop_model_M->Timing.t[0]))) {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeB_k;
        u1 = thermal_closed_loop_model_DW.PrevYB_c;
      } else {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeA_j;
        u1 = thermal_closed_loop_model_DW.PrevYA_c;
      }

      riseValLimit = deltaT *
        thermal_closed_loop_model_cal->RateLimiter2_RisingLim;
      tmp_a = thermal_closed_loop_model_B.TransferFcn2 - u1;
      if (tmp_a > riseValLimit) {
        /* RateLimiter: '<S7>/Rate Limiter2' */
        thermal_closed_loop_model_B.RateLimiter2 = u1 + riseValLimit;
      } else {
        deltaT *= thermal_closed_loop_model_cal->RateLimiter2_FallingLim;
        if (tmp_a < deltaT) {
          /* RateLimiter: '<S7>/Rate Limiter2' */
          thermal_closed_loop_model_B.RateLimiter2 = u1 + deltaT;
        } else {
          /* RateLimiter: '<S7>/Rate Limiter2' */
          thermal_closed_loop_model_B.RateLimiter2 =
            thermal_closed_loop_model_B.TransferFcn2;
        }
      }
    }

    /* End of RateLimiter: '<S7>/Rate Limiter2' */

    /* SimscapeInputBlock: '<S47>/INPUT_8_1_1' */
    thermal_closed_loop_model_B.INPUT_8_1_1[0] =
      thermal_closed_loop_model_B.RateLimiter2;
    thermal_closed_loop_model_B.INPUT_8_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_8_1_1[2] = 0.0;
    thermal_closed_loop_model_B.INPUT_8_1_1[3] = 0.0;

    /* TransferFcn: '<S7>/Transfer Fcn' */
    thermal_closed_loop_model_B.TransferFcn = 0.0;
    thermal_closed_loop_model_B.TransferFcn +=
      thermal_closed_loop_model_cal->TransferFcn_C *
      thermal_closed_loop_model_X.tcv_opening_e;

    /* RateLimiter: '<S7>/Rate Limiter' */
    if ((thermal_closed_loop_model_DW.LastMajorTimeA_h >=
         thermal_closed_loop_model_M->Timing.t[0]) &&
        (thermal_closed_loop_model_DW.LastMajorTimeB_a >=
         thermal_closed_loop_model_M->Timing.t[0])) {
      /* RateLimiter: '<S7>/Rate Limiter' */
      thermal_closed_loop_model_B.RateLimiter =
        thermal_closed_loop_model_B.TransferFcn;
    } else {
      if (((thermal_closed_loop_model_DW.LastMajorTimeA_h <
            thermal_closed_loop_model_DW.LastMajorTimeB_a) &&
           (thermal_closed_loop_model_DW.LastMajorTimeB_a <
            thermal_closed_loop_model_M->Timing.t[0])) ||
          ((thermal_closed_loop_model_DW.LastMajorTimeA_h >=
            thermal_closed_loop_model_DW.LastMajorTimeB_a) &&
           (thermal_closed_loop_model_DW.LastMajorTimeA_h >=
            thermal_closed_loop_model_M->Timing.t[0]))) {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeB_a;
        u1 = thermal_closed_loop_model_DW.PrevYB_h;
      } else {
        deltaT = thermal_closed_loop_model_M->Timing.t[0] -
          thermal_closed_loop_model_DW.LastMajorTimeA_h;
        u1 = thermal_closed_loop_model_DW.PrevYA_f;
      }

      riseValLimit = deltaT *
        thermal_closed_loop_model_cal->RateLimiter_RisingLim;
      tmp_a = thermal_closed_loop_model_B.TransferFcn - u1;
      if (tmp_a > riseValLimit) {
        /* RateLimiter: '<S7>/Rate Limiter' */
        thermal_closed_loop_model_B.RateLimiter = u1 + riseValLimit;
      } else {
        deltaT *= thermal_closed_loop_model_cal->RateLimiter_FallingLim;
        if (tmp_a < deltaT) {
          /* RateLimiter: '<S7>/Rate Limiter' */
          thermal_closed_loop_model_B.RateLimiter = u1 + deltaT;
        } else {
          /* RateLimiter: '<S7>/Rate Limiter' */
          thermal_closed_loop_model_B.RateLimiter =
            thermal_closed_loop_model_B.TransferFcn;
        }
      }
    }

    /* End of RateLimiter: '<S7>/Rate Limiter' */

    /* Gain: '<S214>/Gain' */
    thermal_closed_loop_model_B.Gain_l =
      thermal_closed_loop_model_cal->Gain_Gain_d *
      thermal_closed_loop_model_B.RateLimiter;

    /* Sum: '<S214>/Add' incorporates:
     *  Constant: '<S214>/Valve_Constant'
     */
    thermal_closed_loop_model_B.Add = thermal_closed_loop_model_B.Gain_l -
      thermal_closed_loop_model_cal->Valve_Constant_Value;

    /* SimscapeInputBlock: '<S47>/INPUT_7_1_1' */
    thermal_closed_loop_model_B.INPUT_7_1_1[0] = thermal_closed_loop_model_B.Add;
    thermal_closed_loop_model_B.INPUT_7_1_1[1] = 0.0;
    thermal_closed_loop_model_B.INPUT_7_1_1[2] = 0.0;
    thermal_closed_loop_model_B.INPUT_7_1_1[3] = 0.0;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* SimscapeRtp: '<S44>/RTP_1' incorporates:
       *  Constant: '<S2>/Subsystem_around_RTP_DE9C0308_T'
       */
      if (thermal_closed_loop_model_DW.RTP_1_SetParametersNeeded) {
        tmp = *get_coolant_initial_temperature();
        parameterBundle_mRealParameters = &tmp;
        rtpManager = static_cast<NeslRtpManager *>
          (thermal_closed_loop_model_DW.RTP_1_RtpManager);
        diag = rtw_create_diagnostics();
        diagTree = neu_diagnostic_manager_get_initial_tree(diag);
        expl_temp.mRealParameters.mN = 1;
        expl_temp.mRealParameters.mX = parameterBundle_mRealParameters;
        expl_temp.mLogicalParameters.mN = 0;
        expl_temp.mLogicalParameters.mX = NULL;
        expl_temp.mIntegerParameters.mN = 0;
        expl_temp.mIntegerParameters.mX = NULL;
        expl_temp.mIndexParameters.mN = 0;
        expl_temp.mIndexParameters.mX = NULL;
        ok = nesl_rtp_manager_set_rtps(rtpManager,
          thermal_closed_loop_model_M->Timing.t[0], expl_temp, diag);
        if (!ok) {
          ok = error_buffer_is_empty(rtmGetErrorStatus
            (thermal_closed_loop_model_M));
          if (ok) {
            msg = rtw_diagnostics_msg(diagTree);
            rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
          }
        }
      }

      thermal_closed_loop_model_DW.RTP_1_SetParametersNeeded = false;

      /* End of SimscapeRtp: '<S44>/RTP_1' */
    }

    /* SimscapeExecutionBlock: '<S47>/STATE_1' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.STATE_1_SimData);
    time = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 148;
    simulationData->mData->mContStates.mX =
      &thermal_closed_loop_model_X.thermal_closed_loop_modelBasic_[0];
    simulationData->mData->mDiscStates.mN = 115;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.STATE_1_Discrete[0];
    simulationData->mData->mModeVector.mN = 214;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.STATE_1_Modes[0];
    ok = false;
    simulationData->mData->mFoundZcEvents = ok;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    ok = false;
    simulationData->mData->mIsSolverAssertCheck = ok;
    simulationData->mData->mIsSolverCheckingCIC = false;
    ok = rtsiIsSolverComputingJacobian(&thermal_closed_loop_model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = ok;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_0[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_0[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_0[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_0[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_0[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_0[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_0[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_0[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_0[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_0[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_0[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_0[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_0[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_0[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_0[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_0[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_0[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_0[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_0[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_0[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_0[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_0[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_0[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_0[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_1[8] = 32;
    simulationData->mData->mInputValues.mN = 32;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 369;
    simulationData->mData->mOutputs.mX = &thermal_closed_loop_model_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_0 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.STATE_1_Simulator);
    diag = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (iy != 0) {
      ok = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S47>/STATE_1' */

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_0' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.OUTPUT_1_0_SimData);
    time_1 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_0_Modes;
    ok = false;
    simulationData->mData->mFoundZcEvents = ok;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    ok = false;
    simulationData->mData->mIsSolverAssertCheck = ok;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_3[0] = 0;
    tmp_2[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_2[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_2[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_2[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_3[1] = 4;
    tmp_2[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_2[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_2[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_2[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_3[2] = 8;
    tmp_2[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_2[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_2[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_2[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_3[3] = 12;
    tmp_2[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_2[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_2[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_2[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_3[4] = 16;
    tmp_2[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_2[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_2[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_2[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_3[5] = 20;
    tmp_2[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_2[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_2[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_2[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_3[6] = 24;
    tmp_2[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_2[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_2[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_2[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_3[7] = 28;
    tmp_2[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_2[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_2[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_2[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_3[8] = 32;
    std::memcpy(&tmp_2[32], &thermal_closed_loop_model_B.STATE_1[0], 369U *
                sizeof(real_T));
    tmp_3[9] = 401;
    simulationData->mData->mInputValues.mN = 401;
    simulationData->mData->mInputValues.mX = &tmp_2[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_3[0];
    simulationData->mData->mOutputs.mN = 23;
    simulationData->mData->mOutputs.mX =
      &thermal_closed_loop_model_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_2 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_0_Simulator);
    diag = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_0_DiagMgr);
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (iy != 0) {
      ok = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S47>/OUTPUT_1_0' */

    /* Reshape: '<S24>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE =
      thermal_closed_loop_model_B.OUTPUT_1_0[2];

    /* Reshape: '<S27>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_n =
      thermal_closed_loop_model_B.OUTPUT_1_0[6];

    /* Reshape: '<S28>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_g =
      thermal_closed_loop_model_B.OUTPUT_1_0[5];

    /* Reshape: '<S30>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_j =
      thermal_closed_loop_model_B.OUTPUT_1_0[3];

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant3'
     */
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* RateTransition: '<S1>/Rate Transition1' incorporates:
       *  Constant: '<Root>/p_Vlo_TCP_min_rpm'
       */
      thermal_closed_loop_model_B.RateTransition1 =
        thermal_closed_loop_model_cal->p_Vlo_TCP_min_rpm_Value;
      thermal_closed_loop_model_B.Constant2 =
        thermal_closed_loop_model_cal->Constant2_Value_c;
      thermal_closed_loop_model_B.Constant3 =
        thermal_closed_loop_model_cal->Constant3_Value;
    }

    /* End of RateTransition: '<S1>/Rate Transition1' */

    /* Reshape: '<S29>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_o =
      thermal_closed_loop_model_B.OUTPUT_1_0[1];

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_1' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.OUTPUT_1_1_SimData);
    time_3 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_1_Modes;
    ok = false;
    simulationData->mData->mFoundZcEvents = ok;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    ok = false;
    simulationData->mData->mIsSolverAssertCheck = ok;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_5[0] = 0;
    tmp_4[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_4[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_4[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_4[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_5[1] = 4;
    tmp_4[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_4[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_4[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_4[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_5[2] = 8;
    tmp_4[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_4[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_4[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_4[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_5[3] = 12;
    tmp_4[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_4[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_4[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_4[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_5[4] = 16;
    tmp_4[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_4[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_4[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_4[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_5[5] = 20;
    tmp_4[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_4[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_4[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_4[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_5[6] = 24;
    tmp_4[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_4[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_4[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_4[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_5[7] = 28;
    tmp_4[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_4[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_4[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_4[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_5[8] = 32;
    std::memcpy(&tmp_4[32], &thermal_closed_loop_model_B.STATE_1[0], 369U *
                sizeof(real_T));
    tmp_5[9] = 401;
    simulationData->mData->mInputValues.mN = 401;
    simulationData->mData->mInputValues.mX = &tmp_4[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_5[0];
    simulationData->mData->mOutputs.mN = 2;
    simulationData->mData->mOutputs.mX =
      &thermal_closed_loop_model_B.OUTPUT_1_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_4 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_1_Simulator);
    diag = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_1_DiagMgr);
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (iy != 0) {
      ok = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S47>/OUTPUT_1_1' */

    /* Reshape: '<S26>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_c =
      thermal_closed_loop_model_B.OUTPUT_1_1[1];

    /* Reshape: '<S31>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_nb =
      thermal_closed_loop_model_B.OUTPUT_1_0[4];

    /* Reshape: '<S25>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_e =
      thermal_closed_loop_model_B.OUTPUT_1_0[0];

    /* Reshape: '<S219>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_m =
      thermal_closed_loop_model_B.OUTPUT_1_0[15];

    /* Reshape: '<S220>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_f =
      thermal_closed_loop_model_B.OUTPUT_1_0[20];

    /* Reshape: '<S222>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_h =
      thermal_closed_loop_model_B.OUTPUT_1_0[12];

    /* Reshape: '<S223>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_d =
      thermal_closed_loop_model_B.OUTPUT_1_0[8];

    /* Reshape: '<S224>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_a =
      thermal_closed_loop_model_B.OUTPUT_1_0[21];

    /* Reshape: '<S225>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_dl =
      thermal_closed_loop_model_B.OUTPUT_1_0[22];

    /* Reshape: '<S226>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_g3 =
      thermal_closed_loop_model_B.OUTPUT_1_0[10];

    /* Reshape: '<S230>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_p =
      thermal_closed_loop_model_B.OUTPUT_1_0[17];

    /* Reshape: '<S233>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_l =
      thermal_closed_loop_model_B.OUTPUT_1_0[14];

    /* Reshape: '<S235>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_k =
      thermal_closed_loop_model_B.OUTPUT_1_0[19];

    /* RateTransition: '<S7>/Rate Transition' */
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* RateTransition: '<S7>/Rate Transition' */
      thermal_closed_loop_model_B.RateTransition =
        thermal_closed_loop_model_B.controlBontazTCV.Switch_e;

      /* RateTransition: '<S7>/Rate Transition2' */
      if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
        /* RateTransition: '<S7>/Rate Transition2' */
        thermal_closed_loop_model_B.RateTransition2 =
          thermal_closed_loop_model_B.Sum4_o;
      }

      /* End of RateTransition: '<S7>/Rate Transition2' */
    }

    /* End of RateTransition: '<S7>/Rate Transition' */

    /* Reshape: '<S217>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_gr =
      thermal_closed_loop_model_B.OUTPUT_1_0[13];

    /* Reshape: '<S231>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_mg =
      thermal_closed_loop_model_B.OUTPUT_1_0[18];

    /* Reshape: '<S234>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_lo =
      thermal_closed_loop_model_B.OUTPUT_1_0[16];

    /* Reshape: '<S221>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_ln =
      thermal_closed_loop_model_B.OUTPUT_1_0[7];

    /* Reshape: '<S227>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_ed =
      thermal_closed_loop_model_B.OUTPUT_1_0[9];

    /* Reshape: '<S229>/RESHAPE' */
    thermal_closed_loop_model_B.RESHAPE_js =
      thermal_closed_loop_model_B.OUTPUT_1_0[11];

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.OUTPUT_1_2_SimData);
    time_5 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_5;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_2_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_2_Modes;
    ok = false;
    simulationData->mData->mFoundZcEvents = ok;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    ok = false;
    simulationData->mData->mIsSolverAssertCheck = ok;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_7[0] = 0;
    tmp_6[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_6[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_6[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_6[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_7[1] = 4;
    tmp_6[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_6[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_6[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_6[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_7[2] = 8;
    tmp_6[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_6[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_6[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_6[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_7[3] = 12;
    tmp_6[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_6[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_6[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_6[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_7[4] = 16;
    tmp_6[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_6[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_6[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_6[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_7[5] = 20;
    tmp_6[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_6[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_6[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_6[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_7[6] = 24;
    tmp_6[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_6[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_6[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_6[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_7[7] = 28;
    tmp_6[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_6[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_6[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_6[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_7[8] = 32;
    std::memcpy(&tmp_6[32], &thermal_closed_loop_model_B.STATE_1[0], 369U *
                sizeof(real_T));
    tmp_7[9] = 401;
    simulationData->mData->mInputValues.mN = 401;
    simulationData->mData->mInputValues.mX = &tmp_6[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_7[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */
    simulationData->mData->mOutputs.mX = &thermal_closed_loop_model_B.OUTPUT_1_2;

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_6 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_6;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_2_Simulator);
    diag = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_2_DiagMgr);
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (iy != 0) {
      ok = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.OUTPUT_1_3_SimData);
    time_7 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_7;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_3_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.OUTPUT_1_3_Modes;
    ok = false;
    simulationData->mData->mFoundZcEvents = ok;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    ok = false;
    simulationData->mData->mIsSolverAssertCheck = ok;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_9[0] = 0;
    tmp_8[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_8[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_8[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_8[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_9[1] = 4;
    tmp_8[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_8[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_8[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_8[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_9[2] = 8;
    tmp_8[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_8[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_8[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_8[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_9[3] = 12;
    tmp_8[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_8[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_8[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_8[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_9[4] = 16;
    tmp_8[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_8[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_8[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_8[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_9[5] = 20;
    tmp_8[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_8[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_8[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_8[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_9[6] = 24;
    tmp_8[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_8[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_8[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_8[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_9[7] = 28;
    tmp_8[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_8[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_8[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_8[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_9[8] = 32;
    std::memcpy(&tmp_8[32], &thermal_closed_loop_model_B.STATE_1[0], 369U *
                sizeof(real_T));
    tmp_9[9] = 401;
    simulationData->mData->mInputValues.mN = 401;
    simulationData->mData->mInputValues.mX = &tmp_8[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_9[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
    simulationData->mData->mOutputs.mX = &thermal_closed_loop_model_B.OUTPUT_1_3;

    /* SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_8 = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_8;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_3_Simulator);
    diag = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_3_DiagMgr);
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    iy = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
    if (iy != 0) {
      ok = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }
  }

  if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
    NeslSimulationData *simulationData;
    NeslSimulator *simulator;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[32];
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[9];
    boolean_T tmp;
    if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
      /* Update for UnitDelay: '<S7>/Unit Delay16' */
      thermal_closed_loop_model_DW.UnitDelay16_DSTATE =
        thermal_closed_loop_model_B.FromWs;

      /* Update for UnitDelay: '<S7>/Unit Delay6' */
      thermal_closed_loop_model_DW.UnitDelay6_DSTATE =
        thermal_closed_loop_model_B.RateTransition;

      /* Update for UnitDelay: '<S7>/Unit Delay7' */
      thermal_closed_loop_model_DW.UnitDelay7_DSTATE =
        thermal_closed_loop_model_B.RateLimiter;

      /* Update for UnitDelay: '<S7>/Unit Delay8' */
      thermal_closed_loop_model_DW.UnitDelay8_DSTATE =
        thermal_closed_loop_model_B.RateTransition2;

      /* Update for UnitDelay: '<S7>/Unit Delay9' */
      thermal_closed_loop_model_DW.UnitDelay9_DSTATE =
        thermal_closed_loop_model_B.OUTPUT_1_3;

      /* Update for UnitDelay: '<S1>/Unit Delay10' */
      thermal_closed_loop_model_DW.UnitDelay10_DSTATE =
        thermal_closed_loop_model_B.RateTransition1;

      /* Update for UnitDelay: '<S1>/Unit Delay11' */
      thermal_closed_loop_model_DW.UnitDelay11_DSTATE =
        thermal_closed_loop_model_B.OUTPUT_1_1[0];

      /* Update for UnitDelay: '<S7>/Unit Delay2' */
      thermal_closed_loop_model_DW.UnitDelay2_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_dl;

      /* Update for UnitDelay: '<S7>/Unit Delay1' */
      thermal_closed_loop_model_DW.UnitDelay1_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_f;

      /* Update for UnitDelay: '<S7>/Unit Delay' */
      thermal_closed_loop_model_DW.UnitDelay_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_l;

      /* Update for UnitDelay: '<S7>/Unit Delay5' */
      thermal_closed_loop_model_DW.UnitDelay5_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_a;

      /* Update for UnitDelay: '<S7>/Unit Delay4' */
      thermal_closed_loop_model_DW.UnitDelay4_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_m;

      /* Update for UnitDelay: '<S7>/Unit Delay3' */
      thermal_closed_loop_model_DW.UnitDelay3_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_p;

      /* Update for UnitDelay: '<S7>/Unit Delay14' */
      thermal_closed_loop_model_DW.UnitDelay14_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_h;

      /* Update for UnitDelay: '<S7>/Unit Delay12' */
      thermal_closed_loop_model_DW.UnitDelay12_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_g3;

      /* Update for UnitDelay: '<S7>/Unit Delay13' */
      thermal_closed_loop_model_DW.UnitDelay13_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_d;

      /* Update for UnitDelay: '<S1>/Unit Delay5' */
      thermal_closed_loop_model_DW.UnitDelay5_DSTATE_p =
        thermal_closed_loop_model_B.RESHAPE_g;

      /* Update for UnitDelay: '<S1>/Unit Delay2' */
      thermal_closed_loop_model_DW.UnitDelay2_DSTATE_m =
        thermal_closed_loop_model_B.RESHAPE_n;

      /* Update for UnitDelay: '<S1>/Unit Delay1' */
      thermal_closed_loop_model_DW.UnitDelay1_DSTATE_i =
        thermal_closed_loop_model_B.RESHAPE;

      /* Update for UnitDelay: '<S1>/Unit Delay3' */
      thermal_closed_loop_model_DW.UnitDelay3_DSTATE_d =
        thermal_closed_loop_model_B.RESHAPE_j;

      /* Update for UnitDelay: '<S7>/Unit Delay10' */
      thermal_closed_loop_model_DW.UnitDelay10_DSTATE_f = 0.0;

      /* Update for UnitDelay: '<S7>/Unit Delay11' */
      thermal_closed_loop_model_DW.UnitDelay11_DSTATE_p = 0.0;

      /* Update for UnitDelay: '<S7>/Unit Delay15' */
      thermal_closed_loop_model_DW.UnitDelay15_DSTATE =
        thermal_closed_loop_model_B.RESHAPE_k;
    }

    /* Update for RateLimiter: '<S1>/Rate Limiter1' */
    if (thermal_closed_loop_model_DW.LastMajorTimeA == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeA =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA =
        thermal_closed_loop_model_B.RateLimiter1;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeB == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeB =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB =
        thermal_closed_loop_model_B.RateLimiter1;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeA <
               thermal_closed_loop_model_DW.LastMajorTimeB) {
      thermal_closed_loop_model_DW.LastMajorTimeA =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA =
        thermal_closed_loop_model_B.RateLimiter1;
    } else {
      thermal_closed_loop_model_DW.LastMajorTimeB =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB =
        thermal_closed_loop_model_B.RateLimiter1;
    }

    /* End of Update for RateLimiter: '<S1>/Rate Limiter1' */

    /* Update for RateLimiter: '<S7>/Rate Limiter2' */
    if (thermal_closed_loop_model_DW.LastMajorTimeA_j == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeA_j =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA_c =
        thermal_closed_loop_model_B.RateLimiter2;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeB_k == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeB_k =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB_c =
        thermal_closed_loop_model_B.RateLimiter2;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeA_j <
               thermal_closed_loop_model_DW.LastMajorTimeB_k) {
      thermal_closed_loop_model_DW.LastMajorTimeA_j =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA_c =
        thermal_closed_loop_model_B.RateLimiter2;
    } else {
      thermal_closed_loop_model_DW.LastMajorTimeB_k =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB_c =
        thermal_closed_loop_model_B.RateLimiter2;
    }

    /* End of Update for RateLimiter: '<S7>/Rate Limiter2' */

    /* Update for RateLimiter: '<S7>/Rate Limiter' */
    if (thermal_closed_loop_model_DW.LastMajorTimeA_h == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeA_h =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA_f =
        thermal_closed_loop_model_B.RateLimiter;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeB_a == (rtInf)) {
      thermal_closed_loop_model_DW.LastMajorTimeB_a =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB_h =
        thermal_closed_loop_model_B.RateLimiter;
    } else if (thermal_closed_loop_model_DW.LastMajorTimeA_h <
               thermal_closed_loop_model_DW.LastMajorTimeB_a) {
      thermal_closed_loop_model_DW.LastMajorTimeA_h =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYA_f =
        thermal_closed_loop_model_B.RateLimiter;
    } else {
      thermal_closed_loop_model_DW.LastMajorTimeB_a =
        thermal_closed_loop_model_M->Timing.t[0];
      thermal_closed_loop_model_DW.PrevYB_h =
        thermal_closed_loop_model_B.RateLimiter;
    }

    /* End of Update for RateLimiter: '<S7>/Rate Limiter' */

    /* Update for SimscapeExecutionBlock: '<S47>/STATE_1' */
    simulationData = static_cast<NeslSimulationData *>
      (thermal_closed_loop_model_DW.STATE_1_SimData);
    time = thermal_closed_loop_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 148;
    simulationData->mData->mContStates.mX =
      &thermal_closed_loop_model_X.thermal_closed_loop_modelBasic_[0];
    simulationData->mData->mDiscStates.mN = 115;
    simulationData->mData->mDiscStates.mX =
      &thermal_closed_loop_model_DW.STATE_1_Discrete[0];
    simulationData->mData->mModeVector.mN = 214;
    simulationData->mData->mModeVector.mX =
      &thermal_closed_loop_model_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (thermal_closed_loop_model_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&thermal_closed_loop_model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&thermal_closed_loop_model_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
    tmp_0[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
    tmp_0[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
    tmp_0[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
    tmp_0[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
    tmp_0[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
    tmp_0[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
    tmp_0[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
    tmp_0[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
    tmp_0[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
    tmp_0[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
    tmp_0[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
    tmp_0[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
    tmp_0[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
    tmp_0[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
    tmp_0[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
    tmp_0[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
    tmp_0[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
    tmp_0[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
    tmp_0[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
    tmp_0[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
    tmp_0[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
    tmp_0[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
    tmp_0[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
    tmp_0[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
    tmp_1[8] = 32;
    simulationData->mData->mInputValues.mN = 32;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.STATE_1_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method(simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S47>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(thermal_closed_loop_model_M)) {
    rt_ertODEUpdateContinuousStates(&thermal_closed_loop_model_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++thermal_closed_loop_model_M->Timing.clockTick0)) {
      ++thermal_closed_loop_model_M->Timing.clockTickH0;
    }

    thermal_closed_loop_model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&thermal_closed_loop_model_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    thermal_closed_loop_model_M->Timing.clockTick1++;
    if (!thermal_closed_loop_model_M->Timing.clockTick1) {
      thermal_closed_loop_model_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void thermal_closed_loop_model_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_thermal_closed_loop_mode_T *_rtXdot;
  char *msg;
  real_T tmp_0[32];
  real_T time;
  int_T tmp_1[9];
  int_T is;
  boolean_T tmp;
  _rtXdot = ((XDot_thermal_closed_loop_mode_T *)
             thermal_closed_loop_model_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->tcv_opening = 0.0;
  _rtXdot->tcv_opening += thermal_closed_loop_model_cal->TransferFcn1_A *
    thermal_closed_loop_model_X.tcv_opening;
  _rtXdot->tcv_opening += thermal_closed_loop_model_B.RateTransition1;

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn2' */
  _rtXdot->tcv_opening_o = 0.0;
  _rtXdot->tcv_opening_o += thermal_closed_loop_model_cal->TransferFcn2_A *
    thermal_closed_loop_model_X.tcv_opening_o;
  _rtXdot->tcv_opening_o += thermal_closed_loop_model_B.RateTransition2;

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn' */
  _rtXdot->tcv_opening_e = 0.0;
  _rtXdot->tcv_opening_e += thermal_closed_loop_model_cal->TransferFcn_A *
    thermal_closed_loop_model_X.tcv_opening_e;
  _rtXdot->tcv_opening_e += thermal_closed_loop_model_B.RateTransition;

  /* Derivatives for SimscapeExecutionBlock: '<S47>/STATE_1' */
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.STATE_1_SimData);
  time = thermal_closed_loop_model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 148;
  simulationData->mData->mContStates.mX =
    &thermal_closed_loop_model_X.thermal_closed_loop_modelBasic_[0];
  simulationData->mData->mDiscStates.mN = 115;
  simulationData->mData->mDiscStates.mX =
    &thermal_closed_loop_model_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 214;
  simulationData->mData->mModeVector.mX =
    &thermal_closed_loop_model_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (thermal_closed_loop_model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&thermal_closed_loop_model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&thermal_closed_loop_model_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = thermal_closed_loop_model_B.INPUT_1_1_1[0];
  tmp_0[1] = thermal_closed_loop_model_B.INPUT_1_1_1[1];
  tmp_0[2] = thermal_closed_loop_model_B.INPUT_1_1_1[2];
  tmp_0[3] = thermal_closed_loop_model_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = thermal_closed_loop_model_B.INPUT_2_1_1[0];
  tmp_0[5] = thermal_closed_loop_model_B.INPUT_2_1_1[1];
  tmp_0[6] = thermal_closed_loop_model_B.INPUT_2_1_1[2];
  tmp_0[7] = thermal_closed_loop_model_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = thermal_closed_loop_model_B.INPUT_3_1_1[0];
  tmp_0[9] = thermal_closed_loop_model_B.INPUT_3_1_1[1];
  tmp_0[10] = thermal_closed_loop_model_B.INPUT_3_1_1[2];
  tmp_0[11] = thermal_closed_loop_model_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = thermal_closed_loop_model_B.INPUT_4_1_1[0];
  tmp_0[13] = thermal_closed_loop_model_B.INPUT_4_1_1[1];
  tmp_0[14] = thermal_closed_loop_model_B.INPUT_4_1_1[2];
  tmp_0[15] = thermal_closed_loop_model_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = thermal_closed_loop_model_B.INPUT_5_1_1[0];
  tmp_0[17] = thermal_closed_loop_model_B.INPUT_5_1_1[1];
  tmp_0[18] = thermal_closed_loop_model_B.INPUT_5_1_1[2];
  tmp_0[19] = thermal_closed_loop_model_B.INPUT_5_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = thermal_closed_loop_model_B.INPUT_6_1_1[0];
  tmp_0[21] = thermal_closed_loop_model_B.INPUT_6_1_1[1];
  tmp_0[22] = thermal_closed_loop_model_B.INPUT_6_1_1[2];
  tmp_0[23] = thermal_closed_loop_model_B.INPUT_6_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = thermal_closed_loop_model_B.INPUT_8_1_1[0];
  tmp_0[25] = thermal_closed_loop_model_B.INPUT_8_1_1[1];
  tmp_0[26] = thermal_closed_loop_model_B.INPUT_8_1_1[2];
  tmp_0[27] = thermal_closed_loop_model_B.INPUT_8_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = thermal_closed_loop_model_B.INPUT_7_1_1[0];
  tmp_0[29] = thermal_closed_loop_model_B.INPUT_7_1_1[1];
  tmp_0[30] = thermal_closed_loop_model_B.INPUT_7_1_1[2];
  tmp_0[31] = thermal_closed_loop_model_B.INPUT_7_1_1[3];
  tmp_1[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 148;
  simulationData->mData->mDx.mX = &_rtXdot->thermal_closed_loop_modelBasic_[0];
  simulator = static_cast<NeslSimulator *>
    (thermal_closed_loop_model_DW.STATE_1_Simulator);
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  is = ne_simulator_method(simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (is != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(thermal_closed_loop_model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S47>/STATE_1' */
}

/* Model step function for TID2 */
void thermal_closed_loop_model_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T x;
  real_T x_idx_0;
  real_T x_idx_1;
  real_T x_idx_2;
  int32_T TmpRTBAtSumInport1_Buf_tmp;

  /* RandomNumber: '<S186>/White Noise' */
  thermal_closed_loop_model_B.WhiteNoise =
    thermal_closed_loop_model_DW.NextOutput;

  /* Gain: '<S186>/Output' */
  x_idx_0 = thermal_closed_loop_model_cal->BandLimitedWhiteNoise_Cov[0];
  x_idx_1 = thermal_closed_loop_model_cal->BandLimitedWhiteNoise_Cov[1];
  x_idx_2 = thermal_closed_loop_model_cal->BandLimitedWhiteNoise_Cov[2];
  x = x_idx_0;
  x = std::sqrt(x);
  x_idx_0 = x;
  x = x_idx_1;
  x = std::sqrt(x);
  x_idx_1 = x;
  x = x_idx_2;
  x = std::sqrt(x);
  x_idx_2 = x;
  x_idx_0 /= 0.31622776601683794;

  /* Gain: '<S186>/Output' */
  x_idx_0 *= thermal_closed_loop_model_B.WhiteNoise;
  thermal_closed_loop_model_B.Output[0] = x_idx_0;

  /* ManualSwitch: '<S4>/Manual Switch' */
  if (thermal_closed_loop_model_cal->ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/Manual Switch' */
    thermal_closed_loop_model_B.ManualSwitch[0] = x_idx_0;
  } else {
    /* ManualSwitch: '<S4>/Manual Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    thermal_closed_loop_model_B.ManualSwitch[0] =
      thermal_closed_loop_model_cal->Constant_Value_h[0];
  }

  /* Gain: '<S186>/Output' */
  x_idx_0 = x_idx_1;
  x_idx_0 /= 0.31622776601683794;

  /* Gain: '<S186>/Output' */
  x_idx_0 *= thermal_closed_loop_model_B.WhiteNoise;
  thermal_closed_loop_model_B.Output[1] = x_idx_0;

  /* ManualSwitch: '<S4>/Manual Switch' */
  if (thermal_closed_loop_model_cal->ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/Manual Switch' */
    thermal_closed_loop_model_B.ManualSwitch[1] = x_idx_0;
  } else {
    /* ManualSwitch: '<S4>/Manual Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    thermal_closed_loop_model_B.ManualSwitch[1] =
      thermal_closed_loop_model_cal->Constant_Value_h[1];
  }

  /* Gain: '<S186>/Output' */
  x_idx_0 = x_idx_2;
  x_idx_0 /= 0.31622776601683794;

  /* Gain: '<S186>/Output' */
  x_idx_0 *= thermal_closed_loop_model_B.WhiteNoise;
  thermal_closed_loop_model_B.Output[2] = x_idx_0;

  /* ManualSwitch: '<S4>/Manual Switch' */
  if (thermal_closed_loop_model_cal->ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/Manual Switch' */
    thermal_closed_loop_model_B.ManualSwitch[2] = x_idx_0;
  } else {
    /* ManualSwitch: '<S4>/Manual Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    thermal_closed_loop_model_B.ManualSwitch[2] =
      thermal_closed_loop_model_cal->Constant_Value_h[2];
  }

  /* RateTransition generated from: '<S4>/Sum' */
  thermal_closed_loop_model_DW.TmpRTBAtSumInport1_WrBufIdx = static_cast<int8_T>
    (thermal_closed_loop_model_DW.TmpRTBAtSumInport1_WrBufIdx == 0);
  TmpRTBAtSumInport1_Buf_tmp =
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_WrBufIdx * 3;
  thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[TmpRTBAtSumInport1_Buf_tmp]
    = thermal_closed_loop_model_B.ManualSwitch[0];
  thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[TmpRTBAtSumInport1_Buf_tmp
    + 1] = thermal_closed_loop_model_B.ManualSwitch[1];
  thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[TmpRTBAtSumInport1_Buf_tmp
    + 2] = thermal_closed_loop_model_B.ManualSwitch[2];

  /* Update for RandomNumber: '<S186>/White Noise' */
  thermal_closed_loop_model_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&thermal_closed_loop_model_DW.RandSeed) *
    thermal_closed_loop_model_cal->WhiteNoise_StdDev +
    thermal_closed_loop_model_cal->WhiteNoise_Mean;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  thermal_closed_loop_model_M->Timing.clockTick2++;
  if (!thermal_closed_loop_model_M->Timing.clockTick2) {
    thermal_closed_loop_model_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void thermal_closed_loop_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  thermal_closed_loop_model_P.Integrator_UpperSat = rtInf;
  thermal_closed_loop_model_P.Integrator_LowerSat = rtMinusInf;
  thermal_closed_loop_model_P.Saturation_UpperSat = rtInf;
  thermal_closed_loop_model_P.Saturation_LowerSat = rtMinusInf;
  thermal_closed_loop_model_P.Saturation_UpperSat_g = rtInf;
  thermal_closed_loop_model_P.Saturation_UpperSat_d = rtInf;
  thermal_closed_loop_model_P.controlBontazTCV.Integrator_UpperSat = rtInf;
  thermal_closed_loop_model_P.controlBontazTCV.Integrator_LowerSat = rtMinusInf;
  thermal_closed_loop_model_P.controlBontazTCV.Saturation_UpperSat = rtInf;
  thermal_closed_loop_model_P.controlBontazTCV.Saturation_LowerSat = rtMinusInf;

  /* Set task counter limit used by the static main program */
  (thermal_closed_loop_model_M)->Timing.TaskCounters.cLimit[0] = 1;
  (thermal_closed_loop_model_M)->Timing.TaskCounters.cLimit[1] = 1;
  (thermal_closed_loop_model_M)->Timing.TaskCounters.cLimit[2] = 2;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&thermal_closed_loop_model_M->solverInfo,
                          &thermal_closed_loop_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&thermal_closed_loop_model_M->solverInfo, &rtmGetTPtr
                (thermal_closed_loop_model_M));
    rtsiSetStepSizePtr(&thermal_closed_loop_model_M->solverInfo,
                       &thermal_closed_loop_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&thermal_closed_loop_model_M->solverInfo,
                 &thermal_closed_loop_model_M->derivs);
    rtsiSetContStatesPtr(&thermal_closed_loop_model_M->solverInfo, (real_T **)
                         &thermal_closed_loop_model_M->contStates);
    rtsiSetNumContStatesPtr(&thermal_closed_loop_model_M->solverInfo,
      &thermal_closed_loop_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&thermal_closed_loop_model_M->solverInfo,
      &thermal_closed_loop_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&thermal_closed_loop_model_M->solverInfo,
      &thermal_closed_loop_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&thermal_closed_loop_model_M->solverInfo,
      &thermal_closed_loop_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&thermal_closed_loop_model_M->solverInfo,
                          (&rtmGetErrorStatus(thermal_closed_loop_model_M)));
    rtsiSetSolverMassMatrixIr(&thermal_closed_loop_model_M->solverInfo,
      thermal_closed_loop__MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&thermal_closed_loop_model_M->solverInfo,
      thermal_closed_loop__MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&thermal_closed_loop_model_M->solverInfo,
      thermal_closed_loop__MassMatrix.pr);
    rtsiSetRTModelPtr(&thermal_closed_loop_model_M->solverInfo,
                      thermal_closed_loop_model_M);
  }

  rtsiSetSimTimeStep(&thermal_closed_loop_model_M->solverInfo, MAJOR_TIME_STEP);
  thermal_closed_loop_model_M->intgData.x0 = thermal_closed_loop_model_M->odeX0;
  thermal_closed_loop_model_M->intgData.f0 = thermal_closed_loop_model_M->odeF0;
  thermal_closed_loop_model_M->intgData.x1start =
    thermal_closed_loop_model_M->odeX1START;
  thermal_closed_loop_model_M->intgData.f1 = thermal_closed_loop_model_M->odeF1;
  thermal_closed_loop_model_M->intgData.Delta =
    thermal_closed_loop_model_M->odeDELTA;
  thermal_closed_loop_model_M->intgData.E = thermal_closed_loop_model_M->odeE;
  thermal_closed_loop_model_M->intgData.fac =
    thermal_closed_loop_model_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = thermal_closed_loop_model_M->intgData.fac;
    for (i = 0; i < static_cast<int_T>(sizeof
          (thermal_closed_loop_model_M->odeFAC)/sizeof(real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  thermal_closed_loop_model_M->intgData.DFDX =
    thermal_closed_loop_model_M->odeDFDX;
  thermal_closed_loop_model_M->intgData.W = thermal_closed_loop_model_M->odeW;
  thermal_closed_loop_model_M->intgData.pivots =
    thermal_closed_loop_model_M->odePIVOTS;
  thermal_closed_loop_model_M->intgData.xtmp =
    thermal_closed_loop_model_M->odeXTMP;
  thermal_closed_loop_model_M->intgData.ztmp =
    thermal_closed_loop_model_M->odeZTMP;
  thermal_closed_loop_model_M->intgData.M =
    thermal_closed_loop_model_M->odeMASSMATRIX_M;
  thermal_closed_loop_model_M->intgData.M1 =
    thermal_closed_loop_model_M->odeMASSMATRIX_M1;
  thermal_closed_loop_model_M->intgData.xdot =
    thermal_closed_loop_model_M->odeXDOT;
  thermal_closed_loop_model_M->intgData.Edot =
    thermal_closed_loop_model_M->odeEDOT;
  thermal_closed_loop_model_M->intgData.fminusMxdot =
    thermal_closed_loop_model_M->odeFMXDOT;
  thermal_closed_loop_model_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&thermal_closed_loop_model_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&thermal_closed_loop_model_M->solverInfo,
    1);
  thermal_closed_loop_model_M->contStates = ((X_thermal_closed_loop_model_T *)
    &thermal_closed_loop_model_X);
  thermal_closed_loop_model_M->massMatrixType = ((ssMatrixType)3);
  thermal_closed_loop_model_M->massMatrixNzMax = (34);
  thermal_closed_loop_model_M->massMatrixIr =
    (thermal_closed_loop__MassMatrix.ir);
  thermal_closed_loop_model_M->massMatrixJc =
    (thermal_closed_loop__MassMatrix.jc);
  thermal_closed_loop_model_M->massMatrixPr =
    (thermal_closed_loop__MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&thermal_closed_loop_model_M->solverInfo,
    (ssMatrixType)3);
  rtsiSetSolverMassMatrixNzMax(&thermal_closed_loop_model_M->solverInfo, 34);
  rtsiSetSolverData(&thermal_closed_loop_model_M->solverInfo, static_cast<void *>
                    (&thermal_closed_loop_model_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&thermal_closed_loop_model_M->solverInfo,
    false);
  rtsiSetSolverName(&thermal_closed_loop_model_M->solverInfo,"ode14x");
  rtmSetTPtr(thermal_closed_loop_model_M,
             &thermal_closed_loop_model_M->Timing.tArray[0]);
  thermal_closed_loop_model_M->Timing.stepSize0 = 0.05;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&thermal_closed_loop_model_B)), 0,
                     sizeof(B_thermal_closed_loop_model_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&thermal_closed_loop_model_X), 0,
                       sizeof(X_thermal_closed_loop_model_T));
  }

  /* global mass matrix */
  {
    int_T *ir = thermal_closed_loop__MassMatrix.ir;
    int_T *jc = thermal_closed_loop__MassMatrix.jc;
    real_T *pr = thermal_closed_loop__MassMatrix.pr;
    (void) std::memset(static_cast<void *>(ir), 0,
                       34*sizeof(int_T));
    (void) std::memset(static_cast<void *>(jc), 0,
                       (151+1)*sizeof(int_T));
    (void) std::memset(static_cast<void *>(pr), 0,
                       34*sizeof(real_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&thermal_closed_loop_model_DW), 0,
                     sizeof(DW_thermal_closed_loop_model_T));

  /* Root-level init GlobalMassMatrixPr offset */
  {
    thermal_closed_loop_model_DW.STATE_1_MASS_MATRIX_PR = 3;/* '<S47>/STATE_1' */
  }

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeModelParameters modelParameters_2;
    NeModelParameters modelParameters_3;
    NeslRtpManager *manager;
    NeslSimulationData *tmp;
    NeslSimulator *simulator;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0;
    int32_T tmp_1;
    boolean_T zcDisabled;

    /* Start for FromWorkspace: '<S187>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 180.0, 180.0, 190.0, 190.0, 250.0,
        250.0, 260.0, 260.0, 320.0, 320.0, 330.0, 330.0, 390.0, 390.0, 400.0,
        400.0, 460.0, 460.0, 470.0, 470.0, 530.0, 530.0, 540.0, 540.0, 600.0 } ;

      static real_T pDataValues0[] = { 100.0, 100.0, 100.0, 200.0, 200.0, 200.0,
        200.0, 300.0, 300.0, 300.0, 300.0, 400.0, 400.0, 400.0, 400.0, 300.0,
        300.0, 300.0, 300.0, 200.0, 200.0, 200.0, 200.0, 100.0, 100.0, 100.0 } ;

      thermal_closed_loop_model_DW.FromWs_PWORK.TimePtr = static_cast<void *>
        (pTimeValues0);
      thermal_closed_loop_model_DW.FromWs_PWORK.DataPtr = static_cast<void *>
        (pDataValues0);
      thermal_closed_loop_model_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for SimscapeRtp: '<S44>/RTP_1' */
    manager = nesl_lease_rtp_manager(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      0);
    zcDisabled = pointer_is_null(manager);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      manager = nesl_lease_rtp_manager(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        0);
    }

    thermal_closed_loop_model_DW.RTP_1_RtpManager = (void *)manager;
    thermal_closed_loop_model_DW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S44>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S47>/STATE_1' */
    simulator = nesl_lease_simulator(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      0, 0);
    thermal_closed_loop_model_DW.STATE_1_Simulator = (void *)simulator;
    zcDisabled = pointer_is_null(thermal_closed_loop_model_DW.STATE_1_Simulator);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      simulator = nesl_lease_simulator(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        0, 0);
      thermal_closed_loop_model_DW.STATE_1_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    thermal_closed_loop_model_DW.STATE_1_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    thermal_closed_loop_model_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.41481876E+8;
    modelParameters.mUseModelRefSolver = false;
    tmp_0 = 0.001;
    modelParameters.mSolverTolerance = tmp_0;
    tmp_0 = 0.05;
    modelParameters.mFixedStepSize = tmp_0;
    zcDisabled = false;
    modelParameters.mVariableStepSolver = zcDisabled;
    zcDisabled = false;
    modelParameters.mIsUsingODEN = zcDisabled;
    modelParameters.mZcDisabled = true;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.STATE_1_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters,
      diagnosticManager);
    if (tmp_1 != 0) {
      zcDisabled = error_buffer_is_empty(rtmGetErrorStatus
        (thermal_closed_loop_model_M));
      if (zcDisabled) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S47>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_0' */
    simulator = nesl_lease_simulator(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      1, 0);
    thermal_closed_loop_model_DW.OUTPUT_1_0_Simulator = (void *)simulator;
    zcDisabled = pointer_is_null
      (thermal_closed_loop_model_DW.OUTPUT_1_0_Simulator);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      simulator = nesl_lease_simulator(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        1, 0);
      thermal_closed_loop_model_DW.OUTPUT_1_0_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    thermal_closed_loop_model_DW.OUTPUT_1_0_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    thermal_closed_loop_model_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.41481876E+8;
    modelParameters_0.mUseModelRefSolver = false;
    tmp_0 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_0;
    tmp_0 = 0.05;
    modelParameters_0.mFixedStepSize = tmp_0;
    zcDisabled = false;
    modelParameters_0.mVariableStepSolver = zcDisabled;
    zcDisabled = false;
    modelParameters_0.mIsUsingODEN = zcDisabled;
    modelParameters_0.mZcDisabled = true;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_0_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_0_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_1 != 0) {
      zcDisabled = error_buffer_is_empty(rtmGetErrorStatus
        (thermal_closed_loop_model_M));
      if (zcDisabled) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_0' */

    /* Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_1' */
    simulator = nesl_lease_simulator(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      1, 1);
    thermal_closed_loop_model_DW.OUTPUT_1_1_Simulator = (void *)simulator;
    zcDisabled = pointer_is_null
      (thermal_closed_loop_model_DW.OUTPUT_1_1_Simulator);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      simulator = nesl_lease_simulator(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        1, 1);
      thermal_closed_loop_model_DW.OUTPUT_1_1_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    thermal_closed_loop_model_DW.OUTPUT_1_1_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    thermal_closed_loop_model_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_1.mRTWModifiedTimeStamp = 6.41481876E+8;
    modelParameters_1.mUseModelRefSolver = false;
    tmp_0 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_0;
    tmp_0 = 0.05;
    modelParameters_1.mFixedStepSize = tmp_0;
    zcDisabled = false;
    modelParameters_1.mVariableStepSolver = zcDisabled;
    zcDisabled = false;
    modelParameters_1.mIsUsingODEN = zcDisabled;
    modelParameters_1.mZcDisabled = true;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_1_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_1_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters_1,
      diagnosticManager);
    if (tmp_1 != 0) {
      zcDisabled = error_buffer_is_empty(rtmGetErrorStatus
        (thermal_closed_loop_model_M));
      if (zcDisabled) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_1' */

    /* Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */
    simulator = nesl_lease_simulator(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      1, 2);
    thermal_closed_loop_model_DW.OUTPUT_1_2_Simulator = (void *)simulator;
    zcDisabled = pointer_is_null
      (thermal_closed_loop_model_DW.OUTPUT_1_2_Simulator);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      simulator = nesl_lease_simulator(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        1, 2);
      thermal_closed_loop_model_DW.OUTPUT_1_2_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    thermal_closed_loop_model_DW.OUTPUT_1_2_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    thermal_closed_loop_model_DW.OUTPUT_1_2_DiagMgr = (void *)diagnosticManager;
    modelParameters_2.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_2.mSolverAbsTol = 0.001;
    modelParameters_2.mSolverRelTol = 0.001;
    modelParameters_2.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_2.mStartTime = 0.0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mLinTrimCompile = false;
    modelParameters_2.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_2.mRTWModifiedTimeStamp = 6.41481876E+8;
    modelParameters_2.mUseModelRefSolver = false;
    tmp_0 = 0.001;
    modelParameters_2.mSolverTolerance = tmp_0;
    tmp_0 = 0.05;
    modelParameters_2.mFixedStepSize = tmp_0;
    zcDisabled = false;
    modelParameters_2.mVariableStepSolver = zcDisabled;
    zcDisabled = false;
    modelParameters_2.mIsUsingODEN = zcDisabled;
    modelParameters_2.mZcDisabled = true;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_2_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_2_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters_2,
      diagnosticManager);
    if (tmp_1 != 0) {
      zcDisabled = error_buffer_is_empty(rtmGetErrorStatus
        (thermal_closed_loop_model_M));
      if (zcDisabled) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */

    /* Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
    simulator = nesl_lease_simulator(
      "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
      1, 3);
    thermal_closed_loop_model_DW.OUTPUT_1_3_Simulator = (void *)simulator;
    zcDisabled = pointer_is_null
      (thermal_closed_loop_model_DW.OUTPUT_1_3_Simulator);
    if (zcDisabled) {
      thermal_closed_loop_model_98402bd5_1_gateway();
      simulator = nesl_lease_simulator(
        "thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1",
        1, 3);
      thermal_closed_loop_model_DW.OUTPUT_1_3_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    thermal_closed_loop_model_DW.OUTPUT_1_3_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    thermal_closed_loop_model_DW.OUTPUT_1_3_DiagMgr = (void *)diagnosticManager;
    modelParameters_3.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_3.mSolverAbsTol = 0.001;
    modelParameters_3.mSolverRelTol = 0.001;
    modelParameters_3.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_3.mStartTime = 0.0;
    modelParameters_3.mLoadInitialState = false;
    modelParameters_3.mUseSimState = false;
    modelParameters_3.mLinTrimCompile = false;
    modelParameters_3.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_3.mRTWModifiedTimeStamp = 6.41481876E+8;
    modelParameters_3.mUseModelRefSolver = false;
    tmp_0 = 0.001;
    modelParameters_3.mSolverTolerance = tmp_0;
    tmp_0 = 0.05;
    modelParameters_3.mFixedStepSize = tmp_0;
    zcDisabled = false;
    modelParameters_3.mVariableStepSolver = zcDisabled;
    zcDisabled = false;
    modelParameters_3.mIsUsingODEN = zcDisabled;
    modelParameters_3.mZcDisabled = true;
    simulator = static_cast<NeslSimulator *>
      (thermal_closed_loop_model_DW.OUTPUT_1_3_Simulator);
    diagnosticManager = static_cast<NeuDiagnosticManager *>
      (thermal_closed_loop_model_DW.OUTPUT_1_3_DiagMgr);
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters_3,
      diagnosticManager);
    if (tmp_1 != 0) {
      zcDisabled = error_buffer_is_empty(rtmGetErrorStatus
        (thermal_closed_loop_model_M));
      if (zcDisabled) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(thermal_closed_loop_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
  }

  thermal_closed_loop_mod_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
  thermal_closed_loop_mod_PrevZCX.UD_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    real_T tmp_1;
    real_T tmp_2;
    int32_T t;
    int_T is;
    uint32_T tseed;
    boolean_T tmp;
    boolean_T tmp_0;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay5' */
    tmp_2 = *get_coolant_initial_pressure();

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
    tmp_1 = *get_coolant_initial_temperature();

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay16' */
    thermal_closed_loop_model_DW.UnitDelay16_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay16_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay6' */
    thermal_closed_loop_model_DW.UnitDelay6_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay6_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay7' */
    thermal_closed_loop_model_DW.UnitDelay7_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay7_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay8' */
    thermal_closed_loop_model_DW.UnitDelay8_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay8_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay9' */
    thermal_closed_loop_model_DW.UnitDelay9_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay9_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay10' */
    thermal_closed_loop_model_DW.UnitDelay10_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay10_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay11' */
    thermal_closed_loop_model_DW.UnitDelay11_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay11_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay2' */
    thermal_closed_loop_model_DW.UnitDelay2_DSTATE = tmp_1;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay1' */
    thermal_closed_loop_model_DW.UnitDelay1_DSTATE = tmp_1;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
    thermal_closed_loop_model_DW.UnitDelay_DSTATE = tmp_1;

    /* InitializeConditions for RateTransition generated from: '<S4>/Sum' */
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[0] =
      thermal_closed_loop_model_cal->TmpRTBAtSumInport1_InitialCondi;
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[1] =
      thermal_closed_loop_model_cal->TmpRTBAtSumInport1_InitialCondi;
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_Buf[2] =
      thermal_closed_loop_model_cal->TmpRTBAtSumInport1_InitialCondi;
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_WrBufIdx = 0;
    thermal_closed_loop_model_DW.TmpRTBAtSumInport1_RdBufIdx = 1;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay5' */
    thermal_closed_loop_model_DW.UnitDelay5_DSTATE = tmp_2;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay4' */
    thermal_closed_loop_model_DW.UnitDelay4_DSTATE = tmp_2;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay3' */
    thermal_closed_loop_model_DW.UnitDelay3_DSTATE = tmp_2;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay14' */
    thermal_closed_loop_model_DW.UnitDelay14_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay14_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay12' */
    thermal_closed_loop_model_DW.UnitDelay12_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay12_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay13' */
    thermal_closed_loop_model_DW.UnitDelay13_DSTATE =
      thermal_closed_loop_model_cal->UnitDelay13_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay5' */
    thermal_closed_loop_model_DW.UnitDelay5_DSTATE_p = tmp_2;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    thermal_closed_loop_model_DW.UnitDelay2_DSTATE_m = tmp_1;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
    thermal_closed_loop_model_DW.UnitDelay1_DSTATE_i =
      thermal_closed_loop_model_cal->UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay3' */
    thermal_closed_loop_model_DW.UnitDelay3_DSTATE_d =
      thermal_closed_loop_model_cal->UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay10' */
    thermal_closed_loop_model_DW.UnitDelay10_DSTATE_f =
      thermal_closed_loop_model_cal->UnitDelay10_InitialCondition_f;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay11' */
    thermal_closed_loop_model_DW.UnitDelay11_DSTATE_p =
      thermal_closed_loop_model_cal->UnitDelay11_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay15' */
    thermal_closed_loop_model_DW.UnitDelay15_DSTATE = tmp_2;

    /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
    thermal_closed_loop_model_X.tcv_opening = 0.0;

    /* InitializeConditions for RateLimiter: '<S1>/Rate Limiter1' */
    thermal_closed_loop_model_DW.LastMajorTimeA = (rtInf);
    thermal_closed_loop_model_DW.LastMajorTimeB = (rtInf);

    /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn2' */
    thermal_closed_loop_model_X.tcv_opening_o = 0.0;

    /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter2' */
    thermal_closed_loop_model_DW.LastMajorTimeA_j = (rtInf);
    thermal_closed_loop_model_DW.LastMajorTimeB_k = (rtInf);

    /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn' */
    thermal_closed_loop_model_X.tcv_opening_e = 0.0;

    /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter' */
    thermal_closed_loop_model_DW.LastMajorTimeA_h = (rtInf);
    thermal_closed_loop_model_DW.LastMajorTimeB_a = (rtInf);

    /* InitializeConditions for SimscapeExecutionBlock: '<S47>/STATE_1' */
    tmp = false;
    tmp_0 = false;
    if (tmp_0 || tmp) {
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "daessc");
      tmp = (is == 0);
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "ode14x");
      tmp = (is == 0) | tmp;
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "ode15s");
      tmp = (is == 0) | tmp;
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "ode1be");
      tmp = (is == 0) | tmp;
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "ode23t");
      tmp = (is == 0) | tmp;
      is = strcmp(rtsiGetSolverName(&thermal_closed_loop_model_M->solverInfo),
                  "odeN");
      tmp = (is == 0) | tmp;
      if (!tmp) {
        rtmSetErrorStatus(thermal_closed_loop_model_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S47>/STATE_1' */

    /* InitializeConditions for RandomNumber: '<S186>/White Noise' */
    tmp_2 = std::floor(thermal_closed_loop_model_cal->BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp_2) || rtIsInf(tmp_2)) {
      tmp_2 = 0.0;
    } else {
      tmp_2 = std::fmod(tmp_2, 4.294967296E+9);
    }

    tseed = tmp_2 < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(
      static_cast<uint32_T>(-tmp_2))) : static_cast<uint32_T>(tmp_2);
    is = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(is) << 16U)) +
               static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(is);
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    thermal_closed_loop_model_DW.RandSeed = tseed;
    thermal_closed_loop_model_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&thermal_closed_loop_model_DW.RandSeed) *
      thermal_closed_loop_model_cal->WhiteNoise_StdDev +
      thermal_closed_loop_model_cal->WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S186>/White Noise' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/BasicThermalSubsystemControl' */
    BasicThermalSubsystemC_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/BasicThermalSubsystemControl' */

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[34] = { 0, 1, 2, 10, 9, 8, 11, 3, 12, 13,
        12, 13, 6, 4, 5, 14, 15, 14, 15, 18, 16, 17, 16, 17, 19, 7, 20, 21, 20,
        21, 22, 23, 22, 23 };

      static int_T modelMassMatrixJc[152] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12,
        13, 14, 15, 17, 19, 20, 22, 24, 25, 26, 28, 30, 32, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34,
        34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34 };

      static real_T modelMassMatrixPr[34] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

      (void) std::memcpy(thermal_closed_loop__MassMatrix.ir, modelMassMatrixIr,
                         34*sizeof(int_T));
      (void) std::memcpy(thermal_closed_loop__MassMatrix.jc, modelMassMatrixJc,
                         152*sizeof(int_T));
      (void) std::memcpy(thermal_closed_loop__MassMatrix.pr, modelMassMatrixPr,
                         34*sizeof(real_T));
    }
  }

  /* Enable for Atomic SubSystem: '<Root>/BasicThermalSubsystemControl' */
  BasicThermalSubsyste_Enable();

  /* End of Enable for SubSystem: '<Root>/BasicThermalSubsystemControl' */
}

/* Model terminate function */
void thermal_closed_loop_model_terminate(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;

  /* Terminate for SimscapeExecutionBlock: '<S47>/STATE_1' */
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.STATE_1_DiagMgr);
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.STATE_1_SimData);
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S47>/OUTPUT_1_0' */
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.OUTPUT_1_0_DiagMgr);
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.OUTPUT_1_0_SimData);
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S47>/OUTPUT_1_1' */
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.OUTPUT_1_1_DiagMgr);
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.OUTPUT_1_1_SimData);
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S47>/OUTPUT_1_2' */
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.OUTPUT_1_2_DiagMgr);
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.OUTPUT_1_2_SimData);
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S47>/OUTPUT_1_3' */
  diagnosticManager = static_cast<NeuDiagnosticManager *>
    (thermal_closed_loop_model_DW.OUTPUT_1_3_DiagMgr);
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = static_cast<NeslSimulationData *>
    (thermal_closed_loop_model_DW.OUTPUT_1_3_SimData);
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration_1");
  nesl_destroy_registry();
}
