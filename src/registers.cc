#include<array>
#include <registers.h>
#include<iostream>

using REMU::RISCV::RegisterLength_t;
using REMU::RISCV::RegisterSize_t;

using REMU::RISCV::Registers32bit_t;
using REMU::RISCV::Registers64bit_t;
using REMU::RISCV::Registers128bit_t;

using REMU::RISCV::NUM_REGISTERS16;
using REMU::RISCV::NUM_REGISTERS32;

using std::array;
using std::distance;

std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<Registers32bit_t, NUM_REGISTERS16> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        os << "R" << index << " : " << *it << ",\n";
    }
    return os;
}

std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<Registers32bit_t, NUM_REGISTERS32> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        os << "R" << index << " : " << *it << ",\n";
    }
    return os;
}

std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<Registers64bit_t, NUM_REGISTERS32> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        os << "R" << index << " : " << *it << ",\n";
    }
    return os;
}

std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<Registers128bit_t, NUM_REGISTERS32> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        os << "R" << index << " : " << *it << ",\n";
    }
    return os;
}

std::ostream &REMU::RISCV::operator<<(std::ostream &os, REMU::RISCV::RegisterMemory_t r) {
    os << "[";
    auto l = r.getLength();
    auto s = r.getSize();
    auto mem = r.getMem();
    if(l == RegisterLength_t::RL16 && s == RegisterSize_t::RS32 ) {
        // E
        os << mem.rv32E;
    } else if(l == RegisterLength_t::RL32 && s == RegisterSize_t::RS32) {
        // 32I
        os << mem.rv32I;
    } else if( l == RegisterLength_t::RL32 && s == RegisterSize_t::RS64) {
        //64I
        os << mem.rv64I;
    } else if(l == RegisterLength_t::RL32 && s == RegisterSize_t::RS128) {
        //128I
        os << mem.rv128I;
    }
    os << "]" << '\n';
    return os;
}
