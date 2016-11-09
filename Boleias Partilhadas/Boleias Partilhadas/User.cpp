#include "User.h"

using namespace std;


string User::getusername() {
	return username;
}

string RegisteredUser::getpassword()
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

unsigned int User::getnumTrips()
{
	return Trips.size();
}

string User::getCity()
{
	return city;
}

float User::getAccount()
{
	return account;
}

