#include "rte_thermal_closed_loop_model_parameters.h"
#include "thermal_closed_loop_model.h"
#include "thermal_closed_loop_model_cal.h"

RTE_Param_Service_T RTE_Param_Service = {
  10.0,
  100.0,
  1004.0,
  1.2,
  1.0,
  0.111325,
  293.15,
  0.05,
  0.10260000000000001
};

RTE_Param_Service_T *RTE_Param_Service_ptr = &RTE_Param_Service;
real_T* get_air_HC_min(void)
{
  return &RTE_Param_Service_ptr->air_HC_min;
}

real_T* get_air_HC_nom(void)
{
  return &RTE_Param_Service_ptr->air_HC_nom;
}

real_T* get_air_cp(void)
{
  return &RTE_Param_Service_ptr->air_cp;
}

real_T* get_air_rho(void)
{
  return &RTE_Param_Service_ptr->air_rho;
}

real_T* get_air_vel_nom(void)
{
  return &RTE_Param_Service_ptr->air_vel_nom;
}

real_T* get_coolant_initial_pressure(void)
{
  return &RTE_Param_Service_ptr->coolant_initial_pressure;
}

real_T* get_coolant_initial_temperature(void)
{
  return &RTE_Param_Service_ptr->coolant_initial_temperature;
}

real_T* get_coolant_tube_D(void)
{
  return &RTE_Param_Service_ptr->coolant_tube_D;
}

real_T* get_radiator_area_air(void)
{
  return &RTE_Param_Service_ptr->radiator_area_air;
}

extern thermal_closed_loop_mo_cal_type thermal_closed_loop_mo_cal_impl;
extern RTE_Param_Service_T RTE_Param_Service;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&RTE_Param_Service, (void**)&RTE_Param_Service_ptr, sizeof
      (RTE_Param_Service_T), 2 },

    { (void*)&thermal_closed_loop_mo_cal_impl, (void**)
      &thermal_closed_loop_model_cal, sizeof(thermal_closed_loop_mo_cal_type), 2
    }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
