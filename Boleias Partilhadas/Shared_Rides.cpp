#include "Shared_Rides.h"
#include <algorithm>

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle*>SharedRides::cars(0);
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

		car.setId(stoul(info.substr(0, findpos).c_str()));  //id = � string desde o inicio ate ';' transformada em unsigned int
		info = info.substr(findpos + 1, search);			//string = desde findpos at� ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro � a posicao na string do segundo ';'

		car.setBrand(info.substr(0, findpos));
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' at� ao segundo
		findpos = info.find(';', 0);					//agora o inteiro � a posicao na string do terceiro ';'

		car.setYear(stoul(info.substr(0, findpos).c_str()));
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		car.setRate(info.substr(0, findpos));
		info = info.substr(findpos + 1, search);			//string = desde findpos at� ao resto da  string
		findpos = info.find(';', 0);

		vector<string> route;

		
		while (findpos != -1) {
			route.push_back(info.substr(0, findpos));
			info = info.substr(findpos + 1, search);			//string = desde findpos at� ao resto da  string
			findpos = info.find(';', 0);
		}

		car.setRoute(route);
		Vehicle * v1 = &car;
		cars.push_back(v1);

		
		
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
					//			else if (j == cities.size() - 1) {		   //se chegou ao fim sem encontrar, � porque
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
			Vehicle* v2 = &v1;
			RegisteredUser* RU = new RegisteredUser(username, password1, city, v2);
			maxUsersID++;
			RU->getVehicle()->setId(RU->getID());
			

			users.push_back(RU);
			cars.push_back((*RU).getVehicle());
			usersalterados = true;
			carsalterados = true;
			vehiclebool = true;
		}

		else if (addvehicle == "n") {
			Vehicle* nocar = new Vehicle();

			RegisteredUser* RU = new RegisteredUser(username, password1, city, nocar);

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
	cout << endl << "Now you have to Login to confirm your account.\n";
}

