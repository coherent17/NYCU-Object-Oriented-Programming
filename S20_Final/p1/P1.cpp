#include "P1.h"

//start Cproperty
CProperty::CProperty(){
	owner = nullptr;
	price = 0;
}

CProperty::CProperty(const char *owner){
	this->owner = new char[strlen(owner)];
	for(size_t i = 0; i < strlen(owner); i++){
		this->owner[i] = owner[i];
	}
	price = 0;
}

CProperty::~CProperty(){
	if(owner){
		delete [] owner;
		owner = nullptr;
	} 
}

char *CProperty::get_owner()const{
	return owner;
}

int CProperty::get_price()const{
	return price;
}

void CProperty::set_price(int price){
	this->price = price;
}
//end Cproperty


//start CCar
CCar::CCar(const char *owner = "", int capacity = 0, int distance = 0):CProperty(owner){
	this->capacity = capacity;
	this->distance = distance;
	set_price(capacity * 1000);
}

CCar::~CCar(){
	;
}

int CCar::get_capacity()const{
	return capacity;
}

int CCar::get_distance()const{
	return distance;
}

int CCar::computePrice()const{
	return get_price();
}

ostream& operator<<(ostream& out, CCar& C){
	out << C.get_owner() << "'s car runs " << C.distance << "Km and costs $" << C.get_price()/1000000.0 << "M." << endl;
	return out;
}
//end CCar


//start CHome
CHome::CHome(const char *owner = "", int floor = 0, int area = 0) : CProperty(owner){
	this->floor = floor;
	this->area = area;
	set_price(floor * 100000 * area);
}

CHome::~CHome(){
	;
}

int CHome::get_floor()const{
	return floor;
}

int CHome::get_area()const{
	return area;
}

int CHome::computePrice()const{
	return get_price();
}

ostream& operator<<(ostream& out, CHome& C){
	out << C.get_owner() << "'s home has " << C.floor << " floor(s) and costs $" << C.get_price()/1000000.0 << "M." << endl;
	return out;
}
//end CHome


//start CHomeCar
CHomeCar::CHomeCar(const char* owner = "", int capacity = 0, int distance = 0, int floor = 0, int area = 0, int seat = 0) : CProperty(owner), CCar(owner, capacity, distance), CHome(owner, floor, area){
	this->seat = seat;
	set_price(seat * 50000 + area * 80000 + capacity * 2000);
}

CHomeCar::~CHomeCar(){
	;
}

int CHomeCar::get_seat()const{
	return seat;
}

int CHomeCar::computePrice()const{
	return get_price();
}

ostream& operator<<(ostream& out, CHomeCar& C){
	out << C.get_owner() << endl;
	out << C.get_owner() << "'s homecar has " << C.get_seat()<<" seat(s), "<<C.get_floor()<<" floor(s), "<<C.get_capacity()<<" c.c.,"<<C.get_area()<<" sqft, runs "<<C.get_distance()<<" Km and costs $"<<C.get_price()/1000000.0<<"M"<<endl;
	return out;
}
//end CHomeCar