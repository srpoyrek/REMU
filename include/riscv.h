#pragma once
#include<array>
#include"registers.h"
#include<iostream>

namespace REMU {
    namespace RISCV {
        
        using std::array;
        using std::cout;

        class E {
            protected:
                RegisterMemory_t Registers;
                template<typename T, size_t size, typename R>
                void display_registers(array<T, size> const& r, R const &);

            public:
                E() = default;
                virtual void init(void);                
                virtual void print_registers(void);
                const RegisterMemory_t& getRegisters(void) const { return Registers; };

                template<typename T, size_t size, typename R>
                friend std::ostream& REMU::RISCV::operator<<(std::ostream& os, array<T, size> const& r);
        };

        class I32 : public E {
            public:
                I32() = default;
                virtual void init(void);
                virtual void print_registers(void);
        };

        class I64 : public I32 {
            public:
                I64() = default;
                virtual void init(void);
                virtual void print_registers(void);
        };

    };
}