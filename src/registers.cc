#include<array>
#include <registers.h>
#include<iostream>

using REMU::RISCV::RegisterLength_t;
using REMU::RISCV::RegisterSize_t;

using REMU::RISCV::RegisterAccess_t;

using REMU::RISCV::NUM_REGISTERS16;
using REMU::RISCV::NUM_REGISTERS32;

using std::array;
using std::distance;

template<typename T, size_t S>
std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<T, S> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        os << std::dec;
        os << "R" << index << "\t:\t0x" << std::hex <<  it->all << ",\n";
    }
    os << std::dec;
    return os;
}

template<>
std::ostream &REMU::RISCV::operator<<(std::ostream& os, const array<RegisterAccess128Bit_t, NUM_REGISTERS32> & m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        int index = distance(m.begin(), it);
        
        os << "R" << index << "\t:\t" << std::hex << it->all[0] << it->all[1] << ",\n";
    }
    os << std::dec;
    return os;
}

std::ostream &REMU::RISCV::operator<<(std::ostream &os, REMU::RISCV::RegisterMemory_t r) {
    os << "Registers : \n";
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
    os << '\n';
    return os;
}


REMU::RISCV::RegisterMemory_t::RegisterMemory_t(RegisterLength_t xlen, RegisterSize_t xsize) : XLen(xlen), XSize(xsize) {
    if(xlen == RegisterLength_t::RL16 && xsize== RegisterSize_t::RS32 ) {
        // E
        std::fill(begin(MEM.rv32E), end(MEM.rv32E), DEFAULT_REG_32_VALUE);
    } else if(xlen == RegisterLength_t::RL32 && xsize == RegisterSize_t::RS32) {
        // 32I
        std::fill(begin(MEM.rv32I), end(MEM.rv32I), DEFAULT_REG_32_VALUE);
    } else if( xlen == RegisterLength_t::RL32 && xsize == RegisterSize_t::RS64) {
        //64I
        std::fill(begin(MEM.rv64I), end(MEM.rv64I), DEFAULT_REG_64_VALUE);
    } else if(xlen == RegisterLength_t::RL32 && xsize == RegisterSize_t::RS128) {
        //128I
        std::fill(begin(MEM.rv128I), end(MEM.rv128I), DEFAULT_REG_128_VALUE);
    }
    return;
};