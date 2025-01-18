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
    // Create the "Make Pairings" button
    makePairingsButton = new wxButton(this, wxID_ANY, "Utwórz kojarzenia", wxDefaultPosition, wxDefaultSize);

    // Create the color choice dropdown
    wxArrayString colorOptions;
    colorOptions.Add("Bia³y");
    colorOptions.Add("Czarny");
    colorChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, colorOptions);
    colorChoice->SetSelection(0); // Default to "Bia³y"

    // Layout
    sizer->Add(makePairingsButton, 0, wxALL | wxALIGN_CENTER, 10);
    sizer->Add(colorChoice, 0, wxALL | wxALIGN_CENTER, 10);
    SetSizer(sizer);

    // Bind event
    makePairingsButton->Bind(wxEVT_BUTTON, &RoundPanel::OnMakePairings, this);
}

void RoundPanel::InitializeResultsView()
{
    // Create a listbox to display pairings
    pairingsListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));
    //for (int i = 0; i < 3; i++) {
    //    pairingsListBox->Append("PARA: " + std::to_string(i) );
    //}

    for (auto& pair : tournament->rounds[r_num].pairings) {
        pairingsListBox->Append(pair.display());
    }


    // Create a button to input results
    inputResultsButton = new wxButton(this, wxID_ANY, "WprowadŸ wyniki", wxDefaultPosition, wxDefaultSize);

    // Update layout
    sizer->Add(pairingsListBox, 1, wxEXPAND | wxALL, 10);
    sizer->Add(inputResultsButton, 0, wxALL | wxALIGN_CENTER, 10);
    SetSizer(sizer);
    Layout();
}

void RoundPanel::OnMakePairings(wxCommandEvent& event)
{
    // Get the selected color
    selectedColour = colorChoice->GetStringSelection();

    // Generate pairings (example logic, replace with actual logic)
    //tournament->rounds[r_num].GeneratePairings(selectedColor == "Bia³y");

    if (r_num == 0) {
        tournament->rounds[0].firstRoundPairings(tournament->listOfPlayers, selectedColour.ToStdString());
    }

    // Clear existing layout
    sizer->Clear(true);

    // Initialize results view
    InitializeResultsView();

    // Mark round as paired
    tournament->rounds[r_num].roundPaired = true;
}
