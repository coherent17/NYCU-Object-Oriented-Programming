#include <iostream>
#define f(x) (x)*(x)+(x)*2+4
using namespace std;

int main(void) {
    cout << "Please input integer a: ";
    int a=0;
    cin >> a;

    cout << "f(" << a+1 << ")=" 
         << a+1 << "*" << a+1 << "+" << a+1 << "*2+4=" 
         << f(a+1) << "\n";

    return 0;
}
