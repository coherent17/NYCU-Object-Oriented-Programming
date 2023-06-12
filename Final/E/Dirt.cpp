#include "Dirt.h"

Dirt::Dirt(Position pos):Block(pos){
    hardness = 2;
}

Dirt::~Dirt(){
    ;
}

char** Dirt::render(){
    char **ret = new char *[4];
    for(int i = 0; i < 4; i++){
        ret[i] = new char[8];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            if(i == 0){
                ret[i][j] = '#';
            }
            else{
                ret[i][j] = '@';
            }
        }
    }
    return ret;
}