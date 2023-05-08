#include <iostream>
#include "TV.h"
#include "Phone.h"

using namespace std;

int main()
{
    Electronics* E1;
    Electronics* E2;
    E1 = new TV(5, 10);
    E2 = new Phone(50, 40, 4, 3);
    
    E1->run();
    E2->run(); 

    E1->poweron();
    E1->run();

    E1->charge();
    E1->run();

    E1->poweron();
    E1->run();

    E1->charge();
    E1->run();

    E2->poweron();
    E2->run();

    E2->charge();
    E2->run();

    E2->run();

    E2->poweron();
    E2->run();

    E2->charge();
    E2->run();

    E2->run();

    E2->run();

    E2->charge();
    E2->poweron();
    E2->run();
    
    E2->poweroff();
    E2->run();

    return 0;
}