#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>

class EditPlayerDialog : public wxDialog {
public:
    EditPlayerDialog(wxWindow* parent, long playerId);
    long GetPlayerId() const { return playerId; }

private:
    long playerId;
    wxTextCtrl* surnameCtrl;
    wxTextCtrl* nameCtrl;
    wxTextCtrl* clubCtrl;
    wxTextCtrl* ratingCtrl;
    wxTextCtrl* dayCtrl;
    wxTextCtrl* monthCtrl;
    wxTextCtrl* yearCtrl;

    void OnSave(wxCommandEvent& event);
};
