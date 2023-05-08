#include "TV.h"
#include <iostream>
using namespace std;

TV::TV(int length, int width): Electronics(length, width){
    
}

TV::~TV(){

}

void TV::poweron(){
    if(get_charging()) set_usage(true);
}

void TV::run(){
    cout << "TV: ";
    if(get_charging()) cout << "(charging) " << endl;
    else cout << "(not charging) " << endl;

    cout << " ";
    for(int i = 0; i < get_width(); i++){
        cout << "-";
    }
    cout << " " << endl;
    for(int i = 0; i < get_length() - 2; i++){
        cout << "|";
        for(int j = 0; j < get_width(); j++){
            if(get_usage() && get_charging()) cout << "*";
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

void TV::charge(){
    set_charging(!get_charging());
}

void TV::poweroff(){
    set_usage(false);
}