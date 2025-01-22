#include "ResultsInputPanel.h"
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/button.h>
#include "Round.h"

ResultsInputPanel::ResultsInputPanel(wxWindow* parent, Tournament* tournament, int rNumber)
    : wxPanel(parent), tournament(tournament), sizer(new wxBoxSizer(wxVERTICAL)) {

    r_num = rNumber - 1;

    // Create title
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "WprowadŸ wyniki dla rundy " + std::to_string(rNumber));
    sizer->Add(title, 0, wxALL | wxALIGN_CENTER, 10);

    for (auto& pair : tournament->rounds[r_num].pairings) {
        wxBoxSizer* pairSizer = new wxBoxSizer(wxHORIZONTAL);

        wxStaticText* pairLabel = new wxStaticText(this, wxID_ANY, pair.display());
        pairSizer->Add(pairLabel, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        wxArrayString resultOptions;
        resultOptions.Add("1-0");        
        resultOptions.Add("0.5-0.5");  
        resultOptions.Add("0-1");     
        wxChoice* resultChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, resultOptions);
        resultChoice->SetSelection(1);

        pairSizer->Add(resultChoice, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        sizer->Add(pairSizer, 0, wxEXPAND | wxALL, 5);

        // Save dropdown for later processing
        resultsChoices.push_back(resultChoice);
    }

    wxButton* saveResultsButton = new wxButton(this, wxID_ANY, "Zapisz wyniki");
    sizer->Add(saveResultsButton, 0, wxALL | wxALIGN_CENTER, 10);

    // Bind event
    saveResultsButton->Bind(wxEVT_BUTTON, &ResultsInputPanel::OnSaveResults, this);

    SetSizer(sizer);
    Layout();
}

void ResultsInputPanel::OnSaveResults(wxCommandEvent& event) {
    int i = 0;
    for (auto& choice : resultsChoices) {
        int selectedIndex = choice->GetSelection();
        tournament->rounds[r_num].pairings[i].setResult(selectedIndex);
        int white = tournament->rounds[r_num].pairings[i].getWhitePlayer();
        int black = tournament->rounds[r_num].pairings[i].getBlackPlayer();
        for (int j = 0; j < tournament->listOfPlayers.size(); j++) {
            if (tournament->listOfPlayers[j].startingPosition == white) {
                switch (selectedIndex) {
                    case(0): {
                        tournament->listOfPlayers[j].points++;
                        tournament->listOfPlayers[j].addAsPlayedWith(black, 1);
                        break;
                    }
                    case(1): {
						tournament->listOfPlayers[j].points += 0.5;
                        tournament->listOfPlayers[j].addAsPlayedWith(black, 0.5);
                        break;
                    }
                    case(2): {
                        tournament->listOfPlayers[j].addAsPlayedWith(black, 0);
                        break;
                    }
                }
            }
            if (tournament->listOfPlayers[j].startingPosition == black) {
                switch (selectedIndex) {
                    case(2): {
                        tournament->listOfPlayers[j].points++;
                        tournament->listOfPlayers[j].addAsPlayedWith(white, 1);
                        break;
                    }
                    case(1): {
                        tournament->listOfPlayers[j].points += 0.5;
                        tournament->listOfPlayers[j].addAsPlayedWith(white, 0.5);
                        break;
                    }
                    case(0): {
					    tournament->listOfPlayers[j].addAsPlayedWith(white, 0);
					    break;
				    }
                }
            }
        }
        i++;
    }

    wxMessageBox("Wyniki zosta³y zapisane!", "Sukces", wxOK | wxICON_INFORMATION);
    tournament->rounds[r_num].roundEnded = true;

    tournament->rounds.push_back(Round());

    wxWindow* parent = GetParent();
    while (parent != nullptr) {
        TournamentWindow* tournamentWindow = dynamic_cast<TournamentWindow*>(parent);
        if (tournamentWindow) {
            tournamentWindow->RefreshRoundButtons();
            break;
        }
        parent = parent->GetParent(); // Przejœcie w górê hierarchii
    }

    sizer->Clear(true);

    // Create and display ResultsInputPanel
    RoundPanel* roundPanel = new RoundPanel(this, tournament, r_num + 1);
    sizer->Add(roundPanel, 1, wxEXPAND | wxALL, 10);

    SetSizer(sizer);
    Layout();
}
