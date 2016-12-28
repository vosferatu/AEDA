#include "Vehicle.h"

using namespace std;

unsigned int Vehicle::carstatic = 0;



Vehicle::Vehicle(unsigned int id,unsigned int noSeats, string brand, unsigned int year, string rate) : numberSeats(noSeats) {
	this->brand = brand;
	this->numberSeats = noSeats;
	this->year = year;
	this->idCar = id;
	this->rate = rate;
	this->model = "";
}


Vehicle::Vehicle(unsigned int noSeats, string brand, unsigned int year, string rate) : numberSeats(noSeats) {
	this->brand = brand;
	this->numberSeats = noSeats;
	this->year = year;
	this->idCar = 0;
	this->rate = rate;
	this->model = "";
}



Vehicle::Vehicle() {
	this->brand = "nobrand";
	this->model = "nomodel";
	this->numberSeats = 0;
	this->year = 0;
	this->idCar = 0;
	this->rate = " ";
	vector<string> a{};
	this->route = a;
	this->idCar = carstatic;
	carstatic++;
}

void Vehicle::setModel(string model) {
	this->model = model;
}

void Vehicle::setYear(unsigned int year) {
	this->year = year;
}

void Vehicle::setRate(string rate) {
	this->rate = rate;
}

void Vehicle::setBrand(string brand) {
	this->brand = brand;
}


string Vehicle::getModel() const {
	return model;
}

unsigned int Vehicle::getnumberSeats() const{
	return numberSeats;
}

string Vehicle::getBrand() const{
	return brand;
}

unsigned int Vehicle::getYear() const{
	return year;
}

string Vehicle::getRate() const{
	return rate;
}

unsigned int Vehicle::getID() const{
	return idCar;
}

vector<string> Vehicle::getRoute() const{
	return route;
}

void Vehicle::setId(unsigned int id)  {
	this->idCar = id;
}

void Vehicle::setSeats(unsigned int seats){
	this->numberSeats = seats;
}


void Vehicle::setVehicle(Vehicle * v1){
	this->brand = v1->brand;
	this->model = v1->model;
	this->year = v1->year;
	this->rate = v1->rate;
	this->numberSeats = v1->numberSeats;
	this->idCar = v1->idCar;
}

void Vehicle::setRoute(vector<string> route) {
	this->route = route;
}

Vehicle& Vehicle::operator=(Vehicle car){
	this->brand = car.brand;
	this->model = car.model;
	this->idCar = car.idCar;
	this->numberSeats = car.numberSeats;
	this->rate = car.rate;
	this->route = car.route;
	this->year = car.year;
	
	return *this;
}

ostream& operator<< (ostream& os, const Vehicle car) {
	os << TAB << "Owner ID: "  << car.getID() << endl;
	os << TAB << "Brand: " << car.getBrand() << endl;
	os << TAB << "Model: " << car.getModel() << endl;
	os << TAB << "Year: " << car.getYear() << endl;
	os << TAB << "Number of Seats: " << car.getnumberSeats()<<endl;
	os << TAB << "Rate: " << car.getRate() << endl;
	os << TAB << "Owner predefined route: ";
	
	if (car.getRoute().size() == 0) os << "This user does not have any predefined route.";
	for (size_t i = 0; i < car.getRoute().size(); i++){
		if (i == car.getRoute().size() - 1)
			os << car.getRoute()[i];
		else
			os << car.getRoute()[i] << "-";
		
	}

	return os;
}

void Vehicle::save(ofstream& out) const {
	out << this->getID() << ";" << this->getBrand() << ";" << this->getModel() << ";" << this->getnumberSeats() << ";" << this->getYear() << ";" << this->getRate() << ";";
	
	if (this->getRoute().size() == 0)
		out << endl;
	else {
		for (size_t i = 0; i < this->getRoute().size(); i++) {

			if (i < getRoute().size() - 1)
				out << this->getRoute()[i] << ";";
			else
				out << this->getRoute()[i] << ";" << endl;
		}

	}
}

ostream & operator<<(ostream & os, const Vehicle* car){
	os << "\nBrand: " << car->getBrand() << " ";
	os << "\nModel: " << car->getModel() << " ";
	os << "\nYear: " << car->getYear() << " ";
	os << "\nSeats: " << car->getnumberSeats() << " ";
	os << "\nRate(A-F): " << car->getRate() << endl;

	for (size_t i = 0; i < car->getRoute().size(); i++) {
		os << car->getRoute()[i] << endl;
	}

	return os;
}

//bool Vehicle::operator < (const Vehicle & car1) const {
		
	//if (this->brand != car1.brand) return (this->brand > car1.brand);
//	if (  (this->brand == car1.brand) && (this->model == car1.model)  ) 
	//	return (this->year > car1.year);
	//else return (this->model < car1.model);
//}


bool Vehicle::operator < (Vehicle* const& car1) const {

	if (this->brand != car1->brand) return (this->brand < car1->brand);

	if ( (this->brand == car1->brand) && (this->model == car1->model) )
		return (this->year < car1->year);
		else return (this->model < car1->model);
}



bool Vehicle::operator == (const Vehicle &car1) const {
	return ( (this->brand == car1.brand) && (this->model == car1.model) && (this->year == car1.year));
}

