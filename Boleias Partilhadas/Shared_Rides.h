#pragma once
#ifndef SHARED_RIDES_H_
#define SHARED_RIDES_H_

#include "User.h"
#include <vector>

using namespace std;

class SharedRides
{
	static vector<User*> users;
	//static vector<takenTrip> tripsPrinter;
	static vector<Vehicle> cars;
	//static vector<waitingTrip> tripsWaiting;
	static vector<string>cities;

	static const string citiesfile;

	static unsigned int numbercities;


public:
	static void CreateRegis();
	void saveUsers() const;
	void load();
	static void loadCities();

	~SharedRides(){
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
	}

	
};



#endif