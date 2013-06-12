#ifndef __MODINTVARPROP_H
#define __MODINTVARPROP_H

#include "../mozartcore.hh"
#include <gecode/int.hh>
#include "cstsupport/intsupport.hh"
namespace mozart {

  namespace builtins {

    // Notes:
    // - All the constraints are posted in vm->getCurrentSpace()
    //   TODO: can I assume that the current space is the same space each
    //   variable belongs to?
    class ModIntVarProp: public Module {
    public:
      ModIntVarProp(): Module("IntVarProp") {}

      class Min3: public Builtin<Min3> {
      public:
	Min3(): Builtin("min3") {}

	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::min(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting min malformed"), x0);
	  }
	}
      };

      class Min2: public Builtin<Min2> {
      public:
	Min2(): Builtin("min2") {}

	static void call(VM vm, In x, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(isIntVarArgs(vm,x) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::min(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting min malformed"), x);
	  }
	}
      };

      class Max3: public Builtin<Max3> {
      public:
	Max3(): Builtin("max3") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::max(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting max malformed"), x0);
	  }
	}
      };
  
      class Max2: public Builtin<Max2> {
      public:
	Max2(): Builtin("max2") {}
    
	static void call(VM vm, In x, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntVarArgs(vm,x) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::max(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting max malformed"), x);
	  }
	}
      };
  
      class Abs: public Builtin<Abs> {
      public:
	Abs(): Builtin("abs") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::abs(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting abs malformed"), x0);
	  }
	}
      };

