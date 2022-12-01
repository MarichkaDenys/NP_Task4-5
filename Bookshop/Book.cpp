#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string firstname, string lastname, string title, int year, double price) : Print(title, year, price)
{
	if (!IsValid(firstname, lastname) || !IsValidPrint(title, year, price))
		throw "Invalid input data for book!";

	this->firstname = firstname;
	this->lastname = lastname;

}

bool Book::IsValid(string firstname, string lastname)
{
	for (int i = 0; i < firstname.length(); i++)
	{
		if (isdigit(firstname[i]))
			return false;
	}

	for (int i = 0; i < lastname.length(); i++)
	{
		if (isdigit(lastname[i]))
			return false;
	}

	return true;
}

void Book::WriteToConsole()
{
	cout << firstname << " " << lastname << " " << title << " " << year << " " << price;
}

string Book::GetFirstName() const
{
	return firstname;
}

string Book::GetLastName() const
{
	return lastname;
}

ostream& operator<< (ostream& out, const Book& book)
{
	out << book.firstname << " " << book.lastname << " " << book.title << " " << book.year << " " << book.price;

	return out;
}

istream& operator>> (istream& in, Book& book)
{
	in >> book.firstname;
	in >> book.lastname;
	in >> book.title;
	in >> book.year;
	in >> book.price;

	return in;
}