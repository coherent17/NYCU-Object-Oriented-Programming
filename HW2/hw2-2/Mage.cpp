#include "Mage.h"

Mage::Mage():Role(MAGE_HP, MAGE_ATTACK, MAGE_DEFENSE, MAGE_SPEED, false), magicAttack(MAGE_MAGIC_ATTACK){

}

Mage::~Mage(){

}

void Mage::printInfo(ostream& out)const{
    cout << "Mage" << endl;
    Role::printInfo(out);
    out << "Magic Attack: " << magicAttack;
}

string Mage::get_DEFAULT_ICON1(){
    return DEFAULT_ICON1;
}

string Mage::get_DEFAULT_ICON2(){
    return DEFAULT_ICON2;
}

string Mage::get_ATTACK_ICON1(){
    return ATTACK_ICON1;
}

string Mage::get_ATTACK_ICON2(){
    return ATTACK_ICON2;
}

string Mage::get_DEFENSE_ICON1(){
    return DEFENSE_ICON1;
}

string Mage::get_DEFENSE_ICON2(){
    return DEFENSE_ICON2;
}