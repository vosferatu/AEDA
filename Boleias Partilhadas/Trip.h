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
	takenTrip(){}
	unsigned int getTripCode() const;
	string getName() const;
	
	string getStart() const;
	string getEnd() const;
	Time getEndTime() const;
	Time getStartTime() const;
	Date getDay() const;

	void setStartime(Time start);

	void setTripCode(unsigned int tripcode);




	void save(ofstream& out) const;


	void setName(string nome);

	friend ofstream& operator<<(ofstream& out, const takenTrip& trip);//save in file
	friend ostream& operator<<(ostream& out, const takenTrip& trip); //mostrar no ecrã

};


class Stretch {
	string stop;
	vector<int> usersID;
	Time toNext;
public:
	Stretch(string city, Time next);
	Stretch() {}
	string getCity() const;
	vector<int> getusers() const;
	Time getTime() const;

	void setCity(string city);
	void addUser(int id);
	void setTime(Time newTime);
	void setvectID(vector<int> usersID);



	friend ofstream& operator<<(ofstream& out, const Stretch& way);//save on file
};

class waitingTrip { 
	unsigned int ownerID;
	vector<Stretch> Viagem;
	bool full;
	float pricePerStop;
	int maxSeats;

public:
	waitingTrip(unsigned int owner, vector<Stretch> Viagem, int maxSeats, float price);
	waitingTrip();

	unsigned int getOwner() const;
	vector<Stretch> getWay() const;
	bool getFull() const;
	float getpriceStop() const;
	int getmaxSeats() const;

	void setOwner(unsigned int id);
	void setWay(vector<Stretch> way);
	void setFull(bool change);
	void setpriceStop(float price);
	void setmaxSeats(int seats);


	void save(ofstream& out) const;

	friend ofstream& operator<<(ofstream& out, const waitingTrip& trip);//save on file
};

class Path {
	Time timeSpent;
	string first;
	string second;
public:
	Path(string first, string second, Time timeSpent);
	Path(){}
	Time getTime() const;
	string getFirst() const;
	string getSecond() const;
};

#endif