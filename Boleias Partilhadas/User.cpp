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
	cout << endl;
	cout <<TAB<< "Name: " << this->getusername()<< endl;
	cout <<TAB<< "Home City: " << this->getCity() << endl;
	cout <<TAB<< "Number of Trips: " << this->getnumTrips() << endl;
	cout <<TAB << "Number of Buddies: " << this->getFavs().size() << endl;
	if (this->getVehicle()->getYear() == 0)
		cout <<TAB<< "This user does not have a car associated to his account." << endl;
	else cout <<TAB<< "This user has a " << this->getVehicle()->getBrand() << " associated to his account." << endl;
}

vector<int> RegisteredUser::getFavs() const{
	return favorites;
}
void User::setAccount(float account) {
	this->account = account;
}

ofstream& operator<<(ofstream& os, const RegisteredUser* RU) {
	os << RU->getID() << endl << RU->getusername() << endl << RU->getpassword() << endl << RU->getCity() << endl;
	return os;
}

void RegisteredUser::setVehicle(Vehicle* car)  {
	this->vehicle = car;
}


void RegisteredUser::setTrips(vector<int> trips) {
	this->Trips = trips;
}

void RegisteredUser::setFavs(vector<int> favs) {
	this->favorites = favs;
}

void RegisteredUser::save(ofstream& out) const {
	out << this->getID() << ";" << this->getusername() << ";" << this->getpassword() << ";" << this->getAccount() << ";" << this->getCity() << ";";

	if (Trips.size() == 0)
		out << this->Trips.size() << ";";
	else {
		out << this->Trips.size() << ";";

		for (size_t i = 0; i < this->Trips.size(); i++) {
		out << this->Trips[i] << ";";
		}
	}

	if (favorites.size() == 0)
		out << this->favorites.size() << ";" << endl;
	else {
		out << this->favorites.size() << ";";

		for (size_t i = 0; i < this->favorites.size(); i++){
			
			if (i < favorites.size() - 1)
				out << this->favorites[i] << ";";
			else if (i == favorites.size() - 1)
				out << this->favorites[i] << endl;
			
		}
	}
}

void RegisteredUser::setVehicleID(unsigned int id) {
	this->vehicle->setId(id);
}





////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}



