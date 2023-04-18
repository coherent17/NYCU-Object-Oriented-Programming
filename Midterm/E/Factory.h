#ifndef FACTORY_H_
#define FACTORY_H_

#include "Item.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Factory{

    friend class Item;

    public:
        vector<Item> items;

    public:
        Factory();
        void addItem(Item &);
        static bool cmp(const Item& a, const Item& b);
        void sortItemsByEXP();
        friend ostream& operator<<(ostream& out, const Factory& f);
        int searchItem(string);
        void removeStock(string, int);
        void removeItem(Item &);

};


#endif