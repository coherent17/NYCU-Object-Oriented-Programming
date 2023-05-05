#include "Spotify.h"
#include "Song.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
Spotify::Spotify(string file){

    curr_user = nullptr;

    ifstream fin(file);
    string name;
    string artist;
    string song_len;

    while(getline(fin, name)){
        getline(fin, artist);
        getline(fin, song_len);
        const Song* s = new Song(name, artist, song_len);
        songs.push_back(s);
    }
    sort(songs.begin(), songs.end(), song_cmp);
    fin.close();
}

Spotify::~Spotify(){

}

void Spotify::controlManual(){
    while(1){
        scene1();
        string choice;
        cout << ">> "; cin >> choice;
        if(choice == "s") printSongList();
        else if(choice == "a") addSong();
        else if(choice == "c") createUser();
        else if(choice == "U") printUserList();
        else if(choice == "i") logIN();
    }
    
}

void Spotify::addSong(){
    cout << "ADD SONG" << endl;
    string name;
    string artist;
    string song_len;
    cout << "Song Name: "; cin >> name;
    cout << "Artist: "; cin >> artist;
    cout << "Song Length: "; cin >> song_len;
    const Song* s = new Song(name, artist, song_len);
    songs.push_back(s);
    sort(songs.begin(), songs.end(), song_cmp);
}

void Spotify::createUser(){
    cout << "CREATE USER" << endl;
    string name;
    string passwd; 
    cout << "User Name: "; cin >> name;
    cout << "User Passwd: "; cin >> passwd;
    for(size_t i = 0; i < users.size(); i++){
        if(name == users[i]->get_name()){
            cout << "User already exists." << endl;
            return;
        }
    }

    User *u = new User(name, passwd, songs);
    users.push_back(u);
}

void Spotify::logIN(){
    cout << "LOG IN" << endl;
    string name;
    string passwd;
    cout << "User Name: "; cin >> name;
    cout << "User Passwd: "; cin >> passwd;

    bool found = false;

    for(size_t i = 0; i < users.size(); i++){
        //Successfully login
        if(users[i]->get_name() == name && users[i]->get_passwd() == passwd){
            cout << "Log In Successfully" << endl;
            cout << "Welcome, " << name << endl;
            curr_user = users[i];
            found = true;
            break;
        }

        //the password is wrong
        if(users[i]->get_name() == name && users[i]->get_passwd() != passwd){
            cout << "The Password is wrong" << endl;
            return;
        }
    }

    if(!found){
        cout << "The User doesn't exist" << endl;
        return;
    }

    while(1){
        scene2();
        curr_user->show_list();
        string choice;
        cout << ">> "; cin >> choice;
        if(choice == "c"){
            curr_user->choose_list();

            if(curr_user->curr_list){
                while(1){
                    scene3();
                    curr_user->curr_list->show_song();
                    string playlist_choice;
                    cout << ">> "; cin >> playlist_choice;
                    if(playlist_choice == "a" || playlist_choice == "A") curr_user->curr_list->add_song();
                    else if(playlist_choice == "r") curr_user->curr_list->remove_song();
                    else if(playlist_choice == "p"){
                        if(curr_user->curr_list->get_song_in_list_size() == 0){
                            cout << "The list is empty." << endl;
                            continue;
                        }
                        while(1){
                            scene4();
                            curr_user->curr_list->play_song();
                            string music_choice;
                            cout << ">> "; cin >> music_choice;
                            if(music_choice == "n"){
                                curr_user->curr_list->next_song();
                            } 
                            else if(music_choice == "p"){
                                curr_user->curr_list->prev_song();
                            } 
                            else if(music_choice == "b") break;
                        }
                    } 
                    else if(playlist_choice == "b") break;
                }
            }
            else{
                cout << "List doesn't exist" << endl;
            }
        } 
        else if(choice == "a") curr_user->add_list();
        else if(choice == "o"){
            string logOUT_choice;
            logOUT(); cin >> logOUT_choice;
            if(logOUT_choice == "n") continue;
            if(logOUT_choice == "y") break;
        }
    }
}

void Spotify::logOUT(){
    cout << "Are You SUre to Log Out? (y/n) ";
}

void Spotify::printSongList(){
    cout << "12345678901234567890123456789012345" << endl;
    for(size_t i = 0; i < songs.size(); i++){
        cout << setw(15) << std::left << songs[i]->get_name() << setw(15) << std::left << songs[i]->get_artist() << songs[i]->get_song_len() << endl;
    }
}

