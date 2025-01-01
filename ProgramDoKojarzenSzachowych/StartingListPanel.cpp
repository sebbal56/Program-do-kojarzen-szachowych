#include "StartingListPanel.h"


    StartingListPanel::StartingListPanel(wxWindow* parent)
        : wxPanel(parent) {
        // Tutaj mo¿esz dodaæ komponenty listy startowej, np. wxListBox, wxStaticText, itp.
        wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, "Lista Startowa", wxPoint(20, 20), wxSize(200, 30));

        // Dodaj komponenty listy startowej
        wxListBox* listBox = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(200, 200));
        listBox->Append("Zawodnik 1");
        listBox->Append("Zawodnik 2");
        listBox->Append("Zawodnik 3");

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(titleLabel, 0, wxALL, 10);
        sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);

        SetSizer(sizer);
    }
