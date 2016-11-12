#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;



class User{
	static unsigned int id;
	string name;
	bool vehicle;

public:
	User();
	string getname();
	void setname(const string &n);
	unsigned int getid();
	bool hasvehicle();
	void regist_name();


};

class RegisteredUser : public User {
	string username;
	string password;

	vector<User*> RegisteredUsers;



public:
	
	RegisteredUser();

	//registration
	void setusername(string const &user) const;
	void setpassword(string const &pass) const;

	void regist_password();
	void regist_username();
	void save_user();

		vector <User> friends;


};

RegisteredUser user_registration();

class GuestUser : public User {


};



#endif /* USER_H_ */