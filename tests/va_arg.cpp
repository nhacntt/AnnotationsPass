#include "llvm_annotations.h"
//#include <cstdarg>

void Foo ( __In int n,  ...);

int main (){
	int n;
	Foo(2,2.5,'a');
	
}
void Foo ( __In int n,  ...){}

