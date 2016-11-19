#include "Menus.h"
#include "Helper.h"
#include "Shared_Rides.h"
#include <Windows.h>


void SharedRides::main_menu() {
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
		cout << "Username: ";
		string usern = readLine();
		cout << "Password: ";
		string pass = readLine();
		
		try {
			currentUser = login(usern, pass);
			if (currentUser->getusername() == "admin")
				manage_menu();
			else user_menu(); //chama o menu de user(Seja ele carro, sem carro)
		}
		catch (LoginException<string> err)
		{
			cout << err.info << endl;
			Sleep(800);  //only in windows (?)
			return main_menu();
		}
		break;
	}
	case 2:
		CreateRegis();
		//main_menu();
		break;
	case 3:
		return;
		break;
	default:
		cout << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		break;
	}
	main_menu(); //always called. after done functions or bad inputs here, until exit app
}

void SharedRides::manage_menu(){
	//por aqui função que pede login com username admin e password admin
	int choice = get_input <int>(
		"[0] App Trips" "\n"   //nestes 3 podemos usar os algoritmos de pesquisa para ver um x 
		"[1] App Users" "\n"	//algoritmos de ordenação para mostrar
		"[2] App Vehicles" "\n"
		"[3] End of Month" "\n"
		"[4] Remove user" "\n"
		"[5] Log Off");



	switch (choice) {
	case 1:
		//login();
		break;
	case 2:
		//SharedRides::CreateRegis();
		break;
	}
}

void SharedRides::user_menu(){
	if (dynamic_cast<RegisteredUser*>(currentUser) != NULL) { //isto da erro porque nao temos uma
		//função virtual em user, mas vamos ter, por isso deixa assim

		if (currentUser->getVehicle()->getCarID() != 0) { //currentUser has a CAR			
		
			int choice = get_input <int>(
				"[0] My Trips" "\n"
				"[1] Vehicle" "\n"  //remove/edit vehicle inside
				"[2] New Trip" "\n"     // add/start trip (start begins an added trip) inside
				"[3] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
				"[4] Charge wallet" "\n"
				"[5] Change profile" "\n"
				"[6] Log Off" "\n"
				"[7] Delete Profile");

			switch (choice) {
			case 0:
				showTrips();
				break;
			case 1:
				userWithVehicleMenu();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
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
				"[2] New Trip" "\n"     // add/start trip (start begins an added trip) inside
				"[3] Buddies" "\n"   //add/remove/see(profile/trips) buddies inside
				"[4] Charge wallet" "\n"
				"[5] Change profile" "\n"
				"[6] Log Off" "\n"
				"[7] Delete Profile");



			switch (choice) {
			case 0:
				showTrips();
				break;
			case 1:
				addVehicle();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				currentUser = NULL; //logs off
				return; //returns to main_menu
				break;
			case 7:
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
			//login();
			break;
		case 1:
			//SharedRides::CreateRegis();
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
	user_menu();//always called. after done functions or bad inputs here,
				//until logoff/delete profile or exitApp in guest
}