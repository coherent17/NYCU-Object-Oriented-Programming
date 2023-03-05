#include<iostream>
#include<string>
using namespace std;

typedef struct person_t{
    string name;
    unsigned age;
    void printInfo(){
        cout<<"Name: "<<name<<" | Age: "<<age<<endl;
    }
}person;

int main(){
    person p = {"Janet", 20};
    p.printInfo();
    return 0;
}