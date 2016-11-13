#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <vector>

using namespace std;

class Vehicle {
	unsigned int numberSeats;
	string brand; //vehicle type, only for showing purposes 
	unsigned int year; //user might not choose this vehicle for this
	char rate;  //optional. grade from A to F based on vehicle condition
	unsigned int idCar; //same as user ID
	vector<string> rota;
	
public:
	Vehicle(unsigned int noSeats, string brand, unsigned int year,char rate);
	Vehicle();

	unsigned int getnumberSeats() const;
	string getBrand() const;
	unsigned int getYear() const;
	char getRate() const;
	unsigned int getCarID() const;
	vector<string> getRota() const;


	void setId(unsigned int id);

	Vehicle& operator=(Vehicle car);

};

#endif /* VEHICLE_H_ */
