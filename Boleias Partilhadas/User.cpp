#include "User.h"
#include "Helper.h"
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


unsigned int User::getid() const {
	return id; 
}

float User::getAccount() const{
	return account;
}

void User::chargeAccount(float addition){
	account = account + addition;
}

/////////////////////////////////////////////////// REGISTERED USER /////////////////////////////////////////////////////

RegisteredUser::RegisteredUser(string username, string password, Vehicle* car) : User(username), vehicle(car){
	this->password = password;
}

string RegisteredUser::getpassword() const
{
	return password;
}

vector<int> RegisteredUser::getTrips() const {
	return Trips;
}

unsigned int RegisteredUser::getnumTrips() const {
	return Trips.size();
}

string RegisteredUser::getCity() const {
	return homeCity;
}

Vehicle* RegisteredUser::getVehicle() const {
	return vehicle;
}

void RegisteredUser::setHome(string city){
	this->homeCity = city;
}

void RegisteredUser::setPassword(string password){
	this->password = password;
}

void RegisteredUser::showProfile(){
	cout << "\n\tProfile of " << this->getusername() << ":" << endl;
	cout << "Home City: " << this->getCity() << endl;
	cout << "Number of Trips: " << this->getnumTrips() << endl;
	cout << "Number of Buddies: " << this->getFavs().size() << endl;
	if (this->getVehicle()->getYear() == 0)
		cout << "Car: No." << endl;
	else cout << "Car: Yes." << endl;
}

vector<int> RegisteredUser::getFavs() const{
	return favorites;
}

ofstream& operator<<(ofstream& os, const RegisteredUser* RU) {
	os << RU->getid() << endl << RU->getusername() << endl << RU->getpassword() << endl << RU->getCity() << endl;
	return os;
}

void RegisteredUser::setVehicle(Vehicle* car)  {
	this->vehicle = car;
}





////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}



