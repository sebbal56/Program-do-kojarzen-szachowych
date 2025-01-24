#include "ResultsPanel.h"

ResultsPanel::ResultsPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

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

    SetSizer(sizer);
}

