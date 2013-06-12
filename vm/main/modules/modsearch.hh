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

  class DFS: public Builtin<DFS> {
  public:
    DFS(): Builtin("dfs") {}

      static void call(VM vm, In space, Out result) {
      if(ConstraintSpace(space).isConstraintSpace(vm)) { 
        GecodeSpace* gs = ConstraintSpace(space).constraintSpace(vm);
        Gecode::DFS<GecodeSpace> e(gs);
        if(GecodeSpace *sol = e.next()) {
          ConstraintSpace(space).updateConstraintSpace(vm, sol);
          result = SpaceLike(space).cloneSpace(vm);
        }
        else
          result = build(vm, vm->coreatoms.nil);
      }
    }
  };

};

} // namespace builtins
} // namespace mozart
#endif // __MODSEARCH_H
