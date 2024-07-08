/*
 * thermal_closed_loop_model.h
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

#ifndef RTW_HEADER_thermal_closed_loop_model_h_
#define RTW_HEADER_thermal_closed_loop_model_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw_rtp.h"
#include "thermal_closed_loop_model_98402bd5_1_gateway.h"
#include "nesl_rtw.h"
#include "thermal_closed_loop_model_types.h"
#include "BasicThermalSubsystemControl.h"
#include "controlBontazTCV.h"
#include <cmath>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <cstring>

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include "thermal_closed_loop_model_cal.h"
#include "rt_matrixlib.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
#define rtmGetMassMatrixIr(rtm)        ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
#define rtmSetMassMatrixIr(rtm, val)   ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
#define rtmGetMassMatrixJc(rtm)        ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
#define rtmSetMassMatrixJc(rtm, val)   ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
#define rtmGetMassMatrixNzMax(rtm)     ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
#define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
#define rtmGetMassMatrixPr(rtm)        ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
#define rtmSetMassMatrixPr(rtm, val)   ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
#define rtmGetMassMatrixType(rtm)      ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
#define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
#define rtmGetOdeE(rtm)                ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
#define rtmSetOdeE(rtm, val)           ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeEDOT
#define rtmGetOdeEDOT(rtm)             ((rtm)->odeEDOT)
#endif

#ifndef rtmSetOdeEDOT
#define rtmSetOdeEDOT(rtm, val)        ((rtm)->odeEDOT = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeFMXDOT
#define rtmGetOdeFMXDOT(rtm)           ((rtm)->odeFMXDOT)
#endif

#ifndef rtmSetOdeFMXDOT
#define rtmSetOdeFMXDOT(rtm, val)      ((rtm)->odeFMXDOT = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
#define rtmGetOdeMASSMATRIX_M(rtm)     ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
#define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M1
#define rtmGetOdeMASSMATRIX_M1(rtm)    ((rtm)->odeMASSMATRIX_M1)
#endif

#ifndef rtmSetOdeMASSMATRIX_M1
#define rtmSetOdeMASSMATRIX_M1(rtm, val) ((rtm)->odeMASSMATRIX_M1 = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
#define rtmGetOdeX1START(rtm)          ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
#define rtmSetOdeX1START(rtm, val)     ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXDOT
#define rtmGetOdeXDOT(rtm)             ((rtm)->odeXDOT)
#endif

#ifndef rtmSetOdeXDOT
#define rtmSetOdeXDOT(rtm, val)        ((rtm)->odeXDOT = (val))
#endif

#ifndef rtmGetOdeXTMP
#define rtmGetOdeXTMP(rtm)             ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
#define rtmSetOdeXTMP(rtm, val)        ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
#define rtmGetOdeZTMP(rtm)             ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
#define rtmSetOdeZTMP(rtm, val)        ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
struct B_thermal_closed_loop_model_T {
  real_T StackCurrentI_A_StNA;         /* '<S7>/Unit Delay16' */
  real_T TCVOpeningCommand;            /* '<S7>/Unit Delay6' */
  real_T TCVOpening;                   /* '<S7>/Unit Delay7' */
  real_T TCPRotationalSpeedCommandrpm; /* '<S7>/Unit Delay8' */
  real_T TCPRotationalSpeedrpm;        /* '<S7>/Unit Delay9' */
  real_T AuxTCPRotationalSpeedCommandrpm;/* '<S1>/Unit Delay10' */
  real_T AuxTCPRotationalSpeedrpm;     /* '<S1>/Unit Delay11' */
  real_T AuxTCPOutletTemperature6801K; /* '<S7>/Unit Delay2' */
  real_T Sum;                          /* '<S190>/Sum' */
  real_T StackOutletTemperature6820K;  /* '<S7>/Unit Delay1' */
  real_T Sum_k;                        /* '<S189>/Sum' */
  real_T StackInletTemperature6812K;   /* '<S7>/Unit Delay' */
  real_T Sum_m;                        /* '<S188>/Sum' */
  real_T TmpRTBAtSumInport1[3];        /* '<S4>/Manual Switch' */
  real_T Sum_p[3];                     /* '<S4>/Sum' */
  real_T StackOutletTemperatureSetpointC;/* '<S6>/Add' */
  real_T AuxTCPOutletPressure6801Pa;   /* '<S7>/Unit Delay5' */
  real_T PatoBara;                     /* '<S212>/Pa to Bar(a)' */
  real_T TCPOutletPressure6812Pa;      /* '<S7>/Unit Delay4' */
  real_T PatoBara_i;                   /* '<S211>/Pa to Bar(a)' */
  real_T TCPInletPressure6811Pa;       /* '<S7>/Unit Delay3' */
  real_T PatoBara_j;                   /* '<S210>/Pa to Bar(a)' */
  real_T StackCoolantFlowlmin;         /* '<S7>/Unit Delay14' */
  real_T MixHotCoolantFlowInlmin;      /* '<S7>/Unit Delay12' */
  real_T MixColdCoolantFlowInlmin;     /* '<S7>/Unit Delay13' */
  real_T AuxTCPInletPressurePa;        /* '<S1>/Unit Delay5' */
  real_T PatoBara_g;                   /* '<S19>/Pa to Bar(a)' */
  real_T AuxTCPInletTemperatureK;      /* '<S1>/Unit Delay2' */
  real_T Sum_pg;                       /* '<S9>/Sum' */
  real_T RadiatorCoolantFlowlmin;      /* '<S1>/Unit Delay1' */
  real_T BypassCoolantFlowlmin;        /* '<S1>/Unit Delay3' */
  real_T AuxTCPRotationalSpeedCommandr_m;/* '<S7>/Unit Delay10' */
  real_T AuxTCPRotationalSpeedrpm_l;   /* '<S7>/Unit Delay11' */
  real_T StackOutletPressurePa;        /* '<S7>/Unit Delay15' */
  real_T PatoBara_k;                   /* '<S213>/Pa to Bar(a)' */
  real_T TransferFcn1;                 /* '<S1>/Transfer Fcn1' */
  real_T RateLimiter1;                 /* '<S1>/Rate Limiter1' */
  real_T INPUT_1_1_1[4];               /* '<S47>/INPUT_1_1_1' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Saturation;                   /* '<S1>/Saturation' */
  real_T INPUT_2_1_1[4];               /* '<S47>/INPUT_2_1_1' */
  real_T Product;                      /* '<S35>/Product' */
  real_T mdot_air;                     /* '<S35>/Product1' */
  real_T C_air;                        /* '<S35>/C_air' */
  real_T INPUT_3_1_1[4];               /* '<S47>/INPUT_3_1_1' */
  real_T Divide;                       /* '<S35>/Divide' */
  real_T Saturation_i;                 /* '<S35>/Saturation' */
  real_T Fcn;                          /* '<S35>/Fcn' */
  real_T Product2;                     /* '<S35>/Product2' */
  real_T MinMax;                       /* '<S35>/MinMax' */
  real_T INPUT_4_1_1[4];               /* '<S47>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S47>/INPUT_5_1_1' */
  real_T FromWs;                       /* '<S187>/FromWs' */
  real_T CurrenttoHeatW;               /* '<S2>/Current to Heat (W)' */
  real_T INPUT_6_1_1[4];               /* '<S47>/INPUT_6_1_1' */
  real_T TransferFcn2;                 /* '<S7>/Transfer Fcn2' */
  real_T RateLimiter2;                 /* '<S7>/Rate Limiter2' */
  real_T INPUT_8_1_1[4];               /* '<S47>/INPUT_8_1_1' */
  real_T TransferFcn;                  /* '<S7>/Transfer Fcn' */
  real_T RateLimiter;                  /* '<S7>/Rate Limiter' */
  real_T Gain_l;                       /* '<S214>/Gain' */
  real_T Add;                          /* '<S214>/Add' */
  real_T INPUT_7_1_1[4];               /* '<S47>/INPUT_7_1_1' */
  real_T RTP_1;                        /* '<S44>/RTP_1' */
  real_T STATE_1[369];                 /* '<S47>/STATE_1' */
  real_T OUTPUT_1_0[23];               /* '<S47>/OUTPUT_1_0' */
  real_T RESHAPE;                      /* '<S24>/RESHAPE' */
  real_T RESHAPE_n;                    /* '<S27>/RESHAPE' */
  real_T RESHAPE_g;                    /* '<S28>/RESHAPE' */
  real_T RESHAPE_j;                    /* '<S30>/RESHAPE' */
  real_T RateTransition1;              /* '<S1>/Rate Transition1' */
  real_T Constant2;                    /* '<S1>/Constant2' */
  real_T Constant3;                    /* '<S1>/Constant3' */
  real_T RESHAPE_o;                    /* '<S29>/RESHAPE' */
  real_T OUTPUT_1_1[2];                /* '<S47>/OUTPUT_1_1' */
  real_T RESHAPE_c;                    /* '<S26>/RESHAPE' */
  real_T RESHAPE_nb;                   /* '<S31>/RESHAPE' */
  real_T RESHAPE_e;                    /* '<S25>/RESHAPE' */
  real_T RESHAPE_m;                    /* '<S219>/RESHAPE' */
  real_T RESHAPE_f;                    /* '<S220>/RESHAPE' */
  real_T RESHAPE_h;                    /* '<S222>/RESHAPE' */
  real_T RESHAPE_d;                    /* '<S223>/RESHAPE' */
  real_T RESHAPE_a;                    /* '<S224>/RESHAPE' */
  real_T RESHAPE_dl;                   /* '<S225>/RESHAPE' */
  real_T RESHAPE_g3;                   /* '<S226>/RESHAPE' */
  real_T RESHAPE_p;                    /* '<S230>/RESHAPE' */
  real_T RESHAPE_l;                    /* '<S233>/RESHAPE' */
  real_T RESHAPE_k;                    /* '<S235>/RESHAPE' */
  real_T RateTransition;               /* '<S7>/Rate Transition' */
  real_T RateTransition2;              /* '<S7>/Rate Transition2' */
  real_T RESHAPE_gr;                   /* '<S217>/RESHAPE' */
  real_T RESHAPE_mg;                   /* '<S231>/RESHAPE' */
  real_T RESHAPE_lo;                   /* '<S234>/RESHAPE' */
  real_T RESHAPE_ln;                   /* '<S221>/RESHAPE' */
  real_T RESHAPE_ed;                   /* '<S227>/RESHAPE' */
  real_T RESHAPE_js;                   /* '<S229>/RESHAPE' */
  real_T OUTPUT_1_2;                   /* '<S47>/OUTPUT_1_2' */
  real_T OUTPUT_1_3;                   /* '<S47>/OUTPUT_1_3' */
  real_T WhiteNoise;                   /* '<S186>/White Noise' */
  real_T Output[3];                    /* '<S186>/Output' */
  real_T ManualSwitch[3];              /* '<S4>/Manual Switch' */
  real_T Probe[2];                     /* '<S175>/Probe' */
  real_T Sum1;                         /* '<S175>/Sum1' */
  real_T delta_T_degC;                 /* '<S50>/Sum' */
  real_T K;                            /* '<S117>/K' */
  real_T Integrator;                   /* '<S181>/Integrator' */
  real_T Saturation_g;                 /* '<S181>/Saturation' */
  real_T Sum1_l;                       /* '<S50>/Sum1' */
  real_T ProportionalGain;             /* '<S162>/Proportional Gain' */
  real_T UnitDelay;                    /* '<S120>/Unit Delay' */
  real_T Reciprocal;                   /* '<S50>/Reciprocal' */
  real_T Saturation_b;                 /* '<S182>/Saturation' */
  real_T DiscreteTimeIntegrator;       /* '<S182>/Discrete-Time Integrator' */
  real_T Gain_b;                       /* '<S182>/Gain' */
  real_T Probe_f[2];                   /* '<S182>/Probe' */
  real_T Product2_c;                   /* '<S182>/Product2' */
  real_T MathFunction1;                /* '<S182>/Math Function1' */
  real_T RoundingFunction1;            /* '<S182>/Rounding Function1' */
  real_T Sum4;                         /* '<S182>/Sum4' */
  real_T UnitDelay_b;                  /* '<S182>/Unit Delay' */
  real_T Sum3;                         /* '<S182>/Sum3' */
  real_T Gain1;                        /* '<S182>/Gain1' */
  real_T MathFunction2;                /* '<S182>/Math Function2' */
  real_T RoundingFunction2;            /* '<S182>/Rounding Function2' */
  real_T UnitDelay1;                   /* '<S182>/Unit Delay1' */
  real_T Switch;                       /* '<S182>/Switch' */
  real_T LUT_FFWD_TCP;                 /* '<S50>/LUT_FFWD_TCP' */
  real_T Switch_l;                     /* '<S119>/Switch' */
  real_T Switch2;                      /* '<S119>/Switch2' */
  real_T Sum2;                         /* '<S50>/Sum2' */
  real_T Integrator_k;                 /* '<S157>/Integrator' */
  real_T DerivativeGain;               /* '<S149>/Derivative Gain' */
  real_T Tsamp;                        /* '<S152>/Tsamp' */
  real_T UD;                           /* '<S150>/UD' */
  real_T Diff;                         /* '<S150>/Diff' */
  real_T Sum_j;                        /* '<S167>/Sum' */
  real_T Sum3_o;                       /* '<S50>/Sum3' */
  real_T Switch_p;                     /* '<S148>/Switch' */
  real_T Diff_e;                       /* '<S148>/Diff' */
  real_T IntegralGain;                 /* '<S154>/Integral Gain' */
  real_T Switch_m;                     /* '<S145>/Switch' */
  real_T Switch_f;                     /* '<S165>/Switch' */
  real_T Switch2_m;                    /* '<S165>/Switch2' */
  real_T Max;                          /* '<S175>/Max' */
  real_T AvoidDividebyZero;            /* '<S175>/Avoid Divide by Zero' */
  real_T Sum1_j;                       /* '<S117>/Sum1' */
  real_T uT;                           /* '<S117>/1//T' */
  real_T Sum4_o;                       /* '<S50>/Sum4' */
  real_T Switch_d;                     /* '<S185>/Switch' */
  real_T Sum2_p;                       /* '<S182>/Sum2' */
  real_T Product1;                     /* '<S182>/Product1' */
  real_T Sum1_lt;                      /* '<S182>/Sum1' */
  real_T Product_a;                    /* '<S182>/Product' */
  real_T Sum_i;                        /* '<S182>/Sum' */
  real_T ImpAsg_InsertedFor_Out1_at_inpo;/* '<S183>/Variable Integer Delay' */
  real_T Switch1;                      /* '<S148>/Switch1' */
  real_T uDLookupTable1;               /* '<S52>/1-D Lookup Table1' */
  real_T uDLookupTable1_p;             /* '<S51>/1-D Lookup Table1' */
  int8_T Switch1_l;                    /* '<S145>/Switch1' */
  int8_T Switch2_c;                    /* '<S145>/Switch2' */
  boolean_T Compare;                   /* '<S179>/Compare' */
  boolean_T Compare_p;                 /* '<S178>/Compare' */
  boolean_T LogicalOperator;           /* '<S175>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S182>/Relational Operator' */
  boolean_T LowerRelop1;               /* '<S119>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S119>/UpperRelop' */
  boolean_T u_GTE_up;                  /* '<S148>/u_GTE_up' */
  boolean_T RelationalOperator_c;      /* '<S145>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S145>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S145>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S145>/Equal1' */
  boolean_T AND3;                      /* '<S145>/AND3' */
  boolean_T LowerRelop1_c;             /* '<S165>/LowerRelop1' */
  boolean_T UpperRelop_p;              /* '<S165>/UpperRelop' */
  boolean_T Compare_h;                 /* '<S184>/Compare' */
  boolean_T u_GT_lo;                   /* '<S148>/u_GT_lo' */
  B_CoreSubsys_thermal_closed_l_T CoreSubsys[1];/* '<S182>/For Each Subsystem' */
  B_controlBontazTCV_thermal_cl_T controlBontazTCV;/* '<S3>/controlBontazTCV' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_thermal_closed_loop_model_T {
  real_T UnitDelay16_DSTATE;           /* '<S7>/Unit Delay16' */
  real_T UnitDelay6_DSTATE;            /* '<S7>/Unit Delay6' */
  real_T UnitDelay7_DSTATE;            /* '<S7>/Unit Delay7' */
  real_T UnitDelay8_DSTATE;            /* '<S7>/Unit Delay8' */
  real_T UnitDelay9_DSTATE;            /* '<S7>/Unit Delay9' */
  real_T UnitDelay10_DSTATE;           /* '<S1>/Unit Delay10' */
  real_T UnitDelay11_DSTATE;           /* '<S1>/Unit Delay11' */
  real_T UnitDelay2_DSTATE;            /* '<S7>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S7>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S7>/Unit Delay' */
  real_T UnitDelay5_DSTATE;            /* '<S7>/Unit Delay5' */
  real_T UnitDelay4_DSTATE;            /* '<S7>/Unit Delay4' */
  real_T UnitDelay3_DSTATE;            /* '<S7>/Unit Delay3' */
  real_T UnitDelay14_DSTATE;           /* '<S7>/Unit Delay14' */
  real_T UnitDelay12_DSTATE;           /* '<S7>/Unit Delay12' */
  real_T UnitDelay13_DSTATE;           /* '<S7>/Unit Delay13' */
  real_T UnitDelay5_DSTATE_p;          /* '<S1>/Unit Delay5' */
  real_T UnitDelay2_DSTATE_m;          /* '<S1>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_i;          /* '<S1>/Unit Delay1' */
  real_T UnitDelay3_DSTATE_d;          /* '<S1>/Unit Delay3' */
  real_T UnitDelay10_DSTATE_f;         /* '<S7>/Unit Delay10' */
  real_T UnitDelay11_DSTATE_p;         /* '<S7>/Unit Delay11' */
  real_T UnitDelay15_DSTATE;           /* '<S7>/Unit Delay15' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S47>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S47>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S47>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete[2];      /* '<S47>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete[2];      /* '<S47>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete[2];      /* '<S47>/INPUT_6_1_1' */
  real_T INPUT_8_1_1_Discrete[2];      /* '<S47>/INPUT_8_1_1' */
  real_T INPUT_7_1_1_Discrete[2];      /* '<S47>/INPUT_7_1_1' */
  real_T STATE_1_Discrete[115];        /* '<S47>/STATE_1' */
  real_T Integrator_DSTATE;            /* '<S181>/Integrator' */
  real_T UnitDelay_DSTATE_h;           /* '<S120>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S182>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_b;           /* '<S182>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S182>/Unit Delay1' */
  real_T Integrator_DSTATE_o;          /* '<S157>/Integrator' */
  real_T UD_DSTATE;                    /* '<S150>/UD' */
  real_T TmpRTBAtSumInport1_Buf[6];    /* synthesized block */
  real_T PrevYA;                       /* '<S1>/Rate Limiter1' */
  real_T PrevYB;                       /* '<S1>/Rate Limiter1' */
  real_T LastMajorTimeA;               /* '<S1>/Rate Limiter1' */
  real_T LastMajorTimeB;               /* '<S1>/Rate Limiter1' */
  real_T PrevYA_c;                     /* '<S7>/Rate Limiter2' */
  real_T PrevYB_c;                     /* '<S7>/Rate Limiter2' */
  real_T LastMajorTimeA_j;             /* '<S7>/Rate Limiter2' */
  real_T LastMajorTimeB_k;             /* '<S7>/Rate Limiter2' */
  real_T PrevYA_f;                     /* '<S7>/Rate Limiter' */
  real_T PrevYB_h;                     /* '<S7>/Rate Limiter' */
  real_T LastMajorTimeA_h;             /* '<S7>/Rate Limiter' */
  real_T LastMajorTimeB_a;             /* '<S7>/Rate Limiter' */
  real_T OUTPUT_1_0_Discrete;          /* '<S47>/OUTPUT_1_0' */
  real_T OUTPUT_1_1_Discrete;          /* '<S47>/OUTPUT_1_1' */
  real_T OUTPUT_1_2_Discrete;          /* '<S47>/OUTPUT_1_2' */
  real_T OUTPUT_1_3_Discrete;          /* '<S47>/OUTPUT_1_3' */
  real_T NextOutput;                   /* '<S186>/White Noise' */
  struct {
    void *LoggedData[6];
  } MainSimulationResults_PWORK;       /* '<S6>/Main Simulation Results' */

  struct {
    void *AQHandles[6];
  } TAQSigLogging_InsertedFor_Basic;   /* synthesized block */

  struct {
    void *AQHandles[17];
  } TAQSigLogging_InsertedFor_Subsy;   /* synthesized block */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S187>/FromWs' */

  void* RTP_1_RtpManager;              /* '<S44>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S47>/STATE_1' */
  void* STATE_1_SimData;               /* '<S47>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S47>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S47>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S47>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S47>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S47>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S47>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S47>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S47>/OUTPUT_1_0' */
  void* OUTPUT_1_1_Simulator;          /* '<S47>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimData;            /* '<S47>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagMgr;            /* '<S47>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZcLogger;           /* '<S47>/OUTPUT_1_1' */
  void* OUTPUT_1_1_TsInfo;             /* '<S47>/OUTPUT_1_1' */
  void* OUTPUT_1_2_Simulator;          /* '<S47>/OUTPUT_1_2' */
  void* OUTPUT_1_2_SimData;            /* '<S47>/OUTPUT_1_2' */
  void* OUTPUT_1_2_DiagMgr;            /* '<S47>/OUTPUT_1_2' */
  void* OUTPUT_1_2_ZcLogger;           /* '<S47>/OUTPUT_1_2' */
  void* OUTPUT_1_2_TsInfo;             /* '<S47>/OUTPUT_1_2' */
  void* OUTPUT_1_3_Simulator;          /* '<S47>/OUTPUT_1_3' */
  void* OUTPUT_1_3_SimData;            /* '<S47>/OUTPUT_1_3' */
  void* OUTPUT_1_3_DiagMgr;            /* '<S47>/OUTPUT_1_3' */
  void* OUTPUT_1_3_ZcLogger;           /* '<S47>/OUTPUT_1_3' */
  void* OUTPUT_1_3_TsInfo;             /* '<S47>/OUTPUT_1_3' */
  uint32_T RandSeed;                   /* '<S186>/White Noise' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S187>/FromWs' */

  int_T STATE_1_Modes[214];            /* '<S47>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S47>/OUTPUT_1_0' */
  int_T OUTPUT_1_1_Modes;              /* '<S47>/OUTPUT_1_1' */
  int_T OUTPUT_1_2_Modes;              /* '<S47>/OUTPUT_1_2' */
  int_T OUTPUT_1_3_Modes;              /* '<S47>/OUTPUT_1_3' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S47>/STATE_1' */
  int8_T TmpRTBAtSumInport1_RdBufIdx;  /* synthesized block */
  int8_T TmpRTBAtSumInport1_WrBufIdx;  /* synthesized block */
  int8_T Integrator_PrevResetState;    /* '<S181>/Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S157>/Integrator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S120>/Triggered Subsystem' */
  uint8_T Integrator_IC_LOADING;       /* '<S181>/Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S182>/Discrete-Time Integrator' */
  uint8_T Integrator_IC_LOADING_m;     /* '<S157>/Integrator' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S44>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S47>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S47>/OUTPUT_1_0' */
  boolean_T OUTPUT_1_1_FirstOutput;    /* '<S47>/OUTPUT_1_1' */
  boolean_T OUTPUT_1_2_FirstOutput;    /* '<S47>/OUTPUT_1_2' */
  boolean_T OUTPUT_1_3_FirstOutput;    /* '<S47>/OUTPUT_1_3' */
  boolean_T icLoad;                    /* '<S150>/UD' */
  DW_CoreSubsys_thermal_closed__T CoreSubsys[1];/* '<S182>/For Each Subsystem' */
  DW_controlBontazTCV_thermal_c_T controlBontazTCV;/* '<S3>/controlBontazTCV' */
};

