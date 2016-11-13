#include "User.h"
#include <string>
#include <fstream>

using namespace std;

unsigned int User::id = 1;



//////////////////////////////////////////////////// USER - GENERAL CLASS //////////////////////////////////////////////////////////

User::User(string username) {
	this->username = username;
	this->id = id;
	id++;
}


string User::getusername() const {
	return username;
}

//vector<Trip> User::getTrips() const {
//	return Trips;
//}

unsigned int User::getid() const {
	return id; 
}


//unsigned int User::getnumTrips() const{
////	return Trips.size();
//}

string User::getCity() const{
	return homeCity;
}

float User::getAccount() const{
	return account;
}

/////////////////////////////////////////////////// REGISTERED USER /////////////////////////////////////////////////////

RegisteredUser::RegisteredUser(string username, string password) : User(username){
	this->password = password;
}

string RegisteredUser::getpassword() const
{
	return password;
}

float RegisteredUser::getmaintainenceTAX() const{
	return maintainenceTAX;
}

//unsigned int RegisteredUser::getVehicle() const {
//	return vehicleID;
//}

vector<User*> RegisteredUser::getBuddies() const{
	return friends;
}

ostream& operator<<(ostream& os, const RegisteredUser* RU)
{
	os << RU->getid() << endl << RU->getusername() << endl << RU->getpassword() << endl;
	return os;
}

void RegisteredUser::setVehicle(Vehicle* car)  {
	this->vehicle = (*car);
}

Vehicle RegisteredUser::getVehicle() const {
	return this->vehicle;
}







////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}

