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

vector<int> RegisteredUser::getTrips() const {
	return Trips;
}

unsigned int RegisteredUser::getnumTrips() const {
	return Trips.size();
}

string RegisteredUser::getCity() const {
	return homeCity;
}

//unsigned int RegisteredUser::getVehicle() const {
//	return vehicleID;
//}

vector<int> RegisteredUser::getBuddies() const{
	return friends;
}

void RegisteredUser::menu(){

	if (vehicle.getnumberSeats() != 0) {
		int choice = get_input <int>(
			"[0] My Trips" "\n"
			"[1] Vehicle" "\n"  //add/remove/edit vehicle inside
			"[2] New Trip" "\n"     // add/start trip (start begins an added trip) inside
			"[3] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
			"[4] Charge wallet" "\n"
			"[5] Change password" "\n"
			"[6] Log Off" "\n"
			"[7] Delete Profile");



		switch (choice) {
		case 1:
			//login();
			break;
		case 2:
			//SharedRides::CreateRegis();
			break;
		}
	}
	else {
		int choice = get_input <int>(
			"[0] My Trips" "\n"
			"[1] New Trip" "\n"     // look for a trip
			"[2] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
			"[3] Charge wallet" "\n"
			"[4] Log Off" "\n"
			"[5] Change password" "\n"
			"[6] Delete Profile");



		switch (choice) {
		case 1:
			//login();
			break;
		case 2:
			//SharedRides::CreateRegis();
			break;
		}
	}
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

void GuestUser::menu(){
	int choice = get_input <int>(
		"[0] New Trip" "\n"     // look for a trip
		"[1] Charge wallet" "\n"
		"[3] Delete Profile");



	switch (choice) {
	case 1:
		//login();
		break;
	case 2:
		//SharedRides::CreateRegis();
		break;
	}
}

