#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include "Vehicle.h"
#include "DateTime.h"
#include "Trip.h"

using namespace std;

class User{
	static unsigned int id;

	string username;
	string homeCity;
	//vector<Trip> Trips;
	string city;
	float account;

public:
	User(string username);
	
	string getusername() const;
	
	unsigned int getid() const;
	vector<string> getroute();
	unsigned int getnumTrips();
	string getCity();
	float getAccount();
};

class RegisteredUser : public User {
	vector <User*> friends;
	float maintainenceTAX;
	string password;
	Vehicle* myRide;

public:
	RegisteredUser(string username, string password);

	string getpassword() const;

	friend ostream& operator<<(ostream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

	};


class GuestUser : public User {
	float tripCosts;

public:
	GuestUser(string username);
};



#endif /* USER_H_ */
