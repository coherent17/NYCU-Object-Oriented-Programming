#include "Spotify.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in_file = argv[1];
    Spotify s(in_file);

    s.controlManual();

    return 0;
}