#include "User.h"

User::User(string name, string passwd, vector<const Song *> &songs):name(name), passwd(passwd), songs(songs){

}

User::~User(){
    for(size_t i = 0; i < all_list.size(); i++){
        delete all_list[i];
    }
}

string User::get_name()const{
    return name;
}

string User::get_passwd()const{
    return passwd;
}

// show all playlists of the user (sort by list name)
void User::show_list(){
    cout << "|| PLAY LIST: ";
    for(size_t i = 0; i < all_list.size(); i++){
        cout << all_list[i]->name << " ";
    }
    cout << "||" << endl;
}

// choose a playlist
void User::choose_list(){
    cout << "CHOOSE LIST" << endl;
    string list_name;
    cout << "list name: "; cin >> list_name;
    for(size_t i = 0; i < all_list.size(); i++){
        if(all_list[i]->name == list_name){
            curr_list = all_list[i];
            return;
        }
    }
    //if not found the playlist, set it nullptr
    curr_list = nullptr;
    cout << "List doesn't exist" << endl;
}  

// add a playlist
void User::add_list(){
    cout << "ADD LIST" << endl;
    string List_Name;
    cout << "List Name: "; cin >> List_Name;
    Playlist *p = new Playlist(List_Name, songs);
    all_list.push_back(p);
    sort(all_list.begin(), all_list.end(), list_cmp);
}     