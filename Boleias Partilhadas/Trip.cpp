#include "Trip.h"


////////////////////////TAKEN ///////////////////////////////////////////
unsigned int takenTrip::tripCodeStat = 1;


takenTrip::takenTrip(string owns, string start, string finish, Time end){
	owner = owns;
	startPoint = start;
	endPoint = finish;
	startTime = Time();
	endTime = end;
	day = Date();
	this->tripCode = tripCodeStat;
	tripCodeStat++;
}

unsigned int takenTrip::getTripCode() const{
	return this->tripCode;
}

string takenTrip::getName() const{
	return owner;
}

string takenTrip::getStart() const
{
	return this->startPoint;
}
string takenTrip::getEnd() const {
	return this->endPoint;
}
Time takenTrip::getEndTime() const {
	return this->endTime;
}
Time takenTrip::getStartTime() const {
	return this->startTime;
}
Date takenTrip::getDay() const { 
	return this->day; }

void takenTrip::setName(string nome){
	this->owner = nome;
}

void takenTrip::setStartime(Time start) {
	this->startTime = start;
}

void takenTrip::setTripCode(unsigned int tripcode) {
	this->tripCode = tripcode;
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

void takenTrip::save(ofstream& out) const {
	out << this->tripCode << ";";
	out << this->owner << ";";
	out << this->startPoint << ";";
	out << this->endPoint << ";";
	out << this->startTime << ";";
	out << this->endTime << ";";
	out << this->day << endl;
}





//////////////////////////////////WAITING/////////////////////

waitingTrip::waitingTrip() {
	this->ownerID = 0;
	this->maxSeats = 0;
	this->pricePerStop = 0;

}

waitingTrip::waitingTrip(unsigned int owner, vector<Stretch> Viagem, int maxSeats, float price){
	this->ownerID = owner;
	this->Viagem = Viagem;
	this->maxSeats = maxSeats;
	this->pricePerStop = price;
}

unsigned int waitingTrip::getOwner() const{
	return ownerID;
}

vector<Stretch> waitingTrip::getWay() const
{
	return Viagem;
}

float waitingTrip::getpriceStop() const{
	return pricePerStop;
}

int waitingTrip::getmaxSeats() const{
	return maxSeats;
}

Time waitingTrip::getTotalTime() const{
	Time t1(0, 0);
	for (size_t i = 0; i < Viagem.size(); i++) {
		t1 = t1 + Viagem[i].getTime();
	}
	return t1;
}

void waitingTrip::setOwner(unsigned int id){
	this->ownerID = id;
}

void waitingTrip::setWay(vector<Stretch> way){
	this->Viagem = way;
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

ostream & operator<<(ostream & out, const waitingTrip & trip){
	
		
	out << "No. of stops: " << trip.getWay().size() << endl << endl;
	
	vector<Stretch> viagem = trip.getWay();
	
	for (size_t i = 0; i < viagem.size(); i++)
	{
		if (i == 0)out << "- Starting point - " << endl;
		if (i == viagem.size() - 1) out << "- End Point - " << endl;
		out << viagem[i] << endl << endl;
				
	}
	
	out << "Price per stop: " << trip.pricePerStop << endl;
	out << "Max seats per stop:  " << trip.maxSeats;
	
	return out;
}


void waitingTrip::save(ofstream& out) const {
	out << this->getOwner() << ";";

	out << this->Viagem.size() << ";";

	for (size_t i = 0; i < this->Viagem.size(); i++)
	{
		out << this->Viagem[i] << ";";
	}

	out << this->getpriceStop() << ";" << getmaxSeats() << endl;


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

void Stretch::setvectID(vector<int> usersID) {
	this->usersID = usersID;
}

ofstream & operator<<(ofstream & out, const Stretch & way) {
	out << way.stop << ";" << way.toNext << ";";
	
	out << way.usersID.size();
	
	for (size_t i = 0; i < way.usersID.size(); i++) {
		out << way.usersID[i] << ";";
	}

	return out;
}

ostream & operator<<(ostream & out, const Stretch & way) {

	out << "Stop: " << way.stop;
	
	if (way.toNext == Time(0, 0)) out << " | This is the final point in the journey" << endl;
	else out << " | Time to next stop: " << way.toNext << endl;

	if (!(way.toNext == Time(0, 0))) {
		if (way.usersID.size() == 0) out << "There are no users waiting to enter in this stop" << endl;
		else {
			out << "There are " << way.usersID.size() << " users entering in this stop, being the Users with the IDs ";

			for (size_t i = 0; i < way.usersID.size(); i++) {
				if (i < way.usersID.size() - 1) out << way.usersID[i] << ", ";
				else out << way.usersID[i] << "." << endl;
			}

		}
	}
	return out;
}

/////////////////////////////PATH///////////////////////////////////


Path::Path(string first, string second, Time timeSpent){
	this->first = first;
	this->second = second;
	this->timeSpent = timeSpent;
}

Time Path::getTime() const{
	return timeSpent;
}

string Path::getFirst() const{
	return first;
}

string Path::getSecond() const{
	return second;
}
