
/*---------------------------------------------------------------*/
/*---                                                         ---*/
/*--- This file (ir/iropt.c) is                               ---*/
/*--- Copyright (c) 2004 OpenWorks LLP.  All rights reserved. ---*/
/*---                                                         ---*/
/*---------------------------------------------------------------*/

#include "libvex_basictypes.h"
#include "libvex_ir.h"
#include "libvex.h"

#include "main/vex_util.h"
#include "ir/iropt.h"


/*---------------------------------------------------------------*/
/*--- Finite mappery, of a sort                               ---*/
/*---------------------------------------------------------------*/

/* General map from 64-bit thing 64-bit thing.  Could be done faster
   by hashing. */

typedef
   struct {
      Bool*  inuse;
      ULong* key;
      ULong* val;
      Int    size;
      Int    used;
   }
   Hash64;

static Hash64* newH64 ( void )
{
   Hash64* h = LibVEX_Alloc(sizeof(Hash64));
   h->size   = 4;
   h->used   = 0;
   h->inuse  = LibVEX_Alloc(h->size * sizeof(Bool));
   h->key    = LibVEX_Alloc(h->size * sizeof(ULong));
   h->val    = LibVEX_Alloc(h->size * sizeof(ULong));
   return h;
}


/* Look up key in the map. */

static Bool lookupH64 ( Hash64* h, /*OUT*/ULong* val, ULong key )
{
   Int i;
   //vex_printf("lookupH64(%llx)\n", key );
   for (i = 0; i < h->used; i++) {
      if (h->inuse[i] && h->key[i] == key) {
         *val = h->val[i];
         return True;
      }
   }
   return False;
}


/* Delete any binding for key in h. */

static void delFromH64 ( Hash64* h, ULong key )
{
   Int i;
   for (i = 0; i < h->used; i++) {
      if (h->inuse[i] && h->key[i] == key) {
         h->inuse[i] = False;
         return;
      }
   }
}



/* Add key->val to the map.  Replaces any existing binding for key. */

static void addToH64 ( Hash64* h, ULong key, ULong val )
{
   Int i, j;

   //vex_printf("addToH64(%llx, %llx)\n", key, val);
   /* Find and replace existing binding, if any. */
   for (i = 0; i < h->used; i++) {
      if (h->inuse[i] && h->key[i] == key) {
         h->val[i] = val;
         return;
      }
   }

   /* Ensure a space is available. */
   if (h->used == h->size) {
      /* Copy into arrays twice the size. */
      Bool*  inuse2 = LibVEX_Alloc(2 * h->size * sizeof(Bool));
      ULong* key2   = LibVEX_Alloc(2 * h->size * sizeof(ULong));
      ULong* val2   = LibVEX_Alloc(2 * h->size * sizeof(ULong));
      for (i = j = 0; i < h->size; i++) {
         if (!h->inuse[i]) continue;
         inuse2[j] = True;
         key2[j] = h->key[i];
         val2[j] = h->val[i];
         j++;
      }
      h->used = j;
      h->size *= 2;
      h->inuse = inuse2;
      h->key = key2;
      h->val = val2;
   }

   /* Finally, add it. */
   vassert(h->used < h->size);
   h->inuse[h->used] = True;
   h->key[h->used] = key;
   h->val[h->used] = val;
   h->used++;
}


/*---------------------------------------------------------------*/
/*--- Flattening out a BB into pure SSA form                  ---*/
/*---------------------------------------------------------------*/

/* Clone the NULL-terminated vector of IRExpr*s attached to a
   CCall. */

static IRExpr** copyIexCCallArgs ( IRExpr** vec )
{
   Int      i;
   IRExpr** newvec;
   for (i = 0; vec[i]; i++)
      ;
   newvec = LibVEX_Alloc((i+1)*sizeof(IRExpr*));
   for (i = 0; vec[i]; i++)
      newvec[i] = vec[i];
   newvec[i] = NULL;
   return newvec;
}


/* Flatten out 'ex' so it is atomic, returning a new expression with
   the same value, after having appended extra IRTemp assignments to
   the end of 'bb'. */

