#include "Shared_Rides.h"
#include <algorithm>

using namespace std;

vector<User*> SharedRides::users(0);
vector<Vehicle*>SharedRides::cars(0);
vector<string>SharedRides::cities(0);

const string SharedRides::citiesfile = "cities.txt";

unsigned int  SharedRides::numbercities = 0;

void SharedRides::load()
{
	fillPaths();
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
			Vehicle* v2 = &v1;
			RegisteredUser* RU = new RegisteredUser(username, password1, v2);

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
			Vehicle* nocar = new Vehicle();

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
		if (cars[i]->getCarID() == id) {
			position = i;
			return position;
		}	
	}
	return position;
}

int SharedRides::getPositionUser(unsigned int id) const{
	int position = -1;
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i]->getid() == id) {
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
	//agora temos de recompensar esses users pela viagem que pagram e não vão fazer
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
	case 1:
		editVehicle();
		break;
	case 2:
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
			if (cars[i]->getCarID() == currentUser->getid()) {
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
			
			recompensate(currentUser->getid());
			for (size_t i = 0; i < tripOffers.size(); i++) {
				if (tripOffers[i].getOwner() == currentUser->getid()) {
					tripOffers.erase(tripOffers.begin() + i);
					i--;
				}
			}

			size_t pos = getPositionCar(currentUser->getid());
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
	case 1: {
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
	case 2: {
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
				recompensate(currentUser->getid());

				for (size_t i = 0; i < tripOffers.size(); i++) {
					if (tripOffers[i].getOwner() == currentUser->getid()) {
						tripOffers.erase(tripOffers.begin() + i);
						i--;
					}
				}

				size_t pos = getPositionCar(currentUser->getid());
				cars.erase(cars.begin() + pos);
			}

			for (size_t i = 0; i < users.size(); i++) {
				if (dynamic_cast<RegisteredUser*>(users[i]) != NULL && users[i] != currentUser) {
					for (size_t z = 0; z < users[i]->getFavs().size(); i++) {
						if (users[i]->getFavs()[i] == currentUser->getid()) {
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
						if (tripOffers[i].getWay()[j].getusers()[k] == currentUser->getid()) {
							tripOffers[i].getWay()[j].getusers().erase(tripOffers[i].getWay()[j].getusers().begin() + k);
							break;
						}
					}
				}
			}

			//delete of system!!!!!!!!!!!!
			size_t j = getPositionUser(currentUser->getid());
			currentUser = NULL;
			cars.erase(cars.begin() + j);
		}

		if (remaccount == "n") {
			cout << "Getting back..." << endl;
			break;
		}
		else cout << "Error! Please enter y or n." << endl;
	}

	return;
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