#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;

class Date {
public:
	int date, month, year;
	Date() {
		date = 0;
		month = 0;
		year = 0;
	};

	Date(int date, int month, int year) {
		this->date = date;
		this->month = month;
		this->year = year;
	};
	~Date() {};
};

istream& operator >>(istream& in, Date& d) {
	
}

ostream& operator <<(ostream& out, Date& d) {
	out << d.date << '/' << d.month << '/' << d.year;
	return out;
}

bool operator < (Date& d1, Date& d2) {
	if (d1.year < d2.year)
		return true;
	else if (d1.year > d2.year)
		return false;
	else
		if (d1.month < d2.month)
			return true;
		else if (d1.month > d2.month)
			return false;
		else
			if (d1.date < d2.date)
				return true;
			else
				return false;
}

int main() {
	Date d1(5, 7, 2021);
	Date d2(4, 2, 2021);
	cout << d1 << endl;
	cout << d2 << endl;
	if (d1 < d2)
		cout << 1;
	else cout << 0;

	return 0;

}