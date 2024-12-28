#pragma once
#include "sqlite3.h"
#include "ListOfPeople.h"

class PeopleBaseManager {
private:
    sqlite3* db;
    bool isOpen;

public:
    PeopleBaseManager();
    ~PeopleBaseManager();

    bool openDatabase(const std::string& filename);
    void closeDatabase();

    bool loadPeople(ListOfPeople& list);
    bool savePeople(const ListOfPeople& list);
};