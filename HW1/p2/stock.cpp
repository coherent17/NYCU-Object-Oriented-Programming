#include "stock.h"

const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;

Stock::Stock() : owner_name(""){
    ticket_num = 0;
    avg_buy_price = 0;
}

Stock::Stock(string name) : owner_name(name){
    ticket_num = 0;
    avg_buy_price = 0;
}

Stock::Stock(string name, int n1) : owner_name(name){
    ticket_num = 0;
    avg_buy_price = 0;
}

//Stock(string name, double total1);
void Stock::operator +(const Stock &s){

}

void Stock::operator -(const Stock &s){

}
void Stock::buy(){

}
void Stock::sell(){

}
void Stock::show_stock(){

}
string Stock::get_owner_name() const{
    return owner_name;
}

void Stock::show_current_price(){

}
void Stock::check_trade_is_available(){

}
void Stock::refresh_current_price(){

}