#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "stock.h"

using namespace std;

int main(){
    srand(531);
    int n;
    cout << "How many people want to buy this stock: ";
    cin >> n;
    vector<Stock> stock_vec;
    cout << "These people's name are: ";
    string temp;

    for(int i=0; i<n; i++){
        cin >> temp;
        stock_vec.push_back(Stock(temp));
    }

    bool first = true;
    while(true){
        if(!first){
            Stock::refresh_current_price();
            Stock::check_trade_is_available();
            // cout << "-----------------------------------------------" << endl;
            // Stock::show_current_price();
        }
        else{
            Stock::show_current_price();
        }
        first = false;
        bool flag = true;

        while(flag){
            cout << "Who want to do the trade: ";
            cin >> temp;
            for(int i=0; i<n; i++){
                if(stock_vec[i].get_owner_name() == temp){
                    flag = false;
                    temp = "4";
                    while(temp != "1" && temp != "2" && temp != "3"){
                        cout << "1.buy the stock / 2.sell the stock / 3.show stock: ";
                        cin >> temp;
                        if(temp == "1"){
                            stock_vec[i].buy();
                        }
                        else if(temp == "2"){
                            stock_vec[i].sell();
                        }
                        else if(temp == "3"){
                            stock_vec[i].show_stock();
                        }
                        else{
                            cout << "wrong choice. please enter again." << endl;
                        }
                    }
                }
            }
            if(flag){
                cout << "No this person. please enter again" << endl;
            }
        }
    }
    return 0;
}