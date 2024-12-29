#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {

    wxPanel* panel = new wxPanel(this);

    // Pole tekstowe
    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 20), wxSize(200, 25));

    // Przycisk
    wxButton* button = new wxButton(panel, wxID_ANY, "Przetwórz dane", wxPoint(240, 20));
    Bind(wxEVT_BUTTON, &MainFrame::OnRunLogic, this, button->GetId());

    // Wynik
    outputLabel = new wxStaticText(panel, wxID_ANY, "Wynik pojawi siê tutaj", wxPoint(20, 60), wxSize(300, 25));
}

void MainFrame::OnRunLogic(wxCommandEvent& event) {
    wxString input = inputField->GetValue();
    AppLogic& appLogic = AppLogic::getInstance();
    std::string result = logic.processData(std::string(input.mb_str()));
    outputLabel->SetLabel(result);
}
