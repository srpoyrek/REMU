#pragma once
#include<array>
#include"registers.h"
#include<iostream>

namespace REMU {
    namespace RISCV {
        
        using std::array;
        using std::cout;

        constexpr size_t  NUM_REGISTERS16 = static_cast<size_t>(RegistersE::r16_max);
        constexpr size_t  NUM_REGISTERS32 = static_cast<size_t>(Registers32I::r32_max);
        constexpr size_t  NUM_REGISTERS64 = static_cast<size_t>(Registers64I::r64_max);
        
        union Register {
            array<Registers32bit, NUM_REGISTERS16> r16;
            array<Registers32bit, NUM_REGISTERS32> r32;
            array<Registers64bit, NUM_REGISTERS64> r64;
        };

        class E {
            protected:
                Register Registers;
                template<typename T, size_t size, typename R>
                void display_registers(array<T, size> const& r, R const &);

            public:
                E() = default;
                virtual void init(void);                
                virtual void print_registers(void);
                const Register& getRegisters(void) const { return Registers; };

                template<typename T, size_t size, typename R>
                friend std::ostream& REMU::RISCV::operator<<(std::ostream& os, array<T, size> const& r);
        };

        class I32 : public E {
            public:
                I32() = default;
                void init(void);
                void print_registers(void);
        };

        class I64 : public I32 {
            public:
                I64() = default;
                void init(void);
                void print_registers(void);
        };

    };
}