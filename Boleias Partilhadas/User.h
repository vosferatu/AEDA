#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include "Vehicle.h"
#include "TripDateTime.h"

using namespace std;

class User{
	const unsigned int id;
	static unsigned int next_id;

	string username;
	vector<string> route;
	vector<Trip> Trips;
	string city;
	float account;

public:
	User(string username);
	
	string getusername();
	
	unsigned int getid();
	vector<string> getroute();
	unsigned int getnumTrips();
	string getCity();
	float getAccount();
};

class RegisteredUser : public User {
	vector <User> friends;
	float maintainenceTAX;
	string password;
	Vehicle* myRide;

public:
	RegisteredUser(string username, string password);

	string getpassword();

};


class GuestUser : public User {
	float tripCosts;

};



#endif /* USER_H_ */
