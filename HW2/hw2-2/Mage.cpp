#include "Mage.h"

Mage::Mage(int playerID, int hp, int attack, int defense, int speed, int magicAttack):Role(hp, attack, defense, speed, false), magicAttack(magicAttack){
    if(playerID == 1){
        DEFAULT_ICON = MAGE_DEFAULT_ICON1;
        ATTACK_ICON = MAGE_ATTACK_ICON1;
        DEFENSE_ICON = MAGE_DEFENSE_ICON1;
        SHORT_ATTACK_ICON = MAGE_SHORT_ATTACK_ICON1;
    }
    else{
        DEFAULT_ICON = MAGE_DEFAULT_ICON2;
        ATTACK_ICON = MAGE_ATTACK_ICON2;
        DEFENSE_ICON = MAGE_DEFENSE_ICON2;
        SHORT_ATTACK_ICON = MAGE_SHORT_ATTACK_ICON2;
    }
}

Mage::~Mage(){

}

int Mage::get_magicAttack(){
    return magicAttack;
}

string Mage::get_DEFAULT_ICON(){
    return DEFAULT_ICON;
}

string Mage::get_ATTACK_ICON(){
    return ATTACK_ICON;
}

string Mage::get_DEFENSE_ICON(){
    return DEFENSE_ICON;
}

string Mage::get_SHORT_ATTACK_ICON(){
    return SHORT_ATTACK_ICON;
}