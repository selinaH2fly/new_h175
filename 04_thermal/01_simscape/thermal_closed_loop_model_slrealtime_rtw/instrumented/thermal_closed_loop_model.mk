###########################################################################
## Makefile generated for component 'thermal_closed_loop_model'. 
## 
## Makefile     : thermal_closed_loop_model.mk
## Generated on : Fri Jun 28 15:46:38 2024
## Final product: $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = thermal_closed_loop_model
MAKEFILE                  = thermal_closed_loop_model.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/development/hctrl_sil/h175_model/04_thermal/01_simscape
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
LIBSSC_SLI_SLRT_X64_OBJS  = 
LIBSSC_CORE_SLRT_X64_OBJS = 
LIBSSC_ST_SLRT_X64_OBJS   = 
LIBMC_SLRT_X64_OBJS       = 
LIBEX_SLRT_X64_OBJS       = 
LIBPM_SLRT_X64_OBJS       = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Simulink Real-Time Toolchain
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# SLREALTIME_QNX_SP_ROOT
# SLREALTIME_QNX_VERSION

#-----------
# MACROS
#-----------

QCC_TARGET             = gcc_ntox86_64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -L$(MATLAB_ROOT)/toolbox/slrealtime/target/win64/target/lib -ltraceparser -lpps -lslrealtime_kernel -lslrealtime_platform -lslrealtime_rtps -lsocket -lboost_system -lboost_log -lpci -lopenblas -lpcap

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: QNX C Compiler
CC = qcc

# Linker: QCC Linker
LD = q++

# C++ Compiler: QNX C++ Compiler
CPP = q++

# C++ Linker: QCC C++ Linker
CPP_LD = q++

# Archiver: QNX Archiver
AR = ntox86_64-gcc-ar

# Builder: GMAKE Utility
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g -O0 -finstrument-functions
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g -O0 -finstrument-functions
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -V$(QCC_TARGET) -g \
                       -O2 -fwrapv
CPPFLAGS             = -c -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++ \
                       -O2 -fwrapv
