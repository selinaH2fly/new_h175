/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_slv.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_slv(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static boolean_T _cg_const_1[148] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, false, false, false, false, false, false, false, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, false };

  PmBoolVector out;
  int32_T b;
  boolean_T t0[148];
  (void)t1;
  (void)LC;
  out = t2->mSLV;
  for (b = 0; b < 148; b++) {
    t0[b] = _cg_const_1[b];
  }

  for (b = 0; b < 148; b++) {
    out.mX[b] = t0[b];
  }

  (void)LC;
  (void)t2;
  return 0;
}
