#pragma once
#undef max // because of numeric_limits

#ifndef TRIPDATETIME_H_
#define TRIPDATETIME_H_

#include <string>
#include <iostream>
#include "DateTime.h"

using namespace std;

class Date {
	private:
		unsigned int year;
		unsigned int month;
		unsigned int day;

	public:

		Date();
		~Date() {};
		Date(unsigned int day, unsigned int month, unsigned int year);

		unsigned int getDay() const;
		unsigned int getMonth() const;
		unsigned int getYear() const;

		void setDate(unsigned int dia, unsigned int mes, unsigned int ano);
		void setDay(unsigned int day);
		void setMonth(unsigned int month);
		void setYear(unsigned int year);

		friend bool truedate(const Date & date);    //verifica a data
		friend bool operator<(const Date &date1, const Date &date2);
		friend bool operator==(const Date &date1, const Date &date2); //datas iguais

		friend ostream& operator<<(ostream& out, const Date & data); //mostrar data
		friend istream& operator>>(istream& in, const Date & data); //escrever data
};




class Time {
	unsigned int hours;
	unsigned int minutes;

public:
	Time();
	Time(unsigned int horas, unsigned int minutos); 
	~Time() {};

	unsigned int getHours() const;
	unsigned int getMinutes() const;

	void setTime(unsigned int horas, unsigned int minutos);
	void setHours(unsigned int horas);
	void setMinutes(unsigned int minutos);

	friend bool truetime(const Time & hours);
	friend bool operator<(const Time &horas1, const Time &horas2);
	friend bool operator==(const Time &horas1, const Time &horas2); //horas iguais

	friend Time operator+(const Time & t1, const Time &t2);

	friend ostream& operator<<(ostream& out, const Time & horas); //mostrar horas
	friend istream& operator>> (istream& in, const Time & horas); //escrever horas
};


#endif /*TRIPDATETIME_H_*/
