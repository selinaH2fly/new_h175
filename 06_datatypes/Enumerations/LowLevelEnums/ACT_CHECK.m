classdef ACT_CHECK < Simulink.IntEnumType
  enumeration
    Ok(0)
    NotReady(1)
    FaultInactive(2)
    Fault(3)
    NotUsed(4)
  end
  methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 