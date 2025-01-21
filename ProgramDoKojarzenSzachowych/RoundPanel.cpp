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
    makePairingsButton = new wxButton(this, wxID_ANY, "Utwórz kojarzenia", wxDefaultPosition, wxDefaultSize);

    // Create the color choice dropdown
    wxArrayString colorOptions;
    colorOptions.Add("Bia³y");
    colorOptions.Add("Czarny");
    colorChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, colorOptions);
    colorChoice->SetSelection(0);

    sizer->Add(makePairingsButton, 0, wxALL | wxALIGN_CENTER, 10);
    sizer->Add(colorChoice, 0, wxALL | wxALIGN_CENTER, 10);
    SetSizer(sizer);

    makePairingsButton->Bind(wxEVT_BUTTON, &RoundPanel::OnMakePairings, this);
}

void RoundPanel::InitializeResultsView()
{
    pairingsListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(500, 450));

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
    selectedColour = colorChoice->GetStringSelection();


    if (r_num == 0) {
        tournament->sortByRating(tournament->listOfPlayers);
        tournament->rounds[0].firstRoundPairings(tournament->listOfPlayers, selectedColour.ToStdString());
    }

    sizer->Clear(true);

    // Initialize results view
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