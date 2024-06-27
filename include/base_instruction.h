#pragma once
#include<cstdint>
#include<registers.h>

namespace REMU {
    namespace RISCV {

        namespace Instruction {

            enum class Format : std::uint32_t { R, I, S, U};

            struct R_Format{
                uint32_t opcode : 7;
                uint32_t rd     : 5;
                uint32_t funct3 : 3;
                uint32_t rs1    : 5;
                uint32_t rs2    : 5;
                uint32_t funct7 : 7;
            };

            struct I_Format {
                uint32_t opcode : 7;
                uint32_t rd     : 5;
                uint32_t funct3 : 3;
                uint32_t rs1    : 5;
                uint32_t imm    : 12;
            };

            struct S_Format {
                uint32_t opcode  : 7;
                uint32_t imm0_4  : 5;
                uint32_t funct3  : 3;
                uint32_t rs1     : 5;
                uint32_t rs2     : 5;
                uint32_t imm0_11 : 7;
            };

            struct U_Format{
                uint32_t opcode : 7;
                uint32_t rd     : 5;
                uint32_t imm    : 20;
            };
        };

    };
};