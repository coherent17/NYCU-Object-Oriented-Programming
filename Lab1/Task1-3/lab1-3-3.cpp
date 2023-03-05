#include <iostream>

using namespace std;

#define D_TRIPLE(n) (n+n+n);
inline int I_TRIPLE(int n) { return n+n+n;}

struct MyClass{
    int m_nValue;
    int GetValue();
};

int MyClass::GetValue(){
    cout<<"hi";
    return m_nValue;
}

int main(){
    MyClass my;
    my.m_nValue=2;
    int r1 = D_TRIPLE(my.GetValue());
    cout<<endl;
    int r2 = I_TRIPLE(my.GetValue());
    cout<< endl;
    cout << r1<<" "<<r2<<endl;
    return 0;
}