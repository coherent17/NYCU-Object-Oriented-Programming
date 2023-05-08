#include "Phone.h"
#include <iostream>

using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

Phone::Phone(int in_rate, int out_rate, int length, int width):Electronics(length, width), in_rate(in_rate), out_rate(out_rate){
    currentt_power = 0;
}

Phone::~Phone(){

}

void Phone::poweron(){
    if(get_charging()) set_usage(true);
}

void Phone::run(){
    if(get_charging()) currentt_power += in_rate;
    if(get_usage()) currentt_power -= out_rate;
    currentt_power = min(currentt_power, 100);
    if(currentt_power < 0) currentt_power = 0;

    cout << "Phone: ";
    if(get_charging()) cout << "(charging) ";
    else cout << "(not charging) ";
    cout << currentt_power << "%" << endl;
    cout << " ";
    for(int i = 0; i < get_width(); i++){
        cout << "-";
    }
    cout << " " << endl;
    for(int i = 0; i < get_length() - 2; i++){
        cout << "|";
        for(int j = 0; j < get_width(); j++){
            if(get_usage() && currentt_power > 0) cout << "*";
            else cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for(int i = 0; i < get_width(); i++){
        cout << "-";
    }
    cout << " " << endl;
}

void Phone::charge(){
    set_charging(!get_charging());
}

void Phone::poweroff(){
    set_usage(false);
}