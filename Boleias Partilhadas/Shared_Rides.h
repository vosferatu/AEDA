#pragma once
#ifndef SHARED_RIDES_H_
#define SHARED_RIDES_H_

#include "User.h"
#include "Helper.h"
#include "Vehicle.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <ostream>

#undef max // because of numeric_limits

using namespace std;

/**********************************************************************************************//**
 * @class	SharedRides
 *
 * @brief	The masterclass of our program.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class SharedRides
{
	/** @brief	The users. */
	static vector<User*> users;
	/** @brief	The trips that were taken. */
	static vector<takenTrip> tripsPrinter;
	/** @brief	used to list cars in manage app. */
	static vector<Vehicle*> cars;
	/** @brief	The paths. */
	vector<Path> caminhos;
	/** @brief	The trip offers in the moment. */
	static vector<waitingTrip> tripOffers;
	/** @brief The user operating the system. */
	User* currentUser = NULL;
	/** @brief	The trips waiting. */

	/**********************************************************************************************//**
	 * @property	static vector<string>cities
	 *
	 * @brief	static vector of the cities.
	 *
	 * @tparam	string	Type of the string.
	 *
	 * @value	.
	 **************************************************************************************************/

	static vector<string> cities;

	/** @brief	Identifier for the maximum users. */
	static unsigned int maxUsersID;
	/** @brief	Identifier for the maximum vehicles. */
	static unsigned int maxVehiclesID;
	/** @brief	The maximum taken code. */
	static unsigned int maxTakenCode;

	/**********************************************************************************************//**
	 * @property	static const string citiesfile, usersfile, carsfile, takenfile, waitingfile
	 *
	 * @brief	defitions of files 
	 **************************************************************************************************/

	static const string citiesfile, usersfile, carsfile, takenfile, waitingfile;

	/** @brief	The number of cities. */
	static unsigned int numbercities;
	
	/** @brief	The tax to operate the money system. */
	float TAX;

	/** @brief	True if vect of users changed. */
	static bool usersalterados;
	/** @brief	True if vect of cars changed. */
	static bool carsalterados;


