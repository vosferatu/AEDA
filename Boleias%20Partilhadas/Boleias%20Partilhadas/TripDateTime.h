#pragma once

#ifndef TRIPDATETIME_H_
#define TRIPDATETIME_H_

#include<string>



class Trip {
	string ownerName;
	string startPoint;
	string endPoint;
	Time endTime;
	Time startTime;
	Date day;
	float cost;
};

class Date {
private:
	string date;

public:

	Date();
	Date(string data); // data na forma DD/MM/AAA  //put "curr" to get current date
	~Date();

	string getDate() const;
	void setDate(string data);

	friend bool operator<(const Data &date1, const Data &date2);
	friend bool operator==(const Data &date1, const Data &date2); //datas iguais

	friend ostream& operator<<(ostream& out, const Data & data); //mostrar data
};

class Time {
	string time;

public:
	Time();
	Time(string horas); // data na forma DD/MM/AAA
	~Date();

	string getTime() const;
	void setTime(string horas);

	friend bool operator<(const Time &horas1, const Time &horas2);
	friend bool operator==(const Time &horas1, const Time &horas2); //horas iguais

	friend ostream& operator<<(ostream& out, const Time & horas); //mostrar horas
};


#endif /*TRIPDATETIME_H_*/