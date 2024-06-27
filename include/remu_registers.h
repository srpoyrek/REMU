#pragma once
#include <cstdint>
#include <ostream>

namespace REMU {
    namespace RISCV {
        using std::uint32_t;

        typedef uint32_t Registers32bit;
        typedef uint64_t Registers64bit;

        enum class RegistersE : Registers32bit {
            x0 = 0,
            x1,
            x2,
            x3,
            x4,
            x5,
            x6,
            x7,
            x8,
            x9,
            x10,
            x11,
            x12,
            x13,
            x14,
            x15,
            r16_max
        };

        enum class Registers32I : Registers32bit {
            x0 = 0,
            x1,
            x2,
            x3,
            x4,
            x5,
            x6,
            x7,
            x8,
            x9,
            x10,
            x11,
            x12,
            x13,
            x14,
            x15,
            x16,
            x17,
            x18,
            x19,
            x20,
            x21,
            x22,
            x23,
            x24,
            x25,
            x26,
            x27,
            x28,
            x29,
            x30,
            x31,
            r32_max
        };

        enum class Registers64I : Registers64bit {
            x0 = 0,
            x1,
            x2,
            x3,
            x4,
            x5,
            x6,
            x7,
            x8,
            x9,
            x10,
            x11,
            x12,
            x13,
            x14,
            x15,
            x16,
            x17,
            x18,
            x19,
            x20,
            x21,
            x22,
            x23,
            x24,
            x25,
            x26,
            x27,
            x28,
            x29,
            x30,
            x31,
            x32,
            x33,
            x34,
            x35,
            x36,
            x37,
            x38,
            x39,
            x40,
            x41,
            x42,
            x43,
            x44,
            x45,
            x46,
            x47,
            x48,
            x49,
            x50,
            x51,
            x52,
            x53,
            x54,
            x56,
            x57,
            x58,
            x59,
            x60,
            x61,
            x62,
            x63,
            r64_max
        };

        template<typename S, typename T>
        S& operator<<(S &os, T r);
    };
    
};