public:

	/**********************************************************************************************//**
	 * @fn	SharedRides::SharedRides()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	SharedRides() {}; //podemos fazer os loads todos no construtor

	/**********************************************************************************************//**
	 * @fn	void SharedRides::run();
	 *
	 * @brief	Runs the program.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void run();


	// MENUS

	/**********************************************************************************************//**
	 * @fn	void SharedRides::main_menu();
	 *
	 * @brief	Main menu.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void main_menu();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::manage_menu();
	 *
	 * @brief	Admin's menu.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void manage_menu();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::user_menu();
	 *
	 * @brief	User menu.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void user_menu();

	// SAVE

	/**********************************************************************************************//**
	 * @fn	void SharedRides::saveChanges() const;
	 *
	 * @brief	Saves the changes to users, cars or trips in the files.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void saveChanges() const;
	
	// LOAD

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::load();
	 *
	 * @brief	Loads all the things.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void load();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadCities();
	 *
	 * @brief	Loads the cities.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void loadCities();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadUsers();
	 *
	 * @brief	Loads the users.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void loadUsers();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadVehicles();
	 *
	 * @brief	Loads the vehicles.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void loadVehicles();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadTakenTrips();
	 *
	 * @brief	Loads taken trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void loadTakenTrips();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadWaitingTrips();
	 *
	 * @brief	Loads waiting trips.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void loadWaitingTrips();


	//LOGIN & REGISTRATION

	/**********************************************************************************************//**
	 * @fn	User* SharedRides::login(const string &username, const string &password);
	 *
	 * @brief	Login system.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	username	The username.
	 * @param	password	The password.
	 *
	 * @return	Null if it fails, else a pointer to a User.
	 **************************************************************************************************/

	User* login(const string &username, const string &password);

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::CreateRegis();
	 *
	 * @brief	Creates a user in the system.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	static void CreateRegis();

	/**********************************************************************************************//**
	 * @fn	unsigned int SharedRides::getCARHighID() const;
	 *
	 * @brief	Gets car high identifier.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The car high identifier.
	 **************************************************************************************************/

	unsigned int getCARHighID() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int SharedRides::getUSERHighID() const;
	 *
	 * @brief	Gets user high identifier.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The user high identifier.
	 **************************************************************************************************/

	unsigned int getUSERHighID() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int SharedRides::getTAKENHighID() const;
	 *
	 * @brief	Gets taken trips high identifier.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The taken high identifier.
	 **************************************************************************************************/

	unsigned int getTAKENHighID() const;

	/**********************************************************************************************//**
	 * @fn	SharedRides::~SharedRides()
	 *
	 * @brief	Destructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	~SharedRides(){
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
		for (unsigned int i = 0; i < cars.size(); ++i) {
			delete cars[i];
		}
	}

	//helpers

	/**********************************************************************************************//**
	 * @fn	void SharedRides::fillPaths();
	 *
	 * @brief	Fill paths.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void fillPaths();

	/**********************************************************************************************//**
	 * @fn	int SharedRides::getPositionCar(unsigned int id) const;
	 *
	 * @brief	Gets position of the car in the vector.
	 
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier.
	 *
	 * @return	The car position.
	 **************************************************************************************************/

	int getPositionCar(unsigned int id) const;

	/**********************************************************************************************//**
	 * @fn	int SharedRides::getPositionUser(unsigned int id) const;
	 *
	 * @brief	Gets position of a  user in the vector.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier.
	 *
	 * @return	The user position.
	 **************************************************************************************************/

	int getPositionUser(unsigned int id) const;

	/**********************************************************************************************//**
	 * @fn	void SharedRides::recompensate(unsigned int id);
	 *
	 * @brief	Recompensates the given user .
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier of the user.
	 **************************************************************************************************/

	void recompensate(unsigned int id);

	/**********************************************************************************************//**
	 * @fn	Time SharedRides::searchStretchTime(string one, string two);
	 *
	 * @brief	if a user and his vehicle and trips are removed, the others users recover their money
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	one	The first location
	 * @param	two	The segond location.
	 *
	 * @return	The found stretch time.
	 **************************************************************************************************/

	Time searchStretchTime(string one, string two);

	/**********************************************************************************************//**
	 * @fn	string SharedRides::searchStretchCity(string one, Time t1);
	 *
	 * @brief	Searches for city, given the time and the start city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	one	The city
	 * @param	t1 	The time to get to the city.
	 *
	 * @return	The found stretch between cities.
	 **************************************************************************************************/

	string searchStretchCity(string one, Time t1);

	/**********************************************************************************************//**
	 * @fn	int SharedRides::checkTrip(string a, string b, const vector<Stretch> & v) const;
	 *
	 * @brief	Check if a trip is doable.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	a	place A
	 * @param	b	place B 
	 * @param	v	the stretch between A and B, if it exists
	 *
	 * @return	An int number of stops, negative if doesn't have any.
	 **************************************************************************************************/

	int checkTrip(string a, string b, const vector<Stretch> & v) const;

	/**********************************************************************************************//**
	 * @fn	bool SharedRides::checkBuddie(unsigned int user1);
	 *
	 * @brief	Check if a given user its a friend/favorite of currentuser.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	user1	The user to test.
	 *
	 * @return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool checkBuddie(unsigned int user1);

	//MENUS Functions
	void showTrips() const;

	/**********************************************************************************************//**
	 * @fn	void SharedRides::userWithVehicleMenu();
	 *
	 * @brief	User with vehicle menu.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void userWithVehicleMenu();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::editVehicle();
	 *
	 * @brief	Edits the current user vehicle.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void editVehicle();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::removeVehicle();
	 *
	 * @brief	Removes current user  vehicle.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void removeVehicle();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::addVehicle();
	 *
	 * @brief	Adds vehicle to the current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void addVehicle();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::creditAccount();
	 *
	 * @brief	Credits the  account of current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void creditAccount();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::changeProfile();
	 *
	 * @brief	Change profile of current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void changeProfile();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::deleteAccount();
	 *
	 * @brief	Deletes the account of current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void deleteAccount();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::buddiesMenu();
	 *
	 * @brief	The Buddies menu to a current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void buddiesMenu();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::addBuddie();
	 *
	 * @brief	Adds a  buddie to current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void addBuddie();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::removeBuddie();
	 *
	 * @brief	Removes a buddie of current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void removeBuddie();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::myBuddies() const;
	 *
	 * @brief	Show buddies of current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void myBuddies() const;

	/**********************************************************************************************//**
	 * @fn	void SharedRides::VehicleTripMenu();
	 *
	 * @brief	Vehicle trip menu.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void VehicleTripMenu();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::addTrip();
	 *
	 * @brief	Adds trip to current user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void addTrip();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::startTrip();
	 *
	 * @brief	Starts a desired trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void startTrip();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::enterTrip();
	 *
	 * @brief	Enters a  trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void enterTrip();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::showBuddiesProfileToUser();
	 *
	 * @brief	Shows the buddies profile to user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void showBuddiesProfileToUser();

};

// tratamento de exceções



template<class T>

/**********************************************************************************************//**
 * @class	FileException
 *
 * @brief	Exception for signalling file errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class FileException
{
public:
	T info;
	FileException(T info)
	{
		this->info = info;
	}
};

template<class T>

/**********************************************************************************************//**
 * @class	LoginException
 *
 * @brief	Exception for signalling login errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class LoginException
{
public:
	T info;
	LoginException(T info)
	{
		this->info = info;
	}
};

template<class T>

/**********************************************************************************************//**
 * @class	RegistrationException
 *
 * @brief	Exception for signalling registration errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class RegistrationException
{
public:
	T info;
	RegistrationException(T info)
	{
		this->info = info;
	}
};





#endif