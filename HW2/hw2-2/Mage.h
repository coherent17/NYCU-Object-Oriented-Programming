#ifndef _MAGE_H_
#define _MAGE_H_

#define MAGE_HP 100
#define MAGE_ATTACK 10
#define MAGE_DEFENSE 10
#define MAGE_SPEED 5
#define MAGE_MAGIC_ATTACK 30

#include "Role.h"

class Mage: public Role{
    private:
        int magicAttack;

        string DEFAULT_ICON1 =  " ^_^ "\
                                " ( ) "\
                                "/-+-/"\
                                "  |  "\
                                " / \\ ";
        
        string DEFAULT_ICON2 =  " ^_^ "\
                                " ( ) "\
                                "\\-+-\\"\
                                "  |  "\
                                " / \\ ";

        string ATTACK_ICON1 =   " ^_^     "\
                                " ( )     "\
                                "/-+-----o"\
                                "  |      "\
                                " / \\     ";
        
        string ATTACK_ICON2 =   "     ^_^ "\
                                "     ( ) "\
                                "o-----+-\\"\
                                "      |  "\
                                "     / \\ ";

        string DEFENSE_ICON1 =  " ^_^  "\
                                " ( )  "\
                                "/-+--)"\
                                "  |   "\
                                " / \\  ";

        string DEFENSE_ICON2 =  "  ^_^ "\
                                "  ( ) "\
                                "(--+-\\"\
                                "   |  "\
                                "  / \\ ";

    public:
        Mage();
        ~Mage();
        void printInfo(ostream& out)const override;
        string get_DEFAULT_ICON1()override;
        string get_DEFAULT_ICON2()override;
        string get_ATTACK_ICON1()override;
        string get_ATTACK_ICON2()override;
        string get_DEFENSE_ICON1()override;
        string get_DEFENSE_ICON2()override;
};

#endif