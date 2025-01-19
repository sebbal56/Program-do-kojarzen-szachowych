#ifndef RESULTS_INPUT_PANEL_H
#define RESULTS_INPUT_PANEL_H

#include <wx/wx.h>
#include "Tournament.h"
#include "RoundPanel.h"
#include "TournamentWindow.h"

class ResultsInputPanel : public wxPanel {
public:
    ResultsInputPanel(wxWindow* parent, Tournament* tournament, int rNumber);

private:
    Tournament* tournament;
    int r_num;
    wxBoxSizer* sizer;
    std::vector<wxChoice*> resultsChoices; // Store dropdown menus for results

    void OnSaveResults(wxCommandEvent& event);
};

#endif