static IRExpr* flatten_Expr ( IRBB* bb, IRExpr* ex )
{
   Int i;
   IRExpr** newargs;
   IRType ty = typeOfIRExpr(bb->tyenv, ex);
   IRTemp t1;

   switch (ex->tag) {

      case Iex_Get:
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, 
            IRStmt_Tmp(t1, ex));
         return IRExpr_Tmp(t1);

      case Iex_Binop:
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, IRStmt_Tmp(t1, 
            IRExpr_Binop(ex->Iex.Binop.op,
                         flatten_Expr(bb, ex->Iex.Binop.arg1),
                         flatten_Expr(bb, ex->Iex.Binop.arg2))));
         return IRExpr_Tmp(t1);

      case Iex_Unop:
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, IRStmt_Tmp(t1, 
            IRExpr_Unop(ex->Iex.Unop.op,
                        flatten_Expr(bb, ex->Iex.Unop.arg))));
         return IRExpr_Tmp(t1);

      case Iex_LDle:
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, IRStmt_Tmp(t1,
            IRExpr_LDle(ex->Iex.LDle.ty, 
                        flatten_Expr(bb, ex->Iex.LDle.addr))));
         return IRExpr_Tmp(t1);

      case Iex_CCall:
         newargs = copyIexCCallArgs(ex->Iex.CCall.args);
         for (i = 0; newargs[i]; i++)
            newargs[i] = flatten_Expr(bb, newargs[i]);
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, IRStmt_Tmp(t1,
            IRExpr_CCall(ex->Iex.CCall.name,
                         ex->Iex.CCall.retty,
                         newargs)));
         return IRExpr_Tmp(t1);

      case Iex_Mux0X:
         t1 = newIRTemp(bb->tyenv, ty);
         addStmtToIRBB(bb, IRStmt_Tmp(t1,
            IRExpr_Mux0X(flatten_Expr(bb, ex->Iex.Mux0X.cond),
                         flatten_Expr(bb, ex->Iex.Mux0X.expr0),
                         flatten_Expr(bb, ex->Iex.Mux0X.exprX))));
         return IRExpr_Tmp(t1);

      case Iex_Const:
      case Iex_Tmp:
         return ex;

      default:
         vex_printf("\n");
         ppIRExpr(ex); 
         vex_printf("\n");
         vpanic("flatten_Expr");
   }
}


/* Append a completely flattened form of 'st' to the end of 'bb'. */

static void flatten_Stmt ( IRBB* bb, IRStmt* st )
{
   IRExpr *e1, *e2;
   switch (st->tag) {
      case Ist_Put:
         e1 = flatten_Expr(bb, st->Ist.Put.expr);
         addStmtToIRBB(bb, IRStmt_Put(st->Ist.Put.offset, e1));
         break;
#if 0
      case Ist_PutI:
        e1 = flatten_Expr(bb, st->Ist.PutI.offset);
        e2 = flatten_Expr(bb, st->Ist.PutI.expr);
        addStmtToIRBB(bb, IRStmt_PutI(e1, e2, st->Ist.PutI.minoff,
                          st->Ist.PutI.maxoff));
        break;
#endif
      case Ist_Tmp:
         e1 = flatten_Expr(bb, st->Ist.Tmp.expr);
         addStmtToIRBB(bb, IRStmt_Tmp(st->Ist.Tmp.tmp, e1));
         break;
      case Ist_STle:
         e1 = flatten_Expr(bb, st->Ist.STle.addr);
         e2 = flatten_Expr(bb, st->Ist.STle.data);
         addStmtToIRBB(bb, IRStmt_STle(e1,e2));
         break;
      case Ist_Exit:
         e1 = flatten_Expr(bb, st->Ist.Exit.cond);
         addStmtToIRBB(bb, IRStmt_Exit(e1, st->Ist.Exit.dst));
         break;
      default:
         vex_printf("\n");
         ppIRStmt(st); 
         vex_printf("\n");
         vpanic("flatten_Stmt");
   }
}

static IRBB* flatten_BB ( IRBB* in )
{
   Int   i;
   IRBB* out;
   out = emptyIRBB();
   out->tyenv = copyIRTypeEnv( in->tyenv );
   for (i = 0; i < in->stmts_used; i++)
      flatten_Stmt( out, in->stmts[i] );
   out->next     = flatten_Expr( out, in->next );
   out->jumpkind = in->jumpkind;
   return out;
}



/*---------------------------------------------------------------*/
/*--- Constant propagation and folding                        ---*/
/*---------------------------------------------------------------*/

