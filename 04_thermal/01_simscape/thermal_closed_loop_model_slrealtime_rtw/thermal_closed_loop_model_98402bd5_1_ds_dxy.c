/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_dxy.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_dxy(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t190, NeDsMethodOutput *t191)
{
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
  PmRealVector out;
  real_T X[148];
  real_T ab_efOut[1];
  real_T bb_efOut[1];
  real_T c_efOut[1];
  real_T cb_efOut[1];
  real_T db_efOut[1];
  real_T eb_efOut[1];
  real_T f_efOut[1];
  real_T i_efOut[1];
  real_T l_efOut[1];
  real_T o_efOut[1];
  real_T r_efOut[1];
  real_T s_efOut[1];
  real_T t119[1];
  real_T t_efOut[1];
  real_T u_efOut[1];
  real_T v_efOut[1];
  real_T w_efOut[1];
  real_T x_efOut[1];
  real_T y_efOut[1];
  real_T U_idx_0;
  real_T intermediate_der143;
  real_T intermediate_der144;
  real_T intermediate_der145;
  real_T intermediate_der146;
  real_T intermediate_der149;
  real_T intermediate_der155;
  real_T intermediate_der530;
  real_T intermediate_der540;
  real_T t107_idx_0;
  real_T t140;
  real_T t143;
  real_T t150;
  real_T t151;
  real_T t152;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t162;
  real_T t163;
  real_T t187;
  real_T t188;
  size_t t13[1];
  size_t t14[1];
  size_t t16[1];
  int32_T b;
  U_idx_0 = t190->mU.mX[0];
  for (b = 0; b < 148; b++) {
    X[b] = t190->mX.mX[b];
  }

  out = t191->mDXY;
  t119[0ULL] = X[49ULL];
  t13[0] = 20ULL;
  t14[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL], &t13
    [0ULL], &t14[0ULL]);
  t10 = efOut;
  t119[0ULL] = X[50ULL];
  t16[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t9 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t9.mField0[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t107_idx_0 = c_efOut[0];
  intermediate_der144 = t107_idx_0;
  t119[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t8 = d_efOut;
  t119[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t5 = e_efOut;
  tlu2_2d_linear_linear_value(&f_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t5.mField0[0ULL], &t5.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t107_idx_0 = f_efOut[0];
  intermediate_der149 = t107_idx_0;
  t119[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t4 = g_efOut;
  t119[0ULL] = X[0ULL] * -0.8 + 1.1132499999999999;
  tlu2_linear_linear_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t3 = h_efOut;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t107_idx_0 = i_efOut[0];
  t140 = t107_idx_0;
  t119[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t2 = j_efOut;
  t119[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t6 = k_efOut;
  tlu2_2d_linear_linear_value(&l_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t107_idx_0 = l_efOut[0];
  intermediate_der530 = t107_idx_0;
  t119[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t7 = m_efOut;
  t119[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t11 = n_efOut;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t7.mField0[0ULL], &t7.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t107_idx_0 = o_efOut[0];
  t119[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t119[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t1 = p_efOut;
  t119[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t119[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t0 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t1.mField0[0ULL], &t1.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = r_efOut[0];
  intermediate_der540 = t119[0ULL];
  tlu2_2d_linear_linear_value(&s_efOut[0ULL], &t10.mField1[0ULL], &t10.mField2
    [0ULL], &t9.mField0[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = s_efOut[0];
  intermediate_der145 = t119[0ULL];
  tlu2_2d_linear_linear_value(&t_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t9.mField1[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = t_efOut[0];
  intermediate_der146 = t119[0ULL];
  intermediate_der143 = -1.0 / (intermediate_der144 == 0.0 ? 1.0E-16 :
    intermediate_der144) * 1.0E+6;
  t151 = intermediate_der144 * intermediate_der144;
  intermediate_der144 = X[4ULL] / (t151 == 0.0 ? 1.0E-16 : t151) *
    intermediate_der145 * 1.0E+6;
  intermediate_der145 = X[4ULL] / (t151 == 0.0 ? 1.0E-16 : t151) *
    intermediate_der146 * 1.0E+6;
  tlu2_2d_linear_linear_value(&u_efOut[0ULL], &t8.mField1[0ULL], &t8.mField2
    [0ULL], &t5.mField0[0ULL], &t5.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = u_efOut[0];
  intermediate_der146 = t119[0ULL];
  tlu2_2d_linear_linear_value(&v_efOut[0ULL], &t8.mField0[0ULL], &t8.mField2
    [0ULL], &t5.mField1[0ULL], &t5.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = v_efOut[0];
  intermediate_der155 = t119[0ULL];
  t150 = 1.0 / (intermediate_der149 == 0.0 ? 1.0E-16 : intermediate_der149) *
    1.0E+6;
  t158 = intermediate_der149 * intermediate_der149;
  intermediate_der149 = -X[46ULL] / (t158 == 0.0 ? 1.0E-16 : t158) *
    intermediate_der146 * 1.0E+6;
  intermediate_der146 = -X[46ULL] / (t158 == 0.0 ? 1.0E-16 : t158) *
    intermediate_der155 * 1.0E+6;
  tlu2_2d_linear_linear_value(&w_efOut[0ULL], &t4.mField1[0ULL], &t4.mField2
    [0ULL], &t3.mField0[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = w_efOut[0];
  intermediate_der155 = t119[0ULL];
  tlu2_2d_linear_linear_value(&x_efOut[0ULL], &t4.mField0[0ULL], &t4.mField2
    [0ULL], &t3.mField1[0ULL], &t3.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = x_efOut[0];
  t151 = t119[0ULL] * -0.8;
  t152 = 1.0 / (t140 == 0.0 ? 1.0E-16 : t140) * 1.0E+6;
  t187 = t140 * t140;
  t140 = -X[29ULL] / (t187 == 0.0 ? 1.0E-16 : t187) * intermediate_der155 *
    1.0E+6;
  tlu2_2d_linear_linear_value(&y_efOut[0ULL], &t2.mField1[0ULL], &t2.mField2
    [0ULL], &t6.mField0[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = y_efOut[0];
  intermediate_der155 = t119[0ULL];
  tlu2_2d_linear_linear_value(&ab_efOut[0ULL], &t2.mField0[0ULL], &t2.mField2
    [0ULL], &t6.mField1[0ULL], &t6.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = ab_efOut[0];
  t156 = t119[0ULL];
  t157 = 1.0 / (intermediate_der530 == 0.0 ? 1.0E-16 : intermediate_der530) *
    1.0E+6;
  t188 = intermediate_der530 * intermediate_der530;
  intermediate_der530 = -X[110ULL] / (t188 == 0.0 ? 1.0E-16 : t188) *
    intermediate_der155 * 1.0E+6;
  intermediate_der155 = -X[110ULL] / (t188 == 0.0 ? 1.0E-16 : t188) * t156 *
    1.0E+6;
  tlu2_2d_linear_linear_value(&bb_efOut[0ULL], &t7.mField1[0ULL], &t7.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = bb_efOut[0];
  t156 = t119[0ULL];
  tlu2_2d_linear_linear_value(&cb_efOut[0ULL], &t7.mField0[0ULL], &t7.mField2
    [0ULL], &t11.mField1[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = cb_efOut[0];
  t158 = t119[0ULL];
  t188 = t107_idx_0 * t107_idx_0;
  t143 = X[8ULL] / (t188 == 0.0 ? 1.0E-16 : t188) * t156 * 1.0E+6;
  t156 = X[8ULL] / (t188 == 0.0 ? 1.0E-16 : t188) * t158 * 1.0E+6;
  tlu2_2d_linear_linear_value(&db_efOut[0ULL], &t1.mField1[0ULL], &t1.mField2
    [0ULL], &t0.mField0[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = db_efOut[0];
  t158 = t119[0ULL];
  tlu2_2d_linear_linear_value(&eb_efOut[0ULL], &t1.mField0[0ULL], &t1.mField2
    [0ULL], &t0.mField1[0ULL], &t0.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t119[0] = eb_efOut[0];
  t162 = t119[0ULL];
  t163 = -1.0 / (intermediate_der540 == 0.0 ? 1.0E-16 : intermediate_der540) *
    1.0E+6;
  t188 = intermediate_der540 * intermediate_der540;
  intermediate_der540 = X[16ULL] / (t188 == 0.0 ? 1.0E-16 : t188) * t158 *
    1.0E+6;
  out.mX[0] = -X[29ULL] / (t187 == 0.0 ? 1.0E-16 : t187) * t151 * 1.0E+6 *
    1.0E-6;
  out.mX[1] = -80000.0;
  out.mX[2] = 1.0;
  out.mX[3] = intermediate_der143 * 0.060000000000000012;
  out.mX[4] = -1.0 / (t107_idx_0 == 0.0 ? 1.0E-16 : t107_idx_0) * 1.0E+6 *
    0.060000000000000012;
  out.mX[5] = 1.0;
  out.mX[6] = t163 * 0.060000000000000012;
  out.mX[7] = t140 * 1.0E-6;
  out.mX[8] = 1.0;
  out.mX[9] = t152 * 1.0E-6;
  out.mX[10] = 1.0;
  out.mX[11] = U_idx_0 * 0.10471975511965977 * 0.001 * 1000.0;
  out.mX[12] = t143 * 0.060000000000000012;
  out.mX[13] = 1.0;
  out.mX[14] = t156 * 0.060000000000000012;
  out.mX[15] = 99999.999999999985;
  out.mX[16] = intermediate_der149 * 0.060000000000000012;
  out.mX[17] = intermediate_der146 * 0.060000000000000012;
  out.mX[18] = t150 * 0.060000000000000012;
  out.mX[19] = intermediate_der144 * 0.060000000000000012;
  out.mX[20] = intermediate_der145 * 0.060000000000000012;
  out.mX[21] = 1000.0;
  out.mX[22] = 1.0;
  out.mX[23] = 99999.999999999985;
  out.mX[24] = 1.0;
  out.mX[25] = 99999.999999999985;
  out.mX[26] = intermediate_der530 * 0.060000000000000012;
  out.mX[27] = 1.0;
  out.mX[28] = intermediate_der155 * 0.060000000000000012;
  out.mX[29] = 99999.999999999985;
  out.mX[30] = 1000.0;
  out.mX[31] = t157 * 0.060000000000000012;
  out.mX[32] = intermediate_der540 * 0.060000000000000012;
  out.mX[33] = X[16ULL] / (t188 == 0.0 ? 1.0E-16 : t188) * t162 * 1.0E+6 *
    0.060000000000000012;
  out.mX[34] = 1.0;
  out.mX[35] = 99999.999999999985;
  (void)LC;
  (void)t191;
  return 0;
}
