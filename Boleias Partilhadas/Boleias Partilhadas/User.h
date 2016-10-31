#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class User{
	unsigned int id;
	string name;
	bool hasvehicle;

public:

};

class RegisteredUser : public User {
	vector <User> friends;


};

class GuestUser : public User {


};



#endif /* USER_H_ */