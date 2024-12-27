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
