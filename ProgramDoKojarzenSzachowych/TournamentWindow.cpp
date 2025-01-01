#include "TournamentWindow.h"


TournamentWindow::TournamentWindow(wxWindow* parent, Tournament t) : wxPanel(parent) {
    tournament = t;
    mainLabel = new wxStaticText(this, wxID_ANY, "TURNIEJ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    tournamentLabel = new wxStaticText(this, wxID_ANY, tournament.getName(), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

    placeLabel = new wxStaticText(this, wxID_ANY, "Miejscowoœæ:", wxPoint(300, 120));
    placeLabel2 = new wxStaticText(this, wxID_ANY, tournament.getPlace(), wxPoint(450, 120));

    dateLabel = new wxStaticText(this, wxID_ANY, "Data:", wxPoint(300, 170));
    dateLabel2 = new wxStaticText(this, wxID_ANY, tournament.getDate().writeDate(), wxPoint(450, 170));

    arbiterLabel = new wxStaticText(this, wxID_ANY, "Sêdzia:", wxPoint(300, 220));
    arbiterLabel2 = new wxStaticText(this, wxID_ANY, tournament.getArbiter(), wxPoint(450, 220));

    aboutLabel = new wxStaticText(this, wxID_ANY, "Opis turnieju:", wxPoint(300, 270));
    aboutLabel2 = new wxStaticText(this, wxID_ANY, tournament.getAbout(), wxPoint(300, 300), wxSize(400, 300), wxST_NO_AUTORESIZE);

    startingListButton = new wxButton(this, wxID_CANCEL, "Lista startowa", wxPoint(20, 100), wxSize(160, 40));
    resultsButton = new wxButton(this, wxID_SAVE, "Wyniki", wxPoint(20, 160), wxSize(160, 40));

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

    this->SetSizer(sizer);
    this->Layout();



    // Dodanie menu
    wxMenuBar* menuBar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu();

    fileMenu->Append(wxID_SAVE, "&Zapisz Dane Turnieju\tCtrl+S", "Zapisz dane turnieju do pliku");

    menuBar->Append(fileMenu, "&Plik");


    wxFrame* parentFrame = dynamic_cast<wxFrame*>(parent);
    if (parentFrame) {
        parentFrame->SetMenuBar(menuBar);
        parentFrame->Bind(wxEVT_MENU, &TournamentWindow::OnSaveTournament, this, wxID_SAVE);
    }

}

// Obs³uga zapisu danych turnieju
void TournamentWindow::OnSaveTournament(wxCommandEvent& event) {
    wxLogMessage("Wywo³ano funkcjê OnSaveTournament!");
    wxFileDialog saveFileDialog(this, _("Zapisz dane turnieju"), "", "tournament_data.txt",
        "Pliki tekstowe (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT
    );

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    if (!output_stream.IsOk()) {
        wxLogError("Nie mo¿na zapisaæ pliku '%s'.", saveFileDialog.GetPath());
        return;
    }

    wxTextOutputStream text(output_stream);
    text << tournament.getName() << "\n";
    text << tournament.getPlace() << "\n";
    text << tournament.getDate().getDay() << "\n";
    text << tournament.getDate().getMonth() << "\n";
    text << tournament.getDate().getYear() << "\n";
    text << tournament.getArbiter() << "\n";
    text << tournament.getAbout() << "\n";
    text << "END_OF_TOURNAMENT_DATA" << "\n";

    wxLogMessage("Dane turnieju zapisane pomyœlnie.");
}