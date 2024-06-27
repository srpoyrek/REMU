#pragma once
#include<array>
#include"remu_registers.h"
#include<iostream>

namespace REMU {
    namespace RISCV {
        
        using std::array;
        using std::cout;

        constexpr size_t  NUM_REGISTERS16 = static_cast<size_t>(RegistersE::r16_max);
        constexpr size_t  NUM_REGISTERS32 = static_cast<size_t>(Registers32I::r32_max);
        constexpr size_t  NUM_REGISTERS64 = static_cast<size_t>(Registers64I::r64_max);
        
        constexpr Registers32bit DEFAULT_REGISTER32_VALUE =  0xFFFFFFFF;
        constexpr Registers64bit DEFAULT_REGISTER64_VALUE =  0xFFFFFFFF;

        union Register {
            array<Registers32bit, NUM_REGISTERS16> r16;
            array<Registers32bit, NUM_REGISTERS32> r32;
            array<Registers64bit, NUM_REGISTERS64> r64;
        };

        class E {
            protected:
                Register Registers;
                template<typename T, size_t size, typename R>
                void display_registers(array<T, size> const& r, R const &) {
                    cout << "[";
                    for(auto it = begin(r); it != end(r); it++) {
                        cout << std::dec << static_cast<R>(it - begin(r)) << "\t: 0x";
                        cout << std::hex << *it << "\t"; 
                    }
                    cout << "]\n\n";
                    return;                                     
                }

            public:
                E() = default;
                
                virtual void init(void) {
                    std::fill(begin(Registers.r16), end(Registers.r16), DEFAULT_REGISTER32_VALUE);
                    Registers.r16[static_cast<uint32_t>(RegistersE::x0)] = 0;
                    return;
                }
                
                virtual void print_registers(void) {
                    display_registers(Registers.r16, RegistersE::r16_max);
                    return;                                     
                }
        };

        class I32 : public E {
            public:
                I32() = default;
                
                void init(void) {
                    std::fill(begin(Registers.r32), end(Registers.r32), DEFAULT_REGISTER32_VALUE);
                    Registers.r32[static_cast<uint32_t>(Registers32I::x0)] = 0;
                    return;
                }

                void print_registers(void) {
                    display_registers(Registers.r32, Registers32I::r32_max);
                    return;                                     
                }
                
        };

        class I64 : public I32 {
            public:
                I64() = default;
                
                void init(void) {
                    std::fill(begin(Registers.r64), end(Registers.r64), DEFAULT_REGISTER64_VALUE);
                    Registers.r64[static_cast<uint32_t>(Registers64I::x0)] = 0;
                    return;
                }

                void print_registers(void) {
                    display_registers(Registers.r64, Registers64I::r64_max);
                    return;                                     
                }
                
        };

    };
}