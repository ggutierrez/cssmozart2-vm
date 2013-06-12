#ifndef __INTPROPAUX_H
#define __INTPROPAUX_H

#include "../../mozartcore.hh"
#include <gecode/int.hh>

namespace mozart {

namespace builtins {

static bool isAtomToRelType(VM vm, In r) {
    atom_t a = getArgument<atom_t>(vm,r,MOZART_STR("Atom"));
    if (a == vm->coreatoms.irt_eq or a == vm->coreatoms.irt_nq or a == vm->coreatoms.irt_lq or a == vm->coreatoms.irt_le or a == vm->coreatoms.irt_gq or a == vm->coreatoms.irt_gr){
      return true;
    }else{
      return false;
    }
  }

static Gecode::IntRelType atomToRelType(VM vm, In r) {
  if(isAtomToRelType(vm, r) == false){
      raiseTypeError(vm,MOZART_STR("InvalidRelationType"),r);
  }
  atom_t a = getArgument<atom_t>(vm,r,MOZART_STR("Atom"));
  if (a == vm->coreatoms.irt_eq) return Gecode::IRT_EQ;
  if (a == vm->coreatoms.irt_nq) return Gecode::IRT_NQ;
  if (a == vm->coreatoms.irt_lq) return Gecode::IRT_LQ;
  if (a == vm->coreatoms.irt_le) return Gecode::IRT_LE;
  if (a == vm->coreatoms.irt_gq) return Gecode::IRT_GQ;
  if (a == vm->coreatoms.irt_gr) return Gecode::IRT_GR;
  return Gecode::IRT_GR;
}
  
  //Uncomment this when we use it in a propagator builtin. 
  //Avoing compilation warning.
  /*static Gecode::IntConLevel atomToIntConLevel(VM vm, In l) {
    atom_t a = getArgument<atom_t>(vm,l,MOZART_STR("Atom"));
    if (a == vm->coreatoms.icl_val) return Gecode::ICL_VAL;
    if (a == vm->coreatoms.icl_bnd) return Gecode::ICL_BND;
    if (a == vm->coreatoms.icl_dom) return Gecode::ICL_DOM;
    if (a == vm->coreatoms.icl_def) return Gecode::ICL_DEF;
    raiseTypeError(vm,MOZART_STR("InvalidIntegerConsistencyLevel"),l);
    return Gecode::ICL_DEF;
    }*/
  
  static Gecode::IntVarBranch atomToIntVarBranch(VM vm, In bvar){
    atom_t a = getArgument<atom_t>(vm,bvar,MOZART_STR("Atom"));
    if (a == vm->coreatoms.int_var_none) return Gecode::INT_VAR_NONE;
    if (a == vm->coreatoms.int_var_rnd) return Gecode::INT_VAR_RND;
    if (a == vm->coreatoms.int_var_degree_min) return Gecode::INT_VAR_DEGREE_MIN;
    if (a == vm->coreatoms.int_var_degree_max) return Gecode::INT_VAR_DEGREE_MAX;
    if (a == vm->coreatoms.int_var_afc_min) return Gecode::INT_VAR_AFC_MIN;
    if (a == vm->coreatoms.int_var_min_min) return Gecode::INT_VAR_MIN_MIN;
    if (a == vm->coreatoms.int_var_min_max) return Gecode::INT_VAR_MIN_MAX;
    if (a == vm->coreatoms.int_var_max_min) return Gecode::INT_VAR_MAX_MIN;
    if (a == vm->coreatoms.int_var_max_max) return Gecode::INT_VAR_MAX_MAX;
    if (a == vm->coreatoms.int_var_size_min) return Gecode::INT_VAR_SIZE_MIN;
    if (a == vm->coreatoms.int_var_size_max) return Gecode::INT_VAR_SIZE_MAX;
    if (a == vm->coreatoms.int_var_size_degree_min) return Gecode::INT_VAR_SIZE_DEGREE_MIN;
    if (a == vm->coreatoms.int_var_size_degree_max) return Gecode::INT_VAR_SIZE_DEGREE_MAX;
    if (a == vm->coreatoms.int_var_size_afc_min) return Gecode::INT_VAR_SIZE_AFC_MIN;
    if (a == vm->coreatoms.int_var_size_afc_max) return Gecode::INT_VAR_SIZE_AFC_MAX;
    if (a == vm->coreatoms.int_var_regret_min_min) return Gecode::INT_VAR_REGRET_MIN_MIN;
    if (a == vm->coreatoms.int_var_regret_min_max) return Gecode::INT_VAR_REGRET_MIN_MAX;
    if (a == vm->coreatoms.int_var_regret_max_min) return Gecode::INT_VAR_REGRET_MAX_MIN;
    if (a == vm->coreatoms.int_var_regret_max_max) return Gecode::INT_VAR_REGRET_MAX_MAX;
    raiseTypeError(vm,MOZART_STR("InvalidIntegerBranchType"),bvar);
    return Gecode::INT_VAR_NONE;
  }

