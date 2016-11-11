#pragma once
#ifndef SHARED_RIDES_H_
#define SHARED_RIDES_H_

#include "User.h"
#include <vector>

using namespace std;

class SharedRides
{
	static vector<User*> users;


public:
	static void CreateRegis();
	
	~SharedRides()
	{
		for (unsigned int i = 0; i < users.size(); ++i)
		{
			delete users[i];
		}
	}
};



#endif
