#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include "AppLogic.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnRunLogic(wxCommandEvent& event); // Obs�uga przycisku
    wxTextCtrl* inputField; // Pole tekstowe
    wxStaticText* outputLabel; // Etykieta do wy�wietlania wynik�w
    AppLogic& logic = AppLogic::getInstance();
};

#endif
