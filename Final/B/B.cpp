// B.cpp
#include "Complex.h"
#include "Queue.h"
#include<bits/stdc++.h>
using namespace std;
int main(){
    Queue<int> q1;
    if(q1.empty()) cout << "Queue is empty!" << endl;
    else cout << "Queue is not empty!" << endl;

    q1.push(5); cout << "Pushed " << q1.back() << endl;
    q1.push(4); cout << "Pushed " << q1.back() << endl;
    q1.push(3); cout << "Pushed " << q1.back() << endl;

    if(q1.empty()) cout << "Queue is empty!" << endl;
    else cout << "Queue is not empty!" << endl;

    int size = q1.size();
    for(int i=0; i<size; i++){
        cout << q1.front() << " ";
        q1.pop();
    } cout << endl << endl;

    Queue<Complex> q2;
    if(q2.empty()) cout << "Queue is empty!" << endl;
    else cout << "Queue is not empty!" << endl;

    Complex c1; // real = 0, imag = 0
    q2.push(c1); cout << "Pushed " << q2.back() << endl;
    Complex c2(3.9, 7.1);
    q2.push(c2); cout << "Pushed " << q2.back() << endl;
    c1.set_real(5.6); c1.set_imag(9.4);
    q2.push(c1); cout << "Pushed " << q2.back() << endl;
    Complex c3 = c1 + c2;
    q2.push(c3); cout << "Pushed " << q2.back() << endl;
    c3 = c1 - c2;
    q2.push(c3); cout << "Pushed " << q2.back() << endl;
    c3 += c1;
    q2.push(c3); cout << "Pushed " << q2.back() << endl;
    c3 -= c2;
    q2.push(c3); cout << "Pushed " << q2.back() << endl;

    if(q2.empty()) cout << "Queue is empty!" << endl;
    else cout << "Queue is not empty!" << endl;

    size = q2.size();
    for(int i=0; i<size; i++){
        cout << q2.front() << " ";
        q2.pop();
    } cout << endl;

    return 0;
}