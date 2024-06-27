#include <iostream>
#include<registers.h>
#include<riscv.h>

using std::cout, std::endl;

REMU::RISCV::E e_core;
REMU::RISCV::I32 i32_core;
REMU::RISCV::I64 i64_core;


int main() {
    
    cout << "Hello from REMU: a RISC-V Simulator" << endl;
    // init cores
    e_core.init();
    i32_core.init();
    i64_core.init();

    // print registers
    e_core.print_registers();
    i32_core.print_registers();
    i64_core.print_registers();

    return 0;
}