  static Gecode::IntValBranch atomToIntValBranch(VM vm, In bval){
    atom_t a = getArgument<atom_t>(vm,bval,MOZART_STR("Atom"));  
    if (a == vm->coreatoms.int_val_min) return Gecode::INT_VAL_MIN;
    if (a == vm->coreatoms.int_val_med) return Gecode::INT_VAL_MED;
    if (a == vm->coreatoms.int_val_max) return Gecode::INT_VAL_MAX;
    if (a == vm->coreatoms.int_val_rad) return Gecode::INT_VAL_RND;
    if (a == vm->coreatoms.int_val_split_min) return Gecode::INT_VAL_SPLIT_MIN;
    if (a == vm->coreatoms.int_val_split_max) return Gecode::INT_VAL_SPLIT_MAX;
    if (a == vm->coreatoms.int_val_range_min) return Gecode::INT_VAL_RANGE_MIN;
    if (a == vm->coreatoms.int_val_range_max) return Gecode::INT_VAL_RANGE_MAX;
    if (a == vm->coreatoms.int_values_min) return Gecode::INT_VALUES_MIN;
    if (a == vm->coreatoms.int_values_max) return Gecode::INT_VALUES_MAX;
    raiseTypeError(vm,MOZART_STR("InvalidIntegerBranchType"),bval);
    return Gecode::INT_VAL_MIN;
  }

