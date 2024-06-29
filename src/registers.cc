#include "registers.h"


std::ostream& REMU::RISCV::operator<<(std::ostream& os, REMU::RISCV::RegisterNum_t r) {
    os << "R_" << static_cast<Registers32bit_t>(r); 
    return os;  
}

