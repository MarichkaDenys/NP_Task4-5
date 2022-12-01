#pragma once

#include "Magazine.h"
#include "PrintList.h"
#include "AMagazineList.h"

namespace InheritanceLists
{
	class MagazineList : private PrintList, public AMagazineList
	{
	public:
		MagazineList();
		~MagazineList();

		void Add(Magazine& magazine);

		//void operator+(Magazine& magazine);

		void WriteAllToConsole() const;
		void WriteToConsoleTheOldestMagazine() const;
		void WriteToConsoleTheLatestMagazine() const;
		void WriteToConsoleTheMostExpensiveMagazine() const;
		void WriteToConsoleTheMostCheaperMagazine() const;
	};
}