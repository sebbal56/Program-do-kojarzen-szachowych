#include "ResultsPanel.h"

//
//wxBEGIN_EVENT_TABLE(StartingListPanel, wxPanel)
////EVT_BUTTON(wxID_ANY, StartingListPanel::OnAddPlayer)
//wxEND_EVENT_TABLE()

ResultsPanel::ResultsPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

    // Dodaj komponenty listy startowej
    listBox = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(200, 200));
    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
    listBox->SetFont(font);

    tournament ->sortByPoints(tournament->listOfPlayers);
    int i = 1;
    for (auto& player : tournament->listOfPlayers) {
        listBox->Append(player.playerToResults(i));
        i++;
    }
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);
   // sizer->Add(newPlayerButton, 0, wxALL | wxALIGN_CENTER, 10);

    SetSizer(sizer);
}

