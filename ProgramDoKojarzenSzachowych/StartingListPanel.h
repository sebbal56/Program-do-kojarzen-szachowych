#ifndef STARTING_LIST_PANEL_H
#define STARTING_LIST_PANEL_H

#include <wx/wx.h>
#include <wx/listbox.h>
#include "Tournament.h"
#include "AddPlayerPanel.h"

class StartingListPanel : public wxPanel {
public:
    StartingListPanel(wxWindow* parent, Tournament t);

private:

    wxListBox* listBox;
    wxButton* newPlayerButton;

    void OnAddPlayer(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();


};

#endif // STARTING_LIST_PANEL_H
