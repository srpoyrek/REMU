#pragma once
#include<instruction_format.h>

namespace REMU {
    namespace RISCV {
        
        typedef union {
            R_Format_t R;
            I_Format_t I;
            S_Format_t S;
            B_Format_t B;
            U_Format_t U;
            J_Format_t J;
            FMT_t inst_op;
            uint32_t inst;
        } Instruction_t;


        void ADD(BaseInstructionClass const & BaseInstClass, RegisterMemory_t & r, Instruction_t const & i);

        void ADD_RV32E(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2);
        void ADD_RV32I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2);
        void ADD_RV64I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2);
        void ADD_RV128I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2);

    };
};
