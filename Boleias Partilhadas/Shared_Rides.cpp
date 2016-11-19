#include "Shared_Rides.h"

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle*>SharedRides::cars(0);
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

	// gets password
	string password1 = readPassword("Please enter password", true);
	cout << endl;
	string password2 = readPassword("Please re-enter password", true);

	while (password1 != password2) {
		cout << "Error! Passwords do not match." "\n\n";
		cin.clear();
		cin.ignore(10000, '\n');
		password1 = readPassword("Please enter password", true);
		cout << endl;
		password2 = readPassword("Please re-enter password", true);

	}

	//gets city
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool citybelong = false;

	while (!citybelong) {
		string city;

		cout << endl;


		cout << "Please specify your home city." << endl << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		city = readLine();

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
		addvehicle = get_input <string>("Do you want to add a vehicle? [y|n]");

		if (addvehicle == "y") {
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Please specify its brand and model." << endl;
			string brand = readLine();

			unsigned int year = get_input <unsigned int>("Please specify its year.");
			unsigned int seats = get_input <unsigned int>("Please specify the number of seats of your car.");
			char rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

			Vehicle v1(seats, brand, year, rate);

			RegisteredUser* RU = new RegisteredUser(username, password1, v1);

			RU->getVehicle()->setId(RU->getid());
			
				
		
			// adds route 
			bool routebool = false;
			string cityroute;
			string addroute;
			vector<string> rout(0);

			while (!routebool) {
				addroute = get_input <string>("Do you want do add a common route you do? [y|n]");
				
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				
				if (addroute == "y") {

					cout << "Please specify the cities of your route, separared by slash";
					cout << endl << "Example: Porto-Lisboa-Vila Real" << endl;
					cout << "It must belong to one of these : ";

					for (size_t i = 0; i < cities.size(); i++) {
						if (i < cities.size() - 1)
							cout << cities[i] << ", ";
						else cout << cities[i] << ".\n";
					}

					cityroute = readLine();
					stringstream ss(cityroute);

					while (ss.good()){
						string substr;
						getline(ss, substr, '-');
						rout.push_back(substr);
					}

					routebool = true;
					break; // -----> em vez de break, ir pa menu principal p fazer login
				}
				else if (addroute == "n") {
					routebool = true;
					break; // -----> em vez de break, ir pa menu principal p fazer login
				}
				else
					cout << "\nPlease insert \"y\" or \"n.\" \n";
					routebool = false;
			}

			RU->getVehicle()->setRoute(rout);

			users.push_back(RU);
			cars.push_back((*RU).getVehicle());
			vehiclebool = true;
		}

		else if (addvehicle == "n") {
			Vehicle* nocar;

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

void SharedRides::showTrips(){
	if (dynamic_cast<RegisteredUser*>(currentUser) == NULL) {
		cout << endl << "Not available!" << endl;
		return;
	}

	if (currentUser->getnumTrips() == 0) {
		cout << endl << "You have no trips in your history!" << endl;
	}

	vector<int> vec = currentUser->getTrips();
	cout << "\tYour Trip History:" << endl << endl;
	for (size_t i = 0; i < vec.size(); i++){
		for (size_t j = 0; j < tripsPrinter.size(); j++) {
			if (tripsPrinter[j].getTripCode() == vec[i]) {
				cout << "Trip number " << i+1 << endl;
				cout << tripsPrinter[j] << endl;
				break;
			}
		}
	}
}

void SharedRides::userWithVehicleMenu() {
	cout << endl << "Your Vehicle:" << endl;
	cout << currentUser->getVehicle << endl;

	int choice = get_input <int>(
		"[0] Edit my Vehicle" "\n"
		"[1] Remove my Vehicle" "\n");

	switch (choice) {
	case 1:
		editVehicle();
		break;
	case 2:
		removeVehicle();
		break;
	}
}

void SharedRides::editVehicle(){
	int choice = get_input <int>(
		"[0] Change whole Vehicle" "\n"
		"[1] Change Route" "\n");

	switch (choice) {
	case 1: {
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << "Please specify its brand and model." << endl;
		string brand = readLine();

		unsigned int year = get_input <unsigned int>("Please specify its year.");
		unsigned int seats = get_input <unsigned int>("Please specify the number of seats of your car.");
		char rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

		currentUser->getVehicle()->setRate(rate);
		currentUser->getVehicle()->setYear(year);
		currentUser->getVehicle()->setSeats(seats);
		currentUser->getVehicle()->setBrand(brand);
		currentUser->getVehicle()->setId(currentUser->getid());
		// adds route 
		string cityroute;
		vector<string> rout(0);

		cout << "Now, enter your new route." << endl;
		cout << "Please specify the cities of your route, separared by slash";
		cout << endl << "Example: Porto-Lisboa-Vila Real" << endl;
		cout << "It must belong to one of these : ";
		for (size_t i = 0; i < cities.size(); i++) {
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}
		cityroute = readLine();
		stringstream ss(cityroute);

		while (ss.good()) {
			string substr;
			getline(ss, substr, '-');
			rout.push_back(substr);
		}
		currentUser->getVehicle()->setRoute(rout);

		for (size_t i = 0; i < cars.size(); i++) {
			if (cars[i]->getCarID() == currentUser->getid()) {
				cars[i] = currentUser->getVehicle();
				break;
			}
		}

	}		
		break;
	case 2:
		string cityroute;
		vector<string> rout(0);
		cout << "Please specify the cities of your route, separared by slash";
		cout << endl << "Example: Porto-Lisboa-Vila Real" << endl;
		cout << "It must belong to one of these : ";
		for (size_t i = 0; i < cities.size(); i++) {
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}
		cityroute = readLine();
		stringstream ss(cityroute);

		while (ss.good()) {
			string substr;
			getline(ss, substr, '-');
			rout.push_back(substr);
		}
		currentUser->getVehicle()->setRoute(rout);

		for (size_t i = 0; i < cars.size(); i++) {
			if (cars[i]->getCarID() == currentUser->getid()) {
				cars[i] = currentUser->getVehicle();
				break;
			}
		}
		break;
	}
}

void SharedRides::removeVehicle(){
	string remvehicle;

	while (true){
		remvehicle = get_input <string>("Do you want to remove your vehicle? [y|n]");
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (remvehicle == "y") {
			Vehicle* v1;
			currentUser->getVehicle()->setVehicle(v1);
			for (size_t i = 0; i < cars.size(); i++) {
				if (cars[i]->getCarID() == currentUser->getid()) {
					cars.erase(cars.begin()+i);
					break;
				}
			}
			break;
		}

		if (remvehicle == "n") {
			cout << "Getting back..." << endl;
			break;
		}
		else cout << "Error! Please enter y or n." << endl;
	}

	return;
}

void SharedRides::addVehicle() {
	cout << "Please specify its brand and model." << endl;
	string brand = readLine();

	unsigned int year = get_input <unsigned int>("Please specify its year.");
	unsigned int seats = get_input <unsigned int>("Please specify the number of seats of your car.");
	char rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

	currentUser->getVehicle()->setRate(rate);
	currentUser->getVehicle()->setYear(year);
	currentUser->getVehicle()->setSeats(seats);
	currentUser->getVehicle()->setBrand(brand);
	currentUser->getVehicle()->setId(currentUser->getid());
	// adds route 
	string cityroute;
	vector<string> rout(0);

	cout << "Now, enter your new route." << endl;
	cout << "Please specify the cities of your route, separared by slash";
	cout << endl << "Example: Porto-Lisboa-Vila Real" << endl;
	cout << "It must belong to one of these : ";
	for (size_t i = 0; i < cities.size(); i++) {
		if (i < cities.size() - 1)
			cout << cities[i] << ", ";
		else cout << cities[i] << ".\n";
	}
	cityroute = readLine();
	stringstream ss(cityroute);

	while (ss.good()) {
		string substr;
		getline(ss, substr, '-');
		rout.push_back(substr);
	}
	currentUser->getVehicle()->setRoute(rout);

	cars.push_back(currentUser->getVehicle());
}

User* SharedRides::login(const string &username, const string &password) {
	for (size_t i = 0; i < users.size(); ++i) {
			if (users[i]->getusername() == username){
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

void SharedRides::saveVehicles() const {

	ofstream myfile;
	myfile.open("vehicles.txt");  // in the users.txt file

	myfile << cars.size();

	for (size_t i = 0; i < cars.size(); i++)
	{
		myfile << cars[i];
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
	//save(); //para guardar nos ficheiros as alterações
	return;
}

