#include <iostream>
#include "P1.h"
using namespace std;

int main() {

//Task 1
#ifdef P1T1	
	CProperty *x;
	CProperty y;
#endif

//Task 2
#ifdef P1T2
	CCar p("Joe", 2000, 100);
	CHome q("Tom", 3, 40);
	cout << p << q;
#endif

//Task 3
#ifdef P1T3
	CHomeCar r("Dan", 1000, 5000, 1, 8, 6);
	cout << r;
#endif	

//Task 4
#ifdef P1T4
	const CHomeCar r("Bob", 2000, 15000, 2, 4, 4);
	const CProperty *z = &r;
	cout << z->get_owner() << "\'s property: $" << z->computePrice()/1000000.0 << "M\n";
	z = new CHome("Kim", 5, 20);
	cout << z->get_owner() << "\'s property: $" << z->computePrice()/1000000.0 << "M\n";
#endif	

	return 0;
}
