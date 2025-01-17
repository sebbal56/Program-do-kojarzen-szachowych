#ifndef RESULTS_PANEL_H
#define RESULTS_PANEL_H

#include <wx/wx.h>
#include <wx/listbox.h>
#include "Tournament.h"
#include "AddPlayerPanel.h"

class ResultsPanel : public wxPanel {
public:
    ResultsPanel(wxWindow* parent, Tournament* t);

private:

    wxListBox* listBox;
    //wxButton* newPlayerButton;
    Tournament* tournament;

    //void OnAddPlayer(wxCommandEvent& event);

   // wxDECLARE_EVENT_TABLE();


};

#endif // RESULTS_PANEL_H
