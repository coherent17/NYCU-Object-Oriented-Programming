#include "Role.h"

Role::Role():hp(0), attack(0), defense(0), speed(0), isDenfense(false){

}

Role::Role(int _hp, int _attack, int _defense, int _speed, bool _isDenfense): hp(_hp), attack(_attack), defense(_defense), speed(_speed), isDenfense(false){

}

Role::~Role(){

}

int Role::get_hp()const{
    return hp;
}

int Role::get_attack()const{
    return attack;
}

int Role::get_defense()const{
    return defense;
}

int Role::get_speed()const{
    return speed;
}

bool Role::get_isDenfense()const{
    return isDenfense;
}

void Role::printInfo(ostream& out)const{
    out << "HP: " << hp << endl;
    out << "Attack: " << attack << endl;
    out << "Defense: " << defense << endl;
    out << "Speed: " << speed << endl;
}

ostream& operator<<(ostream& out, const Role& R){
    R.printInfo(out);
    out << endl;
    return out;
}

string Role::get_DEFAULT_ICON1(){
    return "";
}

string Role::get_DEFAULT_ICON2(){
    return "";
}

string Role::get_ATTACK_ICON1(){
    return "";
}

string Role::get_ATTACK_ICON2(){
    return "";
}

string Role::get_DEFENSE_ICON1(){
    return "";
}

string Role::get_DEFENSE_ICON2(){
    return "";
}