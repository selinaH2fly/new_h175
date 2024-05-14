classdef SM_COMPONENT < Simulink.IntEnumType
  enumeration
    None(0)
    ASVi_p(1)
    APRVi_p(2)
    ASti_p(3)
    MemDiff_p(4)
    EACi_p(5)
    EACi_T(6)
    EACi_mDot(7)
    EACo_T(8)
    CHUi_T(9)
    CSti_T(10)
    CSti_p(11)
    INV_p(12)
    ECL_p(13)
    CLSti_T(14)
    CLSto_T(15)
    CLSti_p(16)
    FCSDiff_T(17)
    AvgCell_V(18)
    AvgCell_MinCell_V(19)
    Shunt_T(20)
    Stack_I(21)
    LVBus_V(22)
    HVBus_V(23)
    ISOMON_R(24)
    H2Sensor_GS6901(25)
    H2Sensor_GS6902(26)
    CubeInside_T(27)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 


%% Anode Sensors




