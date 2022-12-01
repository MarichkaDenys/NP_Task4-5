#include "Menu.h"
#include "Book.h"
#include "Factory.h"
#include "Authors.h"
#include "Logger.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu()
{
	ListFactoryProvider factoryProvider;
	AListFactory* listFactory = factoryProvider.GetListFactory();
	booklist = listFactory->GetBookList();
	magazinelist = listFactory->GetMagazineList();
}

Menu::~Menu()
{
	delete booklist;
	delete magazinelist;
}

void Menu::Show()
{
	cout << "Bookshop.Admin.\n";

	char userInput;
	do
	{
		showBaseMenu();

		cin >> userInput;

		if (userInput == '1')
		{
			showAllBooks();
			continue;
		}

		if (userInput == '2')
		{
			showAuthors();
			continue;
		}

		if (userInput == '3')
		{
			analysisbookActivity();
			continue;
		}

		if (userInput == '4')
		{
			addBook();
			continue;
		}

		if (userInput == '5')
		{
			showAllMagazines();
			continue;
		}

		if (userInput == '6')
		{
			analysismagazineActivity();
			continue;
		}

		if (userInput == '7')
		{
			addMagazine();
			continue;
		}
	} while (userInput != '0');

}

void Menu::showBaseMenu()
{
	cout << endl
		<< "Please select an option:\n"
		<< "1. Show all books.\n"
		<< "2. Authors covered by the bookshop.\n"
		<< "3. Analysis of the book's activity.\n"
		<< "4. Add a book.\n"

		<< "5. Show all magazines.\n"
		<< "6. Analysis of the magazine's activity.\n"
		<< "7. Add a magazine.\n"

		<< "0. Exit.\n";
}


void Menu::showAnalysisBookMenu()
{
	cout << endl
		<< "\tPlease select an option:\n"
		<< "\t1. The oldest book.\n"
		<< "\t2. The latest book.\n"
		<< "\t3. The most expensive book.\n"
		<< "\t4. The most cheaper book.\n"
		<< "\t0. Back\n";
}

void Menu::analysisbookActivity()
{
	char userInput;
	do
	{
		showAnalysisBookMenu();

		cin >> userInput;

		if (userInput == '1')
		{
			showTheOldestBook();
			continue;
		}

		if (userInput == '2')
		{
			showTheLatestBook();
			continue;
		}

		if (userInput == '3')
		{
			showTheMostExpensiveBook();
			continue;
		}

		if (userInput == '4')
		{
			showTheMostCheaperBook();
			continue;
		}
	} while (userInput != '0');

}



void Menu::showAnalysisMagazineMenu()
{
	cout << endl
		<< "\tPlease select an option:\n"
		<< "\t1. The oldest magazine.\n"
		<< "\t2. The latest magazine.\n"
		<< "\t3. The most expensive magazine.\n"
		<< "\t4. The most cheaper magazine.\n"
		<< "\t0. Back\n";
}

void Menu::analysismagazineActivity()
{
	char userInput;
	do
	{
		showAnalysisMagazineMenu();

		cin >> userInput;

		if (userInput == '1')
		{
			showTheOldestMagazine();
			continue;
		}

		if (userInput == '2')
		{
			showTheLatestMagazine();
			continue;
		}

		if (userInput == '3')
		{
			showTheMostExpensiveMagazine();
			continue;
		}

		if (userInput == '4')
		{
			showTheMostCheaperMagazine();
			continue;
		}
	} while (userInput != '0');

}






void Menu::addBook()
{
	cout << "\tAdd book or back to main menu:\n"
		<< "\t1. Add.\n"
		<< "\t0. Back.\n";

	char userInput;
	cin >> userInput;

	if (userInput == '0')
		return;
	string firstname, lastname;
	string title;
	int year;
	double price;
	cout << "\nPlease enter book details:\n"
		<< "Author:";
	cin >> firstname >> lastname;
	cout << "Title:";
	cin >> title;
	cout << "Year:";
	cin >> year;
	cout << "Price:";
	cin >> price;

	try
	{
		Book book(firstname, lastname, title, year, price);
		booklist->Add(book);

		cout << "Book added successfully!" << endl;
	}
	catch (const char* err)
	{
		Logger::GetInstance()->LogError(err);
		
		cout << "Book is not added!" << endl << err << endl;
	}
	//book.WriteToConsole();
	//cout << endl;

}

void Menu::showAllBooks()
{
	cout << "All books:" << endl;
	booklist->WriteAllToConsole();
}

void Menu::showTheOldestBook()
{
	booklist->WriteToConsoleTheOldestBook();
}

void Menu::showTheLatestBook()
{
	booklist->WriteToConsoleTheLatestBook();
}

void Menu::showTheMostExpensiveBook()
{
	booklist->WriteToConsoleTheMostExpensiveBook();
}

void Menu::showTheMostCheaperBook()
{
	booklist->WriteToConsoleTheMostCheaperBook();
}

void Menu::showAuthors()
{
	authorlist.WriteToConsoleAllAuthors();
}

void Menu::addMagazine()
{
	cout << "\tAdd magazine or back to main menu:\n"
		<< "\t1. Add.\n"
		<< "\t0. Back.\n";

	char userInput;
	cin >> userInput;

	if (userInput == '0')
		return;

	string editor;
	string title;
	int year;
	double price;

	cout << "\nPlease enter magazine details:\n";
	cout << "Editor:";
	cin >> editor;
	cout << "Title:";
	cin >> title;
	cout << "Year:";
	cin >> year;
	cout << "Price:";
	cin >> price;

	try
	{
		Magazine magazine(editor, title, year, price);
		magazinelist->Add(magazine);

		cout << "Magazine added successfully!" << endl;
	}
	catch (const char* err)
	{
		Logger::GetInstance()->LogError(err);

		cout << "Magazine is not added!" << endl << err << endl;
	}

}

void Menu::showAllMagazines()
{
	cout << "All magazines:" << endl;
	magazinelist->WriteAllToConsole();
}

void Menu::showTheOldestMagazine()
{
	magazinelist->WriteToConsoleTheOldestMagazine();
}

void Menu::showTheLatestMagazine()
{
	magazinelist->WriteToConsoleTheLatestMagazine();
}

void Menu::showTheMostExpensiveMagazine()
{
	magazinelist->WriteToConsoleTheMostExpensiveMagazine();
}

void Menu::showTheMostCheaperMagazine()
{
	magazinelist->WriteToConsoleTheMostCheaperMagazine();
}