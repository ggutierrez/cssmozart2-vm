#ifndef __MODINTVAR_H
#define __MODINTVAR_H

#include "../mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {
namespace builtins {

class ModIntVar: public Module {
public:
  ModIntVar(): Module("IntVar") {}

  class New: public Builtin<New> {
  public:
    New(): Builtin("new") {}

    static void call(VM vm, In min, In max, Out result) {
      result = CstIntVar::build(vm,min,max);
    }
  };

  class Is: public Builtin<Is> {
  public:
    Is(): Builtin("is") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, IntVarLike(var).isIntVarLike(vm));
    }
  };

  class Min: public Builtin<Min> {
  public:
    Min(): Builtin("min") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, IntVarLike(var).min(vm));
    }
  };

  class Max: public Builtin<Max> {
  public:
    Max(): Builtin("max") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, IntVarLike(var).max(vm));
    }
  };

  class Value: public Builtin<Value> {
  public:
    Value(): Builtin("value") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, IntVarLike(var).value(vm));
    }
  };

  class IsIn: public Builtin<IsIn> {
  public:
    IsIn(): Builtin("isIn") {}

    static void call(VM vm, In var, In n, Out result) {
      result = build(vm, IntVarLike(var).isIn(vm,n));
    }
  };
  class Inf: public Builtin<Inf> {
  public:
    Inf(): Builtin("inf") {}

    static void call(VM vm, Out result) {
      result = build(vm, Gecode::Int::Limits::min);
    }
  };

  class Sup: public Builtin<Sup> {
  public:
    Sup(): Builtin("sup") {}

    static void call(VM vm, Out result) {
      result = build(vm, Gecode::Int::Limits::max);
    }
  };

};
} // builtins
} // mozart

#endif // MOZART_GENERATOR
#endif // __MODINTVAR_H
