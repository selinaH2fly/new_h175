#ifndef RTW_HEADER_controlBontazTCV_cal_h_
#define RTW_HEADER_controlBontazTCV_cal_h_
#include "rtwtypes.h"

/* Storage class 'PageSwitching', for system '<S3>/controlBontazTCV' */
struct therm_controlBontazTCV_cal_type {
  real_T uDLookupTable_tableData[6];   /* Expression: [0  2   91  95 99 100]
                                        * Referenced by: '<S55>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[6];    /* Expression: [5  10  70  73 80 100]
                                        * Referenced by: '<S55>/1-D Lookup Table'
                                        */
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S83>/Derivative Gain'
                                       */
  real_T DiscretePIDController_Different;
                              /* Mask Parameter: DiscretePIDController_Different
                               * Referenced by: '<S84>/UD'
                               */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S88>/Integral Gain'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T LowPassFilterDiscreteorContinuo;
                              /* Mask Parameter: LowPassFilterDiscreteorContinuo
                               * Referenced by: '<S54>/K'
                               */
  real_T DiscretePIDController_LowerSatu;
                              /* Mask Parameter: DiscretePIDController_LowerSatu
                               * Referenced by:
                               *   '<S98>/Saturation'
                               *   '<S82>/DeadZone'
                               */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S96>/Proportional Gain'
                                       */
  real_T LowPassFilterDiscreteorContin_a;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_a
                               * Referenced by: '<S108>/Time constant'
                               */
  real_T DiscretePIDController_UpperSatu;
                              /* Mask Parameter: DiscretePIDController_UpperSatu
                               * Referenced by:
                               *   '<S98>/Saturation'
                               *   '<S82>/DeadZone'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S111>/Constant'
                                       */
  real_T CompareToConstant_const_c; /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S115>/Constant'
                                     */
  real_T LowPassFilterDiscreteorContin_k;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_k
                               * Referenced by: '<S108>/Constant'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S80>/Clamping_zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S112>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S114>/Integrator'
                                        */
  real_T Integrator_gainval_a;       /* Computed Parameter: Integrator_gainval_a
                                      * Referenced by: '<S91>/Integrator'
                                      */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S86>/Tsamp'
                                        */
  int8_T Constant_Value_i;             /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S80>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S80>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S80>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S80>/Constant4'
                                        */
};

#endif                                 /* RTW_HEADER_controlBontazTCV_cal_h_ */
