#ifndef _MAGE_H_
#define _MAGE_H_

#define MAGE_DEFAULT_ICON1\
    " ^_^ "\
    " ( ) "\
    "/-+-/"\
    "  |  "\
    " / \\ "

#define MAGE_DEFAULT_ICON2\
    " ^_^ "\
    " ( ) "\
    "\\-+-\\"\
    "  |  "\
    " / \\ "

#define MAGE_ATTACK_ICON1\
    " ^_^     "\
    " ( )     "\
    "/-+-----o"\
    "  |      "\
    " / \\     "

#define MAGE_ATTACK_ICON2\
    "     ^_^ "\
    "     ( ) "\
    "o-----+-\\"\
    "      |  "\
    "     / \\ "

#define MAGE_DEFENSE_ICON1\
    " ^_^  "\
    " ( )  "\
    "/-+--)"\
    "  |   "\
    " / \\  "

#define MAGE_DEFENSE_ICON2\
    "  ^_^ "\
    "  ( ) "\
    "(--+-\\"\
    "   |  "\
    "  / \\ "

#define MAGE_SHORT_ATTACK_ICON1\
    " ^_^   "\
    " ( )   "\
    "/-+---o"\
    "  |    "\
    " / \\   "

#define MAGE_SHORT_ATTACK_ICON2\
    "   ^_^ "\
    "   ( ) "\
    "o---+-\\"\
    "    |  "\
    "   / \\ "

#include "Role.h"

class Mage: public Role{
    private:
        int magicAttack;
        string DEFAULT_ICON;
        string ATTACK_ICON;
        string DEFENSE_ICON;
        string SHORT_ATTACK_ICON;

    public:
        Mage(int playerID, int hp, int attack, int defense, int speed, int magicAttack);
        ~Mage();
        int get_magicAttack()override;
        string get_DEFAULT_ICON()override;
        string get_ATTACK_ICON()override;
        string get_DEFENSE_ICON()override;
        string get_SHORT_ATTACK_ICON()override;
};

#endif