void SharedRides::fillPaths(){
	//Braga Porto Vila Real Aveiro Viseu Lisboa Faro Beja
	Path p1("Braga", "Porto", Time(0, 40)); caminhos.push_back(p1);
	Path p2("Braga", "Vila Real", Time(1, 10)); caminhos.push_back(p2);
	Path p3("Braga", "Aveiro", Time(1, 17)); caminhos.push_back(p3);
	Path p4("Braga", "Viseu", Time(1, 48)); caminhos.push_back(p4);
	Path p5("Braga", "Lisboa", Time(3, 23)); caminhos.push_back(p5);
	Path p6("Braga", "Faro", Time(5, 12)); caminhos.push_back(p6);
	Path p7("Braga", "Beja", Time(4, 34)); caminhos.push_back(p7);

	Path p8("Porto", "Braga", Time(0, 40)); caminhos.push_back(p8);
	Path p9("Porto", "Vila Real", Time(1, 7)); caminhos.push_back(p9);
	Path p10("Porto", "Aveiro", Time(0, 48)); caminhos.push_back(p10);
	Path p11("Porto", "Viseu", Time(1, 18)); caminhos.push_back(p11);
	Path p12("Porto", "Lisboa", Time(2, 53)); caminhos.push_back(p12);
	Path p13("Porto", "Faro", Time(4, 42)); caminhos.push_back(p13);
	Path p14("Porto", "Beja", Time(4, 5)); caminhos.push_back(p14);

	Path p15("Vila Real", "Porto", Time(1, 7)); caminhos.push_back(p15);
	Path p16("Vila Real", "Braga", Time(1, 10)); caminhos.push_back(p16);
	Path p17("Vila Real", "Aveiro", Time(1, 38)); caminhos.push_back(p17);
	Path p18("Vila Real", "Viseu", Time(1, 6)); caminhos.push_back(p18);
	Path p19("Vila Real", "Lisboa", Time(3, 44)); caminhos.push_back(p19);
	Path p20("Vila Real", "Faro", Time(5, 33)); caminhos.push_back(p20);
	Path p21("Vila Real", "Beja", Time(4, 55)); caminhos.push_back(p21);

	Path p22("Aveiro", "Porto", Time(0, 48)); caminhos.push_back(p22);
	Path p23("Aveiro", "Vila Real", Time(1, 38)); caminhos.push_back(p23);
	Path p24("Aveiro", "Braga", Time(1, 17)); caminhos.push_back(p24);
	Path p25("Aveiro", "Viseu", Time(0, 57)); caminhos.push_back(p25);
	Path p26("Aveiro", "Lisboa", Time(2, 28)); caminhos.push_back(p26);
	Path p27("Aveiro", "Faro", Time(4, 16)); caminhos.push_back(p27);
	Path p28("Aveiro", "Beja", Time(3, 39)); caminhos.push_back(p28);
	
	Path p29("Viseu", "Porto", Time(1, 18)); caminhos.push_back(p29);
	Path p30("Viseu", "Vila Real", Time(1, 6)); caminhos.push_back(p30);
	Path p31("Viseu", "Aveiro", Time(0, 57)); caminhos.push_back(p31);
	Path p32("Viseu", "Braga", Time(1, 48)); caminhos.push_back(p32);
	Path p33("Viseu", "Lisboa", Time(2, 56)); caminhos.push_back(p33);
	Path p34("Viseu", "Faro", Time(4, 45)); caminhos.push_back(p34);
	Path p35("Viseu", "Beja", Time(4, 7)); caminhos.push_back(p35);

	Path p36("Lisboa", "Porto", Time(2, 53)); caminhos.push_back(p36);
	Path p37("Lisboa", "Vila Real", Time(3, 44)); caminhos.push_back(p37);
	Path p38("Lisboa", "Aveiro", Time(2, 28)); caminhos.push_back(p38);
	Path p39("Lisboa", "Viseu", Time(2, 56)); caminhos.push_back(p39);
	Path p40("Lisboa", "Braga", Time(3, 23)); caminhos.push_back(p40);
	Path p41("Lisboa", "Faro", Time(2, 32)); caminhos.push_back(p41);
	Path p42("Lisboa", "Beja", Time(1, 55)); caminhos.push_back(p42);

	Path p43("Faro", "Porto", Time(4, 42)); caminhos.push_back(p43);
	Path p44("Faro", "Vila Real", Time(5, 33)); caminhos.push_back(p44);
	Path p45("Faro", "Aveiro", Time(4, 16)); caminhos.push_back(p45);
	Path p46("Faro", "Viseu", Time(4, 45)); caminhos.push_back(p46);
	Path p47("Faro", "Lisboa", Time(2, 32)); caminhos.push_back(p47);
	Path p48("Faro", "Braga", Time(5, 12)); caminhos.push_back(p48);
	Path p49("Faro", "Beja", Time(1, 35)); caminhos.push_back(p49);

	Path p50("Beja", "Porto", Time(4, 5)); caminhos.push_back(p50);
	Path p51("Beja", "Vila Real", Time(4, 55)); caminhos.push_back(p51);
	Path p52("Beja", "Aveiro", Time(3, 39)); caminhos.push_back(p52);
	Path p53("Beja", "Viseu", Time(4, 7)); caminhos.push_back(p53);
	Path p54("Beja", "Lisboa", Time(1, 55)); caminhos.push_back(p54);
	Path p55("Beja", "Braga", Time(4, 34)); caminhos.push_back(p55);
	Path p56("Beja", "Faro", Time(1, 35)); caminhos.push_back(p56);
}

int SharedRides::getPositionCar(unsigned int id) const{
	int position = -1;
	for (size_t i = 0; i < cars.size(); i++) {
		if (cars[i]->getID() == id) {
			position = i;
			return position;
		}	
	}
	return position;
}

int SharedRides::getPositionUser(unsigned int id) const{
	int position = -1;
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i]->getID() == id) {
			position = i;
			return position;
		}
	}
	return position;
}

void SharedRides::recompensate(unsigned int id){
	vector<int> afetados{};
	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() == id) {
			for (size_t j = 0; j < tripOffers[i].getWay().size(); j++) {
				for (size_t k = 0; k < tripOffers[i].getWay()[j].getusers().size(); k++) {
					afetados.push_back(tripOffers[i].getWay()[j].getusers()[k]);
				}
			}
		}
	}

	sort(afetados.begin(), afetados.end());//do menor para o maior
	afetados.erase(unique(afetados.begin(), afetados.end()), afetados.end());
	//remove todos os elementos para alem da primeira aparicao
	//agora temos de recompensar esses users pela viagem que pagram e n�o v�o fazer
	//estabelecemos 5$ como valor a recompensar

	for (size_t i = 0; i < afetados.size(); i++) {
		size_t j = getPositionUser(afetados[i]);
		users[j]->chargeAccount(5.0);
	}
	cout << endl << "Users who payed for your vehicle's trips where recompensated with 5$.\n";
}

