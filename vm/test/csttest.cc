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

  EXPECT_TRUE(ConstraintVar(n).assigned(vm));

  UnstableNode m = SmallInt::build(vm,-1);
  UnstableNode isInM = IntVarLike(n).isIn(vm,m);
  EXPECT_TRUE(getArgument<bool>(vm,isInM));
  
  UnstableNode o = SmallInt::build(vm,0);
  UnstableNode isInO = IntVarLike(n).isIn(vm,o);
  EXPECT_FALSE(getArgument<bool>(vm,isInO));
}

TEST_F(CstTest, CstIntVarIntVarLikeInterface) {
  nativeint v(0);
  UnstableNode x = CstIntVar::build(vm,v);

  std::cout << "Var: " << repr(vm,x) << std::endl;
  
  UnstableNode min = IntVarLike(x).min(vm);
  std::cout << "Min: " << repr(vm,min) << std::endl;
  
  EXPECT_EQ_INT(0,min);
  UnstableNode max = IntVarLike(x).max(vm);
  EXPECT_EQ_INT(0,max);
  UnstableNode value = IntVarLike(x).value(vm);
  EXPECT_EQ_INT(0,value);

  UnstableNode m = SmallInt::build(vm,v);
  UnstableNode isInX = IntVarLike(x).isIn(vm,m);
  EXPECT_TRUE(getArgument<bool>(vm,isInX));
}

TEST_F(CstTest, ConstraintVarInterface) {
  UnstableNode n = SmallInt::build(vm,-1);
  EXPECT_TRUE(ConstraintVar(n).assigned(vm));
  
  nativeint v(0);
  UnstableNode x = CstIntVar::build(vm,v);
  EXPECT_TRUE(ConstraintVar(x).assigned(vm));
}

/*TEST_F(CstTest, CstIntVarIntVarLikeInterface) {
  nativeint v(0);
  UnstableNode x = CstIntVar::build(vm,v);

  std::cout << "Var: " << repr(vm,x) << std::endl;
  
  UnstableNode min = IntVarLike(x).min(vm);
  std::cout << "Min: " << repr(vm,min) << std::endl;
  
  EXPECT_EQ_INT(0,min);
  UnstableNode max = IntVarLike(x).max(vm);
  EXPECT_EQ_INT(0,max);
  UnstableNode value = IntVarLike(x).value(vm);
  EXPECT_EQ_INT(0,value);

  UnstableNode m = SmallInt::build(vm,v);
  UnstableNode isInX = IntVarLike(x).isIn(vm,m);
  EXPECT_TRUE(BooleanValue(isInX).boolValue(vm));
}

TEST_F(CstTest, ConstraintVarInterface) {
  UnstableNode n = SmallInt::build(vm,-1);
  EXPECT_TRUE(ConstraintVar(n).assigned(vm));
  
  nativeint v(0);
  UnstableNode x = CstIntVar::build(vm,v);
  EXPECT_TRUE(ConstraintVar(x).assigned(vm));
}*/
