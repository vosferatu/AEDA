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
	vector<takenTrip> Trips; //user may want to see his trips
	float account;

public:
	User(string username);

	unsigned int getid() const;
	string getusername() const;
	unsigned int getnumTrips() const;
	string getCity() const;
	vector<Trip> getTrips() const;
	float getAccount() const;
};

class RegisteredUser : public User {
	vector <User*> friends;
	float maintainenceTAX;
	string password;
	unsigned int vehicleID;

public:

	RegisteredUser(string username, string password);

	string getpassword() const;
	float getmaintainenceTAX() const;
	unsigned int getVehicle() const;
	vector<User*> getBuddies() const;

	friend ostream& operator<<(ostream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

	};


class GuestUser : public User {
	float tripCosts;

public:
	GuestUser(string username);
};



#endif /* USER_H_ */
