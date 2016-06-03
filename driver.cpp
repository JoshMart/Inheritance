// Author: Joshua Martinetti
// Assignment: Project_05
// Instructor: Professor DeBry
// Class: 1410 Section: 002 
// Date Written: 3/5//16
// Description: Uses the Author and Book classes to create objects, store them to a vector, and display the data.

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
//===========================================================================================================================

#include "driver.h"

int main() //main function was given
{
	// Display Menu 
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;

	cout << "\nCS 1410 Project 5";
	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	// run the selected option
	cin >> option;
	if (option == CREATE)
	{
		createTestFile();
		cout << "\nTest file has been created.";
	}
	else if (option == READ)
	{
		readTestFile();
	}
	else
	{
		cout << "\nInvalid option.";
	}

	system("PAUSE");
	return 0;
}

void displayBooks(const vector<Book*>& books)
{
	// set up cout to display currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);	

	// display heading
	cout << "\n<<<Recommended Reading List>>>\n" << endl;

	//Loop through books to output the correct format
	for (int i = 0; i < books.size(); i++)
	{   
		//check to see if books[i] is an Audiobook
		AudioBooks* bp = dynamic_cast<AudioBooks*>(books[i]); //use dynamic casting to check object type
		if (bp)
		{
			cout << bp->getTitle() << endl;
			cout << bp->getAuth1().getName() << endl;
			cout << bp->getAuth1().getAddress() << endl;
			cout << bp->getPages() << " pages" << endl;
			cout << bp->getLength() << " minutes long" << endl;
			cout << "$" << bp->getPrice() << '\n' << endl;;
		}
		else
		{
			// see if it is a digital book
			DigitalBooks* bp = dynamic_cast<DigitalBooks*>(books[i]);
			if (bp)
			{
				cout << bp->getTitle() << endl;
				cout << bp->getAuth1().getName() << endl;
				cout << bp->getAuth1().getAddress() << endl;
				cout << bp->getPages() << " pages" << endl;
				cout << bp->getFormat() << " format" << endl;
				cout << "$" << bp->getPrice() << '\n' << endl;;
			}
			else // It is not one of the child classes, so it must be a base class (BOOK) object
			{
				cout << books[i]->getTitle() << endl;
				cout << books[i]->getAuth1().getName() << endl;
				cout << books[i]->getAuth1().getAddress() << endl;
				cout << books[i]->getPages() << " pages" << endl;
				cout << "$" << books[i]->getPrice() << '\n' << endl;;;
			}
		}
		
	}

}

void createTestFile() //this function was given
{
	// create a vector for storing the account objects
	vector<Book*> myBooks;

	// add the books to the vector
	// create eveything on the heap because we need to work with Book*
	myBooks.push_back(new AudioBooks(new Author("J.K.Rowling", "Edinburgh, Scotland"), "Harry Potter and the Sorcerer's Stone", 256, 24.95, 415));
	myBooks.push_back(new DigitalBooks(new Author("Suzanne Collins", "Connecticut, USA"), "Mockingjay", 400, 12.99, "PDF"));
	myBooks.push_back(new Book(new Author("J.R.R. Tolkien", "Bournmouth, England"), "The Hobbit", 322, 14.29));

	// write the books to a file
	// the file will be in the same folder as the executable file
	// assume that the file opens
	ofstream outputFile;
	outputFile.open("bookData.txt");

	for (unsigned i = 0; i < myBooks.size(); ++i)
	{
		// Use RTTI to get the type of object being pointed to, cast returns null if cast fails
		// see if it is an audiobook and if it is, output "AUDIOBOOK" to the file to mark the output
		AudioBooks* bp = dynamic_cast<AudioBooks*>(myBooks[i]);
		if (bp)
		{
			outputFile << "AUDIOBOOK" << endl;
		}
		else
		{
			// see if it is a digital book, if it is output "DIGITALBOOK" to the file
			DigitalBooks* bp = dynamic_cast<DigitalBooks*>(myBooks[i]);
			if (bp)
			{
				outputFile << "DIGITALBOOK" << endl;
			}
			else // It is not one of the child classes, so it must be a base class (BOOK) object
			{
				outputFile << "BOOK" << endl;
			}
		}
		// now have the book object write itself to the file
		myBooks[i]->writeData(outputFile);		
	}
	outputFile.close();
}

void readTestFile()
{
	vector<Book*> myBooks;
	ifstream inputFile;
	string classCode;
	
	try  //throw exception if the file can't be opened
	{
		openFile(inputFile, "bookData.txt");
		try  //throw exception if the data is not formatted correctly or eof is reached
		{
			do
			{
				getline(inputFile, classCode); //check the first line of every entry and let the appropriate functions handle it
				if (classCode == "AUDIOBOOK")
				{
					AudioBooks* ab = new AudioBooks();
					ab->readData(inputFile);
					myBooks.push_back(ab);
				}
				else if (classCode == "DIGITALBOOK")
				{
					DigitalBooks* db = new DigitalBooks();
					db->readData(inputFile);
					myBooks.push_back(db);
				}
				else
				{
					Book* b = new Book();
					b->readData(inputFile);
					myBooks.push_back(b);
				}
			} while (!inputFile.eof());
		}
		catch (FileIOExceptions e) //EOF exception treated as the signal point to start displaying to the console
		{
			e.getException();
			if (e.getErrorCode() == END_OF_FILE)
				displayBooks(myBooks);
		}
	}
	catch (FileIOExceptions& e)
	{
		e.getException();
	}
	
}

void openFile(ifstream& in, const string& _name)
{
	// try to open the file
	in.open(_name);

	// if the fail but is set, the file won't open ... throw an open error
	if (!in)
	{
		throw FileIOExceptions(FILE_OPEN_ERROR);
	}
}