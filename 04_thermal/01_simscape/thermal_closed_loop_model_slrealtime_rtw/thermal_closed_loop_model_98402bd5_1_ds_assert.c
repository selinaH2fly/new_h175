/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_assert.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_assert(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1215, NeDsMethodOutput *t1216)
{
  ETTS0 ab_efOut;
  ETTS0 ac_efOut;
  ETTS0 ae_efOut;
  ETTS0 ag_efOut;
  ETTS0 ah_efOut;
  ETTS0 b_efOut;
  ETTS0 bd_efOut;
  ETTS0 bf_efOut;
  ETTS0 cb_efOut;
  ETTS0 cc_efOut;
  ETTS0 ce_efOut;
  ETTS0 cf_efOut;
  ETTS0 ch_efOut;
  ETTS0 d_efOut;
  ETTS0 dc_efOut;
  ETTS0 dd_efOut;
  ETTS0 de_efOut;
  ETTS0 e_efOut;
  ETTS0 eb_efOut;
  ETTS0 efOut;
  ETTS0 ef_efOut;
  ETTS0 eh_efOut;
  ETTS0 fb_efOut;
  ETTS0 fc_efOut;
  ETTS0 fd_efOut;
  ETTS0 fe_efOut;
  ETTS0 fg_efOut;
  ETTS0 g_efOut;
  ETTS0 gd_efOut;
  ETTS0 ge_efOut;
  ETTS0 gf_efOut;
  ETTS0 gg_efOut;
  ETTS0 gh_efOut;
  ETTS0 hb_efOut;
  ETTS0 hc_efOut;
  ETTS0 i_efOut;
  ETTS0 ig_efOut;
  ETTS0 ih_efOut;
  ETTS0 jb_efOut;
  ETTS0 jc_efOut;
  ETTS0 k_efOut;
  ETTS0 kd_efOut;
  ETTS0 kg_efOut;
  ETTS0 kh_efOut;
  ETTS0 l_efOut;
  ETTS0 lc_efOut;
  ETTS0 ld_efOut;
  ETTS0 le_efOut;
  ETTS0 lf_efOut;
  ETTS0 lg_efOut;
  ETTS0 lh_efOut;
  ETTS0 mb_efOut;
  ETTS0 me_efOut;
  ETTS0 mf_efOut;
  ETTS0 n_efOut;
  ETTS0 nb_efOut;
  ETTS0 nc_efOut;
  ETTS0 nd_efOut;
  ETTS0 ng_efOut;
  ETTS0 nh_efOut;
  ETTS0 o_efOut;
  ETTS0 oc_efOut;
  ETTS0 od_efOut;
  ETTS0 oe_efOut;
  ETTS0 of_efOut;
  ETTS0 oh_efOut;
  ETTS0 pb_efOut;
  ETTS0 pg_efOut;
  ETTS0 q_efOut;
  ETTS0 qb_efOut;
  ETTS0 qc_efOut;
  ETTS0 qd_efOut;
  ETTS0 qe_efOut;
  ETTS0 qf_efOut;
  ETTS0 qh_efOut;
  ETTS0 r_efOut;
  ETTS0 rc_efOut;
  ETTS0 rd_efOut;
  ETTS0 re_efOut;
  ETTS0 rg_efOut;
  ETTS0 rh_efOut;
  ETTS0 sb_efOut;
  ETTS0 t100;
  ETTS0 t103;
  ETTS0 t106;
  ETTS0 t108;
  ETTS0 t11;
  ETTS0 t3;
  ETTS0 t41;
  ETTS0 t50;
  ETTS0 t52;
  ETTS0 t66;
  ETTS0 t70;
  ETTS0 t86;
  ETTS0 t91;
  ETTS0 t95;
  ETTS0 t97;
  ETTS0 t98;
  ETTS0 t99;
  ETTS0 t_efOut;
  ETTS0 tb_efOut;
  ETTS0 tc_efOut;
  ETTS0 td_efOut;
  ETTS0 te_efOut;
  ETTS0 tf_efOut;
  ETTS0 tg_efOut;
  ETTS0 th_efOut;
  ETTS0 u_efOut;
  ETTS0 ue_efOut;
  ETTS0 uf_efOut;
  ETTS0 ug_efOut;
  ETTS0 vc_efOut;
  ETTS0 vd_efOut;
  ETTS0 vh_efOut;
  ETTS0 w_efOut;
  ETTS0 wf_efOut;
  ETTS0 wg_efOut;
  ETTS0 x_efOut;
  ETTS0 xc_efOut;
  ETTS0 xe_efOut;
  ETTS0 xg_efOut;
  ETTS0 xh_efOut;
  ETTS0 yb_efOut;
  ETTS0 yc_efOut;
  ETTS0 yd_efOut;
  ETTS0 yf_efOut;
  PmIntVector out;
  real_T X[148];
  real_T nonscalar12[8];
  real_T ad_efOut[1];
  real_T af_efOut[1];
  real_T ai_efOut[1];
  real_T bb_efOut[1];
  real_T bc_efOut[1];
  real_T be_efOut[1];
  real_T bg_efOut[1];
  real_T bh_efOut[1];
  real_T c_efOut[1];
  real_T cd_efOut[1];
  real_T cg_efOut[1];
  real_T db_efOut[1];
  real_T df_efOut[1];
  real_T dg_efOut[1];
  real_T dh_efOut[1];
  real_T ec_efOut[1];
  real_T ed_efOut[1];
  real_T ee_efOut[1];
  real_T eg_efOut[1];
  real_T f_efOut[1];
  real_T ff_efOut[1];
  real_T fh_efOut[1];
  real_T gb_efOut[1];
  real_T gc_efOut[1];
  real_T h_efOut[1];
  real_T hd_efOut[1];
  real_T he_efOut[1];
  real_T hf_efOut[1];
  real_T hg_efOut[1];
  real_T hh_efOut[1];
  real_T ib_efOut[1];
  real_T ic_efOut[1];
  real_T id_efOut[1];
  real_T ie_efOut[1];
  real_T if_efOut[1];
  real_T j_efOut[1];
  real_T jd_efOut[1];
  real_T je_efOut[1];
  real_T jf_efOut[1];
  real_T jg_efOut[1];
  real_T jh_efOut[1];
  real_T kb_efOut[1];
  real_T kc_efOut[1];
  real_T ke_efOut[1];
  real_T kf_efOut[1];
  real_T lb_efOut[1];
  real_T m_efOut[1];
  real_T mc_efOut[1];
  real_T md_efOut[1];
  real_T mg_efOut[1];
  real_T mh_efOut[1];
  real_T ne_efOut[1];
  real_T nf_efOut[1];
  real_T ob_efOut[1];
  real_T og_efOut[1];
  real_T p_efOut[1];
  real_T pc_efOut[1];
  real_T pd_efOut[1];
  real_T pe_efOut[1];
  real_T pf_efOut[1];
  real_T ph_efOut[1];
  real_T qg_efOut[1];
  real_T rb_efOut[1];
  real_T rf_efOut[1];
  real_T s_efOut[1];
  real_T sc_efOut[1];
  real_T sd_efOut[1];
  real_T se_efOut[1];
  real_T sf_efOut[1];
  real_T sg_efOut[1];
  real_T sh_efOut[1];
  real_T t805[1];
  real_T ub_efOut[1];
  real_T uc_efOut[1];
  real_T ud_efOut[1];
  real_T uh_efOut[1];
  real_T v_efOut[1];
  real_T vb_efOut[1];
  real_T ve_efOut[1];
  real_T vf_efOut[1];
  real_T vg_efOut[1];
  real_T wb_efOut[1];
  real_T wc_efOut[1];
  real_T wd_efOut[1];
  real_T we_efOut[1];
  real_T wh_efOut[1];
  real_T xb_efOut[1];
  real_T xd_efOut[1];
  real_T xf_efOut[1];
  real_T y_efOut[1];
  real_T ye_efOut[1];
  real_T yg_efOut[1];
  real_T yh_efOut[1];
  real_T Basic_Peripherals_Aux_TCP_convection_A_mdot_abs;
  real_T Basic_Peripherals_Aux_TCP_hydraulic_power;
  real_T Basic_Peripherals_Aux_TCP_omega_pos;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_rho;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I;
  real_T Basic_Peripherals_Gate_Valve_TL_area_ratio;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_A_rho;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_B_rho;
  real_T Basic_Peripherals_Gate_Valve_TL_mdot_c;
  real_T Basic_Peripherals_Gate_Valve_TL_rho_avg;
  real_T Basic_Peripherals_Gate_Valve_TL_valve_area;
  real_T Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL4_rho;
  real_T Basic_Peripherals_Pipe_TL3_beta_I;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_rho;
  real_T Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs;
  real_T Basic_Peripherals_Pipe_TL3_convection_B_rho;
  real_T Basic_Peripherals_Pipe_TL3_rho_I;
  real_T Basic_Peripherals_T_Junction_TL1_convection_A_rho;
  real_T Basic_Peripherals_T_Junction_TL1_convection_B_rho;
  real_T Basic_Peripherals_T_Junction_TL1_convection_C_rho;
  real_T Basic_Peripherals_T_Junction_TL1_mdot_threshold;
  real_T Basic_Peripherals_T_Junction_TL1_rho_avg;
  real_T Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs;
  real_T Basic_Peripherals_T_Junction_TL_convection_A_rho;
  real_T Basic_Peripherals_T_Junction_TL_convection_B_rho;
  real_T Basic_Peripherals_T_Junction_TL_convection_C_rho;
  real_T Basic_Peripherals_T_Junction_TL_mdot_threshold;
  real_T Basic_Peripherals_T_Junction_TL_rho_avg;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect2;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect8;
  real_T Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I;
  real_T Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_rho;
  real_T Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL2_rho;
  real_T Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_rho;
  real_T Subsystem_Reference_Pipe_TL2_beta_I;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_rho;
  real_T Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL2_convection_B_rho;
  real_T Subsystem_Reference_Pipe_TL2_rho_I;
  real_T Subsystem_Reference_Pipe_TL4_beta_I;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_rho;
  real_T Subsystem_Reference_Pipe_TL4_convection_B_mdot;
  real_T Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL4_convection_B_rho;
  real_T Subsystem_Reference_Pipe_TL4_rho_I;
  real_T Subsystem_Reference_TCP_6812_convection_A_mdot_abs;
  real_T Subsystem_Reference_TCP_6812_convection_A_rho;
  real_T Subsystem_Reference_TCP_6812_convection_B_rho;
  real_T Subsystem_Reference_TCP_6812_hydraulic_power;
  real_T Subsystem_Reference_TCP_6812_mechanical_power;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c;
  real_T Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs;
  real_T Subsystem_Reference_T_Junction_TL_convection_C_rho;
  real_T Subsystem_Reference_T_Junction_TL_rho_avg;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T intrm_sf_mf_105;
  real_T intrm_sf_mf_106;
  real_T intrm_sf_mf_107;
  real_T intrm_sf_mf_112;
  real_T intrm_sf_mf_13;
  real_T intrm_sf_mf_137;
  real_T intrm_sf_mf_138;
  real_T intrm_sf_mf_144;
  real_T intrm_sf_mf_148;
  real_T intrm_sf_mf_149;
  real_T intrm_sf_mf_150;
  real_T intrm_sf_mf_152;
  real_T intrm_sf_mf_162;
  real_T intrm_sf_mf_163;
  real_T intrm_sf_mf_172;
  real_T intrm_sf_mf_18;
  real_T intrm_sf_mf_181;
  real_T intrm_sf_mf_19;
  real_T intrm_sf_mf_191;
  real_T intrm_sf_mf_192;
  real_T intrm_sf_mf_239;
  real_T intrm_sf_mf_240;
  real_T intrm_sf_mf_249;
  real_T intrm_sf_mf_3;
  real_T intrm_sf_mf_4;
  real_T intrm_sf_mf_64;
  real_T intrm_sf_mf_7;
  real_T intrm_sf_mf_84;
  real_T intrm_sf_mf_93;
  real_T t1004;
  real_T t1202;
  real_T t1203;
  real_T t1209;
  real_T t1214;
  real_T t802_idx_0;
  real_T t806;
  real_T t807;
  real_T t808;
  real_T t809;
  real_T t810;
  real_T t811;
  real_T t812;
  real_T t813;
  real_T t814;
  real_T t815;
  real_T t816;
  real_T t817;
  real_T t818;
  real_T t819;
  real_T t820;
  real_T t821;
  real_T t822;
  real_T t823;
  real_T t824;
  real_T t825;
  real_T t826;
  real_T t827;
  real_T t828;
  real_T t829;
  real_T t830;
  real_T t831;
  real_T t833;
  real_T t834;
  real_T t835;
  real_T t836;
  real_T t837;
  real_T t838;
  real_T t839;
  real_T t840;
  real_T t841;
  real_T t842;
  real_T t843;
  real_T t844;
  real_T t845;
  real_T t846;
  real_T t847;
  real_T t848;
  real_T t849;
  real_T t850;
  real_T t851;
  real_T t852;
  real_T t854;
  real_T t856;
  real_T t857;
  real_T t858;
  real_T t859;
  real_T t861;
  real_T t862;
  real_T t869;
  real_T t873;
  real_T t881;
  real_T t891;
  real_T t892;
  real_T t913;
  real_T t916;
  real_T t925;
  real_T t927;
  real_T t939;
  real_T t940;
  real_T t957;
  real_T t964;
  real_T t965;
  real_T t976;
  real_T t987;
  real_T t991;
  real_T t999;
  size_t t113[1];
  size_t t114[1];
  size_t t116[1];
  size_t t596[1];
  size_t t602[1];
  int32_T t713[1173];
  int32_T M[214];
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  int32_T Q_idx_2;
  int32_T b;
  boolean_T t109;
  boolean_T t110;
  boolean_T t111;
  Q_idx_0 = t1215->mQ.mX[0];
  Q_idx_1 = t1215->mQ.mX[1];
  Q_idx_2 = t1215->mQ.mX[2];
  for (b = 0; b < 214; b++) {
    M[b] = t1215->mM.mX[b];
  }

  U_idx_0 = t1215->mU.mX[0];
  U_idx_1 = t1215->mU.mX[1];
  U_idx_2 = t1215->mU.mX[2];
  U_idx_3 = t1215->mU.mX[3];
  U_idx_6 = t1215->mU.mX[6];
  U_idx_7 = t1215->mU.mX[7];
  for (b = 0; b < 148; b++) {
    X[b] = t1215->mX.mX[b];
  }

  out = t1216->mASSERT;
  nonscalar12[0] = -209.43951023931953;
  nonscalar12[1] = 0.0;
  nonscalar12[2] = 209.43951023931953;
  nonscalar12[3] = 261.79938779914943;
  nonscalar12[4] = 314.15926535897933;
  nonscalar12[5] = 366.51914291880917;
  nonscalar12[6] = 418.87902047863906;
  nonscalar12[7] = 439.822971502571;
  t1202 = X[0ULL] * -0.8 + 1.1132499999999999;
  t1214 = U_idx_0 * 0.10471975511965977;
  Basic_Peripherals_Aux_TCP_convection_A_mdot_abs = pmf_sqrt(X[29ULL] * X[29ULL]
    + 4.6221943695030632E-11);
  t805[0ULL] = X[28ULL];
  t113[0] = 20ULL;
  t114[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = efOut;
  t805[0ULL] = t1202;
  t116[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t97 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = c_efOut[0];
  t1203 = t802_idx_0;
  t805[0ULL] = X[31ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = d_efOut;
  t805[0ULL] = X[23ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t11 = e_efOut;
  tlu2_2d_linear_linear_value(&f_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = f_efOut[0];
  t1209 = t802_idx_0;
  t806 = pmf_sqrt(t1214 * t1214 + 13.433628212593847) + t1214;
  Basic_Peripherals_Aux_TCP_omega_pos = t806 / 2.0;
  t806 = X[29ULL] / (t1203 == 0.0 ? 1.0E-16 : t1203);
  t807 = 366.51914291880917 / (Basic_Peripherals_Aux_TCP_omega_pos == 0.0 ?
    1.0E-16 : Basic_Peripherals_Aux_TCP_omega_pos) * t806;
  if (t807 < 0.0) {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 =
      15.800203873598369;
  } else if (t807 * 1.0E+6 <= 1666.6666666666665) {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 = t807 *
      t807 * -1.2844036697247704E+6 + 15.800203873598369;
  } else if (t807 * 1.0E+6 <= 3333.333333333333) {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 = (t807 *
      1834.8623853211036 + t807 * t807 * -1.8348623853211019E+6) +
      14.271151885830777;
  } else {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 = (t807 *
      1.0E+6 - 3333.333333333333) * -0.010397553516819574;
  }

  Basic_Peripherals_Aux_TCP_hydraulic_power = t1203 *
    (Basic_Peripherals_Aux_TCP_omega_pos / 366.51914291880917 *
     (Basic_Peripherals_Aux_TCP_omega_pos / 366.51914291880917) *
     Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0) * 9.81 *
    t806;
  t806 = t1214 * X[32ULL];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 = -X[29ULL] -
    X[35ULL];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 = pmf_sqrt
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
     Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
     4.8042127793498068E-8);
  t805[0ULL] = X[34ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = g_efOut;
  tlu2_2d_linear_linear_value(&h_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = h_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_rho = t802_idx_0;
  t805[0ULL] = X[1ULL];
  tlu2_linear_linear_prelookup(&i_efOut.mField0[0ULL], &i_efOut.mField1[0ULL],
    &i_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = i_efOut;
  tlu2_2d_linear_linear_value(&j_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = j_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I = t802_idx_0;
  intrm_sf_mf_3 = U_idx_1 / 0.045000000000000005;
  if (intrm_sf_mf_3 <= 0.0) {
    intrm_sf_mf_4 = 0.0;
  } else if (intrm_sf_mf_3 <= 0.005) {
    intrm_sf_mf_4 = intrm_sf_mf_3 * intrm_sf_mf_3 * 100.50251256281406;
  } else if (intrm_sf_mf_3 <= 0.995) {
    intrm_sf_mf_4 = intrm_sf_mf_3 * 1.0050251256281406 - 0.0025125628140703518;
  } else if (intrm_sf_mf_3 <= 1.0) {
    intrm_sf_mf_4 = (1.0 - intrm_sf_mf_3) * (1.0 - intrm_sf_mf_3) *
      -100.50251256281406 + 1.0;
  } else {
    intrm_sf_mf_4 = 1.0;
  }

  intrm_sf_mf_3 = intrm_sf_mf_4 * 0.045000000000000005;
  if (intrm_sf_mf_3 / 0.045000000000000005 <= -1.0) {
    intrm_sf_mf_4 = -1.0;
  } else if (intrm_sf_mf_3 / 0.045000000000000005 >= 1.0) {
    intrm_sf_mf_4 = 1.0;
  } else {
    intrm_sf_mf_4 = intrm_sf_mf_3 / 0.045000000000000005;
  }

  Basic_Peripherals_Gate_Valve_TL_valve_area = pmf_acos(intrm_sf_mf_4) *
    0.0010125000000000002 - intrm_sf_mf_3 / 2.0 * pmf_sqrt(0.0020250000000000003
    - intrm_sf_mf_3 * intrm_sf_mf_3);
  Basic_Peripherals_Gate_Valve_TL_area_ratio = 0.0015904312808798331 -
    Basic_Peripherals_Gate_Valve_TL_valve_area;
  Basic_Peripherals_Gate_Valve_TL_valve_area = (0.0015904312808798331 -
    Basic_Peripherals_Gate_Valve_TL_valve_area) + 1.0E-12;
  Basic_Peripherals_Gate_Valve_TL_area_ratio =
    (Basic_Peripherals_Gate_Valve_TL_area_ratio + 1.0E-12) /
    0.0019634954084936209;
  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs = pmf_sqrt(X[46ULL] * X
    [46ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[45ULL];
  tlu2_linear_linear_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = k_efOut;
  t805[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&l_efOut.mField0[0ULL], &l_efOut.mField1[0ULL],
    &l_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t91 = l_efOut;
  tlu2_2d_linear_linear_value(&m_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t91.mField0[0ULL], &t91.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = m_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_convection_A_rho = t802_idx_0;
  t805[0ULL] = X[48ULL];
  tlu2_linear_linear_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = n_efOut;
  t805[0ULL] = X[44ULL];
  tlu2_linear_linear_prelookup(&o_efOut.mField0[0ULL], &o_efOut.mField1[0ULL],
    &o_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t103 = o_efOut;
  tlu2_2d_linear_linear_value(&p_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t103.mField0[0ULL], &t103.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = p_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_convection_B_rho = t802_idx_0;
  t805[0ULL] = X[45ULL];
  tlu2_linear_nearest_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = q_efOut;
  t805[0ULL] = X[42ULL];
  tlu2_linear_nearest_prelookup(&r_efOut.mField0[0ULL], &r_efOut.mField1[0ULL],
    &r_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t52 = r_efOut;
  tlu2_2d_linear_nearest_value(&s_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = s_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_rho_avg = t802_idx_0;
  t805[0ULL] = X[48ULL];
  tlu2_linear_nearest_prelookup(&t_efOut.mField0[0ULL], &t_efOut.mField1[0ULL],
    &t_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = t_efOut;
  t805[0ULL] = X[44ULL];
  tlu2_linear_nearest_prelookup(&u_efOut.mField0[0ULL], &u_efOut.mField1[0ULL],
    &u_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t70 = u_efOut;
  tlu2_2d_linear_nearest_value(&v_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = v_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_mdot_c = pmf_sqrt
    (Basic_Peripherals_Gate_Valve_TL_valve_area * 0.78539816339744828) *
    ((Basic_Peripherals_Gate_Valve_TL_rho_avg + t802_idx_0) / 2.0) * 12.0;
  Basic_Peripherals_Gate_Valve_TL_rho_avg =
    (Basic_Peripherals_Gate_Valve_TL_convection_A_rho +
     Basic_Peripherals_Gate_Valve_TL_convection_B_rho) / 2.0;
  t805[0ULL] = X[49ULL];
  tlu2_linear_linear_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = w_efOut;
  t805[0ULL] = X[50ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t3 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = y_efOut[0];
  t808 = t802_idx_0;
  t805[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = ab_efOut;
  tlu2_2d_linear_linear_value(&bb_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t91.mField0[0ULL], &t91.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = bb_efOut[0];
  t809 = t802_idx_0;
  t805[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&cb_efOut.mField0[0ULL], &cb_efOut.mField1[0ULL],
    &cb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = cb_efOut;
  tlu2_2d_linear_linear_value(&db_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = db_efOut[0];
  Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL4_rho = t802_idx_0;
  t805[0ULL] = X[37ULL];
  tlu2_linear_nearest_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t108 = eb_efOut;
  t805[0ULL] = X[5ULL];
  tlu2_linear_nearest_prelookup(&fb_efOut.mField0[0ULL], &fb_efOut.mField1[0ULL],
    &fb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t86 = fb_efOut;
  tlu2_2d_linear_nearest_value(&gb_efOut[0ULL], &t108.mField0[0ULL],
    &t108.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = gb_efOut[0];
  intrm_sf_mf_138 = t802_idx_0;
  t805[0ULL] = X[53ULL];
  tlu2_linear_nearest_prelookup(&hb_efOut.mField0[0ULL], &hb_efOut.mField1[0ULL],
    &hb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = hb_efOut;
  tlu2_2d_linear_nearest_value(&ib_efOut[0ULL], &t97.mField0[0ULL],
    &t97.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ib_efOut[0];
  intrm_sf_mf_240 = t802_idx_0;
  t805[0ULL] = X[6ULL];
  tlu2_linear_nearest_prelookup(&jb_efOut.mField0[0ULL], &jb_efOut.mField1[0ULL],
    &jb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = jb_efOut;
  tlu2_2d_linear_nearest_value(&kb_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = kb_efOut[0];
  intrm_sf_mf_249 = t802_idx_0;
  intrm_sf_mf_181 = (-X[7ULL] - (-X[57ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&lb_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = lb_efOut[0];
  t810 = t802_idx_0;
  t805[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&mb_efOut.mField0[0ULL], &mb_efOut.mField1[0ULL],
    &mb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t66 = mb_efOut;
  t805[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&nb_efOut.mField0[0ULL], &nb_efOut.mField1[0ULL],
    &nb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t95 = nb_efOut;
  tlu2_2d_linear_linear_value(&ob_efOut[0ULL], &t66.mField0[0ULL], &t66.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ob_efOut[0];
  Basic_Peripherals_Pipe_TL3_beta_I = t802_idx_0;
  Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs = pmf_sqrt(X[7ULL] * X[7ULL]
    + 3.7732198934718893E-12);
  t805[0ULL] = X[58ULL];
  tlu2_linear_linear_prelookup(&pb_efOut.mField0[0ULL], &pb_efOut.mField1[0ULL],
    &pb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t41 = pb_efOut;
  t805[0ULL] = X[38ULL];
  tlu2_linear_linear_prelookup(&qb_efOut.mField0[0ULL], &qb_efOut.mField1[0ULL],
    &qb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t99 = qb_efOut;
  tlu2_2d_linear_linear_value(&rb_efOut[0ULL], &t41.mField0[0ULL], &t41.mField2
    [0ULL], &t99.mField0[0ULL], &t99.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = rb_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_A_rho = t802_idx_0;
  Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs = pmf_sqrt(X[57ULL] * X[57ULL]
    + 3.7732198934718893E-12);
  t805[0ULL] = X[60ULL];
  tlu2_linear_linear_prelookup(&sb_efOut.mField0[0ULL], &sb_efOut.mField1[0ULL],
    &sb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = sb_efOut;
  t805[0ULL] = X[54ULL];
  tlu2_linear_linear_prelookup(&tb_efOut.mField0[0ULL], &tb_efOut.mField1[0ULL],
    &tb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t100 = tb_efOut;
  tlu2_2d_linear_linear_value(&ub_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t100.mField0[0ULL], &t100.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ub_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_B_rho = t802_idx_0;
  tlu2_2d_linear_linear_value(&vb_efOut[0ULL], &t66.mField0[0ULL], &t66.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = vb_efOut[0];
  Basic_Peripherals_Pipe_TL3_rho_I = t802_idx_0;
  tlu2_2d_linear_nearest_value(&wb_efOut[0ULL], &t108.mField0[0ULL],
    &t108.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = wb_efOut[0];
  intrm_sf_mf_112 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&xb_efOut[0ULL], &t97.mField0[0ULL],
    &t97.mField2[0ULL], &t86.mField0[0ULL], &t86.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = xb_efOut[0];
  intrm_sf_mf_162 = t802_idx_0;
  t805[0ULL] = X[62ULL];
  tlu2_linear_nearest_prelookup(&yb_efOut.mField0[0ULL], &yb_efOut.mField1[0ULL],
    &yb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = yb_efOut;
  t805[0ULL] = X[54ULL];
  tlu2_linear_nearest_prelookup(&ac_efOut.mField0[0ULL], &ac_efOut.mField1[0ULL],
    &ac_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t106 = ac_efOut;
  tlu2_2d_linear_nearest_value(&bc_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = bc_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs = t802_idx_0;
  t805[0ULL] = X[63ULL];
  tlu2_linear_nearest_prelookup(&cc_efOut.mField0[0ULL], &cc_efOut.mField1[0ULL],
    &cc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t66 = cc_efOut;
  t805[0ULL] = X[50ULL];
  tlu2_linear_nearest_prelookup(&dc_efOut.mField0[0ULL], &dc_efOut.mField1[0ULL],
    &dc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t97 = dc_efOut;
  tlu2_2d_linear_nearest_value(&ec_efOut[0ULL], &t66.mField0[0ULL],
    &t66.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ec_efOut[0];
  Basic_Peripherals_T_Junction_TL_mdot_threshold = t802_idx_0;
  t805[0ULL] = X[64ULL];
  tlu2_linear_nearest_prelookup(&fc_efOut.mField0[0ULL], &fc_efOut.mField1[0ULL],
    &fc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t98 = fc_efOut;
  tlu2_2d_linear_nearest_value(&gc_efOut[0ULL], &t98.mField0[0ULL],
    &t98.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = gc_efOut[0];
  Basic_Peripherals_T_Junction_TL_mdot_threshold =
    ((Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs *
      0.0019634954084936209 + Basic_Peripherals_T_Junction_TL_mdot_threshold *
      0.0019634954084936209) + t802_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs = pmf_sqrt(X[57ULL] * X
    [57ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[62ULL];
  tlu2_linear_linear_prelookup(&hc_efOut.mField0[0ULL], &hc_efOut.mField1[0ULL],
    &hc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = hc_efOut;
  tlu2_2d_linear_linear_value(&ic_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t100.mField0[0ULL], &t100.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ic_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_A_rho = t802_idx_0;
  t811 = pmf_sqrt(X[4ULL] * X[4ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[63ULL];
  tlu2_linear_linear_prelookup(&jc_efOut.mField0[0ULL], &jc_efOut.mField1[0ULL],
    &jc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t86 = jc_efOut;
  tlu2_2d_linear_linear_value(&kc_efOut[0ULL], &t86.mField0[0ULL], &t86.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = kc_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_B_rho = t802_idx_0;
  t805[0ULL] = X[64ULL];
  tlu2_linear_linear_prelookup(&lc_efOut.mField0[0ULL], &lc_efOut.mField1[0ULL],
    &lc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = lc_efOut;
  tlu2_2d_linear_linear_value(&mc_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t103.mField0[0ULL], &t103.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = mc_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_C_rho = t802_idx_0;
  Basic_Peripherals_T_Junction_TL_rho_avg =
    ((Basic_Peripherals_T_Junction_TL_convection_A_rho * 0.0019634954084936209 +
      Basic_Peripherals_T_Junction_TL_convection_B_rho * 0.0019634954084936209)
     + t802_idx_0 * 0.0019634954084936209) / 0.0058904862254808626;
  t805[0ULL] = X[73ULL];
  tlu2_linear_nearest_prelookup(&nc_efOut.mField0[0ULL], &nc_efOut.mField1[0ULL],
    &nc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = nc_efOut;
  t805[0ULL] = X[23ULL];
  tlu2_linear_nearest_prelookup(&oc_efOut.mField0[0ULL], &oc_efOut.mField1[0ULL],
    &oc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t106 = oc_efOut;
  tlu2_2d_linear_nearest_value(&pc_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = pc_efOut[0];
  t812 = t802_idx_0;
  t805[0ULL] = X[74ULL];
  tlu2_linear_nearest_prelookup(&qc_efOut.mField0[0ULL], &qc_efOut.mField1[0ULL],
    &qc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = qc_efOut;
  t805[0ULL] = X[40ULL];
  tlu2_linear_nearest_prelookup(&rc_efOut.mField0[0ULL], &rc_efOut.mField1[0ULL],
    &rc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t103 = rc_efOut;
  tlu2_2d_linear_nearest_value(&sc_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t103.mField0[0ULL], &t103.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = sc_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mdot_threshold = t802_idx_0;
  t805[0ULL] = X[75ULL];
  tlu2_linear_nearest_prelookup(&tc_efOut.mField0[0ULL], &tc_efOut.mField1[0ULL],
    &tc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t3 = tc_efOut;
  tlu2_2d_linear_nearest_value(&uc_efOut[0ULL], &t3.mField0[0ULL], &t3.mField2
    [0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = uc_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mdot_threshold = ((t812 *
    0.0019634954084936209 + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    0.0019634954084936209) + t802_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  t812 = pmf_sqrt(X[29ULL] * X[29ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[73ULL];
  tlu2_linear_linear_prelookup(&vc_efOut.mField0[0ULL], &vc_efOut.mField1[0ULL],
    &vc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t52 = vc_efOut;
  tlu2_2d_linear_linear_value(&wc_efOut[0ULL], &t52.mField0[0ULL], &t52.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = wc_efOut[0];
  Basic_Peripherals_T_Junction_TL1_convection_A_rho = t802_idx_0;
  t813 = pmf_sqrt(X[8ULL] * X[8ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[74ULL];
  tlu2_linear_linear_prelookup(&xc_efOut.mField0[0ULL], &xc_efOut.mField1[0ULL],
    &xc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = xc_efOut;
  t805[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&yc_efOut.mField0[0ULL], &yc_efOut.mField1[0ULL],
    &yc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t100 = yc_efOut;
  tlu2_2d_linear_linear_value(&ad_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t100.mField0[0ULL], &t100.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ad_efOut[0];
  Basic_Peripherals_T_Junction_TL1_convection_B_rho = t802_idx_0;
  t805[0ULL] = X[75ULL];
  tlu2_linear_linear_prelookup(&bd_efOut.mField0[0ULL], &bd_efOut.mField1[0ULL],
    &bd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t50 = bd_efOut;
  tlu2_2d_linear_linear_value(&cd_efOut[0ULL], &t50.mField0[0ULL], &t50.mField2
    [0ULL], &t91.mField0[0ULL], &t91.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = cd_efOut[0];
  Basic_Peripherals_T_Junction_TL1_convection_C_rho = t802_idx_0;
  Basic_Peripherals_T_Junction_TL1_rho_avg =
    ((Basic_Peripherals_T_Junction_TL1_convection_A_rho * 0.0019634954084936209
      + Basic_Peripherals_T_Junction_TL1_convection_B_rho *
      0.0019634954084936209) + t802_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 = tanh(X[85ULL]
    * 3.0 / 0.029511607098668874) * X[85ULL];
  t815 = tanh(U_idx_2 * 3.0 / 0.029511607098668874) * U_idx_2;
  t109 = (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 >= t815);
  t814 = t109 ? Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 :
    t815;
  t816 = t109 ? t815 :
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 = (t816 +
    0.029511607098668874) / (t814 + 0.029511607098668874 == 0.0 ? 1.0E-16 : t814
    + 0.029511607098668874);
  t815 = X[88ULL] <= 5.0 ? 5.0 : X[88ULL];
  t817 = U_idx_3 <= 0.01 ? 0.01 : U_idx_3;
  t819 = t815 * 0.47700000000000009;
  t820 = t817 * 2.9881500000000005;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7 = (1.0 / (t819 ==
    0.0 ? 1.0E-16 : t819) + 1.0 / (t820 == 0.0 ? 1.0E-16 : t820)) +
    0.000163312919218431;
  t821 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7 * 6.0;
  if (t816 >= 1.0 / (t821 == 0.0 ? 1.0E-16 : t821)) {
    t822 = t816 * Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7;
    t818 = pmf_exp(-1.0 / (t822 == 0.0 ? 1.0E-16 : t822));
  } else {
    t818 = 0.0024787521766663585;
  }

  t805[0ULL] = X[86ULL];
  tlu2_linear_nearest_prelookup(&dd_efOut.mField0[0ULL], &dd_efOut.mField1[0ULL],
    &dd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = dd_efOut;
  tlu2_2d_linear_nearest_value(&ed_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ed_efOut[0];
  t819 = t802_idx_0;
  t805[0ULL] = X[87ULL];
  tlu2_linear_nearest_prelookup(&fd_efOut.mField0[0ULL], &fd_efOut.mField1[0ULL],
    &fd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = fd_efOut;
  t805[0ULL] = t1202;
  tlu2_linear_nearest_prelookup(&gd_efOut.mField0[0ULL], &gd_efOut.mField1[0ULL],
    &gd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t50 = gd_efOut;
  tlu2_2d_linear_nearest_value(&hd_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = hd_efOut[0];
  t1202 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&id_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = id_efOut[0];
  t820 = t802_idx_0;
  if (-X[4ULL] >= 0.0) {
    t822 = -X[4ULL];
  } else {
    t822 = X[4ULL];
  }

  t823 = t822 * 0.0028301886792452828;
  t824 = t802_idx_0 * 0.00075;
  t822 = t823 / (t824 == 0.0 ? 1.0E-16 : t824);
  t824 = t822 >= 1.0 ? t822 : 1.0;
  t825 = pmf_log10(6.9 / (t824 == 0.0 ? 1.0E-16 : t824) + 0.00069701528436089772)
    * pmf_log10(6.9 / (t824 == 0.0 ? 1.0E-16 : t824) + 0.00069701528436089772) *
    3.24;
  t822 = 1.0 / (t825 == 0.0 ? 1.0E-16 : t825);
  tlu2_2d_linear_nearest_value(&jd_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = jd_efOut[0];
  t825 = t802_idx_0;
  t826 = (X[35ULL] >= 0.0 ? X[35ULL] : -X[35ULL]) * 0.0028301886792452828;
  t827 = t802_idx_0 * 0.00075;
  intrm_sf_mf_64 = t826 / (t827 == 0.0 ? 1.0E-16 : t827);
  t827 = intrm_sf_mf_64 >= 1.0 ? intrm_sf_mf_64 : 1.0;
  t828 = pmf_log10(6.9 / (t827 == 0.0 ? 1.0E-16 : t827) + 0.00069701528436089772)
    * pmf_log10(6.9 / (t827 == 0.0 ? 1.0E-16 : t827) + 0.00069701528436089772) *
    3.24;
  intrm_sf_mf_64 = 1.0 / (t828 == 0.0 ? 1.0E-16 : t828);
  t805[0ULL] = X[10ULL];
  tlu2_linear_nearest_prelookup(&kd_efOut.mField0[0ULL], &kd_efOut.mField1[0ULL],
    &kd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t66 = kd_efOut;
  t805[0ULL] = X[11ULL];
  tlu2_linear_nearest_prelookup(&ld_efOut.mField0[0ULL], &ld_efOut.mField1[0ULL],
    &ld_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t106 = ld_efOut;
  tlu2_2d_linear_nearest_value(&md_efOut[0ULL], &t66.mField0[0ULL],
    &t66.mField2[0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = md_efOut[0];
  t828 = t802_idx_0;
  t805[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&nd_efOut.mField0[0ULL], &nd_efOut.mField1[0ULL],
    &nd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t91 = nd_efOut;
  t805[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&od_efOut.mField0[0ULL], &od_efOut.mField1[0ULL],
    &od_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t66 = od_efOut;
  tlu2_2d_linear_linear_value(&pd_efOut[0ULL], &t91.mField0[0ULL], &t91.mField2
    [0ULL], &t66.mField0[0ULL], &t66.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = pd_efOut[0];
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 = t802_idx_0;
  t805[0ULL] = X[94ULL];
  tlu2_linear_nearest_prelookup(&qd_efOut.mField0[0ULL], &qd_efOut.mField1[0ULL],
    &qd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t41 = qd_efOut;
  t805[0ULL] = X[13ULL];
  tlu2_linear_nearest_prelookup(&rd_efOut.mField0[0ULL], &rd_efOut.mField1[0ULL],
    &rd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t95 = rd_efOut;
  tlu2_2d_linear_nearest_value(&sd_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = sd_efOut[0];
  intrm_sf_mf_106 = t802_idx_0;
  t805[0ULL] = X[96ULL];
  tlu2_linear_nearest_prelookup(&td_efOut.mField0[0ULL], &td_efOut.mField1[0ULL],
    &td_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t86 = td_efOut;
  tlu2_2d_linear_nearest_value(&ud_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ud_efOut[0];
  intrm_sf_mf_13 = t802_idx_0;
  t805[0ULL] = X[14ULL];
  tlu2_linear_nearest_prelookup(&vd_efOut.mField0[0ULL], &vd_efOut.mField1[0ULL],
    &vd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = vd_efOut;
  tlu2_2d_linear_nearest_value(&wd_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = wd_efOut[0];
  intrm_sf_mf_7 = t802_idx_0;
  intrm_sf_mf_105 = (X[100ULL] - (-X[101ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&xd_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = xd_efOut[0];
  t829 = t802_idx_0;
  t805[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&yd_efOut.mField0[0ULL], &yd_efOut.mField1[0ULL],
    &yd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = yd_efOut;
  t805[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&ae_efOut.mField0[0ULL], &ae_efOut.mField1[0ULL],
    &ae_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t106 = ae_efOut;
  tlu2_2d_linear_linear_value(&be_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField9, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = be_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I = t802_idx_0;
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 = pmf_sqrt(X
    [100ULL] * X[100ULL] + 2.8825276676098833E-12);
  t805[0ULL] = X[102ULL];
  tlu2_linear_linear_prelookup(&ce_efOut.mField0[0ULL], &ce_efOut.mField1[0ULL],
    &ce_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t70 = ce_efOut;
  t805[0ULL] = X[95ULL];
  tlu2_linear_linear_prelookup(&de_efOut.mField0[0ULL], &de_efOut.mField1[0ULL],
    &de_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t11 = de_efOut;
  tlu2_2d_linear_linear_value(&ee_efOut[0ULL], &t70.mField0[0ULL], &t70.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ee_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect2 = t802_idx_0;
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 = pmf_sqrt(X
    [101ULL] * X[101ULL] + 2.8825276676098833E-12);
  t805[0ULL] = X[104ULL];
  tlu2_linear_linear_prelookup(&fe_efOut.mField0[0ULL], &fe_efOut.mField1[0ULL],
    &fe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t52 = fe_efOut;
  t805[0ULL] = X[97ULL];
  tlu2_linear_linear_prelookup(&ge_efOut.mField0[0ULL], &ge_efOut.mField1[0ULL],
    &ge_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t98 = ge_efOut;
  tlu2_2d_linear_linear_value(&he_efOut[0ULL], &t52.mField0[0ULL], &t52.mField2
    [0ULL], &t98.mField0[0ULL], &t98.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = he_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect8 = t802_idx_0;
  tlu2_2d_linear_linear_value(&ie_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ie_efOut[0];
  Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I = t802_idx_0;
  tlu2_2d_linear_nearest_value(&je_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = je_efOut[0];
  intrm_sf_mf_93 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&ke_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ke_efOut[0];
  intrm_sf_mf_107 = t802_idx_0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area = U_idx_6 *
    0.10471975511965977;
  t805[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&le_efOut.mField0[0ULL], &le_efOut.mField1[0ULL],
    &le_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = le_efOut;
  t805[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&me_efOut.mField0[0ULL], &me_efOut.mField1[0ULL],
    &me_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t108 = me_efOut;
  tlu2_2d_linear_linear_value(&ne_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ne_efOut[0];
  Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_rho = t802_idx_0;
  t805[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&oe_efOut.mField0[0ULL], &oe_efOut.mField1[0ULL],
    &oe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = oe_efOut;
  tlu2_2d_linear_linear_value(&pe_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t100.mField0[0ULL], &t100.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = pe_efOut[0];
  Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_rho = t802_idx_0;
  t805[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&qe_efOut.mField0[0ULL], &qe_efOut.mField1[0ULL],
    &qe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = qe_efOut;
  t805[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&re_efOut.mField0[0ULL], &re_efOut.mField1[0ULL],
    &re_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t70 = re_efOut;
  tlu2_2d_linear_linear_value(&se_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = se_efOut[0];
  Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL2_rho = t802_idx_0;
  t805[0ULL] = X[106ULL];
  tlu2_linear_nearest_prelookup(&te_efOut.mField0[0ULL], &te_efOut.mField1[0ULL],
    &te_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t86 = te_efOut;
  t805[0ULL] = X[17ULL];
  tlu2_linear_nearest_prelookup(&ue_efOut.mField0[0ULL], &ue_efOut.mField1[0ULL],
    &ue_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t52 = ue_efOut;
  tlu2_2d_linear_nearest_value(&ve_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ve_efOut[0];
  intrm_sf_mf_149 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&we_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = we_efOut[0];
  intrm_sf_mf_163 = t802_idx_0;
  t805[0ULL] = X[18ULL];
  tlu2_linear_nearest_prelookup(&xe_efOut.mField0[0ULL], &xe_efOut.mField1[0ULL],
    &xe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = xe_efOut;
  tlu2_2d_linear_nearest_value(&ye_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ye_efOut[0];
  intrm_sf_mf_172 = t802_idx_0;
  intrm_sf_mf_148 = (X[110ULL] - (-X[100ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&af_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = af_efOut[0];
  t830 = t802_idx_0;
  t805[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&bf_efOut.mField0[0ULL], &bf_efOut.mField1[0ULL],
    &bf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = bf_efOut;
  t805[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&cf_efOut.mField0[0ULL], &cf_efOut.mField1[0ULL],
    &cf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t106 = cf_efOut;
  tlu2_2d_linear_linear_value(&df_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField9, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = df_efOut[0];
  Subsystem_Reference_Pipe_TL2_beta_I = t802_idx_0;
  Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs = pmf_sqrt(X[110ULL] * X
    [110ULL] + 3.7732198934718893E-12);
  t805[0ULL] = X[115ULL];
  tlu2_linear_linear_prelookup(&ef_efOut.mField0[0ULL], &ef_efOut.mField1[0ULL],
    &ef_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = ef_efOut;
  tlu2_2d_linear_linear_value(&ff_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ff_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_A_rho = t802_idx_0;
  Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs = pmf_sqrt(X[100ULL] * X
    [100ULL] + 3.7732198934718893E-12);
  t805[0ULL] = X[117ULL];
  tlu2_linear_linear_prelookup(&gf_efOut.mField0[0ULL], &gf_efOut.mField1[0ULL],
    &gf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t3 = gf_efOut;
  tlu2_2d_linear_linear_value(&hf_efOut[0ULL], &t3.mField0[0ULL], &t3.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = hf_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_B_rho = t802_idx_0;
  tlu2_2d_linear_linear_value(&if_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t106.mField0[0ULL], &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = if_efOut[0];
  Subsystem_Reference_Pipe_TL2_rho_I = t802_idx_0;
  tlu2_2d_linear_nearest_value(&jf_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = jf_efOut[0];
  intrm_sf_mf_137 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&kf_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = kf_efOut[0];
  intrm_sf_mf_150 = t802_idx_0;
  t805[0ULL] = X[111ULL];
  tlu2_linear_nearest_prelookup(&lf_efOut.mField0[0ULL], &lf_efOut.mField1[0ULL],
    &lf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t86 = lf_efOut;
  t805[0ULL] = X[19ULL];
  tlu2_linear_nearest_prelookup(&mf_efOut.mField0[0ULL], &mf_efOut.mField1[0ULL],
    &mf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t41 = mf_efOut;
  tlu2_2d_linear_nearest_value(&nf_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = nf_efOut[0];
  intrm_sf_mf_19 = t802_idx_0;
  t805[0ULL] = X[119ULL];
  tlu2_linear_nearest_prelookup(&of_efOut.mField0[0ULL], &of_efOut.mField1[0ULL],
    &of_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = of_efOut;
  tlu2_2d_linear_nearest_value(&pf_efOut[0ULL], &t97.mField0[0ULL],
    &t97.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = pf_efOut[0];
  intrm_sf_mf_239 = t802_idx_0;
  t805[0ULL] = X[20ULL];
  tlu2_linear_nearest_prelookup(&qf_efOut.mField0[0ULL], &qf_efOut.mField1[0ULL],
    &qf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t11 = qf_efOut;
  tlu2_2d_linear_nearest_value(&rf_efOut[0ULL], &t11.mField0[0ULL],
    &t11.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = rf_efOut[0];
  intrm_sf_mf_84 = t802_idx_0;
  Subsystem_Reference_Pipe_TL4_convection_B_mdot = -X[8ULL] - X[110ULL];
  intrm_sf_mf_192 = (-X[16ULL] - Subsystem_Reference_Pipe_TL4_convection_B_mdot)
    / 2.0;
  tlu2_2d_linear_nearest_value(&sf_efOut[0ULL], &t11.mField0[0ULL],
    &t11.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = sf_efOut[0];
  t831 = t802_idx_0;
  t805[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&tf_efOut.mField0[0ULL], &tf_efOut.mField1[0ULL],
    &tf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t50 = tf_efOut;
  t805[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&uf_efOut.mField0[0ULL], &uf_efOut.mField1[0ULL],
    &uf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t95 = uf_efOut;
  tlu2_2d_linear_linear_value(&vf_efOut[0ULL], &t50.mField0[0ULL], &t50.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = vf_efOut[0];
  Subsystem_Reference_Pipe_TL4_beta_I = t802_idx_0;
  Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs = pmf_sqrt(X[16ULL] * X
    [16ULL] + 3.7732198934718893E-12);
  t805[0ULL] = X[122ULL];
  tlu2_linear_linear_prelookup(&wf_efOut.mField0[0ULL], &wf_efOut.mField1[0ULL],
    &wf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t3 = wf_efOut;
  tlu2_2d_linear_linear_value(&xf_efOut[0ULL], &t3.mField0[0ULL], &t3.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = xf_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_A_rho = t802_idx_0;
  Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs = pmf_sqrt
    (Subsystem_Reference_Pipe_TL4_convection_B_mdot *
     Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12);
  t805[0ULL] = X[124ULL];
  tlu2_linear_linear_prelookup(&yf_efOut.mField0[0ULL], &yf_efOut.mField1[0ULL],
    &yf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = yf_efOut;
  t805[0ULL] = X[120ULL];
  tlu2_linear_linear_prelookup(&ag_efOut.mField0[0ULL], &ag_efOut.mField1[0ULL],
    &ag_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t3 = ag_efOut;
  tlu2_2d_linear_linear_value(&bg_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = bg_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_B_rho = t802_idx_0;
  tlu2_2d_linear_linear_value(&cg_efOut[0ULL], &t50.mField0[0ULL], &t50.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = cg_efOut[0];
  Subsystem_Reference_Pipe_TL4_rho_I = t802_idx_0;
  tlu2_2d_linear_nearest_value(&dg_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = dg_efOut[0];
  intrm_sf_mf_18 = t802_idx_0;
  tlu2_2d_linear_nearest_value(&eg_efOut[0ULL], &t97.mField0[0ULL],
    &t97.mField2[0ULL], &t41.mField0[0ULL], &t41.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = eg_efOut[0];
  intrm_sf_mf_191 = t802_idx_0;
  Subsystem_Reference_TCP_6812_convection_A_mdot_abs = pmf_sqrt(X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[128ULL];
  tlu2_linear_linear_prelookup(&fg_efOut.mField0[0ULL], &fg_efOut.mField1[0ULL],
    &fg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = fg_efOut;
  t805[0ULL] = X[127ULL];
  tlu2_linear_linear_prelookup(&gg_efOut.mField0[0ULL], &gg_efOut.mField1[0ULL],
    &gg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t95 = gg_efOut;
  tlu2_2d_linear_linear_value(&hg_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = hg_efOut[0];
  Subsystem_Reference_TCP_6812_convection_A_rho = t802_idx_0;
  t805[0ULL] = X[130ULL];
  tlu2_linear_linear_prelookup(&ig_efOut.mField0[0ULL], &ig_efOut.mField1[0ULL],
    &ig_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t41 = ig_efOut;
  tlu2_2d_linear_linear_value(&jg_efOut[0ULL], &t41.mField0[0ULL], &t41.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = jg_efOut[0];
  Subsystem_Reference_TCP_6812_convection_B_rho = t802_idx_0;
  Subsystem_Reference_TCP_6812_mechanical_power = X[110ULL] /
    (Subsystem_Reference_TCP_6812_convection_A_rho == 0.0 ? 1.0E-16 :
     Subsystem_Reference_TCP_6812_convection_A_rho);
  t805[0ULL] = Subsystem_Reference_TCP_6812_mechanical_power * 1.0E+6;
  t602[0] = 15ULL;
  tlu2_linear_linear_prelookup(&kg_efOut.mField0[0ULL], &kg_efOut.mField1[0ULL],
    &kg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField11, &t805[0ULL],
    &t602[0ULL], &t114[0ULL]);
  t86 = kg_efOut;
  t805[0ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area;
  t596[0] = 8ULL;
  tlu2_linear_linear_prelookup(&lg_efOut.mField0[0ULL], &lg_efOut.mField1[0ULL],
    &lg_efOut.mField2[0ULL], &nonscalar12[0ULL], &t805[0ULL], &t596[0ULL],
    &t114[0ULL]);
  t52 = lg_efOut;
  tlu2_2d_linear_linear_value(&mg_efOut[0ULL], &t86.mField0[0ULL], &t86.mField2
    [0ULL], &t52.mField0[0ULL], &t52.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField10, &t602[0ULL], &t596[0ULL], &t114[0ULL]);
  t802_idx_0 = mg_efOut[0];
  Subsystem_Reference_TCP_6812_hydraulic_power =
    Subsystem_Reference_TCP_6812_convection_A_rho * t802_idx_0 * 9.81 *
    Subsystem_Reference_TCP_6812_mechanical_power;
  Subsystem_Reference_TCP_6812_mechanical_power = -(X[108ULL] *
    Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area);
  t805[0ULL] = U_idx_7 * -0.001 + 0.0025;
  t602[0] = 11ULL;
  tlu2_linear_nearest_prelookup(&ng_efOut.mField0[0ULL], &ng_efOut.mField1[0ULL],
    &ng_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t805[0ULL],
    &t602[0ULL], &t114[0ULL]);
  t106 = ng_efOut;
  tlu2_1d_linear_nearest_value(&og_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t602[0ULL],
    &t114[0ULL]);
  t802_idx_0 = og_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area = t802_idx_0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio = t802_idx_0 /
    0.0019634954084936209;
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs = pmf_sqrt
    (Subsystem_Reference_Pipe_TL4_convection_B_mdot *
     Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11);
  t805[0ULL] = X[131ULL];
  tlu2_linear_linear_prelookup(&pg_efOut.mField0[0ULL], &pg_efOut.mField1[0ULL],
    &pg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = pg_efOut;
  tlu2_2d_linear_linear_value(&qg_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = qg_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho = t802_idx_0;
  t805[0ULL] = X[133ULL];
  tlu2_linear_linear_prelookup(&rg_efOut.mField0[0ULL], &rg_efOut.mField1[0ULL],
    &rg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = rg_efOut;
  tlu2_2d_linear_linear_value(&sg_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = sg_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho = t802_idx_0;
  t805[0ULL] = X[131ULL];
  tlu2_linear_nearest_prelookup(&tg_efOut.mField0[0ULL], &tg_efOut.mField1[0ULL],
    &tg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t11 = tg_efOut;
  t805[0ULL] = X[127ULL];
  tlu2_linear_nearest_prelookup(&ug_efOut.mField0[0ULL], &ug_efOut.mField1[0ULL],
    &ug_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t108 = ug_efOut;
  tlu2_2d_linear_nearest_value(&vg_efOut[0ULL], &t11.mField0[0ULL],
    &t11.mField2[0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = vg_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c = t802_idx_0;
  t805[0ULL] = X[133ULL];
  tlu2_linear_nearest_prelookup(&wg_efOut.mField0[0ULL], &wg_efOut.mField1[0ULL],
    &wg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t86 = wg_efOut;
  t805[0ULL] = X[120ULL];
  tlu2_linear_nearest_prelookup(&xg_efOut.mField0[0ULL], &xg_efOut.mField1[0ULL],
    &xg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t3 = xg_efOut;
  tlu2_2d_linear_nearest_value(&yg_efOut[0ULL], &t86.mField0[0ULL],
    &t86.mField2[0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)
    (LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = yg_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c =
    (Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c + t802_idx_0) / 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff = X[127ULL] - X[120ULL];
  t833 = (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho +
          Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho) / 2.0;
  t836 = Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area * t833 * 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c =
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c * 0.78539816339744828 /
    (t836 == 0.0 ? 1.0E-16 : t836) * 293.87755102040813;
  t805[0ULL] = U_idx_7 * 0.001 + 0.0025;
  tlu2_linear_nearest_prelookup(&ah_efOut.mField0[0ULL], &ah_efOut.mField1[0ULL],
    &ah_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t805[0ULL],
    &t602[0ULL], &t114[0ULL]);
  t106 = ah_efOut;
  tlu2_1d_linear_nearest_value(&bh_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t602[0ULL],
    &t114[0ULL]);
  t802_idx_0 = bh_efOut[0];
  t834 = t802_idx_0;
  t835 = t802_idx_0 / 0.0019634954084936209;
  t805[0ULL] = X[134ULL];
  tlu2_linear_linear_prelookup(&ch_efOut.mField0[0ULL], &ch_efOut.mField1[0ULL],
    &ch_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t3 = ch_efOut;
  tlu2_2d_linear_linear_value(&dh_efOut[0ULL], &t3.mField0[0ULL], &t3.mField2
    [0ULL], &t100.mField0[0ULL], &t100.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = dh_efOut[0];
  t836 = t802_idx_0;
  t805[0ULL] = X[136ULL];
  tlu2_linear_linear_prelookup(&eh_efOut.mField0[0ULL], &eh_efOut.mField1[0ULL],
    &eh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = eh_efOut;
  tlu2_2d_linear_linear_value(&fh_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = fh_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho = t802_idx_0;
  t805[0ULL] = X[134ULL];
  tlu2_linear_nearest_prelookup(&gh_efOut.mField0[0ULL], &gh_efOut.mField1[0ULL],
    &gh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t41 = gh_efOut;
  tlu2_2d_linear_nearest_value(&hh_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t103.mField0[0ULL], &t103.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = hh_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c = t802_idx_0;
  t805[0ULL] = X[136ULL];
  tlu2_linear_nearest_prelookup(&ih_efOut.mField0[0ULL], &ih_efOut.mField1[0ULL],
    &ih_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t41 = ih_efOut;
  tlu2_2d_linear_nearest_value(&jh_efOut[0ULL], &t41.mField0[0ULL],
    &t41.mField2[0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = jh_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c =
    (Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c + t802_idx_0) / 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff = X[40ULL] - X[127ULL];
  t837 = (t836 + Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho) /
    2.0;
  t840 = t834 * t837 * 2.0;
  Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c =
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c * 0.78539816339744828 /
    (t840 == 0.0 ? 1.0E-16 : t840) * 293.87755102040813;
  t805[0ULL] = X[137ULL];
  tlu2_linear_nearest_prelookup(&kh_efOut.mField0[0ULL], &kh_efOut.mField1[0ULL],
    &kh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t3 = kh_efOut;
  t805[0ULL] = X[97ULL];
  tlu2_linear_nearest_prelookup(&lh_efOut.mField0[0ULL], &lh_efOut.mField1[0ULL],
    &lh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t97 = lh_efOut;
  tlu2_2d_linear_nearest_value(&mh_efOut[0ULL], &t3.mField0[0ULL], &t3.mField2
    [0ULL], &t97.mField0[0ULL], &t97.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = mh_efOut[0];
  t838 = t802_idx_0;
  t805[0ULL] = X[138ULL];
  tlu2_linear_nearest_prelookup(&nh_efOut.mField0[0ULL], &nh_efOut.mField1[0ULL],
    &nh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t95 = nh_efOut;
  t805[0ULL] = X[38ULL];
  tlu2_linear_nearest_prelookup(&oh_efOut.mField0[0ULL], &oh_efOut.mField1[0ULL],
    &oh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t3 = oh_efOut;
  tlu2_2d_linear_nearest_value(&ph_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)
    (LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = ph_efOut[0];
  t839 = t802_idx_0;
  t805[0ULL] = X[139ULL];
  tlu2_linear_nearest_prelookup(&qh_efOut.mField0[0ULL], &qh_efOut.mField1[0ULL],
    &qh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t97 = qh_efOut;
  t805[0ULL] = X[112ULL];
  tlu2_linear_nearest_prelookup(&rh_efOut.mField0[0ULL], &rh_efOut.mField1[0ULL],
    &rh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t805[0ULL],
    &t116[0ULL], &t114[0ULL]);
  t95 = rh_efOut;
  tlu2_2d_linear_nearest_value(&sh_efOut[0ULL], &t97.mField0[0ULL],
    &t97.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = sh_efOut[0];
  t839 = ((t838 * 0.0019634954084936209 + t839 * 0.0019634954084936209) +
          t802_idx_0 * 0.0019634954084936209) / 0.0058904862254808626 *
    5.8904862254808616;
  t838 = pmf_sqrt(X[101ULL] * X[101ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[137ULL];
  tlu2_linear_linear_prelookup(&th_efOut.mField0[0ULL], &th_efOut.mField1[0ULL],
    &th_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = th_efOut;
  tlu2_2d_linear_linear_value(&uh_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t98.mField0[0ULL], &t98.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = uh_efOut[0];
  t840 = t802_idx_0;
  t841 = pmf_sqrt(X[7ULL] * X[7ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[138ULL];
  tlu2_linear_linear_prelookup(&vh_efOut.mField0[0ULL], &vh_efOut.mField1[0ULL],
    &vh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = vh_efOut;
  tlu2_2d_linear_linear_value(&wh_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t99.mField0[0ULL], &t99.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t802_idx_0 = wh_efOut[0];
  Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs = pmf_sqrt(X[16ULL] *
    X[16ULL] + 9.4330497336797231E-11);
  t805[0ULL] = X[139ULL];
  tlu2_linear_linear_prelookup(&xh_efOut.mField0[0ULL], &xh_efOut.mField1[0ULL],
    &xh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t805[0ULL],
    &t113[0ULL], &t114[0ULL]);
  t106 = xh_efOut;
  tlu2_2d_linear_linear_value(&yh_efOut[0ULL], &t106.mField0[0ULL],
    &t106.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t805[0] = yh_efOut[0];
  Subsystem_Reference_T_Junction_TL_convection_C_rho = t805[0ULL];
  Subsystem_Reference_T_Junction_TL_rho_avg = ((t840 * 0.0019634954084936209 +
    t802_idx_0 * 0.0019634954084936209) +
    Subsystem_Reference_T_Junction_TL_convection_C_rho * 0.0019634954084936209) /
    0.0058904862254808626;
  t843 = intrm_sf_mf_112 + t810;
  t845 = t843 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_112 = intrm_sf_mf_181 * 0.1413716694115407 / (t845 == 0.0 ?
    1.0E-16 : t845);
  t842 = intrm_sf_mf_112 >= 0.0 ? intrm_sf_mf_112 : -intrm_sf_mf_112;
  intrm_sf_mf_112 = (t842 - 2000.0) / 2000.0;
  t847 = intrm_sf_mf_93 + t829;
  t849 = t847 / 2.0 * 0.0015;
  intrm_sf_mf_93 = intrm_sf_mf_105 * 0.01 / (t849 == 0.0 ? 1.0E-16 : t849);
  t844 = intrm_sf_mf_93 >= 0.0 ? intrm_sf_mf_93 : -intrm_sf_mf_93;
  intrm_sf_mf_93 = t844 > 1000.0 ? t844 : 1000.0;
  t850 = pmf_log10(6.9 / (intrm_sf_mf_93 == 0.0 ? 1.0E-16 : intrm_sf_mf_93) +
                   0.002211858722000578) * pmf_log10(6.9 / (intrm_sf_mf_93 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_93) + 0.002211858722000578) * 3.24;
  t845 = 1.0 / (t850 == 0.0 ? 1.0E-16 : t850);
  t851 = intrm_sf_mf_106 + intrm_sf_mf_7;
  if ((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t845 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    intrm_sf_mf_152 = (pmf_pow((intrm_sf_mf_106 + intrm_sf_mf_7) / 2.0,
      0.66666666666666663) - 1.0) * pmf_sqrt(t845 / 8.0) * 12.7 + 1.0;
    t846 = (intrm_sf_mf_93 - 1000.0) * (t845 / 8.0) * ((intrm_sf_mf_106 +
      intrm_sf_mf_7) / 2.0) / (intrm_sf_mf_152 == 0.0 ? 1.0E-16 :
      intrm_sf_mf_152);
  } else {
    t846 = (intrm_sf_mf_93 - 1000.0) * (t845 / 8.0) * ((intrm_sf_mf_106 +
      intrm_sf_mf_7) / 2.0) / 1.0E-6;
  }

  t848 = (t844 - 2000.0) / 2000.0;
  t849 = t848 * t848 * 3.0 - t848 * t848 * t848 * 2.0;
  if (t844 <= 2000.0) {
    t848 = 3.66;
  } else if (t844 >= 4000.0) {
    t848 = t846;
  } else {
    t848 = (1.0 - t849) * 3.66 + t846 * t849;
  }

  t859 = t848 * 2.0784609690826534;
  t862 = t851 / 2.0;
  if (t844 > t859 / 0.0015 / (t862 == 0.0 ? 1.0E-16 : t862) / 30.0) {
    t873 = (intrm_sf_mf_106 + intrm_sf_mf_7) / 2.0;
    t846 = t848 * 2.0784609690826534 / (t844 == 0.0 ? 1.0E-16 : t844) / 0.0015 /
      (t873 == 0.0 ? 1.0E-16 : t873);
  } else {
    t846 = 30.0;
  }

  t869 = intrm_sf_mf_107 + t829;
  t881 = t869 / 2.0 * 0.0015;
  intrm_sf_mf_106 = -intrm_sf_mf_105 * 0.01 / (t881 == 0.0 ? 1.0E-16 : t881);
  intrm_sf_mf_105 = intrm_sf_mf_106 >= 0.0 ? intrm_sf_mf_106 : -intrm_sf_mf_106;
  intrm_sf_mf_106 = intrm_sf_mf_105 > 1000.0 ? intrm_sf_mf_105 : 1000.0;
  t873 = pmf_log10(6.9 / (intrm_sf_mf_106 == 0.0 ? 1.0E-16 : intrm_sf_mf_106) +
                   0.002211858722000578) * pmf_log10(6.9 / (intrm_sf_mf_106 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_106) + 0.002211858722000578) * 3.24;
  intrm_sf_mf_107 = 1.0 / (t873 == 0.0 ? 1.0E-16 : t873);
  t873 = intrm_sf_mf_13 + intrm_sf_mf_7;
  if ((pmf_pow(t873 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_107 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    t913 = (pmf_pow((intrm_sf_mf_13 + intrm_sf_mf_7) / 2.0, 0.66666666666666663)
            - 1.0) * pmf_sqrt(intrm_sf_mf_107 / 8.0) * 12.7 + 1.0;
    t848 = (intrm_sf_mf_106 - 1000.0) * (intrm_sf_mf_107 / 8.0) *
      ((intrm_sf_mf_13 + intrm_sf_mf_7) / 2.0) / (t913 == 0.0 ? 1.0E-16 : t913);
  } else {
    t848 = (intrm_sf_mf_106 - 1000.0) * (intrm_sf_mf_107 / 8.0) *
      ((intrm_sf_mf_13 + intrm_sf_mf_7) / 2.0) / 1.0E-6;
  }

  t849 = (intrm_sf_mf_105 - 2000.0) / 2000.0;
  t850 = intrm_sf_mf_112 * intrm_sf_mf_112 * 3.0 - intrm_sf_mf_112 *
    intrm_sf_mf_112 * intrm_sf_mf_112 * 2.0;
  intrm_sf_mf_112 = t849 * t849 * 3.0 - t849 * t849 * t849 * 2.0;
  if (intrm_sf_mf_105 <= 2000.0) {
    t849 = 3.66;
  } else if (intrm_sf_mf_105 >= 4000.0) {
    t849 = t848;
  } else {
    t849 = (1.0 - intrm_sf_mf_112) * 3.66 + t848 * intrm_sf_mf_112;
  }

  t881 = t849 * 2.0784609690826534;
  t892 = t873 / 2.0;
  if (intrm_sf_mf_105 > t881 / 0.0015 / (t892 == 0.0 ? 1.0E-16 : t892) / 30.0) {
    t927 = (intrm_sf_mf_13 + intrm_sf_mf_7) / 2.0;
    intrm_sf_mf_112 = t849 * 2.0784609690826534 / (intrm_sf_mf_105 == 0.0 ?
      1.0E-16 : intrm_sf_mf_105) / 0.0015 / (t927 == 0.0 ? 1.0E-16 : t927);
  } else {
    intrm_sf_mf_112 = 30.0;
  }

  t892 = t829 * 0.0015;
  intrm_sf_mf_13 = (X[100ULL] >= 0.0 ? X[100ULL] : -X[100ULL]) * 0.01 / (t892 ==
    0.0 ? 1.0E-16 : t892);
  intrm_sf_mf_7 = t842 > 1000.0 ? t842 : 1000.0;
  t891 = pmf_log10(6.9 / (intrm_sf_mf_7 == 0.0 ? 1.0E-16 : intrm_sf_mf_7) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_7 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_7) + 9.0751776413883736E-6) * 3.24;
  t848 = 1.0 / (t891 == 0.0 ? 1.0E-16 : t891);
  t891 = intrm_sf_mf_138 + intrm_sf_mf_249;
  if ((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t848 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    t927 = (pmf_pow((intrm_sf_mf_138 + intrm_sf_mf_249) / 2.0,
                    0.66666666666666663) - 1.0) * pmf_sqrt(t848 / 8.0) * 12.7 +
      1.0;
    t849 = (intrm_sf_mf_7 - 1000.0) * (t848 / 8.0) * ((intrm_sf_mf_138 +
      intrm_sf_mf_249) / 2.0) / (t927 == 0.0 ? 1.0E-16 : t927);
  } else {
    t849 = (intrm_sf_mf_7 - 1000.0) * (t848 / 8.0) * ((intrm_sf_mf_138 +
      intrm_sf_mf_249) / 2.0) / 1.0E-6;
  }

  if (t842 <= 2000.0) {
    t852 = 3.66;
  } else if (t842 >= 4000.0) {
    t852 = t849;
  } else {
    t852 = (1.0 - t850) * 3.66 + t850 * t849;
  }

  t849 = intrm_sf_mf_13 >= 1.0 ? intrm_sf_mf_13 : 1.0;
  if (-X[101ULL] >= 0.0) {
    intrm_sf_mf_13 = -X[101ULL];
  } else {
    intrm_sf_mf_13 = X[101ULL];
  }

  intrm_sf_mf_13 = intrm_sf_mf_13 * 0.01 / (t892 == 0.0 ? 1.0E-16 : t892);
  t850 = intrm_sf_mf_13 >= 1.0 ? intrm_sf_mf_13 : 1.0;
  t892 = t852 * 0.055555555555555559;
  t916 = t891 / 2.0;
  if (t842 > t892 / 0.0019634954084936209 / (t916 == 0.0 ? 1.0E-16 : t916) /
      30.0) {
    t940 = (intrm_sf_mf_138 + intrm_sf_mf_249) / 2.0;
    intrm_sf_mf_13 = t852 * 0.055555555555555559 / (t842 == 0.0 ? 1.0E-16 : t842)
      / 0.0019634954084936209 / (t940 == 0.0 ? 1.0E-16 : t940);
  } else {
    intrm_sf_mf_13 = 30.0;
  }

  t913 = intrm_sf_mf_137 + t830;
  t925 = t913 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_138 = intrm_sf_mf_148 * 0.1413716694115407 / (t925 == 0.0 ?
    1.0E-16 : t925);
  intrm_sf_mf_137 = intrm_sf_mf_138 >= 0.0 ? intrm_sf_mf_138 : -intrm_sf_mf_138;
  intrm_sf_mf_138 = intrm_sf_mf_137 > 1000.0 ? intrm_sf_mf_137 : 1000.0;
  t916 = pmf_log10(6.9 / (intrm_sf_mf_138 == 0.0 ? 1.0E-16 : intrm_sf_mf_138) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_138 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_138) + 9.0751776413883736E-6) * 3.24;
  t852 = 1.0 / (t916 == 0.0 ? 1.0E-16 : t916);
  t916 = intrm_sf_mf_149 + intrm_sf_mf_172;
  if ((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t852 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    t940 = (pmf_pow((intrm_sf_mf_149 + intrm_sf_mf_172) / 2.0,
                    0.66666666666666663) - 1.0) * pmf_sqrt(t852 / 8.0) * 12.7 +
      1.0;
    intrm_sf_mf_144 = (intrm_sf_mf_138 - 1000.0) * (t852 / 8.0) *
      ((intrm_sf_mf_149 + intrm_sf_mf_172) / 2.0) / (t940 == 0.0 ? 1.0E-16 :
      t940);
  } else {
    intrm_sf_mf_144 = (intrm_sf_mf_138 - 1000.0) * (t852 / 8.0) *
      ((intrm_sf_mf_149 + intrm_sf_mf_172) / 2.0) / 1.0E-6;
  }

  t854 = (intrm_sf_mf_137 - 2000.0) / 2000.0;
  intrm_sf_mf_152 = t854 * t854 * 3.0 - t854 * t854 * t854 * 2.0;
  if (intrm_sf_mf_137 <= 2000.0) {
    t854 = 3.66;
  } else if (intrm_sf_mf_137 >= 4000.0) {
    t854 = intrm_sf_mf_144;
  } else {
    t854 = (1.0 - intrm_sf_mf_152) * 3.66 + intrm_sf_mf_144 * intrm_sf_mf_152;
  }

  t925 = t854 * 0.02777777777777778;
  t939 = t916 / 2.0;
  if (intrm_sf_mf_137 > t925 / 0.0019634954084936209 / (t939 == 0.0 ? 1.0E-16 :
       t939) / 30.0) {
    t965 = (intrm_sf_mf_149 + intrm_sf_mf_172) / 2.0;
    intrm_sf_mf_144 = t854 * 0.02777777777777778 / (intrm_sf_mf_137 == 0.0 ?
      1.0E-16 : intrm_sf_mf_137) / 0.0019634954084936209 / (t965 == 0.0 ?
      1.0E-16 : t965);
  } else {
    intrm_sf_mf_144 = 30.0;
  }

  t927 = intrm_sf_mf_150 + t830;
  t940 = t927 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_149 = -intrm_sf_mf_148 * 0.1413716694115407 / (t940 == 0.0 ?
    1.0E-16 : t940);
  intrm_sf_mf_148 = intrm_sf_mf_149 >= 0.0 ? intrm_sf_mf_149 : -intrm_sf_mf_149;
  intrm_sf_mf_149 = intrm_sf_mf_148 > 1000.0 ? intrm_sf_mf_148 : 1000.0;
  t939 = pmf_log10(6.9 / (intrm_sf_mf_149 == 0.0 ? 1.0E-16 : intrm_sf_mf_149) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_149 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_149) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_150 = 1.0 / (t939 == 0.0 ? 1.0E-16 : t939);
  t939 = intrm_sf_mf_163 + intrm_sf_mf_172;
  if ((pmf_pow(t939 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_150 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    t965 = (pmf_pow((intrm_sf_mf_163 + intrm_sf_mf_172) / 2.0,
                    0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_150 / 8.0)
      * 12.7 + 1.0;
    t854 = (intrm_sf_mf_149 - 1000.0) * (intrm_sf_mf_150 / 8.0) *
      ((intrm_sf_mf_163 + intrm_sf_mf_172) / 2.0) / (t965 == 0.0 ? 1.0E-16 :
      t965);
  } else {
    t854 = (intrm_sf_mf_149 - 1000.0) * (intrm_sf_mf_150 / 8.0) *
      ((intrm_sf_mf_163 + intrm_sf_mf_172) / 2.0) / 1.0E-6;
  }

  intrm_sf_mf_152 = (intrm_sf_mf_148 - 2000.0) / 2000.0;
  t856 = intrm_sf_mf_152 * intrm_sf_mf_152 * 3.0 - intrm_sf_mf_152 *
    intrm_sf_mf_152 * intrm_sf_mf_152 * 2.0;
  if (intrm_sf_mf_148 <= 2000.0) {
    intrm_sf_mf_152 = 3.66;
  } else if (intrm_sf_mf_148 >= 4000.0) {
    intrm_sf_mf_152 = t854;
  } else {
    intrm_sf_mf_152 = (1.0 - t856) * 3.66 + t854 * t856;
  }

  t940 = intrm_sf_mf_152 * 0.02777777777777778;
  t964 = t939 / 2.0;
  if (intrm_sf_mf_148 > t940 / 0.0019634954084936209 / (t964 == 0.0 ? 1.0E-16 :
       t964) / 30.0) {
    t991 = (intrm_sf_mf_163 + intrm_sf_mf_172) / 2.0;
    t854 = intrm_sf_mf_152 * 0.02777777777777778 / (intrm_sf_mf_148 == 0.0 ?
      1.0E-16 : intrm_sf_mf_148) / 0.0019634954084936209 / (t991 == 0.0 ?
      1.0E-16 : t991);
  } else {
    t854 = 30.0;
  }

  t957 = intrm_sf_mf_162 + t810;
  t965 = t957 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_181 = -intrm_sf_mf_181 * 0.1413716694115407 / (t965 == 0.0 ?
    1.0E-16 : t965);
  t965 = t830 * 0.0019634954084936209;
  intrm_sf_mf_162 = (X[110ULL] >= 0.0 ? X[110ULL] : -X[110ULL]) *
    0.1413716694115407 / (t965 == 0.0 ? 1.0E-16 : t965);
  intrm_sf_mf_163 = intrm_sf_mf_162 >= 1.0 ? intrm_sf_mf_162 : 1.0;
  intrm_sf_mf_162 = intrm_sf_mf_181 >= 0.0 ? intrm_sf_mf_181 : -intrm_sf_mf_181;
  if (-X[100ULL] >= 0.0) {
    intrm_sf_mf_181 = -X[100ULL];
  } else {
    intrm_sf_mf_181 = X[100ULL];
  }

  intrm_sf_mf_181 = intrm_sf_mf_181 * 0.1413716694115407 / (t965 == 0.0 ?
    1.0E-16 : t965);
  intrm_sf_mf_172 = intrm_sf_mf_181 >= 1.0 ? intrm_sf_mf_181 : 1.0;
  t964 = intrm_sf_mf_18 + t831;
  t976 = t964 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_181 = intrm_sf_mf_192 * 0.1413716694115407 / (t976 == 0.0 ?
    1.0E-16 : t976);
  intrm_sf_mf_18 = intrm_sf_mf_162 > 1000.0 ? intrm_sf_mf_162 : 1000.0;
  intrm_sf_mf_152 = intrm_sf_mf_181 >= 0.0 ? intrm_sf_mf_181 : -intrm_sf_mf_181;
  intrm_sf_mf_181 = intrm_sf_mf_152 > 1000.0 ? intrm_sf_mf_152 : 1000.0;
  t965 = pmf_log10(6.9 / (intrm_sf_mf_181 == 0.0 ? 1.0E-16 : intrm_sf_mf_181) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_181 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_181) + 9.0751776413883736E-6) * 3.24;
  t856 = 1.0 / (t965 == 0.0 ? 1.0E-16 : t965);
  t965 = intrm_sf_mf_19 + intrm_sf_mf_84;
  if ((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t856 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    t999 = (pmf_pow((intrm_sf_mf_19 + intrm_sf_mf_84) / 2.0, 0.66666666666666663)
            - 1.0) * pmf_sqrt(t856 / 8.0) * 12.7 + 1.0;
    t857 = (intrm_sf_mf_181 - 1000.0) * (t856 / 8.0) * ((intrm_sf_mf_19 +
      intrm_sf_mf_84) / 2.0) / (t999 == 0.0 ? 1.0E-16 : t999);
  } else {
    t857 = (intrm_sf_mf_181 - 1000.0) * (t856 / 8.0) * ((intrm_sf_mf_19 +
      intrm_sf_mf_84) / 2.0) / 1.0E-6;
  }

  t858 = (intrm_sf_mf_152 - 2000.0) / 2000.0;
  t861 = t858 * t858 * 3.0 - t858 * t858 * t858 * 2.0;
  if (intrm_sf_mf_152 <= 2000.0) {
    t858 = 3.66;
  } else if (intrm_sf_mf_152 >= 4000.0) {
    t858 = t857;
  } else {
    t858 = (1.0 - t861) * 3.66 + t857 * t861;
  }

  t976 = t858 * 0.02777777777777778;
  t991 = t965 / 2.0;
  if (intrm_sf_mf_152 > t976 / 0.0019634954084936209 / (t991 == 0.0 ? 1.0E-16 :
       t991) / 30.0) {
    U_idx_0 = (intrm_sf_mf_19 + intrm_sf_mf_84) / 2.0;
    t857 = t858 * 0.02777777777777778 / (intrm_sf_mf_152 == 0.0 ? 1.0E-16 :
      intrm_sf_mf_152) / 0.0019634954084936209 / (U_idx_0 == 0.0 ? 1.0E-16 :
      U_idx_0);
  } else {
    t857 = 30.0;
  }

  t987 = pmf_log10(6.9 / (intrm_sf_mf_18 == 0.0 ? 1.0E-16 : intrm_sf_mf_18) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_18 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_18) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_19 = 1.0 / (t987 == 0.0 ? 1.0E-16 : t987);
  t987 = intrm_sf_mf_191 + t831;
  t999 = t987 / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_192 = -intrm_sf_mf_192 * 0.1413716694115407 / (t999 == 0.0 ?
    1.0E-16 : t999);
  intrm_sf_mf_191 = intrm_sf_mf_192 >= 0.0 ? intrm_sf_mf_192 : -intrm_sf_mf_192;
  intrm_sf_mf_192 = intrm_sf_mf_191 > 1000.0 ? intrm_sf_mf_191 : 1000.0;
  t991 = pmf_log10(6.9 / (intrm_sf_mf_192 == 0.0 ? 1.0E-16 : intrm_sf_mf_192) +
                   9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_192 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_192) + 9.0751776413883736E-6) * 3.24;
  t858 = 1.0 / (t991 == 0.0 ? 1.0E-16 : t991);
  t991 = intrm_sf_mf_239 + intrm_sf_mf_84;
  if ((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t858 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    U_idx_0 = (pmf_pow((intrm_sf_mf_239 + intrm_sf_mf_84) / 2.0,
                       0.66666666666666663) - 1.0) * pmf_sqrt(t858 / 8.0) * 12.7
      + 1.0;
    t861 = (intrm_sf_mf_192 - 1000.0) * (t858 / 8.0) * ((intrm_sf_mf_239 +
      intrm_sf_mf_84) / 2.0) / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    t861 = (intrm_sf_mf_192 - 1000.0) * (t858 / 8.0) * ((intrm_sf_mf_239 +
      intrm_sf_mf_84) / 2.0) / 1.0E-6;
  }

  t862 = (intrm_sf_mf_191 - 2000.0) / 2000.0;
  U_idx_2 = t862 * t862 * 3.0 - t862 * t862 * t862 * 2.0;
  if (intrm_sf_mf_191 <= 2000.0) {
    t862 = 3.66;
  } else if (intrm_sf_mf_191 >= 4000.0) {
    t862 = t861;
  } else {
    t862 = (1.0 - U_idx_2) * 3.66 + t861 * U_idx_2;
  }

  t999 = t862 * 0.02777777777777778;
  U_idx_6 = t991 / 2.0;
  if (intrm_sf_mf_191 > t999 / 0.0019634954084936209 / (U_idx_6 == 0.0 ? 1.0E-16
       : U_idx_6) / 30.0) {
    U_idx_0 = (intrm_sf_mf_239 + intrm_sf_mf_84) / 2.0;
    t861 = t862 * 0.02777777777777778 / (intrm_sf_mf_191 == 0.0 ? 1.0E-16 :
      intrm_sf_mf_191) / 0.0019634954084936209 / (U_idx_0 == 0.0 ? 1.0E-16 :
      U_idx_0);
  } else {
    t861 = 30.0;
  }

  t1004 = intrm_sf_mf_240 + intrm_sf_mf_249;
  if ((pmf_pow(t1004 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    U_idx_0 = (pmf_pow((intrm_sf_mf_240 + intrm_sf_mf_249) / 2.0,
                       0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_19 /
      8.0) * 12.7 + 1.0;
    intrm_sf_mf_239 = (intrm_sf_mf_18 - 1000.0) * (intrm_sf_mf_19 / 8.0) *
      ((intrm_sf_mf_240 + intrm_sf_mf_249) / 2.0) / (U_idx_0 == 0.0 ? 1.0E-16 :
      U_idx_0);
  } else {
    intrm_sf_mf_239 = (intrm_sf_mf_18 - 1000.0) * (intrm_sf_mf_19 / 8.0) *
      ((intrm_sf_mf_240 + intrm_sf_mf_249) / 2.0) / 1.0E-6;
  }

  if (-X[16ULL] >= 0.0) {
    intrm_sf_mf_84 = -X[16ULL];
  } else {
    intrm_sf_mf_84 = X[16ULL];
  }

  U_idx_0 = t831 * 0.0019634954084936209;
  intrm_sf_mf_84 = intrm_sf_mf_84 * 0.1413716694115407 / (U_idx_0 == 0.0 ?
    1.0E-16 : U_idx_0);
  t862 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  intrm_sf_mf_84 = (intrm_sf_mf_162 - 2000.0) / 2000.0;
  U_idx_2 = (Subsystem_Reference_Pipe_TL4_convection_B_mdot >= 0.0 ?
             Subsystem_Reference_Pipe_TL4_convection_B_mdot :
             -Subsystem_Reference_Pipe_TL4_convection_B_mdot) *
    0.1413716694115407 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  U_idx_7 = U_idx_2 >= 1.0 ? U_idx_2 : 1.0;
  U_idx_2 = intrm_sf_mf_84 * intrm_sf_mf_84 * 3.0 - intrm_sf_mf_84 *
    intrm_sf_mf_84 * intrm_sf_mf_84 * 2.0;
  if (intrm_sf_mf_162 <= 2000.0) {
    intrm_sf_mf_84 = 3.66;
  } else if (intrm_sf_mf_162 >= 4000.0) {
    intrm_sf_mf_84 = intrm_sf_mf_239;
  } else {
    intrm_sf_mf_84 = (1.0 - U_idx_2) * 3.66 + intrm_sf_mf_239 * U_idx_2;
  }

  intrm_sf_mf_239 = pmf_sqrt(X[4ULL] * X[4ULL] + 1.4412638338049421E-12);
  U_idx_6 = intrm_sf_mf_84 * 0.055555555555555559;
  U_idx_0 = t1004 / 2.0;
  if (intrm_sf_mf_162 > U_idx_6 / 0.0019634954084936209 / (U_idx_0 == 0.0 ?
       1.0E-16 : U_idx_0) / 30.0) {
    U_idx_0 = (intrm_sf_mf_240 + intrm_sf_mf_249) / 2.0;
    U_idx_2 = intrm_sf_mf_84 * 0.055555555555555559 / (intrm_sf_mf_162 == 0.0 ?
      1.0E-16 : intrm_sf_mf_162) / 0.0019634954084936209 / (U_idx_0 == 0.0 ?
      1.0E-16 : U_idx_0);
  } else {
    U_idx_2 = 30.0;
  }

  intrm_sf_mf_240 = pmf_sqrt(X[35ULL] * X[35ULL] + 1.4412638338049421E-12);
  tlu2_2d_linear_linear_value(&ai_efOut[0ULL], &t91.mField0[0ULL], &t91.mField2
    [0ULL], &t66.mField0[0ULL], &t66.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField9, &t113[0ULL], &t116[0ULL], &t114[0ULL]);
  t805[0] = ai_efOut[0];
  intrm_sf_mf_249 = t805[0ULL];
  if (-X[7ULL] >= 0.0) {
    intrm_sf_mf_84 = -X[7ULL];
  } else {
    intrm_sf_mf_84 = X[7ULL];
  }

  U_idx_0 = t810 * 0.0019634954084936209;
  intrm_sf_mf_84 = intrm_sf_mf_84 * 0.1413716694115407 / (U_idx_0 == 0.0 ?
    1.0E-16 : U_idx_0);
  U_idx_3 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  if (-X[57ULL] >= 0.0) {
    intrm_sf_mf_84 = -X[57ULL];
  } else {
    intrm_sf_mf_84 = X[57ULL];
  }

  intrm_sf_mf_84 = intrm_sf_mf_84 * 0.1413716694115407 / (U_idx_0 == 0.0 ?
    1.0E-16 : U_idx_0);
  U_idx_1 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  U_idx_0 = t828 * 0.00075;
  intrm_sf_mf_84 = t823 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  t823 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  intrm_sf_mf_84 = t826 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  t826 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  if ((size_t)Q_idx_0 >= 1ULL) {
    t109 = ((size_t)Q_idx_0 <= 7ULL);
  } else {
    t109 = false;
  }

  if ((size_t)Q_idx_1 >= 1ULL) {
    t110 = ((size_t)Q_idx_1 <= 7ULL);
  } else {
    t110 = false;
  }

  if ((size_t)Q_idx_2 >= 1ULL) {
    t111 = ((size_t)Q_idx_2 <= 7ULL);
  } else {
    t111 = false;
  }

  t713[0ULL] = (int32_T)(M[108ULL] != 0);
  t713[1ULL] = (int32_T)(M[109ULL] != 0);
  t713[2ULL] = (int32_T)(M[110ULL] != 0);
  t713[3ULL] = (int32_T)(M[111ULL] != 0);
  t713[4ULL] = (int32_T)(M[112ULL] != 0);
  t713[5ULL] = (int32_T)(M[113ULL] != 0);
  t713[6ULL] = (int32_T)(M[114ULL] != 0);
  t713[7ULL] = (int32_T)(M[115ULL] != 0);
  t713[8ULL] = (int32_T)(M[116ULL] != 0);
  t713[9ULL] = (int32_T)(M[117ULL] != 0);
  t713[10ULL] = (int32_T)(M[118ULL] != 0);
  t713[11ULL] = (int32_T)(M[109ULL] != 0);
  t713[12ULL] = (int32_T)(M[110ULL] != 0);
  t713[13ULL] = (int32_T)(M[119ULL] != 0);
  t713[14ULL] = (int32_T)(M[120ULL] != 0);
  t713[15ULL] = (int32_T)(M[121ULL] != 0);
  t713[16ULL] = (int32_T)(M[122ULL] != 0);
  t713[17ULL] = (int32_T)(M[123ULL] != 0);
  t713[18ULL] = (int32_T)(M[124ULL] != 0);
  t713[19ULL] = (int32_T)(M[125ULL] != 0);
  t713[20ULL] = (int32_T)(M[126ULL] != 0);
  t713[21ULL] = (int32_T)(M[127ULL] != 0);
  t713[22ULL] = (int32_T)(M[128ULL] != 0);
  t713[23ULL] = (int32_T)(M[129ULL] != 0);
  t713[24ULL] = (int32_T)(M[130ULL] != 0);
  t713[25ULL] = (int32_T)(M[131ULL] != 0);
  t713[26ULL] = (int32_T)(M[132ULL] != 0);
  t713[27ULL] = (int32_T)(M[133ULL] != 0);
  t713[28ULL] = (int32_T)(M[134ULL] != 0);
  t713[29ULL] = (int32_T)(M[135ULL] != 0);
  t713[30ULL] = (int32_T)(M[136ULL] != 0);
  t713[31ULL] = (int32_T)(M[137ULL] != 0);
  t713[32ULL] = (int32_T)(M[138ULL] != 0);
  t713[33ULL] = (int32_T)(M[139ULL] != 0);
  t713[34ULL] = (int32_T)(M[140ULL] != 0);
  t713[35ULL] = (int32_T)(M[141ULL] != 0);
  t713[36ULL] = (int32_T)(M[142ULL] != 0);
  t713[37ULL] = (int32_T)(M[143ULL] != 0);
  t713[38ULL] = (int32_T)(M[144ULL] != 0);
  t713[39ULL] = (int32_T)(M[145ULL] != 0);
  t713[40ULL] = (int32_T)(M[146ULL] != 0);
  t713[41ULL] = (int32_T)(M[137ULL] != 0);
  t713[42ULL] = (int32_T)(M[138ULL] != 0);
  t713[43ULL] = (int32_T)(M[139ULL] != 0);
  t713[44ULL] = (int32_T)(M[140ULL] != 0);
  t713[45ULL] = (int32_T)(M[141ULL] != 0);
  t713[46ULL] = (int32_T)(M[147ULL] != 0);
  t713[47ULL] = (int32_T)(M[148ULL] != 0);
  t713[48ULL] = (int32_T)(M[149ULL] != 0);
  t713[49ULL] = (int32_T)(M[150ULL] != 0);
  t713[50ULL] = (int32_T)(M[151ULL] != 0);
  t713[51ULL] = (int32_T)(M[127ULL] != 0);
  t713[52ULL] = (int32_T)(M[128ULL] != 0);
  t713[53ULL] = (int32_T)(M[129ULL] != 0);
  t713[54ULL] = (int32_T)(M[130ULL] != 0);
  t713[55ULL] = (int32_T)(M[131ULL] != 0);
  t713[56ULL] = (int32_T)t109;
  t713[57ULL] = (int32_T)(M[113ULL] != 0);
  t713[58ULL] = (int32_T)(M[114ULL] != 0);
  t713[59ULL] = (int32_T)(M[115ULL] != 0);
  t713[60ULL] = (int32_T)(M[116ULL] != 0);
  t713[61ULL] = (int32_T)(M[117ULL] != 0);
  t713[62ULL] = (int32_T)(M[152ULL] != 0);
  t713[63ULL] = (int32_T)(M[153ULL] != 0);
  t713[64ULL] = (int32_T)(M[154ULL] != 0);
  t713[65ULL] = (int32_T)(M[155ULL] != 0);
  t713[66ULL] = (int32_T)(M[156ULL] != 0);
  t713[67ULL] = (int32_T)(M[122ULL] != 0);
  t713[68ULL] = (int32_T)(M[123ULL] != 0);
  t713[69ULL] = (int32_T)(M[124ULL] != 0);
  t713[70ULL] = (int32_T)(M[125ULL] != 0);
  t713[71ULL] = (int32_T)(M[126ULL] != 0);
  t713[72ULL] = (int32_T)t110;
  t713[73ULL] = (int32_T)(M[157ULL] != 0);
  t713[74ULL] = (int32_T)(M[158ULL] != 0);
  t713[75ULL] = (int32_T)(M[159ULL] != 0);
  t713[76ULL] = (int32_T)(M[149ULL] != 0);
  t713[77ULL] = (int32_T)(M[148ULL] != 0);
  t713[78ULL] = (int32_T)(M[160ULL] != 0);
  t713[79ULL] = (int32_T)(M[161ULL] != 0);
  t713[80ULL] = (int32_T)(M[110ULL] != 0);
  t713[81ULL] = (int32_T)(M[109ULL] != 0);
  t713[82ULL] = (int32_T)(M[162ULL] != 0);
  t713[83ULL] = (int32_T)(M[163ULL] != 0);
  t713[84ULL] = (int32_T)(M[164ULL] != 0);
  t713[85ULL] = (int32_T)(M[165ULL] != 0);
  t713[86ULL] = (int32_T)(M[166ULL] != 0);
  t713[87ULL] = (int32_T)(M[167ULL] != 0);
  t713[88ULL] = (int32_T)(M[168ULL] != 0);
  t713[89ULL] = (int32_T)(M[169ULL] != 0);
  t713[90ULL] = (int32_T)(M[170ULL] != 0);
  t713[91ULL] = (int32_T)(M[171ULL] != 0);
  t713[92ULL] = (int32_T)(M[172ULL] != 0);
  t713[93ULL] = (int32_T)(M[173ULL] != 0);
  t713[94ULL] = (int32_T)(M[174ULL] != 0);
  t713[95ULL] = (int32_T)(M[175ULL] != 0);
  t713[96ULL] = (int32_T)(M[176ULL] != 0);
  t713[97ULL] = (int32_T)(M[177ULL] != 0);
  t713[98ULL] = (int32_T)(M[178ULL] != 0);
  t713[99ULL] = (int32_T)(M[179ULL] != 0);
  t713[100ULL] = (int32_T)(M[180ULL] != 0);
  t713[101ULL] = (int32_T)(M[181ULL] != 0);
  t713[102ULL] = (int32_T)(M[182ULL] != 0);
  t713[103ULL] = (int32_T)(M[183ULL] != 0);
  t713[104ULL] = (int32_T)(M[184ULL] != 0);
  t713[105ULL] = (int32_T)(M[185ULL] != 0);
  t713[106ULL] = (int32_T)(M[186ULL] != 0);
  t713[107ULL] = (int32_T)(M[187ULL] != 0);
  t713[108ULL] = (int32_T)(M[188ULL] != 0);
  t713[109ULL] = (int32_T)(M[168ULL] != 0);
  t713[110ULL] = (int32_T)(M[169ULL] != 0);
  t713[111ULL] = (int32_T)(M[170ULL] != 0);
  t713[112ULL] = (int32_T)(M[171ULL] != 0);
  t713[113ULL] = (int32_T)(M[172ULL] != 0);
  t713[114ULL] = (int32_T)(M[189ULL] != 0);
  t713[115ULL] = (int32_T)(M[190ULL] != 0);
  t713[116ULL] = (int32_T)(M[191ULL] != 0);
  t713[117ULL] = (int32_T)(M[192ULL] != 0);
  t713[118ULL] = (int32_T)(M[193ULL] != 0);
  t713[119ULL] = (int32_T)(M[194ULL] != 0);
  t713[120ULL] = (int32_T)(M[195ULL] != 0);
  t713[121ULL] = (int32_T)(M[196ULL] != 0);
  t713[122ULL] = (int32_T)(M[197ULL] != 0);
  t713[123ULL] = (int32_T)(M[198ULL] != 0);
  t713[124ULL] = (int32_T)(M[199ULL] != 0);
  t713[125ULL] = (int32_T)(M[200ULL] != 0);
  t713[126ULL] = (int32_T)(M[201ULL] != 0);
  t713[127ULL] = (int32_T)(M[202ULL] != 0);
  t713[128ULL] = (int32_T)(M[203ULL] != 0);
  t713[129ULL] = (int32_T)(M[204ULL] != 0);
  t713[130ULL] = (int32_T)(M[205ULL] != 0);
  t713[131ULL] = (int32_T)(M[206ULL] != 0);
  t713[132ULL] = (int32_T)(M[207ULL] != 0);
  t713[133ULL] = (int32_T)(M[208ULL] != 0);
  t713[134ULL] = (int32_T)(M[209ULL] != 0);
  t713[135ULL] = (int32_T)(M[210ULL] != 0);
  t713[136ULL] = (int32_T)(M[211ULL] != 0);
  t713[137ULL] = (int32_T)(M[212ULL] != 0);
  t713[138ULL] = (int32_T)(M[213ULL] != 0);
  t713[139ULL] = (int32_T)(M[184ULL] != 0);
  t713[140ULL] = (int32_T)(M[185ULL] != 0);
  t713[141ULL] = (int32_T)(M[186ULL] != 0);
  t713[142ULL] = (int32_T)(M[187ULL] != 0);
  t713[143ULL] = (int32_T)(M[188ULL] != 0);
  t713[144ULL] = (int32_T)(M[209ULL] != 0);
  t713[145ULL] = (int32_T)(M[210ULL] != 0);
  t713[146ULL] = (int32_T)(M[211ULL] != 0);
  t713[147ULL] = (int32_T)(M[212ULL] != 0);
  t713[148ULL] = (int32_T)(M[213ULL] != 0);
  t713[149ULL] = (int32_T)(M[199ULL] != 0);
  t713[150ULL] = (int32_T)(M[200ULL] != 0);
  t713[151ULL] = (int32_T)(M[201ULL] != 0);
  t713[152ULL] = (int32_T)(M[202ULL] != 0);
  t713[153ULL] = (int32_T)(M[203ULL] != 0);
  t713[154ULL] = (int32_T)(M[152ULL] != 0);
  t713[155ULL] = (int32_T)(M[153ULL] != 0);
  t713[156ULL] = (int32_T)(M[154ULL] != 0);
  t713[157ULL] = (int32_T)(M[155ULL] != 0);
  t713[158ULL] = (int32_T)(M[156ULL] != 0);
  t713[159ULL] = (int32_T)(M[209ULL] != 0);
  t713[160ULL] = (int32_T)(M[210ULL] != 0);
  t713[161ULL] = (int32_T)(M[211ULL] != 0);
  t713[162ULL] = (int32_T)(M[212ULL] != 0);
  t713[163ULL] = (int32_T)(M[213ULL] != 0);
  t713[164ULL] = (int32_T)(M[173ULL] != 0);
  t713[165ULL] = (int32_T)(M[174ULL] != 0);
  t713[166ULL] = (int32_T)(M[175ULL] != 0);
  t713[167ULL] = (int32_T)(M[176ULL] != 0);
  t713[168ULL] = (int32_T)(M[177ULL] != 0);
  t713[169ULL] = (int32_T)(M[132ULL] != 0);
  t713[170ULL] = (int32_T)(M[133ULL] != 0);
  t713[171ULL] = (int32_T)(M[134ULL] != 0);
  t713[172ULL] = (int32_T)(M[135ULL] != 0);
  t713[173ULL] = (int32_T)(M[136ULL] != 0);
  t713[174ULL] = (int32_T)(M[194ULL] != 0);
  t713[175ULL] = (int32_T)(M[195ULL] != 0);
  t713[176ULL] = (int32_T)(M[196ULL] != 0);
  t713[177ULL] = (int32_T)(M[197ULL] != 0);
  t713[178ULL] = (int32_T)(M[198ULL] != 0);
  t713[179ULL] = (int32_T)t111;
  t713[180ULL] = 1;
  t713[181ULL] = 1;
  t713[182ULL] = (int32_T)((X[29ULL] * X[29ULL] + 4.6221943695030632E-11 == X
    [29ULL] * X[29ULL] + 4.6221943695030632E-11) && (fabs(X[29ULL] * X[29ULL] +
    4.6221943695030632E-11) != pmf_get_inf()));
  t713[183ULL] = (int32_T)((!(X[29ULL] * X[29ULL] + 4.6221943695030632E-11 == X
    [29ULL] * X[29ULL] + 4.6221943695030632E-11)) || (!(fabs(X[29ULL] * X[29ULL]
    + 4.6221943695030632E-11) != pmf_get_inf())) || (X[29ULL] * X[29ULL] +
    4.6221943695030632E-11 >= 0.0));
  t713[184ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[185ULL] = (int32_T)((!(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0)) || (t1203 != 0.0));
  t713[186ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[187ULL] = 1;
  t713[188ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[189ULL] = 1;
  t713[190ULL] = 1;
  t713[191ULL] = 1;
  t713[192ULL] = (int32_T)((X[29ULL] * X[29ULL] + 4.6221943695030632E-11 == X
    [29ULL] * X[29ULL] + 4.6221943695030632E-11) && (fabs(X[29ULL] * X[29ULL] +
    4.6221943695030632E-11) != pmf_get_inf()));
  t713[193ULL] = (int32_T)((!(X[29ULL] * X[29ULL] + 4.6221943695030632E-11 == X
    [29ULL] * X[29ULL] + 4.6221943695030632E-11)) || (!(fabs(X[29ULL] * X[29ULL]
    + 4.6221943695030632E-11) != pmf_get_inf())) || (X[29ULL] * X[29ULL] +
    4.6221943695030632E-11 >= 0.0));
  t713[194ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[195ULL] = (int32_T)((!(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0)) || (t1209 != 0.0));
  t713[196ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[197ULL] = 1;
  t713[198ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[199ULL] = 1;
  t713[200ULL] = 1;
  t713[201ULL] = 1;
  t713[202ULL] = (int32_T)((t1214 * t1214 + 13.433628212593847 == t1214 * t1214
    + 13.433628212593847) && (fabs(t1214 * t1214 + 13.433628212593847) !=
    pmf_get_inf()));
  t713[203ULL] = (int32_T)((!(t1214 * t1214 + 13.433628212593847 == t1214 *
    t1214 + 13.433628212593847)) || (!(fabs(t1214 * t1214 + 13.433628212593847)
    != pmf_get_inf())) || (t1214 * t1214 + 13.433628212593847 >= 0.0));
  t713[204ULL] = 1;
  t713[205ULL] = (int32_T)(t1203 != 0.0);
  t713[206ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_omega_pos != 0.0);
  t713[207ULL] = 1;
  t713[208ULL] = 1;
  t713[209ULL] = 1;
  t713[210ULL] = 1;
  t713[211ULL] = 1;
  t713[212ULL] = 1;
  t713[213ULL] = 1;
  t713[214ULL] = (int32_T)((!(Basic_Peripherals_Aux_TCP_hydraulic_power > 0.0)) ||
    (!(t806 > 0.0)) || (!(Basic_Peripherals_Aux_TCP_hydraulic_power * 0.001 <
    t806 * 0.001)) || (t806 != 0.0));
  t713[215ULL] = 1;
  t713[216ULL] = 1;
  t713[217ULL] = 1;
  t713[218ULL] = (int32_T)((!(t807 * 1.0E+6 <= 1666.6666666666665)) || (t807 <
    0.0) || (3333.333333333333 - t807 * 1.0E+6 != 0.0));
  t713[219ULL] = (int32_T)((!(t807 * 1.0E+6 <= 3333.333333333333)) || (t807 <
    0.0) || (t807 * 1.0E+6 <= 1666.6666666666665) || (t807 * 1.0E+6 != 0.0));
  t713[220ULL] = 1;
  t713[221ULL] = 1;
  t713[222ULL] = 1;
  t713[223ULL] = (int32_T)
    ((Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
      Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
      4.8042127793498068E-8 ==
      Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
      Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
      4.8042127793498068E-8) && (fabs
      (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
       Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
       4.8042127793498068E-8) != pmf_get_inf()));
  t713[224ULL] = (int32_T)
    ((!(Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
        Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
        4.8042127793498068E-8 ==
        Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
        Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
        4.8042127793498068E-8)) || (!(fabs
       (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
        Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
        4.8042127793498068E-8) != pmf_get_inf())) ||
     (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 *
      Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 +
      4.8042127793498068E-8 >= 0.0));
  t713[225ULL] = (int32_T)
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 != 0.0);
  t713[226ULL] = (int32_T)
    ((!(Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 != 0.0))
     || (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_rho != 0.0));
  t713[227ULL] = (int32_T)
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 != 0.0);
  t713[228ULL] = 1;
  t713[229ULL] = (int32_T)
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 != 0.0);
  t713[230ULL] = 1;
  t713[231ULL] = (int32_T)(Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I
    != 0.0);
  t713[232ULL] = 1;
  t713[233ULL] = 1;
  t713[234ULL] = 1;
  t713[235ULL] = 1;
  t713[236ULL] = 1;
  t713[237ULL] = 1;
  t713[238ULL] = 1;
  t713[239ULL] = 1;
  t713[240ULL] = 1;
  t713[241ULL] = 1;
  t713[242ULL] = 1;
  t713[243ULL] = 1;
  t713[244ULL] = 1;
  t713[245ULL] = 1;
  t713[246ULL] = 1;
  t713[247ULL] = 1;
  t713[248ULL] = (int32_T)((intrm_sf_mf_4 >= -1.0) && (intrm_sf_mf_4 <= 1.0));
  t713[249ULL] = 1;
  t713[250ULL] = 1;
  t713[251ULL] = (int32_T)((0.0020250000000000003 - intrm_sf_mf_3 *
    intrm_sf_mf_3 == 0.0020250000000000003 - intrm_sf_mf_3 * intrm_sf_mf_3) &&
    (fabs(0.0020250000000000003 - intrm_sf_mf_3 * intrm_sf_mf_3) != pmf_get_inf()));
  t713[252ULL] = (int32_T)((!(0.0020250000000000003 - intrm_sf_mf_3 *
    intrm_sf_mf_3 == 0.0020250000000000003 - intrm_sf_mf_3 * intrm_sf_mf_3)) ||
    (!(fabs(0.0020250000000000003 - intrm_sf_mf_3 * intrm_sf_mf_3) !=
       pmf_get_inf())) || (0.0020250000000000003 - intrm_sf_mf_3 * intrm_sf_mf_3
    >= 0.0));
  t713[253ULL] = 1;
  t713[254ULL] = 1;
  t713[255ULL] = (int32_T)((X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11) && (fabs(X[46ULL] * X[46ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[256ULL] = (int32_T)((!(X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11)) || (!(fabs(X[46ULL] * X[46ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[46ULL] * X[46ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[257ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[258ULL] = (int32_T)
    ((!(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0)) ||
     (Basic_Peripherals_Gate_Valve_TL_convection_A_rho != 0.0));
  t713[259ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[260ULL] = 1;
  t713[261ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[262ULL] = 1;
  t713[263ULL] = 1;
  t713[264ULL] = 1;
  t713[265ULL] = (int32_T)((X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11) && (fabs(X[46ULL] * X[46ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[266ULL] = (int32_T)((!(X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11)) || (!(fabs(X[46ULL] * X[46ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[46ULL] * X[46ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[267ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[268ULL] = (int32_T)
    ((!(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0)) ||
     (Basic_Peripherals_Gate_Valve_TL_convection_B_rho != 0.0));
  t713[269ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[270ULL] = 1;
  t713[271ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[272ULL] = 1;
  t713[273ULL] = (int32_T)((Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828 == Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828) && (fabs(Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828) != pmf_get_inf()));
  t713[274ULL] = (int32_T)((!(Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828 == Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828)) || (!(fabs(Basic_Peripherals_Gate_Valve_TL_valve_area *
    0.78539816339744828) != pmf_get_inf())) ||
    (Basic_Peripherals_Gate_Valve_TL_valve_area * 0.78539816339744828 >= 0.0));
  t713[275ULL] = 1;
  t713[276ULL] = 1;
  t713[277ULL] = 1;
  t713[278ULL] = 1;
  t713[279ULL] = (int32_T)((X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c == X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c) && (fabs(X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c) != pmf_get_inf()));
  t713[280ULL] = (int32_T)((!(X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c == X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c)) || (!(fabs(X[46ULL] * X[46ULL] +
    Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c) != pmf_get_inf())) || (X[46ULL] * X
    [46ULL] + Basic_Peripherals_Gate_Valve_TL_mdot_c *
    Basic_Peripherals_Gate_Valve_TL_mdot_c >= 0.0));
  t713[281ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_rho !=
    0.0);
  t713[282ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_B_rho !=
    0.0);
  t713[283ULL] = (int32_T)(t808 != 0.0);
  t713[284ULL] = (int32_T)(t809 != 0.0);
  t713[285ULL] = (int32_T)
    (Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL4_rho != 0.0);
  t713[286ULL] = (int32_T)(t810 * 0.0019634954084936209 != 0.0);
  t713[287ULL] = 1;
  t713[288ULL] = 1;
  t713[289ULL] = (int32_T)((X[7ULL] * X[7ULL] + 3.7732198934718893E-12 == X[7ULL]
    * X[7ULL] + 3.7732198934718893E-12) && (fabs(X[7ULL] * X[7ULL] +
    3.7732198934718893E-12) != pmf_get_inf()));
  t713[290ULL] = (int32_T)((!(X[7ULL] * X[7ULL] + 3.7732198934718893E-12 == X
    [7ULL] * X[7ULL] + 3.7732198934718893E-12)) || (!(fabs(X[7ULL] * X[7ULL] +
    3.7732198934718893E-12) != pmf_get_inf())) || (X[7ULL] * X[7ULL] +
    3.7732198934718893E-12 >= 0.0));
  t713[291ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs !=
    0.0);
  t713[292ULL] = (int32_T)((!(Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs
    != 0.0)) || (Basic_Peripherals_Pipe_TL3_convection_A_rho != 0.0));
  t713[293ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs !=
    0.0);
  t713[294ULL] = 1;
  t713[295ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs !=
    0.0);
  t713[296ULL] = 1;
  t713[297ULL] = 1;
  t713[298ULL] = 1;
  t713[299ULL] = (int32_T)((X[57ULL] * X[57ULL] + 3.7732198934718893E-12 == X
    [57ULL] * X[57ULL] + 3.7732198934718893E-12) && (fabs(X[57ULL] * X[57ULL] +
    3.7732198934718893E-12) != pmf_get_inf()));
  t713[300ULL] = (int32_T)((!(X[57ULL] * X[57ULL] + 3.7732198934718893E-12 == X
    [57ULL] * X[57ULL] + 3.7732198934718893E-12)) || (!(fabs(X[57ULL] * X[57ULL]
    + 3.7732198934718893E-12) != pmf_get_inf())) || (X[57ULL] * X[57ULL] +
    3.7732198934718893E-12 >= 0.0));
  t713[301ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs !=
    0.0);
  t713[302ULL] = (int32_T)((!(Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs
    != 0.0)) || (Basic_Peripherals_Pipe_TL3_convection_B_rho != 0.0));
  t713[303ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs !=
    0.0);
  t713[304ULL] = 1;
  t713[305ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs !=
    0.0);
  t713[306ULL] = 1;
  t713[307ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_rho_I != 0.0);
  t713[308ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_beta_I != 0.0);
  t713[309ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_A_rho != 0.0);
  t713[310ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_B_rho != 0.0);
  t713[311ULL] = 1;
  t713[312ULL] = 1;
  t713[313ULL] = (int32_T)((X[57ULL] * X[57ULL] + 9.4330497336797231E-11 == X
    [57ULL] * X[57ULL] + 9.4330497336797231E-11) && (fabs(X[57ULL] * X[57ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[314ULL] = (int32_T)((!(X[57ULL] * X[57ULL] + 9.4330497336797231E-11 == X
    [57ULL] * X[57ULL] + 9.4330497336797231E-11)) || (!(fabs(X[57ULL] * X[57ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[57ULL] * X[57ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[315ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs
    != 0.0);
  t713[316ULL] = (int32_T)
    ((!(Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs != 0.0)) ||
     (Basic_Peripherals_T_Junction_TL_convection_A_rho != 0.0));
  t713[317ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs
    != 0.0);
  t713[318ULL] = 1;
  t713[319ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs
    != 0.0);
  t713[320ULL] = 1;
  t713[321ULL] = 1;
  t713[322ULL] = 1;
  t713[323ULL] = (int32_T)((X[4ULL] * X[4ULL] + 9.4330497336797231E-11 == X[4ULL]
    * X[4ULL] + 9.4330497336797231E-11) && (fabs(X[4ULL] * X[4ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[324ULL] = (int32_T)((!(X[4ULL] * X[4ULL] + 9.4330497336797231E-11 == X
    [4ULL] * X[4ULL] + 9.4330497336797231E-11)) || (!(fabs(X[4ULL] * X[4ULL] +
    9.4330497336797231E-11) != pmf_get_inf())) || (X[4ULL] * X[4ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[325ULL] = (int32_T)(t811 != 0.0);
  t713[326ULL] = (int32_T)((!(t811 != 0.0)) ||
    (Basic_Peripherals_T_Junction_TL_convection_B_rho != 0.0));
  t713[327ULL] = (int32_T)(t811 != 0.0);
  t713[328ULL] = 1;
  t713[329ULL] = (int32_T)(t811 != 0.0);
  t713[330ULL] = 1;
  t713[331ULL] = 1;
  t713[332ULL] = 1;
  t713[333ULL] = (int32_T)((X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11) && (fabs(X[46ULL] * X[46ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[334ULL] = (int32_T)((!(X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11)) || (!(fabs(X[46ULL] * X[46ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[46ULL] * X[46ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[335ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[336ULL] = (int32_T)
    ((!(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0)) ||
     (Basic_Peripherals_T_Junction_TL_convection_C_rho != 0.0));
  t713[337ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[338ULL] = 1;
  t713[339ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[340ULL] = 1;
  t713[341ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_A_rho !=
    0.0);
  t713[342ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_B_rho !=
    0.0);
  t713[343ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL_convection_C_rho !=
    0.0);
  t713[344ULL] = 1;
  t713[345ULL] = 1;
  t713[346ULL] = (int32_T)((X[29ULL] * X[29ULL] + 9.4330497336797231E-11 == X
    [29ULL] * X[29ULL] + 9.4330497336797231E-11) && (fabs(X[29ULL] * X[29ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[347ULL] = (int32_T)((!(X[29ULL] * X[29ULL] + 9.4330497336797231E-11 == X
    [29ULL] * X[29ULL] + 9.4330497336797231E-11)) || (!(fabs(X[29ULL] * X[29ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[29ULL] * X[29ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[348ULL] = (int32_T)(t812 != 0.0);
  t713[349ULL] = (int32_T)((!(t812 != 0.0)) ||
    (Basic_Peripherals_T_Junction_TL1_convection_A_rho != 0.0));
  t713[350ULL] = (int32_T)(t812 != 0.0);
  t713[351ULL] = 1;
  t713[352ULL] = (int32_T)(t812 != 0.0);
  t713[353ULL] = 1;
  t713[354ULL] = 1;
  t713[355ULL] = 1;
  t713[356ULL] = (int32_T)((X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X[8ULL]
    * X[8ULL] + 9.4330497336797231E-11) && (fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[357ULL] = (int32_T)((!(X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X
    [8ULL] * X[8ULL] + 9.4330497336797231E-11)) || (!(fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf())) || (X[8ULL] * X[8ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[358ULL] = (int32_T)(t813 != 0.0);
  t713[359ULL] = (int32_T)((!(t813 != 0.0)) ||
    (Basic_Peripherals_T_Junction_TL1_convection_B_rho != 0.0));
  t713[360ULL] = (int32_T)(t813 != 0.0);
  t713[361ULL] = 1;
  t713[362ULL] = (int32_T)(t813 != 0.0);
  t713[363ULL] = 1;
  t713[364ULL] = 1;
  t713[365ULL] = 1;
  t713[366ULL] = (int32_T)((X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11) && (fabs(X[46ULL] * X[46ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[367ULL] = (int32_T)((!(X[46ULL] * X[46ULL] + 9.4330497336797231E-11 == X
    [46ULL] * X[46ULL] + 9.4330497336797231E-11)) || (!(fabs(X[46ULL] * X[46ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[46ULL] * X[46ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[368ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[369ULL] = (int32_T)
    ((!(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0)) ||
     (Basic_Peripherals_T_Junction_TL1_convection_C_rho != 0.0));
  t713[370ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[371ULL] = 1;
  t713[372ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs
    != 0.0);
  t713[373ULL] = 1;
  t713[374ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL1_convection_A_rho !=
    0.0);
  t713[375ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL1_convection_B_rho !=
    0.0);
  t713[376ULL] = (int32_T)(Basic_Peripherals_T_Junction_TL1_convection_C_rho !=
    0.0);
  t713[377ULL] = (int32_T)(t814 + 0.029511607098668874 != 0.0);
  t713[378ULL] = (int32_T)(t815 * 0.47700000000000009 != 0.0);
  t713[379ULL] = (int32_T)(t817 * 2.9881500000000005 != 0.0);
  t713[380ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7 * 6.0 != 0.0);
  t713[381ULL] = (int32_T)((!(t816 >= 1.0 / (t821 == 0.0 ? 1.0E-16 : t821))) ||
    (t816 * Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7 !=
     0.0));
  t1203 = t816 * Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7;
  t713[382ULL] = (int32_T)((!(t816 >= 1.0 / (t821 == 0.0 ? 1.0E-16 : t821))) ||
    (!(t816 * Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R7 !=
       0.0)) || (-1.0 / (t1203 == 0.0 ? 1.0E-16 : t1203) < 663.67513503334737));
  t713[383ULL] = 1;
  t713[384ULL] = (int32_T)(t818 > 0.0);
  t713[385ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 != 0.0);
  t713[386ULL] = (int32_T)
    (-Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 * (1.0 -
      t818) < 663.67513503334737);
  t713[387ULL] = (int32_T)
    ((Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 > 0.0) ||
     (t818 != 0.0));
  t713[388ULL] = (int32_T)((t818 >= 0.0) ||
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 == floor
     (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0)));
  t713[389ULL] = (int32_T)
    (((!(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 > 0.0)) &&
      (!(t818 != 0.0))) || ((!(t818 >= 0.0)) &&
      (!(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 == floor
         (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0)))) ||
     (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 != 0.0));
  t1203 = -(1.0 - pmf_pow(t818,
             Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0));
  t713[390ULL] = (int32_T)
    (((!(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 > 0.0)) &&
      (!(t818 != 0.0))) || ((!(t818 >= 0.0)) &&
      (!(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 == floor
         (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0)))) ||
     (((Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 > 0.0) ||
       (t818 != 0.0)) && ((t818 >= 0.0) ||
       (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 == floor
        (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0))) &&
      (!(Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0 != 0.0)))
     || (t1203 / (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0
                  == 0.0 ? 1.0E-16 :
                  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R0)
         < 663.67513503334737));
  t713[391ULL] = (int32_T)(t820 * 0.00075 != 0.0);
  t713[392ULL] = (int32_T)(t824 != 0.0);
  t713[393ULL] = (int32_T)((!(t824 != 0.0)) || (6.9 / (t824 == 0.0 ? 1.0E-16 :
    t824) + 0.00069701528436089772 > 0.0));
  t713[394ULL] = 1;
  t713[395ULL] = 1;
  t713[396ULL] = (int32_T)((!(t824 != 0.0)) || ((t824 != 0.0) && (!(6.9 / (t824 ==
    0.0 ? 1.0E-16 : t824) + 0.00069701528436089772 > 0.0))) || (pmf_log10(6.9 /
    (t824 == 0.0 ? 1.0E-16 : t824) + 0.00069701528436089772) * pmf_log10(6.9 /
    (t824 == 0.0 ? 1.0E-16 : t824) + 0.00069701528436089772) * 3.24 != 0.0));
  t713[397ULL] = (int32_T)((t822 / 8.0 == t822 / 8.0) && (fabs(t822 / 8.0) !=
    pmf_get_inf()));
  t713[398ULL] = (int32_T)((!(t822 / 8.0 == t822 / 8.0)) || (!(fabs(t822 / 8.0)
    != pmf_get_inf())) || (t822 / 8.0 >= 0.0));
  t713[399ULL] = 1;
  t713[400ULL] = (int32_T)(t819 >= 0.0);
  t713[401ULL] = (int32_T)((!(t822 / 8.0 == t822 / 8.0)) || (!(fabs(t822 / 8.0)
    != pmf_get_inf())) || ((t822 / 8.0 == t822 / 8.0) && (fabs(t822 / 8.0) !=
    pmf_get_inf()) && (!(t822 / 8.0 >= 0.0))) || (!(t819 >= 0.0)) || ((pmf_pow
    (t819, 0.66666666666666663) - 1.0) * pmf_sqrt(t822 / 8.0) * 12.7 + 1.0 !=
    0.0));
  t713[402ULL] = 1;
  t713[403ULL] = 1;
  t713[404ULL] = 1;
  t713[405ULL] = 1;
  t713[406ULL] = (int32_T)(t825 * 0.00075 != 0.0);
  t713[407ULL] = (int32_T)(t827 != 0.0);
  t713[408ULL] = (int32_T)((!(t827 != 0.0)) || (6.9 / (t827 == 0.0 ? 1.0E-16 :
    t827) + 0.00069701528436089772 > 0.0));
  t713[409ULL] = 1;
  t713[410ULL] = 1;
  t713[411ULL] = (int32_T)((!(t827 != 0.0)) || ((t827 != 0.0) && (!(6.9 / (t827 ==
    0.0 ? 1.0E-16 : t827) + 0.00069701528436089772 > 0.0))) || (pmf_log10(6.9 /
    (t827 == 0.0 ? 1.0E-16 : t827) + 0.00069701528436089772) * pmf_log10(6.9 /
    (t827 == 0.0 ? 1.0E-16 : t827) + 0.00069701528436089772) * 3.24 != 0.0));
  t713[412ULL] = (int32_T)((intrm_sf_mf_64 / 8.0 == intrm_sf_mf_64 / 8.0) &&
    (fabs(intrm_sf_mf_64 / 8.0) != pmf_get_inf()));
  t713[413ULL] = (int32_T)((!(intrm_sf_mf_64 / 8.0 == intrm_sf_mf_64 / 8.0)) ||
    (!(fabs(intrm_sf_mf_64 / 8.0) != pmf_get_inf())) || (intrm_sf_mf_64 / 8.0 >=
    0.0));
  t713[414ULL] = 1;
  t713[415ULL] = (int32_T)(t1202 >= 0.0);
  t713[416ULL] = (int32_T)((!(intrm_sf_mf_64 / 8.0 == intrm_sf_mf_64 / 8.0)) ||
    (!(fabs(intrm_sf_mf_64 / 8.0) != pmf_get_inf())) || ((intrm_sf_mf_64 / 8.0 ==
    intrm_sf_mf_64 / 8.0) && (fabs(intrm_sf_mf_64 / 8.0) != pmf_get_inf()) &&
    (!(intrm_sf_mf_64 / 8.0 >= 0.0))) || (!(t1202 >= 0.0)) || ((pmf_pow(t1202,
    0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_64 / 8.0) * 12.7 + 1.0 !=
    0.0));
  t713[417ULL] = 1;
  t713[418ULL] = 1;
  t713[419ULL] = 1;
  t713[420ULL] = 1;
  t713[421ULL] = (int32_T)(t829 * 0.0015 != 0.0);
  t713[422ULL] = 1;
  t713[423ULL] = 1;
  t713[424ULL] = (int32_T)((X[100ULL] * X[100ULL] + 2.8825276676098833E-12 == X
    [100ULL] * X[100ULL] + 2.8825276676098833E-12) && (fabs(X[100ULL] * X[100ULL]
    + 2.8825276676098833E-12) != pmf_get_inf()));
  t713[425ULL] = (int32_T)((!(X[100ULL] * X[100ULL] + 2.8825276676098833E-12 ==
    X[100ULL] * X[100ULL] + 2.8825276676098833E-12)) || (!(fabs(X[100ULL] * X
    [100ULL] + 2.8825276676098833E-12) != pmf_get_inf())) || (X[100ULL] * X
    [100ULL] + 2.8825276676098833E-12 >= 0.0));
  t713[426ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 != 0.0);
  t713[427ULL] = (int32_T)
    ((!(Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 != 0.0)) ||
     (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect2 != 0.0));
  t713[428ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 != 0.0);
  t713[429ULL] = 1;
  t713[430ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 != 0.0);
  t713[431ULL] = 1;
  t713[432ULL] = 1;
  t713[433ULL] = 1;
  t713[434ULL] = (int32_T)((X[101ULL] * X[101ULL] + 2.8825276676098833E-12 == X
    [101ULL] * X[101ULL] + 2.8825276676098833E-12) && (fabs(X[101ULL] * X[101ULL]
    + 2.8825276676098833E-12) != pmf_get_inf()));
  t713[435ULL] = (int32_T)((!(X[101ULL] * X[101ULL] + 2.8825276676098833E-12 ==
    X[101ULL] * X[101ULL] + 2.8825276676098833E-12)) || (!(fabs(X[101ULL] * X
    [101ULL] + 2.8825276676098833E-12) != pmf_get_inf())) || (X[101ULL] * X
    [101ULL] + 2.8825276676098833E-12 >= 0.0));
  t713[436ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 != 0.0);
  t713[437ULL] = (int32_T)
    ((!(Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 != 0.0)) ||
     (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect8 != 0.0));
  t713[438ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 != 0.0);
  t713[439ULL] = 1;
  t713[440ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 != 0.0);
  t713[441ULL] = 1;
  t713[442ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I != 0.0);
  t713[443ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I != 0.0);
  t713[444ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect2 != 0.0);
  t713[445ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect8 != 0.0);
  t713[446ULL] = (int32_T)
    (Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_rho != 0.0);
  t713[447ULL] = (int32_T)
    (Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_rho != 0.0);
  t713[448ULL] = (int32_T)
    (Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL2_rho != 0.0);
  t713[449ULL] = (int32_T)(t830 * 0.0019634954084936209 != 0.0);
  t713[450ULL] = 1;
  t713[451ULL] = 1;
  t713[452ULL] = (int32_T)((X[110ULL] * X[110ULL] + 3.7732198934718893E-12 == X
    [110ULL] * X[110ULL] + 3.7732198934718893E-12) && (fabs(X[110ULL] * X[110ULL]
    + 3.7732198934718893E-12) != pmf_get_inf()));
  t713[453ULL] = (int32_T)((!(X[110ULL] * X[110ULL] + 3.7732198934718893E-12 ==
    X[110ULL] * X[110ULL] + 3.7732198934718893E-12)) || (!(fabs(X[110ULL] * X
    [110ULL] + 3.7732198934718893E-12) != pmf_get_inf())) || (X[110ULL] * X
    [110ULL] + 3.7732198934718893E-12 >= 0.0));
  t713[454ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs !=
    0.0);
  t713[455ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs
    != 0.0)) || (Subsystem_Reference_Pipe_TL2_convection_A_rho != 0.0));
  t713[456ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs !=
    0.0);
  t713[457ULL] = 1;
  t713[458ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs !=
    0.0);
  t713[459ULL] = 1;
  t713[460ULL] = 1;
  t713[461ULL] = 1;
  t713[462ULL] = (int32_T)((X[100ULL] * X[100ULL] + 3.7732198934718893E-12 == X
    [100ULL] * X[100ULL] + 3.7732198934718893E-12) && (fabs(X[100ULL] * X[100ULL]
    + 3.7732198934718893E-12) != pmf_get_inf()));
  t713[463ULL] = (int32_T)((!(X[100ULL] * X[100ULL] + 3.7732198934718893E-12 ==
    X[100ULL] * X[100ULL] + 3.7732198934718893E-12)) || (!(fabs(X[100ULL] * X
    [100ULL] + 3.7732198934718893E-12) != pmf_get_inf())) || (X[100ULL] * X
    [100ULL] + 3.7732198934718893E-12 >= 0.0));
  t713[464ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs !=
    0.0);
  t713[465ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs
    != 0.0)) || (Subsystem_Reference_Pipe_TL2_convection_B_rho != 0.0));
  t713[466ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs !=
    0.0);
  t713[467ULL] = 1;
  t713[468ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs !=
    0.0);
  t713[469ULL] = 1;
  t713[470ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_rho_I != 0.0);
  t713[471ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_beta_I != 0.0);
  t713[472ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_A_rho != 0.0);
  t713[473ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_B_rho != 0.0);
  t713[474ULL] = (int32_T)(t831 * 0.0019634954084936209 != 0.0);
  t713[475ULL] = 1;
  t713[476ULL] = 1;
  t713[477ULL] = (int32_T)((X[16ULL] * X[16ULL] + 3.7732198934718893E-12 == X
    [16ULL] * X[16ULL] + 3.7732198934718893E-12) && (fabs(X[16ULL] * X[16ULL] +
    3.7732198934718893E-12) != pmf_get_inf()));
  t713[478ULL] = (int32_T)((!(X[16ULL] * X[16ULL] + 3.7732198934718893E-12 == X
    [16ULL] * X[16ULL] + 3.7732198934718893E-12)) || (!(fabs(X[16ULL] * X[16ULL]
    + 3.7732198934718893E-12) != pmf_get_inf())) || (X[16ULL] * X[16ULL] +
    3.7732198934718893E-12 >= 0.0));
  t713[479ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs !=
    0.0);
  t713[480ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs
    != 0.0)) || (Subsystem_Reference_Pipe_TL4_convection_A_rho != 0.0));
  t713[481ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs !=
    0.0);
  t713[482ULL] = 1;
  t713[483ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs !=
    0.0);
  t713[484ULL] = 1;
  t713[485ULL] = 1;
  t713[486ULL] = 1;
  t713[487ULL] = (int32_T)((Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12) &&
    (fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
          Subsystem_Reference_Pipe_TL4_convection_B_mdot +
          3.7732198934718893E-12) != pmf_get_inf()));
  t713[488ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12)) ||
    (!(fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
            Subsystem_Reference_Pipe_TL4_convection_B_mdot +
            3.7732198934718893E-12) != pmf_get_inf())) ||
    (Subsystem_Reference_Pipe_TL4_convection_B_mdot *
     Subsystem_Reference_Pipe_TL4_convection_B_mdot + 3.7732198934718893E-12 >=
     0.0));
  t713[489ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs !=
    0.0);
  t713[490ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs
    != 0.0)) || (Subsystem_Reference_Pipe_TL4_convection_B_rho != 0.0));
  t713[491ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs !=
    0.0);
  t713[492ULL] = 1;
  t713[493ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs !=
    0.0);
  t713[494ULL] = 1;
  t713[495ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_rho_I != 0.0);
  t713[496ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_beta_I != 0.0);
  t713[497ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_A_rho != 0.0);
  t713[498ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_B_rho != 0.0);
  t713[499ULL] = 1;
  t713[500ULL] = 1;
  t713[501ULL] = (int32_T)((X[110ULL] * X[110ULL] + 9.4330497336797231E-11 == X
    [110ULL] * X[110ULL] + 9.4330497336797231E-11) && (fabs(X[110ULL] * X[110ULL]
    + 9.4330497336797231E-11) != pmf_get_inf()));
  t713[502ULL] = (int32_T)((!(X[110ULL] * X[110ULL] + 9.4330497336797231E-11 ==
    X[110ULL] * X[110ULL] + 9.4330497336797231E-11)) || (!(fabs(X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11) != pmf_get_inf())) || (X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11 >= 0.0));
  t713[503ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[504ULL] = (int32_T)((!(Subsystem_Reference_TCP_6812_convection_A_mdot_abs
    != 0.0)) || (Subsystem_Reference_TCP_6812_convection_A_rho != 0.0));
  t713[505ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[506ULL] = 1;
  t713[507ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[508ULL] = 1;
  t713[509ULL] = 1;
  t713[510ULL] = 1;
  t713[511ULL] = (int32_T)((X[110ULL] * X[110ULL] + 9.4330497336797231E-11 == X
    [110ULL] * X[110ULL] + 9.4330497336797231E-11) && (fabs(X[110ULL] * X[110ULL]
    + 9.4330497336797231E-11) != pmf_get_inf()));
  t713[512ULL] = (int32_T)((!(X[110ULL] * X[110ULL] + 9.4330497336797231E-11 ==
    X[110ULL] * X[110ULL] + 9.4330497336797231E-11)) || (!(fabs(X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11) != pmf_get_inf())) || (X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11 >= 0.0));
  t713[513ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[514ULL] = (int32_T)((!(Subsystem_Reference_TCP_6812_convection_A_mdot_abs
    != 0.0)) || (Subsystem_Reference_TCP_6812_convection_B_rho != 0.0));
  t713[515ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[516ULL] = 1;
  t713[517ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs !=
    0.0);
  t713[518ULL] = 1;
  t713[519ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_rho != 0.0);
  t713[520ULL] = (int32_T)((!(Subsystem_Reference_TCP_6812_hydraulic_power > 0.0))
    || (!(Subsystem_Reference_TCP_6812_mechanical_power > 0.0)) ||
    (!(Subsystem_Reference_TCP_6812_hydraulic_power * 0.001 <
       Subsystem_Reference_TCP_6812_mechanical_power * 0.001)) ||
    (Subsystem_Reference_TCP_6812_mechanical_power != 0.0));
  t713[521ULL] = 1;
  t713[522ULL] = 1;
  t713[523ULL] = (int32_T)((Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11) &&
    (fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
          Subsystem_Reference_Pipe_TL4_convection_B_mdot +
          9.4330497336797231E-11) != pmf_get_inf()));
  t713[524ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11)) ||
    (!(fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
            Subsystem_Reference_Pipe_TL4_convection_B_mdot +
            9.4330497336797231E-11) != pmf_get_inf())) ||
    (Subsystem_Reference_Pipe_TL4_convection_B_mdot *
     Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 >=
     0.0));
  t713[525ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[526ULL] = (int32_T)
    ((!(Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0))
     || (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho != 0.0));
  t713[527ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[528ULL] = 1;
  t713[529ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[530ULL] = 1;
  t713[531ULL] = 1;
  t713[532ULL] = 1;
  t713[533ULL] = (int32_T)((Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11) &&
    (fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
          Subsystem_Reference_Pipe_TL4_convection_B_mdot +
          9.4330497336797231E-11) != pmf_get_inf()));
  t713[534ULL] = (int32_T)((!(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 ==
    Subsystem_Reference_Pipe_TL4_convection_B_mdot *
    Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11)) ||
    (!(fabs(Subsystem_Reference_Pipe_TL4_convection_B_mdot *
            Subsystem_Reference_Pipe_TL4_convection_B_mdot +
            9.4330497336797231E-11) != pmf_get_inf())) ||
    (Subsystem_Reference_Pipe_TL4_convection_B_mdot *
     Subsystem_Reference_Pipe_TL4_convection_B_mdot + 9.4330497336797231E-11 >=
     0.0));
  t713[535ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[536ULL] = (int32_T)
    ((!(Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0))
     || (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho != 0.0));
  t713[537ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[538ULL] = 1;
  t713[539ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[540ULL] = 1;
  t713[541ULL] = 1;
  t713[542ULL] = 1;
  t713[543ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area * t833 * 2.0 != 0.0);
  t713[544ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho != 0.0);
  t713[545ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho != 0.0);
  t713[546ULL] = 1;
  t713[547ULL] = 1;
  t713[548ULL] = (int32_T)((X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X[8ULL]
    * X[8ULL] + 9.4330497336797231E-11) && (fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[549ULL] = (int32_T)((!(X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X
    [8ULL] * X[8ULL] + 9.4330497336797231E-11)) || (!(fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf())) || (X[8ULL] * X[8ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[550ULL] = (int32_T)(t813 != 0.0);
  t713[551ULL] = (int32_T)((!(t813 != 0.0)) || (t836 != 0.0));
  t713[552ULL] = (int32_T)(t813 != 0.0);
  t713[553ULL] = 1;
  t713[554ULL] = (int32_T)(t813 != 0.0);
  t713[555ULL] = 1;
  t713[556ULL] = 1;
  t713[557ULL] = 1;
  t713[558ULL] = (int32_T)((X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X[8ULL]
    * X[8ULL] + 9.4330497336797231E-11) && (fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[559ULL] = (int32_T)((!(X[8ULL] * X[8ULL] + 9.4330497336797231E-11 == X
    [8ULL] * X[8ULL] + 9.4330497336797231E-11)) || (!(fabs(X[8ULL] * X[8ULL] +
    9.4330497336797231E-11) != pmf_get_inf())) || (X[8ULL] * X[8ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[560ULL] = (int32_T)(t813 != 0.0);
  t713[561ULL] = (int32_T)((!(t813 != 0.0)) ||
    (Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho != 0.0));
  t713[562ULL] = (int32_T)(t813 != 0.0);
  t713[563ULL] = 1;
  t713[564ULL] = (int32_T)(t813 != 0.0);
  t713[565ULL] = 1;
  t713[566ULL] = 1;
  t713[567ULL] = 1;
  t713[568ULL] = (int32_T)(t834 * t837 * 2.0 != 0.0);
  t713[569ULL] = (int32_T)(t836 != 0.0);
  t713[570ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho != 0.0);
  t713[571ULL] = 1;
  t713[572ULL] = 1;
  t713[573ULL] = (int32_T)((X[101ULL] * X[101ULL] + 9.4330497336797231E-11 == X
    [101ULL] * X[101ULL] + 9.4330497336797231E-11) && (fabs(X[101ULL] * X[101ULL]
    + 9.4330497336797231E-11) != pmf_get_inf()));
  t713[574ULL] = (int32_T)((!(X[101ULL] * X[101ULL] + 9.4330497336797231E-11 ==
    X[101ULL] * X[101ULL] + 9.4330497336797231E-11)) || (!(fabs(X[101ULL] * X
    [101ULL] + 9.4330497336797231E-11) != pmf_get_inf())) || (X[101ULL] * X
    [101ULL] + 9.4330497336797231E-11 >= 0.0));
  t713[575ULL] = (int32_T)(t838 != 0.0);
  t713[576ULL] = (int32_T)((!(t838 != 0.0)) || (t840 != 0.0));
  t713[577ULL] = (int32_T)(t838 != 0.0);
  t713[578ULL] = 1;
  t713[579ULL] = (int32_T)(t838 != 0.0);
  t713[580ULL] = 1;
  t713[581ULL] = 1;
  t713[582ULL] = 1;
  t713[583ULL] = (int32_T)((X[7ULL] * X[7ULL] + 9.4330497336797231E-11 == X[7ULL]
    * X[7ULL] + 9.4330497336797231E-11) && (fabs(X[7ULL] * X[7ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[584ULL] = (int32_T)((!(X[7ULL] * X[7ULL] + 9.4330497336797231E-11 == X
    [7ULL] * X[7ULL] + 9.4330497336797231E-11)) || (!(fabs(X[7ULL] * X[7ULL] +
    9.4330497336797231E-11) != pmf_get_inf())) || (X[7ULL] * X[7ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[585ULL] = (int32_T)(t841 != 0.0);
  t713[586ULL] = (int32_T)((!(t841 != 0.0)) || (t802_idx_0 != 0.0));
  t713[587ULL] = (int32_T)(t841 != 0.0);
  t713[588ULL] = 1;
  t713[589ULL] = (int32_T)(t841 != 0.0);
  t713[590ULL] = 1;
  t713[591ULL] = 1;
  t713[592ULL] = 1;
  t713[593ULL] = (int32_T)((X[16ULL] * X[16ULL] + 9.4330497336797231E-11 == X
    [16ULL] * X[16ULL] + 9.4330497336797231E-11) && (fabs(X[16ULL] * X[16ULL] +
    9.4330497336797231E-11) != pmf_get_inf()));
  t713[594ULL] = (int32_T)((!(X[16ULL] * X[16ULL] + 9.4330497336797231E-11 == X
    [16ULL] * X[16ULL] + 9.4330497336797231E-11)) || (!(fabs(X[16ULL] * X[16ULL]
    + 9.4330497336797231E-11) != pmf_get_inf())) || (X[16ULL] * X[16ULL] +
    9.4330497336797231E-11 >= 0.0));
  t713[595ULL] = (int32_T)
    (Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs != 0.0);
  t713[596ULL] = (int32_T)
    ((!(Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs != 0.0)) ||
     (Subsystem_Reference_T_Junction_TL_convection_C_rho != 0.0));
  t713[597ULL] = (int32_T)
    (Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs != 0.0);
  t713[598ULL] = 1;
  t713[599ULL] = (int32_T)
    (Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs != 0.0);
  t713[600ULL] = 1;
  t713[601ULL] = (int32_T)(t840 != 0.0);
  t713[602ULL] = (int32_T)(t802_idx_0 != 0.0);
  t713[603ULL] = (int32_T)(Subsystem_Reference_T_Junction_TL_convection_C_rho !=
    0.0);
  t713[604ULL] = (int32_T)(t843 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[605ULL] = (int32_T)(t847 / 2.0 * 0.0015 != 0.0);
  t713[606ULL] = (int32_T)(intrm_sf_mf_93 != 0.0);
  t713[607ULL] = (int32_T)((!(intrm_sf_mf_93 != 0.0)) || (6.9 / (intrm_sf_mf_93 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_93) + 0.002211858722000578 > 0.0));
  t713[608ULL] = 1;
  t713[609ULL] = 1;
  t713[610ULL] = (int32_T)((!(intrm_sf_mf_93 != 0.0)) || ((intrm_sf_mf_93 != 0.0)
    && (!(6.9 / (intrm_sf_mf_93 == 0.0 ? 1.0E-16 : intrm_sf_mf_93) +
          0.002211858722000578 > 0.0))) || (pmf_log10(6.9 / (intrm_sf_mf_93 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_93) + 0.002211858722000578) * pmf_log10(6.9 /
    (intrm_sf_mf_93 == 0.0 ? 1.0E-16 : intrm_sf_mf_93) + 0.002211858722000578) *
    3.24 != 0.0));
  t713[611ULL] = (int32_T)((t845 / 8.0 == t845 / 8.0) && (fabs(t845 / 8.0) !=
    pmf_get_inf()));
  t713[612ULL] = (int32_T)((!(t845 / 8.0 == t845 / 8.0)) || (!(fabs(t845 / 8.0)
    != pmf_get_inf())) || (t845 / 8.0 >= 0.0));
  t713[613ULL] = 1;
  t713[614ULL] = (int32_T)(t851 / 2.0 >= 0.0);
  t713[615ULL] = 1;
  t713[616ULL] = 1;
  t713[617ULL] = 1;
  t713[618ULL] = (int32_T)((!((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t845 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((t845 / 8.0 == t845 / 8.0)
    && (fabs(t845 / 8.0) != pmf_get_inf())));
  t713[619ULL] = (int32_T)((!((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t845 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t845 / 8.0 == t845 /
    8.0)) || (!(fabs(t845 / 8.0) != pmf_get_inf()))) || (t845 / 8.0 >= 0.0));
  t713[620ULL] = 1;
  t713[621ULL] = 1;
  t713[622ULL] = (int32_T)((!((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t845 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t851 / 2.0 >= 0.0));
  t713[623ULL] = (int32_T)((!((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t845 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t845 / 8.0 == t845 /
    8.0)) || (!(fabs(t845 / 8.0) != pmf_get_inf()))) || ((t845 / 8.0 == t845 /
    8.0) && (fabs(t845 / 8.0) != pmf_get_inf()) && (!(t845 / 8.0 >= 0.0))) ||
    (!(t851 / 2.0 >= 0.0)) || ((pmf_pow(t851 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t845 / 8.0) * 12.7 + 1.0 != 0.0));
  t713[624ULL] = 1;
  t713[625ULL] = 1;
  t713[626ULL] = 1;
  t713[627ULL] = 1;
  t713[628ULL] = 1;
  t713[629ULL] = 1;
  t713[630ULL] = 1;
  t713[631ULL] = (int32_T)(t851 / 2.0 != 0.0);
  t713[632ULL] = 1;
  t1203 = t851 / 2.0;
  t713[633ULL] = (int32_T)((!(t844 > t859 / 0.0015 / (t1203 == 0.0 ? 1.0E-16 :
    t1203) / 30.0)) || (t844 != 0.0));
  t713[634ULL] = 1;
  t713[635ULL] = 1;
  t1203 = t851 / 2.0;
  t713[636ULL] = (int32_T)((!(t844 > t859 / 0.0015 / (t1203 == 0.0 ? 1.0E-16 :
    t1203) / 30.0)) || (!(t844 != 0.0)) || (t851 / 2.0 != 0.0));
  t713[637ULL] = (int32_T)(-t846 < 663.67513503334737);
  t713[638ULL] = (int32_T)(t869 / 2.0 * 0.0015 != 0.0);
  t713[639ULL] = (int32_T)(intrm_sf_mf_106 != 0.0);
  t713[640ULL] = (int32_T)((!(intrm_sf_mf_106 != 0.0)) || (6.9 /
    (intrm_sf_mf_106 == 0.0 ? 1.0E-16 : intrm_sf_mf_106) + 0.002211858722000578 >
    0.0));
  t713[641ULL] = 1;
  t713[642ULL] = 1;
  t713[643ULL] = (int32_T)((!(intrm_sf_mf_106 != 0.0)) || ((intrm_sf_mf_106 !=
    0.0) && (!(6.9 / (intrm_sf_mf_106 == 0.0 ? 1.0E-16 : intrm_sf_mf_106) +
               0.002211858722000578 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_106 == 0.0 ? 1.0E-16 : intrm_sf_mf_106) + 0.002211858722000578)
    * pmf_log10(6.9 / (intrm_sf_mf_106 == 0.0 ? 1.0E-16 : intrm_sf_mf_106) +
                0.002211858722000578) * 3.24 != 0.0));
  t713[644ULL] = (int32_T)((intrm_sf_mf_107 / 8.0 == intrm_sf_mf_107 / 8.0) &&
    (fabs(intrm_sf_mf_107 / 8.0) != pmf_get_inf()));
  t713[645ULL] = (int32_T)((!(intrm_sf_mf_107 / 8.0 == intrm_sf_mf_107 / 8.0)) ||
    (!(fabs(intrm_sf_mf_107 / 8.0) != pmf_get_inf())) || (intrm_sf_mf_107 / 8.0 >=
    0.0));
  t713[646ULL] = 1;
  t713[647ULL] = (int32_T)(t873 / 2.0 >= 0.0);
  t713[648ULL] = 1;
  t713[649ULL] = 1;
  t713[650ULL] = 1;
  t713[651ULL] = (int32_T)((!((pmf_pow(t873 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_107 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((intrm_sf_mf_107 / 8.0 == intrm_sf_mf_107 / 8.0) && (fabs(intrm_sf_mf_107 /
    8.0) != pmf_get_inf())));
  t713[652ULL] = (int32_T)((!((pmf_pow(t873 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_107 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_107 / 8.0 == intrm_sf_mf_107 / 8.0)) || (!(fabs
    (intrm_sf_mf_107 / 8.0) != pmf_get_inf()))) || (intrm_sf_mf_107 / 8.0 >= 0.0));
  t713[653ULL] = 1;
  t713[654ULL] = 1;
  t713[655ULL] = (int32_T)((!((pmf_pow(t873 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_107 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t873 / 2.0 >=
    0.0));
  t713[656ULL] = (int32_T)((!((pmf_pow(t873 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_107 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_107 / 8.0 == intrm_sf_mf_107 / 8.0)) || (!(fabs
    (intrm_sf_mf_107 / 8.0) != pmf_get_inf()))) || ((intrm_sf_mf_107 / 8.0 ==
    intrm_sf_mf_107 / 8.0) && (fabs(intrm_sf_mf_107 / 8.0) != pmf_get_inf()) &&
    (!(intrm_sf_mf_107 / 8.0 >= 0.0))) || (!(t873 / 2.0 >= 0.0)) || ((pmf_pow
    (t873 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_107 / 8.0) *
    12.7 + 1.0 != 0.0));
  t713[657ULL] = 1;
  t713[658ULL] = 1;
  t713[659ULL] = 1;
  t713[660ULL] = 1;
  t713[661ULL] = 1;
  t713[662ULL] = 1;
  t713[663ULL] = 1;
  t713[664ULL] = 1;
  t713[665ULL] = 1;
  t713[666ULL] = 1;
  t713[667ULL] = 1;
  t713[668ULL] = (int32_T)(t873 / 2.0 != 0.0);
  t713[669ULL] = 1;
  t1203 = t873 / 2.0;
  t713[670ULL] = (int32_T)((!(intrm_sf_mf_105 > t881 / 0.0015 / (t1203 == 0.0 ?
    1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_105 != 0.0));
  t713[671ULL] = 1;
  t713[672ULL] = 1;
  t1203 = t873 / 2.0;
  t713[673ULL] = (int32_T)((!(intrm_sf_mf_105 > t881 / 0.0015 / (t1203 == 0.0 ?
    1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_105 != 0.0)) || (t873 / 2.0 !=
    0.0));
  t713[674ULL] = (int32_T)(-intrm_sf_mf_112 < 663.67513503334737);
  t713[675ULL] = 1;
  t713[676ULL] = 1;
  t713[677ULL] = 1;
  t713[678ULL] = 1;
  t713[679ULL] = 1;
  t713[680ULL] = (int32_T)(t829 * 0.0015 != 0.0);
  t713[681ULL] = (int32_T)(intrm_sf_mf_7 != 0.0);
  t713[682ULL] = (int32_T)((!(intrm_sf_mf_7 != 0.0)) || (6.9 / (intrm_sf_mf_7 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_7) + 9.0751776413883736E-6 > 0.0));
  t713[683ULL] = 1;
  t713[684ULL] = 1;
  t713[685ULL] = (int32_T)((!(intrm_sf_mf_7 != 0.0)) || ((intrm_sf_mf_7 != 0.0) &&
    (!(6.9 / (intrm_sf_mf_7 == 0.0 ? 1.0E-16 : intrm_sf_mf_7) +
       9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 / (intrm_sf_mf_7 == 0.0 ?
    1.0E-16 : intrm_sf_mf_7) + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (intrm_sf_mf_7 == 0.0 ? 1.0E-16 : intrm_sf_mf_7) + 9.0751776413883736E-6) *
    3.24 != 0.0));
  t713[686ULL] = (int32_T)((t848 / 8.0 == t848 / 8.0) && (fabs(t848 / 8.0) !=
    pmf_get_inf()));
  t713[687ULL] = (int32_T)((!(t848 / 8.0 == t848 / 8.0)) || (!(fabs(t848 / 8.0)
    != pmf_get_inf())) || (t848 / 8.0 >= 0.0));
  t713[688ULL] = 1;
  t713[689ULL] = (int32_T)(t891 / 2.0 >= 0.0);
  t713[690ULL] = 1;
  t713[691ULL] = 1;
  t713[692ULL] = 1;
  t713[693ULL] = (int32_T)((!((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t848 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((t848 / 8.0 == t848 / 8.0)
    && (fabs(t848 / 8.0) != pmf_get_inf())));
  t713[694ULL] = (int32_T)((!((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t848 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t848 / 8.0 == t848 /
    8.0)) || (!(fabs(t848 / 8.0) != pmf_get_inf()))) || (t848 / 8.0 >= 0.0));
  t713[695ULL] = 1;
  t713[696ULL] = 1;
  t713[697ULL] = (int32_T)((!((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t848 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t891 / 2.0 >= 0.0));
  t713[698ULL] = (int32_T)((!((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t848 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t848 / 8.0 == t848 /
    8.0)) || (!(fabs(t848 / 8.0) != pmf_get_inf()))) || ((t848 / 8.0 == t848 /
    8.0) && (fabs(t848 / 8.0) != pmf_get_inf()) && (!(t848 / 8.0 >= 0.0))) ||
    (!(t891 / 2.0 >= 0.0)) || ((pmf_pow(t891 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t848 / 8.0) * 12.7 + 1.0 != 0.0));
  t713[699ULL] = 1;
  t713[700ULL] = 1;
  t713[701ULL] = 1;
  t713[702ULL] = (int32_T)(t849 != 0.0);
  t713[703ULL] = (int32_T)((!(t849 != 0.0)) || (6.9 / (t849 == 0.0 ? 1.0E-16 :
    t849) + 0.002211858722000578 > 0.0));
  t713[704ULL] = 1;
  t713[705ULL] = 1;
  t713[706ULL] = (int32_T)((!(t849 != 0.0)) || ((t849 != 0.0) && (!(6.9 / (t849 ==
    0.0 ? 1.0E-16 : t849) + 0.002211858722000578 > 0.0))) || (pmf_log10(6.9 /
    (t849 == 0.0 ? 1.0E-16 : t849) + 0.002211858722000578) * pmf_log10(6.9 /
    (t849 == 0.0 ? 1.0E-16 : t849) + 0.002211858722000578) * 3.24 != 0.0));
  t713[707ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
     3.0000000000000004E-7 != 0.0);
  t713[708ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I * 4.5E-8 != 0.0);
  t713[709ULL] = 1;
  t713[710ULL] = 1;
  t713[711ULL] = 1;
  t713[712ULL] = 1;
  t713[713ULL] = (int32_T)(t829 * 0.0015 != 0.0);
  t713[714ULL] = (int32_T)(t891 / 2.0 != 0.0);
  t713[715ULL] = 1;
  t1203 = t891 / 2.0;
  t713[716ULL] = (int32_T)((!(t842 > t892 / 0.0019634954084936209 / (t1203 ==
    0.0 ? 1.0E-16 : t1203) / 30.0)) || (t842 != 0.0));
  t713[717ULL] = 1;
  t713[718ULL] = 1;
  t1203 = t891 / 2.0;
  t713[719ULL] = (int32_T)((!(t842 > t892 / 0.0019634954084936209 / (t1203 ==
    0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(t842 != 0.0)) || (t891 / 2.0 != 0.0));
  t713[720ULL] = (int32_T)(t850 != 0.0);
  t713[721ULL] = (int32_T)((!(t850 != 0.0)) || (6.9 / (t850 == 0.0 ? 1.0E-16 :
    t850) + 0.002211858722000578 > 0.0));
  t713[722ULL] = 1;
  t713[723ULL] = 1;
  t713[724ULL] = (int32_T)((!(t850 != 0.0)) || ((t850 != 0.0) && (!(6.9 / (t850 ==
    0.0 ? 1.0E-16 : t850) + 0.002211858722000578 > 0.0))) || (pmf_log10(6.9 /
    (t850 == 0.0 ? 1.0E-16 : t850) + 0.002211858722000578) * pmf_log10(6.9 /
    (t850 == 0.0 ? 1.0E-16 : t850) + 0.002211858722000578) * 3.24 != 0.0));
  t713[725ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I *
     3.0000000000000004E-7 != 0.0);
  t713[726ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_rho_I * 4.5E-8 != 0.0);
  t713[727ULL] = 1;
  t713[728ULL] = 1;
  t713[729ULL] = 1;
  t713[730ULL] = 1;
  t713[731ULL] = (int32_T)(t913 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[732ULL] = (int32_T)(intrm_sf_mf_138 != 0.0);
  t713[733ULL] = (int32_T)((!(intrm_sf_mf_138 != 0.0)) || (6.9 /
    (intrm_sf_mf_138 == 0.0 ? 1.0E-16 : intrm_sf_mf_138) + 9.0751776413883736E-6
    > 0.0));
  t713[734ULL] = 1;
  t713[735ULL] = 1;
  t713[736ULL] = (int32_T)((!(intrm_sf_mf_138 != 0.0)) || ((intrm_sf_mf_138 !=
    0.0) && (!(6.9 / (intrm_sf_mf_138 == 0.0 ? 1.0E-16 : intrm_sf_mf_138) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_138 == 0.0 ? 1.0E-16 : intrm_sf_mf_138) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_138 == 0.0 ? 1.0E-16 : intrm_sf_mf_138) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[737ULL] = (int32_T)(-intrm_sf_mf_13 < 663.67513503334737);
  t713[738ULL] = (int32_T)((t852 / 8.0 == t852 / 8.0) && (fabs(t852 / 8.0) !=
    pmf_get_inf()));
  t713[739ULL] = (int32_T)((!(t852 / 8.0 == t852 / 8.0)) || (!(fabs(t852 / 8.0)
    != pmf_get_inf())) || (t852 / 8.0 >= 0.0));
  t713[740ULL] = 1;
  t713[741ULL] = (int32_T)(t916 / 2.0 >= 0.0);
  t713[742ULL] = 1;
  t713[743ULL] = 1;
  t713[744ULL] = 1;
  t713[745ULL] = (int32_T)((!((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t852 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((t852 / 8.0 == t852 / 8.0)
    && (fabs(t852 / 8.0) != pmf_get_inf())));
  t713[746ULL] = (int32_T)((!((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t852 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t852 / 8.0 == t852 /
    8.0)) || (!(fabs(t852 / 8.0) != pmf_get_inf()))) || (t852 / 8.0 >= 0.0));
  t713[747ULL] = 1;
  t713[748ULL] = 1;
  t713[749ULL] = (int32_T)((!((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t852 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t916 / 2.0 >= 0.0));
  t713[750ULL] = (int32_T)((!((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t852 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t852 / 8.0 == t852 /
    8.0)) || (!(fabs(t852 / 8.0) != pmf_get_inf()))) || ((t852 / 8.0 == t852 /
    8.0) && (fabs(t852 / 8.0) != pmf_get_inf()) && (!(t852 / 8.0 >= 0.0))) ||
    (!(t916 / 2.0 >= 0.0)) || ((pmf_pow(t916 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t852 / 8.0) * 12.7 + 1.0 != 0.0));
  t713[751ULL] = 1;
  t713[752ULL] = 1;
  t713[753ULL] = 1;
  t713[754ULL] = 1;
  t713[755ULL] = 1;
  t713[756ULL] = 1;
  t713[757ULL] = 1;
  t713[758ULL] = (int32_T)(t916 / 2.0 != 0.0);
  t713[759ULL] = 1;
  t1203 = t916 / 2.0;
  t713[760ULL] = (int32_T)((!(intrm_sf_mf_137 > t925 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_137 != 0.0));
  t713[761ULL] = 1;
  t713[762ULL] = 1;
  t1203 = t916 / 2.0;
  t713[763ULL] = (int32_T)((!(intrm_sf_mf_137 > t925 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_137 != 0.0)) ||
    (t916 / 2.0 != 0.0));
  t713[764ULL] = (int32_T)(-intrm_sf_mf_144 < 663.67513503334737);
  t713[765ULL] = (int32_T)(t927 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[766ULL] = (int32_T)(intrm_sf_mf_149 != 0.0);
  t713[767ULL] = (int32_T)((!(intrm_sf_mf_149 != 0.0)) || (6.9 /
    (intrm_sf_mf_149 == 0.0 ? 1.0E-16 : intrm_sf_mf_149) + 9.0751776413883736E-6
    > 0.0));
  t713[768ULL] = 1;
  t713[769ULL] = 1;
  t713[770ULL] = (int32_T)((!(intrm_sf_mf_149 != 0.0)) || ((intrm_sf_mf_149 !=
    0.0) && (!(6.9 / (intrm_sf_mf_149 == 0.0 ? 1.0E-16 : intrm_sf_mf_149) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_149 == 0.0 ? 1.0E-16 : intrm_sf_mf_149) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_149 == 0.0 ? 1.0E-16 : intrm_sf_mf_149) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[771ULL] = (int32_T)((intrm_sf_mf_150 / 8.0 == intrm_sf_mf_150 / 8.0) &&
    (fabs(intrm_sf_mf_150 / 8.0) != pmf_get_inf()));
  t713[772ULL] = (int32_T)((!(intrm_sf_mf_150 / 8.0 == intrm_sf_mf_150 / 8.0)) ||
    (!(fabs(intrm_sf_mf_150 / 8.0) != pmf_get_inf())) || (intrm_sf_mf_150 / 8.0 >=
    0.0));
  t713[773ULL] = 1;
  t713[774ULL] = (int32_T)(t939 / 2.0 >= 0.0);
  t713[775ULL] = 1;
  t713[776ULL] = 1;
  t713[777ULL] = 1;
  t713[778ULL] = (int32_T)((!((pmf_pow(t939 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_150 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((intrm_sf_mf_150 / 8.0 == intrm_sf_mf_150 / 8.0) && (fabs(intrm_sf_mf_150 /
    8.0) != pmf_get_inf())));
  t713[779ULL] = (int32_T)((!((pmf_pow(t939 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_150 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_150 / 8.0 == intrm_sf_mf_150 / 8.0)) || (!(fabs
    (intrm_sf_mf_150 / 8.0) != pmf_get_inf()))) || (intrm_sf_mf_150 / 8.0 >= 0.0));
  t713[780ULL] = 1;
  t713[781ULL] = 1;
  t713[782ULL] = (int32_T)((!((pmf_pow(t939 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_150 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t939 / 2.0 >=
    0.0));
  t713[783ULL] = (int32_T)((!((pmf_pow(t939 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_150 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_150 / 8.0 == intrm_sf_mf_150 / 8.0)) || (!(fabs
    (intrm_sf_mf_150 / 8.0) != pmf_get_inf()))) || ((intrm_sf_mf_150 / 8.0 ==
    intrm_sf_mf_150 / 8.0) && (fabs(intrm_sf_mf_150 / 8.0) != pmf_get_inf()) &&
    (!(intrm_sf_mf_150 / 8.0 >= 0.0))) || (!(t939 / 2.0 >= 0.0)) || ((pmf_pow
    (t939 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_150 / 8.0) *
    12.7 + 1.0 != 0.0));
  t713[784ULL] = 1;
  t713[785ULL] = 1;
  t713[786ULL] = 1;
  t713[787ULL] = 1;
  t713[788ULL] = 1;
  t713[789ULL] = 1;
  t713[790ULL] = 1;
  t713[791ULL] = (int32_T)(t939 / 2.0 != 0.0);
  t713[792ULL] = 1;
  t1203 = t939 / 2.0;
  t713[793ULL] = (int32_T)((!(intrm_sf_mf_148 > t940 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_148 != 0.0));
  t713[794ULL] = 1;
  t713[795ULL] = 1;
  t1203 = t939 / 2.0;
  t713[796ULL] = (int32_T)((!(intrm_sf_mf_148 > t940 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_148 != 0.0)) ||
    (t939 / 2.0 != 0.0));
  t713[797ULL] = (int32_T)(-t854 < 663.67513503334737);
  t713[798ULL] = 1;
  t713[799ULL] = 1;
  t713[800ULL] = 1;
  t713[801ULL] = 1;
  t713[802ULL] = (int32_T)(t957 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[803ULL] = 1;
  t713[804ULL] = (int32_T)(t830 * 0.0019634954084936209 != 0.0);
  t713[805ULL] = (int32_T)(intrm_sf_mf_163 != 0.0);
  t713[806ULL] = (int32_T)((!(intrm_sf_mf_163 != 0.0)) || (6.9 /
    (intrm_sf_mf_163 == 0.0 ? 1.0E-16 : intrm_sf_mf_163) + 9.0751776413883736E-6
    > 0.0));
  t713[807ULL] = 1;
  t713[808ULL] = 1;
  t713[809ULL] = (int32_T)((!(intrm_sf_mf_163 != 0.0)) || ((intrm_sf_mf_163 !=
    0.0) && (!(6.9 / (intrm_sf_mf_163 == 0.0 ? 1.0E-16 : intrm_sf_mf_163) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_163 == 0.0 ? 1.0E-16 : intrm_sf_mf_163) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_163 == 0.0 ? 1.0E-16 : intrm_sf_mf_163) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[810ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[811ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[812ULL] = 1;
  t713[813ULL] = 1;
  t713[814ULL] = 1;
  t713[815ULL] = 1;
  t713[816ULL] = (int32_T)(t830 * 0.0019634954084936209 != 0.0);
  t713[817ULL] = (int32_T)(intrm_sf_mf_172 != 0.0);
  t713[818ULL] = (int32_T)((!(intrm_sf_mf_172 != 0.0)) || (6.9 /
    (intrm_sf_mf_172 == 0.0 ? 1.0E-16 : intrm_sf_mf_172) + 9.0751776413883736E-6
    > 0.0));
  t713[819ULL] = 1;
  t713[820ULL] = 1;
  t713[821ULL] = (int32_T)((!(intrm_sf_mf_172 != 0.0)) || ((intrm_sf_mf_172 !=
    0.0) && (!(6.9 / (intrm_sf_mf_172 == 0.0 ? 1.0E-16 : intrm_sf_mf_172) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_172 == 0.0 ? 1.0E-16 : intrm_sf_mf_172) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_172 == 0.0 ? 1.0E-16 : intrm_sf_mf_172) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[822ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[823ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[824ULL] = 1;
  t713[825ULL] = 1;
  t713[826ULL] = 1;
  t713[827ULL] = 1;
  t713[828ULL] = (int32_T)(t964 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[829ULL] = (int32_T)(intrm_sf_mf_181 != 0.0);
  t713[830ULL] = (int32_T)((!(intrm_sf_mf_181 != 0.0)) || (6.9 /
    (intrm_sf_mf_181 == 0.0 ? 1.0E-16 : intrm_sf_mf_181) + 9.0751776413883736E-6
    > 0.0));
  t713[831ULL] = 1;
  t713[832ULL] = 1;
  t713[833ULL] = (int32_T)((!(intrm_sf_mf_181 != 0.0)) || ((intrm_sf_mf_181 !=
    0.0) && (!(6.9 / (intrm_sf_mf_181 == 0.0 ? 1.0E-16 : intrm_sf_mf_181) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_181 == 0.0 ? 1.0E-16 : intrm_sf_mf_181) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_181 == 0.0 ? 1.0E-16 : intrm_sf_mf_181) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[834ULL] = (int32_T)((t856 / 8.0 == t856 / 8.0) && (fabs(t856 / 8.0) !=
    pmf_get_inf()));
  t713[835ULL] = (int32_T)((!(t856 / 8.0 == t856 / 8.0)) || (!(fabs(t856 / 8.0)
    != pmf_get_inf())) || (t856 / 8.0 >= 0.0));
  t713[836ULL] = 1;
  t713[837ULL] = (int32_T)(t965 / 2.0 >= 0.0);
  t713[838ULL] = 1;
  t713[839ULL] = 1;
  t713[840ULL] = 1;
  t713[841ULL] = (int32_T)((!((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t856 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((t856 / 8.0 == t856 / 8.0)
    && (fabs(t856 / 8.0) != pmf_get_inf())));
  t713[842ULL] = (int32_T)((!((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t856 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t856 / 8.0 == t856 /
    8.0)) || (!(fabs(t856 / 8.0) != pmf_get_inf()))) || (t856 / 8.0 >= 0.0));
  t713[843ULL] = 1;
  t713[844ULL] = 1;
  t713[845ULL] = (int32_T)((!((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t856 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t965 / 2.0 >= 0.0));
  t713[846ULL] = (int32_T)((!((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t856 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t856 / 8.0 == t856 /
    8.0)) || (!(fabs(t856 / 8.0) != pmf_get_inf()))) || ((t856 / 8.0 == t856 /
    8.0) && (fabs(t856 / 8.0) != pmf_get_inf()) && (!(t856 / 8.0 >= 0.0))) ||
    (!(t965 / 2.0 >= 0.0)) || ((pmf_pow(t965 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t856 / 8.0) * 12.7 + 1.0 != 0.0));
  t713[847ULL] = 1;
  t713[848ULL] = 1;
  t713[849ULL] = 1;
  t713[850ULL] = 1;
  t713[851ULL] = 1;
  t713[852ULL] = 1;
  t713[853ULL] = 1;
  t713[854ULL] = (int32_T)(t965 / 2.0 != 0.0);
  t713[855ULL] = 1;
  t1203 = t965 / 2.0;
  t713[856ULL] = (int32_T)((!(intrm_sf_mf_152 > t976 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_152 != 0.0));
  t713[857ULL] = 1;
  t713[858ULL] = 1;
  t1203 = t965 / 2.0;
  t713[859ULL] = (int32_T)((!(intrm_sf_mf_152 > t976 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_152 != 0.0)) ||
    (t965 / 2.0 != 0.0));
  t713[860ULL] = (int32_T)(-t857 < 663.67513503334737);
  t713[861ULL] = (int32_T)(intrm_sf_mf_18 != 0.0);
  t713[862ULL] = (int32_T)((!(intrm_sf_mf_18 != 0.0)) || (6.9 / (intrm_sf_mf_18 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_18) + 9.0751776413883736E-6 > 0.0));
  t713[863ULL] = 1;
  t713[864ULL] = 1;
  t713[865ULL] = (int32_T)((!(intrm_sf_mf_18 != 0.0)) || ((intrm_sf_mf_18 != 0.0)
    && (!(6.9 / (intrm_sf_mf_18 == 0.0 ? 1.0E-16 : intrm_sf_mf_18) +
          9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 / (intrm_sf_mf_18 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_18) + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (intrm_sf_mf_18 == 0.0 ? 1.0E-16 : intrm_sf_mf_18) + 9.0751776413883736E-6) *
    3.24 != 0.0));
  t713[866ULL] = (int32_T)(t987 / 2.0 * 0.0019634954084936209 != 0.0);
  t713[867ULL] = (int32_T)(intrm_sf_mf_192 != 0.0);
  t713[868ULL] = (int32_T)((!(intrm_sf_mf_192 != 0.0)) || (6.9 /
    (intrm_sf_mf_192 == 0.0 ? 1.0E-16 : intrm_sf_mf_192) + 9.0751776413883736E-6
    > 0.0));
  t713[869ULL] = 1;
  t713[870ULL] = 1;
  t713[871ULL] = (int32_T)((!(intrm_sf_mf_192 != 0.0)) || ((intrm_sf_mf_192 !=
    0.0) && (!(6.9 / (intrm_sf_mf_192 == 0.0 ? 1.0E-16 : intrm_sf_mf_192) +
               9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (intrm_sf_mf_192 == 0.0 ? 1.0E-16 : intrm_sf_mf_192) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_192 == 0.0 ? 1.0E-16 : intrm_sf_mf_192) +
                9.0751776413883736E-6) * 3.24 != 0.0));
  t713[872ULL] = (int32_T)((t858 / 8.0 == t858 / 8.0) && (fabs(t858 / 8.0) !=
    pmf_get_inf()));
  t713[873ULL] = (int32_T)((!(t858 / 8.0 == t858 / 8.0)) || (!(fabs(t858 / 8.0)
    != pmf_get_inf())) || (t858 / 8.0 >= 0.0));
  t713[874ULL] = 1;
  t713[875ULL] = (int32_T)(t991 / 2.0 >= 0.0);
  t713[876ULL] = 1;
  t713[877ULL] = 1;
  t713[878ULL] = 1;
  t713[879ULL] = (int32_T)((!((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t858 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((t858 / 8.0 == t858 / 8.0)
    && (fabs(t858 / 8.0) != pmf_get_inf())));
  t713[880ULL] = (int32_T)((!((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t858 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t858 / 8.0 == t858 /
    8.0)) || (!(fabs(t858 / 8.0) != pmf_get_inf()))) || (t858 / 8.0 >= 0.0));
  t713[881ULL] = 1;
  t713[882ULL] = 1;
  t713[883ULL] = (int32_T)((!((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t858 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t991 / 2.0 >= 0.0));
  t713[884ULL] = (int32_T)((!((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t858 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((!(t858 / 8.0 == t858 /
    8.0)) || (!(fabs(t858 / 8.0) != pmf_get_inf()))) || ((t858 / 8.0 == t858 /
    8.0) && (fabs(t858 / 8.0) != pmf_get_inf()) && (!(t858 / 8.0 >= 0.0))) ||
    (!(t991 / 2.0 >= 0.0)) || ((pmf_pow(t991 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(t858 / 8.0) * 12.7 + 1.0 != 0.0));
  t713[885ULL] = 1;
  t713[886ULL] = 1;
  t713[887ULL] = 1;
  t713[888ULL] = 1;
  t713[889ULL] = 1;
  t713[890ULL] = 1;
  t713[891ULL] = 1;
  t713[892ULL] = (int32_T)(t991 / 2.0 != 0.0);
  t713[893ULL] = 1;
  t1203 = t991 / 2.0;
  t713[894ULL] = (int32_T)((!(intrm_sf_mf_191 > t999 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_191 != 0.0));
  t713[895ULL] = 1;
  t713[896ULL] = 1;
  t1203 = t991 / 2.0;
  t713[897ULL] = (int32_T)((!(intrm_sf_mf_191 > t999 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_191 != 0.0)) ||
    (t991 / 2.0 != 0.0));
  t713[898ULL] = (int32_T)(-t861 < 663.67513503334737);
  t713[899ULL] = (int32_T)((intrm_sf_mf_19 / 8.0 == intrm_sf_mf_19 / 8.0) &&
    (fabs(intrm_sf_mf_19 / 8.0) != pmf_get_inf()));
  t713[900ULL] = (int32_T)((!(intrm_sf_mf_19 / 8.0 == intrm_sf_mf_19 / 8.0)) ||
    (!(fabs(intrm_sf_mf_19 / 8.0) != pmf_get_inf())) || (intrm_sf_mf_19 / 8.0 >=
    0.0));
  t713[901ULL] = 1;
  t713[902ULL] = (int32_T)(t1004 / 2.0 >= 0.0);
  t713[903ULL] = 1;
  t713[904ULL] = 1;
  t713[905ULL] = 1;
  t713[906ULL] = (int32_T)((!((pmf_pow(t1004 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || ((intrm_sf_mf_19 /
    8.0 == intrm_sf_mf_19 / 8.0) && (fabs(intrm_sf_mf_19 / 8.0) != pmf_get_inf())));
  t713[907ULL] = (int32_T)((!((pmf_pow(t1004 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_19 / 8.0 == intrm_sf_mf_19 / 8.0)) || (!(fabs(intrm_sf_mf_19
    / 8.0) != pmf_get_inf()))) || (intrm_sf_mf_19 / 8.0 >= 0.0));
  t713[908ULL] = 1;
  t713[909ULL] = 1;
  t713[910ULL] = (int32_T)((!((pmf_pow(t1004 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) || (t1004 / 2.0 >=
    0.0));
  t713[911ULL] = (int32_T)((!((pmf_pow(t1004 / 2.0, 0.66666666666666663) - 1.0) *
    pmf_sqrt(intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 >= 1.0E-6)) ||
    ((!(intrm_sf_mf_19 / 8.0 == intrm_sf_mf_19 / 8.0)) || (!(fabs(intrm_sf_mf_19
    / 8.0) != pmf_get_inf()))) || ((intrm_sf_mf_19 / 8.0 == intrm_sf_mf_19 / 8.0)
    && (fabs(intrm_sf_mf_19 / 8.0) != pmf_get_inf()) && (!(intrm_sf_mf_19 / 8.0 >=
    0.0))) || (!(t1004 / 2.0 >= 0.0)) || ((pmf_pow(t1004 / 2.0,
    0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_19 / 8.0) * 12.7 + 1.0 !=
    0.0));
  t713[912ULL] = 1;
  t713[913ULL] = 1;
  t713[914ULL] = 1;
  t713[915ULL] = 1;
  t713[916ULL] = 1;
  t713[917ULL] = 1;
  t713[918ULL] = 1;
  t713[919ULL] = 1;
  t713[920ULL] = (int32_T)(t831 * 0.0019634954084936209 != 0.0);
  t713[921ULL] = (int32_T)(t862 != 0.0);
  t713[922ULL] = (int32_T)((!(t862 != 0.0)) || (6.9 / (t862 == 0.0 ? 1.0E-16 :
    t862) + 9.0751776413883736E-6 > 0.0));
  t713[923ULL] = 1;
  t713[924ULL] = 1;
  t713[925ULL] = (int32_T)((!(t862 != 0.0)) || ((t862 != 0.0) && (!(6.9 / (t862 ==
    0.0 ? 1.0E-16 : t862) + 9.0751776413883736E-6 > 0.0))) || (pmf_log10(6.9 /
    (t862 == 0.0 ? 1.0E-16 : t862) + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (t862 == 0.0 ? 1.0E-16 : t862) + 9.0751776413883736E-6) * 3.24 != 0.0));
  t713[926ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[927ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[928ULL] = 1;
  t713[929ULL] = 1;
  t713[930ULL] = 1;
  t713[931ULL] = 1;
  t713[932ULL] = (int32_T)(t831 * 0.0019634954084936209 != 0.0);
  t713[933ULL] = (int32_T)(U_idx_7 != 0.0);
  t713[934ULL] = (int32_T)((!(U_idx_7 != 0.0)) || (6.9 / (U_idx_7 == 0.0 ?
    1.0E-16 : U_idx_7) + 9.0751776413883736E-6 > 0.0));
  t713[935ULL] = 1;
  t713[936ULL] = 1;
  t713[937ULL] = (int32_T)((!(U_idx_7 != 0.0)) || ((U_idx_7 != 0.0) && (!(6.9 /
    (U_idx_7 == 0.0 ? 1.0E-16 : U_idx_7) + 9.0751776413883736E-6 > 0.0))) ||
    (pmf_log10(6.9 / (U_idx_7 == 0.0 ? 1.0E-16 : U_idx_7) +
               9.0751776413883736E-6) * pmf_log10(6.9 / (U_idx_7 == 0.0 ?
    1.0E-16 : U_idx_7) + 9.0751776413883736E-6) * 3.24 != 0.0));
  t713[938ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[939ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[940ULL] = 1;
  t713[941ULL] = 1;
  t713[942ULL] = 1;
  t713[943ULL] = 1;
  t713[944ULL] = 1;
  t713[945ULL] = 1;
  t713[946ULL] = 1;
  t713[947ULL] = 1;
  t713[948ULL] = 1;
  t713[949ULL] = 1;
  t713[950ULL] = (int32_T)((X[4ULL] * X[4ULL] + 1.4412638338049421E-12 == X[4ULL]
    * X[4ULL] + 1.4412638338049421E-12) && (fabs(X[4ULL] * X[4ULL] +
    1.4412638338049421E-12) != pmf_get_inf()));
  t713[951ULL] = (int32_T)((!(X[4ULL] * X[4ULL] + 1.4412638338049421E-12 == X
    [4ULL] * X[4ULL] + 1.4412638338049421E-12)) || (!(fabs(X[4ULL] * X[4ULL] +
    1.4412638338049421E-12) != pmf_get_inf())) || (X[4ULL] * X[4ULL] +
    1.4412638338049421E-12 >= 0.0));
  t713[952ULL] = (int32_T)(t1004 / 2.0 != 0.0);
  t713[953ULL] = 1;
  t1203 = t1004 / 2.0;
  t713[954ULL] = (int32_T)((!(intrm_sf_mf_162 > U_idx_6 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (intrm_sf_mf_162 != 0.0));
  t713[955ULL] = 1;
  t713[956ULL] = 1;
  t1203 = t1004 / 2.0;
  t713[957ULL] = (int32_T)((!(intrm_sf_mf_162 > U_idx_6 / 0.0019634954084936209 /
    (t1203 == 0.0 ? 1.0E-16 : t1203) / 30.0)) || (!(intrm_sf_mf_162 != 0.0)) ||
    (t1004 / 2.0 != 0.0));
  t713[958ULL] = 1;
  t713[959ULL] = 1;
  t713[960ULL] = (int32_T)((X[35ULL] * X[35ULL] + 1.4412638338049421E-12 == X
    [35ULL] * X[35ULL] + 1.4412638338049421E-12) && (fabs(X[35ULL] * X[35ULL] +
    1.4412638338049421E-12) != pmf_get_inf()));
  t713[961ULL] = (int32_T)((!(X[35ULL] * X[35ULL] + 1.4412638338049421E-12 == X
    [35ULL] * X[35ULL] + 1.4412638338049421E-12)) || (!(fabs(X[35ULL] * X[35ULL]
    + 1.4412638338049421E-12) != pmf_get_inf())) || (X[35ULL] * X[35ULL] +
    1.4412638338049421E-12 >= 0.0));
  t713[962ULL] = (int32_T)(intrm_sf_mf_239 != 0.0);
  t713[963ULL] = 1;
  t713[964ULL] = (int32_T)(intrm_sf_mf_240 != 0.0);
  t713[965ULL] = 1;
  t713[966ULL] = (int32_T)(intrm_sf_mf_239 != 0.0);
  t713[967ULL] = 1;
  t713[968ULL] = (int32_T)(intrm_sf_mf_240 != 0.0);
  t713[969ULL] = 1;
  t713[970ULL] = (int32_T)(intrm_sf_mf_239 != 0.0);
  t713[971ULL] = (int32_T)((!(intrm_sf_mf_239 != 0.0)) || (X[89ULL] != 0.0));
  t713[972ULL] = (int32_T)(intrm_sf_mf_240 != 0.0);
  t713[973ULL] = (int32_T)((!(intrm_sf_mf_240 != 0.0)) || (X[90ULL] != 0.0));
  t713[974ULL] = (int32_T)(-U_idx_2 < 663.67513503334737);
  t713[975ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 != 0.0);
  t713[976ULL] = (int32_T)(intrm_sf_mf_249 != 0.0);
  t713[977ULL] = 1;
  t713[978ULL] = 1;
  t713[979ULL] = 1;
  t713[980ULL] = 1;
  t713[981ULL] = 1;
  t713[982ULL] = (int32_T)(t810 * 0.0019634954084936209 != 0.0);
  t713[983ULL] = (int32_T)(U_idx_3 != 0.0);
  t713[984ULL] = (int32_T)((!(U_idx_3 != 0.0)) || (6.9 / (U_idx_3 == 0.0 ?
    1.0E-16 : U_idx_3) + 9.0751776413883736E-6 > 0.0));
  t713[985ULL] = 1;
  t713[986ULL] = 1;
  t713[987ULL] = (int32_T)((!(U_idx_3 != 0.0)) || ((U_idx_3 != 0.0) && (!(6.9 /
    (U_idx_3 == 0.0 ? 1.0E-16 : U_idx_3) + 9.0751776413883736E-6 > 0.0))) ||
    (pmf_log10(6.9 / (U_idx_3 == 0.0 ? 1.0E-16 : U_idx_3) +
               9.0751776413883736E-6) * pmf_log10(6.9 / (U_idx_3 == 0.0 ?
    1.0E-16 : U_idx_3) + 9.0751776413883736E-6) * 3.24 != 0.0));
  t713[988ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[989ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[990ULL] = 1;
  t713[991ULL] = 1;
  t713[992ULL] = 1;
  t713[993ULL] = 1;
  t713[994ULL] = (int32_T)(t810 * 0.0019634954084936209 != 0.0);
  t713[995ULL] = (int32_T)(U_idx_1 != 0.0);
  t713[996ULL] = (int32_T)((!(U_idx_1 != 0.0)) || (6.9 / (U_idx_1 == 0.0 ?
    1.0E-16 : U_idx_1) + 9.0751776413883736E-6 > 0.0));
  t713[997ULL] = 1;
  t713[998ULL] = 1;
  t713[999ULL] = (int32_T)((!(U_idx_1 != 0.0)) || ((U_idx_1 != 0.0) && (!(6.9 /
    (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1) + 9.0751776413883736E-6 > 0.0))) ||
    (pmf_log10(6.9 / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1) +
               9.0751776413883736E-6) * pmf_log10(6.9 / (U_idx_1 == 0.0 ?
    1.0E-16 : U_idx_1) + 9.0751776413883736E-6) * 3.24 != 0.0));
  t713[1000ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_rho_I *
    7.8484637847008924E-5 != 0.0);
  t713[1001ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_rho_I *
    1.0900644145417907E-6 != 0.0);
  t713[1002ULL] = 1;
  t713[1003ULL] = 1;
  t713[1004ULL] = 1;
  t713[1005ULL] = 1;
  t713[1006ULL] = (int32_T)(t828 * 0.00075 != 0.0);
  t713[1007ULL] = (int32_T)(t823 != 0.0);
  t713[1008ULL] = (int32_T)((!(t823 != 0.0)) || (6.9 / (t823 == 0.0 ? 1.0E-16 :
    t823) + 0.00069701528436089772 > 0.0));
  t713[1009ULL] = 1;
  t713[1010ULL] = 1;
  t713[1011ULL] = (int32_T)((!(t823 != 0.0)) || ((t823 != 0.0) && (!(6.9 / (t823
    == 0.0 ? 1.0E-16 : t823) + 0.00069701528436089772 > 0.0))) || (pmf_log10(6.9
    / (t823 == 0.0 ? 1.0E-16 : t823) + 0.00069701528436089772) * pmf_log10(6.9 /
    (t823 == 0.0 ? 1.0E-16 : t823) + 0.00069701528436089772) * 3.24 != 0.0));
  t713[1012ULL] = 1;
  t713[1013ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 * 0.0015 !=
     0.0);
  t713[1014ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 * 1.125E-6
     != 0.0);
  t713[1015ULL] = 1;
  t713[1016ULL] = 1;
  t713[1017ULL] = 1;
  t713[1018ULL] = 1;
  t713[1019ULL] = (int32_T)(t828 * 0.00075 != 0.0);
  t713[1020ULL] = (int32_T)(t826 != 0.0);
  t713[1021ULL] = (int32_T)((!(t826 != 0.0)) || (6.9 / (t826 == 0.0 ? 1.0E-16 :
    t826) + 0.00069701528436089772 > 0.0));
  t713[1022ULL] = 1;
  t713[1023ULL] = 1;
  t713[1024ULL] = (int32_T)((!(t826 != 0.0)) || ((t826 != 0.0) && (!(6.9 / (t826
    == 0.0 ? 1.0E-16 : t826) + 0.00069701528436089772 > 0.0))) || (pmf_log10(6.9
    / (t826 == 0.0 ? 1.0E-16 : t826) + 0.00069701528436089772) * pmf_log10(6.9 /
    (t826 == 0.0 ? 1.0E-16 : t826) + 0.00069701528436089772) * 3.24 != 0.0));
  t713[1025ULL] = 1;
  t713[1026ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 * 0.0015 !=
     0.0);
  t713[1027ULL] = (int32_T)
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 * 1.125E-6
     != 0.0);
  t713[1028ULL] = 1;
  t713[1029ULL] = 1;
  t713[1030ULL] = 1;
  t713[1031ULL] = 1;
  t713[1032ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_beta_I != 0.0);
  t713[1033ULL] = (int32_T)(intrm_sf_mf_249 != 0.0);
  t713[1034ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_beta_I != 0.0);
  t713[1035ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_beta_I != 0.0);
  t713[1036ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_beta_I != 0.0);
  t713[1037ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[1038ULL] = (int32_T)(Basic_Peripherals_Aux_TCP_convection_A_mdot_abs !=
    0.0);
  t713[1039ULL] = 1;
  t713[1040ULL] = 1;
  t713[1041ULL] = (int32_T)((t1214 * t1214 + 0.13433628212593846 == t1214 *
    t1214 + 0.13433628212593846) && (fabs(t1214 * t1214 + 0.13433628212593846)
    != pmf_get_inf()));
  t713[1042ULL] = (int32_T)((!(t1214 * t1214 + 0.13433628212593846 == t1214 *
    t1214 + 0.13433628212593846)) || (!(fabs(t1214 * t1214 + 0.13433628212593846)
    != pmf_get_inf())) || (t1214 * t1214 + 0.13433628212593846 >= 0.0));
  t713[1043ULL] = 1;
  t713[1044ULL] = (int32_T)
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 != 0.0);
  t713[1045ULL] = (int32_T)
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0);
  t713[1046ULL] = (int32_T)
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0);
  t713[1047ULL] = 1;
  t713[1048ULL] = 1;
  t713[1049ULL] = 1;
  t713[1050ULL] = 1;
  t713[1051ULL] = (int32_T)(Basic_Peripherals_Gate_Valve_TL_valve_area *
    Basic_Peripherals_Gate_Valve_TL_valve_area *
    Basic_Peripherals_Gate_Valve_TL_rho_avg * 0.97999999999999987 != 0.0);
  t713[1052ULL] = 1;
  t713[1053ULL] = 1;
  t713[1054ULL] = (int32_T)((1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) && (fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()));
  t713[1055ULL] = (int32_T)((!(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51)) || (!(fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf())) ||
    (1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
     Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 >= 0.0));
  t713[1056ULL] = 1;
  t713[1057ULL] = 1;
  t713[1058ULL] = (int32_T)((1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) && (fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()));
  t713[1059ULL] = (int32_T)((!(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51)) || (!(fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf())) ||
    (1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
     Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 >= 0.0));
  t713[1060ULL] = (int32_T)((!(Basic_Peripherals_Gate_Valve_TL_valve_area *
    Basic_Peripherals_Gate_Valve_TL_valve_area *
    Basic_Peripherals_Gate_Valve_TL_rho_avg * 0.97999999999999987 != 0.0)) || ((
    !(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
      Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51)) || (!(fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()))) ||
    ((1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
      Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) && (fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()) &&
     (!(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
        Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 >= 0.0))) || ((!(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51)) || (!(fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()))) ||
    ((1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 == 1.0 -
      Basic_Peripherals_Gate_Valve_TL_area_ratio *
      Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) && (fabs(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != pmf_get_inf()) &&
     (!(1.0 - Basic_Peripherals_Gate_Valve_TL_area_ratio *
        Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51 >= 0.0))) ||
    (Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.7 + pmf_sqrt(1.0 -
    Basic_Peripherals_Gate_Valve_TL_area_ratio *
    Basic_Peripherals_Gate_Valve_TL_area_ratio * 0.51) != 0.0));
  t713[1061ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs !=
    0.0);
  t713[1062ULL] = (int32_T)(Basic_Peripherals_Pipe_TL3_convection_B_mdot_abs !=
    0.0);
  t713[1063ULL] = (int32_T)
    (Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs != 0.0);
  t713[1064ULL] = (int32_T)(t811 != 0.0);
  t713[1065ULL] = (int32_T)
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0);
  t713[1066ULL] = 1;
  t713[1067ULL] = 1;
  t713[1068ULL] = 1;
  t713[1069ULL] = 1;
  t713[1070ULL] = (int32_T)((X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[57ULL] * X[57ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()));
  t713[1071ULL] = (int32_T)((!(X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[57ULL] * X
    [57ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || (X
    [57ULL] * X[57ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0));
  t713[1072ULL] = (int32_T)((!(X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[57ULL] * X
    [57ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || ((X
    [57ULL] * X[57ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[57ULL] * X[57ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[57ULL] * X[57ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()) && (!(X
    [57ULL] * X[57ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1073ULL] = 1;
  t713[1074ULL] = 1;
  t713[1075ULL] = 1;
  t713[1076ULL] = 1;
  t713[1077ULL] = (int32_T)((X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()));
  t713[1078ULL] = (int32_T)((!(X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[4ULL] * X[4ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || (X
    [4ULL] * X[4ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0));
  t713[1079ULL] = (int32_T)((!(X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[4ULL] * X[4ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || ((X
    [4ULL] * X[4ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[4ULL] * X[4ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()) && (!(X
    [4ULL] * X[4ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1080ULL] = 1;
  t713[1081ULL] = 1;
  t713[1082ULL] = 1;
  t713[1083ULL] = 1;
  t713[1084ULL] = (int32_T)((X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[46ULL] * X[46ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()));
  t713[1085ULL] = (int32_T)((!(X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[46ULL] * X
    [46ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || (X
    [46ULL] * X[46ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0));
  t713[1086ULL] = (int32_T)((!(X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold)) || (!(fabs(X[46ULL] * X
    [46ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf())) || ((X
    [46ULL] * X[46ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold == X[46ULL] * X[46ULL] +
    Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) && (fabs(X[46ULL] * X[46ULL]
    + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold) != pmf_get_inf()) && (!(X
    [46ULL] * X[46ULL] + Basic_Peripherals_T_Junction_TL_mdot_threshold *
    Basic_Peripherals_T_Junction_TL_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1087ULL] = (int32_T)(t812 != 0.0);
  t713[1088ULL] = (int32_T)(t813 != 0.0);
  t713[1089ULL] = (int32_T)
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs != 0.0);
  t713[1090ULL] = 1;
  t713[1091ULL] = 1;
  t713[1092ULL] = 1;
  t713[1093ULL] = 1;
  t713[1094ULL] = (int32_T)((X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[29ULL] * X[29ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()));
  t713[1095ULL] = (int32_T)((!(X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[29ULL] * X
    [29ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || (X
    [29ULL] * X[29ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0));
  t713[1096ULL] = (int32_T)((!(X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[29ULL] * X
    [29ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || ((X
    [29ULL] * X[29ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[29ULL] * X[29ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[29ULL] * X[29ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()) && (!(X
    [29ULL] * X[29ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL1_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1097ULL] = 1;
  t713[1098ULL] = 1;
  t713[1099ULL] = 1;
  t713[1100ULL] = 1;
  t713[1101ULL] = (int32_T)((X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[8ULL] * X[8ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()));
  t713[1102ULL] = (int32_T)((!(X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[8ULL] * X
    [8ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || (X
    [8ULL] * X[8ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0));
  t713[1103ULL] = (int32_T)((!(X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[8ULL] * X
    [8ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || ((X
    [8ULL] * X[8ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[8ULL] * X[8ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[8ULL] * X[8ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()) && (!(X
    [8ULL] * X[8ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL1_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1104ULL] = 1;
  t713[1105ULL] = 1;
  t713[1106ULL] = 1;
  t713[1107ULL] = 1;
  t713[1108ULL] = (int32_T)((X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[9ULL] * X[9ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()));
  t713[1109ULL] = (int32_T)((!(X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[9ULL] * X
    [9ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || (X
    [9ULL] * X[9ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0));
  t713[1110ULL] = (int32_T)((!(X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold)) || (!(fabs(X[9ULL] * X
    [9ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf())) || ((X
    [9ULL] * X[9ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold == X[9ULL] * X[9ULL] +
    Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) && (fabs(X[9ULL] * X[9ULL]
    + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold) != pmf_get_inf()) && (!(X
    [9ULL] * X[9ULL] + Basic_Peripherals_T_Junction_TL1_mdot_threshold *
    Basic_Peripherals_T_Junction_TL1_mdot_threshold >= 0.0))) ||
    (Basic_Peripherals_T_Junction_TL1_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1111ULL] = (int32_T)(intrm_sf_mf_239 != 0.0);
  t713[1112ULL] = (int32_T)(intrm_sf_mf_240 != 0.0);
  t713[1113ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect0 != 0.0);
  t713[1114ULL] = (int32_T)
    (Basic_Stack_Heat_Emulation_Fuel_Cell_Coolant_Channels_convect6 != 0.0);
  t713[1115ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs
    != 0.0);
  t713[1116ULL] = (int32_T)(Subsystem_Reference_Pipe_TL2_convection_B_mdot_abs
    != 0.0);
  t713[1117ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs
    != 0.0);
  t713[1118ULL] = (int32_T)(Subsystem_Reference_Pipe_TL4_convection_B_mdot_abs
    != 0.0);
  t713[1119ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs
    != 0.0);
  t713[1120ULL] = (int32_T)(Subsystem_Reference_TCP_6812_convection_A_mdot_abs
    != 0.0);
  t713[1121ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[1122ULL] = (int32_T)
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs != 0.0);
  t713[1123ULL] = 1;
  t713[1124ULL] = 1;
  t713[1125ULL] = 1;
  t713[1126ULL] = 1;
  t713[1127ULL] = 1;
  t713[1128ULL] = (int32_T)(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c >= 0.0);
  t713[1129ULL] = (int32_T)((!(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c >= 0.0)) || (pmf_sqrt
    (pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff *
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff * 1.0E+10 +
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c *
              Subsystem_Reference_TCV_VL6810_orifice_AT_p_diff_c)) != 0.0));
  t713[1130ULL] = 1;
  t713[1131ULL] = 1;
  t713[1132ULL] = (int32_T)(1.0 -
    Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio *
    Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio != 0.0);
  t713[1133ULL] = 1;
  t1214 = 1.0 - Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio *
    Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio;
  t713[1134ULL] = (int32_T)((!(1.0 -
    Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio *
    Subsystem_Reference_TCV_VL6810_orifice_AT_area_ratio != 0.0)) || (t833 * 2.0
    / (t1214 == 0.0 ? 1.0E-16 : t1214) >= 0.0));
  t713[1135ULL] = (int32_T)(t813 != 0.0);
  t713[1136ULL] = (int32_T)(t813 != 0.0);
  t713[1137ULL] = 1;
  t713[1138ULL] = 1;
  t713[1139ULL] = 1;
  t713[1140ULL] = 1;
  t713[1141ULL] = 1;
  t713[1142ULL] = (int32_T)(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c >= 0.0);
  t713[1143ULL] = (int32_T)((!(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 +
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c *
    Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c >= 0.0)) || (pmf_sqrt
    (pmf_sqrt(Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff *
              Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff * 1.0E+10 +
              Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c *
              Subsystem_Reference_TCV_VL6810_orifice_PA_p_diff_c)) != 0.0));
  t713[1144ULL] = 1;
  t713[1145ULL] = 1;
  t713[1146ULL] = (int32_T)(1.0 - t835 * t835 != 0.0);
  t713[1147ULL] = 1;
  t1214 = 1.0 - t835 * t835;
  t713[1148ULL] = (int32_T)((!(1.0 - t835 * t835 != 0.0)) || (t837 * 2.0 /
    (t1214 == 0.0 ? 1.0E-16 : t1214) >= 0.0));
  t713[1149ULL] = (int32_T)(t838 != 0.0);
  t713[1150ULL] = (int32_T)(t841 != 0.0);
  t713[1151ULL] = (int32_T)
    (Subsystem_Reference_T_Junction_TL_convection_C_mdot_abs != 0.0);
  t713[1152ULL] = 1;
  t713[1153ULL] = 1;
  t713[1154ULL] = 1;
  t713[1155ULL] = 1;
  t713[1156ULL] = (int32_T)((X[101ULL] * X[101ULL] + t839 * t839 == X[101ULL] *
    X[101ULL] + t839 * t839) && (fabs(X[101ULL] * X[101ULL] + t839 * t839) !=
    pmf_get_inf()));
  t713[1157ULL] = (int32_T)((!(X[101ULL] * X[101ULL] + t839 * t839 == X[101ULL] *
    X[101ULL] + t839 * t839)) || (!(fabs(X[101ULL] * X[101ULL] + t839 * t839) !=
    pmf_get_inf())) || (X[101ULL] * X[101ULL] + t839 * t839 >= 0.0));
  t713[1158ULL] = (int32_T)((!(X[101ULL] * X[101ULL] + t839 * t839 == X[101ULL] *
    X[101ULL] + t839 * t839)) || (!(fabs(X[101ULL] * X[101ULL] + t839 * t839) !=
    pmf_get_inf())) || ((X[101ULL] * X[101ULL] + t839 * t839 == X[101ULL] * X
    [101ULL] + t839 * t839) && (fabs(X[101ULL] * X[101ULL] + t839 * t839) !=
    pmf_get_inf()) && (!(X[101ULL] * X[101ULL] + t839 * t839 >= 0.0))) ||
    (Subsystem_Reference_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1159ULL] = 1;
  t713[1160ULL] = 1;
  t713[1161ULL] = 1;
  t713[1162ULL] = 1;
  t713[1163ULL] = (int32_T)((X[7ULL] * X[7ULL] + t839 * t839 == X[7ULL] * X[7ULL]
    + t839 * t839) && (fabs(X[7ULL] * X[7ULL] + t839 * t839) != pmf_get_inf()));
  t713[1164ULL] = (int32_T)((!(X[7ULL] * X[7ULL] + t839 * t839 == X[7ULL] * X
    [7ULL] + t839 * t839)) || (!(fabs(X[7ULL] * X[7ULL] + t839 * t839) !=
    pmf_get_inf())) || (X[7ULL] * X[7ULL] + t839 * t839 >= 0.0));
  t713[1165ULL] = (int32_T)((!(X[7ULL] * X[7ULL] + t839 * t839 == X[7ULL] * X
    [7ULL] + t839 * t839)) || (!(fabs(X[7ULL] * X[7ULL] + t839 * t839) !=
    pmf_get_inf())) || ((X[7ULL] * X[7ULL] + t839 * t839 == X[7ULL] * X[7ULL] +
    t839 * t839) && (fabs(X[7ULL] * X[7ULL] + t839 * t839) != pmf_get_inf()) &&
                        (!(X[7ULL] * X[7ULL] + t839 * t839 >= 0.0))) ||
    (Subsystem_Reference_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  t713[1166ULL] = 1;
  t713[1167ULL] = 1;
  t713[1168ULL] = 1;
  t713[1169ULL] = 1;
  t713[1170ULL] = (int32_T)((X[16ULL] * X[16ULL] + t839 * t839 == X[16ULL] * X
    [16ULL] + t839 * t839) && (fabs(X[16ULL] * X[16ULL] + t839 * t839) !=
    pmf_get_inf()));
  t713[1171ULL] = (int32_T)((!(X[16ULL] * X[16ULL] + t839 * t839 == X[16ULL] *
    X[16ULL] + t839 * t839)) || (!(fabs(X[16ULL] * X[16ULL] + t839 * t839) !=
    pmf_get_inf())) || (X[16ULL] * X[16ULL] + t839 * t839 >= 0.0));
  t713[1172ULL] = (int32_T)((!(X[16ULL] * X[16ULL] + t839 * t839 == X[16ULL] *
    X[16ULL] + t839 * t839)) || (!(fabs(X[16ULL] * X[16ULL] + t839 * t839) !=
    pmf_get_inf())) || ((X[16ULL] * X[16ULL] + t839 * t839 == X[16ULL] * X[16ULL]
    + t839 * t839) && (fabs(X[16ULL] * X[16ULL] + t839 * t839) != pmf_get_inf())
                        && (!(X[16ULL] * X[16ULL] + t839 * t839 >= 0.0))) ||
    (Subsystem_Reference_T_Junction_TL_rho_avg * 3.8553142191755308E-6 != 0.0));
  for (b = 0; b < 1173; b++) {
    out.mX[b] = t713[b];
  }

  (void)LC;
  (void)t1216;
  return 0;
}
