#include<bits/stdc++.h>
using namespace std;

#ifndef _VM_H_
#define _VM_H_

typedef struct _item{
    int id;
    string name;
    int price;
}item;

class VM{
    private:
        vector<item> item_vec;
        string password;
        void add_item();
        void remove_item();
        void find_change(item, int , int , int , int);
        void purchase_item();
        void print_itemList();
        void print_optionList();
        void set_password(string);

    public:
        void start();
};


#endif