#ifndef __P1_H_
#define __P1_H_

#include <iostream>
#include <cstring>
using namespace std;

class CProperty {
	private:
		char* owner;
		int price;
	public:
		CProperty();
		CProperty(const char *owner);
		virtual ~CProperty();
		virtual int computePrice()const = 0;
		char *get_owner()const;
		int get_price()const;
		void set_price(int price);

};

class CCar: virtual public CProperty{ //public inherit CProperty 
	private:
		int capacity;
		int distance;
	public:
		CCar(const char *owner, int capacity, int distance);
		~CCar();
		int get_capacity()const;
		int get_distance()const;
		int computePrice()const;
		friend ostream& operator<<(ostream& out, CCar& C);

};

class CHome: virtual public CProperty{ //public inherit CProperty
	private:
		int floor;
		int area;
	public:
		CHome(const char *owner, int floor, int area);
		~CHome();
		int get_floor()const;
		int get_area()const;
		int computePrice()const;
		friend ostream& operator<<(ostream& out, CHome& C);
};

class CHomeCar: public CCar, public CHome{ //public inherit CCar and CHome
	private:
    	int seat;
	public:
		CHomeCar(const char* owner, int capacity, int distance, int floor, int area, int seat);
		~CHomeCar();
		int get_seat()const;
		int computePrice()const;
		friend ostream& operator<<(ostream& out, CHomeCar& C);
};
#endif 
