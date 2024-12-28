#include "DateOfBirth.h"



void DateOfBirth::setDate()
{
    std::cout << "Podaj dzien: ";
    std::cin >> day;
    std::cout << "Podaj miesiac: ";
    std::cin >> month;
    std::cout << "Podaj rok: ";
    std::cin >> year;
}


void DateOfBirth::writeDate()
{
    std::cout << day << "-" << month << "-" << year << std::endl;
}

int DateOfBirth::compare(const DateOfBirth& pattern) const
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

DateOfBirth::DateOfBirth(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}