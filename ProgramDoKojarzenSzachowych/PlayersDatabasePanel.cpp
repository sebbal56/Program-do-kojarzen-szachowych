#include "PlayersDatabasePanel.h"


wxBEGIN_EVENT_TABLE(PlayersDatabasePanel, wxPanel)
EVT_LIST_ITEM_SELECTED(wxID_ANY, PlayersDatabasePanel::OnItemSelected)
EVT_BUTTON(1003, PlayersDatabasePanel::OnAddSelectedPlayer)
wxEND_EVENT_TABLE()

PlayersDatabasePanel::PlayersDatabasePanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

    listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(600, 400), wxLC_REPORT);

    listCtrl->InsertColumn(0, "ID", wxLIST_FORMAT_LEFT, 33);
    listCtrl->InsertColumn(1, "Nazwisko", wxLIST_FORMAT_LEFT, 110);
    listCtrl->InsertColumn(2, "Imie", wxLIST_FORMAT_LEFT, 110);
    listCtrl->InsertColumn(3, "Klub", wxLIST_FORMAT_LEFT, 120);
    listCtrl->InsertColumn(4, "rank", wxLIST_FORMAT_LEFT, 60);
    listCtrl->InsertColumn(5, "D", wxLIST_FORMAT_LEFT, 30);
    listCtrl->InsertColumn(6, "M", wxLIST_FORMAT_LEFT, 30);
    listCtrl->InsertColumn(7, "R", wxLIST_FORMAT_LEFT, 50);

    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
    listCtrl->SetFont(font);

    selectData("players.db", listCtrl);

    wxButton* addToTournamentButton = new wxButton(this, 1003, "Dodaj do turnieju");

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listCtrl, 1, wxEXPAND | wxALL, 10);
    sizer->Add(addToTournamentButton, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    SetSizer(sizer);

    SetSizer(sizer);
}
int PlayersDatabasePanel::callback(void* data, int argc, char** argv, char** azColName)
{
    wxListCtrl* listCtrl = static_cast<wxListCtrl*>(data);

    long index = listCtrl->GetItemCount();
    listCtrl->InsertItem(index, argv[0] ? argv[0] : ""); // ID
    listCtrl->SetItem(index, 1, argv[1] ? argv[1] : ""); // Nazwisko
    listCtrl->SetItem(index, 2, argv[2] ? argv[2] : ""); // Imie
    listCtrl->SetItem(index, 3, argv[3] ? argv[3] : ""); // Klub
    listCtrl->SetItem(index, 4, argv[4] ? argv[4] : ""); // rank
    listCtrl->SetItem(index, 5, argv[5] ? argv[5] : ""); // D
    listCtrl->SetItem(index, 6, argv[6] ? argv[6] : ""); // M
    listCtrl->SetItem(index, 7, argv[7] ? argv[7] : ""); // R

    return 0;
}

int PlayersDatabasePanel::selectData(const char* filename, wxListCtrl* listCtrl)
{
    sqlite3* DB;
    char* messageError;

    std::string sql = "SELECT * FROM PLAYERS;";

    int exit = sqlite3_open(filename, &DB);
    if (exit != SQLITE_OK) {
        std::cerr << "Error opening DB\n";
        return -1;
    }

    exit = sqlite3_exec(DB, sql.c_str(), callback, listCtrl, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Blad SQL: " << messageError << std::endl;
        sqlite3_free(messageError);
    }

    sqlite3_close(DB);
    return 0;
}

void PlayersDatabasePanel::OnItemSelected(wxListEvent& event) {
    selectedIndex = event.GetIndex();
}

void PlayersDatabasePanel::OnAddSelectedPlayer(wxCommandEvent& event) {
    if (selectedIndex == -1) {
        wxMessageBox("Nie zaznaczono zawodnika.", "Blad", wxICON_WARNING);
        return;
    }

    wxString surname = listCtrl->GetItemText(selectedIndex, 1);
    wxString name = listCtrl->GetItemText(selectedIndex, 2);
    wxString club = listCtrl->GetItemText(selectedIndex, 3);
    wxString rating = listCtrl->GetItemText(selectedIndex, 4);
    wxString day = listCtrl->GetItemText(selectedIndex, 5); 
    wxString month = listCtrl->GetItemText(selectedIndex, 6); 
    wxString year = listCtrl->GetItemText(selectedIndex, 7); 
    long ratingValue = 0;
    rating.ToLong(&ratingValue);
    int rate = static_cast<int>(ratingValue);

    Player p(surname.ToStdString(), name.ToStdString(), club.ToStdString(), Date(day, month, year), rate);
    tournament->listOfPlayers.push_back(p);
    if (tournament->tournamentStarted == false)
        tournament->sortByRating(tournament->listOfPlayers);

    wxMessageBox("Zawodnik dodany do turnieju!", "Sukces", wxOK | wxICON_INFORMATION);
}
