/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_dxy_p.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_dxy_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static int32_T _cg_const_1[149] = { 0, 2, 2, 2, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5,
    5, 5, 6, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 12, 12, 12, 12,
    12, 12, 12, 14, 16, 17, 18, 18, 18, 18, 19, 19, 19, 20, 21, 21, 21, 21, 21,
    21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    22, 23, 24, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 28, 30, 30, 31, 32, 33,
    34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 35, 36, 36, 36, 36,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 };

  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  (void)LC;
  out = t2->mDXY_P;
  out.mNumCol = 148ULL;
  out.mNumRow = 27ULL;
  for (b = 0; b < 149; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 5;
  out.mIr[1] = 7;
  out.mIr[2] = 0;
  out.mIr[3] = 3;
  out.mIr[4] = 12;
  out.mIr[5] = 10;
  out.mIr[6] = 14;
  out.mIr[7] = 5;
  out.mIr[8] = 8;
  out.mIr[9] = 5;
  out.mIr[10] = 2;
  out.mIr[11] = 6;
  out.mIr[12] = 12;
  out.mIr[13] = 26;
  out.mIr[14] = 12;
  out.mIr[15] = 25;
  out.mIr[16] = 4;
  out.mIr[17] = 4;
  out.mIr[18] = 4;
  out.mIr[19] = 3;
  out.mIr[20] = 3;
  out.mIr[21] = 13;
  out.mIr[22] = 18;
  out.mIr[23] = 17;
  out.mIr[24] = 24;
  out.mIr[25] = 23;
  out.mIr[26] = 16;
  out.mIr[27] = 20;
  out.mIr[28] = 16;
  out.mIr[29] = 19;
  out.mIr[30] = 15;
  out.mIr[31] = 16;
  out.mIr[32] = 14;
  out.mIr[33] = 14;
  out.mIr[34] = 22;
  out.mIr[35] = 21;
  (void)LC;
  (void)t2;
  return 0;
}
