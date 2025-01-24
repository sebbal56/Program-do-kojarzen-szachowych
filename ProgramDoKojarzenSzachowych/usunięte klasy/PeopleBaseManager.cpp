#include "PeopleBaseManager.h"
PeopleBaseManager::PeopleBaseManager() : db(nullptr), isOpen(false) {}

// Destruktor
PeopleBaseManager::~PeopleBaseManager() {
    closeDatabase();
}

// Otwieranie bazy danych
bool PeopleBaseManager::openDatabase(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "B³¹d otwarcia bazy danych: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // SprawdŸ i ustaw kodowanie na UTF-8 (tylko dla nowej bazy danych)
    char* errorMessage = nullptr;
    if (sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        std::cerr << "B³¹d ustawiania kodowania UTF-8: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }

    isOpen = true;
    return true;
}

// Zamykanie bazy danych
void PeopleBaseManager::closeDatabase() {
    if (isOpen) {
        sqlite3_close(db);
        isOpen = false;
    }
}

// Wczytywanie osób z bazy
bool PeopleBaseManager::loadPeople(ListOfPeople& list) {
    if (!isOpen) return false;

    sqlite3_stmt* stmt;
    std::string query = "SELECT surname, name, day, month, year FROM people;";

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "B³¹d podczas przygotowania zapytania: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string surname = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int day = sqlite3_column_int(stmt, 2);
        int month = sqlite3_column_int(stmt, 3);
        int year = sqlite3_column_int(stmt, 4); 

        Person person(surname, name, day, month, year);

        list.addPerson(person);
    }

    sqlite3_finalize(stmt);
    return true;
}

// Zapisywanie osób do bazy
//bool PeopleBaseManager::savePeople(const ListOfPeople& list) {
//    if (!isOpen) return false;
//
//    std::string query = "INSERT INTO People (name, surname, date_of_birth) VALUES (?, ?, ?);";
//    sqlite3_stmt* stmt;
//
//    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//        std::cerr << "B³¹d podczas przygotowania zapytania: " << sqlite3_errmsg(db) << std::endl;
//        return false;
//    }
//
//    for (const auto& person : list.getPeople()) {
//        sqlite3_bind_text(stmt, 1, person.name.c_str(), -1, SQLITE_STATIC);
//        sqlite3_bind_text(stmt, 2, person.surname.c_str(), -1, SQLITE_STATIC);
//        sqlite3_bind_text(stmt, 3, person.dateOfBirth.toString().c_str(), -1, SQLITE_STATIC);
//
//        if (sqlite3_step(stmt) != SQLITE_DONE) {
//            std::cerr << "B³¹d podczas zapisywania danych: " << sqlite3_errmsg(db) << std::endl;
//        }
//
//        sqlite3_reset(stmt);
//    }
//
//    sqlite3_finalize(stmt);
//    return true;
//}