static IRExpr* fold_Expr ( IRExpr* e )
{
   IRExpr* e2 = e; /* e2 is the result of folding e, if possible */

   /* UNARY ops */
   if (e->tag == Iex_Unop
       && e->Iex.Unop.arg->tag == Iex_Const) {
      switch (e->Iex.Unop.op) {
         case Iop_8Uto32:
            e2 = IRExpr_Const(IRConst_U32(
                    0xFF & e->Iex.Unop.arg->Iex.Const.con->Ico.U8));
            break;
         case Iop_16Uto32:
            e2 = IRExpr_Const(IRConst_U32(
                    0xFFFF & e->Iex.Unop.arg->Iex.Const.con->Ico.U16));
            break;
         default: 
            goto unhandled;
      }
   }

   /* BINARY ops */
   if (e->tag == Iex_Binop) {
      if (e->Iex.Binop.arg1->tag == Iex_Const
          && e->Iex.Binop.arg2->tag == Iex_Const) {
         /* cases where both args are consts */
         switch (e->Iex.Binop.op) {
            case Iop_And8:
               e2 = IRExpr_Const(IRConst_U8(0xFF & 
                       (e->Iex.Binop.arg1->Iex.Const.con->Ico.U8
                        & e->Iex.Binop.arg2->Iex.Const.con->Ico.U8)));
               break;
            case Iop_Sub8:
               e2 = IRExpr_Const(IRConst_U8(0xFF & 
                       (e->Iex.Binop.arg1->Iex.Const.con->Ico.U8
                        - e->Iex.Binop.arg2->Iex.Const.con->Ico.U8)));
               break;
           default:
              goto unhandled;
	 }
      } else {
         /* other cases (identities, etc) */
         if (e->Iex.Binop.op == Iop_Add32
             && e->Iex.Binop.arg2->tag == Iex_Const
             && e->Iex.Binop.arg2->Iex.Const.con->Ico.U32 == 0) {
            e2 = e->Iex.Binop.arg1;
         }
      }
   }

   /* Mux0X */
   if (e->tag == Iex_Mux0X
       && e->Iex.Mux0X.cond->tag == Iex_Const) {
      Bool zero;
      /* assured us by the IR type rules */
      vassert(e->Iex.Mux0X.cond->Iex.Const.con->tag == Ico_U8);
      zero = 0 == e->Iex.Mux0X.cond->Iex.Const.con->Ico.U8;
      e2 = zero ? e->Iex.Mux0X.expr0 : e->Iex.Mux0X.exprX;
   }

   if (e2 != e) {
     vex_printf("FOLD: "); 
      ppIRExpr(e); vex_printf("  ->  ");
      ppIRExpr(e2); vex_printf("\n");
   }

   return e2;

 unhandled:
   vex_printf("\n\n");
   ppIRExpr(e);
   vpanic("fold_Expr: no rule for the above");
}


static Bool isAtom ( IRExpr* e )
{
   return e->tag == Iex_Tmp || e->tag == Iex_Const;
}


/* Apply the subst to a simple 1-level expression -- guaranteed to be
   1-level due to previous flattening pass. */

static IRExpr* subst_Expr ( Hash64* env, IRExpr* ex )
{
   if (ex->tag == Iex_Tmp) {
      ULong res;
      if (lookupH64(env, &res, (ULong)ex->Iex.Tmp.tmp)) {
         return (IRExpr*)res;
      } else {
         /* not bound in env */
         return ex;
      }
   }

   if (ex->tag == Iex_Const)
      return ex;
   if (ex->tag == Iex_Get)
      return ex;

   if (ex->tag == Iex_Binop) {
      vassert(isAtom(ex->Iex.Binop.arg1));
      vassert(isAtom(ex->Iex.Binop.arg2));
      return IRExpr_Binop(
                ex->Iex.Binop.op,
                subst_Expr(env, ex->Iex.Binop.arg1),
                subst_Expr(env, ex->Iex.Binop.arg2)
             );
   }

   if (ex->tag == Iex_Unop) {
      vassert(isAtom(ex->Iex.Unop.arg));
      return IRExpr_Unop(
                ex->Iex.Unop.op,
                subst_Expr(env, ex->Iex.Unop.arg)
             );
   }

   if (ex->tag == Iex_LDle) {
      vassert(isAtom(ex->Iex.LDle.addr));
      return IRExpr_LDle(
                ex->Iex.LDle.ty,
                subst_Expr(env, ex->Iex.LDle.addr)
             );
   }

   if (ex->tag == Iex_CCall) {
      Int      i;
      IRExpr** args2 = copyIexCCallArgs ( ex->Iex.CCall.args );
      for (i = 0; args2[i]; i++) {
         vassert(isAtom(args2[i]));
         args2[i] = subst_Expr(env, args2[i]);
      }
      return IRExpr_CCall(
                ex->Iex.CCall.name,
                ex->Iex.CCall.retty,
                args2 
             );
   }

   if (ex->tag == Iex_Mux0X) {
      vassert(isAtom(ex->Iex.Mux0X.cond));
      vassert(isAtom(ex->Iex.Mux0X.expr0));
      vassert(isAtom(ex->Iex.Mux0X.exprX));
      return IRExpr_Mux0X(
                subst_Expr(env, ex->Iex.Mux0X.cond),
                subst_Expr(env, ex->Iex.Mux0X.expr0),
                subst_Expr(env, ex->Iex.Mux0X.exprX)
             );
   }

   vex_printf("\n\n");
   ppIRExpr(ex);
   vpanic("subst_Expr");
}


