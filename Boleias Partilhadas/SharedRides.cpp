#include "Shared_Rides.h"

using namespace std;

vector<User*> SharedRides::users(0);
//vector<Vehicle*>SharedRides::cars(0);

vector<string>SharedRides::cities(0);

vector<takenTrip> SharedRides::tripsPrinter(0);
vector<waitingTrip> SharedRides::tripOffers(0);


unsigned int SharedRides::maxUsersID = 0;
unsigned int SharedRides::maxVehiclesID = 0;
unsigned int SharedRides::maxTakenCode = 0;

unsigned int  SharedRides::numbercities = 0;

bool SharedRides::usersalterados = false;
bool SharedRides::carsalterados = false;



void SharedRides::run() {
	try {
		fillPaths();
		load();
		main_menu();
		saveChanges();
	}
	catch (FileException<string> err) {
		cout << endl << TAB << "Erro: " << err.info << endl;
	}
}


//Helper Functions
void SharedRides::fillPaths() {
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

int SharedRides::getPositionCar(unsigned int id) const {
	int position = -1;
	int i = 0;
	
	BSTItrIn<VehicleDBItem> it(carsBST);

	while (!it.isAtEnd()) {
		if (it.retrieve().getVehicle()->getID() == id) {
			position = i;
			return position;
		}
			i++;
			it.advance();
	}
	
	//for (size_t i = 0; i < cars.size(); i++) {
		//if (cars[i]->getID() == id) {
			//position = i;
			//return position;
		//}
	//}

	return position;
}

int SharedRides::getPositionUser(unsigned int id) const {
	int position = -1;
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i]->getID() == id) {
			position = i;
			return position;
		}
	}
	return position;
}

void SharedRides::recompensate(unsigned int id) {
	vector<int> afetados{};

	if (tripOffers.size() == 0)
		return;

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

Time SharedRides::searchStretchTime(string one, string two) {
	for (size_t i = 0; i < caminhos.size(); i++) {
		if ((caminhos[i].getFirst() == one) && (caminhos[i].getSecond() == two))
			return caminhos[i].getTime();
	}
//	return Time();
}

string SharedRides::searchStretchCity(string one, Time t1) {
	for (size_t i = 0; i < caminhos.size(); i++) {
		if ((caminhos[i].getFirst() == one) && (caminhos[i].getTime() == t1))
			return caminhos[i].getSecond();
	}
	return "";
}

unsigned int SharedRides::getCARHighID() const {

	unsigned int maiorID = 0;

	BSTItrIn<VehicleDBItem> it(carsBST);

	while (!it.isAtEnd()) {
		unsigned int ID = it.retrieve().getVehicle()->getID();
		
		if (ID > maiorID)
			maiorID = ID;
		
		it.advance();
	}
	
	
	
	//for (size_t i = 0; i < cars.size(); i++)
	//{
		//unsigned int ID = cars[i]->getID();

		//if (ID > maiorID)
			//maiorID = ID;
	//}

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

unsigned int SharedRides::getTAKENHighID() const {

	unsigned int maiorID = 0;

	for (size_t i = 0; i < tripsPrinter.size(); i++)
	{
		unsigned int ID = tripsPrinter.at(i).getTripCode();

		if (ID > maiorID)
			maiorID = ID;
	}

	return maiorID;
}

