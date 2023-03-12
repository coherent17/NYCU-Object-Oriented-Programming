#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

double Fun() {
	cout << "nothing" << endl;	
	return 0.1;
} 

double Fun2() {
	cout << "something" << endl;	
	return 0.2;
}

int main(){
	double (*pF)();

	pF = &Fun;
	double result = (*pF)();
	
	pF = &Fun2;
	cout << pF() << endl;	
	
	cout << result << endl;

	return 0;
}
