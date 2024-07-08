/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_lock_r.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_lock_r(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t130, NeDsMethodOutput *t131)
{
  ETTS0 ab_efOut;
  ETTS0 b_efOut;
  ETTS0 d_efOut;
  ETTS0 e_efOut;
  ETTS0 efOut;
  ETTS0 g_efOut;
  ETTS0 h_efOut;
  ETTS0 j_efOut;
  ETTS0 k_efOut;
  ETTS0 m_efOut;
  ETTS0 n_efOut;
  ETTS0 p_efOut;
  ETTS0 q_efOut;
  ETTS0 s_efOut;
  ETTS0 t11;
  ETTS0 t13;
  ETTS0 t16;
  ETTS0 t17;
  ETTS0 t_efOut;
  ETTS0 v_efOut;
  ETTS0 w_efOut;
  ETTS0 y_efOut;
  PmBoolVector out;
  real_T X[148];
  real_T bb_efOut[1];
  real_T c_efOut[1];
  real_T f_efOut[1];
  real_T i_efOut[1];
  real_T l_efOut[1];
  real_T o_efOut[1];
  real_T r_efOut[1];
  real_T t111[1];
  real_T u_efOut[1];
  real_T x_efOut[1];
  real_T Basic_Peripherals_T_Junction_TL1_mu_avg;
  real_T Subsystem_Reference_T_Junction_TL_mu_B;
  real_T t124_idx_0;
  size_t t37[1];
  size_t t38[1];
  size_t t40[1];
  int32_T CI[108];
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  int32_T Q_idx_2;
  int32_T Q_idx_3;
  int32_T b;
  boolean_T indicator1;
  boolean_T t18;
  boolean_T t19;
  boolean_T t20;
  boolean_T t21;
  boolean_T t22;
  boolean_T t23;
  boolean_T t24;
  boolean_T t25;
  boolean_T t26;
  boolean_T t27;
  boolean_T t28;
  boolean_T t29;
  boolean_T t30;
  boolean_T t31;
  boolean_T t32;
  boolean_T t33;
  boolean_T t34;
  boolean_T t35;
  Q_idx_0 = t130->mQ.mX[0];
  Q_idx_1 = t130->mQ.mX[1];
  Q_idx_2 = t130->mQ.mX[2];
  Q_idx_3 = t130->mQ.mX[3];
  for (b = 0; b < 148; b++) {
    X[b] = t130->mX.mX[b];
  }

  for (b = 0; b < 108; b++) {
    CI[b] = t130->mCI.mX[b];
  }

  out = t131->mLOCK_R;
  t111[0ULL] = X[62ULL];
  t37[0] = 20ULL;
  t38[0] = 1ULL;
  tlu2_linear_nearest_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL], &t37
    [0ULL], &t38[0ULL]);
  t16 = efOut;
  t111[0ULL] = X[54ULL];
  t40[0] = 19ULL;
  tlu2_linear_nearest_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = b_efOut;
  tlu2_2d_linear_nearest_value(&c_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = c_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg = t124_idx_0;
  t111[0ULL] = X[63ULL];
  tlu2_linear_nearest_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = d_efOut;
  t111[0ULL] = X[50ULL];
  tlu2_linear_nearest_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = e_efOut;
  tlu2_2d_linear_nearest_value(&f_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = f_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t124_idx_0;
  t111[0ULL] = X[64ULL];
  tlu2_linear_nearest_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = g_efOut;
  t111[0ULL] = X[44ULL];
  tlu2_linear_nearest_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = h_efOut;
  tlu2_2d_linear_nearest_value(&i_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = i_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B =
    ((Basic_Peripherals_T_Junction_TL1_mu_avg * 0.0019634954084936209 +
      Subsystem_Reference_T_Junction_TL_mu_B * 0.0019634954084936209) +
     t124_idx_0 * 0.0019634954084936209) / 0.0058904862254808626 *
    5.8904862254808616;
  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t18 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t18 = false;
  }

  if (t18) {
    indicator1 = (X[46ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    indicator1 = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t19 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t19 = false;
  }

  if (t19) {
    t18 = (X[46ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t18 = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t20 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t20 = false;
  }

  if (t20) {
    t19 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t19 = false;
  }

  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t21 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t21 = false;
  }

  if (t21) {
    t20 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t20 = false;
  }

  if (X[57ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t22 = (X[4ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t22 = false;
  }

  if (t22) {
    t21 = (X[46ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t21 = false;
  }

  if (X[57ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t23 = (X[4ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t23 = false;
  }

  if (t23) {
    t22 = (X[46ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t22 = false;
  }

  t111[0ULL] = X[73ULL];
  tlu2_linear_nearest_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t17 = j_efOut;
  t111[0ULL] = X[23ULL];
  tlu2_linear_nearest_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t11 = k_efOut;
  tlu2_2d_linear_nearest_value(&l_efOut[0ULL], &t17.mField0[0ULL], &t17.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = l_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg = t124_idx_0;
  t111[0ULL] = X[74ULL];
  tlu2_linear_nearest_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = m_efOut;
  t111[0ULL] = X[40ULL];
  tlu2_linear_nearest_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t13 = n_efOut;
  tlu2_2d_linear_nearest_value(&o_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t13.mField0[0ULL], &t13.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = o_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t124_idx_0;
  t111[0ULL] = X[75ULL];
  tlu2_linear_nearest_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = p_efOut;
  t111[0ULL] = X[42ULL];
  tlu2_linear_nearest_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = q_efOut;
  tlu2_2d_linear_nearest_value(&r_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = r_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B =
    ((Basic_Peripherals_T_Junction_TL1_mu_avg * 0.0019634954084936209 +
      Subsystem_Reference_T_Junction_TL_mu_B * 0.0019634954084936209) +
     t124_idx_0 * 0.0019634954084936209) / 0.0058904862254808626 *
    5.8904862254808616;
  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t24 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t24 = false;
  }

  if (t24) {
    t23 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t23 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t25 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t25 = false;
  }

  if (t25) {
    t24 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t24 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t26 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t26 = false;
  }

  if (t26) {
    t25 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t25 = false;
  }

  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t27 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t27 = false;
  }

  if (t27) {
    t26 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t26 = false;
  }

  if (X[29ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t28 = (X[8ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t28 = false;
  }

  if (t28) {
    t27 = (X[9ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t27 = false;
  }

  if (X[29ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t29 = (X[8ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t29 = false;
  }

  if (t29) {
    t28 = (X[9ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t28 = false;
  }

  t111[0ULL] = X[137ULL];
  tlu2_linear_nearest_prelookup(&s_efOut.mField0[0ULL], &s_efOut.mField1[0ULL],
    &s_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t13 = s_efOut;
  t111[0ULL] = X[97ULL];
  tlu2_linear_nearest_prelookup(&t_efOut.mField0[0ULL], &t_efOut.mField1[0ULL],
    &t_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t11 = t_efOut;
  tlu2_2d_linear_nearest_value(&u_efOut[0ULL], &t13.mField0[0ULL], &t13.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = u_efOut[0];
  Basic_Peripherals_T_Junction_TL1_mu_avg = t124_idx_0;
  t111[0ULL] = X[138ULL];
  tlu2_linear_nearest_prelookup(&v_efOut.mField0[0ULL], &v_efOut.mField1[0ULL],
    &v_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = v_efOut;
  t111[0ULL] = X[38ULL];
  tlu2_linear_nearest_prelookup(&w_efOut.mField0[0ULL], &w_efOut.mField1[0ULL],
    &w_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = w_efOut;
  tlu2_2d_linear_nearest_value(&x_efOut[0ULL], &t16.mField0[0ULL], &t16.mField2
    [0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t124_idx_0 = x_efOut[0];
  t111[0ULL] = X[139ULL];
  tlu2_linear_nearest_prelookup(&y_efOut.mField0[0ULL], &y_efOut.mField1[0ULL],
    &y_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t111[0ULL],
    &t37[0ULL], &t38[0ULL]);
  t16 = y_efOut;
  t111[0ULL] = X[112ULL];
  tlu2_linear_nearest_prelookup(&ab_efOut.mField0[0ULL], &ab_efOut.mField1[0ULL],
    &ab_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t111[0ULL],
    &t40[0ULL], &t38[0ULL]);
  t17 = ab_efOut;
  tlu2_2d_linear_nearest_value(&bb_efOut[0ULL], &t16.mField0[0ULL],
    &t16.mField2[0ULL], &t17.mField0[0ULL], &t17.mField2[0ULL],
    ((_NeDynamicSystem*)(LC))->mField5, &t37[0ULL], &t40[0ULL], &t38[0ULL]);
  t111[0] = bb_efOut[0];
  Subsystem_Reference_T_Junction_TL_mu_B = t111[0ULL];
  Subsystem_Reference_T_Junction_TL_mu_B =
    ((Basic_Peripherals_T_Junction_TL1_mu_avg * 0.0019634954084936209 +
      t124_idx_0 * 0.0019634954084936209) +
     Subsystem_Reference_T_Junction_TL_mu_B * 0.0019634954084936209) /
    0.0058904862254808626 * 5.8904862254808616;
  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t30 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t30 = false;
  }

  if (t30) {
    t29 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t29 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t31 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t31 = false;
  }

  if (t31) {
    t30 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t30 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t32 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t32 = false;
  }

  if (t32) {
    t31 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t31 = false;
  }

  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t33 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t33 = false;
  }

  if (t33) {
    t32 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t32 = false;
  }

  if (X[101ULL] < -Subsystem_Reference_T_Junction_TL_mu_B) {
    t34 = (X[7ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t34 = false;
  }

  if (t34) {
    t33 = (X[16ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t33 = false;
  }

  if (X[101ULL] > Subsystem_Reference_T_Junction_TL_mu_B) {
    t35 = (X[7ULL] > Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t35 = false;
  }

  if (t35) {
    t34 = (X[16ULL] < -Subsystem_Reference_T_Junction_TL_mu_B);
  } else {
    t34 = false;
  }

  if (((CI[37ULL] == 0) && ((size_t)Q_idx_0 == 2ULL) && t20) || (((size_t)
        Q_idx_0 == 2ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[36ULL] == 0) && ((size_t)Q_idx_0 == 2ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 2ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[35ULL] == 0) && ((size_t)Q_idx_0 == 2ULL) && t18) || (((size_t)
               Q_idx_0 == 2ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[34ULL] == 0) && ((size_t)Q_idx_0 == 2ULL) && t22) || (((size_t)
               Q_idx_0 == 2ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[33ULL] == 0) && ((size_t)Q_idx_0 == 2ULL) && t21) || (((size_t)
               Q_idx_0 == 2ULL) && t21 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[32ULL] == 0) && ((size_t)Q_idx_0 == 3ULL) && t19) || (((size_t)
               Q_idx_0 == 3ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[30ULL] == 0) && ((size_t)Q_idx_0 == 3ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 3ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[29ULL] == 0) && ((size_t)Q_idx_0 == 3ULL) && t18) || (((size_t)
               Q_idx_0 == 3ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[28ULL] == 0) && ((size_t)Q_idx_0 == 3ULL) && t22) || (((size_t)
               Q_idx_0 == 3ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[27ULL] == 0) && ((size_t)Q_idx_0 == 3ULL) && t21) || (((size_t)
               Q_idx_0 == 3ULL) && t21 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[26ULL] == 0) && ((size_t)Q_idx_0 == 4ULL) && t19) || (((size_t)
               Q_idx_0 == 4ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[25ULL] == 0) && ((size_t)Q_idx_0 == 4ULL) && t20) || (((size_t)
               Q_idx_0 == 4ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[24ULL] == 0) && ((size_t)Q_idx_0 == 4ULL) && t18) || (((size_t)
               Q_idx_0 == 4ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[23ULL] == 0) && ((size_t)Q_idx_0 == 4ULL) && t22) || (((size_t)
               Q_idx_0 == 4ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[22ULL] == 0) && ((size_t)Q_idx_0 == 4ULL) && t21) || (((size_t)
               Q_idx_0 == 4ULL) && t21 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[21ULL] == 0) && ((size_t)Q_idx_0 == 5ULL) && t19) || (((size_t)
               Q_idx_0 == 5ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[19ULL] == 0) && ((size_t)Q_idx_0 == 5ULL) && t20) || (((size_t)
               Q_idx_0 == 5ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[18ULL] == 0) && ((size_t)Q_idx_0 == 5ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 5ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[17ULL] == 0) && ((size_t)Q_idx_0 == 5ULL) && t22) || (((size_t)
               Q_idx_0 == 5ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[16ULL] == 0) && ((size_t)Q_idx_0 == 5ULL) && t21) || (((size_t)
               Q_idx_0 == 5ULL) && t21 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[15ULL] == 0) && ((size_t)Q_idx_0 == 6ULL) && t19) || (((size_t)
               Q_idx_0 == 6ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[14ULL] == 0) && ((size_t)Q_idx_0 == 6ULL) && t20) || (((size_t)
               Q_idx_0 == 6ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[13ULL] == 0) && ((size_t)Q_idx_0 == 6ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 6ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[12ULL] == 0) && ((size_t)Q_idx_0 == 6ULL) && t18) || (((size_t)
               Q_idx_0 == 6ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[11ULL] == 0) && ((size_t)Q_idx_0 == 6ULL) && t21) || (((size_t)
               Q_idx_0 == 6ULL) && t21 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[2ULL] == 0) && ((size_t)Q_idx_0 == 7ULL) && t19) || (((size_t)
               Q_idx_0 == 7ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[97ULL] == 0) && ((size_t)Q_idx_0 == 7ULL) && t20) || (((size_t)
               Q_idx_0 == 7ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[86ULL] == 0) && ((size_t)Q_idx_0 == 7ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 7ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[75ULL] == 0) && ((size_t)Q_idx_0 == 7ULL) && t18) || (((size_t)
               Q_idx_0 == 7ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[64ULL] == 0) && ((size_t)Q_idx_0 == 7ULL) && t22) || (((size_t)
               Q_idx_0 == 7ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[53ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && t19) || (((size_t)
               Q_idx_0 == 1ULL) && t19 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[42ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && t20) || (((size_t)
               Q_idx_0 == 1ULL) && t20 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[31ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && indicator1) ||
             (((size_t)Q_idx_0 == 1ULL) && indicator1 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[20ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && t18) || (((size_t)
               Q_idx_0 == 1ULL) && t18 && (Q_idx_3 != 0))) {
    t35 = true;
  } else if (((CI[1ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && t22) || (((size_t)
               Q_idx_0 == 1ULL) && t22 && (Q_idx_3 != 0))) {
    t35 = true;
  } else {
    t35 = (((CI[0ULL] == 0) && ((size_t)Q_idx_0 == 1ULL) && t21) || (((size_t)
             Q_idx_0 == 1ULL) && t21 && (Q_idx_3 != 0)));
  }

  if (((CI[77ULL] == 0) && ((size_t)Q_idx_1 == 2ULL) && t26) || (((size_t)
        Q_idx_1 == 2ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[76ULL] == 0) && ((size_t)Q_idx_1 == 2ULL) && t23) || (((size_t)
               Q_idx_1 == 2ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[74ULL] == 0) && ((size_t)Q_idx_1 == 2ULL) && t24) || (((size_t)
               Q_idx_1 == 2ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[73ULL] == 0) && ((size_t)Q_idx_1 == 2ULL) && t28) || (((size_t)
               Q_idx_1 == 2ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[72ULL] == 0) && ((size_t)Q_idx_1 == 2ULL) && t27) || (((size_t)
               Q_idx_1 == 2ULL) && t27 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[71ULL] == 0) && ((size_t)Q_idx_1 == 3ULL) && t25) || (((size_t)
               Q_idx_1 == 3ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[70ULL] == 0) && ((size_t)Q_idx_1 == 3ULL) && t23) || (((size_t)
               Q_idx_1 == 3ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[69ULL] == 0) && ((size_t)Q_idx_1 == 3ULL) && t24) || (((size_t)
               Q_idx_1 == 3ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[68ULL] == 0) && ((size_t)Q_idx_1 == 3ULL) && t28) || (((size_t)
               Q_idx_1 == 3ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[67ULL] == 0) && ((size_t)Q_idx_1 == 3ULL) && t27) || (((size_t)
               Q_idx_1 == 3ULL) && t27 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[66ULL] == 0) && ((size_t)Q_idx_1 == 4ULL) && t25) || (((size_t)
               Q_idx_1 == 4ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[65ULL] == 0) && ((size_t)Q_idx_1 == 4ULL) && t26) || (((size_t)
               Q_idx_1 == 4ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[63ULL] == 0) && ((size_t)Q_idx_1 == 4ULL) && t24) || (((size_t)
               Q_idx_1 == 4ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[62ULL] == 0) && ((size_t)Q_idx_1 == 4ULL) && t28) || (((size_t)
               Q_idx_1 == 4ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[61ULL] == 0) && ((size_t)Q_idx_1 == 4ULL) && t27) || (((size_t)
               Q_idx_1 == 4ULL) && t27 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[60ULL] == 0) && ((size_t)Q_idx_1 == 5ULL) && t25) || (((size_t)
               Q_idx_1 == 5ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[59ULL] == 0) && ((size_t)Q_idx_1 == 5ULL) && t26) || (((size_t)
               Q_idx_1 == 5ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[58ULL] == 0) && ((size_t)Q_idx_1 == 5ULL) && t23) || (((size_t)
               Q_idx_1 == 5ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[57ULL] == 0) && ((size_t)Q_idx_1 == 5ULL) && t28) || (((size_t)
               Q_idx_1 == 5ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[56ULL] == 0) && ((size_t)Q_idx_1 == 5ULL) && t27) || (((size_t)
               Q_idx_1 == 5ULL) && t27 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[55ULL] == 0) && ((size_t)Q_idx_1 == 6ULL) && t25) || (((size_t)
               Q_idx_1 == 6ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[54ULL] == 0) && ((size_t)Q_idx_1 == 6ULL) && t26) || (((size_t)
               Q_idx_1 == 6ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[52ULL] == 0) && ((size_t)Q_idx_1 == 6ULL) && t23) || (((size_t)
               Q_idx_1 == 6ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[51ULL] == 0) && ((size_t)Q_idx_1 == 6ULL) && t24) || (((size_t)
               Q_idx_1 == 6ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[50ULL] == 0) && ((size_t)Q_idx_1 == 6ULL) && t27) || (((size_t)
               Q_idx_1 == 6ULL) && t27 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[49ULL] == 0) && ((size_t)Q_idx_1 == 7ULL) && t25) || (((size_t)
               Q_idx_1 == 7ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[48ULL] == 0) && ((size_t)Q_idx_1 == 7ULL) && t26) || (((size_t)
               Q_idx_1 == 7ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[47ULL] == 0) && ((size_t)Q_idx_1 == 7ULL) && t23) || (((size_t)
               Q_idx_1 == 7ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[46ULL] == 0) && ((size_t)Q_idx_1 == 7ULL) && t24) || (((size_t)
               Q_idx_1 == 7ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[45ULL] == 0) && ((size_t)Q_idx_1 == 7ULL) && t28) || (((size_t)
               Q_idx_1 == 7ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[44ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t25) || (((size_t)
               Q_idx_1 == 1ULL) && t25 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[43ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t26) || (((size_t)
               Q_idx_1 == 1ULL) && t26 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[41ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t23) || (((size_t)
               Q_idx_1 == 1ULL) && t23 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[40ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t24) || (((size_t)
               Q_idx_1 == 1ULL) && t24 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else if (((CI[39ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t28) || (((size_t)
               Q_idx_1 == 1ULL) && t28 && (Q_idx_3 != 0))) {
    indicator1 = true;
  } else {
    indicator1 = (((CI[38ULL] == 0) && ((size_t)Q_idx_1 == 1ULL) && t27) ||
                  (((size_t)Q_idx_1 == 1ULL) && t27 && (Q_idx_3 != 0)));
  }

  if (((CI[10ULL] == 0) && ((size_t)Q_idx_2 == 2ULL) && t32) || (((size_t)
        Q_idx_2 == 2ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[9ULL] == 0) && ((size_t)Q_idx_2 == 2ULL) && t29) || (((size_t)
               Q_idx_2 == 2ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[8ULL] == 0) && ((size_t)Q_idx_2 == 2ULL) && t30) || (((size_t)
               Q_idx_2 == 2ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[7ULL] == 0) && ((size_t)Q_idx_2 == 2ULL) && t34) || (((size_t)
               Q_idx_2 == 2ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[6ULL] == 0) && ((size_t)Q_idx_2 == 2ULL) && t33) || (((size_t)
               Q_idx_2 == 2ULL) && t33 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[5ULL] == 0) && ((size_t)Q_idx_2 == 3ULL) && t31) || (((size_t)
               Q_idx_2 == 3ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[4ULL] == 0) && ((size_t)Q_idx_2 == 3ULL) && t29) || (((size_t)
               Q_idx_2 == 3ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[3ULL] == 0) && ((size_t)Q_idx_2 == 3ULL) && t30) || (((size_t)
               Q_idx_2 == 3ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[107ULL] == 0) && ((size_t)Q_idx_2 == 3ULL) && t34) ||
             (((size_t)Q_idx_2 == 3ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[106ULL] == 0) && ((size_t)Q_idx_2 == 3ULL) && t33) ||
             (((size_t)Q_idx_2 == 3ULL) && t33 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[105ULL] == 0) && ((size_t)Q_idx_2 == 4ULL) && t31) ||
             (((size_t)Q_idx_2 == 4ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[104ULL] == 0) && ((size_t)Q_idx_2 == 4ULL) && t32) ||
             (((size_t)Q_idx_2 == 4ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[103ULL] == 0) && ((size_t)Q_idx_2 == 4ULL) && t30) ||
             (((size_t)Q_idx_2 == 4ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[102ULL] == 0) && ((size_t)Q_idx_2 == 4ULL) && t34) ||
             (((size_t)Q_idx_2 == 4ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[101ULL] == 0) && ((size_t)Q_idx_2 == 4ULL) && t33) ||
             (((size_t)Q_idx_2 == 4ULL) && t33 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[100ULL] == 0) && ((size_t)Q_idx_2 == 5ULL) && t31) ||
             (((size_t)Q_idx_2 == 5ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[99ULL] == 0) && ((size_t)Q_idx_2 == 5ULL) && t32) || (((size_t)
               Q_idx_2 == 5ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[98ULL] == 0) && ((size_t)Q_idx_2 == 5ULL) && t29) || (((size_t)
               Q_idx_2 == 5ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[96ULL] == 0) && ((size_t)Q_idx_2 == 5ULL) && t34) || (((size_t)
               Q_idx_2 == 5ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[95ULL] == 0) && ((size_t)Q_idx_2 == 5ULL) && t33) || (((size_t)
               Q_idx_2 == 5ULL) && t33 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[94ULL] == 0) && ((size_t)Q_idx_2 == 6ULL) && t31) || (((size_t)
               Q_idx_2 == 6ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[93ULL] == 0) && ((size_t)Q_idx_2 == 6ULL) && t32) || (((size_t)
               Q_idx_2 == 6ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[92ULL] == 0) && ((size_t)Q_idx_2 == 6ULL) && t29) || (((size_t)
               Q_idx_2 == 6ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[91ULL] == 0) && ((size_t)Q_idx_2 == 6ULL) && t30) || (((size_t)
               Q_idx_2 == 6ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[90ULL] == 0) && ((size_t)Q_idx_2 == 6ULL) && t33) || (((size_t)
               Q_idx_2 == 6ULL) && t33 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[89ULL] == 0) && ((size_t)Q_idx_2 == 7ULL) && t31) || (((size_t)
               Q_idx_2 == 7ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[88ULL] == 0) && ((size_t)Q_idx_2 == 7ULL) && t32) || (((size_t)
               Q_idx_2 == 7ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[87ULL] == 0) && ((size_t)Q_idx_2 == 7ULL) && t29) || (((size_t)
               Q_idx_2 == 7ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[85ULL] == 0) && ((size_t)Q_idx_2 == 7ULL) && t30) || (((size_t)
               Q_idx_2 == 7ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[84ULL] == 0) && ((size_t)Q_idx_2 == 7ULL) && t34) || (((size_t)
               Q_idx_2 == 7ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[83ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t31) || (((size_t)
               Q_idx_2 == 1ULL) && t31 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[82ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t32) || (((size_t)
               Q_idx_2 == 1ULL) && t32 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[81ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t29) || (((size_t)
               Q_idx_2 == 1ULL) && t29 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[80ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t30) || (((size_t)
               Q_idx_2 == 1ULL) && t30 && (Q_idx_3 != 0))) {
    t18 = true;
  } else if (((CI[79ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t34) || (((size_t)
               Q_idx_2 == 1ULL) && t34 && (Q_idx_3 != 0))) {
    t18 = true;
  } else {
    t18 = (((CI[78ULL] == 0) && ((size_t)Q_idx_2 == 1ULL) && t33) || (((size_t)
             Q_idx_2 == 1ULL) && t33 && (Q_idx_3 != 0)));
  }

  out.mX[0] = t35;
  out.mX[1] = indicator1;
  out.mX[2] = t18;
  (void)LC;
  (void)t131;
  return 0;
}