CPP_LDFLAGS          = -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++
CPP_SHAREDLIB_LDFLAGS  = -V$(QCC_TARGET) -shared -Wl,--no-undefined -g
LDFLAGS              = -V$(QCC_TARGET) -g -std=gnu++14 -stdlib=libstdc++
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -V$(QCC_TARGET) -shared -Wl,--no-undefined -g



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/thermal_closed_loop_model_slrealtime_rtw -I$(MATLAB_ROOT)/toolbox/slrealtime/simulink/blocks/dist/include -I$(MATLAB_ROOT)/toolbox/slrealtime/target/kernel/dist/include -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/extern/physmod/win64/ex/include -I$(MATLAB_ROOT)/extern/physmod/win64/lang/include -I$(MATLAB_ROOT)/extern/physmod/win64/mc/include -I$(MATLAB_ROOT)/extern/physmod/win64/pd/include -I$(MATLAB_ROOT)/extern/physmod/win64/pm/include -I$(MATLAB_ROOT)/extern/physmod/win64/pm_log/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_comp/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_core/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_ds/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_st/include -I$(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/instrumented

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DSIMULINK_REAL_TIME -D_QNX_SOURCE
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DMAT_FILE=0 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=thermal_closed_loop_model -DNUMST=3 -DNCSTATES=151 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_zc.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_tdxy_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxy_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxy.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_y.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_nldv.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_il.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_all.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_act.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_mode.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxm_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_m_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_m.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_log.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf_v_x.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lv.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxm.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_tdxf_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_a_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_a.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_vmf.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxf_p.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_slv.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_ic.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxf.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_update_i.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_f.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_cache_i.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lock_i.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_update_r.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_exp.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lock_r.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_duf.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_assert.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_gateway.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_backsubrr_dbl.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_lu_real.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_matrixlib_dbl.c $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/BasicThermalSubsystemControl.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/calculateDeltaTemperatureSetpoint.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/calculateTemperatureSetpoint.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/controlBontazTCV.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtGetInf.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtGetNaN.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_nonfinite.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_zcfcn.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtmodel.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/slrealtime_datatype_ground.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_cal.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_data.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rte_thermal_closed_loop_model_parameters.cpp $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/main.cpp host_timer_x86.c slrealtime_code_profiling_utility_functions.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = thermal_closed_loop_model_98402bd5_1_ds.o thermal_closed_loop_model_98402bd5_1_ds_zc.o thermal_closed_loop_model_98402bd5_1_ds_tdxy_p.o thermal_closed_loop_model_98402bd5_1_ds_dxy_p.o thermal_closed_loop_model_98402bd5_1_ds_dxy.o thermal_closed_loop_model_98402bd5_1_ds_y.o thermal_closed_loop_model_98402bd5_1_ds_nldv.o thermal_closed_loop_model_98402bd5_1_ds_obs_il.o thermal_closed_loop_model_98402bd5_1_ds_obs_all.o thermal_closed_loop_model_98402bd5_1_ds_obs_act.o thermal_closed_loop_model_98402bd5_1_ds_mode.o thermal_closed_loop_model_98402bd5_1_ds_dxm_p.o thermal_closed_loop_model_98402bd5_1_ds_m_p.o thermal_closed_loop_model_98402bd5_1_ds_m.o thermal_closed_loop_model_98402bd5_1_ds_log.o thermal_closed_loop_model_98402bd5_1_ds_dnf_p.o thermal_closed_loop_model_98402bd5_1_ds_dnf_v_x.o thermal_closed_loop_model_98402bd5_1_ds_lv.o thermal_closed_loop_model_98402bd5_1_ds_dxm.o thermal_closed_loop_model_98402bd5_1_ds_tdxf_p.o thermal_closed_loop_model_98402bd5_1_ds_a_p.o thermal_closed_loop_model_98402bd5_1_ds_a.o thermal_closed_loop_model_98402bd5_1_ds_vmf.o thermal_closed_loop_model_98402bd5_1_ds_dxf_p.o thermal_closed_loop_model_98402bd5_1_ds_slv.o thermal_closed_loop_model_98402bd5_1_ds_ic.o thermal_closed_loop_model_98402bd5_1_ds_dnf.o thermal_closed_loop_model_98402bd5_1_ds_dxf.o thermal_closed_loop_model_98402bd5_1_ds_update_i.o thermal_closed_loop_model_98402bd5_1_ds_f.o thermal_closed_loop_model_98402bd5_1_ds_cache_i.o thermal_closed_loop_model_98402bd5_1_ds_lock_i.o thermal_closed_loop_model_98402bd5_1_ds_update_r.o thermal_closed_loop_model_98402bd5_1_ds_obs_exp.o thermal_closed_loop_model_98402bd5_1_ds_lock_r.o thermal_closed_loop_model_98402bd5_1_ds_duf.o thermal_closed_loop_model_98402bd5_1_ds_assert.o thermal_closed_loop_model_98402bd5_1.o thermal_closed_loop_model_98402bd5_1_gateway.o rt_backsubrr_dbl.o rt_forwardsubrr_dbl.o rt_lu_real.o rt_matrixlib_dbl.o BasicThermalSubsystemControl.o calculateDeltaTemperatureSetpoint.o calculateTemperatureSetpoint.o controlBontazTCV.o rtGetInf.o rtGetNaN.o rt_nonfinite.o rt_zcfcn.o rtmodel.o slrealtime_datatype_ground.o thermal_closed_loop_model.o thermal_closed_loop_model_cal.o thermal_closed_loop_model_data.o rte_thermal_closed_loop_model_parameters.o main.o host_timer_x86.o slrealtime_code_profiling_utility_functions.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_slrt_x64.a $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_slrt_x64.a $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/lib/ssc_st_slrt_x64.a $(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_slrt_x64.a $(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_slrt_x64.a $(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_slrt_x64.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) -Wl,--start-group $(LIBS) -Wl,--end-group $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : ../%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : ../%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/profile/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/toolbox/coder/profile/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/instrumented/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/instrumented/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_zc.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_zc.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_tdxy_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_tdxy_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxy_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxy_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxy.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxy.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_y.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_y.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_nldv.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_nldv.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_obs_il.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_il.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_obs_all.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_all.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_obs_act.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_act.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_mode.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_mode.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxm_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxm_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_m_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_m_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_m.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_m.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_log.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_log.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dnf_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dnf_v_x.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf_v_x.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_lv.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lv.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxm.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxm.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_tdxf_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_tdxf_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_a_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_a_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_a.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_a.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_vmf.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_vmf.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxf_p.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxf_p.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_slv.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_slv.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_ic.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_ic.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dnf.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dnf.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_dxf.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_dxf.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_update_i.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_update_i.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_f.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_f.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_cache_i.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_cache_i.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_lock_i.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lock_i.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_update_r.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_update_r.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_obs_exp.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_obs_exp.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_lock_r.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_lock_r.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_duf.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_duf.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_ds_assert.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_ds_assert.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1.c
	$(CC) $(CFLAGS) -o $@ $<


thermal_closed_loop_model_98402bd5_1_gateway.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_98402bd5_1_gateway.c
	$(CC) $(CFLAGS) -o $@ $<


rt_backsubrr_dbl.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -o $@ $<


rt_forwardsubrr_dbl.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -o $@ $<


rt_lu_real.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -o $@ $<


rt_matrixlib_dbl.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -o $@ $<


BasicThermalSubsystemControl.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/BasicThermalSubsystemControl.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


calculateDeltaTemperatureSetpoint.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/calculateDeltaTemperatureSetpoint.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


calculateTemperatureSetpoint.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/calculateTemperatureSetpoint.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


controlBontazTCV.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/controlBontazTCV.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtGetInf.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtGetNaN.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rt_nonfinite.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rt_zcfcn.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rt_zcfcn.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rtmodel.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rtmodel.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


slrealtime_datatype_ground.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/slrealtime_datatype_ground.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


thermal_closed_loop_model.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


thermal_closed_loop_model_cal.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_cal.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


thermal_closed_loop_model_data.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/thermal_closed_loop_model_data.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


rte_thermal_closed_loop_model_parameters.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/rte_thermal_closed_loop_model_parameters.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


main.o : $(START_DIR)/thermal_closed_loop_model_slrealtime_rtw/main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


#------------------------
# BUILDABLE LIBRARIES
#------------------------

$(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_slrt_x64.a : $(LIBSSC_SLI_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_SLI_SLRT_X64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_slrt_x64.a : $(LIBSSC_CORE_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_CORE_SLRT_X64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ssc_st/lib/ssc_st_slrt_x64.a : $(LIBSSC_ST_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_ST_SLRT_X64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_slrt_x64.a : $(LIBMC_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBMC_SLRT_X64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_slrt_x64.a : $(LIBEX_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBEX_SLRT_X64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_slrt_x64.a : $(LIBPM_SLRT_X64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_SLRT_X64_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


