#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <vector>
#include <fstream>

#undef max // because of numeric_limits

using namespace std;

class Vehicle {
	unsigned int numberSeats;
	string brand; //vehicle type, only for showing purposes 
	unsigned int year; //user might not choose this vehicle for this
	string rate;  //optional. grade from A to F based on vehicle condition
	unsigned int idCar; //same as user ID
	static unsigned int carstatic;
	vector<string> route;
	
public:
	Vehicle(unsigned int noSeats, string brand, unsigned int year,string rate);
	Vehicle();

	//get functions
	unsigned int getnumberSeats() const;
	string getBrand() const;
	unsigned int getYear() const;
	string getRate() const;
	unsigned int getID() const;
	vector<string> getRoute() const;
	
	//set functions
	void setRoute(vector<string> route);
	void setId(unsigned int id);
	void setYear(unsigned int year);
	void setSeats(unsigned int seats);
	void setBrand(string brand);
	void setRate(string rate);
	void setVehicle(Vehicle* v1);

	Vehicle& operator=(Vehicle car);

	friend ofstream& operator<<(ofstream& os, const Vehicle car); // for now, only for writing in file of users purpose
	friend ostream& operator<<(ostream& os, const Vehicle car);
	void save(ofstream& out) const;
};

#endif /* VEHICLE_H_ */
