classdef APRES_STATE < Simulink.IntEnumType
  enumeration
    Off(0)
    PresCtrl(1)
    ReadyForDiffPresCtrl(2)
    DiffPresCtrl(3)
    CompensatingMemPresDiff(4)
    DecreasingAPRViPressure(5)
    ResetESD(6)
    FlushAnode(7)
    MaintenanceHoldPressure(8)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 