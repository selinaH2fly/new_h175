/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_zc.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_zc(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t382, NeDsMethodOutput *t383)
{
  ETTS0 ab_efOut;
  ETTS0 ac_efOut;
  ETTS0 ad_efOut;
  ETTS0 b_efOut;
  ETTS0 bc_efOut;
  ETTS0 bd_efOut;
  ETTS0 cb_efOut;
  ETTS0 d_efOut;
  ETTS0 db_efOut;
  ETTS0 dc_efOut;
  ETTS0 dd_efOut;
  ETTS0 e_efOut;
  ETTS0 ec_efOut;
  ETTS0 ed_efOut;
  ETTS0 efOut;
  ETTS0 fb_efOut;
  ETTS0 g_efOut;
  ETTS0 gb_efOut;
  ETTS0 gc_efOut;
  ETTS0 gd_efOut;
  ETTS0 h_efOut;
  ETTS0 hd_efOut;
  ETTS0 ib_efOut;
  ETTS0 ic_efOut;
  ETTS0 j_efOut;
  ETTS0 jd_efOut;
  ETTS0 k_efOut;
  ETTS0 kb_efOut;
  ETTS0 kc_efOut;
  ETTS0 kd_efOut;
  ETTS0 lb_efOut;
  ETTS0 lc_efOut;
  ETTS0 m_efOut;
  ETTS0 md_efOut;
  ETTS0 n_efOut;
  ETTS0 nb_efOut;
  ETTS0 nc_efOut;
  ETTS0 nd_efOut;
  ETTS0 ob_efOut;
  ETTS0 oc_efOut;
  ETTS0 p_efOut;
  ETTS0 q_efOut;
  ETTS0 qb_efOut;
  ETTS0 qc_efOut;
  ETTS0 rb_efOut;
  ETTS0 rc_efOut;
  ETTS0 s_efOut;
  ETTS0 t44;
  ETTS0 t48;
  ETTS0 t49;
  ETTS0 t51;
  ETTS0 t52;
  ETTS0 t54;
  ETTS0 t57;
  ETTS0 t8;
  ETTS0 t_efOut;
  ETTS0 tb_efOut;
  ETTS0 tc_efOut;
  ETTS0 ub_efOut;
  ETTS0 uc_efOut;
  ETTS0 v_efOut;
  ETTS0 w_efOut;
  ETTS0 wb_efOut;
  ETTS0 wc_efOut;
  ETTS0 xb_efOut;
  ETTS0 xc_efOut;
  ETTS0 y_efOut;
  PmRealVector out;
  real_T t347[227];
  real_T X[148];
  real_T bb_efOut[1];
  real_T c_efOut[1];
  real_T cc_efOut[1];
  real_T cd_efOut[1];
  real_T eb_efOut[1];
  real_T f_efOut[1];
  real_T fc_efOut[1];
  real_T fd_efOut[1];
  real_T hb_efOut[1];
  real_T hc_efOut[1];
  real_T i_efOut[1];
  real_T id_efOut[1];
  real_T jb_efOut[1];
  real_T jc_efOut[1];
  real_T l_efOut[1];
  real_T ld_efOut[1];
  real_T mb_efOut[1];
  real_T mc_efOut[1];
  real_T o_efOut[1];
  real_T od_efOut[1];
  real_T pb_efOut[1];
  real_T pc_efOut[1];
  real_T r_efOut[1];
  real_T sb_efOut[1];
  real_T sc_efOut[1];
  real_T t378[1];
  real_T u_efOut[1];
  real_T vb_efOut[1];
  real_T vc_efOut[1];
  real_T x_efOut[1];
  real_T yb_efOut[1];
  real_T yc_efOut[1];
  real_T Basic_Peripherals_Aux_TCP_A_p;
  real_T Subsystem_Reference_T_Junction_TL_mu_B;
  real_T intrm_sf_mf_222;
  real_T intrm_sf_mf_224;
  real_T intrm_sf_mf_228;
  real_T intrm_sf_mf_229;
  real_T intrm_sf_mf_231;
  real_T intrm_sf_mf_234;
  real_T intrm_sf_mf_236;
  real_T intrm_sf_mf_237;
  real_T intrm_sf_mf_238;
  real_T intrm_sf_mf_254;
  real_T intrm_sf_mf_255;
  real_T intrm_sf_mf_256;
  real_T intrm_sf_mf_257;
  real_T intrm_sf_mf_259;
  real_T intrm_sf_mf_260;
  real_T intrm_sf_mf_261;
  real_T intrm_sf_mf_263;
  real_T t376_idx_0;
  real_T t379;
  real_T t380;
  real_T t381;
  size_t t78[1];
  size_t t79[1];
  size_t t81[1];
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  int32_T Q_idx_2;
  int32_T b;
  boolean_T Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG;
  boolean_T t59;
  boolean_T t60;
  boolean_T t61;
  boolean_T t62;
  boolean_T t63;
  boolean_T t64;
  boolean_T t65;
  boolean_T t66;
  boolean_T t67;
  boolean_T t68;
  boolean_T t69;
  boolean_T t70;
  boolean_T t71;
  boolean_T t72;
  boolean_T t73;
  boolean_T t74;
  boolean_T t75;
  Q_idx_0 = t382->mQ.mX[0];
  Q_idx_1 = t382->mQ.mX[1];
  Q_idx_2 = t382->mQ.mX[2];
  for (b = 0; b < 148; b++) {
    X[b] = t382->mX.mX[b];
  }

  out = t383->mZC;
  Basic_Peripherals_Aux_TCP_A_p = X[0ULL] * -0.8 + 1.1132499999999999;
  t378[0ULL] = X[62ULL];
  t78[0] = 20ULL;
  t79[0] = 1ULL;
  tlu2_linear_nearest_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL], &t78
    [0ULL], &t79[0ULL]);
  t57 = efOut;
  t378[0ULL] = X[54ULL];
  t81[0] = 19ULL;
  tlu2_linear_nearest_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = b_efOut;
  tlu2_2d_linear_nearest_value(&c_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = c_efOut[0];
  intrm_sf_mf_222 = t376_idx_0;
  t378[0ULL] = X[63ULL];
  tlu2_linear_nearest_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = d_efOut;
  t378[0ULL] = X[50ULL];
  tlu2_linear_nearest_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = e_efOut;
  tlu2_2d_linear_nearest_value(&f_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = f_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t376_idx_0;
  t378[0ULL] = X[64ULL];
  tlu2_linear_nearest_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = g_efOut;
  t378[0ULL] = X[44ULL];
  tlu2_linear_nearest_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = h_efOut;
  tlu2_2d_linear_nearest_value(&i_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = i_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = ((intrm_sf_mf_222 *
    0.0019634954084936209 + Subsystem_Reference_T_Junction_TL_mu_B *
    0.0019634954084936209) + t376_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t59 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t59 = false;
  }

  if (t59) {
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG = (X[46ULL] >
      Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t60 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t60 = false;
  }

  if (t60) {
    t59 = (X[46ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t59 = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t61 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t61 = false;
  }

  if (t61) {
    t60 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t60 = false;
  }

  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t62 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t62 = false;
  }

  if (t62) {
    t61 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t61 = false;
  }

  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t63 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t63 = false;
  }

  if (t63) {
    t62 = (X[46ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t62 = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t64 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t64 = false;
  }

  if (t64) {
    t63 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t63 = false;
  }

  t378[0ULL] = X[73ULL];
  tlu2_linear_nearest_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = j_efOut;
  t378[0ULL] = X[23ULL];
  tlu2_linear_nearest_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = k_efOut;
  tlu2_2d_linear_nearest_value(&l_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = l_efOut[0];
  intrm_sf_mf_222 = t376_idx_0;
  t378[0ULL] = X[74ULL];
  tlu2_linear_nearest_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = m_efOut;
  t378[0ULL] = X[40ULL];
  tlu2_linear_nearest_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t51 = n_efOut;
  tlu2_2d_linear_nearest_value(&o_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t51.mField0[0ULL], &t51.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = o_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t376_idx_0;
  t378[0ULL] = X[75ULL];
  tlu2_linear_nearest_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = p_efOut;
  t378[0ULL] = X[42ULL];
  tlu2_linear_nearest_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = q_efOut;
  tlu2_2d_linear_nearest_value(&r_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = r_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = ((intrm_sf_mf_222 *
    0.0019634954084936209 + Subsystem_Reference_T_Junction_TL_mu_B *
    0.0019634954084936209) + t376_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t65 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t65 = false;
  }

  if (t65) {
    t64 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t64 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t66 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t66 = false;
  }

  if (t66) {
    t65 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t65 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t67 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t67 = false;
  }

  if (t67) {
    t66 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t66 = false;
  }

  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t68 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t68 = false;
  }

  if (t68) {
    t67 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t67 = false;
  }

  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t69 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t69 = false;
  }

  if (t69) {
    t68 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t68 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t70 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t70 = false;
  }

  if (t70) {
    t69 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t69 = false;
  }

  t378[0ULL] = X[137ULL];
  tlu2_linear_nearest_prelookup(&s_efOut.mField0[0ULL], &s_efOut.mField1[0ULL],
    &s_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t51 = s_efOut;
  t378[0ULL] = X[97ULL];
  tlu2_linear_nearest_prelookup(&t_efOut.mField0[0ULL], &t_efOut.mField1[0ULL],
    &t_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = t_efOut;
  tlu2_2d_linear_nearest_value(&u_efOut[0ULL], &t51.mField0[0ULL], &t51.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = u_efOut[0];
  intrm_sf_mf_222 = t376_idx_0;
  t378[0ULL] = X[138ULL];
  tlu2_linear_nearest_prelookup(&v_efOut.mField0[0ULL], &v_efOut.mField1[0ULL],
    &v_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = v_efOut;
  t378[0ULL] = X[38ULL];
  tlu2_linear_nearest_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = w_efOut;
  tlu2_2d_linear_nearest_value(&x_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = x_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t376_idx_0;
  t378[0ULL] = X[139ULL];
  tlu2_linear_nearest_prelookup(&y_efOut.mField0[0ULL], &y_efOut.mField1[0ULL],
    &y_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = y_efOut;
  t378[0ULL] = X[112ULL];
  tlu2_linear_nearest_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = ab_efOut;
  tlu2_2d_linear_nearest_value(&bb_efOut[0ULL], &t57.mField0[0ULL],
    &t57.mField2[0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = bb_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = ((intrm_sf_mf_222 *
    0.0019634954084936209 + Subsystem_Reference_T_Junction_TL_mu_B *
    0.0019634954084936209) + t376_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t71 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t71 = false;
  }

  if (t71) {
    t70 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t70 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t72 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t72 = false;
  }

  if (t72) {
    t71 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t71 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t73 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t73 = false;
  }

  if (t73) {
    t72 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t72 = false;
  }

  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t74 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t74 = false;
  }

  if (t74) {
    t73 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t73 = false;
  }

  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t75 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t75 = false;
  }

  if (t75) {
    t74 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t74 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t75 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t75 = false;
  }

  if (t75) {
    t75 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t75 = false;
  }

  t378[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&cb_efOut.mField0[0ULL], &cb_efOut.mField1[0ULL],
    &cb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = cb_efOut;
  t378[0ULL] = Basic_Peripherals_Aux_TCP_A_p;
  tlu2_linear_linear_prelookup(&db_efOut.mField0[0ULL], &db_efOut.mField1[0ULL],
    &db_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t44 = db_efOut;
  tlu2_2d_linear_linear_value(&eb_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t44.mField0[0ULL], &t44.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = eb_efOut[0];
  intrm_sf_mf_222 = t376_idx_0;
  t378[0ULL] = X[22ULL];
  tlu2_linear_linear_prelookup(&fb_efOut.mField0[0ULL], &fb_efOut.mField1[0ULL],
    &fb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = fb_efOut;
  t378[0ULL] = X[23ULL];
  tlu2_linear_linear_prelookup(&gb_efOut.mField0[0ULL], &gb_efOut.mField1[0ULL],
    &gb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = gb_efOut;
  tlu2_2d_linear_linear_value(&hb_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = hb_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t376_idx_0;
  t378[0ULL] = X[1ULL];
  tlu2_linear_linear_prelookup(&ib_efOut.mField0[0ULL], &ib_efOut.mField1[0ULL],
    &ib_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = ib_efOut;
  tlu2_2d_linear_linear_value(&jb_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t44.mField0[0ULL], &t44.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = jb_efOut[0];
  intrm_sf_mf_224 = t376_idx_0;
  t378[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&kb_efOut.mField0[0ULL], &kb_efOut.mField1[0ULL],
    &kb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t8 = kb_efOut;
  t378[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&lb_efOut.mField0[0ULL], &lb_efOut.mField1[0ULL],
    &lb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = lb_efOut;
  tlu2_2d_linear_linear_value(&mb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = mb_efOut[0];
  t379 = t376_idx_0;
  t378[0ULL] = X[43ULL];
  tlu2_linear_linear_prelookup(&nb_efOut.mField0[0ULL], &nb_efOut.mField1[0ULL],
    &nb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = nb_efOut;
  t378[0ULL] = X[44ULL];
  tlu2_linear_linear_prelookup(&ob_efOut.mField0[0ULL], &ob_efOut.mField1[0ULL],
    &ob_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = ob_efOut;
  tlu2_2d_linear_linear_value(&pb_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = pb_efOut[0];
  t380 = t376_idx_0;
  t378[0ULL] = X[37ULL];
  tlu2_linear_linear_prelookup(&qb_efOut.mField0[0ULL], &qb_efOut.mField1[0ULL],
    &qb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t49 = qb_efOut;
  t378[0ULL] = X[38ULL];
  tlu2_linear_linear_prelookup(&rb_efOut.mField0[0ULL], &rb_efOut.mField1[0ULL],
    &rb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t52 = rb_efOut;
  tlu2_2d_linear_linear_value(&sb_efOut[0ULL], &t49.mField0[0ULL], &t49.mField2
    [0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = sb_efOut[0];
  t381 = t376_idx_0;
  t378[0ULL] = X[53ULL];
  tlu2_linear_linear_prelookup(&tb_efOut.mField0[0ULL], &tb_efOut.mField1[0ULL],
    &tb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t51 = tb_efOut;
  t378[0ULL] = X[54ULL];
  tlu2_linear_linear_prelookup(&ub_efOut.mField0[0ULL], &ub_efOut.mField1[0ULL],
    &ub_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t52 = ub_efOut;
  tlu2_2d_linear_linear_value(&vb_efOut[0ULL], &t51.mField0[0ULL], &t51.mField2
    [0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = vb_efOut[0];
  intrm_sf_mf_228 = t376_idx_0;
  t378[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&wb_efOut.mField0[0ULL], &wb_efOut.mField1[0ULL],
    &wb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t54 = wb_efOut;
  t378[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&xb_efOut.mField0[0ULL], &xb_efOut.mField1[0ULL],
    &xb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t8 = xb_efOut;
  tlu2_2d_linear_linear_value(&yb_efOut[0ULL], &t54.mField0[0ULL], &t54.mField2
    [0ULL], &t8.mField0[0ULL], &t8.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = yb_efOut[0];
  intrm_sf_mf_229 = t376_idx_0;
  t378[0ULL] = X[49ULL];
  tlu2_linear_linear_prelookup(&ac_efOut.mField0[0ULL], &ac_efOut.mField1[0ULL],
    &ac_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = ac_efOut;
  t378[0ULL] = X[50ULL];
  tlu2_linear_linear_prelookup(&bc_efOut.mField0[0ULL], &bc_efOut.mField1[0ULL],
    &bc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t57 = bc_efOut;
  tlu2_2d_linear_linear_value(&cc_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t57.mField0[0ULL], &t57.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = cc_efOut[0];
  intrm_sf_mf_231 = t376_idx_0;
  t378[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&dc_efOut.mField0[0ULL], &dc_efOut.mField1[0ULL],
    &dc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t8 = dc_efOut;
  t378[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&ec_efOut.mField0[0ULL], &ec_efOut.mField1[0ULL],
    &ec_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = ec_efOut;
  tlu2_2d_linear_linear_value(&fc_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = fc_efOut[0];
  intrm_sf_mf_234 = t376_idx_0;
  t378[0ULL] = X[86ULL];
  tlu2_linear_linear_prelookup(&gc_efOut.mField0[0ULL], &gc_efOut.mField1[0ULL],
    &gc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = gc_efOut;
  tlu2_2d_linear_linear_value(&hc_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t57.mField0[0ULL], &t57.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = hc_efOut[0];
  intrm_sf_mf_236 = t376_idx_0;
  t378[0ULL] = X[87ULL];
  tlu2_linear_linear_prelookup(&ic_efOut.mField0[0ULL], &ic_efOut.mField1[0ULL],
    &ic_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t52 = ic_efOut;
  tlu2_2d_linear_linear_value(&jc_efOut[0ULL], &t52.mField0[0ULL], &t52.mField2
    [0ULL], &t44.mField0[0ULL], &t44.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = jc_efOut[0];
  intrm_sf_mf_237 = t376_idx_0;
  t378[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&kc_efOut.mField0[0ULL], &kc_efOut.mField1[0ULL],
    &kc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = kc_efOut;
  t378[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&lc_efOut.mField0[0ULL], &lc_efOut.mField1[0ULL],
    &lc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t8 = lc_efOut;
  tlu2_2d_linear_linear_value(&mc_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t8.mField0[0ULL], &t8.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = mc_efOut[0];
  intrm_sf_mf_238 = t376_idx_0;
  t378[0ULL] = X[94ULL];
  tlu2_linear_linear_prelookup(&nc_efOut.mField0[0ULL], &nc_efOut.mField1[0ULL],
    &nc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t51 = nc_efOut;
  t378[0ULL] = X[95ULL];
  tlu2_linear_linear_prelookup(&oc_efOut.mField0[0ULL], &oc_efOut.mField1[0ULL],
    &oc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = oc_efOut;
  tlu2_2d_linear_linear_value(&pc_efOut[0ULL], &t51.mField0[0ULL], &t51.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = pc_efOut[0];
  intrm_sf_mf_254 = t376_idx_0;
  t378[0ULL] = X[96ULL];
  tlu2_linear_linear_prelookup(&qc_efOut.mField0[0ULL], &qc_efOut.mField1[0ULL],
    &qc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = qc_efOut;
  t378[0ULL] = X[97ULL];
  tlu2_linear_linear_prelookup(&rc_efOut.mField0[0ULL], &rc_efOut.mField1[0ULL],
    &rc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = rc_efOut;
  tlu2_2d_linear_linear_value(&sc_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = sc_efOut[0];
  intrm_sf_mf_255 = t376_idx_0;
  t378[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&tc_efOut.mField0[0ULL], &tc_efOut.mField1[0ULL],
    &tc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t8 = tc_efOut;
  t378[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&uc_efOut.mField0[0ULL], &uc_efOut.mField1[0ULL],
    &uc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = uc_efOut;
  tlu2_2d_linear_linear_value(&vc_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = vc_efOut[0];
  intrm_sf_mf_256 = t376_idx_0;
  t378[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&wc_efOut.mField0[0ULL], &wc_efOut.mField1[0ULL],
    &wc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = wc_efOut;
  t378[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&xc_efOut.mField0[0ULL], &xc_efOut.mField1[0ULL],
    &xc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t51 = xc_efOut;
  tlu2_2d_linear_linear_value(&yc_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t51.mField0[0ULL], &t51.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = yc_efOut[0];
  intrm_sf_mf_257 = t376_idx_0;
  t378[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&ad_efOut.mField0[0ULL], &ad_efOut.mField1[0ULL],
    &ad_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = ad_efOut;
  t378[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&bd_efOut.mField0[0ULL], &bd_efOut.mField1[0ULL],
    &bd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = bd_efOut;
  tlu2_2d_linear_linear_value(&cd_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = cd_efOut[0];
  intrm_sf_mf_259 = t376_idx_0;
  t378[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&dd_efOut.mField0[0ULL], &dd_efOut.mField1[0ULL],
    &dd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = dd_efOut;
  t378[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&ed_efOut.mField0[0ULL], &ed_efOut.mField1[0ULL],
    &ed_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = ed_efOut;
  tlu2_2d_linear_linear_value(&fd_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = fd_efOut[0];
  intrm_sf_mf_260 = t376_idx_0;
  t378[0ULL] = X[119ULL];
  tlu2_linear_linear_prelookup(&gd_efOut.mField0[0ULL], &gd_efOut.mField1[0ULL],
    &gd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = gd_efOut;
  t378[0ULL] = X[120ULL];
  tlu2_linear_linear_prelookup(&hd_efOut.mField0[0ULL], &hd_efOut.mField1[0ULL],
    &hd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t48 = hd_efOut;
  tlu2_2d_linear_linear_value(&id_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t48.mField0[0ULL], &t48.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = id_efOut[0];
  intrm_sf_mf_261 = t376_idx_0;
  t378[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&jd_efOut.mField0[0ULL], &jd_efOut.mField1[0ULL],
    &jd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t57 = jd_efOut;
  t378[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&kd_efOut.mField0[0ULL], &kd_efOut.mField1[0ULL],
    &kd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t49 = kd_efOut;
  tlu2_2d_linear_linear_value(&ld_efOut[0ULL], &t57.mField0[0ULL], &t57.mField2
    [0ULL], &t49.mField0[0ULL], &t49.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t376_idx_0 = ld_efOut[0];
  t378[0ULL] = X[126ULL];
  tlu2_linear_linear_prelookup(&md_efOut.mField0[0ULL], &md_efOut.mField1[0ULL],
    &md_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t378[0ULL],
    &t78[0ULL], &t79[0ULL]);
  t48 = md_efOut;
  t378[0ULL] = X[127ULL];
  tlu2_linear_linear_prelookup(&nd_efOut.mField0[0ULL], &nd_efOut.mField1[0ULL],
    &nd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t378[0ULL],
    &t81[0ULL], &t79[0ULL]);
  t57 = nd_efOut;
  tlu2_2d_linear_linear_value(&od_efOut[0ULL], &t48.mField0[0ULL], &t48.mField2
    [0ULL], &t57.mField0[0ULL], &t57.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField15, &t78[0ULL], &t81[0ULL], &t79[0ULL]);
  t378[0] = od_efOut[0];
  intrm_sf_mf_263 = t378[0ULL];
  t347[0ULL] = intrm_sf_mf_222;
  t347[1ULL] = Basic_Peripherals_Aux_TCP_A_p - 0.1;
  t347[2ULL] = 500.0 - Basic_Peripherals_Aux_TCP_A_p;
  t347[3ULL] = X[21ULL] - 232.6432;
  t347[4ULL] = 393.15 - X[21ULL];
  t347[5ULL] = Subsystem_Reference_T_Junction_TL_mu_B;
  t347[6ULL] = X[23ULL] - 0.1;
  t347[7ULL] = 500.0 - X[23ULL];
  t347[8ULL] = X[22ULL] - 232.6432;
  t347[9ULL] = 393.15 - X[22ULL];
  t347[10ULL] = intrm_sf_mf_263;
  t347[11ULL] = X[127ULL] - 0.1;
  t347[12ULL] = 500.0 - X[127ULL];
  t347[13ULL] = X[126ULL] - 232.6432;
  t347[14ULL] = 393.15 - X[126ULL];
  t347[15ULL] = intrm_sf_mf_257;
  t347[16ULL] = X[107ULL] - 0.1;
  t347[17ULL] = 500.0 - X[107ULL];
  t347[18ULL] = X[106ULL] - 232.6432;
  t347[19ULL] = 393.15 - X[106ULL];
  t347[20ULL] = (X[2ULL] + 0.001) - 1.0000000000000001E-7;
  t347[21ULL] = intrm_sf_mf_224;
  t347[22ULL] = X[1ULL] - 232.6432;
  t347[23ULL] = 393.15 - X[1ULL];
  t347[24ULL] = t379;
  t347[25ULL] = X[42ULL] - 0.1;
  t347[26ULL] = 500.0 - X[42ULL];
  t347[27ULL] = X[41ULL] - 232.6432;
  t347[28ULL] = 393.15 - X[41ULL];
  t347[29ULL] = t380;
  t347[30ULL] = X[44ULL] - 0.1;
  t347[31ULL] = 500.0 - X[44ULL];
  t347[32ULL] = X[43ULL] - 232.6432;
  t347[33ULL] = 393.15 - X[43ULL];
  t347[34ULL] = t381;
  t347[35ULL] = X[38ULL] - 0.1;
  t347[36ULL] = 500.0 - X[38ULL];
  t347[37ULL] = X[37ULL] - 232.6432;
  t347[38ULL] = 393.15 - X[37ULL];
  t347[39ULL] = intrm_sf_mf_228;
  t347[40ULL] = X[54ULL] - 0.1;
  t347[41ULL] = 500.0 - X[54ULL];
  t347[42ULL] = X[53ULL] - 232.6432;
  t347[43ULL] = 393.15 - X[53ULL];
  t347[44ULL] = intrm_sf_mf_229;
  t347[45ULL] = X[5ULL] - 0.1;
  t347[46ULL] = 500.0 - X[5ULL];
  t347[47ULL] = X[6ULL] - 232.6432;
  t347[48ULL] = 393.15 - X[6ULL];
  t347[49ULL] = intrm_sf_mf_254;
  t347[50ULL] = X[95ULL] - 0.1;
  t347[51ULL] = 500.0 - X[95ULL];
  t347[52ULL] = X[94ULL] - 232.6432;
  t347[53ULL] = 393.15 - X[94ULL];
  t347[54ULL] = intrm_sf_mf_255;
  t347[55ULL] = X[97ULL] - 0.1;
  t347[56ULL] = 500.0 - X[97ULL];
  t347[57ULL] = X[96ULL] - 232.6432;
  t347[58ULL] = 393.15 - X[96ULL];
  t347[59ULL] = intrm_sf_mf_256;
  t347[60ULL] = X[13ULL] - 0.1;
  t347[61ULL] = 500.0 - X[13ULL];
  t347[62ULL] = X[14ULL] - 232.6432;
  t347[63ULL] = 393.15 - X[14ULL];
  t347[64ULL] = intrm_sf_mf_257;
  t347[65ULL] = intrm_sf_mf_254;
  t347[66ULL] = intrm_sf_mf_259;
  t347[67ULL] = X[17ULL] - 0.1;
  t347[68ULL] = 500.0 - X[17ULL];
  t347[69ULL] = X[18ULL] - 232.6432;
  t347[70ULL] = 393.15 - X[18ULL];
  t347[71ULL] = intrm_sf_mf_260;
  t347[72ULL] = X[112ULL] - 0.1;
  t347[73ULL] = 500.0 - X[112ULL];
  t347[74ULL] = X[111ULL] - 232.6432;
  t347[75ULL] = 393.15 - X[111ULL];
  t347[76ULL] = intrm_sf_mf_261;
  t347[77ULL] = X[120ULL] - 0.1;
  t347[78ULL] = 500.0 - X[120ULL];
  t347[79ULL] = X[119ULL] - 232.6432;
  t347[80ULL] = 393.15 - X[119ULL];
  t347[81ULL] = t376_idx_0;
  t347[82ULL] = X[19ULL] - 0.1;
  t347[83ULL] = 500.0 - X[19ULL];
  t347[84ULL] = X[20ULL] - 232.6432;
  t347[85ULL] = 393.15 - X[20ULL];
  t347[86ULL] = (real_T)(((size_t)Q_idx_0 == 2ULL) && t61);
  t347[87ULL] = (real_T)(((size_t)Q_idx_0 == 2ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[88ULL] = (real_T)(((size_t)Q_idx_0 == 2ULL) && t59);
  t347[89ULL] = (real_T)(((size_t)Q_idx_0 == 2ULL) && t63);
  t347[90ULL] = (real_T)(((size_t)Q_idx_0 == 2ULL) && t62);
  t347[91ULL] = (real_T)(((size_t)Q_idx_0 == 3ULL) && t60);
  t347[92ULL] = (real_T)(((size_t)Q_idx_0 == 3ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[93ULL] = (real_T)(((size_t)Q_idx_0 == 3ULL) && t59);
  t347[94ULL] = (real_T)(((size_t)Q_idx_0 == 3ULL) && t63);
  t347[95ULL] = (real_T)(((size_t)Q_idx_0 == 3ULL) && t62);
  t347[96ULL] = (real_T)(((size_t)Q_idx_0 == 4ULL) && t60);
  t347[97ULL] = (real_T)(((size_t)Q_idx_0 == 4ULL) && t61);
  t347[98ULL] = (real_T)(((size_t)Q_idx_0 == 4ULL) && t59);
  t347[99ULL] = (real_T)(((size_t)Q_idx_0 == 4ULL) && t63);
  t347[100ULL] = (real_T)(((size_t)Q_idx_0 == 4ULL) && t62);
  t347[101ULL] = (real_T)(((size_t)Q_idx_0 == 5ULL) && t60);
  t347[102ULL] = (real_T)(((size_t)Q_idx_0 == 5ULL) && t61);
  t347[103ULL] = (real_T)(((size_t)Q_idx_0 == 5ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[104ULL] = (real_T)(((size_t)Q_idx_0 == 5ULL) && t63);
  t347[105ULL] = (real_T)(((size_t)Q_idx_0 == 5ULL) && t62);
  t347[106ULL] = (real_T)(((size_t)Q_idx_0 == 6ULL) && t60);
  t347[107ULL] = (real_T)(((size_t)Q_idx_0 == 6ULL) && t61);
  t347[108ULL] = (real_T)(((size_t)Q_idx_0 == 6ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[109ULL] = (real_T)(((size_t)Q_idx_0 == 6ULL) && t59);
  t347[110ULL] = (real_T)(((size_t)Q_idx_0 == 6ULL) && t62);
  t347[111ULL] = (real_T)(((size_t)Q_idx_0 == 7ULL) && t60);
  t347[112ULL] = (real_T)(((size_t)Q_idx_0 == 7ULL) && t61);
  t347[113ULL] = (real_T)(((size_t)Q_idx_0 == 7ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[114ULL] = (real_T)(((size_t)Q_idx_0 == 7ULL) && t59);
  t347[115ULL] = (real_T)(((size_t)Q_idx_0 == 7ULL) && t63);
  t347[116ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) && t60);
  t347[117ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) && t61);
  t347[118ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) &&
    Basic_Peripherals_T_Junction_TL_CONVERGINGTOAFLAG);
  t347[119ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) && t59);
  t347[120ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) && t63);
  t347[121ULL] = (real_T)(((size_t)Q_idx_0 == 1ULL) && t62);
  t347[122ULL] = intrm_sf_mf_228;
  t347[123ULL] = intrm_sf_mf_231;
  t347[124ULL] = X[50ULL] - 0.1;
  t347[125ULL] = 500.0 - X[50ULL];
  t347[126ULL] = X[49ULL] - 232.6432;
  t347[127ULL] = 393.15 - X[49ULL];
  t347[128ULL] = t380;
  t347[129ULL] = (real_T)(((size_t)Q_idx_1 == 2ULL) && t67);
  t347[130ULL] = (real_T)(((size_t)Q_idx_1 == 2ULL) && t64);
  t347[131ULL] = (real_T)(((size_t)Q_idx_1 == 2ULL) && t65);
  t347[132ULL] = (real_T)(((size_t)Q_idx_1 == 2ULL) && t69);
  t347[133ULL] = (real_T)(((size_t)Q_idx_1 == 2ULL) && t68);
  t347[134ULL] = (real_T)(((size_t)Q_idx_1 == 3ULL) && t66);
  t347[135ULL] = (real_T)(((size_t)Q_idx_1 == 3ULL) && t64);
  t347[136ULL] = (real_T)(((size_t)Q_idx_1 == 3ULL) && t65);
  t347[137ULL] = (real_T)(((size_t)Q_idx_1 == 3ULL) && t69);
  t347[138ULL] = (real_T)(((size_t)Q_idx_1 == 3ULL) && t68);
  t347[139ULL] = (real_T)(((size_t)Q_idx_1 == 4ULL) && t66);
  t347[140ULL] = (real_T)(((size_t)Q_idx_1 == 4ULL) && t67);
  t347[141ULL] = (real_T)(((size_t)Q_idx_1 == 4ULL) && t65);
  t347[142ULL] = (real_T)(((size_t)Q_idx_1 == 4ULL) && t69);
  t347[143ULL] = (real_T)(((size_t)Q_idx_1 == 4ULL) && t68);
  t347[144ULL] = (real_T)(((size_t)Q_idx_1 == 5ULL) && t66);
  t347[145ULL] = (real_T)(((size_t)Q_idx_1 == 5ULL) && t67);
  t347[146ULL] = (real_T)(((size_t)Q_idx_1 == 5ULL) && t64);
  t347[147ULL] = (real_T)(((size_t)Q_idx_1 == 5ULL) && t69);
  t347[148ULL] = (real_T)(((size_t)Q_idx_1 == 5ULL) && t68);
  t347[149ULL] = (real_T)(((size_t)Q_idx_1 == 6ULL) && t66);
  t347[150ULL] = (real_T)(((size_t)Q_idx_1 == 6ULL) && t67);
  t347[151ULL] = (real_T)(((size_t)Q_idx_1 == 6ULL) && t64);
  t347[152ULL] = (real_T)(((size_t)Q_idx_1 == 6ULL) && t65);
  t347[153ULL] = (real_T)(((size_t)Q_idx_1 == 6ULL) && t68);
  t347[154ULL] = (real_T)(((size_t)Q_idx_1 == 7ULL) && t66);
  t347[155ULL] = (real_T)(((size_t)Q_idx_1 == 7ULL) && t67);
  t347[156ULL] = (real_T)(((size_t)Q_idx_1 == 7ULL) && t64);
  t347[157ULL] = (real_T)(((size_t)Q_idx_1 == 7ULL) && t65);
  t347[158ULL] = (real_T)(((size_t)Q_idx_1 == 7ULL) && t69);
  t347[159ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t66);
  t347[160ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t67);
  t347[161ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t64);
  t347[162ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t65);
  t347[163ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t69);
  t347[164ULL] = (real_T)(((size_t)Q_idx_1 == 1ULL) && t68);
  t347[165ULL] = Subsystem_Reference_T_Junction_TL_mu_B;
  t347[166ULL] = intrm_sf_mf_234;
  t347[167ULL] = X[40ULL] - 0.1;
  t347[168ULL] = 500.0 - X[40ULL];
  t347[169ULL] = X[39ULL] - 232.6432;
  t347[170ULL] = 393.15 - X[39ULL];
  t347[171ULL] = t379;
  t347[172ULL] = (real_T)(((size_t)Q_idx_2 == 2ULL) && t73);
  t347[173ULL] = (real_T)(((size_t)Q_idx_2 == 2ULL) && t70);
  t347[174ULL] = (real_T)(((size_t)Q_idx_2 == 2ULL) && t71);
  t347[175ULL] = (real_T)(((size_t)Q_idx_2 == 2ULL) && t75);
  t347[176ULL] = (real_T)(((size_t)Q_idx_2 == 2ULL) && t74);
  t347[177ULL] = (real_T)(((size_t)Q_idx_2 == 3ULL) && t72);
  t347[178ULL] = (real_T)(((size_t)Q_idx_2 == 3ULL) && t70);
  t347[179ULL] = (real_T)(((size_t)Q_idx_2 == 3ULL) && t71);
  t347[180ULL] = (real_T)(((size_t)Q_idx_2 == 3ULL) && t75);
  t347[181ULL] = (real_T)(((size_t)Q_idx_2 == 3ULL) && t74);
  t347[182ULL] = (real_T)(((size_t)Q_idx_2 == 4ULL) && t72);
  t347[183ULL] = (real_T)(((size_t)Q_idx_2 == 4ULL) && t73);
  t347[184ULL] = (real_T)(((size_t)Q_idx_2 == 4ULL) && t71);
  t347[185ULL] = (real_T)(((size_t)Q_idx_2 == 4ULL) && t75);
  t347[186ULL] = (real_T)(((size_t)Q_idx_2 == 4ULL) && t74);
  t347[187ULL] = (real_T)(((size_t)Q_idx_2 == 5ULL) && t72);
  t347[188ULL] = (real_T)(((size_t)Q_idx_2 == 5ULL) && t73);
  t347[189ULL] = (real_T)(((size_t)Q_idx_2 == 5ULL) && t70);
  t347[190ULL] = (real_T)(((size_t)Q_idx_2 == 5ULL) && t75);
  t347[191ULL] = (real_T)(((size_t)Q_idx_2 == 5ULL) && t74);
  t347[192ULL] = (real_T)(((size_t)Q_idx_2 == 6ULL) && t72);
  t347[193ULL] = (real_T)(((size_t)Q_idx_2 == 6ULL) && t73);
  t347[194ULL] = (real_T)(((size_t)Q_idx_2 == 6ULL) && t70);
  t347[195ULL] = (real_T)(((size_t)Q_idx_2 == 6ULL) && t71);
  t347[196ULL] = (real_T)(((size_t)Q_idx_2 == 6ULL) && t74);
  t347[197ULL] = (real_T)(((size_t)Q_idx_2 == 7ULL) && t72);
  t347[198ULL] = (real_T)(((size_t)Q_idx_2 == 7ULL) && t73);
  t347[199ULL] = (real_T)(((size_t)Q_idx_2 == 7ULL) && t70);
  t347[200ULL] = (real_T)(((size_t)Q_idx_2 == 7ULL) && t71);
  t347[201ULL] = (real_T)(((size_t)Q_idx_2 == 7ULL) && t75);
  t347[202ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t72);
  t347[203ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t73);
  t347[204ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t70);
  t347[205ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t71);
  t347[206ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t75);
  t347[207ULL] = (real_T)(((size_t)Q_idx_2 == 1ULL) && t74);
  t347[208ULL] = intrm_sf_mf_255;
  t347[209ULL] = t381;
  t347[210ULL] = intrm_sf_mf_260;
  t347[211ULL] = X[12ULL];
  t347[212ULL] = intrm_sf_mf_263;
  t347[213ULL] = intrm_sf_mf_261;
  t347[214ULL] = intrm_sf_mf_234;
  t347[215ULL] = intrm_sf_mf_263;
  t347[216ULL] = intrm_sf_mf_236;
  t347[217ULL] = intrm_sf_mf_237;
  t347[218ULL] = intrm_sf_mf_238;
  t347[219ULL] = 393.15 - X[86ULL];
  t347[220ULL] = X[86ULL] - 232.6432;
  t347[221ULL] = 393.15 - X[87ULL];
  t347[222ULL] = X[87ULL] - 232.6432;
  t347[223ULL] = 500.0 - X[11ULL];
  t347[224ULL] = X[11ULL] - 0.1;
  t347[225ULL] = 393.15 - X[10ULL];
  t347[226ULL] = X[10ULL] - 232.6432;
  for (b = 0; b < 227; b++) {
    out.mX[b] = t347[b];
  }

  (void)LC;
  (void)t383;
  return 0;
}
