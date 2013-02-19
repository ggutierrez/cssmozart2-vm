#ifndef __CSTINTVAR_H
#define __CSTINTVAR_H

#include "mozartcore.hh"

#include <gecode/int.hh>

#ifndef MOZART_GENERATOR

namespace mozart {
#include "CstIntVar-implem.hh"

CstIntVar::CstIntVar(VM vm, size_t index)
  : WithHome(vm), _varIndex(index) {}

namespace internal {
  inline 
  bool validAsElement(nativeint e) {
    return e >= Gecode::Int::Limits::min && e <= Gecode::Int::Limits::max;    
  }

  inline
  int element(VM vm, RichNode e) {
    nativeint elem = getArgument<nativeint>(vm,e,MOZART_STR("integer"));
    if (!validAsElement(elem))
      raiseTypeError(vm, MOZART_STR("IntVarLike"), elem);
    return static_cast<int>(elem);
  }
}

CstIntVar::CstIntVar(VM vm, RichNode min, RichNode max) 
  : WithHome(vm) {
  int mn = internal::element(vm,min);
  int mx = internal::element(vm,max);
  if (mn > mx)
    raiseError(vm, MOZART_STR("Empty range"));

  GecodeSpace& sp = home()->getCstSpace();
  _varIndex = sp.newIntVar(mn,mx);
}

CstIntVar::CstIntVar(VM vm, nativeint n)
  : WithHome(vm) {

  if (!internal::validAsElement(n))
    raiseTypeError(vm, MOZART_STR("IntVarLike"), n);

  GecodeSpace& sp = home()->getCstSpace();
  _varIndex = sp.newIntVar((int)n, (int)n);
}

CstIntVar::CstIntVar(VM vm, GR gr, CstIntVar& from)
  : WithHome(vm,gr,from), _varIndex(from._varIndex) {}

Gecode::IntVar& CstIntVar::getVar() {
  return home()->getCstSpace().intVar(_varIndex);
}

// IntVarLike ------------------------------------------------------------------

Gecode::IntVar& CstIntVar::intVar(VM vm) {
  return getVar();
}

UnstableNode CstIntVar::min(VM vm) {
  return SmallInt::build(vm,getVar().min());
}

UnstableNode CstIntVar::max(VM vm) {
  return SmallInt::build(vm,getVar().max());
}

UnstableNode CstIntVar::value(VM vm) {
  if (!assigned(vm))
    raiseError(vm,MOZART_STR("Constraint variable"));
  return SmallInt::build(vm,getVar().val());
}

UnstableNode CstIntVar::isIn(VM vm, RichNode right) {
  int r = internal::element(vm,right);
  return getVar().in(r) ? 
    Boolean::build(vm,true) : Boolean::build(vm,false);
}

// ConstraintVar ------------------------------------------------------------------
bool CstIntVar::assigned(VM vm) {
  return getVar().assigned();
}

} // mozart

#endif // MOZART_GENERATOR

#endif // __CSTINTVAR_H