void Spotify::printUserList(){
    for(size_t i = 0; i < users.size(); i++){
        cout << users[i]->get_name() << "\t";
    }
    cout << endl;
}

void Spotify::scene1() {
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::::'######::'########:::'#######::'########:'####:'########:'##:::'##:::::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::::::::'##... ##: ##.... ##:'##.... ##:... ##..::. ##:: ##.....::. ##:'##::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::: ##:::..:: ##:::: ##: ##:::: ##:::: ##::::: ##:: ##::::::::. ####:::::::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::::::::. ######:: ########:: ##:::: ##:::: ##::::: ##:: ######:::::. ##::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::::..... ##: ##.....::: ##:::: ##:::: ##::::: ##:: ##...::::::: ##::::::::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::::::::'##::: ##: ##:::::::: ##:::: ##:::: ##::::: ##:: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::::::::. ######:: ##::::::::. #######::::: ##::::'####: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::::......:::..::::::::::.......::::::..:::::....::..:::::::::::..:::::::::::::::::::::::::::::::" << endl;
    cout << "               __   __                                                                                                     " << endl;
    cout << "   | .   |    /  \\ / _`       | |\\ |                                                                                       " << endl;
    cout << "   | .   |___ \\__/ \\__>       | | \\|                                                                                       " << endl;
    cout << "                                                                                                                           " << endl;
    cout << "               __   __      __   __        __                  __       __   __   ___      ___  ___          __   ___  __  " << endl;
    cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                /  ` .   /  ` |__) |__   /\\   |  |__     |  | /__` |__  |__) " << endl;
    cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                \\__, .   \\__, |  \\ |___ /~~\\  |  |___    \\__/ .__/ |___ |  \\ " << endl;
    cout << "                                                                                                                           " << endl;
    cout << " __              __  ___     __   __        __   __                            __  ___          __   ___  __   __          " << endl;
    cout << "/__` .   |    | /__`  |     /__` /  \\ |\\ | / _` /__`          |  | .   |    | /__`  |     |  | /__` |__  |__) /__`         " << endl;
    cout << ".__/ .   |___ | .__/  |     .__/ \\__/ | \\| \\__> .__/          \\__/ .   |___ | .__/  |     \\__/ .__/ |___ |  \\ .__/         " << endl
         << endl;
}
void Spotify::scene2() {
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::'##::::'##::'######::'########:'########:::::'########:::::'###:::::'######:::'########:::::::::::::::::" << endl;
    cout << ":::::::::::::::::: ##:::: ##:'##... ##: ##.....:: ##.... ##:::: ##.... ##:::'## ##:::'##... ##:: ##.....::::::::::::::::::" << endl;
    cout << ":::::::::::::::::: ##:::: ##: ##:::..:: ##::::::: ##:::: ##:::: ##:::: ##::'##:. ##:: ##:::..::: ##:::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::: ##:::: ##:. ######:: ######::: ########::::: ########::'##:::. ##: ##::'####: ######:::::::::::::::::::" << endl;
    cout << ":::::::::::::::::: ##:::: ##::..... ##: ##...:::: ##.. ##:::::: ##.....::: #########: ##::: ##:: ##...::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::: ##:::: ##:'##::: ##: ##::::::: ##::. ##::::: ##:::::::: ##.... ##: ##::: ##:: ##:::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::. #######::. ######:: ########: ##:::. ##:::: ##:::::::: ##:::: ##:. ######::: ########:::::::::::::::::" << endl;
    cout << ":::::::::::::::::::.......::::......:::........::..:::::..:::::..:::::::::..:::::..:::......::::........::::::::::::::::::" << endl;
    cout << " __            __   __         __       ___                                                                               " << endl;
    cout << "/  \\ .   |    /  \\ / _`       /  \\ |  |  |                                                                                " << endl;
    cout << "\\__/ .   |___ \\__/ \\__>       \\__/ \\__/  |                                                                                " << endl;
    cout << "                                                                                                                          " << endl;
    cout << "               __   __             __  ___                                                                                " << endl;
    cout << " /\\  .    /\\  |  \\ |  \\    |    | /__`  |                                                                                 " << endl;
    cout << "/~~\\ .   /~~\\ |__/ |__/    |___ | .__/  |                                                                                 " << endl;
    cout << "                                                                                                                          " << endl;
    cout << " __       __        __   __   __   ___            __  ___                                                                 " << endl;
    cout << "/  ` .   /  ` |__| /  \\ /  \\ /__` |__     |    | /__`  |                                                                  " << endl;
    cout << "\\__, .   \\__, |  | \\__/ \\__/ .__/ |___    |___ | .__/  |                                                                  " << endl
         << endl;
}
void Spotify::scene3() {
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::'########::'##::::::::::'###::::'##:::'##:'##:::::::'####::'######::'########::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ##.... ##: ##:::::::::'## ##:::. ##:'##:: ##:::::::. ##::'##... ##:... ##..:::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ##:::: ##: ##::::::::'##:. ##:::. ####::: ##:::::::: ##:: ##:::..::::: ##:::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ########:: ##:::::::'##:::. ##:::. ##:::: ##:::::::: ##::. ######::::: ##:::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ##.....::: ##::::::: #########:::: ##:::: ##:::::::: ##:::..... ##:::: ##:::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ##:::::::: ##::::::: ##.... ##:::: ##:::: ##:::::::: ##::'##::: ##:::: ##:::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::::::: ##:::::::: ########: ##:::: ##:::: ##:::: ########:'####:. ######::::: ##:::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::..:::::::::........::..:::::..:::::..:::::........::....:::......::::::..::::::::::::::::::::::::::" << endl;
    cout << " __       __                                                   " << endl;
    cout << "|__) .   |__) |     /\\  \\ /                                    " << endl;
    cout << "|    .   |    |___ /~~\\  |                                     " << endl;
    cout << "                                                               " << endl;
    cout << "               __   __      __   __        __                  " << endl;
    cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                 " << endl;
    cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                 " << endl;
    cout << "                                                               " << endl;
    cout << " __       __   ___        __        ___     __   __        __  " << endl;
    cout << "|__) .   |__) |__   |\\/| /  \\ \\  / |__     /__` /  \\ |\\ | / _` " << endl;
    cout << "|  \\ .   |  \\ |___  |  | \\__/  \\/  |___    .__/ \\__/ | \\| \\__> " << endl;
    cout << "                                                               " << endl;
    cout << " __       __   __      __        __                            " << endl;
    cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/                      " << endl;
    cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\                      " << endl
         << endl;
}
void Spotify::scene4() {
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::'##::::'##:'##::::'##::'######::'####::'######::::'########:'####:'##::::'##:'########::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ###::'###: ##:::: ##:'##... ##:. ##::'##... ##:::... ##..::. ##:: ###::'###: ##.....:::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ####'####: ##:::: ##: ##:::..::: ##:: ##:::..::::::: ##::::: ##:: ####'####: ##::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ## ### ##: ##:::: ##:. ######::: ##:: ##:::::::::::: ##::::: ##:: ## ### ##: ######::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ##. #: ##: ##:::: ##::..... ##:: ##:: ##:::::::::::: ##::::: ##:: ##. #: ##: ##...:::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ##:.:: ##: ##:::: ##:'##::: ##:: ##:: ##::: ##:::::: ##::::: ##:: ##:.:: ##: ##::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::: ##:::: ##:. #######::. ######::'####:. ######::::::: ##::::'####: ##:::: ##: ########::::::::::::::::::" << endl;
    cout << ":::::::::::::::::::..:::::..:::.......::::......:::....:::......::::::::..:::::....::..:::::..::........:::::::::::::::::::" << endl;
    cout << "               ___     ___     __   __        __" << endl;
    cout << "|\\ | .   |\\ | |__  \\_/  |     /__` /  \\ |\\ | / _`   " << endl;
    cout << "| \\| .   | \\| |___ / \\  |     .__/ \\__/ | \\| \\__>   " << endl;
    cout << "                                                    " << endl;
    cout << " __       __   __   ___          __   __        __  " << endl;
    cout << "|__) .   |__) |__) |__  \\  /    /__` /  \\ |\\ | / _` " << endl;
    cout << "|    .   |    |  \\ |___  \\/     .__/ \\__/ | \\| \\__> " << endl;
    cout << "                                                    " << endl;
    cout << " __       __   __      __        __                 " << endl;
    cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/           " << endl;
    cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\           " << endl
         << endl;
}