#pragma once
#include "Magazine.h"
#include "AList.h"

class AMagazineList : public AList<Magazine>
{
public:
	virtual void WriteToConsoleTheOldestMagazine() const = 0;
	virtual void WriteToConsoleTheLatestMagazine() const = 0;
	virtual void WriteToConsoleTheMostExpensiveMagazine() const = 0;
	virtual void WriteToConsoleTheMostCheaperMagazine() const = 0;
	virtual ~AMagazineList() {};
};