#pragma once
#include<array>
#include<registers.h>
#include<instruction_format.h>
#include<iostream>

namespace REMU {
    namespace RISCV {
        
        using std::array;
        using std::cout;

        class CORE {
            private:
            protected:
                BaseInstructionClass BaseInstClass;
                RegisterMemory_t Registers;
                RegisterLength_t XLen;

            public:
                CORE(BaseInstructionClass base_ins_class, RegisterLength_t xlen, RegisterSize_t xsize) 
                : BaseInstClass(base_ins_class), Registers(RegisterMemory_t(xlen, xsize)) {};
                void initialize(void);
        };

    };
}