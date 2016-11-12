#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

class Vehicle {
	const int numberSeats;
	string brand; //vehicle type, only for showing purposes 
	unsigned int year; //user might not choose this vehicle for this
	char rate;  //optional. grade from A to F based on vehicle condition
	vector<string>& rota;
	const unsigned int id;
	bool active;

public:
	Vehicle();

};

#endif /* VEHICLE_H_ */
