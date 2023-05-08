#include "Commodity.h"

Commodity::Commodity(){
    price = new int;
    score = new double;
}

Commodity::Commodity(string name, int _price){
    name = name;
    price = new int;
    *price = _price;
}

Commodity::~Commodity(){
    delete price;
    delete score;
}