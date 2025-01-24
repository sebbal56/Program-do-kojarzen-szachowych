#include "StartingListPanel.h"


wxBEGIN_EVENT_TABLE(StartingListPanel, wxPanel)
    EVT_BUTTON(wxID_ANY, StartingListPanel::OnAddPlayer)
wxEND_EVENT_TABLE()

    StartingListPanel::StartingListPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

        listBox = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(200, 200));

        wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
        listBox->SetFont(font);

        tournament ->sortByStarting(tournament->listOfPlayers);
        for (auto& player : tournament->listOfPlayers) {
            listBox -> Append(player.playerInfo());
        }

        newPlayerButton = new wxButton(this, wxID_ANY, "Dodaj nowego zawodnika", wxDefaultPosition, wxSize(160, 40));

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);
        sizer->Add(newPlayerButton, 0, wxALL | wxALIGN_CENTER, 10);

        SetSizer(sizer);
    }

void StartingListPanel::OnAddPlayer(wxCommandEvent& event) {
    wxWindow* parent = GetParent();
    if (parent) {
        this->Hide();
        AddPlayerPanel* addPlayerPanel = new AddPlayerPanel(parent, tournament);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(addPlayerPanel, 1, wxEXPAND);
        parent->SetSizer(sizer);
        parent->Layout();
    }
}
