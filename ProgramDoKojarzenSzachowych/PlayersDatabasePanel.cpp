#include "PlayersDatabasePanel.h"


wxBEGIN_EVENT_TABLE(PlayersDatabasePanel, wxPanel)
EVT_LIST_ITEM_SELECTED(wxID_ANY, PlayersDatabasePanel::OnItemSelected)
EVT_BUTTON(1003, PlayersDatabasePanel::OnAddSelectedPlayer)
EVT_BUTTON(1004, PlayersDatabasePanel::OnDeleteSelectedPlayer)
EVT_BUTTON(1005, PlayersDatabasePanel::OnSortById)
EVT_BUTTON(1006, PlayersDatabasePanel::OnSortBySurname)
EVT_BUTTON(1007, PlayersDatabasePanel::OnSortByRating)
EVT_BUTTON(1008, PlayersDatabasePanel::OnSearch)
EVT_BUTTON(1009, PlayersDatabasePanel::OnEdit)
wxEND_EVENT_TABLE()

PlayersDatabasePanel::PlayersDatabasePanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

    listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(600, 300), wxLC_REPORT);

    listCtrl->InsertColumn(0, "ID", wxLIST_FORMAT_LEFT, 33);
    listCtrl->InsertColumn(1, "Nazwisko", wxLIST_FORMAT_LEFT, 105);
    listCtrl->InsertColumn(2, "Imie", wxLIST_FORMAT_LEFT, 110);
    listCtrl->InsertColumn(3, "Klub", wxLIST_FORMAT_LEFT, 105);
    listCtrl->InsertColumn(4, "rank", wxLIST_FORMAT_LEFT, 60);
    listCtrl->InsertColumn(5, "D", wxLIST_FORMAT_LEFT, 30);
    listCtrl->InsertColumn(6, "M", wxLIST_FORMAT_LEFT, 30);
    listCtrl->InsertColumn(7, "R", wxLIST_FORMAT_LEFT, 50);

    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE));
    listCtrl->SetFont(font);

    selectData("players.db", listCtrl);

    wxButton* addToTournamentButton = new wxButton(this, 1003, "Dodaj do turnieju", wxDefaultPosition, wxSize(150, 35));
    wxButton* deleteFromDatabaseButton = new wxButton(this, 1004, "Usun z bazy danych", wxDefaultPosition, wxSize(150, 35));
    wxButton* editPlayerButton = new wxButton(this, 1009, "Edytuj dane zawodnika", wxDefaultPosition, wxSize(150, 35));


    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listCtrl, 1, wxEXPAND | wxALL, 10);

    wxBoxSizer* sortButtonsSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* sortByIdButton = new wxButton(this, 1005, "Sortowanie domyslne", wxDefaultPosition, wxSize(150, 30));
    wxButton* sortBySurnameButton = new wxButton(this, 1006, "Sortuj wg nazwiska", wxDefaultPosition, wxSize(150, 30));
    wxButton* sortByRatingButton = new wxButton(this, 1007, "Sortuj wg rankingu", wxDefaultPosition, wxSize(150, 30));

    sortButtonsSizer->Add(sortByIdButton, 0, wxRIGHT, 10);
    sortButtonsSizer->Add(sortBySurnameButton, 0, wxRIGHT, 10);
    sortButtonsSizer->Add(sortByRatingButton, 0);
    sizer->Add(sortButtonsSizer, 0, wxALIGN_CENTER | wxBOTTOM, 10);

    wxBoxSizer* searchSizer = new wxBoxSizer(wxHORIZONTAL);
    searchCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, 35));
    wxButton* searchButton = new wxButton(this, 1008, "Szukaj", wxDefaultPosition, wxSize(100, 25));

    searchSizer->Add(searchCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    searchSizer->Add(searchButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);

    sizer->Add(searchSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    wxBoxSizer* ButtonsSizer = new wxBoxSizer(wxHORIZONTAL);
    ButtonsSizer->AddStretchSpacer(1);
    ButtonsSizer->Add(addToTournamentButton, 0, wxRIGHT, 10);
    ButtonsSizer->Add(deleteFromDatabaseButton, 0, wxRIGHT, 10);
    ButtonsSizer->Add(editPlayerButton, 0);
    ButtonsSizer->AddStretchSpacer(1);
    sizer->Add(ButtonsSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);




    SetSizer(sizer);

    SetSizer(sizer);
}
int PlayersDatabasePanel::callback(void* data, int argc, char** argv, char** azColName)
{
    wxListCtrl* listCtrl = static_cast<wxListCtrl*>(data);

    long index = listCtrl->GetItemCount();
    listCtrl->InsertItem(index, argv[0] ? argv[0] : ""); 
    listCtrl->SetItem(index, 1, argv[1] ? argv[1] : ""); 
    listCtrl->SetItem(index, 2, argv[2] ? argv[2] : ""); 
    listCtrl->SetItem(index, 3, argv[3] ? argv[3] : ""); 
    listCtrl->SetItem(index, 4, argv[4] ? argv[4] : ""); 
    listCtrl->SetItem(index, 5, argv[5] ? argv[5] : ""); 
    listCtrl->SetItem(index, 6, argv[6] ? argv[6] : ""); 
    listCtrl->SetItem(index, 7, argv[7] ? argv[7] : ""); 

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

void PlayersDatabasePanel::OnDeleteSelectedPlayer(wxCommandEvent& event) {
    if (selectedIndex == -1) {
        wxMessageBox("Nie zaznaczono zawodnika.", "Blad", wxICON_WARNING);
        return;
    }

    wxString idStr = listCtrl->GetItemText(selectedIndex, 0);
    long id;
    if (!idStr.ToLong(&id)) {
        wxMessageBox("Nieprawid³owe ID.", "Blad", wxICON_ERROR);
        return;
    }

    int confirm = wxMessageBox("Czy na pewno chcesz usun¹æ tego zawodnika z bazy danych?", "Potwierdzenie", wxYES_NO | wxICON_QUESTION);
    if (confirm != wxYES) return;

    sqlite3* DB;
    int exit = sqlite3_open("players.db", &DB);
    if (exit != SQLITE_OK) {
        wxMessageBox("Nie uda³o siê otworzyæ bazy danych.", "B³¹d", wxICON_ERROR);
        return;
    }

    std::string sql = "DELETE FROM PLAYERS WHERE PLAYER_ID = " + std::to_string(id) + ";";

    char* errorMessage;
    exit = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, &errorMessage);
    if (exit != SQLITE_OK) {
        wxString msg = "Blad przy usuwaniu: ";
        msg += errorMessage;
        wxMessageBox(msg, "Blad", wxICON_ERROR);
        sqlite3_free(errorMessage);
    }
    else {
        listCtrl->DeleteItem(selectedIndex);
        selectedIndex = -1;
        wxMessageBox("Zawodnik usuniety z bazy!", "Sukces", wxOK | wxICON_INFORMATION);
    }

    sqlite3_close(DB);
}

void PlayersDatabasePanel::refreshList(const std::string& orderBy) {
    listCtrl->DeleteAllItems();


    sqlite3* DB;
    char* messageError;
    std::string sql = "SELECT * FROM PLAYERS ";

    wxString text = searchCtrl->GetValue().Trim().Upper();
    if (!text.IsEmpty()) {
        sql += " WHERE SURNAME LIKE '" + text + "%'";
    }


    sql += "ORDER BY " + orderBy + "; ";


    int exit = sqlite3_open("players.db", &DB);
    if (exit != SQLITE_OK) {
        wxMessageBox("B³¹d otwierania bazy danych.", "B³¹d", wxICON_ERROR);
        return;
    }
    exit = sqlite3_exec(DB, sql.c_str(), callback, listCtrl, &messageError);
    if (exit != SQLITE_OK) {
        wxString msg = "B³¹d SQL: ";
        msg += messageError;
        wxMessageBox(msg, "B³¹d", wxICON_ERROR);
        sqlite3_free(messageError);
    }

    sqlite3_close(DB);
}

void PlayersDatabasePanel::OnSortById(wxCommandEvent& event) {
    refreshList("PLAYER_ID ASC");
}

void PlayersDatabasePanel::OnSortBySurname(wxCommandEvent& event) {
    refreshList("SURNAME COLLATE NOCASE ASC, NAME COLLATE NOCASE ASC, RATING DESC");
}

void PlayersDatabasePanel::OnSortByRating(wxCommandEvent& event) {
    refreshList("RATING DESC");
}

void PlayersDatabasePanel::OnSearch(wxCommandEvent& event) {
    wxString text = searchCtrl->GetValue().Trim().Upper();
    if (text.IsEmpty()) {
        refreshList("PLAYER_ID ASC");
        return;
    }

    searchBySurname(text.ToStdString());
}

void PlayersDatabasePanel::searchBySurname(const std::string& prefix) {
    listCtrl->DeleteAllItems();

    sqlite3* DB;
    char* messageError;

    std::string sql = "SELECT * FROM PLAYERS WHERE UPPER(SURNAME) LIKE '" + prefix + "%';";

    int exit = sqlite3_open("players.db", &DB);
    if (exit != SQLITE_OK) {
        wxMessageBox("B³¹d otwierania bazy danych.", "B³¹d", wxICON_ERROR);
        return;
    }

    exit = sqlite3_exec(DB, sql.c_str(), callback, listCtrl, &messageError);
    if (exit != SQLITE_OK) {
        wxString msg = "B³¹d SQL: ";
        msg += messageError;
        wxMessageBox(msg, "B³¹d", wxICON_ERROR);
        sqlite3_free(messageError);
    }

    sqlite3_close(DB);
}

void PlayersDatabasePanel::OnEdit(wxCommandEvent& event) {
    if (selectedIndex == -1) {
        wxMessageBox("Nie zaznaczono zawodnika.", "B³¹d", wxICON_WARNING);
        return;
    }

    long id;
    if (!listCtrl->GetItemText(selectedIndex, 0).ToLong(&id)) {
        wxMessageBox("Nieprawid³owe ID.", "B³¹d", wxICON_ERROR);
        return;
    }

    EditPlayerDialog dlg(this, id);
    if (dlg.ShowModal() == wxID_OK) {
        refreshList("PLAYER_ID ASC");
    }
}