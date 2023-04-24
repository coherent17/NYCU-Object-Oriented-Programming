#include "Stocks.h"

Stocks::Stocks(int x): type(new int(x)){
    itemList = new string[x];
}

Stocks::~Stocks(){
    if(type != nullptr){
        delete type;
        type = nullptr;
    }

    if(itemList != nullptr){
        delete []itemList;
        itemList = nullptr;
    }
}

Stocks& Stocks::operator=(const Stocks& S){

    if(type != nullptr){
        delete type;
        type = nullptr;
    }

    if(itemList != nullptr){
        delete []itemList;
        itemList = nullptr;
    }
    
    type = new int;
    *type = *(S.type);

    itemList = new string[*(S.type)];
    for(int i = 0; i < *S.type; i++){
        itemList[i] = S.itemList[i];
    }
    return *this;
}

void Stocks::Initialize(){
    cout << "Initialize" << endl;
    for(int i = 0; i < *type; i++){
        cout << "Item " << i + 1 << ": "; cin >> itemList[i];
    }
}

void Stocks::Display(){
    cout << "Item List: ";
    for(int i = 0; i < *type; i++){
        cout << itemList[i] << " ";
    }
    cout << endl;
}