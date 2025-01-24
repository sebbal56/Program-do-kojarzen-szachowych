#include "Person.h"



int Person::compare(const Person& pattern) const
{
    if (this->surname > pattern.surname) return 1;
    if (this->surname < pattern.surname) return -1;

    if (this->name > pattern.name) return 1;
    if (this->name < pattern.name) return -1;

    if (this->dateOfBirth.compare(pattern.dateOfBirth) > 0) return -1;
    if (this->dateOfBirth.compare(pattern.dateOfBirth) < 0) return -1;

    return 0;
}

std::string Person::getSurname() {
    return surname;
}

Person::Person(const Person& pattern){
    name = pattern.name;
    surname = pattern.surname;
    dateOfBirth = pattern.dateOfBirth;
}

Person::Person(std::string sN, std::string n, int d, int m, int y) {
    surname = sN;
    name = n;
    dateOfBirth = Date(d, m, y);
}
