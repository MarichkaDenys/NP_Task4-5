#include "Menu.h"
#include "Book.h"
#include "Factory.h"
#include "Authors.h"
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


void Menu::ReInitBookList()
{
	ListFactoryProvider factoryProvider;
	AListFactory* listFactory = factoryProvider.GetListFactory();

	booklist = listFactory->GetBookList();

}
void Menu::ReInitMagazineList()
{
	ListFactoryProvider factoryProvider;
	AListFactory* listFactory = factoryProvider.GetListFactory();
	
	magazinelist = listFactory->GetMagazineList();
}

Menu::~Menu()
{
	delete booklist;
	delete magazinelist;
}

void Menu::Show()
{
	cout << "Bookshop.User.\n";

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
			showAllMagazines();
			continue;
		}

		if (userInput == '5')
		{
			analysismagazineActivity();
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
		<< "4. Show all magazines.\n"
		<< "5. Analysis of the magazine's activity.\n"
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

void Menu::showAllBooks()
{
	cout << "All books:" << endl;
	ReInitBookList();
	booklist->WriteAllToConsole();
}

void Menu::showTheOldestBook()
{
	ReInitBookList();
	booklist->WriteToConsoleTheOldestBook();
}

void Menu::showTheLatestBook()
{
	ReInitBookList();
	booklist->WriteToConsoleTheLatestBook();
}

void Menu::showTheMostExpensiveBook()
{
	ReInitBookList();
	booklist->WriteToConsoleTheMostExpensiveBook();
}

void Menu::showTheMostCheaperBook()
{
	ReInitBookList();
	booklist->WriteToConsoleTheMostCheaperBook();
}

void Menu::showAuthors()
{
	ReInitBookList();
	authorlist.WriteToConsoleAllAuthors();
}


void Menu::showAllMagazines()
{
	cout << "All magazines:" << endl;
	ReInitMagazineList();
	magazinelist->WriteAllToConsole();
}

void Menu::showTheOldestMagazine()
{
	ReInitMagazineList();
	magazinelist->WriteToConsoleTheOldestMagazine();
}

void Menu::showTheLatestMagazine()
{
	ReInitMagazineList();
	magazinelist->WriteToConsoleTheLatestMagazine();
}

void Menu::showTheMostExpensiveMagazine()
{
	ReInitMagazineList();
	magazinelist->WriteToConsoleTheMostExpensiveMagazine();
}

void Menu::showTheMostCheaperMagazine()
{
	ReInitMagazineList();
	magazinelist->WriteToConsoleTheMostCheaperMagazine();
}