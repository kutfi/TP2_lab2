/*
— использованием файловых и строковых потоков написать программу,
котора€ считывает текст из файла, находит самое длинное слово и
определ€ет, сколько раз оно встретилось в тексте*/

#include <iostream>
#include <fstream>
using namespace std;

bool isDevider(string s)
{
	return(s == " " || s == "\n" || s == "\t" || s == "," || s == "." || s == "!" || s == "?" || s == ";" || s == "\'" || s == ":");
}


int main()
{
	
	ifstream fin;
	fin.open("text.txt");
	if (!fin.is_open())
	{
		cout << "file not found" << endl;
		return 0;
	}

	char c;
	char prev = 'a';
	string word;
	string longest;
	string s;
	int timesMet = 0;
	while (!fin.eof())
	{
		fin.get(c);
		s = c;
		if (isDevider(s))
		{
			if (word == longest)
			{
				timesMet++;
			}
			else
				if (word.length() > longest.length())
				{
					longest = word;
					timesMet = 1;
					
				}
			while (!fin.eof() && isDevider(s))
			{
				fin.get(c);
				s = c;				
			}
			word = "";
		}

			word += s;

	}
	cout << longest << " "<< timesMet<<endl;
	fin.close();
	return 0;
}