/* Apply the subst to stmt, then fold the result as much as possible.
   Much simplified due to stmt being previously flattened. */

static IRStmt* subst_and_fold_Stmt ( Hash64* env, IRStmt* st )
{
#  if 0
   vex_printf("\nsubst and fold stmt\n");
   ppIRStmt(st);
   vex_printf("\n");
#  endif

   if (st->tag == Ist_Put) {
      vassert(isAtom(st->Ist.Put.expr));
      return IRStmt_Put(
                st->Ist.Put.offset, 
                fold_Expr(subst_Expr(env, st->Ist.Put.expr)) 
             );
   }

   if (st->tag == Ist_Tmp) {
      /* This is the one place where an expr (st->Ist.Tmp.expr) is
         allowed to be more than just a constant or a tmp. */
      return IRStmt_Tmp(
                st->Ist.Tmp.tmp,
                fold_Expr(subst_Expr(env, st->Ist.Tmp.expr))
             );
   }

   if (st->tag == Ist_STle) {
      vassert(isAtom(st->Ist.STle.addr));
      vassert(isAtom(st->Ist.STle.data));
      return IRStmt_STle(
                fold_Expr(subst_Expr(env, st->Ist.STle.addr)),
                fold_Expr(subst_Expr(env, st->Ist.STle.data))
             );
   }

   if (st->tag == Ist_Exit) {
     vassert(isAtom(st->Ist.Exit.cond));
     return IRStmt_Exit(
               fold_Expr(subst_Expr(env, st->Ist.Exit.cond)),
               st->Ist.Exit.dst
            );
   }

   vex_printf("\n");
   ppIRStmt(st);
   vpanic("subst_and_fold_Stmt");
}


static IRBB* cprop_BB ( IRBB* in )
{
   Int     i;
   IRBB*   out;
   Hash64* env;
   IRStmt* st2;

   out = emptyIRBB();
   out->tyenv = copyIRTypeEnv( in->tyenv );

   /* Set up the env with which travels forward.  This holds a
      substitution, mapping IRTemps to atoms, that is, IRExprs which
      are either IRTemps or IRConsts.  Thus, copy and constant
      propagation is done.  The environment is to be applied as we
      move along.  Keys are IRTemps.  Values are IRExpr*s.
   */
   env = newH64();

   /* For each original SSA-form stmt ... */
   for (i = 0; i < in->stmts_used; i++) {

      /* First apply the substitution to the current stmt.  This
         propagates in any constants and tmp-tmp assignments
         accumulated prior to this point.  As part of the subst_Stmt
         call, also then fold any constant expressions resulting. */

      st2 = subst_and_fold_Stmt( env, in->stmts[i] );

      /* Now consider what the stmt looks like.  If it's of the form
         't = const' or 't1 = t2', add it to the running environment
         and not to the output BB.  Otherwise, add it to the output
         BB. */

      if (st2->tag == Ist_Tmp && st2->Ist.Tmp.expr->tag == Iex_Const) {
         /* 't = const' -- add to env.  
             The pair (IRTemp, IRExpr*) is added. */
         addToH64(env, (ULong)(st2->Ist.Tmp.tmp),
                       (ULong)(st2->Ist.Tmp.expr) );
      }
      else
      if (st2->tag == Ist_Tmp && st2->Ist.Tmp.expr->tag == Iex_Tmp) {
         /* 't1 = t2' -- add to env.  
             The pair (IRTemp, IRExpr*) is added. */
         addToH64(env, (ULong)(st2->Ist.Tmp.tmp),
                       (ULong)(st2->Ist.Tmp.expr) );
      }
      else {
         /* Not interesting, copy st2 into the output block. */
         addStmtToIRBB( out, st2 );
      }
   }


   out->next     = subst_Expr( env, in->next );
   out->jumpkind = in->jumpkind;
   return out;
}



/*---------------------------------------------------------------*/
/*--- iropt main                                              ---*/
/*---------------------------------------------------------------*/

/* Rules of the game:

   - IRExpr/IRStmt trees should be treated as immutable, as they
     may get shared.  So never change a field of such a tree node;
     instead construct and return a new one if needed.
*/

/* exported from this file */
IRBB* do_iropt_BB ( IRBB* bb0 )
{
   Bool verbose = False;
   IRBB *flat, *cpd;
   flat = flatten_BB ( bb0 );
   if (verbose) {
      vex_printf("\n************************ FLAT\n\n" );
      ppIRBB(flat);
   }
   cpd  = cprop_BB ( flat );
   if (verbose) {
      vex_printf("\n========= CPROPD\n\n" );
      ppIRBB(cpd);
   }
   return cpd;
}


/*---------------------------------------------------------------*/
/*--- end                                          ir/iropt.c ---*/
/*---------------------------------------------------------------*/
