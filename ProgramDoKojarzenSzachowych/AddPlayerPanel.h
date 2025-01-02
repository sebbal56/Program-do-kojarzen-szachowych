#ifndef ADDPLAYERPANEL_H
#define ADDPLAYERPANEL_H

#include <wx/wx.h>

class AddPlayerPanel : public wxPanel {
public:
    AddPlayerPanel(wxWindow* parent);

private:
    wxTextCtrl* surnameInput;
    wxTextCtrl* nameInput;
    wxTextCtrl* clubInput;
    wxTextCtrl* ratingInput;
    wxTextCtrl* dayInput;
    wxTextCtrl* monthInput;
    wxTextCtrl* yearInput;
    void OnSaveButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // ADDPLAYERPANEL_H
