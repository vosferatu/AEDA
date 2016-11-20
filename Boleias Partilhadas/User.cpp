#include "User.h"
#include "Helper.h"
#include <string>


using namespace std;

unsigned int User::idstatic = 1;



//////////////////////////////////////////////////// USER - GENERAL CLASS //////////////////////////////////////////////////////////

User::User(string username) {
	this->username = username;
	this->id = idstatic;
	idstatic++;
}


string User::getusername() const {
	return username;
}


unsigned int User::getID() const {
	return id; 
}

float User::getAccount() const{
	return account;
}

void User::chargeAccount(float addition){
	account = account + addition;
}

/////////////////////////////////////////////////// REGISTERED USER /////////////////////////////////////////////////////

RegisteredUser::RegisteredUser(string username, string password, string city, Vehicle* car) : User(username), vehicle(car){
	this->password = password;
	this->homeCity = city;
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

void RegisteredUser::addTrip(unsigned int ID){
	Trips.push_back(ID);
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
	os << RU->getID() << endl << RU->getusername() << endl << RU->getpassword() << endl << RU->getCity() << endl;
	return os;
}

void RegisteredUser::setVehicle(Vehicle* car)  {
	this->vehicle = car;
}

void RegisteredUser::save(ofstream& out) const {
	out << this->getID() << ";" << this->getusername() << ";" << this->getpassword() << ";" << this->getCity() << endl;
}

void RegisteredUser::setVehicleID(unsigned int id) {
	this->vehicle->setId(id);
}





////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}



