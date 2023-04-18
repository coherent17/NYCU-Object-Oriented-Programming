#ifndef ITEMH_
#define ITEMH_

#include <string>

using namespace std;

class Item{

    friend class Factory;
    friend class Store;
    private:
        string name;
        int quantity;
        double cost;
        double price;
        struct Date{
            int year;
            int month;
            int date;
        }EXP;

    public:
        Item(string, int, double, int, int, int);
        Item(string, int, double, double, int, int, int);
        
        //getter
        string getName()const;
        int getQuantity()const;
        double getCost()const;
        double getPrice()const;
        Date getEXP()const;
        int getYear()const;
        int getMonth()const;
        int getDate()const;
};

#endif