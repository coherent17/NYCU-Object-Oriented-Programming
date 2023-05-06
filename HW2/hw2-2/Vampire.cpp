#include "Vampire.h"

Vampire::Vampire(int playerID):Role(VAMPIRE_HP, VAMPIRE_ATTACK, VAMPIRE_DEFENSE, VAMPIRE_SPEED, false), lifeSteal(VAMPIRE_LIFESTEAL){
    if(playerID == 1){
        DEFAULT_ICON = VAMPIRE_DEFAULT_ICON1;
        ATTACK_ICON = VAMPIRE_ATTACK_ICON1;
        DEFENSE_ICON = VAMPIRE_DEFENSE_ICON1;
        SHORT_ATTACK_ICON = VAMPIRE_SHORT_ATTACK_ICON1;
    }
    else{
        DEFAULT_ICON = VAMPIRE_DEFAULT_ICON2;
        ATTACK_ICON = VAMPIRE_ATTACK_ICON2;
        DEFENSE_ICON = VAMPIRE_DEFENSE_ICON2;
        SHORT_ATTACK_ICON = VAMPIRE_SHORT_ATTACK_ICON2;
    }
}

Vampire::~Vampire(){

}

void Vampire::printInfo(ostream& out)const{
    cout << "Vampire" << endl;
    Role::printInfo(out);
    out << "Life Steal: " << lifeSteal;
}

float Vampire::get_lifeSteal(){
    return lifeSteal;
}

string Vampire::get_DEFAULT_ICON(){
    return DEFAULT_ICON;
}

string Vampire::get_ATTACK_ICON(){
    return ATTACK_ICON;
}

string Vampire::get_DEFENSE_ICON(){
    return DEFENSE_ICON;
}

string Vampire::get_SHORT_ATTACK_ICON(){
    return SHORT_ATTACK_ICON;
}