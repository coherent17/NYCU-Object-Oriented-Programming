#include <iostream>
#define debug 1
#define print_val cout << "a=" << a << " & b=" << b << endl;\
                  cout << "c=" << c << endl 
using namespace std;

int main(void) {
    cout << "Please input two integers: ";
    int a, b;
    cin >> a >> b;
    int c = a*b + 4*b;

    if (debug) print_val;

    cout << "***Program ends here!" << endl;
    return 0;
}
