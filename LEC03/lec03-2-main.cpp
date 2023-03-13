#include <iostream>
#include "lec03-2.h"
using namespace std;

int main() 
{
	CStr one("pg03-2");	//call A
	CStr two(one);		//call B; CStr two = one;
	two.ShowCStr();

	char *p = "Peter Pan";
    CStr thr(p);		//call B
    //delete [] p; 
    //thr.~CStr();		//call destructor
 
	return 0;
}
