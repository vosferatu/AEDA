#include "Menus.h"
#include "Helper.h"

void Menus::main_menu() {
	
	int choice = get_input <int>( 
		"[0] Enter as guest" "\n"
		"[1] Login" "\n"
		"[2] Register" "\n"
		"[3] Exit");

	switch (choice) {
	case 1:
		login();
		break;
	case 2:
		registration();
		break;
	}
}
