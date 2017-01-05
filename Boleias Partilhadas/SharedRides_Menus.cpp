#include "Shared_Rides.h"
#include <Windows.h>


void SharedRides::header(string header,string who) const {
	cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
	cout << endl << TAB << header << endl << endl;
	if (who == "RU") cout << TAB << "-> You are currently logged as " << currentUser->getusername() << " <-" << endl << endl;
	else if (who == "guest") cout << TAB << "-> You are temporarily logged as " << currentUser->getusername() << " <-" << endl << endl;
	else if (who == "admin") cout << TAB << "-> You are currently logged with previlege rights as admin <-" << endl << endl;
}


void SharedRides::main_menu() {
	cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
	cout << endl;
	int choice = get_input <int>(
		TAB_BIG "[0] Enter as guest" "\n" "\n"
		TAB_BIG "[1] Login" "\n""\n"
		TAB_BIG "[2] Register" "\n""\n"
		TAB_BIG "[3] Exit and Save Changes to Files""\n");

	switch (choice) {
	case 0:
		guest_log();
		user_menu();//chama o menu de user (la dentro escolhe automaticamente menu de guest)
		break;
	case 1:
	{
		ClearScreen();
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- LOGIN MENU  --- " << endl;
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << TAB << "Please enter your username: \n";
		string usern = readLine();
		cout << endl <<  TAB;
		string pass = readPassword("Please enter your password:", true);

		if (usern == "admin") 
			if (pass == "admin") {
				ClearScreen();
				loading();
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
	}
		break;
	case 2:
		ClearScreen();
		loading();
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- REGISTRATION  --- " << endl;
		CreateRegis();
		Sleep(2000);
		ClearScreen();
		break;
	case 3:
		ClearScreen();
		return;
		break;
	default:
		cout << TAB << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;
	}
	ClearScreen();
	main_menu(); //always called. after done functions or bad inputs here, until exit app
}

void SharedRides::manage_menu(){
	header(" --- ADMIN HOMEPAGE --- ", "admin");
	
	int choice = get_input <int>(
		TAB_BIG "[0] App Trips" "\n"  "\n"//nestes 3 podemos usar os algoritmos de pesquisa para ver um x 
		TAB_BIG"[1] App Users" "\n""\n"	//algoritmos de ordenação para mostrar
		TAB_BIG"[2] Inative Users" "\n" "\n"
		TAB_BIG"[3] App Vehicles" "\n""\n"
		TAB_BIG"[4] End of Month" "\n""\n"
		TAB_BIG"[5] Set new tax" "\n""\n"
		TAB_BIG"[6] Log Off");
	float choice1 = 0;
	switch (choice) {
	case 0:
		header(" --- APP TRIPS --- ", "admin");
		ClearScreen();
		if (tripsPrinter.size() == 0) {
			cout << endl << TAB << "No trips to show.\n" << endl;
			_getch();
			break;
		}
	
		for (size_t i = 0; i < tripsPrinter.size(); i++) {
			cout << "Trip number " << i + 1 << endl << endl;
			cout << tripsPrinter[i] << endl << endl;
			cout << "----------------------------------------------------" << endl << endl;
		}
		_getch();
		break;
	case 1:
		ClearScreen();
		header(" --- APP USERS --- ", "admin");
		showUsers();
		_getch();
		break;
	case 2: {
		ClearScreen();
		header(" --- INACTIVE USERS --- ", "admin");

		unordered_set<User*, hstr, eqstr>::iterator it;

		it = inativos.begin();

		while (it != inativos.end()) {
			cout << *it << endl << endl;
			cout << " ------------------------------------------------------------------------- " << endl;
		}
	}
		_getch();
		break;
	case 3: {
		ClearScreen();
		header(" --- APP VEHICLES --- ", "admin");
		
		int choice2 = get_input <int>(
			TAB_BIG "[0] All App Vehicles" "\n"  "\n" 
			TAB_BIG"[1] Edit Vehicle Owner" "\n"	
			);

		switch (choice2) {
		case 0: {
			ClearScreen();
			header(" --- APP VEHICLES --- ", "admin");

			showCars();

			//for (size_t i = 0; i < cars.size(); i++) {
			//cout << TAB << "Car number " << i + 1 << endl << endl;
			//cout << *(cars[i]) << endl << Sendl;
			//cout << endl << "-------------------------------------------------------------------------" << endl << endl;
			//}

			_getch();
			break; 
		}
		case 1: {
			try {
				editVehicleOwner();
			}
			catch (UserNotFound<string> err)
			{
				cout << endl << TAB << err.info << endl;
				_getch();
				ClearScreen();
				return manage_menu();
			}
			break; 
		}

		default:
			cout << TAB << "Please, input an integer suitable to the options shown." << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			break;
		}

		break;
	}
		break;
	case 4: {
		ClearScreen();
		header(" --- END OF MONTH --- ", "admin");

		for (size_t i = 0; i < users.size(); i++) {
			if (dynamic_cast<RegisteredUser*>(users[i]) == NULL) continue;
			if (users[i]->getVehicle()->getYear() == 0)
				users[i]->chargeAccount(-(this->TAX + users[i]->getnumTrips()));
			else users[i]->chargeAccount(-(this->TAX));
		}

		cout << TAB << "SUCCESS! The billings were applied to all users.\n\n" << endl;
		_getch();
		break;
	}
		break;
	case 5:
		ClearScreen();
		header(" --- TAX --- ", "admin");
		
		cout <<TAB<< "The current TAX is: " << this->TAX << endl<<endl;
		
		while (true) {

			choice1 = get_input <float>(TAB"Please define the new TAX.");
			if (choice1 > 0)
				break;
			cout <<endl<<TAB<< "[ERROR!] Please, input a positive TAX." << endl;
		}

		this->TAX = choice1;

		cout << endl <<TAB<< "SUCCESS! The new TAX is: " << this->TAX << endl;
		_getch();
		break;
	case 6:
		currentUser = NULL;
		return;
		break;
	default:
		cout <<TAB<< "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;

	}
	ClearScreen();
	manage_menu();
}

void SharedRides::user_menu(){
	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) { //isto da erro porque nao temos uma

		header(" --- USER HOMEPAGE --- ","RU");

		if (currentUser->getVehicle()->getnumberSeats() != 0) { //currentUser has a CAR			
		
				int choice = get_input <int>(
				TAB_BIG"[0] My Trips" "\n""\n"
				TAB_BIG"[1] Vehicle" "\n""\n"  //remove/edit vehicle inside
				TAB_BIG"[2] Search Vehicle" "\n""\n" // search for a vehicle in the system
				TAB_BIG"[3] New Trip" "\n""\n"     // add/start/enter trip (start begins an added trip) inside
				TAB_BIG"[4] Buddies" "\n" "\n"  //add/remove/see(profile/trips) buddies inside
				TAB_BIG"[5] Charge wallet" "\n""\n"
				TAB_BIG"[6] Change profile" "\n""\n"
				TAB_BIG"[7] Delete Profile" "\n" "\n"
				TAB_BIG"[8] Log Off" "\n""\n");

			switch (choice) {
			case 0:
				ClearScreen();
				header(" --- TRIPS --- ","RU");
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				header(" --- VEHICLE --- ", "RU");
				cout <<endl<< TAB << "Right now you have " << currentUser->getVehicle()->getBrand() << " " << currentUser->getVehicle()->getModel() << " associated to your account." << endl << endl;

				userWithVehicleMenu();
				Sleep(3000);
				break;
			case 2: {
				ClearScreen();
				header(" --- SEARCH VEHICLE ---", "RU");
				searchVehicle();
				_getch();
				break;
			}
			case 3:
				ClearScreen();
				header(" --- NEW TRIP --- ","RU");

				VehicleTripMenu();
				_getch();
				break;
			case 4:
				ClearScreen();
				header(" --- BUDDIES --- ", "RU");

				buddiesMenu();
				_getch();
				break;
			case 5:
				ClearScreen();
				header(" --- CREDDIT ACCOUNT --- ", "RU");
				creditAccount();
				Sleep(2000);
				break;
			case 6:
				ClearScreen();
				header(" --- CHANGE PROFILE --- ", "RU");
				changeProfile();
				Sleep(2000);
				break;
			case 8:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				header(" --- DELETE ACCOUNT --- ", "RU");
				deleteAccount();
				_getch();
				return;
				break;
			default:
				cout <<TAB<< "Please, input an integer suitable to the options shown." << endl;
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				break;
			}
		}
		else { //currentUSER does not have a car
			cout << TAB << "You don't have any car associated to your account." << endl << endl;
			int choice = get_input <int>(
				TAB_BIG"[0] My Trips" "\n""\n"
				TAB_BIG"[1] Add Vehicle" "\n" "\n" //add vehicle inside
				TAB_BIG"[2] Search Vehicle" "\n" "\n" // searches for a specific vehicle
				TAB_BIG"[3] New Trip" "\n" "\n"    // enter trip (start begins an added trip) inside
				TAB_BIG"[4] Buddies" "\n" "\n"  //add/remove/see(profile/trips) buddies inside
				TAB_BIG"[5] Charge wallet" "\n""\n"
				TAB_BIG"[6] Change profile" "\n""\n"
				TAB_BIG"[7] Delete Profile" "\n" "\n"
				TAB_BIG"[8] Log Off" "\n""\n");
			switch (choice) {
			case 0:
				ClearScreen();
				header(" --- TRIPS --- ", "RU");
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				header(" --- ADD VEHICLE --- ", "RU");
				addVehicle();
				Sleep(2000);
				break;
			case 2: {
				ClearScreen();
				header(" --- SEARCH VEHICLE ---", "RU");
				searchVehicle();
				break;
			}
			case 3:
				ClearScreen();
				header(" --- ENTER TRIP --- ", "RU");
				enterTrip();
				_getch();
				break;
			case 4:
				ClearScreen();
				header(" --- BUDDIES --- ", "RU");
				buddiesMenu();
				_getch();
				break;
			case 5:
				ClearScreen();
				header(" --- CREDIT ACCOUNT --- ", "RU");
				creditAccount();
				Sleep(2000);
				break;
			case 6:
				ClearScreen();
				header(" --- CHANGE PROFILE --- ", "RU");
				changeProfile();
				Sleep(2000);
				break;
			case 8:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				header(" --- DELETE ACCOUNT --- ", "RU");
				deleteAccount();
				_getch();
				return;
				break;
			default:
				cout <<TAB<< "Please, input an integer suitable to the options shown." << endl;
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				break;
			}
		}

	}
	else { // guest user
		ClearScreen();
		header(" --- GUEST HOMEPAGE --- ", "guest");
		int choice = get_input <int>(
			TAB_BIG"[0] Search Vehicle" "\n" "\n" // search for vhile
			TAB_BIG"[1] New Trip" "\n"   "\n"  // look for a trip
			TAB_BIG"[2] Charge wallet" "\n""\n"
			TAB_BIG"[3] Exit App");

		switch (choice) {
		case 0: {
			ClearScreen();
			header(" --- SEARCH VEHICLE ---", "RU");
			searchVehicle();
			break;
		}
		
		case 1:
			ClearScreen();
			header(" --- NEW TRIP --- ", "guest");
			enterTrip();
			_getch();
			break;
		case 2:
			ClearScreen();
			header(" --- WALLET --- ", "guest");
			creditAccount();
			Sleep(2000);
			break;
		case 3:
			currentUser = NULL; //resets currentUser,
			return; //returns to main_menu
			break;
		default:
			cout <<TAB<< "Please, input an integer suitable to the options shown." << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			break;
		}
	}
	ClearScreen();
	user_menu();//always called. after done functions or bad inputs here,
				//until logoff/delete profile or exitApp in guest
}