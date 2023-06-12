#include "Minecraft.h"

#include <termios.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include "Block.h"
#include "Dirt.h"
#include "Leaf.h"
#include "Player.h"
#include "Rock.h"
#include "Trunk.h"


using namespace std;


void Minecraft::render() {
    system("clear");
    //TODO: render the map
}



void Minecraft::run() {
    struct termios ter;
    tcgetattr(0, &ter);
    ter.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &ter);

    render();
    while (!exit) {
        char key;
        // cin >> key;
        key = cin.get();
        if (key == 27) {
            key = cin.get();
            if (key == 91) {
                key = cin.get();
                ArrowKey arrowKey;
                if (key == 65) {
                    arrowKey = ArrowKey::UP;
                } else if (key == 66) {
                    arrowKey = ArrowKey::DOWN;
                } else if (key == 67) {
                    arrowKey = ArrowKey::RIGHT;
                } else if (key == 68) {
                    arrowKey = ArrowKey::LEFT;
                }
                onArrowKeyPress(arrowKey);
            }
        } else {
            onNormalKeyPress(key);
        }
        render();
    }
}