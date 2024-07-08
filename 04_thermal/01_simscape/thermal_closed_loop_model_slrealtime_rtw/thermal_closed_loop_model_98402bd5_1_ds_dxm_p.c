/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_dxm_p.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_dxm_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static int32_T _cg_const_1[149] = { 0, 1, 2, 3, 3, 3, 7, 11, 11, 11, 11, 15,
    19, 19, 23, 27, 27, 27, 31, 35, 39, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
    43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
    43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
    43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
    43, 43, 43, 43, 43, 43, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45 };

  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  (void)LC;
  out = t2->mDXM_P;
  out.mNumCol = 148ULL;
  out.mNumRow = 31ULL;
  for (b = 0; b < 149; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 1;
  out.mIr[1] = 1;
  out.mIr[2] = 1;
  out.mIr[3] = 5;
  out.mIr[4] = 6;
  out.mIr[5] = 7;
  out.mIr[6] = 8;
  out.mIr[7] = 5;
  out.mIr[8] = 6;
  out.mIr[9] = 7;
  out.mIr[10] = 8;
  out.mIr[11] = 12;
  out.mIr[12] = 13;
  out.mIr[13] = 14;
  out.mIr[14] = 15;
  out.mIr[15] = 12;
  out.mIr[16] = 13;
  out.mIr[17] = 14;
  out.mIr[18] = 15;
  out.mIr[19] = 17;
  out.mIr[20] = 18;
  out.mIr[21] = 19;
  out.mIr[22] = 20;
  out.mIr[23] = 17;
  out.mIr[24] = 18;
  out.mIr[25] = 19;
  out.mIr[26] = 20;
  out.mIr[27] = 23;
  out.mIr[28] = 24;
  out.mIr[29] = 25;
  out.mIr[30] = 26;
  out.mIr[31] = 23;
  out.mIr[32] = 24;
  out.mIr[33] = 25;
  out.mIr[34] = 26;
  out.mIr[35] = 27;
  out.mIr[36] = 28;
  out.mIr[37] = 29;
  out.mIr[38] = 30;
  out.mIr[39] = 27;
  out.mIr[40] = 28;
  out.mIr[41] = 29;
  out.mIr[42] = 30;
  out.mIr[43] = 13;
  out.mIr[44] = 15;
  (void)LC;
  (void)t2;
  return 0;
}
