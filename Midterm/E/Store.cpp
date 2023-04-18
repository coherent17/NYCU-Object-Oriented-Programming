#include "Store.h"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

Store::Store(){
    ;
}

void Store::addItem(Item &a){
    items.push_back(a);
}

bool Store::cmpName(const Item& a, const Item& b){
    return a.getName() < b.getName();
}

void Store::sortItemsByName(){
    sort(items.begin(), items.end(), cmpName);
}
void Store::show_menu(){
    sort(items.begin(), items.end(), cmpName);

    size_t nameMaxWidth = 0;
    size_t quantityMaxWidth = 0;
    size_t priceMaxWidth = 0;
    for(size_t i = 0; i < items.size(); i++){
        if(items[i].getName().length() > nameMaxWidth) nameMaxWidth = items[i].getName().length();
        if(to_string(items[i].getQuantity()).length() > quantityMaxWidth) quantityMaxWidth = to_string(items[i].getQuantity()).length();
        ostringstream ss;
        ss << items[i].getPrice();
        if(ss.str().length() > priceMaxWidth) priceMaxWidth = ss.str().length();
    }

    int i = 0;
    int j = 1;

    while(i < (int)items.size()){
        int q = items[i].getQuantity();
        if(j < (int)items.size())
            while(items[i].getName() == items[j].getName()){
                q += items[j].getQuantity();
                j++;
            }
        cout << setw(nameMaxWidth) << std::left << items[i].getName() << " - Quantity: " << setw(quantityMaxWidth) << std::right << q << " - price $" << setw(priceMaxWidth) << items[i].getPrice() << endl;

        i = j;
        j = i + 1;
    }
}

bool Store::cmp(const Item& a, const Item& b){
    if(a.getYear() != b.getYear()) return a.getYear() < b.getYear();
    else if(a.getMonth() != b.getMonth()) return a.getMonth() < b.getMonth();
    else if(a.getDate() != b.getDate()) return a.getDate() < b.getDate();
    else return a.getName() < b.getName();
}

void Store::sortItemsByEXP(){
    sort(items.begin(), items.end(), cmp);
}

int compare_exp(int y1, int m1, int d1, int y2, int m2, int d2){
    if (y1 != y2) {
        return (y1 < y2) ? -1 : 1;
    }
    else if (m1 != m2) {
        return (m1 < m2) ? -1 : 1;
    }
    else if (d1 != d2) {
        return (d1 < d2) ? -1 : 1;
    }
    else {
        return 0;
    }
}

double Store::get_expired(string today){
    stringstream ss(today);
    char delimiter = '/';
    int y1, m1, d1;
    ss >> y1 >> delimiter >> m1 >> delimiter >> d1;

    sortItemsByEXP();
    double loss = 0;

    auto it = items.begin();
    while (it != items.end()) {
        int result = compare_exp(y1, m1, d1, (*it).getYear(), (*it).getMonth(), (*it).getDate());
        if (result > 0){
            loss -= (*it).getCost() * (*it).getQuantity();
            it = items.erase(it);
        }
        else {
            ++it;
        }
    }
    return loss;
}   

double Store::get_profit(string name, int quantity){
    double profit = 0;
    sortItemsByEXP();
    int remain = quantity;

    auto it = items.begin();
    while (it != items.end()){
        if((*it).getName() == name){
            if((*it).getQuantity() >= remain){
                profit += ((*it).getPrice() - (*it).getCost()) * remain;
                if((*it).getQuantity() == remain) it = items.erase(it);
                else (*it).quantity -= remain;
                return profit;
            }
            else{
                profit += ((*it).getPrice() - (*it).getCost()) * (*it).getQuantity();
                remain -= (*it).getQuantity();
                it = items.erase(it);
            }
        }
        else {
            ++it;
        }
    }

    return profit;
}

ostream& operator<<(ostream& out, const Store& s){

    size_t nameMaxWidth = 0;
    size_t quantityMaxWidth = 0;
    size_t priceMaxWidth = 0;
    size_t costMaxWidth = 0;
    for(size_t i = 0; i < s.items.size(); i++){
        if(s.items[i].getName().length() > nameMaxWidth) nameMaxWidth = s.items[i].getName().length();
        if(to_string(s.items[i].getQuantity()).length() > quantityMaxWidth) quantityMaxWidth = to_string(s.items[i].getQuantity()).length();
        ostringstream s1, s2;
        s1 << s.items[i].getPrice();
        s2 << s.items[i].getCost();
        if(s1.str().length() > priceMaxWidth) priceMaxWidth = s1.str().length();
        if(s2.str().length() > costMaxWidth) costMaxWidth = s2.str().length();
    }

    out << "commodity list:" << endl;
    for(size_t i = 0; i < s.items.size(); i++){
        out << setw(nameMaxWidth) << std::left << s.items[i].getName() << " - Quantity: " << setw(quantityMaxWidth) << std::right << s.items[i].getQuantity() << " - price $" << setw(priceMaxWidth) << s.items[i].getPrice() << " cost:" << setw(costMaxWidth) << s.items[i].getCost() << "  EXP:" << s.items[i].getYear() << "/" << s.items[i].getMonth() << "/" << s.items[i].getDate() << endl;
    }
    return out;
}