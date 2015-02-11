// See LICENSE for license details.

#ifndef RISCV_CSR_ENCODING_H
#define RISCV_CSR_ENCODING_H

#define SR_S     0x00000001
#define SR_PS    0x00000002
#define SR_EI    0x00000004
#define SR_PEI   0x00000008
#define SR_EF    0x00000010
#define SR_U64   0x00000020
#define SR_S64   0x00000040
#define SR_VM    0x00000080
#define SR_EA    0x00000100
#define SR_IM    0x00FF0000
#define SR_IP    0xFF000000
#define SR_ZERO  ~(SR_S|SR_PS|SR_EI|SR_PEI|SR_EF|SR_U64|SR_S64|SR_VM|SR_EA|SR_IM|SR_IP)
#define SR_IM_SHIFT 16
#define SR_IP_SHIFT 24

#define IRQ_COP   2
#define IRQ_IPI   5
#define IRQ_HOST  6
#define IRQ_TIMER 7

#define IMPL_SPIKE  1
#define IMPL_ROCKET 2

// page table entry (PTE) fields
#define PTE_V    0x001 // Entry is a page Table descriptor
#define PTE_T    0x002 // Entry is a page Table, not a terminal node
#define PTE_G    0x004 // Global
#define PTE_UR   0x008 // User Write permission
#define PTE_UW   0x010 // User Read permission
#define PTE_UX   0x020 // User eXecute permission
#define PTE_SR   0x040 // Supervisor Read permission
#define PTE_SW   0x080 // Supervisor Write permission
#define PTE_SX   0x100 // Supervisor eXecute permission
#define PTE_PERM (PTE_SR | PTE_SW | PTE_SX | PTE_UR | PTE_UW | PTE_UX)

#ifdef __riscv

#ifdef __riscv64
# define RISCV_PGLEVELS 3
# define RISCV_PGSHIFT 13
#else
# define RISCV_PGLEVELS 2
# define RISCV_PGSHIFT 12
#endif
#define RISCV_PGLEVEL_BITS 10
#define RISCV_PGSIZE (1 << RISCV_PGSHIFT)

#ifndef __ASSEMBLER__

#define read_csr(reg) ({ long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) \
  asm volatile ("csrw " #reg ", %0" :: "r"(val))

#define swap_csr(reg, val) ({ long __tmp; \
  asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "r"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ long __tmp; \
  if (__builtin_constant_p(bit) && (bit) < 32) \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ long __tmp; \
  if (__builtin_constant_p(bit) && (bit) < 32) \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })

#define rdtime() ({ unsigned long __tmp; \
  asm volatile ("rdtime %0" : "=r"(__tmp)); \
  __tmp; })

#define rdcycle() ({ unsigned long __tmp; \
  asm volatile ("rdcycle %0" : "=r"(__tmp)); \
  __tmp; })

#define rdinstret() ({ unsigned long __tmp; \
  asm volatile ("rdinstret %0" : "=r"(__tmp)); \
  __tmp; })

#endif

#endif

