/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_log.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_log(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t591, NeDsMethodOutput *t592)
{
  ETTS0 ab_efOut;
  ETTS0 ac_efOut;
  ETTS0 ad_efOut;
  ETTS0 b_efOut;
  ETTS0 bb_efOut;
  ETTS0 be_efOut;
  ETTS0 cc_efOut;
  ETTS0 cd_efOut;
  ETTS0 d_efOut;
  ETTS0 db_efOut;
  ETTS0 dc_efOut;
  ETTS0 dd_efOut;
  ETTS0 de_efOut;
  ETTS0 eb_efOut;
  ETTS0 efOut;
  ETTS0 fc_efOut;
  ETTS0 fe_efOut;
  ETTS0 g_efOut;
  ETTS0 gc_efOut;
  ETTS0 gd_efOut;
  ETTS0 h_efOut;
  ETTS0 hb_efOut;
  ETTS0 hd_efOut;
  ETTS0 he_efOut;
  ETTS0 ic_efOut;
  ETTS0 j_efOut;
  ETTS0 jb_efOut;
  ETTS0 jc_efOut;
  ETTS0 jd_efOut;
  ETTS0 je_efOut;
  ETTS0 k_efOut;
  ETTS0 lb_efOut;
  ETTS0 ld_efOut;
  ETTS0 le_efOut;
  ETTS0 m_efOut;
  ETTS0 mc_efOut;
  ETTS0 md_efOut;
  ETTS0 n_efOut;
  ETTS0 nb_efOut;
  ETTS0 nc_efOut;
  ETTS0 ne_efOut;
  ETTS0 ob_efOut;
  ETTS0 od_efOut;
  ETTS0 p_efOut;
  ETTS0 pc_efOut;
  ETTS0 pd_efOut;
  ETTS0 pe_efOut;
  ETTS0 qb_efOut;
  ETTS0 r_efOut;
  ETTS0 rb_efOut;
  ETTS0 rc_efOut;
  ETTS0 sc_efOut;
  ETTS0 sd_efOut;
  ETTS0 t45;
  ETTS0 t46;
  ETTS0 t47;
  ETTS0 t51;
  ETTS0 t58;
  ETTS0 t59;
  ETTS0 t60;
  ETTS0 t62;
  ETTS0 t63;
  ETTS0 t64;
  ETTS0 t66;
  ETTS0 t_efOut;
  ETTS0 tb_efOut;
  ETTS0 td_efOut;
  ETTS0 u_efOut;
  ETTS0 uc_efOut;
  ETTS0 vb_efOut;
  ETTS0 vc_efOut;
  ETTS0 vd_efOut;
  ETTS0 w_efOut;
  ETTS0 wb_efOut;
  ETTS0 wd_efOut;
  ETTS0 x_efOut;
  ETTS0 xc_efOut;
  ETTS0 yb_efOut;
  ETTS0 yd_efOut;
  PmRealVector out;
  real_T t417[659];
  real_T X[148];
  real_T nonscalar12[8];
  real_T ae_efOut[1];
  real_T bc_efOut[1];
  real_T bd_efOut[1];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T ce_efOut[1];
  real_T e_efOut[1];
  real_T ec_efOut[1];
  real_T ed_efOut[1];
  real_T ee_efOut[1];
  real_T f_efOut[1];
  real_T fb_efOut[1];
  real_T fd_efOut[1];
  real_T gb_efOut[1];
  real_T ge_efOut[1];
  real_T hc_efOut[1];
  real_T i_efOut[1];
  real_T ib_efOut[1];
  real_T id_efOut[1];
  real_T ie_efOut[1];
  real_T kb_efOut[1];
  real_T kc_efOut[1];
  real_T kd_efOut[1];
  real_T ke_efOut[1];
  real_T l_efOut[1];
  real_T lc_efOut[1];
  real_T mb_efOut[1];
  real_T me_efOut[1];
  real_T nd_efOut[1];
  real_T o_efOut[1];
  real_T oc_efOut[1];
  real_T oe_efOut[1];
  real_T pb_efOut[1];
  real_T q_efOut[1];
  real_T qc_efOut[1];
  real_T qd_efOut[1];
  real_T qe_efOut[1];
  real_T rd_efOut[1];
  real_T s_efOut[1];
  real_T sb_efOut[1];
  real_T t411[1];
  real_T tc_efOut[1];
  real_T ub_efOut[1];
  real_T ud_efOut[1];
  real_T v_efOut[1];
  real_T wc_efOut[1];
  real_T xb_efOut[1];
  real_T xd_efOut[1];
  real_T y_efOut[1];
  real_T yc_efOut[1];
  real_T Basic_Peripherals_Aux_TCP_A_p;
  real_T Basic_Peripherals_Aux_TCP_Phi_A;
  real_T Basic_Peripherals_Aux_TCP_Phi_B;
  real_T Basic_Peripherals_Aux_TCP_R_w;
  real_T Basic_Peripherals_Aux_TCP_convection_A_rho;
  real_T Basic_Peripherals_Aux_TCP_eta;
  real_T Basic_Peripherals_Aux_TCP_hydraulic_power;
  real_T Basic_Peripherals_Aux_TCP_mechanical_power;
  real_T Basic_Peripherals_Aux_TCP_p_diff;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_h_I;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I;
  real_T Basic_Peripherals_Coolant_Tank_Coolant_Volume_u_I;
  real_T Basic_Peripherals_Gate_Valve_TL_area_opening;
  real_T Basic_Peripherals_Gate_Valve_TL_convection_B_rho;
  real_T Basic_Peripherals_Gate_Valve_TL_q_B;
  real_T Basic_Peripherals_Gate_Valve_TL_valve_area;
  real_T Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V;
  real_T Basic_Peripherals_Pipe_TL3_convection_A_rho;
  real_T Basic_Peripherals_Pipe_TL3_convection_B_rho;
  real_T Basic_Peripherals_Pipe_TL3_h_I;
  real_T Basic_Peripherals_Pipe_TL3_rho_I;
  real_T Basic_Peripherals_Pipe_TL3_u_I;
  real_T Basic_Peripherals_T_Junction_TL1_convection_B_rho;
  real_T Basic_Peripherals_T_Junction_TL1_convection_C_rho;
  real_T Basic_Peripherals_T_Junction_TL1_q_C;
  real_T Basic_Peripherals_T_Junction_TL_convection_B_rho;
  real_T Basic_Peripherals_T_Junction_TL_convection_C_rho;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24;
  real_T Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6;
  real_T Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q;
  real_T Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T D_idx_2;
  real_T Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  real_T Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_V;
  real_T Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_V;
  real_T Subsystem_Reference_Pipe_TL2_convection_A_rho;
  real_T Subsystem_Reference_Pipe_TL2_convection_B_rho;
  real_T Subsystem_Reference_Pipe_TL2_h_I;
  real_T Subsystem_Reference_Pipe_TL2_rho_I;
  real_T Subsystem_Reference_Pipe_TL2_u_I;
  real_T Subsystem_Reference_Pipe_TL4_convection_A_rho;
  real_T Subsystem_Reference_Pipe_TL4_convection_B_rho;
  real_T Subsystem_Reference_Pipe_TL4_h_I;
  real_T Subsystem_Reference_Pipe_TL4_rho_I;
  real_T Subsystem_Reference_Pipe_TL4_u_I;
  real_T Subsystem_Reference_TCP_6812_convection_A_rho;
  real_T Subsystem_Reference_TCP_6812_eta;
  real_T Subsystem_Reference_TCP_6812_mechanical_power;
  real_T Subsystem_Reference_TCP_6812_p_diff;
  real_T Subsystem_Reference_TCP_6812_q_A;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_S;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area;
  real_T Subsystem_Reference_TCV_VL6810_orifice_AT_q_B;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_convection_A_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho;
  real_T Subsystem_Reference_TCV_VL6810_orifice_PA_orifice_area;
  real_T Subsystem_Reference_T_Junction_TL_convection_C_rho;
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T U_idx_7;
  real_T intrm_sf_mf_169;
  real_T intrm_sf_mf_221;
  real_T intrm_sf_mf_38;
  real_T intrm_sf_mf_42;
  real_T intrm_sf_mf_44;
  real_T t465_idx_0;
  real_T t467;
  real_T t469;
  real_T t470;
  real_T t471;
  real_T t472;
  real_T t474;
  real_T t476;
  real_T t477;
  real_T t482;
  real_T t484;
  real_T t487;
  real_T t490;
  real_T t491;
  real_T t493;
  real_T t494;
  real_T t495;
  real_T t496;
  real_T t497;
  real_T t498;
  real_T t502;
  real_T t504;
  real_T t505;
  real_T t508;
  real_T t511;
  real_T t523;
  real_T t525;
  real_T t530;
  real_T t531;
  real_T t533;
  real_T t534;
  real_T t544;
  real_T t567;
  real_T t585;
  size_t t360[1];
  size_t t366[1];
  size_t t69[1];
  size_t t70[1];
  size_t t72[1];
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  int32_T Q_idx_2;
  int32_T b;
  boolean_T intrm_sf_mf_48;
  Q_idx_0 = t591->mQ.mX[0];
  Q_idx_1 = t591->mQ.mX[1];
  Q_idx_2 = t591->mQ.mX[2];
  U_idx_0 = t591->mU.mX[0];
  U_idx_1 = t591->mU.mX[1];
  U_idx_2 = t591->mU.mX[2];
  U_idx_3 = t591->mU.mX[3];
  U_idx_4 = t591->mU.mX[4];
  U_idx_5 = t591->mU.mX[5];
  U_idx_6 = t591->mU.mX[6];
  U_idx_7 = t591->mU.mX[7];
  for (b = 0; b < 148; b++) {
    X[b] = t591->mX.mX[b];
  }

  D_idx_0 = t591->mD.mX[0];
  D_idx_1 = t591->mD.mX[1];
  D_idx_2 = t591->mD.mX[2];
  out = t592->mLOG;
  nonscalar12[0] = -209.43951023931953;
  nonscalar12[1] = 0.0;
  nonscalar12[2] = 209.43951023931953;
  nonscalar12[3] = 261.79938779914943;
  nonscalar12[4] = 314.15926535897933;
  nonscalar12[5] = 366.51914291880917;
  nonscalar12[6] = 418.87902047863906;
  nonscalar12[7] = 439.822971502571;
  Basic_Peripherals_Aux_TCP_A_p = X[0ULL] * -0.8 + 1.1132499999999999;
  Basic_Peripherals_Aux_TCP_Phi_A = -X[24ULL] - X[25ULL];
  Basic_Peripherals_Aux_TCP_Phi_B = -X[26ULL] + X[27ULL];
  Basic_Peripherals_Aux_TCP_R_w = U_idx_0 * 0.10471975511965977;
  t411[0ULL] = X[28ULL];
  t69[0] = 20ULL;
  t70[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL], &t69
    [0ULL], &t70[0ULL]);
  t45 = efOut;
  t411[0ULL] = Basic_Peripherals_Aux_TCP_A_p;
  t72[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t62 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = c_efOut[0];
  Basic_Peripherals_Aux_TCP_convection_A_rho = t465_idx_0;
  t467 = pmf_sqrt(Basic_Peripherals_Aux_TCP_R_w * Basic_Peripherals_Aux_TCP_R_w
                  + 13.433628212593847) + Basic_Peripherals_Aux_TCP_R_w;
  Basic_Peripherals_Aux_TCP_p_diff = t467 / 2.0;
  t467 = X[29ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0);
  Basic_Peripherals_Aux_TCP_hydraulic_power = 366.51914291880917 /
    (Basic_Peripherals_Aux_TCP_p_diff == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Aux_TCP_p_diff) * t467;
  if (Basic_Peripherals_Aux_TCP_hydraulic_power < 0.0) {
    Basic_Peripherals_Aux_TCP_mechanical_power = 15.800203873598369;
  } else if (Basic_Peripherals_Aux_TCP_hydraulic_power * 1.0E+6 <=
             1666.6666666666665) {
    Basic_Peripherals_Aux_TCP_mechanical_power =
      Basic_Peripherals_Aux_TCP_hydraulic_power *
      Basic_Peripherals_Aux_TCP_hydraulic_power * -1.2844036697247704E+6 +
      15.800203873598369;
  } else if (Basic_Peripherals_Aux_TCP_hydraulic_power * 1.0E+6 <=
             3333.333333333333) {
    Basic_Peripherals_Aux_TCP_mechanical_power =
      (Basic_Peripherals_Aux_TCP_hydraulic_power * 1834.8623853211036 +
       Basic_Peripherals_Aux_TCP_hydraulic_power *
       Basic_Peripherals_Aux_TCP_hydraulic_power * -1.8348623853211019E+6) +
      14.271151885830777;
  } else {
    Basic_Peripherals_Aux_TCP_mechanical_power =
      (Basic_Peripherals_Aux_TCP_hydraulic_power * 1.0E+6 - 3333.333333333333) *
      -0.010397553516819574;
  }

  Basic_Peripherals_Aux_TCP_p_diff = t465_idx_0 *
    (Basic_Peripherals_Aux_TCP_p_diff / 366.51914291880917 *
     (Basic_Peripherals_Aux_TCP_p_diff / 366.51914291880917) *
     Basic_Peripherals_Aux_TCP_mechanical_power) * 9.81;
  Basic_Peripherals_Aux_TCP_hydraulic_power = Basic_Peripherals_Aux_TCP_p_diff *
    t467;
  Basic_Peripherals_Aux_TCP_mechanical_power = Basic_Peripherals_Aux_TCP_R_w *
    X[32ULL];
  if (Basic_Peripherals_Aux_TCP_hydraulic_power > 0.0) {
    if (Basic_Peripherals_Aux_TCP_mechanical_power > 0.0) {
      if (Basic_Peripherals_Aux_TCP_hydraulic_power * 0.001 <
          Basic_Peripherals_Aux_TCP_mechanical_power * 0.001) {
        Basic_Peripherals_Aux_TCP_eta =
          Basic_Peripherals_Aux_TCP_hydraulic_power /
          (Basic_Peripherals_Aux_TCP_mechanical_power == 0.0 ? 1.0E-16 :
           Basic_Peripherals_Aux_TCP_mechanical_power);
      } else {
        Basic_Peripherals_Aux_TCP_eta = 1.0;
      }
    } else {
      Basic_Peripherals_Aux_TCP_eta = 1.0;
    }
  } else {
    Basic_Peripherals_Aux_TCP_eta = 0.0;
  }

  Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0 = -X[29ULL] -
    X[35ULL];
  t411[0ULL] = X[1ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = d_efOut;
  tlu2_2d_linear_linear_value(&e_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = e_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I = t465_idx_0;
  tlu2_2d_linear_linear_value(&f_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = f_efOut[0];
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_u_I = t465_idx_0;
  Basic_Peripherals_Coolant_Tank_Coolant_Volume_h_I =
    Basic_Peripherals_Aux_TCP_A_p /
    (Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I == 0.0 ? 1.0E-16 :
     Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I) * 100.0 + t465_idx_0;
  Basic_Peripherals_Gate_Valve_TL_valve_area = U_idx_1 / 0.045000000000000005;
  if (Basic_Peripherals_Gate_Valve_TL_valve_area <= 0.0) {
    Basic_Peripherals_Gate_Valve_TL_area_opening = 0.0;
  } else if (Basic_Peripherals_Gate_Valve_TL_valve_area <= 0.005) {
    Basic_Peripherals_Gate_Valve_TL_area_opening =
      Basic_Peripherals_Gate_Valve_TL_valve_area *
      Basic_Peripherals_Gate_Valve_TL_valve_area * 100.50251256281406;
  } else if (Basic_Peripherals_Gate_Valve_TL_valve_area <= 0.995) {
    Basic_Peripherals_Gate_Valve_TL_area_opening =
      Basic_Peripherals_Gate_Valve_TL_valve_area * 1.0050251256281406 -
      0.0025125628140703518;
  } else if (Basic_Peripherals_Gate_Valve_TL_valve_area <= 1.0) {
    Basic_Peripherals_Gate_Valve_TL_area_opening = (1.0 -
      Basic_Peripherals_Gate_Valve_TL_valve_area) * (1.0 -
      Basic_Peripherals_Gate_Valve_TL_valve_area) * -100.50251256281406 + 1.0;
  } else {
    Basic_Peripherals_Gate_Valve_TL_area_opening = 1.0;
  }

  Basic_Peripherals_Gate_Valve_TL_valve_area =
    Basic_Peripherals_Gate_Valve_TL_area_opening * 0.045000000000000005;
  if (Basic_Peripherals_Gate_Valve_TL_valve_area / 0.045000000000000005 <= -1.0)
  {
    Basic_Peripherals_Gate_Valve_TL_area_opening = -1.0;
  } else if (Basic_Peripherals_Gate_Valve_TL_valve_area / 0.045000000000000005 >=
             1.0) {
    Basic_Peripherals_Gate_Valve_TL_area_opening = 1.0;
  } else {
    Basic_Peripherals_Gate_Valve_TL_area_opening =
      Basic_Peripherals_Gate_Valve_TL_valve_area / 0.045000000000000005;
  }

  Basic_Peripherals_Gate_Valve_TL_convection_B_rho = pmf_acos
    (Basic_Peripherals_Gate_Valve_TL_area_opening) * 0.0010125000000000002 -
    Basic_Peripherals_Gate_Valve_TL_valve_area / 2.0 * pmf_sqrt
    (0.0020250000000000003 - Basic_Peripherals_Gate_Valve_TL_valve_area *
     Basic_Peripherals_Gate_Valve_TL_valve_area);
  Basic_Peripherals_Gate_Valve_TL_valve_area = (0.0015904312808798331 -
    Basic_Peripherals_Gate_Valve_TL_convection_B_rho) + 1.0E-12;
  t411[0ULL] = X[45ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t58 = g_efOut;
  t411[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t47 = h_efOut;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = i_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_area_opening = t465_idx_0;
  t411[0ULL] = X[48ULL];
  tlu2_linear_linear_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = j_efOut;
  t411[0ULL] = X[44ULL];
  tlu2_linear_linear_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t66 = k_efOut;
  tlu2_2d_linear_linear_value(&l_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t66.mField0[0ULL], &t66.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = l_efOut[0];
  Basic_Peripherals_Gate_Valve_TL_convection_B_rho = t465_idx_0;
  Basic_Peripherals_Gate_Valve_TL_q_B = -X[46ULL] / (t465_idx_0 == 0.0 ? 1.0E-16
    : t465_idx_0);
  t470 = -X[51ULL] + X[26ULL];
  t411[0ULL] = X[49ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = m_efOut;
  t411[0ULL] = X[50ULL];
  tlu2_linear_linear_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t58 = n_efOut;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t58.mField0[0ULL], &t58.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = o_efOut[0];
  Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V = -X[4ULL] / (t465_idx_0 ==
    0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t411[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = p_efOut;
  tlu2_2d_linear_linear_value(&q_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = q_efOut[0];
  t471 = X[46ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t411[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&r_efOut.mField0[0ULL], &r_efOut.mField1[0ULL],
    &r_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = r_efOut;
  tlu2_2d_linear_linear_value(&s_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = s_efOut[0];
  t472 = X[29ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t474 = Basic_Peripherals_Aux_TCP_R_w * X[32ULL] * 0.001;
  t476 = -X[55ULL] - X[56ULL];
  t411[0ULL] = X[6ULL];
  tlu2_linear_nearest_prelookup(&t_efOut.mField0[0ULL], &t_efOut.mField1[0ULL],
    &t_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t62 = t_efOut;
  t411[0ULL] = X[5ULL];
  tlu2_linear_nearest_prelookup(&u_efOut.mField0[0ULL], &u_efOut.mField1[0ULL],
    &u_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t45 = u_efOut;
  tlu2_2d_linear_nearest_value(&v_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = v_efOut[0];
  t477 = t465_idx_0;
  t411[0ULL] = X[58ULL];
  tlu2_linear_linear_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t51 = w_efOut;
  t411[0ULL] = X[38ULL];
  tlu2_linear_linear_prelookup(&x_efOut.mField0[0ULL], &x_efOut.mField1[0ULL],
    &x_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t60 = x_efOut;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t51.mField0[0ULL], &t51.mField2
    [0ULL], &t60.mField0[0ULL], &t60.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = y_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_A_rho = t465_idx_0;
  t411[0ULL] = X[60ULL];
  tlu2_linear_linear_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = ab_efOut;
  t411[0ULL] = X[54ULL];
  tlu2_linear_linear_prelookup(&bb_efOut.mField0[0ULL], &bb_efOut.mField1[0ULL],
    &bb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t59 = bb_efOut;
  tlu2_2d_linear_linear_value(&cb_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t59.mField0[0ULL], &t59.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = cb_efOut[0];
  Basic_Peripherals_Pipe_TL3_convection_B_rho = t465_idx_0;
  t411[0ULL] = X[6ULL];
  tlu2_linear_linear_prelookup(&db_efOut.mField0[0ULL], &db_efOut.mField1[0ULL],
    &db_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t62 = db_efOut;
  t411[0ULL] = X[5ULL];
  tlu2_linear_linear_prelookup(&eb_efOut.mField0[0ULL], &eb_efOut.mField1[0ULL],
    &eb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t45 = eb_efOut;
  tlu2_2d_linear_linear_value(&fb_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = fb_efOut[0];
  Basic_Peripherals_Pipe_TL3_rho_I = t465_idx_0;
  tlu2_2d_linear_linear_value(&gb_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = gb_efOut[0];
  Basic_Peripherals_Pipe_TL3_u_I = t465_idx_0;
  Basic_Peripherals_Pipe_TL3_h_I = X[5ULL] / (Basic_Peripherals_Pipe_TL3_rho_I ==
    0.0 ? 1.0E-16 : Basic_Peripherals_Pipe_TL3_rho_I) * 100.0 + t465_idx_0;
  t411[0ULL] = X[62ULL];
  tlu2_linear_linear_prelookup(&hb_efOut.mField0[0ULL], &hb_efOut.mField1[0ULL],
    &hb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = hb_efOut;
  tlu2_2d_linear_linear_value(&ib_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t59.mField0[0ULL], &t59.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ib_efOut[0];
  t482 = t465_idx_0;
  t411[0ULL] = X[63ULL];
  tlu2_linear_linear_prelookup(&jb_efOut.mField0[0ULL], &jb_efOut.mField1[0ULL],
    &jb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t62 = jb_efOut;
  tlu2_2d_linear_linear_value(&kb_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t58.mField0[0ULL], &t58.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = kb_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_B_rho = t465_idx_0;
  t411[0ULL] = X[64ULL];
  tlu2_linear_linear_prelookup(&lb_efOut.mField0[0ULL], &lb_efOut.mField1[0ULL],
    &lb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = lb_efOut;
  tlu2_2d_linear_linear_value(&mb_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t66.mField0[0ULL], &t66.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = mb_efOut[0];
  Basic_Peripherals_T_Junction_TL_convection_C_rho = t465_idx_0;
  t484 = X[46ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0);
  t411[0ULL] = X[73ULL];
  tlu2_linear_linear_prelookup(&nb_efOut.mField0[0ULL], &nb_efOut.mField1[0ULL],
    &nb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t59 = nb_efOut;
  t411[0ULL] = X[23ULL];
  tlu2_linear_linear_prelookup(&ob_efOut.mField0[0ULL], &ob_efOut.mField1[0ULL],
    &ob_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t58 = ob_efOut;
  tlu2_2d_linear_linear_value(&pb_efOut[0ULL], &t59.mField0[0ULL], &t59.mField2
    [0ULL], &t58.mField0[0ULL], &t58.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = pb_efOut[0];
  t469 = t465_idx_0;
  t411[0ULL] = X[74ULL];
  tlu2_linear_linear_prelookup(&qb_efOut.mField0[0ULL], &qb_efOut.mField1[0ULL],
    &qb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = qb_efOut;
  t411[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&rb_efOut.mField0[0ULL], &rb_efOut.mField1[0ULL],
    &rb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t46 = rb_efOut;
  tlu2_2d_linear_linear_value(&sb_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t46.mField0[0ULL], &t46.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = sb_efOut[0];
  Basic_Peripherals_T_Junction_TL1_convection_B_rho = t465_idx_0;
  t411[0ULL] = X[75ULL];
  tlu2_linear_linear_prelookup(&tb_efOut.mField0[0ULL], &tb_efOut.mField1[0ULL],
    &tb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t63 = tb_efOut;
  tlu2_2d_linear_linear_value(&ub_efOut[0ULL], &t63.mField0[0ULL], &t63.mField2
    [0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ub_efOut[0];
  Basic_Peripherals_T_Junction_TL1_convection_C_rho = t465_idx_0;
  Basic_Peripherals_T_Junction_TL1_q_C = X[9ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 :
    t465_idx_0);
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 = tanh(X[85ULL]
    * 3.0 / 0.029511607098668874) * X[85ULL];
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q = tanh(U_idx_2 *
    3.0 / 0.029511607098668874) * U_idx_2;
  intrm_sf_mf_48 =
    (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 >=
     Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q);
  t490 = intrm_sf_mf_48 ?
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 :
    Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q;
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6 =
    intrm_sf_mf_48 ?
    Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q :
    Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24;
  t490 = (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6 +
          0.029511607098668874) / (t490 + 0.029511607098668874 == 0.0 ? 1.0E-16 :
    t490 + 0.029511607098668874);
  t491 = (-X[10ULL] + X[86ULL]) + X[87ULL];
  t493 = (X[88ULL] <= 5.0 ? 5.0 : X[88ULL]) * 0.47700000000000009;
  t494 = (U_idx_3 <= 0.01 ? 0.01 : U_idx_3) * 2.9881500000000005;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = (1.0 / (t493 ==
    0.0 ? 1.0E-16 : t493) + 1.0 / (t494 == 0.0 ? 1.0E-16 : t494)) +
    0.000163312919218431;
  t495 = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T * 6.0;
  if (Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6 >= 1.0 /
      (t495 == 0.0 ? 1.0E-16 : t495)) {
    t496 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6 *
      Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T;
    intrm_sf_mf_44 = pmf_exp(-1.0 / (t496 == 0.0 ? 1.0E-16 : t496));
  } else {
    intrm_sf_mf_44 = 0.0024787521766663585;
  }

  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6 = -pmf_log
    (intrm_sf_mf_44);
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = (1.0 -
    pmf_exp(-t490 * (1.0 - intrm_sf_mf_44))) * (1.0 / (t490 == 0.0 ? 1.0E-16 :
    t490));
  t497 = -(1.0 - pmf_pow(intrm_sf_mf_44, t490));
  intrm_sf_mf_44 = 1.0 - pmf_exp(t497 / (t490 == 0.0 ? 1.0E-16 : t490));
  t493 = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 >=
    Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q ?
    intrm_sf_mf_44 :
    Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T;
  t411[0ULL] = X[10ULL];
  tlu2_linear_linear_prelookup(&vb_efOut.mField0[0ULL], &vb_efOut.mField1[0ULL],
    &vb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = vb_efOut;
  t411[0ULL] = X[11ULL];
  tlu2_linear_linear_prelookup(&wb_efOut.mField0[0ULL], &wb_efOut.mField1[0ULL],
    &wb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t47 = wb_efOut;
  tlu2_2d_linear_linear_value(&xb_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = xb_efOut[0];
  Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24 = t465_idx_0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q = U_idx_5 *
    0.001;
  t411[0ULL] = X[14ULL];
  tlu2_linear_nearest_prelookup(&yb_efOut.mField0[0ULL], &yb_efOut.mField1[0ULL],
    &yb_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t51 = yb_efOut;
  t411[0ULL] = X[13ULL];
  tlu2_linear_nearest_prelookup(&ac_efOut.mField0[0ULL], &ac_efOut.mField1[0ULL],
    &ac_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t47 = ac_efOut;
  tlu2_2d_linear_nearest_value(&bc_efOut[0ULL], &t51.mField0[0ULL],
    &t51.mField2[0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = bc_efOut[0];
  intrm_sf_mf_44 = t465_idx_0;
  t411[0ULL] = X[102ULL];
  tlu2_linear_linear_prelookup(&cc_efOut.mField0[0ULL], &cc_efOut.mField1[0ULL],
    &cc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t47 = cc_efOut;
  t411[0ULL] = X[95ULL];
  tlu2_linear_linear_prelookup(&dc_efOut.mField0[0ULL], &dc_efOut.mField1[0ULL],
    &dc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t59 = dc_efOut;
  tlu2_2d_linear_linear_value(&ec_efOut[0ULL], &t47.mField0[0ULL], &t47.mField2
    [0ULL], &t59.mField0[0ULL], &t59.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ec_efOut[0];
  t494 = t465_idx_0;
  t411[0ULL] = X[104ULL];
  tlu2_linear_linear_prelookup(&fc_efOut.mField0[0ULL], &fc_efOut.mField1[0ULL],
    &fc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t58 = fc_efOut;
  t411[0ULL] = X[97ULL];
  tlu2_linear_linear_prelookup(&gc_efOut.mField0[0ULL], &gc_efOut.mField1[0ULL],
    &gc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t63 = gc_efOut;
  tlu2_2d_linear_linear_value(&hc_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t63.mField0[0ULL], &t63.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = hc_efOut[0];
  t495 = t465_idx_0;
  t411[0ULL] = X[14ULL];
  tlu2_linear_linear_prelookup(&ic_efOut.mField0[0ULL], &ic_efOut.mField1[0ULL],
    &ic_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t62 = ic_efOut;
  t411[0ULL] = X[13ULL];
  tlu2_linear_linear_prelookup(&jc_efOut.mField0[0ULL], &jc_efOut.mField1[0ULL],
    &jc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t45 = jc_efOut;
  tlu2_2d_linear_linear_value(&kc_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = kc_efOut[0];
  t496 = t465_idx_0;
  tlu2_2d_linear_linear_value(&lc_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = lc_efOut[0];
  t497 = t465_idx_0;
  t498 = X[13ULL] / (t496 == 0.0 ? 1.0E-16 : t496) * 100.0 + t465_idx_0;
  Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w = U_idx_6 *
    0.10471975511965977;
  t411[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&mc_efOut.mField0[0ULL], &mc_efOut.mField1[0ULL],
    &mc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = mc_efOut;
  t411[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&nc_efOut.mField0[0ULL], &nc_efOut.mField1[0ULL],
    &nc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t62 = nc_efOut;
  tlu2_2d_linear_linear_value(&oc_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = oc_efOut[0];
  Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_V = X[110ULL] /
    (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t411[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&pc_efOut.mField0[0ULL], &pc_efOut.mField1[0ULL],
    &pc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = pc_efOut;
  tlu2_2d_linear_linear_value(&qc_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t46.mField0[0ULL], &t46.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = qc_efOut[0];
  Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_V = -X[8ULL] /
    (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t411[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&rc_efOut.mField0[0ULL], &rc_efOut.mField1[0ULL],
    &rc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = rc_efOut;
  t411[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&sc_efOut.mField0[0ULL], &sc_efOut.mField1[0ULL],
    &sc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t51 = sc_efOut;
  tlu2_2d_linear_linear_value(&tc_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t51.mField0[0ULL], &t51.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = tc_efOut[0];
  t505 = -X[16ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0) * 1.0E+6;
  t411[0ULL] = X[18ULL];
  tlu2_linear_nearest_prelookup(&uc_efOut.mField0[0ULL], &uc_efOut.mField1[0ULL],
    &uc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t66 = uc_efOut;
  t411[0ULL] = X[17ULL];
  tlu2_linear_nearest_prelookup(&vc_efOut.mField0[0ULL], &vc_efOut.mField1[0ULL],
    &vc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t47 = vc_efOut;
  tlu2_2d_linear_nearest_value(&wc_efOut[0ULL], &t66.mField0[0ULL],
    &t66.mField2[0ULL], &t47.mField0[0ULL], &t47.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = wc_efOut[0];
  t508 = t465_idx_0;
  t411[0ULL] = X[115ULL];
  tlu2_linear_linear_prelookup(&xc_efOut.mField0[0ULL], &xc_efOut.mField1[0ULL],
    &xc_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t58 = xc_efOut;
  tlu2_2d_linear_linear_value(&yc_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = yc_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_A_rho = t465_idx_0;
  t411[0ULL] = X[117ULL];
  tlu2_linear_linear_prelookup(&ad_efOut.mField0[0ULL], &ad_efOut.mField1[0ULL],
    &ad_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t47 = ad_efOut;
  tlu2_2d_linear_linear_value(&bd_efOut[0ULL], &t47.mField0[0ULL], &t47.mField2
    [0ULL], &t59.mField0[0ULL], &t59.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = bd_efOut[0];
  Subsystem_Reference_Pipe_TL2_convection_B_rho = t465_idx_0;
  t411[0ULL] = X[18ULL];
  tlu2_linear_linear_prelookup(&cd_efOut.mField0[0ULL], &cd_efOut.mField1[0ULL],
    &cd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t62 = cd_efOut;
  t411[0ULL] = X[17ULL];
  tlu2_linear_linear_prelookup(&dd_efOut.mField0[0ULL], &dd_efOut.mField1[0ULL],
    &dd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t45 = dd_efOut;
  tlu2_2d_linear_linear_value(&ed_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ed_efOut[0];
  Subsystem_Reference_Pipe_TL2_rho_I = t465_idx_0;
  tlu2_2d_linear_linear_value(&fd_efOut[0ULL], &t62.mField0[0ULL], &t62.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = fd_efOut[0];
  Subsystem_Reference_Pipe_TL2_u_I = t465_idx_0;
  Subsystem_Reference_Pipe_TL2_h_I = X[17ULL] /
    (Subsystem_Reference_Pipe_TL2_rho_I == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL2_rho_I) * 100.0 + t465_idx_0;
  t511 = -X[8ULL] - X[110ULL];
  t411[0ULL] = X[20ULL];
  tlu2_linear_nearest_prelookup(&gd_efOut.mField0[0ULL], &gd_efOut.mField1[0ULL],
    &gd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t66 = gd_efOut;
  t411[0ULL] = X[19ULL];
  tlu2_linear_nearest_prelookup(&hd_efOut.mField0[0ULL], &hd_efOut.mField1[0ULL],
    &hd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t59 = hd_efOut;
  tlu2_2d_linear_nearest_value(&id_efOut[0ULL], &t66.mField0[0ULL],
    &t66.mField2[0ULL], &t59.mField0[0ULL], &t59.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = id_efOut[0];
  intrm_sf_mf_38 = t465_idx_0;
  t411[0ULL] = X[122ULL];
  tlu2_linear_linear_prelookup(&jd_efOut.mField0[0ULL], &jd_efOut.mField1[0ULL],
    &jd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t47 = jd_efOut;
  tlu2_2d_linear_linear_value(&kd_efOut[0ULL], &t47.mField0[0ULL], &t47.mField2
    [0ULL], &t51.mField0[0ULL], &t51.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = kd_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_A_rho = t465_idx_0;
  t411[0ULL] = X[124ULL];
  tlu2_linear_linear_prelookup(&ld_efOut.mField0[0ULL], &ld_efOut.mField1[0ULL],
    &ld_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = ld_efOut;
  t411[0ULL] = X[120ULL];
  tlu2_linear_linear_prelookup(&md_efOut.mField0[0ULL], &md_efOut.mField1[0ULL],
    &md_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t58 = md_efOut;
  tlu2_2d_linear_linear_value(&nd_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t58.mField0[0ULL], &t58.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = nd_efOut[0];
  Subsystem_Reference_Pipe_TL4_convection_B_rho = t465_idx_0;
  t411[0ULL] = X[20ULL];
  tlu2_linear_linear_prelookup(&od_efOut.mField0[0ULL], &od_efOut.mField1[0ULL],
    &od_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t64 = od_efOut;
  t411[0ULL] = X[19ULL];
  tlu2_linear_linear_prelookup(&pd_efOut.mField0[0ULL], &pd_efOut.mField1[0ULL],
    &pd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t45 = pd_efOut;
  tlu2_2d_linear_linear_value(&qd_efOut[0ULL], &t64.mField0[0ULL], &t64.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = qd_efOut[0];
  Subsystem_Reference_Pipe_TL4_rho_I = t465_idx_0;
  tlu2_2d_linear_linear_value(&rd_efOut[0ULL], &t64.mField0[0ULL], &t64.mField2
    [0ULL], &t45.mField0[0ULL], &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField3, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = rd_efOut[0];
  Subsystem_Reference_Pipe_TL4_u_I = t465_idx_0;
  Subsystem_Reference_Pipe_TL4_h_I = X[19ULL] /
    (Subsystem_Reference_Pipe_TL4_rho_I == 0.0 ? 1.0E-16 :
     Subsystem_Reference_Pipe_TL4_rho_I) * 100.0 + t465_idx_0;
  t523 = -X[27ULL] - X[121ULL];
  t411[0ULL] = X[128ULL];
  tlu2_linear_linear_prelookup(&sd_efOut.mField0[0ULL], &sd_efOut.mField1[0ULL],
    &sd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t59 = sd_efOut;
  t411[0ULL] = X[127ULL];
  tlu2_linear_linear_prelookup(&td_efOut.mField0[0ULL], &td_efOut.mField1[0ULL],
    &td_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t411[0ULL],
    &t72[0ULL], &t70[0ULL]);
  t62 = td_efOut;
  tlu2_2d_linear_linear_value(&ud_efOut[0ULL], &t59.mField0[0ULL], &t59.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ud_efOut[0];
  Subsystem_Reference_TCP_6812_convection_A_rho = t465_idx_0;
  Subsystem_Reference_TCP_6812_q_A = X[110ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 :
    t465_idx_0);
  t411[0ULL] = Subsystem_Reference_TCP_6812_q_A * 1.0E+6;
  t366[0] = 15ULL;
  tlu2_linear_linear_prelookup(&vd_efOut.mField0[0ULL], &vd_efOut.mField1[0ULL],
    &vd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField11, &t411[0ULL],
    &t366[0ULL], &t70[0ULL]);
  t66 = vd_efOut;
  t411[0ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t360[0] = 8ULL;
  tlu2_linear_linear_prelookup(&wd_efOut.mField0[0ULL], &wd_efOut.mField1[0ULL],
    &wd_efOut.mField2[0ULL], &nonscalar12[0ULL], &t411[0ULL], &t360[0ULL], &t70
    [0ULL]);
  t64 = wd_efOut;
  tlu2_2d_linear_linear_value(&xd_efOut[0ULL], &t66.mField0[0ULL], &t66.mField2
    [0ULL], &t64.mField0[0ULL], &t64.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField10, &t366[0ULL], &t360[0ULL], &t70[0ULL]);
  t465_idx_0 = xd_efOut[0];
  Subsystem_Reference_TCP_6812_p_diff =
    Subsystem_Reference_TCP_6812_convection_A_rho * t465_idx_0 * 9.81;
  t502 = Subsystem_Reference_TCP_6812_p_diff * Subsystem_Reference_TCP_6812_q_A;
  Subsystem_Reference_TCP_6812_mechanical_power = -(X[108ULL] *
    Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w);
  if (t502 > 0.0) {
    if (Subsystem_Reference_TCP_6812_mechanical_power > 0.0) {
      if (t502 * 0.001 < Subsystem_Reference_TCP_6812_mechanical_power * 0.001)
      {
        Subsystem_Reference_TCP_6812_eta = t502 /
          (Subsystem_Reference_TCP_6812_mechanical_power == 0.0 ? 1.0E-16 :
           Subsystem_Reference_TCP_6812_mechanical_power);
      } else {
        Subsystem_Reference_TCP_6812_eta = 1.0;
      }
    } else {
      Subsystem_Reference_TCP_6812_eta = 1.0;
    }
  } else {
    Subsystem_Reference_TCP_6812_eta = 0.0;
  }

  Subsystem_Reference_TCV_VL6810_orifice_AT_S = U_idx_7 * -0.001 + 0.0025;
  t411[0ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_S;
  t366[0] = 11ULL;
  tlu2_linear_nearest_prelookup(&yd_efOut.mField0[0ULL], &yd_efOut.mField1[0ULL],
    &yd_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t411[0ULL],
    &t366[0ULL], &t70[0ULL]);
  t59 = yd_efOut;
  tlu2_1d_linear_nearest_value(&ae_efOut[0ULL], &t59.mField0[0ULL],
    &t59.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t366[0ULL], &t70
    [0ULL]);
  t465_idx_0 = ae_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area = t465_idx_0;
  t411[0ULL] = X[131ULL];
  tlu2_linear_linear_prelookup(&be_efOut.mField0[0ULL], &be_efOut.mField1[0ULL],
    &be_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = be_efOut;
  tlu2_2d_linear_linear_value(&ce_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ce_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho = t465_idx_0;
  t411[0ULL] = X[133ULL];
  tlu2_linear_linear_prelookup(&de_efOut.mField0[0ULL], &de_efOut.mField1[0ULL],
    &de_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t47 = de_efOut;
  tlu2_2d_linear_linear_value(&ee_efOut[0ULL], &t47.mField0[0ULL], &t47.mField2
    [0ULL], &t58.mField0[0ULL], &t58.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ee_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho = t465_idx_0;
  Subsystem_Reference_TCV_VL6810_orifice_AT_q_B = -t511 / (t465_idx_0 == 0.0 ?
    1.0E-16 : t465_idx_0);
  t525 = U_idx_7 * 0.001 + 0.0025;
  t411[0ULL] = t525;
  tlu2_linear_nearest_prelookup(&fe_efOut.mField0[0ULL], &fe_efOut.mField1[0ULL],
    &fe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField14, &t411[0ULL],
    &t366[0ULL], &t70[0ULL]);
  t45 = fe_efOut;
  tlu2_1d_linear_nearest_value(&ge_efOut[0ULL], &t45.mField0[0ULL],
    &t45.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField13, &t366[0ULL], &t70
    [0ULL]);
  t465_idx_0 = ge_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_orifice_area = t465_idx_0;
  t411[0ULL] = X[134ULL];
  tlu2_linear_linear_prelookup(&he_efOut.mField0[0ULL], &he_efOut.mField1[0ULL],
    &he_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t58 = he_efOut;
  tlu2_2d_linear_linear_value(&ie_efOut[0ULL], &t58.mField0[0ULL], &t58.mField2
    [0ULL], &t46.mField0[0ULL], &t46.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ie_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_convection_A_rho = t465_idx_0;
  t411[0ULL] = X[136ULL];
  tlu2_linear_linear_prelookup(&je_efOut.mField0[0ULL], &je_efOut.mField1[0ULL],
    &je_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = je_efOut;
  tlu2_2d_linear_linear_value(&ke_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t62.mField0[0ULL], &t62.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = ke_efOut[0];
  Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho = t465_idx_0;
  t504 = X[8ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0);
  t411[0ULL] = X[137ULL];
  tlu2_linear_linear_prelookup(&le_efOut.mField0[0ULL], &le_efOut.mField1[0ULL],
    &le_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = le_efOut;
  tlu2_2d_linear_linear_value(&me_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t63.mField0[0ULL], &t63.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = me_efOut[0];
  t487 = t465_idx_0;
  t411[0ULL] = X[138ULL];
  tlu2_linear_linear_prelookup(&ne_efOut.mField0[0ULL], &ne_efOut.mField1[0ULL],
    &ne_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = ne_efOut;
  tlu2_2d_linear_linear_value(&oe_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t60.mField0[0ULL], &t60.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t465_idx_0 = oe_efOut[0];
  t411[0ULL] = X[139ULL];
  tlu2_linear_linear_prelookup(&pe_efOut.mField0[0ULL], &pe_efOut.mField1[0ULL],
    &pe_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t411[0ULL],
    &t69[0ULL], &t70[0ULL]);
  t45 = pe_efOut;
  tlu2_2d_linear_linear_value(&qe_efOut[0ULL], &t45.mField0[0ULL], &t45.mField2
    [0ULL], &t51.mField0[0ULL], &t51.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t69[0ULL], &t72[0ULL], &t70[0ULL]);
  t411[0] = qe_efOut[0];
  Subsystem_Reference_T_Junction_TL_convection_C_rho = t411[0ULL];
  t530 = X[100ULL] >= 0.0 ? X[100ULL] : -X[100ULL];
  intrm_sf_mf_221 = intrm_sf_mf_44 * 0.0015;
  intrm_sf_mf_169 = t530 * 0.01 / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_221);
  t531 = intrm_sf_mf_169 >= 1.0 ? intrm_sf_mf_169 : 1.0;
  t533 = pmf_log10(6.9 / (t531 == 0.0 ? 1.0E-16 : t531) + 0.002211858722000578) *
    pmf_log10(6.9 / (t531 == 0.0 ? 1.0E-16 : t531) + 0.002211858722000578) *
    3.24;
  t531 = 1.0 / (t533 == 0.0 ? 1.0E-16 : t533);
  intrm_sf_mf_42 = t496 * 3.0000000000000004E-7;
  t533 = X[100ULL] * intrm_sf_mf_44 * 114.05125168440817 / (intrm_sf_mf_42 ==
    0.0 ? 1.0E-16 : intrm_sf_mf_42);
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = t496 * 4.5E-8;
  t530 = X[100ULL] * t530 * t531 * 1.7820508075688777 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T);
  t531 = (intrm_sf_mf_169 - 2000.0) / 2000.0;
  t534 = t531 * t531 * 3.0 - t531 * t531 * t531 * 2.0;
  if (intrm_sf_mf_169 <= 2000.0) {
    t531 = t533 * 1.0E-5;
  } else if (intrm_sf_mf_169 >= 4000.0) {
    t531 = t530 * 1.0E-5;
  } else {
    t531 = ((1.0 - t534) * t533 + t530 * t534) * 1.0E-5;
  }

  if (-X[101ULL] >= 0.0) {
    t530 = -X[101ULL];
  } else {
    t530 = X[101ULL];
  }

  intrm_sf_mf_169 = t530 * 0.01 / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_221);
  t533 = intrm_sf_mf_169 >= 1.0 ? intrm_sf_mf_169 : 1.0;
  t544 = pmf_log10(6.9 / (t533 == 0.0 ? 1.0E-16 : t533) + 0.002211858722000578) *
    pmf_log10(6.9 / (t533 == 0.0 ? 1.0E-16 : t533) + 0.002211858722000578) *
    3.24;
  intrm_sf_mf_44 = intrm_sf_mf_44 * X[101ULL] * -114.05125168440817 /
    (intrm_sf_mf_42 == 0.0 ? 1.0E-16 : intrm_sf_mf_42);
  t530 = X[101ULL] * t530 * (1.0 / (t544 == 0.0 ? 1.0E-16 : t544)) *
    -1.7820508075688777 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T);
  t533 = (intrm_sf_mf_169 - 2000.0) / 2000.0;
  t534 = t533 * t533 * 3.0 - t533 * t533 * t533 * 2.0;
  if (intrm_sf_mf_169 <= 2000.0) {
    t533 = intrm_sf_mf_44 * 1.0E-5;
  } else if (intrm_sf_mf_169 >= 4000.0) {
    t533 = t530 * 1.0E-5;
  } else {
    t533 = ((1.0 - t534) * intrm_sf_mf_44 + t530 * t534) * 1.0E-5;
  }

  intrm_sf_mf_44 = X[110ULL] >= 0.0 ? X[110ULL] : -X[110ULL];
  t544 = t508 * 0.0019634954084936209;
  t530 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  intrm_sf_mf_169 = t530 >= 1.0 ? t530 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (intrm_sf_mf_169 == 0.0 ? 1.0E-16 : intrm_sf_mf_169) +
    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_169 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_169) + 9.0751776413883736E-6) * 3.24;
  t567 = Subsystem_Reference_Pipe_TL2_rho_I * 7.8484637847008924E-5;
  t534 = X[110ULL] * t508 * 48.0 / (t567 == 0.0 ? 1.0E-16 : t567);
  t585 = Subsystem_Reference_Pipe_TL2_rho_I * 1.0900644145417907E-6;
  intrm_sf_mf_44 = X[110ULL] * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)) *
    0.75 / (t585 == 0.0 ? 1.0E-16 : t585);
  intrm_sf_mf_169 = (t530 - 2000.0) / 2000.0;
  intrm_sf_mf_221 = intrm_sf_mf_169 * intrm_sf_mf_169 * 3.0 - intrm_sf_mf_169 *
    intrm_sf_mf_169 * intrm_sf_mf_169 * 2.0;
  if (t530 <= 2000.0) {
    intrm_sf_mf_169 = t534 * 1.0E-5;
  } else if (t530 >= 4000.0) {
    intrm_sf_mf_169 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    intrm_sf_mf_169 = ((1.0 - intrm_sf_mf_221) * t534 + intrm_sf_mf_44 *
                       intrm_sf_mf_221) * 1.0E-5;
  }

  if (-X[100ULL] >= 0.0) {
    intrm_sf_mf_44 = -X[100ULL];
  } else {
    intrm_sf_mf_44 = X[100ULL];
  }

  t530 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  t534 = t530 >= 1.0 ? t530 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (t534 == 0.0 ? 1.0E-16 : t534) + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (t534 == 0.0 ? 1.0E-16 : t534) + 9.0751776413883736E-6) * 3.24;
  t508 = X[100ULL] * t508 * -48.0 / (t567 == 0.0 ? 1.0E-16 : t567);
  intrm_sf_mf_44 = X[100ULL] * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)) *
    -0.75 / (t585 == 0.0 ? 1.0E-16 : t585);
  t534 = (t530 - 2000.0) / 2000.0;
  intrm_sf_mf_221 = t534 * t534 * 3.0 - t534 * t534 * t534 * 2.0;
  if (t530 <= 2000.0) {
    t534 = t508 * 1.0E-5;
  } else if (t530 >= 4000.0) {
    t534 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    t534 = ((1.0 - intrm_sf_mf_221) * t508 + intrm_sf_mf_44 * intrm_sf_mf_221) *
      1.0E-5;
  }

  if (-X[16ULL] >= 0.0) {
    intrm_sf_mf_44 = -X[16ULL];
  } else {
    intrm_sf_mf_44 = X[16ULL];
  }

  t544 = intrm_sf_mf_38 * 0.0019634954084936209;
  t508 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  t530 = t508 >= 1.0 ? t508 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (t530 == 0.0 ? 1.0E-16 : t530) + 9.0751776413883736E-6) * pmf_log10(6.9 /
    (t530 == 0.0 ? 1.0E-16 : t530) + 9.0751776413883736E-6) * 3.24;
  t567 = Subsystem_Reference_Pipe_TL4_rho_I * 7.8484637847008924E-5;
  intrm_sf_mf_221 = intrm_sf_mf_38 * X[16ULL] * -48.0 / (t567 == 0.0 ? 1.0E-16 :
    t567);
  t585 = Subsystem_Reference_Pipe_TL4_rho_I * 1.0900644145417907E-6;
  intrm_sf_mf_44 = X[16ULL] * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)) *
    -0.75 / (t585 == 0.0 ? 1.0E-16 : t585);
  t530 = (t508 - 2000.0) / 2000.0;
  intrm_sf_mf_42 = t530 * t530 * 3.0 - t530 * t530 * t530 * 2.0;
  if (t508 <= 2000.0) {
    t530 = intrm_sf_mf_221 * 1.0E-5;
  } else if (t508 >= 4000.0) {
    t530 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    t530 = ((1.0 - intrm_sf_mf_42) * intrm_sf_mf_221 + intrm_sf_mf_44 *
            intrm_sf_mf_42) * 1.0E-5;
  }

  intrm_sf_mf_44 = t511 >= 0.0 ? t511 : -t511;
  t508 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  intrm_sf_mf_221 = t508 >= 1.0 ? t508 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 : intrm_sf_mf_221) +
    9.0751776413883736E-6) * pmf_log10(6.9 / (intrm_sf_mf_221 == 0.0 ? 1.0E-16 :
    intrm_sf_mf_221) + 9.0751776413883736E-6) * 3.24;
  intrm_sf_mf_38 = t511 * intrm_sf_mf_38 * 48.0 / (t567 == 0.0 ? 1.0E-16 : t567);
  intrm_sf_mf_44 = t511 * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)) *
    0.75 / (t585 == 0.0 ? 1.0E-16 : t585);
  intrm_sf_mf_221 = (t508 - 2000.0) / 2000.0;
  intrm_sf_mf_42 = intrm_sf_mf_221 * intrm_sf_mf_221 * 3.0 - intrm_sf_mf_221 *
    intrm_sf_mf_221 * intrm_sf_mf_221 * 2.0;
  if (t508 <= 2000.0) {
    intrm_sf_mf_221 = intrm_sf_mf_38 * 1.0E-5;
  } else if (t508 >= 4000.0) {
    intrm_sf_mf_221 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    intrm_sf_mf_221 = ((1.0 - intrm_sf_mf_42) * intrm_sf_mf_38 + intrm_sf_mf_44 *
                       intrm_sf_mf_42) * 1.0E-5;
  }

  if (-X[7ULL] >= 0.0) {
    intrm_sf_mf_44 = -X[7ULL];
  } else {
    intrm_sf_mf_44 = X[7ULL];
  }

  t544 = t477 * 0.0019634954084936209;
  t508 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  intrm_sf_mf_38 = t508 >= 1.0 ? t508 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (intrm_sf_mf_38 == 0.0 ? 1.0E-16 : intrm_sf_mf_38) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_38 == 0.0 ? 1.0E-16 : intrm_sf_mf_38) +
                9.0751776413883736E-6) * 3.24;
  t567 = Basic_Peripherals_Pipe_TL3_rho_I * 7.8484637847008924E-5;
  intrm_sf_mf_42 = t477 * X[7ULL] * -64.0 / (t567 == 0.0 ? 1.0E-16 : t567);
  t585 = Basic_Peripherals_Pipe_TL3_rho_I * 1.0900644145417907E-6;
  intrm_sf_mf_44 = -(X[7ULL] * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)))
    / (t585 == 0.0 ? 1.0E-16 : t585);
  intrm_sf_mf_38 = (t508 - 2000.0) / 2000.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T =
    intrm_sf_mf_38 * intrm_sf_mf_38 * 3.0 - intrm_sf_mf_38 * intrm_sf_mf_38 *
    intrm_sf_mf_38 * 2.0;
  if (t508 <= 2000.0) {
    intrm_sf_mf_38 = intrm_sf_mf_42 * 1.0E-5;
  } else if (t508 >= 4000.0) {
    intrm_sf_mf_38 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    intrm_sf_mf_38 = ((1.0 -
                       Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)
                      * intrm_sf_mf_42 + intrm_sf_mf_44 *
                      Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)
      * 1.0E-5;
  }

  if (-X[57ULL] >= 0.0) {
    intrm_sf_mf_44 = -X[57ULL];
  } else {
    intrm_sf_mf_44 = X[57ULL];
  }

  t508 = intrm_sf_mf_44 * 0.1413716694115407 / (t544 == 0.0 ? 1.0E-16 : t544);
  intrm_sf_mf_42 = t508 >= 1.0 ? t508 : 1.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T = pmf_log10(6.9
    / (intrm_sf_mf_42 == 0.0 ? 1.0E-16 : intrm_sf_mf_42) + 9.0751776413883736E-6)
    * pmf_log10(6.9 / (intrm_sf_mf_42 == 0.0 ? 1.0E-16 : intrm_sf_mf_42) +
                9.0751776413883736E-6) * 3.24;
  t477 = t477 * X[57ULL] * -64.0 / (t567 == 0.0 ? 1.0E-16 : t567);
  intrm_sf_mf_44 = -(X[57ULL] * intrm_sf_mf_44 * (1.0 /
    (Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T == 0.0 ?
     1.0E-16 : Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)))
    / (t585 == 0.0 ? 1.0E-16 : t585);
  intrm_sf_mf_42 = (t508 - 2000.0) / 2000.0;
  Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T =
    intrm_sf_mf_42 * intrm_sf_mf_42 * 3.0 - intrm_sf_mf_42 * intrm_sf_mf_42 *
    intrm_sf_mf_42 * 2.0;
  if (t508 <= 2000.0) {
    intrm_sf_mf_42 = t477 * 1.0E-5;
  } else if (t508 >= 4000.0) {
    intrm_sf_mf_42 = intrm_sf_mf_44 * 1.0E-5;
  } else {
    intrm_sf_mf_42 = ((1.0 -
                       Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)
                      * t477 + intrm_sf_mf_44 *
                      Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_T)
      * 1.0E-5;
  }

  t417[0ULL] = X[21ULL];
  t417[1ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[2ULL] = X[22ULL];
  t417[3ULL] = X[23ULL] * 0.1;
  t417[4ULL] = Basic_Peripherals_Aux_TCP_Phi_A;
  t417[5ULL] = Basic_Peripherals_Aux_TCP_Phi_B;
  t417[6ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[7ULL] = X[21ULL];
  t417[8ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[9ULL] = Basic_Peripherals_Aux_TCP_Phi_A;
  t417[10ULL] = X[28ULL];
  t417[11ULL] = X[29ULL];
  t417[12ULL] = X[30ULL];
  t417[13ULL] = X[22ULL];
  t417[14ULL] = X[23ULL] * 0.1;
  t417[15ULL] = Basic_Peripherals_Aux_TCP_Phi_B;
  t417[16ULL] = X[31ULL];
  t417[17ULL] = -X[29ULL];
  t417[18ULL] = X[30ULL];
  t417[19ULL] = X[29ULL];
  t417[20ULL] = Basic_Peripherals_Aux_TCP_convection_A_rho;
  t417[21ULL] = t467;
  t417[22ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[23ULL] = Basic_Peripherals_Aux_TCP_p_diff * 1.0000000000000002E-6;
  t417[24ULL] = Basic_Peripherals_Aux_TCP_hydraulic_power * 0.001;
  t417[25ULL] = X[32ULL];
  t417[26ULL] = Basic_Peripherals_Aux_TCP_mechanical_power * 0.001;
  t417[27ULL] = Basic_Peripherals_Aux_TCP_eta;
  t417[28ULL] = -X[29ULL];
  t417[29ULL] = X[21ULL];
  t417[30ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[31ULL] = X[1ULL];
  t417[32ULL] = X[24ULL];
  t417[33ULL] = X[33ULL];
  t417[34ULL] = X[1ULL];
  t417[35ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[36ULL] = X[21ULL];
  t417[37ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[38ULL] = X[24ULL];
  t417[39ULL] = X[34ULL];
  t417[40ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0;
  t417[41ULL] = X[36ULL];
  t417[42ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_rho_I;
  t417[43ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_u_I;
  t417[44ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_h_I;
  t417[45ULL] = X[2ULL];
  t417[46ULL] = X[2ULL] + 0.001;
  t417[47ULL] = X[33ULL];
  t417[48ULL] = X[0ULL] * 80000.0;
  t417[49ULL] = Basic_Peripherals_Coolant_Tank_Coolant_Volume_convection_A_mdo0;
  t417[50ULL] = X[1ULL];
  t417[51ULL] = X[1ULL];
  t417[52ULL] = X[21ULL];
  t417[53ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[54ULL] = X[33ULL];
  t417[55ULL] = X[0ULL] * 80000.0;
  t417[56ULL] = -X[33ULL];
  t417[57ULL] = X[0ULL] * 0.08;
  t417[58ULL] = X[37ULL];
  t417[59ULL] = X[38ULL] * 0.1;
  t417[60ULL] = X[39ULL];
  t417[61ULL] = X[40ULL] * 0.1;
  t417[62ULL] = X[41ULL];
  t417[63ULL] = X[42ULL] * 0.1;
  t417[64ULL] = X[43ULL];
  t417[65ULL] = X[44ULL] * 0.1;
  t417[66ULL] = X[26ULL];
  t417[67ULL] = -X[26ULL];
  t417[68ULL] = U_idx_1;
  t417[69ULL] = X[41ULL];
  t417[70ULL] = X[42ULL] * 0.1;
  t417[71ULL] = X[26ULL];
  t417[72ULL] = X[45ULL];
  t417[73ULL] = X[46ULL];
  t417[74ULL] = X[47ULL];
  t417[75ULL] = X[43ULL];
  t417[76ULL] = X[44ULL] * 0.1;
  t417[77ULL] = -X[26ULL];
  t417[78ULL] = X[48ULL];
  t417[79ULL] = -X[46ULL];
  t417[80ULL] = X[47ULL];
  t417[81ULL] = Basic_Peripherals_Gate_Valve_TL_valve_area;
  t417[82ULL] = X[46ULL];
  t417[83ULL] = -X[46ULL];
  t417[84ULL] = Basic_Peripherals_Gate_Valve_TL_area_opening;
  t417[85ULL] = X[46ULL] / (Basic_Peripherals_Gate_Valve_TL_area_opening == 0.0 ?
    1.0E-16 : Basic_Peripherals_Gate_Valve_TL_area_opening);
  t417[86ULL] = Basic_Peripherals_Gate_Valve_TL_convection_B_rho;
  t417[87ULL] = Basic_Peripherals_Gate_Valve_TL_q_B;
  t417[88ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[89ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[90ULL] = -X[32ULL];
  t417[91ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[92ULL] = X[3ULL];
  t417[93ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[94ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[95ULL] = X[3ULL];
  t417[96ULL] = X[3ULL];
  t417[97ULL] = Basic_Peripherals_Aux_TCP_R_w * 9.5492965855137211;
  t417[98ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[99ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[100ULL] = X[32ULL];
  t417[101ULL] = X[32ULL];
  t417[102ULL] = X[32ULL];
  t417[103ULL] = X[49ULL];
  t417[104ULL] = X[50ULL] * 0.1;
  t417[105ULL] = X[49ULL];
  t417[106ULL] = X[50ULL] * 0.1;
  t417[107ULL] = t470;
  t417[108ULL] = Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V * 1.0E-6;
  t417[109ULL] = -X[4ULL];
  t417[110ULL] = Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V *
    0.060000000000000012;
  t417[111ULL] = X[41ULL];
  t417[112ULL] = X[42ULL] * 0.1;
  t417[113ULL] = X[41ULL];
  t417[114ULL] = X[42ULL] * 0.1;
  t417[115ULL] = X[26ULL];
  t417[116ULL] = t471 * 1.0E-6;
  t417[117ULL] = X[46ULL];
  t417[118ULL] = t471 * 0.060000000000000012;
  t417[119ULL] = X[21ULL];
  t417[120ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[121ULL] = X[21ULL];
  t417[122ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[123ULL] = Basic_Peripherals_Aux_TCP_Phi_A;
  t417[124ULL] = t472 * 1.0E-6;
  t417[125ULL] = X[29ULL];
  t417[126ULL] = t472 * 1.0E-6;
  t417[127ULL] = X[32ULL];
  t417[128ULL] = Basic_Peripherals_Aux_TCP_R_w;
  t417[129ULL] = t474 * 1000.0;
  t417[130ULL] = t474 * 1000.0;
  t417[131ULL] = X[52ULL];
  t417[132ULL] = X[52ULL];
  t417[133ULL] = X[37ULL];
  t417[134ULL] = X[38ULL] * 0.1;
  t417[135ULL] = X[53ULL];
  t417[136ULL] = X[54ULL] * 0.1;
  t417[137ULL] = X[52ULL];
  t417[138ULL] = t476;
  t417[139ULL] = X[51ULL];
  t417[140ULL] = X[5ULL] * 0.1;
  t417[141ULL] = X[6ULL];
  t417[142ULL] = -X[7ULL];
  t417[143ULL] = -X[57ULL];
  t417[144ULL] = X[37ULL];
  t417[145ULL] = X[38ULL] * 0.1;
  t417[146ULL] = t476;
  t417[147ULL] = X[58ULL];
  t417[148ULL] = -X[7ULL];
  t417[149ULL] = X[59ULL];
  t417[150ULL] = X[53ULL];
  t417[151ULL] = X[54ULL] * 0.1;
  t417[152ULL] = X[51ULL];
  t417[153ULL] = X[60ULL];
  t417[154ULL] = -X[57ULL];
  t417[155ULL] = X[61ULL];
  t417[156ULL] = Basic_Peripherals_Pipe_TL3_rho_I;
  t417[157ULL] = Basic_Peripherals_Pipe_TL3_u_I;
  t417[158ULL] = Basic_Peripherals_Pipe_TL3_h_I;
  t417[159ULL] = intrm_sf_mf_38 * 0.1;
  t417[160ULL] = intrm_sf_mf_42 * 0.1;
  t417[161ULL] = Basic_Peripherals_Pipe_TL3_convection_A_rho;
  t417[162ULL] = -X[7ULL] / (Basic_Peripherals_Pipe_TL3_convection_A_rho == 0.0 ?
    1.0E-16 : Basic_Peripherals_Pipe_TL3_convection_A_rho);
  t417[163ULL] = Basic_Peripherals_Pipe_TL3_convection_B_rho;
  t417[164ULL] = -X[57ULL] / (Basic_Peripherals_Pipe_TL3_convection_B_rho == 0.0
    ? 1.0E-16 : Basic_Peripherals_Pipe_TL3_convection_B_rho);
  t417[165ULL] = X[21ULL];
  t417[166ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[167ULL] = Basic_Peripherals_Aux_TCP_A_p * 99999.999999999985;
  t417[168ULL] = X[21ULL];
  t417[169ULL] = Basic_Peripherals_Aux_TCP_A_p * 99999.999999999985;
  t417[170ULL] = X[21ULL];
  t417[171ULL] = U_idx_0;
  t417[172ULL] = U_idx_1;
  t417[173ULL] = X[53ULL];
  t417[174ULL] = X[54ULL] * 0.1;
  t417[175ULL] = X[49ULL];
  t417[176ULL] = X[50ULL] * 0.1;
  t417[177ULL] = X[43ULL];
  t417[178ULL] = X[44ULL] * 0.1;
  t417[179ULL] = X[57ULL];
  t417[180ULL] = X[4ULL];
  t417[181ULL] = X[46ULL];
  t417[182ULL] = X[53ULL];
  t417[183ULL] = X[54ULL] * 0.1;
  t417[184ULL] = -X[51ULL];
  t417[185ULL] = X[62ULL];
  t417[186ULL] = X[57ULL];
  t417[187ULL] = X[65ULL];
  t417[188ULL] = X[49ULL];
  t417[189ULL] = X[50ULL] * 0.1;
  t417[190ULL] = -t470;
  t417[191ULL] = X[63ULL];
  t417[192ULL] = X[4ULL];
  t417[193ULL] = X[65ULL];
  t417[194ULL] = X[43ULL];
  t417[195ULL] = X[44ULL] * 0.1;
  t417[196ULL] = X[26ULL];
  t417[197ULL] = X[64ULL];
  t417[198ULL] = X[46ULL];
  t417[199ULL] = X[65ULL];
  t417[200ULL] = -X[51ULL];
  t417[201ULL] = -t470;
  t417[202ULL] = X[26ULL];
  t417[203ULL] = X[66ULL] * 0.1;
  t417[204ULL] = X[67ULL] * 0.1;
  t417[205ULL] = X[68ULL] * 0.1;
  t417[206ULL] = D_idx_0;
  t417[207ULL] = X[72ULL] * 0.1;
  t417[208ULL] = t482;
  t417[209ULL] = X[57ULL] / (t482 == 0.0 ? 1.0E-16 : t482);
  t417[210ULL] = Basic_Peripherals_T_Junction_TL_convection_B_rho;
  t417[211ULL] = X[4ULL] / (Basic_Peripherals_T_Junction_TL_convection_B_rho ==
    0.0 ? 1.0E-16 : Basic_Peripherals_T_Junction_TL_convection_B_rho);
  t417[212ULL] = Basic_Peripherals_T_Junction_TL_convection_C_rho;
  t417[213ULL] = t484;
  t417[214ULL] = (real_T)(size_t)Q_idx_0;
  t417[215ULL] = X[22ULL];
  t417[216ULL] = X[23ULL] * 0.1;
  t417[217ULL] = X[39ULL];
  t417[218ULL] = X[40ULL] * 0.1;
  t417[219ULL] = X[41ULL];
  t417[220ULL] = X[42ULL] * 0.1;
  t417[221ULL] = X[29ULL];
  t417[222ULL] = X[8ULL];
  t417[223ULL] = X[9ULL];
  t417[224ULL] = X[22ULL];
  t417[225ULL] = X[23ULL] * 0.1;
  t417[226ULL] = -Basic_Peripherals_Aux_TCP_Phi_B;
  t417[227ULL] = X[73ULL];
  t417[228ULL] = X[29ULL];
  t417[229ULL] = X[76ULL];
  t417[230ULL] = X[39ULL];
  t417[231ULL] = X[40ULL] * 0.1;
  t417[232ULL] = X[27ULL];
  t417[233ULL] = X[74ULL];
  t417[234ULL] = X[8ULL];
  t417[235ULL] = X[76ULL];
  t417[236ULL] = X[41ULL];
  t417[237ULL] = X[42ULL] * 0.1;
  t417[238ULL] = -X[26ULL];
  t417[239ULL] = X[75ULL];
  t417[240ULL] = -X[46ULL];
  t417[241ULL] = X[76ULL];
  t417[242ULL] = -Basic_Peripherals_Aux_TCP_Phi_B;
  t417[243ULL] = X[27ULL];
  t417[244ULL] = -X[26ULL];
  t417[245ULL] = X[77ULL] * 0.1;
  t417[246ULL] = X[78ULL] * 0.1;
  t417[247ULL] = X[79ULL] * 0.1;
  t417[248ULL] = D_idx_1;
  t417[249ULL] = X[83ULL] * 0.1;
  t417[250ULL] = t469;
  t417[251ULL] = X[29ULL] / (t469 == 0.0 ? 1.0E-16 : t469);
  t417[252ULL] = Basic_Peripherals_T_Junction_TL1_convection_B_rho;
  t417[253ULL] = X[8ULL] / (Basic_Peripherals_T_Junction_TL1_convection_B_rho ==
    0.0 ? 1.0E-16 : Basic_Peripherals_T_Junction_TL1_convection_B_rho);
  t417[254ULL] = Basic_Peripherals_T_Junction_TL1_convection_C_rho;
  t417[255ULL] = Basic_Peripherals_T_Junction_TL1_q_C;
  t417[256ULL] = (real_T)(size_t)Q_idx_1;
  t417[257ULL] = X[21ULL];
  t417[258ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[259ULL] = X[49ULL];
  t417[260ULL] = X[50ULL] * 0.1;
  t417[261ULL] = U_idx_2;
  t417[262ULL] = U_idx_3;
  t417[263ULL] = U_idx_4;
  t417[264ULL] = X[84ULL] * 1000.0;
  t417[265ULL] = U_idx_4;
  t417[266ULL] = U_idx_4;
  t417[267ULL] = U_idx_3;
  t417[268ULL] = U_idx_4;
  t417[269ULL] = U_idx_2;
  t417[270ULL] = U_idx_4;
  t417[271ULL] = X[21ULL];
  t417[272ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[273ULL] = X[49ULL];
  t417[274ULL] = X[50ULL] * 0.1;
  t417[275ULL] = X[49ULL];
  t417[276ULL] = X[50ULL] * 0.1;
  t417[277ULL] = X[21ULL];
  t417[278ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[279ULL] = U_idx_2;
  t417[280ULL] = U_idx_4;
  t417[281ULL] = U_idx_3;
  t417[282ULL] = X[85ULL];
  t417[283ULL] = U_idx_2;
  t417[284ULL] = t490;
  t417[285ULL] = t491;
  t417[286ULL] = U_idx_4;
  t417[287ULL] = X[88ULL];
  t417[288ULL] = U_idx_3;
  t417[289ULL] = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R6;
  t417[290ULL] = X[84ULL];
  t417[291ULL] = t493;
  t417[292ULL] = X[49ULL];
  t417[293ULL] = X[50ULL] * 0.1;
  t417[294ULL] = X[21ULL];
  t417[295ULL] = Basic_Peripherals_Aux_TCP_A_p * 0.1;
  t417[296ULL] = t470;
  t417[297ULL] = X[25ULL];
  t417[298ULL] = X[86ULL];
  t417[299ULL] = X[87ULL];
  t417[300ULL] = X[10ULL];
  t417[301ULL] = -X[4ULL];
  t417[302ULL] = X[35ULL];
  t417[303ULL] = X[11ULL] * 0.1;
  t417[304ULL] = X[89ULL];
  t417[305ULL] = X[90ULL];
  t417[306ULL] = X[91ULL];
  t417[307ULL] = X[92ULL];
  t417[308ULL] = X[93ULL];
  t417[309ULL] = X[85ULL];
  t417[310ULL] = t491;
  t417[311ULL] = X[88ULL];
  t417[312ULL] = -X[84ULL];
  t417[313ULL] = Basic_Peripherals_Variant_Subsystem_Phyiscal_Radiator_Model_R24;
  t417[314ULL] = X[12ULL];
  t417[315ULL] = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q *
    1000.0;
  t417[316ULL] = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q *
    1000.0;
  t417[317ULL] = -X[12ULL];
  t417[318ULL] = X[94ULL];
  t417[319ULL] = X[95ULL] * 0.1;
  t417[320ULL] = X[96ULL];
  t417[321ULL] = X[97ULL] * 0.1;
  t417[322ULL] = X[94ULL];
  t417[323ULL] = X[95ULL] * 0.1;
  t417[324ULL] = X[96ULL];
  t417[325ULL] = X[97ULL] * 0.1;
  t417[326ULL] = X[12ULL];
  t417[327ULL] = X[98ULL];
  t417[328ULL] = X[55ULL];
  t417[329ULL] = X[13ULL] * 0.1;
  t417[330ULL] = X[14ULL];
  t417[331ULL] = X[100ULL];
  t417[332ULL] = -X[101ULL];
  t417[333ULL] = X[99ULL];
  t417[334ULL] = X[94ULL];
  t417[335ULL] = X[95ULL] * 0.1;
  t417[336ULL] = X[98ULL];
  t417[337ULL] = X[102ULL];
  t417[338ULL] = X[100ULL];
  t417[339ULL] = X[103ULL];
  t417[340ULL] = X[96ULL];
  t417[341ULL] = X[97ULL] * 0.1;
  t417[342ULL] = X[55ULL];
  t417[343ULL] = X[104ULL];
  t417[344ULL] = -X[101ULL];
  t417[345ULL] = X[105ULL];
  t417[346ULL] = t496;
  t417[347ULL] = t497;
  t417[348ULL] = t498;
  t417[349ULL] = t531 * 0.1;
  t417[350ULL] = t533 * 0.1;
  t417[351ULL] = t494;
  t417[352ULL] = X[100ULL] / (t494 == 0.0 ? 1.0E-16 : t494);
  t417[353ULL] = t495;
  t417[354ULL] = -X[101ULL] / (t495 == 0.0 ? 1.0E-16 : t495);
  t417[355ULL] = X[12ULL];
  t417[356ULL] = X[12ULL];
  t417[357ULL] = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q *
    1000.0;
  t417[358ULL] = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q *
    1000.0;
  t417[359ULL] = Basic_Stack_Heat_Emulation_Controlled_Heat_Flow_Rate_Source1_Q;
  t417[360ULL] = X[12ULL];
  t417[361ULL] = X[12ULL];
  t417[362ULL] = (-X[99ULL] + U_idx_5 * 0.001) * 1000.0;
  t417[363ULL] = X[12ULL];
  t417[364ULL] = U_idx_5;
  t417[365ULL] = X[39ULL];
  t417[366ULL] = X[40ULL] * 0.1;
  t417[367ULL] = X[96ULL];
  t417[368ULL] = X[97ULL] * 0.1;
  t417[369ULL] = X[37ULL];
  t417[370ULL] = X[38ULL] * 0.1;
  t417[371ULL] = X[94ULL];
  t417[372ULL] = X[95ULL] * 0.1;
  t417[373ULL] = X[106ULL];
  t417[374ULL] = X[107ULL] * 0.1;
  t417[375ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[376ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[377ULL] = X[108ULL];
  t417[378ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[379ULL] = X[15ULL];
  t417[380ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[381ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[382ULL] = X[15ULL];
  t417[383ULL] = X[15ULL];
  t417[384ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w *
    9.5492965855137211;
  t417[385ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[386ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[387ULL] = -X[108ULL];
  t417[388ULL] = -X[108ULL];
  t417[389ULL] = X[106ULL];
  t417[390ULL] = X[107ULL] * 0.1;
  t417[391ULL] = X[106ULL];
  t417[392ULL] = X[107ULL] * 0.1;
  t417[393ULL] = X[109ULL] * 1000.0;
  t417[394ULL] = X[109ULL];
  t417[395ULL] = Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_V * 1.0E-6;
  t417[396ULL] = X[110ULL];
  t417[397ULL] = X[39ULL];
  t417[398ULL] = X[40ULL] * 0.1;
  t417[399ULL] = X[39ULL];
  t417[400ULL] = X[40ULL] * 0.1;
  t417[401ULL] = -X[27ULL];
  t417[402ULL] = Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_V * 1.0E-6;
  t417[403ULL] = -X[8ULL];
  t417[404ULL] = Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL1_V *
    0.060000000000000012;
  t417[405ULL] = X[111ULL];
  t417[406ULL] = X[112ULL] * 0.1;
  t417[407ULL] = X[111ULL];
  t417[408ULL] = X[112ULL] * 0.1;
  t417[409ULL] = X[56ULL] * 1000.0;
  t417[410ULL] = X[56ULL];
  t417[411ULL] = t505 * 1.0E-6;
  t417[412ULL] = -X[16ULL];
  t417[413ULL] = X[56ULL] * 1000.0;
  t417[414ULL] = t505 * 0.060000000000000012;
  t417[415ULL] = X[109ULL] * 1000.0;
  t417[416ULL] = Subsystem_Reference_Mass_Energy_Flow_Rate_Sensor_TL_V *
    0.060000000000000012;
  t417[417ULL] = -X[108ULL];
  t417[418ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[419ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w * X
    [108ULL] * -0.001 * 1000.0;
  t417[420ULL] = X[113ULL];
  t417[421ULL] = X[113ULL];
  t417[422ULL] = X[114ULL];
  t417[423ULL] = X[114ULL];
  t417[424ULL] = X[106ULL];
  t417[425ULL] = X[107ULL] * 0.1;
  t417[426ULL] = X[94ULL];
  t417[427ULL] = X[95ULL] * 0.1;
  t417[428ULL] = X[113ULL];
  t417[429ULL] = X[109ULL];
  t417[430ULL] = -X[98ULL];
  t417[431ULL] = X[17ULL] * 0.1;
  t417[432ULL] = X[18ULL];
  t417[433ULL] = X[110ULL];
  t417[434ULL] = -X[100ULL];
  t417[435ULL] = X[106ULL];
  t417[436ULL] = X[107ULL] * 0.1;
  t417[437ULL] = X[109ULL];
  t417[438ULL] = X[115ULL];
  t417[439ULL] = X[110ULL];
  t417[440ULL] = X[116ULL];
  t417[441ULL] = X[94ULL];
  t417[442ULL] = X[95ULL] * 0.1;
  t417[443ULL] = -X[98ULL];
  t417[444ULL] = X[117ULL];
  t417[445ULL] = -X[100ULL];
  t417[446ULL] = X[118ULL];
  t417[447ULL] = Subsystem_Reference_Pipe_TL2_rho_I;
  t417[448ULL] = Subsystem_Reference_Pipe_TL2_u_I;
  t417[449ULL] = Subsystem_Reference_Pipe_TL2_h_I;
  t417[450ULL] = intrm_sf_mf_169 * 0.1;
  t417[451ULL] = t534 * 0.1;
  t417[452ULL] = Subsystem_Reference_Pipe_TL2_convection_A_rho;
  t417[453ULL] = X[110ULL] / (Subsystem_Reference_Pipe_TL2_convection_A_rho ==
    0.0 ? 1.0E-16 : Subsystem_Reference_Pipe_TL2_convection_A_rho);
  t417[454ULL] = Subsystem_Reference_Pipe_TL2_convection_B_rho;
  t417[455ULL] = -X[100ULL] / (Subsystem_Reference_Pipe_TL2_convection_B_rho ==
    0.0 ? 1.0E-16 : Subsystem_Reference_Pipe_TL2_convection_B_rho);
  t417[456ULL] = X[111ULL];
  t417[457ULL] = X[112ULL] * 0.1;
  t417[458ULL] = X[119ULL];
  t417[459ULL] = X[120ULL] * 0.1;
  t417[460ULL] = X[114ULL];
  t417[461ULL] = X[56ULL];
  t417[462ULL] = X[121ULL];
  t417[463ULL] = X[19ULL] * 0.1;
  t417[464ULL] = X[20ULL];
  t417[465ULL] = -X[16ULL];
  t417[466ULL] = t511;
  t417[467ULL] = X[111ULL];
  t417[468ULL] = X[112ULL] * 0.1;
  t417[469ULL] = X[56ULL];
  t417[470ULL] = X[122ULL];
  t417[471ULL] = -X[16ULL];
  t417[472ULL] = X[123ULL];
  t417[473ULL] = X[119ULL];
  t417[474ULL] = X[120ULL] * 0.1;
  t417[475ULL] = X[121ULL];
  t417[476ULL] = X[124ULL];
  t417[477ULL] = t511;
  t417[478ULL] = X[125ULL];
  t417[479ULL] = Subsystem_Reference_Pipe_TL4_rho_I;
  t417[480ULL] = Subsystem_Reference_Pipe_TL4_u_I;
  t417[481ULL] = Subsystem_Reference_Pipe_TL4_h_I;
  t417[482ULL] = t530 * 0.1;
  t417[483ULL] = intrm_sf_mf_221 * 0.1;
  t417[484ULL] = Subsystem_Reference_Pipe_TL4_convection_A_rho;
  t417[485ULL] = -X[16ULL] / (Subsystem_Reference_Pipe_TL4_convection_A_rho ==
    0.0 ? 1.0E-16 : Subsystem_Reference_Pipe_TL4_convection_A_rho);
  t417[486ULL] = Subsystem_Reference_Pipe_TL4_convection_B_rho;
  t417[487ULL] = t511 / (Subsystem_Reference_Pipe_TL4_convection_B_rho == 0.0 ?
    1.0E-16 : Subsystem_Reference_Pipe_TL4_convection_B_rho);
  t417[488ULL] = X[94ULL];
  t417[489ULL] = X[95ULL] * 0.1;
  t417[490ULL] = X[95ULL] * 99999.999999999985;
  t417[491ULL] = X[94ULL];
  t417[492ULL] = X[95ULL] * 99999.999999999985;
  t417[493ULL] = X[94ULL];
  t417[494ULL] = X[106ULL];
  t417[495ULL] = X[107ULL] * 0.1;
  t417[496ULL] = X[107ULL] * 99999.999999999985;
  t417[497ULL] = X[106ULL];
  t417[498ULL] = X[107ULL] * 99999.999999999985;
  t417[499ULL] = X[106ULL];
  t417[500ULL] = X[126ULL];
  t417[501ULL] = X[127ULL] * 0.1;
  t417[502ULL] = X[127ULL] * 99999.999999999985;
  t417[503ULL] = X[126ULL];
  t417[504ULL] = X[127ULL] * 99999.999999999985;
  t417[505ULL] = X[126ULL];
  t417[506ULL] = X[96ULL];
  t417[507ULL] = X[97ULL] * 0.1;
  t417[508ULL] = X[97ULL] * 99999.999999999985;
  t417[509ULL] = X[96ULL];
  t417[510ULL] = X[97ULL] * 99999.999999999985;
  t417[511ULL] = X[96ULL];
  t417[512ULL] = X[39ULL];
  t417[513ULL] = X[40ULL] * 0.1;
  t417[514ULL] = X[40ULL] * 99999.999999999985;
  t417[515ULL] = X[39ULL];
  t417[516ULL] = X[40ULL] * 99999.999999999985;
  t417[517ULL] = X[39ULL];
  t417[518ULL] = U_idx_6;
  t417[519ULL] = U_idx_7;
  t417[520ULL] = X[126ULL];
  t417[521ULL] = X[127ULL] * 0.1;
  t417[522ULL] = X[106ULL];
  t417[523ULL] = X[107ULL] * 0.1;
  t417[524ULL] = t523;
  t417[525ULL] = -X[109ULL];
  t417[526ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[527ULL] = X[126ULL];
  t417[528ULL] = X[127ULL] * 0.1;
  t417[529ULL] = t523;
  t417[530ULL] = X[128ULL];
  t417[531ULL] = X[110ULL];
  t417[532ULL] = X[129ULL];
  t417[533ULL] = X[106ULL];
  t417[534ULL] = X[107ULL] * 0.1;
  t417[535ULL] = -X[109ULL];
  t417[536ULL] = X[130ULL];
  t417[537ULL] = -X[110ULL];
  t417[538ULL] = X[129ULL];
  t417[539ULL] = X[110ULL];
  t417[540ULL] = Subsystem_Reference_TCP_6812_convection_A_rho;
  t417[541ULL] = Subsystem_Reference_TCP_6812_q_A;
  t417[542ULL] = Subsystem_Reference_Ideal_Angular_Velocity_Source_R_w;
  t417[543ULL] = Subsystem_Reference_TCP_6812_p_diff * 1.0000000000000002E-6;
  t417[544ULL] = t502 * 0.001;
  t417[545ULL] = -X[108ULL];
  t417[546ULL] = Subsystem_Reference_TCP_6812_mechanical_power * 0.001;
  t417[547ULL] = Subsystem_Reference_TCP_6812_eta;
  t417[548ULL] = -X[110ULL];
  t417[549ULL] = X[126ULL];
  t417[550ULL] = X[127ULL] * 0.1;
  t417[551ULL] = X[39ULL];
  t417[552ULL] = X[40ULL] * 0.1;
  t417[553ULL] = U_idx_7 * 0.001;
  t417[554ULL] = X[119ULL];
  t417[555ULL] = X[120ULL] * 0.1;
  t417[556ULL] = X[126ULL];
  t417[557ULL] = X[127ULL] * 0.1;
  t417[558ULL] = X[119ULL];
  t417[559ULL] = X[120ULL] * 0.1;
  t417[560ULL] = X[121ULL];
  t417[561ULL] = -X[121ULL];
  t417[562ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_S;
  t417[563ULL] = X[126ULL];
  t417[564ULL] = X[127ULL] * 0.1;
  t417[565ULL] = X[121ULL];
  t417[566ULL] = X[131ULL];
  t417[567ULL] = t511;
  t417[568ULL] = X[132ULL];
  t417[569ULL] = X[119ULL];
  t417[570ULL] = X[120ULL] * 0.1;
  t417[571ULL] = -X[121ULL];
  t417[572ULL] = X[133ULL];
  t417[573ULL] = -t511;
  t417[574ULL] = X[132ULL];
  t417[575ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_orifice_area;
  t417[576ULL] = t511;
  t417[577ULL] = -t511;
  t417[578ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho;
  t417[579ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_convection_B_rho;
  t417[580ULL] = t511 /
    (Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho == 0.0 ? 1.0E-16
     : Subsystem_Reference_TCV_VL6810_orifice_AT_convection_A_rho);
  t417[581ULL] = Subsystem_Reference_TCV_VL6810_orifice_AT_q_B;
  t417[582ULL] = X[39ULL];
  t417[583ULL] = X[40ULL] * 0.1;
  t417[584ULL] = X[126ULL];
  t417[585ULL] = X[127ULL] * 0.1;
  t417[586ULL] = -X[27ULL];
  t417[587ULL] = X[27ULL];
  t417[588ULL] = t525;
  t417[589ULL] = X[39ULL];
  t417[590ULL] = X[40ULL] * 0.1;
  t417[591ULL] = -X[27ULL];
  t417[592ULL] = X[134ULL];
  t417[593ULL] = -X[8ULL];
  t417[594ULL] = X[135ULL];
  t417[595ULL] = X[126ULL];
  t417[596ULL] = X[127ULL] * 0.1;
  t417[597ULL] = X[27ULL];
  t417[598ULL] = X[136ULL];
  t417[599ULL] = X[8ULL];
  t417[600ULL] = X[135ULL];
  t417[601ULL] = Subsystem_Reference_TCV_VL6810_orifice_PA_orifice_area;
  t417[602ULL] = -X[8ULL];
  t417[603ULL] = X[8ULL];
  t417[604ULL] = Subsystem_Reference_TCV_VL6810_orifice_PA_convection_A_rho;
  t417[605ULL] = Subsystem_Reference_TCV_VL6810_orifice_PA_convection_B_rho;
  t417[606ULL] = -X[8ULL] /
    (Subsystem_Reference_TCV_VL6810_orifice_PA_convection_A_rho == 0.0 ? 1.0E-16
     : Subsystem_Reference_TCV_VL6810_orifice_PA_convection_A_rho);
  t417[607ULL] = t504;
  t417[608ULL] = X[96ULL];
  t417[609ULL] = X[97ULL] * 0.1;
  t417[610ULL] = X[37ULL];
  t417[611ULL] = X[38ULL] * 0.1;
  t417[612ULL] = X[111ULL];
  t417[613ULL] = X[112ULL] * 0.1;
  t417[614ULL] = X[101ULL];
  t417[615ULL] = X[7ULL];
  t417[616ULL] = X[16ULL];
  t417[617ULL] = X[96ULL];
  t417[618ULL] = X[97ULL] * 0.1;
  t417[619ULL] = -X[55ULL];
  t417[620ULL] = X[137ULL];
  t417[621ULL] = X[101ULL];
  t417[622ULL] = X[140ULL];
  t417[623ULL] = X[37ULL];
  t417[624ULL] = X[38ULL] * 0.1;
  t417[625ULL] = -t476;
  t417[626ULL] = X[138ULL];
  t417[627ULL] = X[7ULL];
  t417[628ULL] = X[140ULL];
  t417[629ULL] = X[111ULL];
  t417[630ULL] = X[112ULL] * 0.1;
  t417[631ULL] = -X[56ULL];
  t417[632ULL] = X[139ULL];
  t417[633ULL] = X[16ULL];
  t417[634ULL] = X[140ULL];
  t417[635ULL] = -X[55ULL];
  t417[636ULL] = -t476;
  t417[637ULL] = -X[56ULL];
  t417[638ULL] = X[141ULL] * 0.1;
  t417[639ULL] = X[142ULL] * 0.1;
  t417[640ULL] = X[143ULL] * 0.1;
  t417[641ULL] = D_idx_2;
  t417[642ULL] = X[147ULL] * 0.1;
  t417[643ULL] = t487;
  t417[644ULL] = X[101ULL] / (t487 == 0.0 ? 1.0E-16 : t487);
  t417[645ULL] = t465_idx_0;
  t417[646ULL] = X[7ULL] / (t465_idx_0 == 0.0 ? 1.0E-16 : t465_idx_0);
  t417[647ULL] = Subsystem_Reference_T_Junction_TL_convection_C_rho;
  t417[648ULL] = X[16ULL] / (Subsystem_Reference_T_Junction_TL_convection_C_rho ==
    0.0 ? 1.0E-16 : Subsystem_Reference_T_Junction_TL_convection_C_rho);
  t417[649ULL] = (real_T)(size_t)Q_idx_2;
  t417[650ULL] = X[69ULL];
  t417[651ULL] = X[71ULL];
  t417[652ULL] = X[80ULL];
  t417[653ULL] = X[144ULL];
  t417[654ULL] = X[70ULL];
  t417[655ULL] = X[81ULL];
  t417[656ULL] = X[82ULL];
  t417[657ULL] = X[145ULL];
  t417[658ULL] = X[146ULL];
  for (b = 0; b < 659; b++) {
    out.mX[b] = t417[b];
  }

  (void)LC;
  (void)t592;
  return 0;
}
