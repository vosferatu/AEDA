#include "User.h"
#include <string>

using namespace std;

unsigned int User::next_id = 0;

User::User(string username) : id(next_id++) {
	this->username = username;
}


string User::getusername() const {
	return username;
}

string RegisteredUser::getpassword() const
{
	return password;
}

unsigned int User::getid() {
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

RegisteredUser::RegisteredUser(string username, string password) : User(username) {
	this->password = password;
}

ostream& operator<<(ostream& os, const RegisteredUser& RU)
{
	os << RU.getusername() << endl << RU.getpassword() << endl;
	return os;
}

