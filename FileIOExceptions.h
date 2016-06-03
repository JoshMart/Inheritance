// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: header file for FileIOExceptions class

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#pragma once
#include <iostream>
using namespace std;

class FileIOExceptions
{
public:
	//default constructor
	// Purpose: default initilizer for the FileIOExceptions class
	// Parameters: none
	// Returns: None
	FileIOExceptions();
	//parameterized constructor
	// Purpose: paramaterized initilizer for the FileIOExceptions class
	// Parameters: int containing the error code
	// Returns: None
	FileIOExceptions(int);
	//getException function
	// Purpose: prints a basic error message to the console
	// Parameters: none
	// Returns: None
	void getException() const;
	//getErrorCode function
	// Purpose:	getter to return the error code
	// parameters: none
	//returns: none
	int getErrorCode() const;
private:
	//variable to store the error code caused the exception and error code values
	int errorCode;
	const int END_OF_FILE = 1;
	const int READ_ERROR = 2;
	const int FILE_OPEN_ERROR = 3;
};

