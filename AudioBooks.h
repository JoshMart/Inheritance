// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: AudioBooks class, child class of Book

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#pragma once
#include "Book.h"

class AudioBooks :	public Book
{
public:
	// Default constructor
	// Purpose: sets default variables for class
	// Parameters: none
	// Returns: none
	AudioBooks();

	// Parameterized constructor
	// Purpose: sets class variables according to passed values
	// Parameters: Author class pointer, number of pages, price, title, length of book
	// Returns: none
	AudioBooks(Author*, string, int, double, int);

	// getLength function
	// Purpose: returns length
	// Parameters: none
	// Returns: length
	int getLength() const;

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
	//length of the audio book in minutes
	int length;
	FileIOExceptions ioe;
};

