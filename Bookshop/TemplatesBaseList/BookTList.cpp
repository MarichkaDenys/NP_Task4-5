#include "BookTList.h"
#include "BookSerializer.h"
#include "HelpersT.h"
#include <iostream>
using namespace std;
using namespace TemplatedLists;

BookList::BookList()
{
	BookSerializer::ReadBooksFromFile(items, current);     // typeof(items) = Book*
}

BookList::~BookList()
{
	BookSerializer::WriteBooksToFile(items, current);
}

void BookList::Add(Book& item)
{
	List<Book>::Add(item);
}

void BookList::WriteAllToConsole() const
{
	List<Book>::WriteAllToConsole();
}

void BookList::WriteToConsoleTheOldestBook() const
{
	WriteToConsoleTheOldestItemsWithAge(items, current);
}

void BookList::WriteToConsoleTheLatestBook() const
{
	WriteToConsoleTheLatestItemsWithAge(items, current);
}

void BookList::WriteToConsoleTheMostExpensiveBook() const
{
	WriteToConsoleTheMostExpensiveItemsWithAge(items, current);
}

void BookList::WriteToConsoleTheMostCheaperBook() const
{
	WriteToConsoleTheMostCheaperItemsWithAge(items, current);
}