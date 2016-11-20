#include "Shared_Rides.h"

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle>SharedRides::cars(0);
vector<string>SharedRides::cities(0);

const string SharedRides::citiesfile = "cities.txt";
const string SharedRides::usersfile = "users.txt";
const string SharedRides::carsfile = "cars.txt";

unsigned int SharedRides::maxUsersID = 0;
unsigned int SharedRides::maxVehiclesID = 0;


unsigned int  SharedRides::numbercities = 0;

bool SharedRides::usersalterados = false;
bool SharedRides::carsalterados = false;


//void SharedRides::loadUsers() {
//
//	fstream file;
//
//	string info;					//string que ira conter a informacao de cada linha do ficheiro
//	string strnumber;					//string que ira remover o numero no inicio do ficheiro
//
//
//	file.open(usersfile);
//
//	if (!file.is_open())
//	{
//		throw FileException<string>("Error opening users file");
//	}
//
//	getline(file, strnumber);
//	maxUsersID = stoi(strnumber);
//
//	while (getline(file, info))
//	{
//		unsigned int search = 10000;
//
//		size_t findpos = info.find(';', 0);
//		unsigned int id = stoul(info.substr(0, findpos - 1).c_str());
//		
//		info = info.substr(findpos + 1, search);			//string = desde inicio ate primeiro ';'
//		findpos = info.find(';', 0);
//
//		string name = 
//
//
//	}
//
//
//}
void SharedRides::loadVehicles() {

	ifstream infile(carsfile);

	if (infile.peek() == std::ifstream::traits_type::eof())
		return;
	
	string info;					//string que ira conter a informacao de cada linha do ficheiro
	string strnumber;					//string que ira remover o numero no inicio do ficheiro

	if (!infile.is_open())
	{
		throw FileException<string>("ERROR! The Vehicles file could not be opened.");
	}

	getline(infile, strnumber);
	maxVehiclesID = stoi(strnumber);

	while (getline(infile, info))
	{
		unsigned int search = 1000;
		Vehicle car;

		size_t findpos = info.find(';', 0);			//inteiro que tem a posicao do primeiro ';'

		car.setId(stoul(info.substr(0, findpos).c_str()));  //id = à string desde o inicio ate ';' transformada em unsigned int
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'

		car.setBrand(info.substr(0, findpos));
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do terceiro ';'

		car.setYear(stoul(info.substr(0, findpos).c_str()));
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		car.setRate(info.substr(0, findpos));
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);

		vector<string> route;

		
		while (findpos != -1) {
			route.push_back(info.substr(0, findpos));
			info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
			findpos = info.find(';', 0);
		}

		car.setRoute(route);
		cars.push_back(car);

		
		
	}


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
	unsigned int i=0;

	while (i < numbercities)
	{
		getline(file, info);
		cities.push_back(info);
		i++;
	}

	
}

