#include "Helper.h"
#include "Shared_Rides.h"
#include <Windows.h>


void SharedRides::main_menu() {

	cout << endl << "Welcome to Shared Rides, please put your seatbelts on and enjoy your travel." << endl;

	int choice = get_input <int>(
		"[0] Enter as guest" "\n"
		"[1] Login" "\n"
		"[2] Register" "\n"
		"[3] Exit");



	switch (choice) {
	case 0:
		//criar um menu de login sem password para guest
		//user_menu();//chama o menu de user (la dentro escolhe automaticamente menu de guest)
		break;
	case 1:
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << "Username: \n";
		string usern = readLine();
		string pass = readPassword("Password:", true);

		if (usern == "admin") 
			if (pass == "admin") {
				ClearScreen();
				manage_menu();
				break;
			}
		try {
			currentUser = login(usern, pass);
		}
		catch (LoginException<string> err)
		{
			cout << err.info << endl;
			Sleep(2000);  //only in windows (?)
			ClearScreen();
			return main_menu();
		}
		ClearScreen();
		user_menu(); //chama o menu de user(Seja ele carro, sem carro)
		break;
	}
	case 2:
		CreateRegis();
		Sleep(2000);
		ClearScreen();
		break;
	case 3:
		ClearScreen();
		return;
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;
	}
	ClearScreen();
	main_menu(); //always called. after done functions or bad inputs here, until exit app
}

void SharedRides::manage_menu(){
	//por aqui função que pede login com username admin e password admin
	int choice = get_input <int>(
		"[0] App Trips" "\n"   //nestes 3 podemos usar os algoritmos de pesquisa para ver um x 
		"[1] App Users" "\n"	//algoritmos de ordenação para mostrar
		"[2] App Vehicles" "\n"
		"[3] End of Month" "\n"
		"[4] Set Billings" "\n"
		"[5] Log Off");
	float choice1 = 0;
	switch (choice) {
	case 0:
		ClearScreen();
		cout << "\tApp Trips:\n\n";
		for (size_t i = 0; i < tripsPrinter.size(); i++) {
			cout << "Trip " << i + 1 << endl;
			cout << tripsPrinter[i] << endl << endl;
		}
		_getch();
		break;
	case 1:
		ClearScreen();
		cout << "\tApp Users:\n\n";
		for (size_t i = 0; i < users.size(); i++) {
			cout << "User " << i + 1 << endl;
			users[i]->showProfile();
			cout << endl << endl;
		}
		_getch();
		break;
	case 2:
		ClearScreen();
		cout << "\tApp Cars:\n\n";
		for (size_t i = 0; i < cars.size(); i++) {
			cout << "Car " << i + 1 << endl;
			cout << *(cars[i]) << endl << endl;
		}
		_getch();
		break;
	case 3:
		for (size_t i = 0; i < users.size(); i++) {
			if (users[i]->getVehicle()->getYear() == 0)
				users[i]->chargeAccount(-(this->TAX + users[i]->getnumTrips()));
			else users[i]->chargeAccount(-(this->TAX));
		}
		cout << "\n\t Billings Applied.\n\n" << endl;
		_getch();
		break;
	case 4:
		cout << "\tCurrent TAX is: " << this->TAX << endl;
		while (true) {
			choice1 = get_input <float>("\tNew TAX? ");
			if (choice1 > 0)
				break;
			cout << "Please, input a positive TAX." << endl;
		}
		this->TAX = choice1;
		cout << "\tThe new TAX is: " << this->TAX << endl;
		_getch();
		break;
	case 5:
		currentUser = NULL;
		return;
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;

	}
	ClearScreen();
	manage_menu();
}

void SharedRides::user_menu(){
	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) { //isto da erro porque nao temos uma
		//função virtual em user, mas vamos ter, por isso deixa assim

		if (currentUser->getVehicle()->getID() != 0) { //currentUser has a CAR			
		
			int choice = get_input <int>(
				"[0] My Trips" "\n"
				"[1] Vehicle" "\n"  //remove/edit vehicle inside
				"[2] New Trip" "\n"     // add/start/enter trip (start begins an added trip) inside
				"[3] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
				"[4] Charge wallet" "\n"
				"[5] Change profile" "\n"
				"[6] Log Off" "\n"
				"[7] Delete Profile");

			switch (choice) {
			case 0:
				ClearScreen();
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				userWithVehicleMenu();
				Sleep(2000);
				break;
			case 2:
				ClearScreen();
				VehicleTripMenu();
				_getch();
				break;
			case 3:
				ClearScreen();
				buddiesMenu();
				_getch();
				break;
			case 4:
				ClearScreen();
				creditAccount();
				Sleep(2000);
				break;
			case 5:
				ClearScreen();
				changeProfile();
				Sleep(2000);
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				deleteAccount();
				_getch();
				return;
				break;
			default:
				cout << "Please, input an integer suitable to the options shown." << endl;
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				break;
			}
		}
		else { //currentUSER does not have a car
			int choice = get_input <int>(
				"[0] My Trips" "\n"
				"[1] Add Vehicle" "\n"  //add vehicle inside
				"[2] New Trip" "\n"     // enter trip (start begins an added trip) inside
				"[3] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
				"[4] Charge wallet" "\n"
				"[5] Change profile" "\n"
				"[6] Log Off" "\n"
				"[7] Delete Profile");

			switch (choice) {
			case 0:
				ClearScreen();
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				addVehicle();
				Sleep(2000);
				break;
			case 2:
				ClearScreen();
				enterTrip();
				_getch();
				break;
			case 3:
				ClearScreen();
				buddiesMenu();
				_getch();
				break;
			case 4:
				ClearScreen();
				creditAccount();
				Sleep(2000);
				break;
			case 5:
				ClearScreen();
				changeProfile();
				Sleep(2000);
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				deleteAccount();
				_getch();
				return;
				break;
			default:
				cout << "Please, input an integer suitable to the options shown." << endl;
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				break;
			}
		}

	}
	else { // guest user

		int choice = get_input <int>(
			"[0] New Trip" "\n"     // look for a trip
			"[1] Charge wallet" "\n"
			"[2] Exit App");

		switch (choice) {
		case 0:
			ClearScreen();
			enterTrip();
			_getch();
			break;
		case 1:
			ClearScreen();
			creditAccount();
			Sleep(2000);
			break;
		case 2:
			currentUser = NULL; //resets currentUser,
			return; //returns to main_menu
			break;
		default:
			cout << "Please, input an integer suitable to the options shown." << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			break;
		}
	}
	ClearScreen();
	user_menu();//always called. after done functions or bad inputs here,
				//until logoff/delete profile or exitApp in guest
}