#pragma once

#include <wx/wx.h>
#include <wx/listbox.h>
#include "Tournament.h"
#include "ResultsInputPanel.h"

class Round;

class RoundPanel : public wxPanel
{
public:
    RoundPanel(wxWindow* parent, Tournament* tournament, int rNumber);
    int r_num;

private:
    void OnMakePairings(wxCommandEvent& event);
    void SwitchToResultsInputPanel();
    void InitializePairingsView();
    void InitializeResultsView();

    Tournament* tournament;

    wxBoxSizer* sizer;
    wxButton* makePairingsButton;
    wxButton* inputResultsButton;
    wxChoice* colorChoice;
    wxListBox* pairingsListBox;
    wxString selectedColour;
};

