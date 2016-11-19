// because of numeric_limits
#pragma once
#ifndef TRIP_H_
#define TRIP_H_

#include "User.h"
#include "DateTime.h"
#include "Vehicle.h"


class takenTrip { //usada para mostrar e gravar viagens dos owners
	string owner;   //usada para mostrar e gravar viagens de cada user (talvez)
	string startPoint;
	string endPoint;
	Time endTime;
	Time startTime;
	Date day;
	static unsigned int tripCode;

public:
	takenTrip(string owns, string start, string finish, Time end);
	unsigned int getTripCode();

	friend ostream& operator<<(ostream& out, const takenTrip& trip);

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
	User* owner;
	vector<Stretch> Viagem;
	bool full;
	float pricePerMinute;
	int maxSeats;

public:

};

#endif