/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_dxm.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_dxm(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t476, NeDsMethodOutput *t477)
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
  ETTS0 t0;
  ETTS0 t1;
  ETTS0 t10;
  ETTS0 t11;
  ETTS0 t2;
  ETTS0 t3;
  ETTS0 t4;
  ETTS0 t5;
  ETTS0 t6;
  ETTS0 t7;
  ETTS0 t8;
  ETTS0 t9;
  ETTS0 w_efOut;
  ETTS0 x_efOut;
  PmRealVector out;
  real_T X[148];
  real_T t282[45];
  real_T t361[4];
  real_T t362[4];
  real_T t363[4];
  real_T t364[4];
  real_T t365[4];
  real_T t366[4];
  real_T t367[4];
  real_T t368[4];
  real_T t369[4];
  real_T t370[4];
  real_T ab_efOut[1];
  real_T ac_efOut[1];
  real_T ad_efOut[1];
  real_T bb_efOut[1];
  real_T bc_efOut[1];
  real_T bd_efOut[1];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T cc_efOut[1];
  real_T cd_efOut[1];
  real_T d_efOut[1];
  real_T db_efOut[1];
  real_T dc_efOut[1];
  real_T dd_efOut[1];
  real_T ec_efOut[1];
  real_T ed_efOut[1];
  real_T fc_efOut[1];
  real_T fd_efOut[1];
  real_T g_efOut[1];
  real_T gb_efOut[1];
  real_T gc_efOut[1];
  real_T gd_efOut[1];
  real_T h_efOut[1];
  real_T hb_efOut[1];
  real_T hc_efOut[1];
  real_T hd_efOut[1];
  real_T i_efOut[1];
  real_T ib_efOut[1];
  real_T ic_efOut[1];
  real_T id_efOut[1];
  real_T j_efOut[1];
  real_T jb_efOut[1];
  real_T jc_efOut[1];
  real_T jd_efOut[1];
  real_T k_efOut[1];
  real_T kb_efOut[1];
  real_T kc_efOut[1];
  real_T kd_efOut[1];
  real_T lb_efOut[1];
  real_T lc_efOut[1];
  real_T ld_efOut[1];
  real_T mb_efOut[1];
  real_T mc_efOut[1];
  real_T md_efOut[1];
  real_T n_efOut[1];
  real_T nb_efOut[1];
  real_T nc_efOut[1];
  real_T nd_efOut[1];
  real_T o_efOut[1];
  real_T ob_efOut[1];
  real_T oc_efOut[1];
  real_T od_efOut[1];
  real_T pb_efOut[1];
  real_T pc_efOut[1];
  real_T qb_efOut[1];
  real_T qc_efOut[1];
  real_T r_efOut[1];
  real_T rb_efOut[1];
  real_T rc_efOut[1];
  real_T s_efOut[1];
  real_T sb_efOut[1];
  real_T sc_efOut[1];
  real_T t360[1];
  real_T t_efOut[1];
  real_T tb_efOut[1];
  real_T tc_efOut[1];
  real_T u_efOut[1];
  real_T ub_efOut[1];
  real_T uc_efOut[1];
  real_T v_efOut[1];
  real_T vb_efOut[1];
  real_T vc_efOut[1];
  real_T wb_efOut[1];
  real_T wc_efOut[1];
  real_T xb_efOut[1];
  real_T xc_efOut[1];
  real_T y_efOut[1];
  real_T yb_efOut[1];
  real_T yc_efOut[1];
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I;
  real_T Basic_Peripherals_Pipe_TL3_rho_I;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I;
  real_T Subsystem_Reference_Pipe_TL2_alpha_I;
  real_T Subsystem_Reference_Pipe_TL2_rho_I;
  real_T Subsystem_Reference_Pipe_TL4_alpha_I;
  real_T Subsystem_Reference_Pipe_TL4_rho_I;
  real_T intermediate_der1561;
  real_T intermediate_der1568;
  real_T intermediate_der1574;
  real_T intermediate_der1575;
  real_T intermediate_der1576;
  real_T intermediate_der1577;
  real_T intermediate_der177;
  real_T intermediate_der178;
  real_T intermediate_der179;
  real_T intermediate_der203;
  real_T intermediate_der204;
  real_T intermediate_der209;
  real_T intermediate_der210;
  real_T intermediate_der212;
  real_T intermediate_der454;
  real_T intermediate_der503;
  real_T intermediate_der504;
  real_T intermediate_der509;
  real_T intermediate_der510;
  real_T intermediate_der511;
  real_T intermediate_der512;
  real_T intermediate_der563;
  real_T intermediate_der564;
  real_T intermediate_der565;
  real_T intermediate_der593;
  real_T intermediate_der595;
  real_T intermediate_der596;
  real_T intermediate_der631;
  real_T intermediate_der632;
  real_T intermediate_der662;
  real_T intermediate_der664;
  real_T intermediate_der665;
  real_T intermediate_der72;
  real_T intermediate_der73;
  real_T intermediate_der76;
  real_T intermediate_der77;
  real_T intrm_sf_mf_249;
  real_T t301_idx_0;
  real_T t383;
  real_T t384;
  real_T t385;
  real_T t386;
  real_T t387;
  real_T t388;
  real_T t390;
  real_T t391;
  real_T t394;
  real_T t395;
  real_T t396;
  real_T t399;
  real_T t400;
  real_T t401;
  real_T t404;
  real_T t405;
  real_T t406;
  real_T t409;
  real_T t410;
  real_T t411;
  real_T t414;
  real_T t415;
  real_T t416;
  real_T t419;
  real_T t420;
  real_T t421;
  real_T t425;
  real_T t426;
  real_T t435;
  real_T t439;
  real_T t442;
  real_T t472;
  size_t t13[1];
  size_t t14[1];
  size_t t16[1];
  size_t t381;
  int32_T b;
  for (b = 0; b < 148; b++) {
    X[b] = t476->mX.mX[b];
  }

  out = t477->mDXM;
  t360[0ULL] = X[1ULL];
  t13[0] = 20ULL;
  t14[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL], &t13
    [0ULL], &t14[0ULL]);
  t11 = efOut;
  t360[0ULL] = X[0ULL] * -0.8 + 1.1132499999999999;
  t16[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t11.mField0[0ULL], &t11.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = c_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&d_efOut[0ULL], &t11.mField0[0ULL], &t11.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = d_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I = t301_idx_0;
  t360[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = e_efOut;
  t360[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&f_efOut.mField0[0ULL], &f_efOut.mField1[0ULL],
    &f_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t7 = f_efOut;
  tlu2_2d_linear_linear_value(&g_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = g_efOut[0];
  t383 = t301_idx_0;
  tlu2_2d_linear_linear_value(&h_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = h_efOut[0];
  t384 = t301_idx_0;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = i_efOut[0];
  t472 = t301_idx_0;
  tlu2_2d_linear_linear_value(&j_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = j_efOut[0];
  Basic_Peripherals_Pipe_TL3_rho_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&k_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = k_efOut[0];
  intermediate_der212 = X[5ULL] / (Basic_Peripherals_Pipe_TL3_rho_I == 0.0 ?
    1.0E-16 : Basic_Peripherals_Pipe_TL3_rho_I) * 100.0 + t301_idx_0;
  t360[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&l_efOut.mField0[0ULL], &l_efOut.mField1[0ULL],
    &l_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t9 = l_efOut;
  t360[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t6 = m_efOut;
  tlu2_2d_linear_linear_value(&n_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = n_efOut[0];
  intermediate_der1575 = t301_idx_0;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = o_efOut[0];
  t385 = t301_idx_0;
  t360[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t5 = p_efOut;
  t360[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t3 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = r_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&s_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = s_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&t_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = t_efOut[0];
  intermediate_der511 = t301_idx_0;
  tlu2_2d_linear_linear_value(&u_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = u_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&v_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = v_efOut[0];
  intermediate_der512 = X[13ULL] /
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I) *
    100.0 + t301_idx_0;
  t360[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t4 = w_efOut;
  t360[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t1 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = y_efOut[0];
  Subsystem_Reference_Pipe_TL2_alpha_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&ab_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = ab_efOut[0];
  t386 = t301_idx_0;
  tlu2_2d_linear_linear_value(&bb_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = bb_efOut[0];
  intermediate_der595 = t301_idx_0;
  tlu2_2d_linear_linear_value(&cb_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = cb_efOut[0];
  Subsystem_Reference_Pipe_TL2_rho_I = t301_idx_0;
  tlu2_2d_linear_linear_value(&db_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t301_idx_0 = db_efOut[0];
  intermediate_der596 = X[17ULL] / (Subsystem_Reference_Pipe_TL2_rho_I == 0.0 ?
    1.0E-16 : Subsystem_Reference_Pipe_TL2_rho_I) * 100.0 + t301_idx_0;
  t360[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t360[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t2 = eb_efOut;
  t360[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&fb_efOut.mField0[0ULL], &fb_efOut.mField1[0ULL],
    &fb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t360[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t0 = fb_efOut;
  tlu2_2d_linear_linear_value(&gb_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = gb_efOut[0];
  Subsystem_Reference_Pipe_TL4_alpha_I = t360[0ULL];
  tlu2_2d_linear_linear_value(&hb_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = hb_efOut[0];
  t387 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ib_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ib_efOut[0];
  intermediate_der664 = t360[0ULL];
  tlu2_2d_linear_linear_value(&jb_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = jb_efOut[0];
  Subsystem_Reference_Pipe_TL4_rho_I = t360[0ULL];
  tlu2_2d_linear_linear_value(&kb_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = kb_efOut[0];
  intrm_sf_mf_249 = t360[0ULL];
  intermediate_der665 = X[19ULL] / (Subsystem_Reference_Pipe_TL4_rho_I == 0.0 ?
    1.0E-16 : Subsystem_Reference_Pipe_TL4_rho_I) * 100.0 + intrm_sf_mf_249;
  tlu2_2d_linear_linear_value(&lb_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = lb_efOut[0];
  intrm_sf_mf_249 = t360[0ULL];
  tlu2_2d_linear_linear_value(&mb_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = mb_efOut[0];
  t388 = t360[0ULL];
  intermediate_der1577 = X[11ULL] / (t385 == 0.0 ? 1.0E-16 : t385) * 100.0 + X
    [93ULL];
  tlu2_2d_linear_linear_value(&nb_efOut[0ULL], &t11.mField1[0ULL], &t11.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = nb_efOut[0];
  intermediate_der72 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ob_efOut[0ULL], &t11.mField0[0ULL], &t11.mField2
    [0ULL], &t10.mField1[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ob_efOut[0];
  intermediate_der73 = t360[0ULL] * -0.8;
  tlu2_2d_linear_linear_value(&pb_efOut[0ULL], &t11.mField1[0ULL], &t11.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = pb_efOut[0];
  intermediate_der76 = t360[0ULL];
  tlu2_2d_linear_linear_value(&qb_efOut[0ULL], &t11.mField0[0ULL], &t11.mField2
    [0ULL], &t10.mField1[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = qb_efOut[0];
  intermediate_der77 = t360[0ULL] * -0.8;
  tlu2_2d_linear_linear_value(&rb_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = rb_efOut[0];
  intermediate_der177 = t360[0ULL];
  tlu2_2d_linear_linear_value(&sb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField1[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = sb_efOut[0];
  intermediate_der178 = t360[0ULL];
  tlu2_2d_linear_linear_value(&tb_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = tb_efOut[0];
  intermediate_der179 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ub_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField1[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ub_efOut[0];
  t442 = t360[0ULL];
  tlu2_2d_linear_linear_value(&vb_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = vb_efOut[0];
  intermediate_der1576 = t360[0ULL];
  tlu2_2d_linear_linear_value(&wb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField1[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = wb_efOut[0];
  intermediate_der210 = t360[0ULL];
  tlu2_2d_linear_linear_value(&xb_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = xb_efOut[0];
  intermediate_der203 = t360[0ULL];
  tlu2_2d_linear_linear_value(&yb_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField1[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = yb_efOut[0];
  intermediate_der204 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ac_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t7.mField0[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ac_efOut[0];
  intermediate_der1574 = t360[0ULL];
  tlu2_2d_linear_linear_value(&bc_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t7.mField1[0ULL], &t7.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = bc_efOut[0];
  intermediate_der209 = t360[0ULL];
  t391 = Basic_Peripherals_Pipe_TL3_rho_I * Basic_Peripherals_Pipe_TL3_rho_I;
  intermediate_der454 = -X[5ULL] / (t391 == 0.0 ? 1.0E-16 : t391) *
    intermediate_der203 * 100.0 + intermediate_der1574;
  intermediate_der1574 = (-X[5ULL] / (t391 == 0.0 ? 1.0E-16 : t391) *
    intermediate_der204 + 1.0 / (Basic_Peripherals_Pipe_TL3_rho_I == 0.0 ?
    1.0E-16 : Basic_Peripherals_Pipe_TL3_rho_I)) * 100.0 + intermediate_der209;
  intermediate_der209 = ((intermediate_der210 - (t383 * intermediate_der1574 +
    intermediate_der212 * intermediate_der178) * 1000.0) *
    Basic_Peripherals_Pipe_TL3_rho_I + (t472 - t383 * intermediate_der212 *
    1000.0) * intermediate_der204) * 0.0019634954084936209;
  intermediate_der210 = ((intermediate_der1576 - (t383 * intermediate_der454 +
    intermediate_der212 * intermediate_der177) * 1000.0) *
    Basic_Peripherals_Pipe_TL3_rho_I + (t472 - t383 * intermediate_der212 *
    1000.0) * intermediate_der203) * 0.0019634954084936209;
  t394 = -(intermediate_der212 * Basic_Peripherals_Pipe_TL3_rho_I);
  t395 = t384 * t384;
  t472 = ((t394 / (t395 == 0.0 ? 1.0E-16 : t395) * t442 + (intermediate_der212 *
            intermediate_der204 + Basic_Peripherals_Pipe_TL3_rho_I *
            intermediate_der1574) / (t384 == 0.0 ? 1.0E-16 : t384)) * 0.01 - X
          [6ULL] * intermediate_der178) * 0.0019634954084936209;
  intermediate_der212 = ((t394 / (t395 == 0.0 ? 1.0E-16 : t395) *
    intermediate_der179 + (intermediate_der212 * intermediate_der203 +
    Basic_Peripherals_Pipe_TL3_rho_I * intermediate_der454) / (t384 == 0.0 ?
    1.0E-16 : t384)) * 0.01 - (X[6ULL] * intermediate_der177 + t383)) *
    0.0019634954084936209;
  tlu2_2d_linear_linear_value(&cc_efOut[0ULL], &t9.mField1[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = cc_efOut[0];
  intermediate_der1576 = t360[0ULL];
  tlu2_2d_linear_linear_value(&dc_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField1[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = dc_efOut[0];
  intermediate_der1574 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ec_efOut[0ULL], &t9.mField1[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ec_efOut[0];
  intermediate_der454 = t360[0ULL];
  tlu2_2d_linear_linear_value(&fc_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField1[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = fc_efOut[0];
  t390 = t360[0ULL];
  tlu2_2d_linear_linear_value(&gc_efOut[0ULL], &t5.mField1[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = gc_efOut[0];
  t391 = t360[0ULL];
  tlu2_2d_linear_linear_value(&hc_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = hc_efOut[0];
  t394 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ic_efOut[0ULL], &t5.mField1[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ic_efOut[0];
  t396 = t360[0ULL];
  tlu2_2d_linear_linear_value(&jc_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = jc_efOut[0];
  t399 = t360[0ULL];
  tlu2_2d_linear_linear_value(&kc_efOut[0ULL], &t5.mField1[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = kc_efOut[0];
  intermediate_der563 = t360[0ULL];
  tlu2_2d_linear_linear_value(&lc_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = lc_efOut[0];
  intermediate_der510 = t360[0ULL];
  tlu2_2d_linear_linear_value(&mc_efOut[0ULL], &t5.mField1[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = mc_efOut[0];
  intermediate_der503 = t360[0ULL];
  tlu2_2d_linear_linear_value(&nc_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = nc_efOut[0];
  intermediate_der504 = t360[0ULL];
  tlu2_2d_linear_linear_value(&oc_efOut[0ULL], &t5.mField1[0ULL], &t5.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = oc_efOut[0];
  intermediate_der564 = t360[0ULL];
  tlu2_2d_linear_linear_value(&pc_efOut[0ULL], &t5.mField0[0ULL], &t5.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = pc_efOut[0];
  intermediate_der509 = t360[0ULL];
  t401 = Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
    Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I;
  intermediate_der565 = -X[13ULL] / (t401 == 0.0 ? 1.0E-16 : t401) *
    intermediate_der503 * 100.0 + intermediate_der564;
  intermediate_der564 = (-X[13ULL] / (t401 == 0.0 ? 1.0E-16 : t401) *
    intermediate_der504 + 1.0 /
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I)) *
    100.0 + intermediate_der509;
  intermediate_der509 = ((intermediate_der510 -
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
     intermediate_der564 + intermediate_der512 * t394) * 1000.0) *
    Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I +
    (intermediate_der511 -
     Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
     intermediate_der512 * 1000.0) * intermediate_der504) *
    0.0051961524227066326;
  intermediate_der510 = ((intermediate_der563 -
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
     intermediate_der565 + intermediate_der512 * t391) * 1000.0) *
    Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I +
    (intermediate_der511 -
     Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
     intermediate_der512 * 1000.0) * intermediate_der503) *
    0.0051961524227066326;
  t404 = -(intermediate_der512 *
           Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I);
  t405 = Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I *
    Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I;
  intermediate_der511 = ((t404 / (t405 == 0.0 ? 1.0E-16 : t405) * t399 +
    (intermediate_der512 * intermediate_der504 +
     Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
     intermediate_der564) /
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I)) *
    0.01 - X[14ULL] * t394) * 0.0051961524227066326;
  intermediate_der512 = ((t404 / (t405 == 0.0 ? 1.0E-16 : t405) * t396 +
    (intermediate_der512 * intermediate_der503 +
     Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
     intermediate_der565) /
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I)) *
    0.01 - (X[14ULL] * t391 +
            Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I)) *
    0.0051961524227066326;
  tlu2_2d_linear_linear_value(&qc_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = qc_efOut[0];
  intermediate_der563 = t360[0ULL];
  tlu2_2d_linear_linear_value(&rc_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = rc_efOut[0];
  intermediate_der564 = t360[0ULL];
  tlu2_2d_linear_linear_value(&sc_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = sc_efOut[0];
  intermediate_der565 = t360[0ULL];
  tlu2_2d_linear_linear_value(&tc_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = tc_efOut[0];
  t400 = t360[0ULL];
  tlu2_2d_linear_linear_value(&uc_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = uc_efOut[0];
  t401 = t360[0ULL];
  tlu2_2d_linear_linear_value(&vc_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = vc_efOut[0];
  t404 = t360[0ULL];
  tlu2_2d_linear_linear_value(&wc_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = wc_efOut[0];
  t406 = t360[0ULL];
  tlu2_2d_linear_linear_value(&xc_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = xc_efOut[0];
  t409 = t360[0ULL];
  tlu2_2d_linear_linear_value(&yc_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t1.mField0[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = yc_efOut[0];
  intermediate_der631 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ad_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t1.mField1[0ULL], &t1.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ad_efOut[0];
  intermediate_der593 = t360[0ULL];
  t411 = Subsystem_Reference_Pipe_TL2_rho_I * Subsystem_Reference_Pipe_TL2_rho_I;
  intermediate_der632 = -X[17ULL] / (t411 == 0.0 ? 1.0E-16 : t411) * t406 *
    100.0 + intermediate_der631;
  intermediate_der631 = (-X[17ULL] / (t411 == 0.0 ? 1.0E-16 : t411) * t409 + 1.0
    / (Subsystem_Reference_Pipe_TL2_rho_I == 0.0 ? 1.0E-16 :
       Subsystem_Reference_Pipe_TL2_rho_I)) * 100.0 + intermediate_der593;
  intermediate_der593 = ((t404 - (Subsystem_Reference_Pipe_TL2_alpha_I *
    intermediate_der631 + intermediate_der596 * intermediate_der564) * 1000.0) *
    Subsystem_Reference_Pipe_TL2_rho_I + (intermediate_der595 -
    Subsystem_Reference_Pipe_TL2_alpha_I * intermediate_der596 * 1000.0) * t409)
    * 0.00098174770424681044;
  t404 = ((t401 - (Subsystem_Reference_Pipe_TL2_alpha_I * intermediate_der632 +
                   intermediate_der596 * intermediate_der563) * 1000.0) *
          Subsystem_Reference_Pipe_TL2_rho_I + (intermediate_der595 -
           Subsystem_Reference_Pipe_TL2_alpha_I * intermediate_der596 * 1000.0) *
          t406) * 0.00098174770424681044;
  t414 = -(intermediate_der596 * Subsystem_Reference_Pipe_TL2_rho_I);
  t415 = t386 * t386;
  intermediate_der595 = ((t414 / (t415 == 0.0 ? 1.0E-16 : t415) * t400 +
    (intermediate_der596 * t409 + Subsystem_Reference_Pipe_TL2_rho_I *
     intermediate_der631) / (t386 == 0.0 ? 1.0E-16 : t386)) * 0.01 - X[18ULL] *
    intermediate_der564) * 0.00098174770424681044;
  intermediate_der596 = ((t414 / (t415 == 0.0 ? 1.0E-16 : t415) *
    intermediate_der565 + (intermediate_der596 * t406 +
    Subsystem_Reference_Pipe_TL2_rho_I * intermediate_der632) / (t386 == 0.0 ?
    1.0E-16 : t386)) * 0.01 - (X[18ULL] * intermediate_der563 +
    Subsystem_Reference_Pipe_TL2_alpha_I)) * 0.00098174770424681044;
  tlu2_2d_linear_linear_value(&bd_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = bd_efOut[0];
  t401 = t360[0ULL];
  tlu2_2d_linear_linear_value(&cd_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = cd_efOut[0];
  intermediate_der631 = t360[0ULL];
  tlu2_2d_linear_linear_value(&dd_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = dd_efOut[0];
  intermediate_der632 = t360[0ULL];
  tlu2_2d_linear_linear_value(&ed_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ed_efOut[0];
  t410 = t360[0ULL];
  tlu2_2d_linear_linear_value(&fd_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = fd_efOut[0];
  t411 = t360[0ULL];
  tlu2_2d_linear_linear_value(&gd_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = gd_efOut[0];
  t414 = t360[0ULL];
  tlu2_2d_linear_linear_value(&hd_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = hd_efOut[0];
  t416 = t360[0ULL];
  tlu2_2d_linear_linear_value(&id_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = id_efOut[0];
  t419 = t360[0ULL];
  tlu2_2d_linear_linear_value(&jd_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = jd_efOut[0];
  intermediate_der1561 = t360[0ULL];
  tlu2_2d_linear_linear_value(&kd_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = kd_efOut[0];
  intermediate_der662 = t360[0ULL];
  t421 = Subsystem_Reference_Pipe_TL4_rho_I * Subsystem_Reference_Pipe_TL4_rho_I;
  intermediate_der1568 = -X[19ULL] / (t421 == 0.0 ? 1.0E-16 : t421) * t416 *
    100.0 + intermediate_der1561;
  intermediate_der1561 = (-X[19ULL] / (t421 == 0.0 ? 1.0E-16 : t421) * t419 +
    1.0 / (Subsystem_Reference_Pipe_TL4_rho_I == 0.0 ? 1.0E-16 :
           Subsystem_Reference_Pipe_TL4_rho_I)) * 100.0 + intermediate_der662;
  intermediate_der662 = ((t414 - (Subsystem_Reference_Pipe_TL4_alpha_I *
    intermediate_der1561 + intermediate_der665 * intermediate_der631) * 1000.0) *
    Subsystem_Reference_Pipe_TL4_rho_I + (intermediate_der664 -
    Subsystem_Reference_Pipe_TL4_alpha_I * intermediate_der665 * 1000.0) * t419)
    * 0.00098174770424681044;
  t414 = ((t411 - (Subsystem_Reference_Pipe_TL4_alpha_I * intermediate_der1568 +
                   intermediate_der665 * t401) * 1000.0) *
          Subsystem_Reference_Pipe_TL4_rho_I + (intermediate_der664 -
           Subsystem_Reference_Pipe_TL4_alpha_I * intermediate_der665 * 1000.0) *
          t416) * 0.00098174770424681044;
  t439 = -(intermediate_der665 * Subsystem_Reference_Pipe_TL4_rho_I);
  t425 = t387 * t387;
  intermediate_der664 = ((t439 / (t425 == 0.0 ? 1.0E-16 : t425) * t410 +
    (intermediate_der665 * t419 + Subsystem_Reference_Pipe_TL4_rho_I *
     intermediate_der1561) / (t387 == 0.0 ? 1.0E-16 : t387)) * 0.01 - X[20ULL] *
    intermediate_der631) * 0.00098174770424681044;
  intermediate_der665 = ((t439 / (t425 == 0.0 ? 1.0E-16 : t425) *
    intermediate_der632 + (intermediate_der665 * t416 +
    Subsystem_Reference_Pipe_TL4_rho_I * intermediate_der1568) / (t387 == 0.0 ?
    1.0E-16 : t387)) * 0.01 - (X[20ULL] * t401 +
    Subsystem_Reference_Pipe_TL4_alpha_I)) * 0.00098174770424681044;
  tlu2_2d_linear_linear_value(&ld_efOut[0ULL], &t9.mField1[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = ld_efOut[0];
  t411 = t360[0ULL];
  tlu2_2d_linear_linear_value(&md_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField1[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = md_efOut[0];
  intermediate_der1561 = t360[0ULL];
  tlu2_2d_linear_linear_value(&nd_efOut[0ULL], &t9.mField1[0ULL], &t9.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = nd_efOut[0];
  intermediate_der1568 = t360[0ULL];
  tlu2_2d_linear_linear_value(&od_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t6.mField1[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField8, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t360[0] = od_efOut[0];
  t420 = t360[0ULL];
  t435 = t385 * t385;
  t421 = -X[11ULL] / (t435 == 0.0 ? 1.0E-16 : t435) * intermediate_der454 *
    100.0;
  t439 = (-X[11ULL] / (t435 == 0.0 ? 1.0E-16 : t435) * t390 + 1.0 / (t385 == 0.0
           ? 1.0E-16 : t385)) * 100.0;
  t426 = ((intermediate_der1574 - (t439 * t388 + t420 * intermediate_der1577) *
           1000.0) * t385 + (intermediate_der1575 - t388 * intermediate_der1577 *
           1000.0) * t390) * 0.0003375;
  intermediate_der1574 = ((intermediate_der1576 - (t421 * t388 +
    intermediate_der1568 * intermediate_der1577) * 1000.0) * t385 +
    (intermediate_der1575 - t388 * intermediate_der1577 * 1000.0) *
    intermediate_der454) * 0.0003375;
  t301_idx_0 = -(t385 * intermediate_der1577);
  t435 = intrm_sf_mf_249 * intrm_sf_mf_249;
  intermediate_der1576 = ((t301_idx_0 / (t435 == 0.0 ? 1.0E-16 : t435) *
    intermediate_der1561 + (t390 * intermediate_der1577 + t385 * t439) /
    (intrm_sf_mf_249 == 0.0 ? 1.0E-16 : intrm_sf_mf_249)) * 0.01 - X[10ULL] *
    t420) * 0.0003375;
  intermediate_der1577 = ((t301_idx_0 / (t435 == 0.0 ? 1.0E-16 : t435) * t411 +
    (intermediate_der454 * intermediate_der1577 + t385 * t421) /
    (intrm_sf_mf_249 == 0.0 ? 1.0E-16 : intrm_sf_mf_249)) * 0.01 - (X[10ULL] *
    intermediate_der1568 + t388)) * 0.0003375;
  t361[0ULL] = (1.0 / (t384 == 0.0 ? 1.0E-16 : t384) * intermediate_der204 +
                -1.0 / (t395 == 0.0 ? 1.0E-16 : t395) *
                Basic_Peripherals_Pipe_TL3_rho_I * t442) * 0.0019634954084936209;
  t361[1ULL] = t472 * 100.0 / 7.0639122278786468;
  t361[2ULL] = (-t383 * intermediate_der204 + -intermediate_der178 *
                Basic_Peripherals_Pipe_TL3_rho_I) * 0.0019634954084936209;
  t361[3ULL] = intermediate_der209 * 0.001 / 7.0639122278786468;
  t362[0ULL] = (1.0 / (t384 == 0.0 ? 1.0E-16 : t384) * intermediate_der203 +
                -1.0 / (t395 == 0.0 ? 1.0E-16 : t395) *
                Basic_Peripherals_Pipe_TL3_rho_I * intermediate_der179) *
    0.0019634954084936209;
  t362[1ULL] = intermediate_der212 * 100.0 / 7.0639122278786468;
  t362[2ULL] = (-t383 * intermediate_der203 + -intermediate_der177 *
                Basic_Peripherals_Pipe_TL3_rho_I) * 0.0019634954084936209;
  t362[3ULL] = intermediate_der210 * 0.001 / 7.0639122278786468;
  t363[0ULL] = (-t388 * intermediate_der454 + -intermediate_der1568 * t385) *
    0.0003375;
  t363[1ULL] = intermediate_der1574 * 0.001 / 1.1978799206025905;
  t363[2ULL] = (1.0 / (intrm_sf_mf_249 == 0.0 ? 1.0E-16 : intrm_sf_mf_249) *
                intermediate_der454 + -1.0 / (t435 == 0.0 ? 1.0E-16 : t435) *
                t385 * t411) * 0.0003375;
  t363[3ULL] = intermediate_der1577 * 100.0 / 1.1978799206025905;
  t364[0ULL] = (-t388 * t390 + -t420 * t385) * 0.0003375;
  t364[1ULL] = t426 * 0.001 / 1.1978799206025905;
  t364[2ULL] = (1.0 / (intrm_sf_mf_249 == 0.0 ? 1.0E-16 : intrm_sf_mf_249) *
                t390 + -1.0 / (t435 == 0.0 ? 1.0E-16 : t435) * t385 *
                intermediate_der1561) * 0.0003375;
  t364[3ULL] = intermediate_der1576 * 100.0 / 1.1978799206025905;
  t365[0ULL] = (1.0 /
                (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I ==
                 0.0 ? 1.0E-16 :
                 Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I) *
                intermediate_der504 + -1.0 / (t405 == 0.0 ? 1.0E-16 : t405) *
                Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
                t399) * 0.0051961524227066326;
  t365[1ULL] = intermediate_der511 * 100.0 / 18.693786844573559;
  t365[2ULL] = (-Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
                intermediate_der504 + -t394 *
                Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I) *
    0.0051961524227066326;
  t365[3ULL] = intermediate_der509 * 0.001 / 18.693786844573559;
  t366[0ULL] = (1.0 /
                (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I ==
                 0.0 ? 1.0E-16 :
                 Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I) *
                intermediate_der503 + -1.0 / (t405 == 0.0 ? 1.0E-16 : t405) *
                Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
                t396) * 0.0051961524227066326;
  t366[1ULL] = intermediate_der512 * 100.0 / 18.693786844573559;
  t366[2ULL] = (-Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_alpha_I *
                intermediate_der503 + -t391 *
                Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I) *
    0.0051961524227066326;
  t366[3ULL] = intermediate_der510 * 0.001 / 18.693786844573559;
  t367[0ULL] = (1.0 / (t386 == 0.0 ? 1.0E-16 : t386) * t409 + -1.0 / (t415 ==
    0.0 ? 1.0E-16 : t415) * Subsystem_Reference_Pipe_TL2_rho_I * t400) *
    0.00098174770424681044;
  t367[1ULL] = intermediate_der595 * 100.0 / 3.5319561139393234;
  t367[2ULL] = (-Subsystem_Reference_Pipe_TL2_alpha_I * t409 +
                -intermediate_der564 * Subsystem_Reference_Pipe_TL2_rho_I) *
    0.00098174770424681044;
  t367[3ULL] = intermediate_der593 * 0.001 / 3.5319561139393234;
  t368[0ULL] = (1.0 / (t386 == 0.0 ? 1.0E-16 : t386) * t406 + -1.0 / (t415 ==
    0.0 ? 1.0E-16 : t415) * Subsystem_Reference_Pipe_TL2_rho_I *
                intermediate_der565) * 0.00098174770424681044;
  t368[1ULL] = intermediate_der596 * 100.0 / 3.5319561139393234;
  t368[2ULL] = (-Subsystem_Reference_Pipe_TL2_alpha_I * t406 +
                -intermediate_der563 * Subsystem_Reference_Pipe_TL2_rho_I) *
    0.00098174770424681044;
  t368[3ULL] = t404 * 0.001 / 3.5319561139393234;
  t369[0ULL] = (1.0 / (t387 == 0.0 ? 1.0E-16 : t387) * t419 + -1.0 / (t425 ==
    0.0 ? 1.0E-16 : t425) * Subsystem_Reference_Pipe_TL4_rho_I * t410) *
    0.00098174770424681044;
  t369[1ULL] = intermediate_der664 * 100.0 / 3.5319561139393234;
  t369[2ULL] = (-Subsystem_Reference_Pipe_TL4_alpha_I * t419 +
                -intermediate_der631 * Subsystem_Reference_Pipe_TL4_rho_I) *
    0.00098174770424681044;
  t369[3ULL] = intermediate_der662 * 0.001 / 3.5319561139393234;
  t370[0ULL] = (1.0 / (t387 == 0.0 ? 1.0E-16 : t387) * t416 + -1.0 / (t425 ==
    0.0 ? 1.0E-16 : t425) * Subsystem_Reference_Pipe_TL4_rho_I *
                intermediate_der632) * 0.00098174770424681044;
  t370[1ULL] = intermediate_der665 * 100.0 / 3.5319561139393234;
  t370[2ULL] = (-Subsystem_Reference_Pipe_TL4_alpha_I * t416 + -t401 *
                Subsystem_Reference_Pipe_TL4_rho_I) * 0.00098174770424681044;
  t370[3ULL] = t414 * 0.001 / 3.5319561139393234;
  t282[0ULL] = (Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I * (X[2ULL] +
    0.001) * intermediate_der73 +
                Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I * (X[2ULL] +
    0.001) * intermediate_der77) * 0.001 / 291.40147251301789;
  t282[1ULL] = (Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I * (X[2ULL] +
    0.001) * intermediate_der72 +
                Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I * (X[2ULL] +
    0.001) * intermediate_der76) * 0.001 / 291.40147251301789;
  t282[2ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_cp_I *
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I * 0.001 /
    291.40147251301789;
  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 3ULL] = t361[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 7ULL] = t362[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 11ULL] = t363[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 15ULL] = t364[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 19ULL] = t365[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 23ULL] = t366[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 27ULL] = t367[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 31ULL] = t368[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 35ULL] = t369[t381];
  }

  for (t381 = 0ULL; t381 < 4ULL; t381++) {
    t282[t381 + 39ULL] = t370[t381];
  }

  out.mX[0] = t282[0];
  out.mX[1] = t282[1];
  out.mX[2] = t282[2];
  out.mX[3] = t282[3];
  out.mX[4] = t282[4];
  out.mX[5] = t282[5];
  out.mX[6] = t282[6];
  out.mX[7] = t282[7];
  out.mX[8] = t282[8];
  out.mX[9] = t282[9];
  out.mX[10] = t282[10];
  out.mX[11] = t282[11];
  out.mX[12] = t282[12];
  out.mX[13] = t282[13];
  out.mX[14] = t282[14];
  out.mX[15] = t282[15];
  out.mX[16] = t282[16];
  out.mX[17] = t282[17];
  out.mX[18] = t282[18];
  out.mX[19] = t282[19];
  out.mX[20] = t282[20];
  out.mX[21] = t282[21];
  out.mX[22] = t282[22];
  out.mX[23] = t282[23];
  out.mX[24] = t282[24];
  out.mX[25] = t282[25];
  out.mX[26] = t282[26];
  out.mX[27] = t282[27];
  out.mX[28] = t282[28];
  out.mX[29] = t282[29];
  out.mX[30] = t282[30];
  out.mX[31] = t282[31];
  out.mX[32] = t282[32];
  out.mX[33] = t282[33];
  out.mX[34] = t282[34];
  out.mX[35] = t282[35];
  out.mX[36] = t282[36];
  out.mX[37] = t282[37];
  out.mX[38] = t282[38];
  out.mX[39] = t282[39];
  out.mX[40] = t282[40];
  out.mX[41] = t282[41];
  out.mX[42] = t282[42];
  out.mX[43] = -(t388 * 1000.0) * t385 * 0.0003375 * 0.001 / 1.1978799206025905;
  out.mX[44] = t385 / (intrm_sf_mf_249 == 0.0 ? 1.0E-16 : intrm_sf_mf_249) *
    3.3750000000000003E-6 * 100.0 / 1.1978799206025905;
  (void)LC;
  (void)t477;
  return 0;
}
