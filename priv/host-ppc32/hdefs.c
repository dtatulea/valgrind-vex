
/*---------------------------------------------------------------*/
/*---                                                         ---*/
/*--- This file (host-ppc32/hdefs.c) is                       ---*/
/*--- Copyright (c) 2005 OpenWorks LLP.  All rights reserved. ---*/
/*---                                                         ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of LibVEX, a library for dynamic binary
   instrumentation and translation.

   Copyright (C) 2004-2005 OpenWorks, LLP.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; Version 2 dated June 1991 of the
   license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or liability
   for damages.  See the GNU General Public License for more details.

   Neither the names of the U.S. Department of Energy nor the
   University of California nor the names of its contributors may be
   used to endorse or promote products derived from this software
   without prior written permission.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA.
*/

#include "libvex_basictypes.h"
#include "libvex.h"
#include "libvex_trc_values.h"

#include "main/vex_util.h"
#include "host-generic/h_generic_regs.h"
#include "host-ppc32/hdefs.h"


/* --------- Registers. --------- */

void ppHRegPPC32 ( HReg reg ) 
{
   Int r;
   static HChar* ireg32_names[32] 
      = { "%r0",  "%r1",  "%r2",  "%r3",  "%r4",  "%r5",  "%r6",  "%r7",
          "%r8",  "%r9",  "%r10", "%r11", "%r12", "%r13", "%r14", "%r15",
          "%r16", "%r17", "%r18", "%r19", "%r20", "%r21", "%r22", "%r23",
          "%r24", "%r25", "%r26", "%r27", "%r28", "%r29", "%r30", "%r31" };
   /* Be generic for all virtual regs. */
   if (hregIsVirtual(reg)) {
      ppHReg(reg);
      return;
   }
   /* But specific for real regs. */
   switch (hregClass(reg)) {
   case HRcInt32:
      r = hregNumber(reg);
      vassert(r >= 0 && r < 32);
      vex_printf("%s", ireg32_names[r]);
      return;
   case HRcFlt64:
      r = hregNumber(reg);
      vassert(r >= 0 && r < 6);
      vex_printf("%%fpr%d", r);
      return;
   default:
      vpanic("ppHRegPPC32");
   }
}

HReg hregPPC32_GPR0  ( void ) { return mkHReg( 0, HRcInt32, False); }
HReg hregPPC32_GPR1  ( void ) { return mkHReg( 1, HRcInt32, False); }
HReg hregPPC32_GPR2  ( void ) { return mkHReg( 2, HRcInt32, False); }
HReg hregPPC32_GPR3  ( void ) { return mkHReg( 3, HRcInt32, False); }
HReg hregPPC32_GPR4  ( void ) { return mkHReg( 4, HRcInt32, False); }
HReg hregPPC32_GPR5  ( void ) { return mkHReg( 5, HRcInt32, False); }
HReg hregPPC32_GPR6  ( void ) { return mkHReg( 6, HRcInt32, False); }
HReg hregPPC32_GPR7  ( void ) { return mkHReg( 7, HRcInt32, False); }
HReg hregPPC32_GPR8  ( void ) { return mkHReg( 8, HRcInt32, False); }
HReg hregPPC32_GPR9  ( void ) { return mkHReg( 9, HRcInt32, False); }
HReg hregPPC32_GPR10 ( void ) { return mkHReg(10, HRcInt32, False); }
HReg hregPPC32_GPR11 ( void ) { return mkHReg(11, HRcInt32, False); }
HReg hregPPC32_GPR12 ( void ) { return mkHReg(12, HRcInt32, False); }
HReg hregPPC32_GPR13 ( void ) { return mkHReg(13, HRcInt32, False); }
HReg hregPPC32_GPR14 ( void ) { return mkHReg(14, HRcInt32, False); }
HReg hregPPC32_GPR15 ( void ) { return mkHReg(15, HRcInt32, False); }
HReg hregPPC32_GPR16 ( void ) { return mkHReg(16, HRcInt32, False); }
HReg hregPPC32_GPR17 ( void ) { return mkHReg(17, HRcInt32, False); }
HReg hregPPC32_GPR18 ( void ) { return mkHReg(18, HRcInt32, False); }
HReg hregPPC32_GPR19 ( void ) { return mkHReg(19, HRcInt32, False); }
HReg hregPPC32_GPR20 ( void ) { return mkHReg(20, HRcInt32, False); }
HReg hregPPC32_GPR21 ( void ) { return mkHReg(21, HRcInt32, False); }
HReg hregPPC32_GPR22 ( void ) { return mkHReg(22, HRcInt32, False); }
HReg hregPPC32_GPR23 ( void ) { return mkHReg(23, HRcInt32, False); }
HReg hregPPC32_GPR24 ( void ) { return mkHReg(24, HRcInt32, False); }
HReg hregPPC32_GPR25 ( void ) { return mkHReg(25, HRcInt32, False); }
HReg hregPPC32_GPR26 ( void ) { return mkHReg(26, HRcInt32, False); }
HReg hregPPC32_GPR27 ( void ) { return mkHReg(27, HRcInt32, False); }
HReg hregPPC32_GPR28 ( void ) { return mkHReg(28, HRcInt32, False); }
HReg hregPPC32_GPR29 ( void ) { return mkHReg(29, HRcInt32, False); }
HReg hregPPC32_GPR30 ( void ) { return mkHReg(30, HRcInt32, False); }
HReg hregPPC32_GPR31 ( void ) { return mkHReg(31, HRcInt32, False); }

HReg hregPPC32_FPR0  ( void ) { return mkHReg( 0, HRcFlt64, False); }
HReg hregPPC32_FPR1  ( void ) { return mkHReg( 1, HRcFlt64, False); }
HReg hregPPC32_FPR2  ( void ) { return mkHReg( 2, HRcFlt64, False); }
HReg hregPPC32_FPR3  ( void ) { return mkHReg( 3, HRcFlt64, False); }
HReg hregPPC32_FPR4  ( void ) { return mkHReg( 4, HRcFlt64, False); }
HReg hregPPC32_FPR5  ( void ) { return mkHReg( 5, HRcFlt64, False); }
HReg hregPPC32_FPR6  ( void ) { return mkHReg( 6, HRcFlt64, False); }
HReg hregPPC32_FPR7  ( void ) { return mkHReg( 7, HRcFlt64, False); }
HReg hregPPC32_FPR8  ( void ) { return mkHReg( 8, HRcFlt64, False); }
HReg hregPPC32_FPR9  ( void ) { return mkHReg( 9, HRcFlt64, False); }
HReg hregPPC32_FPR10 ( void ) { return mkHReg(10, HRcFlt64, False); }
HReg hregPPC32_FPR11 ( void ) { return mkHReg(11, HRcFlt64, False); }
HReg hregPPC32_FPR12 ( void ) { return mkHReg(12, HRcFlt64, False); }
HReg hregPPC32_FPR13 ( void ) { return mkHReg(13, HRcFlt64, False); }
HReg hregPPC32_FPR14 ( void ) { return mkHReg(14, HRcFlt64, False); }
HReg hregPPC32_FPR15 ( void ) { return mkHReg(15, HRcFlt64, False); }
HReg hregPPC32_FPR16 ( void ) { return mkHReg(16, HRcFlt64, False); }
HReg hregPPC32_FPR17 ( void ) { return mkHReg(17, HRcFlt64, False); }
HReg hregPPC32_FPR18 ( void ) { return mkHReg(18, HRcFlt64, False); }
HReg hregPPC32_FPR19 ( void ) { return mkHReg(19, HRcFlt64, False); }
HReg hregPPC32_FPR20 ( void ) { return mkHReg(20, HRcFlt64, False); }
HReg hregPPC32_FPR21 ( void ) { return mkHReg(21, HRcFlt64, False); }
HReg hregPPC32_FPR22 ( void ) { return mkHReg(22, HRcFlt64, False); }
HReg hregPPC32_FPR23 ( void ) { return mkHReg(23, HRcFlt64, False); }
HReg hregPPC32_FPR24 ( void ) { return mkHReg(24, HRcFlt64, False); }
HReg hregPPC32_FPR25 ( void ) { return mkHReg(25, HRcFlt64, False); }
HReg hregPPC32_FPR26 ( void ) { return mkHReg(26, HRcFlt64, False); }
HReg hregPPC32_FPR27 ( void ) { return mkHReg(27, HRcFlt64, False); }
HReg hregPPC32_FPR28 ( void ) { return mkHReg(28, HRcFlt64, False); }
HReg hregPPC32_FPR29 ( void ) { return mkHReg(29, HRcFlt64, False); }
HReg hregPPC32_FPR30 ( void ) { return mkHReg(30, HRcFlt64, False); }
HReg hregPPC32_FPR31 ( void ) { return mkHReg(31, HRcFlt64, False); }

void getAllocableRegs_PPC32 ( Int* nregs, HReg** arr )
{
   *nregs = 59;
   *arr = LibVEX_Alloc(*nregs * sizeof(HReg));
   // GPR0 = reserved
   // GPR1 = stack pointer
   // GPR2 = TOC pointer
   (*arr)[ 0] = hregPPC32_GPR3();
   (*arr)[ 1] = hregPPC32_GPR4();
   (*arr)[ 2] = hregPPC32_GPR5();
   (*arr)[ 3] = hregPPC32_GPR6();
   (*arr)[ 4] = hregPPC32_GPR7();
   (*arr)[ 5] = hregPPC32_GPR8();
   (*arr)[ 6] = hregPPC32_GPR9();
   (*arr)[ 7] = hregPPC32_GPR10();
   (*arr)[ 8] = hregPPC32_GPR11();
   (*arr)[ 9] = hregPPC32_GPR12();
   // GPR13 = thread specific pointer
   (*arr)[10] = hregPPC32_GPR14();
   (*arr)[11] = hregPPC32_GPR15();
   (*arr)[12] = hregPPC32_GPR16();
   (*arr)[13] = hregPPC32_GPR17();
   (*arr)[14] = hregPPC32_GPR18();
   (*arr)[15] = hregPPC32_GPR19();
   (*arr)[16] = hregPPC32_GPR20();
   (*arr)[17] = hregPPC32_GPR21();
   (*arr)[18] = hregPPC32_GPR22();
   (*arr)[19] = hregPPC32_GPR23();
   (*arr)[20] = hregPPC32_GPR24();
   (*arr)[21] = hregPPC32_GPR25();
   (*arr)[22] = hregPPC32_GPR26();
   (*arr)[23] = hregPPC32_GPR27();
   (*arr)[24] = hregPPC32_GPR28();
   (*arr)[25] = hregPPC32_GPR29();
   (*arr)[26] = hregPPC32_GPR30();
   // GPR31 = GuestStatePtr

   (*arr)[27] = hregPPC32_FPR0();
   (*arr)[28] = hregPPC32_FPR1();
   (*arr)[29] = hregPPC32_FPR2();
   (*arr)[30] = hregPPC32_FPR3();
   (*arr)[31] = hregPPC32_FPR4();
   (*arr)[32] = hregPPC32_FPR5();
   (*arr)[33] = hregPPC32_FPR6();
   (*arr)[34] = hregPPC32_FPR7();
   (*arr)[35] = hregPPC32_FPR8();
   (*arr)[36] = hregPPC32_FPR9();
   (*arr)[37] = hregPPC32_FPR10();
   (*arr)[38] = hregPPC32_FPR11();
   (*arr)[39] = hregPPC32_FPR12();
   (*arr)[40] = hregPPC32_FPR13();
   (*arr)[41] = hregPPC32_FPR14();
   (*arr)[42] = hregPPC32_FPR15();
   (*arr)[43] = hregPPC32_FPR16();
   (*arr)[44] = hregPPC32_FPR17();
   (*arr)[45] = hregPPC32_FPR18();
   (*arr)[46] = hregPPC32_FPR19();
   (*arr)[47] = hregPPC32_FPR20();
   (*arr)[48] = hregPPC32_FPR21();
   (*arr)[49] = hregPPC32_FPR22();
   (*arr)[50] = hregPPC32_FPR23();
   (*arr)[51] = hregPPC32_FPR24();
   (*arr)[52] = hregPPC32_FPR25();
   (*arr)[53] = hregPPC32_FPR26();
   (*arr)[54] = hregPPC32_FPR27();
   (*arr)[55] = hregPPC32_FPR28();
   (*arr)[56] = hregPPC32_FPR29();
   (*arr)[57] = hregPPC32_FPR30();
   (*arr)[58] = hregPPC32_FPR31();
}


/* --------- Condition codes, Intel encoding. --------- */

HChar* showPPC32CondCode ( PPC32CondCode cond )
{
   if (cond.test == Pct_ALWAYS) return "always";

   switch (cond.flag) {
   case Pcf_SO:  return (cond.test == Pct_TRUE) ? "so=1" : "so=0";
   case Pcf_EQ:  return (cond.test == Pct_TRUE) ? "eq=1" : "eq=0";
   case Pcf_GT:  return (cond.test == Pct_TRUE) ? "gt=1" : "gt=0";
   case Pcf_LT:  return (cond.test == Pct_TRUE) ? "lt=1" : "lt=0";
   default: vpanic("ppPPC32CondCode");
   }
}

PPC32CondTest invertCondTest ( PPC32CondTest ct )
{
   vassert(ct != Pct_ALWAYS);
   return (ct == Pct_TRUE) ? Pct_FALSE : Pct_TRUE;
}


/* --------- PPCAMode: memory address expressions. --------- */

PPC32AMode* PPC32AMode_IR ( UInt idx, HReg base ) {
   vassert(idx < 0x10000);
   PPC32AMode* am = LibVEX_Alloc(sizeof(PPC32AMode));
   am->tag = Pam_IR;
   am->Pam.IR.base = base;
   am->Pam.IR.index = idx;
   return am;
}
PPC32AMode* PPC32AMode_RR ( HReg idx, HReg base ) {
   PPC32AMode* am = LibVEX_Alloc(sizeof(PPC32AMode));
   am->tag = Pam_RR;
   am->Pam.RR.base = base;
   am->Pam.RR.index = idx;
   return am;
}

PPC32AMode* dopyPPC32AMode ( PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      return PPC32AMode_IR( am->Pam.IR.index, am->Pam.IR.base );
   case Pam_RR: 
      return PPC32AMode_RR( am->Pam.RR.index, am->Pam.RR.base );
   default:
      vpanic("dopyPPC32AMode");
   }
}

void ppPPC32AMode ( PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      if (am->Pam.IR.index == 0)
         vex_printf("(");
      else
         vex_printf("0x%x(", am->Pam.IR.index);
      ppHRegPPC32(am->Pam.IR.base);
      vex_printf(")");
      return;
   case Pam_RR:
      ppHRegPPC32(am->Pam.RR.base);
      vex_printf(",");
      ppHRegPPC32(am->Pam.RR.index);
      return;
   default:
      vpanic("ppPPC32AMode");
   }
}

static void addRegUsage_PPC32AMode ( HRegUsage* u, PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      addHRegUse(u, HRmRead, am->Pam.IR.base);
      return;
   case Pam_RR:
      addHRegUse(u, HRmRead, am->Pam.RR.base);
      addHRegUse(u, HRmRead, am->Pam.RR.index);
      return;
   default:
      vpanic("addRegUsage_PPC32AMode");
   }
}

static void mapRegs_PPC32AMode ( HRegRemap* m, PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      am->Pam.IR.base = lookupHRegRemap(m, am->Pam.IR.base);
      return;
   case Pam_RR:
      am->Pam.RR.base = lookupHRegRemap(m, am->Pam.RR.base);
      am->Pam.RR.index = lookupHRegRemap(m, am->Pam.RR.index);
      return;
   default:
      vpanic("mapRegs_PPC32AMode");
   }
}

