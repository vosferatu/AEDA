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
	float account = 0;

public:
	User() {};
	~User() {};
	User(string username);

	unsigned int getID() const;
	string getusername() const;
	float getAccount() const;
	void setAccount(float account);
	virtual string getpassword() const = 0;
	virtual Vehicle* getVehicle() const = 0;
	virtual void chargeAccount(float addition);
	virtual unsigned int getnumTrips() const = 0;
	virtual string getCity() const = 0;
	virtual vector<int> getTrips() const = 0;
	virtual vector<int> getFavs() const = 0;
	virtual void setPassword(string password) = 0;
	virtual void setHome(string city) = 0;
	virtual void showProfile() = 0;
	virtual void save(ofstream& out) const = 0;
	virtual void setTrips(vector<int> trips) = 0;
	virtual void setFavs(vector<int> favs) = 0;
	virtual void addTrip(unsigned int ID) = 0;
};

class RegisteredUser : public User {
	
	vector<int> Trips; //user may want to see trips his been in (tripID's)
	string homeCity;
	vector<int> favorites; //friends ID
	string password;
	Vehicle* vehicle;


public:

	RegisteredUser(string username, string password, string city, Vehicle* car);

	string getpassword() const;
	unsigned int getnumTrips() const;
	string getCity() const;
	vector<int> getTrips() const;
	vector<int> getFavs() const;

	void setTrips(vector<int> trips);
	void setFavs(vector<int> favs);
	

	float getmaintainenceTAX() const;

	void setVehicle(Vehicle* car);
	Vehicle* getVehicle() const;
	void setHome(string city);
	void setPassword(string password);
	void addTrip(unsigned int ID);

	void setVehicleID(unsigned int id);

	void save(ofstream& out) const;

	void showProfile();

	friend ofstream& operator<<(ofstream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

};


class GuestUser : public User {

public:
	GuestUser(string username);
};



#endif USER_H_ 
