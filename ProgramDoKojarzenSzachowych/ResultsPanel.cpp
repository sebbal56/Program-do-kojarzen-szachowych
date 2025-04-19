#include "ResultsPanel.h"

std::string formatDoubleValues(double val, int precision = 1) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(precision) << val;
    return ss.str();
}

ResultsPanel::ResultsPanel(wxWindow* parent, Tournament* t) : wxPanel(parent) {
    tournament = t;

    listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(400, 200), wxLC_REPORT);

    listCtrl->InsertColumn(0, "Msc", wxLIST_FORMAT_LEFT, 40);
    listCtrl->InsertColumn(1, "Pkt", wxLIST_FORMAT_LEFT, 55);
    listCtrl->InsertColumn(2, "Buch", wxLIST_FORMAT_LEFT, 55);
    listCtrl->InsertColumn(3, "Prog", wxLIST_FORMAT_LEFT, 55);
    listCtrl->InsertColumn(4, "Nazwisko", wxLIST_FORMAT_LEFT, 135);
    listCtrl->InsertColumn(5, "Imie", wxLIST_FORMAT_LEFT, 135);
    listCtrl->InsertColumn(6, "Rank", wxLIST_FORMAT_LEFT, 65);

    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)); // Rozmiar 8, czcionka monospaced
    listCtrl->SetFont(font);

    tournament ->sortByPoints(tournament->listOfPlayers);
    long index = 0;
    for (auto& player : tournament->listOfPlayers) {
        listCtrl->InsertItem(index, std::to_string(index + 1));
        listCtrl->SetItem(index, 1, formatDoubleValues(player.points));
        listCtrl->SetItem(index, 2, formatDoubleValues(player.getBuch()));
        listCtrl->SetItem(index, 3, formatDoubleValues(player.getProg()));
        listCtrl->SetItem(index, 4, player.getSurname());
        listCtrl->SetItem(index, 5, player.getName());
        listCtrl->SetItem(index, 6, std::to_string(player.getRating()));
        ++index;
    }
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listCtrl, 1, wxEXPAND | wxALL, 10);

    SetSizer(sizer);
}

