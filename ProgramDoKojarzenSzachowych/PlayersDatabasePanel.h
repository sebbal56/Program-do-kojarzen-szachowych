#ifndef PLAYERS_DATABASE_PANEL_H
#define PLAYERS_DATABASE_PANEL_H

#include <wx/wx.h>
#include "Tournament.h"
#include "AddPlayerPanel.h"
#include <wx/listctrl.h>
#include <sqlite3.h>

class PlayersDatabasePanel : public wxPanel {
public:
    PlayersDatabasePanel(wxWindow* parent, Tournament* t);
private:
    wxListCtrl* listCtrl;
    wxTextCtrl* searchCtrl;
    Tournament* tournament;

    static int callback(void* data, int argc, char** argv, char** azColName);
    static int selectData(const char* filename, wxListCtrl* listCtrl);

    long selectedIndex = -1;
    void OnItemSelected(wxListEvent& event);
    void OnAddSelectedPlayer(wxCommandEvent& event);
    void OnDeleteSelectedPlayer(wxCommandEvent& event);

    void refreshList(const std::string& orderBy);
    void OnSortById(wxCommandEvent& event);
    void OnSortBySurname(wxCommandEvent& event);
    void OnSortByRating(wxCommandEvent& event);

    void OnSearch(wxCommandEvent& event);
    void searchBySurname(const std::string& prefix);
    wxDECLARE_EVENT_TABLE();


};

#endif // PLAYERS_DATABASE_PANEL_H
