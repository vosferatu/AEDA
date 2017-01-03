// because of numeric_limits
#pragma once
#ifndef TRIP_H_
#define TRIP_H_

#include "User.h"
#include "DateTime.h"
#include "Vehicle.h"
#include <queue>

/**********************************************************************************************//**
 * @class	WaitingUser
 *
 * @brief	Represents the user that is waiting for its trip to begin.
 * @author	João
 * @date	1-1-2017
 **************************************************************************************************/

class WaitingUser {
	/** @brief	The user's ID. */
	unsigned int userID;
	/** @brief	The user's friends. */
	vector<int> buddies;
	/** @brief	How far away is from the driver. */
	Time driveraway;
	/** @brief	The ID of the driver. */
	unsigned int driverID;

public:
	/**********************************************************************************************//**
	 * @fn	WaitingUser::WaitingUser()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	1-1-2016
	 **************************************************************************************************/
	WaitingUser();

	/**********************************************************************************************//**
	 * @fn	WaitingUser::(unsigned int userID, vector<int> buddies, Time driveraway, unsigned int driverID);
	 *
	 * @brief	Class constructor.
	 *
	 * @author	João
	 * @param userID the user's ID
	 * @param buddies the user's vector of friends
	 * @param driveraway how far is from the driver
	 * @param driverID the driver's ID
	 * @date	1-1-2016
	 **************************************************************************************************/

	WaitingUser(unsigned int userID, vector<int> buddies, Time driveraway, unsigned int driverID);
	//bool operator<(const WaitingUser & WU) const ;

	/**********************************************************************************************//**
	 * @fn	bool WaitingUser::operator == (WaitingUser car1);
	 *
	 * @brief	equality operator
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @param	WU	The waiting user
	 *
	 * @return	if the waiting user is  the same or not
	 **************************************************************************************************/
	bool operator==(const WaitingUser & WU) const;
	/**********************************************************************************************//**
	 * @fn	void WaitingUser::setDriverAway(Time time);
	 *
	 * @brief	sets the time way from the driver.
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @param	time	The time.
	 **************************************************************************************************/
	void setDriverAway(Time time);

	/**********************************************************************************************//**
	 * @fn	void WaitingUser::itsBuddie();
	 *
	 * @brief	returns if a user is friend of driver or not
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	bool	if the user is a friend of the driver or not
	 **************************************************************************************************/
	
	bool itsBuddie() const;

	/**********************************************************************************************//**
	 * @fn	vector<int>  WaitingUser:: getBuddies() const;
	 *
	 * @brief	returns the buddies of the user
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	vector<int>	the buddies.
	 **************************************************************************************************/
	vector<int> getBuddies() const;
	
	/**********************************************************************************************//**
	 * @fn	unsigned int WaitingUser::getDriverID() const;
	 *
	 * @brief	returns driverID of the trip the WaitingUser is assigned
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	unsigned int	the buddies.
	 **************************************************************************************************/
	unsigned int getDriverID() const;
	/**********************************************************************************************//**
	 * @fn	Time WaitingUser::getDriverAway() const;
	 *
	 * @brief	returns the time the user is from driver.
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	Time  time the user is from driver.
	 **************************************************************************************************/
	Time getDriverAway() const;

	/**********************************************************************************************//**
	 * @fn	unsigned int WaitingUser::getUserID() const;
	 *
	 * @brief	returns userID 
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	unsigned int	the userID
	 **************************************************************************************************/
	unsigned int getUserID() const;
};

/**********************************************************************************************//**
	 * @fn	bool operator<(const WaitingUser & WU, const WaitingUser &WU2);
	 *
	 * @brief	the overload for the less operator (priority line requirement)
	 *
	 * @author	João
	 * @date	1-1-2017
	 *
	 * @return	unsigned int	the userID
	 **************************************************************************************************/

bool operator<(const WaitingUser & WU, const WaitingUser &WU2);

/*struct Comparator
{
	bool operator() (const WaitingUser &lhs, const WaitingUser &rhs) const
	{
		return true;

		bool itsbuddie = false;
		
		for (size_t i = 0; i <lhs.getBuddies().size(); i++)
		{
			if (lhs.getBuddies()[i] == lhs.getDriverID()) itsbuddie = true;
		}


		//if (itsbuddie) {
			//return (!(lhs.getDriverAway() < rhs.getDriverAway()));
		//}
		//else return true;
	}
};	
*/


typedef priority_queue<WaitingUser> HEAP_USERS;

