#include "llvm_annotations.h"
#include "mylib.h"
//#include "empty.h"
//#include <unistd.h>

int bar(int x, bool y, const char* z){return 4;}

void foo_main(__Anno1 __Anno2 __Anno3 __Anno4 __Anno5 int);

int main(int agrc, const char* agrv[]){
	int fd1;
	int fd2;
	int n;
	foo(fd1,fd2,n);
	bar(100,fd2,"abc");
	return 0;
}
