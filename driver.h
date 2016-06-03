// Author: Joshua Martinetti
// Assignment: Project_03
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 2/8//16
// Description: Uses the Author and Book classes to create objects, store them to a vector, and display the data.

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

const int FILE_OPEN_ERROR = 3;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DigitalBooks.h"
#include "AudioBooks.h"
#include "Book.h"  // the file name for your classes may be different
using namespace std;

// The displayBooks function
// Purpose: Display all of the data about a book
// Parameters: A vector of Book objects
// Returns: none
void displayBooks(const vector<Book>&);

// The createTestFile function
// Purpose: Create a test file using the book data
// Parameters: none
// Returns: none
void createTestFile();

// The readTestFile function
// Purpose: Read the test file and display the results
// Parameters: none
// Returns: none
void readTestFile();

// The openFile function
// Purpose: Open a file for reading
// Parameters: an istream object and a file name
// Returns: none
// Throws a FileException if the file cannot be opened
void openFile(ifstream&, const string&);