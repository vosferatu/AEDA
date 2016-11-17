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
	float account;

public:
	User() {};
	User(string username);

	unsigned int getid() const;
	string getusername() const;
	float getAccount() const;
};

class RegisteredUser : public User {
	
	vector<int> Trips; //user may want to see trips his been in (tripID's)
	string homeCity;
	vector<int> friends; //friends ID
	float maintainenceTAX;
	string password;
	Vehicle vehicle;


public:

	RegisteredUser(string username, string password, Vehicle car);

	string getpassword() const;
	float getmaintainenceTAX() const;
	unsigned int getnumTrips() const;
	string getCity() const;
	vector<int> getTrips() const;
	
	void setVehicle(Vehicle* car);
	Vehicle getVehicle() const;
	
	vector<int> getBuddies() const;

	friend ostream& operator<<(ostream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

};


class GuestUser : public User {
	float tripCosts;

public:
	GuestUser(string username);
};



#endif /* USER_H_ */