/**********************************************************************************************//**
 * @class	takenTrip
 *
 * @brief	The  taken trip class.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class takenTrip { //usada para mostrar e gravar viagens dos owners
	/** @brief	The ownser of the trip. */
	string owner;
	/** @brief	The start point of the trip. */
	string startPoint;
	/** @brief	The end point of the trip. */
	string endPoint;
	/** @brief	The end time of the trip. */
	Time endTime;
	/** @brief	The start time of the trip. */
	Time startTime;
	/** @brief	The day of the trip. */
	Date day;
	/** @brief	The trip code of the trip. */
	static unsigned int tripCodeStat;
	unsigned int tripCode;

	


public:

	/**********************************************************************************************//**
	 * @fn	takenTrip::takenTrip(string owns, string start, string finish, Time end);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	owns  	The owner.
	 * @param	start 	The start.
	 * @param	finish	The finish.
	 * @param	end   	The endtime.
	 **************************************************************************************************/

	takenTrip(string owns, string start, string finish, Time end);

	/**********************************************************************************************//**
	 * @fn	takenTrip::takenTrip()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	takenTrip(){}

	/**********************************************************************************************//**
	 * @fn	unsigned int takenTrip::getTripCode() const;
	 *
	 * @brief	Gets trip code.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The trip code.
	 **************************************************************************************************/

	unsigned int getTripCode() const;

	/**********************************************************************************************//**
	 * @fn	string takenTrip::getName() const;
	 *
	 * @brief	Gets the owner name.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The ownerr name.
	 **************************************************************************************************/

	string getName() const;

	/**********************************************************************************************//**
	 * @fn	string takenTrip::getStart() const;
	 *
	 * @brief	Gets the start point.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The start.
	 **************************************************************************************************/

	string getStart() const;

	/**********************************************************************************************//**
	 * @fn	string takenTrip::getEnd() const;
	 *
	 * @brief	Gets the end point.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The end.
	 **************************************************************************************************/

	string getEnd() const;

	/**********************************************************************************************//**
	 * @fn	Time takenTrip::getEndTime() const;
	 *
	 * @brief	Gets end time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The end time.
	 **************************************************************************************************/

	Time getEndTime() const;

	/**********************************************************************************************//**
	 * @fn	Time takenTrip::getStartTime() const;
	 *
	 * @brief	Gets start time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The start time.
	 **************************************************************************************************/

	Time getStartTime() const;

	/**********************************************************************************************//**
	 * @fn	Date takenTrip::getDay() const;
	 *
	 * @brief	Gets the day.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The day.
	 **************************************************************************************************/

	Date getDay() const;

	/**********************************************************************************************//**
	 * @fn	void takenTrip::setDay(Date data);
	 *
	 * @brief	Sets the day of the taken trip
	 *
	 * @author	João
	 * @date	20-12-2016
	 *
	 * @param	data	the date.
	 **************************************************************************************************/
	void setDay(Date data);


	/**********************************************************************************************//**
	 * @fn	void takenTrip::setEndTime(Time end);
	 *
	 * @brief	Sets the end time of the taken trip
	 *
	 * @author	João
	 * @date	20-12-2016
	 *
	 * @param	end	 the end time.
	 **************************************************************************************************/

	void setEndTime(Time end);
	/**********************************************************************************************//**
	 * @fn	void takenTrip::setStartime(Time start);
	 *
	 * @brief	Sets a start time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	start	The start.
	 **************************************************************************************************/
	void setStartime(Time start);

	/**********************************************************************************************//**
	 * @fn	void takenTrip::setTripCode(unsigned int tripcode);
	 *
	 * @brief	Sets trip code.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	tripcode	The tripcode.
	 **************************************************************************************************/

	void setTripCode(unsigned int tripcode);

	/**********************************************************************************************//**
	 * @fn	void takenTrip::save(ofstream& out) const;
	 *
	 * @brief	Saves the given trip [out] to file.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The out to save.
	 **************************************************************************************************/

	void save(ofstream& out) const;

	/**********************************************************************************************//**
	 * @fn	void takenTrip::setName(string nome);
	 *
	 * @brief	Sets the name of owner.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	nome	The nanme.
	 **************************************************************************************************/

	void setName(string nome);

	/**********************************************************************************************//**
	 * @fn	friend ofstream& takenTrip::operator<<(ofstream& out, const takenTrip& trip);
	 *
	 * @brief	Stream insertion operator to save in file.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out 	The out.
	 * @param 		  	trip	The trip.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ofstream& operator<<(ofstream& out, const takenTrip& trip);//save in file

	/**********************************************************************************************//**
	 * @fn	friend ostream& takenTrip::operator<<(ostream& out, const takenTrip& trip);
	 *
	 * @brief	Stream insertion operator to show the trip in the screen.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out 	The out.
	 * @param 		  	trip	The trip.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ostream& operator<<(ostream& out, const takenTrip& trip); //mostrar no ecrã

};

/**********************************************************************************************//**
 * @class	Stretch
 *
 * @brief	A stretch of a trip.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class Stretch {
	/** @brief	The stop. */
	string stop;
	/** @brief	Vector of users. */
	vector<int> usersID;
	/** @brief	Priority queue  of users to enter in the stretch. */
	HEAP_USERS users;
	/** @brief	Time to next stop. */
	Time toNext;
