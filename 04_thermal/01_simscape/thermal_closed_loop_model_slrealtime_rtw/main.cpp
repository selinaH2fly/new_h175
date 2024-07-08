/* Main generated for Simulink Real-Time model thermal_closed_loop_model */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "rte_thermal_closed_loop_model_parameters.h"
#include "thermal_closed_loop_model.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(thermal_closed_loop_model_step0), slrealtime::TaskInfo::PERIODIC, 0.05, 0, 40);
slrealtime::TaskInfo task_2( 1u, std::bind(thermal_closed_loop_model_step2), slrealtime::TaskInfo::PERIODIC, 0.1, 0, 39);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo thermal_closed_loop_model_Info =
{
    "thermal_closed_loop_model",
    thermal_closed_loop_model_initialize,
    thermal_closed_loop_model_terminate,
    []()->char const*& { return thermal_closed_loop_model_M->errorStatus; },
    []()->unsigned char& { return thermal_closed_loop_model_M->Timing.stopRequestedFlag; },
    { task_1, task_2 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, thermal_closed_loop_model_Info);
}
