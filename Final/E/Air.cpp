#include "Air.h"

Air::Air(Position pos):Block(pos){
    hardness = 2;
}

Air::~Air(){
    ;
}

char** Air::render(){
    char **ret = new char *[4];
    for(int i = 0; i < 4; i++){
        ret[i] = new char[8];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            ret[i][j] = ' ';
        }
    }
    return ret;
}