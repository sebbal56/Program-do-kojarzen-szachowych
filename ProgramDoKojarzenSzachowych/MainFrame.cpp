#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(1001, MainFrame::OnCreateTournament)
EVT_BUTTON(1002, MainFrame::OnLoadTournament)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

    wxPanel* panel = new wxPanel(this);

    // Przycisk
    wxButton* loadButton = new wxButton(panel, wxID_ANY, "Wczytaj turniej", wxPoint(250, 100), wxSize(300, 150));
    Bind(wxEVT_BUTTON, &MainFrame::OnLoadTournament, this, loadButton->GetId());


    //przycisk
    wxButton* newButton = new wxButton(panel, wxID_ANY, "Utwórz turniej", wxPoint(250, 300), wxSize(300, 150));
    Bind(wxEVT_BUTTON, &MainFrame::OnCreateTournament, this, newButton->GetId());


    wxFont font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    loadButton->SetFont(font);
    newButton->SetFont(font);

    Bind(wxEVT_MENU, &MainFrame::OnSaveTournament, this, wxID_SAVE);

}

void MainFrame::OnRunLogic(wxCommandEvent& event) {
    AppLogic& appLogic = AppLogic::getInstance();
}

void MainFrame::OnCreateTournament(wxCommandEvent& event) {
    this->DestroyChildren(); // Usuñ obecne komponenty
    TournamentCreator* creatorPanel = new TournamentCreator(this);
    // Stwórz sizer i dodaj panel
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(creatorPanel, 1, wxEXPAND);

    // Ustaw sizer dla MainFrame
    this->SetSizer(sizer);
    this->Layout(); // Odœwie¿ uk³ad
}



void MainFrame::OnLoadTournament(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, _("Wybierz plik turnieju"), "", "", "Pliki tekstowe (*.txt)|*.txt",wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        return; // U¿ytkownik anulowa³ wybór pliku
    }

    wxString filePath = openFileDialog.GetPath();
    wxTextFile file(filePath);

    if (!file.Open()) {
        wxLogError("Nie mo¿na otworzyæ pliku: %s", filePath);
        return;
    }
    wxString line;

    wxString name, place, day, month, year, arbiter, about;
    int breakIndex;

    for (size_t i = 0; i < file.GetLineCount() || line != "END_OF_TOURNAMENT_DATA"; i++) {
        line = file[i];
        if (line == "END_OF_TOURNAMENT_DATA") {
            breakIndex = i;
            break;
        }
        //if (line.StartsWith("Nazwa: ")) name = line.AfterFirst(' ');
        //else if (line.StartsWith("Miejscowoœæ: ")) place = line.AfterFirst(' ');
        //else if (line.StartsWith("Data: ")) date = line.AfterFirst(' ');
        //else if (line.StartsWith("Sêdzia: ")) arbiter = line.AfterFirst(' ');
        //else if (line.StartsWith("Opis: ")) about = line.AfterFirst(' ');
        if (i == 0) name = line;
        else if (i == 1) place = line;
        else if (i == 2) day = line;
        else if (i == 3) month = line;
        else if (i == 4) year = line;
        else if (i == 5) arbiter = line;
        else if (i == 6) about = line;
        else if (i > 6) about += line;
    }

    file.Close();


    Tournament* tournament = new Tournament(name.ToStdString(),Date(day, month, year), place.ToStdString(), arbiter.ToStdString(), about.ToStdString());

    // Przejœcie do TournamentWindow
    this->DestroyChildren(); // Usuñ obecne komponenty
    TournamentWindow* tournamentWindow = new TournamentWindow(this, tournament);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(tournamentWindow, 1, wxEXPAND);

    this->SetSizer(sizer);
    this->Layout(); // Odœwie¿ uk³ad
}

void MainFrame::OnSaveTournament(wxCommandEvent& event) {
    wxLogMessage("Wywo³ano zapis turnieju z menu.");
    // Przeka¿ zdarzenie do aktywnego TournamentWindow
    TournamentWindow* tournamentWindow = dynamic_cast<TournamentWindow*>(FindWindowByLabel("TournamentWindowLabel")); // U¿yj identyfikatora okna
    if (tournamentWindow) {
        tournamentWindow->OnSaveTournament(event);
    }
    else {
        wxLogError("Nie znaleziono aktywnego okna turnieju.");
    }
}