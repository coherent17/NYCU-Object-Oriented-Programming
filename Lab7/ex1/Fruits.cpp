#include "Fruits.h"

Fruits::Fruits(int a, int b, int c) :Stocks(a){
    
    expired_month = new int;
    *expired_month = b;

    expired_date = new int;
    *expired_date = c;
}

Fruits::~Fruits(){
    if(expired_month != nullptr){
        delete expired_month;
        expired_month = nullptr;
    }
    
    if(expired_date != nullptr){
        delete expired_date;
        expired_date = nullptr;
    }
}

Fruits& Fruits::operator=(const Stocks& S){
    delete expired_date;
    delete expired_month;
    expired_date = nullptr;
    expired_month = nullptr;
    Stocks::operator=(S);
    return *this;
}

void Fruits::Display(){
    Stocks::Display();
    if(expired_date != nullptr)
        cout << "Expired at " << *expired_month << "/" << *expired_date << " " << endl;
    else cout << "No Expiration Date" << endl;
}