#include "Shared_Rides.h"
#include "User.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle>SharedRides::cars(0);



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