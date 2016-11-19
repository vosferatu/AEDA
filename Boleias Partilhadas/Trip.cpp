#include "Trip.h"


////////////////////////TAKEN ///////////////////////////////////////////
unsigned int takenTrip::tripCode = 1;

takenTrip::takenTrip(string owns, string start, string finish, Time end){
	owner = owns;
	startPoint = start;
	endPoint = endPoint;
	startTime = Time();
	endTime = end;
	day = Date();
	this->tripCode = tripCode;
	tripCode++;
}

unsigned int takenTrip::getTripCode(){
	return this->tripCode;
}

ostream & operator<<(ostream & out, const takenTrip & trip){
	out << "Dono: " << trip.owner << " ";
	out << "Start City: " << trip.startPoint << " ";
	out << "Last City: " << trip.endPoint << endl;
	out << "Start Time: " << trip.startTime << " ";
	out << "End Time: " << trip.endTime << " ";
	out << "Day: " << trip.day << endl;

	return out;
}
