#pragma once
#include <cstdint>
#include<array>
#include<bitset>
#include <ostream>

namespace REMU {
    namespace RISCV {

        using std::uint32_t;
        using std::array;
        using std::bitset;

        
        constexpr const size_t REGISTER_32_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * sizeof(uint32_t));
        constexpr const size_t REGISTER_64_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * sizeof(uint64_t));
        constexpr const size_t REGISTER_128_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * 2 * sizeof(uint64_t));

        typedef array<uint64_t, sizeof(uint64_t)> uint128_t;

        template<typename T, size_t S>
        union RegisterAccess_t {
            bitset<S> bits;
            T all;
            RegisterAccess_t(T _all) : all(_all) {};
        };

        typedef RegisterAccess_t<uint32_t, REGISTER_32_BIT_LEN> RegisterAccess32Bit_t;
        typedef RegisterAccess_t<uint64_t, REGISTER_64_BIT_LEN> RegisterAccess64Bit_t;
        typedef RegisterAccess_t<uint128_t, REGISTER_128_BIT_LEN> RegisterAccess128Bit_t;

        enum class RegisterLength_t: uint8_t {
            RL16 = 16U,
            RL32 = 32U,
        };
        
        enum class RegisterSize_t: uint8_t {
            RS32 = 32U,
            RS64 = 64U,
            RS128 = 128U,
        };

        enum class RegisterNumber_t : uint8_t {
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
            X32_MAX = 32,
        };
        
        constexpr const size_t  NUM_REGISTERS16 = static_cast<size_t>(RegisterLength_t::RL16);
        constexpr const size_t  NUM_REGISTERS32 = static_cast<size_t>(RegisterLength_t::RL32);

        const RegisterAccess32Bit_t DEFAULT_REG_32_VALUE({0xFFFFFFFF});
        const RegisterAccess64Bit_t DEFAULT_REG_64_VALUE(0xFFFFFFFFFFFFFFFF);
        const RegisterAccess128Bit_t DEFAULT_REG_128_VALUE({0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF});

        typedef union MEM_t {
                array<RegisterAccess32Bit_t, NUM_REGISTERS16> rv32E;
                array<RegisterAccess32Bit_t, NUM_REGISTERS32> rv32I;
                array<RegisterAccess64Bit_t, NUM_REGISTERS32> rv64I;
                array<RegisterAccess128Bit_t, NUM_REGISTERS32> rv128I;
                MEM_t () {};
        } MEM_t;

        struct RegisterMemory_t {
            RegisterLength_t XLen;
            RegisterSize_t XSize;
            MEM_t Memory;
            
            RegisterSize_t getSize(void) const  {return XSize;};
            RegisterLength_t getLength(void) const  {return XLen;};
            MEM_t & getMem(void) {return Memory;};
            
            RegisterMemory_t(RegisterLength_t xlen, RegisterSize_t xsize);
        };

        std::ostream& operator<<(std::ostream& os, REMU::RISCV::RegisterMemory_t r);
        
        template<typename T, size_t S>
        std::ostream& operator<<(std::ostream& os, const array<T, S>& m);
    
    };
    
};