void SharedRides::showTrips() const{
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
	cout << currentUser->getVehicle() << endl;

	int choice = get_input <int>(
		"[0] Edit my Vehicle" "\n"
		"[1] Remove my Vehicle" "\n");

	switch (choice) {
	case 0:
		editVehicle();
		break;
	case 1:
		removeVehicle();
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		userWithVehicleMenu();
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
		string rate = get_input <string>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

		currentUser->getVehicle()->setRate(rate);
		currentUser->getVehicle()->setYear(year);
		currentUser->getVehicle()->setSeats(seats);
		currentUser->getVehicle()->setBrand(brand);
		currentUser->getVehicle()->setId(currentUser->getID());
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
			if (cars[i]->getID() == currentUser->getID()) {
				cars[i] = currentUser->getVehicle();
				break;
			}
		}

	}		
		break;
	case 2: {
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
			if (cars[i]->getID() == currentUser->getID()) {
				cars[i] = currentUser->getVehicle();
				break;
			}
		}
	}
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		editVehicle();
		break;
	}
}

void SharedRides::removeVehicle(){
	string remvehicle;

	while (true){
		remvehicle = get_input <string>("Do you want to remove your vehicle? [y|n]");
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (remvehicle == "y") {
			Vehicle* v1 = new Vehicle();
			currentUser->getVehicle()->setVehicle(v1);
			
			recompensate(currentUser->getID());
			for (size_t i = 0; i < tripOffers.size(); i++) {
				if (tripOffers[i].getOwner() == currentUser->getID()) {
					tripOffers.erase(tripOffers.begin() + i);
					i--;
				}
			}

			size_t pos = getPositionCar(currentUser->getID());
			cars.erase(cars.begin() + pos);

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
	string rate = get_input <string>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

	currentUser->getVehicle()->setRate(rate);
	currentUser->getVehicle()->setYear(year);
	currentUser->getVehicle()->setSeats(seats);
	currentUser->getVehicle()->setBrand(brand);
	currentUser->getVehicle()->setId(currentUser->getID());
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

void SharedRides::creditAccount(){
	cout << endl << "Your current balance: " << currentUser->getAccount() << "$" << endl;
	cout << "(Input 0 if you selected the wrong menu)" << endl;
	float novo = 0.0;
	while (true) {
		novo = get_input <float>("How much do you want to credit your acount?(X.Y)");
		if (novo < 0) {
			cout << "Cannot charge negative values" << endl;
			continue;
		}
		if (novo == 0)
			return;
		currentUser->chargeAccount(novo);
		break;
	}
	cout << endl << "Your new balance: " << currentUser->getAccount() << "$" << endl;
}

void SharedRides::changeProfile(){
	currentUser->showProfile();
	int choice = get_input <int>(
		"[0] Edit my Password" "\n"
		"[1] Edit my City" "\n");

	switch (choice) {
	case 0: {
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
		currentUser->setPassword(password1);
		cout << "\nPassword edited.\n";
	}
		break;
	case 1: {
		bool citybelong = false;
		string city;
		while (!citybelong) {
			cout << "\nPlease specify your home city." << endl << "It must belong to one of these: ";

			for (size_t i = 0; i < cities.size(); i++){
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
		currentUser->setHome(city);
		cout << "\nHome city edited: " << city << endl;
	}
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		changeProfile();
		break;
	}
}

void SharedRides::deleteAccount(){
	string remaccount;

	while (true) {
		remaccount = get_input <string>("Do you want to remove your vehicle? [y|n]");
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (remaccount == "y") {
			if (currentUser->getVehicle()->getYear() != 0) {
				//delete of system!!!!!!!!!!!!
				for (size_t i = 0; i < tripsPrinter.size(); i++) {
					if (currentUser->getusername() == tripsPrinter[i].getName())
						tripsPrinter[i].setName("Deleted");
				}
				recompensate(currentUser->getID());

				for (size_t i = 0; i < tripOffers.size(); i++) {
					if (tripOffers[i].getOwner() == currentUser->getID()) {
						tripOffers.erase(tripOffers.begin() + i);
						i--;
					}
				}

				size_t pos = getPositionCar(currentUser->getID());
				cars.erase(cars.begin() + pos);
			}

			for (size_t i = 0; i < users.size(); i++) {
				if (dynamic_cast<RegisteredUser*>(users[i]) != NULL && users[i] != currentUser) {
					for (size_t z = 0; z < users[i]->getFavs().size(); i++) {
						if (users[i]->getFavs()[i] == currentUser->getID()) {
							users[i]->getFavs().erase(users[i]->getFavs().begin() + z);
							break;
						}
					}
				}
			}

			vector<int> vec = currentUser->getFavs();
			float splitMoney = currentUser->getAccount() / vec.size();
			for (size_t i = 0; i < vec.size(); i++) {
				size_t j = getPositionUser(vec[i]);
				users[j]->chargeAccount(splitMoney);
			}
			cout << endl << "Your money has been distributed equally by your buddies!" << endl;

			for (size_t i = 0; i < tripOffers.size(); i++) {
				for (size_t j = 0; j < tripOffers[i].getWay().size(); j++) {
					for (size_t k = 0; k < tripOffers[i].getWay()[j].getusers().size(); k++) {
						if (tripOffers[i].getWay()[j].getusers()[k] == currentUser->getID()) {
							tripOffers[i].getWay()[j].getusers().erase(tripOffers[i].getWay()[j].getusers().begin() + k);
							break;
						}
					}
				}
			}

			//delete of system!!!!!!!!!!!!
			size_t j = getPositionUser(currentUser->getID());
			currentUser = NULL;
			users.erase(users.begin() + j);
			cout << "Your account has been deleted. Sad to see you go, hope you enjoyed our App.\n";
			break;
		}

		if (remaccount == "n") {
			cout << "Getting back..." << endl;
			break;
		}
		else cout << "Error! Please enter y or n." << endl;
	}

	return;
}

void SharedRides::buddiesMenu(){
	cout << endl << "You have: ";
	cout << currentUser->getFavs().size() << " Buddies.";

	int choice = get_input <int>(
		"[0] Follow a Buddie" "\n"
		"[1] Unfollow a Buddie" "\n"
		"[2] See my Buddies" "\n"
		);

	switch (choice) {
	case 1:
		//addBuddie();
		break;
	case 2:
		//removeBuddie();
		break;
	case 3:
		//showBuddiesToUser();
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		buddiesMenu();
		break;
	}
}

void SharedRides::addBuddie() {
	int counter = 0;
	for (size_t i = 0; users.size(); i++) {
		if (users[i]->getCity() == currentUser->getCity())
			counter++;
	}
	int number = 0;
	if (counter != 0) {
		cout << "Users near you:" << endl;
		for (size_t i = 0; users.size(); i++) {
			if ((users[i]->getCity() == currentUser->getCity()) && (users[i] != currentUser))
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
		}
		cout << endl << "Other users:" << endl;
		for (size_t i = 0; users.size(); i++) {
			if ((users[i]->getCity() != currentUser->getCity()) && (users[i] != currentUser))
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
		}
	}
	else {
		for (size_t i = 0; users.size(); i++) {
			if (users[i] != currentUser) {
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
			}
		}
	}

	unsigned int choice;
	while (true) {
		choice = get_input <unsigned int>(
			"\tSelect one of your buddies, by their number identifier." "\n"
			);
		if ((choice > 0) && (choice < currentUser->getFavs().size() + 1))
			break;
		else cout << "Input a valid number!" << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	currentUser->getFavs().push_back(users[choice - 1]->getID());
	cout << endl << users[choice - 1]->getusername() << " is now one of your buddies." << endl;
}

void SharedRides::removeBuddie() {
	showBuddiesProfileToUser();
	unsigned int choice;
	while (true) {
		 choice = get_input <unsigned int>(
			"\tSelect on of your buddies, by their number identifier." "\n"
			);
		 if ((choice > 0) && (choice < currentUser->getFavs().size() + 1))
			 break;
		 else cout << "Input a valid number!" << endl;
		 cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	currentUser->getFavs().erase(currentUser->getFavs().begin() + (choice - 1));
	size_t amigo = getPositionUser(currentUser->getFavs()[choice - 1]);
	cout << endl << users[amigo]->getusername() << " is no longer one of your Buddies." << endl;
}

void SharedRides::myBuddies() {

}

void SharedRides::showBuddiesProfileToUser(){
	size_t user = getPositionUser(currentUser->getID());
	vector<int> fav = users[user]->getFavs();

	for (size_t i = 0; i < fav.size(); i++) {
		size_t j = getPositionUser(fav[i]);
		cout << "Buddie number " << i + 1 << ":\n";
		users[j]->showProfile();
		cout << endl;
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
	return NULL;
}


void SharedRides::saveChanges() const {

	if (carsalterados)    //se a flag foi posta a true
	{
		ofstream out_cars(carsfile, ios::trunc);   //declaracao do ficheiro para escrita

		out_cars << getCARHighID() << endl;

		for (size_t i = 0; i < cars.size(); i++)		
		{
			cars.at(i)->save(out_cars);  
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
		unsigned int ID = cars.at(i)->getID();	
																
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