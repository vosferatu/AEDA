#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include "Vehicle.h"
#include "TripDateTime.h"

using namespace std;

class User{
	unsigned int id;
	string username;
	string password;
	vector<string> route;
	vector<Trip> Trips;
	string city;
	float account;

public:
	string getusername();
	string getpassword();
	unsigned int getid();
	vector<string> getroute();
	unsigned int getnumTrips();
	string getCity();
	float getAccount();
};

class RegisteredUser : public User {
	vector <User> friends;
	float maintainenceTAX;

};

class VehicleUser : public RegisteredUser , public User{
	Vehicle myRide; //create constructor and function for empty vehicle, to distinguish reg users
};

class RideUser : public RegisteredUser, public User {
	float TAX;

};

class GuestUser : public User {
	float tripCosts;

};



#endif /* USER_H_ */