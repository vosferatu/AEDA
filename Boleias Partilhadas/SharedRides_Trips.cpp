#include "Shared_Rides.h"

using namespace std;

void SharedRides::showTrips() const {
	
	if (dynamic_cast<RegisteredUser*>(currentUser) == NULL) {
		cout << endl << TAB << "Not available!" << endl;
		return;
	}

	cout << endl;

	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	int choice = get_input <int>(
		TAB_BIG"[0] Active Trips" "\n""\n"
		TAB_BIG"[1] Trip History" "\n""\n"
		);



	switch (choice) {	
	case 0: {
		for (size_t i = 0; i < tripOffers.size(); i++) {
			if (tripOffers[i].getOwner() == currentUser->getID()) {
				cout << tripOffers[i] << endl;
			}
		}
		break;
	}

	case 1: {
		if (currentUser->getnumTrips() == 0) {
			cout << endl << TAB << "You have no taken trips in your history!" << endl;
			return;
		}
		
		vector<int> vec = currentUser->getTrips();

		cout << endl << TAB << "Your trip history:" << endl << endl;
		
		for (size_t i = 0; i < vec.size(); i++) {
			for (size_t j = 0; j < tripsPrinter.size(); j++) {
				if (tripsPrinter[j].getTripCode() == vec[i]) {
					cout << "Trip number " << tripsPrinter[j].getTripCode() << endl; // em vez de i +1 (para efeitos de listagem pessoal)
					cout << tripsPrinter[j] << endl;
					cout << "----------------------------------------------------" << endl << endl;
					break;
				}
			}
		
		}
		break;
	}
	}

	
}

void SharedRides::VehicleTripMenu() {
	cout << endl;
	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	int choice = get_input <int>(
		TAB_BIG"[0] Start Trip" "\n""\n"
		TAB_BIG"[1] Add a Trip" "\n""\n"
		TAB_BIG"[2] Enter a Trip" "\n""\n"
		);

	switch (choice) {
	case 0:
		startTrip();
		usersalterados = true;
		return;
		break;
	case 1:
		addTrip();
		usersalterados = true;
		return;
		break;
	case 2:
		enterTrip();
		usersalterados = true;
		return;
		break;
	default:
		cout << TAB << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;
	}
	VehicleTripMenu();
}

void SharedRides::addTrip() {
	
	if (currentUser->getAccount() < 0) {
		cout << endl << TAB << "Your account is under 0. Please charge account to pay your taxes." << endl;
		return;
	}

	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() == currentUser->getID()) {
			cout << endl << TAB << "You already have an active Trip." << endl;
			return;
		}
	}

	cin.ignore(numeric_limits <streamsize>::max(), '\n');

	int choice = get_input <int>(
		TAB_BIG"[0] Normal Rout" "\n""\n"
		TAB_BIG"[1] Different Trip" "\n""\n"
		);

	switch (choice) {
	case 0: {
		vector<string> rota = currentUser->getVehicle()->getRoute();
		if (currentUser->getVehicle()->getRoute().empty()) {
			cout << endl << TAB << "You don't have a predefined route in your account. Please change it in the Vehicle Editor.";
			cout << endl << endl << TAB << "Press [ENTER] to exit.";
			return;
		}
		vector<Stretch> novo{};
		for (size_t i = 0; i < rota.size() - 1; i++) {
			Time t1 = searchStretchTime(rota[i], rota[i + 1]);
			Stretch s1(rota[i], t1);
			novo.push_back(s1);
		}
		float pps = 0;
		while (true) {
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			pps = get_input <float>(
				"\n" TAB "Please input a price per Stop: "
				);
			if (pps > 0)
				break;
			else cout << endl << TAB << "Please input no negative numbers!" << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
		}
		novo.push_back(Stretch(rota[rota.size() - 1], Time(0, 0)));
		waitingTrip nova(currentUser->getID(), novo, currentUser->getVehicle()->getnumberSeats() - 1, pps);
		tripOffers.push_back(nova);
		cout << endl << TAB << "SUCCESS! New Trip Added." << endl;
		break;
	}
	case 1:
	{//---------------------------------------------------------------------------------
		string cityroute;
		vector<string> rota;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << TAB << "Please specify the cities of your route, separared by slash" << endl;
		cout << TAB << "Example: Porto-Lisboa-Vila Real" << endl;
		cout << TAB << "It must belong to one of these : ";
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
			rota.push_back(substr);
		}
		//_-----------------------------------------------------------------------------------
		vector<Stretch> novo{};
		for (size_t i = 0; i < rota.size() - 1; i++) {
			Time t1 = searchStretchTime(rota[i], rota[i + 1]);
			Stretch s1(rota[i], t1);
			novo.push_back(s1);
		}
		float pps = 0;
		while (true) {
			pps = get_input <float>(
				TAB "Input a price per Stop: "
				);
			if (pps > 0)
				break;
			else cout << endl << TAB << "Please no negative numbers.!" << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
		}
		novo.push_back(Stretch(rota[rota.size() - 1], Time(0, 0)));
		waitingTrip nova(currentUser->getID(), novo, currentUser->getVehicle()->getnumberSeats() - 1, pps);
		tripOffers.push_back(nova);
		cout << endl << TAB << "SUCCESS! New Trip Added." << endl;
	}
	break;
	default:
		cout << endl << TAB << "Please, input an integer suitable to the options shown." << endl << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		addTrip();
		break;
	}
}

