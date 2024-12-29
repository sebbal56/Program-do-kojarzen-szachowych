#include <wx/wx.h>
#include "MainFrame.h"


// Klasa aplikacji wxWidgets
class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        AppLogic& appLogic = AppLogic::getInstance();  // Uzyskanie instancji AppLogic
        appLogic.loadDataFromDatabase("PeopleBase.db");

        MainFrame* frame = new MainFrame("Moja aplikacja GUI z wxWidgets");
        frame->Show(true);
        return true;
    }
};

// Makro uruchamiaj¹ce aplikacjê wxWidgets
wxIMPLEMENT_APP(MyApp);
