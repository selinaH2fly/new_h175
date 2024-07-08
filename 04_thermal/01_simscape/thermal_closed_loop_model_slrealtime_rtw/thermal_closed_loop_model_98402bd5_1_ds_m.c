/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_m.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_m(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t214, NeDsMethodOutput *t215)
{
  ETTS0 b_efOut;
  ETTS0 e_efOut;
  ETTS0 eb_efOut;
  ETTS0 efOut;
  ETTS0 f_efOut;
  ETTS0 fb_efOut;
  ETTS0 l_efOut;
  ETTS0 m_efOut;
  ETTS0 p_efOut;
  ETTS0 q_efOut;
  ETTS0 t1;
  ETTS0 t10;
  ETTS0 t6;
  ETTS0 t8;
  ETTS0 t9;
  ETTS0 w_efOut;
  ETTS0 x_efOut;
  PmRealVector out;
  real_T X[148];
  real_T ab_efOut[1];
  real_T bb_efOut[1];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T d_efOut[1];
  real_T db_efOut[1];
  real_T g_efOut[1];
  real_T gb_efOut[1];
  real_T h_efOut[1];
  real_T hb_efOut[1];
  real_T i_efOut[1];
  real_T ib_efOut[1];
  real_T j_efOut[1];
  real_T jb_efOut[1];
  real_T k_efOut[1];
  real_T kb_efOut[1];
  real_T lb_efOut[1];
  real_T mb_efOut[1];
  real_T n_efOut[1];
  real_T o_efOut[1];
  real_T r_efOut[1];
  real_T s_efOut[1];
  real_T t152[1];
  real_T t_efOut[1];
  real_T u_efOut[1];
  real_T v_efOut[1];
  real_T y_efOut[1];
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I;
  real_T Basic_Peripherals_Pipe_TL3_dUdp;
  real_T Subsystem_Reference_Pipe_TL2_dUdT;
  real_T Subsystem_Reference_Pipe_TL4_dUdT;
  real_T Subsystem_Reference_Pipe_TL4_rho_I;
  real_T intrm_sf_mf_253;
  real_T t141_idx_0;
  real_T t174;
  real_T t176;
  real_T t177;
  real_T t178;
  real_T t179;
  real_T t182;
  real_T t183;
  real_T t185;
  real_T t186;
  real_T t188;
  real_T t190;
  real_T t193;
  real_T t194;
  real_T t195;
  real_T t196;
  real_T t198;
  real_T t200;
  real_T t201;
  real_T t209;
  real_T t213;
  size_t t13[1];
  size_t t14[1];
  size_t t16[1];
  int32_T b;
  for (b = 0; b < 148; b++) {
    X[b] = t214->mX.mX[b];
  }

  out = t215->mM;
  t152[0ULL] = X[1ULL];
  t13[0] = 20ULL;
  t14[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL], &t13
    [0ULL], &t14[0ULL]);
  t8 = efOut;
  t152[0ULL] = X[0ULL] * -0.8 + 1.1132499999999999;
  t16[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = c_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I = t141_idx_0;
  tlu2_2d_linear_linear_value(&d_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = d_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I = t141_idx_0;
  t152[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = e_efOut;
  t152[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&f_efOut.mField0[0ULL], &f_efOut.mField1[0ULL],
    &f_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = f_efOut;
  tlu2_2d_linear_linear_value(&g_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = g_efOut[0];
  t176 = t141_idx_0;
  tlu2_2d_linear_linear_value(&h_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = h_efOut[0];
  t174 = t141_idx_0;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = i_efOut[0];
  Basic_Peripherals_Pipe_TL3_dUdp = t141_idx_0;
  tlu2_2d_linear_linear_value(&j_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = j_efOut[0];
  t177 = t141_idx_0;
  tlu2_2d_linear_linear_value(&k_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = k_efOut[0];
  intrm_sf_mf_253 = X[5ULL] / (t177 == 0.0 ? 1.0E-16 : t177) * 100.0 +
    t141_idx_0;
  t178 = (Basic_Peripherals_Pipe_TL3_dUdp - t176 * intrm_sf_mf_253 * 1000.0) *
    t177 * 0.0019634954084936209;
  Basic_Peripherals_Pipe_TL3_dUdp = (intrm_sf_mf_253 * t177 / (t174 == 0.0 ?
    1.0E-16 : t174) * 0.01 - X[6ULL] * t176) * 0.0019634954084936209;
  t152[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&l_efOut.mField0[0ULL], &l_efOut.mField1[0ULL],
    &l_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t9 = l_efOut;
  t152[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t6 = m_efOut;
  tlu2_2d_linear_linear_value(&n_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = n_efOut[0];
  intrm_sf_mf_253 = t141_idx_0;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = o_efOut[0];
  t193 = t141_idx_0;
  t152[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = p_efOut;
  t152[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = r_efOut[0];
  t194 = t141_idx_0;
  tlu2_2d_linear_linear_value(&s_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = s_efOut[0];
  t182 = t141_idx_0;
  tlu2_2d_linear_linear_value(&t_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = t_efOut[0];
  t183 = t141_idx_0;
  tlu2_2d_linear_linear_value(&u_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = u_efOut[0];
  t185 = t141_idx_0;
  tlu2_2d_linear_linear_value(&v_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = v_efOut[0];
  t188 = X[13ULL] / (t185 == 0.0 ? 1.0E-16 : t185) * 100.0 + t141_idx_0;
  t186 = (t183 - t194 * t188 * 1000.0) * t185 * 0.0051961524227066326;
  t183 = (t188 * t185 / (t182 == 0.0 ? 1.0E-16 : t182) * 0.01 - X[14ULL] * t194)
    * 0.0051961524227066326;
  t152[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = w_efOut;
  t152[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t1 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = y_efOut[0];
  t188 = t141_idx_0;
  tlu2_2d_linear_linear_value(&ab_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = ab_efOut[0];
  t195 = t141_idx_0;
  tlu2_2d_linear_linear_value(&bb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = bb_efOut[0];
  t196 = t141_idx_0;
  tlu2_2d_linear_linear_value(&cb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = cb_efOut[0];
  t190 = t141_idx_0;
  tlu2_2d_linear_linear_value(&db_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t141_idx_0 = db_efOut[0];
  t141_idx_0 += X[17ULL] / (t190 == 0.0 ? 1.0E-16 : t190) * 100.0;
  Subsystem_Reference_Pipe_TL2_dUdT = (t196 - t188 * t141_idx_0 * 1000.0) * t190
    * 0.00098174770424681044;
  t196 = (t141_idx_0 * t190 / (t195 == 0.0 ? 1.0E-16 : t195) * 0.01 - X[18ULL] *
          t188) * 0.00098174770424681044;
  t152[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t152[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = eb_efOut;
  t152[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&fb_efOut.mField0[0ULL], &fb_efOut.mField1[0ULL],
    &fb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t152[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = fb_efOut;
  tlu2_2d_linear_linear_value(&gb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = gb_efOut[0];
  t141_idx_0 = t152[0ULL];
  tlu2_2d_linear_linear_value(&hb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = hb_efOut[0];
  t213 = t152[0ULL];
  tlu2_2d_linear_linear_value(&ib_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = ib_efOut[0];
  t198 = t152[0ULL];
  tlu2_2d_linear_linear_value(&jb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = jb_efOut[0];
  Subsystem_Reference_Pipe_TL4_rho_I = t152[0ULL];
  tlu2_2d_linear_linear_value(&kb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = kb_efOut[0];
  Subsystem_Reference_Pipe_TL4_dUdT = t152[0ULL];
  t209 = X[19ULL] / (Subsystem_Reference_Pipe_TL4_rho_I == 0.0 ? 1.0E-16 :
                     Subsystem_Reference_Pipe_TL4_rho_I) * 100.0 +
    Subsystem_Reference_Pipe_TL4_dUdT;
  Subsystem_Reference_Pipe_TL4_dUdT = (t198 - t141_idx_0 * t209 * 1000.0) *
    Subsystem_Reference_Pipe_TL4_rho_I * 0.00098174770424681044;
  t198 = (t209 * Subsystem_Reference_Pipe_TL4_rho_I / (t213 == 0.0 ? 1.0E-16 :
           t213) * 0.01 - X[20ULL] * t141_idx_0) * 0.00098174770424681044;
  tlu2_2d_linear_linear_value(&lb_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = lb_efOut[0];
  t209 = t152[0ULL];
  tlu2_2d_linear_linear_value(&mb_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t152[0] = mb_efOut[0];
  t179 = t152[0ULL];
  t200 = X[11ULL] / (t193 == 0.0 ? 1.0E-16 : t193) * 100.0 + X[93ULL];
  t201 = (intrm_sf_mf_253 - t179 * t200 * 1000.0) * t193 * 0.0003375;
  intrm_sf_mf_253 = (t193 * t200 / (t209 == 0.0 ? 1.0E-16 : t209) * 0.01 - X
                     [10ULL] * t179) * 0.0003375;
  t200 = 1.0 / (t174 == 0.0 ? 1.0E-16 : t174) * t177 * 0.0019634954084936209;
  t174 = Basic_Peripherals_Pipe_TL3_dUdp * 100.0 / 7.0639122278786468;
  Basic_Peripherals_Pipe_TL3_dUdp = -t176 * t177 * 0.0019634954084936209;
  t177 = -t179 * t193 * 0.0003375;
  t179 = 1.0 / (t209 == 0.0 ? 1.0E-16 : t209) * t193 * 0.0003375;
  intrm_sf_mf_253 = intrm_sf_mf_253 * 100.0 / 1.1978799206025905;
  t193 = 1.0 / (t182 == 0.0 ? 1.0E-16 : t182) * t185 * 0.0051961524227066326;
  t182 = t183 * 100.0 / 18.693786844573559;
  t183 = -t194 * t185 * 0.0051961524227066326;
  t185 = 1.0 / (t195 == 0.0 ? 1.0E-16 : t195) * t190 * 0.00098174770424681044;
  out.mX[0] = -0.08;
  out.mX[1] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I *
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I * (X[2ULL] + 0.001) *
    0.001 / 291.40147251301789;
  out.mX[2] = 1.0;
  out.mX[3] = 1.0;
  out.mX[4] = -1.0;
  out.mX[5] = t200;
  out.mX[6] = t174;
  out.mX[7] = Basic_Peripherals_Pipe_TL3_dUdp;
  out.mX[8] = t178 * 0.001 / 7.0639122278786468;
  out.mX[9] = -1.0;
  out.mX[10] = -1.0;
  out.mX[11] = -1.0;
  out.mX[12] = t177;
  out.mX[13] = t201 * 0.001 / 1.1978799206025905;
  out.mX[14] = t179;
  out.mX[15] = intrm_sf_mf_253;
  out.mX[16] = -1.0;
  out.mX[17] = t193;
  out.mX[18] = t182;
  out.mX[19] = t183;
  out.mX[20] = t186 * 0.001 / 18.693786844573559;
  out.mX[21] = 1.0;
  out.mX[22] = -1.0;
  out.mX[23] = t185;
  out.mX[24] = t196 * 100.0 / 3.5319561139393234;
  out.mX[25] = -t188 * t190 * 0.00098174770424681044;
  out.mX[26] = Subsystem_Reference_Pipe_TL2_dUdT * 0.001 / 3.5319561139393234;
  out.mX[27] = 1.0 / (t213 == 0.0 ? 1.0E-16 : t213) *
    Subsystem_Reference_Pipe_TL4_rho_I * 0.00098174770424681044;
  out.mX[28] = t198 * 100.0 / 3.5319561139393234;
  out.mX[29] = -t141_idx_0 * Subsystem_Reference_Pipe_TL4_rho_I *
    0.00098174770424681044;
  out.mX[30] = Subsystem_Reference_Pipe_TL4_dUdT * 0.001 / 3.5319561139393234;
  (void)LC;
  (void)t215;
  return 0;
}
