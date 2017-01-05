#pragma once
#ifndef SHARED_RIDES_H_
#define SHARED_RIDES_H_

#include "User.h"
#include "Helper.h"
#include "Vehicle.h"
#include "DateTime.h"
#include "BST.h"
#include "Trip.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <queue>
#include <unordered_set>


#undef max // because of numeric_limits



using namespace std;

/**********************************************************************************************//**
* @struct	eqstr
*
* @brief	Equal operator to user to use in hash table
*
* @author	João
* @date	1-1-2017
*
**************************************************************************************************/


struct eqstr {
	bool operator() (const User *s1, const User *s2) const {
		return s1->getusername() == s2->getusername();
	}
};

/**********************************************************************************************//**
* @struct	hstr
*
* @brief	Function to insert elements in the table.
*
* @author	João
* @date	1-1-2017
*
**************************************************************************************************/

struct hstr {
	int operator() (const User *s1) const {

		string name = s1->getusername();
		int v = 0;
		for (unsigned int i = 0; i< name.size(); i++)
			v = 37 * v + name[i];
		return v;
	}
};

/**********************************************************************************************//**
 * @class	SharedRides
 *
 * @brief	The masterclass of our program.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

typedef tr1::unordered_set<User*, hstr, eqstr> HASH;

class SharedRides
{
	/** @brief	The users. */
	static vector<User*> users;
	/** @brief	The trips that were taken. */
	static vector<takenTrip> tripsPrinter;
	/** @brief	used to list cars in manage app. */
	//static vector<Vehicle*> cars;
	/** @brief	The paths. */
	vector<Path> caminhos;
	/** @brief	The trip offers in the moment. */
	static vector<waitingTrip> tripOffers;
	/** @brief	The current user. */
	User* currentUser = NULL;  //se não for pointer, slicing proble
	/** @brief	vector of active trips */
	vector<waitingTrip> tripsWaiting;
	/** @brief	vector with cities suported by this program */
	static vector<string>cities;


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
	float TAX = 0;

	/** @brief	True if vect of users changed. */
	static bool usersalterados;
	/** @brief	True if vect of cars changed. */
	static bool carsalterados;


	/** @brief	The BST to save the vehicles of the system */
	BST<VehicleDBItem> carsBST;

	/** @brief	The hash table to save the inactive users*/

	HASH inativos;




public:
	/**********************************************************************************************//**
	 * @fn	SharedRides::SharedRides()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	SharedRides() : carsBST(VehicleDBItem()){}; //podemos fazer os loads todos no construtor

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

	/**********************************************************************************************//**
	 * @fn	void SharedRides::promotion();
	 *
	 * @brief	This function realizes all the hash table operations, verifing how long a user is inactive in putting him in the table if greater then 10
	 *
	 * @author	João
	 * @date	1-1-2017
	 **************************************************************************************************/

	void promotion();

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

	void load();

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

	 void loadUsers();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::loadVehicles();
	 *
	 * @brief	Loads the vehicles.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	void loadVehicles();

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
	 * @fn	void SharedRides::guest_log();
	 *
	 * @brief	Login system to guest (only requests username)
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 **************************************************************************************************/
	
	void guest_log();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::setTable(unordered_set<User*, hstr, eqstr> inativos);
	 *
	 * @brief	sets a hash table.
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @param inativos the hash table to define.
	 **************************************************************************************************/

	void setTable(unordered_set<User*, hstr, eqstr> inativos);

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::showUsers();
	 *
	 * @brief	outups the users.
	 *
	 * @author	João
	 * @date	1-1-2017
	 **************************************************************************************************/
	
	void showUsers();

	/**********************************************************************************************//**
	 * @fn	static void SharedRides::CreateRegis();
	 *
	 * @brief	Creates a user in the system.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	 void CreateRegis();

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

		carsBST.makeEmpty();

		//for (unsigned int i = 0; i < cars.size(); ++i) {
			//delete cars[i];
		//}
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
	 * @fn	void SharedRides::searchVehicle();
	 *
	 * @brief	function to search vehicles in the BST
	 *
	 * @author	João
	 * @date	1-1-2017
	 **************************************************************************************************/
	
	void searchVehicle();

	/**********************************************************************************************//**
	 * @fn	void SharedRides::editVehicleOwner();
	 *
	 * @brief	Changes the owner of a specific  car.
	 *
	 * @author	João
	 * @date	29-12-2016
	 **************************************************************************************************/

	 void editVehicleOwner();

	 /**********************************************************************************************//**
	 * @fn	void SharedRides::showCars();
	 *
	 * @brief	shows the cars of BST
	 *
	 * @author	João
	 * @date	1-1-2017
	 **************************************************************************************************/

	 void showCars();

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


	/**********************************************************************************************//**
	 * @fn	void SharedRides::header(string header);
	 *
	 * @brief	program header
	 * @param header  the header thitle
	 *@param who - if RU or guest
	 *
	 * @author	João
	 * @date	25-12-2016
	 **************************************************************************************************/

	void header(string header,string who) const;
};

// tratamento de exceções





/**********************************************************************************************//**
 * @class	FileException
 *
 * @brief	Exception for signalling file errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/
template<class T>
class FileException
{
public:
	T info;
	FileException(T info)
	{
		this->info = info;
	}
};



/**********************************************************************************************//**
 * @class	LoginException
 *
 * @brief	Exception for signalling login errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/
template<class T>
class LoginException
{
public:
	T info;
	LoginException(T info)
	{
		this->info = info;
	}
};


/**********************************************************************************************//**
 * @class	RegistrationException
 *
 * @brief	Exception for signalling registration errors.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/
template<class T>

class RegistrationException
{
public:
	T info;
	RegistrationException(T info)
	{
		this->info = info;
	}
};


/**********************************************************************************************//**
 * @class	UserNotFound
 *
 * @brief	Exception for users not found.
 *
 * @author	João
 * @date	29-11-2016
 **************************************************************************************************/

template<class T>
class UserNotFound
{
public:
	T info;
	UserNotFound(T info)
	{
		this->info = info;
	}
};





#endif