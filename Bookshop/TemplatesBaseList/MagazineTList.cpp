#include "MagazineTList.h"
#include "MagazineSerializer.h"
#include "HelpersT.h"

#include <iostream>
using namespace std;
using namespace TemplatedLists;

MagazineList::MagazineList()
{
	MagazineSerializer::ReadMagazinesFromFile(items, current);
}

MagazineList::~MagazineList()
{
	MagazineSerializer::WriteMagazinesToFile(items, current);
}

void MagazineList::Add(Magazine& item)
{
	List<Magazine>::Add(item);
}

void MagazineList::WriteAllToConsole() const
{
	List<Magazine>::WriteAllToConsole();
}

void MagazineList::WriteToConsoleTheOldestMagazine() const
{
	WriteToConsoleTheOldestItemsWithAge(items, current);
}

void MagazineList::WriteToConsoleTheLatestMagazine() const
{
	WriteToConsoleTheLatestItemsWithAge(items, current);
}

void MagazineList::WriteToConsoleTheMostExpensiveMagazine() const
{
	WriteToConsoleTheMostExpensiveItemsWithAge(items, current);
}

void MagazineList::WriteToConsoleTheMostCheaperMagazine() const
{
	WriteToConsoleTheMostCheaperItemsWithAge(items, current);
}