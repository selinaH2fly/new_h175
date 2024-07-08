/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_duf.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_duf(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t318, NeDsMethodOutput *t319)
{
  ETTS0 ab_efOut;
  ETTS0 b_efOut;
  ETTS0 bb_efOut;
  ETTS0 d_efOut;
  ETTS0 db_efOut;
  ETTS0 e_efOut;
  ETTS0 eb_efOut;
  ETTS0 efOut;
  ETTS0 g_efOut;
  ETTS0 gb_efOut;
  ETTS0 h_efOut;
  ETTS0 ib_efOut;
  ETTS0 j_efOut;
  ETTS0 jb_efOut;
  ETTS0 k_efOut;
  ETTS0 lb_efOut;
  ETTS0 m_efOut;
  ETTS0 n_efOut;
  ETTS0 nb_efOut;
  ETTS0 ob_efOut;
  ETTS0 p_efOut;
  ETTS0 q_efOut;
  ETTS0 qb_efOut;
  ETTS0 s_efOut;
  ETTS0 sb_efOut;
  ETTS0 t11;
  ETTS0 t20;
  ETTS0 t22;
  ETTS0 t23;
  ETTS0 t26;
  ETTS0 t27;
  ETTS0 t7;
  ETTS0 tb_efOut;
  ETTS0 u_efOut;
  ETTS0 w_efOut;
  ETTS0 x_efOut;
  PmRealVector out;
  real_T X[148];
  real_T nonscalar12[8];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T f_efOut[1];
  real_T fb_efOut[1];
  real_T hb_efOut[1];
  real_T i_efOut[1];
  real_T kb_efOut[1];
  real_T l_efOut[1];
  real_T mb_efOut[1];
  real_T o_efOut[1];
  real_T pb_efOut[1];
  real_T r_efOut[1];
  real_T rb_efOut[1];
  real_T t190[1];
  real_T t_efOut[1];
  real_T ub_efOut[1];
  real_T v_efOut[1];
  real_T vb_efOut[1];
  real_T wb_efOut[1];
  real_T xb_efOut[1];
  real_T y_efOut[1];
  real_T Basic_Peripherals_Gate_Valve_TL_area_ratio;
  real_T Basic_Peripherals_Gate_Valve_TL_rho_avg;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R10;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T intermediate_der346;
  real_T intermediate_der348;
  real_T intermediate_der373;
  real_T intermediate_der728;
  real_T intermediate_der815;
  real_T intermediate_der85;
  real_T t208;
  real_T t218;
  real_T t220;
  real_T t222;
  real_T t225;
  real_T t226;
  real_T t228;
  real_T t230;
  real_T t232;
  real_T t234;
  real_T t236;
  real_T t238;
  real_T t239;
  real_T t240;
  real_T t241;
  real_T t269;
  real_T t270;
  real_T t278;
  real_T t286;
  real_T t290;
  real_T t297;
  real_T t301;
  real_T t304;
  real_T t307;
  real_T t308;
  real_T t311;
  real_T t312;
  real_T t313;
  real_T t315;
  real_T t316;
  real_T t317;
  size_t t157[1];
  size_t t160[1];
  size_t t31[1];
  size_t t84[1];
  int32_T b;
  boolean_T intrm_sf_mf_48;
  U_idx_0 = t318->mU.mX[0];
  U_idx_1 = t318->mU.mX[1];
  U_idx_2 = t318->mU.mX[2];
  U_idx_3 = t318->mU.mX[3];
  U_idx_4 = t318->mU.mX[4];
  U_idx_6 = t318->mU.mX[6];
  U_idx_7 = t318->mU.mX[7];
  for (b = 0; b < 148; b++) {
    X[b] = t318->mX.mX[b];
  }

  out = t319->mDUF;
  nonscalar12[0] = -209.43951023931953;
  nonscalar12[1] = 0.0;
  nonscalar12[2] = 209.43951023931953;
  nonscalar12[3] = 261.79938779914943;
  nonscalar12[4] = 314.15926535897933;
  nonscalar12[5] = 366.51914291880917;
  nonscalar12[6] = 418.87902047863906;
  nonscalar12[7] = 439.822971502571;
  t316 = U_idx_0 * 0.10471975511965977;
  t190[0ULL] = X[28ULL];
  t157[0] = 20ULL;
  t31[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = efOut;
  t190[0ULL] = X[0ULL] * -0.8 + 1.1132499999999999;
  t160[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t26.mField0[0ULL], &t26.mField2
    [0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = c_efOut[0];
  t208 = U_idx_0;
  t220 = pmf_sqrt(t316 * t316 + 13.433628212593847) + t316;
  t317 = t220 / 2.0;
  t220 = X[29ULL] / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  t307 = 366.51914291880917 / (t317 == 0.0 ? 1.0E-16 : t317) * t220;
  if (t307 < 0.0) {
    intermediate_der85 = 15.800203873598369;
  } else if (t307 * 1.0E+6 <= 1666.6666666666665) {
    intermediate_der85 = t307 * t307 * -1.2844036697247704E+6 +
      15.800203873598369;
  } else if (t307 * 1.0E+6 <= 3333.333333333333) {
    intermediate_der85 = (t307 * 1834.8623853211036 + t307 * t307 *
                          -1.8348623853211019E+6) + 14.271151885830777;
  } else {
    intermediate_der85 = (t307 * 1.0E+6 - 3333.333333333333) *
      -0.010397553516819574;
  }

  if (t307 < 0.0) {
    intermediate_der348 = 0.19375;
  } else if (t307 * 1.0E+6 <= 1666.6666666666665) {
    t315 = 3333.333333333333 - t307 * 1.0E+6;
    intermediate_der348 = (0.64583333333333326 - t307 * t307 *
      52499.999999999993) / (t315 == 0.0 ? 1.0E-16 : t315) * 1000.0;
  } else if (t307 * 1.0E+6 <= 3333.333333333333) {
    t225 = t307 * 1.0E+6;
    intermediate_der348 = (t307 * 75.000000000000028 + 0.17499999999999988) *
      t307 / (t225 == 0.0 ? 1.0E-16 : t225) * 1.0E+6;
  } else {
    intermediate_der348 = 0.42499999999999993;
  }

  t222 = intermediate_der348 / 366.51914291880917;
  t315 = U_idx_1 / 0.045000000000000005;
  if (t315 <= 0.0) {
    intermediate_der348 = 0.0;
  } else if (t315 <= 0.005) {
    intermediate_der348 = t315 * t315 * 100.50251256281406;
  } else if (t315 <= 0.995) {
    intermediate_der348 = t315 * 1.0050251256281406 - 0.0025125628140703518;
  } else if (t315 <= 1.0) {
    intermediate_der348 = (1.0 - t315) * (1.0 - t315) * -100.50251256281406 +
      1.0;
  } else {
    intermediate_der348 = 1.0;
  }

  intermediate_der373 = intermediate_der348 * 0.045000000000000005;
  if (intermediate_der373 / 0.045000000000000005 <= -1.0) {
    intermediate_der348 = -1.0;
  } else if (intermediate_der373 / 0.045000000000000005 >= 1.0) {
    intermediate_der348 = 1.0;
  } else {
    intermediate_der348 = intermediate_der373 / 0.045000000000000005;
  }

  t225 = pmf_acos(intermediate_der348) * 0.0010125000000000002 -
    intermediate_der373 / 2.0 * pmf_sqrt(0.0020250000000000003 -
    intermediate_der373 * intermediate_der373);
  Basic_Peripherals_Gate_Valve_TL_area_ratio = 0.0015904312808798331 - t225;
  t225 = (0.0015904312808798331 - t225) + 1.0E-12;
  Basic_Peripherals_Gate_Valve_TL_area_ratio =
    (Basic_Peripherals_Gate_Valve_TL_area_ratio + 1.0E-12) /
    0.0019634954084936209;
  t190[0ULL] = X[45ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = d_efOut;
  t190[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = e_efOut;
  tlu2_2d_linear_linear_value(&f_efOut[0ULL], &t26.mField0[0ULL], &t26.mField2
    [0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = f_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_rho_avg = U_idx_0;
  t190[0ULL] = X[48ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = g_efOut;
  t190[0ULL] = X[44ULL];
  tlu2_linear_linear_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t27 = h_efOut;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = i_efOut[0];
  intermediate_der346 = U_idx_0;
  t190[0ULL] = X[45ULL];
  tlu2_linear_nearest_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = j_efOut;
  t190[0ULL] = X[42ULL];
  tlu2_linear_nearest_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t27 = k_efOut;
  tlu2_2d_linear_nearest_value(&l_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = l_efOut[0];
  t308 = U_idx_0;
  t190[0ULL] = X[48ULL];
  tlu2_linear_nearest_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = m_efOut;
  t190[0ULL] = X[44ULL];
  tlu2_linear_nearest_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = n_efOut;
  tlu2_2d_linear_nearest_value(&o_efOut[0ULL], &t26.mField0[0ULL], &t26.mField2
    [0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = o_efOut[0];
  t308 = (t308 + U_idx_0) / 2.0;
  intermediate_der728 = pmf_sqrt(t225 * 0.78539816339744828) * t308 * 12.0;
  t226 = pmf_sqrt(X[46ULL] * X[46ULL] + intermediate_der728 *
                  intermediate_der728) * X[46ULL];
  Basic_Peripherals_Gate_Valve_TL_rho_avg =
    (Basic_Peripherals_Gate_Valve_TL_rho_avg + intermediate_der346) / 2.0;
  t218 = tanh(X[85ULL] * 3.0 / 0.029511607098668874) * X[85ULL];
  intermediate_der346 = U_idx_2 * 3.0;
  t228 = tanh(intermediate_der346 / 0.029511607098668874) * U_idx_2;
  intrm_sf_mf_48 = (t218 >= t228);
  t311 = intrm_sf_mf_48 ? t218 : t228;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 =
    intrm_sf_mf_48 ? t228 : t218;
  t312 = (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 +
          0.029511607098668874) / (t311 + 0.029511607098668874 == 0.0 ? 1.0E-16 :
    t311 + 0.029511607098668874);
  t230 = (-X[10ULL] + X[86ULL]) + X[87ULL];
  intermediate_der815 = U_idx_3 <= 0.01 ? 0.01 : U_idx_3;
  t232 = (X[88ULL] <= 5.0 ? 5.0 : X[88ULL]) * 0.47700000000000009;
  U_idx_1 = intermediate_der815 * 2.9881500000000005;
  t313 = (1.0 / (t232 == 0.0 ? 1.0E-16 : t232) + 1.0 / (U_idx_1 == 0.0 ? 1.0E-16
           : U_idx_1)) + 0.000163312919218431;
  t234 = t313 * 6.0;
  if (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 >= 1.0 /
      (t234 == 0.0 ? 1.0E-16 : t234)) {
    t297 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t313;
    t232 = pmf_exp(-1.0 / (t297 == 0.0 ? 1.0E-16 : t297));
  } else {
    t232 = 0.0024787521766663585;
  }

  U_idx_1 = (1.0 - pmf_exp(-t312 * (1.0 - t232))) * (1.0 / (t312 == 0.0 ?
    1.0E-16 : t312));
  t236 = -(1.0 - pmf_pow(t232, t312));
  t297 = 1.0 - pmf_exp(t236 / (t312 == 0.0 ? 1.0E-16 : t312));
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R10 = t218 >= t228
    ? t297 : U_idx_1;
  t190[0ULL] = X[128ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = p_efOut;
  t190[0ULL] = X[127ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t20 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t20.mField0[0ULL], &t20.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = r_efOut[0];
  t297 = U_idx_0;
  t278 = X[110ULL] / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  t190[0ULL] = U_idx_7 * -0.001 + 0.0025;
  t84[0] = 11ULL;
  tlu2_linear_nearest_prelookup(&s_efOut.mField0[0ULL], &s_efOut.mField1[0ULL],
    &s_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t190[0ULL],
    &t84[0ULL], &t31[0ULL]);
  t27 = s_efOut;
  tlu2_1d_linear_nearest_value(&t_efOut[0ULL], &t27.mField0[0ULL], &t27.mField2
    [0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t84[0ULL], &t31[0ULL]);
  U_idx_0 = t_efOut[0];
  t301 = U_idx_0;
  t304 = U_idx_0 / 0.0019634954084936209;
  t190[0ULL] = X[131ULL];
  tlu2_linear_linear_prelookup(&u_efOut.mField0[0ULL], &u_efOut.mField1[0ULL],
    &u_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = u_efOut;
  tlu2_2d_linear_linear_value(&v_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t20.mField0[0ULL], &t20.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = v_efOut[0];
  t290 = U_idx_0;
  t190[0ULL] = X[133ULL];
  tlu2_linear_linear_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = w_efOut;
  t190[0ULL] = X[120ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t7 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t26.mField0[0ULL], &t26.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = y_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c = U_idx_0;
  t190[0ULL] = X[131ULL];
  tlu2_linear_nearest_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t23 = ab_efOut;
  t190[0ULL] = X[127ULL];
  tlu2_linear_nearest_prelookup(&bb_efOut.mField0[0ULL], &bb_efOut.mField1[0ULL],
    &bb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t11 = bb_efOut;
  tlu2_2d_linear_nearest_value(&cb_efOut[0ULL], &t23.mField0[0ULL],
    &t23.mField2[0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = cb_efOut[0];
  t286 = U_idx_0;
  t190[0ULL] = X[133ULL];
  tlu2_linear_nearest_prelookup(&db_efOut.mField0[0ULL], &db_efOut.mField1[0ULL],
    &db_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t23 = db_efOut;
  t190[0ULL] = X[120ULL];
  tlu2_linear_nearest_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = eb_efOut;
  tlu2_2d_linear_nearest_value(&fb_efOut[0ULL], &t23.mField0[0ULL],
    &t23.mField2[0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = fb_efOut[0];
  t286 = (t286 + U_idx_0) / 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff = X[127ULL] - X[120ULL];
  t290 = (t290 + Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c) / 2.0;
  t241 = t301 * t290 * 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c = t286 * t286 *
    0.78539816339744828 / (t241 == 0.0 ? 1.0E-16 : t241) * 293.87755102040813;
  t190[0ULL] = U_idx_7 * 0.001 + 0.0025;
  tlu2_linear_nearest_prelookup(&gb_efOut.mField0[0ULL], &gb_efOut.mField1[0ULL],
    &gb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t190[0ULL],
    &t84[0ULL], &t31[0ULL]);
  t7 = gb_efOut;
  tlu2_1d_linear_nearest_value(&hb_efOut[0ULL], &t7.mField0[0ULL], &t7.mField2
    [0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t84[0ULL], &t31[0ULL]);
  U_idx_0 = hb_efOut[0];
  t238 = U_idx_0;
  t239 = U_idx_0 / 0.0019634954084936209;
  t190[0ULL] = X[134ULL];
  tlu2_linear_linear_prelookup(&ib_efOut.mField0[0ULL], &ib_efOut.mField1[0ULL],
    &ib_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = ib_efOut;
  t190[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&jb_efOut.mField0[0ULL], &jb_efOut.mField1[0ULL],
    &jb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = jb_efOut;
  tlu2_2d_linear_linear_value(&kb_efOut[0ULL], &t26.mField0[0ULL], &t26.mField2
    [0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = kb_efOut[0];
  t240 = U_idx_0;
  t190[0ULL] = X[136ULL];
  tlu2_linear_linear_prelookup(&lb_efOut.mField0[0ULL], &lb_efOut.mField1[0ULL],
    &lb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = lb_efOut;
  tlu2_2d_linear_linear_value(&mb_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t20.mField0[0ULL], &t20.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = mb_efOut[0];
  t241 = U_idx_0;
  t190[0ULL] = X[134ULL];
  tlu2_linear_nearest_prelookup(&nb_efOut.mField0[0ULL], &nb_efOut.mField1[0ULL],
    &nb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = nb_efOut;
  t190[0ULL] = X[40ULL];
  tlu2_linear_nearest_prelookup(&ob_efOut.mField0[0ULL], &ob_efOut.mField1[0ULL],
    &ob_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t190[0ULL],
    &t160[0ULL], &t31[0ULL]);
  t22 = ob_efOut;
  tlu2_2d_linear_nearest_value(&pb_efOut[0ULL], &t26.mField0[0ULL],
    &t26.mField2[0ULL], &t22.mField0[0ULL], &t22.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = pb_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg = U_idx_0;
  t190[0ULL] = X[136ULL];
  tlu2_linear_nearest_prelookup(&qb_efOut.mField0[0ULL], &qb_efOut.mField1[0ULL],
    &qb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t26 = qb_efOut;
  tlu2_2d_linear_nearest_value(&rb_efOut[0ULL], &t26.mField0[0ULL],
    &t26.mField2[0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  U_idx_0 = rb_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg =
    (Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg + U_idx_0) / 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff = X[40ULL] - X[127ULL];
  t240 = (t240 + t241) / 2.0;
  t269 = t238 * t240 * 2.0;
  t241 = Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg *
    Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg * 0.78539816339744828 /
    (t269 == 0.0 ? 1.0E-16 : t269) * 293.87755102040813;
  t270 = pmf_sqrt(t316 * t316 + 13.433628212593847) * 2.0;
  t270 = (1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * t316 * 0.10471975511965977 *
          2.0 + 0.10471975511965977) / 2.0;
  U_idx_1 = t317 * t317;
  t269 = -366.51914291880917 / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1) * t220 *
    t270;
  if (t307 < 0.0) {
    U_idx_0 = 0.0;
  } else if (t307 * 1.0E+6 <= 1666.6666666666665) {
    U_idx_0 = t307 * t269 * -2.5688073394495407E+6;
  } else if (t307 * 1.0E+6 <= 3333.333333333333) {
    U_idx_0 = t269 * 1834.8623853211036 + t307 * t269 * -3.6697247706422037E+6;
  } else {
    U_idx_0 = t269 * -10397.553516819575;
  }

  t317 = t208 * (t317 / 366.51914291880917 * (t317 / 366.51914291880917) *
                 U_idx_0 + t317 / 366.51914291880917 * (t270 /
    366.51914291880917) * intermediate_der85 * 2.0) * 9.81;
  t208 = t220 * t317;
  if (t307 < 0.0) {
    t220 = 0.0;
  } else if (t307 * 1.0E+6 <= 1666.6666666666665) {
    U_idx_1 = (3333.333333333333 - t307 * 1.0E+6) * (3333.333333333333 - t307 *
      1.0E+6);
    U_idx_0 = 3333.333333333333 - t307 * 1.0E+6;
    t220 = (-(t269 * 1.0E+6) * (-(0.64583333333333326 - t307 * t307 *
              52499.999999999993) / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1)) +
            -(t307 * t269 * 104999.99999999999) / (U_idx_0 == 0.0 ? 1.0E-16 :
             U_idx_0)) * 1000.0;
  } else if (t307 * 1.0E+6 <= 3333.333333333333) {
    U_idx_0 = t307 * t307 * 1.0E+12;
    U_idx_1 = t307 * 1.0E+6;
    t220 = (-((t307 * 75.000000000000028 + 0.17499999999999988) * t307) /
            (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0) * t269 * 1.0E+6 + ((t307 *
              75.000000000000028 + 0.17499999999999988) * t269 + t307 * t269 *
             75.000000000000028) / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1)) *
      1.0E+6;
  } else {
    t220 = 0.0;
  }

  t307 = t220 / 366.51914291880917;
  t220 = 22.222222222222218;
  if (t315 <= 0.0) {
    intermediate_der85 = 0.0;
  } else if (t315 <= 0.005) {
    intermediate_der85 = t220 * t315 * 201.00502512562812;
  } else if (t315 <= 0.995) {
    intermediate_der85 = t220 * 1.0050251256281406;
  } else if (t315 <= 1.0) {
    intermediate_der85 = -t220 * (1.0 - t315) * -201.00502512562812;
  } else {
    intermediate_der85 = 0.0;
  }

  t220 = intermediate_der85 * 0.045000000000000005;
  if (intermediate_der373 / 0.045000000000000005 <= -1.0) {
    intermediate_der85 = 0.0;
  } else if (intermediate_der373 / 0.045000000000000005 >= 1.0) {
    intermediate_der85 = 0.0;
  } else {
    intermediate_der85 = t220 / 0.045000000000000005;
  }

  t270 = pmf_sqrt(1.0 - intermediate_der348 * intermediate_der348);
  t269 = pmf_sqrt(0.0020250000000000003 - intermediate_der373 *
                  intermediate_der373) * 2.0;
  intermediate_der348 = -(1.0 / (t270 == 0.0 ? 1.0E-16 : t270)) *
    intermediate_der85 * 0.0010125000000000002 - (t220 / 2.0 * pmf_sqrt
    (0.0020250000000000003 - intermediate_der373 * intermediate_der373) + -(t220
    * intermediate_der373 * 2.0) * (intermediate_der373 / 2.0) * (1.0 / (t269 ==
    0.0 ? 1.0E-16 : t269)));
  t220 = -intermediate_der348;
  intermediate_der85 = -intermediate_der348 / 0.0019634954084936209;
  t270 = pmf_sqrt(t225 * 0.78539816339744828) * 2.0;
  intermediate_der348 = 1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * t308 *
    -intermediate_der348 * 9.42477796076938;
  t270 = pmf_sqrt(X[46ULL] * X[46ULL] + intermediate_der728 *
                  intermediate_der728) * 2.0;
  t315 = 1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * intermediate_der728 * X[46ULL] *
    intermediate_der348 * 2.0;
  t270 = cosh(intermediate_der346 / 0.029511607098668874) * cosh
    (intermediate_der346 / 0.029511607098668874);
  intermediate_der348 = tanh(intermediate_der346 / 0.029511607098668874) +
    101.6549180114056 * (1.0 / (t270 == 0.0 ? 1.0E-16 : t270)) * U_idx_2;
  intermediate_der346 = intrm_sf_mf_48 ? intermediate_der348 : 0.0;
  t269 = (t311 + 0.029511607098668874) * (t311 + 0.029511607098668874);
  intermediate_der348 =
    -(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 +
      0.029511607098668874) / (t269 == 0.0 ? 1.0E-16 : t269) * (intrm_sf_mf_48 ?
    0.0 : intermediate_der348) + intermediate_der346 / (t311 +
    0.029511607098668874 == 0.0 ? 1.0E-16 : t311 + 0.029511607098668874);
  t270 = intermediate_der815 * intermediate_der815 * 8.9290404225000035;
  t308 = -1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * (real_T)!(U_idx_3 <= 0.01) *
    2.9881500000000005;
  if (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 >= 1.0 /
      (t234 == 0.0 ? 1.0E-16 : t234)) {
    t270 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 *
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t313 *
      t313;
    t269 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t313;
    intermediate_der373 = 1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * pmf_exp(-1.0 /
      (t269 == 0.0 ? 1.0E-16 : t269)) * t313 * intermediate_der346;
  } else {
    intermediate_der373 = 0.0;
  }

  if (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 >= 1.0 /
      (t234 == 0.0 ? 1.0E-16 : t234)) {
    t270 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 *
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t313 *
      t313;
    t269 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t313;
    intermediate_der728 = 1.0 / (t270 == 0.0 ? 1.0E-16 : t270) * pmf_exp(-1.0 /
      (t269 == 0.0 ? 1.0E-16 : t269)) *
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 * t308;
  } else {
    intermediate_der728 = 0.0;
  }

  t270 = t312 * t312;
  t308 = (1.0 - pmf_exp(-t312 * (1.0 - t232))) * (-1.0 / (t270 == 0.0 ? 1.0E-16 :
    t270)) * intermediate_der348 + -((-intermediate_der348 * (1.0 - t232) +
    -t312 * -intermediate_der373) * pmf_exp(-t312 * (1.0 - t232))) * (1.0 /
    (t312 == 0.0 ? 1.0E-16 : t312));
  U_idx_7 = -(-t312 * -intermediate_der728 * pmf_exp(-t312 * (1.0 - t232))) *
    (1.0 / (t312 == 0.0 ? 1.0E-16 : t312));
  t269 = pmf_pow(t232, t312 - 1.0) * t312 * intermediate_der728;
  intermediate_der728 = -(t269 / (t312 == 0.0 ? 1.0E-16 : t312) * pmf_exp(t236 /
    (t312 == 0.0 ? 1.0E-16 : t312)));
  t269 = 1.0 - pmf_pow(t232, t312);
  U_idx_0 = pmf_pow(t232, t312 - 1.0) * t312 * intermediate_der373 + pmf_pow
    (t232, t312) * pmf_log(t232) * intermediate_der348;
  intermediate_der373 = -((t269 / (t270 == 0.0 ? 1.0E-16 : t270) *
    intermediate_der348 + U_idx_0 / (t312 == 0.0 ? 1.0E-16 : t312)) * pmf_exp
    (t236 / (t312 == 0.0 ? 1.0E-16 : t312)));
  intermediate_der348 = t218 >= t228 ? intermediate_der373 : t308;
  intermediate_der373 = t218 >= t228 ? intermediate_der728 : U_idx_7;
  t190[0ULL] = t278 * 1.0E+6;
  t157[0] = 15ULL;
  tlu2_linear_linear_prelookup(&sb_efOut.mField0[0ULL], &sb_efOut.mField1[0ULL],
    &sb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField11, &t190[0ULL],
    &t157[0ULL], &t31[0ULL]);
  t22 = sb_efOut;
  t190[0ULL] = U_idx_6 * 0.10471975511965977;
  t160[0] = 8ULL;
  tlu2_linear_linear_prelookup(&tb_efOut.mField0[0ULL], &tb_efOut.mField1[0ULL],
    &tb_efOut.mField2[0ULL], &nonscalar12[0ULL], &t190[0ULL], &t160[0ULL], &t31
    [0ULL]);
  t26 = tb_efOut;
  tlu2_2d_linear_linear_value(&ub_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t26.mField1[0ULL], &t26.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField10, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  t190[0] = ub_efOut[0];
  intermediate_der728 = t190[0ULL] * 0.10471975511965977;
  U_idx_7 = t297 * intermediate_der728 * 9.81;
  intermediate_der728 = t278 * U_idx_7;
  tlu2_2d_linear_linear_value(&vb_efOut[0ULL], &t22.mField0[0ULL], &t22.mField2
    [0ULL], &t26.mField1[0ULL], &t26.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField12, &t157[0ULL], &t160[0ULL], &t31[0ULL]);
  t190[0] = vb_efOut[0];
  t218 = t190[0ULL] * 0.10471975511965977;
  tlu2_1d_linear_nearest_value(&wb_efOut[0ULL], &t27.mField1[0ULL],
    &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t84[0ULL], &t31
    [0ULL]);
  t190[0] = wb_efOut[0];
  t311 = t190[0ULL] * -0.001;
  t278 = t301 * t301 * t290 * t290 * 4.0;
  t312 = -(t286 * t286 * 0.78539816339744828) / (t278 == 0.0 ? 1.0E-16 : t278) *
    t290 * t311 * 587.75510204081627;
  tlu2_1d_linear_nearest_value(&xb_efOut[0ULL], &t7.mField1[0ULL], &t7.mField2
    [0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t84[0ULL], &t31[0ULL]);
  t190[0] = xb_efOut[0];
  t313 = t190[0ULL] * 0.001;
  t278 = t238 * t238 * t240 * t240 * 4.0;
  intermediate_der815 = -(Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg *
    Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg * 0.78539816339744828) /
    (t278 == 0.0 ? 1.0E-16 : t278) * t240 * t313 * 587.75510204081627;
  t317 = -(t317 * 1.0E-5) / 1.0000000018932729;
  t232 = t208 * 0.001;
  t208 = pmf_sqrt(t316 * t316 + 0.13433628212593846) * 2.0;
  U_idx_1 = 1.0 / (t208 == 0.0 ? 1.0E-16 : t208) * t316 * t316 * t222 *
    0.10471975511965977 * 2.0 + (t222 * 0.10471975511965977 + t316 * t307) *
    pmf_sqrt(t316 * t316 + 0.13433628212593846);
  t307 = -(U_idx_1 / 134336.28212593845 * 1000.0);
  t222 = -(U_idx_7 * 1.0E-5);
  U_idx_7 = intermediate_der728 * 0.001;
  intermediate_der728 = -(t297 / 998.2 * t218);
  t208 = pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
                  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
                  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
                  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c) * pmf_sqrt
    (pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c));
  U_idx_1 = t290 * 2.0;
  t297 = 1.0 - t304 * t304;
  t316 = pmf_sqrt(U_idx_1 / (t297 == 0.0 ? 1.0E-16 : t297));
  t286 = pmf_sqrt(pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c)) * pmf_sqrt(pmf_sqrt
    (Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
     Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
     Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
     Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c));
  Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg = -(t290 * 2.0);
  t290 = (1.0 - t304 * t304) * (1.0 - t304 * t304);
  U_idx_0 = pmf_sqrt(pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c));
  t218 = -((-Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff / (t286 == 0.0 ?
             1.0E-16 : t286) * pmf_sqrt(U_idx_1 / (t297 == 0.0 ? 1.0E-16 : t297))
            * (1.0 / (t208 == 0.0 ? 1.0E-16 : t208)) * t301 *
            Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c * t312 * 0.5 +
            (-(t304 * (t311 / 0.0019634954084936209) * 2.0) *
             (Subsystem_Reference_TCV_VL6810_orifice_PA_mu_avg / (t290 == 0.0 ?
    1.0E-16 : t290)) * (1.0 / (t316 == 0.0 ? 1.0E-16 : t316)) * t301 * 0.5 +
             pmf_sqrt(U_idx_1 / (t297 == 0.0 ? 1.0E-16 : t297)) * t311) *
            (Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff / (U_idx_0 == 0.0 ?
              1.0E-16 : U_idx_0))) * 70000.0);
  t208 = pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
                  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 +
                  t241 * t241) * pmf_sqrt(pmf_sqrt
    (Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
     Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 + t241 * t241));
  t311 = t240 * 2.0;
  t312 = 1.0 - t239 * t239;
  t316 = pmf_sqrt(t311 / (t312 == 0.0 ? 1.0E-16 : t312));
  t297 = pmf_sqrt(pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 + t241 * t241)) *
    pmf_sqrt(pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
                      Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10
                      + t241 * t241));
  t301 = (1.0 - t239 * t239) * (1.0 - t239 * t239);
  t304 = pmf_sqrt(pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 + t241 * t241));
  t228 = -((-Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff / (t297 == 0.0 ?
             1.0E-16 : t297) * pmf_sqrt(t311 / (t312 == 0.0 ? 1.0E-16 : t312)) *
            (1.0 / (t208 == 0.0 ? 1.0E-16 : t208)) * t238 * t241 *
            intermediate_der815 * 0.5 + (-(t239 * (t313 / 0.0019634954084936209)
              * 2.0) * (-(t240 * 2.0) / (t301 == 0.0 ? 1.0E-16 : t301)) * (1.0 /
              (t316 == 0.0 ? 1.0E-16 : t316)) * t238 * 0.5 + pmf_sqrt(t311 /
              (t312 == 0.0 ? 1.0E-16 : t312)) * t313) *
            (Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff / (t304 == 0.0 ?
              1.0E-16 : t304))) * 70000.0);
  U_idx_0 = t317;
  U_idx_1 = t307;
  t208 = pmf_sqrt(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
                  Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) * 2.0;
  t316 = (1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
          Basic_Peripherals_Gate_Valve_TL_area_ratio) * t226;
  t317 = t225 * t225 * Basic_Peripherals_Gate_Valve_TL_rho_avg *
    0.97999999999999987;
  t307 = -((pmf_sqrt(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
                     Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) -
            Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7) * (t316 / (t317 ==
             0.0 ? 1.0E-16 : t317)));
  t308 = (Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7 + pmf_sqrt(1.0 -
           Basic_Peripherals_Gate_Valve_TL_area_ratio *
           Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51)) *
    (Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7 + pmf_sqrt(1.0 -
      Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51));
  t312 = t225 * t225 * t225 * t225 * Basic_Peripherals_Gate_Valve_TL_rho_avg *
    Basic_Peripherals_Gate_Valve_TL_rho_avg * 0.9603999999999997;
  t315 = (-(Basic_Peripherals_Gate_Valve_TL_area_ratio * intermediate_der85 *
            1.02) * (1.0 / (t208 == 0.0 ? 1.0E-16 : t208)) - intermediate_der85 *
          0.7) * (t316 / (t317 == 0.0 ? 1.0E-16 : t317)) + (-((1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio) * t226) / (t312 == 0.0 ? 1.0E-16
    : t312) * Basic_Peripherals_Gate_Valve_TL_rho_avg * t225 * t220 *
    1.9599999999999997 + (-(Basic_Peripherals_Gate_Valve_TL_area_ratio *
    intermediate_der85 * 2.0) * t226 + (1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio) * t315) / (t317 == 0.0 ? 1.0E-16
    : t317)) * (pmf_sqrt(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) -
                Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7);
  t316 = Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7 + pmf_sqrt(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51);
  out.mX[0] = U_idx_0;
  out.mX[1] = t232;
  out.mX[2] = U_idx_1;
  out.mX[3] = -(((intermediate_der85 * 0.7 +
                  -(Basic_Peripherals_Gate_Valve_TL_area_ratio *
                    intermediate_der85 * 1.02) * (1.0 / (t208 == 0.0 ? 1.0E-16 :
    t208))) * (t307 / (t308 == 0.0 ? 1.0E-16 : t308)) + t315 / (t316 == 0.0 ?
    1.0E-16 : t316)) * 1.0E-5) / 3.7261553955660564E+8;
  out.mX[4] = -((Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R10
                 * intermediate_der346 +
                 Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 *
                 intermediate_der348) * (t230 - U_idx_4) * 0.001);
  out.mX[5] = -((t230 - U_idx_4) *
                Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 *
                intermediate_der373 * 0.001);
  out.mX[6] = -(-Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R4 *
                Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R10 *
                0.001);
  out.mX[7] = t222;
  out.mX[8] = U_idx_7;
  out.mX[9] = intermediate_der728;
  out.mX[10] = t218;
  out.mX[11] = t228;
  (void)LC;
  (void)t319;
  return 0;
}
