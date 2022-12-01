#include "BookList.h"
#include "BookSerializer.h"
#include <iostream>
using namespace std;
using namespace InheritanceLists;

BookList::BookList()
{
	Book** books;
	BookSerializer::ReadBooksFromFile(books, current);
	prints = (Print**)books;
}

BookList::~BookList()
{
	//BookSerializer::WriteBooksToFile((Book**)prints, current);
}

void BookList::Add(Book& book)
{
	PrintList::Add(new Book(book));
	BookSerializer::WriteBooksToFile((Book**)prints, current);
}

//void BookList::Add(Book& book)
//{
//	prints[current] = (Print*) new Book(book);
//	current++;
//}

//void BookList::operator+(Book& book)
//{
//	this->Add(book);
//}

void BookList::WriteAllToConsole() const
{
	PrintList::WriteAllToConsole();
}


void BookList::WriteToConsoleTheOldestBook() const
{
	WriteToConsoleTheOldestPrint();
}
void BookList::WriteToConsoleTheLatestBook() const
{
	WriteToConsoleTheLatestPrint();
}
void BookList::WriteToConsoleTheMostExpensiveBook() const
{
	WriteToConsoleTheMostExpensivePrint();
}
void BookList::WriteToConsoleTheMostCheaperBook() const
{
	WriteToConsoleTheMostCheaperPrint();
}