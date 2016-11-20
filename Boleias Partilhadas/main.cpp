#include "Helper.h"
#include "Login.h"
#include "Menus.h"
#include "User.h"
#include "Vehicle.h"
#include "Shared_Rides.h"

#include <iostream>

using namespace std;

int main() {	
	SharedRides Boleias;
	Boleias.run();

	cout << "Successfull exit." << endl;

	return 0;


}
