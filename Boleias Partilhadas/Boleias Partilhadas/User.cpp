#include "User.h"

using namespace std;


string User::getname() {
	return name;
}

unsigned int User::getid() {
	return id; 
}

bool User::hasvehicle() {
	return hasvehicle;
}

RegisteredUser::RegisteredUser(string nome,string password) : User()
{
	this->username = nome;
	this->password = password;
}

