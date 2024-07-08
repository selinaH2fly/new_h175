/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_f.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_f(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t1712, NeDsMethodOutput *t1713)
{
  ETTS0 ab_efOut;
  ETTS0 ac_efOut;
  ETTS0 ad_efOut;
  ETTS0 af_efOut;
  ETTS0 ag_efOut;
  ETTS0 ah_efOut;
  ETTS0 ai_efOut;
  ETTS0 aj_efOut;
  ETTS0 b_efOut;
  ETTS0 bb_efOut;
  ETTS0 bc_efOut;
  ETTS0 bd_efOut;
  ETTS0 bg_efOut;
  ETTS0 cf_efOut;
  ETTS0 ch_efOut;
  ETTS0 ci_efOut;
  ETTS0 cj_efOut;
  ETTS0 d_efOut;
  ETTS0 db_efOut;
  ETTS0 dd_efOut;
  ETTS0 df_efOut;
  ETTS0 dh_efOut;
  ETTS0 di_efOut;
  ETTS0 eb_efOut;
  ETTS0 ed_efOut;
  ETTS0 ee_efOut;
  ETTS0 efOut;
  ETTS0 ej_efOut;
  ETTS0 f_efOut;
  ETTS0 fe_efOut;
  ETTS0 fi_efOut;
  ETTS0 g_efOut;
  ETTS0 gb_efOut;
  ETTS0 gd_efOut;
  ETTS0 gi_efOut;
  ETTS0 gj_efOut;
  ETTS0 hb_efOut;
  ETTS0 i_efOut;
  ETTS0 ic_efOut;
  ETTS0 id_efOut;
  ETTS0 ie_efOut;
  ETTS0 ig_efOut;
  ETTS0 ii_efOut;
  ETTS0 ij_efOut;
  ETTS0 jb_efOut;
  ETTS0 jc_efOut;
  ETTS0 je_efOut;
  ETTS0 jg_efOut;
  ETTS0 jj_efOut;
  ETTS0 k_efOut;
  ETTS0 kd_efOut;
  ETTS0 kf_efOut;
  ETTS0 kh_efOut;
  ETTS0 ki_efOut;
  ETTS0 lb_efOut;
  ETTS0 lc_efOut;
  ETTS0 ld_efOut;
  ETTS0 le_efOut;
  ETTS0 lf_efOut;
  ETTS0 lg_efOut;
  ETTS0 lh_efOut;
  ETTS0 m_efOut;
  ETTS0 mc_efOut;
  ETTS0 mi_efOut;
  ETTS0 nd_efOut;
  ETTS0 ne_efOut;
  ETTS0 ng_efOut;
  ETTS0 nh_efOut;
  ETTS0 oc_efOut;
  ETTS0 of_efOut;
  ETTS0 oi_efOut;
  ETTS0 p_efOut;
  ETTS0 pb_efOut;
  ETTS0 pd_efOut;
  ETTS0 ph_efOut;
  ETTS0 q_efOut;
  ETTS0 qb_efOut;
  ETTS0 qc_efOut;
  ETTS0 qi_efOut;
  ETTS0 rd_efOut;
  ETTS0 re_efOut;
  ETTS0 rg_efOut;
  ETTS0 rh_efOut;
  ETTS0 s_efOut;
  ETTS0 sb_efOut;
  ETTS0 sc_efOut;
  ETTS0 se_efOut;
  ETTS0 sf_efOut;
  ETTS0 sg_efOut;
  ETTS0 sh_efOut;
  ETTS0 si_efOut;
  ETTS0 t101;
  ETTS0 t102;
  ETTS0 t104;
  ETTS0 t105;
  ETTS0 t108;
  ETTS0 t109;
  ETTS0 t110;
  ETTS0 t111;
  ETTS0 t112;
  ETTS0 t113;
  ETTS0 t115;
  ETTS0 t118;
  ETTS0 t21;
  ETTS0 t27;
  ETTS0 t29;
  ETTS0 t33;
  ETTS0 t34;
  ETTS0 t35;
  ETTS0 t36;
  ETTS0 t4;
  ETTS0 t44;
  ETTS0 t45;
  ETTS0 t49;
  ETTS0 t50;
  ETTS0 t53;
  ETTS0 t54;
  ETTS0 t56;
  ETTS0 t58;
  ETTS0 t59;
  ETTS0 t61;
  ETTS0 t62;
  ETTS0 t64;
  ETTS0 t68;
  ETTS0 t70;
  ETTS0 t72;
  ETTS0 t75;
  ETTS0 t78;
  ETTS0 t79;
  ETTS0 t80;
  ETTS0 t81;
  ETTS0 t83;
  ETTS0 t84;
  ETTS0 t85;
  ETTS0 t88;
  ETTS0 t89;
  ETTS0 t90;
  ETTS0 t93;
  ETTS0 t95;
  ETTS0 t97;
  ETTS0 tc_efOut;
  ETTS0 td_efOut;
  ETTS0 tf_efOut;
  ETTS0 ti_efOut;
  ETTS0 u_efOut;
  ETTS0 ub_efOut;
  ETTS0 ud_efOut;
  ETTS0 ue_efOut;
  ETTS0 ug_efOut;
  ETTS0 v_efOut;
  ETTS0 vb_efOut;
  ETTS0 vc_efOut;
  ETTS0 vf_efOut;
  ETTS0 vh_efOut;
  ETTS0 vi_efOut;
  ETTS0 wd_efOut;
  ETTS0 we_efOut;
  ETTS0 wg_efOut;
  ETTS0 wi_efOut;
  ETTS0 x_efOut;
  ETTS0 xb_efOut;
  ETTS0 xc_efOut;
  ETTS0 xd_efOut;
  ETTS0 xe_efOut;
  ETTS0 xf_efOut;
  ETTS0 xg_efOut;
  ETTS0 xh_efOut;
  ETTS0 yi_efOut;
  PmRealVector out;
  real_T X[148];
  real_T t921[148];
  real_T nonscalar12[8];
  real_T ae_efOut[1];
  real_T ak_efOut[1];
  real_T be_efOut[1];
  real_T bf_efOut[1];
  real_T bh_efOut[1];
  real_T bi_efOut[1];
  real_T bj_efOut[1];
  real_T bk_efOut[1];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T cc_efOut[1];
  real_T cd_efOut[1];
  real_T ce_efOut[1];
  real_T cg_efOut[1];
  real_T ck_efOut[1];
  real_T dc_efOut[1];
  real_T de_efOut[1];
  real_T dg_efOut[1];
  real_T dj_efOut[1];
  real_T dk_efOut[1];
  real_T e_efOut[1];
  real_T ec_efOut[1];
  real_T ef_efOut[1];
  real_T eg_efOut[1];
  real_T eh_efOut[1];
  real_T ei_efOut[1];
  real_T ek_efOut[1];
  real_T fb_efOut[1];
  real_T fc_efOut[1];
  real_T fd_efOut[1];
  real_T ff_efOut[1];
  real_T fg_efOut[1];
  real_T fh_efOut[1];
  real_T fj_efOut[1];
  real_T fk_efOut[1];
  real_T gc_efOut[1];
  real_T ge_efOut[1];
  real_T gf_efOut[1];
  real_T gg_efOut[1];
  real_T gh_efOut[1];
  real_T gk_efOut[1];
  real_T h_efOut[1];
  real_T hc_efOut[1];
  real_T hd_efOut[1];
  real_T he_efOut[1];
  real_T hf_efOut[1];
  real_T hg_efOut[1];
  real_T hh_efOut[1];
  real_T hi_efOut[1];
  real_T hj_efOut[1];
  real_T hk_efOut[1];
  real_T ib_efOut[1];
  real_T if_efOut[1];
  real_T ih_efOut[1];
  real_T ik_efOut[1];
  real_T j_efOut[1];
  real_T jd_efOut[1];
  real_T jf_efOut[1];
  real_T jh_efOut[1];
  real_T ji_efOut[1];
  real_T jk_efOut[1];
  real_T kb_efOut[1];
  real_T kc_efOut[1];
  real_T ke_efOut[1];
  real_T kg_efOut[1];
  real_T kj_efOut[1];
  real_T kk_efOut[1];
  real_T l_efOut[1];
  real_T li_efOut[1];
  real_T lj_efOut[1];
  real_T lk_efOut[1];
  real_T mb_efOut[1];
  real_T md_efOut[1];
  real_T me_efOut[1];
  real_T mf_efOut[1];
  real_T mg_efOut[1];
  real_T mh_efOut[1];
  real_T mj_efOut[1];
  real_T mk_efOut[1];
  real_T n_efOut[1];
  real_T nb_efOut[1];
  real_T nc_efOut[1];
  real_T nf_efOut[1];
  real_T ni_efOut[1];
  real_T nj_efOut[1];
  real_T nk_efOut[1];
  real_T o_efOut[1];
  real_T ob_efOut[1];
  real_T od_efOut[1];
  real_T oe_efOut[1];
  real_T og_efOut[1];
  real_T oh_efOut[1];
  real_T oj_efOut[1];
  real_T ok_efOut[1];
  real_T pc_efOut[1];
  real_T pe_efOut[1];
  real_T pf_efOut[1];
  real_T pg_efOut[1];
  real_T pi_efOut[1];
  real_T pj_efOut[1];
  real_T pk_efOut[1];
  real_T qd_efOut[1];
  real_T qe_efOut[1];
  real_T qf_efOut[1];
  real_T qg_efOut[1];
  real_T qh_efOut[1];
  real_T qj_efOut[1];
  real_T qk_efOut[1];
  real_T r_efOut[1];
  real_T rb_efOut[1];
  real_T rc_efOut[1];
  real_T rf_efOut[1];
  real_T ri_efOut[1];
  real_T rj_efOut[1];
  real_T rk_efOut[1];
  real_T sd_efOut[1];
  real_T sj_efOut[1];
  real_T t816[1];
  real_T t_efOut[1];
  real_T tb_efOut[1];
  real_T te_efOut[1];
  real_T tg_efOut[1];
  real_T th_efOut[1];
  real_T tj_efOut[1];
  real_T uc_efOut[1];
  real_T uf_efOut[1];
  real_T uh_efOut[1];
  real_T ui_efOut[1];
  real_T uj_efOut[1];
  real_T vd_efOut[1];
  real_T ve_efOut[1];
  real_T vg_efOut[1];
  real_T vj_efOut[1];
  real_T w_efOut[1];
  real_T wb_efOut[1];
  real_T wc_efOut[1];
  real_T wf_efOut[1];
  real_T wh_efOut[1];
  real_T wj_efOut[1];
  real_T xi_efOut[1];
  real_T xj_efOut[1];
  real_T y_efOut[1];
  real_T yb_efOut[1];
  real_T yc_efOut[1];
  real_T yd_efOut[1];
  real_T ye_efOut[1];
  real_T yf_efOut[1];
  real_T yg_efOut[1];
  real_T yh_efOut[1];
  real_T yj_efOut[1];
  real_T Basic_Peripherals_Aux_TCP_convection_A_pv;
  real_T Basic_Peripherals_Aux_TCP_convection_B_pv;
  real_T Basic_Peripherals_Aux_TCP_convection_B_step_neg;
  real_T Basic_Peripherals_Aux_TCP_torque_ref;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_ste0;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_A_pv;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_B_pv;
  real_T Basic_Peripherals_Gate_Valve_TL_mdot_square;
  real_T Basic_Peripherals_Gate_Valve_TL_rho_avg;
  real_T Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi;
  real_T Basic_Peripherals_Pipe_TL3_Phi_A;
  real_T Basic_Peripherals_Pipe_TL3_Q_cond;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_pv;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_step_neg;
  real_T Basic_Peripherals_Pipe_TL3_convection_B_pv;
  real_T Basic_Peripherals_Pipe_TL3_convection_B_step_neg;
  real_T Basic_Peripherals_T_Junction_TL1_convection_B_pv;
  real_T Basic_Peripherals_T_Junction_TL1_k_B;
  real_T Basic_Peripherals_T_Junction_TL1_k_C;
  real_T Basic_Peripherals_T_Junction_TL1_mu_avg;
  real_T Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs;
  real_T Basic_Peripherals_T_Junction_TL_convection_B_pv;
  real_T Basic_Peripherals_T_Junction_TL_k_B;
  real_T Basic_Peripherals_T_Junction_TL_k_C;
  real_T Basic_Peripherals_T_Junction_TL_rho_avg;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T D_idx_2;
  real_T Subsystem_Reference_Pipe_TL2_Q_cond;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_pv;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_step_neg;
  real_T Subsystem_Reference_Pipe_TL2_convection_B_pv;
  real_T Subsystem_Reference_Pipe_TL2_convection_B_step_neg;
  real_T Subsystem_Reference_Pipe_TL2_k_B_in;
  real_T Subsystem_Reference_Pipe_TL4_Pr_A_in;
  real_T Subsystem_Reference_Pipe_TL4_Pr_B_in;
  real_T Subsystem_Reference_Pipe_TL4_Pr_I;
  real_T Subsystem_Reference_Pipe_TL4_Q_cond;
  real_T Subsystem_Reference_Pipe_TL4_Re_avg;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_pv;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_step_neg;
  real_T Subsystem_Reference_Pipe_TL4_convection_B_pv;
  real_T Subsystem_Reference_Pipe_TL4_k_A_in;
  real_T Subsystem_Reference_Pipe_TL4_k_B_in;
  real_T Subsystem_Reference_Pipe_TL4_k_I;
  real_T Subsystem_Reference_Pipe_TL4_mdot_avg;
  real_T Subsystem_Reference_Pipe_TL4_mu_A_in;
  real_T Subsystem_Reference_Pipe_TL4_mu_B_in;
  real_T Subsystem_Reference_Pipe_TL4_u_I;
  real_T Subsystem_Reference_TCP_6812_convection_A_mdot_abs;
  real_T Subsystem_Reference_TCP_6812_convection_A_pv;
  real_T Subsystem_Reference_TCP_6812_convection_A_rho;
  real_T Subsystem_Reference_TCP_6812_convection_B_pv;
  real_T Subsystem_Reference_TCP_6812_convection_B_step_neg;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_pv;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_pv;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg;
  real_T Subsystem_Reference_T_Junction_TL_rho_avg;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T intrm_sf_mf_124;
  real_T intrm_sf_mf_127;
  real_T intrm_sf_mf_158;
  real_T intrm_sf_mf_176;
  real_T intrm_sf_mf_214;
  real_T intrm_sf_mf_217;
  real_T intrm_sf_mf_221;
  real_T intrm_sf_mf_23;
  real_T intrm_sf_mf_242;
  real_T intrm_sf_mf_38;
  real_T intrm_sf_mf_47;
  real_T intrm_sf_mf_61;
  real_T intrm_sf_mf_80;
  real_T intrm_sf_mf_81;
  real_T intrm_sf_mf_84;
  real_T intrm_sf_mf_88;
  real_T intrm_sf_mf_90;
  real_T piece12;
  real_T t1033_idx_0;
  real_T t1071;
  real_T t1072;
  real_T t1074;
  real_T t1076;
  real_T t1077;
  real_T t1078;
  real_T t1080;
  real_T t1082;
  real_T t1085;
  real_T t1087;
  real_T t1088;
  real_T t1089;
  real_T t1090;
  real_T t1091;
  real_T t1092;
  real_T t1093;
  real_T t1095;
  real_T t1097;
  real_T t1098;
  real_T t1099;
  real_T t1101;
  real_T t1103;
  real_T t1104;
  real_T t1105;
  real_T t1106;
  real_T t1107;
  real_T t1109;
  real_T t1110;
  real_T t1111;
  real_T t1113;
  real_T t1116;
  real_T t1117;
  real_T t1121;
  real_T t1122;
  real_T t1123;
  real_T t1124;
  real_T t1126;
  real_T t1129;
  real_T t1130;
  real_T t1132;
  real_T t1134;
  real_T t1136;
  real_T t1137;
  real_T t1138;
  real_T t1140;
  real_T t1142;
  real_T t1144;
  real_T t1145;
  real_T t1146;
  real_T t1148;
  real_T t1150;
  real_T t1152;
  real_T t1154;
  real_T t1155;
  real_T t1161;
  real_T t1162;
  real_T t1163;
  real_T t1165;
  real_T t1168;
  real_T t1169;
  real_T t1170;
  real_T t1171;
  real_T t1172;
  real_T t1173;
  real_T t1174;
  real_T t1175;
  real_T t1176;
  real_T t1177;
  real_T t1178;
  real_T t1179;
  real_T t1183;
  real_T t1186;
  real_T t1188;
  real_T t1190;
  real_T t1197;
  real_T t1198;
  real_T t1199;
  real_T t1200;
  real_T t1202;
  real_T t1204;
  real_T t1205;
  real_T t1208;
  real_T t1211;
  real_T t1212;
  real_T t1213;
  real_T t1214;
  real_T t1215;
  real_T t1216;
  real_T t1218;
  real_T t1220;
  real_T t1221;
  real_T t1222;
  real_T t1223;
  real_T t1225;
  real_T t1227;
  real_T t1229;
  real_T t1230;
  real_T t1231;
  real_T t1233;
  real_T t1235;
  real_T t1237;
  real_T t1238;
  real_T t1239;
  real_T t1240;
  real_T t1241;
  real_T t1243;
  real_T t1245;
  real_T t1246;
  real_T t1248;
  real_T t1249;
  real_T t1250;
  real_T t1251;
  real_T t1255;
  real_T t1257;
  real_T t1259;
  real_T t1260;
  real_T t1261;
  real_T t1262;
  real_T t1264;
  real_T t1266;
  real_T t1268;
  real_T t1269;
  real_T t1272;
  real_T t1274;
  real_T t1275;
  real_T t1276;
  real_T t1278;
  real_T t1280;
  real_T t1387;
  real_T t1392;
  real_T t1409;
  real_T t1413;
  real_T t1415;
  real_T t1416;
  real_T t1485;
  real_T t1527;
  real_T t1528;
  real_T t1529;
  real_T t1539;
  real_T t1542;
  real_T t1543;
  real_T t1571;
  real_T t1576;
  real_T t1579;
  real_T t1603;
  real_T t1616;
  real_T t1618;
  real_T t1683;
  real_T t1707;
  size_t t120[1];
  size_t t121[1];
  size_t t123[1];
  size_t t699[1];
  size_t t708[1];
  int32_T b;
  boolean_T intrm_sf_mf_48;
  U_idx_0 = t1712->mU.mX[0];
  U_idx_1 = t1712->mU.mX[1];
  U_idx_2 = t1712->mU.mX[2];
  U_idx_3 = t1712->mU.mX[3];
  U_idx_4 = t1712->mU.mX[4];
  U_idx_6 = t1712->mU.mX[6];
  U_idx_7 = t1712->mU.mX[7];
  for (b = 0; b < 148; b++) {
    X[b] = t1712->mX.mX[b];
  }

  D_idx_0 = t1712->mD.mX[0];
  D_idx_1 = t1712->mD.mX[1];
  D_idx_2 = t1712->mD.mX[2];
  out = t1713->mF;
  nonscalar12[0] = -209.43951023931953;
  nonscalar12[1] = 0.0;
  nonscalar12[2] = 209.43951023931953;
  nonscalar12[3] = 261.79938779914943;
  nonscalar12[4] = 314.15926535897933;
  nonscalar12[5] = 366.51914291880917;
  nonscalar12[6] = 418.87902047863906;
  nonscalar12[7] = 439.822971502571;
  t1707 = X[0ULL] * -0.8 + 1.1132499999999999;
  t1683 = -X[26ULL] + X[27ULL];
  t1616 = U_idx_0 * 0.10471975511965977;
  t1618 = pmf_sqrt(X[29ULL] * X[29ULL] + 4.6221943695030632E-11);
  t816[0ULL] = X[28ULL];
  t120[0] = 20ULL;
  t121[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t115 = efOut;
  t816[0ULL] = t1707;
  t123[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t108 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t115.mField0[0ULL],
    &t115.mField2[0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = c_efOut[0];
  t1603 = t1033_idx_0;
  Basic_Peripherals_Aux_TCP_convection_A_pv = X[29ULL] / (t1618 == 0.0 ? 1.0E-16
    : t1618) * t1707 / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1072 = (1.0 - X[29ULL] / (t1618 == 0.0 ? 1.0E-16 : t1618)) / 2.0;
  t1074 = (X[29ULL] / (t1618 == 0.0 ? 1.0E-16 : t1618) + 1.0) / 2.0;
  t816[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = d_efOut;
  tlu2_2d_linear_linear_value(&e_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = e_efOut[0];
  t1076 = t1033_idx_0;
  t816[0ULL] = X[31ULL];
  tlu2_linear_linear_prelookup(&f_efOut.mField0[0ULL], &f_efOut.mField1[0ULL],
    &f_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t113 = f_efOut;
  t816[0ULL] = X[23ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t105 = g_efOut;
  tlu2_2d_linear_linear_value(&h_efOut[0ULL], &t113.mField0[0ULL],
    &t113.mField2[0ULL], &t105.mField0[0ULL], &t105.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = h_efOut[0];
  Basic_Peripherals_Aux_TCP_convection_B_pv = -X[29ULL] / (t1618 == 0.0 ?
    1.0E-16 : t1618) * X[23ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Basic_Peripherals_Aux_TCP_convection_B_step_neg = (1.0 - -X[29ULL] / (t1618 ==
    0.0 ? 1.0E-16 : t1618)) / 2.0;
  t1077 = (-X[29ULL] / (t1618 == 0.0 ? 1.0E-16 : t1618) + 1.0) / 2.0;
  t816[0ULL] = X[22ULL];
  tlu2_linear_linear_prelookup(&i_efOut.mField0[0ULL], &i_efOut.mField1[0ULL],
    &i_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = i_efOut;
  tlu2_2d_linear_linear_value(&j_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t105.mField0[0ULL], &t105.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = j_efOut[0];
  t1078 = t1033_idx_0;
  Basic_Peripherals_Aux_TCP_torque_ref = pmf_sqrt(t1616 * t1616 +
    13.433628212593847) + t1616;
  t1080 = Basic_Peripherals_Aux_TCP_torque_ref / 2.0;
  t1082 = X[29ULL] / (t1603 == 0.0 ? 1.0E-16 : t1603);
  Basic_Peripherals_Aux_TCP_torque_ref = 366.51914291880917 / (t1080 == 0.0 ?
    1.0E-16 : t1080) * t1082;
  if (Basic_Peripherals_Aux_TCP_torque_ref < 0.0) {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 =
      15.800203873598369;
  } else if (Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6 <= 1666.6666666666665)
  {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 =
      Basic_Peripherals_Aux_TCP_torque_ref *
      Basic_Peripherals_Aux_TCP_torque_ref * -1.2844036697247704E+6 +
      15.800203873598369;
  } else if (Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6 <= 3333.333333333333)
  {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 =
      (Basic_Peripherals_Aux_TCP_torque_ref * 1834.8623853211036 +
       Basic_Peripherals_Aux_TCP_torque_ref *
       Basic_Peripherals_Aux_TCP_torque_ref * -1.8348623853211019E+6) +
      14.271151885830777;
  } else {
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 =
      (Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6 - 3333.333333333333) *
      -0.010397553516819574;
  }

  t1080 = t1603 * (t1080 / 366.51914291880917 * (t1080 / 366.51914291880917) *
                   Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1)
    * 9.81;
  t1603 = t1080 * t1082;
  if (Basic_Peripherals_Aux_TCP_torque_ref < 0.0) {
    t1082 = 0.19375;
  } else if (Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6 <= 1666.6666666666665)
  {
    U_idx_0 = 3333.333333333333 - Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6;
    t1082 = (0.64583333333333326 - Basic_Peripherals_Aux_TCP_torque_ref *
             Basic_Peripherals_Aux_TCP_torque_ref * 52499.999999999993) /
      (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0) * 1000.0;
  } else if (Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6 <= 3333.333333333333)
  {
    t1088 = Basic_Peripherals_Aux_TCP_torque_ref * 1.0E+6;
    t1082 = (Basic_Peripherals_Aux_TCP_torque_ref * 75.000000000000028 +
             0.17499999999999988) * Basic_Peripherals_Aux_TCP_torque_ref /
      (t1088 == 0.0 ? 1.0E-16 : t1088) * 1.0E+6;
  } else {
    t1082 = 0.42499999999999993;
  }

  Basic_Peripherals_Aux_TCP_torque_ref = t1082 / 366.51914291880917;
  t1082 = -X[29ULL] - X[35ULL];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 = pmf_sqrt
    (t1082 * t1082 + 4.8042127793498068E-8);
  t816[0ULL] = X[34ULL];
  tlu2_linear_linear_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t88 = k_efOut;
  tlu2_2d_linear_linear_value(&l_efOut[0ULL], &t88.mField0[0ULL], &t88.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = l_efOut[0];
  t1085 = t1082 /
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 == 0.0 ?
     1.0E-16 : Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1) *
    t1707 / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_ste0 = (1.0 - t1082
    / (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 == 0.0 ?
       1.0E-16 : Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1))
    / 2.0;
  t1082 = (t1082 /
           (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1 ==
            0.0 ? 1.0E-16 :
            Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1) +
           1.0) / 2.0;
  t816[0ULL] = X[1ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = m_efOut;
  tlu2_2d_linear_linear_value(&n_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = n_efOut[0];
  t1087 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = o_efOut[0];
  t1088 = t1033_idx_0;
  t1089 = t1707 / (t1087 == 0.0 ? 1.0E-16 : t1087) * 100.0 + t1033_idx_0;
  t1091 = U_idx_1 / 0.045000000000000005;
  if (t1091 <= 0.0) {
    t1090 = 0.0;
  } else if (t1091 <= 0.005) {
    t1090 = t1091 * t1091 * 100.50251256281406;
  } else if (t1091 <= 0.995) {
    t1090 = t1091 * 1.0050251256281406 - 0.0025125628140703518;
  } else if (t1091 <= 1.0) {
    t1090 = (1.0 - t1091) * (1.0 - t1091) * -100.50251256281406 + 1.0;
  } else {
    t1090 = 1.0;
  }

  t1091 = t1090 * 0.045000000000000005;
  if (t1091 / 0.045000000000000005 <= -1.0) {
    t1090 = -1.0;
  } else if (t1091 / 0.045000000000000005 >= 1.0) {
    t1090 = 1.0;
  } else {
    t1090 = t1091 / 0.045000000000000005;
  }

  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs = pmf_acos(t1090) *
    0.0010125000000000002 - t1091 / 2.0 * pmf_sqrt(0.0020250000000000003 - t1091
    * t1091);
  t1091 = (0.0015904312808798331 -
           Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) + 1.0E-12;
  t1090 = ((0.0015904312808798331 -
            Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) + 1.0E-12) /
    0.0019634954084936209;
  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs = pmf_sqrt(X[46ULL] * X
    [46ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[45ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t83 = p_efOut;
  t816[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t102 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t83.mField0[0ULL], &t83.mField2
    [0ULL], &t102.mField0[0ULL], &t102.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = r_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_rho_avg = t1033_idx_0;
  Basic_Peripherals_Gate_Valve_TL_convection_A_pv = X[46ULL] /
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) * X[42ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1093 = (1.0 - X[46ULL] /
           (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
            1.0E-16 : Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs)) /
    2.0;
  t1095 = (X[46ULL] / (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs ==
                       0.0 ? 1.0E-16 :
                       Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&s_efOut.mField0[0ULL], &s_efOut.mField1[0ULL],
    &s_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = s_efOut;
  tlu2_2d_linear_linear_value(&t_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t102.mField0[0ULL], &t102.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = t_efOut[0];
  t1097 = t1033_idx_0;
  t816[0ULL] = X[48ULL];
  tlu2_linear_linear_prelookup(&u_efOut.mField0[0ULL], &u_efOut.mField1[0ULL],
    &u_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t84 = u_efOut;
  t816[0ULL] = X[44ULL];
  tlu2_linear_linear_prelookup(&v_efOut.mField0[0ULL], &v_efOut.mField1[0ULL],
    &v_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t78 = v_efOut;
  tlu2_2d_linear_linear_value(&w_efOut[0ULL], &t84.mField0[0ULL], &t84.mField2
    [0ULL], &t78.mField0[0ULL], &t78.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = w_efOut[0];
  Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi = t1033_idx_0;
  Basic_Peripherals_Gate_Valve_TL_convection_B_pv = -X[46ULL] /
    (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) * X[44ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1099 = (1.0 - -X[46ULL] /
           (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
            1.0E-16 : Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs)) /
    2.0;
  t1101 = (-X[46ULL] / (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs ==
                        0.0 ? 1.0E-16 :
                        Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[43ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t78.mField0[0ULL], &t78.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = y_efOut[0];
  t1103 = t1033_idx_0;
  t816[0ULL] = X[45ULL];
  tlu2_linear_nearest_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = ab_efOut;
  t816[0ULL] = X[42ULL];
  tlu2_linear_nearest_prelookup(&bb_efOut.mField0[0ULL], &bb_efOut.mField1[0ULL],
    &bb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t101 = bb_efOut;
  tlu2_2d_linear_nearest_value(&cb_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t101.mField0[0ULL], &t101.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = cb_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_mdot_square = t1033_idx_0;
  t816[0ULL] = X[48ULL];
  tlu2_linear_nearest_prelookup(&db_efOut.mField0[0ULL], &db_efOut.mField1[0ULL],
    &db_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = db_efOut;
  t816[0ULL] = X[44ULL];
  tlu2_linear_nearest_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t75 = eb_efOut;
  tlu2_2d_linear_nearest_value(&fb_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t75.mField0[0ULL], &t75.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fb_efOut[0];
  Basic_Peripherals_Pipe_TL3_Phi_A = pmf_sqrt(t1091 * 0.78539816339744828) *
    ((Basic_Peripherals_Gate_Valve_TL_mdot_square + t1033_idx_0) / 2.0) * 12.0;
  Basic_Peripherals_Gate_Valve_TL_mdot_square = pmf_sqrt(X[46ULL] * X[46ULL] +
    Basic_Peripherals_Pipe_TL3_Phi_A * Basic_Peripherals_Pipe_TL3_Phi_A) * X
    [46ULL];
  Basic_Peripherals_Gate_Valve_TL_rho_avg =
    (Basic_Peripherals_Gate_Valve_TL_rho_avg +
     Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi) / 2.0;
  Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi = -X[51ULL] + X[26ULL];
  Basic_Peripherals_Pipe_TL3_Phi_A = -X[55ULL] - X[56ULL];
  t816[0ULL] = X[37ULL];
  tlu2_linear_nearest_prelookup(&gb_efOut.mField0[0ULL], &gb_efOut.mField1[0ULL],
    &gb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t118 = gb_efOut;
  t816[0ULL] = X[5ULL];
  tlu2_linear_nearest_prelookup(&hb_efOut.mField0[0ULL], &hb_efOut.mField1[0ULL],
    &hb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t70 = hb_efOut;
  tlu2_2d_linear_nearest_value(&ib_efOut[0ULL], &t118.mField0[0ULL],
    &t118.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ib_efOut[0];
  t1104 = t1033_idx_0;
  t816[0ULL] = X[53ULL];
  tlu2_linear_nearest_prelookup(&jb_efOut.mField0[0ULL], &jb_efOut.mField1[0ULL],
    &jb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = jb_efOut;
  tlu2_2d_linear_nearest_value(&kb_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = kb_efOut[0];
  t1105 = t1033_idx_0;
  t816[0ULL] = X[6ULL];
  tlu2_linear_nearest_prelookup(&lb_efOut.mField0[0ULL], &lb_efOut.mField1[0ULL],
    &lb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t45 = lb_efOut;
  tlu2_2d_linear_nearest_value(&mb_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = mb_efOut[0];
  intrm_sf_mf_242 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&nb_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = nb_efOut[0];
  intrm_sf_mf_84 = t1033_idx_0;
  Basic_Peripherals_Pipe_TL3_Q_cond = (X[52ULL] - X[6ULL]) * (t1033_idx_0 *
    0.055555555555555559 / 0.1413716694115407);
  t1106 = (-X[7ULL] - (-X[57ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&ob_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ob_efOut[0];
  t1107 = t1033_idx_0;
  t1409 = t1106 * 0.1413716694115407;
  t1109 = t1033_idx_0 * 0.0019634954084936209;
  intrm_sf_mf_88 = t1409 / (t1109 == 0.0 ? 1.0E-16 : t1109);
  Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs = pmf_sqrt(X[7ULL] * X[7ULL]
    + 3.7732198934718893E-12);
  t816[0ULL] = X[58ULL];
  tlu2_linear_linear_prelookup(&pb_efOut.mField0[0ULL], &pb_efOut.mField1[0ULL],
    &pb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t104 = pb_efOut;
  t816[0ULL] = X[38ULL];
  tlu2_linear_linear_prelookup(&qb_efOut.mField0[0ULL], &qb_efOut.mField1[0ULL],
    &qb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t110 = qb_efOut;
  tlu2_2d_linear_linear_value(&rb_efOut[0ULL], &t104.mField0[0ULL],
    &t104.mField2[0ULL], &t110.mField0[0ULL], &t110.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = rb_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_A_pv = -X[7ULL] /
    (Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs) * X[38ULL] / (t1033_idx_0
    == 0.0 ? 1.0E-16 : t1033_idx_0);
  Basic_Peripherals_Pipe_TL3_convection_A_step_neg = (1.0 - -X[7ULL] /
    (Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs)) / 2.0;
  t1110 = (-X[7ULL] / (Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs == 0.0 ?
                       1.0E-16 :
                       Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs) + 1.0) /
    2.0;
  t816[0ULL] = X[37ULL];
  tlu2_linear_linear_prelookup(&sb_efOut.mField0[0ULL], &sb_efOut.mField1[0ULL],
    &sb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = sb_efOut;
  tlu2_2d_linear_linear_value(&tb_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t110.mField0[0ULL], &t110.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = tb_efOut[0];
  t1111 = t1033_idx_0;
  t1113 = pmf_sqrt(X[57ULL] * X[57ULL] + 3.7732198934718893E-12);
  t816[0ULL] = X[60ULL];
  tlu2_linear_linear_prelookup(&ub_efOut.mField0[0ULL], &ub_efOut.mField1[0ULL],
    &ub_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t68 = ub_efOut;
  t816[0ULL] = X[54ULL];
  tlu2_linear_linear_prelookup(&vb_efOut.mField0[0ULL], &vb_efOut.mField1[0ULL],
    &vb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t112 = vb_efOut;
  tlu2_2d_linear_linear_value(&wb_efOut[0ULL], &t68.mField0[0ULL], &t68.mField2
    [0ULL], &t112.mField0[0ULL], &t112.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = wb_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_B_pv = -X[57ULL] / (t1113 == 0.0 ?
    1.0E-16 : t1113) * X[54ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Basic_Peripherals_Pipe_TL3_convection_B_step_neg = (1.0 - -X[57ULL] / (t1113 ==
    0.0 ? 1.0E-16 : t1113)) / 2.0;
  t1116 = (-X[57ULL] / (t1113 == 0.0 ? 1.0E-16 : t1113) + 1.0) / 2.0;
  t816[0ULL] = X[53ULL];
  tlu2_linear_linear_prelookup(&xb_efOut.mField0[0ULL], &xb_efOut.mField1[0ULL],
    &xb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = xb_efOut;
  tlu2_2d_linear_linear_value(&yb_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t112.mField0[0ULL], &t112.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yb_efOut[0];
  t1117 = t1033_idx_0;
  t816[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&ac_efOut.mField0[0ULL], &ac_efOut.mField1[0ULL],
    &ac_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t90 = ac_efOut;
  t816[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&bc_efOut.mField0[0ULL], &bc_efOut.mField1[0ULL],
    &bc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = bc_efOut;
  tlu2_2d_linear_linear_value(&cc_efOut[0ULL], &t90.mField0[0ULL], &t90.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = cc_efOut[0];
  intrm_sf_mf_38 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&dc_efOut[0ULL], &t90.mField0[0ULL], &t90.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = dc_efOut[0];
  t1121 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&ec_efOut[0ULL], &t118.mField0[0ULL],
    &t118.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ec_efOut[0];
  intrm_sf_mf_47 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&fc_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fc_efOut[0];
  intrm_sf_mf_80 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&gc_efOut[0ULL], &t118.mField0[0ULL],
    &t118.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = gc_efOut[0];
  intrm_sf_mf_158 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&hc_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hc_efOut[0];
  intrm_sf_mf_23 = t1033_idx_0;
  t816[0ULL] = X[62ULL];
  tlu2_linear_nearest_prelookup(&ic_efOut.mField0[0ULL], &ic_efOut.mField1[0ULL],
    &ic_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = ic_efOut;
  t816[0ULL] = X[54ULL];
  tlu2_linear_nearest_prelookup(&jc_efOut.mField0[0ULL], &jc_efOut.mField1[0ULL],
    &jc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = jc_efOut;
  tlu2_2d_linear_nearest_value(&kc_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = kc_efOut[0];
  piece12 = t1033_idx_0;
  t816[0ULL] = X[63ULL];
  tlu2_linear_nearest_prelookup(&lc_efOut.mField0[0ULL], &lc_efOut.mField1[0ULL],
    &lc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t70 = lc_efOut;
  t816[0ULL] = X[50ULL];
  tlu2_linear_nearest_prelookup(&mc_efOut.mField0[0ULL], &mc_efOut.mField1[0ULL],
    &mc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t118 = mc_efOut;
  tlu2_2d_linear_nearest_value(&nc_efOut[0ULL], &t70.mField0[0ULL],
    &t70.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = nc_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs = t1033_idx_0;
  t816[0ULL] = X[64ULL];
  tlu2_linear_nearest_prelookup(&oc_efOut.mField0[0ULL], &oc_efOut.mField1[0ULL],
    &oc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t111 = oc_efOut;
  tlu2_2d_linear_nearest_value(&pc_efOut[0ULL], &t111.mField0[0ULL],
    &t111.mField2[0ULL], &t75.mField0[0ULL], &t75.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = pc_efOut[0];
  piece12 = ((piece12 * 0.0019634954084936209 +
              Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs *
              0.0019634954084936209) + t1033_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626;
  Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs = pmf_sqrt(X[57ULL] * X
    [57ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[62ULL];
  tlu2_linear_linear_prelookup(&qc_efOut.mField0[0ULL], &qc_efOut.mField1[0ULL],
    &qc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t62 = qc_efOut;
  tlu2_2d_linear_linear_value(&rc_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t112.mField0[0ULL], &t112.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = rc_efOut[0];
  Basic_Peripherals_T_Junction_TL_rho_avg = t1033_idx_0;
  t1122 = X[57ULL] / (Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs ==
                      0.0 ? 1.0E-16 :
                      Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs) *
    X[54ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1124 = (1.0 - X[57ULL] /
           (Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs == 0.0 ?
            1.0E-16 : Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs)) /
    2.0;
  t1123 = (X[57ULL] / (Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs ==
                       0.0 ? 1.0E-16 :
                       Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs) +
           1.0) / 2.0;
  t1126 = pmf_sqrt(X[4ULL] * X[4ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[63ULL];
  tlu2_linear_linear_prelookup(&sc_efOut.mField0[0ULL], &sc_efOut.mField1[0ULL],
    &sc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t89 = sc_efOut;
  t816[0ULL] = X[50ULL];
  tlu2_linear_linear_prelookup(&tc_efOut.mField0[0ULL], &tc_efOut.mField1[0ULL],
    &tc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t61 = tc_efOut;
  tlu2_2d_linear_linear_value(&uc_efOut[0ULL], &t89.mField0[0ULL], &t89.mField2
    [0ULL], &t61.mField0[0ULL], &t61.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = uc_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg = t1033_idx_0;
  Basic_Peripherals_T_Junction_TL_convection_B_pv = X[4ULL] / (t1126 == 0.0 ?
    1.0E-16 : t1126) * X[50ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1130 = (1.0 - X[4ULL] / (t1126 == 0.0 ? 1.0E-16 : t1126)) / 2.0;
  t1129 = (X[4ULL] / (t1126 == 0.0 ? 1.0E-16 : t1126) + 1.0) / 2.0;
  t816[0ULL] = X[49ULL];
  tlu2_linear_linear_prelookup(&vc_efOut.mField0[0ULL], &vc_efOut.mField1[0ULL],
    &vc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t75 = vc_efOut;
  tlu2_2d_linear_linear_value(&wc_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t61.mField0[0ULL], &t61.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = wc_efOut[0];
  t1132 = t1033_idx_0;
  t816[0ULL] = X[64ULL];
  tlu2_linear_linear_prelookup(&xc_efOut.mField0[0ULL], &xc_efOut.mField1[0ULL],
    &xc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t59 = xc_efOut;
  tlu2_2d_linear_linear_value(&yc_efOut[0ULL], &t59.mField0[0ULL], &t59.mField2
    [0ULL], &t78.mField0[0ULL], &t78.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yc_efOut[0];
  t1092 = X[46ULL] / (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs ==
                      0.0 ? 1.0E-16 :
                      Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) *
    X[44ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  if (D_idx_0 == 2.0) {
    t1136 = 0.0;
  } else if (D_idx_0 == 3.0) {
    t1136 = 0.38;
  } else if (D_idx_0 == 4.0) {
    t1136 = 0.0;
  } else if (D_idx_0 == 5.0) {
    t1136 = 0.38;
  } else if (D_idx_0 == 6.0) {
    t1136 = 0.76;
  } else {
    t1136 = D_idx_0 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_0 == 2.0) {
    Basic_Peripherals_T_Junction_TL_k_B = 0.38;
  } else if (D_idx_0 == 3.0) {
    Basic_Peripherals_T_Junction_TL_k_B = 0.0;
  } else if (D_idx_0 == 4.0) {
    Basic_Peripherals_T_Junction_TL_k_B = 0.38;
  } else if (D_idx_0 == 5.0) {
    Basic_Peripherals_T_Junction_TL_k_B = 0.0;
  } else if (D_idx_0 == 6.0) {
    Basic_Peripherals_T_Junction_TL_k_B = 0.76;
  } else {
    Basic_Peripherals_T_Junction_TL_k_B = D_idx_0 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_0 == 2.0) {
    Basic_Peripherals_T_Junction_TL_k_C = 1.14;
  } else if (D_idx_0 == 3.0) {
    Basic_Peripherals_T_Junction_TL_k_C = 1.14;
  } else if (D_idx_0 == 4.0) {
    Basic_Peripherals_T_Junction_TL_k_C = 1.14;
  } else if (D_idx_0 == 5.0) {
    Basic_Peripherals_T_Junction_TL_k_C = 1.14;
  } else if (D_idx_0 == 6.0) {
    Basic_Peripherals_T_Junction_TL_k_C = 0.0;
  } else {
    Basic_Peripherals_T_Junction_TL_k_C = (real_T)!(D_idx_0 == 7.0);
  }

  Basic_Peripherals_T_Junction_TL_rho_avg =
    ((Basic_Peripherals_T_Junction_TL_rho_avg * 0.0019634954084936209 +
      Basic_Peripherals_T_Junction_TL1_mu_avg * 0.0019634954084936209) +
     t1033_idx_0 * 0.0019634954084936209) / 0.0058904862254808626;
  t816[0ULL] = X[73ULL];
  tlu2_linear_nearest_prelookup(&ad_efOut.mField0[0ULL], &ad_efOut.mField1[0ULL],
    &ad_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = ad_efOut;
  t816[0ULL] = X[23ULL];
  tlu2_linear_nearest_prelookup(&bd_efOut.mField0[0ULL], &bd_efOut.mField1[0ULL],
    &bd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = bd_efOut;
  tlu2_2d_linear_nearest_value(&cd_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = cd_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg = t1033_idx_0;
  t816[0ULL] = X[74ULL];
  tlu2_linear_nearest_prelookup(&dd_efOut.mField0[0ULL], &dd_efOut.mField1[0ULL],
    &dd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = dd_efOut;
  t816[0ULL] = X[40ULL];
  tlu2_linear_nearest_prelookup(&ed_efOut.mField0[0ULL], &ed_efOut.mField1[0ULL],
    &ed_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t4 = ed_efOut;
  tlu2_2d_linear_nearest_value(&fd_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t4.mField0[0ULL], &t4.mField2[0ULL], ((_NeDynamicSystem*)
    (LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fd_efOut[0];
  t1134 = t1033_idx_0;
  t816[0ULL] = X[75ULL];
  tlu2_linear_nearest_prelookup(&gd_efOut.mField0[0ULL], &gd_efOut.mField1[0ULL],
    &gd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t75 = gd_efOut;
  tlu2_2d_linear_nearest_value(&hd_efOut[0ULL], &t75.mField0[0ULL],
    &t75.mField2[0ULL], &t101.mField0[0ULL], &t101.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hd_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg =
    ((Basic_Peripherals_T_Junction_TL1_mu_avg * 0.0019634954084936209 + t1134 *
      0.0019634954084936209) + t1033_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626;
  t1134 = pmf_sqrt(X[29ULL] * X[29ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[73ULL];
  tlu2_linear_linear_prelookup(&id_efOut.mField0[0ULL], &id_efOut.mField1[0ULL],
    &id_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t56 = id_efOut;
  tlu2_2d_linear_linear_value(&jd_efOut[0ULL], &t56.mField0[0ULL], &t56.mField2
    [0ULL], &t105.mField0[0ULL], &t105.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = jd_efOut[0];
  t1137 = t1033_idx_0;
  t1138 = X[29ULL] / (t1134 == 0.0 ? 1.0E-16 : t1134) * X[23ULL] / (t1033_idx_0 ==
    0.0 ? 1.0E-16 : t1033_idx_0);
  t1140 = (1.0 - X[29ULL] / (t1134 == 0.0 ? 1.0E-16 : t1134)) / 2.0;
  t1071 = (X[29ULL] / (t1134 == 0.0 ? 1.0E-16 : t1134) + 1.0) / 2.0;
  t1142 = pmf_sqrt(X[8ULL] * X[8ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[74ULL];
  tlu2_linear_linear_prelookup(&kd_efOut.mField0[0ULL], &kd_efOut.mField1[0ULL],
    &kd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t54 = kd_efOut;
  t816[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&ld_efOut.mField0[0ULL], &ld_efOut.mField1[0ULL],
    &ld_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t72 = ld_efOut;
  tlu2_2d_linear_linear_value(&md_efOut[0ULL], &t54.mField0[0ULL], &t54.mField2
    [0ULL], &t72.mField0[0ULL], &t72.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = md_efOut[0];
  t1144 = t1033_idx_0;
  Basic_Peripherals_T_Junction_TL1_convection_B_pv = X[8ULL] / (t1142 == 0.0 ?
    1.0E-16 : t1142) * X[40ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1146 = (1.0 - X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142)) / 2.0;
  t1148 = (X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) + 1.0) / 2.0;
  t816[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&nd_efOut.mField0[0ULL], &nd_efOut.mField1[0ULL],
    &nd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = nd_efOut;
  tlu2_2d_linear_linear_value(&od_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t72.mField0[0ULL], &t72.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = od_efOut[0];
  t1150 = t1033_idx_0;
  t816[0ULL] = X[75ULL];
  tlu2_linear_linear_prelookup(&pd_efOut.mField0[0ULL], &pd_efOut.mField1[0ULL],
    &pd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t49 = pd_efOut;
  tlu2_2d_linear_linear_value(&qd_efOut[0ULL], &t49.mField0[0ULL], &t49.mField2
    [0ULL], &t102.mField0[0ULL], &t102.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = qd_efOut[0];
  t1098 = -X[46ULL] / (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs ==
                       0.0 ? 1.0E-16 :
                       Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) *
    X[42ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  if (D_idx_1 == 2.0) {
    t1152 = 0.0;
  } else if (D_idx_1 == 3.0) {
    t1152 = 0.38;
  } else if (D_idx_1 == 4.0) {
    t1152 = 0.0;
  } else if (D_idx_1 == 5.0) {
    t1152 = 0.38;
  } else if (D_idx_1 == 6.0) {
    t1152 = 0.76;
  } else {
    t1152 = D_idx_1 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_1 == 2.0) {
    Basic_Peripherals_T_Junction_TL1_k_B = 0.38;
  } else if (D_idx_1 == 3.0) {
    Basic_Peripherals_T_Junction_TL1_k_B = 0.0;
  } else if (D_idx_1 == 4.0) {
    Basic_Peripherals_T_Junction_TL1_k_B = 0.38;
  } else if (D_idx_1 == 5.0) {
    Basic_Peripherals_T_Junction_TL1_k_B = 0.0;
  } else if (D_idx_1 == 6.0) {
    Basic_Peripherals_T_Junction_TL1_k_B = 0.76;
  } else {
    Basic_Peripherals_T_Junction_TL1_k_B = D_idx_1 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_1 == 2.0) {
    Basic_Peripherals_T_Junction_TL1_k_C = 1.14;
  } else if (D_idx_1 == 3.0) {
    Basic_Peripherals_T_Junction_TL1_k_C = 1.14;
  } else if (D_idx_1 == 4.0) {
    Basic_Peripherals_T_Junction_TL1_k_C = 1.14;
  } else if (D_idx_1 == 5.0) {
    Basic_Peripherals_T_Junction_TL1_k_C = 1.14;
  } else if (D_idx_1 == 6.0) {
    Basic_Peripherals_T_Junction_TL1_k_C = 0.0;
  } else {
    Basic_Peripherals_T_Junction_TL1_k_C = (real_T)!(D_idx_1 == 7.0);
  }

  t1137 = ((t1137 * 0.0019634954084936209 + t1144 * 0.0019634954084936209) +
           t1033_idx_0 * 0.0019634954084936209) / 0.0058904862254808626;
  U_idx_0 = tanh(X[85ULL] * 3.0 / 0.029511607098668874) * X[85ULL];
  t1154 = tanh(U_idx_2 * 3.0 / 0.029511607098668874) * U_idx_2;
  intrm_sf_mf_48 = (U_idx_0 >= t1154);
  t1144 = intrm_sf_mf_48 ? U_idx_0 : t1154;
  t1155 = intrm_sf_mf_48 ? t1154 : U_idx_0;
  t1144 = (t1155 + 0.029511607098668874) / (t1144 + 0.029511607098668874 == 0.0 ?
    1.0E-16 : t1144 + 0.029511607098668874);
  t1571 = (X[88ULL] <= 5.0 ? 5.0 : X[88ULL]) * 0.47700000000000009;
  intrm_sf_mf_61 = (U_idx_3 <= 0.01 ? 0.01 : U_idx_3) * 2.9881500000000005;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 = (1.0 / (t1571
    == 0.0 ? 1.0E-16 : t1571) + 1.0 / (intrm_sf_mf_61 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_61)) + 0.000163312919218431;
  intrm_sf_mf_127 =
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 * 6.0;
  if (t1155 >= 1.0 / (intrm_sf_mf_127 == 0.0 ? 1.0E-16 : intrm_sf_mf_127)) {
    t1161 = t1155 *
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8;
    intrm_sf_mf_90 = pmf_exp(-1.0 / (t1161 == 0.0 ? 1.0E-16 : t1161));
  } else {
    intrm_sf_mf_90 = 0.0024787521766663585;
  }

  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 = (1.0 -
    pmf_exp(-t1144 * (1.0 - intrm_sf_mf_90))) * (1.0 / (t1144 == 0.0 ? 1.0E-16 :
    t1144));
  t1162 = -(1.0 - pmf_pow(intrm_sf_mf_90, t1144));
  intrm_sf_mf_90 = 1.0 - pmf_exp(t1162 / (t1144 == 0.0 ? 1.0E-16 : t1144));
  t1144 = U_idx_0 >= t1154 ? intrm_sf_mf_90 :
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8;
  t816[0ULL] = X[86ULL];
  tlu2_linear_nearest_prelookup(&rd_efOut.mField0[0ULL], &rd_efOut.mField1[0ULL],
    &rd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = rd_efOut;
  tlu2_2d_linear_nearest_value(&sd_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = sd_efOut[0];
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 = t1033_idx_0;
  t816[0ULL] = X[87ULL];
  tlu2_linear_nearest_prelookup(&td_efOut.mField0[0ULL], &td_efOut.mField1[0ULL],
    &td_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = td_efOut;
  t816[0ULL] = t1707;
  tlu2_linear_nearest_prelookup(&ud_efOut.mField0[0ULL], &ud_efOut.mField1[0ULL],
    &ud_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t80 = ud_efOut;
  tlu2_2d_linear_nearest_value(&vd_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = vd_efOut[0];
  U_idx_0 = t1033_idx_0;
  t816[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&wd_efOut.mField0[0ULL], &wd_efOut.mField1[0ULL],
    &wd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t44 = wd_efOut;
  t816[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&xd_efOut.mField0[0ULL], &xd_efOut.mField1[0ULL],
    &xd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t85 = xd_efOut;
  tlu2_2d_linear_linear_value(&yd_efOut[0ULL], &t44.mField0[0ULL], &t44.mField2
    [0ULL], &t85.mField0[0ULL], &t85.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField4, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yd_efOut[0];
  t1154 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&ae_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ae_efOut[0];
  intrm_sf_mf_90 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&be_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = be_efOut[0];
  if (-X[4ULL] >= 0.0) {
    t1571 = -X[4ULL];
  } else {
    t1571 = X[4ULL];
  }

  t1163 = t1571 * 0.0028301886792452828;
  intrm_sf_mf_214 = t1033_idx_0 * 0.00075;
  intrm_sf_mf_81 = t1163 / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214);
  intrm_sf_mf_61 = intrm_sf_mf_81 >= 1.0 ? intrm_sf_mf_81 : 1.0;
  t1165 = pmf_log10(6.9 / (intrm_sf_mf_61 == 0.0 ? 1.0E-16 : intrm_sf_mf_61) +
                    0.00069701528436089772) * pmf_log10(6.9 / (intrm_sf_mf_61 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_61) + 0.00069701528436089772) * 3.24;
  intrm_sf_mf_61 = 1.0 / (t1165 == 0.0 ? 1.0E-16 : t1165);
  intrm_sf_mf_176 = (pmf_pow
                     (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8,
                      0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_61 /
    8.0) * 12.7 + 1.0;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 =
    ((intrm_sf_mf_81 > 1000.0 ? intrm_sf_mf_81 : 1000.0) - 1000.0) *
    (intrm_sf_mf_61 / 8.0) *
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 /
    (intrm_sf_mf_176 == 0.0 ? 1.0E-16 : intrm_sf_mf_176);
  intrm_sf_mf_61 = (intrm_sf_mf_81 - 2000.0) / 2000.0;
  intrm_sf_mf_127 = intrm_sf_mf_61 * intrm_sf_mf_61 * 3.0 - intrm_sf_mf_61 *
    intrm_sf_mf_61 * intrm_sf_mf_61 * 2.0;
  if (intrm_sf_mf_81 <= 2000.0) {
    intrm_sf_mf_61 = 3.66;
  } else if (intrm_sf_mf_81 >= 4000.0) {
    intrm_sf_mf_61 =
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8;
  } else {
    intrm_sf_mf_61 = (1.0 - intrm_sf_mf_127) * 3.66 +
      Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 *
      intrm_sf_mf_127;
  }

  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 =
    intrm_sf_mf_90 * intrm_sf_mf_61 / 2.830188679245283E-5;
  tlu2_2d_linear_nearest_value(&ce_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ce_efOut[0];
  intrm_sf_mf_90 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&de_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = de_efOut[0];
  intrm_sf_mf_61 = X[35ULL] >= 0.0 ? X[35ULL] : -X[35ULL];
  t1170 = intrm_sf_mf_61 * 0.0028301886792452828;
  t1171 = t1033_idx_0 * 0.00075;
  intrm_sf_mf_81 = t1170 / (t1171 == 0.0 ? 1.0E-16 : t1171);
  intrm_sf_mf_127 = intrm_sf_mf_81 >= 1.0 ? intrm_sf_mf_81 : 1.0;
  t1172 = pmf_log10(6.9 / (intrm_sf_mf_127 == 0.0 ? 1.0E-16 : intrm_sf_mf_127) +
                    0.00069701528436089772) * pmf_log10(6.9 / (intrm_sf_mf_127 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_127) + 0.00069701528436089772) * 3.24;
  intrm_sf_mf_127 = 1.0 / (t1172 == 0.0 ? 1.0E-16 : t1172);
  t1174 = (pmf_pow(U_idx_0, 0.66666666666666663) - 1.0) * pmf_sqrt
    (intrm_sf_mf_127 / 8.0) * 12.7 + 1.0;
  U_idx_0 = ((intrm_sf_mf_81 > 1000.0 ? intrm_sf_mf_81 : 1000.0) - 1000.0) *
    (intrm_sf_mf_127 / 8.0) * U_idx_0 / (t1174 == 0.0 ? 1.0E-16 : t1174);
  intrm_sf_mf_127 = (intrm_sf_mf_81 - 2000.0) / 2000.0;
  t1161 = intrm_sf_mf_127 * intrm_sf_mf_127 * 3.0 - intrm_sf_mf_127 *
    intrm_sf_mf_127 * intrm_sf_mf_127 * 2.0;
  if (intrm_sf_mf_81 <= 2000.0) {
    intrm_sf_mf_127 = 3.66;
  } else if (intrm_sf_mf_81 >= 4000.0) {
    intrm_sf_mf_127 = U_idx_0;
  } else {
    intrm_sf_mf_127 = (1.0 - t1161) * 3.66 + U_idx_0 * t1161;
  }

  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 =
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 +
     intrm_sf_mf_90 * intrm_sf_mf_127 / 2.830188679245283E-5) / 2.0;
  t816[0ULL] = X[10ULL];
  tlu2_linear_nearest_prelookup(&ee_efOut.mField0[0ULL], &ee_efOut.mField1[0ULL],
    &ee_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t90 = ee_efOut;
  t816[0ULL] = X[11ULL];
  tlu2_linear_nearest_prelookup(&fe_efOut.mField0[0ULL], &fe_efOut.mField1[0ULL],
    &fe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = fe_efOut;
  tlu2_2d_linear_nearest_value(&ge_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ge_efOut[0];
  intrm_sf_mf_90 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&he_efOut[0ULL], &t44.mField0[0ULL], &t44.mField2
    [0ULL], &t85.mField0[0ULL], &t85.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = he_efOut[0];
  intrm_sf_mf_81 = t1033_idx_0;
  t816[0ULL] = X[94ULL];
  tlu2_linear_nearest_prelookup(&ie_efOut.mField0[0ULL], &ie_efOut.mField1[0ULL],
    &ie_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t45 = ie_efOut;
  t816[0ULL] = X[13ULL];
  tlu2_linear_nearest_prelookup(&je_efOut.mField0[0ULL], &je_efOut.mField1[0ULL],
    &je_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t118 = je_efOut;
  tlu2_2d_linear_nearest_value(&ke_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ke_efOut[0];
  intrm_sf_mf_127 = t1033_idx_0;
  t816[0ULL] = X[96ULL];
  tlu2_linear_nearest_prelookup(&le_efOut.mField0[0ULL], &le_efOut.mField1[0ULL],
    &le_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t70 = le_efOut;
  tlu2_2d_linear_nearest_value(&me_efOut[0ULL], &t70.mField0[0ULL],
    &t70.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = me_efOut[0];
  t1161 = t1033_idx_0;
  t816[0ULL] = X[14ULL];
  tlu2_linear_nearest_prelookup(&ne_efOut.mField0[0ULL], &ne_efOut.mField1[0ULL],
    &ne_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = ne_efOut;
  tlu2_2d_linear_nearest_value(&oe_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = oe_efOut[0];
  t1162 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&pe_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = pe_efOut[0];
  intrm_sf_mf_214 = t1033_idx_0;
  t1165 = (X[12ULL] - X[14ULL]) * (t1033_idx_0 * 2.0784609690826534 / 0.01);
  intrm_sf_mf_124 = (X[100ULL] - (-X[101ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&qe_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = qe_efOut[0];
  intrm_sf_mf_176 = t1033_idx_0;
  t1387 = intrm_sf_mf_124 * 0.01;
  t1392 = t1033_idx_0 * 0.0015;
  t1168 = t1387 / (t1392 == 0.0 ? 1.0E-16 : t1392);
  t1169 = pmf_sqrt(X[100ULL] * X[100ULL] + 2.8825276676098833E-12);
  t816[0ULL] = X[102ULL];
  tlu2_linear_linear_prelookup(&re_efOut.mField0[0ULL], &re_efOut.mField1[0ULL],
    &re_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t81 = re_efOut;
  t816[0ULL] = X[95ULL];
  tlu2_linear_linear_prelookup(&se_efOut.mField0[0ULL], &se_efOut.mField1[0ULL],
    &se_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t35 = se_efOut;
  tlu2_2d_linear_linear_value(&te_efOut[0ULL], &t81.mField0[0ULL], &t81.mField2
    [0ULL], &t35.mField0[0ULL], &t35.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = te_efOut[0];
  t1172 = X[100ULL] / (t1169 == 0.0 ? 1.0E-16 : t1169) * X[95ULL] / (t1033_idx_0
    == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1171 = (1.0 - X[100ULL] / (t1169 == 0.0 ? 1.0E-16 : t1169)) / 2.0;
  t1173 = (X[100ULL] / (t1169 == 0.0 ? 1.0E-16 : t1169) + 1.0) / 2.0;
  t816[0ULL] = X[94ULL];
  tlu2_linear_linear_prelookup(&ue_efOut.mField0[0ULL], &ue_efOut.mField1[0ULL],
    &ue_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t75 = ue_efOut;
  tlu2_2d_linear_linear_value(&ve_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t35.mField0[0ULL], &t35.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ve_efOut[0];
  t1174 = t1033_idx_0;
  t1175 = pmf_sqrt(X[101ULL] * X[101ULL] + 2.8825276676098833E-12);
  t816[0ULL] = X[104ULL];
  tlu2_linear_linear_prelookup(&we_efOut.mField0[0ULL], &we_efOut.mField1[0ULL],
    &we_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t34 = we_efOut;
  t816[0ULL] = X[97ULL];
  tlu2_linear_linear_prelookup(&xe_efOut.mField0[0ULL], &xe_efOut.mField1[0ULL],
    &xe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t33 = xe_efOut;
  tlu2_2d_linear_linear_value(&ye_efOut[0ULL], &t34.mField0[0ULL], &t34.mField2
    [0ULL], &t33.mField0[0ULL], &t33.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ye_efOut[0];
  t1177 = -X[101ULL] / (t1175 == 0.0 ? 1.0E-16 : t1175) * X[97ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1176 = (1.0 - -X[101ULL] / (t1175 == 0.0 ? 1.0E-16 : t1175)) / 2.0;
  t1178 = (-X[101ULL] / (t1175 == 0.0 ? 1.0E-16 : t1175) + 1.0) / 2.0;
  t816[0ULL] = X[96ULL];
  tlu2_linear_linear_prelookup(&af_efOut.mField0[0ULL], &af_efOut.mField1[0ULL],
    &af_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = af_efOut;
  tlu2_2d_linear_linear_value(&bf_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t33.mField0[0ULL], &t33.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = bf_efOut[0];
  t1179 = t1033_idx_0;
  t816[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&cf_efOut.mField0[0ULL], &cf_efOut.mField1[0ULL],
    &cf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = cf_efOut;
  t816[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&df_efOut.mField0[0ULL], &df_efOut.mField1[0ULL],
    &df_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = df_efOut;
  tlu2_2d_linear_linear_value(&ef_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ef_efOut[0];
  t1579 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&ff_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ff_efOut[0];
  t1183 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&gf_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = gf_efOut[0];
  intrm_sf_mf_221 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&hf_efOut[0ULL], &t70.mField0[0ULL],
    &t70.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hf_efOut[0];
  t1186 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&if_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = if_efOut[0];
  t1188 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&jf_efOut[0ULL], &t70.mField0[0ULL],
    &t70.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = jf_efOut[0];
  intrm_sf_mf_217 = t1033_idx_0;
  t816[0ULL] = X[106ULL];
  tlu2_linear_nearest_prelookup(&kf_efOut.mField0[0ULL], &kf_efOut.mField1[0ULL],
    &kf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t90 = kf_efOut;
  t816[0ULL] = X[17ULL];
  tlu2_linear_nearest_prelookup(&lf_efOut.mField0[0ULL], &lf_efOut.mField1[0ULL],
    &lf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t111 = lf_efOut;
  tlu2_2d_linear_nearest_value(&mf_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = mf_efOut[0];
  t1576 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&nf_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = nf_efOut[0];
  t1542 = t1033_idx_0;
  t816[0ULL] = X[18ULL];
  tlu2_linear_nearest_prelookup(&of_efOut.mField0[0ULL], &of_efOut.mField1[0ULL],
    &of_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = of_efOut;
  tlu2_2d_linear_nearest_value(&pf_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = pf_efOut[0];
  t1485 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&qf_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = qf_efOut[0];
  t1543 = t1033_idx_0;
  Subsystem_Reference_Pipe_TL2_Q_cond = (X[113ULL] - X[18ULL]) * (t1033_idx_0 *
    0.02777777777777778 / 0.1413716694115407);
  t1539 = (X[110ULL] - (-X[100ULL])) / 2.0;
  tlu2_2d_linear_nearest_value(&rf_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = rf_efOut[0];
  t1527 = t1033_idx_0;
  t1197 = t1539 * 0.1413716694115407;
  t1198 = t1033_idx_0 * 0.0019634954084936209;
  t1528 = t1197 / (t1198 == 0.0 ? 1.0E-16 : t1198);
  Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs = pmf_sqrt(X[110ULL] * X
    [110ULL] + 3.7732198934718893E-12);
  t816[0ULL] = X[115ULL];
  tlu2_linear_linear_prelookup(&sf_efOut.mField0[0ULL], &sf_efOut.mField1[0ULL],
    &sf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t53 = sf_efOut;
  t816[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&tf_efOut.mField0[0ULL], &tf_efOut.mField1[0ULL],
    &tf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t50 = tf_efOut;
  tlu2_2d_linear_linear_value(&uf_efOut[0ULL], &t53.mField0[0ULL], &t53.mField2
    [0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = uf_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_A_pv = X[110ULL] /
    (Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs) * X[107ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Subsystem_Reference_Pipe_TL2_convection_A_step_neg = (1.0 - X[110ULL] /
    (Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs)) / 2.0;
  t1200 = (X[110ULL] / (Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs ==
                        0.0 ? 1.0E-16 :
                        Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&vf_efOut.mField0[0ULL], &vf_efOut.mField1[0ULL],
    &vf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = vf_efOut;
  tlu2_2d_linear_linear_value(&wf_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = wf_efOut[0];
  t1202 = t1033_idx_0;
  t1204 = pmf_sqrt(X[100ULL] * X[100ULL] + 3.7732198934718893E-12);
  t816[0ULL] = X[117ULL];
  tlu2_linear_linear_prelookup(&xf_efOut.mField0[0ULL], &xf_efOut.mField1[0ULL],
    &xf_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t97 = xf_efOut;
  tlu2_2d_linear_linear_value(&yf_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t35.mField0[0ULL], &t35.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yf_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_B_pv = -X[100ULL] / (t1204 == 0.0 ?
    1.0E-16 : t1204) * X[95ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Subsystem_Reference_Pipe_TL2_convection_B_step_neg = (1.0 - -X[100ULL] /
    (t1204 == 0.0 ? 1.0E-16 : t1204)) / 2.0;
  t1205 = (-X[100ULL] / (t1204 == 0.0 ? 1.0E-16 : t1204) + 1.0) / 2.0;
  t816[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&ag_efOut.mField0[0ULL], &ag_efOut.mField1[0ULL],
    &ag_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t75 = ag_efOut;
  t816[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&bg_efOut.mField0[0ULL], &bg_efOut.mField1[0ULL],
    &bg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = bg_efOut;
  tlu2_2d_linear_linear_value(&cg_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = cg_efOut[0];
  t1529 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&dg_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = dg_efOut[0];
  t1208 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&eg_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = eg_efOut[0];
  t1416 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&fg_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fg_efOut[0];
  Subsystem_Reference_Pipe_TL2_k_B_in = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&gg_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = gg_efOut[0];
  t1413 = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&hg_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t111.mField0[0ULL], &t111.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hg_efOut[0];
  t1415 = t1033_idx_0;
  t816[0ULL] = X[111ULL];
  tlu2_linear_nearest_prelookup(&ig_efOut.mField0[0ULL], &ig_efOut.mField1[0ULL],
    &ig_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t90 = ig_efOut;
  t816[0ULL] = X[19ULL];
  tlu2_linear_nearest_prelookup(&jg_efOut.mField0[0ULL], &jg_efOut.mField1[0ULL],
    &jg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t118 = jg_efOut;
  tlu2_2d_linear_nearest_value(&kg_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = kg_efOut[0];
  Subsystem_Reference_Pipe_TL4_Pr_A_in = t1033_idx_0;
  t816[0ULL] = X[119ULL];
  tlu2_linear_nearest_prelookup(&lg_efOut.mField0[0ULL], &lg_efOut.mField1[0ULL],
    &lg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = lg_efOut;
  tlu2_2d_linear_nearest_value(&mg_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = mg_efOut[0];
  Subsystem_Reference_Pipe_TL4_Pr_B_in = t1033_idx_0;
  t816[0ULL] = X[20ULL];
  tlu2_linear_nearest_prelookup(&ng_efOut.mField0[0ULL], &ng_efOut.mField1[0ULL],
    &ng_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t45 = ng_efOut;
  tlu2_2d_linear_nearest_value(&og_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField6, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = og_efOut[0];
  Subsystem_Reference_Pipe_TL4_Pr_I = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&pg_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = pg_efOut[0];
  Subsystem_Reference_Pipe_TL4_k_I = t1033_idx_0;
  Subsystem_Reference_Pipe_TL4_Q_cond = (X[114ULL] - X[20ULL]) * (t1033_idx_0 *
    0.02777777777777778 / 0.1413716694115407);
  t1211 = -X[8ULL] - X[110ULL];
  Subsystem_Reference_Pipe_TL4_mdot_avg = (-X[16ULL] - t1211) / 2.0;
  tlu2_2d_linear_nearest_value(&qg_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = qg_efOut[0];
  t1212 = t1033_idx_0;
  t1213 = Subsystem_Reference_Pipe_TL4_mdot_avg * 0.1413716694115407;
  t1214 = t1033_idx_0 * 0.0019634954084936209;
  Subsystem_Reference_Pipe_TL4_Re_avg = t1213 / (t1214 == 0.0 ? 1.0E-16 : t1214);
  Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs = pmf_sqrt(X[16ULL] * X
    [16ULL] + 3.7732198934718893E-12);
  t816[0ULL] = X[122ULL];
  tlu2_linear_linear_prelookup(&rg_efOut.mField0[0ULL], &rg_efOut.mField1[0ULL],
    &rg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t64 = rg_efOut;
  t816[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&sg_efOut.mField0[0ULL], &sg_efOut.mField1[0ULL],
    &sg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t27 = sg_efOut;
  tlu2_2d_linear_linear_value(&tg_efOut[0ULL], &t64.mField0[0ULL], &t64.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = tg_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_A_pv = -X[16ULL] /
    (Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs) * X[112ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Subsystem_Reference_Pipe_TL4_convection_A_step_neg = (1.0 - -X[16ULL] /
    (Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs)) / 2.0;
  t1215 = (-X[16ULL] / (Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs ==
                        0.0 ? 1.0E-16 :
                        Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&ug_efOut.mField0[0ULL], &ug_efOut.mField1[0ULL],
    &ug_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = ug_efOut;
  tlu2_2d_linear_linear_value(&vg_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = vg_efOut[0];
  t1216 = t1033_idx_0;
  t1218 = pmf_sqrt(t1211 * t1211 + 3.7732198934718893E-12);
  t816[0ULL] = X[124ULL];
  tlu2_linear_linear_prelookup(&wg_efOut.mField0[0ULL], &wg_efOut.mField1[0ULL],
    &wg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t21 = wg_efOut;
  t816[0ULL] = X[120ULL];
  tlu2_linear_linear_prelookup(&xg_efOut.mField0[0ULL], &xg_efOut.mField1[0ULL],
    &xg_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t80 = xg_efOut;
  tlu2_2d_linear_linear_value(&yg_efOut[0ULL], &t21.mField0[0ULL], &t21.mField2
    [0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yg_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_B_pv = t1211 / (t1218 == 0.0 ? 1.0E-16
    : t1218) * X[120ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1220 = (1.0 - t1211 / (t1218 == 0.0 ? 1.0E-16 : t1218)) / 2.0;
  t1221 = (t1211 / (t1218 == 0.0 ? 1.0E-16 : t1218) + 1.0) / 2.0;
  t816[0ULL] = X[119ULL];
  tlu2_linear_linear_prelookup(&ah_efOut.mField0[0ULL], &ah_efOut.mField1[0ULL],
    &ah_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = ah_efOut;
  tlu2_2d_linear_linear_value(&bh_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = bh_efOut[0];
  t1222 = t1033_idx_0;
  t816[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&ch_efOut.mField0[0ULL], &ch_efOut.mField1[0ULL],
    &ch_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t79 = ch_efOut;
  t816[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&dh_efOut.mField0[0ULL], &dh_efOut.mField1[0ULL],
    &dh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t95 = dh_efOut;
  tlu2_2d_linear_linear_value(&eh_efOut[0ULL], &t79.mField0[0ULL], &t79.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = eh_efOut[0];
  t1223 = t1033_idx_0;
  tlu2_2d_linear_linear_value(&fh_efOut[0ULL], &t79.mField0[0ULL], &t79.mField2
    [0ULL], &t95.mField0[0ULL], &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fh_efOut[0];
  Subsystem_Reference_Pipe_TL4_u_I = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&gh_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = gh_efOut[0];
  Subsystem_Reference_Pipe_TL4_k_A_in = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&hh_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField7, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hh_efOut[0];
  Subsystem_Reference_Pipe_TL4_k_B_in = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&ih_efOut[0ULL], &t90.mField0[0ULL],
    &t90.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ih_efOut[0];
  Subsystem_Reference_Pipe_TL4_mu_A_in = t1033_idx_0;
  tlu2_2d_linear_nearest_value(&jh_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t118.mField0[0ULL], &t118.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = jh_efOut[0];
  Subsystem_Reference_Pipe_TL4_mu_B_in = t1033_idx_0;
  Subsystem_Reference_TCP_6812_convection_A_mdot_abs = pmf_sqrt(X[110ULL] * X
    [110ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[128ULL];
  tlu2_linear_linear_prelookup(&kh_efOut.mField0[0ULL], &kh_efOut.mField1[0ULL],
    &kh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t111 = kh_efOut;
  t816[0ULL] = X[127ULL];
  tlu2_linear_linear_prelookup(&lh_efOut.mField0[0ULL], &lh_efOut.mField1[0ULL],
    &lh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t70 = lh_efOut;
  tlu2_2d_linear_linear_value(&mh_efOut[0ULL], &t111.mField0[0ULL],
    &t111.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = mh_efOut[0];
  Subsystem_Reference_TCP_6812_convection_A_rho = t1033_idx_0;
  Subsystem_Reference_TCP_6812_convection_A_pv = X[110ULL] /
    (Subsystem_Reference_TCP_6812_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_TCP_6812_convection_A_mdot_abs) * X[127ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1225 = (1.0 - X[110ULL] / (Subsystem_Reference_TCP_6812_convection_A_mdot_abs
            == 0.0 ? 1.0E-16 :
            Subsystem_Reference_TCP_6812_convection_A_mdot_abs)) / 2.0;
  t1227 = (X[110ULL] / (Subsystem_Reference_TCP_6812_convection_A_mdot_abs ==
                        0.0 ? 1.0E-16 :
                        Subsystem_Reference_TCP_6812_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[126ULL];
  tlu2_linear_linear_prelookup(&nh_efOut.mField0[0ULL], &nh_efOut.mField1[0ULL],
    &nh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = nh_efOut;
  tlu2_2d_linear_linear_value(&oh_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = oh_efOut[0];
  t1229 = t1033_idx_0;
  t816[0ULL] = X[130ULL];
  tlu2_linear_linear_prelookup(&ph_efOut.mField0[0ULL], &ph_efOut.mField1[0ULL],
    &ph_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t29 = ph_efOut;
  tlu2_2d_linear_linear_value(&qh_efOut[0ULL], &t29.mField0[0ULL], &t29.mField2
    [0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = qh_efOut[0];
  Subsystem_Reference_TCP_6812_convection_B_pv = -X[110ULL] /
    (Subsystem_Reference_TCP_6812_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_TCP_6812_convection_A_mdot_abs) * X[107ULL] /
    (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  Subsystem_Reference_TCP_6812_convection_B_step_neg = (1.0 - -X[110ULL] /
    (Subsystem_Reference_TCP_6812_convection_A_mdot_abs == 0.0 ? 1.0E-16 :
     Subsystem_Reference_TCP_6812_convection_A_mdot_abs)) / 2.0;
  t1230 = (-X[110ULL] / (Subsystem_Reference_TCP_6812_convection_A_mdot_abs ==
            0.0 ? 1.0E-16 : Subsystem_Reference_TCP_6812_convection_A_mdot_abs)
           + 1.0) / 2.0;
  t1231 = X[110ULL] / (Subsystem_Reference_TCP_6812_convection_A_rho == 0.0 ?
                       1.0E-16 : Subsystem_Reference_TCP_6812_convection_A_rho);
  t816[0ULL] = t1231 * 1.0E+6;
  t708[0] = 15ULL;
  tlu2_linear_linear_prelookup(&rh_efOut.mField0[0ULL], &rh_efOut.mField1[0ULL],
    &rh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField11, &t816[0ULL],
    &t708[0ULL], &t121[0ULL]);
  t101 = rh_efOut;
  t816[0ULL] = U_idx_6 * 0.10471975511965977;
  t699[0] = 8ULL;
  tlu2_linear_linear_prelookup(&sh_efOut.mField0[0ULL], &sh_efOut.mField1[0ULL],
    &sh_efOut.mField2[0ULL], &nonscalar12[0ULL], &t816[0ULL], &t699[0ULL],
    &t121[0ULL]);
  t79 = sh_efOut;
  tlu2_2d_linear_linear_value(&th_efOut[0ULL], &t101.mField0[0ULL],
    &t101.mField2[0ULL], &t79.mField0[0ULL], &t79.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField10, &t708[0ULL], &t699[0ULL], &t121[0ULL]);
  t1033_idx_0 = th_efOut[0];
  t1199 = Subsystem_Reference_TCP_6812_convection_A_rho * t1033_idx_0 * 9.81;
  t1190 = t1199 * t1231;
  tlu2_2d_linear_linear_value(&uh_efOut[0ULL], &t101.mField0[0ULL],
    &t101.mField2[0ULL], &t79.mField0[0ULL], &t79.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField12, &t708[0ULL], &t699[0ULL], &t121[0ULL]);
  t1033_idx_0 = uh_efOut[0];
  t1231 = t1033_idx_0;
  t816[0ULL] = U_idx_7 * -0.001 + 0.0025;
  t708[0] = 11ULL;
  tlu2_linear_nearest_prelookup(&vh_efOut.mField0[0ULL], &vh_efOut.mField1[0ULL],
    &vh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t816[0ULL],
    &t708[0ULL], &t121[0ULL]);
  t95 = vh_efOut;
  tlu2_1d_linear_nearest_value(&wh_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t708[0ULL], &t121
    [0ULL]);
  t1033_idx_0 = wh_efOut[0];
  t1233 = t1033_idx_0;
  t1235 = t1033_idx_0 / 0.0019634954084936209;
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs = pmf_sqrt
    (t1211 * t1211 + 9.4330497336797231E-11);
  t816[0ULL] = X[131ULL];
  tlu2_linear_linear_prelookup(&xh_efOut.mField0[0ULL], &xh_efOut.mField1[0ULL],
    &xh_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t90 = xh_efOut;
  tlu2_2d_linear_linear_value(&yh_efOut[0ULL], &t90.mField0[0ULL], &t90.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = yh_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg = t1033_idx_0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_pv = t1211 /
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs == 0.0 ?
     1.0E-16 : Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs) *
    X[127ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1237 = (1.0 - t1211 /
           (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs ==
            0.0 ? 1.0E-16 :
            Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs)) /
    2.0;
  t1238 = (t1211 /
           (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs ==
            0.0 ? 1.0E-16 :
            Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[133ULL];
  tlu2_linear_linear_prelookup(&ai_efOut.mField0[0ULL], &ai_efOut.mField1[0ULL],
    &ai_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t101 = ai_efOut;
  tlu2_2d_linear_linear_value(&bi_efOut[0ULL], &t101.mField0[0ULL],
    &t101.mField2[0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = bi_efOut[0];
  t1239 = t1033_idx_0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_pv = -t1211 /
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs == 0.0 ?
     1.0E-16 : Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs) *
    X[120ULL] / (t1033_idx_0 == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1241 = (1.0 - -t1211 /
           (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs ==
            0.0 ? 1.0E-16 :
            Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs)) /
    2.0;
  t1240 = (-t1211 /
           (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs ==
            0.0 ? 1.0E-16 :
            Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs) +
           1.0) / 2.0;
  t816[0ULL] = X[131ULL];
  tlu2_linear_nearest_prelookup(&ci_efOut.mField0[0ULL], &ci_efOut.mField1[0ULL],
    &ci_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t79 = ci_efOut;
  t816[0ULL] = X[127ULL];
  tlu2_linear_nearest_prelookup(&di_efOut.mField0[0ULL], &di_efOut.mField1[0ULL],
    &di_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t93 = di_efOut;
  tlu2_2d_linear_nearest_value(&ei_efOut[0ULL], &t79.mField0[0ULL],
    &t79.mField2[0ULL], &t93.mField0[0ULL], &t93.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ei_efOut[0];
  t1243 = t1033_idx_0;
  t816[0ULL] = X[133ULL];
  tlu2_linear_nearest_prelookup(&fi_efOut.mField0[0ULL], &fi_efOut.mField1[0ULL],
    &fi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t79 = fi_efOut;
  t816[0ULL] = X[120ULL];
  tlu2_linear_nearest_prelookup(&gi_efOut.mField0[0ULL], &gi_efOut.mField1[0ULL],
    &gi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t45 = gi_efOut;
  tlu2_2d_linear_nearest_value(&hi_efOut[0ULL], &t79.mField0[0ULL],
    &t79.mField2[0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hi_efOut[0];
  t1243 = (t1243 + t1033_idx_0) / 2.0;
  t1245 = X[127ULL] - X[120ULL];
  Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg =
    (Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg + t1239) / 2.0;
  t1249 = t1233 * Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg * 2.0;
  t1239 = t1243 * t1243 * 0.78539816339744828 / (t1249 == 0.0 ? 1.0E-16 : t1249)
    * 293.87755102040813;
  t816[0ULL] = U_idx_7 * 0.001 + 0.0025;
  tlu2_linear_nearest_prelookup(&ii_efOut.mField0[0ULL], &ii_efOut.mField1[0ULL],
    &ii_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t816[0ULL],
    &t708[0ULL], &t121[0ULL]);
  t95 = ii_efOut;
  tlu2_1d_linear_nearest_value(&ji_efOut[0ULL], &t95.mField0[0ULL],
    &t95.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t708[0ULL], &t121
    [0ULL]);
  t1033_idx_0 = ji_efOut[0];
  t1243 = t1033_idx_0;
  t1246 = t1033_idx_0 / 0.0019634954084936209;
  t816[0ULL] = X[134ULL];
  tlu2_linear_linear_prelookup(&ki_efOut.mField0[0ULL], &ki_efOut.mField1[0ULL],
    &ki_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t79 = ki_efOut;
  tlu2_2d_linear_linear_value(&li_efOut[0ULL], &t79.mField0[0ULL], &t79.mField2
    [0ULL], &t72.mField0[0ULL], &t72.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = li_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg = t1033_idx_0;
  t1248 = -X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) * X[40ULL] / (t1033_idx_0 ==
    0.0 ? 1.0E-16 : t1033_idx_0);
  t1249 = (1.0 - -X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142)) / 2.0;
  t1250 = (-X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) + 1.0) / 2.0;
  t816[0ULL] = X[136ULL];
  tlu2_linear_linear_prelookup(&mi_efOut.mField0[0ULL], &mi_efOut.mField1[0ULL],
    &mi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t75 = mi_efOut;
  tlu2_2d_linear_linear_value(&ni_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ni_efOut[0];
  t1251 = t1033_idx_0;
  t1145 = X[8ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) * X[127ULL] / (t1033_idx_0 ==
    0.0 ? 1.0E-16 : t1033_idx_0);
  t816[0ULL] = X[134ULL];
  tlu2_linear_nearest_prelookup(&oi_efOut.mField0[0ULL], &oi_efOut.mField1[0ULL],
    &oi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t36 = oi_efOut;
  tlu2_2d_linear_nearest_value(&pi_efOut[0ULL], &t36.mField0[0ULL],
    &t36.mField2[0ULL], &t4.mField0[0ULL], &t4.mField2[0ULL], ((_NeDynamicSystem*)
    (LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = pi_efOut[0];
  U_idx_2 = t1033_idx_0;
  t816[0ULL] = X[136ULL];
  tlu2_linear_nearest_prelookup(&qi_efOut.mField0[0ULL], &qi_efOut.mField1[0ULL],
    &qi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t109 = qi_efOut;
  tlu2_2d_linear_nearest_value(&ri_efOut[0ULL], &t109.mField0[0ULL],
    &t109.mField2[0ULL], &t93.mField0[0ULL], &t93.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ri_efOut[0];
  U_idx_2 = (U_idx_2 + t1033_idx_0) / 2.0;
  t1255 = X[40ULL] - X[127ULL];
  Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg =
    (Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg + t1251) / 2.0;
  t1261 = t1243 * Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg * 2.0;
  t1251 = U_idx_2 * U_idx_2 * 0.78539816339744828 / (t1261 == 0.0 ? 1.0E-16 :
    t1261) * 293.87755102040813;
  t816[0ULL] = X[137ULL];
  tlu2_linear_nearest_prelookup(&si_efOut.mField0[0ULL], &si_efOut.mField1[0ULL],
    &si_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t4 = si_efOut;
  t816[0ULL] = X[97ULL];
  tlu2_linear_nearest_prelookup(&ti_efOut.mField0[0ULL], &ti_efOut.mField1[0ULL],
    &ti_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t93 = ti_efOut;
  tlu2_2d_linear_nearest_value(&ui_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t93.mField0[0ULL], &t93.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = ui_efOut[0];
  U_idx_2 = t1033_idx_0;
  t816[0ULL] = X[138ULL];
  tlu2_linear_nearest_prelookup(&vi_efOut.mField0[0ULL], &vi_efOut.mField1[0ULL],
    &vi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = vi_efOut;
  t816[0ULL] = X[38ULL];
  tlu2_linear_nearest_prelookup(&wi_efOut.mField0[0ULL], &wi_efOut.mField1[0ULL],
    &wi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t4 = wi_efOut;
  tlu2_2d_linear_nearest_value(&xi_efOut[0ULL], &t58.mField0[0ULL],
    &t58.mField2[0ULL], &t4.mField0[0ULL], &t4.mField2[0ULL], ((_NeDynamicSystem*)
    (LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = xi_efOut[0];
  t1257 = t1033_idx_0;
  t816[0ULL] = X[139ULL];
  tlu2_linear_nearest_prelookup(&yi_efOut.mField0[0ULL], &yi_efOut.mField1[0ULL],
    &yi_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t36 = yi_efOut;
  t816[0ULL] = X[112ULL];
  tlu2_linear_nearest_prelookup(&aj_efOut.mField0[0ULL], &aj_efOut.mField1[0ULL],
    &aj_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t816[0ULL],
    &t123[0ULL], &t121[0ULL]);
  t93 = aj_efOut;
  tlu2_2d_linear_nearest_value(&bj_efOut[0ULL], &t36.mField0[0ULL],
    &t36.mField2[0ULL], &t93.mField0[0ULL], &t93.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = bj_efOut[0];
  U_idx_2 = ((U_idx_2 * 0.0019634954084936209 + t1257 * 0.0019634954084936209) +
             t1033_idx_0 * 0.0019634954084936209) / 0.0058904862254808626;
  t1257 = pmf_sqrt(X[101ULL] * X[101ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[137ULL];
  tlu2_linear_linear_prelookup(&cj_efOut.mField0[0ULL], &cj_efOut.mField1[0ULL],
    &cj_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t118 = cj_efOut;
  tlu2_2d_linear_linear_value(&dj_efOut[0ULL], &t118.mField0[0ULL],
    &t118.mField2[0ULL], &t33.mField0[0ULL], &t33.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = dj_efOut[0];
  Subsystem_Reference_T_Junction_TL_rho_avg = t1033_idx_0;
  t1259 = X[101ULL] / (t1257 == 0.0 ? 1.0E-16 : t1257) * X[97ULL] / (t1033_idx_0
    == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1260 = (1.0 - X[101ULL] / (t1257 == 0.0 ? 1.0E-16 : t1257)) / 2.0;
  t1261 = (X[101ULL] / (t1257 == 0.0 ? 1.0E-16 : t1257) + 1.0) / 2.0;
  t1262 = pmf_sqrt(X[7ULL] * X[7ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[138ULL];
  tlu2_linear_linear_prelookup(&ej_efOut.mField0[0ULL], &ej_efOut.mField1[0ULL],
    &ej_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t58 = ej_efOut;
  tlu2_2d_linear_linear_value(&fj_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t110.mField0[0ULL], &t110.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = fj_efOut[0];
  U_idx_3 = t1033_idx_0;
  t1264 = X[7ULL] / (t1262 == 0.0 ? 1.0E-16 : t1262) * X[38ULL] / (t1033_idx_0 ==
    0.0 ? 1.0E-16 : t1033_idx_0);
  t1266 = (1.0 - X[7ULL] / (t1262 == 0.0 ? 1.0E-16 : t1262)) / 2.0;
  t1268 = (X[7ULL] / (t1262 == 0.0 ? 1.0E-16 : t1262) + 1.0) / 2.0;
  t1269 = pmf_sqrt(X[16ULL] * X[16ULL] + 9.4330497336797231E-11);
  t816[0ULL] = X[139ULL];
  tlu2_linear_linear_prelookup(&gj_efOut.mField0[0ULL], &gj_efOut.mField1[0ULL],
    &gj_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t45 = gj_efOut;
  tlu2_2d_linear_linear_value(&hj_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = hj_efOut[0];
  t1272 = X[16ULL] / (t1269 == 0.0 ? 1.0E-16 : t1269) * X[112ULL] / (t1033_idx_0
    == 0.0 ? 1.0E-16 : t1033_idx_0);
  t1274 = (1.0 - X[16ULL] / (t1269 == 0.0 ? 1.0E-16 : t1269)) / 2.0;
  t1275 = (X[16ULL] / (t1269 == 0.0 ? 1.0E-16 : t1269) + 1.0) / 2.0;
  if (D_idx_2 == 2.0) {
    t1276 = 0.0;
  } else if (D_idx_2 == 3.0) {
    t1276 = 0.38;
  } else if (D_idx_2 == 4.0) {
    t1276 = 0.0;
  } else if (D_idx_2 == 5.0) {
    t1276 = 0.38;
  } else if (D_idx_2 == 6.0) {
    t1276 = 0.76;
  } else {
    t1276 = D_idx_2 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_2 == 2.0) {
    t1278 = 0.38;
  } else if (D_idx_2 == 3.0) {
    t1278 = 0.0;
  } else if (D_idx_2 == 4.0) {
    t1278 = 0.38;
  } else if (D_idx_2 == 5.0) {
    t1278 = 0.0;
  } else if (D_idx_2 == 6.0) {
    t1278 = 0.76;
  } else {
    t1278 = D_idx_2 == 7.0 ? 0.76 : 1.0;
  }

  if (D_idx_2 == 2.0) {
    t1280 = 1.14;
  } else if (D_idx_2 == 3.0) {
    t1280 = 1.14;
  } else if (D_idx_2 == 4.0) {
    t1280 = 1.14;
  } else if (D_idx_2 == 5.0) {
    t1280 = 1.14;
  } else if (D_idx_2 == 6.0) {
    t1280 = 0.0;
  } else {
    t1280 = (real_T)!(D_idx_2 == 7.0);
  }

  Subsystem_Reference_T_Junction_TL_rho_avg =
    ((Subsystem_Reference_T_Junction_TL_rho_avg * 0.0019634954084936209 +
      U_idx_3 * 0.0019634954084936209) + t1033_idx_0 * 0.0019634954084936209) /
    0.0058904862254808626;
  U_idx_1 = (intrm_sf_mf_158 + t1107) / 2.0 * 0.0019634954084936209;
  intrm_sf_mf_158 = t1409 / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1);
  U_idx_3 = intrm_sf_mf_158 >= 0.0 ? intrm_sf_mf_158 : -intrm_sf_mf_158;
  D_idx_1 = (U_idx_3 - 2000.0) / 2000.0;
  U_idx_0 = (t1188 + intrm_sf_mf_176) / 2.0 * 0.0015;
  t1188 = t1387 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  t1409 = t1188 >= 0.0 ? t1188 : -t1188;
  t1387 = t1409 > 1000.0 ? t1409 : 1000.0;
  U_idx_1 = pmf_log10(6.9 / (t1387 == 0.0 ? 1.0E-16 : t1387) +
                      0.002211858722000578) * pmf_log10(6.9 / (t1387 == 0.0 ?
    1.0E-16 : t1387) + 0.002211858722000578) * 3.24;
  D_idx_0 = 1.0 / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1);
  U_idx_1 = intrm_sf_mf_127 + t1162;
  if ((pmf_pow(U_idx_1 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(D_idx_0 /
       8.0) * 12.7 + 1.0 >= 1.0E-6) {
    U_idx_0 = (pmf_pow((intrm_sf_mf_127 + t1162) / 2.0, 0.66666666666666663) -
               1.0) * pmf_sqrt(D_idx_0 / 8.0) * 12.7 + 1.0;
    U_idx_0 = (t1387 - 1000.0) * (D_idx_0 / 8.0) * ((intrm_sf_mf_127 + t1162) /
      2.0) / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    U_idx_0 = (t1387 - 1000.0) * (D_idx_0 / 8.0) * ((intrm_sf_mf_127 + t1162) /
      2.0) / 1.0E-6;
  }

  t1387 = (t1409 - 2000.0) / 2000.0;
  D_idx_0 = t1387 * t1387 * 3.0 - t1387 * t1387 * t1387 * 2.0;
  if (t1409 <= 2000.0) {
    t1387 = 3.66;
  } else if (t1409 >= 4000.0) {
    t1387 = U_idx_0;
  } else {
    t1387 = (1.0 - D_idx_0) * 3.66 + U_idx_0 * D_idx_0;
  }

  U_idx_0 = U_idx_1 / 2.0;
  if (t1409 > t1387 * 2.0784609690826534 / 0.0015 / (U_idx_0 == 0.0 ? 1.0E-16 :
       U_idx_0) / 30.0) {
    U_idx_0 = (intrm_sf_mf_127 + t1162) / 2.0;
    D_idx_0 = t1387 * 2.0784609690826534 / (t1409 == 0.0 ? 1.0E-16 : t1409) /
      0.0015 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    D_idx_0 = 30.0;
  }

  intrm_sf_mf_127 = (X[12ULL] - X[94ULL]) * (1.0 - pmf_exp(-D_idx_0));
  intrm_sf_mf_221 = t1188 * 0.0015 / 0.01 * (U_idx_1 / 2.0) * ((intrm_sf_mf_221
    + intrm_sf_mf_214) / 2.0) * intrm_sf_mf_127;
  U_idx_0 = (intrm_sf_mf_217 + intrm_sf_mf_176) / 2.0 * 0.0015;
  intrm_sf_mf_127 = -intrm_sf_mf_124 * 0.01 / (U_idx_0 == 0.0 ? 1.0E-16 :
    U_idx_0);
  intrm_sf_mf_124 = intrm_sf_mf_127 >= 0.0 ? intrm_sf_mf_127 : -intrm_sf_mf_127;
  t1188 = intrm_sf_mf_124 > 1000.0 ? intrm_sf_mf_124 : 1000.0;
  t1387 = pmf_log10(6.9 / (t1188 == 0.0 ? 1.0E-16 : t1188) +
                    0.002211858722000578) * pmf_log10(6.9 / (t1188 == 0.0 ?
    1.0E-16 : t1188) + 0.002211858722000578) * 3.24;
  intrm_sf_mf_217 = 1.0 / (t1387 == 0.0 ? 1.0E-16 : t1387);
  t1387 = t1161 + t1162;
  if ((pmf_pow(t1387 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_217 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    U_idx_0 = (pmf_pow((t1161 + t1162) / 2.0, 0.66666666666666663) - 1.0) *
      pmf_sqrt(intrm_sf_mf_217 / 8.0) * 12.7 + 1.0;
    t1409 = (t1188 - 1000.0) * (intrm_sf_mf_217 / 8.0) * ((t1161 + t1162) / 2.0)
      / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    t1409 = (t1188 - 1000.0) * (intrm_sf_mf_217 / 8.0) * ((t1161 + t1162) / 2.0)
      / 1.0E-6;
  }

  t1188 = (intrm_sf_mf_124 - 2000.0) / 2000.0;
  intrm_sf_mf_217 = D_idx_1 * D_idx_1 * 3.0 - D_idx_1 * D_idx_1 * D_idx_1 * 2.0;
  D_idx_1 = t1188 * t1188 * 3.0 - t1188 * t1188 * t1188 * 2.0;
  if (intrm_sf_mf_124 <= 2000.0) {
    t1188 = 3.66;
  } else if (intrm_sf_mf_124 >= 4000.0) {
    t1188 = t1409;
  } else {
    t1188 = (1.0 - D_idx_1) * 3.66 + t1409 * D_idx_1;
  }

  t1409 = t1387 / 2.0;
  if (intrm_sf_mf_124 > t1188 * 2.0784609690826534 / 0.0015 / (t1409 == 0.0 ?
       1.0E-16 : t1409) / 30.0) {
    U_idx_0 = (t1161 + t1162) / 2.0;
    D_idx_1 = t1188 * 2.0784609690826534 / (intrm_sf_mf_124 == 0.0 ? 1.0E-16 :
      intrm_sf_mf_124) / 0.0015 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    D_idx_1 = 30.0;
  }

  t1161 = (X[12ULL] - X[96ULL]) * (1.0 - pmf_exp(-D_idx_1));
  intrm_sf_mf_127 = intrm_sf_mf_127 * 0.0015 / 0.01 * (t1387 / 2.0) * ((t1186 +
    intrm_sf_mf_214) / 2.0) * t1161;
  t1161 = (t1168 - -20.0) / 40.0;
  t1162 = t1161 * t1161 * 3.0 - t1161 * t1161 * t1161 * 2.0;
  if (t1168 <= -20.0) {
    t1161 = intrm_sf_mf_127 * 0.001;
  } else if (t1168 >= 20.0) {
    t1161 = intrm_sf_mf_221 * 0.001;
  } else {
    t1161 = ((1.0 - t1162) * intrm_sf_mf_127 + intrm_sf_mf_221 * t1162) * 0.001;
  }

  intrm_sf_mf_127 = X[100ULL] >= 0.0 ? X[100ULL] : -X[100ULL];
  t1162 = intrm_sf_mf_127 * 0.01 / (t1392 == 0.0 ? 1.0E-16 : t1392);
  intrm_sf_mf_214 = U_idx_3 > 1000.0 ? U_idx_3 : 1000.0;
  D_idx_1 = pmf_log10(6.9 / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214)
                      + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214) + 9.0751776413883736E-6)
    * 3.24;
  intrm_sf_mf_124 = 1.0 / (D_idx_1 == 0.0 ? 1.0E-16 : D_idx_1);
  D_idx_1 = t1104 + intrm_sf_mf_242;
  if ((pmf_pow(D_idx_1 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_124 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    U_idx_0 = (pmf_pow((t1104 + intrm_sf_mf_242) / 2.0, 0.66666666666666663) -
               1.0) * pmf_sqrt(intrm_sf_mf_124 / 8.0) * 12.7 + 1.0;
    t1168 = (intrm_sf_mf_214 - 1000.0) * (intrm_sf_mf_124 / 8.0) * ((t1104 +
      intrm_sf_mf_242) / 2.0) / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    t1168 = (intrm_sf_mf_214 - 1000.0) * (intrm_sf_mf_124 / 8.0) * ((t1104 +
      intrm_sf_mf_242) / 2.0) / 1.0E-6;
  }

  if (U_idx_3 <= 2000.0) {
    intrm_sf_mf_214 = 3.66;
  } else if (U_idx_3 >= 4000.0) {
    intrm_sf_mf_214 = t1168;
  } else {
    intrm_sf_mf_214 = (1.0 - intrm_sf_mf_217) * 3.66 + intrm_sf_mf_217 * t1168;
  }

  intrm_sf_mf_124 = t1162 >= 1.0 ? t1162 : 1.0;
  t1409 = pmf_log10(6.9 / (intrm_sf_mf_124 == 0.0 ? 1.0E-16 : intrm_sf_mf_124) +
                    0.002211858722000578) * pmf_log10(6.9 / (intrm_sf_mf_124 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_124) + 0.002211858722000578) * 3.24;
  t1387 = t1579 * 3.0000000000000004E-7;
  t1168 = X[100ULL] * intrm_sf_mf_176 * 114.05125168440817 / (t1387 == 0.0 ?
    1.0E-16 : t1387);
  D_idx_0 = t1579 * 4.5E-8;
  intrm_sf_mf_127 = X[100ULL] * intrm_sf_mf_127 * (1.0 / (t1409 == 0.0 ? 1.0E-16
    : t1409)) * 1.7820508075688777 / (D_idx_0 == 0.0 ? 1.0E-16 : D_idx_0);
  intrm_sf_mf_124 = (t1162 - 2000.0) / 2000.0;
  t1579 = intrm_sf_mf_124 * intrm_sf_mf_124 * 3.0 - intrm_sf_mf_124 *
    intrm_sf_mf_124 * intrm_sf_mf_124 * 2.0;
  if (t1162 <= 2000.0) {
    intrm_sf_mf_124 = t1168 * 1.0E-5;
  } else if (t1162 >= 4000.0) {
    intrm_sf_mf_124 = intrm_sf_mf_127 * 1.0E-5;
  } else {
    intrm_sf_mf_124 = ((1.0 - t1579) * t1168 + intrm_sf_mf_127 * t1579) * 1.0E-5;
  }

  if (-X[101ULL] >= 0.0) {
    intrm_sf_mf_127 = -X[101ULL];
  } else {
    intrm_sf_mf_127 = X[101ULL];
  }

  t1162 = intrm_sf_mf_127 * 0.01 / (t1392 == 0.0 ? 1.0E-16 : t1392);
  t1168 = t1162 >= 1.0 ? t1162 : 1.0;
  t1409 = D_idx_1 / 2.0;
  if (U_idx_3 > intrm_sf_mf_214 * 0.055555555555555559 / 0.0019634954084936209 /
      (t1409 == 0.0 ? 1.0E-16 : t1409) / 30.0) {
    U_idx_0 = (t1104 + intrm_sf_mf_242) / 2.0;
    t1579 = intrm_sf_mf_214 * 0.055555555555555559 / (U_idx_3 == 0.0 ? 1.0E-16 :
      U_idx_3) / 0.0019634954084936209 / (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0);
  } else {
    t1579 = 30.0;
  }

  U_idx_3 = pmf_log10(6.9 / (t1168 == 0.0 ? 1.0E-16 : t1168) +
                      0.002211858722000578) * pmf_log10(6.9 / (t1168 == 0.0 ?
    1.0E-16 : t1168) + 0.002211858722000578) * 3.24;
  intrm_sf_mf_214 = intrm_sf_mf_176 * X[101ULL] * -114.05125168440817 / (t1387 ==
    0.0 ? 1.0E-16 : t1387);
  t1104 = X[101ULL] * intrm_sf_mf_127 * (1.0 / (U_idx_3 == 0.0 ? 1.0E-16 :
    U_idx_3)) * -1.7820508075688777 / (D_idx_0 == 0.0 ? 1.0E-16 : D_idx_0);
  intrm_sf_mf_127 = (t1162 - 2000.0) / 2000.0;
  intrm_sf_mf_176 = intrm_sf_mf_127 * intrm_sf_mf_127 * 3.0 - intrm_sf_mf_127 *
    intrm_sf_mf_127 * intrm_sf_mf_127 * 2.0;
  if (t1162 <= 2000.0) {
    intrm_sf_mf_127 = intrm_sf_mf_214 * 1.0E-5;
  } else if (t1162 >= 4000.0) {
    intrm_sf_mf_127 = t1104 * 1.0E-5;
  } else {
    intrm_sf_mf_127 = ((1.0 - intrm_sf_mf_176) * intrm_sf_mf_214 + t1104 *
                       intrm_sf_mf_176) * 1.0E-5;
  }

  t1413 = (t1413 + t1527) / 2.0 * 0.0019634954084936209;
  t1104 = t1197 / (t1413 == 0.0 ? 1.0E-16 : t1413);
  t1162 = t1104 >= 0.0 ? t1104 : -t1104;
  intrm_sf_mf_214 = t1162 > 1000.0 ? t1162 : 1000.0;
  t1413 = pmf_log10(6.9 / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_214 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_214) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_176 = 1.0 / (t1413 == 0.0 ? 1.0E-16 : t1413);
  t1168 = (X[52ULL] - X[37ULL]) * (1.0 - pmf_exp(-t1579));
  t1413 = t1576 + t1485;
  if ((pmf_pow(t1413 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_176 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    D_idx_0 = (pmf_pow((t1576 + t1485) / 2.0, 0.66666666666666663) - 1.0) *
      pmf_sqrt(intrm_sf_mf_176 / 8.0) * 12.7 + 1.0;
    t1579 = (intrm_sf_mf_214 - 1000.0) * (intrm_sf_mf_176 / 8.0) * ((t1576 +
      t1485) / 2.0) / (D_idx_0 == 0.0 ? 1.0E-16 : D_idx_0);
  } else {
    t1579 = (intrm_sf_mf_214 - 1000.0) * (intrm_sf_mf_176 / 8.0) * ((t1576 +
      t1485) / 2.0) / 1.0E-6;
  }

  intrm_sf_mf_214 = (t1162 - 2000.0) / 2000.0;
  intrm_sf_mf_176 = intrm_sf_mf_214 * intrm_sf_mf_214 * 3.0 - intrm_sf_mf_214 *
    intrm_sf_mf_214 * intrm_sf_mf_214 * 2.0;
  if (t1162 <= 2000.0) {
    intrm_sf_mf_214 = 3.66;
  } else if (t1162 >= 4000.0) {
    intrm_sf_mf_214 = t1579;
  } else {
    intrm_sf_mf_214 = (1.0 - intrm_sf_mf_176) * 3.66 + t1579 * intrm_sf_mf_176;
  }

  U_idx_3 = t1413 / 2.0;
  if (t1162 > intrm_sf_mf_214 * 0.02777777777777778 / 0.0019634954084936209 /
      (U_idx_3 == 0.0 ? 1.0E-16 : U_idx_3) / 30.0) {
    t1392 = (t1576 + t1485) / 2.0;
    intrm_sf_mf_176 = intrm_sf_mf_214 * 0.02777777777777778 / (t1162 == 0.0 ?
      1.0E-16 : t1162) / 0.0019634954084936209 / (t1392 == 0.0 ? 1.0E-16 : t1392);
  } else {
    intrm_sf_mf_176 = 30.0;
  }

  t1162 = (X[113ULL] - X[106ULL]) * (1.0 - pmf_exp(-intrm_sf_mf_176));
  t1104 = t1104 * 0.0019634954084936209 / 0.1413716694115407 * (t1413 / 2.0) *
    ((t1416 + t1543) / 2.0) * t1162;
  t1413 = -t1539 * 0.1413716694115407;
  t1539 = (t1415 + t1527) / 2.0 * 0.0019634954084936209;
  t1162 = t1413 / (t1539 == 0.0 ? 1.0E-16 : t1539);
  intrm_sf_mf_214 = t1162 >= 0.0 ? t1162 : -t1162;
  intrm_sf_mf_176 = intrm_sf_mf_214 > 1000.0 ? intrm_sf_mf_214 : 1000.0;
  intrm_sf_mf_47 = intrm_sf_mf_158 * 0.0019634954084936209 / 0.1413716694115407 *
    (D_idx_1 / 2.0) * ((intrm_sf_mf_47 + intrm_sf_mf_84) / 2.0) * t1168;
  t1539 = pmf_log10(6.9 / (intrm_sf_mf_176 == 0.0 ? 1.0E-16 : intrm_sf_mf_176) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_176 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_176) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_158 = 1.0 / (t1539 == 0.0 ? 1.0E-16 : t1539);
  t1539 = t1542 + t1485;
  if ((pmf_pow(t1539 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_158 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    U_idx_3 = (pmf_pow((t1542 + t1485) / 2.0, 0.66666666666666663) - 1.0) *
      pmf_sqrt(intrm_sf_mf_158 / 8.0) * 12.7 + 1.0;
    t1168 = (intrm_sf_mf_176 - 1000.0) * (intrm_sf_mf_158 / 8.0) * ((t1542 +
      t1485) / 2.0) / (U_idx_3 == 0.0 ? 1.0E-16 : U_idx_3);
  } else {
    t1168 = (intrm_sf_mf_176 - 1000.0) * (intrm_sf_mf_158 / 8.0) * ((t1542 +
      t1485) / 2.0) / 1.0E-6;
  }

  intrm_sf_mf_158 = (intrm_sf_mf_214 - 2000.0) / 2000.0;
  intrm_sf_mf_176 = intrm_sf_mf_158 * intrm_sf_mf_158 * 3.0 - intrm_sf_mf_158 *
    intrm_sf_mf_158 * intrm_sf_mf_158 * 2.0;
  if (intrm_sf_mf_214 <= 2000.0) {
    intrm_sf_mf_158 = 3.66;
  } else if (intrm_sf_mf_214 >= 4000.0) {
    intrm_sf_mf_158 = t1168;
  } else {
    intrm_sf_mf_158 = (1.0 - intrm_sf_mf_176) * 3.66 + t1168 * intrm_sf_mf_176;
  }

  t1416 = t1539 / 2.0;
  if (intrm_sf_mf_214 > intrm_sf_mf_158 * 0.02777777777777778 /
      0.0019634954084936209 / (t1416 == 0.0 ? 1.0E-16 : t1416) / 30.0) {
    t1409 = (t1542 + t1485) / 2.0;
    intrm_sf_mf_176 = intrm_sf_mf_158 * 0.02777777777777778 / (intrm_sf_mf_214 ==
      0.0 ? 1.0E-16 : intrm_sf_mf_214) / 0.0019634954084936209 / (t1409 == 0.0 ?
      1.0E-16 : t1409);
  } else {
    intrm_sf_mf_176 = 30.0;
  }

  intrm_sf_mf_158 = (X[113ULL] - X[94ULL]) * (1.0 - pmf_exp(-intrm_sf_mf_176));
  t1162 = t1162 * 0.0019634954084936209 / 0.1413716694115407 * (t1539 / 2.0) *
    ((Subsystem_Reference_Pipe_TL2_k_B_in + t1543) / 2.0) * intrm_sf_mf_158;
  intrm_sf_mf_158 = (t1528 - -20.0) / 40.0;
  intrm_sf_mf_214 = intrm_sf_mf_158 * intrm_sf_mf_158 * 3.0 - intrm_sf_mf_158 *
    intrm_sf_mf_158 * intrm_sf_mf_158 * 2.0;
  t1543 = (intrm_sf_mf_23 + t1107) / 2.0 * 0.0019634954084936209;
  t1106 = -t1106 * 0.1413716694115407 / (t1543 == 0.0 ? 1.0E-16 : t1543);
  if (t1528 <= -20.0) {
    intrm_sf_mf_158 = t1162 * 0.001;
  } else if (t1528 >= 20.0) {
    intrm_sf_mf_158 = t1104 * 0.001;
  } else {
    intrm_sf_mf_158 = ((1.0 - intrm_sf_mf_214) * t1162 + t1104 * intrm_sf_mf_214)
      * 0.001;
  }

  t1104 = X[110ULL] >= 0.0 ? X[110ULL] : -X[110ULL];
  intrm_sf_mf_23 = t1104 * 0.1413716694115407 / (t1198 == 0.0 ? 1.0E-16 : t1198);
  t1162 = intrm_sf_mf_23 >= 1.0 ? intrm_sf_mf_23 : 1.0;
  t1542 = pmf_log10(6.9 / (t1162 == 0.0 ? 1.0E-16 : t1162) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (t1162 == 0.0 ?
    1.0E-16 : t1162) + 9.0751776413883736E-6) * 3.24;
  t1485 = t1529 * 7.8484637847008924E-5;
  intrm_sf_mf_214 = X[110ULL] * t1527 * 48.0 / (t1485 == 0.0 ? 1.0E-16 : t1485);
  t1543 = t1529 * 1.0900644145417907E-6;
  t1104 = X[110ULL] * t1104 * (1.0 / (t1542 == 0.0 ? 1.0E-16 : t1542)) * 0.75 /
    (t1543 == 0.0 ? 1.0E-16 : t1543);
  t1162 = (intrm_sf_mf_23 - 2000.0) / 2000.0;
  intrm_sf_mf_176 = t1162 * t1162 * 3.0 - t1162 * t1162 * t1162 * 2.0;
  if (intrm_sf_mf_23 <= 2000.0) {
    t1162 = intrm_sf_mf_214 * 1.0E-5;
  } else if (intrm_sf_mf_23 >= 4000.0) {
    t1162 = t1104 * 1.0E-5;
  } else {
    t1162 = ((1.0 - intrm_sf_mf_176) * intrm_sf_mf_214 + t1104 * intrm_sf_mf_176)
      * 1.0E-5;
  }

  t1104 = t1106 >= 0.0 ? t1106 : -t1106;
  if (-X[100ULL] >= 0.0) {
    intrm_sf_mf_23 = -X[100ULL];
  } else {
    intrm_sf_mf_23 = X[100ULL];
  }

  intrm_sf_mf_214 = intrm_sf_mf_23 * 0.1413716694115407 / (t1198 == 0.0 ?
    1.0E-16 : t1198);
  intrm_sf_mf_176 = intrm_sf_mf_214 >= 1.0 ? intrm_sf_mf_214 : 1.0;
  t1542 = pmf_log10(6.9 / (intrm_sf_mf_176 == 0.0 ? 1.0E-16 : intrm_sf_mf_176) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_176 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_176) + 9.0751776413883736E-6) * 3.24;
  t1168 = X[100ULL] * t1527 * -48.0 / (t1485 == 0.0 ? 1.0E-16 : t1485);
  intrm_sf_mf_23 = X[100ULL] * intrm_sf_mf_23 * (1.0 / (t1542 == 0.0 ? 1.0E-16 :
    t1542)) * -0.75 / (t1543 == 0.0 ? 1.0E-16 : t1543);
  intrm_sf_mf_176 = (intrm_sf_mf_214 - 2000.0) / 2000.0;
  t1579 = intrm_sf_mf_176 * intrm_sf_mf_176 * 3.0 - intrm_sf_mf_176 *
    intrm_sf_mf_176 * intrm_sf_mf_176 * 2.0;
  if (intrm_sf_mf_214 <= 2000.0) {
    intrm_sf_mf_176 = t1168 * 1.0E-5;
  } else if (intrm_sf_mf_214 >= 4000.0) {
    intrm_sf_mf_176 = intrm_sf_mf_23 * 1.0E-5;
  } else {
    intrm_sf_mf_176 = ((1.0 - t1579) * t1168 + intrm_sf_mf_23 * t1579) * 1.0E-5;
  }

  t1485 = (Subsystem_Reference_Pipe_TL4_mu_A_in + t1212) / 2.0 *
    0.0019634954084936209;
  intrm_sf_mf_23 = t1213 / (t1485 == 0.0 ? 1.0E-16 : t1485);
  intrm_sf_mf_214 = t1104 > 1000.0 ? t1104 : 1000.0;
  t1168 = intrm_sf_mf_23 >= 0.0 ? intrm_sf_mf_23 : -intrm_sf_mf_23;
  t1579 = t1168 > 1000.0 ? t1168 : 1000.0;
  t1542 = pmf_log10(6.9 / (t1579 == 0.0 ? 1.0E-16 : t1579) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (t1579 == 0.0 ?
    1.0E-16 : t1579) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_221 = 1.0 / (t1542 == 0.0 ? 1.0E-16 : t1542);
  t1542 = Subsystem_Reference_Pipe_TL4_Pr_A_in +
    Subsystem_Reference_Pipe_TL4_Pr_I;
  if ((pmf_pow(t1542 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt
      (intrm_sf_mf_221 / 8.0) * 12.7 + 1.0 >= 1.0E-6) {
    t1527 = (pmf_pow((Subsystem_Reference_Pipe_TL4_Pr_A_in +
                      Subsystem_Reference_Pipe_TL4_Pr_I) / 2.0,
                     0.66666666666666663) - 1.0) * pmf_sqrt(intrm_sf_mf_221 /
      8.0) * 12.7 + 1.0;
    t1186 = (t1579 - 1000.0) * (intrm_sf_mf_221 / 8.0) *
      ((Subsystem_Reference_Pipe_TL4_Pr_A_in + Subsystem_Reference_Pipe_TL4_Pr_I)
       / 2.0) / (t1527 == 0.0 ? 1.0E-16 : t1527);
  } else {
    t1186 = (t1579 - 1000.0) * (intrm_sf_mf_221 / 8.0) *
      ((Subsystem_Reference_Pipe_TL4_Pr_A_in + Subsystem_Reference_Pipe_TL4_Pr_I)
       / 2.0) / 1.0E-6;
  }

  t1579 = (t1168 - 2000.0) / 2000.0;
  intrm_sf_mf_221 = t1579 * t1579 * 3.0 - t1579 * t1579 * t1579 * 2.0;
  if (t1168 <= 2000.0) {
    t1579 = 3.66;
  } else if (t1168 >= 4000.0) {
    t1579 = t1186;
  } else {
    t1579 = (1.0 - intrm_sf_mf_221) * 3.66 + t1186 * intrm_sf_mf_221;
  }

  t1485 = t1542 / 2.0;
  if (t1168 > t1579 * 0.02777777777777778 / 0.0019634954084936209 / (t1485 ==
       0.0 ? 1.0E-16 : t1485) / 30.0) {
    t1529 = (Subsystem_Reference_Pipe_TL4_Pr_A_in +
             Subsystem_Reference_Pipe_TL4_Pr_I) / 2.0;
    intrm_sf_mf_221 = t1579 * 0.02777777777777778 / (t1168 == 0.0 ? 1.0E-16 :
      t1168) / 0.0019634954084936209 / (t1529 == 0.0 ? 1.0E-16 : t1529);
  } else {
    intrm_sf_mf_221 = 30.0;
  }

  t1168 = (X[114ULL] - X[111ULL]) * (1.0 - pmf_exp(-intrm_sf_mf_221));
  intrm_sf_mf_23 = intrm_sf_mf_23 * 0.0019634954084936209 / 0.1413716694115407 *
    (t1542 / 2.0) * ((Subsystem_Reference_Pipe_TL4_k_A_in +
                      Subsystem_Reference_Pipe_TL4_k_I) / 2.0) * t1168;
  t1542 = pmf_log10(6.9 / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_214 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_214) + 9.0751776413883736E-6) * 3.24;
  t1168 = 1.0 / (t1542 == 0.0 ? 1.0E-16 : t1542);
  t1543 = (Subsystem_Reference_Pipe_TL4_mu_B_in + t1212) / 2.0 *
    0.0019634954084936209;
  t1579 = -Subsystem_Reference_Pipe_TL4_mdot_avg * 0.1413716694115407 / (t1543 ==
    0.0 ? 1.0E-16 : t1543);
  intrm_sf_mf_221 = t1579 >= 0.0 ? t1579 : -t1579;
  t1186 = intrm_sf_mf_221 > 1000.0 ? intrm_sf_mf_221 : 1000.0;
  t1542 = pmf_log10(6.9 / (t1186 == 0.0 ? 1.0E-16 : t1186) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (t1186 == 0.0 ?
    1.0E-16 : t1186) + 9.0751776413883736E-6) * 3.24;
  t1188 = 1.0 / (t1542 == 0.0 ? 1.0E-16 : t1542);
  t1542 = Subsystem_Reference_Pipe_TL4_Pr_B_in +
    Subsystem_Reference_Pipe_TL4_Pr_I;
  if ((pmf_pow(t1542 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t1188 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    t1527 = (pmf_pow((Subsystem_Reference_Pipe_TL4_Pr_B_in +
                      Subsystem_Reference_Pipe_TL4_Pr_I) / 2.0,
                     0.66666666666666663) - 1.0) * pmf_sqrt(t1188 / 8.0) * 12.7
      + 1.0;
    intrm_sf_mf_217 = (t1186 - 1000.0) * (t1188 / 8.0) *
      ((Subsystem_Reference_Pipe_TL4_Pr_B_in + Subsystem_Reference_Pipe_TL4_Pr_I)
       / 2.0) / (t1527 == 0.0 ? 1.0E-16 : t1527);
  } else {
    intrm_sf_mf_217 = (t1186 - 1000.0) * (t1188 / 8.0) *
      ((Subsystem_Reference_Pipe_TL4_Pr_B_in + Subsystem_Reference_Pipe_TL4_Pr_I)
       / 2.0) / 1.0E-6;
  }

  t1186 = (intrm_sf_mf_221 - 2000.0) / 2000.0;
  t1188 = t1186 * t1186 * 3.0 - t1186 * t1186 * t1186 * 2.0;
  if (intrm_sf_mf_221 <= 2000.0) {
    t1186 = 3.66;
  } else if (intrm_sf_mf_221 >= 4000.0) {
    t1186 = intrm_sf_mf_217;
  } else {
    t1186 = (1.0 - t1188) * 3.66 + intrm_sf_mf_217 * t1188;
  }

  t1485 = t1542 / 2.0;
  if (intrm_sf_mf_221 > t1186 * 0.02777777777777778 / 0.0019634954084936209 /
      (t1485 == 0.0 ? 1.0E-16 : t1485) / 30.0) {
    t1529 = (Subsystem_Reference_Pipe_TL4_Pr_B_in +
             Subsystem_Reference_Pipe_TL4_Pr_I) / 2.0;
    t1188 = t1186 * 0.02777777777777778 / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 :
      intrm_sf_mf_221) / 0.0019634954084936209 / (t1529 == 0.0 ? 1.0E-16 : t1529);
  } else {
    t1188 = 30.0;
  }

  intrm_sf_mf_221 = (X[114ULL] - X[119ULL]) * (1.0 - pmf_exp(-t1188));
  t1485 = t1105 + intrm_sf_mf_242;
  if ((pmf_pow(t1485 / 2.0, 0.66666666666666663) - 1.0) * pmf_sqrt(t1168 / 8.0) *
      12.7 + 1.0 >= 1.0E-6) {
    t1528 = (pmf_pow((t1105 + intrm_sf_mf_242) / 2.0, 0.66666666666666663) - 1.0)
      * pmf_sqrt(t1168 / 8.0) * 12.7 + 1.0;
    t1186 = (intrm_sf_mf_214 - 1000.0) * (t1168 / 8.0) * ((t1105 +
      intrm_sf_mf_242) / 2.0) / (t1528 == 0.0 ? 1.0E-16 : t1528);
  } else {
    t1186 = (intrm_sf_mf_214 - 1000.0) * (t1168 / 8.0) * ((t1105 +
      intrm_sf_mf_242) / 2.0) / 1.0E-6;
  }

  intrm_sf_mf_214 = t1579 * 0.0019634954084936209 / 0.1413716694115407 * (t1542 /
    2.0) * ((Subsystem_Reference_Pipe_TL4_k_B_in +
             Subsystem_Reference_Pipe_TL4_k_I) / 2.0) * intrm_sf_mf_221;
  t1168 = (Subsystem_Reference_Pipe_TL4_Re_avg - -20.0) / 40.0;
  t1579 = t1168 * t1168 * 3.0 - t1168 * t1168 * t1168 * 2.0;
  if (Subsystem_Reference_Pipe_TL4_Re_avg <= -20.0) {
    t1168 = intrm_sf_mf_214 * 0.001;
  } else if (Subsystem_Reference_Pipe_TL4_Re_avg >= 20.0) {
    t1168 = intrm_sf_mf_23 * 0.001;
  } else {
    t1168 = ((1.0 - t1579) * intrm_sf_mf_214 + intrm_sf_mf_23 * t1579) * 0.001;
  }

  if (-X[16ULL] >= 0.0) {
    intrm_sf_mf_23 = -X[16ULL];
  } else {
    intrm_sf_mf_23 = X[16ULL];
  }

  intrm_sf_mf_214 = intrm_sf_mf_23 * 0.1413716694115407 / (t1214 == 0.0 ?
    1.0E-16 : t1214);
  t1579 = intrm_sf_mf_214 >= 1.0 ? intrm_sf_mf_214 : 1.0;
  t1542 = pmf_log10(6.9 / (t1579 == 0.0 ? 1.0E-16 : t1579) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (t1579 == 0.0 ?
    1.0E-16 : t1579) + 9.0751776413883736E-6) * 3.24;
  t1543 = t1223 * 7.8484637847008924E-5;
  intrm_sf_mf_221 = t1212 * X[16ULL] * -48.0 / (t1543 == 0.0 ? 1.0E-16 : t1543);
  t1539 = t1223 * 1.0900644145417907E-6;
  intrm_sf_mf_23 = X[16ULL] * intrm_sf_mf_23 * (1.0 / (t1542 == 0.0 ? 1.0E-16 :
    t1542)) * -0.75 / (t1539 == 0.0 ? 1.0E-16 : t1539);
  t1579 = (t1104 - 2000.0) / 2000.0;
  t1188 = (intrm_sf_mf_214 - 2000.0) / 2000.0;
  intrm_sf_mf_217 = t1188 * t1188 * 3.0 - t1188 * t1188 * t1188 * 2.0;
  if (intrm_sf_mf_214 <= 2000.0) {
    t1188 = intrm_sf_mf_221 * 1.0E-5;
  } else if (intrm_sf_mf_214 >= 4000.0) {
    t1188 = intrm_sf_mf_23 * 1.0E-5;
  } else {
    t1188 = ((1.0 - intrm_sf_mf_217) * intrm_sf_mf_221 + intrm_sf_mf_23 *
             intrm_sf_mf_217) * 1.0E-5;
  }

  intrm_sf_mf_23 = t1211 >= 0.0 ? t1211 : -t1211;
  intrm_sf_mf_214 = intrm_sf_mf_23 * 0.1413716694115407 / (t1214 == 0.0 ?
    1.0E-16 : t1214);
  intrm_sf_mf_221 = intrm_sf_mf_214 >= 1.0 ? intrm_sf_mf_214 : 1.0;
  t1542 = pmf_log10(6.9 / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 : intrm_sf_mf_221) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_221 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_221) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_217 = t1211 * t1212 * 48.0 / (t1543 == 0.0 ? 1.0E-16 : t1543);
  intrm_sf_mf_23 = t1211 * intrm_sf_mf_23 * (1.0 / (t1542 == 0.0 ? 1.0E-16 :
    t1542)) * 0.75 / (t1539 == 0.0 ? 1.0E-16 : t1539);
  intrm_sf_mf_221 = (intrm_sf_mf_214 - 2000.0) / 2000.0;
  t1576 = t1579 * t1579 * 3.0 - t1579 * t1579 * t1579 * 2.0;
  t1579 = intrm_sf_mf_221 * intrm_sf_mf_221 * 3.0 - intrm_sf_mf_221 *
    intrm_sf_mf_221 * intrm_sf_mf_221 * 2.0;
  if (intrm_sf_mf_214 <= 2000.0) {
    intrm_sf_mf_221 = intrm_sf_mf_217 * 1.0E-5;
  } else if (intrm_sf_mf_214 >= 4000.0) {
    intrm_sf_mf_221 = intrm_sf_mf_23 * 1.0E-5;
  } else {
    intrm_sf_mf_221 = ((1.0 - t1579) * intrm_sf_mf_217 + intrm_sf_mf_23 * t1579)
      * 1.0E-5;
  }

  if (t1104 <= 2000.0) {
    intrm_sf_mf_23 = 3.66;
  } else if (t1104 >= 4000.0) {
    intrm_sf_mf_23 = t1186;
  } else {
    intrm_sf_mf_23 = (1.0 - t1576) * 3.66 + t1186 * t1576;
  }

  intrm_sf_mf_214 = pmf_sqrt(X[4ULL] * X[4ULL] + 1.4412638338049421E-12);
  t1542 = t1485 / 2.0;
  if (t1104 > intrm_sf_mf_23 * 0.055555555555555559 / 0.0019634954084936209 /
      (t1542 == 0.0 ? 1.0E-16 : t1542) / 30.0) {
    t1529 = (t1105 + intrm_sf_mf_242) / 2.0;
    t1579 = intrm_sf_mf_23 * 0.055555555555555559 / (t1104 == 0.0 ? 1.0E-16 :
      t1104) / 0.0019634954084936209 / (t1529 == 0.0 ? 1.0E-16 : t1529);
  } else {
    t1579 = 30.0;
  }

  t1104 = pmf_sqrt(X[35ULL] * X[35ULL] + 1.4412638338049421E-12);
  t1105 = (-X[4ULL] / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214) + 1.0)
    / 2.0;
  intrm_sf_mf_242 = (X[35ULL] / (t1104 == 0.0 ? 1.0E-16 : t1104) + 1.0) / 2.0;
  intrm_sf_mf_23 = (1.0 - -X[4ULL] / (intrm_sf_mf_214 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_214)) / 2.0;
  t1186 = (1.0 - X[35ULL] / (t1104 == 0.0 ? 1.0E-16 : t1104)) / 2.0;
  t1707 = X[35ULL] / (t1104 == 0.0 ? 1.0E-16 : t1104) * t1707 / (X[90ULL] == 0.0
    ? 1.0E-16 : X[90ULL]);
  t1576 = (X[52ULL] - X[53ULL]) * (1.0 - pmf_exp(-t1579));
  intrm_sf_mf_84 = t1106 * 0.0019634954084936209 / 0.1413716694115407 * (t1485 /
    2.0) * ((intrm_sf_mf_80 + intrm_sf_mf_84) / 2.0) * t1576;
  t1106 = (intrm_sf_mf_88 - -20.0) / 40.0;
  intrm_sf_mf_80 = t1106 * t1106 * 3.0 - t1106 * t1106 * t1106 * 2.0;
  if (intrm_sf_mf_88 <= -20.0) {
    t1106 = intrm_sf_mf_84 * 0.001;
  } else if (intrm_sf_mf_88 >= 20.0) {
    t1106 = intrm_sf_mf_47 * 0.001;
  } else {
    t1106 = ((1.0 - intrm_sf_mf_80) * intrm_sf_mf_84 + intrm_sf_mf_47 *
             intrm_sf_mf_80) * 0.001;
  }

  if (-X[7ULL] >= 0.0) {
    intrm_sf_mf_84 = -X[7ULL];
  } else {
    intrm_sf_mf_84 = X[7ULL];
  }

  intrm_sf_mf_88 = intrm_sf_mf_84 * 0.1413716694115407 / (t1109 == 0.0 ? 1.0E-16
    : t1109);
  intrm_sf_mf_47 = intrm_sf_mf_88 >= 1.0 ? intrm_sf_mf_88 : 1.0;
  t1579 = pmf_log10(6.9 / (intrm_sf_mf_47 == 0.0 ? 1.0E-16 : intrm_sf_mf_47) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_47 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_47) + 9.0751776413883736E-6) * 3.24;
  t1576 = intrm_sf_mf_38 * 7.8484637847008924E-5;
  intrm_sf_mf_80 = t1107 * X[7ULL] * -64.0 / (t1576 == 0.0 ? 1.0E-16 : t1576);
  t1542 = intrm_sf_mf_38 * 1.0900644145417907E-6;
  intrm_sf_mf_84 = -(X[7ULL] * intrm_sf_mf_84 * (1.0 / (t1579 == 0.0 ? 1.0E-16 :
    t1579))) / (t1542 == 0.0 ? 1.0E-16 : t1542);
  intrm_sf_mf_38 = (intrm_sf_mf_88 - 2000.0) / 2000.0;
  intrm_sf_mf_47 = intrm_sf_mf_38 * intrm_sf_mf_38 * 3.0 - intrm_sf_mf_38 *
    intrm_sf_mf_38 * intrm_sf_mf_38 * 2.0;
  if (intrm_sf_mf_88 <= 2000.0) {
    intrm_sf_mf_38 = intrm_sf_mf_80 * 1.0E-5;
  } else if (intrm_sf_mf_88 >= 4000.0) {
    intrm_sf_mf_38 = intrm_sf_mf_84 * 1.0E-5;
  } else {
    intrm_sf_mf_38 = ((1.0 - intrm_sf_mf_47) * intrm_sf_mf_80 + intrm_sf_mf_84 *
                      intrm_sf_mf_47) * 1.0E-5;
  }

  if (-X[57ULL] >= 0.0) {
    intrm_sf_mf_84 = -X[57ULL];
  } else {
    intrm_sf_mf_84 = X[57ULL];
  }

  intrm_sf_mf_88 = intrm_sf_mf_84 * 0.1413716694115407 / (t1109 == 0.0 ? 1.0E-16
    : t1109);
  intrm_sf_mf_47 = intrm_sf_mf_88 >= 1.0 ? intrm_sf_mf_88 : 1.0;
  t1579 = pmf_log10(6.9 / (intrm_sf_mf_47 == 0.0 ? 1.0E-16 : intrm_sf_mf_47) +
                    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_47 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_47) + 9.0751776413883736E-6) * 3.24;
  t1107 = t1107 * X[57ULL] * -64.0 / (t1576 == 0.0 ? 1.0E-16 : t1576);
  intrm_sf_mf_84 = -(X[57ULL] * intrm_sf_mf_84 * (1.0 / (t1579 == 0.0 ? 1.0E-16 :
    t1579))) / (t1542 == 0.0 ? 1.0E-16 : t1542);
  intrm_sf_mf_47 = (intrm_sf_mf_88 - 2000.0) / 2000.0;
  intrm_sf_mf_80 = intrm_sf_mf_47 * intrm_sf_mf_47 * 3.0 - intrm_sf_mf_47 *
    intrm_sf_mf_47 * intrm_sf_mf_47 * 2.0;
  if (intrm_sf_mf_88 <= 2000.0) {
    intrm_sf_mf_47 = t1107 * 1.0E-5;
  } else if (intrm_sf_mf_88 >= 4000.0) {
    intrm_sf_mf_47 = intrm_sf_mf_84 * 1.0E-5;
  } else {
    intrm_sf_mf_47 = ((1.0 - intrm_sf_mf_80) * t1107 + intrm_sf_mf_84 *
                      intrm_sf_mf_80) * 1.0E-5;
  }

  t1579 = intrm_sf_mf_90 * 0.00075;
  intrm_sf_mf_84 = t1163 / (t1579 == 0.0 ? 1.0E-16 : t1579);
  t1107 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  t1576 = pmf_log10(6.9 / (t1107 == 0.0 ? 1.0E-16 : t1107) +
                    0.00069701528436089772) * pmf_log10(6.9 / (t1107 == 0.0 ?
    1.0E-16 : t1107) + 0.00069701528436089772) * 3.24;
  t1542 = intrm_sf_mf_81 * 0.0015;
  intrm_sf_mf_88 = X[4ULL] * intrm_sf_mf_90 * -2.1972622222222225E+6 / (t1542 ==
    0.0 ? 1.0E-16 : t1542);
  t1576 = -(X[4ULL] * t1571 * (1.0 / (t1576 == 0.0 ? 1.0E-16 : t1576) * 0.275 /
             0.0028301886792452828));
  t1571 = intrm_sf_mf_81 * 1.125E-6;
  t1107 = t1576 / (t1571 == 0.0 ? 1.0E-16 : t1571);
  intrm_sf_mf_80 = (intrm_sf_mf_84 - 2000.0) / 2000.0;
  intrm_sf_mf_81 = intrm_sf_mf_80 * intrm_sf_mf_80 * 3.0 - intrm_sf_mf_80 *
    intrm_sf_mf_80 * intrm_sf_mf_80 * 2.0;
  if (intrm_sf_mf_84 <= 2000.0) {
    intrm_sf_mf_80 = intrm_sf_mf_88 * 1.0E-5;
  } else if (intrm_sf_mf_84 >= 4000.0) {
    intrm_sf_mf_80 = t1107 * 1.0E-5;
  } else {
    intrm_sf_mf_80 = ((1.0 - intrm_sf_mf_81) * intrm_sf_mf_88 + t1107 *
                      intrm_sf_mf_81) * 1.0E-5;
  }

  intrm_sf_mf_84 = t1170 / (t1579 == 0.0 ? 1.0E-16 : t1579);
  t1107 = intrm_sf_mf_84 >= 1.0 ? intrm_sf_mf_84 : 1.0;
  t1579 = pmf_log10(6.9 / (t1107 == 0.0 ? 1.0E-16 : t1107) +
                    0.00069701528436089772) * pmf_log10(6.9 / (t1107 == 0.0 ?
    1.0E-16 : t1107) + 0.00069701528436089772) * 3.24;
  intrm_sf_mf_88 = X[35ULL] * intrm_sf_mf_90 * 2.1972622222222225E+6 / (t1542 ==
    0.0 ? 1.0E-16 : t1542);
  t1107 = X[35ULL] * intrm_sf_mf_61 * (1.0 / (t1579 == 0.0 ? 1.0E-16 : t1579) *
    0.275 / 0.0028301886792452828) / (t1571 == 0.0 ? 1.0E-16 : t1571);
  intrm_sf_mf_90 = (intrm_sf_mf_84 - 2000.0) / 2000.0;
  intrm_sf_mf_81 = intrm_sf_mf_90 * intrm_sf_mf_90 * 3.0 - intrm_sf_mf_90 *
    intrm_sf_mf_90 * intrm_sf_mf_90 * 2.0;
  if (intrm_sf_mf_84 <= 2000.0) {
    intrm_sf_mf_90 = intrm_sf_mf_88 * 1.0E-5;
  } else if (intrm_sf_mf_84 >= 4000.0) {
    intrm_sf_mf_90 = t1107 * 1.0E-5;
  } else {
    intrm_sf_mf_90 = ((1.0 - intrm_sf_mf_81) * intrm_sf_mf_88 + t1107 *
                      intrm_sf_mf_81) * 1.0E-5;
  }

  intrm_sf_mf_84 = piece12 * 5.8904862254808616;
  t1107 = Basic_Peripherals_T_Junction_TL1_mu_avg * 5.8904862254808616;
  intrm_sf_mf_88 = U_idx_2 * 5.8904862254808616;
  t816[0ULL] = X[86ULL];
  tlu2_linear_linear_prelookup(&ij_efOut.mField0[0ULL], &ij_efOut.mField1[0ULL],
    &ij_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t95 = ij_efOut;
  t816[0ULL] = X[87ULL];
  tlu2_linear_linear_prelookup(&jj_efOut.mField0[0ULL], &jj_efOut.mField1[0ULL],
    &jj_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t816[0ULL],
    &t120[0ULL], &t121[0ULL]);
  t93 = jj_efOut;
  tlu2_2d_linear_linear_value(&kj_efOut[0ULL], &t115.mField0[0ULL],
    &t115.mField2[0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t816[0] = kj_efOut[0];
  tlu2_2d_linear_linear_value(&lj_efOut[0ULL], &t113.mField0[0ULL],
    &t113.mField2[0ULL], &t105.mField0[0ULL], &t105.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1033_idx_0 = lj_efOut[0];
  tlu2_2d_linear_linear_value(&mj_efOut[0ULL], &t88.mField0[0ULL], &t88.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  U_idx_0 = mj_efOut[0];
  tlu2_2d_linear_linear_value(&nj_efOut[0ULL], &t83.mField0[0ULL], &t83.mField2
    [0ULL], &t102.mField0[0ULL], &t102.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  D_idx_0 = nj_efOut[0];
  tlu2_2d_linear_linear_value(&oj_efOut[0ULL], &t84.mField0[0ULL], &t84.mField2
    [0ULL], &t78.mField0[0ULL], &t78.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  D_idx_1 = oj_efOut[0];
  tlu2_2d_linear_linear_value(&pj_efOut[0ULL], &t104.mField0[0ULL],
    &t104.mField2[0ULL], &t110.mField0[0ULL], &t110.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  U_idx_2 = pj_efOut[0];
  tlu2_2d_linear_linear_value(&qj_efOut[0ULL], &t68.mField0[0ULL], &t68.mField2
    [0ULL], &t112.mField0[0ULL], &t112.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  U_idx_3 = qj_efOut[0];
  tlu2_2d_linear_linear_value(&rj_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t112.mField0[0ULL], &t112.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  U_idx_6 = rj_efOut[0];
  tlu2_2d_linear_linear_value(&sj_efOut[0ULL], &t89.mField0[0ULL], &t89.mField2
    [0ULL], &t61.mField0[0ULL], &t61.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  U_idx_7 = sj_efOut[0];
  tlu2_2d_linear_linear_value(&tj_efOut[0ULL], &t59.mField0[0ULL], &t59.mField2
    [0ULL], &t78.mField0[0ULL], &t78.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  D_idx_2 = tj_efOut[0];
  tlu2_2d_linear_linear_value(&uj_efOut[0ULL], &t56.mField0[0ULL], &t56.mField2
    [0ULL], &t105.mField0[0ULL], &t105.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1387 = uj_efOut[0];
  tlu2_2d_linear_linear_value(&vj_efOut[0ULL], &t54.mField0[0ULL], &t54.mField2
    [0ULL], &t72.mField0[0ULL], &t72.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1392 = vj_efOut[0];
  tlu2_2d_linear_linear_value(&wj_efOut[0ULL], &t49.mField0[0ULL], &t49.mField2
    [0ULL], &t102.mField0[0ULL], &t102.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1579 = wj_efOut[0];
  tlu2_2d_linear_linear_value(&xj_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t61.mField0[0ULL], &t61.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  intrm_sf_mf_217 = xj_efOut[0];
  tlu2_2d_linear_linear_value(&yj_efOut[0ULL], &t93.mField0[0ULL], &t93.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField0, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1576 = yj_efOut[0];
  tlu2_2d_linear_linear_value(&ak_efOut[0ULL], &t95.mField0[0ULL], &t95.mField2
    [0ULL], &t61.mField0[0ULL], &t61.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1542 = ak_efOut[0];
  tlu2_2d_linear_linear_value(&bk_efOut[0ULL], &t93.mField0[0ULL], &t93.mField2
    [0ULL], &t108.mField0[0ULL], &t108.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1485 = bk_efOut[0];
  tlu2_2d_linear_linear_value(&ck_efOut[0ULL], &t44.mField0[0ULL], &t44.mField2
    [0ULL], &t85.mField0[0ULL], &t85.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1543 = ck_efOut[0];
  tlu2_2d_linear_linear_value(&dk_efOut[0ULL], &t81.mField0[0ULL], &t81.mField2
    [0ULL], &t35.mField0[0ULL], &t35.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1539 = dk_efOut[0];
  tlu2_2d_linear_linear_value(&ek_efOut[0ULL], &t34.mField0[0ULL], &t34.mField2
    [0ULL], &t33.mField0[0ULL], &t33.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1527 = ek_efOut[0];
  tlu2_2d_linear_linear_value(&fk_efOut[0ULL], &t53.mField0[0ULL], &t53.mField2
    [0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1197 = fk_efOut[0];
  tlu2_2d_linear_linear_value(&gk_efOut[0ULL], &t97.mField0[0ULL], &t97.mField2
    [0ULL], &t35.mField0[0ULL], &t35.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1198 = gk_efOut[0];
  tlu2_2d_linear_linear_value(&hk_efOut[0ULL], &t64.mField0[0ULL], &t64.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1528 = hk_efOut[0];
  tlu2_2d_linear_linear_value(&ik_efOut[0ULL], &t21.mField0[0ULL], &t21.mField2
    [0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1529 = ik_efOut[0];
  tlu2_2d_linear_linear_value(&jk_efOut[0ULL], &t111.mField0[0ULL],
    &t111.mField2[0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1416 = jk_efOut[0];
  tlu2_2d_linear_linear_value(&kk_efOut[0ULL], &t29.mField0[0ULL], &t29.mField2
    [0ULL], &t50.mField0[0ULL], &t50.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  Subsystem_Reference_Pipe_TL2_k_B_in = kk_efOut[0];
  tlu2_2d_linear_linear_value(&lk_efOut[0ULL], &t90.mField0[0ULL], &t90.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1413 = lk_efOut[0];
  tlu2_2d_linear_linear_value(&mk_efOut[0ULL], &t101.mField0[0ULL],
    &t101.mField2[0ULL], &t80.mField0[0ULL], &t80.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1415 = mk_efOut[0];
  tlu2_2d_linear_linear_value(&nk_efOut[0ULL], &t79.mField0[0ULL], &t79.mField2
    [0ULL], &t72.mField0[0ULL], &t72.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  Subsystem_Reference_Pipe_TL4_Pr_A_in = nk_efOut[0];
  tlu2_2d_linear_linear_value(&ok_efOut[0ULL], &t75.mField0[0ULL], &t75.mField2
    [0ULL], &t70.mField0[0ULL], &t70.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  Subsystem_Reference_Pipe_TL4_Pr_B_in = ok_efOut[0];
  tlu2_2d_linear_linear_value(&pk_efOut[0ULL], &t118.mField0[0ULL],
    &t118.mField2[0ULL], &t33.mField0[0ULL], &t33.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  Subsystem_Reference_Pipe_TL4_Pr_I = pk_efOut[0];
  tlu2_2d_linear_linear_value(&qk_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t110.mField0[0ULL], &t110.mField2[0ULL], ((_NeDynamicSystem*)(LC)
    )->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  Subsystem_Reference_Pipe_TL4_k_I = qk_efOut[0];
  tlu2_2d_linear_linear_value(&rk_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t27.mField0[0ULL], &t27.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t120[0ULL], &t123[0ULL], &t121[0ULL]);
  t1211 = rk_efOut[0];
  t921[0ULL] = -0.0;
  t921[1ULL] = -0.0;
  t921[2ULL] = -0.0;
  t921[3ULL] = -0.0;
  t921[4ULL] = -0.0;
  t921[5ULL] = 0.0;
  t921[6ULL] = -(X[33ULL] * t1089 * t1087 / 291.40147251301789);
  t921[7ULL] = -0.0;
  t921[8ULL] = -0.0;
  t921[9ULL] = -0.0;
  t921[10ULL] = -0.0;
  t921[11ULL] = -0.0;
  t921[12ULL] = -0.0;
  t921[13ULL] = -0.0;
  t921[14ULL] = -0.0;
  t921[15ULL] = -0.0;
  t921[16ULL] = -0.0;
  t921[17ULL] = -0.0;
  t921[18ULL] = -0.0;
  t921[19ULL] = -0.0;
  t921[20ULL] = -0.0;
  t921[21ULL] = 0.0;
  t921[22ULL] = 0.0;
  t921[23ULL] = 0.0;
  t921[24ULL] = 0.0;
  t921[25ULL] = 0.0;
  t921[26ULL] = 0.0;
  t921[27ULL] = 0.0;
  t921[28ULL] = 0.0;
  t921[29ULL] = 0.0;
  t921[30ULL] = ((-X[24ULL] - X[25ULL]) / (t1618 == 0.0 ? 1.0E-16 : t1618) -
                 ((t1074 * t1076 - t1072 * X[30ULL]) +
                  Basic_Peripherals_Aux_TCP_convection_A_pv * 100.0)) /
    7.954052018047886E+6;
  U_idx_1 = t816[0ULL] - (t1074 * t1076 + t1072 * X[30ULL]);
  t921[31ULL] = U_idx_1 / 4.5622043810029151E+6;
  t921[32ULL] = (t1683 / (t1618 == 0.0 ? 1.0E-16 : t1618) - ((t1077 * t1078 - X
    [30ULL] * Basic_Peripherals_Aux_TCP_convection_B_step_neg) +
    Basic_Peripherals_Aux_TCP_convection_B_pv * 100.0)) / 7.954052018047886E+6;
  t921[33ULL] = (t1033_idx_0 - (t1077 * t1078 + X[30ULL] *
    Basic_Peripherals_Aux_TCP_convection_B_step_neg)) / 4.5622043810029151E+6;
  t921[34ULL] = -1.1132499978923138 + -(t1080 * 1.0E-5) / 1.0000000018932729;
  t921[35ULL] = t1603 * 0.001;
  U_idx_1 = pmf_sqrt(t1616 * t1616 + 0.13433628212593846) * t1616 *
    Basic_Peripherals_Aux_TCP_torque_ref;
  t921[36ULL] = -(U_idx_1 / 134336.28212593845 * 1000.0);
  t921[37ULL] = (X[24ULL] /
                 (Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1
                  == 0.0 ? 1.0E-16 :
                  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo1)
                 - ((t1076 * t1082 -
                     Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_ste0
                     * X[36ULL]) + t1085 * 100.0)) / 246718.32726960591;
  t921[38ULL] = (U_idx_0 - (t1076 * t1082 +
    Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_ste0 * X[36ULL]))
    / 141510.19266521608;
  t921[39ULL] = -t1088 / 3.381618665435564;
  t921[40ULL] = X[33ULL] * t1087 / 1068.626760737239;
  t921[41ULL] = (X[26ULL] /
                 (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 :
                  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) -
                 ((t1095 * t1097 - t1093 * X[47ULL]) +
                  Basic_Peripherals_Gate_Valve_TL_convection_A_pv * 100.0)) /
    5.5678364126335206E+6;
  t921[42ULL] = (D_idx_0 - (t1095 * t1097 + t1093 * X[47ULL])) /
    3.1935430667020408E+6;
  t921[43ULL] = (-X[26ULL] /
                 (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 :
                  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) -
                 ((t1101 * t1103 - X[47ULL] * t1099) +
                  Basic_Peripherals_Gate_Valve_TL_convection_B_pv * 100.0)) /
    5.5678364126335206E+6;
  t921[44ULL] = (D_idx_1 - (t1101 * t1103 + X[47ULL] * t1099)) /
    3.1935430667020408E+6;
  t1618 = t1091 * t1091 * Basic_Peripherals_Gate_Valve_TL_rho_avg *
    0.97999999999999987;
  t1603 = (pmf_sqrt(1.0 - t1090 * t1090 * 0.51) - t1090 * 0.7) * ((1.0 - t1090 *
    t1090) * Basic_Peripherals_Gate_Valve_TL_mdot_square / (t1618 == 0.0 ?
    1.0E-16 : t1618));
  t1616 = t1090 * 0.7 + pmf_sqrt(1.0 - t1090 * t1090 * 0.51);
  t921[45ULL] = -(t1603 / (t1616 == 0.0 ? 1.0E-16 : t1616) * 1.0E-5) /
    3.7261553955660564E+8;
  t921[46ULL] = (Basic_Peripherals_Pipe_TL3_Phi_A /
                 (Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 : Basic_Peripherals_Pipe_TL3_convection_A_mdot_abs) -
                 ((t1110 * t1111 -
                   Basic_Peripherals_Pipe_TL3_convection_A_step_neg * X[59ULL])
                  + Basic_Peripherals_Pipe_TL3_convection_A_pv * 100.0)) /
    2.7839182063167598E+7;
  t921[47ULL] = (U_idx_2 - (t1110 * t1111 +
    Basic_Peripherals_Pipe_TL3_convection_A_step_neg * X[59ULL])) /
    1.5967715333510201E+7;
  t921[48ULL] = (X[51ULL] / (t1113 == 0.0 ? 1.0E-16 : t1113) - ((t1116 * t1117 -
    Basic_Peripherals_Pipe_TL3_convection_B_step_neg * X[61ULL]) +
    Basic_Peripherals_Pipe_TL3_convection_B_pv * 100.0)) / 2.7839182063167598E+7;
  t921[49ULL] = (U_idx_3 - (t1116 * t1117 +
    Basic_Peripherals_Pipe_TL3_convection_B_step_neg * X[61ULL])) /
    1.5967715333510201E+7;
  t921[50ULL] = -(Basic_Peripherals_Pipe_TL3_Q_cond * 0.001 + t1106) /
    0.00016359949796521223;
  t921[51ULL] = -t1121 / 3.3816186654355636;
  t921[52ULL] = -t1121 / 3.3816186654355636;
  t921[53ULL] = -intrm_sf_mf_38;
  t921[54ULL] = -intrm_sf_mf_47;
  t921[55ULL] = (-X[51ULL] /
                 (Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 :
                  Basic_Peripherals_T_Junction_TL_convection_A_mdot_abs) -
                 ((t1117 * t1123 - t1124 * X[65ULL]) + t1122 * 100.0)) /
    5.5678364126335206E+6;
  t921[56ULL] = (U_idx_6 - (t1117 * t1123 + t1124 * X[65ULL])) /
    3.1935430667020408E+6;
  t921[57ULL] = (-Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi /
                 (t1126 == 0.0 ? 1.0E-16 : t1126) - ((t1129 * t1132 - X[65ULL] *
    t1130) + Basic_Peripherals_T_Junction_TL_convection_B_pv * 100.0)) /
    5.5678364126335206E+6;
  t921[58ULL] = (U_idx_7 - (t1129 * t1132 + X[65ULL] * t1130)) /
    3.1935430667020408E+6;
  t921[59ULL] = (X[26ULL] /
                 (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 :
                  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) -
                 ((t1095 * t1103 - t1093 * X[65ULL]) + t1092 * 100.0)) /
    5.5678364126335206E+6;
  t921[60ULL] = (D_idx_2 - (t1095 * t1103 + t1093 * X[65ULL])) /
    3.1935430667020408E+6;
  t921[61ULL] = 0.0;
  U_idx_1 = t1136 / 2.0 * pmf_sqrt(X[57ULL] * X[57ULL] + intrm_sf_mf_84 *
    intrm_sf_mf_84) * X[57ULL];
  t1616 = Basic_Peripherals_T_Junction_TL_rho_avg * 3.8553142191755308E-6;
  t921[62ULL] = -(U_idx_1 / (t1616 == 0.0 ? 1.0E-16 : t1616) * 1.0E-5);
  U_idx_1 = Basic_Peripherals_T_Junction_TL_k_B / 2.0 * pmf_sqrt(X[4ULL] * X
    [4ULL] + intrm_sf_mf_84 * intrm_sf_mf_84) * X[4ULL];
  t921[63ULL] = -(U_idx_1 / (t1616 == 0.0 ? 1.0E-16 : t1616) * 1.0E-5);
  U_idx_1 = Basic_Peripherals_T_Junction_TL_k_C / 2.0 * pmf_sqrt(X[46ULL] * X
    [46ULL] + intrm_sf_mf_84 * intrm_sf_mf_84) * X[46ULL];
  t921[64ULL] = -(U_idx_1 / (t1616 == 0.0 ? 1.0E-16 : t1616) * 1.0E-5);
  t921[65ULL] = (-t1683 / (t1134 == 0.0 ? 1.0E-16 : t1134) - ((t1078 * t1071 -
    t1140 * X[76ULL]) + t1138 * 100.0)) / 5.5678364126335206E+6;
  t921[66ULL] = (t1387 - (t1078 * t1071 + t1140 * X[76ULL])) /
    3.1935430667020408E+6;
  t921[67ULL] = (X[27ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) - ((t1148 * t1150 -
    X[76ULL] * t1146) + Basic_Peripherals_T_Junction_TL1_convection_B_pv * 100.0))
    / 5.5678364126335206E+6;
  t921[68ULL] = (t1392 - (t1148 * t1150 + X[76ULL] * t1146)) /
    3.1935430667020408E+6;
  t921[69ULL] = (-X[26ULL] /
                 (Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs == 0.0 ?
                  1.0E-16 :
                  Basic_Peripherals_Gate_Valve_TL_convection_A_mdot_abs) -
                 ((t1097 * t1101 - t1099 * X[76ULL]) + t1098 * 100.0)) /
    5.5678364126335206E+6;
  t921[70ULL] = (t1579 - (t1097 * t1101 + t1099 * X[76ULL])) /
    3.1935430667020408E+6;
  t921[71ULL] = 0.0;
  U_idx_0 = t1152 / 2.0 * pmf_sqrt(X[29ULL] * X[29ULL] + t1107 * t1107) * X
    [29ULL];
  t1683 = t1137 * 3.8553142191755308E-6;
  t921[72ULL] = -(U_idx_0 / (t1683 == 0.0 ? 1.0E-16 : t1683) * 1.0E-5);
  U_idx_0 = Basic_Peripherals_T_Junction_TL1_k_B / 2.0 * pmf_sqrt(X[8ULL] * X
    [8ULL] + t1107 * t1107) * X[8ULL];
  t921[73ULL] = -(U_idx_0 / (t1683 == 0.0 ? 1.0E-16 : t1683) * 1.0E-5);
  U_idx_0 = Basic_Peripherals_T_Junction_TL1_k_C / 2.0 * pmf_sqrt(X[9ULL] * X
    [9ULL] + t1107 * t1107) * X[9ULL];
  t921[74ULL] = -(U_idx_0 / (t1683 == 0.0 ? 1.0E-16 : t1683) * 1.0E-5);
  t921[75ULL] = -((((-X[10ULL] + X[86ULL]) + X[87ULL]) - U_idx_4) * t1155 *
                  t1144 * 0.001);
  t921[76ULL] = -intrm_sf_mf_217;
  t921[77ULL] = -t1576;
  t921[78ULL] = (Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_Phi /
                 (intrm_sf_mf_214 == 0.0 ? 1.0E-16 : intrm_sf_mf_214) - ((t1132 *
    t1105 - X[93ULL] * intrm_sf_mf_23) + -X[4ULL] / (intrm_sf_mf_214 == 0.0 ?
    1.0E-16 : intrm_sf_mf_214) * X[50ULL] / (X[89ULL] == 0.0 ? 1.0E-16 : X[89ULL])
    * 100.0)) / 4.5049458478738338E+7;
  t921[79ULL] = (X[25ULL] / (t1104 == 0.0 ? 1.0E-16 : t1104) - ((t1076 *
    intrm_sf_mf_242 - X[93ULL] * t1186) + t1707 * 100.0)) / 3.3816186654343459;
  t921[80ULL] = -(t1132 * t1105 + X[93ULL] * intrm_sf_mf_23) /
    2.5836108213213645E+7;
  t921[81ULL] = -(t1076 * intrm_sf_mf_242 + X[93ULL] * t1186) /
    3.3816186654343459;
  t921[82ULL] = -t1542 / 3.381618665435564;
  t921[83ULL] = -t1485 / 3.381618665435564;
  t921[84ULL] = -(t1154 * ((-X[4ULL] - X[35ULL]) / 2.0)) / 1683.2579790949012;
  t921[85ULL] = -Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R8 /
    18.369970524521413;
  t921[86ULL] = -t1543 / 3.3816186654355636;
  t921[87ULL] = -intrm_sf_mf_80;
  t921[88ULL] = -intrm_sf_mf_90 + 1.1132499999999999;
  t921[89ULL] = 0.0;
  t921[90ULL] = (X[98ULL] / (t1169 == 0.0 ? 1.0E-16 : t1169) - ((t1173 * t1174 -
    t1171 * X[103ULL]) + t1172 * 100.0)) / 3.18511990906445E+7;
  t921[91ULL] = (t1539 - (t1173 * t1174 + t1171 * X[103ULL])) /
    1.8268887317032829E+7;
  t921[92ULL] = (X[55ULL] / (t1175 == 0.0 ? 1.0E-16 : t1175) - ((t1178 * t1179 -
    t1176 * X[105ULL]) + t1177 * 100.0)) / 3.18511990906445E+7;
  t921[93ULL] = (t1527 - (t1178 * t1179 + t1176 * X[105ULL])) /
    1.8268887317032829E+7;
  t921[94ULL] = -(t1165 * 0.001 + t1161);
  t921[95ULL] = -t1183 / 3.3816186654355636;
  t921[96ULL] = -t1183 / 3.3816186654355636;
  t921[97ULL] = -intrm_sf_mf_124;
  t921[98ULL] = -intrm_sf_mf_127;
  t921[99ULL] = (X[109ULL] / (Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs
    == 0.0 ? 1.0E-16 : Subsystem_Reference_Pipe_TL2_convection_A_mdot_abs) -
                 ((t1200 * t1202 -
                   Subsystem_Reference_Pipe_TL2_convection_A_step_neg * X[116ULL])
                  + Subsystem_Reference_Pipe_TL2_convection_A_pv * 100.0)) /
    2.7839182063167598E+7;
  t921[100ULL] = (t1197 - (t1200 * t1202 +
    Subsystem_Reference_Pipe_TL2_convection_A_step_neg * X[116ULL])) /
    1.5967715333510201E+7;
  t921[101ULL] = (-X[98ULL] / (t1204 == 0.0 ? 1.0E-16 : t1204) - ((t1174 * t1205
    - Subsystem_Reference_Pipe_TL2_convection_B_step_neg * X[118ULL]) +
    Subsystem_Reference_Pipe_TL2_convection_B_pv * 100.0)) /
    2.7839182063167598E+7;
  t921[102ULL] = (t1198 - (t1174 * t1205 +
    Subsystem_Reference_Pipe_TL2_convection_B_step_neg * X[118ULL])) /
    1.5967715333510201E+7;
  t921[103ULL] = -(Subsystem_Reference_Pipe_TL2_Q_cond * 0.001 + intrm_sf_mf_158)
    / 8.1799748982606114E-5;
  t921[104ULL] = -t1208 / 3.3816186654355636;
  t921[105ULL] = -t1208 / 3.3816186654355636;
  t921[106ULL] = -t1162;
  t921[107ULL] = -intrm_sf_mf_176;
  t921[108ULL] = (X[56ULL] / (Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs
    == 0.0 ? 1.0E-16 : Subsystem_Reference_Pipe_TL4_convection_A_mdot_abs) -
                  ((t1215 * t1216 -
                    Subsystem_Reference_Pipe_TL4_convection_A_step_neg * X
                    [123ULL]) + Subsystem_Reference_Pipe_TL4_convection_A_pv *
                   100.0)) / 2.7839182063167598E+7;
  t921[109ULL] = (t1528 - (t1215 * t1216 +
    Subsystem_Reference_Pipe_TL4_convection_A_step_neg * X[123ULL])) /
    1.5967715333510201E+7;
  t921[110ULL] = (X[121ULL] / (t1218 == 0.0 ? 1.0E-16 : t1218) - ((t1221 * t1222
    - t1220 * X[125ULL]) + Subsystem_Reference_Pipe_TL4_convection_B_pv * 100.0))
    / 2.7839182063167598E+7;
  t921[111ULL] = (t1529 - (t1221 * t1222 + t1220 * X[125ULL])) /
    1.5967715333510201E+7;
  t921[112ULL] = -(Subsystem_Reference_Pipe_TL4_Q_cond * 0.001 + t1168) /
    8.1799748982606114E-5;
  t921[113ULL] = -Subsystem_Reference_Pipe_TL4_u_I / 3.3816186654355636;
  t921[114ULL] = -Subsystem_Reference_Pipe_TL4_u_I / 3.3816186654355636;
  t921[115ULL] = -t1188;
  t921[116ULL] = -intrm_sf_mf_221;
  t921[117ULL] = ((-X[27ULL] - X[121ULL]) /
                  (Subsystem_Reference_TCP_6812_convection_A_mdot_abs == 0.0 ?
                   1.0E-16 : Subsystem_Reference_TCP_6812_convection_A_mdot_abs)
                  - ((t1227 * t1229 - t1225 * X[129ULL]) +
                     Subsystem_Reference_TCP_6812_convection_A_pv * 100.0)) /
    5.5678364126335206E+6;
  t921[118ULL] = (t1416 - (t1227 * t1229 + t1225 * X[129ULL])) /
    3.1935430667020408E+6;
  t921[119ULL] = (-X[109ULL] /
                  (Subsystem_Reference_TCP_6812_convection_A_mdot_abs == 0.0 ?
                   1.0E-16 : Subsystem_Reference_TCP_6812_convection_A_mdot_abs)
                  - ((t1202 * t1230 - X[129ULL] *
                      Subsystem_Reference_TCP_6812_convection_B_step_neg) +
                     Subsystem_Reference_TCP_6812_convection_B_pv * 100.0)) /
    5.5678364126335206E+6;
  t921[120ULL] = (Subsystem_Reference_Pipe_TL2_k_B_in - (t1202 * t1230 + X
    [129ULL] * Subsystem_Reference_TCP_6812_convection_B_step_neg)) /
    3.1935430667020408E+6;
  t921[121ULL] = -(t1199 * 1.0E-5);
  t921[122ULL] = t1190 * 0.001;
  t921[123ULL] = -(Subsystem_Reference_TCP_6812_convection_A_rho / 998.2 * t1231);
  t921[124ULL] = (X[121ULL] /
                  (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs
                   == 0.0 ? 1.0E-16 :
                   Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs)
                  - ((t1229 * t1238 - t1237 * X[132ULL]) +
                     Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_pv *
                     100.0)) / 5.5678364126335206E+6;
  t921[125ULL] = (t1413 - (t1229 * t1238 + t1237 * X[132ULL])) /
    3.1935430667020408E+6;
  t921[126ULL] = (-X[121ULL] /
                  (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs
                   == 0.0 ? 1.0E-16 :
                   Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_mdot_abs)
                  - ((t1222 * t1240 - X[132ULL] * t1241) +
                     Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_pv *
                     100.0)) / 5.5678364126335206E+6;
  t921[127ULL] = (t1415 - (t1222 * t1240 + X[132ULL] * t1241)) /
    3.1935430667020408E+6;
  t1707 = pmf_sqrt(pmf_sqrt(t1245 * t1245 * 1.0E+10 + t1239 * t1239));
  t1683 = 1.0 - t1235 * t1235;
  t921[128ULL] = -(t1245 / (t1707 == 0.0 ? 1.0E-16 : t1707) * pmf_sqrt
                   (Subsystem_Reference_TCV_VL6810_orifice_AT_rho_avg * 2.0 /
                    (t1683 == 0.0 ? 1.0E-16 : t1683)) * t1233 * 70000.0);
  t921[129ULL] = (-X[27ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) - ((t1150 * t1250
    - t1249 * X[135ULL]) + t1248 * 100.0)) / 5.5678364126335206E+6;
  t921[130ULL] = (Subsystem_Reference_Pipe_TL4_Pr_A_in - (t1150 * t1250 + t1249 *
    X[135ULL])) / 3.1935430667020408E+6;
  t921[131ULL] = (X[27ULL] / (t1142 == 0.0 ? 1.0E-16 : t1142) - ((t1148 * t1229
    - t1146 * X[135ULL]) + t1145 * 100.0)) / 5.5678364126335206E+6;
  t921[132ULL] = (Subsystem_Reference_Pipe_TL4_Pr_B_in - (t1148 * t1229 + t1146 *
    X[135ULL])) / 3.1935430667020408E+6;
  U_idx_1 = pmf_sqrt(pmf_sqrt(t1255 * t1255 * 1.0E+10 + t1251 * t1251));
  U_idx_0 = 1.0 - t1246 * t1246;
  t921[133ULL] = -(t1255 / (U_idx_1 == 0.0 ? 1.0E-16 : U_idx_1) * pmf_sqrt
                   (Subsystem_Reference_TCV_VL6810_orifice_PA_rho_avg * 2.0 /
                    (U_idx_0 == 0.0 ? 1.0E-16 : U_idx_0)) * t1243 * 70000.0);
  t921[134ULL] = (-X[55ULL] / (t1257 == 0.0 ? 1.0E-16 : t1257) - ((t1179 * t1261
    - t1260 * X[140ULL]) + t1259 * 100.0)) / 5.5678364126335206E+6;
  t921[135ULL] = (Subsystem_Reference_Pipe_TL4_Pr_I - (t1179 * t1261 + t1260 *
    X[140ULL])) / 3.1935430667020408E+6;
  t921[136ULL] = (-Basic_Peripherals_Pipe_TL3_Phi_A / (t1262 == 0.0 ? 1.0E-16 :
    t1262) - ((t1111 * t1268 - X[140ULL] * t1266) + t1264 * 100.0)) /
    5.5678364126335206E+6;
  t921[137ULL] = (Subsystem_Reference_Pipe_TL4_k_I - (t1111 * t1268 + X[140ULL] *
    t1266)) / 3.1935430667020408E+6;
  t921[138ULL] = (-X[56ULL] / (t1269 == 0.0 ? 1.0E-16 : t1269) - ((t1216 * t1275
    - X[140ULL] * t1274) + t1272 * 100.0)) / 5.5678364126335206E+6;
  t921[139ULL] = (t1211 - (t1216 * t1275 + X[140ULL] * t1274)) /
    3.1935430667020408E+6;
  t921[140ULL] = 0.0;
  U_idx_1 = t1276 / 2.0 * pmf_sqrt(X[101ULL] * X[101ULL] + intrm_sf_mf_88 *
    intrm_sf_mf_88) * X[101ULL];
  t1707 = Subsystem_Reference_T_Junction_TL_rho_avg * 3.8553142191755308E-6;
  t921[141ULL] = -(U_idx_1 / (t1707 == 0.0 ? 1.0E-16 : t1707) * 1.0E-5);
  U_idx_1 = t1278 / 2.0 * pmf_sqrt(X[7ULL] * X[7ULL] + intrm_sf_mf_88 *
    intrm_sf_mf_88) * X[7ULL];
  t921[142ULL] = -(U_idx_1 / (t1707 == 0.0 ? 1.0E-16 : t1707) * 1.0E-5);
  U_idx_1 = t1280 / 2.0 * pmf_sqrt(X[16ULL] * X[16ULL] + intrm_sf_mf_88 *
    intrm_sf_mf_88) * X[16ULL];
  t921[143ULL] = -(U_idx_1 / (t1707 == 0.0 ? 1.0E-16 : t1707) * 1.0E-5);
  t921[144ULL] = 0.0;
  t921[145ULL] = 0.0;
  t921[146ULL] = 0.0;
  t921[147ULL] = 0.0;
  for (b = 0; b < 148; b++) {
    out.mX[b] = t921[b];
  }

  (void)LC;
  (void)t1713;
  return 0;
}
