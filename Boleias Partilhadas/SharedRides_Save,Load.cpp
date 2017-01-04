#include "Shared_Rides.h"

using namespace std;

const string SharedRides::citiesfile = "cities.txt";
const string SharedRides::usersfile = "users.txt";
const string SharedRides::carsfile = "cars.txt";
const string SharedRides::takenfile = "takentrips.txt";
const string SharedRides::waitingfile = "waitingtrips.txt";

void SharedRides::loadUsers() {

	ifstream infile(usersfile);

	if (infile.peek() == std::ifstream::traits_type::eof())
		return;

	string info;					//string que ira conter a informacao de cada linha do ficheiro
	string strnumber;					//string que ira remover o numero no inicio do ficheiro

	if (!infile.is_open())
	{
		throw FileException<string>("ERROR! The Vehicles file could not be opened.");
	}

	getline(infile, strnumber);
	maxUsersID = stoi(strnumber);

	unsigned int ID;
	string username;
	string password;
	string homecity;
	float account;
	unsigned int numTrips;
	unsigned int numBuddies;

	while (getline(infile, info))
	{
		unsigned int search = 1000;

		size_t findpos = info.find(';', 0);			//inteiro que tem a posicao do primeiro ';'

		ID = stoul(info.substr(0, findpos).c_str());  //id = à string desde o inicio ate ';' transformada em unsigned int
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'

		username = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do terceiro ';'

		password = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		account = stof(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		homecity = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);


		numTrips = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		unsigned int i = 0;

		int IDtrip;
		vector <int> trips(0);
		if (numTrips > 0) {
			while (i < numTrips) {
				IDtrip = atoi(info.substr(0, findpos).c_str());
				trips.push_back(IDtrip);
				info = info.substr(findpos + 1, search);
				findpos = info.find(';', 0);
				i++;
			}
		}

		numBuddies = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		int IDBuddie;
		vector <int> buddies(0);
		unsigned int j = 0;

		while (j < numBuddies) {
			IDBuddie = atoi(info.substr(0, findpos).c_str());
			buddies.push_back(IDBuddie);
			info = info.substr(findpos + 1, search);
			findpos = info.find(';', 0);
			j++;
		}

		bool usernocar = false;
		Vehicle * nocar = new Vehicle();

		
		BSTItrIn<VehicleDBItem> it(carsBST);

		while (!it.isAtEnd()) {
			
			if (it.retrieve().getVehicle()->getID() == ID) {
			
				RegisteredUser* RU = new RegisteredUser(username, password, homecity, it.retrieve().getVehicle());
				RU->setAccount(account);
				RU->setFavs(buddies);
				RU->setTrips(trips);
				users.push_back(RU);
				usernocar = true;
			}
			
			it.advance();
		}
		
		
		
		//for (size_t i = 0; i < cars.size(); i++) {
			//if (cars[i]->getID() == ID) {
			//RegisteredUser* RU = new RegisteredUser(username, password, homecity, cars[i]);
			//RU->setAccount(account);
			//RU->setFavs(buddies);
			//RU->setTrips(trips);
			//users.push_back(RU);
			//usernocar = true;
			//}
		//}


		if (!usernocar || carsBST.isEmpty() ) {
			RegisteredUser* RU = new RegisteredUser(username, password, homecity, nocar);
			RU->setAccount(account);
			RU->setFavs(buddies);
			RU->setTrips(trips);
			users.push_back(RU);
		}
	}
}

