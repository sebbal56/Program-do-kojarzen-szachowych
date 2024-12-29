#ifndef APPLOGIC_H
#define APPLOGIC_H

#include <string>
#include "ListOfPeople.h"
#include "PeopleBaseManager.h"

class AppLogic {
public:
    static AppLogic& getInstance();
    ListOfPeople& getList();
    bool loadDataFromDatabase(const std::string& dbName);
    std::string processData(const std::string& input);
private:
    AppLogic() = default;  // Konstruktor prywatny, aby uniemo¿liwiæ tworzenie wielu instancji
    ListOfPeople list;
    PeopleBaseManager dbManager;  

    // Zapobiega kopiowaniu i przypisywaniu
    AppLogic(const AppLogic&) = delete;
    AppLogic& operator=(const AppLogic&) = delete;
};

#endif