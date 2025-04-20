#include "EditPlayerDialog.h"
#include <sqlite3.h>

EditPlayerDialog::EditPlayerDialog(wxWindow* parent, long playerId)
    : wxDialog(parent, wxID_ANY, "Edytuj zawodnika", wxDefaultPosition, wxSize(300, 400)), playerId(playerId)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxString surname, name, club, rating, day, month, year;

    sqlite3* DB;
    if (sqlite3_open("players.db", &DB) == SQLITE_OK) {
        wxString sql = wxString::Format("SELECT SURNAME, NAME, CLUB, RATING, D, M, Y FROM PLAYERS WHERE PLAYER_ID = %ld", playerId);
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(DB, sql.mb_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                surname = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                name = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
                club = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
                rating = wxString::Format("%d", sqlite3_column_int(stmt, 3));
                day = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
                month = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
                year = wxString(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
            }
        }
        sqlite3_finalize(stmt);
        sqlite3_close(DB);
    }

    surnameCtrl = new wxTextCtrl(this, wxID_ANY, surname);
    nameCtrl = new wxTextCtrl(this, wxID_ANY, name);
    clubCtrl = new wxTextCtrl(this, wxID_ANY, club);
    ratingCtrl = new wxTextCtrl(this, wxID_ANY, rating);
    dayCtrl = new wxTextCtrl(this, wxID_ANY, day);
    monthCtrl = new wxTextCtrl(this, wxID_ANY, month);
    yearCtrl = new wxTextCtrl(this, wxID_ANY, year);

    sizer->Add(new wxStaticText(this, wxID_ANY, "Nazwisko"), 0, wxALL, 5);
    sizer->Add(surnameCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Imiê"), 0, wxALL, 5);
    sizer->Add(nameCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Klub"), 0, wxALL, 5);
    sizer->Add(clubCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Ranking"), 0, wxALL, 5);
    sizer->Add(ratingCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Dzieñ"), 0, wxALL, 5);
    sizer->Add(dayCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Miesi¹c"), 0, wxALL, 5);
    sizer->Add(monthCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(new wxStaticText(this, wxID_ANY, "Rok"), 0, wxALL, 5);
    sizer->Add(yearCtrl, 0, wxEXPAND | wxALL, 5);

    wxButton* saveButton = new wxButton(this, wxID_ANY, "Zapisz");
    saveButton->Bind(wxEVT_BUTTON, &EditPlayerDialog::OnSave, this);
    sizer->Add(saveButton, 0, wxALIGN_CENTER | wxALL, 10);

    SetSizerAndFit(sizer);
}

void EditPlayerDialog::OnSave(wxCommandEvent& event) {
    sqlite3* DB;
    if (sqlite3_open("players.db", &DB) != SQLITE_OK) {
        wxMessageBox("Nie uda³o siê otworzyæ bazy danych.", "B³¹d", wxICON_ERROR);
        return;
    }

    wxString sql = wxString::Format(
        "UPDATE PLAYERS SET "
        "SURNAME='%s', NAME='%s', CLUB='%s', RATING=%s, D='%s', M='%s', Y='%s' "
        "WHERE PLAYER_ID=%ld;",
        surnameCtrl->GetValue(), nameCtrl->GetValue(), clubCtrl->GetValue(), ratingCtrl->GetValue(),
        dayCtrl->GetValue(), monthCtrl->GetValue(), yearCtrl->GetValue(), playerId
    );

    char* errorMsg = nullptr;
    if (sqlite3_exec(DB, sql.mb_str(), nullptr, nullptr, &errorMsg) != SQLITE_OK) {
        wxString msg = "B³¹d SQL: ";
        msg += errorMsg;
        wxMessageBox(msg, "B³¹d", wxICON_ERROR);
        sqlite3_free(errorMsg);
    }
    else {
        EndModal(wxID_OK);
    }

    sqlite3_close(DB);
}
