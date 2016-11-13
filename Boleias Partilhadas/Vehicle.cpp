#include "Vehicle.h"

using namespace std;



Vehicle::Vehicle(unsigned int id, unsigned int noSeats, string brand, unsigned int year, char rate){
	this->brand = brand;
	this->numberSeats = noSeats;
	this->year = year;
	this->idCar = 0;
	this->rate = rate;
}

Vehicle::Vehicle() {
	this->brand = "nobrand";
	this->numberSeats = 0;
	this->year = 0;
	this->idCar = 0;
	this->rate = 0;
}

unsigned int Vehicle::getnumberSeats() const{
	return numberSeats;
}

string Vehicle::getBrand() const{
	return brand;
}

unsigned int Vehicle::getYear() const{
	return year;
}

char Vehicle::getRate() const{
	return rate;
}

unsigned int Vehicle::getCarID() const{
	return idCar;
}

vector<string> Vehicle::getRota() const{
	return rota;
}

void Vehicle::setId(unsigned int id)  {
	this->idCar = id;
}

Vehicle& Vehicle::operator=(Vehicle car){
	this->brand = car.brand;
	this->idCar = car.idCar;
	this->numberSeats = car.numberSeats;
	this->rate = car.rate;
	this->rota = car.rota;
	this->year = car.year;
	
	return *this;
}

