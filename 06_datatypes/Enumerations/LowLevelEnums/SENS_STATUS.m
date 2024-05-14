classdef SENS_STATUS < Simulink.IntEnumType
  enumeration
    Init(0)
    OK(1)
    NOK(2) 
    OOR(3) % Out-Of-Range
    TO(4) % Timeouted
    NP(5) % Not plausible
    NA(6) % Not available
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 