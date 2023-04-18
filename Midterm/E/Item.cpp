#include "Item.h"
#include <string>

using namespace std;

Item::Item(string name, int quantity, double cost, int year, int month, int date){
    this->name = name;
    this->quantity = quantity;
    this->cost = cost;
    this->EXP = {year, month, date};
}

Item::Item(string name, int quantity, double price, double cost, int year, int month, int date){
    this->name = name;
    this->quantity = quantity;
    this->price = price;
    this->cost = cost;
    this->EXP = {year, month, date};
}

string Item::getName()const{
    return name;
}

int Item::getQuantity()const{
    return quantity;
}

double Item::getCost()const{
    return cost;
}

double Item::getPrice()const{
    return price;
}

Item::Date Item::getEXP()const{
    return EXP;
}

int Item::getYear()const{
    return EXP.year;
}

int Item::getMonth()const{
    return EXP.month;
}

int Item::getDate()const{
    return EXP.date;
}