#include "Vehicle.h"

using namespace std;



Vehicle::Vehicle(unsigned int noSeats, string brand, unsigned int year, char rate) : numberSeats(noSeats){
	this->brand = brand;
	this->numberSeats = noSeats;
	this->year = year;
	this->idCar = 0;
	this->rate = rate;
	this->active = false;
}

Vehicle::Vehicle() {
	this->brand = "nobrand";
	this->numberSeats = 0;
	this->year = 0;
	this->idCar = 0;
	this->rate = 0;
	this->active = false;
}

void Vehicle::setId(unsigned int id)  {
	this->idCar = id;
}

Vehicle& Vehicle::operator=(Vehicle car)
{
	this->active = car.active;
	this->brand = car.brand;
	this->idCar = car.idCar;
	this->numberSeats = car.numberSeats;
	this->rate = car.rate;
	this->rota = car.rota;
	this->year = car.year;
	
	return *this;
}

