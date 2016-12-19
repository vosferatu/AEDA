#include "Shared_Rides.h"

using namespace std;

void SharedRides::showTrips() const {
	
	if (dynamic_cast<RegisteredUser*>(currentUser) == NULL) {
		cout << endl << TAB << "Not available!" << endl;
		return;
	}

	if (currentUser->getnumTrips() == 0) {
		cout << endl << TAB << "You have no taken trips in your history!" << endl;
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
		vector<int> vec = currentUser->getTrips();

		cout << endl << TAB << "Your trip history:" << endl << endl;
		
		for (size_t i = 0; i < vec.size(); i++) {
			for (size_t j = 0; j < tripsPrinter.size(); j++) {
				if (tripsPrinter[j].getTripCode() == vec[i]) {
					cout << "Trip number " << i + 1 << endl;
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
				TAB"Please input a price per Stop: "
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

	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() == currentUser->getID()) {
			s1 = tripOffers[i].getWay();
			string end = s1[s1.size() - 1].getCity();
			Time tfim = Time() + tripOffers[i].getTotalTime();

			takenTrip t1(currentUser->getID(), s1[0].getCity(), end, tfim);

			codigo = t1.getTripCode();

			tripOffers.erase(tripOffers.begin() + i);

			tripsPrinter.push_back(t1);

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
			for (size_t j = 0; j < s1[i].getusers().size(); j++)
				gajos.push_back(s1[i].getusers()[j]);
		}

		gajos.push_back(currentUser->getID());
		sort(gajos.begin(), gajos.end());
		gajos.erase(unique(gajos.begin(), gajos.end()), gajos.end());
		
		//fica com vetor de users na viagem

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

	string firstPoint;
	string secondPoint;
	bool citybelong = false;

	cout << endl << TAB << "Where are you catching a ride?" << endl;

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


	int stops = 0;
	vector<int> AvailableTrips{};
	for (size_t i = 0; i < tripOffers.size(); i++) {
		if (tripOffers[i].getOwner() != currentUser->getID()) {
			stops = checkTrip(firstPoint, secondPoint, tripOffers[i].getWay());
			if (stops > 0) {
				if (currentUser->getAccount() > stops*tripOffers[i].getpriceStop()) {
					AvailableTrips.push_back(i);
				}
			}
		}
	}

	if (AvailableTrips.size() == 0) {
		cout << endl << TAB << "We are sorry, but there are no trips available in your conditions." << endl;
		return;
	}

	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) {//REGISTERED
		for (size_t i = 0; i < AvailableTrips.size(); i++) {
			if (checkBuddie(tripOffers[AvailableTrips[i]].getOwner()))
				cout << endl << TAB << "Buddie Trip!" << endl;
			cout << TAB << "Trip number: " << AvailableTrips[i];
			cout << tripOffers[AvailableTrips[i]] << endl << endl;
		}
	}
	else {//GUEST
		for (size_t i = 0; i < AvailableTrips.size(); i++) {
			cout << TAB << "Trip number: " << AvailableTrips[i];
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

	int contador = 0;
	unsigned int bancos = tripOffers[choice].getmaxSeats();
	vector<Stretch> novo = tripOffers[choice].getWay();
	for (size_t i = 0; i < novo.size(); i++) {
		if (novo[i].getCity() == firstPoint) {
			if (novo[i].getusers().size() < bancos)
				contador++;
		}
		if ((contador > 0) && (novo[i].getCity() != secondPoint)) {
			if (novo[i].getusers().size() < bancos)
				contador++;
		}
		if (novo[i].getCity() == secondPoint) {
			if (novo[i].getusers().size() < bancos)
				contador++;
			break;
		}
	}
	if (contador != stops) {
		cout << endl << TAB << "Not enough seats available! We're sorry." << endl;
		return;
	}

	contador = 0;
	for (size_t i = 0; i < novo.size(); i++) {
		if (novo[i].getCity() == firstPoint) {
			novo[i].addUser(currentUser->getID());
			contador++;
		}
		if ((contador > 0) && (novo[i].getCity() != secondPoint)) {
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

	cout << endl << TAB << "You have been added to the trip and you have payed for it." << endl;

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