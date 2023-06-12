#include "RentalSystem.h"
#include "RentalContract.h"

RentalSystem::RentalSystem(){

}

RentalSystem::~RentalSystem(){
    for(size_t i = 0; i < customers.size(); i++){
        delete customers[i];
    }
    for(size_t i = 0; i < vehicles.size(); i++){
        delete vehicless[i];
    }
}

void RentalSystem::add_customer(Customer* x){
    customers.push_back(x);
}

void RentalSystem::add_vehicle(Vehicle* x){
    vehicles.push_back(x);
}

void RentalSystem::add_account_value(string name, string liscense_number, double amount){
    
}

void RentalSystem::rent_car(string name, string liscense_number, Vehicle*, string start_date, string end_date, double deposit = 0.0){

}

void RentalSystem::return_car(string name, string liscense_number, string return_date){

}

void RentalSystem::generate_report(){

}