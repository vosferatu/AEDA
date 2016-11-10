#include "Shared_Rides.h"


using namespace std;

vector<User*> clientes(0);

void SharedRides::CreateRegis(string nome, string password)
{
	clientes.push_back(new RegisteredUser(nome, password));
}