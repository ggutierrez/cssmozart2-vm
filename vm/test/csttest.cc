#include "mozart.hh"

#include <climits>
#include <gtest/gtest.h>
#include "testutils.hh"

using namespace mozart;

class CstTest : public MozartTest {};

TEST_F(CstTest, SpaceCreation) {
  Space *currentSpace = vm->getCurrentSpace();
  GecodeSpace& cst = currentSpace->getCstSpace();
  cst.dumpSpaceInformation();
}

TEST_F(CstTest, InvalidElements) {
  UnstableNode n = SmallInt::build(vm,INT_MAX);
  EXPECT_FALSE(IntVarLike(n).isIntVarLike(vm));
  
  UnstableNode o = SmallInt::build(vm,INT_MAX-1);
  EXPECT_TRUE(IntVarLike(o).isIntVarLike(vm));

  UnstableNode p = SmallInt::build(vm,-(INT_MAX-1));
  EXPECT_TRUE(IntVarLike(p).isIntVarLike(vm));
}

TEST_F(CstTest, SmallIntIntVarLikeInterface) {
  using namespace patternmatching;

  UnstableNode n = SmallInt::build(vm,-1);

  UnstableNode min = IntVarLike(n).min(vm); 
  EXPECT_EQ_INT(-1,min);
  UnstableNode max = IntVarLike(n).max(vm);
  EXPECT_EQ_INT(-1,max);
  UnstableNode value = IntVarLike(n).value(vm);
  EXPECT_EQ_INT(-1,value);

  UnstableNode m = SmallInt::build(vm,-1);
  UnstableNode isInM = IntVarLike(n).isIn(vm,m);
  EXPECT_TRUE(getArgument<bool>(vm,isInM));
  
  UnstableNode o = SmallInt::build(vm,0);
  UnstableNode isInO = IntVarLike(n).isIn(vm,o);
  EXPECT_FALSE(getArgument<bool>(vm,isInO));
}

TEST_F(CstTest, IntVarLike) {
  nativeint x = -5;
  UnstableNode xNode = SmallInt::build(vm,x);
  EXPECT_TRUE(IntVarLike(xNode).isIntVarLike(vm));

  // The following test only makes sense in 64 bits architectures
  // where a nativeint can store integer bigger than INT_MIN
  nativeint out = INT_MIN + 1;
  EXPECT_FALSE(CstIntVar::validAsElement(out));
  UnstableNode outNode = SmallInt::build(vm,out);
  EXPECT_FALSE(IntVarLike(outNode).isIntVarLike(vm));

  EXPECT_RAISE(MOZART_STR("IntVarLike"),
               CstIntVar::build(vm,outNode,outNode));
}
