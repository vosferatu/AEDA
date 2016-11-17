#include "Shared_Rides.h"
#include "User.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle>SharedRides::cars(0);
vector<string>SharedRides::cities(0);

const string SharedRides::citiesfile = "cities.txt";

unsigned int  SharedRides::numbercities = 0;

void SharedRides::load()
{
	loadCities();
	//loadUsers();
	//loadAnuncios();
	//loadBoleias();
}

void SharedRides::loadCities() {

	fstream file;

	string info;					//string que ira conter a informacao de cada linha do ficheiro
	string strnumber;					//string que ira remover o numero no inicio do ficheiro
	
	
	file.open(citiesfile);
	
	if (!file.is_open())
	{
		throw FileException<string>("Erro ao abrir o ficheiro de cidades.");
	}

	getline(file, strnumber);
	numbercities = stoi(strnumber);

	while (getline(file, info))
	{
		cities.push_back(info);
	}

	
}

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

	//gets city

	bool citybelong = false;

	
	while (!citybelong) {
		string city;

		
		

		cout << "Please specify your home city." << endl << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size()-1)
			cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		
		getline(cin, city); 
		cin.clear();
		cin.ignore(1000, '\n');
				
		for (size_t i = 0; i < cities.size(); i++)
		{
			if (city == cities[i])
				citybelong = true;
		}
	}


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

			Vehicle v1(seats, brand, year, rate);

			RegisteredUser* RU = new RegisteredUser(username, password1,v1);
			
			(*RU).getVehicle().setId((*RU).getid());

			users.push_back(RU);
			cars.push_back((*RU).getVehicle());
			vehiclebool = true;
		}

		else if (addvehicle == "n") {
			Vehicle nocar;
			
			RegisteredUser* RU = new RegisteredUser(username, password1, nocar);

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

User* SharedRides::login(const string &username, const string &password) {
	for (size_t i = 0; i < users.size(); ++i) {
			if (users[i]->getusername == username){
				if (users[i]->getpassword() == password)
					return users[i];
				else throw LoginException<string>("Password errada.");
			}
			else throw LoginException<string>("Username inexistente.");
	}
}

void SharedRides::saveUsers() const {

	ofstream myfile;
	myfile.open("users.txt");  // in the users.txt file
	 
	myfile << users.size();

	for (size_t i = 0; i < users.size(); i++)
	{
		myfile << users[i];
	}

	myfile.close();

}

void SharedRides::run() {
	
	try {
		load();
		main_menu();
	}
	catch (FileException<string> err){
		cout << "Erro: " << err.info << endl;
	}
}
