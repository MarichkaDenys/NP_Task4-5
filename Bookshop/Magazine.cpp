#include "Magazine.h"
#include <iostream>
using namespace std;

Magazine::Magazine(string editor, string title, int year, double price) : Print(title, year, price)
{
	if (!IsValid(editor) || !IsValidPrint(title, year, price))
		throw "Invalid input data for magazine!";

	this->editor = editor;
}

bool Magazine::IsValid(string editor)
{
	for (int i = 0; i < editor.length(); i++)
	{
		if (isdigit(editor[i]))
			return false;
	}
	return true;
}


void Magazine::WriteToConsole()
{
	cout << editor << " " << title << " " << year << " " << price;
}

string Magazine::GetEditor() const
{
	return editor;
}