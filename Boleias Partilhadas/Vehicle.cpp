#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int noSeats, string brand, unsigned int year) : numberSeats(noSeats){
	this->brand = brand;
	this->year = year;
}
