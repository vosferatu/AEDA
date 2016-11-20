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

	static vector<string>cities;
	static const string citiesfile;
	static unsigned int numbercities;
	static float TAX;


public:
	
	
	//void saveUsers() const;
	
	SharedRides() {}; //podemos fazer os loads todos no construtor
	 
	void run();


	// MENUS
	void main_menu();
	void manage_menu();
	void user_menu();

	// SAVE
	void saveUsers() const;
	void saveVehicles() const;

	// LOAD
	void load();
	static void loadCities();


	//LOGIN & REGISTRATION
	User* login(const string &username, const string &password);
	static void CreateRegis();

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


#endif