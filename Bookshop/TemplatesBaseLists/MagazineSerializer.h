#pragma once
#include "Magazine.h"


class MagazineSerializer
{
public:
	static void ReadMagazinesFromFile(Magazine**& magazines, int& count);
	static void WriteMagazinesToFile(Magazine** magazines, int count);

	static void ReadMagazinesFromFile(Magazine*& magazines, int& count);
	static void WriteMagazinesToFile(Magazine* magazines, int count);
};