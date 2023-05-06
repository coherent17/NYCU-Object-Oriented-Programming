#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#define WARRIOR_HP 120
#define WARRIOR_ATTACK 30
#define WARRIOR_DEFENSE 20
#define WARRIOR_SPEED 10
#define WARRIOR_CRIT_RATE 0.2

#define WARRIOR_DEFAULT_ICON1\
    "  _  "\
    " ( ) "\
    "/-+-/"\
    " [|] "\
    " / \\ ";

#define WARRIOR_DEFAULT_ICON2\
    "  _  "\
    " ( ) "\
    "\\-+-\\"\
    " [|] "\
    " / \\ ";

#define WARRIOR_ATTACK_ICON1\
    "  _      "\
    " ( )     "\
    "/-+-----o"\
    " [|]     "\
    " / \\     ";

#define WARRIOR_ATTACK_ICON2\
    "      _  "\
    "     ( ) "\
    "o-----+-\\"\
    "     [|] "\
    "     / \\ ";

#define WARRIOR_DEFENSE_ICON1\
    "  _   "\
    " ( )  "\
    "/-+--)"\
    " [|]  "\
    " / \\  ";

#define WARRIOR_DEFENSE_ICON2\
    "   _  "\
    "  ( ) "\
    "(--+-\\"\
    "  [|] "\
    "  / \\ ";

#define WARRIOR_SHORT_ATTACK_ICON1\
    "  _    "\
    " ( )   "\
    "/-+---o"\
    " [|]   "\
    " / \\   ";

#define WARRIOR_SHORT_ATTACK_ICON2\
    "    _  "\
    "   ( ) "\
    "o---+-\\"\
    "   [|] "\
    "   / \\ ";

#include "Role.h"

class Warrior: public Role{
    private:
        float critRate;
        string DEFAULT_ICON;
        string ATTACK_ICON;
        string DEFENSE_ICON;
        string SHORT_ATTACK_ICON;

    public:
        Warrior(int);
        ~Warrior();
        void printInfo(ostream& out)const override;
        float get_critRate()override;
        string get_DEFAULT_ICON()override;
        string get_ATTACK_ICON()override;
        string get_DEFENSE_ICON()override;
        string get_SHORT_ATTACK_ICON()override;
};

#endif