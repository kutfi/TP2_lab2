#pragma once
#include <iostream>
#include <string>


using namespace std;

class SIGN
{
	string name;
	string family;
	string zodiacSign;

	int data[3];

public:

	void setName(string _name);
	void setFamily(string _family);
	void setSign(string _sign);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	string getName();
	string getFamily();
	string getSign();
	int getDay();
	int getMonth();
	int getYear();

	friend std::ostream& operator<<(std::ostream& out, SIGN& obj);
	friend std::istream& operator>>(std::istream& in, SIGN& obj);

	string calcSign();
	void Edit();

	bool operator>(SIGN& obj)
	{
		int d1 = this->getDay();
		int m1 = this->getMonth();
		int y1 = this->getYear();

		int d2 = obj.getDay();
		int m2 = obj.getMonth();
		int y2 = obj.getYear();

		// is THIS > obj?


		if (y1 > y2)
			return true;
		if (y1 < y2)
			return false;

		if (m1 > m2)
			return true;
		if (m1 < m2)
			return false;
		if (d1 > d2)
			return true;

		if (d1 < d2)
			return false;
	
		return false;
	
	}
};