/* Continuous states (default storage) */
struct X_thermal_closed_loop_model_T {
  real_T tcv_opening;                  /* '<S1>/Transfer Fcn1' */
  real_T tcv_opening_o;                /* '<S7>/Transfer Fcn2' */
  real_T tcv_opening_e;                /* '<S7>/Transfer Fcn' */
  real_T thermal_closed_loop_modelBasic_[148];/* '<S47>/STATE_1' */
};

/* State derivatives (default storage) */
struct XDot_thermal_closed_loop_mode_T {
  real_T tcv_opening;                  /* '<S1>/Transfer Fcn1' */
  real_T tcv_opening_o;                /* '<S7>/Transfer Fcn2' */
  real_T tcv_opening_e;                /* '<S7>/Transfer Fcn' */
  real_T thermal_closed_loop_modelBasic_[148];/* '<S47>/STATE_1' */
};

/* State disabled  */
struct XDis_thermal_closed_loop_mode_T {
  boolean_T tcv_opening;               /* '<S1>/Transfer Fcn1' */
  boolean_T tcv_opening_o;             /* '<S7>/Transfer Fcn2' */
  boolean_T tcv_opening_e;             /* '<S7>/Transfer Fcn' */
  boolean_T thermal_closed_loop_modelBasic_[148];/* '<S47>/STATE_1' */
};

