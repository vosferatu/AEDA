#include "Menus.h"
#include "Helper.h"
#include "User.h"

void main_menu() {
	
	int choice = get_input <int>( 
		"[0] Enter as guest" "\n"
		"[1] Login" "\n"
		"[2] Register" "\n"
		"[3] Exit");

	switch (choice) {
	case 0:
		//menu_guest_user();
	case 1:
		//login();
		break;
	case 2:
		´//user_registration();
		break;
	}
}