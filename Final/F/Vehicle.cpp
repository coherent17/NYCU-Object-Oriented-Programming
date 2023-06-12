#include "Vehicle.h"
#include "Customer.h"

Vehicle::Vehicle(string brand, string model, double price, int seats, string transmission_type){
    this->brand = brand;
    this->model = model;
    this->price = price;
    this->seats = seats;
    this->transmission_type = transmission_type;
}

double Vehicle::calculate_rental_price(int days, Customer *customer){

}

double Vehicle::calculate_penalty_fee(int days, Customer *customer){

}