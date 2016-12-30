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
		
		VehicleDBItem vUser = VehicleDBItem(currentUser->getVehicle());
		VehicleDBItem carfound = carsBST.find(vUser);

		carsBST.remove(carfound);

		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << TAB;
		cout << "Please specify its brand." << endl;
		string brand = readLine();

		cout << endl << TAB;
		cout << "Please specify its model." << endl;
		string model = readLine();

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

		carfound.getVehicle()->setRate(rate);
		carfound.getVehicle()->setYear(year);
		carfound.getVehicle()->setSeats(seats);
		carfound.getVehicle()->setBrand(brand);
		carfound.getVehicle()->setModel(model);
		carfound.getVehicle()->setId(currentUser->getID());

		carfound.setBrand(brand);
		carfound.setModel(model);
		carfound.setYear(year);

		carsBST.insert(carfound);

		currentUser->setVehicle(carfound.getVehicle());

		carsalterados = true;
		
		//for (size_t i = 0; i < cars.size(); i++) {
			//if (cars[i]->getID() == currentUser->getID()) {
				//cars[i] = currentUser->getVehicle();
				//break;
			//}
		//}

	}
			break;

	case 1: {
		
		VehicleDBItem vUser = VehicleDBItem(currentUser->getVehicle());
		VehicleDBItem carfound = carsBST.find(vUser);
		carsBST.remove(carfound);

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

		carfound.getVehicle()->setRoute(rout);
		
		carsBST.insert(carfound);
		currentUser->setVehicle(carfound.getVehicle());
		
		carsalterados = true;

	//	for (size_t i = 0; i < cars.size(); i++) {
		//	if (cars[i]->getID() == currentUser->getID()) {
			//	cars[i] = currentUser->getVehicle();
				//break;
			//}
		//}
		
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

			VehicleDBItem carfound = carsBST.find(currentUser->getVehicle());
			carsBST.remove(carfound);

			//size_t pos = getPositionCar(currentUser->getID());
			//cars.erase(cars.begin() + pos);

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
	cout << "Please specify its brand." << endl;
	string brand = readLine();

	cout << endl << TAB;
	cout << "Please specify its model." << endl;
	string model = readLine();

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
	currentUser->getVehicle()->setModel(model);
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

	VehicleDBItem car = VehicleDBItem(currentUser->getVehicle());

	//cars.push_back(currentUser->getVehicle());
	carsBST.insert(car);

	usersalterados = true;
	carsalterados = true;
}

void SharedRides::searchVehicle() {
	
	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	cout << endl << TAB;
	cout << "Please specify the brand of the car you want to search." << endl;
	string brand = readLine();

	cout << endl << TAB;
	cout << "Please specify its model of the car you want to search." << endl;
	string model = readLine();

	BSTItrIn<VehicleDBItem> it(carsBST);

	int contador = 0;
	while (!it.isAtEnd()) {
		if ((it.retrieve().getBrand() == brand) && (it.retrieve().getModel() == model)) {
			contador++;
		}
		it.advance();
	}
	
	if (contador == 0) {
		cout << endl << TAB << "There is no " << brand << " " << model << " registered in our system." << endl;
		_getch();
		return;
	}
	else if (contador == 1) cout << endl << TAB << "There is " << contador << " car avaiable:" << endl << endl;
	else cout << endl << TAB << "There are " << contador << " cars avaiable:" << endl << endl;
	
	BSTItrIn<VehicleDBItem> ita(carsBST);

	while (!ita.isAtEnd()) {

		if ( (ita.retrieve().getBrand() == brand) && (ita.retrieve().getModel() == model) ) {
			cout << *ita.retrieve().getVehicle() << endl;
			cout << endl << endl << "-------------------------------------------------------------------------" << endl << endl;
		}		
		
		ita.advance();
	}

}

void SharedRides::editVehicleOwner() {
	ClearScreen();
	header(" --- APP VEHICLES --- ", "admin");
	showCars();

	unsigned int owner = get_input <unsigned int>(
		TAB "Please input the owner/vehicle ID of the vehicle you want the owner change." "\n" 
		);

	bool ownerfound = false;
	cin.ignore(numeric_limits <streamsize>::max(), '\n');
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i]->getID() == owner) {
			ownerfound = true;

			bool foo = false;
			VehicleDBItem vUser = VehicleDBItem(users[i]->getVehicle());
			VehicleDBItem carfound = carsBST.find(vUser);

			while (!foo) {
				
				stringstream carandmodel;

				carandmodel << carfound.getYear() <<"'s " << carfound.getBrand() << " " << carfound.getModel();

				cout <<endl << TAB << "Are you sure you want to change the owner of " << carandmodel.str() << "? [y|n]" << endl << endl;
				
				string conf = readLine();

				if (conf == "y" || conf == "Y") {
					

					ClearScreen();
					header(" --- APP VEHICLES --- ", "admin");

					cout << "Wich user you want to define as the new owner of " << carandmodel.str() << "?" << endl << endl;

					showUsers();
					
					ownerfound = false;

					unsigned int new_owner = get_input <unsigned int>(
						TAB "Please input the ID of the new owner." "\n"
						);

					for (size_t j = 0; j < users.size(); j++) {

						if (users[j]->getID() == new_owner) {
							ownerfound = true;

							carsBST.remove(carfound);

							Vehicle * carnew = new Vehicle();
							users[i]->setVehicle(carnew);
							
							VehicleDBItem vUser2 = VehicleDBItem(users[j]->getVehicle());
							VehicleDBItem carfound2 = carsBST.find(vUser2);

							carsBST.remove(carfound2);
							
							
							carfound.getVehicle()->setId(users[j]->getID());
							users[j]->setVehicle(carfound.getVehicle());
							carsBST.insert(carfound);
							
							carsalterados = true;
						}
					}



					foo = true;
				}
				else if (conf == "n" || conf == "N")

					foo = true;

				else {
					cout << endl << TAB << "[ERROR] Please, input 'y' or 'n'." << endl;
					foo = false;
				}

			}
		}
	}

	if (ownerfound == false) throw UserNotFound<string>("[ERROR] User not found!");
}

void SharedRides::showCars() {
	if (carsBST.isEmpty()) {
		cout << endl << TAB << "No cars to show.\n" << endl;
		return;
	}

	BSTItrIn<VehicleDBItem> it(carsBST);
	int i = 0;
	cout << endl << "-------------------------------------------------------------------------" << endl << endl;

	while (!it.isAtEnd()) {
		cout << TAB << "Car no. " << i + 1 << endl << endl;
		cout << *it.retrieve().getVehicle();
		cout << endl << endl << "-------------------------------------------------------------------------" << endl << endl;

		i++;
		it.advance();
	}
}