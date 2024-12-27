#include "DateOfBith.h"



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
