#include "Shared_Rides.h"
#include "User.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle>SharedRides::cars(0);
vector<takenTrip>SharedRides::tripsPrinter(0);
vector<waitingTrip>SharedRides::tripOffers(0);
vector<Path>SharedRides::caminhos(0);



void SharedRides::CreateRegis()
{

	// gets username
	string username = get_input <string>("Please enter a username.");
	cout << "Username: " << username << "\n";

	while (get_input <string>("Confirm? [y|n]") != "y") {
		username = get_input <string>("Please enter a username.");
		cout << "Username: \"" << username << "\"\n";
	}

	// gets password
	string password1 = readPassword("Please enter password", true);
	string password2 = readPassword("Please re-enter password", true);

	while (password1 != password2) {
		cout << "Error! Passwords do not match." "\n\n";
		cin.clear();
		cin.ignore(10000, '\n');
		password1 = readPassword("Please enter password", true);
		password2 = readPassword("Please re-enter password", true);
	}

	RegisteredUser* RU = new RegisteredUser(username, password1);

	// gets vehicle
	bool vehiclebool = false; 
	string addvehicle;


	while (!vehiclebool)
	{
		addvehicle = get_input <string>("Do you want to add a vehicle?");
				
		if (addvehicle == "y")
		{
			cout << "Please specify its brand and model." << endl;
			string brand = readLine();
			
			unsigned int year = get_input <unsigned int>("Please specify its year.");
			unsigned int seats = get_input <unsigned int>("Please specify the number of seats of your car.");
			char rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

			Vehicle v1((*RU).getid(), seats, brand, year, rate);

			(*RU).setVehicle(&v1);

			users.push_back(RU);
			cars.push_back((*RU).getVehicle());
			vehiclebool = true;
		}

		else if (addvehicle == "n") {
			Vehicle nocar;
			(*RU).setVehicle(&nocar);
			users.push_back(RU);
			vehiclebool = true;
		}
		else
		{
			cout << "Error! Please enter y or n." << endl;
			vehiclebool = false;
		}

	}
}

void SharedRides::main_menu(){
	int choice = get_input <int>(
		"[0] Enter as guest" "\n"
		"[1] Login" "\n"
		"[2] Register" "\n"
		"[3] Manage App" "\n"
		"[4] Exit");



	switch (choice) {
	case 0:
		//criar um menu de login sem password para guest
		user_menu();//chama o menu de user (la dentro escolhe menu de guest)
		break;
	case 1:
		//login(); //login, se for aceite, muda o currentuser
		user_menu(); //chama o menu de user(Seja ele carro, sem carro)
		break;
	case 2:
		CreateRegis();
		main_menu();
		break;
	case 3:
		manage_menu();
		break;
	case 4:
		return;
	default:
		break;
	}
}

void SharedRides::manage_menu(){
	//por aqui função que pede login com username admin e password admin
	int choice = get_input <int>(
		"[0] App Trips" "\n"   //nestes 3 podemos usar os algoritmos de pesquisa para ver um x 
		"[1] App Users" "\n"	//algoritmos de ordenação para mostrar
		"[2] App Vehicles" "\n"
		"[3] End of Month" "\n"
		"[4] Remove user" "\n"
		"[3] Exit");



	switch (choice) {
	case 1:
		//login();
		break;
	case 2:
		//SharedRides::CreateRegis();
		break;
	}
}

void SharedRides::user_menu(){
	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) {//isto da erro porque nao temos uma
		//função virtual em user, mas vamos ter, por isso deixa assim

		if (currentUser.vehicle.getnumberSeats() != 0) {
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
				//main_menu();
				break;
			case 2:
				//SharedRides::CreateRegis();
				break;
			}
		}

	}
	else {

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
}







//void SharedRides::saveUsers() const {
//
//	ofstream myfile;
//	myfile.open("users.txt");  // in the users.txt file
//	 
//	myfile << users.size();
//
//	for (size_t i = 0; i < users.size(); i++)
//	{
//		myfile << users[i];
//	}
//
//	myfile.close();
//
//}