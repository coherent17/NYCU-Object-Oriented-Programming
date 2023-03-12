#include <iostream>
using namespace std;

int *display();

int main() {
    cout << *display() << endl;
}

int *display() {
    int *pt = new int(0); //pt is int*
    //int pt = 0;
    int b[2] = {10,20};
    for (int i=0; i<2; i++)
      *pt += b[i];
      //pt += b[i];
    return pt; //return int*
    //return &pt;
}