#endif
/* Automatically generated by parse-opcodes */
#ifndef RISCV_ENCODING_H
#define RISCV_ENCODING_H
#define MATCH_FMV_S_X 0xf0000053
#define MASK_FMV_S_X  0xfff0707f
#define MATCH_SUBW 0x4000003b
#define MASK_SUBW  0xfe00707f
#define MATCH_REMUW 0x200703b
#define MASK_REMUW  0xfe00707f
#define MATCH_FMIN_D 0x2a000053
#define MASK_FMIN_D  0xfe00707f
#define MATCH_AMOMAX_D 0xa000302f
#define MASK_AMOMAX_D  0xf800707f
#define MATCH_BLTU 0x6063
#define MASK_BLTU  0x707f
#define MATCH_FSGNJN_D 0x22001053
#define MASK_FSGNJN_D  0xfe00707f
#define MATCH_FMIN_S 0x28000053
#define MASK_FMIN_S  0xfe00707f
#define MATCH_CSRRW 0x1073
#define MASK_CSRRW  0x707f
#define MATCH_SLLIW 0x101b
#define MASK_SLLIW  0xfe00707f
#define MATCH_LB 0x3
#define MASK_LB  0x707f
#define MATCH_FMAX_S 0x28001053
#define MASK_FMAX_S  0xfe00707f
#define MATCH_LH 0x1003
#define MASK_LH  0x707f
#define MATCH_FCVT_D_W 0xd2000053
#define MASK_FCVT_D_W  0xfff0007f
#define MATCH_LW 0x2003
#define MASK_LW  0x707f
#define MATCH_ADD 0x33
#define MASK_ADD  0xfe00707f
#define MATCH_CSRRC 0x3073
#define MASK_CSRRC  0x707f
#define MATCH_FMAX_D 0x2a001053
#define MASK_FMAX_D  0xfe00707f
#define MATCH_BNE 0x1063
#define MASK_BNE  0x707f
#define MATCH_FCVT_S_D 0x40100053
#define MASK_FCVT_S_D  0xfff0007f
#define MATCH_BGEU 0x7063
#define MASK_BGEU  0x707f
#define MATCH_FADD_D 0x2000053
#define MASK_FADD_D  0xfe00007f
#define MATCH_SLTIU 0x3013
#define MASK_SLTIU  0x707f
#define MATCH_FADD_S 0x53
#define MASK_FADD_S  0xfe00007f
#define MATCH_FCLASS_D 0xe2001053
#define MASK_FCLASS_D  0xfff0707f
#define MATCH_FCVT_S_W 0xd0000053
#define MASK_FCVT_S_W  0xfff0007f
#define MATCH_MUL 0x2000033
#define MASK_MUL  0xfe00707f
#define MATCH_AMOMINU_D 0xc000302f
#define MASK_AMOMINU_D  0xf800707f
#define MATCH_FCVT_S_LU 0xd0300053
#define MASK_FCVT_S_LU  0xfff0007f
#define MATCH_SRLI 0x5013
#define MASK_SRLI  0xfc00707f
#define MATCH_AMOMINU_W 0xc000202f
#define MASK_AMOMINU_W  0xf800707f
#define MATCH_DIVUW 0x200503b
#define MASK_DIVUW  0xfe00707f
#define MATCH_MULW 0x200003b
#define MASK_MULW  0xfe00707f
#define MATCH_SRLW 0x503b
#define MASK_SRLW  0xfe00707f
#define MATCH_DIV 0x2004033
#define MASK_DIV  0xfe00707f
#define MATCH_FDIV_D 0x1a000053
#define MASK_FDIV_D  0xfe00007f
#define MATCH_SETTAG 0x6b
#define MASK_SETTAG  0x7f
#define MATCH_FENCE 0xf
#define MASK_FENCE  0x707f
#define MATCH_FNMSUB_S 0x4b
#define MASK_FNMSUB_S  0x600007f
#define MATCH_FCVT_L_S 0xc0200053
#define MASK_FCVT_L_S  0xfff0007f
#define MATCH_SBREAK 0x100073
#define MASK_SBREAK  0xffffffff
#define MATCH_FLE_S 0xa0000053
#define MASK_FLE_S  0xfe00707f
#define MATCH_FDIV_S 0x18000053
#define MASK_FDIV_S  0xfe00007f
#define MATCH_FLE_D 0xa2000053
#define MASK_FLE_D  0xfe00707f
#define MATCH_FENCE_I 0x100f
#define MASK_FENCE_I  0x707f
#define MATCH_FNMSUB_D 0x200004b
#define MASK_FNMSUB_D  0x600007f
#define MATCH_ADDW 0x3b
#define MASK_ADDW  0xfe00707f
#define MATCH_SLL 0x1033
#define MASK_SLL  0xfe00707f
#define MATCH_XOR 0x4033
#define MASK_XOR  0xfe00707f
#define MATCH_JALR 0x67
#define MASK_JALR  0x707f
#define MATCH_BLT 0x4063
#define MASK_BLT  0x707f
#define MATCH_SCALL 0x73
#define MASK_SCALL  0xffffffff
#define MATCH_FCLASS_S 0xe0001053
#define MASK_FCLASS_S  0xfff0707f
#define MATCH_SC_W 0x1800202f
#define MASK_SC_W  0xf800707f
#define MATCH_REM 0x2006033
#define MASK_REM  0xfe00707f
#define MATCH_SRLIW 0x501b
#define MASK_SRLIW  0xfe00707f
#define MATCH_LUI 0x37
#define MASK_LUI  0x7f
#define MATCH_CSRRCI 0x7073
#define MASK_CSRRCI  0x707f
#define MATCH_ADDI 0x13
#define MASK_ADDI  0x707f
#define MATCH_MULH 0x2001033
#define MASK_MULH  0xfe00707f
#define MATCH_FMUL_S 0x10000053
#define MASK_FMUL_S  0xfe00007f
#define MATCH_CSRRSI 0x6073
#define MASK_CSRRSI  0x707f
#define MATCH_SRAI 0x40005013
#define MASK_SRAI  0xfc00707f
#define MATCH_AMOAND_D 0x6000302f
#define MASK_AMOAND_D  0xf800707f
#define MATCH_FLT_D 0xa2001053
#define MASK_FLT_D  0xfe00707f
#define MATCH_SRAW 0x4000503b
#define MASK_SRAW  0xfe00707f
#define MATCH_FMUL_D 0x12000053
#define MASK_FMUL_D  0xfe00007f
#define MATCH_LD 0x3003
#define MASK_LD  0x707f
#define MATCH_ORI 0x6013
#define MASK_ORI  0x707f
#define MATCH_CSRRS 0x2073
#define MASK_CSRRS  0x707f
#define MATCH_FLT_S 0xa0001053
#define MASK_FLT_S  0xfe00707f
#define MATCH_ADDIW 0x1b
#define MASK_ADDIW  0x707f
#define MATCH_AMOAND_W 0x6000202f
#define MASK_AMOAND_W  0xf800707f
#define MATCH_FEQ_S 0xa0002053
#define MASK_FEQ_S  0xfe00707f
#define MATCH_FSGNJX_D 0x22002053
#define MASK_FSGNJX_D  0xfe00707f
#define MATCH_SRA 0x40005033
#define MASK_SRA  0xfe00707f
#define MATCH_BGE 0x5063
#define MASK_BGE  0x707f
#define MATCH_SRAIW 0x4000501b
#define MASK_SRAIW  0xfe00707f
#define MATCH_SRL 0x5033
#define MASK_SRL  0xfe00707f
#define MATCH_FSUB_D 0xa000053
#define MASK_FSUB_D  0xfe00007f
#define MATCH_FSGNJX_S 0x20002053
#define MASK_FSGNJX_S  0xfe00707f
#define MATCH_FEQ_D 0xa2002053
#define MASK_FEQ_D  0xfe00707f
#define MATCH_FCVT_D_WU 0xd2100053
#define MASK_FCVT_D_WU  0xfff0007f
#define MATCH_OR 0x6033
#define MASK_OR  0xfe00707f
#define MATCH_FCVT_WU_D 0xc2100053
#define MASK_FCVT_WU_D  0xfff0007f
#define MATCH_AND 0x7033
#define MASK_AND  0xfe00707f
#define MATCH_FCVT_D_L 0xd2200053
#define MASK_FCVT_D_L  0xfff0007f
#define MATCH_AMOMAXU_D 0xe000302f
#define MASK_AMOMAXU_D  0xf800707f
#define MATCH_XORI 0x4013
#define MASK_XORI  0x707f
#define MATCH_AMOXOR_D 0x2000302f
#define MASK_AMOXOR_D  0xf800707f
#define MATCH_AMOMAXU_W 0xe000202f
#define MASK_AMOMAXU_W  0xf800707f
#define MATCH_FCVT_WU_S 0xc0100053
#define MASK_FCVT_WU_S  0xfff0007f
#define MATCH_ANDI 0x7013
#define MASK_ANDI  0x707f
#define MATCH_FMV_X_S 0xe0000053
#define MASK_FMV_X_S  0xfff0707f
#define MATCH_SRET 0x80000073
#define MASK_SRET  0xffffffff
#define MATCH_FNMADD_S 0x4f
#define MASK_FNMADD_S  0x600007f
#define MATCH_JAL 0x6f
#define MASK_JAL  0x7f
#define MATCH_LWU 0x6003
#define MASK_LWU  0x707f
#define MATCH_FMV_X_D 0xe2000053
#define MASK_FMV_X_D  0xfff0707f
#define MATCH_FCVT_D_S 0x42000053
#define MASK_FCVT_D_S  0xfff0007f
#define MATCH_FNMADD_D 0x200004f
#define MASK_FNMADD_D  0x600007f
#define MATCH_AMOADD_D 0x302f
#define MASK_AMOADD_D  0xf800707f
#define MATCH_AMOMAX_W 0xa000202f
#define MASK_AMOMAX_W  0xf800707f
#define MATCH_FCVT_W_S 0xc0000053
#define MASK_FCVT_W_S  0xfff0007f
#define MATCH_MULHSU 0x2002033
#define MASK_MULHSU  0xfe00707f
#define MATCH_AMOADD_W 0x202f
#define MASK_AMOADD_W  0xf800707f
#define MATCH_FCVT_D_LU 0xd2300053
#define MASK_FCVT_D_LU  0xfff0007f
#define MATCH_LR_W 0x1000202f
#define MASK_LR_W  0xf9f0707f
#define MATCH_FCVT_W_D 0xc2000053
#define MASK_FCVT_W_D  0xfff0007f
#define MATCH_SLT 0x2033
#define MASK_SLT  0xfe00707f
#define MATCH_SLLW 0x103b
#define MASK_SLLW  0xfe00707f
#define MATCH_AMOOR_D 0x4000302f
#define MASK_AMOOR_D  0xf800707f
#define MATCH_SLTI 0x2013
#define MASK_SLTI  0x707f
#define MATCH_REMU 0x2007033
#define MASK_REMU  0xfe00707f
#define MATCH_FLW 0x2007
#define MASK_FLW  0x707f
#define MATCH_REMW 0x200603b
#define MASK_REMW  0xfe00707f
#define MATCH_SLTU 0x3033
#define MASK_SLTU  0xfe00707f
#define MATCH_SLLI 0x1013
#define MASK_SLLI  0xfc00707f
#define MATCH_AMOOR_W 0x4000202f
#define MASK_AMOOR_W  0xf800707f
#define MATCH_BEQ 0x63
#define MASK_BEQ  0x707f
#define MATCH_FLD 0x3007
#define MASK_FLD  0x707f
#define MATCH_FSUB_S 0x8000053
#define MASK_FSUB_S  0xfe00007f
#define MATCH_TAGENFORCE 0xb
#define MASK_TAGENFORCE  0x7f
#define MATCH_FMV_D_X 0xf2000053
#define MASK_FMV_D_X  0xfff0707f
#define MATCH_LBU 0x4003
#define MASK_LBU  0x707f
#define MATCH_FSGNJ_S 0x20000053
#define MASK_FSGNJ_S  0xfe00707f
#define MATCH_AMOXOR_W 0x2000202f
#define MASK_AMOXOR_W  0xf800707f
#define MATCH_LR_D 0x1000302f
#define MASK_LR_D  0xf9f0707f
#define MATCH_FSGNJ_D 0x22000053
#define MASK_FSGNJ_D  0xfe00707f
#define MATCH_MULHU 0x2003033
#define MASK_MULHU  0xfe00707f
#define MATCH_FCVT_L_D 0xc2200053
#define MASK_FCVT_L_D  0xfff0007f
#define MATCH_FCVT_S_WU 0xd0100053
#define MASK_FCVT_S_WU  0xfff0007f
#define MATCH_FCVT_LU_S 0xc0300053
#define MASK_FCVT_LU_S  0xfff0007f
#define MATCH_FCVT_S_L 0xd0200053
#define MASK_FCVT_S_L  0xfff0007f
#define MATCH_AUIPC 0x17
#define MASK_AUIPC  0x7f
#define MATCH_FCVT_LU_D 0xc2300053
#define MASK_FCVT_LU_D  0xfff0007f
#define MATCH_CSRRWI 0x5073
#define MASK_CSRRWI  0x707f
#define MATCH_SC_D 0x1800302f
#define MASK_SC_D  0xf800707f
#define MATCH_FMADD_S 0x43
#define MASK_FMADD_S  0x600007f
#define MATCH_FSQRT_S 0x58000053
#define MASK_FSQRT_S  0xfff0007f
#define MATCH_AMOMIN_W 0x8000202f
#define MASK_AMOMIN_W  0xf800707f
#define MATCH_FSGNJN_S 0x20001053
#define MASK_FSGNJN_S  0xfe00707f
#define MATCH_AMOSWAP_D 0x800302f
#define MASK_AMOSWAP_D  0xf800707f
#define MATCH_FSQRT_D 0x5a000053
#define MASK_FSQRT_D  0xfff0007f
#define MATCH_FMADD_D 0x2000043
#define MASK_FMADD_D  0x600007f
#define MATCH_DIVW 0x200403b
#define MASK_DIVW  0xfe00707f
#define MATCH_AMOMIN_D 0x8000302f
#define MASK_AMOMIN_D  0xf800707f
#define MATCH_DIVU 0x2005033
#define MASK_DIVU  0xfe00707f
#define MATCH_AMOSWAP_W 0x800202f
#define MASK_AMOSWAP_W  0xf800707f
#define MATCH_SUB 0x40000033
#define MASK_SUB  0xfe00707f
#define MATCH_FSD 0x3027
#define MASK_FSD  0x707f
#define MATCH_SW 0x2023
#define MASK_SW  0x707f
#define MATCH_FMSUB_S 0x47
#define MASK_FMSUB_S  0x600007f
#define MATCH_LHU 0x5003
#define MASK_LHU  0x707f
#define MATCH_SH 0x1023
#define MASK_SH  0x707f
#define MATCH_FSW 0x2027
#define MASK_FSW  0x707f
#define MATCH_SB 0x23
#define MASK_SB  0x707f
#define MATCH_FMSUB_D 0x2000047
#define MASK_FMSUB_D  0x600007f
#define MATCH_SD 0x3023
#define MASK_SD  0x707f
#define CSR_FFLAGS 0x1
#define CSR_FRM 0x2
#define CSR_FCSR 0x3
#define CSR_STATS 0xc0
#define CSR_SUP0 0x500
#define CSR_SUP1 0x501
#define CSR_EPC 0x502
#define CSR_BADVADDR 0x503
#define CSR_PTBR 0x504
#define CSR_ASID 0x505
#define CSR_COUNT 0x506
#define CSR_COMPARE 0x507
#define CSR_EVEC 0x508
#define CSR_CAUSE 0x509
#define CSR_STATUS 0x50a
#define CSR_HARTID 0x50b
#define CSR_IMPL 0x50c
#define CSR_FATC 0x50d
#define CSR_SEND_IPI 0x50e
#define CSR_CLEAR_IPI 0x50f
#define CSR_RESET 0x51d
#define CSR_TOHOST 0x51e
#define CSR_FROMHOST 0x51f
#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02
#define CSR_UARCH0 0xcc0
#define CSR_UARCH1 0xcc1
#define CSR_UARCH2 0xcc2
#define CSR_UARCH3 0xcc3
#define CSR_UARCH4 0xcc4
#define CSR_UARCH5 0xcc5
#define CSR_UARCH6 0xcc6
#define CSR_UARCH7 0xcc7
#define CSR_UARCH8 0xcc8
#define CSR_UARCH9 0xcc9
#define CSR_UARCH10 0xcca
#define CSR_UARCH11 0xccb
#define CSR_UARCH12 0xccc
#define CSR_UARCH13 0xccd
#define CSR_UARCH14 0xcce
#define CSR_UARCH15 0xccf
#define CSR_COUNTH 0x586
#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82
#define CAUSE_MISALIGNED_FETCH 0x0
#define CAUSE_FAULT_FETCH 0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_PRIVILEGED_INSTRUCTION 0x3
#define CAUSE_FP_DISABLED 0x4
#define CAUSE_SYSCALL 0x6
#define CAUSE_BREAKPOINT 0x7
#define CAUSE_MISALIGNED_LOAD 0x8
#define CAUSE_MISALIGNED_STORE 0x9
#define CAUSE_FAULT_LOAD 0xa
#define CAUSE_FAULT_STORE 0xb
#define CAUSE_ACCELERATOR_DISABLED 0xc
#define CAUSE_TAG_VIOLATION 0xd
#endif
#ifdef DECLARE_INSN
DECLARE_INSN(fmv_s_x, MATCH_FMV_S_X, MASK_FMV_S_X)
DECLARE_INSN(subw, MATCH_SUBW, MASK_SUBW)
DECLARE_INSN(remuw, MATCH_REMUW, MASK_REMUW)
DECLARE_INSN(fmin_d, MATCH_FMIN_D, MASK_FMIN_D)
DECLARE_INSN(amomax_d, MATCH_AMOMAX_D, MASK_AMOMAX_D)
DECLARE_INSN(bltu, MATCH_BLTU, MASK_BLTU)
DECLARE_INSN(fsgnjn_d, MATCH_FSGNJN_D, MASK_FSGNJN_D)
DECLARE_INSN(fmin_s, MATCH_FMIN_S, MASK_FMIN_S)
DECLARE_INSN(csrrw, MATCH_CSRRW, MASK_CSRRW)
DECLARE_INSN(slliw, MATCH_SLLIW, MASK_SLLIW)
DECLARE_INSN(lb, MATCH_LB, MASK_LB)
DECLARE_INSN(fmax_s, MATCH_FMAX_S, MASK_FMAX_S)
DECLARE_INSN(lh, MATCH_LH, MASK_LH)
DECLARE_INSN(fcvt_d_w, MATCH_FCVT_D_W, MASK_FCVT_D_W)
DECLARE_INSN(lw, MATCH_LW, MASK_LW)
DECLARE_INSN(add, MATCH_ADD, MASK_ADD)
DECLARE_INSN(csrrc, MATCH_CSRRC, MASK_CSRRC)
DECLARE_INSN(fmax_d, MATCH_FMAX_D, MASK_FMAX_D)
DECLARE_INSN(bne, MATCH_BNE, MASK_BNE)
DECLARE_INSN(fcvt_s_d, MATCH_FCVT_S_D, MASK_FCVT_S_D)
DECLARE_INSN(bgeu, MATCH_BGEU, MASK_BGEU)
DECLARE_INSN(fadd_d, MATCH_FADD_D, MASK_FADD_D)
DECLARE_INSN(sltiu, MATCH_SLTIU, MASK_SLTIU)
DECLARE_INSN(fadd_s, MATCH_FADD_S, MASK_FADD_S)
DECLARE_INSN(fclass_d, MATCH_FCLASS_D, MASK_FCLASS_D)
DECLARE_INSN(fcvt_s_w, MATCH_FCVT_S_W, MASK_FCVT_S_W)
DECLARE_INSN(mul, MATCH_MUL, MASK_MUL)
DECLARE_INSN(amominu_d, MATCH_AMOMINU_D, MASK_AMOMINU_D)
DECLARE_INSN(fcvt_s_lu, MATCH_FCVT_S_LU, MASK_FCVT_S_LU)
DECLARE_INSN(srli, MATCH_SRLI, MASK_SRLI)
DECLARE_INSN(amominu_w, MATCH_AMOMINU_W, MASK_AMOMINU_W)
DECLARE_INSN(divuw, MATCH_DIVUW, MASK_DIVUW)
DECLARE_INSN(mulw, MATCH_MULW, MASK_MULW)
DECLARE_INSN(srlw, MATCH_SRLW, MASK_SRLW)
DECLARE_INSN(div, MATCH_DIV, MASK_DIV)
DECLARE_INSN(fdiv_d, MATCH_FDIV_D, MASK_FDIV_D)
DECLARE_INSN(settag, MATCH_SETTAG, MASK_SETTAG)
DECLARE_INSN(fence, MATCH_FENCE, MASK_FENCE)
DECLARE_INSN(fnmsub_s, MATCH_FNMSUB_S, MASK_FNMSUB_S)
DECLARE_INSN(fcvt_l_s, MATCH_FCVT_L_S, MASK_FCVT_L_S)
DECLARE_INSN(sbreak, MATCH_SBREAK, MASK_SBREAK)
DECLARE_INSN(fle_s, MATCH_FLE_S, MASK_FLE_S)
DECLARE_INSN(fdiv_s, MATCH_FDIV_S, MASK_FDIV_S)
DECLARE_INSN(fle_d, MATCH_FLE_D, MASK_FLE_D)
DECLARE_INSN(fence_i, MATCH_FENCE_I, MASK_FENCE_I)
DECLARE_INSN(fnmsub_d, MATCH_FNMSUB_D, MASK_FNMSUB_D)
DECLARE_INSN(addw, MATCH_ADDW, MASK_ADDW)
DECLARE_INSN(sll, MATCH_SLL, MASK_SLL)
DECLARE_INSN(xor, MATCH_XOR, MASK_XOR)
DECLARE_INSN(jalr, MATCH_JALR, MASK_JALR)
DECLARE_INSN(blt, MATCH_BLT, MASK_BLT)
DECLARE_INSN(scall, MATCH_SCALL, MASK_SCALL)
DECLARE_INSN(fclass_s, MATCH_FCLASS_S, MASK_FCLASS_S)
DECLARE_INSN(sc_w, MATCH_SC_W, MASK_SC_W)
DECLARE_INSN(rem, MATCH_REM, MASK_REM)
DECLARE_INSN(srliw, MATCH_SRLIW, MASK_SRLIW)
DECLARE_INSN(lui, MATCH_LUI, MASK_LUI)
DECLARE_INSN(csrrci, MATCH_CSRRCI, MASK_CSRRCI)
DECLARE_INSN(addi, MATCH_ADDI, MASK_ADDI)
DECLARE_INSN(mulh, MATCH_MULH, MASK_MULH)
DECLARE_INSN(fmul_s, MATCH_FMUL_S, MASK_FMUL_S)
DECLARE_INSN(csrrsi, MATCH_CSRRSI, MASK_CSRRSI)
DECLARE_INSN(srai, MATCH_SRAI, MASK_SRAI)
DECLARE_INSN(amoand_d, MATCH_AMOAND_D, MASK_AMOAND_D)
DECLARE_INSN(flt_d, MATCH_FLT_D, MASK_FLT_D)
DECLARE_INSN(sraw, MATCH_SRAW, MASK_SRAW)
DECLARE_INSN(fmul_d, MATCH_FMUL_D, MASK_FMUL_D)
DECLARE_INSN(ld, MATCH_LD, MASK_LD)
DECLARE_INSN(ori, MATCH_ORI, MASK_ORI)
DECLARE_INSN(csrrs, MATCH_CSRRS, MASK_CSRRS)
DECLARE_INSN(flt_s, MATCH_FLT_S, MASK_FLT_S)
DECLARE_INSN(addiw, MATCH_ADDIW, MASK_ADDIW)
DECLARE_INSN(amoand_w, MATCH_AMOAND_W, MASK_AMOAND_W)
DECLARE_INSN(feq_s, MATCH_FEQ_S, MASK_FEQ_S)
DECLARE_INSN(fsgnjx_d, MATCH_FSGNJX_D, MASK_FSGNJX_D)
DECLARE_INSN(sra, MATCH_SRA, MASK_SRA)
DECLARE_INSN(bge, MATCH_BGE, MASK_BGE)
DECLARE_INSN(sraiw, MATCH_SRAIW, MASK_SRAIW)
DECLARE_INSN(srl, MATCH_SRL, MASK_SRL)
DECLARE_INSN(fsub_d, MATCH_FSUB_D, MASK_FSUB_D)
DECLARE_INSN(fsgnjx_s, MATCH_FSGNJX_S, MASK_FSGNJX_S)
DECLARE_INSN(feq_d, MATCH_FEQ_D, MASK_FEQ_D)
DECLARE_INSN(fcvt_d_wu, MATCH_FCVT_D_WU, MASK_FCVT_D_WU)
DECLARE_INSN(or, MATCH_OR, MASK_OR)
DECLARE_INSN(fcvt_wu_d, MATCH_FCVT_WU_D, MASK_FCVT_WU_D)
DECLARE_INSN(and, MATCH_AND, MASK_AND)
DECLARE_INSN(fcvt_d_l, MATCH_FCVT_D_L, MASK_FCVT_D_L)
DECLARE_INSN(amomaxu_d, MATCH_AMOMAXU_D, MASK_AMOMAXU_D)
DECLARE_INSN(xori, MATCH_XORI, MASK_XORI)
DECLARE_INSN(amoxor_d, MATCH_AMOXOR_D, MASK_AMOXOR_D)
DECLARE_INSN(amomaxu_w, MATCH_AMOMAXU_W, MASK_AMOMAXU_W)
DECLARE_INSN(fcvt_wu_s, MATCH_FCVT_WU_S, MASK_FCVT_WU_S)
DECLARE_INSN(andi, MATCH_ANDI, MASK_ANDI)
DECLARE_INSN(fmv_x_s, MATCH_FMV_X_S, MASK_FMV_X_S)
DECLARE_INSN(sret, MATCH_SRET, MASK_SRET)
DECLARE_INSN(fnmadd_s, MATCH_FNMADD_S, MASK_FNMADD_S)
DECLARE_INSN(jal, MATCH_JAL, MASK_JAL)
DECLARE_INSN(lwu, MATCH_LWU, MASK_LWU)
DECLARE_INSN(fmv_x_d, MATCH_FMV_X_D, MASK_FMV_X_D)
DECLARE_INSN(fcvt_d_s, MATCH_FCVT_D_S, MASK_FCVT_D_S)
DECLARE_INSN(fnmadd_d, MATCH_FNMADD_D, MASK_FNMADD_D)
DECLARE_INSN(amoadd_d, MATCH_AMOADD_D, MASK_AMOADD_D)
DECLARE_INSN(amomax_w, MATCH_AMOMAX_W, MASK_AMOMAX_W)
DECLARE_INSN(fcvt_w_s, MATCH_FCVT_W_S, MASK_FCVT_W_S)
DECLARE_INSN(mulhsu, MATCH_MULHSU, MASK_MULHSU)
DECLARE_INSN(amoadd_w, MATCH_AMOADD_W, MASK_AMOADD_W)
DECLARE_INSN(fcvt_d_lu, MATCH_FCVT_D_LU, MASK_FCVT_D_LU)
DECLARE_INSN(lr_w, MATCH_LR_W, MASK_LR_W)
DECLARE_INSN(fcvt_w_d, MATCH_FCVT_W_D, MASK_FCVT_W_D)
DECLARE_INSN(slt, MATCH_SLT, MASK_SLT)
DECLARE_INSN(sllw, MATCH_SLLW, MASK_SLLW)
DECLARE_INSN(amoor_d, MATCH_AMOOR_D, MASK_AMOOR_D)
DECLARE_INSN(slti, MATCH_SLTI, MASK_SLTI)
DECLARE_INSN(remu, MATCH_REMU, MASK_REMU)
DECLARE_INSN(flw, MATCH_FLW, MASK_FLW)
DECLARE_INSN(remw, MATCH_REMW, MASK_REMW)
DECLARE_INSN(sltu, MATCH_SLTU, MASK_SLTU)
DECLARE_INSN(slli, MATCH_SLLI, MASK_SLLI)
DECLARE_INSN(amoor_w, MATCH_AMOOR_W, MASK_AMOOR_W)
DECLARE_INSN(beq, MATCH_BEQ, MASK_BEQ)
DECLARE_INSN(fld, MATCH_FLD, MASK_FLD)
DECLARE_INSN(fsub_s, MATCH_FSUB_S, MASK_FSUB_S)
DECLARE_INSN(tagenforce, MATCH_TAGENFORCE, MASK_TAGENFORCE)
DECLARE_INSN(fmv_d_x, MATCH_FMV_D_X, MASK_FMV_D_X)
DECLARE_INSN(lbu, MATCH_LBU, MASK_LBU)
DECLARE_INSN(fsgnj_s, MATCH_FSGNJ_S, MASK_FSGNJ_S)
DECLARE_INSN(amoxor_w, MATCH_AMOXOR_W, MASK_AMOXOR_W)
DECLARE_INSN(lr_d, MATCH_LR_D, MASK_LR_D)
DECLARE_INSN(fsgnj_d, MATCH_FSGNJ_D, MASK_FSGNJ_D)
DECLARE_INSN(mulhu, MATCH_MULHU, MASK_MULHU)
DECLARE_INSN(fcvt_l_d, MATCH_FCVT_L_D, MASK_FCVT_L_D)
DECLARE_INSN(fcvt_s_wu, MATCH_FCVT_S_WU, MASK_FCVT_S_WU)
DECLARE_INSN(fcvt_lu_s, MATCH_FCVT_LU_S, MASK_FCVT_LU_S)
DECLARE_INSN(fcvt_s_l, MATCH_FCVT_S_L, MASK_FCVT_S_L)
DECLARE_INSN(auipc, MATCH_AUIPC, MASK_AUIPC)
DECLARE_INSN(fcvt_lu_d, MATCH_FCVT_LU_D, MASK_FCVT_LU_D)
DECLARE_INSN(csrrwi, MATCH_CSRRWI, MASK_CSRRWI)
DECLARE_INSN(sc_d, MATCH_SC_D, MASK_SC_D)
DECLARE_INSN(fmadd_s, MATCH_FMADD_S, MASK_FMADD_S)
DECLARE_INSN(fsqrt_s, MATCH_FSQRT_S, MASK_FSQRT_S)
DECLARE_INSN(amomin_w, MATCH_AMOMIN_W, MASK_AMOMIN_W)
DECLARE_INSN(fsgnjn_s, MATCH_FSGNJN_S, MASK_FSGNJN_S)
DECLARE_INSN(amoswap_d, MATCH_AMOSWAP_D, MASK_AMOSWAP_D)
DECLARE_INSN(fsqrt_d, MATCH_FSQRT_D, MASK_FSQRT_D)
DECLARE_INSN(fmadd_d, MATCH_FMADD_D, MASK_FMADD_D)
DECLARE_INSN(divw, MATCH_DIVW, MASK_DIVW)
DECLARE_INSN(amomin_d, MATCH_AMOMIN_D, MASK_AMOMIN_D)
DECLARE_INSN(divu, MATCH_DIVU, MASK_DIVU)
DECLARE_INSN(amoswap_w, MATCH_AMOSWAP_W, MASK_AMOSWAP_W)
DECLARE_INSN(sub, MATCH_SUB, MASK_SUB)
DECLARE_INSN(fsd, MATCH_FSD, MASK_FSD)
DECLARE_INSN(sw, MATCH_SW, MASK_SW)
DECLARE_INSN(fmsub_s, MATCH_FMSUB_S, MASK_FMSUB_S)
DECLARE_INSN(lhu, MATCH_LHU, MASK_LHU)
DECLARE_INSN(sh, MATCH_SH, MASK_SH)
DECLARE_INSN(fsw, MATCH_FSW, MASK_FSW)
DECLARE_INSN(sb, MATCH_SB, MASK_SB)
DECLARE_INSN(fmsub_d, MATCH_FMSUB_D, MASK_FMSUB_D)
DECLARE_INSN(sd, MATCH_SD, MASK_SD)
#endif
#ifdef DECLARE_CSR
DECLARE_CSR(fflags, CSR_FFLAGS)
DECLARE_CSR(frm, CSR_FRM)
DECLARE_CSR(fcsr, CSR_FCSR)
DECLARE_CSR(stats, CSR_STATS)
DECLARE_CSR(sup0, CSR_SUP0)
DECLARE_CSR(sup1, CSR_SUP1)
DECLARE_CSR(epc, CSR_EPC)
DECLARE_CSR(badvaddr, CSR_BADVADDR)
DECLARE_CSR(ptbr, CSR_PTBR)
DECLARE_CSR(asid, CSR_ASID)
DECLARE_CSR(count, CSR_COUNT)
DECLARE_CSR(compare, CSR_COMPARE)
DECLARE_CSR(evec, CSR_EVEC)
DECLARE_CSR(cause, CSR_CAUSE)
DECLARE_CSR(status, CSR_STATUS)
DECLARE_CSR(hartid, CSR_HARTID)
DECLARE_CSR(impl, CSR_IMPL)
DECLARE_CSR(fatc, CSR_FATC)
DECLARE_CSR(send_ipi, CSR_SEND_IPI)
DECLARE_CSR(clear_ipi, CSR_CLEAR_IPI)
DECLARE_CSR(reset, CSR_RESET)
DECLARE_CSR(tohost, CSR_TOHOST)
DECLARE_CSR(fromhost, CSR_FROMHOST)
DECLARE_CSR(cycle, CSR_CYCLE)
DECLARE_CSR(time, CSR_TIME)
DECLARE_CSR(instret, CSR_INSTRET)
DECLARE_CSR(uarch0, CSR_UARCH0)
DECLARE_CSR(uarch1, CSR_UARCH1)
DECLARE_CSR(uarch2, CSR_UARCH2)
DECLARE_CSR(uarch3, CSR_UARCH3)
DECLARE_CSR(uarch4, CSR_UARCH4)
DECLARE_CSR(uarch5, CSR_UARCH5)
DECLARE_CSR(uarch6, CSR_UARCH6)
DECLARE_CSR(uarch7, CSR_UARCH7)
DECLARE_CSR(uarch8, CSR_UARCH8)
DECLARE_CSR(uarch9, CSR_UARCH9)
DECLARE_CSR(uarch10, CSR_UARCH10)
DECLARE_CSR(uarch11, CSR_UARCH11)
DECLARE_CSR(uarch12, CSR_UARCH12)
DECLARE_CSR(uarch13, CSR_UARCH13)
DECLARE_CSR(uarch14, CSR_UARCH14)
DECLARE_CSR(uarch15, CSR_UARCH15)
DECLARE_CSR(counth, CSR_COUNTH)
DECLARE_CSR(cycleh, CSR_CYCLEH)
DECLARE_CSR(timeh, CSR_TIMEH)
DECLARE_CSR(instreth, CSR_INSTRETH)
#endif
#ifdef DECLARE_CAUSE
DECLARE_CAUSE("fflags", CAUSE_FFLAGS)
DECLARE_CAUSE("frm", CAUSE_FRM)
DECLARE_CAUSE("fcsr", CAUSE_FCSR)
DECLARE_CAUSE("stats", CAUSE_STATS)
DECLARE_CAUSE("sup0", CAUSE_SUP0)
DECLARE_CAUSE("sup1", CAUSE_SUP1)
DECLARE_CAUSE("epc", CAUSE_EPC)
DECLARE_CAUSE("badvaddr", CAUSE_BADVADDR)
DECLARE_CAUSE("ptbr", CAUSE_PTBR)
DECLARE_CAUSE("asid", CAUSE_ASID)
DECLARE_CAUSE("count", CAUSE_COUNT)
DECLARE_CAUSE("compare", CAUSE_COMPARE)
DECLARE_CAUSE("evec", CAUSE_EVEC)
DECLARE_CAUSE("cause", CAUSE_CAUSE)
DECLARE_CAUSE("status", CAUSE_STATUS)
DECLARE_CAUSE("hartid", CAUSE_HARTID)
DECLARE_CAUSE("impl", CAUSE_IMPL)
DECLARE_CAUSE("fatc", CAUSE_FATC)
DECLARE_CAUSE("send_ipi", CAUSE_SEND_IPI)
DECLARE_CAUSE("clear_ipi", CAUSE_CLEAR_IPI)
DECLARE_CAUSE("reset", CAUSE_RESET)
DECLARE_CAUSE("tohost", CAUSE_TOHOST)
DECLARE_CAUSE("fromhost", CAUSE_FROMHOST)
DECLARE_CAUSE("cycle", CAUSE_CYCLE)
DECLARE_CAUSE("time", CAUSE_TIME)
DECLARE_CAUSE("instret", CAUSE_INSTRET)
DECLARE_CAUSE("uarch0", CAUSE_UARCH0)
DECLARE_CAUSE("uarch1", CAUSE_UARCH1)
DECLARE_CAUSE("uarch2", CAUSE_UARCH2)
DECLARE_CAUSE("uarch3", CAUSE_UARCH3)
DECLARE_CAUSE("uarch4", CAUSE_UARCH4)
DECLARE_CAUSE("uarch5", CAUSE_UARCH5)
DECLARE_CAUSE("uarch6", CAUSE_UARCH6)
DECLARE_CAUSE("uarch7", CAUSE_UARCH7)
DECLARE_CAUSE("uarch8", CAUSE_UARCH8)
DECLARE_CAUSE("uarch9", CAUSE_UARCH9)
DECLARE_CAUSE("uarch10", CAUSE_UARCH10)
DECLARE_CAUSE("uarch11", CAUSE_UARCH11)
DECLARE_CAUSE("uarch12", CAUSE_UARCH12)
DECLARE_CAUSE("uarch13", CAUSE_UARCH13)
DECLARE_CAUSE("uarch14", CAUSE_UARCH14)
DECLARE_CAUSE("uarch15", CAUSE_UARCH15)
DECLARE_CAUSE("counth", CAUSE_COUNTH)
DECLARE_CAUSE("cycleh", CAUSE_CYCLEH)
DECLARE_CAUSE("timeh", CAUSE_TIMEH)
DECLARE_CAUSE("instreth", CAUSE_INSTRETH)
#endif
