#ifndef __MODFDB_H
#define __MODFDB_H

#include "../mozartcore.hh"

namespace mozart {
namespace builtins {

///////////////////
// Search Module //
///////////////////

class ModFDB: public Module {
public:
	ModFDB(): Module("FDB") {}

	class Distribute: public Builtin<Distribute> {
	public:
		Distribute(): Builtin("distribute") {}

		static void call(VM vm, In b, In x) {
			assert(vm->getCurrentSpace()->hasConstraintSpace());
			atom_t a = getArgument<atom_t>(vm,b,MOZART_STR("Atom"));
			if (a == vm->coreatoms.naive){
				GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
				Gecode::IntVar& vx = IntVarLike(x).intVar(vm);
				Gecode::branch(home, vx, Gecode::INT_VAL_MIN);	
			}
		}

	};
};

} // namespace builtins
} // namespace mozart
#endif // __MODFDB_H
