#include "Helper.h"
#include "Shared_Rides.h"
#include <Windows.h>


void SharedRides::main_menu() {
	cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
	cout << endl;
	int choice = get_input <int>(
		TAB_BIG "[0] Enter as guest" "\n" "\n"
		TAB_BIG "[1] Login" "\n""\n"
		TAB_BIG "[2] Register" "\n""\n"
		TAB_BIG "[3] Exit""\n");

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
		break;
	}
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
	cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
	cout << endl << TAB << " --- ADMIN HOMEPAGE --- " << endl << endl;
	cout << TAB << "-> You are currently logged as admin <- "<< endl << endl;
	
	int choice = get_input <int>(
		TAB_BIG "[0] App Trips" "\n"  "\n"//nestes 3 podemos usar os algoritmos de pesquisa para ver um x 
		TAB_BIG"[1] App Users" "\n""\n"	//algoritmos de ordenação para mostrar
		TAB_BIG"[2] App Vehicles" "\n""\n"
		TAB_BIG"[3] End of Month" "\n""\n"
		TAB_BIG"[4] Set new tax" "\n""\n"
		TAB_BIG"[5] Log Off");
	float choice1 = 0;
	
	switch (choice) {
	case 0:
		ClearScreen();
		if (tripsPrinter.size() == 0) {
			cout << endl << TAB << "No trips to show.\n" << endl;
			_getch();
			break;
		}
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- APP TRIPS --- " << endl << endl;
		cout << endl << "-------------------------------------------------------------------------" << endl << endl;
		for (size_t i = 0; i < tripsPrinter.size(); i++) {
			cout << "Trip number " << i + 1 << endl << endl;
			cout << tripsPrinter[i] << endl << endl;
			cout << "----------------------------------------------------" << endl << endl;
		}
		_getch();
		break;
	case 1:
		ClearScreen();
		if (users.size() == 0) {
			cout << endl << TAB << "No trips to show.\n" << endl;
			_getch();
			break;
		}
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- APP USERS --- " << endl << endl;
		cout << endl << "-------------------------------------------------------------------------" << endl << endl;
		for (size_t i = 0; i < users.size(); i++) {
			cout<< TAB << "User with ID " << users[i]->getID() << endl;
			users[i]->showProfile();
			cout << endl << "-------------------------------------------------------------------------" << endl << endl;
		}
		_getch();
		break;
	case 2: {
		if (cars.size() == 0) {
			cout << endl << TAB << "No trips to show.\n" << endl;
			_getch();
			break;
		}
		ClearScreen();
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- APP CARS --- " << endl << endl;
		cout << endl << "-------------------------------------------------------------------------" << endl << endl;
		for (size_t i = 0; i < cars.size(); i++) {
			cout << TAB << "Car number " << i + 1 << endl << endl;
			cout << *(cars[i]) << endl << endl;
			cout << endl << "-------------------------------------------------------------------------" << endl << endl;
		}
		cout << endl << endl << "------------------------------- BST PRINT TABLE ----------------------------------------" << endl << endl;

		BSTItrIn<Vehicle*> it(carsBST);
		int i = 1;

		while (!it.isAtEnd()) {
			cout << TAB << "Car number " << i << endl << endl;
			cout << *it.retrieve() << endl << endl;
			cout << endl << "-------------------------------------------------------------------------" << endl << endl;
			i++;
			it.advance();
		}
		cout << endl << endl;
		carsBST.printTree();
		_getch();
		break; 
	}
	case 3:
		for (size_t i = 0; i < users.size(); i++) {
			if (users[i]->getVehicle()->getYear() == 0)
				users[i]->chargeAccount(-(this->TAX + users[i]->getnumTrips()));
			else users[i]->chargeAccount(-(this->TAX));
		}
		ClearScreen();
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- END OF MONTH --- " << endl << endl;

		cout << TAB << "SUCCESS! The billings were applied to all users.\n\n" << endl;
		_getch();
		break;
	case 4:
		ClearScreen();
		cout << endl << TAB << "Welcome to Shared Rides V.1.0. Please put your seatbelts on and enjoy your travel." << endl;
		cout << endl << TAB << " --- TAX --- " << endl << endl;
		
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
	case 5:
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

		header(" --- USER HOMEPAGE --- ");

		if (currentUser->getVehicle()->getnumberSeats() != 0) { //currentUser has a CAR			
		
				int choice = get_input <int>(
				TAB_BIG"[0] My Trips" "\n""\n"
				TAB_BIG"[1] Vehicle" "\n""\n"  //remove/edit vehicle inside
				TAB_BIG"[2] New Trip" "\n""\n"     // add/start/enter trip (start begins an added trip) inside
				TAB_BIG"[3] Buddies" "\n" "\n"  //add/remove/see(profile/trips) buddies inside
				TAB_BIG"[4] Charge wallet" "\n""\n"
				TAB_BIG"[5] Change profile" "\n""\n"
				TAB_BIG"[6] Log Off" "\n""\n"
				TAB_BIG"[7] Delete Profile");

			switch (choice) {
			case 0:
				ClearScreen();
				header(" --- TRIPS --- ");
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				header(" --- VEHICLE --- ");
				cout <<endl<< TAB << "Right now you have " << currentUser->getVehicle()->getBrand() << " associated to your account." << endl << endl;

				userWithVehicleMenu();
				Sleep(3000);
				break;
			case 2:
				ClearScreen();
				header(" --- NEW TRIP --- ");

				VehicleTripMenu();
				_getch();
				break;
			case 3:
				ClearScreen();
				header(" --- BUDDIES --- ");
				buddiesMenu();
				_getch();
				break;
			case 4:
				ClearScreen();
				header(" --- CREDDIT ACCOUNT --- ");
				creditAccount();
				Sleep(2000);
				break;
			case 5:
				ClearScreen();
				header(" --- CHANGE PROFILE --- ");
				changeProfile();
				Sleep(2000);
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				header(" --- DELETE ACCOUNT --- ");
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
				TAB_BIG"[2] New Trip" "\n" "\n"    // enter trip (start begins an added trip) inside
				TAB_BIG"[3] Buddies" "\n" "\n"  //add/remove/see(profile/trips) buddies inside
				TAB_BIG"[4] Charge wallet" "\n""\n"
				TAB_BIG"[5] Change profile" "\n""\n"
				TAB_BIG"[6] Log Off" "\n""\n"
				TAB_BIG"[7] Delete Profile");
			switch (choice) {
			case 0:
				ClearScreen();
				header(" --- TRIPS --- ");
				showTrips();
				_getch();
				break;
			case 1:
				ClearScreen();
				header(" --- ADD VEHICLE --- ");
				addVehicle();
				Sleep(2000);
				break;
			case 2:
				ClearScreen();
				try { enterTrip(); }
				catch (TripEnterException<string> err)
				{
					cout << err.info << endl;
					Sleep(2000);  //only in windows (?)
					_getch();
					ClearScreen();					
					return user_menu();
				}
				break;
			case 3:
				ClearScreen();
				header(" --- BUDDIES --- ");
				buddiesMenu();
				_getch();
				break;
			case 4:
				ClearScreen();
				header(" --- CREDIT ACCOUNT --- ");
				creditAccount();
				Sleep(2000);
				break;
			case 5:
				ClearScreen();
				header(" --- CHANGE PROFILE --- ");
				changeProfile();
				Sleep(2000);
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
				ClearScreen();
				header(" --- DELETE ACCOUNT --- ");
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
		header(" --- GUEST HOMEPAGE --- ");

		int choice = get_input <int>(

			TAB_BIG"[0] New Trip" "\n"   "\n"  // look for a trip
			TAB_BIG"[1] Charge wallet" "\n""\n"
			TAB_BIG"[2] Exit App");

		switch (choice) {
		case 0:
			ClearScreen();
			try { enterTrip(); }
			catch (TripEnterException<string> err)
			{
				cout << err.info << endl;
				Sleep(2000);  //only in windows (?)
				ClearScreen();
				return user_menu();
			}
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
			cout <<TAB<< "Please, input an integer suitable to the options shown." << endl;
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			break;
		}
	}
	ClearScreen();
	user_menu();//always called. after done functions or bad inputs here,
				//until logoff/delete profile or exitApp in guest
}