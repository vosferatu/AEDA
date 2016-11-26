#pragma once
#undef max // because of numeric_limits

#ifndef TRIPDATETIME_H_
#define TRIPDATETIME_H_

#include <string>
#include <iostream>
#include "DateTime.h"

using namespace std;

/**********************************************************************************************//**
 * @class	Date
 *
 * @brief	Date class.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class Date {
	private:
		/** @brief	The year. */
		unsigned int year;
		/** @brief	The month. */
		unsigned int month;
		/** @brief	The day. */
		unsigned int day;

	public:

		/**********************************************************************************************//**
		 * @fn	Date::Date();
		 *
		 * @brief	Default constructor.
		 *
		 * @author	João
		 * @date	20-11-2016
		 **************************************************************************************************/

		Date();

		/**********************************************************************************************//**
		 * @fn	Date::~Date()
		 *
		 * @brief	Destructor.
		 *
		 * @author	João
		 * @date	20-11-2016
		 **************************************************************************************************/

		~Date() {};

		/**********************************************************************************************//**
		 * @fn	Date::Date(unsigned int day, unsigned int month, unsigned int year);
		 *
		 * @brief	Constructor.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	day  	The day.
		 * @param	month	The month.
		 * @param	year 	The year.
		 **************************************************************************************************/

		Date(unsigned int day, unsigned int month, unsigned int year);

		/**********************************************************************************************//**
		 * @fn	unsigned int Date::getDay() const;
		 *
		 * @brief	Gets the day.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @return	The day.
		 **************************************************************************************************/

		unsigned int getDay() const;

		/**********************************************************************************************//**
		 * @fn	unsigned int Date::getMonth() const;
		 *
		 * @brief	Gets the month.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @return	The month.
		 **************************************************************************************************/

		unsigned int getMonth() const;

		/**********************************************************************************************//**
		 * @fn	unsigned int Date::getYear() const;
		 *
		 * @brief	Gets the year.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @return	unsigned int - The year.
		 **************************************************************************************************/

		unsigned int getYear() const;

		/**********************************************************************************************//**
		 * @fn	void Date::setDate(unsigned int dia, unsigned int mes, unsigned int ano);
		 *
		 * @brief	Sets a date.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	dia	 - the day desired
		 * @param	mes	 - the month desired
		 * @param	ano	 - the year desired
		 **************************************************************************************************/

		void setDate(unsigned int dia, unsigned int mes, unsigned int ano);

		/**********************************************************************************************//**
		 * @fn	void Date::setDay(unsigned int day);
		 *
		 * @brief	Sets a day.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	day	The day.
		 **************************************************************************************************/

		void setDay(unsigned int day);

		/**********************************************************************************************//**
		 * @fn	void Date::setMonth(unsigned int month);
		 *
		 * @brief	Sets a month.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	month	The month.
		 **************************************************************************************************/

		void setMonth(unsigned int month);

		/**********************************************************************************************//**
		 * @fn	void Date::setYear(unsigned int year);
		 *
		 * @brief	Sets a year.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	year	The year.
		 **************************************************************************************************/

		void setYear(unsigned int year);

		/**********************************************************************************************//**
		 * @fn	friend bool Date::truedate(const Date & date);
		 *
		 * @brief	Truedates the given date.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	date	The date.
		 *
		 * @return	True if it succeeds, false if it fails.
		 **************************************************************************************************/

		friend bool truedate(const Date & date);    //verifica a data

		/**********************************************************************************************//**
		 * @fn	friend bool Date::operator<(const Date &date1, const Date &date2);
		 *
		 * @brief	Less-than comparison operator of dates.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	date1	The date instance to compare.
		 * @param	date2	The date instance to compare.
		 *
		 * @return	True if the first date is less  in calendar than the second.
		 **************************************************************************************************/

		friend bool operator<(const Date &date1, const Date &date2);

		/**********************************************************************************************//**
		 * @fn	friend bool Date::operator==(const Date &date1, const Date &date2);
		 *
		 * @brief	Equality operator.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param	date1	The first date to compare.
		 * @param	date2	The second date to compare.
		 *
		 * @return	True if the parameters are considered equivalent.
		 **************************************************************************************************/

		friend bool operator==(const Date &date1, const Date &date2); //datas iguais

		/**********************************************************************************************//**
		 * @fn	friend ostream& Date::operator<<(ostream& out, const Date & data);
		 *
		 * @brief	Stream insertion operator.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param [in,out]	out 	The out.
		 * @param 		  	data	The data.
		 *
		 * @return	The shifted result.
		 **************************************************************************************************/

		friend ostream& operator<<(ostream& out, const Date & data); //mostrar data

		/**********************************************************************************************//**
		 * @fn	friend istream& Date::operator>>(istream& in, const Date & data);
		 *
		 * @brief	Stream extraction operator.
		 *
		 * @author	João
		 * @date	20-11-2016
		 *
		 * @param [in,out]	in  	The in.
		 * @param 		  	data	The data.
		 *
		 * @return	The shifted result.
		 **************************************************************************************************/

		friend istream& operator>>(istream& in, const Date & data); //escrever data
};




