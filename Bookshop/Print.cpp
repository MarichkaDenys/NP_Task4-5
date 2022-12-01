#include "Print.h"

#include <iostream>
using namespace std;

Print::Print(string title, int year, double price)
{
	/*if (!IsValidPrint(title, year, price))
		throw "Invalid input data!";*/

	this->title = title;
	this->year = year;
	this->price = price;
}

bool Print::IsValidPrint(string title, int year, double price)
{

	for (int i = 0; i < title.length(); i++)
	{
		if (isdigit(title[i]))
			return false;
	}

	if (year < 0)
		return false;
	if (price < 0)
		return false;

	return true;
}

void Print::WriteToConsole()
{
	cout << title << " " << year << " " << price;
}


string Print::GetTitle() const
{
	return title;
}
int Print::GetYear() const
{
	return year;
}
double Print::GetPrice() const
{
	return price;
}

int Print::GetCurrentYear()
{
	return 2022;
}

int Print::GetAge() const
{
	return Print::GetCurrentYear() - year;
}