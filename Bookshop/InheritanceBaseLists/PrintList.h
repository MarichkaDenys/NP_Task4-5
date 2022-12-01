#pragma once

#include "Print.h"

class PrintList
{
protected:
	Print** prints;
	int current;

	void Add(Print* print);

	void WriteToConsoleTheOldestPrint() const;
	void WriteToConsoleTheLatestPrint() const;
	void WriteToConsoleTheMostExpensivePrint() const;
	void WriteToConsoleTheMostCheaperPrint() const;

public:
	PrintList();
	~PrintList();

	void WriteAllToConsole() const;

};