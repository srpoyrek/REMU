#pragma once
#include<instruction_format.h>

namespace REMU {
    namespace RISCV {
        
        union Instruction_t {
            R_Format_t R;
            I_Format_t I;
            S_Format_t S;
            B_Format_t B;
            U_Format_t U;
            J_Format_t J;
            FMT_t inst_op;
            uint32_t inst;
        };

    };
};
