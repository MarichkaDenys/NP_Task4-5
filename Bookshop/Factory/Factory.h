#pragma once
#include "ABookList.h"
#include "AMagazineList.h"
#include "BookList.h"
#include "BookTList.h"
#include "MagazineList.h"
#include "MagazineTList.h"

class AListFactory
{
public:
	virtual ABookList* GetBookList() = 0;
	virtual AMagazineList* GetMagazineList() = 0;
};

class InheritanceListFactory : public AListFactory
{
public:
	ABookList* GetBookList()
	{
		return new InheritanceLists::BookList;
	}

	AMagazineList* GetMagazineList()
	{
		return new InheritanceLists::MagazineList;
	}

};

class TemplatedListFactory : public AListFactory
{
public:
	ABookList* GetBookList()
	{
		return new TemplatedLists::BookList;
	}

	AMagazineList* GetMagazineList()
	{
		return new TemplatedLists::MagazineList;
	}

};


class ListFactoryProvider
{
public:
	AListFactory* GetListFactory()
	{
		return new InheritanceListFactory();
	}
};