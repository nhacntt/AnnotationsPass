#include "AnnotationsHelper.hh"


using namespace std;
using namespace llvm;

map<string,vector<int>> getInputArgMap(FuncDeclList& FL){
	map<string,vector<int>> InputArgMap;

	for (const auto& FD:FL.List) {
		vector<int> ArgVec;
		for (const auto& P:FD.ParamVec) {
			auto Annotations=P.Annotations;
			for (int i = 0; i< Annotations.size(); ++i) {
				if (Annotations[i]==INPUT_ANNOTATION) {
					ArgVec.push_back(i);
				}
			}
		}
		
		if (not ArgVec.empty()) {
			InputArgMap.insert(make_pair(FD.MangledName,ArgVec));
		}
	}

	return InputArgMap;
}
map<string,vector<int>> getOutputArgMap(FuncDeclList& FL) {
	map<string,vector<int>> OutputArgMap;

	for (const auto& FD:FL.List) {
		vector<int> ArgVec;
		for (const auto& P:FD.ParamVec) {
			auto Annotations=P.Annotations;
			for (int i = 0; i< Annotations.size(); ++i) {
				if (Annotations[i]==OUTPUT_ANNOTATION) {
					ArgVec.push_back(i);
				}
			}
		}
		

		if (not ArgVec.empty()) {
			OutputArgMap.insert(make_pair(FD.MangledName,ArgVec));
		}
	}

	return OutputArgMap;
}

StringSet<> getExplicitSourceNames(FuncDeclList& FL) {
	StringSet<> SourceNames;

	for (const auto& FD:FL.List) {
		for (const auto& A:FD.Annotations) {
			if (A==SOURCE_ANNO){
				SourceNames.insert(A);
			}
		}
	}
	
	return SourceNames;
}

StringSet<> getExplicitSinkNames(FuncDeclList& FL) {
	StringSet<> SinkNames;

	for (const auto& FD:FL.List) {
		for (const auto& A:FD.Annotations) {
			if (A==SINK_ANNO){
				SinkNames.insert(A);
			}
		}
	}
	
	return SinkNames;
}

