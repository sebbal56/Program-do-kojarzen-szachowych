#include "StartingListPanel.h"


wxBEGIN_EVENT_TABLE(StartingListPanel, wxPanel)
    EVT_BUTTON(wxID_ANY, StartingListPanel::OnAddPlayer)
    EVT_BUTTON(wxID_ANY, StartingListPanel::OnOpenDatabase)
wxEND_EVENT_TABLE()

    StartingListPanel::StartingListPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

        listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(400, 200), wxLC_REPORT);

        listCtrl->InsertColumn(0, "Nr", wxLIST_FORMAT_LEFT, 40);
        listCtrl->InsertColumn(1, "Rank", wxLIST_FORMAT_LEFT, 60);
        listCtrl->InsertColumn(2, "Nazwisko", wxLIST_FORMAT_LEFT, 140);
        listCtrl->InsertColumn(3, "Imie", wxLIST_FORMAT_LEFT, 120);
        listCtrl->InsertColumn(4, "Klub", wxLIST_FORMAT_LEFT, 120);
        listCtrl->InsertColumn(5, "Rok", wxLIST_FORMAT_LEFT, 60);

        wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
        listCtrl->SetFont(font);

        tournament ->sortByStarting(tournament->listOfPlayers);
        long index = 0;
        for (auto& player : tournament->listOfPlayers) {
            listCtrl->InsertItem(index, std::to_string(player.startingPosition));
            listCtrl->SetItem(index, 1, std::to_string(player.getRating()));
            listCtrl->SetItem(index, 2, player.getSurname());
            listCtrl->SetItem(index, 3, player.getName());
            listCtrl->SetItem(index, 4, player.getClub());
            listCtrl->SetItem(index, 5, std::to_string(player.getYear()));
            ++index;
        }

        newPlayerButton = new wxButton(this, wxID_ANY, "Dodaj nowego zawodnika", wxDefaultPosition, wxSize(160, 40));
        openDatabaseButton = new wxButton(this, wxID_ANY, "Otworz baze zawodnikow", wxDefaultPosition, wxSize(160, 40));

        newPlayerButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnAddPlayer(event);});
        openDatabaseButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {OnOpenDatabase(event);});

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        //sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);
        sizer->Add(listCtrl, 1, wxEXPAND | wxALL, 10);
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        buttonSizer->Add(newPlayerButton, 0, wxALL, 10);
        buttonSizer->Add(openDatabaseButton, 0, wxALL, 10);

        sizer->Add(buttonSizer, 0, wxALIGN_CENTER);

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

void StartingListPanel::OnOpenDatabase(wxCommandEvent& event) {
    wxWindow* parent = GetParent();
    if (parent) {
        this->Hide();
        PlayersDatabasePanel* playersDatabasePanel = new PlayersDatabasePanel(parent, tournament);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(playersDatabasePanel, 1, wxEXPAND);
        parent->SetSizer(sizer);
        parent->Layout();
    }
}
