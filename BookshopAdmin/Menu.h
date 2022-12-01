#pragma once
#include "ABookList.h"
#include "AMagazineList.h"
#include "Authors.h"

class Menu
{
	ABookList* booklist;
	AMagazineList* magazinelist;
	Authors authorlist;
public:
	void Show();
	Menu();
	~Menu();

private:
	void showBaseMenu();

	void showAnalysisBookMenu();
	void analysisbookActivity();

	void showAnalysisMagazineMenu();
	void analysismagazineActivity();


	void showAllBooks();
	void addBook();
	void showTheOldestBook();
	void showTheLatestBook();
	void showTheMostExpensiveBook();
	void showTheMostCheaperBook();
	void showAuthors();

	void showAllMagazines();
	void addMagazine();
	void showTheOldestMagazine();
	void showTheLatestMagazine();
	void showTheMostExpensiveMagazine();
	void showTheMostCheaperMagazine();

};
