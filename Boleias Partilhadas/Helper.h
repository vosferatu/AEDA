
#pragma once
#ifndef HELPER_H_
#define HELPER_H_

#include <limits> // for std::numeric_limits
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>

#undef max // because of numeric_limits


using namespace std;



/*
* /brief Function that returns the input by user, if bad input try again
* get_input - template function that returns an input generated by the user
* @param strQuery - strings given
* @return out - returns the input from the user converted to its type
*/
template <typename T> 
T get_input(const string &strQuery)
{
	cout << strQuery << "\n> ";
	T out = T();

	while (!(cin >> out)) {
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << "Error!" "\n";
		cout << strQuery << "\n> ";
	}

	return out;
}

/**********************************************************************************************//**
 * @fn	string readLine();
 *
 * @brief	Reads the line.
 *
 * @author	Jo�o
 * @date	20-11-2016
 *
 * @return	The line.
 **************************************************************************************************/

string readLine();

/**********************************************************************************************//**
 * @fn	string readPassword(const char *prompt, bool show_asterisk);
 *
 * @brief	Reads a password and shadows, if true, the characters on the screen.
 *
 * @author	Jo�o
 * @date	20-11-2016
 *
 * @param	prompt		 	The prompt.
 * @param	show_asterisk	True to show, false to hide the asterisk.
 *
 * @return	The password.
 **************************************************************************************************/

string readPassword(const char *prompt, bool show_asterisk);

/**********************************************************************************************//**
 * @fn	void getEnter();
 *
 * @brief	Waits to user to press ENTER.
 *
 * @author	Jo�o
 * @date	20-11-2016
 **************************************************************************************************/

void getEnter();
// espera que o utilizador prima ENTER

/**********************************************************************************************//**
 * @fn	void ClearScreen();
 *
 * @brief	Clears the screen.
 *
 * @author	Jo�o
 * @date	20-11-2016
 **************************************************************************************************/

void ClearScreen();

/**********************************************************************************************//**
 * @fn	string ltrim(string& s);
 *
 * @brief	eliminates initial spaces the given string may have.
 *
 * @author	Jo�o
 * @date	20-11-2016
 *
 * @param [in,out]	s	The string to process.
 *
 * @return	A string.
 **************************************************************************************************/

string ltrim(string& s);
//elimina os espa�os inicias de uma string
// @param s - string a ser analisada

/**********************************************************************************************//**
 * @fn	string rtrim(string& s);
 *
 * @brief	eliminates last spaces the given string can have.
 *
 * @author	Jo�o
 * @date	20-11-2016
 *
 * @param [in,out]	s	The string to process.
 *
 * @return	A string.
 **************************************************************************************************/

string rtrim(string& s);
//elimina os espa�os finais de uma string
// @param s - string a ser analisada

/**********************************************************************************************//**
 * @fn	bool is_empty(ifstream& pFile);
 *
 * @brief	Query if 'pFile' is empty.
 *
 * @author	Jo�o
 * @date	20-11-2016
 *
 * @param [in,out]	pFile	The file.
 *
 * @return	True if empty, false if not.
 **************************************************************************************************/

bool is_empty(ifstream& pFile);
#endif /* HELPER_H_ */
