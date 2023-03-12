#include <iostream>
//#define DEBUG
#define dprint cout << "a=" << a << " & b=" << b << " ";\
               cout << "c=" << c << endl 
using namespace std;

int main(void) {
    cout << "Please input two integers: ";
    int a, b;
    cin >> a >> b;
    int c = a*b + 4*b;

#ifdef DEBUG
    dprint;
#else
    cout << "c=f(" << a << "," << b << ")=" << c << endl;
#endif  

    cout << "***Program ends here!" << endl;
    return 0;
}
