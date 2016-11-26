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

/**********************************************************************************************//**
 * @class	User
 *
 * @brief	An user class.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class User{

	/** @brief	The idstatic to define users. */
	static unsigned int idstatic;
	/** @brief	The identifier of the user. */
	unsigned int id;
	/** @brief	The username of the user. */
	string username;
	/** @brief	The account of the user. */
	float account = 0;

public:

	/**********************************************************************************************//**
	 * @fn	User::User()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	User() {};

	/**********************************************************************************************//**
	 * @fn	User::~User()
	 *
	 * @brief	Destructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	~User() {};

	/**********************************************************************************************//**
	 * @fn	User::User(string username);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	username	The username.
	 **************************************************************************************************/

	User(string username);

	/**********************************************************************************************//**
	 * @fn	unsigned int User::getID() const;
	 *
	 * @brief	Gets the identifier.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The identifier.
	 **************************************************************************************************/

	unsigned int getID() const;

	/**********************************************************************************************//**
	 * @fn	string User::getusername() const;
	 *
	 * @brief	Gets the getusername.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	A string.
	 **************************************************************************************************/

	string getusername() const;

	/**********************************************************************************************//**
	 * @fn	float User::getAccount() const;
	 *
	 * @brief	Gets the account.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The account.
	 **************************************************************************************************/

	float getAccount() const;

	/**********************************************************************************************//**
	 * @fn	void User::setAccount(float account);
	 *
	 * @brief	Sets an account.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	account	The account.
	 **************************************************************************************************/

	void setAccount(float account);

	/**********************************************************************************************//**
	 * @fn	virtual string User::getpassword() const = 0;
	 *
	 * @brief	Gets the password.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	A string, password.
	 **************************************************************************************************/

	virtual string getpassword() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual Vehicle* User::getVehicle() const = 0;
	 *
	 * @brief	Gets the vehicle.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	Null if it fails, else the vehicle.
	 **************************************************************************************************/

	virtual Vehicle* getVehicle() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::chargeAccount(float addition);
	 *
	 * @brief	Charge account.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	addition	The addition to the previous value.
	 **************************************************************************************************/

	virtual void chargeAccount(float addition);

	/**********************************************************************************************//**
	 * @fn	virtual unsigned int User::getnumTrips() const = 0;
	 *
	 * @brief	Gets the number of trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	An int, the number of trips.
	 **************************************************************************************************/

	virtual unsigned int getnumTrips() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual string User::getCity() const = 0;
	 *
	 * @brief	Gets the homecity of the user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The city.
	 **************************************************************************************************/

	virtual string getCity() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual vector<int> User::getTrips() const = 0;
	 *
	 * @brief	Gets the trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The trips.
	 **************************************************************************************************/

	virtual vector<int> getTrips() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual vector<int> User::getFavs() const = 0;
	 *
	 * @brief	Gets the buddies.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The buddies.
	 **************************************************************************************************/

	virtual vector<int> getFavs() const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::setPassword(string password) = 0;
	 *
	 * @brief	Sets a password.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	password	The password.
	 **************************************************************************************************/

	virtual void setPassword(string password) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::setHome(string city) = 0;
	 *
	 * @brief	Sets a home city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	city	The city.
	 **************************************************************************************************/

	virtual void setHome(string city) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::showProfile() = 0;
	 *
	 * @brief	Shows the user profile.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	virtual void showProfile() = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::save(ofstream& out) const = 0;
	 *
	 * @brief	Saves the given output of the user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The output to save.
	 **************************************************************************************************/

	virtual void save(ofstream& out) const = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::setTrips(vector<int> trips) = 0;
	 *
	 * @brief	Sets the trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	trips	The vector of taken trips.
	 **************************************************************************************************/

	virtual void setTrips(vector<int> trips) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::setFavs(vector<int> favs) = 0;
	 *
	 * @brief	Sets the buddies.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	favs	The vector of buddies. 
	 **************************************************************************************************/

	virtual void setFavs(vector<int> favs) = 0;

	/**********************************************************************************************//**
	 * @fn	virtual void User::addTrip(unsigned int ID) = 0;
	 *
	 * @brief	Adds a trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	ID	The identifier of the trip.
	 **************************************************************************************************/

	virtual void addTrip(unsigned int ID) = 0;
};