void SharedRides::load() {
	loadCities();
	//loadUsers();
	loadVehicles();
}
void SharedRides::CreateRegis()
{

	// gets username
	bool userexists = true;
	string username;
	
	while (userexists) {
		username = get_input <string>("Please enter a username.");
		cout << "Username: " << username << "\n";
		
		if (users.size() == 0)
			userexists = false;
		
		bool uservec = false; 

		for (size_t i = 0; i < users.size(); i++) {
			if (users[i]->getusername() == username) 
				uservec = true;
		}

		if (uservec == true)
		{
			cout << "Username already exists!\n";
			userexists = true;
		}
		else userexists = false;

		
	}

	// gets password
	string password1 = readPassword("Please enter password", true);
	cout << endl;
	string password2 = readPassword("Please re-enter password", true);

	while (password1 != password2) {
		cout << "\nError! Passwords do not match." "\n\n";
		password1 = readPassword("Please enter password", true);
		cout << endl;
		password2 = readPassword("Please re-enter password", true);

	}

	//gets city
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool citybelong = false;
	string city;

	while(!citybelong) {
		cout << endl;
		
		cout << "Please specify your home city." << endl << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		city = readLine();

		for (size_t i = 0; i < cities.size(); i++){
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

			bool goodyear = false;
			unsigned int year;

			while (!goodyear) {
				year = get_input <unsigned int>("Please specify its year.");

				if (year < 1901 || year > 2017) {
					goodyear = false;
					cout << "\nError! Invalid year. \n\n";
				}

				else goodyear = true;
			}

			bool goodseats=false;
			unsigned int seats;
			while (!goodseats) {
				seats = get_input <unsigned int>("Please specify the number of seats of your car, including yours. [2|5|9]");
				if (seats != 2 && seats != 5 && seats != 9)
				{
					cout << "\nError! The number of seats you provided is not valid.\n";
					goodseats = false;
				}
				else goodseats = true;
			}

			bool goodrate = false;
			string rate;
			while (!goodrate) {
				rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");
			
				if (rate != "A" && rate != "B" && rate != "C" && rate != "D" && rate != "E" && rate != "F")
				{
					cout << "\nError! Please give an evaluation in the provided scale.\n";
					goodrate = false;
				}
				else goodrate = true;
			}
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

					//bool total = false;
					//for (size_t i = 0; i < rout.size(); i++) {
					//	if (!total) {
					//		for (size_t j = 0; j < cities.size(); j++) { // vetor principal 
					//			if (cities[j] == rout[i])
					//				break;                           // se encontrou para 
					//			else if (j = cities.size() - 1) {		   //se chegou ao fim sem encontrar, é porque
					//				total = true;					// o elemento nao foi encontrado
					//				break;
					//			}
					//		}
					//	}
					//	else break;
					//}

					//if (total)
					//	cout << "\nError! One of entered cities doesn't belong to supported ones.\n";
					//else { routebool = true; break; }

					routebool = true;
					break;
					
					 
				}
				else if (addroute == "n") {
					routebool = true;
					break; 
				}
				else
					cout << "\nPlease insert \"y\" or \"n.\" \n";
					routebool = false;
			}

			Vehicle v1(seats, brand, year, rate);
			v1.setRoute(rout);
			maxVehiclesID++;

			RegisteredUser* RU = new RegisteredUser(username, password1, city, v1);
			maxUsersID++;
			
			(*RU).setVehicleID((*RU).getID());

			users.push_back(RU);
			cars.push_back((*RU).getVehicle());
			usersalterados = true;
			carsalterados = true;
			vehiclebool = true;
		}

		else if (addvehicle == "n") {
			Vehicle nocar;

			RegisteredUser* RU = new RegisteredUser(username, password1,city, nocar);

			users.push_back(RU);
			usersalterados = true;
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
			if (users[i]->getusername() == username) {
				if (users[i]->getpassword() == password) 
					return users[i];
			}
		}

	throw LoginException<string>("\nInvalid combination of username/password. Please try again.\n");
}


void SharedRides::saveChanges() const {

	if (carsalterados)    //se a flag foi posta a true
	{
		ofstream out_cars(carsfile, ios::trunc);   //declaracao do ficheiro para escrita

		out_cars << getCARHighID() << endl;

		for (size_t i = 0; i < cars.size(); i++)		
		{
			cars.at(i).save(out_cars);  
		}
		out_cars.close();
	}

	if (usersalterados)    //se a flag foi posta a true
	{
		ofstream out_users(usersfile, ios::trunc);   //declaracao do ficheiro para escrita

		out_users << getUSERHighID() << endl;

		for (size_t i = 0; i < users.size(); i++)    
		{
			users[i]->save(out_users);   //funcao save da classe
		}
		out_users.close();
	}
}

void SharedRides::run() {
	
	try {
		load();
		
		for (size_t i = 0; i < cars.size(); i++)
		{
			cout << cars[i] << endl;
		}

		main_menu();
		saveChanges();
	}
	catch (FileException<string> err){
		cout << "Erro: " << err.info << endl;
	}
}


unsigned int SharedRides::getCARHighID() const {

	unsigned int maiorID = 0;

	for (size_t i = 0; i < cars.size(); i++)		
	{
		unsigned int ID = cars.at(i).getID();	
																
		if (ID > maiorID)								
			maiorID = ID;						
	}

	return maiorID;
}

unsigned int SharedRides::getUSERHighID() const {

	unsigned int maiorID = 0;

	for (size_t i = 0; i < users.size(); i++)
	{
		unsigned int ID = users.at(i)->getID();

		if (ID > maiorID)
			maiorID = ID;
	}

	return maiorID;
}