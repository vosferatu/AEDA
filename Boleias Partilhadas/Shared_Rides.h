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
	User* currentUser;  //se não for pointer, slicing problem
	static vector<string>cities; //saved in file

	static const string citiesfile;

	static unsigned int numbercities;


public:
	static void CreateRegis();
	//void saveUsers() const;
	SharedRides() {}; //podemos fazer os loads todos no construtor
	void main_menu();
	void manage_menu();
	void user_menu();
	void saveUsers() const;
	void load();
	static void loadCities();

	~SharedRides(){
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
	}

	
};



#endif