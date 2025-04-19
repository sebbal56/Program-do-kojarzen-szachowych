#ifndef ADDPLAYERPANEL_H
#define ADDPLAYERPANEL_H

#include <wx/wx.h>
#include "Tournament.h"
#include <sqlite3.h>

class AddPlayerPanel : public wxPanel {
public:
    AddPlayerPanel(wxWindow* parent, Tournament* t);

private:
    wxTextCtrl* surnameInput;
    wxTextCtrl* nameInput;
    wxTextCtrl* clubInput;
    wxTextCtrl* ratingInput;
    wxTextCtrl* dayInput;
    wxTextCtrl* monthInput;
    wxTextCtrl* yearInput;

    Tournament* tournament;

    wxButton* saveButton;
    void OnSaveButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // ADDPLAYERPANEL_H
