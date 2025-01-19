#pragma once

#include <wx/wx.h>
#include <wx/listbox.h>
#include "Tournament.h"
#include "ResultsInputPanel.h"

class Round;

class RoundPanel : public wxPanel
{
public:
    // Constructor
    RoundPanel(wxWindow* parent, Tournament* tournament, int rNumber);
    int r_num;

private:
    // Event handler for making pairings
    void OnMakePairings(wxCommandEvent& event);
    void SwitchToResultsInputPanel();
    void InitializePairingsView();
    void InitializeResultsView();


    // Pointer to the tournament object
    Tournament* tournament;

    // UI elements
    wxBoxSizer* sizer;
    wxButton* makePairingsButton;
    wxButton* inputResultsButton;
    wxChoice* colorChoice;
    wxListBox* pairingsListBox;
    wxString selectedColour;
};