/* --------- Operand, which can be reg or immediate only. --------- */

PPC32RI* PPC32RI_Imm ( UInt imm32 ) {
   PPC32RI* op       = LibVEX_Alloc(sizeof(PPC32RI));
   op->tag           = Pri_Imm;
   op->Pri.Imm.imm32 = imm32;
   return op;
}
PPC32RI* PPC32RI_Reg ( HReg reg ) {
   PPC32RI* op     = LibVEX_Alloc(sizeof(PPC32RI));
   op->tag         = Pri_Reg;
   op->Pri.Reg.reg = reg;
   return op;
}

void ppPPC32RI ( PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      vex_printf("$0x%x", op->Pri.Imm.imm32);
      return;
   case Pri_Reg: 
      ppHRegPPC32(op->Pri.Reg.reg);
      return;
   default: 
      vpanic("ppPPC32RI");
   }
}

/* An PPC32RI can only be used in a "read" context (what would it mean
   to write or modify a literal?) and so we enumerate its registers
   accordingly. */
static void addRegUsage_PPC32RI ( HRegUsage* u, PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      return;
   case Pri_Reg: 
      addHRegUse(u, HRmRead, op->Pri.Reg.reg);
      return;
   default: 
      vpanic("addRegUsage_PPC32RI");
   }
}

static void mapRegs_PPC32RI ( HRegRemap* m, PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      return;
   case Pri_Reg: 
      op->Pri.Reg.reg = lookupHRegRemap(m, op->Pri.Reg.reg);
      return;
   default: 
      vpanic("mapRegs_PPC32RI");
   }
}

/* --------- Instructions. --------- */

//.. HChar* showX86ScalarSz ( X86ScalarSz sz ) {
//..    switch (sz) {
//..       case Xss_16: return "w";
//..       case Xss_32: return "l";
//..       default: vpanic("showX86ScalarSz");
//..    }
//.. }

HChar* showPPC32UnaryOp ( PPC32UnaryOp op ) {
   switch (op) {
   case Pun_NOT: return "not";
   case Pun_NEG: return "neg";
   case Pun_CLZ: return "cntlzw";
   default: vpanic("showPPC32UnaryOp");
   }
}

HChar* showPPC32AluOp ( PPC32AluOp op ) {
   switch (op) {
   case Palu_ADD:  return "add";
   case Palu_SUB:  return "subf";
//   case Palu_ADC:  return "adc";
//   case Palu_SBB:  return "sbb";
   case Palu_AND:  return "and";
   case Palu_OR:   return "or";
   case Palu_XOR:  return "xor";
   default: vpanic("showPPC32AluOp");
   }
}

HChar* showPPC32ShiftOp ( PPC32ShiftOp op ) {
   switch (op) {
   case Psh_SHL: return "slw";
   case Psh_SHR: return "srw";
   case Psh_SAR: return "sraw";
   case Psh_ROL: return "rlw";
   default: vpanic("showPPC32ShiftOp");
   }
}

HChar* showPPC32CmpOp ( PPC32CmpOp op ) {
   switch (op) {
   case Pcmp_U: return "cmpl";
   case Pcmp_S: return "cmp";
   default: vpanic("showPPC32CmpOp");
   }
}

//.. HChar* showX86FpOp ( X86FpOp op ) {
//..    switch (op) {
//..       case Xfp_ADD:    return "add";
//..       case Xfp_SUB:    return "sub";
//..       case Xfp_MUL:    return "mul";
//..       case Xfp_DIV:    return "div";
//..       case Xfp_SCALE:  return "scale";
//..       case Xfp_ATAN:   return "atan";
//..       case Xfp_YL2X:   return "yl2x";
//..       case Xfp_YL2XP1: return "yl2xp1";
//..       case Xfp_PREM:   return "prem";
//..       case Xfp_PREM1:  return "prem1";
//..       case Xfp_SQRT:   return "sqrt";
//..       case Xfp_ABS:    return "abs";
//..       case Xfp_NEG:    return "chs";
//..       case Xfp_MOV:    return "mov";
//..       case Xfp_SIN:    return "sin";
//..       case Xfp_COS:    return "cos";
//..       case Xfp_TAN:    return "tan";
//..       case Xfp_ROUND:  return "round";
//..       case Xfp_2XM1:   return "2xm1";
//..       default: vpanic("showX86FpOp");
//..    }
//.. }

PPC32Instr* PPC32Instr_Alu32 ( PPC32AluOp op, HReg dst, HReg src1, PPC32RI* src2 ) {
   if (src2->tag == Pri_Imm)
      vassert(src2->Pri.Imm.imm32 < 0x10000);
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_Alu32;
   i->Pin.Alu32.op   = op;
   i->Pin.Alu32.dst  = dst;
   i->Pin.Alu32.src1 = src1;
   i->Pin.Alu32.src2 = src2;
   return i;
}
PPC32Instr* PPC32Instr_Sh32 ( PPC32ShiftOp op, HReg dst, HReg src, PPC32RI* shft ) {
   if (op == Psh_SHL || op == Psh_SHR)  // No imm versions for these.
      vassert(shft->tag == Pri_Reg);
   if (shft->tag == Pri_Imm)
      vassert(shft->Pri.Imm.imm32 < 32);
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag           = Pin_Sh32;
   i->Pin.Sh32.op   = op;
   i->Pin.Sh32.dst  = dst;
   i->Pin.Sh32.src  = src;
   i->Pin.Sh32.shft = shft;
   return i;
}
//PPC32Instr* PPC32Instr_Test32  ( HReg dst, PPC32RI* src ) {
//   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
//   i->tag            = Pin_Test32;
//   i->Pin.Test32.dst = dst;
//   i->Pin.Test32.src = src;
//   return i;
//}
PPC32Instr* PPC32Instr_Cmp32 ( PPC32CmpOp op, UInt crfD, HReg src1, PPC32RI* src2 ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_Cmp32;
   i->Pin.Cmp32.op   = op;
   i->Pin.Cmp32.crfD = crfD;
   i->Pin.Cmp32.src1 = src1;
   i->Pin.Cmp32.src2 = src2;
   return i;
}
PPC32Instr* PPC32Instr_Unary32  ( PPC32UnaryOp op, HReg dst, HReg src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_Unary32;
   i->Pin.Unary32.op  = op;
   i->Pin.Unary32.dst = dst;
   i->Pin.Unary32.src = src;
   return i;
}
PPC32Instr* PPC32Instr_MulL ( Bool syned, Bool word, HReg dst,
                              HReg src1, PPC32RI* src2 ) {
   if (word == 1) { // high
      vassert(src2->tag == Pri_Reg);
   } else {         // low
      if (src2->tag == Pri_Imm) {
         vassert(syned == True);
         vassert(src2->Pri.Imm.imm32 < 0x10000);
      }
   }
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_MulL;
   i->Pin.MulL.syned = syned;
   i->Pin.MulL.word  = word;
   i->Pin.MulL.dst   = dst;
   i->Pin.MulL.src1  = src1;
   i->Pin.MulL.src2  = src2;
   return i;
}
PPC32Instr* PPC32Instr_Div ( Bool syned, HReg dst, HReg src1, HReg src2 ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_Div;
   i->Pin.Div.syned   = syned;
   i->Pin.Div.dst     = dst;
   i->Pin.Div.src1    = src1;
   i->Pin.Div.src2    = src2;
   return i;
}
//.. X86Instr* X86Instr_Sh3232  ( X86ShiftOp op, UInt amt, HReg src, HReg dst ) {
//..    X86Instr* i       = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag            = Xin_Sh3232;
//..    i->Xin.Sh3232.op  = op;
//..    i->Xin.Sh3232.amt = amt;
//..    i->Xin.Sh3232.src = src;
//..    i->Xin.Sh3232.dst = dst;
//..    vassert(op == Xsh_SHL || op == Xsh_SHR);
//..    return i;
//.. }
//.. X86Instr* X86Instr_Push( X86RMI* src ) {
//..    X86Instr* i     = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag          = Xin_Push;
//..    i->Xin.Push.src = src;
//..    return i;
//.. }
PPC32Instr* PPC32Instr_Call ( PPC32CondCode cond, Addr32 target, Int regparms ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag               = Pin_Call;
   i->Pin.Call.cond     = cond;
   i->Pin.Call.target   = target;
   i->Pin.Call.regparms = regparms;
   vassert(regparms >= 0 && regparms < PPC32_N_REGPARMS);
   return i;
}
PPC32Instr* PPC32Instr_Goto ( IRJumpKind jk, PPC32CondCode cond, PPC32RI* dst ) {
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag           = Pin_Goto;
   i->Pin.Goto.cond = cond;
   i->Pin.Goto.dst  = dst;
   i->Pin.Goto.jk   = jk;
   return i;
}
PPC32Instr* PPC32Instr_CMov32  ( PPC32CondCode cond, HReg dst, PPC32RI* src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_CMov32;
   i->Pin.CMov32.cond = cond;
   i->Pin.CMov32.src  = src;
   i->Pin.CMov32.dst  = dst;
   vassert(cond.test != Pct_ALWAYS);
   return i;
}
PPC32Instr* PPC32Instr_LoadEX ( UChar sz, Bool syned,
                                HReg dst, PPC32AMode* src ) {
   PPC32Instr* i       = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag              = Pin_LoadEX;
   i->Pin.LoadEX.sz    = sz;
   i->Pin.LoadEX.syned = syned;
   i->Pin.LoadEX.src   = src;
   i->Pin.LoadEX.dst   = dst;
   vassert(sz == 1 || sz == 2 || sz == 4);
   return i;
}
PPC32Instr* PPC32Instr_Store ( UChar sz, PPC32AMode* dst, HReg src ) {
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag           = Pin_Store;
   i->Pin.Store.sz  = sz;
   i->Pin.Store.src = src;
   i->Pin.Store.dst = dst;
   vassert(sz == 1 || sz == 2 || sz == 4);
   return i;
}
PPC32Instr* PPC32Instr_Set32 ( PPC32CondCode cond, HReg dst ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_Set32;
   i->Pin.Set32.cond = cond;
   i->Pin.Set32.dst  = dst;
   return i;
}
//.. X86Instr* X86Instr_Bsfr32 ( Bool isFwds, HReg src, HReg dst ) {
//..    X86Instr* i          = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag               = Xin_Bsfr32;
//..    i->Xin.Bsfr32.isFwds = isFwds;
//..    i->Xin.Bsfr32.src    = src;
//..    i->Xin.Bsfr32.dst    = dst;
//..    return i;
//.. }
PPC32Instr* PPC32Instr_MFence ( void )
{
   PPC32Instr* i         = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag                = Pin_MFence;
   return i;
}