      class Mult: public Builtin<Mult> {
      public:
	Mult(): Builtin("mult") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::mult(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting mult malformed"), x0);
	  }
	}
      };
  
      class Sqr: public Builtin<Sqr> {
      public:
	Sqr(): Builtin("sqr") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
     
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::sqr(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting sqr malformed"), x0);
	  }
	}
      };

      class Sqrt: public Builtin<Sqrt> {
      public:
	Sqrt(): Builtin("sqrt") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::sqrt(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting sqrt malformed"), x0);
	  }
	}
      };
  
      class Divmod: public Builtin<Divmod> {
      public:
	Divmod(): Builtin("divmod") {}
    
	static void call(VM vm, In x0, In x1, In x2, In x3) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm) and IntVarLike(x3).isIntVarLike(vm)){
	    Gecode::divmod(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm),IntVarLike(x3).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting divmod malformed"), x0);
	  }
	}
      };

      class DivI: public Builtin<DivI> {
      public:
	DivI(): Builtin("divI") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
     
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::div(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting div malformed"), x0);
	  }
	}
      };

      class ModI: public Builtin<ModI> {
      public:
	ModI(): Builtin("modI") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::mod(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting mod malformed"), x0);
	  }
	}
      };

      class Dom2: public Builtin<Dom2> {
      public:
	Dom2(): Builtin("dom2") {}

	static void call(VM vm, In x, In n) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>()){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(num));
	  }else if(isIntVarArgs(vm,x) and n.is<SmallInt>()){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,getIntVarArgs(vm,x),(int)(num));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isIntSet(vm,n)){
	    Gecode::dom(home,IntVarLike(x).intVar(vm),getIntSet(vm,n));
	  }else if(isIntVarArgs(vm,x) and isIntSet(vm,n)){
	    Gecode::dom(home,getIntVarArgs(vm,x),getIntSet(vm,n));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting domain malformed"), x);
	  }
	}
      };

      class Dom3: public Builtin<Dom3> {
      public:
	Dom3(): Builtin("dom3") {}

	static void call(VM vm, In x, In n, In m) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and m.is<SmallInt>()){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(min),(int)(max));
	  }else if(isIntVarArgs(vm,x) and n.is<SmallInt>() and m.is<SmallInt>()){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,getIntVarArgs(vm,x),(int)(min),(int)(max));
	  }else if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and BoolVarLike(m).isBoolVarLike(vm)){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(num),BoolVarLike(m).boolVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isIntSet(vm,n) and BoolVarLike(m).isBoolVarLike(vm)){
	    Gecode::dom(home,IntVarLike(x).intVar(vm),getIntSet(vm,n),BoolVarLike(m).boolVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting domain malformed"), x);
	  }
	}
      };

      class Dom4: public Builtin<Dom4> {
      public:
	Dom4(): Builtin("dom4") {}

	static void call(VM vm, In x, In n, In m, In b) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and m.is<SmallInt>() and BoolVarLike(b).isBoolVarLike(vm)){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(min),(int)(max),BoolVarLike(b).boolVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting domain malformed"), x);
	  }
	}
      };

      class Count: public Builtin<Count> {
      public:
	Count(): Builtin("count") {}

	static void call(VM vm, In x, In n, In r, In m) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  Gecode::IntRelType rt = atomToRelType(vm,r);
	  Gecode::count(home,getIntVarArgs(vm,x),(int)(n.as<SmallInt>().value()),rt,(int)(m.as<SmallInt>().value()));
	}
      };

      class Rel2: public Builtin<Rel2> {
      public:
	Rel2(): Builtin("rel2") {}

	static void call(VM vm, In x, In r) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt);
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting rel malformed"), x);
	  }
	}
      };

      class Rel3: public Builtin<Rel3> {
      public:
	Rel3(): Builtin("rel3") {}

	static void call(VM vm, In x, In r, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,IntVarLike(y).intVar(vm));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,IntVarLike(y).intVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and y.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,(int)(num));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and y.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,(int)(num));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and isIntVarArgs(vm,y)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,getIntVarArgs(vm,y));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting rel malformed"), x);
	  }
	}
      };
  
      class Rel4: public Builtin<Rel4> {
      public:
	Rel4(): Builtin("rel4") {}

	static void call(VM vm, In x, In r, In y, In b) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm) and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,IntVarLike(y).intVar(vm),BoolVarLike(b).boolVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and y.is<SmallInt>() and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,(int)(num),BoolVarLike(b).boolVar(vm));
	  }
	  else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting rel malformed"), x);
	  }
	}
      };

      class Distinct: public Builtin<Distinct> {
      public:
	Distinct(): Builtin("distinct") {}
    
	static void call(VM vm, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntVarArgs(vm,x)){
	    Gecode::distinct(home,getIntVarArgs(vm,x));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting distinct malformed"), x);
	  }
	}
      };

      class Distinct2: public Builtin<Distinct2> {
      public:
	Distinct2(): Builtin("distinct2") {}
    
	static void call(VM vm, In v, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntArgs(vm,v) and isIntVarArgs(vm,x)){
	    Gecode::distinct(home,getIntArgs(vm,v),getIntVarArgs(vm,x));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting distinct malformed"), x);
	  }
	}
      };
  
      class Linear3: public Builtin<Linear3> {
      public:
	Linear3(): Builtin("linear3") {}
    
	static void call(VM vm, In v, In r, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and x.is<SmallInt>()){
	    nativeint val=x.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,(int)(val));
	  }else if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and IntVarLike(x).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,IntVarLike(x).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting linear malformed"), v);
	  }
	}
      };
      
      class Linear4: public Builtin<Linear4> {
      public:
	Linear4(): Builtin("linear4") {}
    
	static void call(VM vm, In v, In r, In x, In c) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and x.is<SmallInt>() and BoolVarLike(c).isBoolVarLike(vm)){
	    nativeint val=x.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,(int)(val),BoolVarLike(c).boolVar(vm));
	  }else if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and IntVarLike(x).isIntVarLike(vm) and BoolVarLike(c).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,IntVarLike(x).intVar(vm),BoolVarLike(c).boolVar(vm));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and c.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint val=c.as<SmallInt>().value();
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,(int)(val));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(c).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,IntVarLike(c).intVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting linear malformed"), v);
	  }
	}
      };

      class Linear5: public Builtin<Linear5> {
      public:
	Linear5(): Builtin("linear5") {}
    
	static void call(VM vm, In v, In r, In x, In c, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and c.is<SmallInt>() and BoolVarLike(y).isBoolVarLike(vm)){
	    nativeint val=c.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,(int)(val),BoolVarLike(y).boolVar(vm));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(c).isIntVarLike(vm) and BoolVarLike(y).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,IntVarLike(c).intVar(vm),BoolVarLike(y).boolVar(vm));
	  }else{
	    raiseTypeError(vm, MOZART_STR("Propagator posting linear malformed"), v);
	  }
	}
      };


      class Branch: public Builtin<Branch> {
      public:
	Branch(): Builtin("branch") {}
	static void call(VM vm, In x, In bvar, In bval) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  Gecode::IntVarBranch bvart = atomToIntVarBranch(vm,bvar); 
	  Gecode::IntValBranch bvalt = atomToIntValBranch(vm,bval);
	  Gecode::branch(home,getIntVarArgs(vm,x),bvart,bvalt); 
	}
      };

      class Element: public Builtin<Element>{
      public:
	Element(): Builtin("element") {}
    
	static void call(VM vm, In n, In x0, In x1){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  Gecode::element(home, getIntSharedArray(vm,n), IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	}
      };

    }; // class ModIntVarProp
  } // namespace builtins
} // namespace mozart
#endif // __MODINTVARPROP_H
