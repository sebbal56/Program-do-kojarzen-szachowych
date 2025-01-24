#include "TournamentWindow.h"
#include "Round.h"

TournamentWindow::TournamentWindow(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;
    SetLabel("TournamentWindowLabel");

    wxMenuBar* menuBar = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(wxID_SAVE, "Zapisz turniej\tCtrl+S", "Zapisz dane turnieju");
    menuBar->Append(fileMenu, "Plik");

    wxFrame* parentFrame = dynamic_cast<wxFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->SetMenuBar(menuBar);
    }

    // Panel z przyciskami po lewej
    buttonPanel = new wxPanel(this);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    mainButton = new wxButton(buttonPanel, wxID_ANY, "Strona g³ówna", wxDefaultPosition, wxSize(160, 40));
    startingListButton = new wxButton(buttonPanel, wxID_ANY, "Lista startowa", wxDefaultPosition, wxSize(160, 40));
    resultsButton = new wxButton(buttonPanel, wxID_ANY, "Wyniki", wxDefaultPosition, wxSize(160, 40));


    
    buttonSizer->Add(mainButton, 0, wxALL, 10);
    buttonSizer->Add(startingListButton, 0, wxALL, 10);
    buttonSizer->Add(resultsButton, 0, wxALL, 10);
    buttonPanel->SetSizer(buttonSizer);

    int r_num = 1;
    for (auto& round : tournament->rounds) {
        wxButton* roundButton = new wxButton(buttonPanel, wxID_ANY, "Runda " + std::to_string(r_num), wxDefaultPosition, wxSize(160, 30));

        roundButton->Bind(wxEVT_BUTTON, [this, r_num](wxCommandEvent& event) {OnShowRound(event, r_num); });

        buttonSizer->Add(roundButton, 0, wxALL, 10);
        r_num++;
    }

    // Panel z z prawej
    contentPanel = new wxPanel(this);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);

    InfoPanel* infoPanel = new InfoPanel(contentPanel, tournament);
    contentSizer->Add(infoPanel, 1, wxEXPAND | wxALL, 10);

    contentPanel->SetSizer(contentSizer);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(contentPanel, 1, wxEXPAND | wxALL, 10);

    this->SetSizer(mainSizer);
    this->Layout();


    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowStartingList, this, startingListButton->GetId());
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowInfoPanel, this, mainButton->GetId());
    Bind(wxEVT_MENU, &TournamentWindow::OnSaveTournament, this, wxID_SAVE);
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowResults, this, resultsButton->GetId());
}




void TournamentWindow::OnSaveTournament(wxCommandEvent& event) {
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
    text << tournament -> getName() << "\n";
    text << tournament -> getPlace() << "\n";
    text << tournament -> getDate().getDay() << "\n";
    text << tournament -> getDate().getMonth() << "\n";
    text << tournament -> getDate().getYear() << "\n";
    text << tournament -> getArbiter() << "\n";
    text << tournament -> getAbout() << "\n";
    text << "END_OF_TOURNAMENT_DATA" << "\n";

    text << "BEGIN_OF_LIST_OF_PLAYERS" << "\n";
    for (auto& player : tournament->listOfPlayers) {
        text << player.playerToFile() << "\n";
    }
    text << "END_OF_LIST_OF_PLAYERS" << "\n";

    wxLogMessage("Dane turnieju zapisane pomyœlnie.");
}



void TournamentWindow::OnShowStartingList(wxCommandEvent& event) {
    contentPanel->DestroyChildren();

    StartingListPanel* startingListPanel = new StartingListPanel(contentPanel, tournament);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);
    contentSizer->Add(startingListPanel, 1, wxEXPAND);
    contentPanel->SetSizer(contentSizer);
    contentPanel->Layout();
}




void TournamentWindow::OnShowInfoPanel(wxCommandEvent& event) {
    contentPanel->DestroyChildren();

    InfoPanel* startingListPanel = new InfoPanel(contentPanel, tournament);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);
    contentSizer->Add(startingListPanel, 1, wxEXPAND);
    contentPanel->SetSizer(contentSizer);
    contentPanel->Layout();
}

void TournamentWindow::OnShowResults(wxCommandEvent& event){
    contentPanel->DestroyChildren();
    
    ResultsPanel* resultsPanel = new ResultsPanel(contentPanel, tournament);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);
    contentSizer->Add(resultsPanel, 1, wxEXPAND);
    contentPanel->SetSizer(contentSizer);
    contentPanel->Layout();
}

void TournamentWindow::OnShowRound(wxCommandEvent& event, int roundNumber) {
    contentPanel->DestroyChildren();

    RoundPanel* roundPanel = new RoundPanel(contentPanel, tournament, roundNumber);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);
    contentSizer->Add(roundPanel, 1, wxEXPAND);
    contentPanel->SetSizer(contentSizer);
    contentPanel->Layout();
}


void TournamentWindow::RefreshRoundButtons() {
    buttonPanel->DestroyChildren(); // Usuwamy istniej¹ce przyciski
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    // Dodajemy g³ówne przyciski
    mainButton = new wxButton(buttonPanel, wxID_ANY, "Strona g³ówna", wxDefaultPosition, wxSize(160, 40));
    startingListButton = new wxButton(buttonPanel, wxID_ANY, "Lista startowa", wxDefaultPosition, wxSize(160, 40));
    resultsButton = new wxButton(buttonPanel, wxID_ANY, "Wyniki", wxDefaultPosition, wxSize(160, 40));

    buttonSizer->Add(mainButton, 0, wxALL, 10);
    buttonSizer->Add(startingListButton, 0, wxALL, 10);
    buttonSizer->Add(resultsButton, 0, wxALL, 10);

    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowStartingList, this, startingListButton->GetId());
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowInfoPanel, this, mainButton->GetId());
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowResults, this, resultsButton->GetId());

    int r_num = 1;
    for (auto& round : tournament->rounds) {
        wxButton* roundButton = new wxButton(buttonPanel, wxID_ANY, "Runda " + std::to_string(r_num), wxDefaultPosition, wxSize(160, 30));
        roundButton->Bind(wxEVT_BUTTON, [this, r_num](wxCommandEvent& event) { OnShowRound(event, r_num); });

        buttonSizer->Add(roundButton, 0, wxALL, 10);
        r_num++;
    }

    buttonPanel->SetSizer(buttonSizer);
    buttonPanel->Layout();
    Layout();
}
