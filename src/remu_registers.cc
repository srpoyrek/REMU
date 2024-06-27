#include "remu_registers.h"

template<> 
std::ostream& REMU::RISCV::operator<<(std::ostream& os, REMU::RISCV::RegistersE r) {
    os << "R16_" << static_cast<Registers32bit>(r); 
    return os;  
}

template<> 
std::ostream& REMU::RISCV::operator<<(std::ostream &os, REMU::RISCV::Registers32I r) {
    os << "R32_" << static_cast<Registers32bit>(r);
    return os;
}

template<> 
std::ostream& REMU::RISCV::operator<<(std::ostream &os, REMU::RISCV::Registers64I r) {
    os << "R64_" << static_cast<Registers32bit>(r);
    return os;
}

