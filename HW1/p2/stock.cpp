#include "Stock.h"
#include <iostream>
#include <cmath>

using namespace std;

const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;
double Stock::cur_price = init_price;
bool Stock::trade_available = true;

Stock::Stock() : owner_name(""){
    ticket_num = 0;
    avg_buy_price = cur_price;
}

Stock::Stock(string name) : owner_name(name){
    ticket_num = 0;
    avg_buy_price = 0;
}

Stock::Stock(string name, int n1) : owner_name(name){
    ticket_num = n1;
    avg_buy_price = cur_price;
}


void Stock::operator +(const Stock &s){
    avg_buy_price = (avg_buy_price * ticket_num + s.avg_buy_price * s.ticket_num) / (ticket_num + s.ticket_num);
    ticket_num += s.ticket_num;
}

void Stock::operator -(const Stock &s){

    if(ticket_num - s.ticket_num == 0){
        avg_buy_price = 0;
        ticket_num = 0;
        return;
    }

    avg_buy_price = (avg_buy_price * ticket_num - s.avg_buy_price * s.ticket_num) / (ticket_num - s.ticket_num);
    ticket_num -= s.ticket_num;
}


void Stock::buy(){
    if(trade_available){
        int x;
        cout << "How many tickets do you want to buy: "; cin >> x;
        (*this) + Stock(owner_name, x);
    }
    else cout << "The trade is not available today." << endl;
}
void Stock::sell(){
    if(trade_available){
        int x;
        cout << "How many tickets do you want to sell: "; cin >> x;

        if(x <= ticket_num){
            (*this) - Stock(owner_name, x);
        }
        else{
            cout << "you don't have enough stock ticket" << endl;
        }
    }
    else cout << "The trade is not available today." << endl;
}

void Stock::show_stock(){
    cout << owner_name << ", you have " << ticket_num << " stocks and the average price is " << avg_buy_price << endl;
}


string Stock::get_owner_name() const{
    return owner_name;
}

void Stock::show_current_price(){
    cout << "-----------------------------------------------" << endl;
    cout << "current price of the stock: " << cur_price << endl;
}

void Stock::check_trade_is_available(){
    if(fabs(cur_price - init_price) / init_price > limit_ratio && trade_available == true){
        trade_available = false;
    }
    if(trade_available == false) cout << "trade is not available anymore" << endl;
}

void Stock::refresh_current_price(){
    cur_price = cur_price + static_cast<double>(rand() % 500) / 100 - 2.5;
    show_current_price();
}