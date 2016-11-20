#pragma once
#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <fstream>
#include "Vehicle.h"
#include "DateTime.h"
#include "Trip.h"

#undef max // because of numeric_limits
using namespace std;

class User{

	static unsigned int idstatic;
	unsigned int id;
	string username;
	float account;

public:
	User() {};
	User(string username);

	unsigned int getID() const;
	string getusername() const;
	float getAccount() const;
	virtual string getpassword() const = 0;
	virtual Vehicle getVehicle() const=0;
	virtual void save(ofstream& out) const = 0;

};

class RegisteredUser : public User {
	
	vector<int> Trips; //user may want to see trips his been in (tripID's)
	string homeCity;
	vector<int> friends; //friends ID
	float maintainenceTAX;
	string password;
	Vehicle vehicle;


public:

	RegisteredUser(string username, string password, string city, Vehicle car);

	string getpassword() const;
	float getmaintainenceTAX() const;
	unsigned int getnumTrips() const;
	string getCity() const;
	vector<int> getTrips() const;
	
	void setVehicle(Vehicle* car);
	Vehicle getVehicle() const;

	void setVehicleID(unsigned int id);

	void save(ofstream& out) const;

	vector<int> getBuddies() const;

	friend ofstream& operator<<(ofstream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

};


class GuestUser : public User {
	float tripCosts;

public:
	GuestUser(string username);
};



#endif /* USER_H_ */
