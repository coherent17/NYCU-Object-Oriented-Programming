#ifndef _STORE_H_
#define _STORE_H_

#include "Item.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Store{
    
    private:
        vector<Item> items;

    public:
        Store();
        void addItem(Item &);
        static bool cmpName(const Item& a, const Item& b);
        void sortItemsByName();
        void show_menu();
        static bool cmp(const Item& a, const Item& b);
        void sortItemsByEXP();
        double get_expired(string);
        double get_profit(string, int);

        friend ostream& operator<<(ostream& out, const Store& s);
};

#endif