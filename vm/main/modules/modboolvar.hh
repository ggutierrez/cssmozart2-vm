#ifndef __MODBOOLVAR_H
#define __MODBOOLVAR_H

#include "../mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {
namespace builtins {

class ModBoolVar: public Module {
public:
  ModBoolVar(): Module("BoolVar") {}

  class New: public Builtin<New> {
  public:
    New(): Builtin("new") {}

    static void call(VM vm, Out result) {
      result = CstBoolVar::build(vm);
    }
  };

  class Is: public Builtin<Is> {
  public:
    Is(): Builtin("is") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).isBoolVarLike(vm));
    }
  };

  class Min: public Builtin<Min> {
  public:
    Min(): Builtin("min") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).min(vm));
    }
  };

  class Max: public Builtin<Max> {
  public:
    Max(): Builtin("max") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).max(vm));
    }
  };

  class Value: public Builtin<Value> {
  public:
    Value(): Builtin("value") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).value(vm));
    }
  };

  class Zero: public Builtin<Zero> {
  public:
    Zero(): Builtin("zero") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).zero(vm));
    }
  };

  class One: public Builtin<One> {
  public:
    One(): Builtin("one") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).one(vm));
    }
  };

  class None: public Builtin<None> {
  public:
    None(): Builtin("none") {}

    static void call(VM vm, In var, Out result) {
      result = build(vm, BoolVarLike(var).none(vm));
    }
  };


};
} // builtins
} // mozart

#endif // MOZART_GENERATOR
#endif // __MODBOOLVAR_H
