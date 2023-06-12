#include "Trunk.h"

Trunk::Trunk(Position pos):Block(pos){
    hardness = 4;
}

Trunk::~Trunk(){
    ;
}

char** Trunk::render(){
    char **ret = new char *[4];
    for(int i = 0; i < 4; i++){
        ret[i] = new char[8];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            ret[i][j] = '|';
        }
    }
    return ret;
}