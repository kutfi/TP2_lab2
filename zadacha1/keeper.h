#pragma once
#include "stdio.h"
#include "sign.h"


class Keeper
{
	int num;
	SIGN** list;

public:
	Keeper();
	~Keeper();

	int getNum();

	void Add();
	void Edit(int);
	void Delete(int);
	void printAll();

	void Sort()
	{
		for (int i = 0; i < getNum() - 1;)
		{
			if (*list[i] > *list[i + 1])
			{
				SIGN* tempr = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tempr;
				i = 0;
			}
			else i++;
		}
	}

	void search()
	{
		string input;
		cout << "enter search family: ";
		cin >> input;

		for (int i = 0; i < getNum(); i++)
		{
			if (list[i]->getFamily() == input)
				cout << *list[i];
		}

	}
};