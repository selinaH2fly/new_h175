classdef DVLV_STATE < Simulink.IntEnumType
  enumeration
    Closed(0)
    Open(1)
    NotForced(2)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 