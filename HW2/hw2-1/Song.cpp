#include "Song.h"

Song::Song(string name, string artist, string song_len):name(name), artist(artist), song_len(song_len){

}

Song::~Song(){

}

string Song::get_name()const{
    return name;
}

string Song::get_artist()const{
    return artist;
}

string Song::get_song_len()const{
    return song_len;
}

bool song_cmp(const Song *s1, const Song *s2){
    int min1 = stoi(s1->song_len.substr(0, s1->song_len.find(":")));
    int sec1 = stoi(s1->song_len.substr(s1->song_len.find(":") + 1));
    int min2 = stoi(s2->song_len.substr(0, s2->song_len.find(":")));
    int sec2 = stoi(s2->song_len.substr(s2->song_len.find(":") + 1));
    int total1 = min1 * 60 + sec1;
    int total2 = min2 * 60 + sec2;
    return (total1 == total2) ? s1->name < s2->name : total1 < total2;
}