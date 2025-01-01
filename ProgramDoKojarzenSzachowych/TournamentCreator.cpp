#include "TournamentCreator.h"

wxBEGIN_EVENT_TABLE(TournamentCreator, wxPanel)
//EVT_BUTTON(wxID_SAVE, TournamentCreator::OnSaveTournament)
EVT_BUTTON(wxID_SAVE, TournamentCreator::OnNext)
EVT_BUTTON(wxID_CANCEL, TournamentCreator::OnCancel)
wxEND_EVENT_TABLE()

TournamentCreator::TournamentCreator(wxWindow* parent) : wxPanel(parent) {

    wxStaticText* tournamentName = new wxStaticText(this, wxID_ANY, "Nazwa turnieju:", wxPoint(20, 20));
    nameField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(150, 15), wxSize(550, 25));

    wxStaticText* tournamentDate = new wxStaticText(this, wxID_ANY, "Data turnieju:", wxPoint(20, 60));
    wxStaticText* tournamentDate1 = new wxStaticText(this, wxID_ANY, "Dzieñ:", wxPoint(20, 100));
    dayField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 95), wxSize(40, 25));

    wxStaticText* tournamentDate2 = new wxStaticText(this, wxID_ANY, "Miesi¹c:", wxPoint(20, 140));
    monthField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 135), wxSize(40, 25));

    wxStaticText* tournamentDate3 = new wxStaticText(this, wxID_ANY, "Rok:", wxPoint(20, 180));
    yearField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 175), wxSize(40, 25));

    wxStaticText* tournamentPlace = new wxStaticText(this, wxID_ANY, "Miejscowoœæ:", wxPoint(380, 60));
    placeField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(500, 55), wxSize(200, 25));

    wxStaticText* tournamentArbiter = new wxStaticText(this, wxID_ANY, "Sêdzia:", wxPoint(380, 100));
    arbiterField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(500, 95), wxSize(200, 25));

    wxStaticText* tournamentAbout = new wxStaticText(this, wxID_ANY, "Opis turnieju:", wxPoint(20, 220));
    aboutField = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 250), wxSize(740, 200));

    cancelButton = new wxButton(this, wxID_CANCEL, "Anuluj", wxPoint(40, 470), wxSize(160, 40));
    nextButton = new wxButton(this, wxID_SAVE, "Dalej", wxPoint(590, 470), wxSize(160, 40));

    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont font2(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    tournamentName->SetFont(font);
    tournamentDate->SetFont(font);
    tournamentPlace->SetFont(font);
    tournamentArbiter->SetFont(font);
    tournamentAbout->SetFont(font);
    tournamentDate1->SetFont(font2);
    tournamentDate2->SetFont(font2);
    tournamentDate3->SetFont(font2);
    nameField->SetFont(font);
    nextButton->SetFont(font);
    cancelButton->SetFont(font);
}

void TournamentCreator::OnCancel(wxCommandEvent& event) {
    // Zamykamy obecne okno kreatora turnieju
    this->GetParent()->Show(false);  // Ukrywa kreator turnieju

    // Tworzymy now¹ instancjê g³ównego okna i je pokazujemy
    MainFrame* mainFrame = new MainFrame("Program do kojarzeñ szachowych");
    mainFrame->Show(true);
}

void TournamentCreator::OnNext(wxCommandEvent& event) {
    long day, month, year;

    // Konwersja pól na liczby
    if (!dayField->GetValue().ToLong(&day)) {
        wxLogError("B³¹d: Nieprawid³owy format dnia.");
        return;
    }
    if (!monthField->GetValue().ToLong(&month)) {
        wxLogError("B³¹d: Nieprawid³owy format miesi¹ca.");
        return;
    }
    if (!yearField->GetValue().ToLong(&year)) {
        wxLogError("B³¹d: Nieprawid³owy format roku.");
        return;
    }

    int tournamentDay = static_cast<int>(day);
    int tournamentMonth = static_cast<int>(month);
    int tournamentYear = static_cast<int>(year);
    wxString tournamentName = nameField->GetValue();
    //wxString tournamentDay = dayField->GetValue();
    //wxString tournamentMonth = monthField->GetValue();
    //wxString tournamentYear = yearField->GetValue();
    wxString tournamentPlace = placeField->GetValue();
    wxString tournamentArbiter = arbiterField->GetValue();
    wxString tournamentAbout = aboutField->GetValue();

    // Ukrywamy obecny panel
    this->Hide();

    wxWindow* parent = this->GetParent();
    
    TournamentWindow* tournamentWindow = new TournamentWindow(parent, Tournament(tournamentName.ToStdString(), Date(tournamentDay, tournamentMonth, tournamentYear), 
        tournamentPlace.ToStdString(), tournamentArbiter.ToStdString(), tournamentAbout.ToStdString()));

    // Ustawiamy sizer i uk³ad
    wxBoxSizer* sizer = dynamic_cast<wxBoxSizer*>(parent->GetSizer());
    if (sizer) {
        sizer->Clear(true); // Usuwamy obecny panel
        sizer->Add(tournamentWindow, 1, wxEXPAND);
        parent->Layout();
        parent->Refresh();
    }
}