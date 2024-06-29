#pragma once
#include<cstdint>
#include<registers.h>

namespace REMU {
    namespace RISCV {

        enum class Format_t : std::uint32_t { R, I, S, B, U, J};

        enum class Opcode_t : std::uint32_t {
            LOAD        = 0b0000011, // load
            MISC_MEM    = 0b0001111, // fence I/O and memory accesses
            OP_IMM      = 0b0010011, // operation immediate
            AUIPC       = 0b0010111, // add immediate pc
            STORE       = 0b0100011, // store 
            OP          = 0b0110011, // operation on registers
            LUI         = 0b0110111, // load immediate
            BRANCH      = 0b1100011, // branch inst
            JALR        = 0b1100111, // jump and link register
            JAL         = 0b1101111, // jump and link
            SYSTEM      = 0b1110011, // system
        };
        
        struct R_Format_t{
            Opcode_t opcode     : 7;
            RegisterNum_t rd    : 5;
            uint32_t funct3     : 3;
            RegisterNum_t rs1   : 5;
            RegisterNum_t rs2   : 5;
            uint32_t funct7     : 7;
        };

        struct I_Format_t {
            Opcode_t opcode     : 7;
            RegisterNum_t rd    : 5;
            uint32_t funct3     : 3;
            RegisterNum_t rs1   : 5;
            uint32_t imm11_0    : 12;
        };

        struct S_Format_t {
            Opcode_t opcode     : 7;
            uint32_t imm4_0     : 5;
            uint32_t funct3     : 3;
            RegisterNum_t rs1   : 5;
            RegisterNum_t rs2   : 5;
            uint32_t imm11_5    : 7;
        };

        struct B_Format_t {
            Opcode_t opcode     : 7;
            uint32_t imm11      : 1;
            uint32_t imm4_1     : 4;
            uint32_t funct3     : 3;
            RegisterNum_t rs1   : 5;
            RegisterNum_t rs2   : 5;
            uint32_t imm10_5    : 6;
            uint32_t imm12      : 6;
        };

        struct U_Format_t{
            Opcode_t opcode     : 7;
            RegisterNum_t rd    : 5;
            uint32_t imm        : 20;
        };

        struct J_Format_t{
            Opcode_t opcode     : 7;
            RegisterNum_t rd    : 5;
            uint32_t imm19_12   : 8;
            uint32_t imm11      : 1;
            uint32_t imm10_1    : 10;
            uint32_t imm20      : 1;
        };
        
    };
};