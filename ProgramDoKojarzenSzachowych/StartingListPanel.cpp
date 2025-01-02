#include "StartingListPanel.h"


wxBEGIN_EVENT_TABLE(StartingListPanel, wxPanel)
    EVT_BUTTON(wxID_ANY, StartingListPanel::OnAddPlayer)
wxEND_EVENT_TABLE()

    StartingListPanel::StartingListPanel(wxWindow* parent, Tournament t) : wxPanel(parent) {

        // Dodaj komponenty listy startowej
        wxListBox* listBox = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(200, 200));
        listBox->Append("Zawodnik 1");
        listBox->Append("Zawodnik 2");
        listBox->Append("Zawodnik 3");

        //przycisk dodawania nowego zawodnika
        newPlayerButton = new wxButton(this, wxID_ANY, "Dodaj nowego zawodnika", wxDefaultPosition, wxSize(160, 40));

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);
        sizer->Add(newPlayerButton, 0, wxALL | wxALIGN_CENTER, 10);

        SetSizer(sizer);
    }

void StartingListPanel::OnAddPlayer(wxCommandEvent& event) {
    wxWindow* parent = GetParent(); // Pobierz rodzica (g³ówne okno)
    if (parent) {
        parent->DestroyChildren(); // Usuñ bie¿¹ce komponenty
        AddPlayerPanel* addPlayerPanel = new AddPlayerPanel(parent);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(addPlayerPanel, 1, wxEXPAND);
        parent->SetSizer(sizer);
        parent->Layout();
    }
}
