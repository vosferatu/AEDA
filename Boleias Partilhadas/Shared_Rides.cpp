#include "Shared_Rides.h"
#include "User.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<User*> SharedRides::users(0);





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
		string password1 = readPassword("Please enter password",true);
		string password2 = readPassword("Please re-enter password", true);
	


	while (password1 != password2) {
		cout << "Error! Passwords do not match." "\n\n";
		cin.clear();
		cin.ignore(10000, '\n');
		password1 = readPassword("Please enter password", true);
		cout << "|" << password1 << "|" << endl;
		password2 = readPassword("Please re-enter password", true);
		cout << "|" << password2 << "|" << endl;

	// gets vehicle


	//	if (get_input <string>("Do you want to add a vehicle?") == "y") 
	//	{
			//Vehicle v1;
			//v1.settype() = get_input <string>("Please specify its brand and model.");
			//v1.setyear() = get_input <unsigned int> ("Please specify its year.");
			//v1.setavaibleseats() = get_input <unsigned int>("Please specify the number of seats of your car.");
		
		//}



	}

	// saving the user
	
	
	RegisteredUser* RU = new RegisteredUser(username,password1);

	users.push_back(RU); // in a vector 
	
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