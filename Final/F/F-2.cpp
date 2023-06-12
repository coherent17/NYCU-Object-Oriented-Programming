#ifndef VEHICLE_H
#define VEHICLE_H
#include "Vehicle.h"
#endif
#ifndef CAR_H
#define CAR_H
#include "Car.h"
#endif
#ifndef VAN_H
#define VAN_H
#include "Van.h"
#endif
#ifndef SUV_H
#define SUV_H
#include "SUV.h"
#endif
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Customer.h"
#endif
#ifndef RENTAL_CONTRACT_H
#define RENTAL_CONTRACT_H
#include "RentalContract.h"
#endif
#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H
#include "RentalSystem.h"
#endif

#include <iostream>
#include <string>
using namespace std;

string curr_date = "06_28";
int main() {
    RentalSystem Sys;

    // ---- Vehicles ----
    Sys.add_vehicle(new Car("Toyota", "ALTIS", 3200, "Auto"));
    Sys.add_vehicle(new Car("Honda", "FIT", 2930, "Manual"));
    Sys.add_vehicle(new Car("Toyota", "ALTIS", 3200, "Auto"));
    Sys.add_vehicle(new SUV("Luxgen", "M7", 4600, "Auto"));
    Sys.add_vehicle(new Car("Ford", "KUGA", 3000, "Manual"));
    Sys.add_vehicle(new Van("Ford", "Tourneo", 5200, "Auto"));
    Sys.add_vehicle(new Van("Toyota", "GRANVIA", 7600, "Auto"));
    Sys.add_vehicle(new SUV("Toyota", "SIENTA", 3900, "Manual"));
    Sys.add_vehicle(new SUV("Toyota", "RAV4", 4200, "Auto"));
    // ---- Vehicles ----

    // ---- Customers ----
    Sys.add_customer(new Customer("Tom", "511070", 100));
    Sys.add_customer(new Customer("Jack", "511238", 1000));
    Sys.add_customer(new Customer("Benson", "511699"));
    Sys.get_customer(0)->set_bonus_point(3);  // get_customer(i): get customers[i] value, set_bonus_point(i): set bonus_point to i
    Sys.get_customer(1)->set_bonus_point(8);
    Sys.get_customer(2)->set_bonus_point(10);
    // ---- Customers ----
    Sys.add_account_value("Tom", "511070", 20000);
    Sys.generate_report();
    cout << endl;

    // trade list in 06/28
    cout << "Trade in 06/28" << endl;
    Sys.rent_car("Tom", "511070", Sys.get_vehicle(1), curr_date, "07_01");
    Sys.rent_car("Benson", "511699", Sys.get_vehicle(6), curr_date, "06_29", 20000);
    Sys.generate_report();
    cout << endl;

    // trade list in 06/30
    cout << "Trade in 06/30" << endl;
    curr_date = "06_30";
    Sys.return_car("Benson", "511699", curr_date);
    Sys.rent_car("Jack", "511238", Sys.get_vehicle(5), curr_date, "07_02", 30000);
    Sys.generate_report();
    cout << endl;

    // trade list in 07/01
    cout << "Trade in 07/01" << endl;
    curr_date = "07_01";
    Sys.return_car("Tom", "511070", curr_date);
    Sys.rent_car("Mark", "510123", Sys.get_vehicle(6), curr_date, "07_02", 18000);
    Sys.generate_report();
    cout << endl;

    // trade list in 07/03
    cout << "Trade in 07/03" << endl;
    curr_date = "07_03";
    Sys.return_car("Jack", "511238", curr_date);
    Sys.return_car("Mark", "510123", curr_date);
    Sys.generate_report();
    cout << endl;
    return 0;
}