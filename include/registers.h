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

        
        constexpr size_t REGISTER_32_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * sizeof(uint32_t));
        constexpr size_t REGISTER_64_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * sizeof(uint64_t));
        constexpr size_t REGISTER_128_BIT_LEN = static_cast<size_t>(__CHAR_BIT__ * 2 * sizeof(uint64_t));

        typedef bitset<REGISTER_32_BIT_LEN> Registers32bit_t;
        typedef bitset<REGISTER_64_BIT_LEN> Registers64bit_t;
        typedef bitset<REGISTER_128_BIT_LEN> Registers128bit_t;

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
        
        const size_t  NUM_REGISTERS16 = static_cast<size_t>(RegisterLength_t::RL16);
        const size_t  NUM_REGISTERS32 = static_cast<size_t>(RegisterLength_t::RL32);

        const Registers32bit_t DEFAULT_REGISTER32_VALUE {0xFFFFFFFF};
        const Registers64bit_t DEFAULT_REGISTER64_VALUE {0xFFFFFFFFFFFFFFFF};
        const Registers128bit_t DEFAULT_REGISTER128_VALUE = std::bitset<REGISTER_128_BIT_LEN>(std::string("1").assign(REGISTER_128_BIT_LEN, '1'));


        struct RegisterMemory_t {
            RegisterLength_t XLen;
            RegisterSize_t XSize;
            union MEM_t {
                array<Registers32bit_t, NUM_REGISTERS16> rv32E;
                array<Registers32bit_t, NUM_REGISTERS32> rv32I;
                array<Registers64bit_t, NUM_REGISTERS32> rv64I;
                array<Registers128bit_t, NUM_REGISTERS32> rv128I;

               

                MEM_t() {
                    fill(begin(rv32E), end(rv32E), DEFAULT_REGISTER32_VALUE);
                    fill(begin(rv32I), end(rv32I), DEFAULT_REGISTER32_VALUE);
                    fill(begin(rv64I), end(rv64I), DEFAULT_REGISTER64_VALUE);
                    fill(begin(rv128I), end(rv128I), DEFAULT_REGISTER128_VALUE);
                    return;
                };

            } MEM;
            RegisterSize_t getSize(void) const  {return XSize;};
            RegisterLength_t getLength(void) const  {return XLen;};
            const MEM_t & getMem(void) {return MEM;};
            
            RegisterMemory_t(RegisterLength_t xlen, RegisterSize_t xsize) : XLen(xlen), XSize(xsize) {};
        };

        std::ostream& operator<<(std::ostream& os, REMU::RISCV::RegisterMemory_t r);
        
        std::ostream& operator<<(std::ostream& os, const array<Registers32bit_t, NUM_REGISTERS16>& m);
        std::ostream& operator<<(std::ostream& os, const array<Registers32bit_t, NUM_REGISTERS32>& m);
        std::ostream& operator<<(std::ostream& os, const array<Registers64bit_t, NUM_REGISTERS32>& m);
        std::ostream& operator<<(std::ostream& os, const array<Registers128bit_t, NUM_REGISTERS32>& m);
        
    };
    
};
