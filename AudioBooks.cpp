// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: AudioBooks implementation

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#include "AudioBooks.h"

//default constructor
AudioBooks::AudioBooks()	
{
	length = 0;
}

//paramaterized constructor
AudioBooks::AudioBooks(Author* _author, string _title, int _numPages, double _price, int _length)
	:Book(_author, _title, _numPages, _price)
{
	length = _length;
}

//getLength function
int AudioBooks::getLength() const
{
	return length;
}

//read data function
void AudioBooks::readData(ifstream& streamIn)
{
	string lengthTemp;

	Book::readData(streamIn);//use the Book class to read in its own data
	getline(streamIn, lengthTemp);
	
	try
	{
		length = stoi(lengthTemp);//need to change from string to int
	}
	catch (invalid_argument)
	{
		throw FileIOExceptions(READ_ERROR);
		ioe.getErrorCode();
	}

	if (!streamIn.eof() && streamIn.fail())
		throw FileIOExceptions(READ_ERROR);
	if (streamIn.eof())
		throw FileIOExceptions(END_OF_FILE);
}

//writeData function
void AudioBooks::writeData(ofstream& streamOut)
{	
	Book::writeData(streamOut);
	streamOut << length << endl;
}