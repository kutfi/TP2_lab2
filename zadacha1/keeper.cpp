#define _CRT_SECURE_NO_WARNINGS
#include"Keeper.h"
#include "myscanf.h"

Keeper::Keeper() {
	printf("\n\tKeeper()\n");
	num = 0;
	list = nullptr;
	
}

Keeper::~Keeper() {
	printf("\n\t~Keeper()\n");
	for (int i = 0; i < num; i++)
		delete list[i];
}


void Keeper::Add() {

	SIGN* add = new SIGN;
	cin >> *add;

	if (add == nullptr)
		throw "exeption: memory allocation error";
	num += 1;

	SIGN** tmp = new SIGN * [num];
	if (tmp == nullptr)
		throw "exeption: memory allocation error";

	for (int i = 0; i < num - 1; i++)
	{
		tmp[i] = list[i];
	}

	list = tmp;
	list[num - 1] = add;

	printf("\n\tadded\n");
}

int Keeper::getNum() {
	return num;
}

void Keeper::Edit(int i) {
	if (i < 0 || i >= num)
		printf("error: id out of range\n");
	else
	{
		try {
			cin >> *list[i];
		}
		catch (...)
		{
			printf("error\n");
		}
	}
}

void Keeper::Delete(int id) {

	delete list[id];

	for (int i = id; i < num - 1; i++)
	{
		list[i] = list[i + 1];
	}
	num--;
	printf("\n\trecord was deleted\n\n");
}




void Keeper::printAll() {
	Sort();
	for (int i = 0; i < num; i++)
	{
		printf("\trecord -- %d\n", i);
		cout << *list[i];
		printf("\n");
	}
}

