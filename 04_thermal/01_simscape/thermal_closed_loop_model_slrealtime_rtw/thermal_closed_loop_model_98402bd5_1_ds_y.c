/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'thermal_closed_loop_model/Basic Stack Heat Emulation/Solver Configuration'.
 */

#include "ne_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_sys_struct.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_y.h"
#include "thermal_closed_loop_model_98402bd5_1_ds.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_externals.h"
#include "thermal_closed_loop_model_98402bd5_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T thermal_closed_loop_model_98402bd5_1_ds_y(const NeDynamicSystem *LC,
  const NeDynamicSystemInput *t98, NeDsMethodOutput *t99)
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
  ETTS0 t10;
  ETTS0 t11;
  ETTS0 t9;
  PmRealVector out;
  real_T X[148];
  real_T c_efOut[1];
  real_T f_efOut[1];
  real_T i_efOut[1];
  real_T l_efOut[1];
  real_T o_efOut[1];
  real_T r_efOut[1];
  real_T t51[1];
  real_T Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V;
  real_T Basic_Peripherals_Pressure_Temperature_Sensor_TL6_P;
  real_T U_idx_0;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T t71_idx_0;
  real_T t73;
  real_T t74;
  real_T t79;
  real_T t81;
  size_t t13[1];
  size_t t14[1];
  size_t t16[1];
  int32_T b;
  U_idx_0 = t98->mU.mX[0];
  U_idx_5 = t98->mU.mX[5];
  U_idx_6 = t98->mU.mX[6];
  for (b = 0; b < 148; b++) {
    X[b] = t98->mX.mX[b];
  }

  out = t99->mY;
  Basic_Peripherals_Pressure_Temperature_Sensor_TL6_P = X[0ULL] * -0.8 +
    1.1132499999999999;
  U_idx_0 *= 0.10471975511965977;
  t51[0ULL] = X[49ULL];
  t13[0] = 20ULL;
  t14[0] = 1ULL;
  tlu2_linear_linear_prelookup(&efOut.mField0[0ULL], &efOut.mField1[0ULL],
    &efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL], &t13
    [0ULL], &t14[0ULL]);
  t10 = efOut;
  t51[0ULL] = X[50ULL];
  t16[0] = 19ULL;
  tlu2_linear_linear_prelookup(&b_efOut.mField0[0ULL], &b_efOut.mField1[0ULL],
    &b_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t9 = b_efOut;
  tlu2_2d_linear_linear_value(&c_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t9.mField0[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t71_idx_0 = c_efOut[0];
  Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V = -X[4ULL] / (t71_idx_0 ==
    0.0 ? 1.0E-16 : t71_idx_0) * 1.0E+6;
  t51[0ULL] = X[41ULL];
  tlu2_linear_linear_prelookup(&d_efOut.mField0[0ULL], &d_efOut.mField1[0ULL],
    &d_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t10 = d_efOut;
  t51[0ULL] = X[42ULL];
  tlu2_linear_linear_prelookup(&e_efOut.mField0[0ULL], &e_efOut.mField1[0ULL],
    &e_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t9 = e_efOut;
  tlu2_2d_linear_linear_value(&f_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t9.mField0[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t71_idx_0 = f_efOut[0];
  t73 = X[46ULL] / (t71_idx_0 == 0.0 ? 1.0E-16 : t71_idx_0) * 1.0E+6;
  t51[0ULL] = X[21ULL];
  tlu2_linear_linear_prelookup(&g_efOut.mField0[0ULL], &g_efOut.mField1[0ULL],
    &g_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t10 = g_efOut;
  t51[0ULL] = Basic_Peripherals_Pressure_Temperature_Sensor_TL6_P;
  tlu2_linear_linear_prelookup(&h_efOut.mField0[0ULL], &h_efOut.mField1[0ULL],
    &h_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t9 = h_efOut;
  tlu2_2d_linear_linear_value(&i_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t9.mField0[0ULL], &t9.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t71_idx_0 = i_efOut[0];
  t74 = X[29ULL] / (t71_idx_0 == 0.0 ? 1.0E-16 : t71_idx_0) * 1.0E+6;
  t51[0ULL] = X[106ULL];
  tlu2_linear_linear_prelookup(&j_efOut.mField0[0ULL], &j_efOut.mField1[0ULL],
    &j_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t9 = j_efOut;
  t51[0ULL] = X[107ULL];
  tlu2_linear_linear_prelookup(&k_efOut.mField0[0ULL], &k_efOut.mField1[0ULL],
    &k_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t11 = k_efOut;
  tlu2_2d_linear_linear_value(&l_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t71_idx_0 = l_efOut[0];
  t79 = X[110ULL] / (t71_idx_0 == 0.0 ? 1.0E-16 : t71_idx_0) * 1.0E+6;
  t51[0ULL] = X[39ULL];
  tlu2_linear_linear_prelookup(&m_efOut.mField0[0ULL], &m_efOut.mField1[0ULL],
    &m_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t10 = m_efOut;
  t51[0ULL] = X[40ULL];
  tlu2_linear_linear_prelookup(&n_efOut.mField0[0ULL], &n_efOut.mField1[0ULL],
    &n_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t11 = n_efOut;
  tlu2_2d_linear_linear_value(&o_efOut[0ULL], &t10.mField0[0ULL], &t10.mField2
    [0ULL], &t11.mField0[0ULL], &t11.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t71_idx_0 = o_efOut[0];
  t51[0ULL] = X[111ULL];
  tlu2_linear_linear_prelookup(&p_efOut.mField0[0ULL], &p_efOut.mField1[0ULL],
    &p_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField1, &t51[0ULL],
    &t13[0ULL], &t14[0ULL]);
  t9 = p_efOut;
  t51[0ULL] = X[112ULL];
  tlu2_linear_linear_prelookup(&q_efOut.mField0[0ULL], &q_efOut.mField1[0ULL],
    &q_efOut.mField2[0ULL], ((_NeDynamicSystem*)(LC))->mField2, &t51[0ULL],
    &t16[0ULL], &t14[0ULL]);
  t10 = q_efOut;
  tlu2_2d_linear_linear_value(&r_efOut[0ULL], &t9.mField0[0ULL], &t9.mField2
    [0ULL], &t10.mField0[0ULL], &t10.mField2[0ULL], ((_NeDynamicSystem*)(LC))
    ->mField0, &t13[0ULL], &t16[0ULL], &t14[0ULL]);
  t51[0] = r_efOut[0];
  t81 = t51[0ULL];
  t81 = -X[16ULL] / (t81 == 0.0 ? 1.0E-16 : t81) * 1.0E+6;
  out.mX[0] = X[3ULL];
  out.mX[1] = U_idx_0 * 9.5492965855137211;
  out.mX[2] = X[32ULL];
  out.mX[3] = Basic_Peripherals_Mass_Energy_Flow_Rate_Sensor_TL1_V *
    0.060000000000000012;
  out.mX[4] = t73 * 0.060000000000000012;
  out.mX[5] = t74 * 1.0E-6;
  out.mX[6] = U_idx_0 * X[32ULL] * 0.001 * 1000.0;
  out.mX[7] = Basic_Peripherals_Pressure_Temperature_Sensor_TL6_P *
    99999.999999999985;
  out.mX[8] = X[21ULL];
  out.mX[9] = U_idx_5 * 0.001;
  out.mX[10] = X[15ULL];
  out.mX[11] = U_idx_6 * 0.10471975511965977 * 9.5492965855137211;
  out.mX[12] = -X[8ULL] / (t71_idx_0 == 0.0 ? 1.0E-16 : t71_idx_0) * 1.0E+6 *
    0.060000000000000012;
  out.mX[13] = X[56ULL] * 1000.0;
  out.mX[14] = t81 * 0.060000000000000012;
  out.mX[15] = X[109ULL] * 1000.0;
  out.mX[16] = t79 * 0.060000000000000012;
  out.mX[17] = X[95ULL] * 99999.999999999985;
  out.mX[18] = X[94ULL];
  out.mX[19] = X[107ULL] * 99999.999999999985;
  out.mX[20] = X[106ULL];
  out.mX[21] = X[127ULL] * 99999.999999999985;
  out.mX[22] = X[126ULL];
  out.mX[23] = X[97ULL] * 99999.999999999985;
  out.mX[24] = X[96ULL];
  out.mX[25] = X[40ULL] * 99999.999999999985;
  out.mX[26] = X[39ULL];
  (void)LC;
  (void)t99;
  return 0;
}
