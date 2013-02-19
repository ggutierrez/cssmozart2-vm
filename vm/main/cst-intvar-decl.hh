#ifndef __CSTINTVAR_DECL_H
#define __CSTINTVAR_DECL_H

#include "mozartcore-decl.hh"

namespace mozart {

class CstIntVar;

#ifndef MOZART_GENERATOR
#include "CstIntVar-implem-decl.hh"
#endif

class CstIntVar: public WithHome,
  public DataType<CstIntVar>,
  Transient,
  WithVariableBehavior<5> {
public:

  // TODO: uuid is missing

  // TODO: getTypeAtomg is missing
  inline
  CstIntVar(VM vm, size_t index);

  // Constructor from min and max elements in the domain
  inline
  CstIntVar(VM vm, RichNode min, RichNode max);

  // Constructor from a single integer
  inline
  CstIntVar(VM vm, nativeint n);

  // TODO: Constructor from a list (?) describing the domain

  // TODO: Ask Sebastien about this constructor. The docs says that is needed
  // if yes, what is its semantics?
  // CstIntVar(VM vm, SpaceRef home)
  //   : WithHome(home), _varIndex(0) {}
  inline
  CstIntVar(VM vm, GR gr, CstIntVar& from);

public:
  inline
  Gecode::IntVar& getVar(void);

public:
  // IntVarLike interface
  bool isIntVarLike(VM vm) {
    return true;
  }

  inline
  Gecode::IntVar& intVar(VM vm);

  inline
  UnstableNode min(VM vm);

  inline
  UnstableNode max(VM vm);

  inline
  UnstableNode value(VM vm);

  inline
  UnstableNode isIn(VM vm, RichNode right);
public:
  // ConstraintVar interface
  inline
  bool assigned(VM vm);
public:
  // Miscellaneous
  void printReprToStream(VM vm, std::ostream& out, int depth, int width) {
    out << getVar();
  }
private:
  // The actual representation of a constraint integer variable is a 
  // Gecode::IntVar, here we store the index of an object of that class
  // inside an array stored by a Gecode::Space
  size_t _varIndex;
};// End class CstIntVar

#ifndef MOZART_GENERATOR
#include "CstIntVar-implem-decl-after.hh"
#endif

} // End namespace mozart

#endif // __CSTINTVAR_DECL_H
