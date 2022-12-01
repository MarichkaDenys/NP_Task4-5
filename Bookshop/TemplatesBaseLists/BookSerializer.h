#pragma once
#include "Book.h"


class BookSerializer
{
public:
	static void ReadBooksFromFile(Book**& books, int& count);
	static void WriteBooksToFile(Book** books, int count);

	static void ReadBooksFromFile(Book*& books, int& count);
	static void WriteBooksToFile(Book* books, int count);
};