#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include "AppLogic.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnRunLogic(wxCommandEvent& event); // Obs³uga przycisku
    wxTextCtrl* inputField; // Pole tekstowe
    wxStaticText* outputLabel; // Etykieta do wyœwietlania wyników
    AppLogic& logic = AppLogic::getInstance();
};

#endif
