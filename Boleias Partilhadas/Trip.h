#pragma once
#ifndef TRIP_H_
#define TRIP_H_

#include "User.h"
#include "DateTime.h"
#include "Vehicle.h"
#include "Grafo.h"


class takenTrip { //usada para mostrar e gravar viagens dos owners
	User* owner;   //usada para mostrar e gravar viagens de cada user (talvez)
	string startPont;
	string endPoint;
	Time endTime;
	Time startTime;
	Date day;

public:

};

class Path {
	Time timeSpent;
	string first;
	string second;
	float preco;
};

class Stretch {
	Path caminho;
	vector<int> usersID;
};

class waitingTrip { 
	User* owner;
	vector<Stretch> Viagem;
	bool full;

public:

};

#endif