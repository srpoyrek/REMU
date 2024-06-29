#include<registers.h>
#include<riscv.h>

template<typename T, size_t size, typename R>
void REMU::RISCV::E::display_registers(array<T, size> const& r, R const &) {
    cout << "[";
    for(auto it = begin(r); it != end(r); it++) {
        cout << std::dec << static_cast<R>(it - begin(r)) << "\t: 0x";
        cout << std::hex << *it << "\n"; 
    }
    cout << "]\n\n";
    return;                                     
}


// cores init 
void REMU::RISCV::E::init(void) {
    std::fill(begin(Registers.r16), end(Registers.r16), DEFAULT_REGISTER32_VALUE);
    Registers.r16[static_cast<uint32_t>(RegisterNum_t::X0)] = 0;
    return;
}

void REMU::RISCV::I32::init(void) {
    std::fill(begin(Registers.r32), end(Registers.r32), DEFAULT_REGISTER32_VALUE);
    Registers.r32[static_cast<uint32_t>(RegisterNum_t::X0)] = 0;
    return;
}

void REMU::RISCV::I64::init(void) {
    std::fill(begin(Registers.r64), end(Registers.r64), DEFAULT_REGISTER64_VALUE);
    Registers.r32[static_cast<uint32_t>(RegisterNum_t::X0)] = 0;
    return;
}

// cores print registers 
void REMU::RISCV::E::print_registers(void) {
    REMU::RISCV::E::display_registers(Registers.r16, RegisterNum_t::X16);
    return;                                     
}

void REMU::RISCV::I32::print_registers(void) {
    REMU::RISCV::I32::display_registers(Registers.r32, RegisterNum_t::X32_MAX);
    return;                                     
}

void REMU::RISCV::I64::print_registers(void) {
    REMU::RISCV::I64::display_registers(Registers.r64, RegisterNum_t::X32_MAX);
    return;                                     
}
