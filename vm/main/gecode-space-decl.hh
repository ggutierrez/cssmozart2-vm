#ifndef VM_HAS_CSS
#error This file is only included with the CSS support
#endif

#ifndef __GECODESPACE_DECL_H
#define __GECODESPACE_DECL_H


// temporal!!
#include <iostream>

#include <vector>
#include <gecode/kernel.hh>
#include <gecode/int.hh>
#include <gecode/set.hh>

namespace mozart {
class GecodeSpace : public Gecode::Space {
private:
  static std::vector<GecodeSpace*> alive;
  Gecode::SpaceStatus lastStatus;
  std::vector<Gecode::IntVar> _intVars;
  std::vector<Gecode::SetVar> _setVars;
  std::vector<Gecode::BoolVar> _boolVars;
public:
  inline
  GecodeSpace(void);
  inline
  GecodeSpace(bool share, GecodeSpace& other);
  inline
  virtual ~GecodeSpace(void);
  inline
  void propagate(void);
  inline
  void fail(void);
  inline
  int getLastStatus(void);
  //This methods updates all the vars of *this* gecodeSpace with
  //the information available in *other* gecodeSpace.
  inline
  void reflectVars(GecodeSpace& other);
  inline
  virtual Gecode::Space* copy(bool share);
  inline
  Gecode::IntVar& intVar(size_t index);
  inline
  size_t newIntVar(int min, int max);
  inline
  Gecode::SetVar& setVar(size_t index);
  inline
  size_t newSetVar();
  inline
  Gecode::BoolVar& boolVar(size_t index);
  inline
  size_t newBoolVar();
  inline
  void dumpSpaceInformation(void) const;
  inline
  static void gCollect(void);
  };
}

#endif
