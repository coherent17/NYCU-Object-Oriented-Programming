//main program
#include <iostream>
#include "AirTicket.h"
using namespace std;

int main(int argc, char ** argv) {
    //declare a stack variable
    AirTicket tkt1; 
    //initialize and compute price
    tkt1.setName("Peter Woods");
    tkt1.setMiles(25000);
    cout << tkt1.getName() << "pays" 
         << tkt1.calculatePrice() << endl;    
    //declare a heap variable
    AirTicket * tkt2 = new AirTicket;
    //initialize and compute price
    tkt2->setName("Laura Clinton");
    tkt2->setMiles(3000);
    cout << tkt2->getName() << " pays" 
         << tkt2->calculatePrice() << endl;
    //delete the variable when done
    delete tkt2;

    return 0;
}