void SharedRides::loadTakenTrips() {

	ifstream infile(takenfile);

	if (infile.peek() == std::ifstream::traits_type::eof())
		return;

	string info;					//string que ira conter a informacao de cada linha do ficheiro
	string strnumber;					//string que ira remover o numero no inicio do ficheiro

	if (!infile.is_open())
	{
		throw FileException<string>("ERROR! The TakenTrip file could not be opened.");
	}

	
	getline(infile, strnumber);
	maxTakenCode = stoi(strnumber);

	unsigned int tripcode;
	string name;
	string start;
	string end;
	Time startime;
	int startimehora;
	int startimeminuto;
	Time endtime;
	int endtimehora;
	int endtimeminuto;
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
	Date data;
	

	while (getline(infile, info))
	{
		unsigned int search = 1000;


		size_t findpos = info.find(';', 0);			//inteiro que tem a posicao do primeiro ';'
		
		tripcode = stoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'
		
		name = info.substr(0, findpos);  //id = à string desde o inicio ate ';' transformada em unsigned int
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'

		start = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do terceiro ';'

		end = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);
		findpos = info.find(':', 0);

		startimehora = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		startimeminuto = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(':', 0);

		startime = Time(startimehora, startimeminuto);

		endtimehora = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		endtimeminuto = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find('/', 0);

		endtime = Time(endtimehora, endtimeminuto);

		dia = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find('/', 0);

		mes = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find('/', 0);

		ano = atoi(info.substr(0, findpos).c_str());

		data = Date(dia, mes, ano);
		
		takenTrip v1(name, start, end, endtime);
		v1.setStartime(startime);
		v1.setEndTime(endtime);
		v1.setTripCode(tripcode);
		v1.setDay(data);

		for (size_t i = 0; i < users.size(); i++)
		{
			if (users[i]->getusername() == name) {
				if (users[i]->getLastTrip() < data)
					users[i]->setLastTrip(data);
			}
		}

		tripsPrinter.push_back(v1);
	}
}

