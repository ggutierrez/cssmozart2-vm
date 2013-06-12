#ifndef __CSTBOOLVAR_H
#define __CSTBOOLVAR_H

#include "mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {
#include "CstBoolVar-implem.hh"

  CstBoolVar::CstBoolVar(VM vm) 
    : WithHome(vm), _varIndex(0) {
    auto& sp = home()->getCstSpace();
    _varIndex = sp.newBoolVar();
  }

  UnstableNode CstBoolVar::min(VM vm) {
    return SmallInt::build(vm,getVar().min());
  }

  UnstableNode CstBoolVar::max(VM vm) {
    return SmallInt::build(vm,getVar().max());
  }

  UnstableNode CstBoolVar::value(VM vm) {
    return SmallInt::build(vm,getVar().val());
  }

  UnstableNode CstBoolVar::zero(VM vm) {
    return Boolean::build(vm,getVar().zero());
  }

  UnstableNode CstBoolVar::one(VM vm) {
    return Boolean::build(vm,getVar().one());
  }

  UnstableNode CstBoolVar::none(VM vm) {
    return Boolean::build(vm,getVar().none());
  }

} // mozart

#endif // MOZART_GENERATOR

#endif // __CSTBOOLVAR_H
