#include "AnnotationsHelper.h"

#include <llvm/Analysis/DeclarationAnalysis.h>
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IntrinsicInst.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
using namespace llvm;

namespace {
	struct AnnotationsPass : public FunctionPass {
		static char ID;
		AnnotationsPass() : FunctionPass(ID) {}

		virtual bool runOnFunction(Function &F){
			for (auto& B:F){
				for (auto& I:B){
					if (isa<CallInst>(I)) {
						Function* func =cast<CallInst>(I).getCalledFunction();
						if(func->getName()=="llvm.var.annotation"){
        /*
							GlobalVariable* annotationStrVar = dyn_cast<GlobalVariable>(I.getOperand(1)->stripPointerCasts());
	//errs()<<*annotationStrVar;
        ConstantDataArray* annotationStrValArray = dyn_cast<ConstantDataArray> (annotationStrVar->getInitializer());

        StringRef annotationStrValCString = annotationStrValArray->getAsCString();
							errs()<<annotationStrValCString.data();
							*/
							auto anno= cast<GlobalVariable*>(I.getOperand(1)->stripPointerCasts())->getInitializer();
							errs()<<anno.getName();
						}
					}
				}
			}

			return false;
		}
  	};
}

char AnnotationsPass::ID = 0;
static RegisterPass<AnnotationsPass> X("AnnotationsPass", "LLVM Annotations Pass", false, false);

