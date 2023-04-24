#include "Fruits.h"
#include "Stocks.h"
using namespace std;

int main() {
    // Test 1
    Stocks A(3);  // create a Stocks called A, with *type = 3
    Stocks B(3);

    cout << "Stocks A" << endl;
    A.Initialize();
    A.Display();
    cout << endl;

    cout << "Stocks B" << endl;
    B.Initialize();
    B.Display();
    cout << endl;

    cout << "Stocks B = A" << endl;
    B = A;
    B.Display();
    cout << endl;

    Fruits C(3, 10, 15);  // create a Fruits called C, with *type = 3, *expired_month = 10, *expired_date = 3
    cout << "Fruits C" << endl;
    C.Initialize();
    C.Display();
    cout << endl;

    cout << "Stocks B = C" << endl;
    B = C;
    B.Display();
    cout << endl;

    cout << "Fruits C = A" << endl;
    C = A;
    C.Display();
    cout << endl;
    return 0;

    // Test 2
    // Stocks A(2);
    // Stocks B(3);

    // cout << "Stocks A" << endl;
    // A.Initialize();
    // A.Display();
    // cout << endl;

    // cout << "Stocks B" << endl;
    // B.Initialize();
    // B.Display();
    // cout << endl;

    // cout << "Stocks B = A" << endl;
    // B = A;
    // B.Display();
    // cout << endl;

    // Fruits C(4, 10, 15);
    // cout << "Fruits C" << endl;
    // C.Initialize();
    // C.Display();
    // cout << endl;

    // cout << "Stocks B = C" << endl;
    // B = C;
    // B.Display();
    // cout << endl;

    // cout << "Fruits C = A" << endl;
    // C = A;
    // C.Display();
    // cout << endl;
    // return 0;
}