  static bool isIntVarArgs(VM vm, In x){
    bool v=true;
    size_t width;

    if(x.is<Tuple>()){
      width = x.as<Tuple>().getWidth();
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Tuple>().getElement(i);
	UnstableNode a = Reference::build(vm, t);
	RichNode tt = a;
	v = IntVarLike(tt).isIntVarLike(vm);
      }
    }else if(x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
      	UnstableNode uhead = Reference::build(vm, head);
      	RichNode rhead = uhead;
	v = IntVarLike(rhead).isIntVarLike(vm);
	UnstableNode utail = Reference::build(vm, tail);
      	RichNode rtail = utail;
	if (!rtail.is<Cons>()){
	  break;
	}
      	UnstableNode ncons = Reference::build(vm, tail);
      	RichNode rncons = ncons;
      	head=rncons.as<Cons>().getHead();
	tail=rncons.as<Cons>().getTail();	
      }
    }else if(x.is<Record>()){
      width = x.as<Record>().getWidth();
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Record>().getElement(i);
      	UnstableNode a = Reference::build(vm, t);
      	RichNode tt = a;
	v = IntVarLike(tt).isIntVarLike(vm);
      }
    }else{
      v=false;
    }
    return v;
  }

  static Gecode::IntVarArgs getIntVarArgs(VM vm, In x){
    size_t width;

    if(!isIntVarArgs(vm,x)){
      raiseTypeError(vm, MOZART_STR("Finite Domain Integer Arguments"), x);
    }
    
    if(x.is<Tuple>()){
      width = x.as<Tuple>().getWidth();
      Gecode::IntVarArgs v(width);
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Tuple>().getElement(i);
	UnstableNode a = Reference::build(vm, t);
	RichNode tt = a;
	v[i] = IntVarLike(tt).intVar(vm);
      }
      return v;
    }else if(x.is<Cons>()){
      Gecode::IntVarArgs v;
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
      	UnstableNode uhead = Reference::build(vm, head);
      	RichNode rhead = uhead;
      	v << IntVarLike(rhead).intVar(vm);
	UnstableNode utail = Reference::build(vm, tail);
      	RichNode rtail = utail;
	if (!rtail.is<Cons>()){
	  break;
	}
      	UnstableNode ncons = Reference::build(vm, tail);
      	RichNode rncons = ncons;
      	head=rncons.as<Cons>().getHead();
	tail=rncons.as<Cons>().getTail();	
      }
      return v;
    }else {
      width = x.as<Record>().getWidth();
      Gecode::IntVarArgs v(width);
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Record>().getElement(i);
      	UnstableNode a = Reference::build(vm, t);
      	RichNode tt = a;
      	v[i] = IntVarLike(tt).intVar(vm);
      }
      return v;
    }
  } 

  static bool isIntArgs(VM vm, In x){
    bool v=true;
    size_t width;
    if(x.is<Tuple>()){
      width = x.as<Tuple>().getWidth();
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Tuple>().getElement(i);
	UnstableNode a = Reference::build(vm, t);
	RichNode tt = a;
	if(!tt.is<SmallInt>()){
	  v=false;
	}
      }
    }else if(x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
	UnstableNode uhead = Reference::build(vm, head);
	RichNode rhead = uhead;
	if(rhead.is<SmallInt>() or rhead.is<Tuple>()){
	  if(rhead.is<Tuple>()){
	    size_t widtht = rhead.as<Tuple>().getWidth();
	    for(unsigned int i=0; i<widtht; i++){
	      StableNode* t=rhead.as<Tuple>().getElement(i);
	      UnstableNode a = Reference::build(vm, t);
	      RichNode tt = a;
	      if(!tt.is<SmallInt>()){
		v=false;
	      }
	    }
	  } 
	}else{
	  v=false;
	}
	UnstableNode utail = Reference::build(vm, tail);
	RichNode rtail = utail;
	if (!rtail.is<Cons>()){
	  break;
	}
	UnstableNode ncons = Reference::build(vm, tail);
	RichNode rncons = ncons;
	head=rncons.as<Cons>().getHead();
	tail=rncons.as<Cons>().getTail();
	
      }
    }
    return v;
  }

  static Gecode::IntArgs getIntArgs(VM vm, In x){
    
    if(!isIntArgs(vm,x)){
      raiseTypeError(vm, MOZART_STR("Integer Arguments"), x);
    }

    std::vector<int> v;
    size_t width;
    if(x.is<Tuple>()){
      width = x.as<Tuple>().getWidth();
      for(unsigned int i=0; i<width; i++){
      	StableNode* t=x.as<Tuple>().getElement(i);
	UnstableNode a = Reference::build(vm, t);
	RichNode tt = a;
	assert(tt.is<SmallInt>());
	nativeint val=tt.as<SmallInt>().value();
	v.push_back((int)(val));
      }
    }else if(x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
	UnstableNode uhead = Reference::build(vm, head);
	RichNode rhead = uhead;
	if(rhead.is<SmallInt>()){
	  assert(rhead.is<SmallInt>());
	  nativeint val=rhead.as<SmallInt>().value();
	  v.push_back((int)(val));
	} else 
	  if(rhead.is<Tuple>()){
	    size_t widtht = rhead.as<Tuple>().getWidth();
	    for(unsigned int i=0; i<widtht; i++){
	      StableNode* t=rhead.as<Tuple>().getElement(i);
	      UnstableNode a = Reference::build(vm, t);
	      RichNode tt = a;
	      assert(tt.is<SmallInt>());
	      nativeint val=tt.as<SmallInt>().value();
	      v.push_back((int)(val));
	    }
	  }
	UnstableNode utail = Reference::build(vm, tail);
	RichNode rtail = utail;
	if (!rtail.is<Cons>()){
	  break;
	}
	UnstableNode ncons = Reference::build(vm, tail);
	RichNode rncons = ncons;
	head=rncons.as<Cons>().getHead();
	tail=rncons.as<Cons>().getTail();
	
      }
    }
    return Gecode::IntArgs(v);
  }

  static bool isIntSet(VM vm, In x){
    bool v=true;
    if (x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
	UnstableNode uhead = Reference::build(vm, head);
	RichNode rhead = uhead;
	if(rhead.is<SmallInt>() or rhead.is<Tuple>()){ 
	  if(rhead.is<Tuple>()){
	    size_t widtht = rhead.as<Tuple>().getWidth();
	    for(unsigned int i=0; i<widtht; i++){
	      StableNode* t=rhead.as<Tuple>().getElement(i);
	      UnstableNode a = Reference::build(vm, t);
	      RichNode tt = a;
              if(!tt.is<SmallInt>()){
		v=false;
	      }
	    }
	  }
	}else{
	  v=false;
	}
	  
	UnstableNode utail = Reference::build(vm, tail);
	RichNode rtail = utail;
	if (!rtail.is<Cons>()){
	  break;
	}	  
	UnstableNode ncons = Reference::build(vm, tail);
	RichNode rncons = ncons;
	head=rncons.as<Cons>().getHead();
	tail=rncons.as<Cons>().getTail();	
      } 
    }
    return v;
  }

  static Gecode::IntSet getIntSet(VM vm, In x){

    if(!isIntSet(vm,x)){
      raiseTypeError(vm, MOZART_STR("Integer Arguments"), x);
    }

    std::vector<int> v;
    if (x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
	UnstableNode uhead = Reference::build(vm, head);
	RichNode rhead = uhead;
	if(rhead.is<SmallInt>()){
	  assert(rhead.is<SmallInt>());
	  nativeint val=rhead.as<SmallInt>().value();
	  v.push_back((int)(val));
	  v.push_back((int)(val));
	} else 
	  if(rhead.is<Tuple>()){
	    size_t widtht = rhead.as<Tuple>().getWidth();
	    for(unsigned int i=0; i<widtht; i++){
	      StableNode* t=rhead.as<Tuple>().getElement(i);
	      UnstableNode a = Reference::build(vm, t);
	      RichNode tt = a;
	      assert(tt.is<SmallInt>());
	      nativeint val=tt.as<SmallInt>().value();
	      v.push_back((int)(val));
	    }
	  }
	  UnstableNode utail = Reference::build(vm, tail);
	  RichNode rtail = utail;
	  if (!rtail.is<Cons>()){
	    break;
	  }	  
	  UnstableNode ncons = Reference::build(vm, tail);
	  RichNode rncons = ncons;
	  head=rncons.as<Cons>().getHead();
	  tail=rncons.as<Cons>().getTail();	
	} 
      int pairs[v.size()/2][2];
      unsigned int i=0;
      unsigned int ii=0;
      while (i<v.size()){
	pairs[ii][0]= v[i];
	pairs[ii][1]= v[i+1];
	i=i+2;
	ii++;
      }
      return Gecode::IntSet(pairs, v.size()/2);
    }
          
    return Gecode::IntSet();
  }
  
  //Uncomment this when we use it in a propagator builtin. 
  //Avoing compilation warning.
  /*static Gecode::IntSetArgs getIntSetArgs(VM vm, In x){
    Gecode::IntSetArgs v;
    
    assert(x.is<Cons>());

    if (x.is<Cons>()){
      StableNode* head=x.as<Cons>().getHead();
      StableNode* tail=x.as<Cons>().getTail();
      while (true){
    	UnstableNode uhead = Reference::build(vm, head);
    	RichNode rhead = uhead;
    	if(rhead.is<Cons>()){
    	  assert(rhead.is<Cons>());
	  Gecode::IntSet s=getIntSet(vm,rhead);
	  v << s;
	} 
    	UnstableNode utail = Reference::build(vm, tail);
    	RichNode rtail = utail;
    	if (!rtail.is<Cons>()){
    	  break;
    	}	  
    	UnstableNode ncons = Reference::build(vm, tail);
    	RichNode rncons = ncons;
    	head=rncons.as<Cons>().getHead();
    	tail=rncons.as<Cons>().getTail();	
      }
      return v;
    }
    return v;
    }*/

  static Gecode::IntSharedArray getIntSharedArray(VM vm,In x){
    if(x.is<Cons>()){
      return Gecode::IntSharedArray(getIntArgs(vm,x));
    }
    return Gecode::IntSharedArray();
  }

}

}

#endif
