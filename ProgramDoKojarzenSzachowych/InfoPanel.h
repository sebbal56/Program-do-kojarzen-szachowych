#pragma once

#include <wx/wx.h>
#include "Tournament.h"

class InfoPanel : public wxPanel {
public:
    InfoPanel(wxWindow* parent, Tournament& tournament);

private:
    wxStaticText* mainLabel;
    wxStaticText* tournamentLabel;
    wxStaticText* placeLabel;
    wxStaticText* placeLabel2;
    wxStaticText* dateLabel;
    wxStaticText* dateLabel2;
    wxStaticText* arbiterLabel;
    wxStaticText* arbiterLabel2;
    wxStaticText* aboutLabel;
    wxStaticText* aboutLabel2;

    Tournament tournament;
};