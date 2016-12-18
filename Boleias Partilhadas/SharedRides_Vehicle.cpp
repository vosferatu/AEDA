#include "Shared_Rides.h"

using namespace std;

void SharedRides::userWithVehicleMenu() {

	int choice = get_input <int>(
		TAB_BIG"[0] Edit my Vehicle" "\n" "\n"
		TAB_BIG"[1] Remove my Vehicle" "\n" "\n");

	switch (choice) {
	case 0:
		editVehicle();
		carsalterados = true;
		break;
	case 1:
		removeVehicle();
		carsalterados = true;
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		userWithVehicleMenu();
		break;
	}
}

void SharedRides::editVehicle() {

	cout << endl;
	cin.ignore(numeric_limits <streamsize>::max(), '\n');

	int choice = get_input <int>(
		TAB_BIG"[0] Change my vehicle to another vehicle" "\n" "\n"
		TAB_BIG"[1] Change route" "\n" "\n");

	switch (choice) {
	case 0: {
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << TAB;
		cout << "Please specify its brand and model." << endl;
		string brand = readLine();

		bool goodyear = false;
		unsigned int year;

		while (!goodyear) {
			cout << endl << TAB;
			year = get_input <unsigned int>("Please specify its year.");

			if (year < 1901 || year > 2017) {
				goodyear = false;
				cout << endl << TAB << "[Error!] Invalid year. \n";
			}

			else goodyear = true;
		}

		bool goodseats = false;
		unsigned int seats;
		while (!goodseats) {
			cout << endl << TAB;
			seats = get_input <unsigned int>("Please specify the number of seats of your car, including yours. [2|5|9]");
			if (seats != 2 && seats != 5 && seats != 9)
			{
				cout << endl << TAB << "[Error!] The number of seats you provided is not valid.\n";
				goodseats = false;
			}
			else goodseats = true;
		}

		bool goodrate = false;
		string rate;
		while (!goodrate) {
			cout << endl << TAB;
			rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

			if (rate != "A" && rate != "B" && rate != "C" && rate != "D" && rate != "E" && rate != "F")
			{
				cout << endl << TAB << "[Error!] Please give an evaluation in the provided scale.\n";
				goodrate = false;
			}
			else goodrate = true;
		}

		currentUser->getVehicle()->setRate(rate);
		currentUser->getVehicle()->setYear(year);
		currentUser->getVehicle()->setSeats(seats);
		currentUser->getVehicle()->setBrand(brand);
		currentUser->getVehicle()->setId(currentUser->getID());
		// adds route 
		bool routebool = false;
		string cityroute;
		string addroute;
		vector<string> rout(0);

		while (!routebool) {
			cout << endl << TAB;
			addroute = get_input <string>("Do you want to add a common route you do? [y|n]");

			cin.ignore(numeric_limits <streamsize>::max(), '\n');

			if (addroute == "y") {

				cout << TAB << "Please specify the cities of your route, separated by slash" << endl;
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
					rout.push_back(substr);
				}

				routebool = true;
				break;

			}
			else if (addroute == "n") {
				routebool = true;
				break;
			}
			else
				cout << endl << TAB << "Please insert \"y\" or \"n.\" \n";
			routebool = false;
		}

		currentUser->getVehicle()->setRoute(rout);

		for (size_t i = 0; i < cars.size(); i++) {
			if (cars[i]->getID() == currentUser->getID()) {
				cars[i] = currentUser->getVehicle();
				break;
			}
		}
		carsalterados = true;
	}
			break;
	case 1: {
		string cityroute;
		vector<string> rout(0);
		cout << TAB << "Please specify the cities of your route, separared by slash" << endl;
		cout << TAB << "Example: Porto-Lisboa-Vila Real" << endl;
		cout << TAB << "It must belong to one of these : ";
		for (size_t i = 0; i < cities.size(); i++) {
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
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
		carsalterados = true;
	}
			break;
	default:
		cout << TAB << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		editVehicle();
		break;
	}
	usersalterados = true;
	carsalterados = true;
}

void SharedRides::removeVehicle() {
	string remvehicle;

	while (true) {
		cout << endl << TAB;
		remvehicle = get_input <string>("Do you really want to remove your vehicle? [y|n]");
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (remvehicle == "y") {
			Vehicle* v1 = new Vehicle();

			recompensate(currentUser->getID());

			for (size_t i = 0; i < tripOffers.size(); i++) {
				if (tripOffers[i].getOwner() == currentUser->getID()) {
					tripOffers.erase(tripOffers.begin() + i);
					i--;
				}
			}

			size_t pos = getPositionCar(currentUser->getID());
			cars.erase(cars.begin() + pos);
			currentUser->getVehicle()->setVehicle(v1);

			break;
		}

		if (remvehicle == "n") {
			cout << TAB << "Your vehicle was not removed." << endl;
			break;
		}
		else cout << TAB << "Error! Please enter y or n." << endl;
	}
	usersalterados = true;
	carsalterados = true;
	return;
}

void SharedRides::addVehicle() {

	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	cout << endl << TAB;
	cout << "Please specify its brand and model." << endl;
	string brand = readLine();

	bool goodyear = false;
	unsigned int year;

	while (!goodyear) {
		cout << endl << TAB;
		year = get_input <unsigned int>("Please specify its year.");

		if (year < 1901 || year > 2017) {
			goodyear = false;
			cout << endl << TAB << "[Error!] Invalid year. \n";
		}

		else goodyear = true;
	}

	bool goodseats = false;
	unsigned int seats;
	while (!goodseats) {
		cout << endl << TAB;
		seats = get_input <unsigned int>("Please specify the number of seats of your car, including yours. [2|5|9]");
		if (seats != 2 && seats != 5 && seats != 9)
		{
			cout << endl << TAB << "[Error!] The number of seats you provided is not valid.\n";
			goodseats = false;
		}
		else goodseats = true;
	}

	bool goodrate = false;
	string rate;
	while (!goodrate) {
		cout << endl << TAB;
		rate = get_input <char>("In a scale [F(worst) - A (best)], please specify your evaluation of your car conditions.");

		if (rate != "A" && rate != "B" && rate != "C" && rate != "D" && rate != "E" && rate != "F")
		{
			cout << endl << TAB << "[Error!] Please give an evaluation in the provided scale.\n";
			goodrate = false;
		}
		else goodrate = true;
	}

	currentUser->getVehicle()->setRate(rate);
	currentUser->getVehicle()->setYear(year);
	currentUser->getVehicle()->setSeats(seats);
	currentUser->getVehicle()->setBrand(brand);
	currentUser->getVehicle()->setId(currentUser->getID());
	// adds route 
	bool routebool = false;
	string cityroute;
	string addroute;
	vector<string> rout(0);

	while (!routebool) {
		cout << endl << TAB;
		addroute = get_input <string>("Do you want do add a common route you do? [y|n]");

		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (addroute == "y") {

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
				rout.push_back(substr);
			}

			routebool = true;
			break;

		}
		else if (addroute == "n") {
			routebool = true;
			break;
		}
		else
			cout << endl << TAB << "Please insert \"y\" or \"n.\" \n";
		routebool = false;
	}

	currentUser->getVehicle()->setRoute(rout);

	cars.push_back(currentUser->getVehicle());
	usersalterados = true;
	carsalterados = true;
}
