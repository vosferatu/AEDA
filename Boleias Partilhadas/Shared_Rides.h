#pragma once
#ifndef SHARED_RIDES_H_
#define SHARED_RIDES_H_

#include "User.h"
#include <vector>

using namespace std;

class SharedRides
{
	static vector<User*> users;
	static vector<takenTrip> tripsPrinter;
	static vector<Vehicle> cars;//used to list cars in manage app
	static vector<Path> caminhos;//saved in file
	static vector<waitingTrip> tripOffers;
	User* currentUser = NULL;  //se não for pointer, slicing problem
	//static vector<takenTrip> tripsPrinter;
	//static vector<waitingTrip> tripsWaiting;
	static vector<string>cities;

	static const string citiesfile;

	static unsigned int numbercities;


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

	
};

// tratamento de exceções



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