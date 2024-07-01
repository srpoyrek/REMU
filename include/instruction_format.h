#pragma once
#include<cstdint>
#include<registers.h>
#include<array>
#include<bitset>
#include<cstddef>

namespace REMU {
    namespace RISCV {
        using std::uint32_t;
        using std::bitset;
        
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



        enum class OP_Funct3_t : uint32_t {
            ADD_SUB = 0x0,
            SLL     = 0x1,
            SLT     = 0x2,
            SLTU    = 0x3,
            XOR     = 0x4,
            SRL_SRA = 0x5,
            OR      = 0x6,
            AND     = 0x7,
        };

        enum class LOAD_Funct3_t : uint32_t {
            LB  = 0x0,
            LH  = 0x1,
            LW  = 0x2,
            LBU = 0x4,
            HBU = 0x5,
        };

        enum class STORE_Funct3_t : std::uint32_t {
            SB  = 0x0,
            SH  = 0x1,
            SW  = 0x2,
        };

        enum class BRANCH_Funct3_t : std::uint32_t {
            BEQ     = 0x0,
            BNE     = 0x1,
            BLT     = 0x4,
            BGE     = 0x5,
            BLTU    = 0x6,
            BGEU    = 0x7,
        };

        enum class JLINK_Funct3_t : std::uint32_t {
            JALR    = 0x0,
        };

        enum class ENVC_Funct3_t : std::uint32_t {
            ECALL    = 0x0,
        };

        enum class ENVB_Funct3_t : std::uint32_t {
            EBREAK    = 0x0,
        };

        constexpr int OPCODE_BITS = 7;
        constexpr int REG_BITS = 5;
        constexpr int FUNCT3_BITS = 3;
        constexpr int FUNCT7_BITS = 7;

        constexpr int IMM4_0_BITS = 5;
        constexpr int IMM4_1_BITS = 4;
        constexpr int IMM10_5_BITS = 6;
        constexpr int IMM11_0_BITS = 12;
        constexpr int IMM11_5_BITS = 7;

        constexpr int IMM31_12_BITS = 20;
        constexpr int IMM19_12_BITS = 8;
        constexpr int IMM10_1_BITS = 10;

        constexpr int IMM20_BITS = 1;
        constexpr int IMM11_BITS = 1;
        constexpr int IMM12_BITS = 1;
        
        constexpr int OTHER_BITS = (sizeof(uint32_t) * __CHAR_BIT__) - OPCODE_BITS;

        struct R_Format_t{
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<FUNCT7_BITS> funct7;
        };

        struct I_Format_t {
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<IMM11_0_BITS> imm11_0;
        };

        struct S_Format_t {
            bitset<OPCODE_BITS> opcode;
            bitset<IMM4_0_BITS> imm4_0;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<IMM11_5_BITS> imm11_5;
        };

        struct B_Format_t {
            bitset<OPCODE_BITS> opcode;
            bitset<IMM11_BITS> imm11;
            bitset<IMM4_1_BITS> imm4_1;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<IMM10_5_BITS> imm10_5;
            bitset<IMM12_BITS> imm12;
        };

        struct U_Format_t{
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<IMM31_12_BITS> imm31_12;
        };

        struct J_Format_t{
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<IMM19_12_BITS> imm19_12;
            bitset<IMM11_BITS> imm11;
            bitset<IMM10_1_BITS> imm10_1;
            bitset<IMM20_BITS> imm20;
        };

        struct FMT_t{
            bitset<OPCODE_BITS> opcode;
            bitset<OTHER_BITS> other;
        };


        enum class BaseInstructionClass: uint32_t {
            RV32E,
            RV32I,
            RV64I,
            RV128I,
        };

        enum class InstructionExtension: uint32_t {
            M,
            A,
            F,
            D,
            Q,
            L,
            C,
            B,
        };

    };
};