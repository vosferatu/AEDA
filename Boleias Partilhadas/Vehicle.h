#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <vector>
#include <fstream>
#include "Helper.h"

#undef max // because of numeric_limits

using namespace std;

/**********************************************************************************************//**
 * @class	Vehicle
 *
 * @brief	A vehicle class.
 *
 * @author	Jo�o
 * @date	20-11-2016
 **************************************************************************************************/

class Vehicle {
	/** @brief	Number of seats. */
	unsigned int numberSeats;
	/** @brief	vehicle type, only for showing purposes. */
	string brand;
	/** @brief	user might not choose this vehicle for this. */
	unsigned int year;
	/** @brief	optional. grade from A to F based on vehicle condition. */
	string rate;
	/** @brief	same as user ID. */
	unsigned int idCar;
	/** @brief	The carstatic. */
	static unsigned int carstatic;
	/** @brief	The route of the vehicle. */
	vector<string> route;
	
public:

	
		
	
	Vehicle(unsigned int id, unsigned int noSeats, string brand, unsigned int year, string rate);

	/**********************************************************************************************//**
	 * @fn	Vehicle::Vehicle(unsigned int noSeats, string brand, unsigned int year,string rate);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param	noSeats	The number of  seats.
	 * @param	brand  	The brand.
	 * @param	year   	The year.
	 * @param	rate   	The rate.
	 **************************************************************************************************/

	Vehicle(unsigned int noSeats, string brand, unsigned int year,string rate);

	/**********************************************************************************************//**
	 * @fn	Vehicle::Vehicle();
	 *
	 * @brief	Default constructor.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 **************************************************************************************************/

	Vehicle();

	/**********************************************************************************************//**
	 * @fn	Vehicle::~Vehicle()
	 *
	 * @brief	Destructor.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 **************************************************************************************************/

	~Vehicle() {};

	//get functions

	/**********************************************************************************************//**
	 * @fn	unsigned int Vehicle::getnumberSeats() const;
	 *
	 * @brief	Get the number of  seats.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @return	An int, the num. of seats.
	 **************************************************************************************************/

	unsigned int getnumberSeats() const;

	/**********************************************************************************************//**
	 * @fn	string Vehicle::getBrand() const;
	 *
	 * @brief	Gets the brand.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @return	The brand.
	 **************************************************************************************************/

	string getBrand() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int Vehicle::getYear() const;
	 *
	 * @brief	Gets the year.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @return	The year.
	 **************************************************************************************************/

	unsigned int getYear() const;

	/**********************************************************************************************//**
	 * @fn	string Vehicle::getRate() const;
	 *
	 * @brief	Gets the rate.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @return	The rate.
	 **************************************************************************************************/

	string getRate() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int Vehicle::getID() const;
	 *
	 * @brief	Gets the identifier of the car.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @return	The identifier of the car.
	 **************************************************************************************************/

	unsigned int getID() const;

	/**********************************************************************************************//**
	 * @fn	vector<string> Vehicle::getRoute() const;
	 *
	 * @brief	Gets the route.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @return	The route.
	 **************************************************************************************************/

	vector<string> getRoute() const;
	
	//set functions

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setRoute(vector<string> route);
	 *
	 * @brief	Sets a route.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	route	The route.
	 **************************************************************************************************/

	void setRoute(vector<string> route);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setId(unsigned int id);
	 *
	 * @brief	Sets an identifier.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	id	The identifier.
	 **************************************************************************************************/

	void setId(unsigned int id);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setYear(unsigned int year);
	 *
	 * @brief	Sets a year.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	year	The year.
	 **************************************************************************************************/

	void setYear(unsigned int year);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setSeats(unsigned int seats);
	 *
	 * @brief	Sets the number of  seats.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	seats	The number of seats.
	 **************************************************************************************************/

	void setSeats(unsigned int seats);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setBrand(string brand);
	 *
	 * @brief	Sets a brand.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	brand	The brand.
	 **************************************************************************************************/

	void setBrand(string brand);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setRate(string rate);
	 *
	 * @brief	Sets a rate.
	 *
	 * @author	Jo�o
	 * @date	21-11-2016
	 *
	 * @param	rate	The rate.
	 **************************************************************************************************/

	void setRate(string rate);

	/**********************************************************************************************//**
	 * @fn	void Vehicle::setVehicle(Vehicle* v1);
	 *
	 * @brief	Sets a vehicle.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param [in,out]	v1	If non-null, the first Vehicle.
	 **************************************************************************************************/

	void setVehicle(Vehicle* v1);

	/**********************************************************************************************//**
	 * @fn	Vehicle& Vehicle::operator=(Vehicle car);
	 *
	 * @brief	Assignment operator.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param	car	The car.
	 *
	 * @return	A shallow copy of this object.
	 **************************************************************************************************/

	Vehicle& operator=(Vehicle car);

	/**********************************************************************************************//**
	 * @fn	friend ofstream& Vehicle::operator<<(ofstream& os, const Vehicle car);
	 *
	 * @brief	Stream insertion operator, to save the vehicle.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param [in,out]	os 	The operating system.
	 * @param 		  	car	The car.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ostream& operator<<(ostream& os, const Vehicle car); // for now, only for writing in file of users purpose

	/**********************************************************************************************//**
	 * @fn	friend ostream& Vehicle::operator<<(ostream& os, const Vehicle car);
	 *
	 * @brief	Stream insertion operator, to show the vehicle in the screen.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param [in,out]	os 	The operating system.
	 * @param 		  	car	The car.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ostream& operator<<(ostream& os, const Vehicle car); // for now, only for writing in file of users purpose

	/**********************************************************************************************//**
	 * @fn	void Vehicle::save(ofstream& out) const;
	 *
	 * @brief	Saves the given out in a file.
	 *
	 * @author	Jo�o
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The output of the car to save.
	 **************************************************************************************************/

	void save(ofstream& out) const;

};

#endif /* VEHICLE_H_ */
