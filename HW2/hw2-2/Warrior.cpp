#include "Warrior.h"

Warrior::Warrior(int playerID, int hp, int attack, int defense, int speed, float critRate):Role(hp, attack, defense, speed, false), critRate(critRate){
    if(playerID == 1){
        DEFAULT_ICON = WARRIOR_DEFAULT_ICON1;
        ATTACK_ICON = WARRIOR_ATTACK_ICON1;
        DEFENSE_ICON = WARRIOR_DEFENSE_ICON1;
        SHORT_ATTACK_ICON = WARRIOR_SHORT_ATTACK_ICON1;
    }
    else{
        DEFAULT_ICON = WARRIOR_DEFAULT_ICON2;
        ATTACK_ICON = WARRIOR_ATTACK_ICON2;
        DEFENSE_ICON = WARRIOR_DEFENSE_ICON2;
        SHORT_ATTACK_ICON = WARRIOR_SHORT_ATTACK_ICON2;
    }
}

Warrior::~Warrior(){

}

float Warrior::get_critRate(){
    return critRate;
}

string Warrior::get_DEFAULT_ICON(){
    return DEFAULT_ICON;
}

string Warrior::get_ATTACK_ICON(){
    return ATTACK_ICON;
}

string Warrior::get_DEFENSE_ICON(){
    return DEFENSE_ICON;
}

string Warrior::get_SHORT_ATTACK_ICON(){
    return SHORT_ATTACK_ICON;
}