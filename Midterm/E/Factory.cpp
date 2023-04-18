#include "Factory.h"
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

Factory::Factory(){
    ;
}

void Factory::addItem(Item &a){
    items.push_back(a);
}

bool Factory::cmp(const Item& a, const Item& b){
    if(a.getYear() != b.getYear()) return a.getYear() < b.getYear();
    else if(a.getMonth() != b.getMonth()) return a.getMonth() < b.getMonth();
    else if(a.getDate() != b.getDate()) return a.getDate() < b.getDate();
    else return a.getName() < b.getName();
}

void Factory::sortItemsByEXP(){
    sort(items.begin(), items.end(), cmp);
}

ostream& operator<<(ostream& out, const Factory& f){

    size_t nameMaxWidth = 0;
    size_t quantityMaxWidth = 0;
    size_t costMaxWidth = 0;
    for(size_t i = 0; i < f.items.size(); i++){
        if(f.items[i].getName().length() > nameMaxWidth) nameMaxWidth = f.items[i].getName().length();
        if(to_string(f.items[i].getQuantity()).length() > quantityMaxWidth) quantityMaxWidth = to_string(f.items[i].getQuantity()).length();
        ostringstream ss;
        ss << f.items[i].getCost();
        if(ss.str().length() > costMaxWidth) costMaxWidth = ss.str().length();
    }

    out << "Factory Stock list:" << endl;
    for(size_t i = 0; i < f.items.size(); i++){
        out << setw(nameMaxWidth) << std::left << f.items[i].getName() << " - Quantity: " << setw(quantityMaxWidth) << std::right << f.items[i].getQuantity() << " - cost $" << setw(costMaxWidth) << f.items[i].getCost() << " EXP:" << f.items[i].getYear() << "/" << f.items[i].getMonth() << "/" << f.items[i].getDate() << endl;
    }
    return out;
}

int Factory::searchItem(string name){
    for(size_t i = 0; i < items.size(); i++){
        if(items[i].getName() == name) return i;
    }
    return -1;
}

void Factory::removeStock(string name, int remain){
    for(size_t i = 0; i < items.size(); i++){
        if(items[i].getName() == name){
            items[i].quantity -= remain;
        }
    }
}

void Factory::removeItem(Item &it){
    for(size_t i = 0; i < items.size(); i++){
        if(items[i].getName() == it.getName()){
            items.erase(items.begin() + i);
        }
    }
}