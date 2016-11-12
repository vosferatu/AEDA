#include "TripDateTime.h"
#include <time.h>


/////////////////////////////////////////TRIP TRIP TRIP  ///////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////DATA DATA DATA /////////////////////////////////////////////////////////

Date::Date(){
	char dat[9];
	_strdate_s(dat);
	string data = dat;
	string da = data.substr(3, 2);
	string mont = data.substr(0, 2);
	string yea = "20" + data.substr(6, 2);

	year = stoi(yea);
	month = stoi(mont);
	day = stoi(da);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year){
	this->day = day;
	this->month = month;
	this->year = year;
}

unsigned int Date::getDay() const{
	return day;
}

unsigned int Date::getMonth() const{
	return month;
}

unsigned int Date::getYear() const{
	return year;
}


void Date::setDay(unsigned int day){
	this->day = day;
}

void Date::setMonth(unsigned int month){
	this->month = month;
}

void Date::setYear(unsigned int year){
	this->year = year;
}

void Date::setDate(unsigned int dia, unsigned int mes, unsigned int ano){
	year = ano;
	month = mes;
	day = dia;
}

bool truedate(const Date & data){
	if (data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12){
		if (data.day >= 1 && data.day <= 31)
			return true;
		else return false;
	}
	else {
		if (data.month == 4 || data.month == 6 || data.month == 9 || data.month == 11){
			if (data.day >= 1 && data.day <= 30)
				return true;
			else return false;
		}
		else {
			if (data.month == 2){
				if ((data.year % 4 == 0 && data.year % 100 != 0) || (data.year % 4 == 0 && data.year % 100 == 0 && data.year % 400 == 0)){
					if (data.day >= 1 && data.day <= 29)
						return true;
					else return false;
				} 
				else {
					if (data.day >= 1 && data.day <= 28)
						return true;
					else return false;
				}
			}
			else
				return false;
		}
	}
}

bool operator<(const Date &date1, const Date &date2){
	if (date1.year < date2.year)
		return true;
	else if (date2.year < date1.year)
		return false;
	else if (date1.month < date2.month)
		return true;
	else if (date2.month < date1.month)
		return false;
	else if (date1.day < date2.day)
		return true;
	else if (date2.day < date1.day)
		return false;
	else return false;
}

bool operator==(const Date &date1, const Date &date2){
	return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

ostream& operator<<(ostream& out, const Date & data){
	string date;
	if (data.month < 10)
		date = to_string(data.day) + "/0" + to_string(data.month) + '/' + to_string(data.year);
	else
		date = to_string(data.day) + "/" + to_string(data.month) + '/' + to_string(data.year);
	out << date;

	return out;
}

istream& operator>>(istream& in, const Date & data) {
	string date;
	if (data.month < 10)
		date = to_string(data.day) + "/0" + to_string(data.month) + '/' + to_string(data.year);
	else
		date = to_string(data.day) + "/" + to_string(data.month) + '/' + to_string(data.year);
	in >> date;

	return in;
}

///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////TIME TIME TIME ////////////////////////////////////


Time::Time() {
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	hours = aTime->tm_hour;
	minutes = aTime->tm_min;
}

Time::Time(unsigned int horas, unsigned int minutos) {
	hours = horas;
	minutes = minutos;
}

unsigned int Time::getHours() const {
	return hours;
}

unsigned int Time::getMinutes() const {
	return minutes;
}

void Time::setTime(unsigned int horas, unsigned int minutos) {
	hours = horas;
	minutes = minutos;
}

void Time::setHours(unsigned int horas) {
	hours = horas;
}

void Time::setMinutes(unsigned int minutos) {
	minutes = minutos;
}

bool truetime(const Time & horas) {
	return (((horas.hours < 24) && (horas.hours >= 0)) && ((horas.minutes < 60) && (horas.minutes >= 0)));
}

bool operator==(const Time &horas1, const Time &horas2) {
	return (horas1.hours == horas2.hours && horas1.minutes == horas2.minutes);
}

bool operator<(const Time &horas1, const Time &horas2) {
	if (horas1.hours < horas2.hours)
		return true;
	else if (horas2.hours < horas1.hours)
		return false;
	else if (horas1.minutes < horas2.minutes)
		return true;
	else if (horas2.minutes < horas1.minutes)
		return false;
	else return false;
}

ostream& operator<<(ostream& out, const Time & horas) {
	string hora;
	if (horas.minutes < 10) {
		hora = to_string(horas.hours) + ":0" + to_string(horas.minutes);
		if (horas.hours < 10)
			hora = "0" + hora;
	}
	else {
		hora = to_string(horas.hours) + ":" + to_string(horas.minutes);
		if (horas.hours < 10)
			hora = "0" + hora;
	}
	out << hora;
	return out;
}

istream& operator >> (istream& in, const Time & horas) {
	string hora;
	if (horas.minutes < 10) {
		hora = to_string(horas.hours) + ":0" + to_string(horas.minutes);
		if (horas.hours < 10)
			hora = "0" + hora;
	}
	else {
		hora = to_string(horas.hours) + ":" + to_string(horas.minutes);
		if (horas.hours < 10)
			hora = "0" + hora;
	}
	in >> hora;
	return in;
}

//////////////////////////////////////////////////////////////////////////////////////////////