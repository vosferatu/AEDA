#include "Shared_Rides.h"

using namespace std;



bool SharedRides::checkBuddie(unsigned int user1) {
	for (size_t i = 0; i < currentUser->getFavs().size(); i++) {
		if (user1 == currentUser->getFavs()[i])
			return true;
	}
	return false;
}

void SharedRides::buddiesMenu() {
	cout << endl << TAB << "You have ";
	cout << currentUser->getFavs().size() << " buddies." << endl << endl;

	int choice = get_input <int>(
		TAB_BIG"[0] Follow a Buddie" "\n""\n"
		TAB_BIG"[1] Unfollow a Buddie" "\n""\n"
		TAB_BIG"[2] See my Buddies" "\n""\n"
		);

	switch (choice) {
	case 0:
		addBuddie();
		usersalterados = true;
		break;
	case 1:
		removeBuddie();
		usersalterados = true;
		break;
	case 2:
		myBuddies();
		break;
	default:
		cout << endl << TAB << "Please, input an integer suitable to the options shown." << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		buddiesMenu();
		break;
	}
}

void SharedRides::addBuddie() {
	int counter = 0;
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i]->getCity() == currentUser->getCity())
			counter++;
	}
	int number = 0;
	if (counter != 0) {
		cout << "Users near you:" << endl;
		for (size_t i = 0; i < users.size(); i++) {
			if ((users[i]->getCity() == currentUser->getCity()) && (users[i] != currentUser)) {
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
			}
		}
		cout << endl << "Other users:" << endl;
		for (size_t i = 0; i < users.size(); i++) {
			if ((users[i]->getCity() != currentUser->getCity()) && (users[i] != currentUser)) {
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
			}
		}
	}
	else {
		for (size_t i = 0; i < users.size(); i++) {
			if (users[i] != currentUser) {
				number = i + 1;
				cout << "User number " << number << endl;
				users[i]->showProfile();
			}
		}
	}

	unsigned int choice;
	while (true) {
		choice = get_input <unsigned int>(
			"\tSelect one of the users, by their number identifier." "\n"
			);
		if ((choice > 0) && (choice < users.size() + 1) && (choice - 1 != currentUser->getID()))
			break;
		else cout << "Input a valid number!" << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}
	vector<int> novo = currentUser->getFavs();
	novo.push_back(users[choice - 1]->getID());
	currentUser->setFavs(novo);
	cout << endl << users[choice - 1]->getusername() << " is now one of your buddies." << endl;
	usersalterados = true;
}

void SharedRides::removeBuddie() {
	size_t user = getPositionUser(currentUser->getID());
	vector<int> fav = users[user]->getFavs();

	for (size_t i = 0; i < fav.size(); i++) {
		size_t j = getPositionUser(fav[i]);
		cout << "Buddie number " << i + 1 << ":\n";
		users[j]->showProfile();
		cout << endl;
	}

	unsigned int choice;
	while (true) {
		choice = get_input <unsigned int>(
			"\tSelect one of your buddies, by their number identifier." "\n"
			);
		if ((choice > 0) && (choice < currentUser->getFavs().size() + 1))
			break;
		else cout << "Input a valid number!" << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}
	vector<int> novo = currentUser->getFavs();
	novo.erase(novo.begin() + (choice - 1));
	currentUser->setFavs(novo);
	size_t amigo = getPositionUser(currentUser->getFavs()[choice - 1]);
	cout << endl << users[amigo]->getusername() << " is no longer one of your Buddies." << endl;
	usersalterados = true;
}

void SharedRides::myBuddies() const {
	size_t user = getPositionUser(currentUser->getID());
	vector<int> fav = users[user]->getFavs();
	vector<int> nearfav{};
	vector<int> farfav{};
	for (size_t i = 0; i < fav.size(); i++) {
		size_t j = getPositionUser(fav[i]);
		if (users[j]->getCity() == users[user]->getCity())
			nearfav.push_back(j);
		else farfav.push_back(j);
	}
	nearfav.insert(nearfav.end(), farfav.begin(), farfav.end());

	for (size_t i = 0; i < nearfav.size(); i++) {
		cout << "Buddie number " << nearfav[i] + 1 << ":\n";
		users[nearfav[i]]->showProfile();
		cout << endl;
	}

	string seetrip;
	while (true) {
		seetrip = get_input <string>("Do you want to see Buddies Trips? [y|n]");
		cin.ignore(numeric_limits <streamsize>::max(), '\n');

		if (seetrip == "y") {
			break;
		}

		if (seetrip == "n") {
			cout << "Getting back..." << endl;
			return;
		}
		else cout << "Error! Please enter y or n." << endl;
	}

	unsigned int choice;
	bool can = false;
	while (true) {
		choice = get_input <unsigned int>(
			"\tSelect on of your buddies, by their number identifier, to see their trips." "\n"
			);
		for (size_t i = 0; i < nearfav.size(); i++) {
			if (choice == nearfav[i] + 1) {
				can = true;
				break;
			}
		}
		if ((choice >= 0) && (choice < users.size() + 1) && (can == true))
			break;
		else cout << "Input a valid number!" << endl;
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
	}

	if (users[choice - 1]->getnumTrips() == 0) {
		cout << endl << "\t" << users[choice - 1]->getusername() << " has no trips in his history!" << endl;
	}

	vector<int> vec = users[choice - 1]->getTrips();
	cout << endl << "\tViagens de " << users[choice - 1]->getusername() << " :\n";
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < tripsPrinter.size(); j++) {
			if (tripsPrinter[j].getTripCode() == vec[i]) {
				cout << "Trip number " << i + 1 << endl;
				cout << tripsPrinter[j] << endl;
				break;
			}
		}
	}
}

void SharedRides::showBuddiesProfileToUser() {
	size_t user = getPositionUser(currentUser->getID());
	vector<int> fav = users[user]->getFavs();

	for (size_t i = 0; i < fav.size(); i++) {
		size_t j = getPositionUser(fav[i]);
		cout << "Buddie number: " << i + 1 << "\n";
		users[j]->showProfile();
		cout << endl;
	}
}