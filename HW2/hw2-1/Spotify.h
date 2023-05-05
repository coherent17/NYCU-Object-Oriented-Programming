#ifndef SPOTIFY_H
#define SPOTIFY_H
#include <fstream>
#include <vector>
#include <algorithm>
#include "User.h"

using namespace std;
// Add any Boolean Function for sorting you need

class Spotify {
    private:
        User *curr_user;             // points to the current user, NULL at first
        vector<User *> users;        // store all users information
        vector<const Song *> songs;  // store the songs provided in streaming service

        void scene1();
        void scene2();
        void scene3();
        void scene4();
        void addSong();        // add new song into songs
        void createUser();     // create new user
        void logIN();          // log in to specific user
        void logOUT();         // log out from current user
        void printSongList();  // list all songs in device (sort by song length, if equal sort by song title)
        void printUserList();  // list all users in device (sort by creation order)

    public:
        Spotify(string file);
        ~Spotify();
        void controlManual();  // controller of the whole device
};

#endif