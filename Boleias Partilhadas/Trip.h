#pragma once
#ifndef TRIP_H_
#define TRIP_H_

#include "User.h"
#include "DateTime.h"
#include "Vehicle.h"


class takenTrip {
	User* owner;
	string startPont;
	string endPoint;
	Time endTime;
	Time startTime;
	Date day;

public:

};

//class trip 
class waitingTrip {
	User* owner;
	bool full;

public:

};

#endif