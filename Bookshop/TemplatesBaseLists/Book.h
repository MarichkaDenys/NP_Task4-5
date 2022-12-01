#pragma once
#include "Print.h"

#include <string>
using namespace std;

class Book : public Print
{
	string firstname, lastname;

	bool IsValid(string firstname, string lastname);


public:
	Book(string firstname = "", string lastname = "", string title = "", int year = 0, double price = 0.0);
	void WriteToConsole();

	string GetFirstName() const;
	string GetLastName() const;

	friend ostream& operator<< (ostream& out, const Book& book);
	friend istream& operator>> (istream& in, Book& book);
};