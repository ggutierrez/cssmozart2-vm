#ifndef __MODSEARCH_H
#define __MODSEARCH_H

#include "../mozartcore.hh"
#include <gecode/search.hh>

namespace mozart {
namespace builtins {

///////////////////
// Search Module //
///////////////////

class ModSearch: public Module {
public:
	ModSearch(): Module("Search") {}

	class Distribute: public Builtin<Distribute> {
	public:
		Distribute(): Builtin("distribute") {}

		void operator()(VM vm, In b, In x) {
			assert(vm->getCurrentSpace()->hasConstraintSpace());
			atom_t a = getArgument<atom_t>(vm,b,MOZART_STR("Atom"));
			if (a == vm->coreatoms.naive){
				GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
				Gecode::IntVar& vx = IntVarLike(x).intVar(vm);
				Gecode::branch(home, vx, Gecode::INT_VAL_MIN);	
			}
		}

	};

	class DFS: public Builtin<DFS> {
	public:
		DFS(): Builtin("dfs") {}

	        void operator()(VM vm, In space, Out result) {
			if(SpaceLike(space).isSpace(vm)) { 
				Space* s = SpaceLike(space).space(vm);
				if(s->hasConstraintSpace()){
					GecodeSpace& gs = s->getCstSpace();
					Gecode::DFS<GecodeSpace> e(&gs);
					GecodeSpace *sol = e.next();
					Space* cs = s->clone(vm);
					cs->setCstSpace(*sol);
					result = ReifiedSpace::build(vm, cs);
					delete sol;
				}
			}

		}

	};

};

} // namespace builtins
} // namespace mozart
#endif // __MODSEARCH_H


