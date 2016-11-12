#include "User.h"
#include <string>
#include <fstream>

using namespace std;

unsigned int User::id = 0;



//////////////////////////////////////////////////// USER - GENERAL CLASS //////////////////////////////////////////////////////////

User::User(string username) {
	this->username = username;
	this->id = id;
	id++;
}


string User::getusername() const {
	return username;
}



unsigned int User::getid() const {
	return id; 
}

vector<string> User::getroute()
{
	return vector<string>();
}

//unsigned int User::getnumTrips()
//{
	//return Trips.size();
//}

string User::getCity()
{
	return city;
}

float User::getAccount()
{
	return account;
}

/////////////////////////////////////////////////// REGISTERED USER /////////////////////////////////////////////////////

RegisteredUser::RegisteredUser(string username, string password) : User(username) {
	this->password = password;
}

string RegisteredUser::getpassword() const
{
	return password;
}

ostream& operator<<(ostream& os, const RegisteredUser* RU)
{
	os << RU->getid() << endl << RU->getusername() << endl << RU->getpassword() << endl;
	return os;
}



////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}