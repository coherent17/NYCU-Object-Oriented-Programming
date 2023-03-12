#include "A.h"
#include "B.h"
 
int main() {
	A a;
	B b;
	a.b = &b;
	b.a = &a;
	return 0;
}