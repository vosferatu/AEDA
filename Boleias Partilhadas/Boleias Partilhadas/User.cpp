#include "User.h"
#include "Helper.h"

using namespace std;

unsigned int User::id = 0;

string User::getname() {
	return name;
}

void User::setname(const string &n)
{
	this->name = n;
}

unsigned int User::getid() {
	return id; 
}

bool User::hasvehicle() {
	return vehicle;
}

void RegisteredUser::regist_password() {
		
		string password1 = get_input <string>("Please enter your password.");
		string password2 = get_input <string>("Please re-enter your password.");

		while (password1 != password2) {
			std::cout << "Error! Passwords do not match." "\n";
			password1 = get_input <string>("Please enter your password.");
			password2 = get_input <string>("Please re-enter your password.");
		}
		
		this->password = password1;

}

void RegisteredUser::regist_username(){
	
	string usern = get_input <std::string>("Please enter a username.");
	cout << "Username: " << usern << "\n";

	this->username=  usern;
}

void User::regist_name() {
	string na = get_input <std::string>("Please enter your name.");
	cout << "Name: " << na << "\n";

	this->name = na;
}

void RegisteredUser::save_user() {

	string filename = "users.txt";
	ofstream file(filename);
	file << this->username << "\n" << this->password << "\n";

}

RegisteredUser RegisteredUser::user_registration()
{
	RegisteredUser u1;
	u1.regist_username();
	u1.regist_password();
	u1.regist_name();
	u1.save_user();

	return u1;
}