public:

	/**********************************************************************************************//**
	 * @fn	Stretch::Stretch(string city, Time next);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	city	The city.
	 * @param	next	The next city.
	 **************************************************************************************************/

	Stretch(string city, Time next);

	/**********************************************************************************************//**
	 * @fn	Stretch::Stretch()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	Stretch() {}

	/**********************************************************************************************//**
	 * @fn	string Stretch::getCity() const;
	 *
	 * @brief	Gets the city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The city.
	 **************************************************************************************************/

	string getCity() const;

	/**********************************************************************************************//**
	 * @fn	vector<int> Stretch::getusers() const;
	 *
	 * @brief	Gets the users.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	A vector of users ID.
	 **************************************************************************************************/

	/**********************************************************************************************//**
	 * @fn	void Stretch::addtoHeap(WaitingUser u1);
	 *
	 * @brief	adds an user to the heap of users of the stretch
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	u1 the waiting user to add.
	 **************************************************************************************************/
	
	void addtoHeap(WaitingUser u1);

	/**********************************************************************************************//**
	 * @fn	HEAP_USERS  Stretch:: getHeap() const;
	 *
	 * @brief returns the heap of the users.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	HEAP_USERS  the users heap.
	 **************************************************************************************************/
	
	HEAP_USERS getHeap() const;

	//vector<int> getusers() const;

	/**********************************************************************************************//**
	 * @fn	Time Stretch::getTime() const;
	 *
	 * @brief	Gets the time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The time.
	 **************************************************************************************************/

	Time getTime() const;

	/**********************************************************************************************//**
	 * @fn	void Stretch::setCity(string city);
	 *
	 * @brief	Sets a city.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	city	The city.
	 **************************************************************************************************/

	void setCity(string city);

	/**********************************************************************************************//**
	 * @fn	void Stretch::addUser(int id);
	 *
	 * @brief	Adds a user.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier of the user.
	 **************************************************************************************************/

	void addUser(int id);

	/**********************************************************************************************//**
	 * @fn	void Stretch::setTime(Time newTime);
	 *
	 * @brief	Sets a time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	newTime	The new time.
	 **************************************************************************************************/

	void setTime(Time newTime);

	/**********************************************************************************************//**
	 * @fn	void Stretch::setvectID(vector<int> usersID);
	 *
	 * @brief	Set vect of users.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	usersID	the vector of ids of the users.
	 **************************************************************************************************/

	void setHeap(HEAP_USERS heap);

	/**********************************************************************************************//**
	 * @fn	friend ofstream& Stretch::operator<<(ofstream& out, const Stretch& way);
	 *
	 * @brief	Stream insertion operator to save in file.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The out.
	 * @param 		  	way	The way.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ofstream& operator<<(ofstream& out, const Stretch& way);//save on file
	/**********************************************************************************************//**
	 * @fn	friend ostream& Stretch::operator<<(ostream& out, const Stretch& way);
	 *
	 * @brief	Stream insertion operator to show in screen
	 *
	 * @author	João
	 * @date	18-12-2016
	 *
	 * @param [in,out]	out	The out.
	 * @param 		  	way	The way.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/
	friend ostream & operator<<(ostream & out, const Stretch & way);
};

/**********************************************************************************************//**
 * @class	waitingTrip
 *
 * @brief	A waiting trip class.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class waitingTrip { 
	/** @brief	The identifier that owns the trip. */
	unsigned int ownerID;
	/** @brief	The trip, composed by stretchs. */
	vector<Stretch> Viagem;
	/** @brief	The price per stop. */
	float pricePerStop;
	/** @brief	The maximum seats. */
	int maxSeats;

