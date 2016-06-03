// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: DigitalBooks implementation

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#include "DigitalBooks.h"

//default constructor
DigitalBooks::DigitalBooks()
{
	format = "null";
}

//paramaterized constructor
DigitalBooks::DigitalBooks(Author* _author, const string& _title, int _numPages, double _price, const string& _format)
	:Book(_author, _title, _numPages, _price)
{
	format = _format;
}

//getFormat function
string DigitalBooks::getFormat() const
{
	return format;
}

//readData function
void DigitalBooks::readData(ifstream& streamIn)
{
	Book::readData(streamIn);
	getline(streamIn, format);

	if (!streamIn.eof() && streamIn.fail())
		throw FileIOExceptions(READ_ERROR);
	if (streamIn.eof())
		throw FileIOExceptions(END_OF_FILE);
}

//writeData function
void DigitalBooks::writeData(ofstream& streamOut)
{	
	Book::writeData(streamOut);
	streamOut << format << endl;
}

