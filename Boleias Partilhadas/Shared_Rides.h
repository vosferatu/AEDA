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
	static vector<Path> caminhos;
	static vector<waitingTrip> tripOffers;
	User* currentUser;  //se não for pointer, slicing problem


public:
	static void CreateRegis();
	//void saveUsers() const;
	SharedRides() {};
	void main_menu();
	void manage_menu();

	~SharedRides(){
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
	}

	
};



#endif