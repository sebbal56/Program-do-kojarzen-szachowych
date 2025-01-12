// InfoPanel.cpp

#include "InfoPanel.h"

InfoPanel::InfoPanel(wxWindow* parent, Tournament* tournament)
    : wxPanel(parent), tournament(tournament) {

    mainLabel = new wxStaticText(this, wxID_ANY, "TURNIEJ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    tournamentLabel = new wxStaticText(this, wxID_ANY, tournament -> getName(), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

    placeLabel = new wxStaticText(this, wxID_ANY, "Miejscowoœæ:", wxPoint(300, 120));
    placeLabel2 = new wxStaticText(this, wxID_ANY, tournament -> getPlace(), wxPoint(450, 120));

    dateLabel = new wxStaticText(this, wxID_ANY, "Data:", wxPoint(300, 170));
    dateLabel2 = new wxStaticText(this, wxID_ANY, tournament -> getDate().writeDate(), wxPoint(450, 170));

    arbiterLabel = new wxStaticText(this, wxID_ANY, "Sêdzia:", wxPoint(300, 220));
    arbiterLabel2 = new wxStaticText(this, wxID_ANY, tournament -> getArbiter(), wxPoint(450, 220));

    aboutLabel = new wxStaticText(this, wxID_ANY, "Opis turnieju:", wxPoint(300, 270));
    aboutLabel2 = new wxStaticText(this, wxID_ANY, tournament -> getAbout(), wxPoint(300, 300), wxSize(400, 300), wxST_NO_AUTORESIZE);

    wxFont font(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont font2(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    mainLabel->SetFont(font);
    tournamentLabel->SetFont(font);
    placeLabel->SetFont(font);
    placeLabel2->SetFont(font);
    dateLabel->SetFont(font);
    dateLabel2->SetFont(font);
    arbiterLabel->SetFont(font);
    arbiterLabel2->SetFont(font);
    aboutLabel->SetFont(font);
    aboutLabel2->SetFont(font2);

    // Uk³ad elementów w pionie
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mainLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);
    sizer->Add(tournamentLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 30);
    
    // Dodanie poziomego sizer-a dla placeLabel i placeLabel2
    wxBoxSizer* placeSizer = new wxBoxSizer(wxHORIZONTAL);
    placeSizer->Add(placeLabel, 0, wxALIGN_LEFT | wxRIGHT, 30); // Margines z prawej strony
    placeSizer->Add(placeLabel2, 1, wxEXPAND); // Rozci¹gniêcie na resztê linii

    sizer->Add(placeSizer, 0, wxEXPAND | wxTOP, 20); // Dodanie poziomego sizer-a

    wxBoxSizer* dateSizer = new wxBoxSizer(wxHORIZONTAL);
    dateSizer->Add(dateLabel, 0, wxALIGN_LEFT | wxRIGHT, 110); // Margines z prawej strony
    dateSizer->Add(dateLabel2, 1, wxEXPAND); // Rozci¹gniêcie na resztê linii

    sizer->Add(dateSizer, 0, wxEXPAND | wxTOP, 20); // Dodanie poziomego sizer-a


    //sizer->Add(dateLabel, 0, wxALIGN_LEFT | wxTOP, 10);
    //sizer->Add(dateLabel2, 0, wxALIGN_LEFT | wxTOP, 10);

    wxBoxSizer* arbiterSizer = new wxBoxSizer(wxHORIZONTAL);
    arbiterSizer->Add(arbiterLabel, 0, wxALIGN_LEFT | wxRIGHT, 90); // Margines z prawej strony
    arbiterSizer->Add(arbiterLabel2, 1, wxEXPAND); // Rozci¹gniêcie na resztê linii

    sizer->Add(arbiterSizer, 0, wxEXPAND | wxTOP, 20); // Dodanie poziomego sizer-a

    //sizer->Add(arbiterLabel, 0, wxALIGN_LEFT | wxTOP, 10);
    //sizer->Add(arbiterLabel2, 0, wxALIGN_LEFT | wxTOP, 10);
    sizer->Add(aboutLabel, 0, wxALIGN_LEFT | wxTOP, 10);
    sizer->Add(aboutLabel2, 1, wxEXPAND | wxTOP, 10);

    this->SetSizer(sizer);
    this->Layout();
}
