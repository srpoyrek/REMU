#include <iostream>
#include<registers.h>
#include<riscv.h>
#include<instructions.h>


using std::cout, std::endl;


int main() {
    
    cout << "Hello from REMU: a RISC-V Simulator" << endl;
    
    REMU::RISCV::CORE RV32E(
        REMU::RISCV::BaseInstructionClass::RV32E,
        REMU::RISCV::RegisterLength_t::RL16,
        REMU::RISCV::RegisterSize_t::RS32
    );

    REMU::RISCV::CORE RV32I(
        REMU::RISCV::BaseInstructionClass::RV32I,
        REMU::RISCV::RegisterLength_t::RL32,
        REMU::RISCV::RegisterSize_t::RS32
    );

    REMU::RISCV::CORE RV64I(
        REMU::RISCV::BaseInstructionClass::RV64I,
        REMU::RISCV::RegisterLength_t::RL32,
        REMU::RISCV::RegisterSize_t::RS64
    );

    REMU::RISCV::CORE RV128I(
        REMU::RISCV::BaseInstructionClass::RV64I,
        REMU::RISCV::RegisterLength_t::RL32,
        REMU::RISCV::RegisterSize_t::RS128
    );
    
    
    RV32E.initialize();
    RV32I.initialize();
    RV64I.initialize();
    RV128I.initialize();


    return 0;
}