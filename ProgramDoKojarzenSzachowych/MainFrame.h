#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/log.h>
#include <wx/textfile.h>
#include "TournamentCreator.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnLoadTournament(wxCommandEvent& event);
    void OnSaveTournament(wxCommandEvent& event);


    void OnCreateTournament(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif
