#include <iostream>
#include "sign.h"
#include "myscanf.h"
using namespace std;

string SIGN::calcSign() {
	string s = "invalid";

	int m = getMonth();
	int d = getDay();
	int dm = m * 100 + d;

	if (dm >= 321 && dm <= 420)

		s = "aries";
	if (dm >= 421 && dm <= 520)
		s = "taurus";

	if (dm >= 521 && dm <= 620)
		s = "gemini";

	if (dm >= 621 && dm <= 722)
		s = "cancer";

	if (dm >= 723 && dm <= 822)
		s = "leo";

	if (dm >= 823 && dm <= 922)
		s = "virgo";

	if (dm >= 923 && dm <= 1022)
		s = "libra";

	if (dm >= 1023 && dm <= 1122)
		s = "scorpius";

	if (dm >= 1123 && dm <= 1221)
		s = "sagittarius";

	if (dm >= 120 && dm <= 219)
		s = "aquarius";

	if (dm >= 220 && dm <= 320)
		s = "pisces";

	int md = m * 10000 + d;

	if (s == "invalid")
		if (dm >= 1222 || md <= 10019)
			s = "capricornus";
	return s;
}
void SIGN::setName(string _name) {
	name = _name;
}
void SIGN::setFamily(string _family) {
	family = _family;
}
void SIGN::setSign(string _sign) {
	zodiacSign = _sign;
}
void SIGN::setDay(int d){
	data[0] = d;
}
void SIGN::setMonth(int m) {
	data[1] = m;
}
void SIGN::setYear(int y) {
	data[2] = y;
}

string SIGN::getName() {
	return name;
}
string SIGN::getFamily() {
	return family;
}
string SIGN::getSign() { 
	return zodiacSign;
}
int SIGN::getDay() {
	return data[0];
}
int SIGN::getMonth() {
	return data[1];
}
int SIGN::getYear() {
	return data[2];
}

std::ostream& operator<<(std::ostream& out, SIGN& obj) {
	return out << obj.getFamily() << " " << obj.getName() << " " 
		<< obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear() 
		<<  " " << obj.getSign() << endl;

}

std::istream& operator>>(std::istream& in, SIGN& obj) {
	string s;
	cout << "name: ";
	in >> s;
	obj.setName(s);
	cout << "family: ";
	in >> s;
	obj.setFamily(s);
	s = "invalid";
	while (s == "invalid")
	{
		int number = -1;
		while (number <= 0 || number > 31)
		{
			cout << "date of birth\nday: ";
			take(&number);
		}
		obj.setDay(number);

		number = -1;
		while (number <= 0 || number > 12)
		{
			cout << "date of birth\nmonth: ";
			take(&number);
		}
		obj.setMonth(number);

		number = -1;
		while (number <= 0 )
		{
			cout << "date of birth\nyear: ";
			take(&number);
		}
		obj.setYear(number);


		s = obj.calcSign();
		if (s == "invalid")
			cout << "such date of birth is invalid, try again" << endl;
		else
			obj.setSign(s);
	}
	return in;
}


void SIGN::Edit()
{
	cout << *this;
	cin >> *this;

}
