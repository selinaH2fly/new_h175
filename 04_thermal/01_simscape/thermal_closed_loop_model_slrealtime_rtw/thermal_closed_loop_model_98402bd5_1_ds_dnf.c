/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_dnf.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_dnf(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t19, NeDsMethodOutput *t20)
{
  PmRealVector out;
  (void)t19;
  (void)LC;
  out = t20->mDNF;
  out.mX[0] = -1.0;
  out.mX[1] = -1.0;
  out.mX[2] = -1.0;
  out.mX[3] = -1.0;
  out.mX[4] = -12224.976389752;
  out.mX[5] = -1.0;
  out.mX[6] = -1.0;
  out.mX[7] = -6112.488194876;
  out.mX[8] = -1.0;
  out.mX[9] = 0.001;
  out.mX[10] = -0.29571637104481052;
  out.mX[11] = -0.29571637104481052;
  out.mX[12] = -12.224976389752001;
  out.mX[13] = -0.29571637104481052;
  out.mX[14] = -0.29571637104481052;
  out.mX[15] = -1.0;
  out.mX[16] = -0.001;
  out.mX[17] = -0.02721833436436754;
  out.mX[18] = -0.29571637104481052;
  out.mX[19] = -0.29571637104481052;
  out.mX[20] = -1.0;
  out.mX[21] = -1.0;
  out.mX[22] = -0.29571637104481052;
  out.mX[23] = -0.29571637104481052;
  out.mX[24] = -12224.976389752;
  out.mX[25] = -1.0E-5;
  out.mX[26] = -0.29571637104481047;
  out.mX[27] = -9.9999999810672728E-6;
  out.mX[28] = -12.224976389752001;
  out.mX[29] = 0.001;
  out.mX[30] = -1.0;
  out.mX[31] = -0.02721833436436754;
  out.mX[32] = -6.1124881948760006;
  (void)LC;
  (void)t20;
  return 0;
}
