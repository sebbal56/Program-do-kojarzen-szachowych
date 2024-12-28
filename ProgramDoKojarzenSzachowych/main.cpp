#include <iostream>
#include "Person.h"
#include "ListOfPeople.h"

int main()
{
    /*Person osoba1;
    osoba1.setPerson();
    osoba1.writePerson();*/

    ListOfPeople lista;
    Person zatrudniony;
    for (int i = 0; i < 5; i++) {
        zatrudniony.setPerson();
        lista.addPerson(zatrudniony);
        lista.writeAllPeople();
        std::cout << std::endl;
    }
}
