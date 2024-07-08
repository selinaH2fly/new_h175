/*
 * Code generation for system system '<S3>/controlBontazTCV'
 * For more details, see corresponding source file controlBontazTCV.c
 *
 */

#ifndef RTW_HEADER_controlBontazTCV_h_
#define RTW_HEADER_controlBontazTCV_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw_rtp.h"
#include "thermal_closed_loop_model_98402bd5_1_gateway.h"
#include "nesl_rtw.h"
#include "controlBontazTCV_cal.h"
#include "thermal_closed_loop_model_types.h"

/* Block signals for system '<S3>/controlBontazTCV' */
struct B_controlBontazTCV_thermal_cl_T {
  real_T Probe[2];                     /* '<S108>/Probe' */
  real_T Sum1;                         /* '<S108>/Sum1' */
  real_T e_STCL_T_degC;                /* '<S49>/Sum' */
  real_T K;                            /* '<S54>/K' */
  real_T Integrator;                   /* '<S114>/Integrator' */
  real_T Saturation;                   /* '<S114>/Saturation' */
  real_T ProportionalGain;             /* '<S96>/Proportional Gain' */
  real_T Integrator_f;                 /* '<S91>/Integrator' */
  real_T DerivativeGain;               /* '<S83>/Derivative Gain' */
  real_T Tsamp;                        /* '<S86>/Tsamp' */
  real_T UD;                           /* '<S84>/UD' */
  real_T Diff;                         /* '<S84>/Diff' */
  real_T Sum;                          /* '<S100>/Sum' */
  real_T DeadZone;                     /* '<S82>/DeadZone' */
  real_T IntegralGain;                 /* '<S88>/Integral Gain' */
  real_T Switch;                       /* '<S80>/Switch' */
  real_T Saturation_g;                 /* '<S98>/Saturation' */
  real_T Max;                          /* '<S108>/Max' */
  real_T AvoidDividebyZero;            /* '<S108>/Avoid Divide by Zero' */
  real_T Sum1_n;                       /* '<S54>/Sum1' */
  real_T uT;                           /* '<S54>/1//T' */
  real_T Switch_e;                     /* '<S55>/Switch' */
  real_T uDLookupTable;                /* '<S55>/1-D Lookup Table' */
  int8_T Switch1;                      /* '<S80>/Switch1' */
  int8_T Switch2;                      /* '<S80>/Switch2' */
  boolean_T Compare;                   /* '<S112>/Compare' */
  boolean_T Compare_i;                 /* '<S111>/Compare' */
  boolean_T LogicalOperator;           /* '<S108>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S80>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S80>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S80>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S80>/Equal1' */
  boolean_T AND3;                      /* '<S80>/AND3' */
  boolean_T Compare_p;                 /* '<S115>/Compare' */
};

/* Block states (default storage) for system '<S3>/controlBontazTCV' */
struct DW_controlBontazTCV_thermal_c_T {
  real_T Integrator_DSTATE;            /* '<S114>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S91>/Integrator' */
  real_T UD_DSTATE;                    /* '<S84>/UD' */
  int8_T Integrator_PrevResetState;    /* '<S114>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S114>/Integrator' */
};

/* Parameters for system: '<S3>/controlBontazTCV' */
struct P_controlBontazTCV_thermal_cl_T_ {
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S114>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S114>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S114>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S114>/Saturation'
                                        */
};

extern void therm_controlBontazTCV_Init(B_controlBontazTCV_thermal_cl_T *localB,
  DW_controlBontazTCV_thermal_c_T *localDW, therm_controlBontazTCV_cal_type
  *thermal_close_PageSwitching_arg);
extern void thermal_cl_controlBontazTCV(real_T rtu_log_STCL_T_SP_degC, real_T
  rtu_s_T_decC_CLSti_Get, B_controlBontazTCV_thermal_cl_T *localB,
  DW_controlBontazTCV_thermal_c_T *localDW, P_controlBontazTCV_thermal_cl_T
  *localP, therm_controlBontazTCV_cal_type *thermal_close_PageSwitching_arg);

#endif                                 /* RTW_HEADER_controlBontazTCV_h_ */
