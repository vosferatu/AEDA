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

float RegisteredUser::getmaintainenceTAX() const{
	return maintainenceTAX;
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
void User::setAccount(float account) {
	this->account = account;
}

ostream& operator<<(ostream& os, const RegisteredUser* RU) {
	os << "|" << (*RU).getID() << "|" << endl << (*RU).getusername() << "|" << endl << "|" << (*RU).getpassword() << "|" << endl << "|" << (*RU).getCity() << "|" << endl;
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

	for (size_t i = 0; i < this->Trips.size(); i++)
	{
		out << this->Trips.size() << ";";
		out << this->Trips[i] << ";";
	}

	if (favorites.size() == 0)
		out << this->favorites.size() << ";";

	for (size_t i = 0; i < this->favorites.size(); i++)
	{
		out << this->favorites.size() << ";";
		out << this->favorites[i] << ";";
	}
}

void RegisteredUser::setVehicleID(unsigned int id) {
	this->vehicle->setId(id);
}





////////////////////////////////////////////////// GUEST USER /////////////////////////////////////////////////////////////

GuestUser::GuestUser(string username) : User(username) {
}



