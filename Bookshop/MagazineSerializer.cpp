#include "MagazineSerializer.h"
#include <iostream>
#include <fstream>
#define magazines_file_name "C:\\Users\\Ã‡–≥◊Í¿\\source\\repos\\Bookshop4\\Bookshop4\\magazines.txt"

void MagazineSerializer::ReadMagazinesFromFile(Magazine**& magazines, int& count)
{
	ifstream fin(magazines_file_name);

	if (!fin.is_open())
		cout << "File not open.\n";
	else
	{
		magazines = new Magazine * [100];
		count = 0;

		string editor;
		string title;
		int year;
		double price;

		while (!fin.eof())
		{
			fin >> editor >> title >> year >> price;
			magazines[count++] = new Magazine(editor, title, year, price);
		}

		fin.close();

	}

}
void MagazineSerializer::WriteMagazinesToFile(Magazine** magazines, int count)
{
	ofstream fout(magazines_file_name);

	if (!fout.is_open())
		cout << "File not open.\n";
	else
	{
		for (int i = 0; i < count; i++)
		{
			fout << magazines[i]->GetEditor() << " " << magazines[i]->GetTitle() << " " << magazines[i]->GetYear() << " " << magazines[i]->GetPrice();
			if (i != count - 1)
				fout << endl;
		}

		fout.close();
	}
}

void MagazineSerializer::ReadMagazinesFromFile(Magazine*& magazines, int& count)
{
	ifstream fin("magazines.txt");

	if (!fin.is_open())
		cout << "File not open.\n";
	else
	{
		magazines = new Magazine[100];
		count = 0;

		string editor;
		string title;
		int year;
		double price;

		while (!fin.eof())
		{
			fin >> editor >> title >> year >> price;
			magazines[count++] = Magazine(editor, title, year, price);
		}

		fin.close();

	}

}

void MagazineSerializer::WriteMagazinesToFile(Magazine* magazines, int count)
{
	ofstream fout("magazines.txt");

	if (!fout.is_open())
		cout << "File not open.\n";
	else
	{
		for (int i = 0; i < count; i++)
		{
			fout << magazines[i].GetEditor() << " " << magazines[i].GetTitle() << " " << magazines[i].GetYear() << " " << magazines[i].GetPrice();
			if (i != count - 1)
				fout << endl;
		}

		fout.close();
	}
}