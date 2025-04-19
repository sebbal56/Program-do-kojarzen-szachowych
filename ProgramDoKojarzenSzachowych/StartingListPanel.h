#ifndef STARTING_LIST_PANEL_H
#define STARTING_LIST_PANEL_H

#include <wx/wx.h>
#include "Tournament.h"
#include "AddPlayerPanel.h"
#include <wx/listctrl.h>

class StartingListPanel : public wxPanel {
public:
    StartingListPanel(wxWindow* parent, Tournament* t);

private:
    wxListCtrl* listCtrl;
    wxButton* newPlayerButton;
    Tournament* tournament;

    void OnAddPlayer(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();


};

#endif // STARTING_LIST_PANEL_H
