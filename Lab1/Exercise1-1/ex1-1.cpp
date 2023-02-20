#include <iostream>
#include "Double.h"

using namespace std;

int main(){
    cout << "Please enter the number: ";
    double num;
    cin >> num;

    Double MyNum = Double(num);
    MyNum.showResult();

return 0;
}