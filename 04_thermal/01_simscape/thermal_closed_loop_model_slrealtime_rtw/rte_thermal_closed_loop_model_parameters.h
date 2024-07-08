#ifndef _RTE_THERMAL_CLOSED_LOOP_MODEL_PARAMETERS_H
#define _RTE_THERMAL_CLOSED_LOOP_MODEL_PARAMETERS_H
#include "rtwtypes.h"
#include "SegmentInfo.hpp"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "thermal_closed_loop_model_types.h"

struct RTE_Param_Service_T {
  real_T air_HC_min;
  real_T air_HC_nom;
  real_T air_cp;
  real_T air_rho;
  real_T air_vel_nom;
  real_T coolant_initial_pressure;
  real_T coolant_initial_temperature;
  real_T coolant_tube_D;
  real_T radiator_area_air;
};

extern RTE_Param_Service_T RTE_Param_Service;
extern RTE_Param_Service_T *RTE_Param_Service_ptr;
real_T* get_air_HC_min(void);
real_T* get_air_HC_nom(void);
real_T* get_air_cp(void);
real_T* get_air_rho(void);
real_T* get_air_vel_nom(void);
real_T* get_coolant_initial_pressure(void);
real_T* get_coolant_initial_temperature(void);
real_T* get_coolant_tube_D(void);
real_T* get_radiator_area_air(void);
namespace slrealtime
{
  SegmentVector &getSegmentVector(void);
}                                      // slrealtime

#endif
