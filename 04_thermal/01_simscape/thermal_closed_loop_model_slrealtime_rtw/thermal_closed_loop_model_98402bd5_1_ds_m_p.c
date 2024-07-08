/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_m_p.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_m_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static int32_T _cg_const_1[149] = { 0, 1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 14, 16,
    17, 19, 21, 22, 23, 25, 27, 29, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31 };

  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  (void)LC;
  out = t2->mM_P;
  out.mNumCol = 148ULL;
  out.mNumRow = 148ULL;
  for (b = 0; b < 149; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 7;
  out.mIr[1] = 6;
  out.mIr[2] = 5;
  out.mIr[3] = 8;
  out.mIr[4] = 0;
  out.mIr[5] = 9;
  out.mIr[6] = 10;
  out.mIr[7] = 9;
  out.mIr[8] = 10;
  out.mIr[9] = 3;
  out.mIr[10] = 1;
  out.mIr[11] = 2;
  out.mIr[12] = 11;
  out.mIr[13] = 12;
  out.mIr[14] = 11;
  out.mIr[15] = 12;
  out.mIr[16] = 15;
  out.mIr[17] = 13;
  out.mIr[18] = 14;
  out.mIr[19] = 13;
  out.mIr[20] = 14;
  out.mIr[21] = 16;
  out.mIr[22] = 4;
  out.mIr[23] = 17;
  out.mIr[24] = 18;
  out.mIr[25] = 17;
  out.mIr[26] = 18;
  out.mIr[27] = 19;
  out.mIr[28] = 20;
  out.mIr[29] = 19;
  out.mIr[30] = 20;
  (void)LC;
  (void)t2;
  return 0;
}
