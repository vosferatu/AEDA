#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class User{
	unsigned int id;
	string username;
	bool vehicle;

public:
	string getname();
	unsigned int getid();
	bool hasvehicle();


};

class RegisteredUser : public User {
	vector <User> friends;
	string password;

public:
	RegisteredUser(string nome, string password);


};

class GuestUser : public User {


};



#endif /* USER_H_ */