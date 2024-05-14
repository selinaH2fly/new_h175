classdef SD_PROCEDURE < Simulink.IntEnumType
  enumeration
    SD_NONE(0)
    SD_Close_ASVi(1)
    SD_pAPRVi_High_WhileFlushAN(2)
    SD_pASTi_High_WhileFlushAN(3)
    SD_pMemb_Out_Off_Range(4)
    SD_E(5)
    SD_F(6)
    SD_Emergency(7)
  end
    methods (Static = true)
     function retVal = addClassNameToEnumNames()
          retVal = true;
     end
end
end 