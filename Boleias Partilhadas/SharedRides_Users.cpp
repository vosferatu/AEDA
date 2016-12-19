#include "Shared_Rides.h"

using namespace std;
// User-specific functions

void SharedRides::CreateRegis()
{

	// gets username
	bool userexists = true;
	string username;

	while (userexists) {
		cout << endl;
		username = get_input <string>(TAB"Please enter a username.");
		cout << endl << TAB << "Username: " << username << "\n" << endl;

		if (users.size() == 0)
			userexists = false;

		bool uservec = false;

		for (size_t i = 0; i < users.size(); i++) {
			if (users[i]->getusername() == username)
				uservec = true;
		}

		if (uservec == true)
		{
			cout << TAB << "[ERROR!] Username already exists!\n";
			userexists = true;
		}
		else userexists = false;


	}

	// gets password
	cout << TAB;
	string password1 = readPassword("Please enter password", true);
	cout << endl << endl << TAB;
	string password2 = readPassword("Please re-enter password", true);

	while (password1 != password2) {
		cout << TAB << "\nError! Passwords do not match." "\n\n";
		cout << TAB;
		password1 = readPassword("Please enter password", true);
		cout << endl << endl << TAB;
		password2 = readPassword("Please re-enter password", true);

	}

	//gets city
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool citybelong = false;
	string city;

	while (!citybelong) {

		cout << endl << endl << TAB << "Please specify your home city." << endl << TAB << "It must belong to one of these: ";

		for (size_t i = 0; i < cities.size(); i++)
		{
			if (i < cities.size() - 1)
				cout << cities[i] << ", ";
			else cout << cities[i] << ".\n";
		}

		city = readLine();

		for (size_t i = 0; i < cities.size(); i++) {
			if (city == cities[i])
				citybelong = true;
		}

	}
	// gets vehicle
	bool vehiclebool = false;
	string addvehicle;


	while (!vehiclebool)
	{
		cout << endl << TAB;
		addvehicle = get_input <string>("Do you want to add a vehicle? [y|n]");

		if (addvehicle == "y") {
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

					//bool total = false;
					//for (size_t i = 0; i < rout.size(); i++) {
					//	if (!total) {
					//		for (size_t j = 0; j < cities.size(); j++) { // vetor principal 
					//			if (cities[j] == rout[i])
					//				break;                           // se encontrou para 
					//			else if (j == cities.size() - 1) {		   //se chegou ao fim sem encontrar, é porque
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
					cout << endl << TAB << "Please insert \"y\" or \"n.\" \n";
				routebool = false;
			}


			Vehicle* v1 = new Vehicle(seats, brand, year, rate);
			v1->setRoute(rout);
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
			Vehicle* nocar = new Vehicle();

			RegisteredUser* RU = new RegisteredUser(username, password1, city, nocar);

			users.push_back(RU);
			usersalterados = true;
			vehiclebool = true;
		}
		else
		{
			cout << endl << TAB << "[Error!] Please enter y or n." << endl;
			vehiclebool = false;
		}

	}

	cout << endl << TAB << "SUCCESS! Your account has been created. Now you have to Login to confirm your account.\n";
}

void SharedRides::creditAccount() {
	cout << endl << TAB << "Your current balance: $" << currentUser->getAccount() << endl << endl;

	float novo = 0.0;
	while (true) {
		novo = get_input <float>(TAB "How much do you want to credit your acount? (X.Y)" "\n" TAB "(Input 0 if you selected the wrong menu and want to go back)");
		if (novo < 0) {
			cout << endl << TAB << "Cannot charge negative values" << endl;
			continue;
		}
		if (novo == 0)
			return;

		currentUser->chargeAccount(novo);

		break;
	}
	cout << endl << TAB << "SUCCESS! Your new balance is $" << currentUser->getAccount() << endl;
	usersalterados = true;
}

void SharedRides::changeProfile() {
	cout << endl;
	currentUser->showProfile();
	cout << endl;
	int choice = get_input <int>(
		TAB_BIG"[0] Edit my password" "\n""\n"
		TAB_BIG"[1] Edit my city" "\n");

	switch (choice) {
	case 0: {
		cout << TAB;
		string password1 = readPassword("Please enter the new password", true);
		cout << endl << TAB;
		string password2 = readPassword("Please re-enter the new password", true);

		while (password1 != password2) {
			cout << TAB << "Error! Passwords do not match." "\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			cout << TAB;

			password1 = readPassword("Please enter password", true);
			cout << endl << TAB;
			password2 = readPassword("Please re-enter password", true);

		}
		currentUser->setPassword(password1);
		cout << endl << TAB << "SUCCESS! Your password was edited.\n";
	}
			break;
	case 1: {
		bool citybelong = false;
		string city;
		while (!citybelong) {
			cout << endl << TAB << "Please specify your home city." << endl << TAB << "It must belong to one of these: ";

			for (size_t i = 0; i < cities.size(); i++) {
				if (i < cities.size() - 1)
					cout << cities[i] << ", ";
				else cout << cities[i] << ".\n";
			}
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			city = readLine();
			for (size_t i = 0; i < cities.size(); i++)
			{
				if (city == cities[i])
					citybelong = true;
			}
		}
		currentUser->setHome(city);
		cout << endl << TAB << "SUCCESS! Your home city was edited.\n";
	}
			break;
	default:
		cout << endl << TAB << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		changeProfile();
		break;
	}
	usersalterados = true;
}

void SharedRides::deleteAccount() {
	string remaccount;

	while (true) {
		cout << endl;
		remaccount = get_input <string>(TAB"Do you want to remove your account? [y|n]");
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
			usersalterados = true;
			carsalterados = true;
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

void SharedRides::guest_log() {
	bool userexists = true;
	string username;

	while (userexists) {
		cout << endl;
		username = get_input <string>(TAB"Please enter a username.");
		cout << endl << TAB << "Username: " << username << "\n" << endl;

		if (users.size() == 0)
			userexists = false;

		bool uservec = false;

		for (size_t i = 0; i < users.size(); i++) {
			if (users[i]->getusername() == username)
				uservec = true;
		}

		if (uservec == true)
		{
			cout << TAB << "[ERROR!] Username already exists!\n";
			userexists = true;
		}
		else userexists = false;
	}
	User* u1 = new GuestUser(username);
	users.push_back(u1);
	usersalterados = true;
	currentUser = u1;
}
