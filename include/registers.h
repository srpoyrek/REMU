#pragma once
#include <cstdint>
#include<array>
#include <ostream>

namespace REMU {
    namespace RISCV {

        using std::uint32_t;
        using std::array;

        typedef uint32_t Registers32bit_t;
        typedef uint64_t Registers64bit_t;

        enum class RegisterNum_t : Registers32bit_t {
            X0 = 0,
            X1,
            X2,
            X3,
            X4,
            X5,
            X6,
            X7,
            X8,
            X9,
            X10,
            X11,
            X12,
            X13,
            X14,
            X15,
            X16,
            X17,
            X18,
            X19,
            X20,
            X21,
            X22,
            X23,
            X24,
            X25,
            X26,
            X27,
            X28,
            X29,
            X30,
            X31,
            X32_MAX
        };
        
        constexpr size_t  NUM_REGISTERS16 = static_cast<size_t>(RegisterNum_t::X16);
        constexpr size_t  NUM_REGISTERS32 = static_cast<size_t>(RegisterNum_t::X32_MAX);

        constexpr Registers32bit_t DEFAULT_REGISTER32_VALUE =  0xFFFFFFFF;
        constexpr Registers64bit_t DEFAULT_REGISTER64_VALUE =  0xFFFFFFFFFFFFFFFF;

        union RegisterMemory_t {
            array<Registers32bit_t, NUM_REGISTERS16> r16;
            array<Registers32bit_t, NUM_REGISTERS32> r32;
            array<Registers64bit_t, NUM_REGISTERS32> r64;
        };

        std::ostream& operator<<(std::ostream& os, REMU::RISCV::RegisterNum_t r);

    };
    
};
