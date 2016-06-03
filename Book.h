// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: Header file containing Author and Book classes. Book is a virtual class.

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "FileIOExceptions.h"

const int END_OF_FILE = 1;
const int READ_ERROR = 2;

using namespace std;

class Author
{
public:
	// Author class initilizer
	// Purpose: default initilizer
	// Parameters: None
	// Returns: None
	Author();
	// Author class parameterized initilizer
	// Purpose: parameterized initilizer
	// Parameters: name as string, address as string
	// Returns: None
	Author(const string&, const string&);
	// getName method
	// Purpose: Returns name variable
	// Parameters: None
	// Returns: name as a string
	string getName() const;
	// getAddress method
	// Purpose: Returns address variable
	// Parameters: None
	// Returns: address as a string
	string getAddress() const;
	// writeData method
	// Purpose: writes data members from the class
	// Parameters: referenced ofstream
	// Returns: none
	void writeData(ofstream&);
	// getAddress method
	// Purpose: Returns address variable
	// Parameters: None
	// Returns: address as a string
	void readData(ifstream&);

private:
	//Class variables
	string name;
	string address;
};

class Book
{
public:
	// Book class initilizer
	// Purpose: default initilizer
	// Parameters: None
	// Returns: None
	Book();
	// Book class parameterized initilizer
	// Purpose: parameterized initilizer
	// Parameters: Author object, title as string, pages as int, price as double
	// Returns: None
	Book(Author*, const string&, int, double);
	// getAuth1method
	// Purpose: Returns auth1 variable
	// Parameters: None
	// Returns: auth1 Author object
	Author getAuth1();
	// getTitle method
	// Purpose: Returns title variable
	// Parameters: None
	// Returns: Title as a string
	string getTitle() const;
	// getPages method
	// Purpose: Returns pages variable
	// Parameters: None
	// Returns: pages as a int
	int getPages() const;
	// getPrice method
	// Purpose: Returns price variable
	// Parameters: None
	// Returns: price as a double
	double getPrice() const;
	// getAddress method
	// Purpose: Returns address variable
	// Parameters: None
	// Returns: address as a string
	virtual void writeData(ofstream&);
	// writeData method
	// Purpose: writes data members from the class
	// Parameters: referenced ofstream
	// Returns: none
	virtual void readData(ifstream&);
	
private:
	//Class variables
	Author* auth1;
	string title;
	string pagesTemp;
	string priceTemp;
	FileIOExceptions ioe;
	int pages;
	double price;
	int status;
};