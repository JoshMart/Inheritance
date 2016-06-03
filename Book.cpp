// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: cpp file containing Author and Book class implementations

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#include "Book.h"

//Default constructor
Author::Author()
{
	name = "null";
	address = "null";
}
//Parameterized constructor
Author::Author(const string& _name, const string& _address)
{
	name = _name;
	address = _address;
}
//getName getter
string Author::getName() const
{
	return name;
}
//getAddress getter
string Author::getAddress() const
{
	return address;
}
//writes data from Author class
void Author::writeData(ofstream& outStream)
{
	outStream << name << '\n' << address << '\n';
}
//reads data for the Author class
void Author::readData(ifstream& streamIn)
{
	getline(streamIn, name);
	getline(streamIn, address);
}

//Default constructor
Book::Book()
{
	title = "null";
	pages = 0;
	price = 0;
}
//Paramaterized constructor
Book::Book(Author* _auth1, const string& _title, int _pages, double _price)
{
	auth1 = _auth1;
	title = _title;
	pages = _pages;
	price = _price;
}
//auth1 getter
Author Book::getAuth1()
{
	return *auth1;
}
//title getter
string Book::getTitle() const
{
	return title;
}
//pages getter
int Book::getPages() const
{
	return pages;
}
//price getter
double Book::getPrice() const
{
	return price;
}
//writes data from Book class
void Book::writeData(ofstream& streamOut)
{
	auth1->writeData(streamOut);//let Author class handle its own writing
	streamOut << title << '\n';		
	streamOut << pages << '\n' << price << endl;
}
//reads data into the Book class
void Book::readData(ifstream& streamIn)
{
		//throws exception if bad data or sudden eof is encountered
	auth1 = new Author();
	auth1->readData(streamIn);//Author reads its own data
	
	if (!streamIn.eof() && streamIn.fail())
		throw FileIOExceptions(READ_ERROR);
	if (streamIn.eof())
		throw FileIOExceptions(END_OF_FILE);
		
	getline(streamIn, title);
	getline(streamIn, pagesTemp);
	getline(streamIn, priceTemp);
	if (!streamIn.eof() && streamIn.fail())
		throw FileIOExceptions(READ_ERROR);
	if (streamIn.eof())
		throw FileIOExceptions(END_OF_FILE);
		//throws exception if stoi/stoid parameters are invalid
	try
	{
		pages = stoi(pagesTemp);//convert from string to int
		price = stod(priceTemp);//convert from string to double
	}
	catch (invalid_argument)
	{
		throw FileIOExceptions(READ_ERROR);
		ioe.getErrorCode();
	}
}
