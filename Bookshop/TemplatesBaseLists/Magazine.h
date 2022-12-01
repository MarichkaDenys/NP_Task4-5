#pragma once
#include "Print.h"

#include <string>
using namespace std;

class Magazine : public Print
{
	string editor;
	bool IsValid(string editor);
public:
	Magazine(string editor = "", string title = "", int year = 0, double price = 0.0);
	void WriteToConsole();
	string GetEditor() const;
};