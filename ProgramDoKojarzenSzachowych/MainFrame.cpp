#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(1001, MainFrame::OnCreateTournament)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

    wxPanel* panel = new wxPanel(this);

    // Przycisk
    wxButton* loadButton = new wxButton(panel, wxID_ANY, "Wczytaj turniej", wxPoint(250, 100), wxSize(300, 150));


    //przycisk
    wxButton* newButton = new wxButton(panel, wxID_ANY, "Utwórz turniej", wxPoint(250, 300), wxSize(300, 150));
    Bind(wxEVT_BUTTON, &MainFrame::OnCreateTournament, this, newButton->GetId());


    wxFont font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    loadButton->SetFont(font);
    newButton->SetFont(font);

}

void MainFrame::OnRunLogic(wxCommandEvent& event) {
    AppLogic& appLogic = AppLogic::getInstance();
}

void MainFrame::OnCreateTournament(wxCommandEvent& event) {
    this->DestroyChildren(); // Usuñ obecne komponenty
    TournamentCreator* creatorPanel = new TournamentCreator(this);
    this->Layout(); // Odœwie¿ uk³ad
}
