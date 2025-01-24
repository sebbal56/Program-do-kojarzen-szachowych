#include "AddPlayerPanel.h"

wxBEGIN_EVENT_TABLE(AddPlayerPanel, wxPanel)
EVT_BUTTON(wxID_ANY, AddPlayerPanel::OnSaveButtonClicked)
wxEND_EVENT_TABLE()


AddPlayerPanel::AddPlayerPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {

    tournament = t;

    wxStaticText* mainLabel = new wxStaticText(this, wxID_ANY, "Dodawanie nowego zawodnika", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* surnameLabel = new wxStaticText(this, wxID_ANY, "Nazwisko", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* nameLabel = new wxStaticText(this, wxID_ANY, "Imiê", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* clubLabel = new wxStaticText(this, wxID_ANY, "Klub / Miejscowoœæ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* ratingLabel = new wxStaticText(this, wxID_ANY, "Ranking", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* birthdayLabel = new wxStaticText(this, wxID_ANY, "Data urodzenia", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* dayLabel = new wxStaticText(this, wxID_ANY, "Dzieñ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* monthLabel = new wxStaticText(this, wxID_ANY, "Miesi¹c", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    wxStaticText* yearLabel = new wxStaticText(this, wxID_ANY, "Rok", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

    surnameInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    nameInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    clubInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    ratingInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
    dayInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(30, 30));
    monthInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(30, 30));
    yearInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(50, 30));


    saveButton = new wxButton(this, wxID_ANY, "Zapisz", wxDefaultPosition, wxSize(100, 30));
    saveButton->Bind(wxEVT_BUTTON, &AddPlayerPanel::OnSaveButtonClicked, this);

    wxFont font(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont font2(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont font3(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    mainLabel->SetFont(font);
    surnameLabel->SetFont(font2);
    nameLabel->SetFont(font2);
    clubLabel->SetFont(font2);
    ratingLabel->SetFont(font2);
    birthdayLabel->SetFont(font2);
    dayLabel->SetFont(font3);
    monthLabel->SetFont(font3);
    yearLabel->SetFont(font3);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mainLabel, 0, wxALIGN_CENTER | wxTOP | wxBottom, 20);

    wxBoxSizer* surnameSizer = new wxBoxSizer(wxHORIZONTAL);
    surnameSizer->Add(surnameLabel, 0, wxALIGN_CENTER | wxRIGHT, 40);
    surnameSizer->Add(surnameInput, 1, wxALIGN_CENTER);
    sizer->Add(surnameSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

    wxBoxSizer* nameSizer = new wxBoxSizer(wxHORIZONTAL);
    nameSizer->Add(nameLabel, 0, wxALIGN_CENTER | wxRIGHT, 70);
    nameSizer->Add(nameInput, 1, wxALIGN_CENTER);
    sizer->Add(nameSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

    wxBoxSizer* clubSizer = new wxBoxSizer(wxHORIZONTAL);
    clubSizer->Add(clubLabel, 0, wxALIGN_CENTER | wxRIGHT, 30);
    clubSizer->Add(clubInput, 1, wxALIGN_CENTER);
    sizer->Add(clubSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

    wxBoxSizer* ratingSizer = new wxBoxSizer(wxHORIZONTAL);
    ratingSizer->Add(ratingLabel, 0, wxALIGN_CENTER | wxRIGHT, 70);
    ratingSizer->Add(ratingInput, 0, 1, wxALIGN_CENTER);
    sizer->Add(ratingSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);


    sizer->Add(birthdayLabel, 0, wxALIGN_CENTER | wxTOP, 20);

    wxBoxSizer* bdSizer = new wxBoxSizer(wxHORIZONTAL);
    bdSizer->Add(dayLabel, 0, wxALIGN_CENTER | wxRIGHT, 10);
    bdSizer->Add(dayInput, 0, wxALIGN_CENTER | wxRIGHT, 30);
    bdSizer->Add(monthLabel, 0, wxALIGN_CENTER | wxRIGHT, 10);
    bdSizer->Add(monthInput, 0, wxALIGN_CENTER | wxRIGHT, 30);
    bdSizer->Add(yearLabel, 0, wxALIGN_CENTER | wxRIGHT, 10);
    bdSizer->Add(yearInput, 0, wxALIGN_CENTER | wxRIGHT, 30);
    sizer->Add(bdSizer, 0, wxALIGN_CENTER | wxTOP, 10);


    sizer->Add(saveButton, 0, wxALIGN_CENTER | wxTOP, 20);

    SetSizer(sizer);
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