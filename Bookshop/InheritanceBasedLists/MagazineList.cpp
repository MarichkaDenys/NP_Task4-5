#include "MagazineList.h"
#include "MagazineSerializer.h"
#include <iostream>
using namespace std;
using namespace  InheritanceLists;

MagazineList::MagazineList()
{
	Magazine** magazines;
	MagazineSerializer::ReadMagazinesFromFile(magazines, current);
	prints = (Print**)magazines;
}

MagazineList::~MagazineList()
{
	//MagazineSerializer::WriteMagazinesToFile((Magazine**)prints, current);
}

void MagazineList::Add(Magazine& magazine)
{
	PrintList::Add(new Magazine(magazine));
	MagazineSerializer::WriteMagazinesToFile((Magazine**)prints, current);
}

//void MagazineList::Add(Magazine& magazine)
//{
//	prints[current] = (Print*) new Magazine(magazine);
//	current++;
//}

//void MagazineList::operator+(Magazine& magazine)
//{
//	this->Add(magazine);
//}

void MagazineList::WriteAllToConsole() const
{
	PrintList::WriteAllToConsole();
}

void MagazineList::WriteToConsoleTheOldestMagazine() const
{
	WriteToConsoleTheOldestPrint();
}
void MagazineList::WriteToConsoleTheLatestMagazine() const
{
	WriteToConsoleTheLatestPrint();
}
void MagazineList::WriteToConsoleTheMostExpensiveMagazine() const
{
	WriteToConsoleTheMostExpensivePrint();
}
void MagazineList::WriteToConsoleTheMostCheaperMagazine() const
{
	WriteToConsoleTheMostCheaperPrint();
}