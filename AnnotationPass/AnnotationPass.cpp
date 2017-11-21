#include "AnnotationCallSemantics.hh"

#include <llvm/Analysis/DeclarationAnalysis.h>
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IntrinsicInst.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <llvm/Support/CommandLine.h>

using namespace llvm;

cl::opt<string> InputYAML("yaml-file", cl::desc("Specify YAML input filename"), cl::value_desc("filename"));

	struct AnnotationPass : public FunctionPass {
	
		static char ID;

		AnnotationCallSemantics CS;

		AnnotationPass() : FunctionPass(ID),CS(InputYAML) {}

		virtual bool runOnFunction(Function &F){
			//if (CS ==NULL) return false;
			
			errs()<<F.getName()<<"\n";
			F.dump();
			for (auto& B:F){
				for (auto& I:B){
					if (auto* CI=dyn_cast<CallInst>(&I)) {
						CI->dump();
						errs() << "\nOutput Parameters:";
						//for (const auto& ArgNum:CS->CallOutputs(CI)) errs() << ArgNum << "\t";
						//errs() << "\nSource:" << CS->IsSource(CI);
						//errs() << "\nSource:" << CS->IsSource(CI) <<"\n";
					}
				}
			}
			return false;
		}

	};

char AnnotationPass::ID = 0;
static RegisterPass<AnnotationPass> X("AnnotationPass", "LLVM Annotation Pass");