void SharedRides::startTrip() {

	bool noTrip = false;

	unsigned int codigo = 0;

	vector<Stretch> s1;

	int maxseats = 0;

	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() == currentUser->getID()) {
			s1 = tripOffers[i].getWay();
			string end = s1[s1.size() - 1].getCity();
			Time tfim = Time() + tripOffers[i].getTotalTime();
			
			maxseats = tripOffers[i].getmaxSeats();

			takenTrip t1(currentUser->getusername(), s1[0].getCity(), end, tfim);

			codigo = t1.getTripCode();
			tripOffers.erase(tripOffers.begin() + i);
			
			tripsPrinter.push_back(t1);
			currentUser->setLastTrip(t1.getDay());

			noTrip = true;
			break;
		}
	}


	
	if (noTrip == false)
		cout << endl << TAB << "You have no pending trips!" << endl;
	else {
		
		cout << endl << TAB << "Your trip has been started!" << endl;
		
		vector<int> gajos{};
		
		for (size_t i = 0; i < s1.size(); i++) {
			
			HEAP_USERS buffer = s1[i].getHeap();
			int seats = 0;

			while (seats != maxseats) {
			
				while (!buffer.empty()) {
					WaitingUser u = buffer.top();
					buffer.pop();
					gajos.push_back(u.getUserID());
					seats++;
				}
			}


			//for (size_t j = 0; j < s1[i].getusers().size(); j++)
				//gajos.push_back(s1[i].getusers()[j]);
		}

		sort(gajos.begin(), gajos.end());
		
		gajos.erase(unique(gajos.begin(), gajos.end()), gajos.end());
		
		//fica com vetor de users na viagem (sem o owner)
		
		for (size_t i = 0; i < gajos.size(); i++) {
			size_t j = getPositionUser(gajos[i]);
			users[j]->addTrip(codigo);
		}
		
		currentUser->addTrip(codigo);
		
		usersalterados = true;
	}
}