//.. X86Instr* X86Instr_FpUnary ( X86FpOp op, HReg src, HReg dst ) {
//..    X86Instr* i        = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag             = Xin_FpUnary;
//..    i->Xin.FpUnary.op  = op;
//..    i->Xin.FpUnary.src = src;
//..    i->Xin.FpUnary.dst = dst;
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpBinary ( X86FpOp op, HReg srcL, HReg srcR, HReg dst ) {
//..    X86Instr* i          = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag               = Xin_FpBinary;
//..    i->Xin.FpBinary.op   = op;
//..    i->Xin.FpBinary.srcL = srcL;
//..    i->Xin.FpBinary.srcR = srcR;
//..    i->Xin.FpBinary.dst  = dst;
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpLdSt ( Bool isLoad, UChar sz, HReg reg, X86AMode* addr ) {
//..    X86Instr* i          = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag               = Xin_FpLdSt;
//..    i->Xin.FpLdSt.isLoad = isLoad;
//..    i->Xin.FpLdSt.sz     = sz;
//..    i->Xin.FpLdSt.reg    = reg;
//..    i->Xin.FpLdSt.addr   = addr;
//..    vassert(sz == 4 || sz == 8);
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpLdStI ( Bool isLoad, UChar sz,  
//..                              HReg reg, X86AMode* addr ) {
//..    X86Instr* i           = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag                = Xin_FpLdStI;
//..    i->Xin.FpLdStI.isLoad = isLoad;
//..    i->Xin.FpLdStI.sz     = sz;
//..    i->Xin.FpLdStI.reg    = reg;
//..    i->Xin.FpLdStI.addr   = addr;
//..    vassert(sz == 2 || sz == 4 || sz == 8);
//..    return i;
//.. }
//.. X86Instr* X86Instr_Fp64to32 ( HReg src, HReg dst ) {
//..    X86Instr* i         = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag              = Xin_Fp64to32;
//..    i->Xin.Fp64to32.src = src;
//..    i->Xin.Fp64to32.dst = dst;
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpCMov ( X86CondCode cond, HReg src, HReg dst ) {
//..    X86Instr* i        = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag             = Xin_FpCMov;
//..    i->Xin.FpCMov.cond = cond;
//..    i->Xin.FpCMov.src  = src;
//..    i->Xin.FpCMov.dst  = dst;
//..    vassert(cond != Xcc_ALWAYS);
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpLdStCW ( Bool isLoad, X86AMode* addr ) {
//..    X86Instr* i            = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag                 = Xin_FpLdStCW;
//..    i->Xin.FpLdStCW.isLoad = isLoad;
//..    i->Xin.FpLdStCW.addr   = addr;
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpStSW_AX ( void ) {
//..    X86Instr* i = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag      = Xin_FpStSW_AX;
//..    return i;
//.. }
//.. X86Instr* X86Instr_FpCmp ( HReg srcL, HReg srcR, HReg dst ) {
//..    X86Instr* i       = LibVEX_Alloc(sizeof(X86Instr));
//..    i->tag            = Xin_FpCmp;
//..    i->Xin.FpCmp.srcL = srcL;
//..    i->Xin.FpCmp.srcR = srcR;
//..    i->Xin.FpCmp.dst  = dst;
//..    return i;
//.. }

void ppPPC32Instr ( PPC32Instr* i )
{
   switch (i->tag) {
   case Pin_Alu32:
      if (i->Pin.Alu32.op == Palu_OR &&     // or Rd,Rs,Rs == mr Rd,Rs
          i->Pin.Alu32.src2->tag == Pri_Reg &&
          i->Pin.Alu32.src2->Pri.Reg.reg == i->Pin.Alu32.src1) {
         vex_printf("mr ");
         ppHRegPPC32(i->Pin.Alu32.dst);
         vex_printf(",");
         ppHRegPPC32(i->Pin.Alu32.src1);
         return;
      }
      if (i->Pin.Alu32.op == Palu_ADD &&     // add Rd,R0,Rs == li Rd,Rs
          i->Pin.Alu32.src1 == hregPPC32_GPR0() &&
          i->Pin.Alu32.src2->tag == Pri_Imm) {
         vex_printf("li ");
         ppHRegPPC32(i->Pin.Alu32.dst);
         vex_printf(",");
         ppPPC32RI(i->Pin.Alu32.src2);
         return;
      }
      vex_printf("%s%s ", showPPC32AluOp(i->Pin.Alu32.op),
                 i->Pin.Alu32.src2->tag == Pri_Imm ? "i" : "" );
      ppHRegPPC32(i->Pin.Alu32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Alu32.src1);
      vex_printf(",");
      ppPPC32RI(i->Pin.Alu32.src2);
      return;
   case Pin_Sh32:
      vex_printf("%s%s ", showPPC32ShiftOp(i->Pin.Sh32.op),
                 i->Pin.Sh32.shft->tag == Pri_Imm ? "i" : "" );
      ppHRegPPC32(i->Pin.Sh32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Sh32.src);
      vex_printf(",");
      ppPPC32RI(i->Pin.Sh32.shft);
      return;
//      case Pin_Test32:
//         vex_printf("test ");
//         ppHRegPPC32(i->Pin.Test32.dst);
//         vex_printf(",");
//         ppPPC32RI(i->Pin.Test32.src);
//         return;
   case Pin_Cmp32:
      vex_printf("cmp%s %%crf%d,",
                 i->Pin.Cmp32.src2->tag == Pri_Imm ? "i" : "",
                 i->Pin.Cmp32.crfD);
      ppHRegPPC32(i->Pin.Alu32.src1);
      vex_printf(",");
      ppPPC32RI(i->Pin.Alu32.src2);
      return;
   case Pin_Unary32:
      vex_printf("%s ", showPPC32UnaryOp(i->Pin.Unary32.op));
      ppHRegPPC32(i->Pin.Unary32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      if (i->Pin.MulL.src2->tag == Pri_Imm) {
         vex_printf("mulli ");
      } else {
         vex_printf("mul%s%c ",
                    i->Pin.MulL.word ? "hw" : "lw",
                    i->Pin.MulL.syned ? 's' : 'u');
      }
      ppHRegPPC32(i->Pin.MulL.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.MulL.src1);
      vex_printf(",");
      ppPPC32RI(i->Pin.MulL.src2);
      return;
   case Pin_Div:
      vex_printf("divw%s ",
                 i->Pin.Div.syned ? "" : "u");
      ppHRegPPC32(i->Pin.Div.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Div.src1);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Div.src2);
      return;
//..       case Xin_Sh3232:
//..          vex_printf("%sdl ", showX86ShiftOp(i->Xin.Sh3232.op));
//..          if (i->Xin.Sh3232.amt == 0)
//..            vex_printf(" %%cl,"); 
//..          else 
//..             vex_printf(" $%d,", i->Xin.Sh3232.amt);
//..          ppHRegX86(i->Xin.Sh3232.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Sh3232.dst);
//..          return;
//..       case Xin_Push:
//..          vex_printf("pushl ");
//..          ppX86RMI(i->Xin.Push.src);
//..          return;
   case Pin_Call:
      vex_printf("call: la r12, 0x%x ; mtctr r12 ; bcctrl[%d] %s",
                 i->Pin.Call.target,
                 i->Pin.Call.regparms,
                 showPPC32CondCode(i->Pin.Call.cond));
      break;
   case Pin_Goto:
      vex_printf("goto: ");
      if (i->Pin.Goto.cond.test != Pct_ALWAYS) {
         vex_printf("if (%%CR.%s) { ", 
                    showPPC32CondCode(i->Pin.Goto.cond));
      }
      if (i->Pin.Goto.jk != Ijk_Boring) {
         vex_printf("la %%r31, $");
         ppIRJumpKind(i->Pin.Goto.jk);
         vex_printf(" ; ");
      }
      vex_printf("bca %s,%%r4, ", showPPC32CondCode(i->Pin.Goto.cond));
      ppPPC32RI(i->Pin.Goto.dst);
      vex_printf(" ; ret");
      if (i->Pin.Goto.cond.test != Pct_ALWAYS) {
         vex_printf(" }");
      }
      return;
   case Pin_CMov32:
// bc false,cond,8
// li ...
      vex_printf("cmov32 (%s) ", showPPC32CondCode(i->Pin.CMov32.cond));
      ppHRegPPC32(i->Pin.CMov32.dst);
      vex_printf(",");
      ppPPC32RI(i->Pin.CMov32.src);
      return;
   case Pin_LoadEX: {
      UChar sz = i->Pin.LoadEX.sz;
      Bool syned = i->Pin.LoadEX.syned;
// CAB: How to get 'update'... ?
      Bool update = False;
      Bool idxd = (i->Pin.LoadEX.src->tag == Pam_IR) ? True : False;
      vex_printf("l%c%c%s%s ",
                 (sz==1) ? 'b' : (sz==2 ? 'h' : 'w'),
                 syned ? 'a' : 'z',
                 update ? "u" : "",
                 idxd ? "x" : "" );
      ppHRegPPC32(i->Pin.LoadEX.dst);
      vex_printf(",");
      ppPPC32AMode(i->Pin.LoadEX.src);
      return;
   }
   case Pin_Store: {
      UChar sz = i->Pin.Store.sz;
// CAB: How to get 'update'... ?
      Bool update = False;
      Bool idxd = (i->Pin.Store.dst->tag == Pam_IR) ? True : False;
      vex_printf("st%c%s%s ",
                 (sz==1) ? 'b' : (sz==2 ? 'h' : 'w'),
                 update ? "u" : "",
                 idxd ? "x" : "" );
      ppHRegPPC32(i->Pin.Store.src);
      vex_printf(",");
      ppPPC32AMode(i->Pin.Store.dst);
      return;
   }
   case Pin_Set32:
      vex_printf("set32 (%s) ", showPPC32CondCode(i->Pin.Set32.cond));
      ppHRegPPC32(i->Pin.Set32.dst);
      return;
//..       case Xin_Bsfr32:
//..          vex_printf("bs%cl ", i->Xin.Bsfr32.isFwds ? 'f' : 'r');
//..          ppHRegX86(i->Xin.Bsfr32.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Bsfr32.dst);
//..          return;
   case Pin_MFence:
      vex_printf("mfence (=sync)");
      return;
//..       case Xin_FpUnary:
//..          vex_printf("g%sD ", showX86FpOp(i->Xin.FpUnary.op));
//..          ppHRegX86(i->Xin.FpUnary.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpUnary.dst);
//..          break;
//..       case Xin_FpBinary:
//..          vex_printf("g%sD ", showX86FpOp(i->Xin.FpBinary.op));
//..          ppHRegX86(i->Xin.FpBinary.srcL);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpBinary.srcR);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpBinary.dst);
//..          break;
//..       case Xin_FpLdSt:
//..          if (i->Xin.FpLdSt.isLoad) {
//..             vex_printf("gld%c " , i->Xin.FpLdSt.sz==8 ? 'D' : 'F');
//..             ppX86AMode(i->Xin.FpLdSt.addr);
//..             vex_printf(", ");
//..             ppHRegX86(i->Xin.FpLdSt.reg);
//..          } else {
//..             vex_printf("gst%c " , i->Xin.FpLdSt.sz==8 ? 'D' : 'F');
//..             ppHRegX86(i->Xin.FpLdSt.reg);
//..             vex_printf(", ");
//..             ppX86AMode(i->Xin.FpLdSt.addr);
//..          }
//..          return;
//..       case Xin_FpLdStI:
//..          if (i->Xin.FpLdStI.isLoad) {
//..             vex_printf("gild%s ", i->Xin.FpLdStI.sz==8 ? "ll" : 
//..                                   i->Xin.FpLdStI.sz==4 ? "l" : "w");
//..             ppX86AMode(i->Xin.FpLdStI.addr);
//..             vex_printf(", ");
//..             ppHRegX86(i->Xin.FpLdStI.reg);
//..          } else {
//..             vex_printf("gist%s ", i->Xin.FpLdStI.sz==8 ? "ll" : 
//..                                   i->Xin.FpLdStI.sz==4 ? "l" : "w");
//..             ppHRegX86(i->Xin.FpLdStI.reg);
//..             vex_printf(", ");
//..             ppX86AMode(i->Xin.FpLdStI.addr);
//..          }
//..          return;
//..       case Xin_Fp64to32:
//..          vex_printf("gdtof ");
//..          ppHRegX86(i->Xin.Fp64to32.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Fp64to32.dst);
//..          return;
//..       case Xin_FpCMov:
//..          vex_printf("gcmov%s ", showX86CondCode(i->Xin.FpCMov.cond));
//..          ppHRegX86(i->Xin.FpCMov.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpCMov.dst);
//..          return;
//..       case Xin_FpLdStCW:
//..          vex_printf(i->Xin.FpLdStCW.isLoad ? "fldcw " : "fstcw ");
//..          ppX86AMode(i->Xin.FpLdStCW.addr);
//..          return;
//..       case Xin_FpStSW_AX:
//..          vex_printf("fstsw %%ax");
//..          return;
//..       case Xin_FpCmp:
//..          vex_printf("gcmp ");
//..          ppHRegX86(i->Xin.FpCmp.srcL);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpCmp.srcR);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.FpCmp.dst);
//..          break;
//..       case Xin_SseConst:
//..          vex_printf("const $0x%04x,", (Int)i->Xin.SseConst.con);
//..          ppHRegX86(i->Xin.SseConst.dst);
//..          break;
//..       case Xin_SseLdSt:
//..          vex_printf("movups ");
//..          if (i->Xin.SseLdSt.isLoad) {
//..             ppX86AMode(i->Xin.SseLdSt.addr);
//..             vex_printf(",");
//..             ppHRegX86(i->Xin.SseLdSt.reg);
//..          } else {
//..             ppHRegX86(i->Xin.SseLdSt.reg);
//..             vex_printf(",");
//..             ppX86AMode(i->Xin.SseLdSt.addr);
//..          }
//..          return;
//..       case Xin_SseLdzLO:
//..          vex_printf("movs%s ", i->Xin.SseLdzLO.sz==4 ? "s" : "d");
//..          ppX86AMode(i->Xin.SseLdzLO.addr);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.SseLdzLO.reg);
//..          return;
//..       case Xin_Sse32Fx4:
//..          vex_printf("%sps ", showX86SseOp(i->Xin.Sse32Fx4.op));
//..          ppHRegX86(i->Xin.Sse32Fx4.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Sse32Fx4.dst);
//..          return;
//..       case Xin_Sse32FLo:
//..          vex_printf("%sss ", showX86SseOp(i->Xin.Sse32FLo.op));
//..          ppHRegX86(i->Xin.Sse32FLo.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Sse32FLo.dst);
//..          return;
//..       case Xin_Sse64Fx2:
//..          vex_printf("%spd ", showX86SseOp(i->Xin.Sse64Fx2.op));
//..          ppHRegX86(i->Xin.Sse64Fx2.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Sse64Fx2.dst);
//..          return;
//..       case Xin_Sse64FLo:
//..          vex_printf("%ssd ", showX86SseOp(i->Xin.Sse64FLo.op));
//..          ppHRegX86(i->Xin.Sse64FLo.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.Sse64FLo.dst);
//..          return;
//..       case Xin_SseReRg:
//..          vex_printf("%s ", showX86SseOp(i->Xin.SseReRg.op));
//..          ppHRegX86(i->Xin.SseReRg.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.SseReRg.dst);
//..          return;
//..       case Xin_SseCMov:
//..          vex_printf("cmov%s ", showX86CondCode(i->Xin.SseCMov.cond));
//..          ppHRegX86(i->Xin.SseCMov.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.SseCMov.dst);
//..          return;
//..       case Xin_SseShuf:
//..          vex_printf("pshufd $0x%x,", i->Xin.SseShuf.order);
//..          ppHRegX86(i->Xin.SseShuf.src);
//..          vex_printf(",");
//..          ppHRegX86(i->Xin.SseShuf.dst);
//..          return;

   default:
      vex_printf("\nppPPC32Instr(ppc32): No such tag(%d)\n", i->tag);
      vpanic("ppPPC32Instr(ppc32)");
   }
}

/* --------- Helpers for register allocation. --------- */

void getRegUsage_PPC32Instr ( HRegUsage* u, PPC32Instr* i )
{
//   Bool unary;
   initHRegUsage(u);
   switch (i->tag) {
   case Pin_Alu32:
      addHRegUse(u, HRmRead, i->Pin.Alu32.src1);
      addRegUsage_PPC32RI(u, i->Pin.Alu32.src2);
//         if (i->Pin.Alu32.op == Palu_CMP) { 
//            addHRegUse(u, HRmRead, i->Pin.Alu32.dst);
//            return;
//         }
      addHRegUse(u, HRmWrite, i->Pin.Alu32.dst);
// CAB TODO: Any circumstance where dst is read & written?
      return;

   case Pin_Sh32:
      addHRegUse(u, HRmWrite, i->Pin.Sh32.dst);
      addHRegUse(u, HRmRead, i->Pin.Sh32.src);
      addRegUsage_PPC32RI(u, i->Pin.Sh32.shft);
// CAB TODO: Any circumstance where dst is read & written?
      return;
      
//   case Pin_Test32:
//      addHRegUse(u, HRmRead, i->Pin.Test32.dst);
//      addRegUsage_PPC32RI(u, i->Pin.Test32.src);
//      return;

   case Pin_Cmp32:
      addHRegUse(u, HRmRead, i->Pin.Cmp32.src1);
      addRegUsage_PPC32RI(u, i->Pin.Cmp32.src2);
      return;

   case Pin_Unary32:
      addHRegUse(u, HRmWrite, i->Pin.Unary32.dst);
      addHRegUse(u, HRmRead, i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      addHRegUse(u, HRmWrite, i->Pin.MulL.dst);
      addHRegUse(u, HRmRead, i->Pin.MulL.src1);
      addRegUsage_PPC32RI(u, i->Pin.MulL.src2);
      return;
   case Pin_Div:
      addHRegUse(u, HRmWrite, i->Pin.Div.dst);
      addHRegUse(u, HRmRead, i->Pin.Div.src1);
      addHRegUse(u, HRmRead, i->Pin.Div.src2);
      return;
//..       case Xin_Sh3232:
//..          addHRegUse(u, HRmRead, i->Xin.Sh3232.src);
//..          addHRegUse(u, HRmModify, i->Xin.Sh3232.dst);
//..          if (i->Xin.Sh3232.amt == 0)
//..             addHRegUse(u, HRmRead, hregX86_ECX());
//..          return;
//..       case Xin_Push:
//..          addRegUsage_X86RMI(u, i->Xin.Push.src);
//..          addHRegUse(u, HRmModify, hregX86_ESP());
//..          return;
   case Pin_Call:
      /* This is a bit subtle. */
      /* First off, claim it trashes all the caller-saved regs
         which fall within the register allocator's jurisdiction.
         These I believe to be: r0,r3:12
      */
      addHRegUse(u, HRmWrite, hregPPC32_GPR0());
      addHRegUse(u, HRmWrite, hregPPC32_GPR3());
      addHRegUse(u, HRmWrite, hregPPC32_GPR4());
      addHRegUse(u, HRmWrite, hregPPC32_GPR5());
      addHRegUse(u, HRmWrite, hregPPC32_GPR6());
      addHRegUse(u, HRmWrite, hregPPC32_GPR7());
      addHRegUse(u, HRmWrite, hregPPC32_GPR8());
      addHRegUse(u, HRmWrite, hregPPC32_GPR9());
      addHRegUse(u, HRmWrite, hregPPC32_GPR10());
      addHRegUse(u, HRmWrite, hregPPC32_GPR11());
      addHRegUse(u, HRmWrite, hregPPC32_GPR12());
      
      /* Now we have to state any parameter-carrying registers
         which might be read.  This depends on the regparmness. */
      switch (i->Pin.Call.regparms) {
      case  8: addHRegUse(u, HRmRead, hregPPC32_GPR10()); /*fallthru*/
      case  7: addHRegUse(u, HRmRead, hregPPC32_GPR9() ); /*fallthru*/
      case  6: addHRegUse(u, HRmRead, hregPPC32_GPR8() ); /*fallthru*/
      case  5: addHRegUse(u, HRmRead, hregPPC32_GPR7() ); /*fallthru*/
      case  4: addHRegUse(u, HRmRead, hregPPC32_GPR6() ); /*fallthru*/
      case  3: addHRegUse(u, HRmRead, hregPPC32_GPR5() ); /*fallthru*/
      case  2: addHRegUse(u, HRmRead, hregPPC32_GPR4() ); /*fallthru*/
      case  1: addHRegUse(u, HRmRead, hregPPC32_GPR3() ); /*fallthru*/
      case  0: break;
      default: vpanic("getRegUsage_PPC32Instr:Call:regparms");
      }
      /* Finally, there is the issue that the insn trashes a
         register because the literal target address has to be
         loaded into a register.  %r12 seems a suitable victim.  */
      addHRegUse(u, HRmWrite, hregPPC32_GPR12());
      /* Upshot of this is that the assembler really must use %r12,
            and no other, as a destination temporary. */
      return;
   case Pin_Goto:
      addRegUsage_PPC32RI(u, i->Pin.Goto.dst);
      addHRegUse(u, HRmWrite, hregPPC32_GPR4());
      if (i->Pin.Goto.jk != Ijk_Boring)
         addHRegUse(u, HRmWrite, GuestStatePtr);
      return;
   case Pin_CMov32:
      addRegUsage_PPC32RI(u, i->Pin.CMov32.src);
      addHRegUse(u, HRmModify, i->Pin.CMov32.dst);
      return;
   case Pin_LoadEX:
      addRegUsage_PPC32AMode(u, i->Pin.LoadEX.src);
      addHRegUse(u, HRmWrite, i->Pin.LoadEX.dst);
      return;
   case Pin_Store:
      addHRegUse(u, HRmRead, i->Pin.Store.src);
      addRegUsage_PPC32AMode(u, i->Pin.Store.dst);
      return;
   case Pin_Set32:
      addHRegUse(u, HRmWrite, i->Pin.Set32.dst);
      return;
//..       case Xin_Bsfr32:
//..          addHRegUse(u, HRmRead, i->Xin.Bsfr32.src);
//..          addHRegUse(u, HRmWrite, i->Xin.Bsfr32.dst);
//..          return;
   case Pin_MFence:
      return;
//..       case Xin_FpUnary:
//..          addHRegUse(u, HRmRead, i->Xin.FpUnary.src);
//..          addHRegUse(u, HRmWrite, i->Xin.FpUnary.dst);
//..          return;
//..       case Xin_FpBinary:
//..          addHRegUse(u, HRmRead, i->Xin.FpBinary.srcL);
//..          addHRegUse(u, HRmRead, i->Xin.FpBinary.srcR);
//..          addHRegUse(u, HRmWrite, i->Xin.FpBinary.dst);
//..          return;
//..       case Xin_FpLdSt:
//..          addRegUsage_X86AMode(u, i->Xin.FpLdSt.addr);
//..          addHRegUse(u, i->Xin.FpLdSt.isLoad ? HRmWrite : HRmRead,
//..                        i->Xin.FpLdSt.reg);
//..          return;
//..       case Xin_FpLdStI:
//..          addRegUsage_X86AMode(u, i->Xin.FpLdStI.addr);
//..          addHRegUse(u, i->Xin.FpLdStI.isLoad ? HRmWrite : HRmRead,
//..                        i->Xin.FpLdStI.reg);
//..          return;
//..       case Xin_Fp64to32:
//..          addHRegUse(u, HRmRead,  i->Xin.Fp64to32.src);
//..          addHRegUse(u, HRmWrite, i->Xin.Fp64to32.dst);
//..          return;
//..       case Xin_FpCMov:
//..          addHRegUse(u, HRmRead,   i->Xin.FpCMov.src);
//..          addHRegUse(u, HRmModify, i->Xin.FpCMov.dst);
//..          return;
//..       case Xin_FpLdStCW:
//..          addRegUsage_X86AMode(u, i->Xin.FpLdStCW.addr);
//..          return;
//..       case Xin_FpStSW_AX:
//..          addHRegUse(u, HRmWrite, hregX86_EAX());
//..          return;
//..       case Xin_FpCmp:
//..          addHRegUse(u, HRmRead, i->Xin.FpCmp.srcL);
//..          addHRegUse(u, HRmRead, i->Xin.FpCmp.srcR);
//..          addHRegUse(u, HRmWrite, i->Xin.FpCmp.dst);
//..          addHRegUse(u, HRmWrite, hregX86_EAX());
//..          return;
//..       case Xin_SseLdSt:
//..          addRegUsage_X86AMode(u, i->Xin.SseLdSt.addr);
//..          addHRegUse(u, i->Xin.SseLdSt.isLoad ? HRmWrite : HRmRead,
//..                        i->Xin.SseLdSt.reg);
//..          return;
//..       case Xin_SseLdzLO:
//..          addRegUsage_X86AMode(u, i->Xin.SseLdzLO.addr);
//..          addHRegUse(u, HRmWrite, i->Xin.SseLdzLO.reg);
//..          return;
//..       case Xin_SseConst:
//..          addHRegUse(u, HRmWrite, i->Xin.SseConst.dst);
//..          return;
//..       case Xin_Sse32Fx4:
//..          vassert(i->Xin.Sse32Fx4.op != Xsse_MOV);
//..          unary = i->Xin.Sse32Fx4.op == Xsse_RCPF
//..                  || i->Xin.Sse32Fx4.op == Xsse_RSQRTF
//..                  || i->Xin.Sse32Fx4.op == Xsse_SQRTF;
//..          addHRegUse(u, HRmRead, i->Xin.Sse32Fx4.src);
//..          addHRegUse(u, unary ? HRmWrite : HRmModify, 
//..                        i->Xin.Sse32Fx4.dst);
//..          return;
//..       case Xin_Sse32FLo:
//..          vassert(i->Xin.Sse32FLo.op != Xsse_MOV);
//..          unary = i->Xin.Sse32FLo.op == Xsse_RCPF
//..                  || i->Xin.Sse32FLo.op == Xsse_RSQRTF
//..                  || i->Xin.Sse32FLo.op == Xsse_SQRTF;
//..          addHRegUse(u, HRmRead, i->Xin.Sse32FLo.src);
//..          addHRegUse(u, unary ? HRmWrite : HRmModify, 
//..                        i->Xin.Sse32FLo.dst);
//..          return;
//..       case Xin_Sse64Fx2:
//..          vassert(i->Xin.Sse64Fx2.op != Xsse_MOV);
//..          unary = i->Xin.Sse64Fx2.op == Xsse_RCPF
//..                  || i->Xin.Sse64Fx2.op == Xsse_RSQRTF
//..                  || i->Xin.Sse64Fx2.op == Xsse_SQRTF;
//..          addHRegUse(u, HRmRead, i->Xin.Sse64Fx2.src);
//..          addHRegUse(u, unary ? HRmWrite : HRmModify, 
//..                        i->Xin.Sse64Fx2.dst);
//..          return;
//..       case Xin_Sse64FLo:
//..          vassert(i->Xin.Sse64FLo.op != Xsse_MOV);
//..          unary = i->Xin.Sse64FLo.op == Xsse_RCPF
//..                  || i->Xin.Sse64FLo.op == Xsse_RSQRTF
//..                  || i->Xin.Sse64FLo.op == Xsse_SQRTF;
//..          addHRegUse(u, HRmRead, i->Xin.Sse64FLo.src);
//..          addHRegUse(u, unary ? HRmWrite : HRmModify, 
//..                        i->Xin.Sse64FLo.dst);
//..          return;
//..       case Xin_SseReRg:
//..          if (i->Xin.SseReRg.op == Xsse_XOR
//..              && i->Xin.SseReRg.src == i->Xin.SseReRg.dst) {
//..             /* reg-alloc needs to understand 'xor r,r' as a write of r */
//..             /* (as opposed to a rite of passage :-) */
//..             addHRegUse(u, HRmWrite, i->Xin.SseReRg.dst);
//..          } else {
//..             addHRegUse(u, HRmRead, i->Xin.SseReRg.src);
//..             addHRegUse(u, i->Xin.SseReRg.op == Xsse_MOV 
//..                              ? HRmWrite : HRmModify, 
//..                           i->Xin.SseReRg.dst);
//..          }
//..          return;
//..       case Xin_SseCMov:
//..          addHRegUse(u, HRmRead,   i->Xin.SseCMov.src);
//..          addHRegUse(u, HRmModify, i->Xin.SseCMov.dst);
//..          return;
//..       case Xin_SseShuf:
//..          addHRegUse(u, HRmRead,  i->Xin.SseShuf.src);
//..          addHRegUse(u, HRmWrite, i->Xin.SseShuf.dst);
//..          return;
   default:
      ppPPC32Instr(i);
      vpanic("getRegUsage_PPC32Instr");
   }
}

/* local helper */
static void mapReg(HRegRemap* m, HReg* r)
{
   *r = lookupHRegRemap(m, *r);
}

void mapRegs_PPC32Instr (HRegRemap* m, PPC32Instr* i)
{
   switch (i->tag) {
   case Pin_Alu32:
      mapReg(m, &i->Pin.Alu32.dst);
      mapReg(m, &i->Pin.Alu32.src1);
      mapRegs_PPC32RI(m, i->Pin.Alu32.src2);
      return;
   case Pin_Sh32:
      mapReg(m, &i->Pin.Sh32.dst);
      mapReg(m, &i->Pin.Sh32.src);
      mapRegs_PPC32RI(m, i->Pin.Sh32.shft);
      return;
//      case Pin_Test32:
//         mapReg(m, &i->Pin.Test32.dst);
//         mapRegs_PPC32RI(m, i->Pin.Test32.src);
//         return;
   case Pin_Cmp32:
      mapReg(m, &i->Pin.Cmp32.src1);
      mapRegs_PPC32RI(m, i->Pin.Cmp32.src2);
      return;
   case Pin_Unary32:
      mapReg(m, &i->Pin.Unary32.dst);
      mapReg(m, &i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      mapReg(m, &i->Pin.MulL.dst);
      mapReg(m, &i->Pin.MulL.src1);
      mapRegs_PPC32RI(m, i->Pin.MulL.src2);
      return;
   case Pin_Div:
      mapReg(m, &i->Pin.Div.dst);
      mapReg(m, &i->Pin.Div.src1);
      mapReg(m, &i->Pin.Div.src2);
      return;
//..       case Xin_Sh3232:
//..          mapReg(m, &i->Xin.Sh3232.src);
//..          mapReg(m, &i->Xin.Sh3232.dst);
//..          return;
//..       case Xin_Push:
//..          mapRegs_X86RMI(m, i->Xin.Push.src);
//..          return;
   case Pin_Call:
      return;
   case Pin_Goto:
      mapRegs_PPC32RI(m, i->Pin.Goto.dst);
      return;
   case Pin_CMov32:
      mapRegs_PPC32RI(m, i->Pin.CMov32.src);
      mapReg(m, &i->Pin.CMov32.dst);
      return;
   case Pin_LoadEX:
      mapRegs_PPC32AMode(m, i->Pin.LoadEX.src);
      mapReg(m, &i->Pin.LoadEX.dst);
      return;
   case Pin_Store:
      mapReg(m, &i->Pin.Store.src);
      mapRegs_PPC32AMode(m, i->Pin.Store.dst);
      return;
   case Pin_Set32:
      mapReg(m, &i->Pin.Set32.dst);
      return;
//..       case Xin_Bsfr32:
//..          mapReg(m, &i->Xin.Bsfr32.src);
//..          mapReg(m, &i->Xin.Bsfr32.dst);
//..          return;
   case Pin_MFence:
      return;
//..       case Xin_FpUnary:
//..          mapReg(m, &i->Xin.FpUnary.src);
//..          mapReg(m, &i->Xin.FpUnary.dst);
//..          return;
//..       case Xin_FpBinary:
//..          mapReg(m, &i->Xin.FpBinary.srcL);
//..          mapReg(m, &i->Xin.FpBinary.srcR);
//..          mapReg(m, &i->Xin.FpBinary.dst);
//..          return;
//..       case Xin_FpLdSt:
//..          mapRegs_X86AMode(m, i->Xin.FpLdSt.addr);
//..          mapReg(m, &i->Xin.FpLdSt.reg);
//..          return;
//..       case Xin_FpLdStI:
//..          mapRegs_X86AMode(m, i->Xin.FpLdStI.addr);
//..          mapReg(m, &i->Xin.FpLdStI.reg);
//..          return;
//..       case Xin_Fp64to32:
//..          mapReg(m, &i->Xin.Fp64to32.src);
//..          mapReg(m, &i->Xin.Fp64to32.dst);
//..          return;
//..       case Xin_FpCMov:
//..          mapReg(m, &i->Xin.FpCMov.src);
//..          mapReg(m, &i->Xin.FpCMov.dst);
//..          return;
//..       case Xin_FpLdStCW:
//..          mapRegs_X86AMode(m, i->Xin.FpLdStCW.addr);
//..          return;
//..       case Xin_FpStSW_AX:
//..          return;
//..       case Xin_FpCmp:
//..          mapReg(m, &i->Xin.FpCmp.srcL);
//..          mapReg(m, &i->Xin.FpCmp.srcR);
//..          mapReg(m, &i->Xin.FpCmp.dst);
//..          return;
//..       case Xin_SseConst:
//..          mapReg(m, &i->Xin.SseConst.dst);
//..          return;
//..       case Xin_SseLdSt:
//..          mapReg(m, &i->Xin.SseLdSt.reg);
//..          mapRegs_X86AMode(m, i->Xin.SseLdSt.addr);
//..          break;
//..       case Xin_SseLdzLO:
//..          mapReg(m, &i->Xin.SseLdzLO.reg);
//..          mapRegs_X86AMode(m, i->Xin.SseLdzLO.addr);
//..          break;
//..       case Xin_Sse32Fx4:
//..          mapReg(m, &i->Xin.Sse32Fx4.src);
//..          mapReg(m, &i->Xin.Sse32Fx4.dst);
//..          return;
//..       case Xin_Sse32FLo:
//..          mapReg(m, &i->Xin.Sse32FLo.src);
//..          mapReg(m, &i->Xin.Sse32FLo.dst);
//..          return;
//..       case Xin_Sse64Fx2:
//..          mapReg(m, &i->Xin.Sse64Fx2.src);
//..          mapReg(m, &i->Xin.Sse64Fx2.dst);
//..          return;
//..       case Xin_Sse64FLo:
//..          mapReg(m, &i->Xin.Sse64FLo.src);
//..          mapReg(m, &i->Xin.Sse64FLo.dst);
//..          return;
//..       case Xin_SseReRg:
//..          mapReg(m, &i->Xin.SseReRg.src);
//..          mapReg(m, &i->Xin.SseReRg.dst);
//..          return;
//..       case Xin_SseCMov:
//..          mapReg(m, &i->Xin.SseCMov.src);
//..          mapReg(m, &i->Xin.SseCMov.dst);
//..          return;
//..       case Xin_SseShuf:
//..          mapReg(m, &i->Xin.SseShuf.src);
//..          mapReg(m, &i->Xin.SseShuf.dst);
//..          return;
   default:
      ppPPC32Instr(i);
      vpanic("mapRegs_PPC32Instr");
   }
}

/* Figure out if i represents a reg-reg move, and if so assign the
   source and destination to *src and *dst.  If in doubt say No.  Used
   by the register allocator to do move coalescing. 
*/
Bool isMove_PPC32Instr ( PPC32Instr* i, HReg* src, HReg* dst )
{
   /* Moves between integer regs */
   if (i->tag == Pin_Alu32) {
      // or Rd,Rs,Rs == mr Rd,Rs
      if (i->Pin.Alu32.op != Palu_OR)
         return False;
      if (i->Pin.Alu32.src2->tag != Pri_Reg)
         return False;
      if (i->Pin.Alu32.src2->Pri.Reg.reg != i->Pin.Alu32.src1)
         return False;
      *src = i->Pin.Alu32.src1;
      *dst = i->Pin.Alu32.dst;
      return True;
   }
//..    /* Moves between FP regs */
//..    if (i->tag == Xin_FpUnary) {
//..       if (i->Xin.FpUnary.op != Xfp_MOV)
//..          return False;
//..       *src = i->Xin.FpUnary.src;
//..       *dst = i->Xin.FpUnary.dst;
//..       return True;
//..    }
//..    if (i->tag == Xin_SseReRg) {
//..       if (i->Xin.SseReRg.op != Xsse_MOV)
//..          return False;
//..       *src = i->Xin.SseReRg.src;
//..       *dst = i->Xin.SseReRg.dst;
//..       return True;
//..    }
   return False;
}


/* Generate ppc32 spill/reload instructions under the direction of the
   register allocator.  Note it's critical these don't write the
   condition codes. */

PPC32Instr* genSpill_PPC32 ( HReg rreg, Int offsetB )
{
   PPC32AMode* am;
   vassert(offsetB >= 0);
   vassert(!hregIsVirtual(rreg));
   am = PPC32AMode_IR(offsetB, GuestStatePtr);
   
   switch (hregClass(rreg)) {
   case HRcInt32:
      return PPC32Instr_Store( 4, am, rreg);
//   case HRcFlt64:
//      return PPC32Instr_FpLdSt ( False/*store*/, 8, rreg, am );
//   case HRcVec128:
//      return PPC32Instr_SseLdSt ( False/*store*/, rreg, am );
   default: 
      ppHRegClass(hregClass(rreg));
      vpanic("genSpill_PPC32: unimplemented regclass");
   }
}

PPC32Instr* genReload_PPC32 ( HReg rreg, Int offsetB )
{
   PPC32AMode* am;
   vassert(offsetB >= 0);
   vassert(!hregIsVirtual(rreg));
   am = PPC32AMode_IR(offsetB, GuestStatePtr);

   switch (hregClass(rreg)) {
   case HRcInt32:
      return PPC32Instr_LoadEX( 4, False, rreg, am );
//   case HRcFlt64:
//      return PPC32Instr_FpLdSt ( True/*load*/, 8, rreg, am );
//   case HRcVec128:
//      return PPC32Instr_SseLdSt ( True/*load*/, rreg, am );
   default: 
      ppHRegClass(hregClass(rreg));
      vpanic("genReload_PPC32: unimplemented regclass");
   }
}


/* --------- The ppc32 assembler (bleh.) --------- */

static UInt iregNo ( HReg r )
{
   UInt n;
   vassert(hregClass(r) == HRcInt32);
   vassert(!hregIsVirtual(r));
   n = hregNumber(r);
   vassert(n <= 32);
   return n;
}

//.. static UInt fregNo ( HReg r )
//.. {
//..    UInt n;
//..    vassert(hregClass(r) == HRcFlt64);
//..    vassert(!hregIsVirtual(r));
//..    n = hregNumber(r);
//..    vassert(n <= 5);
//..    return n;
//.. }

//.. static UInt vregNo ( HReg r )
//.. {
//..    UInt n;
//..    vassert(hregClass(r) == HRcVec128);
//..    vassert(!hregIsVirtual(r));
//..    n = hregNumber(r);
//..    vassert(n <= 7);
//..    return n;
//.. }

//.. static UChar mkModRegRM ( UChar mod, UChar reg, UChar regmem )
//.. {
//..    return ((mod & 3) << 6) | ((reg & 7) << 3) | (regmem & 7);
//.. }

//.. static UChar mkSIB ( Int shift, Int regindex, Int regbase )
//.. {
//..    return ((shift & 3) << 6) | ((regindex & 7) << 3) | (regbase & 7);
//.. }

/* Emit 32bit instruction big-endianly */
static UChar* emit32 ( UChar* p, UInt w32 )
{
   *p++ = (w32 >> 24) & 0x000000FF;
   *p++ = (w32 >> 16) & 0x000000FF;
   *p++ = (w32 >>  8) & 0x000000FF;
   *p++ = (w32)       & 0x000000FF;
   return p;
}

//.. /* Does a sign-extend of the lowest 8 bits give 
//..    the original number? */
//.. static Bool fits8bits ( UInt w32 )
//.. {
//..    Int i32 = (Int)w32;
//..    return i32 == ((i32 << 24) >> 24);
//.. }


//.. /* Forming mod-reg-rm bytes and scale-index-base bytes.
//.. 
//..      greg,  0(ereg)    |  ereg != ESP && ereg != EBP
//..                        =  00 greg ereg
//.. 
//..      greg,  d8(ereg)   |  ereg != ESP
//..                        =  01 greg ereg, d8
//.. 
//..      greg,  d32(ereg)  |  ereg != ESP
//..                        =  10 greg ereg, d32
//.. 
//..      greg,  d8(%esp)   =  01 greg 100, 0x24, d8
//.. 
//..      -----------------------------------------------
//.. 
//..      greg,  d8(base,index,scale)  
//..                |  index != ESP
//..                =  01 greg 100, scale index base, d8
//.. 
//..      greg,  d32(base,index,scale)
//..                |  index != ESP
//..                =  10 greg 100, scale index base, d32
//.. */
//.. static UChar* doAMode_M ( UChar* p, HReg greg, X86AMode* am ) 
//.. {
//..    if (am->tag == Xam_IR) {
//..       if (am->Xam.IR.imm == 0 
//..           && am->Xam.IR.reg != hregX86_ESP()
//..           && am->Xam.IR.reg != hregX86_EBP() ) {
//..          *p++ = mkModRegRM(0, iregNo(greg), iregNo(am->Xam.IR.reg));
//..          return p;
//..       }
//..       if (fits8bits(am->Xam.IR.imm)
//..           && am->Xam.IR.reg != hregX86_ESP()) {
//..          *p++ = mkModRegRM(1, iregNo(greg), iregNo(am->Xam.IR.reg));
//..          *p++ = am->Xam.IR.imm & 0xFF;
//..          return p;
//..       }
//..       if (am->Xam.IR.reg != hregX86_ESP()) {
//..          *p++ = mkModRegRM(2, iregNo(greg), iregNo(am->Xam.IR.reg));
//..          p = emit32(p, am->Xam.IR.imm);
//..          return p;
//..       }
//..       if (am->Xam.IR.reg == hregX86_ESP()
//..           && fits8bits(am->Xam.IR.imm)) {
//..          *p++ = mkModRegRM(1, iregNo(greg), 4);
//..          *p++ = 0x24;
//..          *p++ = am->Xam.IR.imm & 0xFF;
//..          return p;
//..       }
//..       ppX86AMode(am);
//..       vpanic("doAMode_M: can't emit amode IR");
//..       /*NOTREACHED*/
//..    }
//..    if (am->tag == Xam_IRRS) {
//..       if (fits8bits(am->Xam.IRRS.imm)
//..           && am->Xam.IRRS.index != hregX86_ESP()) {
//..          *p++ = mkModRegRM(1, iregNo(greg), 4);
//..          *p++ = mkSIB(am->Xam.IRRS.shift, am->Xam.IRRS.index, 
//..                                           am->Xam.IRRS.base);
//..          *p++ = am->Xam.IRRS.imm & 0xFF;
//..          return p;
//..       }
//..       if (am->Xam.IRRS.index != hregX86_ESP()) {
//..          *p++ = mkModRegRM(2, iregNo(greg), 4);
//..          *p++ = mkSIB(am->Xam.IRRS.shift, am->Xam.IRRS.index,
//..                                           am->Xam.IRRS.base);
//..          p = emit32(p, am->Xam.IRRS.imm);
//..          return p;
//..       }
//..       ppX86AMode(am);
//..       vpanic("doAMode_M: can't emit amode IRRS");
//..       /*NOTREACHED*/
//..    }
//..    vpanic("doAMode_M: unknown amode");
//..    /*NOTREACHED*/
//.. }


//.. /* Emit a mod-reg-rm byte when the rm bit denotes a reg. */
//.. static UChar* doAMode_R ( UChar* p, HReg greg, HReg ereg ) 
//.. {
//..    *p++ = mkModRegRM(3, iregNo(greg), iregNo(ereg));
//..    return p;
//.. }


//.. /* Emit ffree %st(7) */
//.. static UChar* do_ffree_st7 ( UChar* p )
//.. {
//..    *p++ = 0xDD;
//..    *p++ = 0xC7;
//..    return p;
//.. }

//.. /* Emit fstp %st(i), 1 <= i <= 7 */
//.. static UChar* do_fstp_st ( UChar* p, Int i )
//.. {
//..    vassert(1 <= i && i <= 7);
//..    *p++ = 0xDD;
//..    *p++ = 0xD8+i;
//..    return p;
//.. }

//.. /* Emit fld %st(i), 0 <= i <= 6 */
//.. static UChar* do_fld_st ( UChar* p, Int i )
//.. {
//..    vassert(0 <= i && i <= 6);
//..    *p++ = 0xD9;
//..    *p++ = 0xC0+i;
//..    return p;
//.. }

//.. /* Emit f<op> %st(0) */
//.. static UChar* do_fop1_st ( UChar* p, X86FpOp op )
//.. {
//..    switch (op) {
//..       case Xfp_NEG:    *p++ = 0xD9; *p++ = 0xE0; break;
//..       case Xfp_ABS:    *p++ = 0xD9; *p++ = 0xE1; break;
//..       case Xfp_SQRT:   *p++ = 0xD9; *p++ = 0xFA; break;
//..       case Xfp_ROUND:  *p++ = 0xD9; *p++ = 0xFC; break;
//..       case Xfp_SIN:    *p++ = 0xD9; *p++ = 0xFE; break;
//..       case Xfp_COS:    *p++ = 0xD9; *p++ = 0xFF; break;
//..       case Xfp_2XM1:   *p++ = 0xD9; *p++ = 0xF0; break;
//..       case Xfp_MOV:    break;
//..       case Xfp_TAN:    p = do_ffree_st7(p); /* since fptan pushes 1.0 */
//..                        *p++ = 0xD9; *p++ = 0xF2; /* fptan */
//..                        *p++ = 0xD9; *p++ = 0xF7; /* fincstp */
//..                        break;
//..       default: vpanic("do_fop1_st: unknown op");
//..    }
//..    return p;
//.. }

//.. /* Emit f<op> %st(i), 1 <= i <= 5 */
//.. static UChar* do_fop2_st ( UChar* p, X86FpOp op, Int i )
//.. {
//.. #  define fake(_n) mkHReg((_n), HRcInt32, False)
//..    Int subopc;
//..    switch (op) {
//..       case Xfp_ADD: subopc = 0; break;
//..       case Xfp_SUB: subopc = 4; break;
//..       case Xfp_MUL: subopc = 1; break;
//..       case Xfp_DIV: subopc = 6; break;
//..       default: vpanic("do_fop2_st: unknown op");
//..    }
//..    *p++ = 0xD8;
//..    p    = doAMode_R(p, fake(subopc), fake(i));
//..    return p;
//.. #  undef fake
//.. }

//.. /* Push a 32-bit word on the stack.  The word depends on tags[3:0];
//.. each byte is either 0x00 or 0xFF depending on the corresponding bit in tags[].
//.. */
//.. static UChar* push_word_from_tags ( UChar* p, UShort tags )
//.. {
//..    UInt w;
//..    vassert(0 == (tags & ~0xF));
//..    if (tags == 0) {
//..       /* pushl $0x00000000 */
//..       *p++ = 0x6A;
//..       *p++ = 0x00;
//..    }
//..    else 
//..    /* pushl $0xFFFFFFFF */
//..    if (tags == 0xF) {
//..       *p++ = 0x6A;
//..       *p++ = 0xFF;
//..    } else {
//..       vassert(0); /* awaiting test case */
//..       w = 0;
//..       if (tags & 1) w |= 0x000000FF;
//..       if (tags & 2) w |= 0x0000FF00;
//..       if (tags & 4) w |= 0x00FF0000;
//..       if (tags & 8) w |= 0xFF000000;
//..       *p++ = 0x68;
//..       p = emit32(p, w);
//..    }
//..    return p;
//.. }

static UChar* mkFormD ( UChar* p, UInt op1, UInt r1, UInt r2, UInt imm )
{
   vassert(op1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(imm < 0x10000 || imm >= 0xFFFF0000);     // Pos|Neg
   UInt theInstr = ((op1<<26) | (r1<<21) | (r2<<16) | (imm));
   return emit32(p, theInstr);
}

static UChar* mkFormX ( UChar* p, UInt op1, UInt r1, UInt r2,
                        UInt r3, UInt op2, UInt b0 )
{
   vassert(op1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(r3  < 0x20);
   vassert(op2 < 0x400);
   vassert(b0  < 0x2);
   UInt theInstr = ((op1<<26) | (r1<<21) | (r2<<16) |
                    (r3<<11) | (op2<<1) | (b0));
   return emit32(p, theInstr);
}

static UChar* mkFormXO ( UChar* p, UInt op1, UInt r1, UInt r2,
                         UInt r3, UInt b10, UInt op2, UInt b0 )
{
   vassert(op1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(r3  < 0x20);
   vassert(b10 < 0x2);
   vassert(op2 < 0x200);
   vassert(b0  < 0x2);
   UInt theInstr = ((op1<<26) | (r1<<21) | (r2<<16) |
                    (r3<<11) | (b10 << 10) | (op2<<1) | (b0));
   return emit32(p, theInstr);
}

static UChar* mkFormXL ( UChar* p, UInt op1, UInt f1, UInt f2,
                         UInt f3, UInt op2, UInt b0 )
{
   vassert(op1 < 0x40);
   vassert(f1  < 0x20);
   vassert(f2  < 0x20);
   vassert(f3  < 0x20);
   vassert(op2 < 0x400);
   vassert(b0  < 0x2);
   UInt theInstr = ((op1<<26) | (f1<<21) | (f2<<16) |
                    (f3<<11) | (op2<<1) | (b0));
   return emit32(p, theInstr);
}

// Note: for split field ops, give mnemonic arg
static UChar* mkFormXFX ( UChar* p, UInt r1, UInt f2, UInt op2 )
{
   vassert(r1  < 0x20);
   vassert(f2  < 0x20);
   vassert(op2 < 0x400);
   switch (op2) {
   case 144:  // mtcrf
      vassert(f2 < 0x100);
      f2 = f2 << 1;
      break;
   case 339:  // mfspr
   case 371:  // mftb
   case 467:  // mtspr
      vassert(f2 < 0x400);
      f2 = ((f2>>5) & 0x1F) | ((f2 & 0x1F)<<5);  // re-arrange split field
      break;
   default: vpanic("mkFormXFX(PPC32)");
   }
   UInt theInstr = ((31<<26) | (r1<<21) | (f2<<11) | (op2<<1));
   return emit32(p, theInstr);
}

#if 0
// 'b'
static UChar* mkFormI ( UChar* p, UInt LI, UInt AA, UInt LK )
{
   vassert(LI  < 0x1000000);
   vassert(AA  < 0x2);
   vassert(LK  < 0x2);
   UInt theInstr = ((18<<26) | (LI<<2) | (AA<<1) | (LK));
   return emit32(p, theInstr);
}
#endif

// 'bc'
static UChar* mkFormB ( UChar* p, UInt BO, UInt BI,
                        UInt BD, UInt AA, UInt LK )
{
   vassert(BO  < 0x20);
   vassert(BI  < 0x20);
   vassert(BD  < 0x4000);
   vassert(AA  < 0x2);
   vassert(LK  < 0x2);
   UInt theInstr = ((16<<26) | (BO<<21) | (BI<<16) |
                    (BD<<2) | (AA<<1) | (LK));
   return emit32(p, theInstr);
}

// rotates
static UChar* mkFormM ( UChar* p, UInt op1, UInt r1, UInt r2,
                        UInt f3, UInt MB, UInt ME, UInt Rc )
{
   vassert(op1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(f3  < 0x20);
   vassert(MB  < 0x20);
   vassert(ME  < 0x20);
   vassert(Rc  < 0x2);
   UInt theInstr = ((op1<<26) | (r1<<21) | (r2<<16) |
                    (f3<<11) | (MB<<6) | (ME<<1) | (Rc));
   return emit32(p, theInstr);
}

static UChar* doAMode_IR ( UChar* p, UInt op1, HReg hrSD, PPC32AMode* am )
{
   vassert(am->tag == Pam_IR);
   UInt rSD = iregNo(hrSD);
   UInt rA  = iregNo(am->Pam.IR.base);
   UInt idx = am->Pam.IR.index;
   vassert(idx < 0x10000);
   
   p = mkFormD(p, op1, rSD, rA, idx);
   return p;
}


static UChar* doAMode_RR ( UChar* p, UInt op1, UInt op2,
                           HReg hrSD, PPC32AMode* am )
{
//   vassert(hregClass(hrSD) == HRcInt32); // CAB: etc. worth doing this?
   vassert(am->tag == Pam_RR);
   UInt rSD = iregNo(hrSD);
   UInt rA  = iregNo(am->Pam.RR.base);
   UInt rB  = iregNo(am->Pam.RR.index);
   
   p = mkFormX(p, op1, rSD, rA, rB, op2, 0);
   return p;
}


/* Emit an instruction into buf and return the number of bytes used.
   Note that buf is not the insn's final place, and therefore it is
   imperative to emit position-independent code. */

Int emit_PPC32Instr ( UChar* buf, Int nbuf, PPC32Instr* i )
{
//..    UInt irno, opc, opc_rr, subopc_imm, opc_imma, opc_cl, opc_imm, subopc;
//.. 
//..    UInt   xtra;
   UChar* p = &buf[0];
//..    UChar* ptmp;
//..    vassert(nbuf >= 32);
//.. 
//..    /* Wrap an integer as a int register, for use assembling
//..       GrpN insns, in which the greg field is used as a sub-opcode
//..       and does not really contain a register. */
//.. #  define fake(_n) mkHReg((_n), HRcInt32, False)

   vex_printf("asm  ");ppPPC32Instr(i); vex_printf("\n");

   switch (i->tag) {

   case Pin_Alu32: {
      UInt op1 = 31, op2, rB, imm;
      UInt r_dst  = iregNo(i->Pin.Alu32.dst);
      UInt r_src1 = iregNo(i->Pin.Alu32.src1);

      /* ADD/SUB/ADC/SBB/AND/OR/XOR */
      if (i->Pin.Alu32.src2->tag == Pri_Reg) {
         op1 = 31;
         rB = iregNo(i->Pin.Alu32.src2->Pri.Reg.reg);
         switch (i->Pin.Alu32.op) {
         case Palu_ADD: op2 = 266; break;
         case Palu_SUB: op2 = 266; break;
         case Palu_AND: op2 =  28; break;
         case Palu_XOR: op2 = 316; break;
         case Palu_OR:  op2 = 444; break;
//         case Palu_ADC:
//         case Palu_SBB:
         default:
            goto bad;
         }

         switch (i->Pin.Alu32.op) {
         case Palu_ADD: case Palu_SUB:
            p = mkFormXO(p, op1, r_dst, r_src1, rB, 0, op2, 0); // rD = rA...
            break;
         case Palu_AND: case Palu_XOR: case Palu_OR:
            p = mkFormX(p, op1, r_src1, r_dst, rB, op2, 0); // rA = rS...
            break;
//         case Palu_ADC:
//         case Palu_SBB:
         default:
            goto bad;
         }
      } else { // Pri_Imm:
         imm = i->Pin.Alu32.src2->Pri.Imm.imm32;
         switch (i->Pin.Alu32.op) {
         case Palu_ADD: op1 = 14; break;
         case Palu_SUB: op1 =  8; break;
         case Palu_AND: op1 = 28; break;
         case Palu_XOR: op1 = 26; break;
         case Palu_OR:  op1 = 24; break;
//         case Palu_ADC:
//         case Palu_SBB:
         default:
            goto bad;
         }

         switch (i->Pin.Alu32.op) {
         case Palu_ADD: case Palu_SUB:
            p = mkFormD(p, op1, r_dst, r_src1, imm); // rD = rA...
            break;
         case Palu_AND: case Palu_XOR: case Palu_OR:
            p = mkFormD(p, op1, r_src1, r_dst, imm); // rA = rS...
            break;
//         case Palu_ADC:
//         case Palu_SBB:
         default:
            goto bad;
         }
      }
      goto done;
   }

   case Pin_Sh32: {
      UInt opc1 = 31, opc2, rB, sh;
      UInt op = i->Pin.Sh32.op;
      UInt rS = iregNo(i->Pin.Sh32.dst);
      UInt rA = iregNo(i->Pin.Sh32.src);
      PPC32RITag ri_tag = i->Pin.Sh32.shft->tag;

      if ((op == Psh_SHL || op == Psh_SHR) && ri_tag == Pri_Imm)
         goto bad;  // No imm versions of these

      switch (op) {
      case Psh_SHL: opc2 = 24;  break;
      case Psh_SHR: opc2 = 536; break;
      case Psh_SAR: opc2 = (ri_tag == Pri_Reg) ? 792 : 824; break;
      default: goto bad;
      }

      switch (i->Pin.Sh32.shft->tag) {
      case Pri_Reg:
         rB = iregNo(i->Pin.Sh32.shft->Pri.Reg.reg);
         p = mkFormX(p, opc1, rS, rA, rB, opc2, 0);
         break;
      case Pri_Imm:
         sh = i->Pin.Sh32.shft->Pri.Imm.imm32;
         p = mkFormX(p, opc1, rS, rA, sh, opc2, 0);
         break;
      default:
         goto bad;
      }
      goto done;
   }

//..    case Xin_Test32:
//..       if (i->Xin.Test32.src->tag == Xri_Imm
//..           && i->Xin.Test32.dst->tag == Xrm_Reg) {
//..          /* testl $imm32, %reg */
//..          *p++ = 0xF7;
//..          p = doAMode_R(p, fake(0), i->Xin.Test32.dst->Xrm.Reg.reg);
//..          p = emit32(p, i->Xin.Test32.src->Xri.Imm.imm32);
//..          goto done;
//..       }
//..       break;

   case Pin_Cmp32: {
      UInt opc1, opc2=0;
      UInt op = i->Pin.Cmp32.op;
      UInt fld1 = i->Pin.Cmp32.crfD << 2;
      UInt r1 = iregNo(i->Pin.Cmp32.src1);
      UInt r2, imm;

      switch (i->Pin.Cmp32.src2->tag) {
      case Pri_Imm:
         opc1 = (op == Pcmp_U) ? 10 : 11;
         imm = i->Pin.Cmp32.src2->Pri.Imm.imm32;
         p = mkFormD(p, opc1, fld1, r1, imm);
         break;
      case Pri_Reg:
         opc1 = 31;
         opc2 = (op == Pcmp_U) ? 32 : 0;
         r2 = iregNo(i->Pin.Cmp32.src2->Pri.Reg.reg);
         p = mkFormX(p, opc1, fld1, r1, r2, opc2, 0);
         break;
      default: goto bad;
      }        
      goto done;
   }

   case Pin_Unary32: {
      UInt r_dst = iregNo(i->Pin.Unary32.dst);
      UInt r_src = iregNo(i->Pin.Unary32.src);

      switch (i->Pin.Unary32.op) {
      case Pun_NOT:  // nor r_dst,r_src,r_src
         p = mkFormX(p, 31, r_src, r_dst, r_src, 124, 0);
         break;
      case Pun_NEG:  // neg r_dst,r_src
         p = mkFormXO(p, 31, r_dst, r_src, 0, 0, 104, 0);
         break;
      case Pun_CLZ:  // cntlzw r_dst, r_src
         p = mkFormX(p, 31, r_dst, r_src, 0, 26, 0);
         break;
      default: goto bad;
      }
      goto done;
   }

   case Pin_MulL: {
      Bool syned  = i->Pin.MulL.syned;
      UInt r_dst  = iregNo(i->Pin.MulL.dst);
      UInt r_src1 = iregNo(i->Pin.MulL.src1);
      UInt r_src2, imm;

      switch (i->Pin.MulL.word) {
      case 0:       // multiply low word
         switch (i->Pin.MulL.src2->tag) {
         case Pri_Reg:
            // mullw r_dst,r_src1,r_src2
            // sign makes no difference.
            r_src2 = iregNo(i->Pin.MulL.src2->Pri.Reg.reg);
            p = mkFormXO(p, 31, r_dst, r_src1, r_src2, 0, 235, 0);
            break;
         case Pri_Imm:
            // mulli r_dst,r_src,imm
            vassert(syned == True);  // always signed
            imm = i->Pin.MulL.src2->Pri.Imm.imm32;
            p = mkFormD(p, 07, r_dst, r_src1, imm);
            break;
         default:
            goto bad;
         }
         break;
      case 1:       // multiply high word
         vassert(i->Pin.MulL.src2->tag == Pri_Reg);
         r_src2 = iregNo(i->Pin.MulL.src2->Pri.Reg.reg);
         if (syned == True) {
            // mulhw r_dst,r_src1,r_src2
            p = mkFormXO(p, 31, r_dst, r_src1, r_src2, 0, 75, 0);
         } else {
            // mulhwu r_dst,r_src1,r_src2
            p = mkFormXO(p, 31, r_dst, r_src1, r_src2, 0, 11, 0);
         }
         break;
      default:
         goto bad;
      }
      goto done;
   }

//..    case Xin_Div:
//..       subopc = i->Xin.Div.syned ? 7 : 6;
//..       if (i->Xin.Div.ssz == Xss_32) {
//..          *p++ = 0xF7;
//..          switch (i->Xin.Div.src->tag)  {
//..             case Xrm_Mem:
//..                p = doAMode_M(p, fake(subopc),
//..                                 i->Xin.Div.src->Xrm.Mem.am);
//..                goto done;
//..             case Xrm_Reg:
//..                p = doAMode_R(p, fake(subopc), 
//..                                 i->Xin.Div.src->Xrm.Reg.reg);
//..                goto done;
//..             default:
//..                goto bad;
//..          }
//..       }
//..       break;

//..    case Xin_Sh3232:
//..       vassert(i->Xin.Sh3232.op == Xsh_SHL || i->Xin.Sh3232.op == Xsh_SHR);
//..       if (i->Xin.Sh3232.amt == 0) {
//..          /* shldl/shrdl by %cl */
//..          *p++ = 0x0F;
//..          if (i->Xin.Sh3232.op == Xsh_SHL) {
//..             *p++ = 0xA5;
//..          } else {
//..             *p++ = 0xAD;
//..          }
//..          p = doAMode_R(p, i->Xin.Sh3232.src, i->Xin.Sh3232.dst);
//..          goto done;
//..       }
//..       break;

//..    case Xin_Push:
//..       switch (i->Xin.Push.src->tag) {
//..          case Xrmi_Mem: 
//..             *p++ = 0xFF;
//..             p = doAMode_M(p, fake(6), i->Xin.Push.src->Xrmi.Mem.am);
//..             goto done;
//..          case Xrmi_Imm:
//..             *p++ = 0x68;
//..             p = emit32(p, i->Xin.Push.src->Xrmi.Imm.imm32);
//..             goto done;
//..          case Xrmi_Reg:
//..             *p++ = 0x50 + iregNo(i->Xin.Push.src->Xrmi.Reg.reg);
//..             goto done;
//..         default: 
//..             goto bad;
//..       }

   case Pin_Call: {
      Addr32 target;

      /* As per detailed comment for Ain_Call in
         getRegUsage_PPC32Instr above, %r12 is used as an address
         temporary. */
      /* jump over the following two insns if the condition does not
         hold */
      if (i->Pin.Call.cond.test != Pct_ALWAYS) {
         target = 16; /* num bytes in next insts */
         /* bca ct,cf,target */
         p = mkFormB(p, invertCondTest(i->Pin.Call.cond.test),
                     (31 - i->Pin.Call.cond.flag),
                     target, 1, 0);
      }

      /* addi r12,0,(target & 0xFFFF)
         addis r12,r12,((target >> 16) & 0xFFFF) => load target to r12 */
      target = i->Pin.Call.target;
      p = mkFormD(p, 14, 12, 0, (target & 0xFFFF));
      p = mkFormD(p, 15, 12, 12, ((target>>16) & 0xFFFF) );

      /* mtspr 9,r12 => move r12 to count register */
      p = mkFormXFX(p, 12, 9, 467);
      
      /* bcctrl 20,0 => branch w. link to count register */
      p = mkFormXL(p, 19, Pct_ALWAYS, 0, 0, 528, 1);

/* CAB: Hmm...
   "When possible, independent instructions should separate the load
   of the Count Register from the branch to prevent pipeline stalls." */

      goto done;
   }

   case Pin_Goto: {
      UInt magic_num = 0;
      UChar r_dst, r_src;
      PPC32CondCode cond = i->Pin.Goto.cond;
      UInt imm;
      
      /* First off, if this is conditional, create a conditional
         jump over the rest of it. */
      if (cond.test != Pct_ALWAYS) {
         /* jmp fwds if !condition */
         imm = 8; /* num bytes in next insts */
         /* bca ct,cf,imm */
         p = mkFormB(p, invertCondTest(cond.test),
                     (31 - cond.flag), imm, 1, 0);
      }

      /* If a non-boring, set GuestStatePtr appropriately. */
      /* addi r31,0,magic_num */
      switch (i->Pin.Goto.jk) {
      case Ijk_ClientReq: magic_num = VEX_TRC_JMP_CLIENTREQ; break;
      case Ijk_Syscall:   magic_num = VEX_TRC_JMP_SYSCALL;   break;
      case Ijk_Yield:     magic_num = VEX_TRC_JMP_YIELD;     break;
      case Ijk_EmWarn:    magic_num = VEX_TRC_JMP_EMWARN;    break;
      case Ijk_MapFail:   magic_num = VEX_TRC_JMP_MAPFAIL;   break;
      case Ijk_NoDecode:  magic_num = VEX_TRC_JMP_NODECODE;  break;
      case Ijk_Ret:
      case Ijk_Call:
      case Ijk_Boring:
         break;
      default: 
         ppIRJumpKind(i->Pin.Goto.jk);
         vpanic("emit_PPC32Instr.Pin_Goto: unknown jump kind");
      }
      if (magic_num !=0) {
         vassert(magic_num < 0x10000);
         p = mkFormD(p, 14, 31, 0, magic_num);
      }


      /* Get the destination address into %r4 */
// CAB: Which reg?  On amd64,x86, does 'ret' use rax,eax somehow?
      r_dst = 4;
      if (i->Pin.Goto.dst->tag == Pri_Imm) {
         imm = i->Pin.Goto.dst->Pri.Imm.imm32;
         if (imm < 0x10000) {
            // addi r_dst,0,(imm & 0xFFFF)
            p = mkFormD(p, 14, r_dst, 0, imm);
         } else {
            // addi r_dst,0,(imm & 0xFFFF)
            // addis r_dst,r_dst,((imm >> 16) & 0xFFFF)
            p = mkFormD(p, 14, r_dst, 0, (imm & 0xFFFF));
            p = mkFormD(p, 15, r_dst, r_dst, ((imm>>16) & 0xFFFF));
         }
      } else {
         vassert(i->Pin.Goto.dst->tag == Pri_Reg);
         if (i->Pin.Goto.dst->Pri.Reg.reg != hregPPC32_GPR4()) {
            /* add r_dst, 0, r_src */
            r_src = iregNo(i->Pin.Goto.dst->Pri.Reg.reg);
            p = mkFormXO(p, 31, r_dst, 0, r_src, 0, 266, 0);
            /* noop */
            p = mkFormD(p, 24, 0, 0, 0);
         }
      }

      /* ret => bclr (always),0 */
      p = mkFormXL(p, 19, Pct_ALWAYS, 0, 0, 16, 0);
      goto done;
   }

   case Pin_CMov32: {
      vassert(i->Pin.CMov32.cond.test != Pct_ALWAYS);
      UInt r_dst = iregNo(i->Pin.CMov32.dst);
      PPC32CondCode cond = i->Pin.CMov32.cond;
      UInt imm, r_src;

      // branch (if cond false) over next instr
      // bc false,cond,8
      p = mkFormB(p, invertCondTest(cond.test), cond.flag, 8, 0, 0);

      // cond true: move src => dst
      switch (i->Pin.CMov32.src->tag) {
      case Pri_Imm:
         imm = i->Pin.CMov32.src->Pri.Imm.imm32;
         if (imm < 0x10000) {
            // addi r_dst,0,imm
            p = mkFormD(p, 14, r_dst, 0, imm);
         } else {
            // addi r_dst,0,(imm & 0xFFFF)
            // addis r_dst,r_dst,((imm >> 16) & 0xFFFF)
            p = mkFormD(p, 14, r_dst, 0, (imm & 0xFFFF));
            p = mkFormD(p, 15, r_dst, r_dst, ((imm>>16) & 0xFFFF));
         }
         break;
      case Pri_Reg:
         r_src = iregNo(i->Pin.CMov32.src->Pri.Reg.reg);
         if (r_src != r_dst) {
            /* add r_dst, 0, r_src */
            p = mkFormXO(p, 31, r_dst, 0, r_src, 0, 266, 0);
         }
         break;
      default: goto bad;
      }
      goto done;
   }

   case Pin_LoadEX: {
      UInt op1, op2, sz = i->Pin.LoadEX.sz;
      switch (i->Pin.LoadEX.src->tag) {
      case Pam_IR:
         if (sz == 2) {  // the only signed load
            op1 = (i->Pin.LoadEX.syned) ? 42: 40;
         } else {
            vassert(i->Pin.LoadEX.syned == False);
            op1 = (sz == 1) ? 34 : 32;   // 1:4
         }
         p = doAMode_IR(p, op1, i->Pin.LoadEX.dst, i->Pin.LoadEX.src);
         goto done;
      case Pam_RR:
         op1 = 31;
         if (sz == 2) {  // the only signed load
            op2 = (i->Pin.LoadEX.syned) ? 343: 279;
         } else {
            vassert(i->Pin.LoadEX.syned == False);
            op2 = (sz == 1) ? 87 : 23;   // 1:4
         }
         p = doAMode_RR(p, op1, op2, i->Pin.LoadEX.dst, i->Pin.LoadEX.src);
         goto done;
      default:
         goto bad;
      }
   }

   case Pin_Set32: {
      /* Make the destination register be 1 or 0, depending on whether
         the relevant condition holds. Yay! - mfcr doesn't change CR. */
      UInt r_dst = iregNo(i->Pin.Set32.dst);
      PPC32CondCode cond = i->Pin.Set32.cond;
      UInt shft;
      UInt r_tmp;

      if (cond.test == Pct_ALWAYS) {
         // just load 1 to dst => li dst,1
         p = mkFormD(p, 14, r_dst, 0, 1);
      } else {
         shft = 32 - cond.flag;
         r_tmp = 1;
// CAB: how choose r_tmp so don't kill anything else?

         // r_tmp = CR  => mfcr r_tmp
         p = mkFormX(p, 31, r_tmp, 0, 0, 19, 0);

         // r_dst = flag (rotate left and mask)
         //  => rlwinm r_dst,r_tmp,shft,31,31
         p = mkFormM(p, 21, r_dst, r_tmp, shft, 31, 31, 0);

         if (cond.test == Pct_FALSE) {
            // flip bit  => xori rD,rD,1
            p = mkFormD(p, 26, r_dst, r_dst, 1);
         }
      }
      goto done;
   }

//..    case Xin_Bsfr32:
//..       *p++ = 0x0F;
//..       if (i->Xin.Bsfr32.isFwds) {
//..          *p++ = 0xBC;
//..       } else {
//..          *p++ = 0xBD;
//..       }
//..       p = doAMode_R(p, i->Xin.Bsfr32.dst, i->Xin.Bsfr32.src);
//..       goto done;

   case Pin_MFence: {
// CAB: choose...
#if 1  // sync (Synchronise, p616)
      p = mkFormX(p, 31, 0, 0, 0, 598, 0);
#else  // isync (instruction synchronise, p467)
      p = mkFormXL(p, 19, 0, 0, 0, 150, 0);
#endif
      goto done;
   }

   case Pin_Store: {
      UInt op1, op2, sz = i->Pin.Store.sz;
      switch (i->Pin.Store.dst->tag) {
      case Pam_IR:
         op1 = (sz == 1) ? 38 : ((sz == 2) ? 44 : 36);      // 1:2:4
         p = doAMode_IR(p, op1, i->Pin.Store.src, i->Pin.Store.dst);
         goto done;
      case Pam_RR:
         op1 = 31;
         op2 = (sz == 1) ? 215 : ((sz == 2) ? 407 : 151);   // 1:2:4
         p = doAMode_RR(p, op1, op2, i->Pin.Store.src, i->Pin.Store.dst);
         goto done;
      default:
         goto bad;
      }
      goto done;
   }

//..    case Xin_FpUnary:
//..       /* gop %src, %dst
//..          --> ffree %st7 ; fld %st(src) ; fop %st(0) ; fstp %st(1+dst)
//..       */
//..       p = do_ffree_st7(p);
//..       p = do_fld_st(p, 0+hregNumber(i->Xin.FpUnary.src));
//..       p = do_fop1_st(p, i->Xin.FpUnary.op);
//..       p = do_fstp_st(p, 1+hregNumber(i->Xin.FpUnary.dst));
//..       goto done;
//.. 
//..    case Xin_FpBinary:
//..       if (i->Xin.FpBinary.op == Xfp_YL2X
//..           || i->Xin.FpBinary.op == Xfp_YL2XP1) {
//..          /* Have to do this specially. */
//..          /* ffree %st7 ; fld %st(srcL) ; 
//..             ffree %st7 ; fld %st(srcR+1) ; fyl2x{p1} ; fstp(1+dst) */
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 0+hregNumber(i->Xin.FpBinary.srcL));
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 1+hregNumber(i->Xin.FpBinary.srcR));
//..          *p++ = 0xD9; 
//..          *p++ = i->Xin.FpBinary.op==Xfp_YL2X ? 0xF1 : 0xF9;
//..          p = do_fstp_st(p, 1+hregNumber(i->Xin.FpBinary.dst));
//..          goto done;
//..       }
//..       if (i->Xin.FpBinary.op == Xfp_ATAN) {
//..          /* Have to do this specially. */
//..          /* ffree %st7 ; fld %st(srcL) ; 
//..             ffree %st7 ; fld %st(srcR+1) ; fpatan ; fstp(1+dst) */
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 0+hregNumber(i->Xin.FpBinary.srcL));
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 1+hregNumber(i->Xin.FpBinary.srcR));
//..          *p++ = 0xD9; *p++ = 0xF3;
//..          p = do_fstp_st(p, 1+hregNumber(i->Xin.FpBinary.dst));
//..          goto done;
//..       }
//..       if (i->Xin.FpBinary.op == Xfp_PREM
//..           || i->Xin.FpBinary.op == Xfp_PREM1
//..           || i->Xin.FpBinary.op == Xfp_SCALE) {
//..          /* Have to do this specially. */
//..          /* ffree %st7 ; fld %st(srcR) ; 
//..             ffree %st7 ; fld %st(srcL+1) ; fprem/fprem1/fscale ; fstp(2+dst) ; 
//..             fincstp ; ffree %st7 */
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 0+hregNumber(i->Xin.FpBinary.srcR));
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 1+hregNumber(i->Xin.FpBinary.srcL));
//..          *p++ = 0xD9;
//..          switch (i->Xin.FpBinary.op) {
//..             case Xfp_PREM: *p++ = 0xF8; break;
//..             case Xfp_PREM1: *p++ = 0xF5; break;
//..             case Xfp_SCALE: *p++ =  0xFD; break;
//..             default: vpanic("emitX86Instr(FpBinary,PREM/PREM1/SCALE)");
//..          }
//..          p = do_fstp_st(p, 2+hregNumber(i->Xin.FpBinary.dst));
//..          *p++ = 0xD9; *p++ = 0xF7;
//..          p = do_ffree_st7(p);
//..          goto done;
//..       }
//..       /* General case */
//..       /* gop %srcL, %srcR, %dst
//..          --> ffree %st7 ; fld %st(srcL) ; fop %st(1+srcR) ; fstp %st(1+dst)
//..       */
//..       p = do_ffree_st7(p);
//..       p = do_fld_st(p, 0+hregNumber(i->Xin.FpBinary.srcL));
//..       p = do_fop2_st(p, i->Xin.FpBinary.op, 
//..                         1+hregNumber(i->Xin.FpBinary.srcR));
//..       p = do_fstp_st(p, 1+hregNumber(i->Xin.FpBinary.dst));
//..       goto done;
//.. 
//..    case Xin_FpLdSt:
//..       vassert(i->Xin.FpLdSt.sz == 4 || i->Xin.FpLdSt.sz == 8);
//..       if (i->Xin.FpLdSt.isLoad) {
//..          /* Load from memory into %fakeN.  
//..             --> ffree %st(7) ; fld{s/l} amode ; fstp st(N+1) 
//..          */
//..          p = do_ffree_st7(p);
//..          *p++ = i->Xin.FpLdSt.sz==4 ? 0xD9 : 0xDD;
//..          p = doAMode_M(p, fake(0)/*subopcode*/, i->Xin.FpLdSt.addr);
//..          p = do_fstp_st(p, 1+hregNumber(i->Xin.FpLdSt.reg));
//..          goto done;
//..       } else {
//..          /* Store from %fakeN into memory.
//..             --> ffree %st(7) ; fld st(N) ; fstp{l|s} amode
//..          */
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 0+hregNumber(i->Xin.FpLdSt.reg));
//..          *p++ = i->Xin.FpLdSt.sz==4 ? 0xD9 : 0xDD;
//..          p = doAMode_M(p, fake(3)/*subopcode*/, i->Xin.FpLdSt.addr);
//..          goto done;
//..       }
//..       break;
//.. 
//..    case Xin_FpLdStI:
//..       if (i->Xin.FpLdStI.isLoad) {
//..          /* Load from memory into %fakeN, converting from an int.  
//..             --> ffree %st(7) ; fild{w/l/ll} amode ; fstp st(N+1) 
//..          */
//..          switch (i->Xin.FpLdStI.sz) {
//..             case 8:  opc = 0xDF; subopc_imm = 5; break;
//..             case 4:  opc = 0xDB; subopc_imm = 0; break;
//..             case 2:  vassert(0); opc = 0xDF; subopc_imm = 0; break;
//..             default: vpanic("emitX86Instr(Xin_FpLdStI-load)");
//..          }
//..          p = do_ffree_st7(p);
//..          *p++ = opc;
//..          p = doAMode_M(p, fake(subopc_imm)/*subopcode*/, i->Xin.FpLdStI.addr);
//..          p = do_fstp_st(p, 1+hregNumber(i->Xin.FpLdStI.reg));
//..          goto done;
//..       } else {
//..          /* Store from %fakeN into memory, converting to an int.
//..             --> ffree %st(7) ; fld st(N) ; fistp{w/l/ll} amode
//..          */
//..          switch (i->Xin.FpLdStI.sz) {
//..             case 8:  opc = 0xDF; subopc_imm = 7; break;
//..             case 4:  opc = 0xDB; subopc_imm = 3; break;
//..             case 2:  opc = 0xDF; subopc_imm = 3; break;
//..             default: vpanic("emitX86Instr(Xin_FpLdStI-store)");
//..          }
//..          p = do_ffree_st7(p);
//..          p = do_fld_st(p, 0+hregNumber(i->Xin.FpLdStI.reg));
//..          *p++ = opc;
//..          p = doAMode_M(p, fake(subopc_imm)/*subopcode*/, i->Xin.FpLdStI.addr);
//..          goto done;
//..       }
//..       break;
//.. 
//..    case Xin_Fp64to32:
//..       /* ffree %st7 ; fld %st(src) */
//..       p = do_ffree_st7(p);
//..       p = do_fld_st(p, 0+fregNo(i->Xin.Fp64to32.src));
//..       /* subl $4, %esp */
//..       *p++ = 0x83; *p++ = 0xEC; *p++ = 0x04;
//..       /* fstps (%esp) */
//..       *p++ = 0xD9; *p++ = 0x1C; *p++ = 0x24;
//..       /* flds (%esp) */
//..       *p++ = 0xD9; *p++ = 0x04; *p++ = 0x24;
//..       /* addl $4, %esp */
//..       *p++ = 0x83; *p++ = 0xC4; *p++ = 0x04;
//..       /* fstp %st(1+dst) */
//..       p = do_fstp_st(p, 1+fregNo(i->Xin.Fp64to32.dst));
//..       goto done;
//.. 
//..    case Xin_FpCMov:
//..       /* jmp fwds if !condition */
//..       *p++ = 0x70 + (i->Xin.FpCMov.cond ^ 1);
//..       *p++ = 0; /* # of bytes in the next bit, which we don't know yet */
//..       ptmp = p;
//.. 
//..       /* ffree %st7 ; fld %st(src) ; fstp %st(1+dst) */
//..       p = do_ffree_st7(p);
//..       p = do_fld_st(p, 0+fregNo(i->Xin.FpCMov.src));
//..       p = do_fstp_st(p, 1+fregNo(i->Xin.FpCMov.dst));
//.. 
//..       /* Fill in the jump offset. */
//..       *(ptmp-1) = p - ptmp;
//..       goto done;
//.. 
//..    case Xin_FpLdStCW:
//..       if (i->Xin.FpLdStCW.isLoad) {
//..          *p++ = 0xD9;
//..          p = doAMode_M(p, fake(5)/*subopcode*/, i->Xin.FpLdStCW.addr);
//..       } else {
//..          vassert(0);
//..       }
//..       goto done;
//.. 
//..    case Xin_FpStSW_AX:
//..       /* note, this emits fnstsw %ax, not fstsw %ax */
//..       *p++ = 0xDF;
//..       *p++ = 0xE0;
//..       goto done;
//.. 
//..    case Xin_FpCmp:
//..       /* gcmp %fL, %fR, %dst
//..          -> ffree %st7; fpush %fL ; fucomp %(fR+1) ; 
//..             fnstsw %ax ; movl %eax, %dst 
//..       */
//..       /* ffree %st7 */
//..       p = do_ffree_st7(p);
//..       /* fpush %fL */
//..       p = do_fld_st(p, 0+fregNo(i->Xin.FpCmp.srcL));
//..       /* fucomp %(fR+1) */
//..       *p++ = 0xDD;
//..       *p++ = 0xE8 + (7 & (1+fregNo(i->Xin.FpCmp.srcR)));
//..       /* fnstsw %ax */
//..       *p++ = 0xDF;
//..       *p++ = 0xE0;
//..       /*  movl %eax, %dst */
//..       *p++ = 0x89;
//..       p = doAMode_R(p, hregX86_EAX(), i->Xin.FpCmp.dst);
//..       goto done;
//.. 
//..    case Xin_SseConst: {
//..       UShort con = i->Xin.SseConst.con;
//..       p = push_word_from_tags(p, (con >> 12) & 0xF);
//..       p = push_word_from_tags(p, (con >> 8) & 0xF);
//..       p = push_word_from_tags(p, (con >> 4) & 0xF);
//..       p = push_word_from_tags(p, con & 0xF);
//..       /* movl (%esp), %xmm-dst */
//..       *p++ = 0x0F;
//..       *p++ = 0x10;
//..       *p++ = 0x04 + 8 * (7 & vregNo(i->Xin.SseConst.dst));
//..       *p++ = 0x24;
//..       /* addl $16, %esp */
//..       *p++ = 0x83;
//..       *p++ = 0xC4;
//..       *p++ = 0x10;
//..       goto done;
//..    }
//.. 
//..    case Xin_SseLdSt:
//..       *p++ = 0x0F; 
//..       *p++ = i->Xin.SseLdSt.isLoad ? 0x10 : 0x11;
//..       p = doAMode_M(p, fake(vregNo(i->Xin.SseLdSt.reg)), i->Xin.SseLdSt.addr);
//..       goto done;
//.. 
//..    case Xin_SseLdzLO:
//..       vassert(i->Xin.SseLdzLO.sz == 4 || i->Xin.SseLdzLO.sz == 8);
//..       /* movs[sd] amode, %xmm-dst */
//..       *p++ = i->Xin.SseLdzLO.sz==4 ? 0xF3 : 0xF2;
//..       *p++ = 0x0F; 
//..       *p++ = 0x10; 
//..       p = doAMode_M(p, fake(vregNo(i->Xin.SseLdzLO.reg)), 
//..                        i->Xin.SseLdzLO.addr);
//..       goto done;
//.. 
//..    case Xin_Sse32Fx4:
//..       xtra = 0;
//..       *p++ = 0x0F;
//..       switch (i->Xin.Sse32Fx4.op) {
//..          case Xsse_ADDF:   *p++ = 0x58; break;
//..          case Xsse_DIVF:   *p++ = 0x5E; break;
//..          case Xsse_MAXF:   *p++ = 0x5F; break;
//..          case Xsse_MINF:   *p++ = 0x5D; break;
//..          case Xsse_MULF:   *p++ = 0x59; break;
//..          case Xsse_RCPF:   *p++ = 0x53; break;
//..          case Xsse_RSQRTF: *p++ = 0x52; break;
//..          case Xsse_SQRTF:  *p++ = 0x51; break;
//..          case Xsse_SUBF:   *p++ = 0x5C; break;
//..          case Xsse_CMPEQF: *p++ = 0xC2; xtra = 0x100; break;
//..          case Xsse_CMPLTF: *p++ = 0xC2; xtra = 0x101; break;
//..          case Xsse_CMPLEF: *p++ = 0xC2; xtra = 0x102; break;
//..          default: goto bad;
//..       }
//..       p = doAMode_R(p, fake(vregNo(i->Xin.Sse32Fx4.dst)),
//..                        fake(vregNo(i->Xin.Sse32Fx4.src)) );
//..       if (xtra & 0x100)
//..          *p++ = (UChar)(xtra & 0xFF);
//..       goto done;
//.. 
//..    case Xin_Sse64Fx2:
//..       xtra = 0;
//..       *p++ = 0x66;
//..       *p++ = 0x0F;
//..       switch (i->Xin.Sse64Fx2.op) {
//..          case Xsse_ADDF:   *p++ = 0x58; break;
//..          case Xsse_DIVF:   *p++ = 0x5E; break;
//..          case Xsse_MAXF:   *p++ = 0x5F; break;
//..          case Xsse_MINF:   *p++ = 0x5D; break;
//..          case Xsse_MULF:   *p++ = 0x59; break;
//..          case Xsse_RCPF:   *p++ = 0x53; break;
//..          case Xsse_RSQRTF: *p++ = 0x52; break;
//..          case Xsse_SQRTF:  *p++ = 0x51; break;
//..          case Xsse_SUBF:   *p++ = 0x5C; break;
//..          case Xsse_CMPEQF: *p++ = 0xC2; xtra = 0x100; break;
//..          case Xsse_CMPLTF: *p++ = 0xC2; xtra = 0x101; break;
//..          case Xsse_CMPLEF: *p++ = 0xC2; xtra = 0x102; break;
//..          default: goto bad;
//..       }
//..       p = doAMode_R(p, fake(vregNo(i->Xin.Sse64Fx2.dst)),
//..                        fake(vregNo(i->Xin.Sse64Fx2.src)) );
//..       if (xtra & 0x100)
//..          *p++ = (UChar)(xtra & 0xFF);
//..       goto done;
//.. 
//..    case Xin_Sse32FLo:
//..       xtra = 0;
//..       *p++ = 0xF3;
//..       *p++ = 0x0F;
//..       switch (i->Xin.Sse32FLo.op) {
//..          case Xsse_ADDF:   *p++ = 0x58; break;
//..          case Xsse_DIVF:   *p++ = 0x5E; break;
//..          case Xsse_MAXF:   *p++ = 0x5F; break;
//..          case Xsse_MINF:   *p++ = 0x5D; break;
//..          case Xsse_MULF:   *p++ = 0x59; break;
//..          case Xsse_RCPF:   *p++ = 0x53; break;
//..          case Xsse_RSQRTF: *p++ = 0x52; break;
//..          case Xsse_SQRTF:  *p++ = 0x51; break;
//..          case Xsse_SUBF:   *p++ = 0x5C; break;
//..          case Xsse_CMPEQF: *p++ = 0xC2; xtra = 0x100; break;
//..          case Xsse_CMPLTF: *p++ = 0xC2; xtra = 0x101; break;
//..          case Xsse_CMPLEF: *p++ = 0xC2; xtra = 0x102; break;
//..          default: goto bad;
//..       }
//..       p = doAMode_R(p, fake(vregNo(i->Xin.Sse32FLo.dst)),
//..                        fake(vregNo(i->Xin.Sse32FLo.src)) );
//..       if (xtra & 0x100)
//..          *p++ = (UChar)(xtra & 0xFF);
//..       goto done;
//.. 
//..    case Xin_Sse64FLo:
//..       xtra = 0;
//..       *p++ = 0xF2;
//..       *p++ = 0x0F;
//..       switch (i->Xin.Sse64FLo.op) {
//..          case Xsse_ADDF:   *p++ = 0x58; break;
//..          case Xsse_DIVF:   *p++ = 0x5E; break;
//..          case Xsse_MAXF:   *p++ = 0x5F; break;
//..          case Xsse_MINF:   *p++ = 0x5D; break;
//..          case Xsse_MULF:   *p++ = 0x59; break;
//..          case Xsse_RCPF:   *p++ = 0x53; break;
//..          case Xsse_RSQRTF: *p++ = 0x52; break;
//..          case Xsse_SQRTF:  *p++ = 0x51; break;
//..          case Xsse_SUBF:   *p++ = 0x5C; break;
//..          case Xsse_CMPEQF: *p++ = 0xC2; xtra = 0x100; break;
//..          case Xsse_CMPLTF: *p++ = 0xC2; xtra = 0x101; break;
//..          case Xsse_CMPLEF: *p++ = 0xC2; xtra = 0x102; break;
//..          default: goto bad;
//..       }
//..       p = doAMode_R(p, fake(vregNo(i->Xin.Sse64FLo.dst)),
//..                        fake(vregNo(i->Xin.Sse64FLo.src)) );
//..       if (xtra & 0x100)
//..          *p++ = (UChar)(xtra & 0xFF);
//..       goto done;
//.. 
//..    case Xin_SseReRg:
//.. #     define XX(_n) *p++ = (_n)
//..       switch (i->Xin.SseReRg.op) {
//..          case Xsse_MOV:     /*movups*/ XX(0x0F); XX(0x10); break;
//..          case Xsse_OR:                 XX(0x0F); XX(0x56); break;
//..          case Xsse_XOR:                XX(0x0F); XX(0x57); break;
//..          case Xsse_AND:                XX(0x0F); XX(0x54); break;
//..          case Xsse_PACKSSD:  XX(0x66); XX(0x0F); XX(0x6B); break;
//..          case Xsse_PACKSSW:  XX(0x66); XX(0x0F); XX(0x63); break;
//..          case Xsse_PACKUSW:  XX(0x66); XX(0x0F); XX(0x67); break;
//..          case Xsse_ADD8:     XX(0x66); XX(0x0F); XX(0xFC); break;
//..          case Xsse_ADD16:    XX(0x66); XX(0x0F); XX(0xFD); break;
//..          case Xsse_ADD32:    XX(0x66); XX(0x0F); XX(0xFE); break;
//..          case Xsse_ADD64:    XX(0x66); XX(0x0F); XX(0xD4); break;
//..          case Xsse_QADD8S:   XX(0x66); XX(0x0F); XX(0xEC); break;
//..          case Xsse_QADD16S:  XX(0x66); XX(0x0F); XX(0xED); break;
//..          case Xsse_QADD8U:   XX(0x66); XX(0x0F); XX(0xDC); break;
//..          case Xsse_QADD16U:  XX(0x66); XX(0x0F); XX(0xDD); break;
//..          case Xsse_AVG8U:    XX(0x66); XX(0x0F); XX(0xE0); break;
//..          case Xsse_AVG16U:   XX(0x66); XX(0x0F); XX(0xE3); break;
//..          case Xsse_CMPEQ8:   XX(0x66); XX(0x0F); XX(0x74); break;
//..          case Xsse_CMPEQ16:  XX(0x66); XX(0x0F); XX(0x75); break;
//..          case Xsse_CMPEQ32:  XX(0x66); XX(0x0F); XX(0x76); break;
//..          case Xsse_CMPGT8S:  XX(0x66); XX(0x0F); XX(0x64); break;
//..          case Xsse_CMPGT16S: XX(0x66); XX(0x0F); XX(0x65); break;
//..          case Xsse_CMPGT32S: XX(0x66); XX(0x0F); XX(0x66); break;
//..          case Xsse_MAX16S:   XX(0x66); XX(0x0F); XX(0xEE); break;
//..          case Xsse_MAX8U:    XX(0x66); XX(0x0F); XX(0xDE); break;
//..          case Xsse_MIN16S:   XX(0x66); XX(0x0F); XX(0xEA); break;
//..          case Xsse_MIN8U:    XX(0x66); XX(0x0F); XX(0xDA); break;
//..          case Xsse_MULHI16U: XX(0x66); XX(0x0F); XX(0xE4); break;
//..          case Xsse_MULHI16S: XX(0x66); XX(0x0F); XX(0xE5); break;
//..          case Xsse_MUL16:    XX(0x66); XX(0x0F); XX(0xD5); break;
//..          case Xsse_SHL16:    XX(0x66); XX(0x0F); XX(0xF1); break;
//..          case Xsse_SHL32:    XX(0x66); XX(0x0F); XX(0xF2); break;
//..          case Xsse_SHL64:    XX(0x66); XX(0x0F); XX(0xF3); break;
//..          case Xsse_SAR16:    XX(0x66); XX(0x0F); XX(0xE1); break;
//..          case Xsse_SAR32:    XX(0x66); XX(0x0F); XX(0xE2); break;
//..          case Xsse_SHR16:    XX(0x66); XX(0x0F); XX(0xD1); break;
//..          case Xsse_SHR32:    XX(0x66); XX(0x0F); XX(0xD2); break;
//..          case Xsse_SHR64:    XX(0x66); XX(0x0F); XX(0xD3); break;
//..          case Xsse_SUB8:     XX(0x66); XX(0x0F); XX(0xF8); break;
//..          case Xsse_SUB16:    XX(0x66); XX(0x0F); XX(0xF9); break;
//..          case Xsse_SUB32:    XX(0x66); XX(0x0F); XX(0xFA); break;
//..          case Xsse_SUB64:    XX(0x66); XX(0x0F); XX(0xFB); break;
//..          case Xsse_QSUB8S:   XX(0x66); XX(0x0F); XX(0xE8); break;
//..          case Xsse_QSUB16S:  XX(0x66); XX(0x0F); XX(0xE9); break;
//..          case Xsse_QSUB8U:   XX(0x66); XX(0x0F); XX(0xD8); break;
//..          case Xsse_QSUB16U:  XX(0x66); XX(0x0F); XX(0xD9); break;
//..          case Xsse_UNPCKHB:  XX(0x66); XX(0x0F); XX(0x68); break;
//..          case Xsse_UNPCKHW:  XX(0x66); XX(0x0F); XX(0x69); break;
//..          case Xsse_UNPCKHD:  XX(0x66); XX(0x0F); XX(0x6A); break;
//..          case Xsse_UNPCKHQ:  XX(0x66); XX(0x0F); XX(0x6D); break;
//..          case Xsse_UNPCKLB:  XX(0x66); XX(0x0F); XX(0x60); break;
//..          case Xsse_UNPCKLW:  XX(0x66); XX(0x0F); XX(0x61); break;
//..          case Xsse_UNPCKLD:  XX(0x66); XX(0x0F); XX(0x62); break;
//..          case Xsse_UNPCKLQ:  XX(0x66); XX(0x0F); XX(0x6C); break;
//..          default: goto bad;
//..       }
//..       p = doAMode_R(p, fake(vregNo(i->Xin.SseReRg.dst)),
//..                        fake(vregNo(i->Xin.SseReRg.src)) );
//.. #     undef XX
//..       goto done;
//.. 
//..    case Xin_SseCMov:
//..       /* jmp fwds if !condition */
//..       *p++ = 0x70 + (i->Xin.SseCMov.cond ^ 1);
//..       *p++ = 0; /* # of bytes in the next bit, which we don't know yet */
//..       ptmp = p;
//.. 
//..       /* movaps %src, %dst */
//..       *p++ = 0x0F; 
//..       *p++ = 0x28; 
//..       p = doAMode_R(p, fake(vregNo(i->Xin.SseCMov.dst)),
//..                        fake(vregNo(i->Xin.SseCMov.src)) );
//.. 
//..       /* Fill in the jump offset. */
//..       *(ptmp-1) = p - ptmp;
//..       goto done;
//.. 
//..    case Xin_SseShuf:
//..       *p++ = 0x66; 
//..       *p++ = 0x0F; 
//..       *p++ = 0x70; 
//..       p = doAMode_R(p, fake(vregNo(i->Xin.SseShuf.dst)),
//..                        fake(vregNo(i->Xin.SseShuf.src)) );
//..       *p++ = (UChar)(i->Xin.SseShuf.order);
//..       goto done;

   default: 
      goto bad;
   }

  bad:
   vex_printf("\n=> ");
   ppPPC32Instr(i);
   vpanic("emit_PPC32Instr");
   /*NOTREACHED*/
   
  done:
   vassert(p - &buf[0] <= 32);
   return p - &buf[0];

#  undef fake
}

/*---------------------------------------------------------------*/
/*--- end                                  host-ppc32/hdefs.c ---*/
/*---------------------------------------------------------------*/
