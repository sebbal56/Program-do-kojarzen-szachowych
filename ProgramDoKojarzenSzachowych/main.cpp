#include <iostream>
#include "Person.h"
#include "ListOfPeople.h"
#include "PeopleBaseManager.h"
#include <Windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ListOfPeople list;
    PeopleBaseManager dbManager;
    if (dbManager.openDatabase("PeopleBase.db")) {
        dbManager.loadPeople(list);
    }
    list.writeAllPeople();
}
