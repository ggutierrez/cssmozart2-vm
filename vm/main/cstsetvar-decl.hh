#ifndef __CSTSETVAR_DECL_H
#define __CSTSETVAR_DECL_H

#include "mozartcore-decl.hh"

namespace mozart {

class CstSetVar;

#ifndef MOZART_GENERATOR
#include "CstSetVar-implem-decl.hh"
#endif

class CstSetVar: public WithHome,
  public DataType<CstSetVar>,
  public Transient,
  public WithVariableBehavior<5> {
public:
  CstSetVar(VM vm, size_t index)
    : WithHome(vm), _varIndex(index) {}

  // Constructor from min and max elements in the domain
  inline
  CstSetVar(VM vm);

 
  CstSetVar(VM vm, GR gr, CstSetVar from)
    //    : WithHome(vm,gr,from->home()), _varIndex(from->_varIndex) {}
    : WithHome(vm,gr,from), _varIndex(from._varIndex) {}

public:
  Gecode::SetVar& getVar(void) {
    return home()->getCstSpace().setVar(_varIndex);
  }
public:
  // SetVarLike interface
  bool isSetVarLike(VM vm) {
    return true;
  }

  Gecode::SetVar& setVar(VM vm) {
    return getVar();
  }

public:
  // Miscellaneous
  void printReprToStream(RichNode self, VM vm, std::ostream& out, int depth, int width) {
    out << getVar();
  }
private:
  // The actual representation of a constraint integer variable is a 
  // Gecode::SetVar, here we store the index of an object of that class
  // inside an array stored by a Gecode::Space
  size_t _varIndex;
};// End class CstSetVar

#ifndef MOZART_GENERATOR
#include "CstSetVar-implem-decl-after.hh"
#endif

} // End namespace mozart

#endif // __CSTSETVAR_DECL_H
