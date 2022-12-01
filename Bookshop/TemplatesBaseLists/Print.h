#pragma once
#include <string>
using namespace std;

class Print
{

protected:
	string title;
	int year;
	double price;

	bool IsValidPrint(string title, int year, double price);


public:

	Print(string title = "", int year = 0, double price = 0.0);
	virtual void WriteToConsole();

	string GetTitle() const;
	int GetYear() const;
	double GetPrice() const;
	int GetAge() const;
	static int GetCurrentYear();

};