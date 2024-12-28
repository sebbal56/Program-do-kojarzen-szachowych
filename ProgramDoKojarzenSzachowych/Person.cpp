#include "Person.h"


void Person::setPerson()
{
    std::cout << "Podaj imie: ";
    std::cin >> name;
    std::cout << "Podaj nazwisko: ";
    std::cin >> surname;
    dateOfBirth.setDate();
}


void Person::writePerson()
{
    std::cout << name << std::endl;
    std::cout << surname << std::endl;
    dateOfBirth.writeDate();
}

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

Person::Person(const Person& pattern){
    name = pattern.name;
    surname = pattern.surname;
    dateOfBirth = pattern.dateOfBirth;
}
