// Copyright © 2011, Université catholique de Louvain
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// *  Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// *  Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "callables.hh"

//////////////////////
// BuiltinProcedure //
//////////////////////

const BuiltinProcedure BuiltinProcedure::rawType;
const BuiltinProcedure* const BuiltinProcedure::type =
  &BuiltinProcedure::rawType;

BuiltinResult Implementation<BuiltinProcedure>::raiseIllegalArity(int argc) {
  // TODO raiseIllegalArity
  return BuiltinResultContinue;
}


/////////////////
// Abstraction //
/////////////////

const Abstraction Abstraction::rawType;
const Abstraction* const Abstraction::type = &Abstraction::rawType;

Implementation<Abstraction>::Implementation(VM vm, size_t Gc,
                                            StaticArray<StableNode> _Gs,
                                            int arity, UnstableNode* body) :
  _arity(arity), _Gc(Gc) {

  _body.init(vm, *body);

  _codeAreaCacheValid = false;
}
