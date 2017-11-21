#include "../include/ProvAnnotations.hh"
#include "mylib.h"


int main(int agrc, const char* agrv[]){
	int x; 
	int a = m_read(0,&x,sizeof(x));
	int y = x;
	int z = y;
	int b = m_write(1,&z,sizeof(y));
	return 0;
}
