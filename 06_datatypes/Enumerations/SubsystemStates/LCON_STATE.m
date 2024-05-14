classdef LCON_STATE < Simulink.IntEnumType
  enumeration
    Init(0)
    Disconnected(1)
    Diagnosis(2)
    NegPoleConnected(3)
    Precharge(4)
    Connected(5)
    PrechargeRelayFault(6)
    PositiveRelayFault(7)
    NegativeRelayFault(8)
    BothRelayFault(9)
    ResetFault(10)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 