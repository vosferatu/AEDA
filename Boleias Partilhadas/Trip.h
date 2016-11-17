#pragma once
#ifndef TRIP_H_
#define TRIP_H_

#include "User.h"
#include "DateTime.h"
#include "Vehicle.h"


class takenTrip { //usada para mostrar e gravar viagens dos owners
	RegisteredUser* owner;   //usada para mostrar e gravar viagens de cada user (talvez)
	string startPont;
	string endPoint;
	Time endTime;
	Time startTime;
	Date day;
	unsigned int tripCode;

public:

};

class Path {
	Time timeSpent;
	string first;
	string second;
};

class Stretch {
	string stop;
	vector<int> usersID;
	Time toNext;
};

class waitingTrip { 
	RegisteredUser* owner;
	vector<Stretch> Viagem;
	bool full;
	float pricePerMinute;
	int maxSeats;

public:

};

#endif