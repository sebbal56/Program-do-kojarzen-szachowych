#include "AppLogic.h"

    AppLogic& AppLogic::getInstance(){
        static AppLogic instance;  // Statyczna instancja klasy
        return instance;
    }

    ListOfPeople& AppLogic::getList() {
        return list;
    }

    bool AppLogic::loadDataFromDatabase(const std::string& dbName) {
        if (dbManager.openDatabase(dbName)) {
            return dbManager.loadPeople(list);  // £adowanie danych do listy
        }
        return false;  // Zwraca false, jeœli nie uda³o siê otworzyæ bazy danych
    }

    std::string AppLogic::processData(const std::string& input) {
        // Tu mo¿esz dodaæ bardziej z³o¿on¹ logikê przetwarzania danych
        //return "Przetworzone: " + input;
        return list.getSurnameOfHead();
    }

