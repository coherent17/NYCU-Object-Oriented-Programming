#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
    private:
        string name;      // title of song
        string artist;    // artist of song
        string song_len;  // length of song

    public:
        Song(string name, string artist, string song_len);
        ~Song();
        string get_name()const;
        string get_artist()const;
        string get_song_len()const;
        friend bool song_cmp(const Song *s1, const Song *s2);
};

bool song_cmp(const Song *s1, const Song *s2);

#endif