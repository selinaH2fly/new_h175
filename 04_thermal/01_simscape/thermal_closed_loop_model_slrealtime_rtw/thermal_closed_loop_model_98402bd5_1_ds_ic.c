/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_ic.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_ic(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T t0[148];
  real_T P_R_idx_0;
  int32_T b;
  (void)LC;
  P_R_idx_0 = t1->mP_R.mX[0];
  out = t2->mIC;
  t0[0ULL] = 0.0;
  t0[1ULL] = 293.15;
  t0[2ULL] = 0.08;
  t0[3ULL] = 0.0;
  t0[4ULL] = 0.0;
  t0[5ULL] = 1.1132499999999999;
  t0[6ULL] = 293.15;
  t0[7ULL] = 0.0;
  t0[8ULL] = 0.0;
  t0[9ULL] = 0.0;
  t0[10ULL] = 293.15;
  t0[11ULL] = 1.1132499999999999;
  t0[12ULL] = P_R_idx_0;
  t0[13ULL] = 1.1132499999999999;
  t0[14ULL] = 293.15;
  t0[15ULL] = 0.0;
  t0[16ULL] = 0.0;
  t0[17ULL] = 1.1132499999999999;
  t0[18ULL] = 293.15;
  t0[19ULL] = 1.1132499999999999;
  t0[20ULL] = 293.15;
  t0[21ULL] = 300.0;
  t0[22ULL] = 300.0;
  t0[23ULL] = 1.0;
  t0[24ULL] = 0.0;
  t0[25ULL] = 0.0;
  t0[26ULL] = 0.0;
  t0[27ULL] = 0.0;
  t0[28ULL] = 300.0;
  t0[29ULL] = 0.0;
  t0[30ULL] = 85.0;
  t0[31ULL] = 300.0;
  t0[32ULL] = 0.0;
  t0[33ULL] = 0.0;
  t0[34ULL] = 300.0;
  t0[35ULL] = 1.0;
  t0[36ULL] = 85.0;
  t0[37ULL] = 300.0;
  t0[38ULL] = 1.0;
  t0[39ULL] = 300.0;
  t0[40ULL] = 1.0;
  t0[41ULL] = 300.0;
  t0[42ULL] = 1.0;
  t0[43ULL] = 300.0;
  t0[44ULL] = 1.0;
  t0[45ULL] = 300.0;
  t0[46ULL] = 0.0;
  t0[47ULL] = 85.0;
  t0[48ULL] = 300.0;
  t0[49ULL] = 300.0;
  t0[50ULL] = 1.0;
  t0[51ULL] = 0.0;
  t0[52ULL] = 293.15;
  t0[53ULL] = 300.0;
  t0[54ULL] = 1.0;
  t0[55ULL] = 0.0;
  t0[56ULL] = 0.0;
  t0[57ULL] = 0.0;
  t0[58ULL] = 300.0;
  t0[59ULL] = 85.0;
  t0[60ULL] = 300.0;
  t0[61ULL] = 85.0;
  t0[62ULL] = 300.0;
  t0[63ULL] = 300.0;
  t0[64ULL] = 300.0;
  t0[65ULL] = 85.0;
  t0[66ULL] = 0.0;
  t0[67ULL] = 0.0;
  t0[68ULL] = 0.0;
  t0[69ULL] = 0.0;
  t0[70ULL] = 0.0;
  t0[71ULL] = 0.0;
  t0[72ULL] = 1.01325;
  t0[73ULL] = 300.0;
  t0[74ULL] = 300.0;
  t0[75ULL] = 300.0;
  t0[76ULL] = 85.0;
  t0[77ULL] = 0.0;
  t0[78ULL] = 0.0;
  t0[79ULL] = 0.0;
  t0[80ULL] = 0.0;
  t0[81ULL] = 0.0;
  t0[82ULL] = 0.0;
  t0[83ULL] = 1.01325;
  t0[84ULL] = 0.0;
  t0[85ULL] = 0.0;
  t0[86ULL] = 300.0;
  t0[87ULL] = 300.0;
  t0[88ULL] = 1.0;
  t0[89ULL] = 1000.0;
  t0[90ULL] = 1000.0;
  t0[91ULL] = 85.0;
  t0[92ULL] = 85.0;
  t0[93ULL] = 85.0;
  t0[94ULL] = 300.0;
  t0[95ULL] = 1.0;
  t0[96ULL] = 300.0;
  t0[97ULL] = 1.0;
  t0[98ULL] = 0.0;
  t0[99ULL] = 0.0;
  t0[100ULL] = 0.0;
  t0[101ULL] = 0.0;
  t0[102ULL] = 300.0;
  t0[103ULL] = 85.0;
  t0[104ULL] = 300.0;
  t0[105ULL] = 85.0;
  t0[106ULL] = 300.0;
  t0[107ULL] = 1.0;
  t0[108ULL] = 0.0;
  t0[109ULL] = 0.0;
  t0[110ULL] = 0.0;
  t0[111ULL] = 300.0;
  t0[112ULL] = 1.0;
  t0[113ULL] = 293.15;
  t0[114ULL] = 293.15;
  t0[115ULL] = 300.0;
  t0[116ULL] = 85.0;
  t0[117ULL] = 300.0;
  t0[118ULL] = 85.0;
  t0[119ULL] = 300.0;
  t0[120ULL] = 1.0;
  t0[121ULL] = 0.0;
  t0[122ULL] = 300.0;
  t0[123ULL] = 85.0;
  t0[124ULL] = 300.0;
  t0[125ULL] = 85.0;
  t0[126ULL] = 300.0;
  t0[127ULL] = 1.0;
  t0[128ULL] = 300.0;
  t0[129ULL] = 85.0;
  t0[130ULL] = 300.0;
  t0[131ULL] = 300.0;
  t0[132ULL] = 85.0;
  t0[133ULL] = 300.0;
  t0[134ULL] = 300.0;
  t0[135ULL] = 85.0;
  t0[136ULL] = 300.0;
  t0[137ULL] = 300.0;
  t0[138ULL] = 300.0;
  t0[139ULL] = 300.0;
  t0[140ULL] = 85.0;
  t0[141ULL] = 0.0;
  t0[142ULL] = 0.0;
  t0[143ULL] = 0.0;
  t0[144ULL] = 0.0;
  t0[145ULL] = 0.0;
  t0[146ULL] = 0.0;
  t0[147ULL] = 1.01325;
  for (b = 0; b < 148; b++) {
    out.mX[b] = t0[b];
  }

  (void)LC;
  (void)t2;
  return 0;
}
