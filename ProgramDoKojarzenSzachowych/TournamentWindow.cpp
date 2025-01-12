#include "TournamentWindow.h"


TournamentWindow::TournamentWindow(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;
    SetLabel("TournamentWindowLabel");

    // Tworzenie menu
    wxMenuBar* menuBar = new wxMenuBar();

    // Menu "Plik"
    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(wxID_SAVE, "Zapisz turniej\tCtrl+S", "Zapisz dane turnieju");
    menuBar->Append(fileMenu, "Plik");

    // Ustawienie menu dla okna nadrzêdnego
    wxFrame* parentFrame = dynamic_cast<wxFrame*>(GetParent());
    if (parentFrame) {
        parentFrame->SetMenuBar(menuBar);
    }

    // Panel z przyciskami (po lewej stronie)
    wxPanel* buttonPanel = new wxPanel(this);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    mainButton = new wxButton(buttonPanel, wxID_ANY, "Strona g³ówna", wxDefaultPosition, wxSize(160, 40));
    startingListButton = new wxButton(buttonPanel, wxID_ANY, "Lista startowa", wxDefaultPosition, wxSize(160, 40));
    resultsButton = new wxButton(buttonPanel, wxID_ANY, "Wyniki", wxDefaultPosition, wxSize(160, 40));
    
    buttonSizer->Add(mainButton, 0, wxALL, 10);
    buttonSizer->Add(startingListButton, 0, wxALL, 10);
    buttonSizer->Add(resultsButton, 0, wxALL, 10);
    buttonPanel->SetSizer(buttonSizer);

    // Panel z treœci¹ (prawa czêœæ, która siê zmienia)
    contentPanel = new wxPanel(this);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);

    // Tworzymy InfoPanel, który wyœwietli szczegó³y turnieju
    InfoPanel* infoPanel = new InfoPanel(contentPanel, tournament);
    contentSizer->Add(infoPanel, 1, wxEXPAND | wxALL, 10); // Dodajemy InfoPanel do contentPanel

    contentPanel->SetSizer(contentSizer);

    // G³ówny sizer: podzielony na dwie kolumny
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 10);  // Przyciski po lewej stronie
    mainSizer->Add(contentPanel, 1, wxEXPAND | wxALL, 10); // Dynamiczna zawartoœæ po prawej stronie

    this->SetSizer(mainSizer);
    this->Layout();


    // Zdarzenia
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowStartingList, this, startingListButton->GetId());
    Bind(wxEVT_BUTTON, &TournamentWindow::OnShowInfoPanel, this, mainButton->GetId());
    Bind(wxEVT_MENU, &TournamentWindow::OnSaveTournament, this, wxID_SAVE);
    //Bind(wxEVT_BUTTON, &TournamentWindow::OnShowResults, this, resultsButton->GetId());
}




void TournamentWindow::OnSaveTournament(wxCommandEvent& event) {
    wxLogMessage("Wywo³ano funkcjê zapisu turnieju.");

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