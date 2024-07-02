#include<instructions.h>

using REMU::RISCV::Opcode_t;
using REMU::RISCV::OP_Funct3_t;
using REMU::RISCV::OP_Funct7_t;

void REMU::RISCV::ADD(BaseInstructionClass const & BaseInstClass, RegisterMemory_t & r, Instruction_t const & i) {
    if(static_cast<Opcode_t>(i.inst_op.opcode.to_ulong()) != Opcode_t::OP) return;
    if(static_cast<OP_Funct3_t>(i.R.funct3.to_ulong()) != OP_Funct3_t::ADD) return;
    if(static_cast<OP_Funct7_t>(i.R.funct7.to_ulong()) != OP_Funct7_t::ADD) return;

    uint8_t rd = static_cast<uint8_t>(i.R.rd.to_ulong());
    uint8_t rs1 = static_cast<uint8_t>(i.R.rs1.to_ulong());
    uint8_t rs2 = static_cast<uint8_t>(i.R.rs2.to_ulong());

    if(static_cast<RegisterNumber_t>(rd) > RegisterNumber_t::X32_MAX ) return;
    if(static_cast<RegisterNumber_t>(rs1) > RegisterNumber_t::X32_MAX ) return;
    if(static_cast<RegisterNumber_t>(rs2) > RegisterNumber_t::X32_MAX ) return;

    switch(BaseInstClass) {
        case BaseInstructionClass::RV32E:
            REMU::RISCV::ADD_RV32E(r, rd, rs1, rs2);
        break;
        case BaseInstructionClass::RV64I:
            REMU::RISCV::ADD_RV64I(r, rd, rs1, rs2);
        break;
        case BaseInstructionClass::RV128I:
            // TO DO: CARRY
            REMU::RISCV::ADD_RV128I(r, rd, rs1, rs2);
        break;
        case BaseInstructionClass::RV32I:
            REMU::RISCV::ADD_RV32I(r, rd, rs1, rs2);
        default:
        break;
    }
    return;
}


void REMU::RISCV::ADD_RV32E(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2) {
    if(static_cast<RegisterNumber_t>(rd) > RegisterNumber_t::X16 ) return;
    if(static_cast<RegisterNumber_t>(rs1) > RegisterNumber_t::X16 ) return;
    if(static_cast<RegisterNumber_t>(rs2) > RegisterNumber_t::X16 ) return;
    r.Memory.rv32E[rd].all = r.Memory.rv32E[rs1].all + r.Memory.rv32E[rs1].all;
    return;
}

void REMU::RISCV::ADD_RV32I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2) {
    r.Memory.rv32I[rd].all = r.Memory.rv32I[rs1].all + r.Memory.rv32I[rs1].all;
    return;
}

void REMU::RISCV::ADD_RV64I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2) {
    r.Memory.rv64I[rd].all = r.Memory.rv64I[rs1].all + r.Memory.rv64I[rs1].all;
    return;
}

void REMU::RISCV::ADD_RV128I(RegisterMemory_t & r, uint8_t rd, uint8_t rs1, uint8_t rs2) {
    // TO DO: CARRY
    r.Memory.rv128I[rd].all[0] = r.Memory.rv128I[rs1].all[0] + r.Memory.rv128I[rs1].all[0];
    r.Memory.rv128I[rd].all[1]= r.Memory.rv128I[rs1].all[1] + r.Memory.rv128I[rs1].all[1];
    return;
}