public:

	/**********************************************************************************************//**
	 * @fn	waitingTrip::waitingTrip(unsigned int owner, vector<Stretch> Viagem, int maxSeats, float price);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	owner   	The owner.
	 * @param	Viagem  	The viagem.
	 * @param	maxSeats	The maximum seats.
	 * @param	price   	The price.
	 **************************************************************************************************/

	waitingTrip(unsigned int owner, vector<Stretch> Viagem, int maxSeats, float price);

	/**********************************************************************************************//**
	 * @fn	waitingTrip::waitingTrip();
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	waitingTrip();

	/**********************************************************************************************//**
	 * @fn	unsigned int waitingTrip::getOwner() const;
	 *
	 * @brief	Gets the owner of the trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The owner.
	 **************************************************************************************************/

	unsigned int getOwner() const;

	/**********************************************************************************************//**
	 * @fn	vector<Stretch> waitingTrip::getWay() const;
	 *
	 * @brief	Gets the way.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The way.
	 **************************************************************************************************/

	vector<Stretch> getWay() const;

	vector<Stretch> getWayStretch();

	/**********************************************************************************************//**
	 * @fn	float waitingTrip::getpriceStop() const;
	 *
	 * @brief	Gets the price per stop.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	A float, the price. 
	 **************************************************************************************************/

	float getpriceStop() const;

	/**********************************************************************************************//**
	 * @fn	int waitingTrip::getmaxSeats() const;
	 *
	 * @brief	Gets the maximum number of  seats.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	An int, the maxium number of seats. 
	 **************************************************************************************************/

	int getmaxSeats() const;

	/**********************************************************************************************//**
	 * @fn	Time waitingTrip::getTotalTime() const;
	 *
	 * @brief	Gets total time of the trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The total time.
	 **************************************************************************************************/

	Time getTotalTime() const;

	/**********************************************************************************************//**
	 * @fn	void waitingTrip::setOwner(unsigned int id);
	 *
	 * @brief	Sets an owner to the trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	id	The identifier of the ownser.
	 **************************************************************************************************/

	void setOwner(unsigned int id);

	/**********************************************************************************************//**
	 * @fn	void waitingTrip::setWay(vector<Stretch> way);
	 *
	 * @brief	Sets a way to the trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	way	The way.
	 **************************************************************************************************/

	void setWay(vector<Stretch> way);

	/**********************************************************************************************//**
	 * @fn	void waitingTrip::setpriceStop(float price);
	 *
	 * @brief	Sets the price per stop.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	price	The price.
	 **************************************************************************************************/

	void setpriceStop(float price);

	/**********************************************************************************************//**
	 * @fn	void waitingTrip::setmaxSeats(int seats);
	 *
	 * @brief	Sets the maxium number of  seats.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	seats	The seats.
	 **************************************************************************************************/

	void setmaxSeats(int seats);

	/**********************************************************************************************//**
	 * @fn	void waitingTrip::save(ofstream& out) const;
	 *
	 * @brief	Saves the given out, the waiting trip.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The trip to save.
	 **************************************************************************************************/

	void save(ofstream& out) const;

	/**********************************************************************************************//**
	 * @fn	friend ofstream& waitingTrip::operator<<(ofstream& out, const waitingTrip& trip);
	 *
	 * @brief	Stream insertion operator.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out 	The output.
	 * @param 		  	trip	The trip.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ofstream& operator<<(ofstream& out, const waitingTrip& trip);//save on file

	/**********************************************************************************************//**
	 * @fn	friend ostream& waitingTrip::operator<<(ostream& out, const waitingTrip& trip);
	 *
	 * @brief	Stream insertion operator.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param [in,out]	out	The output.
	 * @param 		  	trip	The trip.
	 *
	 * @return	The shifted result.
	 **************************************************************************************************/

	friend ostream& operator<<(ostream& out, const waitingTrip& trip);
};

/**********************************************************************************************//**
 * @class	Path
 *
 * @brief	A path to follow, given 2 locations.
 *
 * @author	João
 * @date	20-11-2016
 **************************************************************************************************/

class Path {
	/** @brief	The time spent. */
	Time timeSpent;
	/** @brief	The first location. */
	string first;
	/** @brief	The second location. */
	string second;
public:

	/**********************************************************************************************//**
	 * @fn	Path::Path(string first, string second, Time timeSpent);
	 *
	 * @brief	Constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @param	first	 	The first point.
	 * @param	second   	The second point.
	 * @param	timeSpent	The time spent between points.
	 **************************************************************************************************/

	Path(string first, string second, Time timeSpent);

	/**********************************************************************************************//**
	 * @fn	Path::Path()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	João
	 * @date	20-11-2016
	 **************************************************************************************************/

	Path(){}

	/**********************************************************************************************//**
	 * @fn	Time Path::getTime() const;
	 *
	 * @brief	Gets the time.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The time.
	 **************************************************************************************************/

	Time getTime() const;

	/**********************************************************************************************//**
	 * @fn	string Path::getFirst() const;
	 *
	 * @brief	Gets the first location.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The first location.
	 **************************************************************************************************/

	string getFirst() const;

	/**********************************************************************************************//**
	 * @fn	string Path::getSecond() const;
	 *
	 * @brief	Gets the second location.
	 *
	 * @author	João
	 * @date	20-11-2016
	 *
	 * @return	The second location.
	 **************************************************************************************************/

	string getSecond() const;
};






#endif