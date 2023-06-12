#include "Player.h"

Player::Player(Position pos, Block*** map, int mapSizeY, int mapSizeX){
    this->pos = pos;
    this->map = map;
    this->mapSizeY = mapSizeY;
    this->mapSizeX = mapSizeX;
}

char** Player::render(){
    char **ret = new char *[8];
    for(int i = 0; i < 8; i++){
        ret[i] = new char[8];
    }

    for(int i = 0; i < 8; i++){
        if(i == 0){
            char temp[] = {' ', '+', '-', '-', '-', '-', '+', ' '};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
        else if(i == 1){
            char temp[] = {' ', '|', '+', '_', '_', '+', '|', ' '};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
        else if(i == 2){
            char temp[] = {' ', '+', '-', '-', '-', '-', '+', ' '};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
        else if(i == 3){
            char temp[] = {'|', '=', '=', '=', '=', '=', '=', '|'};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
        else if(i == 4){
            char temp[] = {'|', ' ', ' ', '=', '=', ' ', ' ', '|'};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }

        else if(i == 5){
            char temp[] = {'|', ' ', '|', '=', '=', '|', ' ', '|'};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
        else if(i == 6){
            char temp[] = {' ', ' ', '|', ' ', ' ', '|', ' ', ' '};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }

        else if(i == 7){
            char temp[] = {' ', ' ', '|', ' ', ' ', '|', ' ', ' '};
            for(int j = 0; j < 8; j++){
                ret[i][j] = temp[j];
            }
        }
    }
    return ret;
}