void SharedRides::enterTrip() {
	if (currentUser->getAccount() < 0) {
		cout << TAB << "Your account is under 0. Please charge account to pay your taxes." << endl;
		return;
	}

	cout << endl << TAB << "Right now you have " << currentUser->getAccount() << "$. Please be sure you have enough for the trip!" << endl;

	string firstPoint;
	string secondPoint;
	bool citybelong = false;

	cout << endl << TAB << "Where are you catching a ride?" << endl;
	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	while (!citybelong) {

		cout << TAB << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		firstPoint = readLine();

		for (size_t i = 0; i < cities.size(); i++) {
			if (firstPoint == cities[i])
				citybelong = true;
		}

	}
	citybelong = false;
	cout << endl << TAB << "Where are you dropping off?" << endl;
	while (!citybelong) {

		cout << TAB << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		secondPoint = readLine();

		for (size_t i = 0; i < cities.size(); i++) {
			if (secondPoint == cities[i])
				citybelong = true;
		}

	}

	if (firstPoint == secondPoint) {
		cout << endl << TAB << "If you want to hang around in town, why don't you consider taking a walk? :)" << endl;
		cout << endl << TAB << "Press [ENTER] to return." << endl;
		return;
	}


	int stops = 0;
	
	vector<int> AvailableTrips{};


	
	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() != currentUser->getID()) {
			stops = checkTrip(firstPoint, secondPoint, tripOffers[i].getWay());
			if (stops > 0) {
				if (currentUser->getAccount() > stops*tripOffers[i].getpriceStop()) {
					AvailableTrips.push_back(i);
				}
				else {
					cout << endl << TAB << "You don't have enough money! You can do charge your account in the main menu." << endl;
					cout << endl << TAB << "Press [ENTER] to return." << endl;
					return;
				}
			}
		}
	}

	
	if (AvailableTrips.size() == 0) {
		cout << endl << TAB << "We are sorry, but there are no trips available in your conditions." << endl;
		cout << endl << TAB << "Press [ENTER] to return." << endl;
		return;
	}

	ClearScreen();
	header(" --- NEW TRIP --- ", "RU");

	cout << endl << TAB << "				::  Avaible Trips from " << firstPoint <<  " to " << secondPoint << "  :: "<<  endl;
	
	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) {//REGISTERED
		
		for (size_t i = 0; i < AvailableTrips.size(); i++) {
			
			if (checkBuddie(tripOffers[AvailableTrips[i]].getOwner())) 
			cout << endl << endl << TAB << " >>> Buddie Trip! <<< " << endl;

			cout << endl << " ---------------------------------------------------------------------- " << endl;
			cout << endl << TAB << "Trip number: " << AvailableTrips[i];
			cout << tripOffers[AvailableTrips[i]] << endl << endl;

			cout <<TAB<<  Estimated price for this trip: " << tripOffers[AvailableTrips[i]].getpriceStop() * stops" << "$." << endl<< endl;
		}
	}
	
	else {//GUEST
		for (size_t i = 0; i < AvailableTrips.size(); i++) {
			cout << endl  << TAB << " Trip number: " << AvailableTrips[i];
			cout << tripOffers[AvailableTrips[i]] << endl << endl;
		}
	}

	unsigned int choice;
	
	while (true) {
		choice = get_input <unsigned int>(
			TAB"Select one of the Trips, by their number identifier." "\n"
			);
		if ((choice >= 0) && (choice < tripOffers.size() + 1))
			break;

		cout << "Input a valid number!" << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	Time driveraway; 
	if (tripOffers[choice].getWay()[0].getCity() == firstPoint) driveraway = Time(0, 0);
	else driveraway = searchStretchTime(tripOffers[choice].getWay()[0].getCity(), firstPoint);
	
	WaitingUser u1;
	vector<int> nobuddies{};

	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) //REGISTERED 
		 u1 = WaitingUser(currentUser->getID(), currentUser->getFavs(), driveraway, tripOffers[choice].getOwner());	
	else // GUEST
		u1 = WaitingUser(currentUser->getID(), nobuddies, driveraway, tripOffers[choice].getOwner());

	vector<Stretch> novo = tripOffers[choice].getWay();
	
	bool entrou = false;
	
	
	
	
	
	for (size_t i = 0; i < novo.size(); i++) {

		HEAP_USERS buffer = novo[i].getHeap();
		
		while (!buffer.empty()) { // garante que o mesmo user nao entra
			if (currentUser->getID() == buffer.top().getUserID()) {
				entrou = false;
				buffer.pop();
				break;
			}
			buffer.pop();
		}

		
		if (novo[i].getCity() == firstPoint) {
			novo[i].addtoHeap(u1);
			entrou = true;
		}

		if ((entrou == true) && (novo[i].getCity() != secondPoint) && (novo[i].getCity() != firstPoint)) {
			novo[i].addtoHeap(u1);
			entrou = true;
		}
		if (novo[i].getCity() == secondPoint) {
			novo[i].addtoHeap(u1);
			entrou = true;
			cout << endl << TAB << "You have been added to the waiting line for the trip. If you are friend of the driver you'll be prioritized.  " << endl;
			cout << endl << TAB << "Press [ENTER] to return.  " << endl;
			break;
		}
	}

	if (entrou == false) {
		cout << endl << TAB << "You have not been added to the waiting line for the trip. Are you sure you aren't already assigned to this trip? " << endl;
		cout << endl << TAB << "Press [ENTER] to return.  " << endl;
		return;
	}

	tripOffers[choice].setWay(novo);


	/*
	int contador = 0;
	bool entrou = false;
	unsigned int bancos = tripOffers[choice].getmaxSeats();

	vector<Stretch> novo = tripOffers[choice].getWay();

	for (size_t i = 0; i < novo.size(); i++) {
		
		if (novo[i].getCity() == firstPoint) {
			if (novo[i].getusers().size() < bancos)
				entrou = true;
			else entrou = false;
		}

		if ((entrou == true) && (novo[i].getCity() != secondPoint)) {
			if (novo[i].getusers().size() < bancos)
				entrou = true;
			else entrou = false;
		}
		if (novo[i].getCity() == secondPoint) {
			if (novo[i].getusers().size() < bancos)
				entrou = true;
			else entrou = false;
			break;
		}
	}

	if (entrou != true) {
		cout << endl << TAB << "Not enough seats available! We're sorry." << endl;
		return;
	}

	contador = 0;
	
	for (size_t i = 0; i < novo.size(); i++) {
		if (novo[i].getCity() == firstPoint) {
			novo[i].addUser(currentUser->getID());
			contador++;
		}
		if ((contador > 0) && (novo[i].getCity() != secondPoint) && (novo[i].getCity() != firstPoint)) {
			novo[i].addUser(currentUser->getID());
			contador++;
		}
		if (novo[i].getCity() == secondPoint) {
			novo[i].addUser(currentUser->getID());
			break;
		}
	}
	

	tripOffers[choice].setWay(novo);

	currentUser->chargeAccount(stops*tripOffers[choice].getpriceStop());

	cout << endl << TAB << "You have been added to the trip. The trip price " << stops*tripOffers[choice].getpriceStop() <<"$ was automatically charged from your account." << endl;
	*/
}

int SharedRides::checkTrip(string a, string b, const vector<Stretch> & v) const {
	int found1 = -1000;
	int found2 = -100;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].getCity() == a)
			found1 = i;
		if (v[i].getCity() == b)
			found2 = i;
	}
	return ((found2 - found1) + 1);
}