#include "Playlist.h"

Playlist::Playlist(string name, const vector<const Song *> &songs):name(name), songs(songs){
    curr_song_index = 0;
}

Playlist::~Playlist(){

}

// show song in playlist (sort by song length, if equal sort by song title)
void Playlist::show_song(){
    cout << "|| SONG IN LIST ||" << endl;
    for(size_t i = 0; i < song_in_list.size(); i++){
        cout << setw(15) << std::left << song_in_list[i]->get_name() << setw(15) << std::left << song_in_list[i]->get_artist() << song_in_list[i]->get_song_len() << endl;
    }
}

// add song into playlist (song must exists in streaming device)
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

// remove song from playlist
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

// play current song
void Playlist::play_song(){
    cout << "//// SONG INFO ////" << endl;
    cout << "Name: " << song_in_list[curr_song_index]->get_name() << endl;
    cout << "Artist: " << song_in_list[curr_song_index]->get_artist() << endl;
    cout << "Length: " << song_in_list[curr_song_index]->get_song_len() << endl;
    cout << "//// SONG INFO ////" << endl;
} 

// play next song (back to first song if meet the end of playlist)
void Playlist::next_song(){
    curr_song_index = (curr_song_index + 1) % song_in_list.size();
}

// play previous song (go to last song if meet the start of playlist)
void Playlist::prev_song(){
    curr_song_index = (curr_song_index + song_in_list.size() - 1) % song_in_list.size();
}

bool list_cmp(const Playlist *p1, const Playlist *p2){
    return p1->name < p2->name;
}