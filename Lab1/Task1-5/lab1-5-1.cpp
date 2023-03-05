#include<iostream>
#include<string>
using namespace std;
typedef struct person_t{
    string name;
    unsigned age;
}person;

void printInfo(person p){
    cout<<"Name: "<<p.name<<" | Age: "<<p.age<<endl;
}

int main(){
    person p = {"Janet", 20};
    printInfo(p);
    return 0;
}