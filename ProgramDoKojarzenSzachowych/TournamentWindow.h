#ifndef TOURNAMENTWINDOW_H
#define TOURNAMENTWINDOW_H

#include <wx/wx.h>
#include "MainFrame.h"


class TournamentWindow : public wxPanel {
public:
    TournamentWindow(wxWindow* parent, const wxString& tournamentName, const wxString& tournamentDay, const wxString& tournamentMonth, 
        const wxString& tournamentYear, const wxString& tournamentPlace, const wxString& tournamentArbiter, const wxString& tournamentAbout);
private:
    wxStaticText* mainLabel;
    wxStaticText* tournamentLabel;
    wxStaticText* arbiterLabel;
    wxStaticText* arbiterLabel2;
    wxStaticText* placeLabel;
    wxStaticText* placeLabel2;
    wxStaticText* dateLabel;
    wxStaticText* dateLabel2;
    wxStaticText* aboutLabel;
    wxStaticText* aboutLabel2;
    wxButton* startingListButton;
    wxButton* resultsButton;
};

#endif // TOURNAMENTWINDOW_H