#ifndef __CSTSETVAR_H
#define __CSTSETVAR_H

#include "mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {
#include "CstSetVar-implem.hh"

CstSetVar::CstSetVar(VM vm) 
  : WithHome(vm), _varIndex(0) {

  auto& sp = home()->getCstSpace();
  _varIndex = sp.newSetVar();
}


} // mozart

#endif // MOZART_GENERATOR

#endif // __CSTSETVAR_H
