#include "Customer.h"

Customer::Customer(string name, string license_number, double account_balance = 0.0){
    this->name = name;
    this->license_number = license_number;
    this->account_balance = account_balance;
}

Customer::~Customer(){

}

void Customer::rent_vehicle(Vehicle* vehicle, int rental_duration){

}

void Customer::return_vehicle(Vehicle* vehicle, int late_day){

}

void Customer::add_value(double deposit){

}