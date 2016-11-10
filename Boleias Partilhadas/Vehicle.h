#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include<string>

class Vehicle {
	int avaiableSeats;
	string type; //vehicle type, only for showing purposes 
	unsigned int year; //user might not choose this vehicle for this
	char rate;  //optional. grade from A to F based on vehicle condition
	vector<string>& rota;
};

#endif /* VEHICLE_H_ */
