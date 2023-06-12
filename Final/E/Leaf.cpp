#include "Leaf.h"

Leaf::Leaf(Position pos):Block(pos){
    hardness = 1;
}
Leaf::~Leaf(){

}

char** Leaf::render(){
    char **ret = new char *[4];
    for(int i = 0; i < 4; i++){
        ret[i] = new char[8];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            ret[i][j] = '#';
        }
    }
    return ret;
}