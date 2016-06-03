// Author: Joshua Martinetti
// Assignment: Project_03
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 2/8//16
// Description: cpp file for FileIOExceptions class

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#include "FileIOExceptions.h"
//default constructor
FileIOExceptions::FileIOExceptions()
{
	errorCode = 0;
}
//parameterized constructor
FileIOExceptions::FileIOExceptions(int _errorCode)
{
	errorCode = _errorCode;
}
//compares error code and outputs the correct error message
void FileIOExceptions::getException() const
{
	if (errorCode == END_OF_FILE)
	{
		cout << "File read complete. Now outputting data. \n" << endl;
	}
	else if (errorCode == READ_ERROR)
	{
		cout << "\nAn error during the reading of the file occured."<<'\n'<<"Please ensure the data in the file is formatted properly." << endl;
		cout << "Program cannot continue, terminating program." << '\n' << endl;
	}
	else if (errorCode == FILE_OPEN_ERROR)
	{
		cout << "\nThe file could not be opened." << '\n' << "Please ensure the file is named 'bookData.txt' and run the program again." << endl;
		cout << "Program cannot continue, terminating program." << '\n' << endl;
	}
	else //default error code for unknown error
	{
		cout << "\nAn unknown error occured. Ensure the file and data are formatted properly and run the program again." << endl;
		cout << "Program cannot continue, terminating program." << '\n' << endl;
	}
}
//returns class error code
int FileIOExceptions::getErrorCode() const
{
	return errorCode;
}
