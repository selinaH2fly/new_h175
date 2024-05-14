classdef IREQ_STATE < Simulink.IntEnumType
  enumeration
    Steady(0)
    DynUp(1)
    DynDown(2)
    Auto(3)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 