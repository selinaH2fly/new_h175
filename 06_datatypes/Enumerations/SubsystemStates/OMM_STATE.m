%Enumeration Definition for the Operation Mode Manager
%tens define the superstate and ones define the substate
%i.e. "ControllerPowerup" is a substate of "Standby"
%
classdef OMM_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    Standby(10)
    ControllerPowerup(11)
    NormalOperationStandby(12)
    MaintainStandby(13)
    MaintainFlushAn(14)
    MaintainPurgeAn(15)
    MaintainPurgeAnAPRV(16)
    MaintainVentThermal(17)
    Startup(20)
    StartupPreparation(21)
    FFAnode(22)
    FFCathode(26)
    RunupSystem(31)
    ConnectLoad(32)
    Operation(40)
    NormalOperation(41)
    Shutdown(50)
    NormalShutdown(51)
    FastShutdown(52)
    FaultHandling(60)
    FaultHandlingMode(61)
    FaultMaintenanceMode(62)
    EmergencyShutdown(70)
    NormalEShutdown(71)
    FastEShutdown(72)
    HardEStop(73)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 