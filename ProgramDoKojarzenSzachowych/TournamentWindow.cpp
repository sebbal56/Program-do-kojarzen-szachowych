#include "TournamentWindow.h"


TournamentWindow::TournamentWindow(wxWindow* parent, const wxString& tournamentName, const wxString& tournamentDay, const wxString& tournamentMonth,
    const wxString& tournamentYear, const wxString& tournamentPlace, const wxString& tournamentArbiter, const wxString& tournamentAbout) : wxPanel(parent) {
    // Utworzenie etykiety
    mainLabel = new wxStaticText(this, wxID_ANY, "TURNIEJ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    tournamentLabel = new wxStaticText(this, wxID_ANY, tournamentName, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

    placeLabel = new wxStaticText(this, wxID_ANY, "Miejscowoœæ:", wxPoint(300, 120));
    placeLabel2 = new wxStaticText(this, wxID_ANY, tournamentPlace, wxPoint(450, 120));

    dateLabel = new wxStaticText(this, wxID_ANY, "Data:", wxPoint(300, 170));
    dateLabel2 = new wxStaticText(this, wxID_ANY, tournamentDay + "-" + tournamentMonth + "-" + tournamentYear, wxPoint(450, 170));

    arbiterLabel = new wxStaticText(this, wxID_ANY, "Sêdzia:", wxPoint(300, 220));
    arbiterLabel2 = new wxStaticText(this, wxID_ANY, tournamentArbiter, wxPoint(450, 220));

    aboutLabel = new wxStaticText(this, wxID_ANY, "Opis turnieju:", wxPoint(300, 270));
    aboutLabel2 = new wxStaticText(this, wxID_ANY, tournamentAbout, wxPoint(300, 300), wxSize(400, 300), wxST_NO_AUTORESIZE);

    startingListButton = new wxButton(this, wxID_CANCEL, "Lista startowa", wxPoint(20, 100), wxSize(160, 40));
    resultsButton = new wxButton(this, wxID_SAVE, "Wyniki", wxPoint(20, 160), wxSize(160, 40));

    // Ustawienie czcionki
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

    // Utworzenie g³ównego sizer-a w pionie
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mainLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20); // Wyœrodkowanie tylko poziomo z marginesem od góry
    sizer->Add(tournamentLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 30); // Wyœrodkowanie tylko poziomo z marginesem od góry

    // Ustawienie sizer-a
    this->SetSizer(sizer);
    this->Layout();
}
