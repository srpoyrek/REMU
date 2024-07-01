#include<registers.h>
#include<riscv.h>
#include<iostream>

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
