#pragma once
#include "Book.h"
#include "AList.h"

class ABookList : public AList<Book>
{
public:
	virtual void WriteToConsoleTheOldestBook() const = 0;
	virtual void WriteToConsoleTheLatestBook() const = 0;
	virtual void WriteToConsoleTheMostExpensiveBook() const = 0;
	virtual void WriteToConsoleTheMostCheaperBook() const = 0;
	virtual ~ABookList() {};
};
