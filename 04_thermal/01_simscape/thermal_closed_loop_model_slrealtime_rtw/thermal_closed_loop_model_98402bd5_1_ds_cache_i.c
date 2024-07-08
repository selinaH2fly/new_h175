/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_cache_i.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_cache_i(const NeDynamicSystem
  *LC, const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  int32_T M[214];
  int32_T t0[108];
  int32_T b;
  (void)LC;
  for (b = 0; b < 214; b++) {
    M[b] = t1->mM.mX[b];
  }

  out = t2->mCACHE_I;
  t0[0ULL] = (int32_T)(M[0ULL] != 0);
  t0[1ULL] = (int32_T)(M[1ULL] != 0);
  t0[2ULL] = (int32_T)(M[2ULL] != 0);
  t0[3ULL] = (int32_T)(M[3ULL] != 0);
  t0[4ULL] = (int32_T)(M[4ULL] != 0);
  t0[5ULL] = (int32_T)(M[5ULL] != 0);
  t0[6ULL] = (int32_T)(M[6ULL] != 0);
  t0[7ULL] = (int32_T)(M[7ULL] != 0);
  t0[8ULL] = (int32_T)(M[8ULL] != 0);
  t0[9ULL] = (int32_T)(M[9ULL] != 0);
  t0[10ULL] = (int32_T)(M[10ULL] != 0);
  t0[11ULL] = (int32_T)(M[11ULL] != 0);
  t0[12ULL] = (int32_T)(M[12ULL] != 0);
  t0[13ULL] = (int32_T)(M[13ULL] != 0);
  t0[14ULL] = (int32_T)(M[14ULL] != 0);
  t0[15ULL] = (int32_T)(M[15ULL] != 0);
  t0[16ULL] = (int32_T)(M[16ULL] != 0);
  t0[17ULL] = (int32_T)(M[17ULL] != 0);
  t0[18ULL] = (int32_T)(M[18ULL] != 0);
  t0[19ULL] = (int32_T)(M[19ULL] != 0);
  t0[20ULL] = (int32_T)(M[20ULL] != 0);
  t0[21ULL] = (int32_T)(M[21ULL] != 0);
  t0[22ULL] = (int32_T)(M[22ULL] != 0);
  t0[23ULL] = (int32_T)(M[23ULL] != 0);
  t0[24ULL] = (int32_T)(M[24ULL] != 0);
  t0[25ULL] = (int32_T)(M[25ULL] != 0);
  t0[26ULL] = (int32_T)(M[26ULL] != 0);
  t0[27ULL] = (int32_T)(M[27ULL] != 0);
  t0[28ULL] = (int32_T)(M[28ULL] != 0);
  t0[29ULL] = (int32_T)(M[29ULL] != 0);
  t0[30ULL] = (int32_T)(M[30ULL] != 0);
  t0[31ULL] = (int32_T)(M[31ULL] != 0);
  t0[32ULL] = (int32_T)(M[32ULL] != 0);
  t0[33ULL] = (int32_T)(M[33ULL] != 0);
  t0[34ULL] = (int32_T)(M[34ULL] != 0);
  t0[35ULL] = (int32_T)(M[35ULL] != 0);
  t0[36ULL] = (int32_T)(M[36ULL] != 0);
  t0[37ULL] = (int32_T)(M[37ULL] != 0);
  t0[38ULL] = (int32_T)(M[38ULL] != 0);
  t0[39ULL] = (int32_T)(M[39ULL] != 0);
  t0[40ULL] = (int32_T)(M[40ULL] != 0);
  t0[41ULL] = (int32_T)(M[41ULL] != 0);
  t0[42ULL] = (int32_T)(M[42ULL] != 0);
  t0[43ULL] = (int32_T)(M[43ULL] != 0);
  t0[44ULL] = (int32_T)(M[44ULL] != 0);
  t0[45ULL] = (int32_T)(M[45ULL] != 0);
  t0[46ULL] = (int32_T)(M[46ULL] != 0);
  t0[47ULL] = (int32_T)(M[47ULL] != 0);
  t0[48ULL] = (int32_T)(M[48ULL] != 0);
  t0[49ULL] = (int32_T)(M[49ULL] != 0);
  t0[50ULL] = (int32_T)(M[50ULL] != 0);
  t0[51ULL] = (int32_T)(M[51ULL] != 0);
  t0[52ULL] = (int32_T)(M[52ULL] != 0);
  t0[53ULL] = (int32_T)(M[53ULL] != 0);
  t0[54ULL] = (int32_T)(M[54ULL] != 0);
  t0[55ULL] = (int32_T)(M[55ULL] != 0);
  t0[56ULL] = (int32_T)(M[56ULL] != 0);
  t0[57ULL] = (int32_T)(M[57ULL] != 0);
  t0[58ULL] = (int32_T)(M[58ULL] != 0);
  t0[59ULL] = (int32_T)(M[59ULL] != 0);
  t0[60ULL] = (int32_T)(M[60ULL] != 0);
  t0[61ULL] = (int32_T)(M[61ULL] != 0);
  t0[62ULL] = (int32_T)(M[62ULL] != 0);
  t0[63ULL] = (int32_T)(M[63ULL] != 0);
  t0[64ULL] = (int32_T)(M[64ULL] != 0);
  t0[65ULL] = (int32_T)(M[65ULL] != 0);
  t0[66ULL] = (int32_T)(M[66ULL] != 0);
  t0[67ULL] = (int32_T)(M[67ULL] != 0);
  t0[68ULL] = (int32_T)(M[68ULL] != 0);
  t0[69ULL] = (int32_T)(M[69ULL] != 0);
  t0[70ULL] = (int32_T)(M[70ULL] != 0);
  t0[71ULL] = (int32_T)(M[71ULL] != 0);
  t0[72ULL] = (int32_T)(M[72ULL] != 0);
  t0[73ULL] = (int32_T)(M[73ULL] != 0);
  t0[74ULL] = (int32_T)(M[74ULL] != 0);
  t0[75ULL] = (int32_T)(M[75ULL] != 0);
  t0[76ULL] = (int32_T)(M[76ULL] != 0);
  t0[77ULL] = (int32_T)(M[77ULL] != 0);
  t0[78ULL] = (int32_T)(M[78ULL] != 0);
  t0[79ULL] = (int32_T)(M[79ULL] != 0);
  t0[80ULL] = (int32_T)(M[80ULL] != 0);
  t0[81ULL] = (int32_T)(M[81ULL] != 0);
  t0[82ULL] = (int32_T)(M[82ULL] != 0);
  t0[83ULL] = (int32_T)(M[83ULL] != 0);
  t0[84ULL] = (int32_T)(M[84ULL] != 0);
  t0[85ULL] = (int32_T)(M[85ULL] != 0);
  t0[86ULL] = (int32_T)(M[86ULL] != 0);
  t0[87ULL] = (int32_T)(M[87ULL] != 0);
  t0[88ULL] = (int32_T)(M[88ULL] != 0);
  t0[89ULL] = (int32_T)(M[89ULL] != 0);
  t0[90ULL] = (int32_T)(M[90ULL] != 0);
  t0[91ULL] = (int32_T)(M[91ULL] != 0);
  t0[92ULL] = (int32_T)(M[92ULL] != 0);
  t0[93ULL] = (int32_T)(M[93ULL] != 0);
  t0[94ULL] = (int32_T)(M[94ULL] != 0);
  t0[95ULL] = (int32_T)(M[95ULL] != 0);
  t0[96ULL] = (int32_T)(M[96ULL] != 0);
  t0[97ULL] = (int32_T)(M[97ULL] != 0);
  t0[98ULL] = (int32_T)(M[98ULL] != 0);
  t0[99ULL] = (int32_T)(M[99ULL] != 0);
  t0[100ULL] = (int32_T)(M[100ULL] != 0);
  t0[101ULL] = (int32_T)(M[101ULL] != 0);
  t0[102ULL] = (int32_T)(M[102ULL] != 0);
  t0[103ULL] = (int32_T)(M[103ULL] != 0);
  t0[104ULL] = (int32_T)(M[104ULL] != 0);
  t0[105ULL] = (int32_T)(M[105ULL] != 0);
  t0[106ULL] = (int32_T)(M[106ULL] != 0);
  t0[107ULL] = (int32_T)(M[107ULL] != 0);
  for (b = 0; b < 108; b++) {
    out.mX[b] = t0[b];
  }

  (void)LC;
  (void)t2;
  return 0;
}
