#include "User.h"
#include <iostream>

User::User(string name, string passwd, vector<const Song *> &songs): songs(songs){
    this->name = name;
    this->passwd = passwd;
}

User::~User(){

}

string User::get_name() const{
    return name;
}

string User::get_passwd() const{
    return passwd;
}

void User::show_list(){
    cout << "|| PLAY LIST: ";
    for(size_t i = 0; i < all_list.size(); i++){
        cout << all_list[i]->get_name() << " ";
    }
    cout << "||" << endl;
}

void User::choose_list(){
    cout << "CHOOSE LIST" << endl;
    string list_name;
    cout << "list name: "; cin >> list_name;
    for(size_t i = 0; i < all_list.size(); i++){
        if(all_list[i]->get_name() == list_name){
            curr_list = all_list[i];
            return;
        }
    }
    //if not found the playlist, set it nullptr
    curr_list = nullptr;
}

void User::add_list(){
    cout << "ADD LIST" << endl;
    string List_Name;
    cout << "List Name: "; cin >> List_Name;
    Playlist *p = new Playlist(List_Name, songs);
    all_list.push_back(p);
}