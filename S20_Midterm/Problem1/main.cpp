#include <iostream>
#include "Square.h"
using namespace std;

int main(){
    //Q1
    cout << "---Q1---" << endl;
    double center_x = 6, center_y = 4, len = 4, angle =0;
    Square s1 = Square(center_x, center_y, len, angle);
    Square s2 = Square(s1);
    Square s3 = Square(s1);
    Square s4 = Square(s1);

    cout << s1;
    cout << s2;

    //Q2
    cout << "---Q2---" << endl;
    s1 = s1 * 2;
    s2 = s2^45;
    s3 = s3 + 5;
    Center offset = Center(3,2);
    s4 += offset;
    
    cout << s1;
    cout << s2;
    cout << s3;
    cout << s4;


    //Q3
    cout << "---Q3---" << endl;
    cout << s1++;
    cout << ++s1;
    cout << s1--;
    cout << --s1;
    cout << (s1 == s2) << endl;
    cout << (s2 < s1) << endl;

    return 0;
}