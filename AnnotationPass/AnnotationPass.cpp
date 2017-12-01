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

cl::opt<std::string> InputYAML("yaml-file", cl::desc("Specify YAML input filename"), cl::value_desc("filename"));

	struct AnnotationPass : public FunctionPass {
	
		static char ID;

		AnnotationCallSemantics CS;

		AnnotationPass() : FunctionPass(ID),CS(InputYAML) {}

		virtual bool runOnFunction(Function &F){;
			F.dump();
			if (InputYAML=="") {
				errs()<<"No YAML file.\n";
				return false;
			}
			for (auto& B:F){
				for (auto& I:B){
					if (auto* CI=dyn_cast<CallInst>(&I)) {
						auto CallOutputs=CS.CallOutputs(CI);
						for (const auto& ArgNum:CallOutputs) {
							if (const auto& CallIn =dyn_cast<CallInst>(ArgNum)){
								errs()<<CallIn->getCalledFunction()->getName()<<":";
							} 
							else ArgNum->dump();
						}
							//errs() << ArgNum << "\t";
						errs() << "\nSource:" << (CS.IsSource(CI)?"yes":"no");
						errs() << "\nSink:" << (CS.CanSink(CI)?"yes":"no:") <<"\n\n";
					}
				}
			}
			return false;
		}

	};

char AnnotationPass::ID = 0;
static RegisterPass<AnnotationPass> X("AnnotationPass", "LLVM Annotation Pass");

