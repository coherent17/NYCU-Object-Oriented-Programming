#include <iostream>
#define f(x) x*x+x*2+4
using namespace std;

int main(void) {
    cout << "Please input an integer: ";
    int k=0;
    cin >> k;

    cout << "f(" << k << ")=" 
         << k << "*" << k << "+" << k << "*2+4=" 
         << f(k) << "\n";

    return 0;
}
