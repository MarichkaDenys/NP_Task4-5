#include "PrintList.h"

#include <iostream>
using namespace std;

PrintList::PrintList()
{
	current = 0;
	prints = new Print * [100];
}

PrintList::~PrintList()
{
	for (int i = 0; i < current; i++)
	{
		delete prints[i];
	}

	delete[] prints;
}

void PrintList::Add(Print* print)
{
	prints[current] = print;
	current++;
}

void PrintList::WriteAllToConsole() const
{
	for (int i = 0; i < current; i++)
	{
		prints[i]->WriteToConsole();
		cout << endl;
	}
}

void PrintList::WriteToConsoleTheOldestPrint() const
{
	int maxAge = prints[0]->GetAge();  int maxAgeIdx = 0;
	for (int i = 1; i < current; i++)
	{
		if (prints[i]->GetAge() > maxAge)
		{
			maxAge = prints[i]->GetAge();
			maxAgeIdx = i;
		}
	}
	prints[maxAgeIdx]->WriteToConsole();
}

void PrintList::WriteToConsoleTheLatestPrint() const
{
	int minAge = prints[0]->GetAge();  int minAgeIdx = 0;
	for (int i = 1; i < current; i++)
	{
		if (prints[i]->GetAge() < minAge)
		{
			minAge = prints[i]->GetAge();
			minAgeIdx = i;
		}
	}
	prints[minAgeIdx]->WriteToConsole();
}

void PrintList::WriteToConsoleTheMostExpensivePrint() const
{
	double maxPrice = prints[0]->GetPrice(); int maxPriceIdx = 0;
	for (int i = 1; i < current; i++)
	{
		if (prints[i]->GetPrice() > maxPrice)
		{
			maxPrice = prints[i]->GetPrice();
			maxPriceIdx = i;
		}
	}
	prints[maxPriceIdx]->WriteToConsole();

}
void PrintList::WriteToConsoleTheMostCheaperPrint() const
{
	double minPrice = prints[0]->GetPrice(); int minPriceIdx = 0;
	for (int i = 1; i < current; i++)
	{
		if (prints[i]->GetPrice() < minPrice)
		{
			minPrice = prints[i]->GetPrice();
			minPriceIdx = i;
		}
	}
	prints[minPriceIdx]->WriteToConsole();
}