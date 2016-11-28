#include "Helper.h"
#include "User.h"
#include "Vehicle.h"
#include "Shared_Rides.h"

#include <iostream>

using namespace std;

int main() {	

	//funcao para fazer resize do cmd
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1200, 700, TRUE); // 800 width, 100 height
														 /////////////////////////////////////////////////////////////////////////////

	SetConsoleTitle(TEXT("SharedRides - The best app for your favorite travel"));

	SharedRides Boleias;
	Boleias.run();

	cout << "Successfull exit." << endl;

	return 0;


}
