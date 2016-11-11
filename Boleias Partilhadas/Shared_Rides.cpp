#include "Shared_Rides.h"
#include "User.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<User*> clientes(0);





void SharedRides::CreateRegis()
{

	// gets username
	string username = get_input <string>("Please enter a username.");
	cout << "Username: " << username << "\n";

	while (get_input <int>("Confirm? [0|1]") != 1) {
		username = get_input <string>("Please enter a username.");
		cout << "Username: \"" << username << "\"\n";
	}
	// gets password
	string password1 = get_input <string>("Please enter your password.");
	string password2 = get_input <string>("Please re-enter your password.");

	while (password1 != password2) {
		cout << "Error! Passwords do not match." "\n";
		password1 = get_input <string>("Please enter your password.");
		password2 = get_input <string>("Please re-enter your password.");
	}

	// saving the user
	
	
	RegisteredUser* RU = new RegisteredUser(username,password1);

	clientes.push_back(RU); // in a vector 
	
	ofstream myfile;
	myfile.open("users.txt");  // in the users.txt file
	myfile << RU;
	myfile.close();
		
}