#ifndef TOURNAMENT_CREATOR_H
#define TOURNAMENT_CREATOR_H

#include <wx/wx.h>
#include "MainFrame.h"
#include "TournamentWindow.h"
#include "Tournament.h"

class TournamentCreator : public wxPanel {
public:
    TournamentCreator(wxWindow* parent);

private:
    void OnCancel(wxCommandEvent& event);  
    void OnNext(wxCommandEvent& event);  

    wxTextCtrl* nameField;
    wxTextCtrl* dayField;
    wxTextCtrl* monthField;
    wxTextCtrl* yearField;
    wxTextCtrl* placeField;
    wxTextCtrl* arbiterField;
    wxTextCtrl* aboutField;
    wxButton* nextButton;
    wxButton* cancelButton;

    wxDECLARE_EVENT_TABLE();
};

#endif // TOURNAMENT_CREATOR_H
