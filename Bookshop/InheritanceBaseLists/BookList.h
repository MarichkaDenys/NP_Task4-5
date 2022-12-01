#pragma once
#include "Book.h"
#include "PrintList.h"
#include "ABookList.h"

namespace InheritanceLists
{
	class BookList : private PrintList, public ABookList
	{
	public:
		BookList();
		~BookList();

		void Add(Book& book);

		//void operator+(Book& book);

		void WriteAllToConsole() const;
		void WriteToConsoleTheOldestBook() const;
		void WriteToConsoleTheLatestBook() const;
		void WriteToConsoleTheMostExpensiveBook() const;
		void WriteToConsoleTheMostCheaperBook() const;
	};
}