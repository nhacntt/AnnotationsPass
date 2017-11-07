#include "llvm_annotations.h"
//#include <iostream>

__df(1,0)
__df(2,0)

void foo(__Anno1 __Anno2 int a,__Anno3 int b, int c);//{b<-a,c b=a+c;}
	

__Anno1 void bar(int x, __Anno2 int y);