void SharedRides::loadWaitingTrips() {

	ifstream infile(waitingfile);

	if (infile.peek() == std::ifstream::traits_type::eof())
		return;

	string info;					//string que ira conter a informacao de cada linha do ficheiro

	if (!infile.is_open())
	{
		throw FileException<string>("ERROR! The waiting file could not be opened.");
	}

	unsigned int owner;
	int viagemsize;
	string stop;
	int tonexthora;
	int tonextminuto;
	Time tonext;
	int  ID;
	int numIDs;
	float pricestop;
	int maxseats;
	int driverawayhour;
	int driverawayminute;
	Time driveraway;

	vector<Stretch> viagem;

	while (getline(infile, info)) {
		unsigned int search = 1000;


		size_t findpos = info.find(';', 0);			//inteiro que tem a posicao do primeiro ';'

		owner = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'

		viagemsize = atoi(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);

		int i = 0;


		while (i < viagemsize) {
			stop = info.substr(0, findpos);
			info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
			findpos = info.find(':', 0);

			tonexthora = atoi(info.substr(0, findpos).c_str());
			info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
			findpos = info.find(';', 0);

			tonextminuto = atoi(info.substr(0, findpos).c_str());
			info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
			findpos = info.find(';', 0);

			tonext = Time(tonexthora, tonextminuto);

			numIDs = atoi(info.substr(0, findpos).c_str());
			info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
			findpos = info.find(';', 0);
			int j = 0;
			vector<int> vectID;
			
			HEAP_USERS heap;
			
			while (j < numIDs) {
				ID = atoi(info.substr(0, findpos).c_str());
				info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
				findpos = info.find(':', 0);

				driverawayhour = atoi(info.substr(0, findpos).c_str());
				info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
				findpos = info.find(';', 0);

				driverawayminute = atoi(info.substr(0, findpos).c_str());
				info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
				findpos = info.find(';', 0);

				driveraway = Time(driverawayhour, driverawayminute);
				
				vector<int> buddies;
				
				for (size_t i = 0; i < users.size(); i++) {
					if (users[i]->getID() == ID) {
						buddies = users[i]->getFavs();
						break;
					}
				}
				
				WaitingUser u1 = WaitingUser(ID, buddies, driveraway, owner);
				
				heap.push(u1);
				
				vectID.push_back(ID);
				
				j++;
			}
			
			Stretch str(stop, tonext);
			//str.setvectID(vectID);
			//str.setHeap(heap);
			viagem.push_back(str);
			i++;
		}
		
		
		pricestop = stof(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);

		maxseats = atoi(info.substr(0, findpos).c_str());
		


		waitingTrip waiting(owner, viagem, maxseats, pricestop);
		tripOffers.push_back(waiting);
	}
}

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

	unsigned int ID;
	string brand;
	unsigned int year;
	string rate;
	string model;
	unsigned int seats;

	while (getline(infile, info))
	{
		unsigned int search = 1000;


		size_t findpos = info.find(';', 0);			//inteiro que tem a posicao do primeiro ';'

		ID = stoul(info.substr(0, findpos).c_str());  //id = à string desde o inicio ate ';' transformada em unsigned int
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do segundo ';'

		brand = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do terceiro ';'

		model = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);			//string = desde primeiro ';' até ao segundo
		findpos = info.find(';', 0);					//agora o inteiro é a posicao na string do terceiro ';'

		seats = stoul(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		year = stoul(info.substr(0, findpos).c_str());
		info = info.substr(findpos + 1, search);
		findpos = info.find(';', 0);

		rate = info.substr(0, findpos);
		info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
		findpos = info.find(';', 0);

		vector<string> route;


		while (findpos != -1) {
			route.push_back(info.substr(0, findpos));
			info = info.substr(findpos + 1, search);			//string = desde findpos até ao resto da  string
			findpos = info.find(';', 0);
		}

		Vehicle* v1 = new Vehicle(ID, seats, brand, year, rate);
		v1->setRoute(route);
		v1->setModel(model);
		//cars.push_back(v1);

		VehicleDBItem v1Item = VehicleDBItem(v1);
		carsBST.insert(v1Item);

	}

	BSTItrIn<VehicleDBItem> it(carsBST);
	while (!it.isAtEnd()) {

		for (size_t j = 0; j < users.size(); j++) {
			if (users[j]->getID() == it.retrieve().getVehicle()->getID()) 
				users[j]->setVehicle(it.retrieve().getVehicle());
		}
		it.advance();
	}
	
	
	//for (size_t i = 0; i < cars.size(); i++) {
		//for (size_t j = 0; j < users.size(); j++) {
			//if (users[j]->getID() == cars[i]->getID()) {
				//users[j]->setVehicle(cars[i]);
			//}
		//}
	//}
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
	unsigned int i = 0;

	while (i < numbercities)
	{
		getline(file, info);
		cities.push_back(info);
		i++;
	}


}

void SharedRides::load() {
	loadCities();
	loadVehicles();
	loadUsers();
	loadWaitingTrips();
	loadTakenTrips();
}

void SharedRides::saveChanges() const {

	if (carsalterados)    //se a flag foi posta a true
	{
		ofstream out_cars(carsfile, ios::trunc);   //declaracao do ficheiro para escrita

		out_cars << getCARHighID() << endl;

		BSTItrIn<VehicleDBItem> it(carsBST);

		while (!it.isAtEnd()) {
			it.retrieve().getVehicle()->save(out_cars);
			it.advance();
		}
		
		//for (size_t i = 0; i < cars.size(); i++) {
			//cars[i]->save(out_cars);
		//}

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

	ofstream out_taken(takenfile, ios::trunc);   //declaracao do ficheiro para escrita

	out_taken << getTAKENHighID() << endl;

	for (size_t i = 0; i < tripsPrinter.size(); i++)
	{
		tripsPrinter[i].save(out_taken);   //funcao save da classe
	}
	out_taken.close();



	ofstream out_waiting(waitingfile, ios::trunc);   //declaracao do ficheiro para escrita

	for (size_t i = 0; i < tripOffers.size(); i++)
	{
		tripOffers[i].save(out_waiting);   //funcao save da classe
	}
	out_waiting.close();
}