/**********************************************************************************************//**
 * @class	RegisteredUser
 *
 * @brief	A registered user, the inherits from User.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class RegisteredUser : public User {
	
	/** @brief	user may want to see trips his been in (tripID's) */
	vector<int> Trips;
	/** @brief	The home city. */
	string homeCity;
	/** @brief	friends ID. */
	vector<int> favorites;
	/** @brief	The user password. */
	string password;
	/** @brief	The vehicle. */
	Vehicle* vehicle;


public:

	/**********************************************************************************************//**
	 * @fn	RegisteredUser::RegisteredUser(string username, string password, string city, Vehicle* car);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param 		  	username	The username.
	 * @param 		  	password	The password.
	 * @param 		  	city		The home city.
	 * @param [in,out]	car			If non-null, the car.
	 **************************************************************************************************/

	RegisteredUser(string username, string password, string city, Vehicle* car);

	/**********************************************************************************************//**
	 * @fn	string RegisteredUser::getpassword() const;
	 *
	 * @brief	Gets the password.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	A string, the password.
	 **************************************************************************************************/

	string getpassword() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int RegisteredUser::getnumTrips() const;
	 *
	 * @brief	Get the number of  trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	An int, the number of trips.
	 **************************************************************************************************/

	unsigned int getnumTrips() const;

	/**********************************************************************************************//**
	 * @fn	string RegisteredUser::getCity() const;
	 *
	 * @brief	Gets the home  city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The city.
	 **************************************************************************************************/

	string getCity() const;

	/**********************************************************************************************//**
	 * @fn	vector<int> RegisteredUser::getTrips() const;
	 *
	 * @brief	Gets the trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The vector of trips.
	 **************************************************************************************************/

	vector<int> getTrips() const;

	/**********************************************************************************************//**
	 * @fn	vector<int> RegisteredUser::getFavs() const;
	 *
	 * @brief	Gets the buddies.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The vector of buddies.
	 **************************************************************************************************/

	vector<int> getFavs() const;

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setTrips(vector<int> trips);
	 *
	 * @brief	Sets the  vector of trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	trips	The trips.
	 **************************************************************************************************/

	void setTrips(vector<int> trips);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setFavs(vector<int> favs);
	 *
	 * @brief	Sets the vector of friends.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	favs	The friends.
	 **************************************************************************************************/

	void setFavs(vector<int> favs);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setVehicle(Vehicle* car);
	 *
	 * @brief	Sets a vehicle.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	car	If non-null, the car.
	 **************************************************************************************************/

	void setVehicle(Vehicle* car);

	/**********************************************************************************************//**
	 * @fn	Vehicle* RegisteredUser::getVehicle() const;
	 *
	 * @brief	Gets the vehicle.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	Null if it fails, else the vehicle.
	 **************************************************************************************************/

	Vehicle* getVehicle() const;

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setHome(string city);
	 *
	 * @brief	Sets a home city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	city	The city.
	 **************************************************************************************************/

	void setHome(string city);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setPassword(string password);
	 *
	 * @brief	Sets a password.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	password	The password.
	 **************************************************************************************************/

	void setPassword(string password);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::addTrip(unsigned int ID);
	 *
	 * @brief	Adds a trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	ID	The identifier of the trip.
	 **************************************************************************************************/

	void addTrip(unsigned int ID);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::setVehicleID(unsigned int id);
	 *
	 * @brief	Sets vehicle identifier.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier.
	 **************************************************************************************************/

	void setVehicleID(unsigned int id);

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::save(ofstream& out) const;
	 *
	 * @brief	Saves the given out.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The output to save.
	 **************************************************************************************************/

	void save(ofstream& out) const;

	/**********************************************************************************************//**
	 * @fn	void RegisteredUser::showProfile();
	 *
	 * @brief	Shows the user profile.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void showProfile();

	/**********************************************************************************************//**
	 * @fn	friend ofstream& RegisteredUser::operator<<(ofstream& os, const RegisteredUser* RU);
	 *
	 * @brief	Stream insertion operator.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	os	The operating system.
	 * @param 		  	RU	The ru.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ofstream& operator<<(ofstream& os, const RegisteredUser* RU); // for now, only for writing in file of users purpose

};

/**********************************************************************************************//**
 * @class	GuestUser
 *
 * @brief	A guest user class.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class GuestUser : public User {

public:

	/**********************************************************************************************//**
	 * @fn	GuestUser::GuestUser(string username);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	username	The username.
	 **************************************************************************************************/

	GuestUser(string username);
};



#endif USER_H_ 
