#include "Trip.h"


////////////////////////TAKEN ///////////////////////////////////////////
unsigned int takenTrip::tripCode = 1;

takenTrip::takenTrip(string owns, string start, string finish, Time end){
	owner = owns;
	startPoint = start;
	endPoint = endPoint;
	startTime = Time();
	endTime = end;
	day = Date();
	this->tripCode = tripCode;
	tripCode++;
}

unsigned int takenTrip::getTripCode() const{
	return this->tripCode;
}

string takenTrip::getName() const{
	return owner;
}

void takenTrip::setName(string nome){
	this->owner = nome;
}

ofstream & operator<<(ofstream & out, const takenTrip & trip){
	out << trip.owner << ";";
	out << trip.tripCode << ";";
	out << trip.startPoint << ";";
	out << trip.endPoint << ";";
	out << trip.startTime << ";";
	out << trip.endTime << ";";
	out << trip.day << endl;
	return out;
}

ostream & operator<<(ostream & out, const takenTrip & trip){
	out << "Dono: " << trip.owner << " ";
	out << "Start City: " << trip.startPoint << " ";
	out << "Last City: " << trip.endPoint << endl;
	out << "Start Time: " << trip.startTime << " ";
	out << "End Time: " << trip.endTime << " ";
	out << "Day: " << trip.day << endl;

	return out;
}

//////////////////////////////////WAITING/////////////////////

waitingTrip::waitingTrip(unsigned int owner, vector<Stretch> Viagem, int maxSeats, float price){
	this->ownerID = owner;
	this->Viagem = Viagem;
	this->maxSeats = maxSeats;
	this->pricePerStop = price;
	this->full = false;
}

unsigned int waitingTrip::getOwner() const{
	return ownerID;
}

vector<Stretch> waitingTrip::getWay() const
{
	return Viagem;
}

bool waitingTrip::getFull() const{
	return full;
}

float waitingTrip::getpriceStop() const{
	return pricePerStop;
}

int waitingTrip::getmaxSeats() const{
	return maxSeats;
}

void waitingTrip::setOwner(unsigned int id){
	this->ownerID = id;
}

void waitingTrip::setWay(vector<Stretch> way){
	this->Viagem = way;
}

void waitingTrip::setFull(bool change){
	this->full = change;
}

void waitingTrip::setpriceStop(float price){
	this->pricePerStop = price;
}

void waitingTrip::setmaxSeats(int seats){
	this->maxSeats = seats;
}

ofstream & operator<<(ofstream & out, const waitingTrip & trip){
	out << trip.ownerID << ";";
	out << trip.pricePerStop << ";";
	out << trip.maxSeats << ";";
	for (size_t i = 0; i < trip.Viagem.size(); i++) {
		if (i = trip.Viagem.size() - 1)
			out << trip.Viagem[i] << endl;
		else out << trip.Viagem[i] << ";";
	}
	
	return out;
}

///////////////////////////////////STRETCH//////////////////////////////

Stretch::Stretch(string city, Time next){
	this->stop = city;
	this->toNext = next;
}

string Stretch::getCity() const{
	return stop;
}

vector<int> Stretch::getusers() const{
	return usersID;
}

Time Stretch::getTime() const
{
	return toNext;
}

void Stretch::setCity(string city){
	this->stop = city;
}

void Stretch::addUser(int id){
	this->usersID.push_back(id);
}

void Stretch::setTime(Time newTime){
	this->toNext = newTime;
}

ofstream & operator<<(ofstream & out, const Stretch & way) {
	out << way.stop << ";" << way.toNext << ";";
	for (size_t i = 0; i < way.usersID.size(); i++) {
		out << way.usersID[i] << ";";
	}
}

/////////////////////////////PATH///////////////////////////////////

Path::Path(string first, string second, Time timeSpent){
	this->first = first;
	this->second = second;
	this->timeSpent = timeSpent;
}
