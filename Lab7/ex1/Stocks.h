#ifndef STOCKS_H
#define STOCKS_H
#include <iostream>
#include <string>
using namespace std;
class Stocks {
    private:
        int* type;         // number of stock types
        string* itemList;  // store all stock name

    public:
        Stocks(int);
        ~Stocks();
        Stocks& operator=(const Stocks&);
        void Initialize();
        void Display();
};

#endif