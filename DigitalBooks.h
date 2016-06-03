// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: Digital books class, child class of Book

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#pragma once
#include "Book.h"

//Base class Book
class DigitalBooks 	: public Book
{
public:
	// Default Constructor
	// Purpose: Initialize object with default values
	// Parameters: none
	// Returns: none
	DigitalBooks();

	// Parameterized Constructor
	// Purpose: Initialize object with passed values
	// Parameters: Author class pointer, number of pages, price, title, format
	// Returns: none
	DigitalBooks(Author*, const string&, int, double, const string&);

	// getFormat function
	// Purpose: Returns the format
	// Parameters: none
	// Returns: format
	string getFormat() const;

	// readData function
	// Purpose: Reads from an ifstream and sets class varibles accordingly
	// Parameters: ifstream
	// Returns: none
	void readData(ifstream&);

	// writeData function
	// Purpose: Writes class variables from an ofstream
	// Parameters: ofstream
	// Returns: none
	void writeData(ofstream&);
private:
	//format of the digital book
	string format;
};

