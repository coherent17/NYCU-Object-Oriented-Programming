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

string curr_date = "06_05";
int main() {
    RentalSystem Sys;

    // ---- Vehicles ----
    Sys.add_vehicle(new Car("Toyota", "ALTIS", 3200, "Auto"));
    Sys.add_vehicle(new Van("Ford", "Tourneo", 5200, "Auto"));
    Sys.add_vehicle(new Car("Honda", "FIT", 2930, "Manual"));
    Sys.add_vehicle(new SUV("Toyota", "RAV4", 4200, "Auto"));
    // ---- Vehicles ----

    // ---- Customers ----
    Sys.add_customer(new Customer("Tom", "511070", 100));
    Sys.add_customer(new Customer("Jack", "511238", 1000));
    Sys.add_customer(new Customer("Benson", "511699"));
    // ---- Customers ----
    Sys.add_account_value("Tom", "511070", 10000);
    Sys.generate_report();
    cout << endl;

    // trade list in 06/05
    cout << "Trade in 06/05" << endl;
    Sys.rent_car("Tom", "511070", Sys.get_vehicle(0), curr_date, "06_06");          // get_vehicle(0): get vehicles[0] value
    Sys.rent_car("Mark", "510123", Sys.get_vehicle(3), curr_date, "06_07", 20000);  // get_vehicle(3): get vehicles[3] value
    Sys.generate_report();
    cout << endl;

    // trade list in 06/07
    cout << "Trade in 06/07" << endl;
    curr_date = "06_07";
    Sys.return_car("Mark", "510123", curr_date);
    Sys.generate_report();
    cout << endl;

    // trade list in 06/08
    cout << "Trade in 06/08" << endl;
    curr_date = "06_08";
    Sys.return_car("Tom", "511070", curr_date);
    Sys.generate_report();
    cout << endl;
    return 0;
}