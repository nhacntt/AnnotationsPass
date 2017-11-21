#include "../include/ProvAnnotations.hh"
//#include "mylib.h"
//#include "empty.h"
//#include <unistd.h>

_SOURCE_ int bar(int x, bool y, const char* z){return 4;}

int main(int agrc, const char* agrv[]){
	int fd1;
	int fd2;
	int n;
	bar(100,fd2,"abc");
	return 0;
}
