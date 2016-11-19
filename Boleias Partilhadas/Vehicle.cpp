#include "Vehicle.h"

using namespace std;



Vehicle::Vehicle(unsigned int noSeats, string brand, unsigned int year, char rate) : numberSeats(noSeats){
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
	vector<string> a{};
	this->route = a;
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

vector<string> Vehicle::getRoute() const{
	return route;
}

void Vehicle::setId(unsigned int id)  {
	this->idCar = id;
}

void Vehicle::setYear(unsigned int year){
	this->year = year;
}

void Vehicle::setSeats(unsigned int seats){
	this->numberSeats = seats;
}

void Vehicle::setBrand(string brand){
	this->brand = brand;
}

void Vehicle::setRate(char rate){
	this->rate = rate;
}

void Vehicle::setVehicle(Vehicle * v1){
	this->brand = v1->brand;
	this->year = v1->year;
	this->rate = v1->rate;
	this->numberSeats = v1->numberSeats;
	this->idCar = v1->idCar;
	this->idCar = v1->idCar;
}

void Vehicle::setRoute(vector<string> route) {
	this->route = route;
}

Vehicle& Vehicle::operator=(Vehicle car){
	this->brand = car.brand;
	this->idCar = car.idCar;
	this->numberSeats = car.numberSeats;
	this->rate = car.rate;
	this->route = car.route;
	this->year = car.year;
	
	return *this;
}

ofstream& operator<< (ofstream& os, const Vehicle car) {
	os << car.getCarID() << endl << car.getBrand() << endl << car.getYear() << endl <<car.getRate() << endl;

	for (size_t i = 0; i < car.getRoute().size(); i++){
		os << car.getRoute()[i] << endl;
	}

	return os;
}

ostream & operator<<(ostream & os, const Vehicle car){
	os << "Brand: " << car.getBrand() << " ";
	os << "Year: " << car.getYear() << " ";
	os << "Seats: " << car.getnumberSeats() << " ";
	os << "Rate(A-F): " << car.getRate() << endl;

	for (size_t i = 0; i < car.getRoute().size(); i++) {
		os << car.getRoute()[i] << endl;
	}

	return os;
}
