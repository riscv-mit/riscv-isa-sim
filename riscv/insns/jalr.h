reg_t tmp = npc;
// check the tag on the jump target to make sure it is ok to execute
// but only if RS1 is ra, the conventional return pointer register
if ((1 || TAG_ENFORCE_ON) &&
    (!(TAG_S1 & TAG_PC)) &&
    (insn.rs1() == 1) &&
    (IS_SUPERVISOR == false)) {
    // need to sub 4 from already incremented pc.
    printf("trap would have happened at pc %08lx: \n", npc-4);
    TAG_TRAP();
}

#ifdef TAG_POLICY_NO_PARTIAL_COPY
if(TAG_S1 & TAG_DATA) {
    printf("trap would have happened jumping to data at pc %08lx: \n", npc-4);
    TAG_TRAP();
}
#endif
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
WRITE_RD_AND_TAG(tmp, TAG_PC);
