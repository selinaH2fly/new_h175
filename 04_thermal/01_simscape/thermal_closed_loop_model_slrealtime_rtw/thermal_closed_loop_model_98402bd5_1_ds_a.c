/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_a.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_a(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t266, NeDsMethodOutput *t267)
{
  PmRealVector out;
  real_T t0[161];
  real_T t42[4];
  real_T t5[4];
  size_t t106;
  int32_T b;
  (void)t266;
  (void)LC;
  out = t267->mA;
  t5[0ULL] = -1.0;
  t5[1ULL] = 1.0;
  t5[2ULL] = -1.0;
  t5[3ULL] = -1.0;
  t42[0] = -1.0;
  t42[1] = -0.0004;
  t42[2] = 1.0;
  t42[3] = 1.0;
  t0[0ULL] = 0.79999999848538172;
  t0[1ULL] = -0.8;
  t0[2ULL] = -1.0;
  t0[3ULL] = 1.0;
  t0[4ULL] = -1.0;
  t0[5ULL] = -1.0;
  t0[6ULL] = -1.0;
  t0[7ULL] = 1.0;
  for (t106 = 0ULL; t106 < 4ULL; t106++) {
    t0[t106 + 8ULL] = t5[t106];
  }

  t0[12ULL] = 1.0;
  t0[13ULL] = 1.0;
  t0[14ULL] = -1.0;
  t0[15ULL] = -1.0;
  t0[16ULL] = -1.0;
  t0[17ULL] = -1.0;
  t0[18ULL] = -1.0;
  t0[19ULL] = 1.0;
  t0[20ULL] = -1.0;
  t0[21ULL] = -1.0;
  t0[22ULL] = -1.0;
  t0[23ULL] = -1.0;
  t0[24ULL] = 0.99999999810672713;
  t0[25ULL] = 1.0;
  t0[26ULL] = 0.0034316916499292109;
  t0[27ULL] = -1.0;
  t0[28ULL] = 0.83480821641701153;
  t0[29ULL] = -1.0;
  t0[30ULL] = 0.83480821641701153;
  t0[31ULL] = -1.0;
  t0[32ULL] = 1.0;
  t0[33ULL] = -1.0;
  t0[34ULL] = 0.000935780420948944;
  t0[35ULL] = 1.0;
  t0[36ULL] = 1.0;
  t0[37ULL] = 1.0;
  t0[38ULL] = 1.0;
  t0[39ULL] = 1.0;
  t0[40ULL] = 0.000935780420948944;
  t0[41ULL] = 0.29571637104481047;
  t0[42ULL] = 1.0;
  t0[43ULL] = 1.0;
  t0[44ULL] = 1.0;
  t0[45ULL] = 2.6837313365673137E-9;
  t0[46ULL] = 1.0;
  t0[47ULL] = -2.6837313365673137E-9;
  t0[48ULL] = 1.0;
  t0[49ULL] = 1.0;
  t0[50ULL] = 1.0;
  t0[51ULL] = 1.0;
  t0[52ULL] = 1.0;
  t0[53ULL] = 0.14156461288595434;
  t0[54ULL] = -0.83480821641701153;
  t0[55ULL] = 1.0;
  t0[56ULL] = 1.0;
  t0[57ULL] = -0.14156461288595434;
  t0[58ULL] = 0.05349370934387649;
  t0[59ULL] = -0.14156461288595434;
  t0[60ULL] = 0.28312922577190869;
  t0[61ULL] = -1.0;
  t0[62ULL] = 1.0;
  t0[63ULL] = 0.29571637104481052;
  t0[64ULL] = 0.29571637104481052;
  t0[65ULL] = 1.0;
  t0[66ULL] = -1.0;
  t0[67ULL] = 1.0;
  t0[68ULL] = -1.0;
  t0[69ULL] = 1.0;
  t0[70ULL] = -1.0;
  t0[71ULL] = -0.0004;
  t0[72ULL] = 1.0;
  t0[73ULL] = -1.0;
  t0[74ULL] = -0.0004;
  t0[75ULL] = 1.0;
  t0[76ULL] = -0.0004;
  t0[77ULL] = 1.0;
  t0[78ULL] = 1.0;
  t0[79ULL] = -1.0;
  t0[80ULL] = -1.0;
  t0[81ULL] = -1.0;
  t0[82ULL] = 1.0;
  t0[83ULL] = -1.0;
  t0[84ULL] = 1.0;
  t0[85ULL] = -1.0;
  t0[86ULL] = 1.0;
  t0[87ULL] = -1.0;
  t0[88ULL] = -0.0004;
  t0[89ULL] = 1.0;
  t0[90ULL] = -1.0;
  t0[91ULL] = -0.0004;
  t0[92ULL] = 1.0;
  for (t106 = 0ULL; t106 < 4ULL; t106++) {
    t0[t106 + 93ULL] = t42[t106];
  }

  t0[97ULL] = -1.0;
  t0[98ULL] = -1.0;
  t0[99ULL] = -1.0;
  t0[100ULL] = -0.83480821641701153;
  t0[101ULL] = 1.0;
  t0[102ULL] = 0.00059408600013748721;
  t0[103ULL] = 0.05443666872873508;
  t0[104ULL] = 1.0;
  t0[105ULL] = 1.0;
  t0[106ULL] = 3.8705519877353628E-8;
  t0[107ULL] = 0.29571637104481047;
  t0[108ULL] = 0.295716371044917;
  t0[109ULL] = 0.29571637104481047;
  t0[110ULL] = 0.29571637104481052;
  t0[111ULL] = 1.0;
  t0[112ULL] = 1.0;
  t0[113ULL] = 1.0;
  t0[114ULL] = 1.0;
  t0[115ULL] = 0.05349370934387649;
  t0[116ULL] = -0.28312922577190869;
  t0[117ULL] = 0.05349370934387649;
  t0[118ULL] = 0.038314176245210725;
  t0[119ULL] = 1.0;
  t0[120ULL] = 1.0;
  t0[121ULL] = -1.0;
  t0[122ULL] = -1.0;
  t0[123ULL] = 1.0;
  t0[124ULL] = 0.29571637104481052;
  t0[125ULL] = 0.29571637104481052;
  t0[126ULL] = 1.0;
  t0[127ULL] = 1.0;
  t0[128ULL] = -1.0;
  t0[129ULL] = 0.28312922577190869;
  t0[130ULL] = -1.0;
  t0[131ULL] = 1.0;
  t0[132ULL] = -1.0;
  t0[133ULL] = -1.0;
  t0[134ULL] = 1.0;
  t0[135ULL] = 1.0;
  t0[136ULL] = 0.29571637104481052;
  t0[137ULL] = 0.29571637104481052;
  t0[138ULL] = 1.0;
  t0[139ULL] = 0.28312922577190869;
  t0[140ULL] = -1.0;
  t0[141ULL] = 0.29571637104481052;
  t0[142ULL] = 0.29571637104481052;
  t0[143ULL] = -1.0;
  t0[144ULL] = 1.0;
  t0[145ULL] = -1.0;
  t0[146ULL] = 1.0;
  t0[147ULL] = -1.0;
  t0[148ULL] = 1.0;
  t0[149ULL] = -1.0;
  t0[150ULL] = -0.0004;
  t0[151ULL] = 1.0;
  t0[152ULL] = -1.0;
  t0[153ULL] = -0.0004;
  t0[154ULL] = 1.0;
  t0[155ULL] = -1.0;
  t0[156ULL] = -0.0004;
  t0[157ULL] = 1.0;
  t0[158ULL] = -1.0;
  t0[159ULL] = -1.0;
  t0[160ULL] = -1.0;
  for (b = 0; b < 161; b++) {
    out.mX[b] = t0[b];
  }

  (void)LC;
  (void)t267;
  return 0;
}