class Time {
	/** @brief	The hours. */
	unsigned int hours;
	/** @brief	The minutes. */
	unsigned int minutes;

public:

	/**********************************************************************************************//**
	 * @fn	Time::Time();
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	Time();

	/**********************************************************************************************//**
	 * @fn	Time::Time(unsigned int horas, unsigned int minutos);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	horas  	The horas.
	 * @param	minutos	The minutos.
	 **************************************************************************************************/

	Time(unsigned int horas, unsigned int minutos); 

	/**********************************************************************************************//**
	 * @fn	Time::~Time()
	 *
	 * @brief	Destructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	~Time() {};

	/**********************************************************************************************//**
	 * @fn	unsigned int Time::getHours() const;
	 *
	 * @brief	Gets the hours.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The hours.
	 **************************************************************************************************/

	unsigned int getHours() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int Time::getMinutes() const;
	 *
	 * @brief	Gets the minutes.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The minutes.
	 **************************************************************************************************/

	unsigned int getMinutes() const;

	/**********************************************************************************************//**
	 * @fn	void Time::setTime(unsigned int horas, unsigned int minutos);
	 *
	 * @brief	Sets a time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	horas  	The horas.
	 * @param	minutos	The minutos.
	 **************************************************************************************************/

	void setTime(unsigned int horas, unsigned int minutos);

	/**********************************************************************************************//**
	 * @fn	void Time::setHours(unsigned int horas);
	 *
	 * @brief	Sets the hours.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	horas	The horas.
	 **************************************************************************************************/

	void setHours(unsigned int horas);

	/**********************************************************************************************//**
	 * @fn	void Time::setMinutes(unsigned int minutos);
	 *
	 * @brief	Sets the minutes.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	minutos	The minutes to set.
	 **************************************************************************************************/

	void setMinutes(unsigned int minutos);

	/**********************************************************************************************//**
	 * @fn	friend bool Time::truetime(const Time & hours);
	 *
	 * @brief	Truetimes the given hours, if are correct.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	hours	The hours.
	 *
	 * @return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	friend bool truetime(const Time & hours);

	/**********************************************************************************************//**
	 * @fn	friend bool Time::operator<(const Time &horas1, const Time &horas2);
	 *
	 * @brief	Less-than comparison operator of hours.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	horas1	The first instance to compare.
	 * @param	horas2	The second instance to compare.
	 *
	 * @return	True if the first parameter is less than the second.
	 **************************************************************************************************/

	friend bool operator<(const Time &horas1, const Time &horas2);

	/**********************************************************************************************//**
	 * @fn	friend bool Time::operator==(const Time &horas1, const Time &horas2);
	 *
	 * @brief	Equality operator of hours.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	horas1	The first instance to compare.
	 * @param	horas2	The second instance to compare.
	 *
	 * @return	True if the parameters are considered equivalent.
	 **************************************************************************************************/

	friend bool operator==(const Time &horas1, const Time &horas2); //horas iguais

	/**********************************************************************************************//**
	 * @fn	friend Time Time::operator+(const Time & t1, const Time &t2);
	 *
	 * @brief	Addition operator.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	t1	The first value.
	 * @param	t2	A value to add to it.
	 *
	 * @return	The result of the operation + to hours.
	 **************************************************************************************************/

	friend Time operator+(const Time & t1, const Time &t2);

	/**********************************************************************************************//**
	 * @fn	friend ostream& Time::operator<<(ostream& out, const Time & horas);
	 *
	 * @brief	Stream insertion operator. shows  the hours
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out  	The out.
	 * @param 		  	horas	The horas.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ostream& operator<<(ostream& out, const Time & horas); //mostrar horas

	/**********************************************************************************************//**
	 * @fn	friend istream& Time::operator>> (istream& in, const Time & horas);
	 *
	 * @brief	Stream extraction operator. writes the hours
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	in   	The in.
	 * @param 		  	horas	The horas.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend istream& operator>> (istream& in, const Time & horas); //escrever horas
};


#endif /*TRIPDATETIME_H_*/
