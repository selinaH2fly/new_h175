#ifndef RTW_HEADER_thermal_closed_loop_model_cal_h_
#define RTW_HEADER_thermal_closed_loop_model_cal_h_
#include "rtwtypes.h"
#include "BasicThermalSubsystemControl_cal.h"
#include "controlBontazTCV_cal.h"

/* Storage class 'PageSwitching', for system '<Root>' */
struct thermal_closed_loop_mo_cal_type {
  thermal_clo_CoreSubsys_cal_type thermal_closed_l_CoreSubsys_cal;/* '<S182>/For Each Subsystem' */
  therm_controlBontazTCV_cal_type thermal_cl_controlBontazTCV_cal;/* '<S3>/controlBontazTCV' */
  real_T BandLimitedWhiteNoise_Cov[3];
                                    /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S186>/Output'
                                     */
  real_T uDLookupTable1_tableData[13];
  /* Expression: [ 8, 8,    8,    8,     8,    8,    8,    8,     9,   10,   11,   12,   13]
   * Referenced by: '<S51>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[13];
  /* Expression: [0   50   100   150   200   250   300   350   400   425   450   475   500]
   * Referenced by: '<S51>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData_e[13];
  /* Expression: [58, 58,   62,   64,   66,   69,   72,  73,   73,   73,   73,   73,   73]
   * Referenced by: '<S52>/1-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data_i[13];
  /* Expression: [0   50   100   150   200   250   300   350   400   425   450   475   500]
   * Referenced by: '<S52>/1-D Lookup Table1'
   */
  real_T LUT_FFWD_TCP_tableData[14];
  /* Expression: [1400, 1400, 1600, 1800, 2200, 2600, 2800, 2900, 2900, 2900, 2900, 2900, 2900, 2900]
   * Referenced by: '<S50>/LUT_FFWD_TCP'
   */
  real_T LUT_FFWD_TCP_bp01Data[14];
  /* Expression: [   0,  100,  199,  200,  250,  300,  350,  399,  400,  420,  450,  480,  500,  600]
   * Referenced by: '<S50>/LUT_FFWD_TCP'
   */
  real_T Constant_Value_h[3];          /* Expression: zeros(1,3)
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T CurrenttoHeatW_tableData[9];
       /* Expression: [0, 9932, 21438, 33442,47123, 59491, 77033, 93585, 112042]
        * Referenced by: '<S2>/Current to Heat (W)'
        */
  real_T CurrenttoHeatW_bp01Data[9];   /* Expression: [0:50:400]
                                        * Referenced by: '<S2>/Current to Heat (W)'
                                        */
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S149>/Derivative Gain'
                                       */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S154>/Integral Gain'
                                       */
  real_T LowPassFilterDiscreteorContinuo;
                              /* Mask Parameter: LowPassFilterDiscreteorContinuo
                               * Referenced by: '<S117>/K'
                               */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S162>/Proportional Gain'
                                       */
  real_T LowPassFilterDiscreteorContin_b;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_b
                               * Referenced by: '<S175>/Time constant'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S178>/Constant'
                                       */
  real_T MovingAverageVariableFrequency_;
                              /* Mask Parameter: MovingAverageVariableFrequency_
                               * Referenced by: '<S182>/Gain1'
                               */
  real_T LowPassFilterDiscreteorContin_f;
                              /* Mask Parameter: LowPassFilterDiscreteorContin_f
                               * Referenced by: '<S175>/Constant'
                               */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S186>/White Noise'
                                    */
  real_T MovingAverageVariableFrequenc_d;
                              /* Mask Parameter: MovingAverageVariableFrequenc_d
                               * Referenced by: '<S182>/Unit Delay1'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S145>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S185>/Out1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S185>/Switch'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S145>/Clamping_zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S179>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S181>/Integrator'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S120>/Unit Delay'
                                        */
  real_T p_Emp_TCP_min_rpm_Value;      /* Expression: 1400
                                        * Referenced by: '<S50>/p_Emp_TCP_min_rpm'
                                        */
  real_T p_Emp_TCP_max_rpm_Value;      /* Expression: 3000
                                        * Referenced by: '<S50>/p_Emp_TCP_max_rpm'
                                        */
  real_T p_Emp_STCL_FFWD_Filter_PER_s_Va;/* Expression: 0.1
                                          * Referenced by: '<S50>/p_Emp_STCL_FFWD_Filter_PER_s'
                                          */
  real_T Saturation_LowerSat_j;        /* Expression: eps
                                        * Referenced by: '<S182>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S182>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S182>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S182>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S182>/Unit Delay'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S182>/Constant2'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S157>/Integrator'
                                      */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S152>/Tsamp'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S184>/Constant'
                                        */
  real_T UnitDelay16_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay16'
                                        */
  real_T UnitDelay6_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay6'
                                        */
  real_T UnitDelay7_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay7'
                                        */
  real_T UnitDelay8_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay8'
                                        */
  real_T UnitDelay9_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay9'
                                        */
  real_T UnitDelay10_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay10'
                                        */
  real_T UnitDelay11_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay11'
                                        */
  real_T Constant_Value_m;             /* Expression: 273.15
                                        * Referenced by: '<S190>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 273.15
                                        * Referenced by: '<S189>/Constant'
                                        */
  real_T Constant_Value_e5;            /* Expression: 273.15
                                        * Referenced by: '<S188>/Constant'
                                        */
  real_T TmpRTBAtSumInport1_InitialCondi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T PatoBara_Gain;                /* Expression: 1e-5
                                        * Referenced by: '<S212>/Pa to Bar(a)'
                                        */
  real_T PatoBara_Gain_o;              /* Expression: 1e-5
                                        * Referenced by: '<S211>/Pa to Bar(a)'
                                        */
  real_T PatoBara_Gain_f;              /* Expression: 1e-5
                                        * Referenced by: '<S210>/Pa to Bar(a)'
                                        */
  real_T UnitDelay14_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay14'
                                        */
  real_T UnitDelay12_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay12'
                                        */
  real_T UnitDelay13_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay13'
                                        */
  real_T PatoBara_Gain_e;              /* Expression: 1e-5
                                        * Referenced by: '<S19>/Pa to Bar(a)'
                                        */
  real_T Constant_Value_p;             /* Expression: 273.15
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay3'
                                        */
  real_T UnitDelay10_InitialCondition_f;/* Expression: 0
                                         * Referenced by: '<S7>/Unit Delay10'
                                         */
  real_T UnitDelay11_InitialCondition_o;/* Expression: 0
                                         * Referenced by: '<S7>/Unit Delay11'
                                         */
  real_T PatoBara_Gain_l;              /* Expression: 1e-5
                                        * Referenced by: '<S213>/Pa to Bar(a)'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T RateLimiter1_RisingLim;       /* Expression: 1000
                                        * Referenced by: '<S1>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Expression: -1000
                                        * Referenced by: '<S1>/Rate Limiter1'
                                        */
  real_T Bypass_Opening_Value;         /* Expression: 1
                                        * Referenced by: '<Root>/Bypass_Opening'
                                        */
  real_T Saturation_LowerSat_j0;       /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant_Value_n;             /* Expression: 100
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0
                                        * Referenced by: '<S35>/Saturation'
                                        */
  real_T Constant1_Value_a;            /* Expression: 293.15
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S7>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S7>/Transfer Fcn2'
                                        */
  real_T RateLimiter2_RisingLim;       /* Expression: 1000
                                        * Referenced by: '<S7>/Rate Limiter2'
                                        */
  real_T RateLimiter2_FallingLim;      /* Expression: -1000
                                        * Referenced by: '<S7>/Rate Limiter2'
                                        */
  real_T Valve_Constant_Value;         /* Expression: 2.5
                                        * Referenced by: '<S214>/Valve_Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T RateLimiter_RisingLim;        /* Expression: 45
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Expression: -45
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 0.05
                                        * Referenced by: '<S214>/Gain'
                                        */
  real_T p_Vlo_TCP_min_rpm_Value;      /* Expression: 2100
                                        * Referenced by: '<Root>/p_Vlo_TCP_min_rpm'
                                        */
  real_T Constant2_Value_c;            /* Expression: 100e3
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 40
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S186>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S186>/White Noise'
                                        */
  real32_T Constant_Value_a4;          /* Computed Parameter: Constant_Value_a4
                                        * Referenced by: '<S50>/Constant'
                                        */
  int8_T Constant_Value_i;             /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S145>/Constant'
                                        */
  int8_T Constant2_Value_f;            /* Computed Parameter: Constant2_Value_f
                                        * Referenced by: '<S145>/Constant2'
                                        */
  int8_T Constant3_Value_h;            /* Computed Parameter: Constant3_Value_h
                                        * Referenced by: '<S145>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S145>/Constant4'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S4>/Manual Switch'
                               */
  boolean_T Constant_Value_g;          /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S185>/Constant'
                                        */
};

/* Storage class 'PageSwitching' */
extern thermal_closed_loop_mo_cal_type thermal_closed_loop_mo_cal_impl;
extern thermal_closed_loop_mo_cal_type *thermal_closed_loop_model_cal;

#endif                         /* RTW_HEADER_thermal_closed_loop_model_cal_h_ */
