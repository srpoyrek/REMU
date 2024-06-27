#include<registers.h>
#include<riscv.h>

constexpr REMU::RISCV::Registers32bit DEFAULT_REGISTER32_VALUE =  0xFFFFFFFF;
constexpr REMU::RISCV::Registers64bit DEFAULT_REGISTER64_VALUE =  0xFFFFFFFF;

template<typename T, size_t size, typename R>
void REMU::RISCV::E::display_registers(array<T, size> const& r, R const &) {
    cout << "[";
    for(auto it = begin(r); it != end(r); it++) {
        cout << std::dec << static_cast<R>(it - begin(r)) << "\t: 0x";
        cout << std::hex << *it << "\t"; 
    }
    cout << "]\n\n";
    return;                                     
}


// cores init 
void REMU::RISCV::E::init(void) {
    std::fill(begin(Registers.r16), end(Registers.r16), DEFAULT_REGISTER32_VALUE);
    Registers.r16[static_cast<uint32_t>(RegistersE::x0)] = 0;
    return;
}

void REMU::RISCV::I32::init(void) {
    std::fill(begin(Registers.r32), end(Registers.r32), DEFAULT_REGISTER32_VALUE);
    Registers.r32[static_cast<uint32_t>(Registers32I::x0)] = 0;
    return;
}

void REMU::RISCV::I64::init(void) {
    std::fill(begin(Registers.r64), end(Registers.r64), DEFAULT_REGISTER64_VALUE);
    Registers.r64[static_cast<uint32_t>(Registers64I::x0)] = 0;
    return;
}




// cores print registers 
void REMU::RISCV::E::print_registers(void) {
    REMU::RISCV::E::display_registers(Registers.r16, RegistersE::r16_max);
    return;                                     
}

void REMU::RISCV::I32::print_registers(void) {
    REMU::RISCV::I32::display_registers(Registers.r32, Registers32I::r32_max);
    return;                                     
}

void REMU::RISCV::I64::print_registers(void) {
    REMU::RISCV::I64::display_registers(Registers.r64, Registers64I::r64_max);
    return;                                     
}