#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include "AppLogic.h"
#include "TournamentCreator.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnRunLogic(wxCommandEvent& event); // Obs³uga przycisku
    AppLogic& logic = AppLogic::getInstance();

    void OnCreateTournament(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif
