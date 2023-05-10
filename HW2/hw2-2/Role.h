#ifndef _ROLE_H_
#define _ROLE_H_

#include <iostream>
#include <string>
using namespace std;

class Role{
    private:
        int hp;
        int attack;
        int defense;
        int speed;
        bool isDenfense;

    public:
        Role();
        Role(int _hp, int _attack, int _defense, int _speed, bool _isDenfense);
        virtual ~Role();

        int get_hp()const;
        int get_attack()const;
        int get_defense()const;
        int get_speed()const;
        bool get_isDenfense()const;

        void set_hp(int);
        void set_isDenfense(bool);

        virtual string get_DEFAULT_ICON() = 0;
        virtual string get_ATTACK_ICON() = 0;
        virtual string get_DEFENSE_ICON() = 0;
        virtual string get_SHORT_ATTACK_ICON() = 0;
        virtual int get_magicAttack();
        virtual float get_critRate();
        virtual float get_lifeSteal();
        virtual int get_maxHP();
        friend ostream& operator<<(ostream& out, const Role& R);
};

#endif