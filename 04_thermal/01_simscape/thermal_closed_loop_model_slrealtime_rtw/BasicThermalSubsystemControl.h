/*
 * Code generation for system system '<Root>/BasicThermalSubsystemControl'
 * For more details, see corresponding source file BasicThermalSubsystemControl.c
 *
 */

#ifndef RTW_HEADER_BasicThermalSubsystemControl_h_
#define RTW_HEADER_BasicThermalSubsystemControl_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw_rtp.h"
#include "thermal_closed_loop_model_98402bd5_1_gateway.h"
#include "nesl_rtw.h"
#include "rt_zcfcn.h"

/* Block signals for system '<S182>/For Each Subsystem' */
struct B_CoreSubsys_thermal_closed_l_T {
  real_T VariableIntegerDelay;         /* '<S183>/Variable Integer Delay' */
};

/* Block states (default storage) for system '<S182>/For Each Subsystem' */
struct DW_CoreSubsys_thermal_closed__T {
  real_T VariableIntegerDelay_DSTATE[4096];/* '<S183>/Variable Integer Delay' */
};

extern void BasicThermalSubsystemC_Init(void);
extern void BasicThermalSubsyste_Enable(void);
extern void BasicThermalSubsystemContro(void);

#endif                          /* RTW_HEADER_BasicThermalSubsystemControl_h_ */
