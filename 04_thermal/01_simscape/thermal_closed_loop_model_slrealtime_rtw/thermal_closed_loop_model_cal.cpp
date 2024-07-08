#include "thermal_closed_loop_model_cal.h"
#include "thermal_closed_loop_model.h"

/* Storage class 'PageSwitching' */
thermal_closed_loop_mo_cal_type thermal_closed_loop_mo_cal_impl = {
  /* Start of '<S183>/CoreSubsys' */
  {
    /* Expression: 0.0
     * Referenced by: '<S183>/Variable Integer Delay'
     */
    0.0
  }
  ,

  /* End of '<S183>/CoreSubsys' */

  /* Start of '<S3>/controlBontazTCV' */
  {
    /* Expression: [0  2   91  95 99 100]
     * Referenced by: '<S55>/1-D Lookup Table'
     */
    { 0.0, 2.0, 91.0, 95.0, 99.0, 100.0 },

    /* Expression: [5  10  70  73 80 100]
     * Referenced by: '<S55>/1-D Lookup Table'
     */
    { 5.0, 10.0, 70.0, 73.0, 80.0, 100.0 },

    /* Mask Parameter: DiscretePIDController_D
     * Referenced by: '<S83>/Derivative Gain'
     */
    0.0,

    /* Mask Parameter: DiscretePIDController_Different
     * Referenced by: '<S84>/UD'
     */
    0.0,

    /* Mask Parameter: DiscretePIDController_I
     * Referenced by: '<S88>/Integral Gain'
     */
    0.75,

    /* Mask Parameter: DiscretePIDController_InitialCo
     * Referenced by: '<S91>/Integrator'
     */
    0.0,

    /* Mask Parameter: LowPassFilterDiscreteorContinuo
     * Referenced by: '<S54>/K'
     */
    1.0,

    /* Mask Parameter: DiscretePIDController_LowerSatu
     * Referenced by:
     *   '<S98>/Saturation'
     *   '<S82>/DeadZone'
     */
    0.0,

    /* Mask Parameter: DiscretePIDController_P
     * Referenced by: '<S96>/Proportional Gain'
     */
    2.0,

    /* Mask Parameter: LowPassFilterDiscreteorContin_a
     * Referenced by: '<S108>/Time constant'
     */
    1.0,

    /* Mask Parameter: DiscretePIDController_UpperSatu
     * Referenced by:
     *   '<S98>/Saturation'
     *   '<S82>/DeadZone'
     */
    100.0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S111>/Constant'
     */
    2.0,

    /* Mask Parameter: CompareToConstant_const_c
     * Referenced by: '<S115>/Constant'
     */
    0.0,

    /* Mask Parameter: LowPassFilterDiscreteorContin_k
     * Referenced by: '<S108>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S80>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S80>/Clamping_zero'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S112>/Constant'
     */
    0.0,

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S114>/Integrator'
     */
    0.05,

    /* Computed Parameter: Integrator_gainval_a
     * Referenced by: '<S91>/Integrator'
     */
    0.05,

    /* Computed Parameter: Tsamp_WtEt
     * Referenced by: '<S86>/Tsamp'
     */
    20.0,

    /* Computed Parameter: Constant_Value_i
     * Referenced by: '<S80>/Constant'
     */
    1,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S80>/Constant2'
     */
    -1,

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S80>/Constant3'
     */
    1,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S80>/Constant4'
     */
    -1
  }
  ,

  /* End of '<S3>/controlBontazTCV' */

  /* Mask Parameter: BandLimitedWhiteNoise_Cov
   * Referenced by: '<S186>/Output'
   */
  { 0.005, 0.0005, 0.0005 },

  /* Expression: [ 8, 8,    8,    8,     8,    8,    8,    8,     9,   10,   11,   12,   13]
   * Referenced by: '<S51>/1-D Lookup Table1'
   */
  { 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0 },

  /* Expression: [0   50   100   150   200   250   300   350   400   425   450   475   500]
   * Referenced by: '<S51>/1-D Lookup Table1'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 425.0, 450.0,
    475.0, 500.0 },

  /* Expression: [58, 58,   62,   64,   66,   69,   72,  73,   73,   73,   73,   73,   73]
   * Referenced by: '<S52>/1-D Lookup Table1'
   */
  { 58.0, 58.0, 62.0, 64.0, 66.0, 69.0, 72.0, 73.0, 73.0, 73.0, 73.0, 73.0, 73.0
  },

  /* Expression: [0   50   100   150   200   250   300   350   400   425   450   475   500]
   * Referenced by: '<S52>/1-D Lookup Table1'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 425.0, 450.0,
    475.0, 500.0 },

  /* Expression: [1400, 1400, 1600, 1800, 2200, 2600, 2800, 2900, 2900, 2900, 2900, 2900, 2900, 2900]
   * Referenced by: '<S50>/LUT_FFWD_TCP'
   */
  { 1400.0, 1400.0, 1600.0, 1800.0, 2200.0, 2600.0, 2800.0, 2900.0, 2900.0,
    2900.0, 2900.0, 2900.0, 2900.0, 2900.0 },

  /* Expression: [   0,  100,  199,  200,  250,  300,  350,  399,  400,  420,  450,  480,  500,  600]
   * Referenced by: '<S50>/LUT_FFWD_TCP'
   */
  { 0.0, 100.0, 199.0, 200.0, 250.0, 300.0, 350.0, 399.0, 400.0, 420.0, 450.0,
    480.0, 500.0, 600.0 },

  /* Expression: zeros(1,3)
   * Referenced by: '<S4>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0, 9932, 21438, 33442,47123, 59491, 77033, 93585, 112042]
   * Referenced by: '<S2>/Current to Heat (W)'
   */
  { 0.0, 9932.0, 21438.0, 33442.0, 47123.0, 59491.0, 77033.0, 93585.0, 112042.0
  },

  /* Expression: [0:50:400]
   * Referenced by: '<S2>/Current to Heat (W)'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0 },

  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S149>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S154>/Integral Gain'
   */
  5.0,

  /* Mask Parameter: LowPassFilterDiscreteorContinuo
   * Referenced by: '<S117>/K'
   */
  1.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S162>/Proportional Gain'
   */
  50.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_b
   * Referenced by: '<S175>/Time constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S178>/Constant'
   */
  2.0,

  /* Mask Parameter: MovingAverageVariableFrequency_
   * Referenced by: '<S182>/Gain1'
   */
  100.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_f
   * Referenced by: '<S175>/Constant'
   */
  1.0,

  /* Mask Parameter: BandLimitedWhiteNoise_seed
   * Referenced by: '<S186>/White Noise'
   */
  23341.0,

  /* Mask Parameter: MovingAverageVariableFrequenc_d
   * Referenced by: '<S182>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S145>/Constant1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S185>/Out1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S185>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S145>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S179>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S181>/Integrator'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S120>/Unit Delay'
   */
  0.0,

  /* Expression: 1400
   * Referenced by: '<S50>/p_Emp_TCP_min_rpm'
   */
  1400.0,

  /* Expression: 3000
   * Referenced by: '<S50>/p_Emp_TCP_max_rpm'
   */
  3000.0,

  /* Expression: 0.1
   * Referenced by: '<S50>/p_Emp_STCL_FFWD_Filter_PER_s'
   */
  0.1,

  /* Expression: eps
   * Referenced by: '<S182>/Saturation'
   */
  2.2204460492503131E-16,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S182>/Discrete-Time Integrator'
   */
  0.025,

  /* Expression: 0
   * Referenced by: '<S182>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S182>/Gain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S182>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S182>/Constant2'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S157>/Integrator'
   */
  0.05,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S152>/Tsamp'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S184>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay16'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay11'
   */
  0.0,

  /* Expression: 273.15
   * Referenced by: '<S190>/Constant'
   */
  273.15,

  /* Expression: 273.15
   * Referenced by: '<S189>/Constant'
   */
  273.15,

  /* Expression: 273.15
   * Referenced by: '<S188>/Constant'
   */
  273.15,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 1e-5
   * Referenced by: '<S212>/Pa to Bar(a)'
   */
  1.0E-5,

  /* Expression: 1e-5
   * Referenced by: '<S211>/Pa to Bar(a)'
   */
  1.0E-5,

  /* Expression: 1e-5
   * Referenced by: '<S210>/Pa to Bar(a)'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay12'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay13'
   */
  0.0,

  /* Expression: 1e-5
   * Referenced by: '<S19>/Pa to Bar(a)'
   */
  1.0E-5,

  /* Expression: 273.15
   * Referenced by: '<S9>/Constant'
   */
  273.15,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay11'
   */
  0.0,

  /* Expression: 1e-5
   * Referenced by: '<S213>/Pa to Bar(a)'
   */
  1.0E-5,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  -0.5,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  0.5,

  /* Expression: 1000
   * Referenced by: '<S1>/Rate Limiter1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S1>/Rate Limiter1'
   */
  -1000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Bypass_Opening'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Constant'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S35>/Saturation'
   */
  0.0,

  /* Expression: 293.15
   * Referenced by: '<S1>/Constant1'
   */
  293.15,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S7>/Transfer Fcn2'
   */
  -0.5,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S7>/Transfer Fcn2'
   */
  0.5,

  /* Expression: 1000
   * Referenced by: '<S7>/Rate Limiter2'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S7>/Rate Limiter2'
   */
  -1000.0,

  /* Expression: 2.5
   * Referenced by: '<S214>/Valve_Constant'
   */
  2.5,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S7>/Transfer Fcn'
   */
  -5.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S7>/Transfer Fcn'
   */
  5.0,

  /* Expression: 45
   * Referenced by: '<S7>/Rate Limiter'
   */
  45.0,

  /* Expression: -45
   * Referenced by: '<S7>/Rate Limiter'
   */
  -45.0,

  /* Expression: 0.05
   * Referenced by: '<S214>/Gain'
   */
  0.05,

  /* Expression: 2100
   * Referenced by: '<Root>/p_Vlo_TCP_min_rpm'
   */
  2100.0,

  /* Expression: 100e3
   * Referenced by: '<S1>/Constant2'
   */
  100000.0,

  /* Expression: 40
   * Referenced by: '<S1>/Constant3'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S186>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S186>/White Noise'
   */
  1.0,

  /* Computed Parameter: Constant_Value_a4
   * Referenced by: '<S50>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S145>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_f
   * Referenced by: '<S145>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_h
   * Referenced by: '<S145>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S145>/Constant4'
   */
  -1,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S4>/Manual Switch'
   */
  0U,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S185>/Constant'
   */
  true
};

thermal_closed_loop_mo_cal_type *thermal_closed_loop_model_cal =
  &thermal_closed_loop_mo_cal_impl;