/* Zero-crossing (trigger) state */
struct PrevZCX_thermal_closed_loop_m_T {
  ZCSigState UD_Reset_ZCE;             /* '<S150>/UD' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S120>/Triggered Subsystem' */
};

/* Mass Matrix (global) */
struct MassMatrix_thermal_closed_loo_T {
  int_T ir[34];
  int_T jc[152];
  real_T pr[34];
};

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
struct ODE14X_IntgData {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
};

#endif

/* Parameters (default storage) */
struct P_thermal_closed_loop_model_T_ {
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S181>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S181>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S181>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S181>/Saturation'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: inf
                                        * Referenced by: '<S182>/Saturation'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S35>/Saturation'
                                        */
  P_controlBontazTCV_thermal_cl_T controlBontazTCV;/* '<S3>/controlBontazTCV' */
};

/* Real-time Model Data Structure */
struct tag_RTM_thermal_closed_loop_m_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_thermal_closed_loop_model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_thermal_closed_loop_mode_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[151];
  real_T odeF0[151];
  real_T odeX1START[151];
  real_T odeF1[151];
  real_T odeDELTA[151];
  real_T odeE[4*151];
  real_T odeFAC[151];
  real_T odeDFDX[151*151];
  real_T odeW[151*151];
  int_T odePIVOTS[151];
  real_T odeXTMP[151];
  real_T odeZTMP[151];
  real_T odeMASSMATRIX_M[34];
  real_T odeMASSMATRIX_M1[34];
  real_T odeEDOT[4*151];
  real_T odeXDOT[151];
  real_T odeFMXDOT[151];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
      uint8_T cLimit[3];
    } TaskCounters;

    struct {
      uint8_T TID1_2;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_thermal_closed_loop_model_T thermal_closed_loop_model_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_thermal_closed_loop_model_T thermal_closed_loop_model_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_thermal_closed_loop_model_T thermal_closed_loop_model_X;

/* Block states (default storage) */
extern struct DW_thermal_closed_loop_model_T thermal_closed_loop_model_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_thermal_closed_loop_m_T thermal_closed_loop_mod_PrevZCX;

/* global MassMatrix */
extern MassMatrix_thermal_closed_loo_T thermal_closed_loop__MassMatrix;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void thermal_closed_loop_model_initialize(void);
  extern void thermal_closed_loop_model_step0(void);
  extern void thermal_closed_loop_model_step2(void);
  extern void thermal_closed_loop_model_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_thermal_closed_loop__T *const thermal_closed_loop_model_M;

#ifdef __cplusplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'thermal_closed_loop_model'
 * '<S1>'   : 'thermal_closed_loop_model/Basic Peripherals'
 * '<S2>'   : 'thermal_closed_loop_model/Basic Stack Heat Emulation'
 * '<S3>'   : 'thermal_closed_loop_model/BasicThermalSubsystemControl'
 * '<S4>'   : 'thermal_closed_loop_model/Emulate Sensors'
 * '<S5>'   : 'thermal_closed_loop_model/Load Cycle(s)'
 * '<S6>'   : 'thermal_closed_loop_model/Monitoring'
 * '<S7>'   : 'thermal_closed_loop_model/Subsystem Reference'
 * '<S8>'   : 'thermal_closed_loop_model/Basic Peripherals/Coolant Tank'
 * '<S9>'   : 'thermal_closed_loop_model/Basic Peripherals/Kelvin to °C2'
 * '<S10>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter 2'
 * '<S11>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter1'
 * '<S12>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter18'
 * '<S13>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter19'
 * '<S14>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter20'
 * '<S15>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter21'
 * '<S16>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter25'
 * '<S17>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter26'
 * '<S18>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter28'
 * '<S19>'  : 'thermal_closed_loop_model/Basic Peripherals/Pascal to Bar(a)2'
 * '<S20>'  : 'thermal_closed_loop_model/Basic Peripherals/Simulink-PS Converter1'
 * '<S21>'  : 'thermal_closed_loop_model/Basic Peripherals/Simulink-PS Converter4'
 * '<S22>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem'
 * '<S23>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter 2/EVAL_KEY'
 * '<S24>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter1/EVAL_KEY'
 * '<S25>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter18/EVAL_KEY'
 * '<S26>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter19/EVAL_KEY'
 * '<S27>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter20/EVAL_KEY'
 * '<S28>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter21/EVAL_KEY'
 * '<S29>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter25/EVAL_KEY'
 * '<S30>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter26/EVAL_KEY'
 * '<S31>'  : 'thermal_closed_loop_model/Basic Peripherals/PS-Simulink Converter28/EVAL_KEY'
 * '<S32>'  : 'thermal_closed_loop_model/Basic Peripherals/Simulink-PS Converter1/EVAL_KEY'
 * '<S33>'  : 'thermal_closed_loop_model/Basic Peripherals/Simulink-PS Converter4/EVAL_KEY'
 * '<S34>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model'
 * '<S35>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct'
 * '<S36>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter'
 * '<S37>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter1'
 * '<S38>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter2'
 * '<S39>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter/EVAL_KEY'
 * '<S40>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter1/EVAL_KEY'
 * '<S41>'  : 'thermal_closed_loop_model/Basic Peripherals/Variant Subsystem/Phyiscal_Radiator_Model/Aircraft Duct/Simulink-PS Converter2/EVAL_KEY'
 * '<S42>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/PS-Simulink Converter16'
 * '<S43>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/Simulink-PS Converter6'
 * '<S44>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'
 * '<S45>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/PS-Simulink Converter16/EVAL_KEY'
 * '<S46>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/Simulink-PS Converter6/EVAL_KEY'
 * '<S47>'  : 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration/EVAL_KEY'
 * '<S48>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/Setpoints'
 * '<S49>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV'
 * '<S50>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP'
 * '<S51>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/Setpoints/calculateDeltaTemperatureSetpoint'
 * '<S52>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/Setpoints/calculateTemperatureSetpoint'
 * '<S53>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller'
 * '<S54>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)'
 * '<S55>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Valve_Characteristics'
 * '<S56>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Anti-windup'
 * '<S57>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/D Gain'
 * '<S58>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter'
 * '<S59>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter ICs'
 * '<S60>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/I Gain'
 * '<S61>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Ideal P Gain'
 * '<S62>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S63>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Integrator'
 * '<S64>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Integrator ICs'
 * '<S65>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/N Copy'
 * '<S66>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/N Gain'
 * '<S67>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/P Copy'
 * '<S68>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Parallel P Gain'
 * '<S69>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Reset Signal'
 * '<S70>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Saturation'
 * '<S71>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Saturation Fdbk'
 * '<S72>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Sum'
 * '<S73>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Sum Fdbk'
 * '<S74>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tracking Mode'
 * '<S75>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tracking Mode Sum'
 * '<S76>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tsamp - Integral'
 * '<S77>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tsamp - Ngain'
 * '<S78>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/postSat Signal'
 * '<S79>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/preSat Signal'
 * '<S80>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S81>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S82>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S83>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S84>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter/Differentiator'
 * '<S85>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter/Differentiator/Tsamp'
 * '<S86>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S87>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S88>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S89>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S90>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Integrator/Discrete'
 * '<S92>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S93>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S94>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/N Gain/Passthrough'
 * '<S95>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/P Copy/Disabled'
 * '<S96>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Reset Signal/Disabled'
 * '<S98>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Saturation/Enabled'
 * '<S99>'  : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S100>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Sum/Sum_PID'
 * '<S101>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S102>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S103>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S105>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S107>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S108>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S109>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S110>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S111>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Constant'
 * '<S112>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S113>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S114>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S115>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlBontazTCV/Valve_Characteristics/Compare To Constant'
 * '<S116>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller'
 * '<S117>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)'
 * '<S118>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Moving Average (Variable Frequency)'
 * '<S119>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Saturation Dynamic'
 * '<S120>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/initial engagement trigger'
 * '<S121>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Anti-windup'
 * '<S122>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/D Gain'
 * '<S123>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter'
 * '<S124>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter ICs'
 * '<S125>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/I Gain'
 * '<S126>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Ideal P Gain'
 * '<S127>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S128>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Integrator'
 * '<S129>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Integrator ICs'
 * '<S130>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/N Copy'
 * '<S131>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/N Gain'
 * '<S132>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/P Copy'
 * '<S133>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Parallel P Gain'
 * '<S134>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Reset Signal'
 * '<S135>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Saturation'
 * '<S136>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Saturation Fdbk'
 * '<S137>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Sum'
 * '<S138>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Sum Fdbk'
 * '<S139>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tracking Mode'
 * '<S140>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tracking Mode Sum'
 * '<S141>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tsamp - Integral'
 * '<S142>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tsamp - Ngain'
 * '<S143>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/postSat Signal'
 * '<S144>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/preSat Signal'
 * '<S145>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S146>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S147>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S148>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S149>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S150>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter/Differentiator'
 * '<S151>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter/Differentiator/Tsamp'
 * '<S152>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S153>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Filter ICs/External IC'
 * '<S154>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S155>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S156>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S157>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Integrator/Discrete'
 * '<S158>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Integrator ICs/External IC'
 * '<S159>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S160>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/N Gain/Passthrough'
 * '<S161>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/P Copy/Disabled'
 * '<S162>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S163>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Reset Signal/External Reset'
 * '<S164>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Saturation/External'
 * '<S165>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Saturation/External/Saturation Dynamic'
 * '<S166>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S167>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Sum/Sum_PID'
 * '<S168>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S169>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S170>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S171>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S172>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S173>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S174>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S175>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S176>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S177>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S178>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Constant'
 * '<S179>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S180>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S181>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S182>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Moving Average (Variable Frequency)/Discrete'
 * '<S183>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/Moving Average (Variable Frequency)/Discrete/For Each Subsystem'
 * '<S184>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/initial engagement trigger/IsPositive'
 * '<S185>' : 'thermal_closed_loop_model/BasicThermalSubsystemControl/controlEMPHVTCP/initial engagement trigger/Triggered Subsystem'
 * '<S186>' : 'thermal_closed_loop_model/Emulate Sensors/Band-Limited White Noise'
 * '<S187>' : 'thermal_closed_loop_model/Load Cycle(s)/I_Stack__TB -  Power Cycle'
 * '<S188>' : 'thermal_closed_loop_model/Subsystem Reference/Kelvin to °C'
 * '<S189>' : 'thermal_closed_loop_model/Subsystem Reference/Kelvin to °C1'
 * '<S190>' : 'thermal_closed_loop_model/Subsystem Reference/Kelvin to °C2'
 * '<S191>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter'
 * '<S192>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter 1'
 * '<S193>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter1'
 * '<S194>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter10'
 * '<S195>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter11'
 * '<S196>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter13'
 * '<S197>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter14'
 * '<S198>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter16'
 * '<S199>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter17'
 * '<S200>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter22'
 * '<S201>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter23'
 * '<S202>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter24'
 * '<S203>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter3'
 * '<S204>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter4'
 * '<S205>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter5'
 * '<S206>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter6'
 * '<S207>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter7'
 * '<S208>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter8'
 * '<S209>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter9'
 * '<S210>' : 'thermal_closed_loop_model/Subsystem Reference/Pascal to Bar(a)'
 * '<S211>' : 'thermal_closed_loop_model/Subsystem Reference/Pascal to Bar(a)1'
 * '<S212>' : 'thermal_closed_loop_model/Subsystem Reference/Pascal to Bar(a)2'
 * '<S213>' : 'thermal_closed_loop_model/Subsystem Reference/Pascal to Bar(a)3'
 * '<S214>' : 'thermal_closed_loop_model/Subsystem Reference/Relative Opening to Spool Position'
 * '<S215>' : 'thermal_closed_loop_model/Subsystem Reference/Simulink-PS Converter'
 * '<S216>' : 'thermal_closed_loop_model/Subsystem Reference/Simulink-PS Converter2'
 * '<S217>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter/EVAL_KEY'
 * '<S218>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter 1/EVAL_KEY'
 * '<S219>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter1/EVAL_KEY'
 * '<S220>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter10/EVAL_KEY'
 * '<S221>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter11/EVAL_KEY'
 * '<S222>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter13/EVAL_KEY'
 * '<S223>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter14/EVAL_KEY'
 * '<S224>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter16/EVAL_KEY'
 * '<S225>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter17/EVAL_KEY'
 * '<S226>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter22/EVAL_KEY'
 * '<S227>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter23/EVAL_KEY'
 * '<S228>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter24/EVAL_KEY'
 * '<S229>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter3/EVAL_KEY'
 * '<S230>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter4/EVAL_KEY'
 * '<S231>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter5/EVAL_KEY'
 * '<S232>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter6/EVAL_KEY'
 * '<S233>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter7/EVAL_KEY'
 * '<S234>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter8/EVAL_KEY'
 * '<S235>' : 'thermal_closed_loop_model/Subsystem Reference/PS-Simulink Converter9/EVAL_KEY'
 * '<S236>' : 'thermal_closed_loop_model/Subsystem Reference/Simulink-PS Converter/EVAL_KEY'
 * '<S237>' : 'thermal_closed_loop_model/Subsystem Reference/Simulink-PS Converter2/EVAL_KEY'
 */
#endif                             /* RTW_HEADER_thermal_closed_loop_model_h_ */
