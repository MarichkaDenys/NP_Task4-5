#include "BookSerializer.h"
#include <iostream>
#include <fstream>
#define books_file_name "C:\\Users\\Ã‡–≥◊Í¿\\source\\repos\\Bookshop4\\Bookshop4\\books.txt"

void BookSerializer::ReadBooksFromFile(Book**& books, int& count)
{
	
	ifstream fin(books_file_name);

	if (!fin.is_open())
		cout << "File not open.\n";
	else
	{
		books = new Book * [100];
		count = 0;

		string firstname, lastname, title; int year; double price;
		while (!fin.eof())
		{
			fin >> firstname >> lastname >> title >> year >> price;
			books[count++] = new Book(firstname, lastname, title, year, price);
		}

		fin.close();

	}

}
void BookSerializer::WriteBooksToFile(Book** books, int count)
{
	ofstream fout(books_file_name);

	if (!fout.is_open())
		cout << "File not open.\n";
	else
	{
		for (int i = 0; i < count; i++)
		{
			fout << books[i]->GetFirstName() << " " << books[i]->GetLastName() << " " << books[i]->GetTitle() << " " << books[i]->GetYear() << " " << books[i]->GetPrice();
			if (i != count - 1)
				fout << endl;
		}

		fout.close();
	}
}


void BookSerializer::ReadBooksFromFile(Book*& books, int& count)
{
	ifstream fin("books.txt");

	if (!fin.is_open())
		cout << "File not open.\n";
	else
	{
		books = new Book[100];
		count = 0;

		string firstname, lastname, title; int year; double price;
		while (!fin.eof())
		{
			fin >> firstname >> lastname >> title >> year >> price;
			books[count++] = Book(firstname, lastname, title, year, price);
		}

		fin.close();

	}
}

void BookSerializer::WriteBooksToFile(Book* books, int count)
{
	ofstream fout("books.txt");

	if (!fout.is_open())
		cout << "File not open.\n";
	else
	{
		for (int i = 0; i < count; i++)
		{
			fout << books[i].GetFirstName() << " " << books[i].GetLastName() << " " << books[i].GetTitle() << " " << books[i].GetYear() << " " << books[i].GetPrice();
			if (i != count - 1)
				fout << endl;
		}

		fout.close();
	}
}