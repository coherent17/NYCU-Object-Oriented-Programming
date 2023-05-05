#include "Playlist.h"
#include "Song.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
Playlist::Playlist(string name, const vector<const Song *> &songs): songs(songs){
    this->name = name;
    curr_song_index = 0;
}

Playlist::~Playlist(){

}

string Playlist::get_name()const{
    return name;
}

void Playlist::show_song(){
    cout << "|| SONG IN LIST ||" << endl;
    for(size_t i = 0; i < song_in_list.size(); i++){
        cout << setw(15) << std::left << song_in_list[i]->get_name() << setw(15) << std::left << song_in_list[i]->get_artist() << song_in_list[i]->get_song_len() << endl;
    }
}

void Playlist::add_song(){
    cout << "ADD SONG" << endl;
    string name;
    cout << "Song Name: "; cin >> name;
    
    for(size_t i = 0; i < songs.size(); i++){
        if(name == songs[i]->get_name()){
            song_in_list.push_back(songs[i]);
            sort(song_in_list.begin(), song_in_list.end(), song_cmp);
            return;
        }
    }
    cout << "Doesn't find the song." << endl;
}

void Playlist::remove_song(){
    cout << "REMOVE SONG" << endl;
    string name;
    cout << "Song Name: "; cin >> name;
    for(size_t i = 0; i < song_in_list.size(); i++){
        if(song_in_list[i]->get_name() == name){
            song_in_list.erase(song_in_list.begin() + i);
            return;
        }
    }
    cout << "Doesn't find the song." << endl;
}

void Playlist::play_song(){
    cout << "//// SONG INFO ////" << endl;
    cout << "Name: " << song_in_list[curr_song_index]->get_name() << endl;
    cout << "Artist: " << song_in_list[curr_song_index]->get_artist() << endl;
    cout << "Length: " << song_in_list[curr_song_index]->get_song_len() << endl;
    cout << "//// SONG INFO ////" << endl;
}

void Playlist::next_song(){
    curr_song_index = (curr_song_index + 1) % song_in_list.size();
}

void Playlist::prev_song(){
    curr_song_index = (curr_song_index + song_in_list.size() - 1) % song_in_list.size();
}

size_t Playlist::get_song_in_list_size()const{
    return song_in_list.size();
}