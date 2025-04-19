#include "RoundPanel.h"
#include "Round.h"

RoundPanel::RoundPanel(wxWindow* parent, Tournament* tournament, int rNumber)
    : wxPanel(parent), tournament(tournament), sizer(new wxBoxSizer(wxVERTICAL)){

    r_num = rNumber - 1;
    if (!tournament->rounds[r_num].roundPaired) {
        InitializePairingsView();
    }
    else {
        InitializeResultsView();
    }
}

void RoundPanel::InitializePairingsView()
{
    gridSizer = new wxFlexGridSizer(1, 0, 0);

    gridSizer->AddGrowableRow(0); 
    gridSizer->AddGrowableCol(0); 

    wxBoxSizer* centerSizer = new wxBoxSizer(wxVERTICAL);

    wxFont buttonFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont choiceFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    makePairingsButton = new wxButton(this, wxID_ANY, "Utwórz kojarzenia", wxDefaultPosition, wxDefaultSize);
    makePairingsButton->SetFont(buttonFont);
    centerSizer->Add(makePairingsButton, 0, wxALL | wxALIGN_CENTER, 10);

    if (r_num == 0) {
        wxArrayString colorOptions;
        colorOptions.Add("Bia³y");
        colorOptions.Add("Czarny");

        colorChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, colorOptions);
        colorChoice->SetFont(choiceFont);
        colorChoice->SetSelection(0);

        centerSizer->Add(colorChoice, 0, wxALL | wxALIGN_CENTER, 10);
    }

    gridSizer->Add(centerSizer, 1, wxALIGN_CENTER);

    SetSizer(gridSizer);

    makePairingsButton->Bind(wxEVT_BUTTON, &RoundPanel::OnMakePairings, this);
}

void RoundPanel::InitializeResultsView()
{
    pairingsListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(500, 450));

    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
    pairingsListBox->SetFont(font);

    std::ostringstream stream;
    stream << std::setw(36) << std::left << "Biale" << std::setw(9) << std::left << "Wynik" << std::setw(32) << std::right << "Czarne";

    pairingsListBox->Append(stream.str());

    if (tournament->rounds[r_num].roundEnded) {
        for (auto& pair : tournament->rounds[r_num].pairings) {
            pairingsListBox->Append(pair.displayResult());
        }
    }
    else {
        for (auto& pair : tournament->rounds[r_num].pairings) {
            pairingsListBox->Append(pair.display());
        }
    }


    sizer->Add(pairingsListBox, 1, wxEXPAND | wxALL, 10);

    if (!tournament->rounds[r_num].roundEnded) {
        inputResultsButton = new wxButton(this, wxID_ANY, "WprowadŸ wyniki", wxDefaultPosition, wxDefaultSize);
        sizer->Add(inputResultsButton, 0, wxALL | wxALIGN_CENTER, 10);
        inputResultsButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
            SwitchToResultsInputPanel();
            });
        SetSizer(sizer);
        Layout();


    }
}

void RoundPanel::OnMakePairings(wxCommandEvent& event)
{    
    if (r_num == 0) {
        tournament->tournamentStarted = true;
        tournament->sortByRating(tournament->listOfPlayers);
        selectedColour = colorChoice->GetStringSelection();
        tournament->firstColour = selectedColour == "Bia³y";
        selectedColour = colorChoice->GetStringSelection();
        tournament->rounds[0].firstRoundPairings(tournament->listOfPlayers, tournament->firstColour);
        tournament->firstColour = !tournament->firstColour;
    }
    if (r_num == 1) {
        tournament->sortByPoints(tournament->listOfPlayers);
		tournament->rounds[1].secoundRoundPairings(tournament->listOfPlayers, tournament->firstColour);
        tournament->firstColour = !tournament->firstColour;
    }
    if (r_num > 1) {
        tournament->sortByStarting(tournament->listOfPlayers);
        tournament->rounds[r_num].furtherRoundPairings(tournament->listOfPlayers, tournament->firstColour);
        tournament->firstColour = !tournament->firstColour;
    }
    sizer->Clear(true);
    gridSizer->Clear(true);

    InitializeResultsView();

    tournament->rounds[r_num].roundPaired = true;
}


void RoundPanel::SwitchToResultsInputPanel()
{
    sizer->Clear(true);

    ResultsInputPanel* resultsInputPanel = new ResultsInputPanel(this, tournament, r_num + 1);
    sizer->Add(resultsInputPanel, 1, wxEXPAND | wxALL, 10);

    SetSizer(sizer);
    Layout();
}