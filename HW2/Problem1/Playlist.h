#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>
using namespace std;
// Add any Boolean Function for sorting you need

class Playlist {
    private:
        string name;                        // name of playlist
        int curr_song_index;                // record  current playing song, points to 1st song at first.
        vector<const Song *> song_in_list;  // store the songs in list
        const vector<const Song *> songs;   // store the songs provided in streaming service (can't modified)

        void show_song();    // show song in playlist (sort by song length)
        void add_song();     // add song into playlist (song must exists in streaming device)
        void remove_song();  // remove song from playlist
        void play_song();    // play current song
        void next_song();    // play next song (back to first song if meet the end of playlist)
        void prev_song();    // play previous song (go to last song if meet the start of playlist)

    public:
        Playlist(string name, const vector<const Song *> &songs);
        ~Playlist();
        string get_name()const;
        size_t get_song_in_list_size()const;
        friend class Spotify;
        // Add any Accessor & Mutator functions, or friend class declaration you need
};

#endif