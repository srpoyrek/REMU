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
            ADD     = 0x00,
            SUB     = 0x00,
            SLL     = 0x01,
            SLT     = 0x02,
            SLTU    = 0x03,
            XOR     = 0x04,
            SRL     = 0x05,
            SRA     = 0x05,
            OR      = 0x06,
            AND     = 0x07,
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

        enum class OP_Funct7_t : uint32_t {
            ADD     = 0x00,
            SUB     = 0x20,
            SLL     = 0x00,
            SLT     = 0x00,
            SLTU    = 0x00,
            XOR     = 0x00,
            SRL     = 0x00,
            SRA     = 0x20,
            OR      = 0x00,
            AND     = 0x00,
        };


        enum class OP_IMM_Funct7_t : uint32_t {
            SLLI_IMM = 0x00,
            SRLI_IMM = 0x00,
            SRAI_IMM = 0x20,
        };

        enum class ENVC_Funct7_t : std::uint32_t {
            ECALL    = 0x0,
        };

        enum class ENVB_Funct7_t : std::uint32_t {
            EBREAK    = 0x1,
        };


        constexpr const size_t OPCODE_BITS = 7;
        constexpr const size_t REG_BITS = 5;
        constexpr const size_t FUNCT3_BITS = 3;
        constexpr const size_t FUNCT7_BITS = 7;

        constexpr const size_t IMM4_0_BITS = 5;
        constexpr const size_t IMM4_1_BITS = 4;
        constexpr const size_t IMM10_5_BITS = 6;
        constexpr const size_t IMM11_0_BITS = 12;
        constexpr const size_t IMM11_5_BITS = 7;

        constexpr const size_t IMM31_12_BITS = 20;
        constexpr const size_t IMM19_12_BITS = 8;
        constexpr const size_t IMM10_1_BITS = 10;

        constexpr const size_t IMM20_BITS = 1;
        constexpr const size_t IMM11_BITS = 1;
        constexpr const size_t IMM12_BITS = 1;
        
        constexpr const size_t DONT_CARE_BITS = (sizeof(uint32_t) * __CHAR_BIT__) - OPCODE_BITS;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<FUNCT7_BITS> funct7;
        } R_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<IMM11_0_BITS> imm11_0;
        } I_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<IMM4_0_BITS> imm4_0;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<IMM11_5_BITS> imm11_5;
        } S_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<IMM11_BITS> imm11;
            bitset<IMM4_1_BITS> imm4_1;
            bitset<FUNCT3_BITS> funct3;
            bitset<REG_BITS> rs1;
            bitset<REG_BITS> rs2;
            bitset<IMM10_5_BITS> imm10_5;
            bitset<IMM12_BITS> imm12;
        } B_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<IMM31_12_BITS> imm31_12;
        } U_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<REG_BITS> rd;
            bitset<IMM19_12_BITS> imm19_12;
            bitset<IMM11_BITS> imm11;
            bitset<IMM10_1_BITS> imm10_1;
            bitset<IMM20_BITS> imm20;
        } J_Format_t;

        typedef struct {
            bitset<OPCODE_BITS> opcode;
            bitset<DONT_CARE_BITS> dont_care;
        } FMT_t;


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