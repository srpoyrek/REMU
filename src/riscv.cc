#include<registers.h>
#include<riscv.h>
#include<iostream>
#include<instructions.h>

using REMU::RISCV::BaseInstructionClass;
using REMU::RISCV::CORE;
            
using std:: cout, std::endl;

void CORE::initialize(void) {
    auto l = static_cast<size_t>(Registers.getLength());
    auto s = static_cast<size_t>(Registers.getSize());
    cout << "Init Core : XLen: "<<  l << " XSize: "<< s << endl;
    cout << Registers;
    return;
};


void CORE::execute(Instruction_t const & i) {
    ADD(BaseInstClass, Registers, i);
    return;
};
