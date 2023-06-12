#include "Minecraft.h"

#include <termios.h>

#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Block.h"
#include "Dirt.h"
#include "Leaf.h"
#include "Player.h"
#include "Rock.h"
#include "Trunk.h"
#include "Position.h"
#include "Air.h"


using namespace std;

void Minecraft::buildMap(string mapFilename){
    ifstream fin(mapFilename);
    string line;
    getline(fin, line);
    stringstream ss(line);
    ss >> sizeY >> sizeX;

    Block**(*map) = new Block**[getSizeY() * getSizeX()];
    int count = 0;
    for(int y = 0; y < getSizeY(); y++){
        for(int x = 0; x < getSizeX(); x++){
            Position p = {x, y};
            char material;
            fin >> material;
            if(material == 'a'){
                Air A(p);
                map[count++] = A;
            }
            else if(material == 'd'){
                Dirt D(p);
                map[count++] = D;
            }
            else if(material == 'l'){
                Leaf L(p);
                map[count++] = L;
            }
            else if(material == 't'){
                Trunk T(p);
                map[count++] = T;
            }
            else if(material == 'r'){
                Rock R(p);
                map[count++] = R;
            }
            else{
                Air A(p);
                map[count++] = A;
            }
        }

    }
}


Minecraft::Minecraft(string mapFilename){
    buildMap(mapFilename);
}

Minecraft::~Minecraft(){

}

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
    // while (!exit) {
    //     char key;
    //     // cin >> key;
    //     key = cin.get();
    //     if (key == 27) {
    //         key = cin.get();
    //         if (key == 91) {
    //             key = cin.get();
    //             ArrowKey arrowKey;
    //             if (key == 65) {
    //                 arrowKey = ArrowKey::UP;
    //             } else if (key == 66) {
    //                 arrowKey = ArrowKey::DOWN;
    //             } else if (key == 67) {
    //                 arrowKey = ArrowKey::RIGHT;
    //             } else if (key == 68) {
    //                 arrowKey = ArrowKey::LEFT;
    //             }
    //             onArrowKeyPress(arrowKey);
    //         }
    //     } else {
    //         onNormalKeyPress(key);
    //     }
    //     render();
    // }
}