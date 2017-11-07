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
		std::map<string, FuncDecl> FuncDeclMap;
		static char ID;

		AnnotationsPass() : FunctionPass(ID) {

		auto F=FuncDeclList::fromYAML(MetaFilename);
		if (std::error_code ec = F.getError()) {
			errs()<<ec.message();
			return;
		}

		FuncDeclList FL=F.get();

		for (const auto& i:FL) {
			FuncDeclMap.insert(std::make_pair(i->MangledName,*i)
		}

		virtual bool runOnFunction(Function &F){
			if (FuncDeclMap.empty()) {
				return false;
			for (auto& B:F){
				for (auto& I:B){
					if (isa<CallInst>(I)) {
						Function* func =cast<CallInst>(I).getCalledFunction();
							
						}
					}
				}
			}

			return false;
		}
  	};
}// namespace

char AnnotationsPass::ID = 0;
static RegisterPass<AnnotationsPass> X("AnnotationsPass", "LLVM Annotations Pass");

