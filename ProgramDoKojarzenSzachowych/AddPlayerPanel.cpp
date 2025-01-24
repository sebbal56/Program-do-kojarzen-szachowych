#include "AddPlayerPanel.h"

wxBEGIN_EVENT_TABLE(AddPlayerPanel, wxPanel)
EVT_BUTTON(wxID_ANY, AddPlayerPanel::OnSaveButtonClicked)
wxEND_EVENT_TABLE()


AddPlayerPanel::AddPlayerPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {

    tournament = t;

    // Czcionki
    wxFont mainFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont labelFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont inputFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    wxStaticText* mainLabel = new wxStaticText(this, wxID_ANY, "Dodawanie nowego zawodnika");
    wxStaticText* surnameLabel = new wxStaticText(this, wxID_ANY, "Nazwisko:");
    wxStaticText* nameLabel = new wxStaticText(this, wxID_ANY, "Imiê:");
    wxStaticText* clubLabel = new wxStaticText(this, wxID_ANY, "Klub / Miejscowoœæ:");
    wxStaticText* ratingLabel = new wxStaticText(this, wxID_ANY, "Ranking:");
    wxStaticText* birthdayLabel = new wxStaticText(this, wxID_ANY, "Data urodzenia:");

    surnameInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    surnameInput->SetFont(inputFont);
    nameInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    nameInput->SetFont(inputFont);
    clubInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    clubInput->SetFont(inputFont);
    ratingInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    ratingInput->SetFont(inputFont);
    dayInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, 30));
    dayInput->SetFont(inputFont);
    monthInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(40, 30));
    monthInput->SetFont(inputFont);
    yearInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 30));
    yearInput->SetFont(inputFont);

    saveButton = new wxButton(this, wxID_ANY, "Zapisz", wxDefaultPosition, wxSize(100, 30));
    saveButton->Bind(wxEVT_BUTTON, &AddPlayerPanel::OnSaveButtonClicked, this);


    mainLabel->SetFont(mainFont);
    surnameLabel->SetFont(labelFont);
    nameLabel->SetFont(labelFont);
    clubLabel->SetFont(labelFont);
    ratingLabel->SetFont(labelFont);
    birthdayLabel->SetFont(labelFont);

    // Sizer g³ówny
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(mainLabel, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

    // Sizer z siatk¹
    wxFlexGridSizer* gridSizer = new wxFlexGridSizer(2, 25, 25);
    gridSizer->AddGrowableCol(1);
    gridSizer->Add(surnameLabel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    gridSizer->Add(surnameInput, 1, wxEXPAND);
    gridSizer->Add(nameLabel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    gridSizer->Add(nameInput, 1, wxEXPAND);
    gridSizer->Add(clubLabel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    gridSizer->Add(clubInput, 1, wxEXPAND);
    gridSizer->Add(ratingLabel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);
    gridSizer->Add(ratingInput, 1, wxEXPAND);
    gridSizer->Add(birthdayLabel, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL);

    // Sizer dla daty
    wxBoxSizer* dateSizer = new wxBoxSizer(wxHORIZONTAL);
    dateSizer->Add(dayInput, 0, wxRIGHT, 5);
    dateSizer->Add(new wxStaticText(this, wxID_ANY, "-"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dateSizer->Add(monthInput, 0, wxRIGHT, 5);
    dateSizer->Add(new wxStaticText(this, wxID_ANY, "-"), 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 5);
    dateSizer->Add(yearInput, 0);
    gridSizer->Add(dateSizer, 1, wxEXPAND);

    mainSizer->Add(gridSizer, 1, wxALL | wxEXPAND, 20);

    mainSizer->Add(saveButton, 0, wxALIGN_CENTER | wxTOP, 20);

    SetSizer(mainSizer);
}




void AddPlayerPanel::OnSaveButtonClicked(wxCommandEvent& event) {

    wxString surname = surnameInput->GetValue();
    wxString name = nameInput->GetValue();
    wxString club = clubInput->GetValue();
    wxString rating = ratingInput->GetValue();
    wxString day = dayInput->GetValue();
    wxString month = monthInput->GetValue();
    wxString year = yearInput->GetValue();
    long ratingValue = 0;
    rating.ToLong(&ratingValue); 
    int rate = static_cast<int>(ratingValue);

    Player p(surname.ToStdString(), name.ToStdString(), club.ToStdString(), Date(day, month, year), rate);
    tournament->listOfPlayers.push_back(p);
    if(tournament->tournamentStarted == false)
        tournament->sortByRating(tournament->listOfPlayers);
    surnameInput->Clear();
    nameInput->Clear();
    clubInput->Clear();
    ratingInput->Clear();
    dayInput->Clear();
    monthInput->Clear();
    yearInput->Clear();

    //wxMessageBox("Dane zawodnika zosta³y zapisane!", "Informacja", wxOK | wxICON_INFORMATION, this);
}