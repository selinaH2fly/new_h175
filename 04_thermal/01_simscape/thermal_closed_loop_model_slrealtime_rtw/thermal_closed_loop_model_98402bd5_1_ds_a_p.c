/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_a_p.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_a_p(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  static int32_T _cg_const_2[161] = { 34, 88, 11, 61, 53, 54, 9, 140, 19, 71,
    128, 133, 71, 89, 87, 88, 97, 98, 19, 140, 106, 107, 115, 116, 34, 72, 6, 35,
    12, 35, 12, 35, 35, 122, 40, 71, 36, 5, 7, 11, 40, 39, 53, 142, 73, 45, 74,
    45, 64, 61, 89, 63, 87, 10, 12, 54, 62, 10, 14, 10, 20, 9, 61, 51, 52, 21,
    62, 22, 63, 23, 64, 21, 144, 0, 22, 144, 23, 144, 146, 62, 63, 64, 24, 72,
    25, 73, 26, 74, 24, 145, 1, 25, 145, 2, 26, 145, 146, 72, 73, 74, 12, 75, 84,
    85, 76, 77, 80, 82, 81, 83, 86, 97, 107, 98, 141, 14, 18, 14, 15, 94, 13, 17,
    13, 140, 95, 96, 106, 121, 123, 18, 122, 17, 19, 128, 115, 143, 104, 105,
    116, 20, 122, 113, 114, 121, 27, 141, 28, 142, 29, 143, 27, 147, 3, 28, 147,
    4, 29, 147, 141, 142, 143 };

  static int32_T _cg_const_1[149] = { 0, 2, 2, 2, 2, 4, 6, 6, 8, 12, 14, 14, 16,
    16, 18, 18, 18, 20, 22, 22, 24, 24, 24, 24, 26, 28, 30, 32, 34, 34, 36, 36,
    36, 37, 39, 39, 41, 42, 42, 44, 44, 45, 45, 47, 47, 49, 49, 51, 51, 51, 51,
    53, 55, 55, 55, 57, 59, 61, 63, 63, 64, 64, 65, 65, 65, 65, 65, 67, 69, 71,
    73, 76, 79, 82, 82, 82, 82, 82, 84, 86, 88, 90, 93, 97, 100, 102, 103, 103,
    103, 104, 105, 106, 108, 110, 111, 111, 113, 113, 115, 117, 120, 122, 124,
    124, 125, 125, 126, 126, 128, 129, 131, 134, 134, 136, 136, 136, 136, 137,
    137, 138, 138, 139, 141, 141, 142, 142, 143, 143, 144, 144, 144, 144, 144,
    144, 144, 144, 144, 144, 144, 144, 144, 144, 146, 148, 150, 152, 155, 158,
    161 };

  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  (void)LC;
  out = t2->mA_P;
  out.mNumCol = 148ULL;
  out.mNumRow = 148ULL;
  for (b = 0; b < 149; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  for (b = 0; b < 161; b++) {
    out.mIr[b] = _cg_const_2[b];
  }

  (void)LC;
  (void)t2;
  return 0;
}
