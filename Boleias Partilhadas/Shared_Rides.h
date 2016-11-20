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

class SharedRides
{
	static vector<User*> users;
	static vector<takenTrip> tripsPrinter;
	static vector<Vehicle*> cars;//used to list cars in manage app
	static vector<Path> caminhos;
	static vector<waitingTrip> tripOffers;
	User* currentUser = NULL;  //se n�o for pointer, slicing problem
	static vector<waitingTrip> tripsWaiting;
	static vector<string>cities;

	static unsigned int maxUsersID;
	static unsigned int maxVehiclesID;

	static const string citiesfile, usersfile, carsfile; 

	static unsigned int numbercities;
	static float TAX;

	static bool usersalterados;
	static bool carsalterados;


public:
	
	
	//void saveUsers() const;
	
	SharedRides() {}; //podemos fazer os loads todos no construtor
	 
	void run();


	// MENUS
	void main_menu();
	void manage_menu();
	void user_menu();

	// SAVE
	void saveChanges() const;
	
	// LOAD
	static void load();
	static void loadCities();
	static void loadUsers();
	static void loadVehicles();


	//LOGIN & REGISTRATION
	User* login(const string &username, const string &password);
	static void CreateRegis();

	unsigned int getCARHighID() const;
	unsigned int getUSERHighID() const;


	~SharedRides(){
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
	}

	//helpers
	void fillPaths();
	int getPositionCar(unsigned int id) const;
	int getPositionUser(unsigned int id) const;
	void recompensate(unsigned int id);

	//MENUS Functions
	void showTrips() const;

	void userWithVehicleMenu();
	void editVehicle();
	void removeVehicle();

	void addVehicle();

	void creditAccount();

	void changeProfile();

	void deleteAccount();

	void buddiesMenu();
	void addBuddie();
	void removeBuddie();
	void showBuddiesProfileToUser();
	void myBuddies();

};

// tratamento de exce��es



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





#endif