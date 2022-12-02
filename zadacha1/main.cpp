#include <iostream>
#include "keeper.h"
#include "myscanf.h"

/*
Определить класс с именем SIGN, содержащий следующие поля:
● фамилия, имя;
● знак зодиака;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа SIGN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по датам дней рождения;
● вывод на экран информации о человеке, чья фамилия введена с
клавиатуры;
● если такого нет, выдать на дисплей соответствующее сообщение.
*/

void print_menu_commands()
{
	printf("menu");
	printf("\t-1_exit\n");
	printf("\t0__print to console\n");

	printf("\n\t11__add record\n");
	printf("\t12__edit record\n");
	printf("\t13__delete record\n");
	printf("\search\n");

	printf("\t__\n");
}

int main()
{
	Keeper ppl;

	int t = 0;
	int id = -1;
	while (true)
	{
		print_menu_commands();
		printf("enter menu command:\n");
		take(&t);
		switch (t)
		{
		case -1:
			return 0;

		case 0:
			ppl.printAll();
			break;

		case 14:
			ppl.search();
			break;

		case 11:
			ppl.Add();
			break;

		case 12:
			if (ppl.getNum() == 0)
				printf("there are 0 records\n");
			else
			{
				while (id < 0 || id > ppl.getNum())
					take(&id);
				try {
					ppl.Edit(id);
				}
				catch (char* m)
				{
					printf("%s\n", m);
				}
			}
			break;

		case 13:
			if (ppl.getNum() == 0)
				printf("there are 0 records\n");
			else
			{
				while (id < 0 || id > ppl.getNum())
					take(&id);
				try {
					ppl.Delete(id);
				}
				catch (char* m)
				{
					printf("%s\n", m);
				}
			}
			break;

		default:
			printf("no such command\n");
			break;
		}


	}

	return 0;
}