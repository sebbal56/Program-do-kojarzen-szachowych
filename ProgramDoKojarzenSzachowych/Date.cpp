#include "Date.h"



void Date::setDate()
{
    std::cout << "Podaj dzien: ";
    std::cin >> day;
    std::cout << "Podaj miesiac: ";
    std::cin >> month;
    std::cout << "Podaj rok: ";
    std::cin >> year;
}


void Date::writeDate()
{
    std::cout << day << "-" << month << "-" << year << std::endl;
}

int Date::compare(const Date& pattern) const
{
	// jezeli this jest starsze niz pattern return - 1
	if (this->year > pattern.year) return -1;
	if (this->year < pattern.year) return 1;
	if (this->month > pattern.month) return -1;
	if (this->month < pattern.month) return 1;
	if (this->day > pattern.day) return -1;
	if (this->day < pattern.day) return 1;
	return 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}